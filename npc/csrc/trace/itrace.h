#ifndef __ITRACE_H__
#define __ITRACE_H__

#include <stdint.h>
#include <stdbool.h>

// 初始化itrace（包括capstone反汇编库）
void init_itrace();

// 运行时开关
void set_itrace_enabled(bool enable);
bool itrace_enabled();

// 记录一条指令的执行
// pc: 指令地址
// inst: 指令编码
// print_to_console: 是否输出到控制台（si<=10时为true）
void itrace_log(uint32_t pc, uint32_t inst, bool print_to_console);

// 显示指令环形缓冲区（用于错误时显示最近执行的指令）
void display_iringbuf();

#endif
