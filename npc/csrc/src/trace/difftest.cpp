#include "common.h"
#include "mem.h"
#include "cpu.h"

#include <dlfcn.h>

enum { DIFFTEST_TO_DUT, DIFFTEST_TO_REF };
#define NR_GPR MUXDEF(RVE, 16, 32)
struct diff_context_t {
  word_t gpr[NR_GPR];
  word_t pc;
};

void (*ref_difftest_memcpy)(addr_t addr, void *buf, size_t n, bool direction) = NULL;
void (*ref_difftest_regcpy)(void *dut, bool direction) = NULL;
void (*ref_difftest_exec)(uint64_t n) = NULL;
void (*ref_difftest_raise_intr)(uint64_t NO) = NULL;

#ifdef DIFFTEST

static bool is_skip_ref = false;
static bool is_skip_ref_next = false;
static int skip_dut_nr_inst = 0;

static void difftest_regcpy() {
  diff_context_t ctx;
  for (int i = 0; i < NR_GPR; ++i) {
    ctx.gpr[i] = gpr(i);
  }
  ctx.pc = cpu_pc;
  ref_difftest_regcpy(&ctx, DIFFTEST_TO_REF);
}

void difftest_skip_ref() {
  is_skip_ref = true;
}

void difftest_skip_ref_next() {
  is_skip_ref_next = true;
}

void init_difftest(char *ref_so_file, long img_size) {
  assert(ref_so_file != NULL);

  void *handle;
  handle = dlopen(ref_so_file, RTLD_LAZY);
  assert(handle);

  ref_difftest_memcpy = (void (*)(addr_t addr, void *buf, size_t n, bool direction))dlsym(handle, "difftest_memcpy");
  assert(ref_difftest_memcpy);

  ref_difftest_regcpy = (void (*)(void *dut, bool direction))dlsym(handle, "difftest_regcpy");
  assert(ref_difftest_regcpy);

  ref_difftest_exec = (void (*)(uint64_t n))dlsym(handle, "difftest_exec");
  assert(ref_difftest_exec);

  ref_difftest_raise_intr = (void (*)(uint64_t NO))dlsym(handle, "difftest_raise_intr");
  assert(ref_difftest_raise_intr);

  void (*ref_difftest_init)(int) = (void (*)(int))dlsym(handle, "difftest_init");
  assert(ref_difftest_init);

  Log("Differential testing: %s", ANSI_FMT("ON", ANSI_FG_GREEN));
  Log("Difftest Ref: %s", ref_so_file);

  ref_difftest_init(1234);
#ifdef YSYXSOC
  ref_difftest_memcpy(FLASH_BASE, guest_to_host(FLASH_BASE), img_size, DIFFTEST_TO_REF);
#else
  ref_difftest_memcpy(MEM_BASE, guest_to_host(MEM_BASE), img_size, DIFFTEST_TO_REF);
#endif
  difftest_regcpy();
}

static bool checkregs(diff_context_t *ref) {
  for (int i = 0; i < NR_GPR; ++i) {
    if (ref->gpr[i] != gpr(i)) return false;
  }
  return ref->pc == cpu_pc;
}

static void display_ref(diff_context_t *ref) {
  word_t val;
  printf("----- reference cpu state -----\npc = " FMT_ADDR "\n", ref->pc);
  printf(
    MUXDEF(RV64, "%-3s %-18s %-20s %-20s\n", "%-3s %-10s %-12s %-12s\n"),
    "Reg", "Hex", "Unsigned dec", "Signed dec"
  );
  for (int i = 0; i < NR_GPR; ++i) {
    val = ref->gpr[i];
    printf(
      MUXDEF(RV64, "%-3s 0x%-16llx %-20llu %-20lld\n", "%-3s 0x%-8x %-12u %-12d\n"),
      reg_name(i), val, val, val
    );
  }
}

void difftest_step() {
  if (is_skip_ref) {
    difftest_regcpy();
    if (is_skip_ref_next) is_skip_ref_next = false;
    else is_skip_ref = false;
    return;
  }
  if (is_skip_ref_next) {
    is_skip_ref = true;
    is_skip_ref_next = false;
  }
  ref_difftest_exec(1);
  diff_context_t ref;
  ref_difftest_regcpy(&ref, DIFFTEST_TO_DUT);

  if (!checkregs(&ref)) {
    Log("Difftest failed");
    set_npc_state(NPC_ABORT, cpu_pc, 1);
    printf("----- npc state -----\npc = " FMT_ADDR "\n", cpu_pc);
    reg_display();
    display_ref(&ref);
  }
}
#else
void init_difftest(char *ref_so_file, long img_size) { }
#endif
