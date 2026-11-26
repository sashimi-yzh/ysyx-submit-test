/***************************************************************************************
* NPC CPU Execution
* CPU执行控制模块
***************************************************************************************/

#ifndef __CPU_H__
#define __CPU_H__

#include <cstdint>

// 初始化CPU（Verilator模块）
bool init_cpu(int argc, char** argv);

// 复位CPU
void reset_cpu();

// 单步执行
void exec_once();

// CPU执行n条指令
void cpu_exec(uint64_t n);

// 清理CPU资源
void cleanup_cpu();

// 设置itrace输出模式
void set_itrace_print(bool enable);

#endif
