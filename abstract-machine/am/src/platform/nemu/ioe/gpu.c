#include <am.h>
#include <nemu.h>
#include <klib.h>

#define SYNC_ADDR (VGACTL_ADDR + 4)
static int display_w = 0,display_h=0;
static uint32_t *fb = NULL;
void __am_gpu_init() {
  display_w = inw(VGACTL_ADDR+2);  // TODO: get the correct width
  display_h = inw(VGACTL_ADDR);  // TODO: get the correct height
  fb = (uint32_t *)(uintptr_t)FB_ADDR;
  // for (int i = 0; i < w * h; i ++) fb[i] = 0;
  outl(SYNC_ADDR, 1);
}

void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
  *cfg = (AM_GPU_CONFIG_T) {
    .present = true, .has_accel = false,
    .width = inw(VGACTL_ADDR+2), .height = inw(VGACTL_ADDR),
    .vmemsz = inl(FB_ADDR),
  };
  display_w = cfg->width;
  display_h = cfg->height;
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

  if (draw->sync) {
    outl(SYNC_ADDR, 1);
  }
}

void __am_gpu_status(AM_GPU_STATUS_T *status) {
  status->ready = true;
}
