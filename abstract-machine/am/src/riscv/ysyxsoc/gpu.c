#include <am.h>

#define GPU_BASE_ADDR  0x21000000
#define FRAME_ADDR (uint32_t *)(GPU_BASE_ADDR + 0x00)

void __am_gpu_init() {
}

void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
  *cfg = (AM_GPU_CONFIG_T) {
    .present = true, .has_accel = false,
    .width = 640, .height = 480,
    .vmemsz = 0
  };
}


void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) {
  int x = ctl->x, y = ctl->y, w = ctl->w, h = ctl->h;
  if (!ctl->sync && (w == 0 || h == 0)) return;
  uint32_t *pixels = ctl->pixels;
  uint32_t *fb = FRAME_ADDR;
  uint32_t screen_w = 640;
  for (int i = y; i < y+h; i++) {
    for (int j = x; j < x+w; j++) {
      fb[screen_w*i+j] = pixels[w*(i-y)+(j-x)];
    }
  }
  // if (ctl->sync) {
  //   outl(SYNC_ADDR, 1);
  // }
}


void __am_gpu_status(AM_GPU_STATUS_T *status) {
  status->ready = true;
}
