#include <am.h>

#define RTC_BASE_ADDR  0x02000000
#define UPTIME_LOW  (*(volatile uint32_t *)(RTC_BASE_ADDR + 0x00))
#define UPTIME_HIGH (*(volatile uint32_t *)(RTC_BASE_ADDR + 0x04))
#define UPTIME_ENA  (*(volatile uint32_t *)(RTC_BASE_ADDR + 0x08))

void __am_timer_init() {
  UPTIME_ENA  = 1 ;
}

void __am_timer_uptime(AM_TIMER_UPTIME_T *uptime) {
  uint32_t high = UPTIME_HIGH;
  uint32_t low = UPTIME_LOW;
  uptime->us = (((uint64_t)low + (((uint64_t)high) << 32))  <<  0);
}

void __am_timer_rtc(AM_TIMER_RTC_T *rtc) {
  rtc->second = 0;
  rtc->minute = 0;
  rtc->hour   = 0;
  rtc->day    = 0;
  rtc->month  = 0;
  rtc->year   = 1900;
}
