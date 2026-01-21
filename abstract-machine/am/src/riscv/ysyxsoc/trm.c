#include <am.h>
#include "ysyxsoc.h"

extern char _heap_start;
extern char _heap_end;
int main(const char *args);

Area heap = RANGE(&_heap_start, &_heap_end);
static const char mainargs[MAINARGS_MAX_LEN] = TOSTRING(MAINARGS_PLACEHOLDER); // defined in CFLAGS

int count = 0;

void putch(char ch) {
  while(1) {
    if(count < 16) {
      outb(UART_PORT, ch);
      count++;
      break;
    }
    if(inb(UART_LSR) & 0b00100000) {
      outb(UART_PORT, ch);
      count = 0;
      break;
    } 
  }
}

void halt(int code) {
  asm volatile("mv a0, %0; ebreak" : :"r"(code));
  while (1);
}

void _uart_init() {
  outb(UART_IER, 0b00000010);
  outb(UART_LCR, 0b10000011);
  outb(UART_DLH, 0);
  outb(UART_DLL, 1);
  outb(UART_LCR, 0b00000011);
}

static void _id_puts() {
  uint32_t mvendorid, marchid;
  asm volatile ("csrr %0, mvendorid" : "=r"(mvendorid));
  asm volatile ("csrr %0, marchid" : "=r"(marchid));
  for (int i = 7; i >= 0; i--) { 
      uint8_t nibble = (mvendorid >> (i * 4)) & 0xF;
      putch(nibble < 10 ? '0' + nibble : 'A' + nibble - 10);
  }
  putch('\n');
  for (int i = 7; i >= 0; i--) {  
      uint8_t nibble = (marchid >> (i * 4)) & 0xF;
      putch(nibble < 10 ? '0' + nibble : 'A' + nibble - 10);
  }
  putch('\n');
}

void _trm_init() {
  _uart_init();
  _id_puts();
  int ret = main(mainargs);
  halt(ret);
}
