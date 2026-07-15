#include <am.h>
#include <klib.h>

void __am_timer_init() {
}

void __am_timer_uptime(AM_TIMER_UPTIME_T *uptime) {
  uint64_t bef32_t = *(volatile uint32_t *)(0x02000008);
  uint64_t aft32_t = *(volatile uint32_t *)(0x02000004);
  uptime->us = (bef32_t << 32) | aft32_t;
}

void __am_timer_rtc(AM_TIMER_RTC_T *rtc) {
  rtc->second = 0;
  rtc->minute = 0;
  rtc->hour   = 0;
  rtc->day    = 0;
  rtc->month  = 0;
  rtc->year   = 1900;
}
