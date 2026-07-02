#include <cpu/cpu.h>
#include <isa.h>

enum {
  MSTATUS_MIE  = (1u << 3),
  MSTATUS_MPIE = (1u << 7),
  MSTATUS_MPP  = (3u << 11),
};

static bool commit_valid = false;
static vaddr_t commit_pc = 0;
static uint32_t commit_inst = 0;

static bool program_has_ended() {
  return npc_state.state == NPC_END || npc_state.state == NPC_ABORT || npc_state.state == NPC_QUIT;
}

extern "C" void npc_commit(
    uint32_t retired_pc,
    uint32_t retired_inst,
    uint32_t pc,
    uint32_t mstatus,
    uint32_t mtvec,
    uint32_t mepc,
    uint32_t mcause,
    const uint32_t *gpr
) {
  if (program_has_ended()) return;
  Assert(!commit_valid,
      "DPI commit overwrites an unconsumed commit: old_pc=" FMT_WORD
      " new_pc=" FMT_WORD " new_inst=0x%08x",
      commit_pc, retired_pc, retired_inst);
  Assert(gpr != NULL, "DPI commit with null GPR pointer: pc=" FMT_WORD " inst=0x%08x",
      retired_pc, retired_inst);
  Assert((retired_pc & 0x3) == 0 && (pc & 0x3) == 0,
      "DPI commit pc is unaligned: retired_pc=" FMT_WORD " pc=" FMT_WORD
      " inst=0x%08x",
      retired_pc, pc, retired_inst);
  if (retired_inst == 0x00000073) {
    Assert(mepc == retired_pc && mcause == 11 && pc == (mtvec & ~0x3u)
        && (mstatus & MSTATUS_MIE) == 0 && (mstatus & MSTATUS_MPP) == MSTATUS_MPP,
        "bad ecall commit state: retired_pc=" FMT_WORD " pc=" FMT_WORD
        " inst=0x%08x mstatus=" FMT_WORD " mtvec=" FMT_WORD
        " mepc=" FMT_WORD " mcause=" FMT_WORD,
        retired_pc, pc, retired_inst, mstatus, mtvec, mepc, mcause);
  } else if (retired_inst == 0x30200073) {
    Assert(pc == mepc && (mstatus & MSTATUS_MPIE) != 0 && (mstatus & MSTATUS_MPP) == 0,
        "bad mret commit state: retired_pc=" FMT_WORD " pc=" FMT_WORD
        " inst=0x%08x mstatus=" FMT_WORD " mepc=" FMT_WORD,
        retired_pc, pc, retired_inst, mstatus, mepc);
  }

  commit_valid = true;
  commit_pc = retired_pc;
  commit_inst = retired_inst;

  for (int i = 0; i < 32; i++) cpu.gpr[i] = gpr[i];
  cpu.pc = pc;
  cpu.mstatus = mstatus;
  cpu.mtvec = mtvec;
  cpu.mepc = mepc;
  cpu.mcause = mcause;

  if (retired_inst == 0x00100073) {
    npc_state.state = NPC_END;
    npc_state.halt_pc = retired_pc;
    npc_state.halt_ret = cpu.gpr[10];
  }
}

bool npc_fetch_commit(vaddr_t *pc, uint32_t *inst) {
  Assert(pc != NULL && inst != NULL, "npc_fetch_commit with null output: pc=%p inst=%p",
      pc, inst);
  if (!commit_valid) return false;
  *pc = commit_pc;
  *inst = commit_inst;
  commit_valid = false;
  return true;
}

void npc_reset_commit_state(vaddr_t pc) {
  Assert((pc & 0x3) == 0, "reset commit pc is unaligned: pc=" FMT_WORD, pc);
  commit_valid = false;
  commit_pc = pc;
  commit_inst = 0;
  memset(&cpu, 0, sizeof(cpu));
  cpu.pc = pc;
  cpu.mstatus = 0x1800;
  cpu.mtvec = 1;
}
