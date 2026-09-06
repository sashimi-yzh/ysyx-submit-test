#include "amdev.h"
#include "klib.h"
#include <am.h>
#include <klib-macros.h>

#define CLINT_MTIME_ADDR 0x0200bff8

static void __am_uart_tx(AM_UART_TX_T *cfg) { putch(cfg->data); }
static void __am_uart_rx(AM_UART_RX_T *cfg) {
  static char *str = "nemu am not fully support uart";
  static size_t i = 0;
  if (i < strlen(str)) {
    cfg->data = str[i];
    i++;
    return;
  }
  cfg->data = 0;
  return;
}

static uint64_t read_mtime(void) {
  volatile const uint32_t *mtime =
      (volatile const uint32_t *)(uintptr_t)CLINT_MTIME_ADDR;
  uint32_t high;
  uint32_t low;
  uint32_t high_after;

  // A low-word rollover between the two reads must not produce a torn value.
  do {
    high = mtime[1];
    low = mtime[0];
    high_after = mtime[1];
  } while (high != high_after);

  return ((uint64_t)high << 32) | low;
}

void __am_timer_uptime(AM_TIMER_UPTIME_T *uptime) {
  // Dissue models mtime at 1 MHz, so one tick is one microsecond.
  uptime->us = read_mtime();
}

void __am_timer_rtc(AM_TIMER_RTC_T *rtc) {
  rtc->second = 0;
  rtc->minute = 0;
  rtc->hour = 0;
  rtc->day = 0;
  rtc->month = 0;
  rtc->year = 1900;
}

static void __am_uart_config(AM_UART_CONFIG_T *cfg) { cfg->present = true; }
static void __am_timer_config(AM_TIMER_CONFIG_T *cfg) { cfg->present = true; }

typedef void (*handler_t)(void *buf);
static void *lut[128] = {
    [AM_UART_CONFIG] = __am_uart_config, [AM_UART_TX] = __am_uart_tx,
    [AM_UART_RX] = __am_uart_rx,         [AM_TIMER_CONFIG] = __am_timer_config,
    [AM_TIMER_RTC] = __am_timer_rtc,     [AM_TIMER_UPTIME] = __am_timer_uptime};

static void fail(void *buf) { panic("access nonexist register"); }

bool ioe_init() {
  for (int i = 0; i < LENGTH(lut); i++)
    if (!lut[i])
      lut[i] = fail;
  return true;
}

void ioe_read(int reg, void *buf) { ((handler_t)lut[reg])(buf); }
void ioe_write(int reg, void *buf) { ((handler_t)lut[reg])(buf); }
