#include <klib.h>
#include <spi.h>
#include <stdint.h>

#define MY_CHECK(C)                                                            \
  do {                                                                         \
    if (!(C))                                                                  \
      return -1;                                                               \
  } while (0)

int main() {
  for (int i = 0; i < 0xff0; i += 4) {
    uint32_t recv = flash_read(i);
    MY_CHECK(recv == i);
  }
  // char buffer[16] = {};
  // int cnt = 0;
  // while (recv) {
  //   int dig = recv % 16;
  //   buffer[cnt++] = (dig < 10 ? '0' + dig : 'a' + dig - 10);
  //   recv /= 16;
  // }
  // for (int i = cnt - 1; i >= 0; i--)
  //   putch(buffer[i]);
  // putch('\n');
}
