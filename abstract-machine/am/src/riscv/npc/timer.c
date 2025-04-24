#include <am.h>

#ifdef __ICS_EXPORT
void __am_timer_init() {
}

void __am_timer_uptime(AM_TIMER_UPTIME_T *uptime) {
  uptime->us = 0;
}
#else
static uint64_t boot_time = 0;

static uint64_t read_time() {
#if __riscv_xlen == 64
  volatile uint64_t *p = (uint64_t *)0x0200bff8ul;
  return *p;
#else
  volatile uint32_t *p = (uint32_t *)0x0200bff8ul;
  uint64_t us = (uint64_t)p[1] << 32;
  us |= p[0];
  return us;
#endif
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
