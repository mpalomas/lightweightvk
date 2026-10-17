/*
 * LightweightVK
 *
 * Copyright (c) 2023-2026 Sergey Kosarevsky and contributors.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

/*
 * 005_MeshShaders written in plain C99 using the generated C API (lvk/c/lvk_c.h).
 * Supports: --headless, --screenshot-frame <N>, --screenshot-file <name>
 */

#include "C_Common.h"

static const char* codeTask =
    "layout(local_size_x = 1, local_size_y = 1, local_size_z = 1) in;\n"
    "void main() {\n"
    "  EmitMeshTasksEXT(1, 1, 1);\n"
    "}\n";

static const char* codeMesh =
    "layout(triangles, max_vertices = 3, max_primitives = 1) out;\n"
    "layout (location=0) out vec3 color[3];\n"
    "const vec2 pos[3] = vec2[3](vec2(-0.6, -0.4), vec2(0.6, -0.4), vec2(0.0, 0.6));\n"
    "const vec3 col[3] = vec3[3](vec3(1.0, 0.0, 0.0), vec3(0.0, 1.0, 0.0), vec3(0.0, 0.0, 1.0));\n"
    "void main() {\n"
    "  SetMeshOutputsEXT(3, 1);\n"
    "  for (uint i = 0; i != 3; i++) {\n"
    "    gl_MeshVerticesEXT[i].gl_Position = vec4(pos[i], 0.0, 1.0);\n"
    "    color[i] = col[i];\n"
    "  }\n"
    "  gl_PrimitiveTriangleIndicesEXT[0] = uvec3(0, 1, 2);\n"
    "}\n";

static const char* codeFrag =
    "#version 460\n"
    "layout (location=0) in vec3 color;\n"
    "layout (location=0) out vec4 out_FragColor;\n"
    "void main() {\n"
    "  out_FragColor = vec4(color, 1.0);\n"
    "}\n";

int main(int argc, char* argv[]) {
  const SampleArgs args = parseSampleArgs(argc, argv);

  int width = 800;
  int height = 600;
  GLFWwindow* window = (GLFWwindow*)lvk_init_window("LVK C API: Mesh Shaders", &width, &height, true, args.headless);

  lvk_context_config_t config = lvk_context_config_default();
  config.enableHeadlessSurface = args.headless;

  lvk_context_t* ctx = lvk_create_vulkan_context_with_swapchain(window, (uint32_t)width, (uint32_t)height, &config, LVK_HW_DEVICE_TYPE_DISCRETE, -1);
  if (!ctx) {
    fprintf(stderr, "Failed to create a Vulkan context\n");
    return 1;
  }
  if (!lvk_context_supports_mesh_shader(ctx)) {
    fprintf(stderr, "Mesh shaders are not supported by this device\n");
    lvk_context_destroy(ctx);
    return 1;
  }

  const lvk_shader_module_desc_t taskDesc = lvk_shader_module_desc_from_source(codeTask, LVK_STAGE_TASK, "Shader Module: main (task)");
  const lvk_shader_module_desc_t meshDesc = lvk_shader_module_desc_from_source(codeMesh, LVK_STAGE_MESH, "Shader Module: main (mesh)");
  const lvk_shader_module_desc_t fragDesc = lvk_shader_module_desc_from_source(codeFrag, LVK_STAGE_FRAG, "Shader Module: main (frag)");
  const lvk_shader_module_handle_t task = lvk_context_create_shader_module(ctx, &taskDesc, NULL);
  const lvk_shader_module_handle_t mesh = lvk_context_create_shader_module(ctx, &meshDesc, NULL);
  const lvk_shader_module_handle_t frag = lvk_context_create_shader_module(ctx, &fragDesc, NULL);

  lvk_render_pipeline_desc_t pipelineDesc = lvk_render_pipeline_desc_default();
  pipelineDesc.smTask = task;
  pipelineDesc.smMesh = mesh;
  pipelineDesc.smFrag = frag;
  pipelineDesc.color[0].format = lvk_context_get_swapchain_format(ctx);
  const lvk_render_pipeline_handle_t pipeline = lvk_context_create_render_pipeline(ctx, &pipelineDesc, NULL);

  unsigned long long frameCount = 0;
  while (args.headless || !glfwWindowShouldClose(window)) {
    if (window) {
      glfwPollEvents();
      int w = 0;
      int h = 0;
      glfwGetFramebufferSize(window, &w, &h);
      if (!w || !h) {
        continue;
      }
      if (w != width || h != height) {
        width = w;
        height = h;
        lvk_context_init_swapchain(ctx, (uint32_t)width, (uint32_t)height);
      }
    }

    const lvk_texture_handle_t swapchainTexture = lvk_context_get_current_swapchain_texture(ctx);

    lvk_render_pass_t renderPass = lvk_render_pass_default();
    renderPass.color[0].loadOp = LVK_LOAD_OP_CLEAR;
    renderPass.color[0].clearColor.float32[0] = 1.0f;
    renderPass.color[0].clearColor.float32[1] = 1.0f;
    renderPass.color[0].clearColor.float32[2] = 1.0f;
    renderPass.color[0].clearColor.float32[3] = 1.0f;

    lvk_framebuffer_t framebuffer = lvk_framebuffer_default();
    framebuffer.color[0].texture = swapchainTexture;

    const lvk_dependencies_t noDeps = lvk_dependencies_default();
    const lvk_span_texture_handle_t noRelease = {NULL, 0};
    const lvk_dimensions_t threadgroupCount = {1, 1, 1};

    lvk_cmd_buffer_t* buffer = lvk_context_acquire_command_buffer(ctx, false);
    lvk_cmd_begin_rendering(buffer, &renderPass, &framebuffer, &noDeps);
    lvk_cmd_bind_render_pipeline(buffer, pipeline);
    lvk_cmd_push_debug_group_label(buffer, "Render Triangle", 0xff0000ff);
    lvk_cmd_draw_mesh_tasks(buffer, &threadgroupCount);
    lvk_cmd_pop_debug_group_label(buffer);
    lvk_cmd_end_rendering(buffer);
    lvk_context_submit(ctx, buffer, swapchainTexture, &noRelease);

    if (args.screenshotFrame && ++frameCount == args.screenshotFrame) {
      saveScreenshot(ctx, swapchainTexture, args.screenshotFile);
      break;
    }
  }

  lvk_context_wait(ctx, (lvk_submit_handle_t){0});
  lvk_context_destroy_render_pipeline(ctx, pipeline);
  lvk_context_destroy_shader_module(ctx, task);
  lvk_context_destroy_shader_module(ctx, mesh);
  lvk_context_destroy_shader_module(ctx, frag);
  lvk_context_destroy(ctx);

  if (window) {
    glfwDestroyWindow(window);
  }
  glfwTerminate();
  return 0;
}
