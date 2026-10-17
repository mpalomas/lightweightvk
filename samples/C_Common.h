/*
 * LightweightVK
 *
 * Copyright (c) 2023-2026 Sergey Kosarevsky and contributors.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

/* Helpers shared by the samples written in plain C against the generated C API (lvk/c/lvk_c.h) */

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <GLFW/glfw3.h>
#include <stb_image_write.h>

#include <lvk_c.h>

typedef struct SampleArgs {
  int headless;
  unsigned long long screenshotFrame;
  const char* screenshotFile;
} SampleArgs;

/* --headless, --screenshot-frame <N>, --screenshot-file <name> */
static SampleArgs parseSampleArgs(int argc, char* argv[]) {
  SampleArgs args = {0, 0, "screenshot.png"};
  for (int i = 1; i < argc; i++) {
    if (!strcmp(argv[i], "--headless")) {
      args.headless = 1;
    } else if (!strcmp(argv[i], "--screenshot-frame") && i + 1 < argc) {
      args.screenshotFrame = strtoull(argv[++i], NULL, 10);
    } else if (!strcmp(argv[i], "--screenshot-file") && i + 1 < argc) {
      args.screenshotFile = argv[++i];
    }
  }
  return args;
}

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
