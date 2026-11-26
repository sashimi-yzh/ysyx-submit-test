#ifndef __FTRACE_H__
#define __FTRACE_H__

#include <stdint.h>
#include <stdbool.h>

// 初始化ftrace（需要ELF文件来解析符号表）
void init_ftrace(const char *elf_file);

// 运行时开关
void set_ftrace_enabled(bool enable);
bool ftrace_enabled();

// 记录函数调用（延迟输出）
// pc: 当前PC
// target: 跳转目标地址
void ftrace_call(uint32_t pc, uint32_t target);

// 记录函数返回（延迟输出）
// pc: jalr 指令地址
// target: 返回目标地址，即 ra 寄存器的值（用于查函数名）
void ftrace_ret(uint32_t pc, uint32_t target);

// 刷新ftrace缓冲区（在时钟周期结束后调用）
// print_to_console: 是否输出到控制台（si<=10时为true）
void ftrace_flush(bool print_to_console);
void ftrace_dump_recent();

#endif
