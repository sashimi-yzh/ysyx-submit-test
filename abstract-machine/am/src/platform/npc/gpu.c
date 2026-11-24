#include <am.h>
#include <npc.h>

#define SYNC_ADDR (VGACTL_ADDR + 4)
int screen_width;

void __am_gpu_init() {
  // this will be used in draw function
  screen_width = inw(VGACTL_ADDR + 2);
}

void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
  *cfg = (AM_GPU_CONFIG_T) {
    .present = true, .has_accel = false,
    .width = inw(VGACTL_ADDR + 2), .height = inw(VGACTL_ADDR),
    .vmemsz = 0
  };
}

void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) {
  int x = ctl->x, y = ctl->y, w = ctl->w, h = ctl->h;
  // local copy: fb stores can't alias it, so no reload + __mulsi3 per pixel
  // (rv32e has no M extension)
  int sw = screen_width;
  uint32_t *dst = (uint32_t *)(uintptr_t)FB_ADDR + y * sw + x;  // one multiply per call
  uint32_t *src = (uint32_t *)(ctl->pixels);

  for (int j = 0; j < h; j++, dst += sw, src += w) {
    for (int i = 0; i < w; i++) {
      dst[i] = src[i];
    }
  }
  if (ctl->sync) {
    outl(SYNC_ADDR, 1);
  }
}

void __am_gpu_status(AM_GPU_STATUS_T *status) {
  status->ready = true;
}
