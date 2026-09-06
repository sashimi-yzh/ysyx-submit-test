#include "common.h"
#include "map.h"
#include <ctime>
#include <iostream>
#include <stdint.h>

#define TIMER_BASE 0xa0000048

static uint32_t *rtc_port = NULL;
static uint64_t boot_time = 0;

uint64_t get_time() {
  timespec ts;
  timespec_get(&ts, TIME_UTC);
  uint64_t us = ts.tv_sec * 1000000 + ts.tv_nsec / 1000;
  if (boot_time == 0) {
    boot_time = us;
    return 0;
  }
  return us - boot_time;
}

void rtc_io_handle(uint32_t offset, int len, bool is_write) {
  uint64_t time_get = get_time();
  // std::cout << "the get time is " << time_get << std::endl;
  rtc_port[0] = (uint32_t)(time_get);
  rtc_port[1] = (uint32_t)(time_get >> 32);
}

void rtc_init() {
  rtc_port = (uint32_t *)new_space(8);
  add_mmio_map("timer", TIMER_BASE, 8, rtc_port, rtc_io_handle);
}
