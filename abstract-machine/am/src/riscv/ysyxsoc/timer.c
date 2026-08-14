#include <am.h>
#define UPDATE_ADDR        0x02000000
void __am_timer_init() {
}

void __am_timer_uptime(AM_TIMER_UPTIME_T *uptime) {
  uint32_t hi, lo, hi_check;
  do {
    hi = *(volatile uint32_t *)(UPDATE_ADDR + 4);
    lo = *(volatile uint32_t *)(UPDATE_ADDR);
    hi_check = *(volatile uint32_t *)(UPDATE_ADDR + 4);
  } while (hi != hi_check);
  // 标准双读法
  uptime->us = ((uint64_t)hi << 32) | lo;
  return ;
}

void __am_timer_rtc(AM_TIMER_RTC_T *rtc) {
  rtc->second = 0;
  rtc->minute = 0;
  rtc->hour   = 0;
  rtc->day    = 0;
  rtc->month  = 0;
  rtc->year   = 1900;
}
