#include <am.h>
#define FB_BASE 0x21000000
static uint32_t screen_width = 0;
static uint32_t screen_height = 0;

void __am_gpu_init() {
  screen_width = 640;
  screen_height = 480;
}

void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
  cfg->present = true;
  cfg->has_accel = false;
  cfg->width = screen_width;
  cfg->height = screen_height;
  cfg->vmemsz = cfg->height * cfg->width * sizeof(uint32_t);
}

void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) {
  int x = ctl->x;
  int y = ctl->y;
  int w = ctl->w;
  int h = ctl->h;
  uint32_t *pixels = ctl->pixels;
  int i, j;
  uint32_t *fb = (uint32_t *)(uintptr_t)FB_BASE;
  for(i = 0 ;i < h; i++) {
    for(j = 0 ;j < w; j++) {
      fb[(y+i)*screen_width + (x+j)] = pixels[i*w+j];
    }
  }
}
