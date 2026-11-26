/***************************************************************************************
* NPC EBREAK Handler
* EBREAK指令处理
***************************************************************************************/

#ifndef __EBREAK_H__
#define __EBREAK_H__

// DPI-C接口：ebreak处理
extern "C" void ebreak_handler(int code);

// DPI-C接口：Access Fault处理 (取指/load/store访问异常, 跳转地址0)
extern "C" void access_fault_handler(int pc_val, int is_store);

#endif
