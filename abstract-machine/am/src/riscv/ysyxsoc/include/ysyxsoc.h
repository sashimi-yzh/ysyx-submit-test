#ifndef NPC_H__
#define NPC_H__

#define UART_BASE 0x10000000
#define UART_RBR (UART_BASE + 0x00) // DLAB=0: 接收缓冲
#define UART_THR (UART_BASE + 0x00) // DLAB=0: 发送保持
#define UART_IER (UART_BASE + 0x01) // DLAB=0: 中断使能
#define UART_FCR (UART_BASE + 0x02)
#define UART_DLL (UART_BASE + 0x00) // DLAB=1: 除数低字节
#define UART_DLM (UART_BASE + 0x01) // DLAB=1: 除数高字节
#define UART_LCR (UART_BASE + 0x03)
#define UART_LSR (UART_BASE + 0x05)


#define RTC         0x10000004
#define RTC_UPTIME 0x10000028

#endif