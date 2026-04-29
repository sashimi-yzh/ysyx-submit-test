#ifndef __DEV_REG_H__
#define __DEV_REG_H__

#include <stdint.h>

typedef volatile uint8_t*  volatile_u8ptr;
typedef volatile uint16_t* volatile_u16ptr;
typedef volatile uint32_t* volatile_u32ptr;

typedef volatile_u8ptr dev_reg8_ptr;
typedef volatile_u16ptr dev_reg16_ptr;
typedef volatile_u32ptr dev_reg32_ptr;

#define DEV_REG8(addr)  ((dev_reg8_ptr)(addr))
#define DEV_REG16(addr) ((dev_reg16_ptr)(addr))
#define DEV_REG32(addr) ((dev_reg32_ptr)(addr))

#define UART_BASE 0x10000000u
#define _UART_R(x)    (DEV_REG8(UART_BASE + (x)))
#define UART_LCR       _UART_R(0x03)
#define UART_DL_LSB    _UART_R(0x00)
#define UART_DL_MSB    _UART_R(0x01)
#define UART_FIFO_CTRL _UART_R(0x02)
#define UART_IER       _UART_R(0x01)
#define UART_LSR       _UART_R(0x05)

#define UART_TX 			 _UART_R(0x00)
#define UART_RX 			 _UART_R(0x00)

#define IS_UART_TRANSMIT_EMPTY()  ((*UART_LSR)&0b00100000)
#define IS_UART_RECEIVE_READY()   ((*UART_LSR)&0b00000001)


#define SPI_BASE 0x10001000u
#define _SPI_R(x)    (DEV_REG32(SPI_BASE + (x)*4))
#define SPI_Rx0     _SPI_R(0)
#define SPI_Rx1     _SPI_R(1)
#define SPI_Rx2     _SPI_R(2)
#define SPI_Rx3     _SPI_R(3)
#define SPI_Tx0     _SPI_R(0)
#define SPI_Tx1     _SPI_R(1)
#define SPI_Tx2     _SPI_R(2)
#define SPI_Tx3     _SPI_R(3)
#define SPI_CTRL    _SPI_R(4)
#define SPI_DIVIDER _SPI_R(5)
#define SPI_SS      _SPI_R(6)

#define SPI_CTRL_ASS   (1<<13)
#define SPI_CTRL_IE    (1<<12)
#define SPI_CTRL_LSB   (1<<11)
#define SPI_CTRL_TXNEG (1<<10)
#define SPI_CTRL_RXNEG (1<<9)
#define SPI_CTRL_GOBSY (1<<8)

#define SPI_CTRL_CHARLEN(len) ((len)&0xff)

#define IS_SPI_BUSY()  ((*SPI_CTRL)&SPI_CTRL_GOBSY)

#define GPIO_BASE 0x10002000u
#define _GPIO_R(x)  (DEV_REG32(GPIO_BASE + (x)*4))
#define GPIO_LED    _GPIO_R(0)
#define GPIO_SWITCH _GPIO_R(1)
#define GPIO_SEG    _GPIO_R(2)

#define PS2_BASE 0x10011000u
#define _PS2_R(x) (DEV_REG8(PS2_BASE + (x)))
#define PS2_KEYINPUT   _PS2_R(0)

#define VGA_FB_BEG 0x21000000u
#define VGA_FB_END 0x211fffffu

#define CHIPLINK_MEM_BASE 0xc0000000u

#endif // __DEV_REG_H__
