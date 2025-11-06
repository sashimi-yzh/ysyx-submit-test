#include <riscv/riscv.h>

//uart
#define UART_REG_RB  0x10000000     // receiver buffer
#define UART_REG_LC  0x10000003
#define UART_REG_DL1 0x10000000
#define UART_REG_DL2 0x10000001
#define UART_REG_LS  0x10000005

// Line Status Register bits
#define UART_LS_DR	0	// Data ready
#define UART_LS_OE	1	// Overrun Error
#define UART_LS_PE	2	// Parity Error
#define UART_LS_FE	3	// Framing Error
#define UART_LS_BI	4	// Break interrupt
#define UART_LS_TFE	5	// Transmit FIFO is empty
#define UART_LS_TE	6	// Transmitter Empty indicator
#define UART_LS_EI	7	// Error indicator

// SPI
#define SPI_BASE    0x10001000
#define SPI_RX_0    SPI_BASE + 0x0
#define SPI_RX_1    SPI_BASE + 0x4
#define SPI_RX_2    SPI_BASE + 0x5
#define SPI_RX_3    SPI_BASE + 0xc
#define SPI_TX_0    SPI_BASE + 0x0
#define SPI_TX_1    SPI_BASE + 0x4
#define SPI_TX_2    SPI_BASE + 0x8
#define SPI_TX_3    SPI_BASE + 0xc
#define SPI_CTRL    SPI_BASE + 0x10
#define SPI_DEVIDE  SPI_BASE + 0x14
#define SPI_SS      SPI_BASE + 0x18

// PS/2
#define PS2_BASE    0x10011000

// VGA
#define VGA_BASE    0x21000000
#define VGA_SIZE    0x00200000

// clint
#define RTC_ADDR  0x02000000
#define RTC_SIZE  0x0000ffff


#define DEVICE_BASE 	0xa0000000
#define MMIO_BASE 	    0xa0000000

#define SERIAL_PORT     (DEVICE_BASE + 0x00003f8)
#define KBD_ADDR        (DEVICE_BASE + 0x0000060)
// #define RTC_ADDR        (DEVICE_BASE + 0x0000048)
#define VGACTL_ADDR     (DEVICE_BASE + 0x0000100)
#define AUDIO_ADDR      (DEVICE_BASE + 0x0000200)
#define DISK_ADDR       (DEVICE_BASE + 0x0000300)
#define FB_ADDR         (MMIO_BASE   + 0x1000000)
#define AUDIO_SBUF_ADDR (MMIO_BASE   + 0x1200000)
