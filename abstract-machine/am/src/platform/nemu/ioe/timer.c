#include <am.h>
#include <nemu.h>

#ifdef __ICS_EXPORT
void __am_timer_init() {
}

void __am_timer_uptime(AM_TIMER_UPTIME_T *uptime) {
  uptime->us = 0;
}
#else
static uint64_t boot_time = 0;

static uint64_t read_time() {
  union {
    struct { uint32_t lo, hi; };
    uint64_t val;
  } time;
  time.hi = inl(RTC_ADDR + 4);
  time.lo = inl(RTC_ADDR);
  return time.val;
}

void __am_timer_uptime(AM_TIMER_UPTIME_T *uptime) {
  uptime->us = read_time() - boot_time;
}

void __am_timer_init() {
  boot_time = read_time();
}
#endif

void __am_timer_rtc(AM_TIMER_RTC_T *rtc) {
  rtc->second = 0;
  rtc->minute = 0;
  rtc->hour   = 0;
  rtc->day    = 0;
  rtc->month  = 0;
  rtc->year   = 1900;
}
