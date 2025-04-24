#include <dlfcn.h>
#include "common.h"
#include "utils.h"

enum { DIFFTEST_TO_DUT, DIFFTEST_TO_REF };

void (*ref_difftest_memcpy)(uint32_t addr, void *buf, size_t n, bool direction) = NULL;
void (*ref_difftest_regcpy)(void *dut, bool direction) = NULL;
void (*ref_difftest_exec)(uint64_t n) = NULL;
void (*ref_difftest_raise_intr)(uint64_t NO) = NULL;

static bool is_skip_ref = false;

// this is used to let ref skip instructions which
// can not produce consistent behavior with NEMU
void difftest_skip_ref() {
  is_skip_ref = true;
}

void init_difftest(const char *ref_so_file) {
  assert(ref_so_file != NULL);

  void *handle;
  handle = dlopen(ref_so_file, RTLD_LAZY);
  assert(handle);

  ref_difftest_memcpy = (void (*)(uint32_t, void*, size_t, bool))dlsym(handle, "difftest_memcpy");
  assert(ref_difftest_memcpy);

  ref_difftest_regcpy = (void (*)(void*, bool))dlsym(handle, "difftest_regcpy");
  assert(ref_difftest_regcpy);

  ref_difftest_exec = (void (*)(uint64_t))dlsym(handle, "difftest_exec");
  assert(ref_difftest_exec);

  ref_difftest_raise_intr = (void (*)(uint64_t))dlsym(handle, "difftest_raise_intr");
  assert(ref_difftest_raise_intr);

  void (*ref_difftest_init)(int) = (void (*)(int))dlsym(handle, "difftest_init");
  assert(ref_difftest_init);

  Log("Differential testing: %s", ANSI_FMT("ON", ANSI_FG_GREEN));
  Log("REF PATH = %s", ref_so_file);

  ref_difftest_init(0);
}

void difftest_sync(word_t *dut_r, void *mem, long img_size) {
  uint32_t reset_pc = dut_r[NR_REGS];
  ref_difftest_memcpy(reset_pc, mem, img_size, DIFFTEST_TO_REF);
  ref_difftest_regcpy(dut_r, DIFFTEST_TO_REF);
}

static const char *reg_name[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};

static bool difftest_check_reg(const char *name, uint32_t pc, word_t ref, word_t dut) {
  if (ref != dut) {
    printf("%s is different after executing instruction at pc = " FMT_WORD ", "
        "right = " FMT_WORD ", wrong = " FMT_WORD ", diff = " FMT_WORD "\n", name, pc, ref, dut, ref ^ dut);
    return false;
  }
  return true;
}

static bool checkregs(word_t *ref_r, word_t *dut_r, uint32_t thispc, uint32_t npc) {
  bool ok = true;
  if (memcmp(dut_r + 1, ref_r + 1, sizeof(ref_r[0]) * (NR_REGS - 1))) {
    for (int i = 1; i < NR_REGS; i ++) { // do not check $0
      ok &= difftest_check_reg(reg_name[i], thispc, ref_r[i], dut_r[i]);
    }
  }
  ok &= difftest_check_reg("pc", thispc, ref_r[NR_REGS], npc);
  if (!ok) {
    for (int i = 0; i < NR_REGS; i ++) {
      printf("%s: " FMT_WORD " ", reg_name[i], dut_r[i]);
      if (i % 4 == 3) printf("\n");
    }
  }
  return ok;
}

bool difftest_step(void *dut_r, uint32_t thispc, uint32_t npc) {
  word_t regs[NR_REGS + 1]; // GPRs + PC

  if (is_skip_ref) {
    // to skip the checking of an instruction, just copy the reg state to reference design
    memcpy(regs, dut_r, sizeof(word_t) * NR_REGS);
    regs[NR_REGS] = npc;
    ref_difftest_regcpy(regs, DIFFTEST_TO_REF);
    is_skip_ref = false;
    return true;
  }

  ref_difftest_exec(1);
  ref_difftest_regcpy(regs, DIFFTEST_TO_DUT);

  return checkregs(regs, (word_t *)dut_r, thispc, npc);
}
