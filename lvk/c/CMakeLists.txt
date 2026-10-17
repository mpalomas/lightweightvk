# LightweightVK
#
# Copyright (c) 2023-2026 Sergey Kosarevsky and contributors.
#
# This source code is licensed under the MIT license found in the
# LICENSE file in the root directory of this source tree.

cmake_minimum_required(VERSION 3.22)

project(LVKC CXX C)

set(LVK_C_GENERATED lvk_c.h lvk_c.cpp)

if(LVK_GENERATE_C_BINDINGS)
  if(NOT Python3_FOUND)
    message(FATAL_ERROR "LVK_GENERATE_C_BINDINGS=ON requires Python 3")
  endif()
  execute_process(COMMAND ${Python3_EXECUTABLE} -c "import clang.cindex" RESULT_VARIABLE LVK_C_LIBCLANG_RESULT OUTPUT_QUIET ERROR_QUIET)
  if(NOT LVK_C_LIBCLANG_RESULT EQUAL 0)
    message(FATAL_ERROR "LVK_GENERATE_C_BINDINGS=ON requires the Python libclang bindings: pip install libclang")
  endif()

  set(LVK_C_GEN_DEFINES "")
  if(LVK_WITH_GLFW)
    list(APPEND LVK_C_GEN_DEFINES -DLVK_WITH_GLFW=1)
  elseif(LVK_WITH_SDL3)
    list(APPEND LVK_C_GEN_DEFINES -DLVK_WITH_SDL3=1)
  endif()

  # lvk_c.h and lvk_c.cpp are committed, regenerate them whenever the generator, its config or LVK.h change
  add_custom_command(
    OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/lvk_c.h ${CMAKE_CURRENT_SOURCE_DIR}/lvk_c.cpp
    COMMAND ${Python3_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/lvk_c_gen.py ${LVK_C_GEN_DEFINES}
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/lvk_c_gen.py ${CMAKE_CURRENT_SOURCE_DIR}/lvk_c_gen.json ${LVK_ROOT_DIR}/lvk/LVK.h
    WORKING_DIRECTORY ${LVK_ROOT_DIR}
    COMMENT "Generating the LVK C API"
    VERBATIM
  )
endif()

if(LVK_C_BINDINGS_SHARED)
  add_library(LVKC SHARED ${LVK_C_GENERATED})
  target_compile_definitions(LVKC PUBLIC LVK_C_SHARED=1 PRIVATE LVK_C_BUILD=1)
  set_target_properties(LVKC PROPERTIES CXX_VISIBILITY_PRESET hidden VISIBILITY_INLINES_HIDDEN ON)
  if(UNIX AND NOT APPLE)
    # do not re-export the symbols of the static libraries linked into LVKC
    target_link_options(LVKC PRIVATE "LINKER:--exclude-libs,ALL")
  endif()
else()
  add_library(LVKC STATIC ${LVK_C_GENERATED})
endif()

lvk_setup_target(LVKC)
lvk_set_folder(LVKC "LVK")

# only lvk_c.h is public, the C++ API stays an implementation detail
target_include_directories(LVKC PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
target_link_libraries(LVKC PRIVATE LVKLibrary)
