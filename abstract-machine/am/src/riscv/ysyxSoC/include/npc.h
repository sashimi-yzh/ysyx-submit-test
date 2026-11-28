#ifndef NPC_H__
#define NPC_H__


#define UART_BASE 0x10000000 

#define UART_REG_TR  0x0 
#define UART_REG_XR  0x0
#define UART_REG_DL1 0x0 // Divisor Latch Low
#define UART_REG_DL2 0x1 // Divisor Latch High
#define UART_REG_LC  0x3 // Line Control

#define UART_REG_LS  0x5  // LSR

#define UART_LS_THRE 0x20 // Bit 5: Transmitter Holding Register Empty
#define UART_LS_DR 0x1 // bit 0: Data Ready (DR) indicator 

#define RTC_ADDR         (0x02000000 + 0XBFF8)

#define GPIO_BASE 0x10002000
#define GPIO_LED (GPIO_BASE + 0x0)
#define GPIO_SW (GPIO_BASE + 0x4)
#define GPIO_SEG (GPIO_BASE + 0x8)

#define KEYBOARD (0x10011000)

#define VGA_BASE (0x21000000)
#endif