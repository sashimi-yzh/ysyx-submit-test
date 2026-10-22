#include <am.h>
#include <klib-macros.h>
#include <riscv/riscv.h>

void __am_timer_init();
void __am_gpu_init();
void __am_audio_init();

void __am_timer_rtc(AM_TIMER_RTC_T *);
void __am_timer_uptime(AM_TIMER_UPTIME_T *);
void __am_input_keybrd(AM_INPUT_KEYBRD_T *);
void __am_gpu_config(AM_GPU_CONFIG_T *);
void __am_gpu_status(AM_GPU_STATUS_T *);
void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *);
void __am_audio_config(AM_AUDIO_CONFIG_T *);
void __am_audio_ctrl(AM_AUDIO_CTRL_T *);
void __am_audio_status(AM_AUDIO_STATUS_T *);
void __am_audio_play(AM_AUDIO_PLAY_T *);
// void __am_disk_config(AM_DISK_CONFIG_T *cfg);
// void __am_disk_status(AM_DISK_STATUS_T *stat);
// void __am_disk_blkio(AM_DISK_BLKIO_T *io);

static void __am_timer_config(AM_TIMER_CONFIG_T *cfg) { cfg->present = true; cfg->has_rtc = true; }
static void __am_input_config(AM_INPUT_CONFIG_T *cfg) { cfg->present = true;  }
static void __am_uart_config(AM_INPUT_CONFIG_T *cfg) { cfg->present = false;  }
// static void __am_net_config (AM_NET_CONFIG_T *cfg) 

typedef void (*handler_t)(void *buf);
static void *lut[128] = {
  [AM_TIMER_CONFIG] = __am_timer_config,
  [AM_TIMER_RTC   ] = __am_timer_rtc,
  [AM_TIMER_UPTIME] = __am_timer_uptime,
  [AM_INPUT_CONFIG] = __am_input_config,
  [AM_INPUT_KEYBRD] = __am_input_keybrd,
  [AM_GPU_CONFIG  ] = __am_gpu_config,
  [AM_GPU_FBDRAW  ] = __am_gpu_fbdraw,
  [AM_GPU_STATUS  ] = __am_gpu_status,
  [AM_UART_CONFIG]  = __am_uart_config,
  [AM_AUDIO_CONFIG] = __am_audio_config,
  [AM_AUDIO_CTRL  ] = __am_audio_ctrl,
  [AM_AUDIO_STATUS] = __am_audio_status,
  [AM_AUDIO_PLAY  ] = __am_audio_play,
  // [AM_DISK_CONFIG ] = __am_disk_config,
  // [AM_DISK_STATUS ] = __am_disk_status,
  // [AM_DISK_BLKIO  ] = __am_disk_blkio,
  // [AM_NET_CONFIG  ] = __am_net_config,
};

static void fail(void *buf) { panic("access nonexist register"); }

bool ioe_init() {
  for (int i = 0; i < LENGTH(lut); i++)
    if (!lut[i]) lut[i] = fail;
  // __am_gpu_init();
  __am_timer_init();
  // __am_audio_init();
  return true;
}

void ioe_read (int reg, void *buf) { ((handler_t)lut[reg])(buf); }
void ioe_write(int reg, void *buf) { ((handler_t)lut[reg])(buf); }

// //================gpu=================

// #define MMIO_BASE 0xa0000000
// #define DEVICE_BASE 0xa0000000
// #define VGACTL_ADDR     (DEVICE_BASE + 0x0000100)
// #define SYNC_ADDR (VGACTL_ADDR + 4)
// #define FB_ADDR         (MMIO_BASE   + 0x1000000)

// static uint32_t width = 0;
// static uint32_t height = 0;

// static void am_get_gpu_config() {
//     uint32_t config = inl(VGACTL_ADDR);
//     width = config >> 16;
//     height = config & 0xFFFF;
// }

// void __am_gpu_init() {
//   am_get_gpu_config();

//   int i;
//   uint32_t *fb = (uint32_t *)(uintptr_t)FB_ADDR;
//   for (i = 0; i < width * height; i ++) fb[i] = 0;
//   outl(SYNC_ADDR, 1);
// }

// void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
//   if (width == 0 || height == 0) {
//     am_get_gpu_config();
//   }
  
//   *cfg = (AM_GPU_CONFIG_T) {
//     .present = true, .has_accel = false,
//     .width = width, .height = height,
//     .vmemsz = width * height * sizeof(uint32_t)
//   };
// }

// void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) {
//   if (width == 0 || height == 0) {
//         am_get_gpu_config();
//     }
//     if (ctl->x >= width || ctl->y >= height) return;

//     uint32_t *fb = (uint32_t *)(uintptr_t)FB_ADDR;
//     uint32_t *pixels = (uint32_t *)ctl->pixels;

//     uint32_t draw_w = ctl->w;
//     uint32_t draw_h = ctl->h;

//     if (ctl->x + draw_w > width) {
//       draw_w = width - ctl->x;
//     }
//     if (ctl->y + draw_h > height) {
//       draw_h = height - ctl->y;
//     }

//   //if (draw_w == 0 || draw_h == 0) return;

//   for (uint32_t y = 0; y < draw_h; y++) {
//     // 计算当前行在源和目标中的起始位置
//     uint32_t src_start = y * ctl->w;
//     uint32_t dst_start = (ctl->y + y) * width + ctl->x;
        
//     // 复制一行像素
//     for (uint32_t x = 0; x < draw_w; x++) {
//       fb[dst_start + x] = pixels[src_start + x];
//     }
//   }
//   if (ctl->sync) {
//     outl(SYNC_ADDR, 1);
//   }
// }

// void __am_gpu_status(AM_GPU_STATUS_T *status) {
//   status->ready = true;
// }

// //================audio==================
// #define AUDIO_ADDR      (DEVICE_BASE + 0x0000200)
// #define AUDIO_SBUF_ADDR (MMIO_BASE   + 0x1200000)
// #define AUDIO_FREQ_ADDR      (AUDIO_ADDR + 0x00)
// #define AUDIO_CHANNELS_ADDR  (AUDIO_ADDR + 0x04)
// #define AUDIO_SAMPLES_ADDR   (AUDIO_ADDR + 0x08)
// #define AUDIO_SBUF_SIZE_ADDR (AUDIO_ADDR + 0x0c)
// #define AUDIO_INIT_ADDR      (AUDIO_ADDR + 0x10)
// #define AUDIO_COUNT_ADDR     (AUDIO_ADDR + 0x14)
// #define AUDIO_WP_ADDR     (AUDIO_ADDR + 0x18)
// #define AUDIO_RP_ADDR     (AUDIO_ADDR + 0x1c)
// #define AUDIO_BUF_SIZE 0x10000


// static uint32_t app_wp = 0;



// void __am_audio_init() {
//   outl(AUDIO_INIT_ADDR, 1);

//   app_wp = 0;
//   outl(AUDIO_WP_ADDR, app_wp);

// }

// void __am_audio_config(AM_AUDIO_CONFIG_T *cfg) {
//   cfg->present = true;
//   cfg->bufsize = inl(AUDIO_SBUF_SIZE_ADDR);
// }

// void __am_audio_ctrl(AM_AUDIO_CTRL_T *ctrl) {
//   if (ctrl->freq) {
//     outl(AUDIO_FREQ_ADDR, ctrl->freq);
//   }
//   if (ctrl->channels) {
//     outl(AUDIO_CHANNELS_ADDR, ctrl->channels);
//   }
//   if (ctrl->samples) {
//     outl(AUDIO_SAMPLES_ADDR, ctrl->samples);
//   }
  
// }

// void __am_audio_status(AM_AUDIO_STATUS_T *stat) {
//   stat->count = inl(AUDIO_COUNT_ADDR);
//   //printf("%d\n", audio_count);
//   //outl(AUDIO_COUNT_ADDR, audio_count);
// }

// void __am_audio_play(AM_AUDIO_PLAY_T *ctl) {
//   Area *area = &ctl->buf;
//     uint8_t *src = (uint8_t *)area->start;
//     uint32_t len = (uint8_t *)area->end - src;
    
//     if (len == 0) {
//     // 更新写指针
//     outl(AUDIO_WP_ADDR, app_wp);
//     return;
//   }
    
//     // 获取当前缓冲区使用情况
//     uint32_t total_size = inl(AUDIO_SBUF_SIZE_ADDR);
//     uint32_t used = inl(AUDIO_COUNT_ADDR);
//     uint32_t free_space = total_size - used;

//     if (len > free_space) {
//     len = free_space;
//   }
//     if (len == 0) return;
    
//     uint8_t *hw_buf = (uint8_t *)(uintptr_t)AUDIO_SBUF_ADDR;
//     if (app_wp + len <= total_size) {
//     // 情况1: 不需要回绕
//     for (uint32_t i = 0; i < len; i++) {
//       hw_buf[app_wp + i] = src[i];
//     }
//     app_wp += len;
//   } else {
//     // 情况2: 需要回绕
//     uint32_t part1 = total_size - app_wp;
//     for (uint32_t i = 0; i < part1; i++) {
//       hw_buf[app_wp + i] = src[i];
//     }
    
//     uint32_t part2 = len - part1;

//     for (uint32_t i = 0; i < part2; i++) {
//       hw_buf[i] = src[part1 + i];
//     }
//     app_wp = part2;
//   }
    
//     // 更新已使用空间计数
//   outl(AUDIO_WP_ADDR, app_wp);
  
//   // 设置返回区域
//   ctl->buf.start = (void *)(hw_buf + app_wp);
//   ctl->buf.end = (void *)(hw_buf + app_wp + len);
// }
