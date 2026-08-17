#pragma once
#include <chrono>
#include <cstdint>
struct RTC_t {
  uint64_t RTC_reg_bias;
  std::chrono::steady_clock::time_point last_time;
};

inline RTC_t RTC;

inline uint64_t update_RTC() {
  return RTC.RTC_reg_bias +
         std::chrono::duration_cast<std::chrono::microseconds>(
             std::chrono::steady_clock::now() - RTC.last_time)
             .count();
}