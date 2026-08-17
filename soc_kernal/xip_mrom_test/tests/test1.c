#include <klib.h>
#include <spi.h>
#include <stdint.h>

#define MY_CHECK(C)                                                            \
  do {                                                                         \
    if (!(C))                                                                  \
      return -1;                                                               \
  } while (0)
#define XIP_BASE 0x30000000
int main() {
  for (uint32_t i = 0; i < 0x100; i += 4) {
    uint32_t recv = inl(XIP_BASE + i);

    char buffer[16] = {};
    int cnt = 0;
    while (recv) {
      int dig = recv % 16;
      buffer[cnt++] = (dig < 10 ? '0' + dig : 'a' + dig - 10);
      recv /= 16;
    }
    while (cnt < 8) {
      buffer[cnt++] = '0';
    }
    for (int j = 7; j >= 0; j--)
      putch(buffer[j]);
    putch('\n');
  }
  asm volatile("lui t0, 0x30000");
  asm volatile("jr t0");
}
