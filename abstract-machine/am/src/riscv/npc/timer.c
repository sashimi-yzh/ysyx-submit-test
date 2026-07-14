#include <am.h>
#include <riscv/riscv.h>
#include <npc.h>

void __am_timer_init()
{
}
#define SIM_FREQ_HZ (1000 * 1000 * 1000)

// void __am_timer_uptime(AM_TIMER_UPTIME_T *uptime) {
//   uptime->us = ((uint64_t)inl(RTC_UPTIME+4))<<32 | inl(RTC_UPTIME );
// }
void __am_timer_uptime(AM_TIMER_UPTIME_T *uptime)
{
  uint32_t hi, lo;

  do
  {
    hi = inl(CLINT_MTIME + 4);
    lo = inl(CLINT_MTIME);
  } while (hi != inl(CLINT_MTIME + 4));

  uint64_t cycles = (((uint64_t)hi) << 32) | lo;

  uptime->us = (cycles * 1000000ULL) / SIM_FREQ_HZ;
}
void __am_timer_rtc(AM_TIMER_RTC_T *rtc)
{

  rtc->second = inl(RTC);
  rtc->minute = inl(RTC + 4);
  rtc->hour = inl(RTC + 8);
  rtc->day = inl(RTC + 12);
  rtc->month = inl(RTC + 16);
  rtc->year = inl(RTC + 20);
}
