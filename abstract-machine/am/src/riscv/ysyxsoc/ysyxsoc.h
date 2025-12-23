/*UART*/
#define UART_BASE 0x10000000

#define UART_REG_RB  0
#define UART_REG_LC  3
#define UART_REG_DL1 0
#define UART_REG_DL2 1
#define UART_REG_LS  5
// Line Status Register bits
#define UART_LS_DR	0	// Data ready
#define UART_LS_OE	1	// Overrun Error
#define UART_LS_PE	2	// Parity Error
#define UART_LS_FE	3	// Framing Error
#define UART_LS_BI	4	// Break interrupt
#define UART_LS_TFE	5	// Transmit FIFO is empty
#define UART_LS_TE	6	// Transmitter Empty indicator
#define UART_LS_EI	7	// Error indicator

/*PS2*/
#define PS2_BASE 0x10011000

/*GPU*/
#define VGA_BASE 0x21000000
#define VGA_SIZE 0x200000
#define VGA_WIDTH 640
#define VGA_HIGHT 480

/*RTC*/
#define RTC_BASE 0x02000000 //as same as CLINT BASE