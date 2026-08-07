#include <am.h>

extern char _end[];
#define psramBase _end
#define psramSize 0x00400000u
#define sdramBase 0xa0000000u
#define sdramSize 0x08000000u // 0x0100_0000 * 2 * 4
#define base sdramBase
void check(bool res) {
  if (!res)
    halt(1);
}
int main() {
  check(((unsigned int)base & 0x3) == 0);
  for (int i = base; i < base + sdramSize; i += sizeof(int)) {
    *((volatile int *)(i)) = i & 0xffffffff;
    check(*((volatile int *)(i)) == (i & 0xffffffff));
  }
  for (int i = base; i < base + sdramSize; i += sizeof(int)) {
    check(*((volatile int *)(i)) == (i & 0xffffffff));
  }
  for (int i = base; i < base + sdramSize; i += sizeof(short)) {
    *((volatile short *)(i)) = i & 0xffff;
    check(*((volatile short *)(i)) == (i & 0xffff));
  }
  for (int i = base; i < base + sdramSize; i += sizeof(short)) {
    check(*((volatile short *)(i)) == (i & 0xffff));
  }
  for (int i = base; i < base + sdramSize; i += sizeof(char)) {
    *((volatile char *)(i)) = i & 0xff;
    check(*((volatile char *)(i)) == (i & 0xff));
  }
  for (int i = base; i < base + sdramSize; i += sizeof(char)) {
    check(*((volatile char *)(i)) == (i & 0xff));
  }
  return 0;
}
