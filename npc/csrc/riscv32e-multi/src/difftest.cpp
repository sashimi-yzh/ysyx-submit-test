#include <dlfcn.h>
#include <common.h>
#include <dpi-c.h>
void (*ref_difftest_memcpy)(paddr_t addr, void *buf, size_t n, bool direction) = NULL;
void (*ref_difftest_regcpy)(void *dut, bool direction) = NULL;
void (*ref_difftest_mtimecpy)(void *dut) = NULL;
void (*ref_difftest_exec)(uint64_t n) = NULL;
void (*ref_difftest_raise_intr)(uint64_t NO) = NULL;

void init_difftest(char *ref_so_file, long img_size, int port) {
#ifdef DIFFTEST_COND
  assert(ref_so_file != NULL);

  void *handle;
  handle = dlopen(ref_so_file, RTLD_LAZY);
  assert(handle);

  ref_difftest_memcpy = (void (*)(paddr_t addr, void *buf, size_t n, bool direction))dlsym(handle, "difftest_memcpy");
  assert(ref_difftest_memcpy);

  ref_difftest_regcpy = (void (*)(void *dut, bool direction))dlsym(handle, "difftest_regcpy");
  assert(ref_difftest_regcpy);

  ref_difftest_exec = (void (*)(uint64_t n))dlsym(handle, "difftest_exec");
  assert(ref_difftest_exec);

  ref_difftest_raise_intr = (void (*)(uint64_t NO))dlsym(handle, "difftest_raise_intr");
  assert(ref_difftest_raise_intr);

  void (*ref_difftest_init)(int) = (void (*)(int))dlsym(handle, "difftest_init");
  assert(ref_difftest_init);

  ref_difftest_init(port);
  ref_difftest_memcpy(0x30000000, flash, img_size, DIFFTEST_TO_REF);
  CPU_state ref_r;
  for(int i = 0;i<16;i++) ref_r.gpr[i] = 0;
  ref_r.pc = get_pc();
  ref_r.mcause = 0;
  ref_r.mepc = 0;
  ref_r.mtvec = 0;
  ref_r.marchid = 0x018CE197;
  ref_r.mstatus = 0x1800;
  ref_r.mvendorid = 0x79737978;
  ref_difftest_regcpy(&ref_r, DIFFTEST_TO_REF);
#endif
}

bool difftest_skip_ref = false;

void difftest_step(word_t pc, word_t cur_pc) {
#ifdef DIFFTEST_COND
  CPU_state ref_r;
  if(difftest_skip_ref) {
    for(int i = 0;i<16;i++) ref_r.gpr[i] = get_regs(i);
    ref_r.mcause = get_csrs(CSR_MCAUSE);
    ref_r.mepc = get_csrs(CSR_MEPC);
    ref_r.mtvec = get_csrs(CSR_MTVEC);
    ref_r.marchid = get_csrs(CSR_MARCHID);
    ref_r.mstatus = get_csrs(CSR_MSTATUS);
    ref_r.mvendorid = get_csrs(CSR_MVENDORID);
    ref_r.pc = get_pc();
    ref_difftest_regcpy(&ref_r, DIFFTEST_TO_REF);
  }
  else {
    ref_difftest_exec(1);
    ref_difftest_regcpy(&ref_r, DIFFTEST_TO_DUT);
    for(int i = 0; i <16; i++){
      if(get_regs(i) != ref_r.gpr[i]) {
        printf(ANSI_FMT("npc difftest halt pc: 0x%08x\n", ANSI_FG_RED), cur_pc);
        printf(ANSI_FMT("regs[%d] expected: 0x%08x yours: 0x%08x\n", ANSI_FG_RED), i, ref_r.gpr[i], get_regs(i));
        npc_state = NPC_ABORT;
        return ;
      }
    }
    if(pc != ref_r.pc) {
      printf(ANSI_FMT("npc difftest halt pc: 0x%08x\n", ANSI_FG_RED), cur_pc);
      printf(ANSI_FMT("pc expected: 0x%08x yours: 0x%08x\n", ANSI_FG_RED), ref_r.pc, pc);
      npc_state = NPC_ABORT;
      return ;
    }
    if(get_csrs(CSR_MEPC) != ref_r.mepc) {
      printf(ANSI_FMT("npc difftest halt pc: 0x%08x\n", ANSI_FG_RED), cur_pc);
      printf(ANSI_FMT("mepc expected: 0x%08x yours: 0x%08x\n", ANSI_FG_RED), ref_r.mepc, get_csrs(CSR_MEPC));
      npc_state = NPC_ABORT;
      return ;
    }
    if(get_csrs(CSR_MSTATUS) != ref_r.mstatus) {
      printf(ANSI_FMT("npc difftest halt pc: 0x%08x\n", ANSI_FG_RED), cur_pc);
      printf(ANSI_FMT("mstatus expected: 0x%08x yours: 0x%08x\n", ANSI_FG_RED), ref_r.mstatus, get_csrs(CSR_MSTATUS));
      npc_state = NPC_ABORT;
      return ;
    }
    if(get_csrs(CSR_MCAUSE) != ref_r.mcause) {
      printf(ANSI_FMT("npc difftest halt pc: 0x%08x\n", ANSI_FG_RED), cur_pc);
      printf(ANSI_FMT("mcause expected: 0x%08x yours: 0x%08x\n", ANSI_FG_RED), ref_r.mcause, get_csrs(CSR_MCAUSE));
      npc_state = NPC_ABORT;
      return ;
    }
    if(get_csrs(CSR_MTVEC) != ref_r.mtvec) {
      printf(ANSI_FMT("npc difftest halt pc: 0x%08x\n", ANSI_FG_RED), cur_pc);
      printf(ANSI_FMT("mtvec expected: 0x%08x yours: 0x%08x\n", ANSI_FG_RED), ref_r.mtvec, get_csrs(CSR_MTVEC));
      npc_state = NPC_ABORT;
      return ;
    }
  }
  difftest_skip_ref = false;
#endif
}