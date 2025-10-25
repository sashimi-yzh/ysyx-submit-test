#include <am.h>
#include "npc.h"
#include "riscv.h"
static uint32_t *fb = NULL;
#define WIDTH 640
#define VWIDTH 1024
#define HEIGHT 480
void __am_gpu_init()
{

	fb = (uint32_t *)(uintptr_t)VGA_ADDR;
}

void __am_gpu_config(AM_GPU_CONFIG_T *cfg)
{
	// AM_GPU_FBDRAW, AM帧缓冲控制器, 可写入绘图信息, 向屏幕(x, y)坐标处绘制w*h的矩形图像. 图像像素按行优先方式存储在pixels中, 每个像素用32位整数以00RRGGBB的方式描述颜色. 若sync为true, 则马上将帧缓冲中的内容同步到屏幕上.
	*cfg = (AM_GPU_CONFIG_T){
		.present = true, .has_accel = false, .width = 0, .height = 0, .vmemsz = 0};
	cfg->width = WIDTH;
	cfg->height = HEIGHT;
	cfg->vmemsz = cfg->width * cfg->height * sizeof(uint32_t);
}

void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl)
{
	for (int i = 0; i < ctl->h; i++)
	{
		for (int j = 0; j < ctl->w; j++)
		{
			fb[(ctl->y + i) * VWIDTH + ctl->x + j] = ((uint32_t *)ctl->pixels)[i * ctl->w + j];
		}
	}
}

void __am_gpu_status(AM_GPU_STATUS_T *status)
{

	status->ready = true;
}
