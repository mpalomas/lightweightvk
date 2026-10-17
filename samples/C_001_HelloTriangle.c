/*
 * LightweightVK
 *
 * Copyright (c) 2023-2026 Sergey Kosarevsky and contributors.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

/*
 * 001_HelloTriangle written in plain C99 using the generated C API (lvk/c/lvk_c.h).
 * Supports: --headless, --screenshot-frame <N>, --screenshot-file <name>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <GLFW/glfw3.h>
#include <stb_image_write.h>

#include <lvk_c.h>

static const char* codeVS =
    "#version 460\n"
    "layout (location=0) out vec3 color;\n"
    "const vec2 pos[3] = vec2[3](vec2(-0.6, -0.4), vec2(0.6, -0.4), vec2(0.0, 0.6));\n"
    "const vec3 col[3] = vec3[3](vec3(1.0, 0.0, 0.0), vec3(0.0, 1.0, 0.0), vec3(0.0, 0.0, 1.0));\n"
    "void main() {\n"
    "  gl_Position = vec4(pos[gl_VertexIndex], 0.0, 1.0);\n"
    "  color = col[gl_VertexIndex];\n"
    "}\n";

static const char* codeFS =
    "#version 460\n"
    "layout (location=0) in vec3 color;\n"
    "layout (location=0) out vec4 out_FragColor;\n"
    "void main() {\n"
    "  out_FragColor = vec4(color, 1.0);\n"
    "}\n";

static int saveScreenshot(lvk_context_t* ctx, lvk_texture_handle_t texture, const char* fileName) {
  lvk_context_wait(ctx, (lvk_submit_handle_t){0});
  const lvk_dimensions_t dim = lvk_context_get_dimensions(ctx, texture);
  const lvk_format_t format = lvk_context_get_format(ctx, texture);
  if (format != LVK_FORMAT_BGRA_UN8 && format != LVK_FORMAT_BGRA_SRGB8 && format != LVK_FORMAT_RGBA_UN8 && format != LVK_FORMAT_RGBA_SRGB8) {
    fprintf(stderr, "Unsupported pixel format %u\n", (unsigned)format);
    return 0;
  }
  const size_t numPixels = (size_t)dim.width * dim.height;
  uint8_t* rgba = (uint8_t*)malloc(numPixels * 4);
  uint8_t* rgb = (uint8_t*)malloc(numPixels * 3);

  lvk_texture_range_desc_t range = lvk_texture_range_desc_default();
  range.dimensions = dim;
  lvk_context_download_texture(ctx, texture, &range, rgba);

  const int isBGRA = format == LVK_FORMAT_BGRA_UN8 || format == LVK_FORMAT_BGRA_SRGB8;
  for (size_t i = 0; i != numPixels; i++) {
    rgb[3 * i + 0] = rgba[4 * i + (isBGRA ? 2 : 0)];
    rgb[3 * i + 1] = rgba[4 * i + 1];
    rgb[3 * i + 2] = rgba[4 * i + (isBGRA ? 0 : 2)];
  }
  printf("Saving screenshot...%ux%u\n", dim.width, dim.height);
  stbi_write_png(fileName, (int)dim.width, (int)dim.height, 3, rgb, 0);
  free(rgba);
  free(rgb);
  return 1;
}

int main(int argc, char* argv[]) {
  int headless = 0;
  unsigned long long screenshotFrame = 0;
  const char* screenshotFile = "screenshot.png";
  for (int i = 1; i < argc; i++) {
    if (!strcmp(argv[i], "--headless")) {
      headless = 1;
    } else if (!strcmp(argv[i], "--screenshot-frame") && i + 1 < argc) {
      screenshotFrame = strtoull(argv[++i], NULL, 10);
    } else if (!strcmp(argv[i], "--screenshot-file") && i + 1 < argc) {
      screenshotFile = argv[++i];
    }
  }

  int width = 800;
  int height = 600;
  GLFWwindow* window = (GLFWwindow*)lvk_init_window("LVK C API: Hello Triangle", &width, &height, true, headless);

  lvk_context_config_t config = lvk_context_config_default();
  config.enableHeadlessSurface = headless;

  lvk_context_t* ctx = lvk_create_vulkan_context_with_swapchain(window, (uint32_t)width, (uint32_t)height, &config, LVK_HW_DEVICE_TYPE_DISCRETE, -1);
  if (!ctx) {
    fprintf(stderr, "Failed to create a Vulkan context\n");
    return 1;
  }

  const lvk_shader_module_desc_t vertDesc = lvk_shader_module_desc_from_source(codeVS, LVK_STAGE_VERT, "Shader Module: main (vert)");
  const lvk_shader_module_desc_t fragDesc = lvk_shader_module_desc_from_source(codeFS, LVK_STAGE_FRAG, "Shader Module: main (frag)");
  const lvk_shader_module_handle_t vert = lvk_context_create_shader_module(ctx, &vertDesc, NULL);
  const lvk_shader_module_handle_t frag = lvk_context_create_shader_module(ctx, &fragDesc, NULL);

  lvk_render_pipeline_desc_t pipelineDesc = lvk_render_pipeline_desc_default();
  pipelineDesc.smVert = vert;
  pipelineDesc.smFrag = frag;
  pipelineDesc.color[0].format = lvk_context_get_swapchain_format(ctx);
  const lvk_render_pipeline_handle_t pipeline = lvk_context_create_render_pipeline(ctx, &pipelineDesc, NULL);

  unsigned long long frameCount = 0;
  while (headless || !glfwWindowShouldClose(window)) {
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

    lvk_cmd_buffer_t* buffer = lvk_context_acquire_command_buffer(ctx, false);
    lvk_cmd_begin_rendering(buffer, &renderPass, &framebuffer, &noDeps);
    lvk_cmd_bind_render_pipeline(buffer, pipeline);
    lvk_cmd_push_debug_group_label(buffer, "Render Triangle", 0xff0000ff);
    lvk_cmd_draw(buffer, 3, 1, 0, 0);
    lvk_cmd_pop_debug_group_label(buffer);
    lvk_cmd_end_rendering(buffer);
    lvk_context_submit(ctx, buffer, swapchainTexture, &noRelease);

    if (screenshotFrame && ++frameCount == screenshotFrame) {
      saveScreenshot(ctx, swapchainTexture, screenshotFile);
      break;
    }
  }

  lvk_context_wait(ctx, (lvk_submit_handle_t){0});
  lvk_context_destroy_render_pipeline(ctx, pipeline);
  lvk_context_destroy_shader_module(ctx, vert);
  lvk_context_destroy_shader_module(ctx, frag);
  lvk_context_destroy(ctx);

  if (window) {
    glfwDestroyWindow(window);
  }
  glfwTerminate();
  return 0;
}
