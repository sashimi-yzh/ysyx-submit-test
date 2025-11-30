#include <am.h>
#include "./../riscv.h"
#include <stdio.h>

#define UART_BASE 0X10000000
void __am_uart_rx(AM_UART_RX_T *rx) {
	if(!(inb(UART_BASE + 0X5) & 0x01)) { rx->data = 0xff; }
	else { rx->data = inb(UART_BASE); }
}
