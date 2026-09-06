#include "amdev.h"
#include <am.h>
#include <nemu.h>

#include "klib.h"

#define SYNC_ADDR (VGACTL_ADDR + 4)
size_t screen_h_nemu = 0;
size_t screen_w_nemu = 0;

void __am_gpu_init() {}

void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
  uint32_t gpuctl = *(uint32_t *)VGACTL_ADDR;
  cfg->width = gpuctl >> 16;
  cfg->height = gpuctl & 0xffff;
  screen_h_nemu = cfg->height;
  screen_w_nemu = cfg->width;
  // printf("%d %d\n", screen_w_nemu, screen_h_nemu);
}

void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) {
  if (screen_h_nemu == 0 && screen_w_nemu == 0) {
    screen_w_nemu = 400;
    screen_h_nemu = 320;
  }
  uint32_t *pix = (uint32_t *)ctl->pixels;
  uint32_t *fdb = (uint32_t *)FB_ADDR;
  size_t fb_h = ctl->h;
  size_t fb_w = ctl->w;
  size_t fb_x = ctl->x;
  size_t fb_y = ctl->y;
  for (int i = 0; i < fb_h && i < screen_h_nemu; i++) {
    for (int j = 0; j < fb_w && j < screen_w_nemu; j++) {
      *(fdb + (i + fb_y) * screen_w_nemu + (j + fb_x)) = *(pix + i * fb_w + j);
    }
  }
  if (ctl->sync) {
    outl(SYNC_ADDR, 1);
  }
}

void __am_gpu_status(AM_GPU_STATUS_T *status) { status->ready = true; }
