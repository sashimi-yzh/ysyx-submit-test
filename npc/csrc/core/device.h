/***************************************************************************************
* NPC Device Management
* 设备管理模块头文件
***************************************************************************************/

#ifndef __DEVICE_H__
#define __DEVICE_H__

#include <cstdint>

// ── 设备 MMIO 地址（与 npc.h / NEMU 保持一致）──────────────────────────
#define SERIAL_PORT    0x10000000   // 串口（只写，输出字符）
#define RTC_ADDR_LO    0x10000048   // RTC 低32位（只读）
#define RTC_ADDR_HI    0x1000004c   // RTC 高32位（只读）
#define KBD_ADDR       0x10000060   // 键盘数据寄存器（只读）
#define VGACTL_ADDR    0x10000100   // VGA 控制寄存器：高16位=宽，低16位=高
#define VGASYNC_ADDR   0x10000104   // VGA 同步寄存器（写1触发刷屏）
#define FB_ADDR        0x11000000   // 帧缓冲起始地址（MMIO）

// 屏幕分辨率
#define SCREEN_W  400
#define SCREEN_H  300

// 帧缓冲大小（字节）
#define FB_SIZE   (SCREEN_W * SCREEN_H * 4)

// ── 接口声明 ─────────────────────────────────────────────────────────────

// 初始化设备（设置启动时间、SDL 窗口等）
void init_device();

// 检查地址是否为设备地址（MMIO 寄存器区）
bool is_device_addr(uint32_t addr);

// 检查地址是否为帧缓冲地址
bool is_fb_addr(uint32_t addr);

// 设备寄存器读取
uint32_t device_read(uint32_t addr);

// 设备寄存器写入
void device_write(uint32_t addr, uint32_t data, uint8_t wmask);

// 帧缓冲写入（由 memory.cpp 调用）
void fb_write(uint32_t addr, uint32_t data, uint8_t wmask);

// 每条指令执行后调用，处理 SDL 事件
void device_update();

// 清理设备资源
void device_cleanup();

#endif
