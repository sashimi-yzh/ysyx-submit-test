#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include "../riscv.h"
#include "device/device.h"

extern char _heap_start;
extern char _heap_end;

void __am_uart_init();
int main(const char *args);

Area heap = RANGE(&_heap_start, &_heap_end);

static const char mainargs[MAINARGS_MAX_LEN] = MAINARGS_PLACEHOLDER; // defined in CFLAGS

void putch(char ch) {
  volatile uint8_t* uart_lsr = (volatile uint8_t*)(DEV_SERIAL + 5);
  while (!(*uart_lsr & 0x20));
  outb(DEV_SERIAL, ch);
}


char getch(){
  volatile uint8_t* uart_lsr = (volatile uint8_t*)(DEV_SERIAL + 5);
  if ((*uart_lsr & 0x01))
    return inb(DEV_SERIAL);
  else
    return 0xff;
}


void halt(int code) 
{
  asm volatile("mv a0, %0; ebreak" : :"r"(code));
  while (1);
}


void devinfo_print()
{
    unsigned int value;
    asm volatile ("csrr %0, mvendorid" : "=r"(value));
    char* ysyx = (char*)&value;
    putch(ysyx[3]); putch(ysyx[2]); putch(ysyx[1]); putch(ysyx[0]);
    putch('_');
    asm volatile ("csrr %0, marchid" : "=r"(value));
    char id[9] = {}; 
    int8_t i = 7;
    for (; i >= 0; i--)
    {
       id[i] = value % 10 + '0';
       value /= 10;
    }
    putstr(id); putch('\n');
}


void _trm_init()
{
  __am_uart_init();
  devinfo_print();
  int ret = main(mainargs);
  halt(ret);
}
