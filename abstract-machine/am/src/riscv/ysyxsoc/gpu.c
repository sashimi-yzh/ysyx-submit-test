#include <am.h>
#include "../riscv.h"
#include <stdio.h>

#define FB_ADDR   0x21000000
#define CTL_ADDR  0x211FFFF0
#define SYNC_ADDR 0x211FFFF4
#define SIZE 0x200000

void __am_gpu_init() {
	//uint32_t *fb = (uint32_t *)(uintptr_t)FB_ADDR;
	//for(int i = 0; i < 640 * 480; i ++) {
		//fb[i] = 0;
	//}
	//outl(SYNC_ADDR, 1);
}

void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
	*cfg = (AM_GPU_CONFIG_T) {
    .present = true, .has_accel = false,
    .width = 640, //nvboard
		.height = 480, //nvboard
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
			fb[640 * i + j] = pixels[ctl->w * (i-(ctl->y)) + (j-(ctl->x))];	//w*i+j 
		}
	}
	if(ctl->sync) {
		outl(SYNC_ADDR, 1);
	}
}

void __am_gpu_status(AM_GPU_STATUS_T *status) {
  status->ready = true;
}
