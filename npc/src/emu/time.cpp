#include "common.h"
#include <sys/time.h>

static uint64_t boot_time = 0;

static uint64_t get_time_internal() {
  struct timeval now;
  gettimeofday(&now, NULL);
  uint64_t us = now.tv_sec * 1000000 + now.tv_usec;
  return us;
}

void init_time() {
  boot_time = get_time_internal();
}

uint64_t get_time() {
  uint64_t now = get_time_internal();
  return now - boot_time;
}
