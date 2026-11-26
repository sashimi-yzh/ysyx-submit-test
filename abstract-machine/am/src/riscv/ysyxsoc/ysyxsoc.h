#ifndef YSYXSOC_H__
#define YSYXSOC_H__

#include <klib-macros.h>
#include <riscv/riscv.h>

#define UART_BASE     0x10000000  
#define UART_TX       0x0          
#define UART_IE       0x1          
#define UART_FCR      0x2          
#define UART_LCR      0x3          
#define UART_LSR      0x5          
#define UART_LSR_THRE 0x20         // 发送保持寄存器空 (THRE, bit 5)
#define UART_LSR_DR   0x01         // 数据就绪 (DR, bit 0)
#define UART_LCR_DLAB 0x80         // 除数访问位 (LCR bit 7)
#define UART_LCR_8N1  0x03         // 8 数据位, 无校验, 1 停止位
#define UART_DIVISOR  0x01         // 波特率除数 

#define CPU_FREQ_MHZ 500

#define CLINT_BASE    0x02000000
#define CLINT_MTIME   0x0000bff8   // 64-bit mtime, low word first

#define PS2_BASE      0x10011000   

#define VGA_FB_BASE   0x21000000   
#define VGA_WIDTH     640
#define VGA_HEIGHT    480

#define SRAM_BASE     0x0f000000
#define SRAM_SIZE     0x2000       // 8KB

#define MROM_BASE     0x20000000
#define MROM_SIZE     0x1000       // 4KB

#define PSRAM_BASE    0x80000000
#define PSRAM_SIZE    0x400000     // 4MB

#define SDRAM_BASE    0xa0000000
#define SDRAM_SIZE    0x2000000    // 32MB

#define FLASH_BASE    0x30000000
#define FLASH_SIZE    0x1000000    // 16MB

#define npc_trap(code) asm volatile("mv a0, %0; ebreak" : :"r"(code))

#endif