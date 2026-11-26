#include <am.h>
#include "ysyxsoc.h"

void __am_timer_init() {
}

void __am_timer_uptime(AM_TIMER_UPTIME_T *uptime) {
  uint32_t lo = *(volatile uint32_t *)(CLINT_BASE + CLINT_MTIME);
  uint32_t hi = *(volatile uint32_t *)(CLINT_BASE + CLINT_MTIME + 4);
  uptime->us = (((uint64_t)hi << 32) | lo) / CPU_FREQ_MHZ;
}

void __am_timer_rtc(AM_TIMER_RTC_T *rtc) {
  rtc->second = 0;
  rtc->minute = 0;
  rtc->hour   = 0;
  rtc->day    = 1;
  rtc->month  = 1;
  rtc->year   = 2026;
}
