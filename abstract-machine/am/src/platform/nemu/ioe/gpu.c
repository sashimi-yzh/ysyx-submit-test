#include <am.h>
#include <nemu.h>

#define SYNC_ADDR (VGACTL_ADDR + 4)
static int width = 0;
static int height = 0;
static uint32_t *fb = NULL;
void __am_gpu_init()
{
	int i;
	uint32_t port_base = inl(VGACTL_ADDR);
	width = (port_base >> 16) & 0xffff;
	height = port_base & 0xffff;
	fb = (uint32_t *)(uintptr_t)FB_ADDR;
	for (i = 0; i < width * height; i++)
		fb[i] = i;
	outl(SYNC_ADDR, 1);
}

void __am_gpu_config(AM_GPU_CONFIG_T *cfg)
{
	// AM_GPU_FBDRAW, AM帧缓冲控制器, 可写入绘图信息, 向屏幕(x, y)坐标处绘制w*h的矩形图像. 图像像素按行优先方式存储在pixels中, 每个像素用32位整数以00RRGGBB的方式描述颜色. 若sync为true, 则马上将帧缓冲中的内容同步到屏幕上.
	*cfg = (AM_GPU_CONFIG_T){
		.present = true, .has_accel = false, .width = 0, .height = 0, .vmemsz = 0};
	uint32_t port_base = inl(VGACTL_ADDR);
	cfg->width = (port_base >> 16) & 0xffff;
	cfg->height = port_base & 0xffff;
	cfg->vmemsz = cfg->width * cfg->height * sizeof(uint32_t);
}

void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl)
{
	for (int i = 0; i < ctl->h; i++)
	{
		for (int j = 0; j < ctl->w; j++)
		{
			fb[(ctl->y + i) * width + ctl->x + j] = ((uint32_t *)ctl->pixels)[i * ctl->w + j];
		}
	}
	if (ctl->sync)
	{
		outl(SYNC_ADDR, 1);
	}
}

void __am_gpu_status(AM_GPU_STATUS_T *status)
{

	status->ready = true;
}
