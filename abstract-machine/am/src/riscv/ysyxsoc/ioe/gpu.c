#include <am.h>
#include <riscv/ysyxsoc/ysyxsoc.h>
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
  int width = 640;
  uint32_t *fb = (uint32_t *)(uintptr_t)VGA_BUFFER;
  uint32_t *pb = (uint32_t *)ctl->pixels;
  int x = ctl->x;
  int y = ctl->y;
  int h = ctl->h;
  int w = ctl->w;
  int point = y * width + x;
  int i,j;
  for (i = 0; i < h; i++) 
    for (j = 0; j < w; j++) {
      fb[point + i * width + j] = pb[i * w + j];
    }
}

void __am_gpu_status(AM_GPU_STATUS_T *status) {
  status->ready = true;
}
