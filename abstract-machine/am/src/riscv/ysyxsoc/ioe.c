#include <am.h>
#include <klib.h>
#include <klib-macros.h>

void __am_timer_init();

void __am_timer_rtc(AM_TIMER_RTC_T *);
void __am_timer_uptime(AM_TIMER_UPTIME_T *);
void __am_input_keybrd(AM_INPUT_KEYBRD_T *);

static void __am_timer_config(AM_TIMER_CONFIG_T *cfg) { cfg->present = true; cfg->has_rtc = true; }
static void __am_input_config(AM_INPUT_CONFIG_T *cfg) { cfg->present = true;  }
static void __am_uart_config(AM_UART_CONFIG_T *cfg) { cfg->present = true;  }
static void __am_uart_rx(AM_UART_RX_T *cfg) {
  uint8_t status = *(volatile uint8_t*)0x10000005;
  
  if ((status & 0x01) == 0) {
    cfg->data = 0xff;
  }
  else {
    cfg->data = *(volatile uint8_t*)0x10000000;
  }
}

void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
  uint32_t h = 480;
  uint32_t w = 640;
  *cfg = (AM_GPU_CONFIG_T) {
    .present = true, .has_accel = false,
    .width = w, .height = h,
    .vmemsz = w * h * sizeof(uint32_t)
  };
}

void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) {
  uint32_t *fb = (uint32_t *)0x21000000;
  int size_w = 640;

  for (int y = 0; y < ctl->h; y ++) {
    for (int x = 0; x < ctl->w; x ++) {
      int fb_idx = (ctl->y + y) * size_w + ctl->x + x;
      int buf_idx = y * ctl->w + x;
      fb[fb_idx] = ((uint32_t *)ctl->pixels)[buf_idx];
    }
  }
}

typedef void (*handler_t)(void *buf);
static void *lut[128] = {
  [AM_TIMER_CONFIG] = __am_timer_config,
  [AM_TIMER_RTC   ] = __am_timer_rtc,
  [AM_TIMER_UPTIME] = __am_timer_uptime,
  [AM_INPUT_CONFIG] = __am_input_config,
  [AM_INPUT_KEYBRD] = __am_input_keybrd,
  [AM_UART_CONFIG]  = __am_uart_config,
  [AM_UART_RX]      = __am_uart_rx,
  [AM_GPU_CONFIG  ] = __am_gpu_config,
  [AM_GPU_FBDRAW  ] = __am_gpu_fbdraw,
};

static void fail(void *buf) { panic("access nonexist register"); }

bool ioe_init() {
  for (int i = 0; i < LENGTH(lut); i++)
    if (!lut[i]) lut[i] = fail;
  __am_timer_init();
  return true;
}

void ioe_read (int reg, void *buf) { ((handler_t)lut[reg])(buf); }
void ioe_write(int reg, void *buf) { ((handler_t)lut[reg])(buf); }
