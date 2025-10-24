#include <am.h>
#include <klib-macros.h>
#include <klib.h>
#include "ysyxsoc.h"
#include "../riscv.h"

#define SYNC_ADDR (VGACTL_ADDR + 4)

void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
    cfg->width = VGA_WIDTH;//宽度
    cfg->height = VGA_HIGHT;//高度
    cfg->present = true;//GPU存在
    cfg->has_accel = false;//没有图形加速
    cfg->vmemsz = 0;//没有虚拟显存
}

void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) {
    int i, j;
    uint32_t *pixels = ctl->pixels;
    uint32_t *fb = (uint32_t *)(uintptr_t)(VGA_BASE + (ctl->x + VGA_WIDTH * ctl->y) * sizeof(uint32_t));
    for(i = 0; i < ctl->h; i++){//绘制每一行
        for(j = 0; j < ctl->w; j++){//绘制每一行中的每一个像素
            fb[j] = *pixels++;//将像素读取写入到VGA缓冲区中
        }
        fb += VGA_WIDTH;//换到下一行
    }
    // ctl->sync = true;//更新屏幕(讲义说不用实现这个,因为NVBOARD自动刷新)
}

void __am_gpu_status(AM_GPU_STATUS_T *status) {
  status->ready = true;
}
