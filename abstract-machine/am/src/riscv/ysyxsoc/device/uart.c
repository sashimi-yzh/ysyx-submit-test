#include <am.h>
#include <klib.h>
#include "device.h"

void __am_uart_init()
{
  device_ctrl uart_lcr = (device_ctrl)(DEV_SERIAL + 3);
  *uart_lcr = 0x83;

  device_ctrl uart_divisor = (device_ctrl)DEV_SERIAL;
  uart_divisor[1] = 0x00;
  uart_divisor[0] = 0x01;

  *uart_lcr = 0x03;
}


void __am_uart_rx(AM_UART_RX_T* rx)
{
  rx->data = getch();
}