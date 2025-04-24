#include <am.h>
#include <klib-macros.h>
#include <klib.h>

extern char _heap_start, _heap_end;
int main(const char *args);

Area heap = RANGE(&_heap_start, &_heap_end);
static const char mainargs[MAINARGS_MAX_LEN] = TOSTRING(MAINARGS_PLACEHOLDER); // defined in CFLAGS
#define UART_BASE ((volatile uint8_t *)0x10000000ul)

void putch(char ch) {
  while ((UART_BASE[5] & 0x20) == 0); // wait until TX is empty
  UART_BASE[0] = ch;
}

void halt(int code) {
  asm volatile("mv a0, %0; ebreak" : :"r"(code));
  while (1);
}

static void uart_init() {
  uint8_t lcr = UART_BASE[3];
  UART_BASE[3] = lcr | 0x80;
  UART_BASE[1] = 0;
  UART_BASE[0] = 1;
  UART_BASE[3] = lcr;
}

void display_stuid() {
  union { char c[4]; uint32_t u32; } vendor;
  uint32_t marchid;
  asm volatile("csrr %0, mvendorid; csrr %1, marchid" :
      "=r"(vendor.u32), "=r"(marchid));
  printf("stu id = %c%c%c%c_%d\n", vendor.c[3], vendor.c[2],
      vendor.c[1], vendor.c[0], marchid);
}

void led_test() {
  int i = 0;
  uint16_t v = 0x5555;
  uint32_t stuid = 0x19010006;
  for (i = 0; i < 10; i ++) {
    for (volatile int j = 0; j < 100000; j ++);
    volatile uint32_t *gpio = (void *)0x10002000L;
    gpio[0] = v;
    gpio[2] = (i & 1) ? stuid : 0x89abcdef;
    v = (v << 1) | ((v >> 15) & 1);
    printf("sw = %x\n", gpio[1]);
  }
}

void _trm_init() {
  uart_init();
  display_stuid();
  //led_test();
  int ret = main(mainargs);
  halt(ret);
}
