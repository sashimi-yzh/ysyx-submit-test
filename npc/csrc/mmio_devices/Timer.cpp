#include <chrono>
#include <cstdint>
#include "include/common.h"
using namespace std::chrono;

static const steady_clock::time_point start_time = steady_clock::now();

uint32_t uptime_read(int addr)
{
    auto now = steady_clock::now();
    auto us_since_start = duration_cast<microseconds>(now - start_time).count();
    uint64_t uptime_data = us_since_start;
    if (addr == RTC_UPTIME)
    {
        return uptime_data & 0xFFFFFFFF;
    }
    else if (addr == RTC_UPTIME + 4)
    {
        return uptime_data >> 32;
    }
    return 0;
}


uint32_t real_time_read(int addr)
{
    auto now = system_clock::now();
    std::time_t t = system_clock::to_time_t(now);

    std::tm tm{};
    localtime_r(&t, &tm);

    int rtc_data[6] = {tm.tm_sec, tm.tm_min, tm.tm_hour, tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900};
    int idx = (addr - RTC) / 4;
    if (idx >= 0 && idx < 6)
    {
        return rtc_data[idx];
    }
    return 0;
}

void init_timer()
{
    add_device(RTC, 6 * 4, real_time_read, nullptr);
    add_device(RTC_UPTIME, 8, uptime_read, nullptr);
}
