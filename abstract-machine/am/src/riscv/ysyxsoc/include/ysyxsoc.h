#ifndef NEMU_H__
#define NEMU_H__

#include <klib-macros.h>

#define UART_BASE 0x10000000
#define UART_REG_RB_TH (UART_BASE + 0x0) // Receive buffer
#define UART_REG_IE    (UART_BASE + 0x1) // Interrupt enable
#define UART_REG_II_FC (UART_BASE + 0x2) // Interrupt identification
#define UART_REG_LC    (UART_BASE + 0x3) // Line control
#define UART_REG_MC    (UART_BASE + 0x4) // Modem control
#define UART_REG_LS    (UART_BASE + 0x5) // Line status
#define UART_REG_MS    (UART_BASE + 0x6) // Modem status
#define UART_REG_SR    (UART_BASE + 0x7) // Scratch

#define PS2_BASE 0x10011000

#define VGA_BASE 0x21000000

#endif