#include "utils.h"

NPCState npc_state = { .state = NPC_STOP };

int is_exit_status_bad() {
  int good = (npc_state.state == NPC_END && npc_state.halt_ret == 0) ||
    (npc_state.state == NPC_QUIT);
  return !good;
}

void set_npc_state(int state, addr_t halt_pc, int halt_ret) {
  npc_state.state = state;
  npc_state.halt_pc = halt_pc;
  npc_state.halt_ret = halt_ret;
}
