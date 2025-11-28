#include <am.h>
#include <riscv.h>
#include <ysyxsoc.h>
#include <klib.h>
long long rtc[2];
static long long  start=0; 
static long long  now=0; 

void __am_timer_init() {
  rtc[0] = inl(MTIME_LOW);
  rtc[1] = inl(MTIME_HIGH);
  start = ((rtc[1]<<32)|rtc[0]);
}

void __am_timer_uptime(AM_TIMER_UPTIME_T *uptime) {
  rtc[0] = inl(MTIME_LOW);
  rtc[1] = inl(MTIME_HIGH);
  now = ((rtc[1]<<32)|rtc[0]);
  uptime->us = now-start;
}

void __am_timer_rtc(AM_TIMER_RTC_T *rtc) {
  rtc->second = 0;
  rtc->minute = 0;
  rtc->hour   = 0;
  rtc->day    = 0;
  rtc->month  = 0;
  rtc->year   = 1900;
}
