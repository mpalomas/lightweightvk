/*
 * LightweightVK C API
 *
 * GENERATED FILE - DO NOT EDIT. Regenerate with: python3 lvk/c/lvk_c_gen.py
 * Source: lvk/LVK.h, configuration: lvk/c/lvk_c_gen.json
 *
 * Conventions:
 *  - always initialize descriptor structs with their lvk_*_default() function, C++ defaults are not zeros
 *  - handles are plain values; destroy them with lvk_context_destroy_*() (there is no RAII)
 *  - parameters with a C++ default value are listed in a comment, pass them explicitly
 */
#ifndef LVK_C_H
#define LVK_C_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#if defined(LVK_C_SHARED)
  #if defined(_WIN32)
    #if defined(LVK_C_BUILD)
      #define LVK_C_API __declspec(dllexport)
    #else
      #define LVK_C_API __declspec(dllimport)
    #endif
  #else
    #define LVK_C_API __attribute__((visibility("default")))
  #endif
#else
  #define LVK_C_API
#endif

/* constants */
enum {
  LVK_MAX_COLOR_ATTACHMENTS = 8,
  LVK_MAX_MIP_LEVELS = 16,
  LVK_MAX_CUSTOM_EXTENSIONS = 32,
  LVK_MAX_CUSTOM_LAYERS = 8,
  LVK_MAX_PRESENT_MODES = 8,
  LVK_MAX_PHYSICAL_DEVICE_NAME_SIZE = 256,
  LVK_VERTEX_ATTRIBUTES_MAX = 16,
  LVK_VERTEX_BUFFER_MAX = 16,
  LVK_SPECIALIZATION_CONSTANTS_MAX = 16,
};
#ifndef __cplusplus /* C++ code gets these from LVK.h */
#define LVK_WHOLE_SIZE 0xffffffffffffffffull
#endif

/* opaque interfaces */
typedef struct lvk_cmd_buffer_t lvk_cmd_buffer_t;
typedef struct lvk_context_t lvk_context_t;

/* enums: fixed-width typedefs keep the layout of the C++ structs */
typedef uint8_t lvk_index_format_t;
enum {
  LVK_INDEX_FORMAT_UI8 = 0,
  LVK_INDEX_FORMAT_UI16 = 1,
  LVK_INDEX_FORMAT_UI32 = 2,
};
typedef uint8_t lvk_topology_t;
enum {
  LVK_TOPOLOGY_POINT = 0,
  LVK_TOPOLOGY_LINE = 1,
  LVK_TOPOLOGY_LINE_STRIP = 2,
  LVK_TOPOLOGY_TRIANGLE = 3,
  LVK_TOPOLOGY_TRIANGLE_STRIP = 4,
  LVK_TOPOLOGY_PATCH = 5,
};
typedef uint8_t lvk_color_space_t;
enum {
  LVK_COLOR_SPACE_SRGB_NONLINEAR = 0,
  LVK_COLOR_SPACE_SRGB_EXTENDED_LINEAR = 1,
  LVK_COLOR_SPACE_HDR10 = 2,
  LVK_COLOR_SPACE_BT709_LINEAR = 3,
};
typedef uint8_t lvk_present_mode_t;
enum {
  LVK_PRESENT_MODE_FIFO = 0,
  LVK_PRESENT_MODE_FIFO_RELAXED = 1,
  LVK_PRESENT_MODE_IMMEDIATE = 2,
  LVK_PRESENT_MODE_MAILBOX = 3,
  LVK_PRESENT_MODE_SHARED_DEMAND_REFRESH = 4,
  LVK_PRESENT_MODE_SHARED_CONTINUOUS_REFRESH = 5,
  LVK_PRESENT_MODE_FIFO_LATEST_READY = 6,
};
typedef uint8_t lvk_surface_transform_t;
enum {
  LVK_SURFACE_TRANSFORM_IDENTITY = 0,
  LVK_SURFACE_TRANSFORM_ROTATE90 = 1,
  LVK_SURFACE_TRANSFORM_ROTATE180 = 2,
  LVK_SURFACE_TRANSFORM_ROTATE270 = 3,
};
typedef uint8_t lvk_texture_type_t;
enum {
  LVK_TEXTURE_TYPE_2D = 0,
  LVK_TEXTURE_TYPE_3D = 1,
  LVK_TEXTURE_TYPE_CUBE = 2,
};
typedef uint8_t lvk_sampler_filter_t;
enum {
  LVK_SAMPLER_FILTER_NEAREST = 0,
  LVK_SAMPLER_FILTER_LINEAR = 1,
};
typedef uint8_t lvk_sampler_mip_t;
enum {
  LVK_SAMPLER_MIP_DISABLED = 0,
  LVK_SAMPLER_MIP_NEAREST = 1,
  LVK_SAMPLER_MIP_LINEAR = 2,
};
typedef uint8_t lvk_sampler_wrap_t;
enum {
  LVK_SAMPLER_WRAP_REPEAT = 0,
  LVK_SAMPLER_WRAP_CLAMP = 1,
  LVK_SAMPLER_WRAP_CLAMP_TO_BORDER = 2,
  LVK_SAMPLER_WRAP_MIRROR_REPEAT = 3,
  LVK_SAMPLER_WRAP_MIRROR_CLAMP_TO_EDGE = 4,
};
typedef uint32_t lvk_hw_device_type_t;
enum {
  LVK_HW_DEVICE_TYPE_INTEGRATED = 1,
  LVK_HW_DEVICE_TYPE_DISCRETE = 2,
  LVK_HW_DEVICE_TYPE_EXTERNAL = 3,
  LVK_HW_DEVICE_TYPE_SOFTWARE = 4,
};
typedef uint32_t lvk_storage_type_t;
enum {
  LVK_STORAGE_TYPE_DEVICE = 0,
  LVK_STORAGE_TYPE_HOST_VISIBLE = 1,
  LVK_STORAGE_TYPE_MEMORYLESS = 2,
};
typedef uint8_t lvk_cull_mode_t;
enum {
  LVK_CULL_MODE_NONE = 0,
  LVK_CULL_MODE_FRONT = 1,
  LVK_CULL_MODE_BACK = 2,
};
typedef uint8_t lvk_winding_mode_t;
enum {
  LVK_WINDING_MODE_CCW = 0,
  LVK_WINDING_MODE_CW = 1,
};
typedef uint8_t lvk_compare_op_t;
enum {
  LVK_COMPARE_OP_NEVER = 0,
  LVK_COMPARE_OP_LESS = 1,
  LVK_COMPARE_OP_EQUAL = 2,
  LVK_COMPARE_OP_LESS_EQUAL = 3,
  LVK_COMPARE_OP_GREATER = 4,
  LVK_COMPARE_OP_NOT_EQUAL = 5,
  LVK_COMPARE_OP_GREATER_EQUAL = 6,
  LVK_COMPARE_OP_ALWAYS_PASS = 7,
};
typedef uint8_t lvk_stencil_op_t;
enum {
  LVK_STENCIL_OP_KEEP = 0,
  LVK_STENCIL_OP_ZERO = 1,
  LVK_STENCIL_OP_REPLACE = 2,
  LVK_STENCIL_OP_INCREMENT_CLAMP = 3,
  LVK_STENCIL_OP_DECREMENT_CLAMP = 4,
  LVK_STENCIL_OP_INVERT = 5,
  LVK_STENCIL_OP_INCREMENT_WRAP = 6,
  LVK_STENCIL_OP_DECREMENT_WRAP = 7,
};
typedef uint8_t lvk_blend_op_t;
enum {
  LVK_BLEND_OP_ADD = 0,
  LVK_BLEND_OP_SUBTRACT = 1,
  LVK_BLEND_OP_REVERSE_SUBTRACT = 2,
  LVK_BLEND_OP_MIN = 3,
  LVK_BLEND_OP_MAX = 4,
};
typedef uint8_t lvk_blend_factor_t;
enum {
  LVK_BLEND_FACTOR_ZERO = 0,
  LVK_BLEND_FACTOR_ONE = 1,
  LVK_BLEND_FACTOR_SRC_COLOR = 2,
  LVK_BLEND_FACTOR_ONE_MINUS_SRC_COLOR = 3,
  LVK_BLEND_FACTOR_SRC_ALPHA = 4,
  LVK_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA = 5,
  LVK_BLEND_FACTOR_DST_COLOR = 6,
  LVK_BLEND_FACTOR_ONE_MINUS_DST_COLOR = 7,
  LVK_BLEND_FACTOR_DST_ALPHA = 8,
  LVK_BLEND_FACTOR_ONE_MINUS_DST_ALPHA = 9,
  LVK_BLEND_FACTOR_SRC_ALPHA_SATURATED = 10,
  LVK_BLEND_FACTOR_BLEND_COLOR = 11,
  LVK_BLEND_FACTOR_ONE_MINUS_BLEND_COLOR = 12,
  LVK_BLEND_FACTOR_BLEND_ALPHA = 13,
  LVK_BLEND_FACTOR_ONE_MINUS_BLEND_ALPHA = 14,
  LVK_BLEND_FACTOR_SRC1_COLOR = 15,
  LVK_BLEND_FACTOR_ONE_MINUS_SRC1_COLOR = 16,
  LVK_BLEND_FACTOR_SRC1_ALPHA = 17,
  LVK_BLEND_FACTOR_ONE_MINUS_SRC1_ALPHA = 18,
};
typedef uint8_t lvk_polygon_mode_t;
enum {
  LVK_POLYGON_MODE_FILL = 0,
  LVK_POLYGON_MODE_LINE = 1,
  LVK_POLYGON_MODE_POINT = 2,
};
typedef uint8_t lvk_shading_rate_combiner_op_t;
enum {
  LVK_SHADING_RATE_COMBINER_OP_KEEP = 0,
  LVK_SHADING_RATE_COMBINER_OP_REPLACE = 1,
  LVK_SHADING_RATE_COMBINER_OP_MIN = 2,
  LVK_SHADING_RATE_COMBINER_OP_MAX = 3,
  LVK_SHADING_RATE_COMBINER_OP_MUL = 4,
};
typedef uint8_t lvk_vertex_format_t;
enum {
  LVK_VERTEX_FORMAT_INVALID = 0,
  LVK_VERTEX_FORMAT_FLOAT1 = 1,
  LVK_VERTEX_FORMAT_FLOAT2 = 2,
  LVK_VERTEX_FORMAT_FLOAT3 = 3,
  LVK_VERTEX_FORMAT_FLOAT4 = 4,
  LVK_VERTEX_FORMAT_BYTE1 = 5,
  LVK_VERTEX_FORMAT_BYTE2 = 6,
  LVK_VERTEX_FORMAT_BYTE3 = 7,
  LVK_VERTEX_FORMAT_BYTE4 = 8,
  LVK_VERTEX_FORMAT_U_BYTE1 = 9,
  LVK_VERTEX_FORMAT_U_BYTE2 = 10,
  LVK_VERTEX_FORMAT_U_BYTE3 = 11,
  LVK_VERTEX_FORMAT_U_BYTE4 = 12,
  LVK_VERTEX_FORMAT_SHORT1 = 13,
  LVK_VERTEX_FORMAT_SHORT2 = 14,
  LVK_VERTEX_FORMAT_SHORT3 = 15,
  LVK_VERTEX_FORMAT_SHORT4 = 16,
  LVK_VERTEX_FORMAT_U_SHORT1 = 17,
  LVK_VERTEX_FORMAT_U_SHORT2 = 18,
  LVK_VERTEX_FORMAT_U_SHORT3 = 19,
  LVK_VERTEX_FORMAT_U_SHORT4 = 20,
  LVK_VERTEX_FORMAT_BYTE2_NORM = 21,
  LVK_VERTEX_FORMAT_BYTE4_NORM = 22,
  LVK_VERTEX_FORMAT_U_BYTE2_NORM = 23,
  LVK_VERTEX_FORMAT_U_BYTE4_NORM = 24,
  LVK_VERTEX_FORMAT_SHORT2_NORM = 25,
  LVK_VERTEX_FORMAT_SHORT4_NORM = 26,
  LVK_VERTEX_FORMAT_U_SHORT2_NORM = 27,
  LVK_VERTEX_FORMAT_U_SHORT4_NORM = 28,
  LVK_VERTEX_FORMAT_INT1 = 29,
  LVK_VERTEX_FORMAT_INT2 = 30,
  LVK_VERTEX_FORMAT_INT3 = 31,
  LVK_VERTEX_FORMAT_INT4 = 32,
  LVK_VERTEX_FORMAT_U_INT1 = 33,
  LVK_VERTEX_FORMAT_U_INT2 = 34,
  LVK_VERTEX_FORMAT_U_INT3 = 35,
  LVK_VERTEX_FORMAT_U_INT4 = 36,
  LVK_VERTEX_FORMAT_HALF_FLOAT1 = 37,
  LVK_VERTEX_FORMAT_HALF_FLOAT2 = 38,
  LVK_VERTEX_FORMAT_HALF_FLOAT3 = 39,
  LVK_VERTEX_FORMAT_HALF_FLOAT4 = 40,
  LVK_VERTEX_FORMAT_INT_2_10_10_10_REV = 41,
};
typedef uint8_t lvk_vertex_input_rate_t;
enum {
  LVK_VERTEX_INPUT_RATE_VERTEX = 0,
  LVK_VERTEX_INPUT_RATE_INSTANCE = 1,
};
typedef uint8_t lvk_format_t;
enum {
  LVK_FORMAT_INVALID = 0,
  LVK_FORMAT_R_UN8 = 1,
  LVK_FORMAT_R_UI8 = 2,
  LVK_FORMAT_R_I8 = 3,
  LVK_FORMAT_R_UI16 = 4,
  LVK_FORMAT_R_I16 = 5,
  LVK_FORMAT_R_UI32 = 6,
  LVK_FORMAT_R_I32 = 7,
  LVK_FORMAT_R_UN16 = 8,
  LVK_FORMAT_R_F16 = 9,
  LVK_FORMAT_R_F32 = 10,
  LVK_FORMAT_A_UN8 = 11,
  LVK_FORMAT_RG_UN8 = 12,
  LVK_FORMAT_RG_UI8 = 13,
  LVK_FORMAT_RG_I8 = 14,
  LVK_FORMAT_RG_UI16 = 15,
  LVK_FORMAT_RG_I16 = 16,
  LVK_FORMAT_RG_UI32 = 17,
  LVK_FORMAT_RG_I32 = 18,
  LVK_FORMAT_RG_UN16 = 19,
  LVK_FORMAT_RG_F16 = 20,
  LVK_FORMAT_RG_F32 = 21,
  LVK_FORMAT_RGBA_UN8 = 22,
  LVK_FORMAT_RGBA_SN8 = 23,
  LVK_FORMAT_RGBA_UI8 = 24,
  LVK_FORMAT_RGBA_I8 = 25,
  LVK_FORMAT_RGBA_UI16 = 26,
  LVK_FORMAT_RGBA_I16 = 27,
  LVK_FORMAT_RGBA_UI32 = 28,
  LVK_FORMAT_RGBA_I32 = 29,
  LVK_FORMAT_RGBA_UN16 = 30,
  LVK_FORMAT_RGBA_F16 = 31,
  LVK_FORMAT_RGBA_F32 = 32,
  LVK_FORMAT_RGBA_SRGB8 = 33,
  LVK_FORMAT_BGRA_UN8 = 34,
  LVK_FORMAT_BGRA_UI8 = 35,
  LVK_FORMAT_BGRA_SRGB8 = 36,
  LVK_FORMAT_A2_B10_G10_R10_UN = 37,
  LVK_FORMAT_A2_R10_G10_B10_UN = 38,
  LVK_FORMAT_A1_B5_G5_R5_UN = 39,
  LVK_FORMAT_R4_G4_B4_A4_UN = 40,
  LVK_FORMAT_R5_G5_B5_A1_UN = 41,
  LVK_FORMAT_R5_G6_B5_UN = 42,
  LVK_FORMAT_B10_G11_R11_UF = 43,
  LVK_FORMAT_E5_B9_G9_R9_UF = 44,
  LVK_FORMAT_ETC2_RGB8 = 45,
  LVK_FORMAT_ETC2_SRGB8 = 46,
  LVK_FORMAT_EAC_RG11 = 47,
  LVK_FORMAT_BC1_RGBA = 48,
  LVK_FORMAT_BC1_SRGBA = 49,
  LVK_FORMAT_BC3_RGBA = 50,
  LVK_FORMAT_BC3_SRGBA = 51,
  LVK_FORMAT_BC4R = 52,
  LVK_FORMAT_BC5_RG = 53,
  LVK_FORMAT_BC5_RG_SN = 54,
  LVK_FORMAT_BC7_RGBA = 55,
  LVK_FORMAT_BC7_SRGBA = 56,
  LVK_FORMAT_ASTC_4X4_RGBA = 57,
  LVK_FORMAT_ASTC_4X4_SRGBA = 58,
  LVK_FORMAT_ASTC_5X5_RGBA = 59,
  LVK_FORMAT_ASTC_5X5_SRGBA = 60,
  LVK_FORMAT_ASTC_6X6_RGBA = 61,
  LVK_FORMAT_ASTC_6X6_SRGBA = 62,
  LVK_FORMAT_Z_UN16 = 63,
  LVK_FORMAT_Z_UN24 = 64,
  LVK_FORMAT_Z_F32 = 65,
  LVK_FORMAT_Z_UN24S_UI8 = 66,
  LVK_FORMAT_Z_F32S_UI8 = 67,
  LVK_FORMAT_S_UI8 = 68,
  LVK_FORMAT_YUV_NV12 = 69,
  LVK_FORMAT_YUV_420P = 70,
};
typedef uint8_t lvk_load_op_t;
enum {
  LVK_LOAD_OP_LOAD = 0,
  LVK_LOAD_OP_CLEAR = 1,
  LVK_LOAD_OP_DONT_CARE = 2,
  LVK_LOAD_OP_NONE = 3,
  LVK_LOAD_OP_INVALID = 255,
};
typedef uint8_t lvk_store_op_t;
enum {
  LVK_STORE_OP_STORE = 0,
  LVK_STORE_OP_DONT_CARE = 1,
  LVK_STORE_OP_NONE = 2,
};
typedef uint8_t lvk_resolve_mode_t;
enum {
  LVK_RESOLVE_MODE_NONE = 0,
  LVK_RESOLVE_MODE_SAMPLE_ZERO = 1,
  LVK_RESOLVE_MODE_AVERAGE = 2,
  LVK_RESOLVE_MODE_MIN = 3,
  LVK_RESOLVE_MODE_MAX = 4,
};
typedef uint8_t lvk_shader_stage_t;
enum {
  LVK_STAGE_VERT = 0,
  LVK_STAGE_TESC = 1,
  LVK_STAGE_TESE = 2,
  LVK_STAGE_GEOM = 3,
  LVK_STAGE_FRAG = 4,
  LVK_STAGE_COMP = 5,
  LVK_STAGE_TASK = 6,
  LVK_STAGE_MESH = 7,
  LVK_STAGE_RAY_GEN = 8,
  LVK_STAGE_ANY_HIT = 9,
  LVK_STAGE_CLOSEST_HIT = 10,
  LVK_STAGE_MISS = 11,
  LVK_STAGE_INTERSECTION = 12,
  LVK_STAGE_CALLABLE = 13,
  LVK_STAGE_DATA_GRAPH = 14,
};
typedef uint8_t lvk_color_component_bits_t;
enum {
  LVK_COLOR_COMPONENT_BIT_R = 1,
  LVK_COLOR_COMPONENT_BIT_G = 2,
  LVK_COLOR_COMPONENT_BIT_B = 4,
  LVK_COLOR_COMPONENT_BIT_A = 8,
  LVK_COLOR_COMPONENT_BIT_ALL = 15,
};
typedef uint8_t lvk_buffer_usage_bits_t;
enum {
  LVK_BUFFER_USAGE_BITS_INDEX = 1,
  LVK_BUFFER_USAGE_BITS_VERTEX = 2,
  LVK_BUFFER_USAGE_BITS_UNIFORM = 4,
  LVK_BUFFER_USAGE_BITS_STORAGE = 8,
  LVK_BUFFER_USAGE_BITS_INDIRECT = 16,
  LVK_BUFFER_USAGE_BITS_SHADER_BINDING_TABLE = 32,
  LVK_BUFFER_USAGE_BITS_ACCEL_STRUCT_BUILD_INPUT_READ_ONLY = 64,
  LVK_BUFFER_USAGE_BITS_ACCEL_STRUCT_STORAGE = 128,
};
typedef uint8_t lvk_texture_usage_bits_t;
enum {
  LVK_TEXTURE_USAGE_BITS_SAMPLED = 1,
  LVK_TEXTURE_USAGE_BITS_STORAGE = 2,
  LVK_TEXTURE_USAGE_BITS_ATTACHMENT = 4,
  LVK_TEXTURE_USAGE_BITS_INPUT_ATTACHMENT = 8,
  LVK_TEXTURE_USAGE_BITS_FRAGMENT_DENSITY_MAP = 16,
  LVK_TEXTURE_USAGE_BITS_SHADING_RATE_ATTACHMENT = 32,
};
typedef uint32_t lvk_pipeline_stage_bits_t;
enum {
  LVK_PIPELINE_STAGE_BITS_DRAW_INDIRECT = 1,
  LVK_PIPELINE_STAGE_BITS_VERTEX_INPUT = 2,
  LVK_PIPELINE_STAGE_BITS_VERTEX = 4,
  LVK_PIPELINE_STAGE_BITS_TASK = 8,
  LVK_PIPELINE_STAGE_BITS_MESH = 16,
  LVK_PIPELINE_STAGE_BITS_DEPTH_STENCIL = 32,
  LVK_PIPELINE_STAGE_BITS_FRAGMENT = 64,
  LVK_PIPELINE_STAGE_BITS_COLOR_ATTACHMENT = 128,
  LVK_PIPELINE_STAGE_BITS_COMPUTE = 256,
  LVK_PIPELINE_STAGE_BITS_RAY_TRACING = 512,
  LVK_PIPELINE_STAGE_BITS_ACCEL_STRUCT_BUILD = 1024,
  LVK_PIPELINE_STAGE_BITS_TRANSFER = 2048,
  LVK_PIPELINE_STAGE_BITS_HOST = 4096,
  LVK_PIPELINE_STAGE_BITS_ALL_COMMANDS = 8192,
};
typedef uint32_t lvk_access_bits_t;
enum {
  LVK_ACCESS_BITS_INDIRECT_READ = 1,
  LVK_ACCESS_BITS_INDEX_READ = 2,
  LVK_ACCESS_BITS_VERTEX_ATTRIBUTE_READ = 4,
  LVK_ACCESS_BITS_SHADER_READ = 8,
  LVK_ACCESS_BITS_SHADER_WRITE = 16,
  LVK_ACCESS_BITS_COLOR_READ = 32,
  LVK_ACCESS_BITS_COLOR_WRITE = 64,
  LVK_ACCESS_BITS_DEPTH_STENCIL_READ = 128,
  LVK_ACCESS_BITS_DEPTH_STENCIL_WRITE = 256,
  LVK_ACCESS_BITS_TRANSFER_READ = 512,
  LVK_ACCESS_BITS_TRANSFER_WRITE = 1024,
  LVK_ACCESS_BITS_HOST_READ = 2048,
  LVK_ACCESS_BITS_HOST_WRITE = 4096,
  LVK_ACCESS_BITS_ACCEL_STRUCT_READ = 8192,
  LVK_ACCESS_BITS_ACCEL_STRUCT_WRITE = 16384,
};
typedef uint8_t lvk_swizzle_t;
enum {
  LVK_SWIZZLE_DEFAULT = 0,
  LVK_SWIZZLE_0 = 1,
  LVK_SWIZZLE_1 = 2,
  LVK_SWIZZLE_R = 3,
  LVK_SWIZZLE_G = 4,
  LVK_SWIZZLE_B = 5,
  LVK_SWIZZLE_A = 6,
};
typedef uint8_t lvk_texture_aspect_t;
enum {
  LVK_TEXTURE_ASPECT_DEFAULT = 0,
  LVK_TEXTURE_ASPECT_DEPTH = 1,
  LVK_TEXTURE_ASPECT_STENCIL = 2,
  LVK_TEXTURE_ASPECT_PLANE0 = 3,
  LVK_TEXTURE_ASPECT_PLANE1 = 4,
  LVK_TEXTURE_ASPECT_PLANE2 = 5,
};
typedef uint8_t lvk_accel_struct_type_t;
enum {
  LVK_ACCEL_STRUCT_TYPE_INVALID = 0,
  LVK_ACCEL_STRUCT_TYPE_TLAS = 1,
  LVK_ACCEL_STRUCT_TYPE_BLAS = 2,
  LVK_ACCEL_STRUCT_TYPE_OPACITY_MICROMAP = 3,
};
typedef uint8_t lvk_accel_struct_geom_type_t;
enum {
  LVK_ACCEL_STRUCT_GEOM_TYPE_TRIANGLES = 0,
  LVK_ACCEL_STRUCT_GEOM_TYPE_AAB_BS = 1,
  LVK_ACCEL_STRUCT_GEOM_TYPE_INSTANCES = 2,
};
typedef uint8_t lvk_accel_struct_build_flag_bits_t;
enum {
  LVK_ACCEL_STRUCT_BUILD_FLAG_BITS_ALLOW_UPDATE = 1,
  LVK_ACCEL_STRUCT_BUILD_FLAG_BITS_ALLOW_COMPACTION = 2,
  LVK_ACCEL_STRUCT_BUILD_FLAG_BITS_PREFER_FAST_TRACE = 4,
  LVK_ACCEL_STRUCT_BUILD_FLAG_BITS_PREFER_FAST_BUILD = 8,
  LVK_ACCEL_STRUCT_BUILD_FLAG_BITS_LOW_MEMORY = 16,
  LVK_ACCEL_STRUCT_BUILD_FLAG_BITS_ALLOW_DISABLE_OPACITY_MICROMAPS = 32,
  LVK_ACCEL_STRUCT_BUILD_FLAG_BITS_ALLOW_DATA_ACCESS = 64,
};
typedef uint8_t lvk_accel_struct_geometry_flag_bits_t;
enum {
  LVK_ACCEL_STRUCT_GEOMETRY_FLAG_BITS_OPAQUE = 1,
  LVK_ACCEL_STRUCT_GEOMETRY_FLAG_BITS_NO_DUPLICATE_ANY_HIT = 2,
};
typedef uint8_t lvk_accel_struct_instance_flag_bits_t;
enum {
  LVK_ACCEL_STRUCT_INSTANCE_FLAG_BITS_TRIANGLE_FACING_CULL_DISABLE = 1,
  LVK_ACCEL_STRUCT_INSTANCE_FLAG_BITS_TRIANGLE_FLIP_FACING = 2,
  LVK_ACCEL_STRUCT_INSTANCE_FLAG_BITS_FORCE_OPAQUE = 4,
  LVK_ACCEL_STRUCT_INSTANCE_FLAG_BITS_FORCE_NO_OPAQUE = 8,
  LVK_ACCEL_STRUCT_INSTANCE_FLAG_BITS_FORCE_OPACITY_MICROMAP2_STATE = 16,
  LVK_ACCEL_STRUCT_INSTANCE_FLAG_BITS_DISABLE_OPACITY_MICROMAPS = 32,
};
typedef uint8_t lvk_opacity_micromap_format_t;
enum {
  LVK_OPACITY_MICROMAP_FORMAT_2_STATE = 1,
  LVK_OPACITY_MICROMAP_FORMAT_4_STATE = 2,
};
typedef int32_t lvk_opacity_micromap_special_index_t;
enum {
  LVK_OPACITY_MICROMAP_SPECIAL_INDEX_FULLY_TRANSPARENT = -1,
  LVK_OPACITY_MICROMAP_SPECIAL_INDEX_FULLY_OPAQUE = -2,
  LVK_OPACITY_MICROMAP_SPECIAL_INDEX_FULLY_UNKNOWN_TRANSPARENT = -3,
  LVK_OPACITY_MICROMAP_SPECIAL_INDEX_FULLY_UNKNOWN_OPAQUE = -4,
};
typedef uint32_t lvk_vulkan_version_t;
enum {
  LVK_VULKAN_VERSION_1_3 = 0,
  LVK_VULKAN_VERSION_1_4 = 1,
};
typedef int32_t lvk_result_code_t;
enum {
  LVK_RESULT_CODE_OK = 0,
  LVK_RESULT_CODE_ARGUMENT_OUT_OF_RANGE = 1,
  LVK_RESULT_CODE_RUNTIME_ERROR = 2,
};

typedef uint8_t lvk_buffer_usage_flags_t;
typedef uint8_t lvk_texture_usage_flags_t;
typedef uint32_t lvk_pipeline_stage_flags_t;
typedef uint32_t lvk_access_flags_t;

/* handles */
typedef struct lvk_compute_pipeline_handle_t {
  uint32_t index;
  uint32_t gen;
} lvk_compute_pipeline_handle_t;
static inline bool lvk_compute_pipeline_handle_valid(lvk_compute_pipeline_handle_t h) { return h.gen != 0; }
typedef struct lvk_render_pipeline_handle_t {
  uint32_t index;
  uint32_t gen;
} lvk_render_pipeline_handle_t;
static inline bool lvk_render_pipeline_handle_valid(lvk_render_pipeline_handle_t h) { return h.gen != 0; }
typedef struct lvk_ray_tracing_pipeline_handle_t {
  uint32_t index;
  uint32_t gen;
} lvk_ray_tracing_pipeline_handle_t;
static inline bool lvk_ray_tracing_pipeline_handle_valid(lvk_ray_tracing_pipeline_handle_t h) { return h.gen != 0; }
typedef struct lvk_shader_module_handle_t {
  uint32_t index;
  uint32_t gen;
} lvk_shader_module_handle_t;
static inline bool lvk_shader_module_handle_valid(lvk_shader_module_handle_t h) { return h.gen != 0; }
typedef struct lvk_sampler_handle_t {
  uint32_t index;
  uint32_t gen;
} lvk_sampler_handle_t;
static inline bool lvk_sampler_handle_valid(lvk_sampler_handle_t h) { return h.gen != 0; }
typedef struct lvk_buffer_handle_t {
  uint32_t index;
  uint32_t gen;
} lvk_buffer_handle_t;
static inline bool lvk_buffer_handle_valid(lvk_buffer_handle_t h) { return h.gen != 0; }
typedef struct lvk_texture_handle_t {
  uint32_t index;
  uint32_t gen;
} lvk_texture_handle_t;
static inline bool lvk_texture_handle_valid(lvk_texture_handle_t h) { return h.gen != 0; }
typedef struct lvk_query_pool_handle_t {
  uint32_t index;
  uint32_t gen;
} lvk_query_pool_handle_t;
static inline bool lvk_query_pool_handle_valid(lvk_query_pool_handle_t h) { return h.gen != 0; }
typedef struct lvk_accel_struct_handle_t {
  uint32_t index;
  uint32_t gen;
} lvk_accel_struct_handle_t;
static inline bool lvk_accel_struct_handle_valid(lvk_accel_struct_handle_t h) { return h.gen != 0; }

/* forward declarations */
typedef struct lvk_hw_device_desc_t lvk_hw_device_desc_t;
typedef struct lvk_result_t lvk_result_t;
typedef struct lvk_scissor_rect_t lvk_scissor_rect_t;
typedef struct lvk_dimensions_t lvk_dimensions_t;
typedef struct lvk_viewport_t lvk_viewport_t;
typedef struct lvk_sampler_state_desc_t lvk_sampler_state_desc_t;
typedef struct lvk_stencil_face_state_t lvk_stencil_face_state_t;
typedef struct lvk_stencil_state_t lvk_stencil_state_t;
typedef struct lvk_depth_state_t lvk_depth_state_t;
typedef union lvk_clear_color_value_t lvk_clear_color_value_t;
typedef struct lvk_vertex_input_t lvk_vertex_input_t;
typedef struct lvk_vertex_attribute_t lvk_vertex_attribute_t;
typedef struct lvk_vertex_input_binding_t lvk_vertex_input_binding_t;
typedef struct lvk_color_attachment_t lvk_color_attachment_t;
typedef struct lvk_shader_module_desc_t lvk_shader_module_desc_t;
typedef struct lvk_specialization_constant_entry_t lvk_specialization_constant_entry_t;
typedef struct lvk_specialization_constant_desc_t lvk_specialization_constant_desc_t;
typedef struct lvk_render_pipeline_desc_t lvk_render_pipeline_desc_t;
typedef struct lvk_compute_pipeline_desc_t lvk_compute_pipeline_desc_t;
typedef struct lvk_ray_tracing_hit_group_desc_t lvk_ray_tracing_hit_group_desc_t;
typedef struct lvk_ray_tracing_pipeline_desc_t lvk_ray_tracing_pipeline_desc_t;
typedef struct lvk_render_pass_t lvk_render_pass_t;
typedef struct lvk_render_pass_attachment_desc_t lvk_render_pass_attachment_desc_t;
typedef struct lvk_framebuffer_t lvk_framebuffer_t;
typedef struct lvk_framebuffer_attachment_desc_t lvk_framebuffer_attachment_desc_t;
typedef struct lvk_buffer_desc_t lvk_buffer_desc_t;
typedef struct lvk_offset3d_t lvk_offset3d_t;
typedef struct lvk_texture_layers_t lvk_texture_layers_t;
typedef struct lvk_texture_range_desc_t lvk_texture_range_desc_t;
typedef struct lvk_component_mapping_t lvk_component_mapping_t;
typedef struct lvk_texture_desc_t lvk_texture_desc_t;
typedef struct lvk_texture_view_desc_t lvk_texture_view_desc_t;
typedef struct lvk_opacity_micromap_usage_t lvk_opacity_micromap_usage_t;
typedef struct lvk_opacity_micromap_triangle_t lvk_opacity_micromap_triangle_t;
typedef struct lvk_accel_struct_sizes_t lvk_accel_struct_sizes_t;
typedef struct lvk_accel_struct_build_range_t lvk_accel_struct_build_range_t;
typedef struct lvk_mat3x4_t lvk_mat3x4_t;
typedef struct lvk_accel_struct_instance_t lvk_accel_struct_instance_t;
typedef struct lvk_accel_struct_desc_t lvk_accel_struct_desc_t;
typedef struct lvk_submit_handle_t lvk_submit_handle_t;
typedef struct lvk_dependencies_t lvk_dependencies_t;
typedef struct lvk_barrier_t lvk_barrier_t;
typedef struct lvk_context_config_t lvk_context_config_t;

/* structs */
struct lvk_hw_device_desc_t {
  uintptr_t guid;
  lvk_hw_device_type_t type;
  char name[LVK_MAX_PHYSICAL_DEVICE_NAME_SIZE];
};

struct lvk_result_t {
  lvk_result_code_t code;
  const char* message;
};

struct lvk_scissor_rect_t {
  uint32_t x;
  uint32_t y;
  uint32_t width;
  uint32_t height;
};

struct lvk_dimensions_t {
  uint32_t width;
  uint32_t height;
  uint32_t depth;
};

struct lvk_viewport_t {
  float x;
  float y;
  float width;
  float height;
  float minDepth;
  float maxDepth;
};

struct lvk_sampler_state_desc_t {
  lvk_sampler_filter_t minFilter;
  lvk_sampler_filter_t magFilter;
  lvk_sampler_mip_t mipMap;
  lvk_sampler_wrap_t wrapU;
  lvk_sampler_wrap_t wrapV;
  lvk_sampler_wrap_t wrapW;
  lvk_compare_op_t depthCompareOp;
  uint8_t mipLodMin;
  uint8_t mipLodMax;
  uint8_t maxAnisotropic;
  bool depthCompareEnabled;
  const char* debugName;
};

struct lvk_stencil_face_state_t {
  lvk_stencil_op_t stencilFailureOp;
  lvk_stencil_op_t depthFailureOp;
  lvk_stencil_op_t depthStencilPassOp;
  lvk_compare_op_t stencilCompareOp;
  uint32_t readMask;
  uint32_t writeMask;
  uint32_t reference;
};

struct lvk_stencil_state_t {
  bool enable;
  lvk_stencil_face_state_t front;
  lvk_stencil_face_state_t back;
};

struct lvk_depth_state_t {
  lvk_compare_op_t compareOp;
  bool isDepthWriteEnabled;
  bool isDepthBoundsTestEnabled;
};

union lvk_clear_color_value_t {
  float float32[4];
  int32_t int32[4];
  uint32_t uint32[4];
};

struct lvk_vertex_attribute_t {
  uint32_t location;
  uint32_t binding;
  lvk_vertex_format_t format;
  uintptr_t offset;
};

struct lvk_vertex_input_binding_t {
  uint32_t stride;
  lvk_vertex_input_rate_t inputRate;
};

struct lvk_vertex_input_t {
  lvk_vertex_attribute_t attributes[16];
  lvk_vertex_input_binding_t inputBindings[16];
};

struct lvk_color_attachment_t {
  lvk_format_t format;
  bool blendEnabled;
  lvk_blend_op_t rgbBlendOp;
  lvk_blend_op_t alphaBlendOp;
  lvk_blend_factor_t srcRGBBlendFactor;
  lvk_blend_factor_t srcAlphaBlendFactor;
  lvk_blend_factor_t dstRGBBlendFactor;
  lvk_blend_factor_t dstAlphaBlendFactor;
  uint8_t colorWriteMask;
};

struct lvk_shader_module_desc_t {
  lvk_shader_stage_t stage;
  const char* data;
  size_t dataSize;
  bool optimizeSPIRV;
  const char* entryPointName;
  const char* debugName;
};

struct lvk_specialization_constant_entry_t {
  uint32_t constantId;
  uint32_t offset;
  size_t size;
};

struct lvk_specialization_constant_desc_t {
  lvk_specialization_constant_entry_t entries[LVK_SPECIALIZATION_CONSTANTS_MAX];
  const void* data;
  size_t dataSize;
};

struct lvk_render_pipeline_desc_t {
  lvk_topology_t topology;
  lvk_vertex_input_t vertexInput;
  lvk_shader_module_handle_t smVert;
  lvk_shader_module_handle_t smTesc;
  lvk_shader_module_handle_t smTese;
  lvk_shader_module_handle_t smGeom;
  lvk_shader_module_handle_t smTask;
  lvk_shader_module_handle_t smMesh;
  lvk_shader_module_handle_t smFrag;
  lvk_specialization_constant_desc_t specInfo;
  const char* entryPointVert;
  const char* entryPointTesc;
  const char* entryPointTese;
  const char* entryPointGeom;
  const char* entryPointTask;
  const char* entryPointMesh;
  const char* entryPointFrag;
  lvk_color_attachment_t color[LVK_MAX_COLOR_ATTACHMENTS];
  lvk_format_t depthFormat;
  lvk_format_t stencilFormat;
  lvk_cull_mode_t cullMode;
  lvk_winding_mode_t frontFace;
  lvk_polygon_mode_t polygonMode;
  bool provokingVertexLast;
  uint32_t samplesCount;
  uint32_t patchControlPoints;
  float minSampleShading;
  bool alphaToCoverage;
  const char* debugName;
};

struct lvk_compute_pipeline_desc_t {
  lvk_shader_module_handle_t smComp;
  lvk_specialization_constant_desc_t specInfo;
  const char* entryPoint;
  const char* debugName;
};

struct lvk_ray_tracing_hit_group_desc_t {
  lvk_shader_module_handle_t smClosestHit;
  lvk_shader_module_handle_t smAnyHit;
  lvk_shader_module_handle_t smIntersection;
};

typedef struct lvk_span_shader_module_handle_t {
  lvk_shader_module_handle_t* data;
  size_t size;
} lvk_span_shader_module_handle_t;

typedef struct lvk_span_ray_tracing_hit_group_desc_t {
  lvk_ray_tracing_hit_group_desc_t* data;
  size_t size;
} lvk_span_ray_tracing_hit_group_desc_t;

struct lvk_ray_tracing_pipeline_desc_t {
  lvk_span_shader_module_handle_t smRayGen;
  lvk_span_shader_module_handle_t smMiss;
  lvk_span_shader_module_handle_t smCallable;
  lvk_span_ray_tracing_hit_group_desc_t hitGroups;
  lvk_specialization_constant_desc_t specInfo;
  uint32_t maxRecursionDepth;
  uint32_t stackSize;
  const char* debugName;
};

struct lvk_render_pass_attachment_desc_t {
  lvk_load_op_t loadOp;
  lvk_store_op_t storeOp;
  lvk_resolve_mode_t resolveMode;
  uint8_t layer;
  uint8_t level;
  lvk_clear_color_value_t clearColor;
  float clearDepth;
  uint32_t clearStencil;
};

struct lvk_render_pass_t {
  lvk_render_pass_attachment_desc_t color[LVK_MAX_COLOR_ATTACHMENTS];
  lvk_render_pass_attachment_desc_t depth;
  lvk_render_pass_attachment_desc_t stencil;
  uint32_t layerCount;
  uint32_t viewMask;
  uint32_t attachmentlessWidth;
  uint32_t attachmentlessHeight;
};

struct lvk_framebuffer_attachment_desc_t {
  lvk_texture_handle_t texture;
  lvk_texture_handle_t resolveTexture;
};

struct lvk_framebuffer_t {
  lvk_framebuffer_attachment_desc_t color[LVK_MAX_COLOR_ATTACHMENTS];
  lvk_framebuffer_attachment_desc_t depthStencil;
  lvk_texture_handle_t fragmentDensityMap;
  lvk_texture_handle_t shadingRateAttachment;
  lvk_dimensions_t shadingRateAttachmentTexelSize;
  const char* debugName;
};

struct lvk_buffer_desc_t {
  lvk_buffer_usage_flags_t usage;
  lvk_storage_type_t storage;
  size_t size;
  const void* data;
  const char* debugName;
};

struct lvk_offset3d_t {
  int32_t x;
  int32_t y;
  int32_t z;
};

struct lvk_texture_layers_t {
  uint32_t mipLevel;
  uint32_t layer;
  uint32_t numLayers;
};

struct lvk_texture_range_desc_t {
  lvk_offset3d_t offset;
  lvk_dimensions_t dimensions;
  uint32_t layer;
  uint32_t numLayers;
  uint32_t mipLevel;
  uint32_t numMipLevels;
};

struct lvk_component_mapping_t {
  lvk_swizzle_t r;
  lvk_swizzle_t g;
  lvk_swizzle_t b;
  lvk_swizzle_t a;
};

struct lvk_texture_desc_t {
  lvk_texture_type_t type;
  lvk_format_t format;
  lvk_dimensions_t dimensions;
  uint32_t numLayers;
  uint32_t numSamples;
  lvk_texture_usage_flags_t usage;
  uint32_t numMipLevels;
  lvk_storage_type_t storage;
  lvk_component_mapping_t components;
  const void* data;
  uint32_t dataNumMipLevels;
  bool generateMipmaps;
  const char* debugName;
};

struct lvk_texture_view_desc_t {
  lvk_texture_type_t type;
  uint32_t layer;
  uint32_t numLayers;
  uint32_t mipLevel;
  uint32_t numMipLevels;
  lvk_component_mapping_t components;
  lvk_texture_aspect_t aspect;
};

struct lvk_opacity_micromap_usage_t {
  uint32_t count;
  uint32_t subdivisionLevel;
  lvk_opacity_micromap_format_t format;
};

struct lvk_opacity_micromap_triangle_t {
  uint32_t dataOffset;
  uint16_t subdivisionLevel;
  uint16_t format;
};

struct lvk_accel_struct_sizes_t {
  uint64_t accelerationStructureSize;
  uint64_t updateScratchSize;
  uint64_t buildScratchSize;
};

struct lvk_accel_struct_build_range_t {
  uint32_t primitiveCount;
  uint32_t primitiveOffset;
  uint32_t firstVertex;
  uint32_t transformOffset;
};

struct lvk_mat3x4_t {
  float matrix[3][4];
};

struct lvk_accel_struct_instance_t {
  lvk_mat3x4_t transform;
  uint32_t instanceCustomIndex : 24;
  uint32_t mask : 8;
  uint32_t instanceShaderBindingTableRecordOffset : 24;
  uint32_t flags : 8;
  uint64_t accelerationStructureReference;
};

struct lvk_accel_struct_desc_t {
  lvk_accel_struct_type_t type;
  lvk_accel_struct_geom_type_t geometryType;
  uint8_t geometryFlags;
  lvk_vertex_format_t vertexFormat;
  lvk_buffer_handle_t vertexBuffer;
  uint32_t vertexStride;
  uint32_t numVertices;
  lvk_index_format_t indexFormat;
  lvk_buffer_handle_t indexBuffer;
  lvk_buffer_handle_t transformBuffer;
  lvk_buffer_handle_t instancesBuffer;
  lvk_accel_struct_handle_t micromap;
  lvk_buffer_handle_t micromapIndexBuffer;
  lvk_buffer_handle_t micromapData;
  lvk_buffer_handle_t micromapTriangles;
  lvk_index_format_t micromapIndexFormat;
  uint32_t micromapIndexOffset;
  const lvk_opacity_micromap_usage_t* micromapUsageCounts;
  uint32_t micromapNumUsageCounts;
  lvk_accel_struct_build_range_t buildRange;
  uint8_t buildFlags;
  const char* debugName;
};

struct lvk_submit_handle_t {
  uint64_t handle;
};

typedef struct lvk_span_texture_handle_t {
  lvk_texture_handle_t* data;
  size_t size;
} lvk_span_texture_handle_t;

typedef struct lvk_span_buffer_handle_t {
  lvk_buffer_handle_t* data;
  size_t size;
} lvk_span_buffer_handle_t;

typedef struct lvk_span_submit_handle_t {
  lvk_submit_handle_t* data;
  size_t size;
} lvk_span_submit_handle_t;

struct lvk_dependencies_t {
  lvk_span_texture_handle_t sampledImages;
  lvk_span_texture_handle_t storageImages;
  lvk_span_buffer_handle_t buffers;
  lvk_span_texture_handle_t inputAttachments;
  lvk_span_submit_handle_t waitCompute;
  lvk_span_submit_handle_t waitGraphics;
};

struct lvk_barrier_t {
  lvk_pipeline_stage_flags_t srcStages;
  lvk_access_flags_t srcAccess;
  lvk_pipeline_stage_flags_t dstStages;
  lvk_access_flags_t dstAccess;
};

typedef struct lvk_span_accel_struct_handle_t {
  lvk_accel_struct_handle_t* data;
  size_t size;
} lvk_span_accel_struct_handle_t;

typedef struct lvk_span_const_dimensions_t {
  const lvk_dimensions_t* data;
  size_t size;
} lvk_span_const_dimensions_t;

struct lvk_context_config_t {
  lvk_vulkan_version_t vulkanVersion;
  bool terminateOnValidationError;
  bool enableValidation;
  bool enableValidationGpuAV;
  bool enableValidationSync;
  bool generateSPIRVDebugInfo;
  lvk_color_space_t swapchainRequestedColorSpace;
  bool swapchainUseSurfacePreTransform;
  const void* pipelineCacheData;
  size_t pipelineCacheDataSize;
  uint32_t maxRayRecursionDepth;
  lvk_present_mode_t presentModes[LVK_MAX_PRESENT_MODES];
  const char* layers[LVK_MAX_CUSTOM_LAYERS];
  const char* extensionsInstance[LVK_MAX_CUSTOM_EXTENSIONS];
  const char* extensionsDevice[LVK_MAX_CUSTOM_EXTENSIONS];
  void* extensionsDeviceFeatures;
  void* customVkGetInstanceProcAddr;
  bool enableHeadlessSurface;
  bool enableFragmentShadingRate;
  uint64_t maxStagingBufferSize;
};

/* default-initialized descriptors */
LVK_C_API lvk_hw_device_desc_t lvk_hw_device_desc_default(void);
LVK_C_API lvk_result_t lvk_result_default(void);
LVK_C_API lvk_scissor_rect_t lvk_scissor_rect_default(void);
LVK_C_API lvk_dimensions_t lvk_dimensions_default(void);
LVK_C_API lvk_viewport_t lvk_viewport_default(void);
LVK_C_API lvk_sampler_state_desc_t lvk_sampler_state_desc_default(void);
LVK_C_API lvk_stencil_face_state_t lvk_stencil_face_state_default(void);
LVK_C_API lvk_stencil_state_t lvk_stencil_state_default(void);
LVK_C_API lvk_depth_state_t lvk_depth_state_default(void);
LVK_C_API lvk_clear_color_value_t lvk_clear_color_value_default(void);
LVK_C_API lvk_vertex_input_t lvk_vertex_input_default(void);
LVK_C_API lvk_vertex_attribute_t lvk_vertex_attribute_default(void);
LVK_C_API lvk_vertex_input_binding_t lvk_vertex_input_binding_default(void);
LVK_C_API lvk_color_attachment_t lvk_color_attachment_default(void);
LVK_C_API lvk_specialization_constant_entry_t lvk_specialization_constant_entry_default(void);
LVK_C_API lvk_specialization_constant_desc_t lvk_specialization_constant_desc_default(void);
LVK_C_API lvk_render_pipeline_desc_t lvk_render_pipeline_desc_default(void);
LVK_C_API lvk_compute_pipeline_desc_t lvk_compute_pipeline_desc_default(void);
LVK_C_API lvk_ray_tracing_hit_group_desc_t lvk_ray_tracing_hit_group_desc_default(void);
LVK_C_API lvk_ray_tracing_pipeline_desc_t lvk_ray_tracing_pipeline_desc_default(void);
LVK_C_API lvk_render_pass_t lvk_render_pass_default(void);
LVK_C_API lvk_render_pass_attachment_desc_t lvk_render_pass_attachment_desc_default(void);
LVK_C_API lvk_framebuffer_t lvk_framebuffer_default(void);
LVK_C_API lvk_framebuffer_attachment_desc_t lvk_framebuffer_attachment_desc_default(void);
LVK_C_API lvk_buffer_desc_t lvk_buffer_desc_default(void);
LVK_C_API lvk_offset3d_t lvk_offset3d_default(void);
LVK_C_API lvk_texture_layers_t lvk_texture_layers_default(void);
LVK_C_API lvk_texture_range_desc_t lvk_texture_range_desc_default(void);
LVK_C_API lvk_component_mapping_t lvk_component_mapping_default(void);
LVK_C_API lvk_texture_desc_t lvk_texture_desc_default(void);
LVK_C_API lvk_texture_view_desc_t lvk_texture_view_desc_default(void);
LVK_C_API lvk_opacity_micromap_usage_t lvk_opacity_micromap_usage_default(void);
LVK_C_API lvk_opacity_micromap_triangle_t lvk_opacity_micromap_triangle_default(void);
LVK_C_API lvk_accel_struct_sizes_t lvk_accel_struct_sizes_default(void);
LVK_C_API lvk_accel_struct_build_range_t lvk_accel_struct_build_range_default(void);
LVK_C_API lvk_mat3x4_t lvk_mat3x4_default(void);
LVK_C_API lvk_accel_struct_instance_t lvk_accel_struct_instance_default(void);
LVK_C_API lvk_accel_struct_desc_t lvk_accel_struct_desc_default(void);
LVK_C_API lvk_submit_handle_t lvk_submit_handle_default(void);
LVK_C_API lvk_dependencies_t lvk_dependencies_default(void);
LVK_C_API lvk_barrier_t lvk_barrier_default(void);
LVK_C_API lvk_context_config_t lvk_context_config_default(void);

/* functions */
LVK_C_API bool lvk_is_quarter_turn(lvk_surface_transform_t transform);
LVK_C_API void lvk_get_surface_transform_rotation(lvk_surface_transform_t transform, float* outCos, float* outSin);
LVK_C_API void lvk_cmd_barrier(lvk_cmd_buffer_t* self, const lvk_barrier_t* barrier);
LVK_C_API void lvk_cmd_transition_to_general(lvk_cmd_buffer_t* self, const lvk_span_texture_handle_t* textures, lvk_shader_stage_t extraDstStage);
LVK_C_API void lvk_cmd_transition_to_shader_read_only(lvk_cmd_buffer_t* self, const lvk_span_texture_handle_t* textures, lvk_shader_stage_t extraDstStage);
LVK_C_API void lvk_cmd_transition_to_rendering_local_read(lvk_cmd_buffer_t* self, const lvk_span_texture_handle_t* textures);
/* defaults: colorRGBA = 0xffffffff */
LVK_C_API void lvk_cmd_push_debug_group_label(lvk_cmd_buffer_t* self, const char* label, uint32_t colorRGBA);
/* defaults: colorRGBA = 0xffffffff */
LVK_C_API void lvk_cmd_insert_debug_event_label(lvk_cmd_buffer_t* self, const char* label, uint32_t colorRGBA);
LVK_C_API void lvk_cmd_pop_debug_group_label(lvk_cmd_buffer_t* self);
LVK_C_API void lvk_cmd_bind_ray_tracing_pipeline(lvk_cmd_buffer_t* self, lvk_ray_tracing_pipeline_handle_t handle);
LVK_C_API void lvk_cmd_bind_compute_pipeline(lvk_cmd_buffer_t* self, lvk_compute_pipeline_handle_t handle);
/* defaults: deps = {0} */
LVK_C_API void lvk_cmd_dispatch(lvk_cmd_buffer_t* self, const lvk_dimensions_t* groupCount, const lvk_dependencies_t* deps);
/* defaults: indirectBufferOffset = 0, deps = {0} */
LVK_C_API void lvk_cmd_dispatch_indirect(lvk_cmd_buffer_t* self, lvk_buffer_handle_t indirectBuffer, size_t indirectBufferOffset, const lvk_dependencies_t* deps);
/* defaults: deps = {0} */
LVK_C_API void lvk_cmd_begin_rendering(lvk_cmd_buffer_t* self, const lvk_render_pass_t* renderPass, const lvk_framebuffer_t* desc, const lvk_dependencies_t* deps);
LVK_C_API void lvk_cmd_end_rendering(lvk_cmd_buffer_t* self);
LVK_C_API void lvk_cmd_next_subpass(lvk_cmd_buffer_t* self);
LVK_C_API void lvk_cmd_bind_viewport(lvk_cmd_buffer_t* self, const lvk_viewport_t* viewport);
LVK_C_API void lvk_cmd_bind_scissor_rect(lvk_cmd_buffer_t* self, const lvk_scissor_rect_t* rect);
LVK_C_API void lvk_cmd_bind_render_pipeline(lvk_cmd_buffer_t* self, lvk_render_pipeline_handle_t handle);
LVK_C_API void lvk_cmd_bind_depth_state(lvk_cmd_buffer_t* self, const lvk_depth_state_t* state);
LVK_C_API void lvk_cmd_bind_stencil_state(lvk_cmd_buffer_t* self, const lvk_stencil_state_t* state);
/* defaults: bufferOffset = 0, bufferSize = LVK_WHOLE_SIZE */
LVK_C_API void lvk_cmd_bind_vertex_buffer(lvk_cmd_buffer_t* self, uint32_t index, lvk_buffer_handle_t buffer, uint64_t bufferOffset, uint64_t bufferSize);
/* defaults: bufferOffset = 0, bufferSize = LVK_WHOLE_SIZE */
LVK_C_API void lvk_cmd_bind_index_buffer(lvk_cmd_buffer_t* self, lvk_buffer_handle_t indexBuffer, lvk_index_format_t indexFormat, uint64_t bufferOffset, uint64_t bufferSize);
/* defaults: offset = 0 */
LVK_C_API void lvk_cmd_push_constants(lvk_cmd_buffer_t* self, const void* data, size_t size, size_t offset);
LVK_C_API void lvk_cmd_copy_buffer(lvk_cmd_buffer_t* self, lvk_buffer_handle_t srcBuffer, lvk_buffer_handle_t dstBuffer, size_t srcOffset, size_t dstOffset, size_t size);
LVK_C_API void lvk_cmd_fill_buffer(lvk_cmd_buffer_t* self, lvk_buffer_handle_t buffer, size_t bufferOffset, size_t size, uint32_t data);
LVK_C_API void lvk_cmd_update_buffer(lvk_cmd_buffer_t* self, lvk_buffer_handle_t buffer, size_t bufferOffset, size_t size, const void* data);
/* defaults: instanceCount = 1, firstVertex = 0, baseInstance = 0 */
LVK_C_API void lvk_cmd_draw(lvk_cmd_buffer_t* self, uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t baseInstance);
/* defaults: instanceCount = 1, firstIndex = 0, vertexOffset = 0, baseInstance = 0 */
LVK_C_API void lvk_cmd_draw_indexed(lvk_cmd_buffer_t* self, uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, int32_t vertexOffset, uint32_t baseInstance);
/* defaults: stride = 0 */
LVK_C_API void lvk_cmd_draw_indirect(lvk_cmd_buffer_t* self, lvk_buffer_handle_t indirectBuffer, size_t indirectBufferOffset, uint32_t drawCount, uint32_t stride);
/* defaults: stride = 0 */
LVK_C_API void lvk_cmd_draw_indexed_indirect(lvk_cmd_buffer_t* self, lvk_buffer_handle_t indirectBuffer, size_t indirectBufferOffset, uint32_t drawCount, uint32_t stride);
/* defaults: stride = 0 */
LVK_C_API void lvk_cmd_draw_indexed_indirect_count(lvk_cmd_buffer_t* self, lvk_buffer_handle_t indirectBuffer, size_t indirectBufferOffset, lvk_buffer_handle_t countBuffer, size_t countBufferOffset, uint32_t maxDrawCount, uint32_t stride);
LVK_C_API void lvk_cmd_draw_mesh_tasks(lvk_cmd_buffer_t* self, const lvk_dimensions_t* threadgroupCount);
/* defaults: stride = 0 */
LVK_C_API void lvk_cmd_draw_mesh_tasks_indirect(lvk_cmd_buffer_t* self, lvk_buffer_handle_t indirectBuffer, size_t indirectBufferOffset, uint32_t drawCount, uint32_t stride);
/* defaults: stride = 0 */
LVK_C_API void lvk_cmd_draw_mesh_tasks_indirect_count(lvk_cmd_buffer_t* self, lvk_buffer_handle_t indirectBuffer, size_t indirectBufferOffset, lvk_buffer_handle_t countBuffer, size_t countBufferOffset, uint32_t maxDrawCount, uint32_t stride);
/* defaults: depth = 1, deps = {0} */
LVK_C_API void lvk_cmd_trace_rays(lvk_cmd_buffer_t* self, uint32_t width, uint32_t height, uint32_t depth, const lvk_dependencies_t* deps);
LVK_C_API void lvk_cmd_set_blend_color(lvk_cmd_buffer_t* self, const float* color);
/* defaults: clamp = 0.0f */
LVK_C_API void lvk_cmd_set_depth_bias(lvk_cmd_buffer_t* self, float constantFactor, float slopeFactor, float clamp);
LVK_C_API void lvk_cmd_set_depth_bias_enable(lvk_cmd_buffer_t* self, bool enable);
LVK_C_API void lvk_cmd_set_depth_bounds(lvk_cmd_buffer_t* self, float minDepthBounds, float maxDepthBounds);
LVK_C_API void lvk_cmd_set_primitive_restart_enable(lvk_cmd_buffer_t* self, bool enable);
/* defaults: primitiveOp = LVK_SHADING_RATE_COMBINER_OP_KEEP, attachmentOp = LVK_SHADING_RATE_COMBINER_OP_KEEP */
LVK_C_API void lvk_cmd_set_fragment_shading_rate(lvk_cmd_buffer_t* self, const lvk_dimensions_t* fragmentSize, lvk_shading_rate_combiner_op_t primitiveOp, lvk_shading_rate_combiner_op_t attachmentOp);
LVK_C_API void lvk_cmd_reset_query_pool(lvk_cmd_buffer_t* self, lvk_query_pool_handle_t pool, uint32_t firstQuery, uint32_t queryCount);
LVK_C_API void lvk_cmd_write_timestamp(lvk_cmd_buffer_t* self, lvk_query_pool_handle_t pool, uint32_t query);
/* defaults: layers = {0} */
LVK_C_API void lvk_cmd_clear_color_image(lvk_cmd_buffer_t* self, lvk_texture_handle_t tex, const lvk_clear_color_value_t* value, const lvk_texture_layers_t* layers);
/* defaults: srcOffset = {0}, dstOffset = {0}, srcLayers = {0}, dstLayers = {0} */
LVK_C_API void lvk_cmd_copy_image(lvk_cmd_buffer_t* self, lvk_texture_handle_t src, lvk_texture_handle_t dst, const lvk_dimensions_t* extent, const lvk_offset3d_t* srcOffset, const lvk_offset3d_t* dstOffset, const lvk_texture_layers_t* srcLayers, const lvk_texture_layers_t* dstLayers);
LVK_C_API void lvk_cmd_generate_mipmap(lvk_cmd_buffer_t* self, lvk_texture_handle_t handle);
LVK_C_API void lvk_cmd_update_tlas(lvk_cmd_buffer_t* self, lvk_accel_struct_handle_t handle, lvk_buffer_handle_t instancesBuffer);
LVK_C_API void lvk_cmd_update_blas(lvk_cmd_buffer_t* self, const lvk_span_accel_struct_handle_t* handles);
/* defaults: dedicatedCompute = false */
LVK_C_API lvk_cmd_buffer_t* lvk_context_acquire_command_buffer(lvk_context_t* self, bool dedicatedCompute);
/* defaults: present = {0}, release = {0} */
LVK_C_API lvk_submit_handle_t lvk_context_submit(lvk_context_t* self, lvk_cmd_buffer_t* commandBuffer, lvk_texture_handle_t present, const lvk_span_texture_handle_t* release);
LVK_C_API void lvk_context_wait(lvk_context_t* self, lvk_submit_handle_t handle);
LVK_C_API bool lvk_context_is_ready(lvk_context_t* self, lvk_submit_handle_t handle);
/* defaults: debugName = NULL, outResult = NULL */
LVK_C_API lvk_buffer_handle_t lvk_context_create_buffer(lvk_context_t* self, const lvk_buffer_desc_t* desc, const char* debugName, lvk_result_t* outResult);
/* defaults: outResult = NULL */
LVK_C_API lvk_sampler_handle_t lvk_context_create_sampler(lvk_context_t* self, const lvk_sampler_state_desc_t* desc, lvk_result_t* outResult);
/* defaults: debugName = NULL, outResult = NULL */
LVK_C_API lvk_texture_handle_t lvk_context_create_texture(lvk_context_t* self, const lvk_texture_desc_t* desc, const char* debugName, lvk_result_t* outResult);
/* defaults: debugName = NULL, outResult = NULL */
LVK_C_API lvk_texture_handle_t lvk_context_create_texture_view(lvk_context_t* self, lvk_texture_handle_t texture, const lvk_texture_view_desc_t* desc, const char* debugName, lvk_result_t* outResult);
/* defaults: outResult = NULL */
LVK_C_API lvk_compute_pipeline_handle_t lvk_context_create_compute_pipeline(lvk_context_t* self, const lvk_compute_pipeline_desc_t* desc, lvk_result_t* outResult);
/* defaults: outResult = NULL */
LVK_C_API lvk_render_pipeline_handle_t lvk_context_create_render_pipeline(lvk_context_t* self, const lvk_render_pipeline_desc_t* desc, lvk_result_t* outResult);
/* defaults: outResult = NULL */
LVK_C_API lvk_ray_tracing_pipeline_handle_t lvk_context_create_ray_tracing_pipeline(lvk_context_t* self, const lvk_ray_tracing_pipeline_desc_t* desc, lvk_result_t* outResult);
/* defaults: outResult = NULL */
LVK_C_API lvk_shader_module_handle_t lvk_context_create_shader_module(lvk_context_t* self, const lvk_shader_module_desc_t* desc, lvk_result_t* outResult);
/* defaults: outResult = NULL */
LVK_C_API lvk_query_pool_handle_t lvk_context_create_query_pool(lvk_context_t* self, uint32_t numQueries, const char* debugName, lvk_result_t* outResult);
/* defaults: outResult = NULL */
LVK_C_API lvk_accel_struct_handle_t lvk_context_create_acceleration_structure(lvk_context_t* self, const lvk_accel_struct_desc_t* desc, lvk_result_t* outResult);
LVK_C_API void lvk_context_destroy_compute_pipeline(lvk_context_t* self, lvk_compute_pipeline_handle_t handle);
LVK_C_API void lvk_context_destroy_render_pipeline(lvk_context_t* self, lvk_render_pipeline_handle_t handle);
LVK_C_API void lvk_context_destroy_ray_tracing_pipeline(lvk_context_t* self, lvk_ray_tracing_pipeline_handle_t arg0);
LVK_C_API void lvk_context_destroy_shader_module(lvk_context_t* self, lvk_shader_module_handle_t handle);
LVK_C_API void lvk_context_destroy_sampler(lvk_context_t* self, lvk_sampler_handle_t handle);
LVK_C_API void lvk_context_destroy_buffer(lvk_context_t* self, lvk_buffer_handle_t handle);
LVK_C_API void lvk_context_destroy_texture(lvk_context_t* self, lvk_texture_handle_t handle);
LVK_C_API void lvk_context_destroy_query_pool(lvk_context_t* self, lvk_query_pool_handle_t handle);
LVK_C_API void lvk_context_destroy_accel_struct(lvk_context_t* self, lvk_accel_struct_handle_t handle);
LVK_C_API void lvk_context_destroy_framebuffer(lvk_context_t* self, lvk_framebuffer_t* fb);
LVK_C_API uint64_t lvk_context_gpu_address_accel_struct(lvk_context_t* self, lvk_accel_struct_handle_t handle);
/* defaults: offset = 0 */
LVK_C_API uint64_t lvk_context_gpu_address_buffer(lvk_context_t* self, lvk_buffer_handle_t handle, size_t offset);
/* defaults: outResult = NULL */
LVK_C_API lvk_accel_struct_sizes_t lvk_context_get_accel_struct_sizes(lvk_context_t* self, const lvk_accel_struct_desc_t* desc, lvk_result_t* outResult);
/* defaults: offset = 0 */
LVK_C_API lvk_result_t lvk_context_upload_buffer(lvk_context_t* self, lvk_buffer_handle_t handle, const void* data, size_t size, size_t offset);
/* defaults: bufferRowLength = 0 */
LVK_C_API lvk_result_t lvk_context_upload_texture(lvk_context_t* self, lvk_texture_handle_t handle, const lvk_texture_range_desc_t* range, const void* data, uint32_t bufferRowLength);
LVK_C_API lvk_result_t lvk_context_download_buffer(lvk_context_t* self, lvk_buffer_handle_t handle, void* data, size_t size, size_t offset);
LVK_C_API lvk_result_t lvk_context_download_texture(lvk_context_t* self, lvk_texture_handle_t handle, const lvk_texture_range_desc_t* range, void* outData);
LVK_C_API uint8_t* lvk_context_get_mapped_ptr(lvk_context_t* self, lvk_buffer_handle_t handle);
LVK_C_API void lvk_context_flush_mapped_memory(lvk_context_t* self, lvk_buffer_handle_t handle, size_t offset, size_t size);
LVK_C_API void lvk_context_invalidate_mapped_memory(lvk_context_t* self, lvk_buffer_handle_t handle, size_t offset, size_t size);
LVK_C_API uint32_t lvk_context_get_max_storage_buffer_range(lvk_context_t* self);
LVK_C_API lvk_dimensions_t lvk_context_get_dimensions(lvk_context_t* self, lvk_texture_handle_t handle);
LVK_C_API float lvk_context_get_aspect_ratio(lvk_context_t* self, lvk_texture_handle_t handle);
LVK_C_API lvk_format_t lvk_context_get_format(lvk_context_t* self, lvk_texture_handle_t handle);
LVK_C_API lvk_result_t lvk_context_init_swapchain(lvk_context_t* self, uint32_t width, uint32_t height);
LVK_C_API lvk_texture_handle_t lvk_context_get_current_swapchain_texture(lvk_context_t* self);
LVK_C_API lvk_format_t lvk_context_get_swapchain_format(lvk_context_t* self);
LVK_C_API lvk_color_space_t lvk_context_get_swapchain_color_space(lvk_context_t* self);
LVK_C_API uint32_t lvk_context_get_swapchain_current_image_index(lvk_context_t* self);
LVK_C_API uint32_t lvk_context_get_num_swapchain_images(lvk_context_t* self);
LVK_C_API lvk_surface_transform_t lvk_context_get_swapchain_surface_transform(lvk_context_t* self);
LVK_C_API bool lvk_context_set_current_present_mode(lvk_context_t* self, lvk_present_mode_t mode);
LVK_C_API lvk_present_mode_t lvk_context_get_current_present_mode(lvk_context_t* self);
LVK_C_API uint32_t lvk_context_get_framebuffer_msaa_bit_mask(lvk_context_t* self);
LVK_C_API lvk_dimensions_t lvk_context_get_shading_rate_attachment_min_texel_size(lvk_context_t* self);
LVK_C_API lvk_dimensions_t lvk_context_get_shading_rate_attachment_max_texel_size(lvk_context_t* self);
LVK_C_API lvk_span_const_dimensions_t lvk_context_get_supported_fragment_shading_rates(lvk_context_t* self);
LVK_C_API lvk_dimensions_t lvk_context_get_fragment_density_map_min_texel_size(lvk_context_t* self);
LVK_C_API bool lvk_context_is_extension_enabled(lvk_context_t* self, const char* ext);
LVK_C_API bool lvk_context_supports_async_compute(lvk_context_t* self);
LVK_C_API bool lvk_context_supports_depth_bounds(lvk_context_t* self);
LVK_C_API bool lvk_context_supports_mesh_shader(lvk_context_t* self);
LVK_C_API bool lvk_context_supports_provoking_vertex(lvk_context_t* self);
LVK_C_API bool lvk_context_supports_ray_query(lvk_context_t* self);
LVK_C_API bool lvk_context_supports_ray_tracing_pipeline(lvk_context_t* self);
LVK_C_API bool lvk_context_supports_opacity_micromap(lvk_context_t* self);
LVK_C_API bool lvk_context_supports_shader_interlock(lvk_context_t* self);
/* defaults: usageFlags = LVK_TEXTURE_USAGE_BITS_SAMPLED */
LVK_C_API bool lvk_context_supports_texture_format(lvk_context_t* self, lvk_format_t format, lvk_texture_usage_flags_t usageFlags);
LVK_C_API bool lvk_context_supports_tensors_arm(lvk_context_t* self);
LVK_C_API bool lvk_context_supports_data_graph_arm(lvk_context_t* self);
LVK_C_API uint32_t lvk_context_get_multiview_max_view_count(lvk_context_t* self);
LVK_C_API uint32_t lvk_context_get_multiview_max_mesh_view_count(lvk_context_t* self);
LVK_C_API double lvk_context_get_timestamp_period_to_ms(lvk_context_t* self);
LVK_C_API bool lvk_context_get_query_pool_results(lvk_context_t* self, lvk_query_pool_handle_t pool, uint32_t firstQuery, uint32_t queryCount, size_t dataSize, void* outData, size_t stride);
LVK_C_API void lvk_context_destroy(lvk_context_t* self);
LVK_C_API bool lvk_is_depth_or_stencil_format(lvk_format_t format);
LVK_C_API uint32_t lvk_get_num_image_planes(lvk_format_t format);
LVK_C_API uint32_t lvk_get_texture_bytes_per_layer(uint32_t width, uint32_t height, lvk_format_t format, uint32_t level);
LVK_C_API uint32_t lvk_get_texture_bytes_per_plane(uint32_t width, uint32_t height, lvk_format_t format, uint32_t plane);
LVK_C_API uint32_t lvk_get_vertex_format_size(lvk_vertex_format_t format);
LVK_C_API void lvk_log_shader_source(const char* text);
LVK_C_API uint32_t lvk_calc_num_mip_levels(uint32_t width, uint32_t height);
/* defaults: preferredDeviceType = LVK_HW_DEVICE_TYPE_DISCRETE, selectedDevice = -1 */
LVK_C_API lvk_context_t* lvk_create_vulkan_context_with_swapchain(void* window, uint32_t width, uint32_t height, const lvk_context_config_t* cfg, lvk_hw_device_type_t preferredDeviceType, int selectedDevice);
/* defaults: resizable = false, headless = false */
LVK_C_API void* lvk_init_window(const char* windowTitle, int* outWidth, int* outHeight, bool resizable, bool headless);
LVK_C_API lvk_shader_module_desc_t lvk_shader_module_desc_from_source(const char* source, lvk_shader_stage_t stage, const char* debugName);
LVK_C_API lvk_shader_module_desc_t lvk_shader_module_desc_from_source_entry_point(const char* source, const char* entryPointName, lvk_shader_stage_t stage, const char* debugName);
LVK_C_API lvk_shader_module_desc_t lvk_shader_module_desc_from_spirv(const void* data, size_t dataLength, lvk_shader_stage_t stage, const char* debugName);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* LVK_C_H */
