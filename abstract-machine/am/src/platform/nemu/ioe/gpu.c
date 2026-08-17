#include <am.h>
#include <klib.h>
#include <nemu.h>
#include <stdint.h>

#define SYNC_ADDR (VGACTL_ADDR + 4)

void __am_gpu_init() {}

void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
  uint32_t ctl_lower = inl(VGACTL_ADDR);
  int w = ctl_lower >> 16;
  int h = ctl_lower & 0xFFFF;
  *cfg = (AM_GPU_CONFIG_T){.present = true,
                           .has_accel = false,
                           .width = w,
                           .height = h,
                           .vmemsz = w * h * sizeof(uint32_t)};
}

void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) {
  uint32_t ctl_lower = inl(VGACTL_ADDR);
  int w = ctl_lower >> 16;
  uint32_t *fb = (uint32_t *)(uintptr_t)FB_ADDR;
  for (int i = 0; i < ctl->h; i++) {
    for (int j = 0; j < ctl->w; j++)
      outl((uintptr_t)(&fb[(ctl->y + i) * w + ctl->x + j]),
           ((uint32_t *)ctl->pixels)[i * ctl->w + j]);
  }
  if (ctl->sync) {
    outl(SYNC_ADDR, 1);
  }
}

void __am_gpu_status(AM_GPU_STATUS_T *status) { status->ready = true; }
