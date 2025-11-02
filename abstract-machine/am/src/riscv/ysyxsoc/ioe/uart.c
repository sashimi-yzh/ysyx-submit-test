#include <am.h>
#include <riscv/riscv.h>
#include <ysyxsoc.h>

void __am_uart_rx(AM_UART_RX_T *rx) {
	if(inb(UART_BASE + UART_LSR) & (char)0x01)
		rx -> data = inb(UART_BASE + UART_RX);
	else
		rx -> data = 0xff;
}
