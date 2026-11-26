#include <am.h>
#include "npc.h"

// NPC GPU 设备地址（与 device.h 保持一致）
#define VGACTL_ADDR  0x10000100
#define VGASYNC_ADDR 0x10000104
#define FB_ADDR      0x11000000

void __am_gpu_init() {
}

void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
  uint32_t vgactl = inl(VGACTL_ADDR);
  int w = vgactl >> 16;
  int h = vgactl & 0xFFFF;
  *cfg = (AM_GPU_CONFIG_T) {
    .present  = true,
    .has_accel = false,
    .width    = w,
    .height   = h,
    .vmemsz   = w * h * sizeof(uint32_t)
  };
}

void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) {
  if (ctl->pixels != NULL) {
    AM_GPU_CONFIG_T cfg;
    __am_gpu_config(&cfg);
    int screen_w = cfg.width;

    uint32_t *fb     = (uint32_t *)(uintptr_t)FB_ADDR;
    uint32_t *pixels = (uint32_t *)ctl->pixels;

    for (int j = 0; j < ctl->h; j++) {
      for (int i = 0; i < ctl->w; i++) {
        fb[(ctl->y + j) * screen_w + (ctl->x + i)] = pixels[j * ctl->w + i];
      }
    }
  }

  if (ctl->sync) {
    outl(VGASYNC_ADDR, 1);
  }
}

void __am_gpu_status(AM_GPU_STATUS_T *status) {
  status->ready = true;
}
