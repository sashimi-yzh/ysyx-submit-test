#include <am.h>

//#define SYNC_ADDR (VGACTL_ADDR + 4)

#define YSYXSOC_VGA 0x21000000

void __am_gpu_init() {
	// int i;
	// int w = screen & 0x0000ffff;  // TODO: get the correct width
	// int h = screen >> 16;  // TODO: get the correct height
	// uint32_t *fb = (uint32_t *)(uintptr_t)FB_ADDR;
	// for (i = 0; i < w * h; i ++) fb[i] = i;
	// outl(SYNC_ADDR, 1);
}

void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {  //显示控制器信息
	*cfg = (AM_GPU_CONFIG_T) {
		.present = true,            //显示器存在
		.has_accel = false,       //无图形加速功能，只有基本的帧缓冲区，需要CPU软件渲染
		.width = 640, .height = 480,
		.vmemsz = 0               //显存大小,0表示使用系统内存作为帧缓冲区
	};
	
}

void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) {   //帧缓冲控制器
	if (!ctl->sync &&( ctl->w == 0 || ctl->h == 0 ) ) return;   //不需要同步且宽高为0
	uint32_t *pixels = ctl->pixels;  //图像像素
	uint32_t screen_w = 640; // 固定宽度640
	uint32_t *fb_addr = (uint32_t *)(uintptr_t)YSYXSOC_VGA;   //帧缓冲区地址
	
	for (int i = ctl->y; i < ctl->y + ctl->h; i++) {  //图像相对位置 → 屏幕绝对位置
    	for (int j = ctl->x; j < ctl->x + ctl->w; j++) {
      		fb_addr[screen_w * i + j] = pixels[ctl->w * (i - ctl->y) + (j - ctl->x)];
    	}
	}

	// if (ctl->sync) {   //同步屏幕的功能
	// 	outl(SYNC_ADDR, 1);
	// }//由于NVBoard提供的VGA机制是自动刷新的, 因此无需实现AM中的画面同步功能
}

void __am_gpu_status(AM_GPU_STATUS_T *status) {
	status->ready = true;
}
