#include <am.h>
#include "ysyxsoc.h"

#define W 640
#define H 480

void __am_gpu_init() {
	int w = io_read(AM_GPU_CONFIG).width;
	int h = io_read(AM_GPU_CONFIG).height;

	uint32_t *fb = (uint32_t *)(uint32_t)FB_ADDR;

	for (int i = 0; i < w * h; i ++) fb[i] = 0;
}

void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
	*cfg = (AM_GPU_CONFIG_T) {
		.present = true, .has_accel = false,
		.width = W, .height = H,
		.vmemsz = 0
	};
}

void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) {
	int x = ctl->x, y = ctl->y, w = ctl->w, h = ctl->h;

	if(!ctl->sync && (w == 0 || h == 0)) return;

	uint32_t *pixels = ctl->pixels;
	uint32_t *fb = (uint32_t *)(uint32_t)FB_ADDR;
	uint32_t screen_w = io_read(AM_GPU_CONFIG).width;

	for (int i = y; i < y + h; i++) {
		for (int j = x; j < w + x; j++) {
			fb[screen_w * i + j] = pixels[w * (i - y) + (j - x)];
		}
	}
}

void __am_gpu_status(AM_GPU_STATUS_T *status) {
	status->ready = true;
}
