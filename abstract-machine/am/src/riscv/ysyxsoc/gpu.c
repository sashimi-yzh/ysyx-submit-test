#include <am.h>
#include <klib.h>
#include <klib-macros.h>

#define FB_ADDR 0x21000000l
#define W 640
#define H 480

void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
  *cfg = (AM_GPU_CONFIG_T) {
    .present = true, .has_accel = false,
    .width = W, .height = H,
    .vmemsz = 0
  };
}

void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) {
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
}

void __am_gpu_status(AM_GPU_STATUS_T *status) {
  status->ready = true;
}
