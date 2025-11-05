#include <am.h>
#include <riscv/riscv.h>
#include <stdio.h>

#define VGACTL_ADDR  0xa0000100
#define MMIO_BASE 0xa0000000
#define FB_ADDR         (MMIO_BASE   + 0x1000000)

#define SYNC_ADDR (VGACTL_ADDR + 4)

void __am_gpu_init() {
  // uint32_t scr_size = inl(VGACTL_ADDR);
  // uint32_t h = scr_size & 0xffff;
  // uint32_t w = scr_size >> 16;
  // uint32_t *fb = (uint32_t *)(uintptr_t)FB_ADDR;
  // for (size_t i = 0; i < w * h; i ++) fb[i] = i;
  outl(SYNC_ADDR, 1);
}

void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
 //see func: init_vga in vga.c in nemu
  uint32_t scr_size = inl(VGACTL_ADDR);
  uint32_t h = scr_size & 0xffff;
  uint32_t w = scr_size >> 16;
  //printf("%s: h: %d, w: %d \n",__func__, h , w);
  *cfg = (AM_GPU_CONFIG_T) {
    .present = true, .has_accel = false,
    .width = w, .height = h,
    .vmemsz = 0
  };
  // w = io_read(AM_GPU_CONFIG).width ;
  // h = io_read(AM_GPU_CONFIG).height ;
  // printf("%s: h: %d, w: %d \n",__func__, h , w);
}

void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) {
  if(ctl->w != 0 && ctl->h != 0){
    uint32_t *pixels = ctl->pixels;
    uint32_t *fb_addr = (uint32_t *)(uintptr_t)FB_ADDR;
    uint32_t screen_w = inl(VGACTL_ADDR) >> 16;
    for(int i = ctl->y; i < ctl->y + ctl->h; i++){
      for(int j = ctl->x; j < ctl->x + ctl->w; j++){
        fb_addr[screen_w*i+j] = pixels[ctl->w*(i-ctl->y)+(j-ctl->x)];
      }
    }
  }
  if (ctl->sync) {
    outl(SYNC_ADDR, 1);
  }
}

void __am_gpu_status(AM_GPU_STATUS_T *status) {
  status->ready = true;
}
