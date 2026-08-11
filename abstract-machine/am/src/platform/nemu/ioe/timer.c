#include <am.h>
#include <nemu.h>
#include <stdint.h>

static inline uint32_t mmio_read(uintptr_t addr) {
  return *(volatile uint32_t *)addr;
}

void __am_timer_init() { }
// 这块应该就是那个小坑了！
void __am_timer_uptime(AM_TIMER_UPTIME_T *uptime) {
  uint32_t hi1, lo, hi2;
  do {
    hi1 = mmio_read(RTC_ADDR + 4);
    lo  = mmio_read(RTC_ADDR + 0);
    hi2 = mmio_read(RTC_ADDR + 4);
  } while (hi1 != hi2);

  uptime->us = ((uint64_t)hi1 << 32) | lo;
}

void __am_timer_rtc(AM_TIMER_RTC_T *rtc) {
  rtc->second = 0;
  rtc->minute = 0;
  rtc->hour   = 0;
  rtc->day    = 0;
  rtc->month  = 0;
  rtc->year   = 1900;
}