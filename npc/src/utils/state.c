#include <npc.h>

NPCState npc_state = { .state = NPC_STOP };

int is_exit_status_bad() {
  int good = (npc_state.state == NPC_END && R[10] == 0) || (npc_state.state == NPC_QUIT);
  return !good;
}

void is_illegal_inst() {
  Log("\033[1;31mAbort at PC = 0x%08x with illegal_inst = 0x%08x\033[0m", CPU_PC(), CPU_INST());
  npc_state.state = NPC_ABORT;
  npc_state.halt_pc = CPU_PC();
}