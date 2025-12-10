#include "../../include/common.h"

NPCState npcstate = {.state = NPC_RUNNING};
void set_nemu_state(int state, uint32_t pc, int halt_ret){
  npcstate.state = state;
  npcstate.halt_pc = pc;
  npcstate.halt_ret = halt_ret;
}

bool is_ebreak(uint32_t inst_i) { return inst_i == 0x00100073; }
bool is_jal(uint32_t inst_i) { return (inst_i & 0x7F) == 0x6F; }
bool is_jalr(uint32_t inst_i) { return (inst_i & 0x7F) == 0x67; }
bool is_ret(uint32_t inst_i) {return inst_i == 0x00008067;  }
