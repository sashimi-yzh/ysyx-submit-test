#ifndef AM_RISCV_YSYXSOC_PLATFORM_H
#define AM_RISCV_YSYXSOC_PLATFORM_H

#include <riscv/riscv.h>

/* MMIO addresses shared by the ysyxSoC AM drivers. */
#define YSYXSOC_MTIME_LOW_ADDR       0x0200bff8u
#define YSYXSOC_MTIME_HIGH_ADDR      0x0200bffcu
#define YSYXSOC_UART_BASE            0x10000000u
#define YSYXSOC_GPIO_LED_ADDR        0x10002000u
#define YSYXSOC_GPIO_SWITCH_ADDR     0x10002004u
#define YSYXSOC_GPIO_SEGMENT_ADDR    0x10002008u
#define YSYXSOC_KEYBOARD_DATA_ADDR   0x10011000u
#define YSYXSOC_FRAMEBUFFER_ADDR     0x21000000u

/* 16550-compatible UART register offsets. */
#define UART_RX_DATA_OFFSET          0x00u
#define UART_TX_DATA_OFFSET          0x00u
#define UART_DIVISOR_LOW_OFFSET      0x00u
#define UART_DIVISOR_HIGH_OFFSET     0x01u
#define UART_FIFO_CONTROL_OFFSET     0x02u
#define UART_LINE_CONTROL_OFFSET     0x03u
#define UART_LINE_STATUS_OFFSET      0x05u

/* UART status and configuration values. */
#define UART_STATUS_RX_READY         0x01u
#define UART_STATUS_TX_READY         0x20u
#define UART_CONTROL_DLAB            0x80u
#define UART_CONTROL_8N1             0x03u
#define UART_DIVISOR_LOW_VALUE       0x01u
#define UART_DIVISOR_HIGH_VALUE      0x00u
#define UART_FIFO_INIT_VALUE         0x07u

void uart_init(void);
void putch(char ch);
void nvboard_init(void);
void halt(int code);

#endif
