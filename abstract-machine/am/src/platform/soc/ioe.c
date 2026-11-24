#include <am.h>
#include <klib-macros.h>
#include <klib.h>
#include <soc.h>

// manully enable/disable it when building
#undef CONFIG_DIFFTEST

typedef void (*handler_t)(void *buf);
static void __am_uart_config(AM_UART_CONFIG_T *cfg) { cfg->present = true; }
static void __am_input_config(AM_INPUT_CONFIG_T *cfg) { cfg->present = true; }
static void __am_timer_config(AM_TIMER_CONFIG_T *cfg) {
  cfg->present = true;
  cfg->has_rtc = true;
}

void __am_timer_init();
void __am_gpu_init();

void __am_uart_tx(AM_UART_TX_T *);
void __am_uart_rx(AM_UART_RX_T *);
void __am_input_keybrd(AM_INPUT_KEYBRD_T *);
void __am_gpu_config(AM_GPU_CONFIG_T *);
void __am_gpu_status(AM_GPU_STATUS_T *);
void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *);
void __am_timer_rtc(AM_TIMER_RTC_T *);
void __am_timer_uptime(AM_TIMER_UPTIME_T *);

static void *lut[128] = {
    [AM_TIMER_CONFIG] = __am_timer_config,
    [AM_TIMER_RTC]    = __am_timer_rtc,
    [AM_TIMER_UPTIME] = __am_timer_uptime,
    [AM_UART_CONFIG]  = __am_uart_config,
    [AM_UART_TX]      = __am_uart_tx,
    [AM_UART_RX]      = __am_uart_rx,
    [AM_INPUT_CONFIG] = __am_input_config,
    [AM_INPUT_KEYBRD] = __am_input_keybrd,
    [AM_GPU_CONFIG]   = __am_gpu_config,
    [AM_GPU_FBDRAW]   = __am_gpu_fbdraw,
    [AM_GPU_STATUS]   = __am_gpu_status,
};

static void fail(void *buf) { panic("soc access nonexist register"); }

bool ioe_init() {
  static int ioe_init_done = false;
  int        ret           = 0;

  if (ioe_init_done) {
    return true;
  }

  // diff test cannot support uart and spi devices

#ifndef CONFIG_DIFFTEST
  for (int i = 0; i < LENGTH(lut); i++)
    if (!lut[i])
      lut[i] = fail;

  ret = __am_uart_init();
  if (ret) {
    printf("uart init failed\n");
    return ret;
  }
  ret = __am_spi_init();
  if (ret) {
    printf("spi init failed\n");
    return ret;
  }
  __am_timer_init();
  __am_gpu_init();
#endif

  ioe_init_done = true;
  return ret;
}

void ioe_read(int reg, void *buf) { ((handler_t)lut[reg])(buf); }
void ioe_write(int reg, void *buf) { ((handler_t)lut[reg])(buf); }
