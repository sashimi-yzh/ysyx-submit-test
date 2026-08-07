#include <am.h>

#define FB_BASE 0x21000000L

void __am_gpu_init() {}

void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
  cfg->present = true;
  cfg->has_accel = false;
  cfg->width = 640;
  cfg->height = 480;
  cfg->vmemsz = 640 * 480 * 4;
}

void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) {
  uint32_t *fb = (uint32_t *)FB_BASE;
  uint32_t *pixels = (uint32_t *)ctl->pixels;
  for (int row = 0; row < ctl->h; row++) {
    for (int col = 0; col < ctl->w; col++) {
      uint32_t offset = (ctl->y + row) * 640 + (ctl->x + col);
      fb[offset] = pixels[row * ctl->w + col];
    }
  }
}

void __am_gpu_status(AM_GPU_STATUS_T *status) { status->ready = true; }
