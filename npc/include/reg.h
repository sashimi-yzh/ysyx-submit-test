#ifndef __REG_H__
#define __REG_H__

#define REG_NUM 16
typedef struct cpu_state {
    uint32_t gpr[16];
    uint32_t pc;
} CPU_state;

// SOC_NPC, SOC_GPR 当SOC_PC执行成功后, 下一个PC的值和新的GPR状态
#define SOC_NPC top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__u_ysyx_25050136_NPC__DOT__u_ysyx_25050136_NPCCORE__DOT__mem_dbg_pc
#define SOC_GPR top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__u_ysyx_25050136_NPC__DOT__u_ysyx_25050136_NPCCORE__DOT__u_ysyx_25050136_WB__DOT__u_ysyx_25050136_RegisterFile__DOT__gpr
// SOC_PC,SOC_INST 当前提交的的指令的PC, INST
#define SOC_PC   top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__u_ysyx_25050136_NPC__DOT__u_ysyx_25050136_NPCCORE__DOT__u_ysyx_25050136_WB__DOT__wb_dbg_pc
#define SOC_INST top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__u_ysyx_25050136_NPC__DOT__u_ysyx_25050136_NPCCORE__DOT__u_ysyx_25050136_WB__DOT__wb_dbg_inst
// SOC_SRAM 指向SOC的外设SRAM
#define SOC_SRAM top->rootp->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__mem_ext__DOT__Memory

uint32_t get_reg(int i);
void printf_regs();
uint32_t reg_str2val(const char *s, bool *success);
bool isa_difftest_checkregs(CPU_state *ref);

#endif