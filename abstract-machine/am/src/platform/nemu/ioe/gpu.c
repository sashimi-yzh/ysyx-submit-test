#include <am.h>
#include <nemu.h>

#define SYNC_ADDR (VGACTL_ADDR + 4)

void __am_gpu_init() {
  // int i;
  // int w = io_read(AM_GPU_CONFIG).width;  
  // int h = io_read(AM_GPU_CONFIG).height;  
  // uint32_t *fb = (uint32_t *)(uintptr_t)FB_ADDR;
  // printf("gpu init %d %d\n",w,h);
  // for (i = 0; i < w * h; i ++) fb[i] = i;
  // printf("gpu init finished\n");
  // outl(SYNC_ADDR, 1);
}

void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {

  *cfg = (AM_GPU_CONFIG_T) {
    .present = true, .has_accel = false,
    .width = inw(VGACTL_ADDR+2), .height = inw(VGACTL_ADDR),
    .vmemsz = inw(VGACTL_ADDR+2) * inw(VGACTL_ADDR) * 4
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
    outl(FB_ADDR + ((i + x) + (j + y) * cfg.width) * sizeof(uint32_t), buf[i + j * w]);
  }
  
  if (ctl->sync) {
    outl(SYNC_ADDR, 1);
  }
}

void __am_gpu_status(AM_GPU_STATUS_T *status) {
  status->ready = true;
}
