#include "common.h"
#include "devices.h"
#include <sys/time.h>

enum{
  reg_us_l,
  reg_us_h,
  reg_rtc
};

static uint64_t boot_time = 0;

static uint64_t get_time_internal() {
  struct timeval now;
  gettimeofday(&now, NULL);
  uint64_t us = now.tv_sec * 1000000 + now.tv_usec;
  return us;
}

uint64_t get_time() {
  //printf("NOW=\n");
  if (boot_time == 0) boot_time = get_time_internal();
  uint64_t now = get_time_internal();
  return now - boot_time;
}

static uint32_t rtc_io_handler(uint32_t offset, uint32_t data, int len, bool is_write){
  static uint64_t latest_time=0;
  if(is_write){

  }else{
    switch (offset)
    {
    case reg_us_l*sizeof(uint32_t):
      latest_time = get_time();
      return latest_time & 0xffffffff;
      break;
    case reg_us_h*sizeof(uint32_t):
      return (latest_time >> 32) & 0xffffffff;
      break;
    default:
      break;
    }
  }
  return 0;
}

void init_rtc(){
  add_mmio_space("rtc", CONFIG_RTC_MMIO, CONFIG_RTC_MMIO_SIZE, rtc_io_handler);
}
