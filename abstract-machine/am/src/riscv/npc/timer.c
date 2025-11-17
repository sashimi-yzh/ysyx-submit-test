#include <am.h>
#include <riscv/riscv.h>

//#define RTC_ADDR        (0xa0000000 + 0x0000048)
#define RTC_ADDR        (0x02000000 + 0x0000048)

void __am_timer_init() {
}

void __am_timer_uptime(AM_TIMER_UPTIME_T *uptime) {
  uint64_t us = 0;
  uint32_t us_high = inl(RTC_ADDR + 4);
  uint32_t us_low  = inl(RTC_ADDR);
  us = (uint64_t)us_low | ((uint64_t)us_high << 32);
  uptime->us = us / 2;
}

void __am_timer_rtc(AM_TIMER_RTC_T *rtc) {
  rtc->second = 0;
  rtc->minute = 0;
  rtc->hour   = 0;
  rtc->day    = 0;
  rtc->month  = 0;
  rtc->year   = 1900;
}
