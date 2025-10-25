#include <am.h>
#include "npc.h"
#include "riscv.h"
#define UART_RBR (0) // 接收缓冲寄存器 (DLAB=0)
#define UART_THR (0) // 发送保持寄存器 (DLAB=0)
#define UART_DLL (0) // 除数锁存器 LSB (DLAB=1)
#define UART_DLM (1) // 除数锁存器 MSB (DLAB=1)
#define UART_LCR (3) // 线路控制寄存器
#define UART_LSR (5) // 线路状态寄存器
unsigned char getch()
{
	volatile uint8_t *uart = (volatile uint8_t *)SERIAL_PORT;

	if (uart[UART_LSR] & 0x01)
	{
		return uart[0] & 0xFF; // 地址0就是 UART_RBR
	}
	return -1; // 无数据
}
void putch(char ch)
{

	volatile uint8_t *uart = (volatile uint8_t *)SERIAL_PORT;
	while ((uart[UART_LSR] & 0x40) == 0)
		;
	outb(SERIAL_PORT, ch);
}
void uart_init()
{
	volatile uint8_t *uart = (volatile uint8_t *)SERIAL_PORT;

	uart[UART_LCR] = 0x80;

	uart[UART_DLM] = 0x00;
	uart[UART_DLL] = 0x01;

	// 3. 设置通信参数并清除DLAB
	// 8位数据，无校验，1位停止位 (0b00000011)
	uart[UART_LCR] = 0x03;
}
void __am_uart_rx(AM_UART_RX_T *uart_rx)
{
	uart_rx->data = getch();
}