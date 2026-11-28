#include <am.h>
#include <npc.h>
#include <riscv/riscv.h>

void __am_gpu_init() {

}

void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {

  *cfg = (AM_GPU_CONFIG_T) {
    .present = true, .has_accel = false,
    .width = 640, .height = 480,
    .vmemsz = 640*480*4
  };
}

void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) {
  AM_GPU_CONFIG_T cfg;
  __am_gpu_config(&cfg);
  size_t x =ctl->x,y = ctl->y;
  size_t w = ctl->w, h = ctl->h;
  uint32_t* buf = ctl->pixels;

  for(size_t j = 0 ; j < h ; j++)
  for(size_t i = 0 ; i < w ; i++){
    outl(VGA_BASE + ((i + x) + (j + y) * cfg.width) * sizeof(uint32_t), buf[i + j * w]);
  }
}

void __am_gpu_status(AM_GPU_STATUS_T *status) {
  status->ready = true;
}


