#include <am.h>
#include <ysyxsoc.h>
#include <klib.h>
#include <riscv.h>
#define SYNC_ADDR (VGACTL_ADDR + 4)

static int display_w = 640,display_h=480;
static uint32_t *fb = NULL;
void __am_gpu_init() {

  printf("w %d,h %d\n",display_w,display_h);
  fb = (uint32_t *)(uintptr_t)FB_BASE;
  for (int i = 0; i < display_w * display_h; i ++) fb[i] = 255;
}

void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
  *cfg = (AM_GPU_CONFIG_T) {
    .present = true, .has_accel = false,
    .width = display_w, .height =display_h,
    .vmemsz = inl(FB_SIZE),
  };
}

void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *draw) {

  int x = draw->x, y = draw->y, w = draw->w, h = draw->h;
  int W = display_w, H = display_h;
  uint32_t *pixels = draw->pixels;
  int len = (x + w >= W) ? W - x : w;
  for (int j = 0; j < h; j ++, pixels += w) {
    if (y + j < H) {
      uint32_t *px = &fb[x + (j + y) * W];
      for (int i = 0; i < len; i ++, px ++) {
        uint32_t p = pixels[i];
        *px = p;
      }
    }
  }

  // if (draw->sync) {
  //   outl(SYNC_ADDR, 1);
  // }
}

void __am_gpu_status(AM_GPU_STATUS_T *status) {
  status->ready = true;
}
