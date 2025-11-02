#include <am.h>
#include <nemu.h>

void __am_timer_init() {
}

void __am_timer_uptime(AM_TIMER_UPTIME_T *uptime) {
  //uptime->us = 0;
  //uint32_t us_low = inl(RTC_ADDR); // 0xa0000048
  uint32_t us_high = inl(RTC_ADDR + 4); // 0xa000004c,offset=4
  uint32_t us_low = inl(RTC_ADDR);
  
  uptime->us = ((uint64_t)us_high) << 32 | us_low;
}

void __am_timer_rtc(AM_TIMER_RTC_T *rtc) {
  rtc->second = 0;
  rtc->minute = 0;
  rtc->hour   = 0;
  rtc->day    = 0;
  rtc->month  = 0;
  rtc->year   = 1900;
}
