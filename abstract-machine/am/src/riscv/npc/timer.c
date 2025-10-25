#include <am.h>
#include "npc.h"
#include "riscv.h"
static uint64_t boot_time = 0;
static uint64_t read_time()
{
	uint64_t us = 0;
	uint32_t res[2];
	res[0] = inl(RTC_ADDR + 0);
	res[1] = inl(RTC_ADDR + 4);
	us = ((uint64_t)res[1] << 32) | res[0];
	return us;
}
void __am_timer_init()
{
	boot_time = read_time();
}

void __am_timer_uptime(AM_TIMER_UPTIME_T *uptime)
{
	uptime->us = read_time() - boot_time;
}

void __am_timer_rtc(AM_TIMER_RTC_T *rtc)
{
	rtc->second = 0;
	rtc->minute = 0;
	rtc->hour = 0;
	rtc->day = 0;
	rtc->month = 0;
	rtc->year = 1900;
}
