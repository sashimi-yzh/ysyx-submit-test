#include <am.h>
#include <nemu.h>

#define SYNC_ADDR (VGACTL_ADDR + 4)

void __am_gpu_init() {
  // int i;
  // int w = 400;  // TODO: get the correct width
  // int h = 300;  // TODO: get the correct height
  // uint32_t *fb = (uint32_t *)(uintptr_t)FB_ADDR;
  
  // for (i = 0; i < w * h; i ++) fb[i] = i;

  // outl(SYNC_ADDR, 1);
}

void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
  uint32_t all_size = inl(VGACTL_ADDR);
  uint32_t width_size = all_size >> 16;
  uint32_t height_size = all_size & (0xffff);
  
  *cfg = (AM_GPU_CONFIG_T) {
    .present = true, .has_accel = false,
    .width = width_size, .height = height_size,
    .vmemsz = 0
  };
}

void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) {
  uint32_t x = ctl->x,y = ctl->y,w = ctl->w,h = ctl->h;
  if(ctl->sync != 1 &&(w == 0 || h == 0)){
    return;
  }
  uint32_t screen_width_size = inl(VGACTL_ADDR) >> 16;
  uint32_t *fb = (uint32_t *)(uintptr_t)FB_ADDR;
  uint32_t *pixels = (uint32_t*)ctl->pixels;

  for(size_t i = y;i < y + h;i++){
    for(size_t j = x;j < x + w;j++){
      fb[i*screen_width_size+j] = pixels[(i-y)*w + (j-x)];
    }
  }
  if (ctl->sync) {
    outl(SYNC_ADDR, 1);
  }
}

void __am_gpu_status(AM_GPU_STATUS_T *status) {
  status->ready = true;
}
