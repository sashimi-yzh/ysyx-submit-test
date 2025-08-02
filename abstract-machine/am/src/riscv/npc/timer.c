#include <am.h>

void __am_timer_init() {
  // for FPGA
  *(volatile uint32_t  *)0x02000008 = 1;
}

void __am_timer_uptime(AM_TIMER_UPTIME_T *uptime) {
  // uint32_t high = *(volatile uint32_t *)0xa000004C;
  // uint32_t low = *(volatile uint32_t *)0xa0000048;
  // uptime->us = (uint64_t)low + (((uint64_t)high) << 32);

  // for FPGA
  uint32_t high = *(volatile uint32_t *)0x02000004;
  uint32_t low = *(volatile uint32_t *)0x02000000;
  uptime->us = (uint64_t)low + (((uint64_t)high) << 32);
}

void __am_timer_rtc(AM_TIMER_RTC_T *rtc) {
  rtc->second = 0;
  rtc->minute = 0;
  rtc->hour   = 0;
  rtc->day    = 0;
  rtc->month  = 0;
  rtc->year   = 1900;
}
