#include <am.h>
#include <klib-macros.h>
#include <ysyxsoc.h>
#include <riscv/riscv.h>

#define WIDTH      640
#define HEIGHT     480
#define VRAM_PITCH 512           // 硬件一行（实际是一列）跨度
#define FB_ADDR    0x21000000
#define FB         ((uint32_t *)(uintptr_t)FB_ADDR)

void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *fb) {
    int x = fb->x, y = fb->y, w = fb->w, h = fb->h;
    uint32_t *pixels = (uint32_t *)fb->pixels;

    for (int i = 0; i < h; i++) {
        int py = y + i;
        if (py < 0 || py >= HEIGHT)
            continue;                     // 仅绘制可见行
        for (int j = 0; j < w; j++) {
            int px = x + j;
            if (px < 0 || px >= WIDTH)
                continue;                 // 仅绘制可见列
            int offset = px * VRAM_PITCH + py;   // 与硬件读地址映射一致
            FB[offset] = pixels[i * w + j];
        }
    }
}
void __am_gpu_config(AM_GPU_CONFIG_T *cfg)
{
    *cfg = (AM_GPU_CONFIG_T) {
        .present = true, .has_accel = false,
        .width = WIDTH, .height = HEIGHT,
        .vmemsz = 0
    };
}
void __am_gpu_status(AM_GPU_STATUS_T *status)
{
    status->ready = true;
}
