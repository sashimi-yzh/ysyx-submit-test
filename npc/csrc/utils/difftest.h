/***************************************************************************************
* NPC DiffTest 头文件
* 
* 定义 DiffTest 相关的数据结构和函数接口
***************************************************************************************/

#ifndef __DIFFTEST_H__
#define __DIFFTEST_H__

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>  // for size_t

// DiffTest 方向定义
enum { DIFFTEST_TO_DUT, DIFFTEST_TO_REF };

// CPU 状态结构
typedef struct {
  uint32_t gpr[16];  // 16个通用寄存器
  uint32_t pc;       // 程序计数器
} DiffTestState;

// DiffTest API 函数指针
extern void (*ref_difftest_memcpy)(uint32_t addr, void *buf, size_t n, bool direction);
extern void (*ref_difftest_regcpy)(void *dut, bool direction);
extern void (*ref_difftest_exec)(uint64_t n);
extern void (*ref_difftest_raise_intr)(uint64_t NO);
extern void (*ref_difftest_init)(int port);

// DiffTest 初始化和控制函数
void init_difftest(const char *ref_so_file, long img_size);
void difftest_step(uint32_t pc, uint32_t npc);
// extern "C": ysyx_26020070.v 通过 DPI-C 调用此函数 (UART 访问时自动 skip difftest)
extern "C" void difftest_skip_ref();

// 辅助函数
bool difftest_check_reg(const char *name, uint32_t pc, uint32_t ref, uint32_t dut);

#endif

