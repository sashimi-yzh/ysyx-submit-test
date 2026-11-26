/***************************************************************************************
* NPC FTRACE DPI-C Interface
* FTRACE的DPI-C接口
***************************************************************************************/

#ifndef __FTRACE_DPI_H__
#define __FTRACE_DPI_H__

// DPI-C接口：ftrace函数调用处理
extern "C" void ftrace_call_handler(int pc_val, int target_val);

// DPI-C接口：ftrace函数返回处理
extern "C" void ftrace_ret_handler(int pc_val, int target_val);

#endif
