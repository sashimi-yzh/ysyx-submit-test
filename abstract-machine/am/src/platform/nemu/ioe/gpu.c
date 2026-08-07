#include <am.h>
#include <nemu.h>
#include <stdio.h>

#define SYNC_ADDR (VGACTL_ADDR + 4)

void __am_gpu_init() {
  int i;
  int w = (inl(VGACTL_ADDR) >> 16);
  int h = (inl(VGACTL_ADDR) & 0xffff);
  uint32_t *fb = (uint32_t *)(uintptr_t)FB_ADDR;
  for (i = 0; i < w * h; i++)
    fb[i] = 0x00ffffff;
  outl(SYNC_ADDR, 1);
}

void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
  int w = (inl(VGACTL_ADDR) >> 16);
  int h = (inl(VGACTL_ADDR) & 0xffff);
  *cfg = (AM_GPU_CONFIG_T){
      .present = true,
      .has_accel = false,
      .width = w,
      .height = h,
      .vmemsz = w * h * sizeof(uint32_t),
  };
}

void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) {
  int w = ctl->w, h = ctl->h, x = ctl->x, y = ctl->y;
  uint32_t *pixels = ctl->pixels;
  int screen_w = (inl(VGACTL_ADDR) >> 16);
  int screen_h = (inl(VGACTL_ADDR) & 0xffff);
  for (int i = x; i < x + w; i++) {
    if (i >= screen_w)
      break;
    for (int j = y; j < y + h; j++) {
      if (j >= screen_h)
        break;
      outl(FB_ADDR + (j * screen_w + i) * sizeof(uint32_t), pixels[(j - y) * w + (i - x)]);
    }
  }
  if (ctl->sync) {
    outl(SYNC_ADDR, 1);
  }
}

void __am_gpu_status(AM_GPU_STATUS_T *status) {
  status->ready = true;
}
