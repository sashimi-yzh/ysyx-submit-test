#include <am.h>
#include <klib-macros.h>
#include "include/npc.h"

void __am_timer_init();
void __am_gpu_init();

void __am_timer_rtc(AM_TIMER_RTC_T *);
void __am_timer_uptime(AM_TIMER_UPTIME_T *);
void __am_input_keybrd(AM_INPUT_KEYBRD_T *);
void __am_gpu_config(AM_GPU_CONFIG_T *);
void __am_gpu_status(AM_GPU_STATUS_T *);
void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *);

static void __am_timer_config(AM_TIMER_CONFIG_T *cfg) { cfg->present = true; cfg->has_rtc = true; }
static void __am_input_config(AM_INPUT_CONFIG_T *cfg) { cfg->present = true;  }
static void __am_uart_config(AM_UART_CONFIG_T *cfg) { cfg->present = true; }
static void __am_gpio_config(AM_GPIO_CONFIG_T *cfg) { cfg->present = true; }

static inline uint8_t uart_read8(uint32_t off) {
  return inb(UART_BASE + off);
}

static void __am_uart_tx(AM_UART_TX_T *tx) {
  putch((char)tx->data);
}

static void __am_uart_rx(AM_UART_RX_T *rx) {
  if (uart_read8(UART_REG_LSR) & UART_LSR_DR) {
    rx->data = (char)uart_read8(UART_REG_RBR);
  } else {
    rx->data = (char)0xffu;
  }
}

static void __am_gpio_led(AM_GPIO_LED_T *led) {
  outl(GPIO_BASE + 0x0u, (uint32_t)led->value);
}

static void __am_gpio_sw(AM_GPIO_SW_T *sw) {
  sw->value = (uint16_t)(inl(GPIO_BASE + 0x4u) & 0xffffu);
}

static void __am_gpio_seg(AM_GPIO_SEG_T *seg) {
  outl(GPIO_BASE + 0x8u, seg->value);
}

typedef void (*handler_t)(void *buf);
static void *lut[128] = {
  [AM_TIMER_CONFIG] = __am_timer_config,
  [AM_TIMER_RTC   ] = __am_timer_rtc,
  [AM_TIMER_UPTIME] = __am_timer_uptime,
  [AM_INPUT_CONFIG] = __am_input_config,
  [AM_INPUT_KEYBRD] = __am_input_keybrd,
  [AM_UART_CONFIG]  = __am_uart_config,
  [AM_UART_TX]      = __am_uart_tx,
  [AM_UART_RX]      = __am_uart_rx,
  [AM_GPU_CONFIG]   = __am_gpu_config,
  [AM_GPU_FBDRAW]   = __am_gpu_fbdraw,
  [AM_GPU_STATUS]   = __am_gpu_status,
  [AM_GPIO_CONFIG]  = __am_gpio_config,
  [AM_GPIO_LED]     = __am_gpio_led,
  [AM_GPIO_SW]      = __am_gpio_sw,
  [AM_GPIO_SEG]     = __am_gpio_seg,
};

static void fail(void *buf) { panic("access nonexist register"); }

bool ioe_init() {
  for (int i = 0; i < LENGTH(lut); i++)
    if (!lut[i]) lut[i] = fail;
  __am_timer_init();
  __am_gpu_init();
  return true;
}

void ioe_read (int reg, void *buf) { ((handler_t)lut[reg])(buf); }
void ioe_write(int reg, void *buf) { ((handler_t)lut[reg])(buf); }
