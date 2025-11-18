#include <am.h>
#include <klib.h>

void __am_uart_rx(AM_UART_RX_T *uart) {
  // this function is not important on nemu, always return -1
  uart->data = 0xff;
}
