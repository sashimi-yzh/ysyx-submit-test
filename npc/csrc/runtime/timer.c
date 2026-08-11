#include <stdlib.h>
#include <time.h>
#include <npc/base.h>

static uint64_t epoch_us;
// linux系统时间
static uint64_t clock_us(void) {
  struct timespec timestamp;
  clock_gettime(CLOCK_MONOTONIC_COARSE, &timestamp);
  return timestamp.tv_sec * 1000000 + timestamp.tv_nsec / 1000;
}
// generate random seed
void init_rand() {
  srand((unsigned)clock_us());
}
// timepiece
uint64_t get_time() {
  uint64_t now = clock_us();
  if (epoch_us == 0) epoch_us = now;
  return now - epoch_us;
}
