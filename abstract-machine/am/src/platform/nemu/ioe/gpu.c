#include <am.h>
#include <nemu.h>
#include <stdio.h>
#define SYNC_ADDR (VGACTL_ADDR + 4)
int disp_w , disp_h;

void __am_gpu_init() {
  int i;
  int w = (inl(VGACTL_ADDR) & 0xFFFF0000)>>16;
  int h = inl(VGACTL_ADDR) & 0x0000FFFF;
  disp_w = w;
  disp_h = h;
  uint32_t *fb = (uint32_t *)(uintptr_t)FB_ADDR;
  for (i = 0; i < w * h; i ++) fb[i] = 0x00000000;
  outl(SYNC_ADDR, 1);
}

void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
  *cfg = (AM_GPU_CONFIG_T) {
    .present = true, .has_accel = false,
    .width = disp_w, .height = disp_h,
    .vmemsz = 0
  };
}

void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) {
  uint32_t *pixels = ctl->pixels;
  uint32_t *fb = (uint32_t *)(uintptr_t)FB_ADDR;
  for (int i = 1; i <= ctl->h; i ++){
    for (int j = 1; j <= ctl->w; j ++){
      fb[disp_w*(i+(ctl->y)-1)+j+(ctl->x)-1] = pixels[ctl->w*(i-1)+j-1];
    }
  }
  if (ctl->sync) {
    outl(SYNC_ADDR, 1);
  }
}

void __am_gpu_status(AM_GPU_STATUS_T *status) {
  status->ready = true;
}
