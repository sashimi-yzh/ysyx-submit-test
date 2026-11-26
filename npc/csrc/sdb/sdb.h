#ifndef __SDB_H__
#define __SDB_H__

#include <cstdint>
#include <cstdio>
#include <cstring>
#include <cstdlib>

typedef uint32_t word_t;

// 顶层模块
#ifdef SOC_MODE
class VysyxSoCFull;
using SimTop = VysyxSoCFull;
#else
class Vtop;
using SimTop = Vtop;
#endif

// 表达式求值
word_t expr(char *e, bool *success);

// 监视点结构体定义
typedef struct watchpoint WP;

// 监视点接口
WP* create_watchpoint(char *expr_str);
bool delete_watchpoint(int no);
void display_watchpoints();
bool check_watchpoints();

// PC 断点
bool check_breakpoints();

// sdb主接口
void init_sdb();
void sdb_set_batch_mode();
void sdb_mainloop();

// 寄存器和内存访问接口（需要在main.cpp中实现）
extern word_t npc_reg_str2val(const char *name, bool *success);
extern void npc_reg_display();
extern word_t flash_read_word(uint32_t addr);
extern bool in_flash(uint32_t addr);
extern word_t pmem_read_word(uint32_t addr);
extern bool in_pmem(uint32_t addr);
extern bool npc_mem_read_word(uint32_t addr, uint32_t *data);

// CPU执行接口
extern void cpu_exec(uint64_t n);

extern SimTop* top;

#endif
