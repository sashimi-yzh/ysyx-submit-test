#include <am.h>
#include "ysyxsoc.h"
void __am_uart_init() {
    // LCR Configuration Register (Offset +3, DLAB=0)
  typedef union {
    uint8_t val;
    struct {
      uint8_t wls    : 2;  // [1:0] Word Length Select: 00=5, 01=6, 10=7, 11=8 bits
      uint8_t stb    : 1;  // [2]   Stop Bits: 0=1 stop, 1=1.5/2 stop bits
      uint8_t pen    : 1;  // [3]   Parity Enable
      uint8_t eps    : 1;  // [4]   Even Parity Select: 0=odd, 1=even
      uint8_t stkpar : 1;  // [5]   Stick Parity: 1=force fixed parity
      uint8_t brk    : 1;  // [6]   Break Control: 1=force TX low (break condition)
      uint8_t dlab   : 1;  // [7]   Divisor Latch Access Bit: 1=access baud divisor
    } bits;
  } LCR_CONFIG_T;
  LCR_CONFIG_T lcr_config;
  lcr_config.val = inb(SERIAL_PORT + 3);
  // lcr_config.bits.wls=0x3;
  // lcr_config.bits.stb=0;
  // lcr_config.bits.pen=0;
  lcr_config.bits.dlab=1;
  outb(SERIAL_PORT + 3, lcr_config.val);
  outb(SERIAL_PORT + 1, 0x00);
  outb(SERIAL_PORT + 0, 0x01);
  lcr_config.bits.dlab=0;
  outb(SERIAL_PORT + 3, lcr_config.val);
}


void __am_uart_rx(AM_UART_RX_T *val)
{
  if(!(inb(SERIAL_PORT + 5) & 0x01)){
    val->data = 0xff;
  }else{
    val->data = inb(SERIAL_PORT);
  }
}