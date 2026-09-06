#include <am.h>
#include <klib-macros.h>
#include "amdev.h"
#include "soc-ioe.h"

static void __am_uart_config(AM_UART_CONFIG_T *cfg) {
    cfg->present = true;
}

static void __am_uart_tx(AM_UART_TX_T *tx) {
    putch(tx->data);
}

static void __am_uart_rx(AM_UART_RX_T *rx) {
    if ((*(volatile unsigned char *)(0x10000000 + 5) & 0x01) == 0)
        rx->data = (char)-1;
    else
        rx->data = *(volatile unsigned char *)(0x10000000 + 0);
}

static void __am_input_config(AM_INPUT_CONFIG_T *cfg) {
    cfg->present = true;
}

static void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
    cfg->present = true;
    cfg->has_accel = true;
    cfg->width = 640;
    cfg->height = 480;
    cfg->vmemsz = 0x200000;
}

static void __am_timer_config(AM_TIMER_CONFIG_T *cfg) {
    cfg->present = true;
    cfg->has_rtc = true;
}

typedef void (*handler_t)(void *buf);
static void *lut[128] = {
    [AM_UART_RX] = __am_uart_rx,
    [AM_UART_TX] = __am_uart_tx,
    [AM_UART_CONFIG] = __am_uart_config,
    [AM_INPUT_CONFIG] = __am_input_config,
    [AM_INPUT_KEYBRD] = __am_input_keybrd,
    [AM_GPU_CONFIG] = __am_gpu_config,
    [AM_GPU_FBDRAW] = __am_gpu_fbdraw,
    [AM_GPU_MEMCPY] = __am_gpu_memcpy,
    [AM_TIMER_CONFIG] = __am_timer_config,
    [AM_TIMER_UPTIME] = __am_timer_uptime,
    [AM_TIMER_RTC] = __am_timer_rtc
};

static void fail(void *buf) { panic("access nonexist register"); }

bool ioe_init() {
  for (int i = 0; i < LENGTH(lut); i++)
    if (!lut[i]) lut[i] = fail;
  return true;
}


void ioe_read (int reg, void *buf) { ((handler_t)lut[reg])(buf); }
void ioe_write(int reg, void *buf) { ((handler_t)lut[reg])(buf); }