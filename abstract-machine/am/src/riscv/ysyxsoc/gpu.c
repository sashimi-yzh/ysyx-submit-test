#include <am.h>
#include <klib.h>

#include "include/npc.h"

enum {
  SCREEN_WIDTH = 640,
  SCREEN_HEIGHT = 480,
};

static void write_pixel(int x, int y, uint32_t pixel) {
  if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT) {
    return;
  }

  volatile uint32_t *framebuffer =
      (volatile uint32_t *)(uintptr_t)YSYXSOC_FRAMEBUFFER_ADDR;
  framebuffer[y * SCREEN_WIDTH + x] = pixel;
}

void __am_gpu_init(void) {}

void __am_gpu_config(AM_GPU_CONFIG_T *config) {
  config->present = true;
  config->has_accel = false;
  config->width = SCREEN_WIDTH;
  config->height = SCREEN_HEIGHT;
  config->vmemsz = SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(uint32_t);
}

void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *drawing) {
  if (drawing == NULL || drawing->pixels == NULL) {
    return;
  }

  const uint32_t *pixels = drawing->pixels;
  for (int row = 0; row < drawing->h; row++) {
    for (int column = 0; column < drawing->w; column++) {
      int x = drawing->x + column;
      int y = drawing->y + row;
      write_pixel(x, y, pixels[row * drawing->w + column]);
    }
  }
}

void __am_gpu_status(AM_GPU_STATUS_T *status) {
  status->ready = true;
}
