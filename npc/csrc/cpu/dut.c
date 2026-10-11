#include<dlfcn.h>
#include "cpu/cpu.h"
#include "memory/pmem.h"
#include "include/debug.h"
#include "cpu/difftest.h"
#include "isa/reg.h"
void (*ref_difftest_memcpy)(uint32_t addr, void *buf, size_t n, bool direction) = NULL;
void (*ref_difftest_regcpy)(void *dut, bool direction) = NULL;
void (*ref_difftest_exec)(uint64_t n) = NULL;
void (*ref_difftest_raise_intr)(uint64_t NO) = NULL;

static int is_skip_ref = false;

extern "C" void difftest_skip_ref() {
  is_skip_ref = 1;
}


void init_difftest(const char *ref_so_file, long img_size) {
  assert(ref_so_file != NULL);
    printf("%s\n",ref_so_file);
  void *handle;
  handle = dlopen(ref_so_file, RTLD_LAZY);
  assert(handle);

  ref_difftest_memcpy = (void(*)(uint32_t addr, void *buf, size_t n, bool direction))dlsym(handle, "difftest_memcpy");
  assert(ref_difftest_memcpy);

  ref_difftest_regcpy = (void(*)(void *dut, bool direction))dlsym(handle, "difftest_regcpy");
  assert(ref_difftest_regcpy);

  ref_difftest_exec = (void(*)(uint64_t n))dlsym(handle, "difftest_exec");
  assert(ref_difftest_exec);

  ref_difftest_raise_intr = (void(*)(uint64_t NO))dlsym(handle, "difftest_raise_intr");
  assert(ref_difftest_raise_intr);

  void (*ref_difftest_init)(int) = (void (*)(int))dlsym(handle, "difftest_init");
  assert(ref_difftest_init);

  Log("Differential testing: ON");
  Log("The result of every instruction will be compared with %s. "
      "If it is not necessary, you can turn it off in menuconfig.", ref_so_file);

  ref_difftest_init(0);
#ifdef RISCV32E_NPC
  ref_difftest_memcpy(PSRAM_START, psram, img_size, DIFFTEST_TO_REF);//error need change
#else
  ref_difftest_memcpy(FLASH_START, flash, img_size, DIFFTEST_TO_REF);//error need change

#endif
  ref_difftest_regcpy(&cpu_dut, DIFFTEST_TO_REF);
}

static void checkregs(CPU_state *ref, uint32_t pc) {
  if (!isa_difftest_checkregs(ref,&cpu_dut)) {
    npc_state.state = NPC_ABORT;
    npc_state.halt_pc = pc;
    isa_reg_display(&cpu_dut);
  }
}

void difftest_step(uint32_t pc, uint32_t npc) {
  CPU_state ref_r;
  if (is_skip_ref>0) {
    // to skip the checking of an instruction, just copy the reg state to reference design
    ref_difftest_regcpy(&cpu_dut, DIFFTEST_TO_REF);
    is_skip_ref--;
    return;
  }

  ref_difftest_exec(1);
  ref_difftest_regcpy(&ref_r, DIFFTEST_TO_DUT);

  checkregs(&ref_r, pc);
}

