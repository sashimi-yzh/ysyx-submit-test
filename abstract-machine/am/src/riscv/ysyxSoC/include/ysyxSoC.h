#ifndef YSYXSOC_H__
#define YSYXSOC_H__

#include <klib-macros.h>

#include ISA_H // the macro `ISA_H` is defined in CFLAGS
               // it will be expanded as "x86/x86.h", "mips/mips32.h", ...

#if defined(__ISA_X86__)
# define nemu_trap(code) asm volatile ("int3" : :"a"(code))
#elif defined(__ISA_MIPS32__)
# define nemu_trap(code) asm volatile ("move $v0, %0; sdbbp" : :"r"(code))
#elif defined(__riscv)
# define npc_trap(code) asm volatile("mv a0, %0; ebreak" : :"r"(code)) // 內联汇编
#elif defined(__ISA_LOONGARCH32R__)
# define nemu_trap(code) asm volatile("move $a0, %0; break 0" : :"r"(code))
#else
# error unsupported ISA __ISA__
#endif

#if defined(__ARCH_X86_NEMU)
# define DEVICE_BASE 0x0
#else
// # define DEVICE_BASE 0xa0000000
#endif

#define MMIO_BASE 0xa0000000

#define UART_BASE 0x10000000L
#define UART_RX   0
#define UART_TX   0 // 除法寄存器的低八位
#define UART_IE   1 // 除法寄存器的高八位
#define UART_FCR  2 // fifo 控制寄存器
#define UART_LCR  3 // bit7 跳转到除法寄存器
#define UART_LSR  5 // bit5 指示fifo空

// #define SPI_BASE   0x10001000L
// #define SPI_RX_0   0
// #define SPI_RX_1   1
// #define SPI_RX_2   2
// #define SPI_RX_3   3
// #define SPI_TX_0   0
// #define SPI_TX_1   1
// #define SPI_TX_2   2
// #define SPI_TX_3   3
// #define SPI_CTRL   4
// #define SPI_DEVIDE 5
// #define SPI_SS     6

#define RTC_ADDR        0x02000000
#define KBD_ADDR        0x10011000
// #define VGACTL_ADDR     0x21000000
#define FB_ADDR         0x21000000


#define GPIO_ADDR       0x10002000

// #define SERIAL_PORT     (0x10000000L)
// #define TIME_ADDR       (DEVICE_BASE + 0x0000070)
// #define RTC_ADDR        (DEVICE_BASE + 0x0000048)
// #define VGACTL_ADDR     (DEVICE_BASE + 0x0000100)
// #define AUDIO_ADDR      (DEVICE_BASE + 0x0000200)
// #define DISK_ADDR       (DEVICE_BASE + 0x0000300)
// #define FB_ADDR         (MMIO_BASE   + 0x1000000)
// #define AUDIO_SBUF_ADDR (MMIO_BASE   + 0x1200000)

extern char _pmem_start;
#define PMEM_SIZE (0x2000)
#define PMEM_END  ((uintptr_t)&_pmem_start + PMEM_SIZE)


typedef uintptr_t PTE;

#define PGSIZE    4096

#endif
