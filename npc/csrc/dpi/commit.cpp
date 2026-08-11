#include <isa.h>
#include <string.h>
#include <npc/cpu.h>
#include <npc/diagnostics.h>
// break inst
constexpr uint32_t INST_EBREAK = 0x00100073u;
constexpr uint32_t INST_ECALL  = 0x00000073u;
constexpr uint32_t INST_MRET   = 0x30200073u;

constexpr uint32_t MSTATUS_MIE      = 1u << 3;
constexpr uint32_t MSTATUS_MPIE     = 1u << 7;
constexpr uint32_t MSTATUS_MPP_MASK = 3u << 11;
constexpr uint32_t MACHINE_MODE     = 3u << 11;
// struct def for retirement inst
struct RetireEvent {
  bool occupied;
  vaddr_t pc;
  uint32_t inst_word;
};
// initial the retirement struct
static RetireEvent mailbox = {};
// record the latest 16 retire pc by a vector (circular array)
constexpr uint32_t RETIRE_HISTORY_SIZE = 16;
static vaddr_t retire_history[RETIRE_HISTORY_SIZE] = {};
static uint32_t retire_history_pos = 0;
// push pc
static void remember_retirement(vaddr_t pc) {
  retire_history[retire_history_pos] = pc;
  retire_history_pos = (retire_history_pos + 1) % RETIRE_HISTORY_SIZE;
}
// print pc
static void print_retire_history() {
  Log("retirement history before nonzero halt:");
  for (uint32_t i = 0; i < RETIRE_HISTORY_SIZE; i ++) {
    uint32_t slot = (retire_history_pos + i) % RETIRE_HISTORY_SIZE;
    Log("  [%02u] " FMT_WORD, i, retire_history[slot]);
  }
}
// state is correct
static bool runtime_is_closed() {
  return npc_state.state == NPC_END || npc_state.state == NPC_ABORT || npc_state.state == NPC_QUIT;
}
// check align (security check)
static void validate_retirement_address(vaddr_t retired_pc, vaddr_t next_pc, uint32_t instruction) {
  // pc is aligned && pc next is aligned
  Assert((retired_pc & 3u) == 0, "retirement address is unaligned: pc=" FMT_WORD " inst=0x%08x", retired_pc, instruction);
  Assert((next_pc & 3u) == 0, "successor address is unaligned: pc=" FMT_WORD " inst=0x%08x", next_pc, instruction);
}
// check ecall && mret (security check)
static void validate_privileged_transition(vaddr_t retired_pc, uint32_t instruction, vaddr_t next_pc, word_t mstatus, word_t mtvec, word_t mepc, word_t mcause) {
  if (instruction == INST_ECALL) {
    bool saved_pc = (mepc == retired_pc);
    bool machine_trap = (mcause == 11);
    bool entered_vector = (next_pc == (mtvec & ~3u));
    bool interrupts_off = ((mstatus & MSTATUS_MIE) == 0);
    bool machine_mode_saved = ((mstatus & MSTATUS_MPP_MASK) == MACHINE_MODE);
    Assert(saved_pc && machine_trap && entered_vector && interrupts_off && machine_mode_saved, "ecall retirement state mismatch: retire=" FMT_WORD " next=" FMT_WORD
      " mtvec=" FMT_WORD " mepc=" FMT_WORD " mcause=" FMT_WORD, retired_pc, next_pc, mtvec, mepc, mcause);
  } else if (instruction == INST_MRET) {
    bool resumed = (next_pc == mepc);
    bool interrupts_restored = ((mstatus & MSTATUS_MPIE) != 0);
    bool user_mode = ((mstatus & MSTATUS_MPP_MASK) == 0);
    Assert(resumed && interrupts_restored && user_mode, "mret retirement state mismatch: retire=" FMT_WORD " next=" FMT_WORD
      " mstatus=" FMT_WORD " mepc=" FMT_WORD, retired_pc, next_pc, mstatus, mepc);
  }
}
// synchronization the cpu (C struct)
static void install_arch_state(vaddr_t next_pc, word_t mstatus, word_t mtvec, word_t mepc, word_t mcause, const uint32_t *gpr) {
  memcpy(cpu.gpr, gpr, sizeof(cpu.gpr));
  cpu.pc = next_pc;
  cpu.mstatus = mstatus;
  cpu.mtvec = mtvec;
  cpu.mepc = mepc;
  cpu.mcause = mcause;
}
// with the right end (record info && print recent pc)
static void finish_on_breakpoint(vaddr_t retired_pc, uint32_t instruction) {
  if (instruction != INST_EBREAK) return;
  npc_state.state = NPC_END;
  npc_state.halt_pc = retired_pc;
  npc_state.halt_ret = cpu.gpr[10];
  if (npc_state.halt_ret != 0) print_retire_history();
}
// DPI interface
extern "C" void cpu_commit(uint32_t retired_pc, uint32_t retired_inst, uint32_t next_pc, uint32_t mstatus, uint32_t mtvec, uint32_t mepc, uint32_t mcause, const uint32_t *gpr) {
  if (runtime_is_closed()) return;

  Assert(!mailbox.occupied, "retirement queue overflow: queued=" FMT_WORD " incoming=" FMT_WORD, mailbox.pc, retired_pc);
  Assert(gpr != NULL, "retirement event has no register image at " FMT_WORD, retired_pc);

  validate_retirement_address(retired_pc, next_pc, retired_inst);
  validate_privileged_transition(retired_pc, retired_inst, next_pc, mstatus, mtvec, mepc, mcause);
  install_arch_state(next_pc, mstatus, mtvec, mepc, mcause, gpr);
  remember_retirement(retired_pc);
  mailbox = {true, retired_pc, retired_inst};
  finish_on_breakpoint(retired_pc, retired_inst);
}
// shift the struct
bool cpu_take_commit(vaddr_t *pc, uint32_t *instruction) {
  // pc && inst address is valid
  Assert(((pc != NULL) && (instruction != NULL)), "retirement consumer received a null inst / pc");
  if (!mailbox.occupied) return false;
  *pc = mailbox.pc;
  *instruction = mailbox.inst_word;
  mailbox.occupied = false;
  return true;
}

void cpu_reset(vaddr_t reset_pc) {
  Assert((reset_pc & 3u) == 0, "reset address is unaligned: " FMT_WORD, reset_pc);
  mailbox = {false, reset_pc, 0};
  memset(retire_history, 0, sizeof(retire_history));
  retire_history_pos = 0;
  memset(&cpu, 0, sizeof(cpu));
  cpu.pc = reset_pc;
  cpu.mstatus = MACHINE_MODE;
  cpu.mtvec = 1;
}
