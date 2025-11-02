#include <am.h>
#include "soc.h"
#include <riscv/riscv.h>

const int disp_w = 640, disp_h = 480;

#define WIDTH      2048
#define HEIGHT     1024

void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) {
  uint32_t x = ctl->x, y = ctl->y;
  uint32_t w = ctl->w, h = ctl->h;
  uint32_t *pixels = (uint32_t *)ctl->pixels;
  
  for (int i = 0; i < w; i++) {
    for (int j = 0; j < h; j++) {
        uintptr_t addr = FB_ADDR + (((i+x) * 2048 + (j+y)) * 4);
        outl(addr, pixels[j*w + i]);
    }
  }
//   for (int i = 1; i <= h; i ++){
//     for (int j = 1; j <= w; j ++){
//       fb[disp_w*(i+y-1)+j+x-1] = pixels[w*(i-1)+j-1];
//     }
//   }
//   if (ctl->sync) {
//     outl(SYNC_ADDR, 1);
//   }
//   else{
//     outl(SYNC_ADDR, 0);
//   }
}

void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
  *cfg = (AM_GPU_CONFIG_T) {
    .present = true, .has_accel = false,
    .width = disp_w, .height = disp_h,
    .vmemsz = 0
  };
}
void __am_gpu_status(AM_GPU_STATUS_T *status) {
  status->ready = true;
}