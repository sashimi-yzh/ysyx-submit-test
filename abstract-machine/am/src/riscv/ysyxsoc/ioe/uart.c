#include <am.h>
#include <ysyxsoc.h>

#define THR_ADDR UART_ADDR
#define DIV_LSB_ADDR UART_ADDR
#define DIV_MSB_ADDR UART_ADDR + 1
#define IER_ADDR UART_ADDR + 1
#define FCR_ADDR UART_ADDR + 2
#define LCR_ADDR UART_ADDR + 3
#define LST_ADDR UART_ADDR + 5

void __am_uart_init() {
  outb(LCR_ADDR, 0b10000011);
  outb(DIV_MSB_ADDR, 0);
  outb(DIV_LSB_ADDR, 1);
  outb(LCR_ADDR, 0b00000011);
  outb(FCR_ADDR, 0b11000110);
  outb(IER_ADDR, 0b00000000);
}

void __am_uart_tx(AM_UART_TX_T *out) {
  while (!((inb(LST_ADDR) >> 5) & 1));
  outb(THR_ADDR, out->data);
}

void __am_uart_rx(AM_UART_RX_T *in) {
  in->data = (inb(LST_ADDR) & 1) ? inb(THR_ADDR) : 0xff;
}
