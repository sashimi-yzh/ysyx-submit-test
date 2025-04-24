#include <am.h>
#include <nemu.h>
#ifndef __ICS_EXPORT
#include <klib.h>
#endif

#define SYNC_ADDR (VGACTL_ADDR + 4)

#ifdef __ICS_EXPORT
void __am_gpu_init() {
}
#else
static int W = 0, H = 0;

void __am_gpu_init() {
  uint32_t data = inl(VGACTL_ADDR);
  W = data >> 16;
  H = data & 0xffff;
}
#endif

void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
  *cfg = (AM_GPU_CONFIG_T) {
    .present = true, .has_accel = false,
#ifdef __ICS_EXPORT
    .width = 0, .height = 0, .vmem = NULL,
#else
    .width = W, .height = H, .vmem = (void *)FB_ADDR,
#endif
    .vmemsz = 0
  };
}

void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) {
#ifndef __ICS_EXPORT
  uint32_t *pixels = ctl->pixels;
  if (pixels) {
    int x = ctl->x, y = ctl->y, w = ctl->w, h = ctl->h;
    panic_on(x + w > W || y + h > H, "bad draw command");
    int len = sizeof(uint32_t) * w;
    uint32_t* const fb = (uint32_t *)FB_ADDR;
    uint32_t *p_fb = &fb[y * W + x];
    int j;

    for (j = 0; j < h; j ++) {
      memcpy(p_fb, pixels, len);
      p_fb += W;
      pixels += w;
    }
  }
#endif
  if (ctl->sync) {
    outl(SYNC_ADDR, 1);
  }
}

void __am_gpu_status(AM_GPU_STATUS_T *status) {
  status->ready = true;
}
