/***************************************************************************************
* NPC Register Interface
* 寄存器访问接口
***************************************************************************************/

#ifndef __REG_H__
#define __REG_H__

#include <cstdint>

typedef uint32_t word_t;

// 寄存器名称转换为值
word_t npc_reg_str2val(const char *s, bool *success);

// 打印所有寄存器
void npc_reg_display();

// DPI-C接口（供Verilog调用）
extern "C" {
    void update_reg_value(int idx, int value);
    void update_pc_value(int pc_val);
    void update_inst_value(int pc_val, int inst_val);
}

#endif
