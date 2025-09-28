#include <am.h>
#include <ysyxsoc.h>
#include <klib.h>

#define W 640
#define H 480
#define VRAM_ADDR VGA_ADDR
#define SYNC_ADDR VGA_ADDR + 0x4b000

void __am_gpu_init() {
}

void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
  *cfg = (AM_GPU_CONFIG_T) {
    .present = true, .has_accel = false,
    .width = W, .height = H,
    .vmemsz = W * H * sizeof(uint32_t)
  };
}

void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) {
  uint32_t *fb = (uint32_t *)(uintptr_t)VRAM_ADDR;
  uint32_t *p = ctl->pixels;
  for (int i = 0; i < ctl->h; ++i) {
    for (int j = 0; j < ctl->w; ++j) {
      fb[(ctl->y + i) * W + (ctl->x + j)] = *p++;
    }
  }
}

void __am_gpu_status(AM_GPU_STATUS_T *status) {
  status->ready = true;
}
