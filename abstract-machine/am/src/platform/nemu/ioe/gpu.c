#include <am.h>
#include <nemu.h>
//#include "./../../../../../klib/include/klib.h"

#define SYNC_ADDR (VGACTL_ADDR + 4)

void __am_gpu_init() {
/***
	int i;
	int w = io_read(AM_GPU_CONFIG).width;  //get the correct width
  int h = io_read(AM_GPU_CONFIG).height;  //get the correct height
  uint32_t *fb = (uint32_t *)(uintptr_t)FB_ADDR;
  for (i = 0; i < w * h; i ++) fb[i] = i;
  outl(SYNC_ADDR, 1);
***/
}

void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
	*cfg = (AM_GPU_CONFIG_T) {
    .present = true, .has_accel = false,
    .width = inw(VGACTL_ADDR + 2),	//小端系统 
		.height = inw(VGACTL_ADDR),
    .vmemsz = 0
  };
}

void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) {
	if(!ctl->sync && (ctl->w == 0 || ctl->h == 0))
		return;
	uint32_t *fb = (uint32_t *)(uintptr_t)FB_ADDR;
	uint32_t *pixels = ctl->pixels;
	for(int i = ctl->y; i < (ctl->y + ctl->h); i ++) {
		for(int j = ctl->x; j < (ctl->x + ctl->w); j ++) {
			fb[inw(VGACTL_ADDR+2) * i + j] = pixels[ctl->w * (i-(ctl->y)) + (j-(ctl->x))];	//w*i+j 
		}
	}
	if(ctl->sync) {
		outl(SYNC_ADDR, 1);
	}
}

void __am_gpu_status(AM_GPU_STATUS_T *status) {
  status->ready = true;
}
