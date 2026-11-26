#include <am.h>
#include "ysyxsoc.h"

#define VGABASE  ((volatile uint32_t *)VGA_FB_BASE)

void __am_gpu_init() {
}

void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
  cfg->present   = true;
  cfg->has_accel = false;
  cfg->width     = VGA_WIDTH;
  cfg->height    = VGA_HEIGHT;
  cfg->vmemsz    = VGA_WIDTH * VGA_HEIGHT * 4;
}

void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) {
  int x = ctl->x, y = ctl->y;
  int w = ctl->w, h = ctl->h;
  uint32_t *pixels = (uint32_t *)ctl->pixels;

  if (pixels != NULL) {
    for (int j = 0; j < h; j++) {
      int yy = y + j;
      if (yy < 0 || yy >= VGA_HEIGHT) continue;
      for (int i = 0; i < w; i++) {
        int xx = x + i;
        if (xx < 0 || xx >= VGA_WIDTH) continue;
        VGABASE[yy * VGA_WIDTH + xx] = pixels[j * w + i];
      }
    }
  }
}

void __am_gpu_status(AM_GPU_STATUS_T *status) {
  status->ready = true;
}
