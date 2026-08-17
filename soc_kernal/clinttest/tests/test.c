#include <klib.h>
#include <stdint.h>

int main() {
  volatile uint32_t *mtime_addr = (volatile uint32_t *)0x02000000;
  volatile uint32_t *mtimeh_addr = (volatile uint32_t *)0x02000004;

  uint32_t mcycle, mcycleh, mtime, mtimeh;
  for (int i = 0; i < 16; i++) {
    asm volatile("csrr %0, mcycle" : "=r"(mcycle) : :);
    asm volatile("csrr %0, mcycleh" : "=r"(mcycleh) : :);
    mtime = *mtime_addr;
    mtimeh = *mtimeh_addr;
    printf("%10d %10d : %10d %10d\n", mcycle, mcycleh, mtime, mtimeh);
  }

  return 0;
}