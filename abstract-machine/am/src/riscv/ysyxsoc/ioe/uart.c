#include <am.h>
#include <riscv/ysyxsoc/ysyxsoc.h>

void __am_uart_rx(AM_UART_RX_T *uart) {
  uint8_t ret = 0xff;
  if(inb(UART_LSR) & 0b00000001) {ret = inb(UART_PORT);}
  uart->data = ret;
}

