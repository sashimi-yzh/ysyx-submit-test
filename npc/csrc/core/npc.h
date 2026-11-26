/***************************************************************************************
* NPC Core
* NPC核心状态管理
***************************************************************************************/

#ifndef __NPC_H__
#define __NPC_H__

#include <cstdint>

// NPC状态枚举
enum {
    NPC_RUNNING,
    NPC_STOP,
    NPC_END,
    NPC_ABORT,
    NPC_QUIT
};

// NPC状态结构
struct NPCState {
    int state;
    uint32_t halt_pc;
    uint32_t halt_ret;
};

// 获取NPC状态
NPCState* npc_get_state();

// 周期/提交计数
uint64_t npc_get_cycle();
uint64_t npc_get_commit_count();
uint64_t npc_get_commit_cycle();
uint64_t npc_get_commit_time();
uint64_t npc_get_time();
void npc_inc_cycle();

// 获取当前PC
uint32_t npc_get_pc();

// 获取当前指令
uint32_t npc_get_inst();

// 获取寄存器值
uint32_t npc_get_reg(int idx);

// CSR 缓存: 0=mstatus, 1=mtvec, 2=mepc, 3=mcause, 4=mcycle, 5=mcycleh
uint32_t npc_get_csr(int idx);

// 退出控制
void npc_set_exit(bool exit, uint32_t code);
bool npc_should_exit();
uint32_t npc_get_exit_code();

// DPI-C接口
extern "C" {
    void update_reg_value(int idx, int value);
    void update_pc_value(int pc_val);
    void update_inst_value(int pc_val, int inst_val);
    void update_csr_values(int mstatus, int mtvec, int mepc, int mcause,
                           int mcycle_lo, int mcycle_hi);
}

#endif
