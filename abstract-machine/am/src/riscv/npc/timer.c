#include <am.h>
#include "./../riscv.h"
#include <stdio.h>

#define k 7 //系数 仿真速率实验值

void __am_timer_init() {
}

void __am_timer_uptime(AM_TIMER_UPTIME_T *uptime) {
  uint32_t high = inl(0x0200004c);
	uint32_t low  = inl(0x02000048);
	uptime->us = (((uint64_t)high << 32) + low) * k;
}

void __am_timer_rtc(AM_TIMER_RTC_T *rtc) {
  rtc->second = 0;
  rtc->minute = 0;
  rtc->hour   = 0;
  rtc->day    = 0;
  rtc->month  = 0;
  rtc->year   = 1900;
}
