#include "device.h"

#include <stdio.h>
#include <sys/types.h>
#include <time.h>

struct timespec start, end;

word_t rtc[2] = {};

void timer_init()
{
    // 获取程序启动时间
    clock_gettime(CLOCK_MONOTONIC, &start);
}

void timer_handler(word_t addr, void* data, bool isw)
{
    clock_gettime(CLOCK_MONOTONIC, &end);    // 当前时间

    long seconds = end.tv_sec - start.tv_sec;
    long nanos = end.tv_nsec - start.tv_nsec;
    
    if (nanos < 0) {
        seconds -= 1;
        nanos += 1000000000;  // 借一秒，补纳秒
    }
    
    uint64_t cur = (uint64_t)seconds * 1000000 + nanos / 1000;
    rtc[0] = (word_t)cur;
    rtc[1] = cur >> 32;

    *((word_t*)data) = (addr - DEV_TIMER) ? rtc[1] : rtc[0];
}