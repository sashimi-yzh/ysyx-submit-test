#include <npc.h>

#define NPC_PERIOD 5// in us

static uint64_t us = 0;

void __am_timer_init()
{
    uint32_t time_hi = inl(RTC_PORT+ 4);
    uint32_t time_lo = inl(RTC_PORT);

    // printf("Timer init: time_hi=0x%x time_lo=0x%x\n", time_hi, time_lo);

    us = (((uint64_t)time_hi << 32) | (uint64_t)time_lo) * NPC_PERIOD;
}

void __am_timer_uptime(AM_TIMER_UPTIME_T *uptime)
{
    uint32_t time_hi = inl(RTC_PORT+ 4);
    uint32_t time_lo = inl(RTC_PORT);

    uptime->us = (((uint64_t)time_hi << 32) | (uint64_t)time_lo) * NPC_PERIOD;
}

void __am_timer_rtc(AM_TIMER_RTC_T *rtc)
{
    uint32_t time_hi = inl(RTC_PORT+ 4);
    uint32_t time_lo = inl(RTC_PORT);

    // npc's period is 5us
    uint64_t up_us = (((uint64_t)time_hi << 32) | (uint64_t)time_lo) * NPC_PERIOD; 

    uint64_t s = (us + up_us) / 1000000ULL;
    uint64_t day = s / 86400ULL;
    rtc->second = s % 60;
    rtc->minute = (s / 60) % 60;
    rtc->hour   = (s / 3600) % 24;
    rtc->day    = day % 30 + 1;
    rtc->month  = day / 30 % 12 + 1;
    rtc->year   = 1970 + day / 365;
}
