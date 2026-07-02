#include <am.h>
#include <nemu.h>

#define SYNC_ADDR (VGACTL_ADDR + 4)

static int screen_w = 0;
static int screen_h = 0;

void __am_gpu_init() {
  uint32_t wh = inl(VGACTL_ADDR);
  screen_w = wh >> 16;
  screen_h = wh & 0xffff;
}

void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
  *cfg = (AM_GPU_CONFIG_T) {
    .present = true, .has_accel = false,
    .width = screen_w, .height = screen_h,
    .vmemsz = 0
  };
}

void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) {
  if (ctl->pixels) {
    int x = ctl->x, y = ctl->y, draw_w = ctl->w, draw_h = ctl->h;
    uint32_t *pixels = (uint32_t *)ctl->pixels;
    uint32_t *fb = (uint32_t *)(uintptr_t)FB_ADDR;

    for (int j = 0; j < draw_h; j ++) {
      for (int i = 0; i < draw_w; i ++) {
        fb[(y + j) * screen_w + (x + i)] = pixels[j * draw_w + i];
      }
    }
  }

  if (ctl->sync) {
    outl(SYNC_ADDR, 1);
  }
}

void __am_gpu_status(AM_GPU_STATUS_T *status) {
  status->ready = true;
}
