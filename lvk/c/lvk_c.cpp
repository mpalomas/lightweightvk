// GENERATED FILE - DO NOT EDIT. Regenerate with: python3 lvk/c/lvk_c_gen.py

#include <bit>
#include <cstddef>

#include "lvk_c.h"
#include <lvk/LVK.h>

// layout checks: the C structs must be bit-compatible with their C++ counterparts
static_assert(sizeof(lvk_compute_pipeline_handle_t) == sizeof(lvk::ComputePipelineHandle), "size mismatch: lvk_compute_pipeline_handle_t");
static_assert(sizeof(lvk_render_pipeline_handle_t) == sizeof(lvk::RenderPipelineHandle), "size mismatch: lvk_render_pipeline_handle_t");
static_assert(sizeof(lvk_ray_tracing_pipeline_handle_t) == sizeof(lvk::RayTracingPipelineHandle), "size mismatch: lvk_ray_tracing_pipeline_handle_t");
static_assert(sizeof(lvk_shader_module_handle_t) == sizeof(lvk::ShaderModuleHandle), "size mismatch: lvk_shader_module_handle_t");
static_assert(sizeof(lvk_sampler_handle_t) == sizeof(lvk::SamplerHandle), "size mismatch: lvk_sampler_handle_t");
static_assert(sizeof(lvk_buffer_handle_t) == sizeof(lvk::BufferHandle), "size mismatch: lvk_buffer_handle_t");
static_assert(sizeof(lvk_texture_handle_t) == sizeof(lvk::TextureHandle), "size mismatch: lvk_texture_handle_t");
static_assert(sizeof(lvk_query_pool_handle_t) == sizeof(lvk::QueryPoolHandle), "size mismatch: lvk_query_pool_handle_t");
static_assert(sizeof(lvk_accel_struct_handle_t) == sizeof(lvk::AccelStructHandle), "size mismatch: lvk_accel_struct_handle_t");
static_assert(sizeof(lvk_buffer_usage_flags_t) == sizeof(lvk::BufferUsageFlags), "size mismatch: lvk_buffer_usage_flags_t");
static_assert(sizeof(lvk_texture_usage_flags_t) == sizeof(lvk::TextureUsageFlags), "size mismatch: lvk_texture_usage_flags_t");
static_assert(sizeof(lvk_pipeline_stage_flags_t) == sizeof(lvk::PipelineStageFlags), "size mismatch: lvk_pipeline_stage_flags_t");
static_assert(sizeof(lvk_access_flags_t) == sizeof(lvk::AccessFlags), "size mismatch: lvk_access_flags_t");
static_assert(sizeof(lvk_index_format_t) == sizeof(lvk::IndexFormat), "size mismatch: lvk_index_format_t");
static_assert(sizeof(lvk_topology_t) == sizeof(lvk::Topology), "size mismatch: lvk_topology_t");
static_assert(sizeof(lvk_color_space_t) == sizeof(lvk::ColorSpace), "size mismatch: lvk_color_space_t");
static_assert(sizeof(lvk_present_mode_t) == sizeof(lvk::PresentMode), "size mismatch: lvk_present_mode_t");
static_assert(sizeof(lvk_surface_transform_t) == sizeof(lvk::SurfaceTransform), "size mismatch: lvk_surface_transform_t");
static_assert(sizeof(lvk_texture_type_t) == sizeof(lvk::TextureType), "size mismatch: lvk_texture_type_t");
static_assert(sizeof(lvk_sampler_filter_t) == sizeof(lvk::SamplerFilter), "size mismatch: lvk_sampler_filter_t");
static_assert(sizeof(lvk_sampler_mip_t) == sizeof(lvk::SamplerMip), "size mismatch: lvk_sampler_mip_t");
static_assert(sizeof(lvk_sampler_wrap_t) == sizeof(lvk::SamplerWrap), "size mismatch: lvk_sampler_wrap_t");
static_assert(sizeof(lvk_hw_device_type_t) == sizeof(lvk::HWDeviceType), "size mismatch: lvk_hw_device_type_t");
static_assert(sizeof(lvk_storage_type_t) == sizeof(lvk::StorageType), "size mismatch: lvk_storage_type_t");
static_assert(sizeof(lvk_cull_mode_t) == sizeof(lvk::CullMode), "size mismatch: lvk_cull_mode_t");
static_assert(sizeof(lvk_winding_mode_t) == sizeof(lvk::WindingMode), "size mismatch: lvk_winding_mode_t");
static_assert(sizeof(lvk_compare_op_t) == sizeof(lvk::CompareOp), "size mismatch: lvk_compare_op_t");
static_assert(sizeof(lvk_stencil_op_t) == sizeof(lvk::StencilOp), "size mismatch: lvk_stencil_op_t");
static_assert(sizeof(lvk_blend_op_t) == sizeof(lvk::BlendOp), "size mismatch: lvk_blend_op_t");
static_assert(sizeof(lvk_blend_factor_t) == sizeof(lvk::BlendFactor), "size mismatch: lvk_blend_factor_t");
static_assert(sizeof(lvk_polygon_mode_t) == sizeof(lvk::PolygonMode), "size mismatch: lvk_polygon_mode_t");
static_assert(sizeof(lvk_shading_rate_combiner_op_t) == sizeof(lvk::ShadingRateCombinerOp), "size mismatch: lvk_shading_rate_combiner_op_t");
static_assert(sizeof(lvk_vertex_format_t) == sizeof(lvk::VertexFormat), "size mismatch: lvk_vertex_format_t");
static_assert(sizeof(lvk_vertex_input_rate_t) == sizeof(lvk::VertexInputRate), "size mismatch: lvk_vertex_input_rate_t");
static_assert(sizeof(lvk_format_t) == sizeof(lvk::Format), "size mismatch: lvk_format_t");
static_assert(sizeof(lvk_load_op_t) == sizeof(lvk::LoadOp), "size mismatch: lvk_load_op_t");
static_assert(sizeof(lvk_store_op_t) == sizeof(lvk::StoreOp), "size mismatch: lvk_store_op_t");
static_assert(sizeof(lvk_resolve_mode_t) == sizeof(lvk::ResolveMode), "size mismatch: lvk_resolve_mode_t");
static_assert(sizeof(lvk_shader_stage_t) == sizeof(lvk::ShaderStage), "size mismatch: lvk_shader_stage_t");
static_assert(sizeof(lvk_color_component_bits_t) == sizeof(lvk::ColorComponentBits), "size mismatch: lvk_color_component_bits_t");
static_assert(sizeof(lvk_buffer_usage_bits_t) == sizeof(lvk::BufferUsageBits), "size mismatch: lvk_buffer_usage_bits_t");
static_assert(sizeof(lvk_texture_usage_bits_t) == sizeof(lvk::TextureUsageBits), "size mismatch: lvk_texture_usage_bits_t");
static_assert(sizeof(lvk_pipeline_stage_bits_t) == sizeof(lvk::PipelineStageBits), "size mismatch: lvk_pipeline_stage_bits_t");
static_assert(sizeof(lvk_access_bits_t) == sizeof(lvk::AccessBits), "size mismatch: lvk_access_bits_t");
static_assert(sizeof(lvk_swizzle_t) == sizeof(lvk::Swizzle), "size mismatch: lvk_swizzle_t");
static_assert(sizeof(lvk_texture_aspect_t) == sizeof(lvk::TextureAspect), "size mismatch: lvk_texture_aspect_t");
static_assert(sizeof(lvk_accel_struct_type_t) == sizeof(lvk::AccelStructType), "size mismatch: lvk_accel_struct_type_t");
static_assert(sizeof(lvk_accel_struct_geom_type_t) == sizeof(lvk::AccelStructGeomType), "size mismatch: lvk_accel_struct_geom_type_t");
static_assert(sizeof(lvk_accel_struct_build_flag_bits_t) == sizeof(lvk::AccelStructBuildFlagBits), "size mismatch: lvk_accel_struct_build_flag_bits_t");
static_assert(sizeof(lvk_accel_struct_geometry_flag_bits_t) == sizeof(lvk::AccelStructGeometryFlagBits), "size mismatch: lvk_accel_struct_geometry_flag_bits_t");
static_assert(sizeof(lvk_accel_struct_instance_flag_bits_t) == sizeof(lvk::AccelStructInstanceFlagBits), "size mismatch: lvk_accel_struct_instance_flag_bits_t");
static_assert(sizeof(lvk_opacity_micromap_format_t) == sizeof(lvk::OpacityMicromapFormat), "size mismatch: lvk_opacity_micromap_format_t");
static_assert(sizeof(lvk_opacity_micromap_special_index_t) == sizeof(lvk::OpacityMicromapSpecialIndex), "size mismatch: lvk_opacity_micromap_special_index_t");
static_assert(sizeof(lvk_vulkan_version_t) == sizeof(lvk::VulkanVersion), "size mismatch: lvk_vulkan_version_t");
static_assert(sizeof(lvk_hw_device_desc_t) == sizeof(lvk::HWDeviceDesc), "size mismatch: lvk_hw_device_desc_t");
static_assert(sizeof(lvk_result_code_t) == sizeof(lvk::Result::Code), "size mismatch: lvk_result_code_t");
static_assert(sizeof(lvk_result_t) == sizeof(lvk::Result), "size mismatch: lvk_result_t");
static_assert(sizeof(lvk_scissor_rect_t) == sizeof(lvk::ScissorRect), "size mismatch: lvk_scissor_rect_t");
static_assert(sizeof(lvk_dimensions_t) == sizeof(lvk::Dimensions), "size mismatch: lvk_dimensions_t");
static_assert(sizeof(lvk_viewport_t) == sizeof(lvk::Viewport), "size mismatch: lvk_viewport_t");
static_assert(sizeof(lvk_sampler_state_desc_t) == sizeof(lvk::SamplerStateDesc), "size mismatch: lvk_sampler_state_desc_t");
static_assert(sizeof(lvk_stencil_face_state_t) == sizeof(lvk::StencilFaceState), "size mismatch: lvk_stencil_face_state_t");
static_assert(sizeof(lvk_stencil_state_t) == sizeof(lvk::StencilState), "size mismatch: lvk_stencil_state_t");
static_assert(sizeof(lvk_depth_state_t) == sizeof(lvk::DepthState), "size mismatch: lvk_depth_state_t");
static_assert(sizeof(lvk_clear_color_value_t) == sizeof(lvk::ClearColorValue), "size mismatch: lvk_clear_color_value_t");
static_assert(sizeof(lvk_vertex_attribute_t) == sizeof(lvk::VertexInput::VertexAttribute), "size mismatch: lvk_vertex_attribute_t");
static_assert(sizeof(lvk_vertex_input_binding_t) == sizeof(lvk::VertexInput::VertexInputBinding), "size mismatch: lvk_vertex_input_binding_t");
static_assert(sizeof(lvk_vertex_input_t) == sizeof(lvk::VertexInput), "size mismatch: lvk_vertex_input_t");
static_assert(sizeof(lvk_color_attachment_t) == sizeof(lvk::ColorAttachment), "size mismatch: lvk_color_attachment_t");
static_assert(sizeof(lvk_shader_module_desc_t) == sizeof(lvk::ShaderModuleDesc), "size mismatch: lvk_shader_module_desc_t");
static_assert(sizeof(lvk_specialization_constant_entry_t) == sizeof(lvk::SpecializationConstantEntry), "size mismatch: lvk_specialization_constant_entry_t");
static_assert(sizeof(lvk_specialization_constant_desc_t) == sizeof(lvk::SpecializationConstantDesc), "size mismatch: lvk_specialization_constant_desc_t");
static_assert(sizeof(lvk_render_pipeline_desc_t) == sizeof(lvk::RenderPipelineDesc), "size mismatch: lvk_render_pipeline_desc_t");
static_assert(sizeof(lvk_compute_pipeline_desc_t) == sizeof(lvk::ComputePipelineDesc), "size mismatch: lvk_compute_pipeline_desc_t");
static_assert(sizeof(lvk_ray_tracing_hit_group_desc_t) == sizeof(lvk::RayTracingHitGroupDesc), "size mismatch: lvk_ray_tracing_hit_group_desc_t");
static_assert(sizeof(lvk_span_shader_module_handle_t) == sizeof(ldr::Span<ldr::Handle<lvk::ShaderModule>>), "size mismatch: lvk_span_shader_module_handle_t");
static_assert(sizeof(lvk_span_ray_tracing_hit_group_desc_t) == sizeof(ldr::Span<lvk::RayTracingHitGroupDesc>), "size mismatch: lvk_span_ray_tracing_hit_group_desc_t");
static_assert(sizeof(lvk_ray_tracing_pipeline_desc_t) == sizeof(lvk::RayTracingPipelineDesc), "size mismatch: lvk_ray_tracing_pipeline_desc_t");
static_assert(sizeof(lvk_render_pass_attachment_desc_t) == sizeof(lvk::RenderPass::AttachmentDesc), "size mismatch: lvk_render_pass_attachment_desc_t");
static_assert(sizeof(lvk_render_pass_t) == sizeof(lvk::RenderPass), "size mismatch: lvk_render_pass_t");
static_assert(sizeof(lvk_framebuffer_attachment_desc_t) == sizeof(lvk::Framebuffer::AttachmentDesc), "size mismatch: lvk_framebuffer_attachment_desc_t");
static_assert(sizeof(lvk_framebuffer_t) == sizeof(lvk::Framebuffer), "size mismatch: lvk_framebuffer_t");
static_assert(sizeof(lvk_buffer_desc_t) == sizeof(lvk::BufferDesc), "size mismatch: lvk_buffer_desc_t");
static_assert(sizeof(lvk_offset3d_t) == sizeof(lvk::Offset3D), "size mismatch: lvk_offset3d_t");
static_assert(sizeof(lvk_texture_layers_t) == sizeof(lvk::TextureLayers), "size mismatch: lvk_texture_layers_t");
static_assert(sizeof(lvk_texture_range_desc_t) == sizeof(lvk::TextureRangeDesc), "size mismatch: lvk_texture_range_desc_t");
static_assert(sizeof(lvk_component_mapping_t) == sizeof(lvk::ComponentMapping), "size mismatch: lvk_component_mapping_t");
static_assert(sizeof(lvk_texture_desc_t) == sizeof(lvk::TextureDesc), "size mismatch: lvk_texture_desc_t");
static_assert(sizeof(lvk_texture_view_desc_t) == sizeof(lvk::TextureViewDesc), "size mismatch: lvk_texture_view_desc_t");
static_assert(sizeof(lvk_opacity_micromap_usage_t) == sizeof(lvk::OpacityMicromapUsage), "size mismatch: lvk_opacity_micromap_usage_t");
static_assert(sizeof(lvk_opacity_micromap_triangle_t) == sizeof(lvk::OpacityMicromapTriangle), "size mismatch: lvk_opacity_micromap_triangle_t");
static_assert(sizeof(lvk_accel_struct_sizes_t) == sizeof(lvk::AccelStructSizes), "size mismatch: lvk_accel_struct_sizes_t");
static_assert(sizeof(lvk_accel_struct_build_range_t) == sizeof(lvk::AccelStructBuildRange), "size mismatch: lvk_accel_struct_build_range_t");
static_assert(sizeof(lvk_mat3x4_t) == sizeof(lvk::mat3x4), "size mismatch: lvk_mat3x4_t");
static_assert(sizeof(lvk_accel_struct_instance_t) == sizeof(lvk::AccelStructInstance), "size mismatch: lvk_accel_struct_instance_t");
static_assert(sizeof(lvk_accel_struct_desc_t) == sizeof(lvk::AccelStructDesc), "size mismatch: lvk_accel_struct_desc_t");
static_assert(sizeof(lvk_submit_handle_t) == sizeof(lvk::SubmitHandle), "size mismatch: lvk_submit_handle_t");
static_assert(sizeof(lvk_span_texture_handle_t) == sizeof(ldr::Span<ldr::Handle<lvk::Texture>>), "size mismatch: lvk_span_texture_handle_t");
static_assert(sizeof(lvk_span_buffer_handle_t) == sizeof(ldr::Span<ldr::Handle<lvk::Buffer>>), "size mismatch: lvk_span_buffer_handle_t");
static_assert(sizeof(lvk_span_submit_handle_t) == sizeof(ldr::Span<lvk::SubmitHandle>), "size mismatch: lvk_span_submit_handle_t");
static_assert(sizeof(lvk_dependencies_t) == sizeof(lvk::Dependencies), "size mismatch: lvk_dependencies_t");
static_assert(sizeof(lvk_barrier_t) == sizeof(lvk::Barrier), "size mismatch: lvk_barrier_t");
static_assert(sizeof(lvk_span_accel_struct_handle_t) == sizeof(const ldr::Span<ldr::Handle<lvk::AccelerationStructure>>), "size mismatch: lvk_span_accel_struct_handle_t");
static_assert(sizeof(lvk_span_const_dimensions_t) == sizeof(ldr::Span<const lvk::Dimensions>), "size mismatch: lvk_span_const_dimensions_t");
static_assert(sizeof(lvk_context_config_t) == sizeof(lvk::ContextConfig), "size mismatch: lvk_context_config_t");
static_assert(offsetof(lvk_hw_device_desc_t, guid) == offsetof(lvk::HWDeviceDesc, guid), "layout mismatch: lvk_hw_device_desc_t::guid");
static_assert(offsetof(lvk_hw_device_desc_t, type) == offsetof(lvk::HWDeviceDesc, type), "layout mismatch: lvk_hw_device_desc_t::type");
static_assert(offsetof(lvk_hw_device_desc_t, name) == offsetof(lvk::HWDeviceDesc, name), "layout mismatch: lvk_hw_device_desc_t::name");
static_assert(offsetof(lvk_result_t, code) == offsetof(lvk::Result, code), "layout mismatch: lvk_result_t::code");
static_assert(offsetof(lvk_result_t, message) == offsetof(lvk::Result, message), "layout mismatch: lvk_result_t::message");
static_assert(offsetof(lvk_scissor_rect_t, x) == offsetof(lvk::ScissorRect, x), "layout mismatch: lvk_scissor_rect_t::x");
static_assert(offsetof(lvk_scissor_rect_t, y) == offsetof(lvk::ScissorRect, y), "layout mismatch: lvk_scissor_rect_t::y");
static_assert(offsetof(lvk_scissor_rect_t, width) == offsetof(lvk::ScissorRect, width), "layout mismatch: lvk_scissor_rect_t::width");
static_assert(offsetof(lvk_scissor_rect_t, height) == offsetof(lvk::ScissorRect, height), "layout mismatch: lvk_scissor_rect_t::height");
static_assert(offsetof(lvk_dimensions_t, width) == offsetof(lvk::Dimensions, width), "layout mismatch: lvk_dimensions_t::width");
static_assert(offsetof(lvk_dimensions_t, height) == offsetof(lvk::Dimensions, height), "layout mismatch: lvk_dimensions_t::height");
static_assert(offsetof(lvk_dimensions_t, depth) == offsetof(lvk::Dimensions, depth), "layout mismatch: lvk_dimensions_t::depth");
static_assert(offsetof(lvk_viewport_t, x) == offsetof(lvk::Viewport, x), "layout mismatch: lvk_viewport_t::x");
static_assert(offsetof(lvk_viewport_t, y) == offsetof(lvk::Viewport, y), "layout mismatch: lvk_viewport_t::y");
static_assert(offsetof(lvk_viewport_t, width) == offsetof(lvk::Viewport, width), "layout mismatch: lvk_viewport_t::width");
static_assert(offsetof(lvk_viewport_t, height) == offsetof(lvk::Viewport, height), "layout mismatch: lvk_viewport_t::height");
static_assert(offsetof(lvk_viewport_t, minDepth) == offsetof(lvk::Viewport, minDepth), "layout mismatch: lvk_viewport_t::minDepth");
static_assert(offsetof(lvk_viewport_t, maxDepth) == offsetof(lvk::Viewport, maxDepth), "layout mismatch: lvk_viewport_t::maxDepth");
static_assert(offsetof(lvk_sampler_state_desc_t, minFilter) == offsetof(lvk::SamplerStateDesc, minFilter), "layout mismatch: lvk_sampler_state_desc_t::minFilter");
static_assert(offsetof(lvk_sampler_state_desc_t, magFilter) == offsetof(lvk::SamplerStateDesc, magFilter), "layout mismatch: lvk_sampler_state_desc_t::magFilter");
static_assert(offsetof(lvk_sampler_state_desc_t, mipMap) == offsetof(lvk::SamplerStateDesc, mipMap), "layout mismatch: lvk_sampler_state_desc_t::mipMap");
static_assert(offsetof(lvk_sampler_state_desc_t, wrapU) == offsetof(lvk::SamplerStateDesc, wrapU), "layout mismatch: lvk_sampler_state_desc_t::wrapU");
static_assert(offsetof(lvk_sampler_state_desc_t, wrapV) == offsetof(lvk::SamplerStateDesc, wrapV), "layout mismatch: lvk_sampler_state_desc_t::wrapV");
static_assert(offsetof(lvk_sampler_state_desc_t, wrapW) == offsetof(lvk::SamplerStateDesc, wrapW), "layout mismatch: lvk_sampler_state_desc_t::wrapW");
static_assert(offsetof(lvk_sampler_state_desc_t, depthCompareOp) == offsetof(lvk::SamplerStateDesc, depthCompareOp), "layout mismatch: lvk_sampler_state_desc_t::depthCompareOp");
static_assert(offsetof(lvk_sampler_state_desc_t, mipLodMin) == offsetof(lvk::SamplerStateDesc, mipLodMin), "layout mismatch: lvk_sampler_state_desc_t::mipLodMin");
static_assert(offsetof(lvk_sampler_state_desc_t, mipLodMax) == offsetof(lvk::SamplerStateDesc, mipLodMax), "layout mismatch: lvk_sampler_state_desc_t::mipLodMax");
static_assert(offsetof(lvk_sampler_state_desc_t, maxAnisotropic) == offsetof(lvk::SamplerStateDesc, maxAnisotropic), "layout mismatch: lvk_sampler_state_desc_t::maxAnisotropic");
static_assert(offsetof(lvk_sampler_state_desc_t, depthCompareEnabled) == offsetof(lvk::SamplerStateDesc, depthCompareEnabled), "layout mismatch: lvk_sampler_state_desc_t::depthCompareEnabled");
static_assert(offsetof(lvk_sampler_state_desc_t, debugName) == offsetof(lvk::SamplerStateDesc, debugName), "layout mismatch: lvk_sampler_state_desc_t::debugName");
static_assert(offsetof(lvk_stencil_face_state_t, stencilFailureOp) == offsetof(lvk::StencilFaceState, stencilFailureOp), "layout mismatch: lvk_stencil_face_state_t::stencilFailureOp");
static_assert(offsetof(lvk_stencil_face_state_t, depthFailureOp) == offsetof(lvk::StencilFaceState, depthFailureOp), "layout mismatch: lvk_stencil_face_state_t::depthFailureOp");
static_assert(offsetof(lvk_stencil_face_state_t, depthStencilPassOp) == offsetof(lvk::StencilFaceState, depthStencilPassOp), "layout mismatch: lvk_stencil_face_state_t::depthStencilPassOp");
static_assert(offsetof(lvk_stencil_face_state_t, stencilCompareOp) == offsetof(lvk::StencilFaceState, stencilCompareOp), "layout mismatch: lvk_stencil_face_state_t::stencilCompareOp");
static_assert(offsetof(lvk_stencil_face_state_t, readMask) == offsetof(lvk::StencilFaceState, readMask), "layout mismatch: lvk_stencil_face_state_t::readMask");
static_assert(offsetof(lvk_stencil_face_state_t, writeMask) == offsetof(lvk::StencilFaceState, writeMask), "layout mismatch: lvk_stencil_face_state_t::writeMask");
static_assert(offsetof(lvk_stencil_face_state_t, reference) == offsetof(lvk::StencilFaceState, reference), "layout mismatch: lvk_stencil_face_state_t::reference");
static_assert(offsetof(lvk_stencil_state_t, enable) == offsetof(lvk::StencilState, enable), "layout mismatch: lvk_stencil_state_t::enable");
static_assert(offsetof(lvk_stencil_state_t, front) == offsetof(lvk::StencilState, front), "layout mismatch: lvk_stencil_state_t::front");
static_assert(offsetof(lvk_stencil_state_t, back) == offsetof(lvk::StencilState, back), "layout mismatch: lvk_stencil_state_t::back");
static_assert(offsetof(lvk_depth_state_t, compareOp) == offsetof(lvk::DepthState, compareOp), "layout mismatch: lvk_depth_state_t::compareOp");
static_assert(offsetof(lvk_depth_state_t, isDepthWriteEnabled) == offsetof(lvk::DepthState, isDepthWriteEnabled), "layout mismatch: lvk_depth_state_t::isDepthWriteEnabled");
static_assert(offsetof(lvk_depth_state_t, isDepthBoundsTestEnabled) == offsetof(lvk::DepthState, isDepthBoundsTestEnabled), "layout mismatch: lvk_depth_state_t::isDepthBoundsTestEnabled");
static_assert(offsetof(lvk_clear_color_value_t, float32) == offsetof(lvk::ClearColorValue, float32), "layout mismatch: lvk_clear_color_value_t::float32");
static_assert(offsetof(lvk_clear_color_value_t, int32) == offsetof(lvk::ClearColorValue, int32), "layout mismatch: lvk_clear_color_value_t::int32");
static_assert(offsetof(lvk_clear_color_value_t, uint32) == offsetof(lvk::ClearColorValue, uint32), "layout mismatch: lvk_clear_color_value_t::uint32");
static_assert(offsetof(lvk_vertex_input_t, attributes) == offsetof(lvk::VertexInput, attributes), "layout mismatch: lvk_vertex_input_t::attributes");
static_assert(offsetof(lvk_vertex_input_t, inputBindings) == offsetof(lvk::VertexInput, inputBindings), "layout mismatch: lvk_vertex_input_t::inputBindings");
static_assert(offsetof(lvk_vertex_attribute_t, location) == offsetof(lvk::VertexInput::VertexAttribute, location), "layout mismatch: lvk_vertex_attribute_t::location");
static_assert(offsetof(lvk_vertex_attribute_t, binding) == offsetof(lvk::VertexInput::VertexAttribute, binding), "layout mismatch: lvk_vertex_attribute_t::binding");
static_assert(offsetof(lvk_vertex_attribute_t, format) == offsetof(lvk::VertexInput::VertexAttribute, format), "layout mismatch: lvk_vertex_attribute_t::format");
static_assert(offsetof(lvk_vertex_attribute_t, offset) == offsetof(lvk::VertexInput::VertexAttribute, offset), "layout mismatch: lvk_vertex_attribute_t::offset");
static_assert(offsetof(lvk_vertex_input_binding_t, stride) == offsetof(lvk::VertexInput::VertexInputBinding, stride), "layout mismatch: lvk_vertex_input_binding_t::stride");
static_assert(offsetof(lvk_vertex_input_binding_t, inputRate) == offsetof(lvk::VertexInput::VertexInputBinding, inputRate), "layout mismatch: lvk_vertex_input_binding_t::inputRate");
static_assert(offsetof(lvk_color_attachment_t, format) == offsetof(lvk::ColorAttachment, format), "layout mismatch: lvk_color_attachment_t::format");
static_assert(offsetof(lvk_color_attachment_t, blendEnabled) == offsetof(lvk::ColorAttachment, blendEnabled), "layout mismatch: lvk_color_attachment_t::blendEnabled");
static_assert(offsetof(lvk_color_attachment_t, rgbBlendOp) == offsetof(lvk::ColorAttachment, rgbBlendOp), "layout mismatch: lvk_color_attachment_t::rgbBlendOp");
static_assert(offsetof(lvk_color_attachment_t, alphaBlendOp) == offsetof(lvk::ColorAttachment, alphaBlendOp), "layout mismatch: lvk_color_attachment_t::alphaBlendOp");
static_assert(offsetof(lvk_color_attachment_t, srcRGBBlendFactor) == offsetof(lvk::ColorAttachment, srcRGBBlendFactor), "layout mismatch: lvk_color_attachment_t::srcRGBBlendFactor");
static_assert(offsetof(lvk_color_attachment_t, srcAlphaBlendFactor) == offsetof(lvk::ColorAttachment, srcAlphaBlendFactor), "layout mismatch: lvk_color_attachment_t::srcAlphaBlendFactor");
static_assert(offsetof(lvk_color_attachment_t, dstRGBBlendFactor) == offsetof(lvk::ColorAttachment, dstRGBBlendFactor), "layout mismatch: lvk_color_attachment_t::dstRGBBlendFactor");
static_assert(offsetof(lvk_color_attachment_t, dstAlphaBlendFactor) == offsetof(lvk::ColorAttachment, dstAlphaBlendFactor), "layout mismatch: lvk_color_attachment_t::dstAlphaBlendFactor");
static_assert(offsetof(lvk_color_attachment_t, colorWriteMask) == offsetof(lvk::ColorAttachment, colorWriteMask), "layout mismatch: lvk_color_attachment_t::colorWriteMask");
static_assert(offsetof(lvk_shader_module_desc_t, stage) == offsetof(lvk::ShaderModuleDesc, stage), "layout mismatch: lvk_shader_module_desc_t::stage");
static_assert(offsetof(lvk_shader_module_desc_t, data) == offsetof(lvk::ShaderModuleDesc, data), "layout mismatch: lvk_shader_module_desc_t::data");
static_assert(offsetof(lvk_shader_module_desc_t, dataSize) == offsetof(lvk::ShaderModuleDesc, dataSize), "layout mismatch: lvk_shader_module_desc_t::dataSize");
static_assert(offsetof(lvk_shader_module_desc_t, optimizeSPIRV) == offsetof(lvk::ShaderModuleDesc, optimizeSPIRV), "layout mismatch: lvk_shader_module_desc_t::optimizeSPIRV");
static_assert(offsetof(lvk_shader_module_desc_t, entryPointName) == offsetof(lvk::ShaderModuleDesc, entryPointName), "layout mismatch: lvk_shader_module_desc_t::entryPointName");
static_assert(offsetof(lvk_shader_module_desc_t, debugName) == offsetof(lvk::ShaderModuleDesc, debugName), "layout mismatch: lvk_shader_module_desc_t::debugName");
static_assert(offsetof(lvk_specialization_constant_entry_t, constantId) == offsetof(lvk::SpecializationConstantEntry, constantId), "layout mismatch: lvk_specialization_constant_entry_t::constantId");
static_assert(offsetof(lvk_specialization_constant_entry_t, offset) == offsetof(lvk::SpecializationConstantEntry, offset), "layout mismatch: lvk_specialization_constant_entry_t::offset");
static_assert(offsetof(lvk_specialization_constant_entry_t, size) == offsetof(lvk::SpecializationConstantEntry, size), "layout mismatch: lvk_specialization_constant_entry_t::size");
static_assert(offsetof(lvk_specialization_constant_desc_t, entries) == offsetof(lvk::SpecializationConstantDesc, entries), "layout mismatch: lvk_specialization_constant_desc_t::entries");
static_assert(offsetof(lvk_specialization_constant_desc_t, data) == offsetof(lvk::SpecializationConstantDesc, data), "layout mismatch: lvk_specialization_constant_desc_t::data");
static_assert(offsetof(lvk_specialization_constant_desc_t, dataSize) == offsetof(lvk::SpecializationConstantDesc, dataSize), "layout mismatch: lvk_specialization_constant_desc_t::dataSize");
static_assert(offsetof(lvk_render_pipeline_desc_t, topology) == offsetof(lvk::RenderPipelineDesc, topology), "layout mismatch: lvk_render_pipeline_desc_t::topology");
static_assert(offsetof(lvk_render_pipeline_desc_t, vertexInput) == offsetof(lvk::RenderPipelineDesc, vertexInput), "layout mismatch: lvk_render_pipeline_desc_t::vertexInput");
static_assert(offsetof(lvk_render_pipeline_desc_t, smVert) == offsetof(lvk::RenderPipelineDesc, smVert), "layout mismatch: lvk_render_pipeline_desc_t::smVert");
static_assert(offsetof(lvk_render_pipeline_desc_t, smTesc) == offsetof(lvk::RenderPipelineDesc, smTesc), "layout mismatch: lvk_render_pipeline_desc_t::smTesc");
static_assert(offsetof(lvk_render_pipeline_desc_t, smTese) == offsetof(lvk::RenderPipelineDesc, smTese), "layout mismatch: lvk_render_pipeline_desc_t::smTese");
static_assert(offsetof(lvk_render_pipeline_desc_t, smGeom) == offsetof(lvk::RenderPipelineDesc, smGeom), "layout mismatch: lvk_render_pipeline_desc_t::smGeom");
static_assert(offsetof(lvk_render_pipeline_desc_t, smTask) == offsetof(lvk::RenderPipelineDesc, smTask), "layout mismatch: lvk_render_pipeline_desc_t::smTask");
static_assert(offsetof(lvk_render_pipeline_desc_t, smMesh) == offsetof(lvk::RenderPipelineDesc, smMesh), "layout mismatch: lvk_render_pipeline_desc_t::smMesh");
static_assert(offsetof(lvk_render_pipeline_desc_t, smFrag) == offsetof(lvk::RenderPipelineDesc, smFrag), "layout mismatch: lvk_render_pipeline_desc_t::smFrag");
static_assert(offsetof(lvk_render_pipeline_desc_t, specInfo) == offsetof(lvk::RenderPipelineDesc, specInfo), "layout mismatch: lvk_render_pipeline_desc_t::specInfo");
static_assert(offsetof(lvk_render_pipeline_desc_t, entryPointVert) == offsetof(lvk::RenderPipelineDesc, entryPointVert), "layout mismatch: lvk_render_pipeline_desc_t::entryPointVert");
static_assert(offsetof(lvk_render_pipeline_desc_t, entryPointTesc) == offsetof(lvk::RenderPipelineDesc, entryPointTesc), "layout mismatch: lvk_render_pipeline_desc_t::entryPointTesc");
static_assert(offsetof(lvk_render_pipeline_desc_t, entryPointTese) == offsetof(lvk::RenderPipelineDesc, entryPointTese), "layout mismatch: lvk_render_pipeline_desc_t::entryPointTese");
static_assert(offsetof(lvk_render_pipeline_desc_t, entryPointGeom) == offsetof(lvk::RenderPipelineDesc, entryPointGeom), "layout mismatch: lvk_render_pipeline_desc_t::entryPointGeom");
static_assert(offsetof(lvk_render_pipeline_desc_t, entryPointTask) == offsetof(lvk::RenderPipelineDesc, entryPointTask), "layout mismatch: lvk_render_pipeline_desc_t::entryPointTask");
static_assert(offsetof(lvk_render_pipeline_desc_t, entryPointMesh) == offsetof(lvk::RenderPipelineDesc, entryPointMesh), "layout mismatch: lvk_render_pipeline_desc_t::entryPointMesh");
static_assert(offsetof(lvk_render_pipeline_desc_t, entryPointFrag) == offsetof(lvk::RenderPipelineDesc, entryPointFrag), "layout mismatch: lvk_render_pipeline_desc_t::entryPointFrag");
static_assert(offsetof(lvk_render_pipeline_desc_t, color) == offsetof(lvk::RenderPipelineDesc, color), "layout mismatch: lvk_render_pipeline_desc_t::color");
static_assert(offsetof(lvk_render_pipeline_desc_t, depthFormat) == offsetof(lvk::RenderPipelineDesc, depthFormat), "layout mismatch: lvk_render_pipeline_desc_t::depthFormat");
static_assert(offsetof(lvk_render_pipeline_desc_t, stencilFormat) == offsetof(lvk::RenderPipelineDesc, stencilFormat), "layout mismatch: lvk_render_pipeline_desc_t::stencilFormat");
static_assert(offsetof(lvk_render_pipeline_desc_t, cullMode) == offsetof(lvk::RenderPipelineDesc, cullMode), "layout mismatch: lvk_render_pipeline_desc_t::cullMode");
static_assert(offsetof(lvk_render_pipeline_desc_t, frontFace) == offsetof(lvk::RenderPipelineDesc, frontFace), "layout mismatch: lvk_render_pipeline_desc_t::frontFace");
static_assert(offsetof(lvk_render_pipeline_desc_t, polygonMode) == offsetof(lvk::RenderPipelineDesc, polygonMode), "layout mismatch: lvk_render_pipeline_desc_t::polygonMode");
static_assert(offsetof(lvk_render_pipeline_desc_t, provokingVertexLast) == offsetof(lvk::RenderPipelineDesc, provokingVertexLast), "layout mismatch: lvk_render_pipeline_desc_t::provokingVertexLast");
static_assert(offsetof(lvk_render_pipeline_desc_t, samplesCount) == offsetof(lvk::RenderPipelineDesc, samplesCount), "layout mismatch: lvk_render_pipeline_desc_t::samplesCount");
static_assert(offsetof(lvk_render_pipeline_desc_t, patchControlPoints) == offsetof(lvk::RenderPipelineDesc, patchControlPoints), "layout mismatch: lvk_render_pipeline_desc_t::patchControlPoints");
static_assert(offsetof(lvk_render_pipeline_desc_t, minSampleShading) == offsetof(lvk::RenderPipelineDesc, minSampleShading), "layout mismatch: lvk_render_pipeline_desc_t::minSampleShading");
static_assert(offsetof(lvk_render_pipeline_desc_t, alphaToCoverage) == offsetof(lvk::RenderPipelineDesc, alphaToCoverage), "layout mismatch: lvk_render_pipeline_desc_t::alphaToCoverage");
static_assert(offsetof(lvk_render_pipeline_desc_t, debugName) == offsetof(lvk::RenderPipelineDesc, debugName), "layout mismatch: lvk_render_pipeline_desc_t::debugName");
static_assert(offsetof(lvk_compute_pipeline_desc_t, smComp) == offsetof(lvk::ComputePipelineDesc, smComp), "layout mismatch: lvk_compute_pipeline_desc_t::smComp");
static_assert(offsetof(lvk_compute_pipeline_desc_t, specInfo) == offsetof(lvk::ComputePipelineDesc, specInfo), "layout mismatch: lvk_compute_pipeline_desc_t::specInfo");
static_assert(offsetof(lvk_compute_pipeline_desc_t, entryPoint) == offsetof(lvk::ComputePipelineDesc, entryPoint), "layout mismatch: lvk_compute_pipeline_desc_t::entryPoint");
static_assert(offsetof(lvk_compute_pipeline_desc_t, debugName) == offsetof(lvk::ComputePipelineDesc, debugName), "layout mismatch: lvk_compute_pipeline_desc_t::debugName");
static_assert(offsetof(lvk_ray_tracing_hit_group_desc_t, smClosestHit) == offsetof(lvk::RayTracingHitGroupDesc, smClosestHit), "layout mismatch: lvk_ray_tracing_hit_group_desc_t::smClosestHit");
static_assert(offsetof(lvk_ray_tracing_hit_group_desc_t, smAnyHit) == offsetof(lvk::RayTracingHitGroupDesc, smAnyHit), "layout mismatch: lvk_ray_tracing_hit_group_desc_t::smAnyHit");
static_assert(offsetof(lvk_ray_tracing_hit_group_desc_t, smIntersection) == offsetof(lvk::RayTracingHitGroupDesc, smIntersection), "layout mismatch: lvk_ray_tracing_hit_group_desc_t::smIntersection");
static_assert(offsetof(lvk_ray_tracing_pipeline_desc_t, smRayGen) == offsetof(lvk::RayTracingPipelineDesc, smRayGen), "layout mismatch: lvk_ray_tracing_pipeline_desc_t::smRayGen");
static_assert(offsetof(lvk_ray_tracing_pipeline_desc_t, smMiss) == offsetof(lvk::RayTracingPipelineDesc, smMiss), "layout mismatch: lvk_ray_tracing_pipeline_desc_t::smMiss");
static_assert(offsetof(lvk_ray_tracing_pipeline_desc_t, smCallable) == offsetof(lvk::RayTracingPipelineDesc, smCallable), "layout mismatch: lvk_ray_tracing_pipeline_desc_t::smCallable");
static_assert(offsetof(lvk_ray_tracing_pipeline_desc_t, hitGroups) == offsetof(lvk::RayTracingPipelineDesc, hitGroups), "layout mismatch: lvk_ray_tracing_pipeline_desc_t::hitGroups");
static_assert(offsetof(lvk_ray_tracing_pipeline_desc_t, specInfo) == offsetof(lvk::RayTracingPipelineDesc, specInfo), "layout mismatch: lvk_ray_tracing_pipeline_desc_t::specInfo");
static_assert(offsetof(lvk_ray_tracing_pipeline_desc_t, maxRecursionDepth) == offsetof(lvk::RayTracingPipelineDesc, maxRecursionDepth), "layout mismatch: lvk_ray_tracing_pipeline_desc_t::maxRecursionDepth");
static_assert(offsetof(lvk_ray_tracing_pipeline_desc_t, stackSize) == offsetof(lvk::RayTracingPipelineDesc, stackSize), "layout mismatch: lvk_ray_tracing_pipeline_desc_t::stackSize");
static_assert(offsetof(lvk_ray_tracing_pipeline_desc_t, debugName) == offsetof(lvk::RayTracingPipelineDesc, debugName), "layout mismatch: lvk_ray_tracing_pipeline_desc_t::debugName");
static_assert(offsetof(lvk_render_pass_t, color) == offsetof(lvk::RenderPass, color), "layout mismatch: lvk_render_pass_t::color");
static_assert(offsetof(lvk_render_pass_t, depth) == offsetof(lvk::RenderPass, depth), "layout mismatch: lvk_render_pass_t::depth");
static_assert(offsetof(lvk_render_pass_t, stencil) == offsetof(lvk::RenderPass, stencil), "layout mismatch: lvk_render_pass_t::stencil");
static_assert(offsetof(lvk_render_pass_t, layerCount) == offsetof(lvk::RenderPass, layerCount), "layout mismatch: lvk_render_pass_t::layerCount");
static_assert(offsetof(lvk_render_pass_t, viewMask) == offsetof(lvk::RenderPass, viewMask), "layout mismatch: lvk_render_pass_t::viewMask");
static_assert(offsetof(lvk_render_pass_t, attachmentlessWidth) == offsetof(lvk::RenderPass, attachmentlessWidth), "layout mismatch: lvk_render_pass_t::attachmentlessWidth");
static_assert(offsetof(lvk_render_pass_t, attachmentlessHeight) == offsetof(lvk::RenderPass, attachmentlessHeight), "layout mismatch: lvk_render_pass_t::attachmentlessHeight");
static_assert(offsetof(lvk_render_pass_attachment_desc_t, loadOp) == offsetof(lvk::RenderPass::AttachmentDesc, loadOp), "layout mismatch: lvk_render_pass_attachment_desc_t::loadOp");
static_assert(offsetof(lvk_render_pass_attachment_desc_t, storeOp) == offsetof(lvk::RenderPass::AttachmentDesc, storeOp), "layout mismatch: lvk_render_pass_attachment_desc_t::storeOp");
static_assert(offsetof(lvk_render_pass_attachment_desc_t, resolveMode) == offsetof(lvk::RenderPass::AttachmentDesc, resolveMode), "layout mismatch: lvk_render_pass_attachment_desc_t::resolveMode");
static_assert(offsetof(lvk_render_pass_attachment_desc_t, layer) == offsetof(lvk::RenderPass::AttachmentDesc, layer), "layout mismatch: lvk_render_pass_attachment_desc_t::layer");
static_assert(offsetof(lvk_render_pass_attachment_desc_t, level) == offsetof(lvk::RenderPass::AttachmentDesc, level), "layout mismatch: lvk_render_pass_attachment_desc_t::level");
static_assert(offsetof(lvk_render_pass_attachment_desc_t, clearColor) == offsetof(lvk::RenderPass::AttachmentDesc, clearColor), "layout mismatch: lvk_render_pass_attachment_desc_t::clearColor");
static_assert(offsetof(lvk_render_pass_attachment_desc_t, clearDepth) == offsetof(lvk::RenderPass::AttachmentDesc, clearDepth), "layout mismatch: lvk_render_pass_attachment_desc_t::clearDepth");
static_assert(offsetof(lvk_render_pass_attachment_desc_t, clearStencil) == offsetof(lvk::RenderPass::AttachmentDesc, clearStencil), "layout mismatch: lvk_render_pass_attachment_desc_t::clearStencil");
static_assert(offsetof(lvk_framebuffer_t, color) == offsetof(lvk::Framebuffer, color), "layout mismatch: lvk_framebuffer_t::color");
static_assert(offsetof(lvk_framebuffer_t, depthStencil) == offsetof(lvk::Framebuffer, depthStencil), "layout mismatch: lvk_framebuffer_t::depthStencil");
static_assert(offsetof(lvk_framebuffer_t, fragmentDensityMap) == offsetof(lvk::Framebuffer, fragmentDensityMap), "layout mismatch: lvk_framebuffer_t::fragmentDensityMap");
static_assert(offsetof(lvk_framebuffer_t, shadingRateAttachment) == offsetof(lvk::Framebuffer, shadingRateAttachment), "layout mismatch: lvk_framebuffer_t::shadingRateAttachment");
static_assert(offsetof(lvk_framebuffer_t, shadingRateAttachmentTexelSize) == offsetof(lvk::Framebuffer, shadingRateAttachmentTexelSize), "layout mismatch: lvk_framebuffer_t::shadingRateAttachmentTexelSize");
static_assert(offsetof(lvk_framebuffer_t, debugName) == offsetof(lvk::Framebuffer, debugName), "layout mismatch: lvk_framebuffer_t::debugName");
static_assert(offsetof(lvk_framebuffer_attachment_desc_t, texture) == offsetof(lvk::Framebuffer::AttachmentDesc, texture), "layout mismatch: lvk_framebuffer_attachment_desc_t::texture");
static_assert(offsetof(lvk_framebuffer_attachment_desc_t, resolveTexture) == offsetof(lvk::Framebuffer::AttachmentDesc, resolveTexture), "layout mismatch: lvk_framebuffer_attachment_desc_t::resolveTexture");
static_assert(offsetof(lvk_buffer_desc_t, usage) == offsetof(lvk::BufferDesc, usage), "layout mismatch: lvk_buffer_desc_t::usage");
static_assert(offsetof(lvk_buffer_desc_t, storage) == offsetof(lvk::BufferDesc, storage), "layout mismatch: lvk_buffer_desc_t::storage");
static_assert(offsetof(lvk_buffer_desc_t, size) == offsetof(lvk::BufferDesc, size), "layout mismatch: lvk_buffer_desc_t::size");
static_assert(offsetof(lvk_buffer_desc_t, data) == offsetof(lvk::BufferDesc, data), "layout mismatch: lvk_buffer_desc_t::data");
static_assert(offsetof(lvk_buffer_desc_t, debugName) == offsetof(lvk::BufferDesc, debugName), "layout mismatch: lvk_buffer_desc_t::debugName");
static_assert(offsetof(lvk_offset3d_t, x) == offsetof(lvk::Offset3D, x), "layout mismatch: lvk_offset3d_t::x");
static_assert(offsetof(lvk_offset3d_t, y) == offsetof(lvk::Offset3D, y), "layout mismatch: lvk_offset3d_t::y");
static_assert(offsetof(lvk_offset3d_t, z) == offsetof(lvk::Offset3D, z), "layout mismatch: lvk_offset3d_t::z");
static_assert(offsetof(lvk_texture_layers_t, mipLevel) == offsetof(lvk::TextureLayers, mipLevel), "layout mismatch: lvk_texture_layers_t::mipLevel");
static_assert(offsetof(lvk_texture_layers_t, layer) == offsetof(lvk::TextureLayers, layer), "layout mismatch: lvk_texture_layers_t::layer");
static_assert(offsetof(lvk_texture_layers_t, numLayers) == offsetof(lvk::TextureLayers, numLayers), "layout mismatch: lvk_texture_layers_t::numLayers");
static_assert(offsetof(lvk_texture_range_desc_t, offset) == offsetof(lvk::TextureRangeDesc, offset), "layout mismatch: lvk_texture_range_desc_t::offset");
static_assert(offsetof(lvk_texture_range_desc_t, dimensions) == offsetof(lvk::TextureRangeDesc, dimensions), "layout mismatch: lvk_texture_range_desc_t::dimensions");
static_assert(offsetof(lvk_texture_range_desc_t, layer) == offsetof(lvk::TextureRangeDesc, layer), "layout mismatch: lvk_texture_range_desc_t::layer");
static_assert(offsetof(lvk_texture_range_desc_t, numLayers) == offsetof(lvk::TextureRangeDesc, numLayers), "layout mismatch: lvk_texture_range_desc_t::numLayers");
static_assert(offsetof(lvk_texture_range_desc_t, mipLevel) == offsetof(lvk::TextureRangeDesc, mipLevel), "layout mismatch: lvk_texture_range_desc_t::mipLevel");
static_assert(offsetof(lvk_texture_range_desc_t, numMipLevels) == offsetof(lvk::TextureRangeDesc, numMipLevels), "layout mismatch: lvk_texture_range_desc_t::numMipLevels");
static_assert(offsetof(lvk_component_mapping_t, r) == offsetof(lvk::ComponentMapping, r), "layout mismatch: lvk_component_mapping_t::r");
static_assert(offsetof(lvk_component_mapping_t, g) == offsetof(lvk::ComponentMapping, g), "layout mismatch: lvk_component_mapping_t::g");
static_assert(offsetof(lvk_component_mapping_t, b) == offsetof(lvk::ComponentMapping, b), "layout mismatch: lvk_component_mapping_t::b");
static_assert(offsetof(lvk_component_mapping_t, a) == offsetof(lvk::ComponentMapping, a), "layout mismatch: lvk_component_mapping_t::a");
static_assert(offsetof(lvk_texture_desc_t, type) == offsetof(lvk::TextureDesc, type), "layout mismatch: lvk_texture_desc_t::type");
static_assert(offsetof(lvk_texture_desc_t, format) == offsetof(lvk::TextureDesc, format), "layout mismatch: lvk_texture_desc_t::format");
static_assert(offsetof(lvk_texture_desc_t, dimensions) == offsetof(lvk::TextureDesc, dimensions), "layout mismatch: lvk_texture_desc_t::dimensions");
static_assert(offsetof(lvk_texture_desc_t, numLayers) == offsetof(lvk::TextureDesc, numLayers), "layout mismatch: lvk_texture_desc_t::numLayers");
static_assert(offsetof(lvk_texture_desc_t, numSamples) == offsetof(lvk::TextureDesc, numSamples), "layout mismatch: lvk_texture_desc_t::numSamples");
static_assert(offsetof(lvk_texture_desc_t, usage) == offsetof(lvk::TextureDesc, usage), "layout mismatch: lvk_texture_desc_t::usage");
static_assert(offsetof(lvk_texture_desc_t, numMipLevels) == offsetof(lvk::TextureDesc, numMipLevels), "layout mismatch: lvk_texture_desc_t::numMipLevels");
static_assert(offsetof(lvk_texture_desc_t, storage) == offsetof(lvk::TextureDesc, storage), "layout mismatch: lvk_texture_desc_t::storage");
static_assert(offsetof(lvk_texture_desc_t, components) == offsetof(lvk::TextureDesc, components), "layout mismatch: lvk_texture_desc_t::components");
static_assert(offsetof(lvk_texture_desc_t, data) == offsetof(lvk::TextureDesc, data), "layout mismatch: lvk_texture_desc_t::data");
static_assert(offsetof(lvk_texture_desc_t, dataNumMipLevels) == offsetof(lvk::TextureDesc, dataNumMipLevels), "layout mismatch: lvk_texture_desc_t::dataNumMipLevels");
static_assert(offsetof(lvk_texture_desc_t, generateMipmaps) == offsetof(lvk::TextureDesc, generateMipmaps), "layout mismatch: lvk_texture_desc_t::generateMipmaps");
static_assert(offsetof(lvk_texture_desc_t, debugName) == offsetof(lvk::TextureDesc, debugName), "layout mismatch: lvk_texture_desc_t::debugName");
static_assert(offsetof(lvk_texture_view_desc_t, type) == offsetof(lvk::TextureViewDesc, type), "layout mismatch: lvk_texture_view_desc_t::type");
static_assert(offsetof(lvk_texture_view_desc_t, layer) == offsetof(lvk::TextureViewDesc, layer), "layout mismatch: lvk_texture_view_desc_t::layer");
static_assert(offsetof(lvk_texture_view_desc_t, numLayers) == offsetof(lvk::TextureViewDesc, numLayers), "layout mismatch: lvk_texture_view_desc_t::numLayers");
static_assert(offsetof(lvk_texture_view_desc_t, mipLevel) == offsetof(lvk::TextureViewDesc, mipLevel), "layout mismatch: lvk_texture_view_desc_t::mipLevel");
static_assert(offsetof(lvk_texture_view_desc_t, numMipLevels) == offsetof(lvk::TextureViewDesc, numMipLevels), "layout mismatch: lvk_texture_view_desc_t::numMipLevels");
static_assert(offsetof(lvk_texture_view_desc_t, components) == offsetof(lvk::TextureViewDesc, components), "layout mismatch: lvk_texture_view_desc_t::components");
static_assert(offsetof(lvk_texture_view_desc_t, aspect) == offsetof(lvk::TextureViewDesc, aspect), "layout mismatch: lvk_texture_view_desc_t::aspect");
static_assert(offsetof(lvk_opacity_micromap_usage_t, count) == offsetof(lvk::OpacityMicromapUsage, count), "layout mismatch: lvk_opacity_micromap_usage_t::count");
static_assert(offsetof(lvk_opacity_micromap_usage_t, subdivisionLevel) == offsetof(lvk::OpacityMicromapUsage, subdivisionLevel), "layout mismatch: lvk_opacity_micromap_usage_t::subdivisionLevel");
static_assert(offsetof(lvk_opacity_micromap_usage_t, format) == offsetof(lvk::OpacityMicromapUsage, format), "layout mismatch: lvk_opacity_micromap_usage_t::format");
static_assert(offsetof(lvk_opacity_micromap_triangle_t, dataOffset) == offsetof(lvk::OpacityMicromapTriangle, dataOffset), "layout mismatch: lvk_opacity_micromap_triangle_t::dataOffset");
static_assert(offsetof(lvk_opacity_micromap_triangle_t, subdivisionLevel) == offsetof(lvk::OpacityMicromapTriangle, subdivisionLevel), "layout mismatch: lvk_opacity_micromap_triangle_t::subdivisionLevel");
static_assert(offsetof(lvk_opacity_micromap_triangle_t, format) == offsetof(lvk::OpacityMicromapTriangle, format), "layout mismatch: lvk_opacity_micromap_triangle_t::format");
static_assert(offsetof(lvk_accel_struct_sizes_t, accelerationStructureSize) == offsetof(lvk::AccelStructSizes, accelerationStructureSize), "layout mismatch: lvk_accel_struct_sizes_t::accelerationStructureSize");
static_assert(offsetof(lvk_accel_struct_sizes_t, updateScratchSize) == offsetof(lvk::AccelStructSizes, updateScratchSize), "layout mismatch: lvk_accel_struct_sizes_t::updateScratchSize");
static_assert(offsetof(lvk_accel_struct_sizes_t, buildScratchSize) == offsetof(lvk::AccelStructSizes, buildScratchSize), "layout mismatch: lvk_accel_struct_sizes_t::buildScratchSize");
static_assert(offsetof(lvk_accel_struct_build_range_t, primitiveCount) == offsetof(lvk::AccelStructBuildRange, primitiveCount), "layout mismatch: lvk_accel_struct_build_range_t::primitiveCount");
static_assert(offsetof(lvk_accel_struct_build_range_t, primitiveOffset) == offsetof(lvk::AccelStructBuildRange, primitiveOffset), "layout mismatch: lvk_accel_struct_build_range_t::primitiveOffset");
static_assert(offsetof(lvk_accel_struct_build_range_t, firstVertex) == offsetof(lvk::AccelStructBuildRange, firstVertex), "layout mismatch: lvk_accel_struct_build_range_t::firstVertex");
static_assert(offsetof(lvk_accel_struct_build_range_t, transformOffset) == offsetof(lvk::AccelStructBuildRange, transformOffset), "layout mismatch: lvk_accel_struct_build_range_t::transformOffset");
static_assert(offsetof(lvk_mat3x4_t, matrix) == offsetof(lvk::mat3x4, matrix), "layout mismatch: lvk_mat3x4_t::matrix");
static_assert(offsetof(lvk_accel_struct_instance_t, transform) == offsetof(lvk::AccelStructInstance, transform), "layout mismatch: lvk_accel_struct_instance_t::transform");
static_assert(offsetof(lvk_accel_struct_instance_t, accelerationStructureReference) == offsetof(lvk::AccelStructInstance, accelerationStructureReference), "layout mismatch: lvk_accel_struct_instance_t::accelerationStructureReference");
static_assert(offsetof(lvk_accel_struct_desc_t, type) == offsetof(lvk::AccelStructDesc, type), "layout mismatch: lvk_accel_struct_desc_t::type");
static_assert(offsetof(lvk_accel_struct_desc_t, geometryType) == offsetof(lvk::AccelStructDesc, geometryType), "layout mismatch: lvk_accel_struct_desc_t::geometryType");
static_assert(offsetof(lvk_accel_struct_desc_t, geometryFlags) == offsetof(lvk::AccelStructDesc, geometryFlags), "layout mismatch: lvk_accel_struct_desc_t::geometryFlags");
static_assert(offsetof(lvk_accel_struct_desc_t, vertexFormat) == offsetof(lvk::AccelStructDesc, vertexFormat), "layout mismatch: lvk_accel_struct_desc_t::vertexFormat");
static_assert(offsetof(lvk_accel_struct_desc_t, vertexBuffer) == offsetof(lvk::AccelStructDesc, vertexBuffer), "layout mismatch: lvk_accel_struct_desc_t::vertexBuffer");
static_assert(offsetof(lvk_accel_struct_desc_t, vertexStride) == offsetof(lvk::AccelStructDesc, vertexStride), "layout mismatch: lvk_accel_struct_desc_t::vertexStride");
static_assert(offsetof(lvk_accel_struct_desc_t, numVertices) == offsetof(lvk::AccelStructDesc, numVertices), "layout mismatch: lvk_accel_struct_desc_t::numVertices");
static_assert(offsetof(lvk_accel_struct_desc_t, indexFormat) == offsetof(lvk::AccelStructDesc, indexFormat), "layout mismatch: lvk_accel_struct_desc_t::indexFormat");
static_assert(offsetof(lvk_accel_struct_desc_t, indexBuffer) == offsetof(lvk::AccelStructDesc, indexBuffer), "layout mismatch: lvk_accel_struct_desc_t::indexBuffer");
static_assert(offsetof(lvk_accel_struct_desc_t, transformBuffer) == offsetof(lvk::AccelStructDesc, transformBuffer), "layout mismatch: lvk_accel_struct_desc_t::transformBuffer");
static_assert(offsetof(lvk_accel_struct_desc_t, instancesBuffer) == offsetof(lvk::AccelStructDesc, instancesBuffer), "layout mismatch: lvk_accel_struct_desc_t::instancesBuffer");
static_assert(offsetof(lvk_accel_struct_desc_t, micromap) == offsetof(lvk::AccelStructDesc, micromap), "layout mismatch: lvk_accel_struct_desc_t::micromap");
static_assert(offsetof(lvk_accel_struct_desc_t, micromapIndexBuffer) == offsetof(lvk::AccelStructDesc, micromapIndexBuffer), "layout mismatch: lvk_accel_struct_desc_t::micromapIndexBuffer");
static_assert(offsetof(lvk_accel_struct_desc_t, micromapData) == offsetof(lvk::AccelStructDesc, micromapData), "layout mismatch: lvk_accel_struct_desc_t::micromapData");
static_assert(offsetof(lvk_accel_struct_desc_t, micromapTriangles) == offsetof(lvk::AccelStructDesc, micromapTriangles), "layout mismatch: lvk_accel_struct_desc_t::micromapTriangles");
static_assert(offsetof(lvk_accel_struct_desc_t, micromapIndexFormat) == offsetof(lvk::AccelStructDesc, micromapIndexFormat), "layout mismatch: lvk_accel_struct_desc_t::micromapIndexFormat");
static_assert(offsetof(lvk_accel_struct_desc_t, micromapIndexOffset) == offsetof(lvk::AccelStructDesc, micromapIndexOffset), "layout mismatch: lvk_accel_struct_desc_t::micromapIndexOffset");
static_assert(offsetof(lvk_accel_struct_desc_t, micromapUsageCounts) == offsetof(lvk::AccelStructDesc, micromapUsageCounts), "layout mismatch: lvk_accel_struct_desc_t::micromapUsageCounts");
static_assert(offsetof(lvk_accel_struct_desc_t, micromapNumUsageCounts) == offsetof(lvk::AccelStructDesc, micromapNumUsageCounts), "layout mismatch: lvk_accel_struct_desc_t::micromapNumUsageCounts");
static_assert(offsetof(lvk_accel_struct_desc_t, buildRange) == offsetof(lvk::AccelStructDesc, buildRange), "layout mismatch: lvk_accel_struct_desc_t::buildRange");
static_assert(offsetof(lvk_accel_struct_desc_t, buildFlags) == offsetof(lvk::AccelStructDesc, buildFlags), "layout mismatch: lvk_accel_struct_desc_t::buildFlags");
static_assert(offsetof(lvk_accel_struct_desc_t, debugName) == offsetof(lvk::AccelStructDesc, debugName), "layout mismatch: lvk_accel_struct_desc_t::debugName");
static_assert(offsetof(lvk_dependencies_t, sampledImages) == offsetof(lvk::Dependencies, sampledImages), "layout mismatch: lvk_dependencies_t::sampledImages");
static_assert(offsetof(lvk_dependencies_t, storageImages) == offsetof(lvk::Dependencies, storageImages), "layout mismatch: lvk_dependencies_t::storageImages");
static_assert(offsetof(lvk_dependencies_t, buffers) == offsetof(lvk::Dependencies, buffers), "layout mismatch: lvk_dependencies_t::buffers");
static_assert(offsetof(lvk_dependencies_t, inputAttachments) == offsetof(lvk::Dependencies, inputAttachments), "layout mismatch: lvk_dependencies_t::inputAttachments");
static_assert(offsetof(lvk_dependencies_t, waitCompute) == offsetof(lvk::Dependencies, waitCompute), "layout mismatch: lvk_dependencies_t::waitCompute");
static_assert(offsetof(lvk_dependencies_t, waitGraphics) == offsetof(lvk::Dependencies, waitGraphics), "layout mismatch: lvk_dependencies_t::waitGraphics");
static_assert(offsetof(lvk_barrier_t, srcStages) == offsetof(lvk::Barrier, srcStages), "layout mismatch: lvk_barrier_t::srcStages");
static_assert(offsetof(lvk_barrier_t, srcAccess) == offsetof(lvk::Barrier, srcAccess), "layout mismatch: lvk_barrier_t::srcAccess");
static_assert(offsetof(lvk_barrier_t, dstStages) == offsetof(lvk::Barrier, dstStages), "layout mismatch: lvk_barrier_t::dstStages");
static_assert(offsetof(lvk_barrier_t, dstAccess) == offsetof(lvk::Barrier, dstAccess), "layout mismatch: lvk_barrier_t::dstAccess");
static_assert(offsetof(lvk_context_config_t, vulkanVersion) == offsetof(lvk::ContextConfig, vulkanVersion), "layout mismatch: lvk_context_config_t::vulkanVersion");
static_assert(offsetof(lvk_context_config_t, terminateOnValidationError) == offsetof(lvk::ContextConfig, terminateOnValidationError), "layout mismatch: lvk_context_config_t::terminateOnValidationError");
static_assert(offsetof(lvk_context_config_t, enableValidation) == offsetof(lvk::ContextConfig, enableValidation), "layout mismatch: lvk_context_config_t::enableValidation");
static_assert(offsetof(lvk_context_config_t, enableValidationGpuAV) == offsetof(lvk::ContextConfig, enableValidationGpuAV), "layout mismatch: lvk_context_config_t::enableValidationGpuAV");
static_assert(offsetof(lvk_context_config_t, enableValidationSync) == offsetof(lvk::ContextConfig, enableValidationSync), "layout mismatch: lvk_context_config_t::enableValidationSync");
static_assert(offsetof(lvk_context_config_t, generateSPIRVDebugInfo) == offsetof(lvk::ContextConfig, generateSPIRVDebugInfo), "layout mismatch: lvk_context_config_t::generateSPIRVDebugInfo");
static_assert(offsetof(lvk_context_config_t, swapchainRequestedColorSpace) == offsetof(lvk::ContextConfig, swapchainRequestedColorSpace), "layout mismatch: lvk_context_config_t::swapchainRequestedColorSpace");
static_assert(offsetof(lvk_context_config_t, swapchainUseSurfacePreTransform) == offsetof(lvk::ContextConfig, swapchainUseSurfacePreTransform), "layout mismatch: lvk_context_config_t::swapchainUseSurfacePreTransform");
static_assert(offsetof(lvk_context_config_t, pipelineCacheData) == offsetof(lvk::ContextConfig, pipelineCacheData), "layout mismatch: lvk_context_config_t::pipelineCacheData");
static_assert(offsetof(lvk_context_config_t, pipelineCacheDataSize) == offsetof(lvk::ContextConfig, pipelineCacheDataSize), "layout mismatch: lvk_context_config_t::pipelineCacheDataSize");
static_assert(offsetof(lvk_context_config_t, maxRayRecursionDepth) == offsetof(lvk::ContextConfig, maxRayRecursionDepth), "layout mismatch: lvk_context_config_t::maxRayRecursionDepth");
static_assert(offsetof(lvk_context_config_t, presentModes) == offsetof(lvk::ContextConfig, presentModes), "layout mismatch: lvk_context_config_t::presentModes");
static_assert(offsetof(lvk_context_config_t, layers) == offsetof(lvk::ContextConfig, layers), "layout mismatch: lvk_context_config_t::layers");
static_assert(offsetof(lvk_context_config_t, extensionsInstance) == offsetof(lvk::ContextConfig, extensionsInstance), "layout mismatch: lvk_context_config_t::extensionsInstance");
static_assert(offsetof(lvk_context_config_t, extensionsDevice) == offsetof(lvk::ContextConfig, extensionsDevice), "layout mismatch: lvk_context_config_t::extensionsDevice");
static_assert(offsetof(lvk_context_config_t, extensionsDeviceFeatures) == offsetof(lvk::ContextConfig, extensionsDeviceFeatures), "layout mismatch: lvk_context_config_t::extensionsDeviceFeatures");
static_assert(offsetof(lvk_context_config_t, customVkGetInstanceProcAddr) == offsetof(lvk::ContextConfig, customVkGetInstanceProcAddr), "layout mismatch: lvk_context_config_t::customVkGetInstanceProcAddr");
static_assert(offsetof(lvk_context_config_t, enableHeadlessSurface) == offsetof(lvk::ContextConfig, enableHeadlessSurface), "layout mismatch: lvk_context_config_t::enableHeadlessSurface");
static_assert(offsetof(lvk_context_config_t, enableFragmentShadingRate) == offsetof(lvk::ContextConfig, enableFragmentShadingRate), "layout mismatch: lvk_context_config_t::enableFragmentShadingRate");
static_assert(offsetof(lvk_context_config_t, maxStagingBufferSize) == offsetof(lvk::ContextConfig, maxStagingBufferSize), "layout mismatch: lvk_context_config_t::maxStagingBufferSize");

extern "C" {

lvk_hw_device_desc_t lvk_hw_device_desc_default(void) {
  const lvk::HWDeviceDesc v{};
  return std::bit_cast<lvk_hw_device_desc_t>(v);
}

lvk_result_t lvk_result_default(void) {
  const lvk::Result v{};
  return std::bit_cast<lvk_result_t>(v);
}

lvk_scissor_rect_t lvk_scissor_rect_default(void) {
  const lvk::ScissorRect v{};
  return std::bit_cast<lvk_scissor_rect_t>(v);
}

lvk_dimensions_t lvk_dimensions_default(void) {
  const lvk::Dimensions v{};
  return std::bit_cast<lvk_dimensions_t>(v);
}

lvk_viewport_t lvk_viewport_default(void) {
  const lvk::Viewport v{};
  return std::bit_cast<lvk_viewport_t>(v);
}

lvk_sampler_state_desc_t lvk_sampler_state_desc_default(void) {
  const lvk::SamplerStateDesc v{};
  return std::bit_cast<lvk_sampler_state_desc_t>(v);
}

lvk_stencil_face_state_t lvk_stencil_face_state_default(void) {
  const lvk::StencilFaceState v{};
  return std::bit_cast<lvk_stencil_face_state_t>(v);
}

lvk_stencil_state_t lvk_stencil_state_default(void) {
  const lvk::StencilState v{};
  return std::bit_cast<lvk_stencil_state_t>(v);
}

lvk_depth_state_t lvk_depth_state_default(void) {
  const lvk::DepthState v{};
  return std::bit_cast<lvk_depth_state_t>(v);
}

lvk_clear_color_value_t lvk_clear_color_value_default(void) {
  const lvk::ClearColorValue v{};
  return std::bit_cast<lvk_clear_color_value_t>(v);
}

lvk_vertex_input_t lvk_vertex_input_default(void) {
  const lvk::VertexInput v{};
  return std::bit_cast<lvk_vertex_input_t>(v);
}

lvk_vertex_attribute_t lvk_vertex_attribute_default(void) {
  const lvk::VertexInput::VertexAttribute v{};
  return std::bit_cast<lvk_vertex_attribute_t>(v);
}

lvk_vertex_input_binding_t lvk_vertex_input_binding_default(void) {
  const lvk::VertexInput::VertexInputBinding v{};
  return std::bit_cast<lvk_vertex_input_binding_t>(v);
}

lvk_color_attachment_t lvk_color_attachment_default(void) {
  const lvk::ColorAttachment v{};
  return std::bit_cast<lvk_color_attachment_t>(v);
}

lvk_specialization_constant_entry_t lvk_specialization_constant_entry_default(void) {
  const lvk::SpecializationConstantEntry v{};
  return std::bit_cast<lvk_specialization_constant_entry_t>(v);
}

lvk_specialization_constant_desc_t lvk_specialization_constant_desc_default(void) {
  const lvk::SpecializationConstantDesc v{};
  return std::bit_cast<lvk_specialization_constant_desc_t>(v);
}

lvk_render_pipeline_desc_t lvk_render_pipeline_desc_default(void) {
  const lvk::RenderPipelineDesc v{};
  return std::bit_cast<lvk_render_pipeline_desc_t>(v);
}

lvk_compute_pipeline_desc_t lvk_compute_pipeline_desc_default(void) {
  const lvk::ComputePipelineDesc v{};
  return std::bit_cast<lvk_compute_pipeline_desc_t>(v);
}

lvk_ray_tracing_hit_group_desc_t lvk_ray_tracing_hit_group_desc_default(void) {
  const lvk::RayTracingHitGroupDesc v{};
  return std::bit_cast<lvk_ray_tracing_hit_group_desc_t>(v);
}

lvk_ray_tracing_pipeline_desc_t lvk_ray_tracing_pipeline_desc_default(void) {
  const lvk::RayTracingPipelineDesc v{};
  return std::bit_cast<lvk_ray_tracing_pipeline_desc_t>(v);
}

lvk_render_pass_t lvk_render_pass_default(void) {
  const lvk::RenderPass v{};
  return std::bit_cast<lvk_render_pass_t>(v);
}

lvk_render_pass_attachment_desc_t lvk_render_pass_attachment_desc_default(void) {
  const lvk::RenderPass::AttachmentDesc v{};
  return std::bit_cast<lvk_render_pass_attachment_desc_t>(v);
}

lvk_framebuffer_t lvk_framebuffer_default(void) {
  const lvk::Framebuffer v{};
  return std::bit_cast<lvk_framebuffer_t>(v);
}

lvk_framebuffer_attachment_desc_t lvk_framebuffer_attachment_desc_default(void) {
  const lvk::Framebuffer::AttachmentDesc v{};
  return std::bit_cast<lvk_framebuffer_attachment_desc_t>(v);
}

lvk_buffer_desc_t lvk_buffer_desc_default(void) {
  const lvk::BufferDesc v{};
  return std::bit_cast<lvk_buffer_desc_t>(v);
}

lvk_offset3d_t lvk_offset3d_default(void) {
  const lvk::Offset3D v{};
  return std::bit_cast<lvk_offset3d_t>(v);
}

lvk_texture_layers_t lvk_texture_layers_default(void) {
  const lvk::TextureLayers v{};
  return std::bit_cast<lvk_texture_layers_t>(v);
}

lvk_texture_range_desc_t lvk_texture_range_desc_default(void) {
  const lvk::TextureRangeDesc v{};
  return std::bit_cast<lvk_texture_range_desc_t>(v);
}

lvk_component_mapping_t lvk_component_mapping_default(void) {
  const lvk::ComponentMapping v{};
  return std::bit_cast<lvk_component_mapping_t>(v);
}

lvk_texture_desc_t lvk_texture_desc_default(void) {
  const lvk::TextureDesc v{};
  return std::bit_cast<lvk_texture_desc_t>(v);
}

lvk_texture_view_desc_t lvk_texture_view_desc_default(void) {
  const lvk::TextureViewDesc v{};
  return std::bit_cast<lvk_texture_view_desc_t>(v);
}

lvk_opacity_micromap_usage_t lvk_opacity_micromap_usage_default(void) {
  const lvk::OpacityMicromapUsage v{};
  return std::bit_cast<lvk_opacity_micromap_usage_t>(v);
}

lvk_opacity_micromap_triangle_t lvk_opacity_micromap_triangle_default(void) {
  const lvk::OpacityMicromapTriangle v{};
  return std::bit_cast<lvk_opacity_micromap_triangle_t>(v);
}

lvk_accel_struct_sizes_t lvk_accel_struct_sizes_default(void) {
  const lvk::AccelStructSizes v{};
  return std::bit_cast<lvk_accel_struct_sizes_t>(v);
}

lvk_accel_struct_build_range_t lvk_accel_struct_build_range_default(void) {
  const lvk::AccelStructBuildRange v{};
  return std::bit_cast<lvk_accel_struct_build_range_t>(v);
}

lvk_mat3x4_t lvk_mat3x4_default(void) {
  const lvk::mat3x4 v{};
  return std::bit_cast<lvk_mat3x4_t>(v);
}

lvk_accel_struct_instance_t lvk_accel_struct_instance_default(void) {
  const lvk::AccelStructInstance v{};
  return std::bit_cast<lvk_accel_struct_instance_t>(v);
}

lvk_accel_struct_desc_t lvk_accel_struct_desc_default(void) {
  const lvk::AccelStructDesc v{};
  return std::bit_cast<lvk_accel_struct_desc_t>(v);
}

lvk_submit_handle_t lvk_submit_handle_default(void) {
  const lvk::SubmitHandle v{};
  return std::bit_cast<lvk_submit_handle_t>(v);
}

lvk_dependencies_t lvk_dependencies_default(void) {
  const lvk::Dependencies v{};
  return std::bit_cast<lvk_dependencies_t>(v);
}

lvk_barrier_t lvk_barrier_default(void) {
  const lvk::Barrier v{};
  return std::bit_cast<lvk_barrier_t>(v);
}

lvk_context_config_t lvk_context_config_default(void) {
  const lvk::ContextConfig v{};
  return std::bit_cast<lvk_context_config_t>(v);
}

bool lvk_is_quarter_turn(lvk_surface_transform_t transform) {
  return lvk::isQuarterTurn(static_cast<lvk::SurfaceTransform>(transform));
}

void lvk_get_surface_transform_rotation(lvk_surface_transform_t transform, float* outCos, float* outSin) {
  lvk::getSurfaceTransformRotation(static_cast<lvk::SurfaceTransform>(transform), *outCos, *outSin);
}

void lvk_cmd_barrier(lvk_cmd_buffer_t* self, const lvk_barrier_t* barrier) {
  reinterpret_cast<lvk::ICommandBuffer*>(self)->cmdBarrier(*reinterpret_cast<const lvk::Barrier*>(barrier));
}

void lvk_cmd_transition_to_general(lvk_cmd_buffer_t* self, const lvk_span_texture_handle_t* textures, lvk_shader_stage_t extraDstStage) {
  reinterpret_cast<lvk::ICommandBuffer*>(self)->cmdTransitionToGeneral(*reinterpret_cast<const ldr::Span<ldr::Handle<lvk::Texture>>*>(textures), static_cast<lvk::ShaderStage>(extraDstStage));
}

void lvk_cmd_transition_to_shader_read_only(lvk_cmd_buffer_t* self, const lvk_span_texture_handle_t* textures, lvk_shader_stage_t extraDstStage) {
  reinterpret_cast<lvk::ICommandBuffer*>(self)->cmdTransitionToShaderReadOnly(*reinterpret_cast<const ldr::Span<ldr::Handle<lvk::Texture>>*>(textures), static_cast<lvk::ShaderStage>(extraDstStage));
}

void lvk_cmd_transition_to_rendering_local_read(lvk_cmd_buffer_t* self, const lvk_span_texture_handle_t* textures) {
  reinterpret_cast<lvk::ICommandBuffer*>(self)->cmdTransitionToRenderingLocalRead(*reinterpret_cast<const ldr::Span<ldr::Handle<lvk::Texture>>*>(textures));
}

void lvk_cmd_push_debug_group_label(lvk_cmd_buffer_t* self, const char* label, uint32_t colorRGBA) {
  reinterpret_cast<lvk::ICommandBuffer*>(self)->cmdPushDebugGroupLabel(label, colorRGBA);
}

void lvk_cmd_insert_debug_event_label(lvk_cmd_buffer_t* self, const char* label, uint32_t colorRGBA) {
  reinterpret_cast<lvk::ICommandBuffer*>(self)->cmdInsertDebugEventLabel(label, colorRGBA);
}

void lvk_cmd_pop_debug_group_label(lvk_cmd_buffer_t* self) {
  reinterpret_cast<lvk::ICommandBuffer*>(self)->cmdPopDebugGroupLabel();
}

void lvk_cmd_bind_ray_tracing_pipeline(lvk_cmd_buffer_t* self, lvk_ray_tracing_pipeline_handle_t handle) {
  reinterpret_cast<lvk::ICommandBuffer*>(self)->cmdBindRayTracingPipeline(std::bit_cast<lvk::RayTracingPipelineHandle>(handle));
}

void lvk_cmd_bind_compute_pipeline(lvk_cmd_buffer_t* self, lvk_compute_pipeline_handle_t handle) {
  reinterpret_cast<lvk::ICommandBuffer*>(self)->cmdBindComputePipeline(std::bit_cast<lvk::ComputePipelineHandle>(handle));
}

void lvk_cmd_dispatch(lvk_cmd_buffer_t* self, const lvk_dimensions_t* groupCount, const lvk_dependencies_t* deps) {
  reinterpret_cast<lvk::ICommandBuffer*>(self)->cmdDispatch(*reinterpret_cast<const lvk::Dimensions*>(groupCount), *reinterpret_cast<const lvk::Dependencies*>(deps));
}

void lvk_cmd_dispatch_indirect(lvk_cmd_buffer_t* self, lvk_buffer_handle_t indirectBuffer, size_t indirectBufferOffset, const lvk_dependencies_t* deps) {
  reinterpret_cast<lvk::ICommandBuffer*>(self)->cmdDispatchIndirect(std::bit_cast<lvk::BufferHandle>(indirectBuffer), indirectBufferOffset, *reinterpret_cast<const lvk::Dependencies*>(deps));
}

void lvk_cmd_begin_rendering(lvk_cmd_buffer_t* self, const lvk_render_pass_t* renderPass, const lvk_framebuffer_t* desc, const lvk_dependencies_t* deps) {
  reinterpret_cast<lvk::ICommandBuffer*>(self)->cmdBeginRendering(*reinterpret_cast<const lvk::RenderPass*>(renderPass), *reinterpret_cast<const lvk::Framebuffer*>(desc), *reinterpret_cast<const lvk::Dependencies*>(deps));
}

void lvk_cmd_end_rendering(lvk_cmd_buffer_t* self) {
  reinterpret_cast<lvk::ICommandBuffer*>(self)->cmdEndRendering();
}

void lvk_cmd_next_subpass(lvk_cmd_buffer_t* self) {
  reinterpret_cast<lvk::ICommandBuffer*>(self)->cmdNextSubpass();
}

void lvk_cmd_bind_viewport(lvk_cmd_buffer_t* self, const lvk_viewport_t* viewport) {
  reinterpret_cast<lvk::ICommandBuffer*>(self)->cmdBindViewport(*reinterpret_cast<const lvk::Viewport*>(viewport));
}

void lvk_cmd_bind_scissor_rect(lvk_cmd_buffer_t* self, const lvk_scissor_rect_t* rect) {
  reinterpret_cast<lvk::ICommandBuffer*>(self)->cmdBindScissorRect(*reinterpret_cast<const lvk::ScissorRect*>(rect));
}

void lvk_cmd_bind_render_pipeline(lvk_cmd_buffer_t* self, lvk_render_pipeline_handle_t handle) {
  reinterpret_cast<lvk::ICommandBuffer*>(self)->cmdBindRenderPipeline(std::bit_cast<lvk::RenderPipelineHandle>(handle));
}

void lvk_cmd_bind_depth_state(lvk_cmd_buffer_t* self, const lvk_depth_state_t* state) {
  reinterpret_cast<lvk::ICommandBuffer*>(self)->cmdBindDepthState(*reinterpret_cast<const lvk::DepthState*>(state));
}

void lvk_cmd_bind_stencil_state(lvk_cmd_buffer_t* self, const lvk_stencil_state_t* state) {
  reinterpret_cast<lvk::ICommandBuffer*>(self)->cmdBindStencilState(*reinterpret_cast<const lvk::StencilState*>(state));
}

void lvk_cmd_bind_vertex_buffer(lvk_cmd_buffer_t* self, uint32_t index, lvk_buffer_handle_t buffer, uint64_t bufferOffset, uint64_t bufferSize) {
  reinterpret_cast<lvk::ICommandBuffer*>(self)->cmdBindVertexBuffer(index, std::bit_cast<lvk::BufferHandle>(buffer), bufferOffset, bufferSize);
}

void lvk_cmd_bind_index_buffer(lvk_cmd_buffer_t* self, lvk_buffer_handle_t indexBuffer, lvk_index_format_t indexFormat, uint64_t bufferOffset, uint64_t bufferSize) {
  reinterpret_cast<lvk::ICommandBuffer*>(self)->cmdBindIndexBuffer(std::bit_cast<lvk::BufferHandle>(indexBuffer), static_cast<lvk::IndexFormat>(indexFormat), bufferOffset, bufferSize);
}

void lvk_cmd_push_constants(lvk_cmd_buffer_t* self, const void* data, size_t size, size_t offset) {
  reinterpret_cast<lvk::ICommandBuffer*>(self)->cmdPushConstants(data, size, offset);
}

void lvk_cmd_copy_buffer(lvk_cmd_buffer_t* self, lvk_buffer_handle_t srcBuffer, lvk_buffer_handle_t dstBuffer, size_t srcOffset, size_t dstOffset, size_t size) {
  reinterpret_cast<lvk::ICommandBuffer*>(self)->cmdCopyBuffer(std::bit_cast<lvk::BufferHandle>(srcBuffer), std::bit_cast<lvk::BufferHandle>(dstBuffer), srcOffset, dstOffset, size);
}

void lvk_cmd_fill_buffer(lvk_cmd_buffer_t* self, lvk_buffer_handle_t buffer, size_t bufferOffset, size_t size, uint32_t data) {
  reinterpret_cast<lvk::ICommandBuffer*>(self)->cmdFillBuffer(std::bit_cast<lvk::BufferHandle>(buffer), bufferOffset, size, data);
}

void lvk_cmd_update_buffer(lvk_cmd_buffer_t* self, lvk_buffer_handle_t buffer, size_t bufferOffset, size_t size, const void* data) {
  reinterpret_cast<lvk::ICommandBuffer*>(self)->cmdUpdateBuffer(std::bit_cast<lvk::BufferHandle>(buffer), bufferOffset, size, data);
}

void lvk_cmd_draw(lvk_cmd_buffer_t* self, uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t baseInstance) {
  reinterpret_cast<lvk::ICommandBuffer*>(self)->cmdDraw(vertexCount, instanceCount, firstVertex, baseInstance);
}

void lvk_cmd_draw_indexed(lvk_cmd_buffer_t* self, uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, int32_t vertexOffset, uint32_t baseInstance) {
  reinterpret_cast<lvk::ICommandBuffer*>(self)->cmdDrawIndexed(indexCount, instanceCount, firstIndex, vertexOffset, baseInstance);
}

void lvk_cmd_draw_indirect(lvk_cmd_buffer_t* self, lvk_buffer_handle_t indirectBuffer, size_t indirectBufferOffset, uint32_t drawCount, uint32_t stride) {
  reinterpret_cast<lvk::ICommandBuffer*>(self)->cmdDrawIndirect(std::bit_cast<lvk::BufferHandle>(indirectBuffer), indirectBufferOffset, drawCount, stride);
}

void lvk_cmd_draw_indexed_indirect(lvk_cmd_buffer_t* self, lvk_buffer_handle_t indirectBuffer, size_t indirectBufferOffset, uint32_t drawCount, uint32_t stride) {
  reinterpret_cast<lvk::ICommandBuffer*>(self)->cmdDrawIndexedIndirect(std::bit_cast<lvk::BufferHandle>(indirectBuffer), indirectBufferOffset, drawCount, stride);
}

void lvk_cmd_draw_indexed_indirect_count(lvk_cmd_buffer_t* self, lvk_buffer_handle_t indirectBuffer, size_t indirectBufferOffset, lvk_buffer_handle_t countBuffer, size_t countBufferOffset, uint32_t maxDrawCount, uint32_t stride) {
  reinterpret_cast<lvk::ICommandBuffer*>(self)->cmdDrawIndexedIndirectCount(std::bit_cast<lvk::BufferHandle>(indirectBuffer), indirectBufferOffset, std::bit_cast<lvk::BufferHandle>(countBuffer), countBufferOffset, maxDrawCount, stride);
}

void lvk_cmd_draw_mesh_tasks(lvk_cmd_buffer_t* self, const lvk_dimensions_t* threadgroupCount) {
  reinterpret_cast<lvk::ICommandBuffer*>(self)->cmdDrawMeshTasks(*reinterpret_cast<const lvk::Dimensions*>(threadgroupCount));
}

void lvk_cmd_draw_mesh_tasks_indirect(lvk_cmd_buffer_t* self, lvk_buffer_handle_t indirectBuffer, size_t indirectBufferOffset, uint32_t drawCount, uint32_t stride) {
  reinterpret_cast<lvk::ICommandBuffer*>(self)->cmdDrawMeshTasksIndirect(std::bit_cast<lvk::BufferHandle>(indirectBuffer), indirectBufferOffset, drawCount, stride);
}

void lvk_cmd_draw_mesh_tasks_indirect_count(lvk_cmd_buffer_t* self, lvk_buffer_handle_t indirectBuffer, size_t indirectBufferOffset, lvk_buffer_handle_t countBuffer, size_t countBufferOffset, uint32_t maxDrawCount, uint32_t stride) {
  reinterpret_cast<lvk::ICommandBuffer*>(self)->cmdDrawMeshTasksIndirectCount(std::bit_cast<lvk::BufferHandle>(indirectBuffer), indirectBufferOffset, std::bit_cast<lvk::BufferHandle>(countBuffer), countBufferOffset, maxDrawCount, stride);
}

void lvk_cmd_trace_rays(lvk_cmd_buffer_t* self, uint32_t width, uint32_t height, uint32_t depth, const lvk_dependencies_t* deps) {
  reinterpret_cast<lvk::ICommandBuffer*>(self)->cmdTraceRays(width, height, depth, *reinterpret_cast<const lvk::Dependencies*>(deps));
}

void lvk_cmd_set_blend_color(lvk_cmd_buffer_t* self, const float* color) {
  reinterpret_cast<lvk::ICommandBuffer*>(self)->cmdSetBlendColor(color);
}

void lvk_cmd_set_depth_bias(lvk_cmd_buffer_t* self, float constantFactor, float slopeFactor, float clamp) {
  reinterpret_cast<lvk::ICommandBuffer*>(self)->cmdSetDepthBias(constantFactor, slopeFactor, clamp);
}

void lvk_cmd_set_depth_bias_enable(lvk_cmd_buffer_t* self, bool enable) {
  reinterpret_cast<lvk::ICommandBuffer*>(self)->cmdSetDepthBiasEnable(enable);
}

void lvk_cmd_set_depth_bounds(lvk_cmd_buffer_t* self, float minDepthBounds, float maxDepthBounds) {
  reinterpret_cast<lvk::ICommandBuffer*>(self)->cmdSetDepthBounds(minDepthBounds, maxDepthBounds);
}

void lvk_cmd_set_primitive_restart_enable(lvk_cmd_buffer_t* self, bool enable) {
  reinterpret_cast<lvk::ICommandBuffer*>(self)->cmdSetPrimitiveRestartEnable(enable);
}

void lvk_cmd_set_fragment_shading_rate(lvk_cmd_buffer_t* self, const lvk_dimensions_t* fragmentSize, lvk_shading_rate_combiner_op_t primitiveOp, lvk_shading_rate_combiner_op_t attachmentOp) {
  reinterpret_cast<lvk::ICommandBuffer*>(self)->cmdSetFragmentShadingRate(*reinterpret_cast<const lvk::Dimensions*>(fragmentSize), static_cast<lvk::ShadingRateCombinerOp>(primitiveOp), static_cast<lvk::ShadingRateCombinerOp>(attachmentOp));
}

void lvk_cmd_reset_query_pool(lvk_cmd_buffer_t* self, lvk_query_pool_handle_t pool, uint32_t firstQuery, uint32_t queryCount) {
  reinterpret_cast<lvk::ICommandBuffer*>(self)->cmdResetQueryPool(std::bit_cast<lvk::QueryPoolHandle>(pool), firstQuery, queryCount);
}

void lvk_cmd_write_timestamp(lvk_cmd_buffer_t* self, lvk_query_pool_handle_t pool, uint32_t query) {
  reinterpret_cast<lvk::ICommandBuffer*>(self)->cmdWriteTimestamp(std::bit_cast<lvk::QueryPoolHandle>(pool), query);
}

void lvk_cmd_clear_color_image(lvk_cmd_buffer_t* self, lvk_texture_handle_t tex, const lvk_clear_color_value_t* value, const lvk_texture_layers_t* layers) {
  reinterpret_cast<lvk::ICommandBuffer*>(self)->cmdClearColorImage(std::bit_cast<lvk::TextureHandle>(tex), *reinterpret_cast<const lvk::ClearColorValue*>(value), *reinterpret_cast<const lvk::TextureLayers*>(layers));
}

void lvk_cmd_copy_image(lvk_cmd_buffer_t* self, lvk_texture_handle_t src, lvk_texture_handle_t dst, const lvk_dimensions_t* extent, const lvk_offset3d_t* srcOffset, const lvk_offset3d_t* dstOffset, const lvk_texture_layers_t* srcLayers, const lvk_texture_layers_t* dstLayers) {
  reinterpret_cast<lvk::ICommandBuffer*>(self)->cmdCopyImage(std::bit_cast<lvk::TextureHandle>(src), std::bit_cast<lvk::TextureHandle>(dst), *reinterpret_cast<const lvk::Dimensions*>(extent), *reinterpret_cast<const lvk::Offset3D*>(srcOffset), *reinterpret_cast<const lvk::Offset3D*>(dstOffset), *reinterpret_cast<const lvk::TextureLayers*>(srcLayers), *reinterpret_cast<const lvk::TextureLayers*>(dstLayers));
}

void lvk_cmd_generate_mipmap(lvk_cmd_buffer_t* self, lvk_texture_handle_t handle) {
  reinterpret_cast<lvk::ICommandBuffer*>(self)->cmdGenerateMipmap(std::bit_cast<lvk::TextureHandle>(handle));
}

void lvk_cmd_update_tlas(lvk_cmd_buffer_t* self, lvk_accel_struct_handle_t handle, lvk_buffer_handle_t instancesBuffer) {
  reinterpret_cast<lvk::ICommandBuffer*>(self)->cmdUpdateTLAS(std::bit_cast<lvk::AccelStructHandle>(handle), std::bit_cast<lvk::BufferHandle>(instancesBuffer));
}

void lvk_cmd_update_blas(lvk_cmd_buffer_t* self, const lvk_span_accel_struct_handle_t* handles) {
  reinterpret_cast<lvk::ICommandBuffer*>(self)->cmdUpdateBLAS(*reinterpret_cast<const ldr::Span<ldr::Handle<lvk::AccelerationStructure>>*>(handles));
}

lvk_cmd_buffer_t* lvk_context_acquire_command_buffer(lvk_context_t* self, bool dedicatedCompute) {
  return reinterpret_cast<lvk_cmd_buffer_t*>(&(reinterpret_cast<lvk::IContext*>(self)->acquireCommandBuffer(dedicatedCompute)));
}

lvk_submit_handle_t lvk_context_submit(lvk_context_t* self, lvk_cmd_buffer_t* commandBuffer, lvk_texture_handle_t present, const lvk_span_texture_handle_t* release) {
  return std::bit_cast<lvk_submit_handle_t>(reinterpret_cast<lvk::IContext*>(self)->submit(*reinterpret_cast<lvk::ICommandBuffer*>(commandBuffer), std::bit_cast<lvk::TextureHandle>(present), *reinterpret_cast<const ldr::Span<ldr::Handle<lvk::Texture>>*>(release)));
}

void lvk_context_wait(lvk_context_t* self, lvk_submit_handle_t handle) {
  reinterpret_cast<lvk::IContext*>(self)->wait(std::bit_cast<lvk::SubmitHandle>(handle));
}

bool lvk_context_is_ready(lvk_context_t* self, lvk_submit_handle_t handle) {
  return reinterpret_cast<lvk::IContext*>(self)->isReady(std::bit_cast<lvk::SubmitHandle>(handle));
}

lvk_buffer_handle_t lvk_context_create_buffer(lvk_context_t* self, const lvk_buffer_desc_t* desc, const char* debugName, lvk_result_t* outResult) {
  return std::bit_cast<lvk_buffer_handle_t>((reinterpret_cast<lvk::IContext*>(self)->createBuffer(*reinterpret_cast<const lvk::BufferDesc*>(desc), debugName, reinterpret_cast<lvk::Result*>(outResult))).release());
}

lvk_sampler_handle_t lvk_context_create_sampler(lvk_context_t* self, const lvk_sampler_state_desc_t* desc, lvk_result_t* outResult) {
  return std::bit_cast<lvk_sampler_handle_t>((reinterpret_cast<lvk::IContext*>(self)->createSampler(*reinterpret_cast<const lvk::SamplerStateDesc*>(desc), reinterpret_cast<lvk::Result*>(outResult))).release());
}

lvk_texture_handle_t lvk_context_create_texture(lvk_context_t* self, const lvk_texture_desc_t* desc, const char* debugName, lvk_result_t* outResult) {
  return std::bit_cast<lvk_texture_handle_t>((reinterpret_cast<lvk::IContext*>(self)->createTexture(*reinterpret_cast<const lvk::TextureDesc*>(desc), debugName, reinterpret_cast<lvk::Result*>(outResult))).release());
}

lvk_texture_handle_t lvk_context_create_texture_view(lvk_context_t* self, lvk_texture_handle_t texture, const lvk_texture_view_desc_t* desc, const char* debugName, lvk_result_t* outResult) {
  return std::bit_cast<lvk_texture_handle_t>((reinterpret_cast<lvk::IContext*>(self)->createTextureView(std::bit_cast<lvk::TextureHandle>(texture), *reinterpret_cast<const lvk::TextureViewDesc*>(desc), debugName, reinterpret_cast<lvk::Result*>(outResult))).release());
}

lvk_compute_pipeline_handle_t lvk_context_create_compute_pipeline(lvk_context_t* self, const lvk_compute_pipeline_desc_t* desc, lvk_result_t* outResult) {
  return std::bit_cast<lvk_compute_pipeline_handle_t>((reinterpret_cast<lvk::IContext*>(self)->createComputePipeline(*reinterpret_cast<const lvk::ComputePipelineDesc*>(desc), reinterpret_cast<lvk::Result*>(outResult))).release());
}

lvk_render_pipeline_handle_t lvk_context_create_render_pipeline(lvk_context_t* self, const lvk_render_pipeline_desc_t* desc, lvk_result_t* outResult) {
  return std::bit_cast<lvk_render_pipeline_handle_t>((reinterpret_cast<lvk::IContext*>(self)->createRenderPipeline(*reinterpret_cast<const lvk::RenderPipelineDesc*>(desc), reinterpret_cast<lvk::Result*>(outResult))).release());
}

lvk_ray_tracing_pipeline_handle_t lvk_context_create_ray_tracing_pipeline(lvk_context_t* self, const lvk_ray_tracing_pipeline_desc_t* desc, lvk_result_t* outResult) {
  return std::bit_cast<lvk_ray_tracing_pipeline_handle_t>((reinterpret_cast<lvk::IContext*>(self)->createRayTracingPipeline(*reinterpret_cast<const lvk::RayTracingPipelineDesc*>(desc), reinterpret_cast<lvk::Result*>(outResult))).release());
}

lvk_shader_module_handle_t lvk_context_create_shader_module(lvk_context_t* self, const lvk_shader_module_desc_t* desc, lvk_result_t* outResult) {
  return std::bit_cast<lvk_shader_module_handle_t>((reinterpret_cast<lvk::IContext*>(self)->createShaderModule(*reinterpret_cast<const lvk::ShaderModuleDesc*>(desc), reinterpret_cast<lvk::Result*>(outResult))).release());
}

lvk_query_pool_handle_t lvk_context_create_query_pool(lvk_context_t* self, uint32_t numQueries, const char* debugName, lvk_result_t* outResult) {
  return std::bit_cast<lvk_query_pool_handle_t>((reinterpret_cast<lvk::IContext*>(self)->createQueryPool(numQueries, debugName, reinterpret_cast<lvk::Result*>(outResult))).release());
}

lvk_accel_struct_handle_t lvk_context_create_acceleration_structure(lvk_context_t* self, const lvk_accel_struct_desc_t* desc, lvk_result_t* outResult) {
  return std::bit_cast<lvk_accel_struct_handle_t>((reinterpret_cast<lvk::IContext*>(self)->createAccelerationStructure(*reinterpret_cast<const lvk::AccelStructDesc*>(desc), reinterpret_cast<lvk::Result*>(outResult))).release());
}

void lvk_context_destroy_compute_pipeline(lvk_context_t* self, lvk_compute_pipeline_handle_t handle) {
  reinterpret_cast<lvk::IContext*>(self)->destroy(std::bit_cast<lvk::ComputePipelineHandle>(handle));
}

void lvk_context_destroy_render_pipeline(lvk_context_t* self, lvk_render_pipeline_handle_t handle) {
  reinterpret_cast<lvk::IContext*>(self)->destroy(std::bit_cast<lvk::RenderPipelineHandle>(handle));
}

void lvk_context_destroy_ray_tracing_pipeline(lvk_context_t* self, lvk_ray_tracing_pipeline_handle_t arg0) {
  reinterpret_cast<lvk::IContext*>(self)->destroy(std::bit_cast<lvk::RayTracingPipelineHandle>(arg0));
}

void lvk_context_destroy_shader_module(lvk_context_t* self, lvk_shader_module_handle_t handle) {
  reinterpret_cast<lvk::IContext*>(self)->destroy(std::bit_cast<lvk::ShaderModuleHandle>(handle));
}

void lvk_context_destroy_sampler(lvk_context_t* self, lvk_sampler_handle_t handle) {
  reinterpret_cast<lvk::IContext*>(self)->destroy(std::bit_cast<lvk::SamplerHandle>(handle));
}

void lvk_context_destroy_buffer(lvk_context_t* self, lvk_buffer_handle_t handle) {
  reinterpret_cast<lvk::IContext*>(self)->destroy(std::bit_cast<lvk::BufferHandle>(handle));
}

void lvk_context_destroy_texture(lvk_context_t* self, lvk_texture_handle_t handle) {
  reinterpret_cast<lvk::IContext*>(self)->destroy(std::bit_cast<lvk::TextureHandle>(handle));
}

void lvk_context_destroy_query_pool(lvk_context_t* self, lvk_query_pool_handle_t handle) {
  reinterpret_cast<lvk::IContext*>(self)->destroy(std::bit_cast<lvk::QueryPoolHandle>(handle));
}

void lvk_context_destroy_accel_struct(lvk_context_t* self, lvk_accel_struct_handle_t handle) {
  reinterpret_cast<lvk::IContext*>(self)->destroy(std::bit_cast<lvk::AccelStructHandle>(handle));
}

void lvk_context_destroy_framebuffer(lvk_context_t* self, lvk_framebuffer_t* fb) {
  reinterpret_cast<lvk::IContext*>(self)->destroy(*reinterpret_cast<lvk::Framebuffer*>(fb));
}

uint64_t lvk_context_gpu_address_accel_struct(lvk_context_t* self, lvk_accel_struct_handle_t handle) {
  return reinterpret_cast<lvk::IContext*>(self)->gpuAddress(std::bit_cast<lvk::AccelStructHandle>(handle));
}

uint64_t lvk_context_gpu_address_buffer(lvk_context_t* self, lvk_buffer_handle_t handle, size_t offset) {
  return reinterpret_cast<lvk::IContext*>(self)->gpuAddress(std::bit_cast<lvk::BufferHandle>(handle), offset);
}

lvk_accel_struct_sizes_t lvk_context_get_accel_struct_sizes(lvk_context_t* self, const lvk_accel_struct_desc_t* desc, lvk_result_t* outResult) {
  return std::bit_cast<lvk_accel_struct_sizes_t>(reinterpret_cast<lvk::IContext*>(self)->getAccelStructSizes(*reinterpret_cast<const lvk::AccelStructDesc*>(desc), reinterpret_cast<lvk::Result*>(outResult)));
}

lvk_result_t lvk_context_upload_buffer(lvk_context_t* self, lvk_buffer_handle_t handle, const void* data, size_t size, size_t offset) {
  return std::bit_cast<lvk_result_t>(reinterpret_cast<lvk::IContext*>(self)->upload(std::bit_cast<lvk::BufferHandle>(handle), data, size, offset));
}

lvk_result_t lvk_context_upload_texture(lvk_context_t* self, lvk_texture_handle_t handle, const lvk_texture_range_desc_t* range, const void* data, uint32_t bufferRowLength) {
  return std::bit_cast<lvk_result_t>(reinterpret_cast<lvk::IContext*>(self)->upload(std::bit_cast<lvk::TextureHandle>(handle), *reinterpret_cast<const lvk::TextureRangeDesc*>(range), data, bufferRowLength));
}

lvk_result_t lvk_context_download_buffer(lvk_context_t* self, lvk_buffer_handle_t handle, void* data, size_t size, size_t offset) {
  return std::bit_cast<lvk_result_t>(reinterpret_cast<lvk::IContext*>(self)->download(std::bit_cast<lvk::BufferHandle>(handle), data, size, offset));
}

lvk_result_t lvk_context_download_texture(lvk_context_t* self, lvk_texture_handle_t handle, const lvk_texture_range_desc_t* range, void* outData) {
  return std::bit_cast<lvk_result_t>(reinterpret_cast<lvk::IContext*>(self)->download(std::bit_cast<lvk::TextureHandle>(handle), *reinterpret_cast<const lvk::TextureRangeDesc*>(range), outData));
}

uint8_t* lvk_context_get_mapped_ptr(lvk_context_t* self, lvk_buffer_handle_t handle) {
  return reinterpret_cast<lvk::IContext*>(self)->getMappedPtr(std::bit_cast<lvk::BufferHandle>(handle));
}

void lvk_context_flush_mapped_memory(lvk_context_t* self, lvk_buffer_handle_t handle, size_t offset, size_t size) {
  reinterpret_cast<lvk::IContext*>(self)->flushMappedMemory(std::bit_cast<lvk::BufferHandle>(handle), offset, size);
}

void lvk_context_invalidate_mapped_memory(lvk_context_t* self, lvk_buffer_handle_t handle, size_t offset, size_t size) {
  reinterpret_cast<lvk::IContext*>(self)->invalidateMappedMemory(std::bit_cast<lvk::BufferHandle>(handle), offset, size);
}

uint32_t lvk_context_get_max_storage_buffer_range(lvk_context_t* self) {
  return reinterpret_cast<lvk::IContext*>(self)->getMaxStorageBufferRange();
}

lvk_dimensions_t lvk_context_get_dimensions(lvk_context_t* self, lvk_texture_handle_t handle) {
  return std::bit_cast<lvk_dimensions_t>(reinterpret_cast<lvk::IContext*>(self)->getDimensions(std::bit_cast<lvk::TextureHandle>(handle)));
}

float lvk_context_get_aspect_ratio(lvk_context_t* self, lvk_texture_handle_t handle) {
  return reinterpret_cast<lvk::IContext*>(self)->getAspectRatio(std::bit_cast<lvk::TextureHandle>(handle));
}

lvk_format_t lvk_context_get_format(lvk_context_t* self, lvk_texture_handle_t handle) {
  return static_cast<lvk_format_t>(reinterpret_cast<lvk::IContext*>(self)->getFormat(std::bit_cast<lvk::TextureHandle>(handle)));
}

lvk_result_t lvk_context_init_swapchain(lvk_context_t* self, uint32_t width, uint32_t height) {
  return std::bit_cast<lvk_result_t>(reinterpret_cast<lvk::IContext*>(self)->initSwapchain(width, height));
}

lvk_texture_handle_t lvk_context_get_current_swapchain_texture(lvk_context_t* self) {
  return std::bit_cast<lvk_texture_handle_t>(reinterpret_cast<lvk::IContext*>(self)->getCurrentSwapchainTexture());
}

lvk_format_t lvk_context_get_swapchain_format(lvk_context_t* self) {
  return static_cast<lvk_format_t>(reinterpret_cast<lvk::IContext*>(self)->getSwapchainFormat());
}

lvk_color_space_t lvk_context_get_swapchain_color_space(lvk_context_t* self) {
  return static_cast<lvk_color_space_t>(reinterpret_cast<lvk::IContext*>(self)->getSwapchainColorSpace());
}

uint32_t lvk_context_get_swapchain_current_image_index(lvk_context_t* self) {
  return reinterpret_cast<lvk::IContext*>(self)->getSwapchainCurrentImageIndex();
}

uint32_t lvk_context_get_num_swapchain_images(lvk_context_t* self) {
  return reinterpret_cast<lvk::IContext*>(self)->getNumSwapchainImages();
}

lvk_surface_transform_t lvk_context_get_swapchain_surface_transform(lvk_context_t* self) {
  return static_cast<lvk_surface_transform_t>(reinterpret_cast<lvk::IContext*>(self)->getSwapchainSurfaceTransform());
}

bool lvk_context_set_current_present_mode(lvk_context_t* self, lvk_present_mode_t mode) {
  return reinterpret_cast<lvk::IContext*>(self)->setCurrentPresentMode(static_cast<lvk::PresentMode>(mode));
}

lvk_present_mode_t lvk_context_get_current_present_mode(lvk_context_t* self) {
  return static_cast<lvk_present_mode_t>(reinterpret_cast<lvk::IContext*>(self)->getCurrentPresentMode());
}

uint32_t lvk_context_get_framebuffer_msaa_bit_mask(lvk_context_t* self) {
  return reinterpret_cast<lvk::IContext*>(self)->getFramebufferMSAABitMask();
}

lvk_dimensions_t lvk_context_get_shading_rate_attachment_min_texel_size(lvk_context_t* self) {
  return std::bit_cast<lvk_dimensions_t>(reinterpret_cast<lvk::IContext*>(self)->getShadingRateAttachmentMinTexelSize());
}

lvk_dimensions_t lvk_context_get_shading_rate_attachment_max_texel_size(lvk_context_t* self) {
  return std::bit_cast<lvk_dimensions_t>(reinterpret_cast<lvk::IContext*>(self)->getShadingRateAttachmentMaxTexelSize());
}

lvk_span_const_dimensions_t lvk_context_get_supported_fragment_shading_rates(lvk_context_t* self) {
  return std::bit_cast<lvk_span_const_dimensions_t>(reinterpret_cast<lvk::IContext*>(self)->getSupportedFragmentShadingRates());
}

lvk_dimensions_t lvk_context_get_fragment_density_map_min_texel_size(lvk_context_t* self) {
  return std::bit_cast<lvk_dimensions_t>(reinterpret_cast<lvk::IContext*>(self)->getFragmentDensityMapMinTexelSize());
}

bool lvk_context_is_extension_enabled(lvk_context_t* self, const char* ext) {
  return reinterpret_cast<lvk::IContext*>(self)->isExtensionEnabled(ext);
}

bool lvk_context_supports_async_compute(lvk_context_t* self) {
  return reinterpret_cast<lvk::IContext*>(self)->supportsAsyncCompute();
}

bool lvk_context_supports_depth_bounds(lvk_context_t* self) {
  return reinterpret_cast<lvk::IContext*>(self)->supportsDepthBounds();
}

bool lvk_context_supports_mesh_shader(lvk_context_t* self) {
  return reinterpret_cast<lvk::IContext*>(self)->supportsMeshShader();
}

bool lvk_context_supports_provoking_vertex(lvk_context_t* self) {
  return reinterpret_cast<lvk::IContext*>(self)->supportsProvokingVertex();
}

bool lvk_context_supports_ray_query(lvk_context_t* self) {
  return reinterpret_cast<lvk::IContext*>(self)->supportsRayQuery();
}

bool lvk_context_supports_ray_tracing_pipeline(lvk_context_t* self) {
  return reinterpret_cast<lvk::IContext*>(self)->supportsRayTracingPipeline();
}

bool lvk_context_supports_opacity_micromap(lvk_context_t* self) {
  return reinterpret_cast<lvk::IContext*>(self)->supportsOpacityMicromap();
}

bool lvk_context_supports_shader_interlock(lvk_context_t* self) {
  return reinterpret_cast<lvk::IContext*>(self)->supportsShaderInterlock();
}

bool lvk_context_supports_texture_format(lvk_context_t* self, lvk_format_t format, lvk_texture_usage_flags_t usageFlags) {
  return reinterpret_cast<lvk::IContext*>(self)->supportsTextureFormat(static_cast<lvk::Format>(format), usageFlags);
}

bool lvk_context_supports_tensors_arm(lvk_context_t* self) {
  return reinterpret_cast<lvk::IContext*>(self)->supportsTensorsARM();
}

bool lvk_context_supports_data_graph_arm(lvk_context_t* self) {
  return reinterpret_cast<lvk::IContext*>(self)->supportsDataGraphARM();
}

uint32_t lvk_context_get_multiview_max_view_count(lvk_context_t* self) {
  return reinterpret_cast<lvk::IContext*>(self)->getMultiviewMaxViewCount();
}

uint32_t lvk_context_get_multiview_max_mesh_view_count(lvk_context_t* self) {
  return reinterpret_cast<lvk::IContext*>(self)->getMultiviewMaxMeshViewCount();
}

double lvk_context_get_timestamp_period_to_ms(lvk_context_t* self) {
  return reinterpret_cast<lvk::IContext*>(self)->getTimestampPeriodToMs();
}

bool lvk_context_get_query_pool_results(lvk_context_t* self, lvk_query_pool_handle_t pool, uint32_t firstQuery, uint32_t queryCount, size_t dataSize, void* outData, size_t stride) {
  return reinterpret_cast<lvk::IContext*>(self)->getQueryPoolResults(std::bit_cast<lvk::QueryPoolHandle>(pool), firstQuery, queryCount, dataSize, outData, stride);
}

void lvk_context_destroy(lvk_context_t* self) {
  delete reinterpret_cast<lvk::IContext*>(self);
}

bool lvk_is_depth_or_stencil_format(lvk_format_t format) {
  return lvk::isDepthOrStencilFormat(static_cast<lvk::Format>(format));
}

uint32_t lvk_get_num_image_planes(lvk_format_t format) {
  return lvk::getNumImagePlanes(static_cast<lvk::Format>(format));
}

uint32_t lvk_get_texture_bytes_per_layer(uint32_t width, uint32_t height, lvk_format_t format, uint32_t level) {
  return lvk::getTextureBytesPerLayer(width, height, static_cast<lvk::Format>(format), level);
}

uint32_t lvk_get_texture_bytes_per_plane(uint32_t width, uint32_t height, lvk_format_t format, uint32_t plane) {
  return lvk::getTextureBytesPerPlane(width, height, static_cast<lvk::Format>(format), plane);
}

uint32_t lvk_get_vertex_format_size(lvk_vertex_format_t format) {
  return lvk::getVertexFormatSize(static_cast<lvk::VertexFormat>(format));
}

void lvk_log_shader_source(const char* text) {
  lvk::logShaderSource(text);
}

uint32_t lvk_calc_num_mip_levels(uint32_t width, uint32_t height) {
  return lvk::calcNumMipLevels(width, height);
}

#if LVK_WITH_GLFW || LVK_WITH_SDL3 || defined(ANDROID)
lvk_context_t* lvk_create_vulkan_context_with_swapchain(void* window, uint32_t width, uint32_t height, const lvk_context_config_t* cfg, lvk_hw_device_type_t preferredDeviceType, int selectedDevice) {
  return reinterpret_cast<lvk_context_t*>((lvk::createVulkanContextWithSwapchain(reinterpret_cast<GLFWwindow*>(window), width, height, *reinterpret_cast<const lvk::ContextConfig*>(cfg), static_cast<lvk::HWDeviceType>(preferredDeviceType), selectedDevice)).release());
}
#endif

#if LVK_WITH_GLFW || LVK_WITH_SDL3
void* lvk_init_window(const char* windowTitle, int* outWidth, int* outHeight, bool resizable, bool headless) {
  return reinterpret_cast<void*>(lvk::initWindow(windowTitle, *outWidth, *outHeight, resizable, headless));
}
#endif

lvk_shader_module_desc_t lvk_shader_module_desc_from_source(const char* source, lvk_shader_stage_t stage, const char* debugName) {
  return std::bit_cast<lvk_shader_module_desc_t>(lvk::ShaderModuleDesc(source, static_cast<lvk::ShaderStage>(stage), debugName));
}

lvk_shader_module_desc_t lvk_shader_module_desc_from_source_entry_point(const char* source, const char* entryPointName, lvk_shader_stage_t stage, const char* debugName) {
  return std::bit_cast<lvk_shader_module_desc_t>(lvk::ShaderModuleDesc(source, entryPointName, static_cast<lvk::ShaderStage>(stage), debugName));
}

lvk_shader_module_desc_t lvk_shader_module_desc_from_spirv(const void* data, size_t dataLength, lvk_shader_stage_t stage, const char* debugName) {
  return std::bit_cast<lvk_shader_module_desc_t>(lvk::ShaderModuleDesc(data, dataLength, static_cast<lvk::ShaderStage>(stage), debugName));
}

} // extern "C"
