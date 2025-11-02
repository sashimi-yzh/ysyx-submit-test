#include <am.h>
#include <riscv/riscv.h>
#include <ysyxsoc.h>
#include <klib.h>
#include <klib-macros.h>

//#define SYNC_ADDR (VGACTL_BASE + 4)

#define SCREEN_W 640
#define SCREEN_H 480


void __am_gpu_init() {
}

void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
  *cfg = (AM_GPU_CONFIG_T) {
    .present = true, .has_accel = false,
    .width = SCREEN_W, .height = SCREEN_H,
    .vmemsz = 0
  };
}


//ctl 有如下成员变量：int x, y, void* pixels, int w,h, bool sync
//其中x，y是画方块的起始位置（左上角坐标），pixel为方块的颜色，w和h为方块的尺寸，sync
//表示这个方块是否要被立刻显示
void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) {
    uint32_t* color_buf = (uint32_t*)ctl -> pixels;
	
	int h = ctl->h; 
	int w = ctl->w;
	int y_start = ctl->y;
	int x_start = ctl->x;

	for(int y = 0; y < h; y++){
        for(int x = 0; x < w; x++){
            //outl(FB_BASE + 4*((ctl->y + y)*SCREEN_W + (ctl->x + x)), color_buf[y*ctl->w+x]);
            outl(FB_BASE + 4*((y_start + y)*SCREEN_W + (x_start + x)), color_buf[y*w+x]);
        }
    }
	//uint64_t t2 = io_read(AM_TIMER_UPTIME).us;
	//printf("time on vga kernel real is: %d ms\n", (t2 - t1)/1000);
	//用于测试
    //for(int i = 0; i < 400*50; ++i)
    //  outl(FB_BASE + 4*i, 0x00ffffff);

    //if (ctl->sync)
    //    outl(SYNC_ADDR, 1);
    //else
    //  outl(SYNC_ADDR, 0);

}


void __am_gpu_status(AM_GPU_STATUS_T *status) {
	status->ready = true;
}


