#include<npc.h>

NPCState npc_state = { .state = NPC_STOP };

void set_npc_state(int state, vaddr_t pc, int halt_ret) {
//   difftest_skip_ref();
  npc_state.state = state;
  npc_state.halt_pc = pc;
  npc_state.halt_ret = halt_ret;
}

int is_exit_status_bad() {
  int good = (npc_state.state == NPC_END && npc_state.halt_ret == 0) ||
    (npc_state.state == NPC_QUIT);
  return !good;
}