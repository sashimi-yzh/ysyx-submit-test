#include <am.h>
#include <nemu.h>
#include <klib.h>
#define SYNC_ADDR (VGACTL_ADDR + 4)

static int gpu_w,gpu_h;

void __am_gpu_init() {
  gpu_w = (unsigned int)inl(VGACTL_ADDR)>>16;
  gpu_h = (unsigned int)inl(VGACTL_ADDR)&0xffff;
}

void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
  *cfg = (AM_GPU_CONFIG_T) {
    .present = true, .has_accel = false,
    .width = (unsigned int)inl(VGACTL_ADDR)>>16, .height = (unsigned int)inl(VGACTL_ADDR)&0xffff,
    .vmemsz = gpu_w*gpu_h*4
  };
}

void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) {
  if (ctl->sync) outl(SYNC_ADDR, 1);
  if(ctl->pixels == NULL) return;
  int pindex=0;
  int sindex = ctl->y * gpu_w + ctl->x;
  for(int i=0;i<ctl->h;i++){
    for(int j=0;j<ctl->w;j++){
      outl(FB_ADDR + (sindex << 2),*((unsigned int*)ctl->pixels + pindex));
      sindex ++;
      pindex ++;
    }
    sindex += (gpu_w - ctl->w);
  }
}

void __am_gpu_status(AM_GPU_STATUS_T *status) {
  status->ready = true;
}
