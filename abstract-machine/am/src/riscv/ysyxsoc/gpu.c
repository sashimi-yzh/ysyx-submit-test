#include <am.h>
#include <klib-macros.h>
#include <klib.h>
#include "ysyxsoc.h"

#define VGA_WIDTH 640
#define VGA_HIGH  480

// TAG:只需要下面的三个函数，这三个是为了渲染使用，将输入的信号写出到VGA的地址去
void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
  *cfg = (AM_GPU_CONFIG_T) {
    .present = true, 
    .has_accel = false,
    .width = VGA_WIDTH, 
    .height = VGA_HIGH,
    .vmemsz = VGA_WIDTH * VGA_HIGH * sizeof(uint32_t)
  };
}

//写入显存 偏移量加到起点，然后写w*h*sizeof(uint32)
void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) {
  uint32_t x = ctl->x, y = ctl->y;
  uint32_t w = ctl->w, h = ctl->h;
  if (w == 0 || h == 0) return;

  uint32_t *fb      = (uint32_t *)VGA_BASE;
  uint32_t *pixels  = (uint32_t *)ctl->pixels;
  // memcpy(fb + ((y * VGA_WIDTH)  + x ),pixels ,w*4*h);
  for (uint32_t i = 0; i < h; ++i){
     for (uint32_t j = 0; j < w; ++j) {
          fb[(y + i) * VGA_WIDTH + (x + j)] = pixels[i * w + j];
      }  
  }
}


void __am_gpu_status(AM_GPU_STATUS_T *status) {
  status->ready = true;
}
