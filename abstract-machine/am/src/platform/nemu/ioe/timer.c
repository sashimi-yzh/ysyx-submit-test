#include <am.h>
#include <nemu.h>
#include <stdint.h>
#include <stdio.h>
static uint64_t _am_start_time;

static uint64_t get_us_time(){
	uint64_t lo = inl(RTC_ADDR);
	uint64_t hi = inl(RTC_ADDR+4);
	uint64_t res=(hi<<32)|lo;
//	printf("hi %d lo %d\n",hi,lo);
	return res;
}

void __am_timer_init() {
	_am_start_time=get_us_time();
}

void __am_timer_uptime(AM_TIMER_UPTIME_T *uptime) {
  uptime->us = get_us_time()-_am_start_time;
}

void __am_timer_rtc(AM_TIMER_RTC_T *rtc) {
  rtc->second = 0;
  rtc->minute = 0;
  rtc->hour   = 0;
  rtc->day    = 0;
  rtc->month  = 0;
  rtc->year   = 1900;
}
