#include <dlfcn.h>
#include "../include/common.h"
#include "../include/switch.h"
#include "../include/difftest-def.h"
#include "../include/memory.h"
#include "../include/reg.h"

#ifdef CONFIG_YSYXSOC
#include "VysyxSoCFull___024root.h"
#include "VysyxSoCFull.h"
extern VysyxSoCFull *top;
#define dut_pc top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__diff_pc
#define dut_gpr top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu_cpu__DOT__regs
#define dut_mtvec top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu_cpu__DOT__mtvec
#define dut_mepc top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu_cpu__DOT__mepc
#define dut_mcause top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu_cpu__DOT__mcause
#define dut_mstatus top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu_cpu__DOT__mstatus
#else
#include "Vysyx_25020037_npc___024root.h"
#include "Vysyx_25020037_npc.h"
extern Vysyx_25020037_npc *top;
#define dut_pc top->rootp->ysyx_25020037_npc__DOT__cpu__DOT__diff_pc
#define dut_gpr top->rootp->ysyx_25020037_npc__DOT__cpu__DOT__wbu_cpu__DOT__regs
#define dut_mtvec top->rootp->ysyx_25020037_npc__DOT__cpu__DOT__wbu_cpu__DOT__mtvec
#define dut_mepc top->rootp->ysyx_25020037_npc__DOT__cpu__DOT__wbu_cpu__DOT__mepc
#define dut_mcause top->rootp->ysyx_25020037_npc__DOT__cpu__DOT__wbu_cpu__DOT__mcause
#define dut_mstatus top->rootp->ysyx_25020037_npc__DOT__cpu__DOT__wbu_cpu__DOT__mstatus
#endif

void (*ref_difftest_memcpy)(paddr_t addr, void *buf, size_t n, bool direction) = NULL;
void (*ref_difftest_regcpy)(void *dut, bool direction) = NULL;
void (*ref_difftest_exec)(uint64_t n) = NULL;
void (*ref_difftest_raise_intr)(uint64_t NO) = NULL;

diff_context_t* ref_r = (diff_context_t*)malloc(sizeof(diff_context_t));

static bool is_skip_ref = false;
static int skip_dut_nr_inst = 0;

extern "C" void difftest_skip_ref() {
  is_skip_ref = true;
  skip_dut_nr_inst = 0;
}

#ifdef CONFIG_DIFFTEST

void difftest_skip_dut(int nr_ref, int nr_dut) {
  skip_dut_nr_inst += nr_dut;

  while (nr_ref -- > 0) {
    ref_difftest_exec(1);
  }
}

void init_difftest(char *ref_so_file, long img_size, int port) {
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
  printf("\x1B[34mThe result of every instruction will be compared with \x1B[1m\x1B[33m%s\x1B[0m. "
           "This will help you a lot for debugging, but also significantly reduce the performance. "
           "If it is not necessary, you can turn it off in switch.h\n\x1B[0m", ref_so_file);

  ref_difftest_init(port);
#ifdef CONFIG_YSYXSOC
  ref_difftest_memcpy(FLASH_RESET_VECTOR, SoC_to_host(FLASH_RESET_VECTOR), img_size, DIFFTEST_TO_REF);
  diff_context_t* dut_r = (diff_context_t*)malloc(sizeof(diff_context_t));
  for(int i = 0; i < 16; i++){
    dut_r->gpr[i] = dut_gpr[i];
  }
  dut_r->pc      = FLASH_RESET_VECTOR;
  dut_r->mtvec   = dut_mtvec;
  dut_r->mepc    = dut_mepc;
  dut_r->mcause  = dut_mcause;
  dut_r->mstatus = dut_mstatus;
  ref_difftest_regcpy(dut_r, DIFFTEST_TO_REF);
#else
  ref_difftest_memcpy(RESET_VECTOR, guest_to_host(RESET_VECTOR), img_size, DIFFTEST_TO_REF);
  diff_context_t* dut_r = (diff_context_t*)malloc(sizeof(diff_context_t));
  for(int i = 0; i < 16; i++){
    dut_r->gpr[i] = dut_gpr[i];
  }
  dut_r->pc      = RESET_VECTOR;
  dut_r->mtvec   = dut_mtvec;
  dut_r->mepc    = dut_mepc;
  dut_r->mcause  = dut_mcause;
  dut_r->mstatus = dut_mstatus;
  ref_difftest_regcpy(dut_r, DIFFTEST_TO_REF);
#endif
}

static void checkregs(diff_context_t *ref, vaddr_t pc) {
  if (!isa_difftest_checkregs(ref, pc)) {
    NPC_STATE = NPC_ABORT;
    isa_reg_display();
  }
}

void difftest_step(vaddr_t pc) {

  if (is_skip_ref) {
    diff_context_t* dut_r = (diff_context_t*)malloc(sizeof(diff_context_t));
    for(int i = 0; i < 16; i++){
      dut_r->gpr[i] = dut_gpr[i];
    }
    dut_r->pc      = dut_pc+4;
    dut_r->mtvec   = dut_mtvec;
    dut_r->mepc    = dut_mepc;
    dut_r->mcause  = dut_mcause;
    dut_r->mstatus = dut_mstatus;
    ref_difftest_regcpy(dut_r, DIFFTEST_TO_REF);
    is_skip_ref = false;
    return;
  }
  ref_difftest_exec(1);

  ref_difftest_regcpy(ref_r, DIFFTEST_TO_DUT);
  checkregs(ref_r, pc);
}
#else
void init_difftest(char *ref_so_file, long img_size, int port) { }
#endif
