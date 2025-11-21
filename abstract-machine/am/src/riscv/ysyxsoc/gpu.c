#include <am.h>
#include "include/ysyxsoc.h"

static uint32_t WIDE = 640;
static uint32_t HIGHT = 480;

void __am_gpu_init() {

//   uint32_t disp_wh = inl(VGACTL_ADDR);
//   HIGHT  = disp_wh & 0xffff;
//   WIDE   = disp_wh >> 16;
  uint32_t *fb = (uint32_t *)(uintptr_t)VGA_FB_ADDR;
  for (int i = 0; i < WIDE * HIGHT; i ++){
    fb[i] = 0;
  } 
  outl(VGA_SYNC_ADDR, 1);
}

void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
  *cfg = (AM_GPU_CONFIG_T) {
    .present = true, .has_accel = false,
    .width = WIDE, .height = HIGHT,
    .vmemsz = 0
  };
}

void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) {

  int x = ctl->x, y = ctl->y, w = ctl->w, h = ctl->h;
  if (!ctl->sync && (w == 0 || h == 0)) return;
  uint32_t *pixels = (uint32_t *)(ctl->pixels);
  uint32_t *fb = (uint32_t *)(uintptr_t)VGA_FB_ADDR;
  for (int i = y; i < y+h; i++) {
    for (int j = x; j < x+w; j++) {
      fb[WIDE*i+j] = pixels[w*(i-y)+(j-x)];
    }
  }
  if (ctl->sync) {
    outl(VGA_SYNC_ADDR, 1);
  }
}

void __am_gpu_status(AM_GPU_STATUS_T *status) {
  status->ready = true;
}