#include <am.h>
#include <klib-macros.h>
extern char _heap_start;
extern char _heap_end;
int main(const char *args);

Area heap = RANGE(&_heap_start, &_heap_end);
static const char mainargs[MAINARGS_MAX_LEN] =
    TOSTRING(MAINARGS_PLACEHOLDER); // defined in CFLAGS

void putch(char ch) {
  AM_UART_TX_T tx = {.data = ch};
  ioe_write(AM_UART_TX, &tx);
}

void halt(int code) {
  asm volatile("mv a0, %0; ebreak" : : "r"(code));
  while (1)
    ;
}

void loadVendor() {
  int printf(const char *format, ...);
  unsigned int mvendorid;
  unsigned int marchid;
  asm volatile("csrr %0, mvendorid" : "=r"(mvendorid));
  asm volatile("csrr %0, marchid" : "=r"(marchid));
  char mvendoridString[5];
  mvendoridString[0] = mvendorid >> 24;
  mvendoridString[1] = mvendorid >> 16;
  mvendoridString[2] = mvendorid >> 8;
  mvendoridString[3] = mvendorid >> 0;
  mvendoridString[4] = '\0';
  printf("mvendorid: %s\n", mvendoridString);
  printf("marchid: %d\n", marchid);
}

void _trm_init() {
  // loadVendor();
  int ret = main(mainargs);
  halt(ret);
}
