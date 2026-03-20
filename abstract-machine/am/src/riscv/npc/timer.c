#include <am.h>
// #define RTC_ADDR 0x10000048
#define RTC_ADDR 0x02000048

static uint64_t _am_start_time;
static uint64_t get_us_time() {
  uint64_t lo = *(volatile uint32_t *)(RTC_ADDR);
  uint64_t hi = *(volatile uint32_t *)(RTC_ADDR + 4);
  uint64_t res = (hi << 32) | lo;
  return res;
}

void __am_timer_init() { _am_start_time = get_us_time(); }

void __am_timer_uptime(AM_TIMER_UPTIME_T *uptime) {
  uptime->us = (get_us_time() - _am_start_time)*4;
	// adjust to make npc timer closer to real time
}

void __am_timer_rtc(AM_TIMER_RTC_T *rtc) {

  rtc->second = 0;
  rtc->minute = 0;
  rtc->hour = 0;
  rtc->day = 0;
  rtc->month = 0;
  rtc->year = 1900;
}
