#ifndef NPC_H__
#define NPC_H__

#include <klib-macros.h>
#include <riscv/riscv.h>

#define SERIAL_PORT  0x10000000   // 串口（只写）
#define RTC_ADDR_LO  0x10000048   // RTC 低32位（只读）
#define RTC_ADDR_HI  0x1000004c   // RTC 高32位（只读）
#define KBD_ADDR     0x10000060   // 键盘数据寄存器（只读）
#define VGACTL_ADDR  0x10000100   // VGA 控制：高16位=宽，低16位=高（只读）
#define VGASYNC_ADDR 0x10000104   // VGA 同步：写1触发刷屏（只写）
#define FB_ADDR      0x11000000   // 帧缓冲起始地址

extern char _pmem_start;
#define PMEM_SIZE (128 * 1024 * 1024)
#define PMEM_END  ((uintptr_t)&_pmem_start + PMEM_SIZE)

#define npc_trap(code) asm volatile("mv a0, %0; ebreak" : :"r"(code))

#endif
