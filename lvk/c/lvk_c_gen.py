#!/usr/bin/env python3
# LightweightVK
#
# Copyright (c) 2023-2026 Sergey Kosarevsky and contributors.
#
# This source code is licensed under the MIT license found in the
# LICENSE file in the root directory of this source tree.

"""
Generates the C99 API of LightweightVK (lvk_c.h) and its C++ shim (lvk_c.cpp) from lvk/LVK.h using libclang.

    python3 lvk/c/lvk_c_gen.py            # (re)generate lvk/c/lvk_c.h and lvk/c/lvk_c.cpp
    python3 lvk/c/lvk_c_gen.py --check    # fail if the committed files are out of date

Requires the 'libclang' Python package (pip install libclang) or a system libclang with its Python bindings.
Naming conventions and special cases are configured in lvk_c_gen.json.
"""

import argparse
import json
import os
import re
import subprocess
import sys

try:
  import clang.cindex as ci
  from clang.cindex import CursorKind as CK
  from clang.cindex import TypeKind as TK
except ImportError:
  sys.exit("lvk_c_gen.py: cannot import clang.cindex. Install it with: pip install libclang")

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(os.path.dirname(HERE))

BUILTIN_C = {
    TK.BOOL: "bool",
    TK.CHAR_S: "char",
    TK.CHAR_U: "char",
    TK.SCHAR: "signed char",
    TK.UCHAR: "unsigned char",
    TK.SHORT: "short",
    TK.USHORT: "unsigned short",
    TK.INT: "int",
    TK.UINT: "unsigned int",
    TK.LONG: "long",
    TK.ULONG: "unsigned long",
    TK.LONGLONG: "long long",
    TK.ULONGLONG: "unsigned long long",
    TK.FLOAT: "float",
    TK.DOUBLE: "double",
}

ENUM_UNDERLYING_C = {
    TK.SCHAR: "int8_t",
    TK.UCHAR: "uint8_t",
    TK.CHAR_S: "int8_t",
    TK.CHAR_U: "uint8_t",
    TK.SHORT: "int16_t",
    TK.USHORT: "uint16_t",
    TK.INT: "int32_t",
    TK.UINT: "uint32_t",
    TK.LONG: "int64_t",
    TK.ULONG: "uint64_t",
    TK.LONGLONG: "int64_t",
    TK.ULONGLONG: "uint64_t",
}

STD_INT_NAMES = {
    "int8_t", "int16_t", "int32_t", "int64_t", "uint8_t", "uint16_t", "uint32_t", "uint64_t", "size_t", "uintptr_t", "intptr_t", "ptrdiff_t"
}

WORD_RE = re.compile(r"[A-Z]+(?=[A-Z][a-z])|[A-Z]?[a-z0-9]+|[A-Z0-9]+")


def split_words(name):
  """Splits CamelCase / snake_case identifiers keeping acronyms and digits together: 'getFramebufferMSAABitMask' -> [...]"""
  words = []
  for part in name.split("_"):
    if not part:
      continue
    words.extend(WORD_RE.findall(part))
  merged = []
  for w in words:
    # '3D' in 'Offset3D' stays attached to the preceding word
    if merged and len(w) == 1 and w.isupper() and merged[-1][-1].isdigit():
      merged[-1] += w
    else:
      merged.append(w)
  return merged


def to_snake(name):
  return "_".join(w.lower() for w in split_words(name))


def to_upper_snake(name):
  return "_".join(w.upper() for w in split_words(name))


class CT:
  """A C type mapped from a C++ type"""

  def __init__(self, c, cpp="", kind="prim", cpp_pointee="", const_pointee=False):
    self.c = c  # C spelling
    self.cpp = cpp  # canonical C++ spelling (used in casts)
    self.kind = kind  # void, prim, enum, agg, ptr, ptr_prim, ref, ref_prim, iface_ptr, iface_ref, holder, uptr
    self.cpp_pointee = cpp_pointee
    self.const_pointee = const_pointee


class Param:
  def __init__(self, name, ct, default):
    self.name = name
    self.ct = ct
    self.default = default


class Func:
  def __init__(self, cname, ret, params, call, guard=None, doc=None):
    self.cname = cname
    self.ret = ret
    self.params = params
    self.call = call  # callable (arg_exprs) -> C++ expression string
    self.guard = guard
    self.doc = doc


class Generator:
  def __init__(self, cfg, tu, header_path):
    self.cfg = cfg
    self.tu = tu
    self.header_path = os.path.realpath(header_path)
    self.type_prefix = cfg["type_prefix"]
    self.type_suffix = cfg["type_suffix"]
    self.func_prefix = cfg["func_prefix"]
    self.const_prefix = cfg["const_prefix"]
    self.renames = cfg.get("type_renames", {})
    self.interfaces = cfg["interfaces"]
    self.struct_overrides = cfg.get("struct_overrides", {})
    self.skip_functions = set(cfg.get("skip_functions", []))
    self.skip_free_functions = set(cfg.get("skip_free_functions", []))
    self.guards = cfg.get("guards", {})
    self.window_cpp = cfg.get("window_cpp_type", "")

    self.defines = []  # (name, value, comment)
    self.const_names = {}  # C++ identifier -> C macro name
    self.opaque = {}  # usr -> (cname, cppname)
    self.enums = {}  # usr -> (cname, cppname, underlying, [(name, value)])
    self.enum_order = []
    self.int_aliases = {}  # alias name -> (cname, underlying)
    self.handles = {}  # alias name -> cname
    self.handle_by_canon = {}  # canonical C++ spelling -> alias name
    self.structs = {}  # usr -> dict
    self.struct_order = []  # usr in dependency order
    self.spans = {}  # cname -> dict
    self.type_checks = []  # (cname, cppname)
    self.funcs = []
    self.enumerator_names = {}  # C++ enumerator -> C name

  # ---------------------------------------------------------------- naming
  @staticmethod
  def is_anon(c):
    return not c.spelling or c.is_anonymous() or "(unnamed" in c.spelling or "(anonymous" in c.spelling

  def in_main_file(self, c):
    return c.location.file is not None and os.path.realpath(c.location.file.name) == self.header_path

  def qualified(self, decl):
    parts = []
    c = decl
    while c is not None and c.kind != CK.TRANSLATION_UNIT and c.kind != CK.NAMESPACE:
      if c.spelling:
        parts.append(c.spelling)
      c = c.semantic_parent
    return "::".join(reversed(parts))

  def cpp_name(self, decl):
    return "lvk::" + self.qualified(decl)

  def type_cname(self, qualified):
    short = self.renames.get(qualified, qualified.replace("::", "_"))
    return self.type_prefix + to_snake(short) + self.type_suffix

  def const_cname(self, name):
    if name.startswith(self.const_prefix):
      return name
    if re.match(r"^k[A-Z]", name):
      name = name[1:]
    return self.const_prefix + to_upper_snake(name)

  # ---------------------------------------------------------------- constants
  def add_define(self, name, value):
    self.defines.append((name, value))

  def register_anon_enum(self, decl):
    unsigned = decl.enum_type.get_canonical().kind in (TK.ULONG, TK.ULONGLONG, TK.UINT)
    for e in decl.get_children():
      if e.kind != CK.ENUM_CONSTANT_DECL:
        continue
      v = e.enum_value
      if unsigned and v < 0:
        v += 1 << (8 * decl.enum_type.get_size())
      text = ("0x%xull" % v) if v > 0x7FFFFFFF else str(v)
      cname = self.const_cname(e.spelling)
      self.const_names[e.spelling] = cname
      self.add_define(cname, text)

  def register_constexpr_var(self, var):
    toks = [t.spelling for t in var.get_tokens()]
    if "=" not in toks:
      return
    value = " ".join(toks[toks.index("=") + 1 :]).rstrip(";").strip()
    if not re.match(r"^[0-9]+[uUlL]*$", value):
      return
    cname = self.const_cname(var.spelling)
    self.const_names[var.spelling] = cname
    self.add_define(cname, value)

  # ---------------------------------------------------------------- types
  def is_iface(self, decl):
    return decl.spelling in self.interfaces and decl.kind == CK.CLASS_DECL

  def iface_cname(self, decl):
    return self.type_cname(self.interfaces[decl.spelling]["type"])

  def need_opaque(self, decl):
    cname = self.iface_cname(decl)
    self.opaque[decl.get_usr()] = (cname, self.cpp_name(decl))
    return cname

  def need_enum(self, decl):
    usr = decl.get_usr()
    if usr in self.enums:
      return self.enums[usr]
    qualified = self.qualified(decl)
    cname = self.type_cname(qualified)
    cpp = self.cpp_name(decl)
    underlying = ENUM_UNDERLYING_C[decl.enum_type.get_canonical().kind]
    unsigned = underlying.startswith("u")
    values = []
    short = decl.spelling
    for e in decl.get_children():
      if e.kind != CK.ENUM_CONSTANT_DECL:
        continue
      name = e.spelling
      qual_up = to_upper_snake(qualified.replace("::", "_"))
      if name.startswith(short + "_"):
        full = qual_up + "_" + to_upper_snake(name[len(short) + 1 :])
      elif decl.is_scoped_enum():
        full = qual_up + "_" + to_upper_snake(name)
      else:
        full = to_upper_snake(name)
      v = e.enum_value
      if unsigned and v < 0:
        v += 1 << (8 * decl.enum_type.get_size())
      values.append((self.const_prefix + full, v))
      self.enumerator_names[name] = self.const_prefix + full
    entry = (cname, cpp, underlying, values)
    self.enums[usr] = entry
    self.enum_order.append(usr)
    self.type_checks.append((cname, cpp))
    return entry

  def need_int_alias(self, decl):
    name = decl.spelling
    cname = self.type_cname(name)
    self.int_aliases[name] = (cname, decl.underlying_typedef_type.spelling)
    self.type_checks.append((cname, "lvk::" + name))

  def need_handle_alias(self, decl):
    name = decl.spelling
    cname = self.type_cname(name)
    self.handles[name] = cname
    self.handle_by_canon[decl.underlying_typedef_type.get_canonical().spelling] = name
    self.type_checks.append((cname, "lvk::" + name))

  def need_span(self, t):
    elem_t = t.get_template_argument_type(0)
    elem = self.map_type(elem_t)
    const = elem_t.is_const_qualified()
    stem = elem.c
    if stem.startswith(self.type_prefix):
      stem = stem[len(self.type_prefix) :]
    if stem.endswith(self.type_suffix):
      stem = stem[: -len(self.type_suffix)]
    cname = self.type_prefix + "span_" + ("const_" if const else "") + stem + self.type_suffix
    if cname not in self.spans:
      self.spans[cname] = {"elem": ("const " if const else "") + elem.c, "order": len(self.spans)}
      self.struct_order.append(("span", cname))
      self.type_checks.append((cname, t.get_canonical().spelling))
    return CT(cname, t.get_canonical().spelling, "agg")

  def need_record(self, decl):
    usr = decl.get_usr()
    if usr in self.structs:
      return self.structs[usr]["ct"]
    qualified = self.qualified(decl)
    cname = self.type_cname(qualified)
    cpp = self.cpp_name(decl)
    ct = CT(cname, cpp, "agg")
    ctors = [c for c in decl.get_children() if c.kind == CK.CONSTRUCTOR]
    default_ok = not ctors or any(c.is_default_constructor() for c in ctors)
    info = {"default_ok": default_ok, "ct": ct, "cname": cname, "cpp": cpp, "union": decl.kind == CK.UNION_DECL, "fields": [], "decl": decl, "short": decl.spelling}
    self.structs[usr] = info
    # nested types first
    for ch in decl.get_children():
      if ch.kind in (CK.STRUCT_DECL, CK.UNION_DECL) and ch.is_definition() and not ch.is_anonymous():
        self.need_record(ch)
      elif ch.kind == CK.ENUM_DECL:
        if self.is_anon(ch):
          self.register_anon_enum(ch)
        else:
          self.need_enum(ch)
    override = self.struct_overrides.get(qualified)
    if override is not None:
      info["fields"] = [(ctype, name, [], 0) for ctype, name in override]
      info["override"] = True
    else:
      for ch in decl.get_children():
        if ch.kind != CK.FIELD_DECL:
          continue
        info["fields"].append(self.map_field(ch))
    self.struct_order.append(("struct", usr))
    self.type_checks.append((cname, cpp))
    return ct

  def array_dims(self, t):
    dims = []
    while t.kind == TK.CONSTANTARRAY:
      dims.append(t.get_array_size())
      t = t.element_type
    return dims, t

  def map_field(self, f):
    dims, elem_t = self.array_dims(f.type)
    ct = self.map_type(elem_t)
    ctype = ct.c
    # recover symbolic array sizes from the source tokens
    sym = []
    if dims:
      toks = [t.spelling for t in f.get_tokens()]
      if "=" in toks:
        toks = toks[: toks.index("=")]
      groups, cur, depth = [], [], 0
      for tk in toks:
        if tk == "[":
          depth += 1
          cur = []
        elif tk == "]":
          depth -= 1
          groups.append(cur)
        elif depth:
          cur.append(tk)
      if len(groups) == len(dims):
        for g, d in zip(groups, dims):
          sym.append(self.const_names.get(g[-1], str(d)) if len(g) == 1 or (len(g) == 3 and g[1] == "::") else str(d))
      else:
        sym = [str(d) for d in dims]
    if f.is_bitfield():
      return (ctype, f.spelling, [], f.get_bitfield_width())
    return (ctype, f.spelling, sym, 0)

  def map_type(self, t):
    k = t.kind
    if k == TK.VOID:
      return CT("void", "void", "void")
    if k == TK.ELABORATED:
      return self.map_type(t.get_named_type())
    if k == TK.UNEXPOSED and t.get_canonical().kind != TK.UNEXPOSED:
      return self.map_type(t.get_canonical())
    if k in BUILTIN_C:
      return CT(BUILTIN_C[k], BUILTIN_C[k], "prim")
    if k == TK.TYPEDEF:
      name = t.get_declaration().spelling
      if name in STD_INT_NAMES:
        return CT(name, name, "prim")
      if name in self.int_aliases:
        return CT(self.int_aliases[name][0], "lvk::" + name, "prim")
      if name in self.handles:
        return CT(self.handles[name], "lvk::" + name, "agg")
      return self.map_type(t.get_canonical())
    if k == TK.ENUM:
      cname, cpp, _, _ = self.need_enum(t.get_declaration())
      return CT(cname, cpp, "enum")
    if k == TK.RECORD:
      decl = t.get_declaration()
      name = decl.spelling
      if name == "Span":
        return self.need_span(t)
      if name == "Handle":
        alias = self.handle_by_canon[t.get_canonical().spelling]
        return CT(self.handles[alias], "lvk::" + alias, "agg")
      if name == "Holder":
        inner = self.map_type(t.get_template_argument_type(0))
        return CT(inner.c, t.get_canonical().spelling, "holder")
      if name == "unique_ptr":
        inner_decl = t.get_template_argument_type(0).get_declaration()
        return CT(self.iface_cname(inner_decl) + "*", t.get_canonical().spelling, "uptr")
      if self.is_iface(decl):
        return CT(self.need_opaque(decl), self.cpp_name(decl), "iface")
      if decl.get_definition() is not None and self.in_main_file(decl.get_definition()):
        return self.need_record(decl.get_definition())
      return CT(name, t.get_canonical().spelling, "external")
    if k in (TK.POINTER, TK.LVALUEREFERENCE):
      pointee = t.get_pointee()
      inner = self.map_type(pointee)
      is_ref = k == TK.LVALUEREFERENCE
      const = pointee.is_const_qualified()
      pointee_cpp = pointee.get_canonical().spelling
      if inner.kind == "external":
        cc = "const void*" if const else "void*"
        return CT(cc, pointee_cpp + "*", "ptr", pointee_cpp, const)
      if inner.kind == "iface":
        return CT(inner.c + "*", pointee_cpp + "*", "iface_ref" if is_ref else "iface_ptr", pointee_cpp, const)
      cc = ("const " if const else "") + inner.c + "*"
      prim = inner.kind in ("prim", "void") and not inner.c.startswith(self.type_prefix)
      if prim:
        return CT(cc, pointee_cpp + "*", "ref_prim" if is_ref else "ptr_prim", pointee_cpp, const)
      return CT(cc, pointee_cpp + "*", "ref" if is_ref else "ptr", pointee_cpp, const)
    if k == TK.CONSTANTARRAY:
      elem = t.element_type
      inner = self.map_type(elem)
      const = elem.is_const_qualified()
      prim = inner.kind == "prim" and not inner.c.startswith(self.type_prefix)
      return CT(("const " if const else "") + inner.c + "*", elem.get_canonical().spelling + "*", "ptr_prim" if prim else "ptr", elem.get_canonical().spelling, const)
    raise RuntimeError("unsupported type: %s (%s)" % (t.spelling, k))

  # ---------------------------------------------------------------- conversions
  def arg_expr(self, ct, name):
    k = ct.kind
    if k in ("prim", "ptr_prim", "void"):
      return name
    if k == "enum":
      return "static_cast<%s>(%s)" % (ct.cpp, name)
    if k == "agg":
      return "std::bit_cast<%s>(%s)" % (ct.cpp, name)
    if k in ("ptr", "iface_ptr"):
      return "reinterpret_cast<%s>(%s)" % (ct.cpp, name)
    if k in ("ref", "iface_ref"):
      return "*reinterpret_cast<%s>(%s)" % (ct.cpp, name)
    if k == "ref_prim":
      return "*" + name
    raise RuntimeError("cannot convert argument of kind " + k)

  def ret_expr(self, ct, expr):
    k = ct.kind
    if k in ("prim", "ptr_prim", "void"):
      return expr
    if k == "enum":
      return "static_cast<%s>(%s)" % (ct.c, expr)
    if k == "agg":
      return "std::bit_cast<%s>(%s)" % (ct.c, expr)
    if k == "holder":
      return "std::bit_cast<%s>((%s).release())" % (ct.c, expr)
    if k == "uptr":
      return "reinterpret_cast<%s>((%s).release())" % (ct.c, expr)
    if k == "iface_ref":
      return "reinterpret_cast<%s>(&(%s))" % (ct.c, expr)
    if k in ("ptr", "iface_ptr"):
      return "reinterpret_cast<%s>(%s)" % (ct.c, expr)
    raise RuntimeError("cannot convert return value of kind " + k)

  # ---------------------------------------------------------------- functions
  def map_params(self, cursor):
    params = []
    for i, a in enumerate(cursor.get_arguments()):
      ct = self.map_type(a.type)
      toks = [t.spelling for t in a.get_tokens()]
      default = self.translate_default(toks[toks.index("=") + 1 :]) if "=" in toks else None
      params.append(Param(a.spelling or "arg%d" % i, ct, default))
    return params

  def translate_default(self, toks):
    out = []
    for t in toks:
      if t == "nullptr":
        t = "NULL"
      elif t in self.enumerator_names:
        t = self.enumerator_names[t]
      elif t in self.const_names:
        t = self.const_names[t]
      out.append(t)
    text = "".join(out).replace("lvk::", "")
    return "{0}" if text.replace(" ", "") == "{}" else text

  def tag_of(self, t):
    while t.kind in (TK.POINTER, TK.LVALUEREFERENCE):
      t = t.get_pointee()
    decl = t.get_declaration()
    return decl.spelling if decl.spelling else t.get_canonical().spelling

  def collect_interface(self, decl):
    cfg = self.interfaces[decl.spelling]
    iface_c = self.iface_cname(decl)
    iface_cpp = self.cpp_name(decl)
    self.need_opaque(decl)
    methods = []
    for m in decl.get_children():
      if m.kind != CK.CXX_METHOD or m.access_specifier != ci.AccessSpecifier.PUBLIC or m.is_static_method():
        continue
      if m.spelling in self.skip_functions or m.type.kind == TK.FUNCTIONPROTO and m.type.is_function_variadic():
        continue
      methods.append(m)
    groups = {}
    for m in methods:
      groups.setdefault(m.spelling, []).append(m)
    for name, group in groups.items():
      suffixes = {}
      if len(group) > 1:
        arg_lists = [[a.type for a in m.get_arguments()] for m in group]
        n = min(len(a) for a in arg_lists)
        idx = next((i for i in range(n) if len(set(self.tag_of(a[i]) for a in arg_lists)) > 1), None)
        if idx is None:
          raise RuntimeError("cannot disambiguate overloads of " + name)
        for m, a in zip(group, arg_lists):
          tag = self.tag_of(a[idx])
          tag = tag[: -len("Handle")] if tag.endswith("Handle") and tag != "Handle" else tag
          suffixes[m.get_usr()] = "_" + to_snake(tag)
        if len(set(suffixes.values())) != len(group):
          raise RuntimeError("overload suffix collision for " + name)
      for m in group:
        base = name
        strip = cfg.get("strip", "")
        if strip and base.startswith(strip) and len(base) > len(strip) and base[len(strip)].isupper():
          base = base[len(strip) :]
        cname = self.func_prefix + cfg["prefix"] + "_" + to_snake(base) + suffixes.get(m.get_usr(), "")
        ret = self.map_type(m.result_type)
        params = self.map_params(m)
        const = m.is_const_method()
        self.funcs.append(
            Func(
                cname,
                ret,
                [Param("self", CT(iface_c + "*", iface_cpp + "*", "iface_ptr"), None)] + params,
                (lambda args, mname=name, icpp=iface_cpp: "%s->%s(%s)" % (args[0], mname, ", ".join(args[1:]))),
                self.guards.get(name),
            )
        )
        self.funcs[-1].self_cpp = iface_cpp
    if cfg.get("destroy_function"):
      cname = self.func_prefix + cfg["prefix"] + "_destroy"
      f = Func(cname, CT("void", "void", "void"), [Param("self", CT(iface_c + "*", iface_cpp + "*", "iface_ptr"), None)], None)
      f.custom_body = "delete reinterpret_cast<%s*>(self);" % iface_cpp
      self.funcs.append(f)

  def collect_function(self, c):
    name = c.spelling
    if name in self.skip_free_functions or name in self.skip_functions or name.startswith("operator"):
      return
    if c.type.kind == TK.FUNCTIONPROTO and c.type.is_function_variadic():
      return
    cname = self.func_prefix + to_snake(name)
    ret = self.map_type(c.result_type)
    params = self.map_params(c)
    f = Func(cname, ret, params, (lambda args, n=name: "lvk::%s(%s)" % (n, ", ".join(args))), self.guards.get(name))
    self.funcs.append(f)

  # ---------------------------------------------------------------- driver
  def run(self):
    top = []

    def walk(cursor):
      for ch in cursor.get_children():
        if not self.in_main_file(ch):
          continue
        if ch.kind == CK.NAMESPACE:
          walk(ch)
        else:
          top.append(ch)

    walk(self.tu.cursor)
    # pass 0: constants, aliases and enums, so that array sizes and types resolve in any order
    for c in top:
      if c.kind == CK.ENUM_DECL and self.is_anon(c):
        self.register_anon_enum(c)
      elif c.kind == CK.VAR_DECL:
        self.register_constexpr_var(c)
      elif c.kind == CK.TYPE_ALIAS_DECL:
        canon = c.underlying_typedef_type.get_canonical()
        if canon.kind == TK.RECORD and canon.get_declaration().spelling == "Handle":
          self.need_handle_alias(c)
        elif canon.kind in ENUM_UNDERLYING_C:
          self.need_int_alias(c)
    for c in top:
      if c.kind == CK.ENUM_DECL and not self.is_anon(c):
        self.need_enum(c)
    # pass 1: records and functions
    for c in top:
      if c.kind in (CK.STRUCT_DECL, CK.UNION_DECL) and c.is_definition():
        self.need_record(c)
      elif c.kind == CK.CLASS_DECL and c.is_definition() and c.spelling in self.interfaces:
        self.collect_interface(c)
      elif c.kind == CK.FUNCTION_DECL:
        self.collect_function(c)
    self.collect_constructors()

  def collect_constructors(self):
    """Structs without a default constructor get one lvk_<struct>_<suffix>() function per C++ constructor"""
    for info in list(self.structs.values()):
      if info["default_ok"]:
        continue
      decl = info["decl"]
      qualified = self.qualified(decl)
      ctors = [
          c
          for c in decl.get_children()
          if c.kind == CK.CONSTRUCTOR and c.access_specifier == ci.AccessSpecifier.PUBLIC and not c.is_copy_constructor() and not c.is_move_constructor()
      ]
      suffixes = self.cfg.get("constructor_suffixes", {}).get(qualified)
      if not suffixes or len(suffixes) != len(ctors):
        raise RuntimeError("%s has %d constructors, list their suffixes in 'constructor_suffixes'" % (qualified, len(ctors)))
      stem = info["cname"][: -len(self.type_suffix)] if self.type_suffix else info["cname"]
      for c, suffix in zip(ctors, suffixes):
        f = Func(
            self.func_prefix + stem[len(self.type_prefix) :] + "_" + suffix,
            info["ct"],
            self.map_params(c),
            (lambda args, cpp=info["cpp"]: "%s(%s)" % (cpp, ", ".join(args))),
        )
        self.funcs.append(f)

  # ---------------------------------------------------------------- emitters
  def decl_str(self, ctype, name, dims):
    return "%s %s%s" % (ctype, name, "".join("[%s]" % d for d in dims))

  def func_proto(self, f):
    params = ", ".join("%s %s" % (p.ct.c, p.name) for p in f.params) or "void"
    return "LVK_C_API %s %s(%s)" % (f.ret.c, f.cname, params)

  def emit_header(self):
    p = self.cfg
    out = []
    w = out.append
    guard = p.get("header_guard", "LVK_C_H")
    w("/*")
    w(" * LightweightVK C API")
    w(" *")
    w(" * GENERATED FILE - DO NOT EDIT. Regenerate with: python3 lvk/c/lvk_c_gen.py")
    w(" * Source: lvk/LVK.h, configuration: lvk/c/lvk_c_gen.json")
    w(" *")
    w(" * Conventions:")
    w(" *  - always initialize descriptor structs with their lvk_*_default() function, C++ defaults are not zeros")
    w(" *  - handles are plain values; destroy them with lvk_context_destroy_*() (there is no RAII)")
    w(" *  - parameters with a C++ default value are listed in a comment, pass them explicitly")
    w(" */")
    w("#ifndef " + guard)
    w("#define " + guard)
    w("")
    w("#include <stdbool.h>")
    w("#include <stddef.h>")
    w("#include <stdint.h>")
    w("")
    w("#ifdef __cplusplus")
    w('extern "C" {')
    w("#endif")
    w("")
    w("#if defined(LVK_C_SHARED)")
    w("  #if defined(_WIN32)")
    w("    #if defined(LVK_C_BUILD)")
    w("      #define LVK_C_API __declspec(dllexport)")
    w("    #else")
    w("      #define LVK_C_API __declspec(dllimport)")
    w("    #endif")
    w("  #else")
    w('    #define LVK_C_API __attribute__((visibility("default")))')
    w("  #endif")
    w("#else")
    w("  #define LVK_C_API")
    w("#endif")
    w("")
    if self.defines:
      # small values are enum constants: they cannot clash with the identically named C++ enumerators of LVK.h (macros would)
      small = [(n, v) for n, v in self.defines if not v.startswith("0x")]
      big = [(n, v) for n, v in self.defines if v.startswith("0x")]
      w("/* constants */")
      if small:
        w("enum {")
        for name, value in small:
          w("  %s = %s," % (name, value))
        w("};")
      if big:
        w("#ifndef __cplusplus /* C++ code gets these from LVK.h */")
        for name, value in big:
          w("#define %s %s" % (name, value))
        w("#endif")
      w("")
    if self.opaque:
      w("/* opaque interfaces */")
      for cname, _ in sorted(set(self.opaque.values())):
        w("typedef struct %s %s;" % (cname, cname))
      w("")
    if self.enums:
      w("/* enums: fixed-width typedefs keep the layout of the C++ structs */")
      for usr in self.enum_order:
        cname, _, underlying, values = self.enums[usr]
        w("typedef %s %s;" % (underlying, cname))
        small = [(n, v) for n, v in values if -0x80000000 <= v <= 0x7FFFFFFF]
        big = [(n, v) for n, v in values if not -0x80000000 <= v <= 0x7FFFFFFF]
        if small:
          w("enum {")
          for n, v in small:
            w("  %s = %d," % (n, v))
          w("};")
        for n, v in big:
          w("#define %s 0x%x%s" % (n, v, "ull" if v > 0xFFFFFFFF else "u"))
      w("")
    if self.int_aliases:
      for name, (cname, under) in self.int_aliases.items():
        w("typedef %s %s;" % (under, cname))
      w("")
    if self.handles:
      w("/* handles */")
      for name, cname in self.handles.items():
        w("typedef struct %s {" % cname)
        w("  uint32_t index;")
        w("  uint32_t gen;")
        w("} %s;" % cname)
        w("static inline bool %s_valid(%s h) { return h.gen != 0; }" % (cname[: -len(self.type_suffix)] if self.type_suffix else cname, cname))
      w("")
    forwards = [i["cname"] for i in self.structs.values()]
    if forwards:
      w("/* forward declarations */")
      for usr, i in self.structs.items():
        w("typedef %s %s %s;" % ("union" if i["union"] else "struct", i["cname"], i["cname"]))
      w("")
    w("/* structs */")
    for kind, key in self.struct_order:
      if kind == "span":
        s = self.spans[key]
        w("typedef struct %s {" % key)
        w("  %s* data;" % s["elem"])
        w("  size_t size;")
        w("} %s;" % key)
        w("")
      else:
        i = self.structs[key]
        w("%s %s {" % ("union" if i["union"] else "struct", i["cname"]))
        for ctype, name, dims, bits in i["fields"]:
          w("  %s%s;" % (self.decl_str(ctype, name, dims), " : %d" % bits if bits else ""))
        w("};")
        w("")
    w("/* default-initialized descriptors */")
    for fn in self.default_funcs():
      w("LVK_C_API %s %s(void);" % (fn[1], fn[0]))
    w("")
    w("/* functions */")
    for f in self.funcs:
      doc = [p for p in f.params if p.default is not None]
      if doc:
        w("/* defaults: %s */" % ", ".join("%s = %s" % (p.name, p.default) for p in doc))
      w(self.func_proto(f) + ";")
    w("")
    w("#ifdef __cplusplus")
    w('} /* extern "C" */')
    w("#endif")
    w("")
    w("#endif /* %s */" % guard)
    return "\n".join(out) + "\n"

  def default_funcs(self):
    res = []
    for i in self.structs.values():
      if not i["default_ok"]:
        continue
      res.append((self.func_prefix + to_snake(i["cname"][len(self.type_prefix) : -len(self.type_suffix) or None]) + "_default", i["cname"], i))
    return res

  def emit_shim(self):
    out = []
    w = out.append
    w("// GENERATED FILE - DO NOT EDIT. Regenerate with: python3 lvk/c/lvk_c_gen.py")
    w("")
    w("#include <bit>")
    w("#include <cstddef>")
    w("")
    w('#include "lvk_c.h"')
    w("#include <lvk/LVK.h>")
    w("")
    w("// layout checks: the C structs must be bit-compatible with their C++ counterparts")
    for cname, cpp in self.type_checks:
      w("static_assert(sizeof(%s) == sizeof(%s), \"size mismatch: %s\");" % (cname, cpp, cname))
    for i in self.structs.values():
      if i.get("override"):
        continue
      for ctype, name, dims, bits in i["fields"]:
        if bits:
          continue
        w("static_assert(offsetof(%s, %s) == offsetof(%s, %s), \"layout mismatch: %s::%s\");" % (i["cname"], name, i["cpp"], name, i["cname"], name))
    w("")
    w('extern "C" {')
    w("")
    for fn in self.default_funcs():
      w("%s %s(void) {" % (fn[1], fn[0]))
      w("  const %s v{};" % fn[2]["cpp"])
      w("  return std::bit_cast<%s>(v);" % fn[1])
      w("}")
      w("")
    for f in self.funcs:
      if f.guard:
        w("#if %s" % f.guard)
      w(self.func_proto(f).replace("LVK_C_API ", "") + " {")
      if getattr(f, "custom_body", None):
        w("  " + f.custom_body)
      else:
        args = []
        for p in f.params:
          args.append(self.arg_expr(p.ct, p.name))
        call = f.call(args)
        if f.ret.kind == "void":
          w("  %s;" % call)
        else:
          w("  return %s;" % self.ret_expr(f.ret, call))
      w("}")
      if f.guard:
        w("#endif")
      w("")
    w('} // extern "C"')
    return "\n".join(out) + "\n"


def find_resource_dir(clang_exe):
  try:
    return subprocess.check_output([clang_exe, "-print-resource-dir"], stderr=subprocess.DEVNULL).decode().strip()
  except (OSError, subprocess.CalledProcessError):
    return None


def main():
  ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
  ap.add_argument("--header", default=os.path.join(ROOT, "lvk", "LVK.h"))
  ap.add_argument("--config", default=os.path.join(HERE, "lvk_c_gen.json"))
  ap.add_argument("--out-dir", default=HERE)
  ap.add_argument("-D", dest="defines", action="append", default=None, help="extra preprocessor definition, e.g. -DLVK_WITH_GLFW=1")
  ap.add_argument("-I", dest="includes", action="append", default=None, help="extra include directory")
  ap.add_argument("--clang", default="clang", help="clang executable used to find the builtin headers (resource dir)")
  ap.add_argument("--check", action="store_true", help="do not write, fail if the files on disk differ")
  args = ap.parse_args()

  with open(args.config, "r", encoding="utf-8") as f:
    cfg = json.load(f)

  clang_args = ["-x", "c++", "-std=c++20", "-fsyntax-only"]
  includes = [os.path.join(ROOT, "lvk"), os.path.join(ROOT, "third-party", "deps", "src")] + (args.includes or [])
  clang_args += ["-I" + i for i in includes]
  for d in args.defines if args.defines is not None else cfg.get("defines", []):
    clang_args.append("-D" + d)
  res = find_resource_dir(args.clang)
  if res:
    clang_args += ["-resource-dir", res]

  tu = ci.Index.create().parse(args.header, args=clang_args)
  errors = [d for d in tu.diagnostics if d.severity >= ci.Diagnostic.Error]
  if errors:
    for d in errors:
      print("error:", d, file=sys.stderr)
    sys.exit("lvk_c_gen.py: failed to parse " + args.header)

  gen = Generator(cfg, tu, args.header)
  gen.run()
  files = {"lvk_c.h": gen.emit_header(), "lvk_c.cpp": gen.emit_shim()}

  rc = 0
  for name, text in files.items():
    path = os.path.join(args.out_dir, name)
    if args.check:
      current = open(path, "r", encoding="utf-8").read() if os.path.exists(path) else None
      if current != text:
        print("%s is out of date, run: python3 lvk/c/lvk_c_gen.py" % path, file=sys.stderr)
        rc = 1
    else:
      with open(path, "w", encoding="utf-8", newline="\n") as f:
        f.write(text)
      print("wrote", path)
  return rc


if __name__ == "__main__":
  sys.exit(main())
