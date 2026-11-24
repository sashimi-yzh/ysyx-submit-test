#include <am.h>
#include <soc.h>

int screen_width;

void __am_gpu_init() {
  // this will be used in draw function
  screen_width = inw(VGACTL_ADDR + 4);
}

void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
  *cfg = (AM_GPU_CONFIG_T){.present   = true,
                           .has_accel = false,
                           .width     = inw(VGACTL_ADDR + 4),
                           .height    = inw(VGACTL_ADDR),
                           .vmemsz    = 0};
}

void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) {
  uint32_t *fb     = (uint32_t *)(uintptr_t)FB_ADDR;
  uint32_t *pixels = (uint32_t *)(ctl->pixels);

  int x = ctl->x, y = ctl->y, w = ctl->w, h = ctl->h;

  for (int j = 0; j < h; j++) {
    for (int i = 0; i < w; i++) {
      fb[(y + j) * screen_width + (x + i)] = pixels[j * w + i];
    }
  }
  if (ctl->sync) {
    outl(SYNC_ADDR, 1);
  }
}

void __am_gpu_status(AM_GPU_STATUS_T *status) { status->ready = true; }