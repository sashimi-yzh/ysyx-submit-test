#include <am.h>
#include <riscv/riscv.h>

#define MMIO_BASE 0xa0000000
#define DEVICE_BASE 0xa0000000
#define VGACTL_ADDR     (DEVICE_BASE + 0x0000100)
#define SYNC_ADDR (VGACTL_ADDR + 4)
#define FB_ADDR         (MMIO_BASE   + 0x1000000)

static uint32_t width = 0;
static uint32_t height = 0;

static void am_get_gpu_config() {
    uint32_t config = inl(VGACTL_ADDR);
    width = config >> 16;
    height = config & 0xFFFF;
}

void __am_gpu_init() {
  am_get_gpu_config();

  int i;
  uint32_t *fb = (uint32_t *)(uintptr_t)FB_ADDR;
  for (i = 0; i < width * height; i ++) fb[i] = 0;
  outl(SYNC_ADDR, 1);
}

void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
  if (width == 0 || height == 0) {
    am_get_gpu_config();
  }
  
  *cfg = (AM_GPU_CONFIG_T) {
    .present = true, .has_accel = false,
    .width = width, .height = height,
    .vmemsz = width * height * sizeof(uint32_t)
  };
}

void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) {
  if (width == 0 || height == 0) {
        am_get_gpu_config();
    }
    if (ctl->x >= width || ctl->y >= height) return;

    uint32_t *fb = (uint32_t *)(uintptr_t)FB_ADDR;
    uint32_t *pixels = (uint32_t *)ctl->pixels;

    uint32_t draw_w = ctl->w;
    uint32_t draw_h = ctl->h;

    if (ctl->x + draw_w > width) {
      draw_w = width - ctl->x;
    }
    if (ctl->y + draw_h > height) {
      draw_h = height - ctl->y;
    }

  //if (draw_w == 0 || draw_h == 0) return;

  for (uint32_t y = 0; y < draw_h; y++) {
    // 计算当前行在源和目标中的起始位置
    uint32_t src_start = y * ctl->w;
    uint32_t dst_start = (ctl->y + y) * width + ctl->x;
        
    // 复制一行像素
    for (uint32_t x = 0; x < draw_w; x++) {
      fb[dst_start + x] = pixels[src_start + x];
    }
  }
  if (ctl->sync) {
    outl(SYNC_ADDR, 1);
  }
}

void __am_gpu_status(AM_GPU_STATUS_T *status) {
  status->ready = true;
}
