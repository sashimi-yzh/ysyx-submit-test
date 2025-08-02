#include <dlfcn.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

#include "VysyxSoCFull.h"
#include "VysyxSoCFull___024root.h"
#include "memory.h"
#include "config.h"

enum { DIFFTEST_TO_DUT, DIFFTEST_TO_REF };

void (*ref_difftest_memcpy)(uint32_t addr, void *buf, size_t n, bool direction) = NULL;
void (*ref_difftest_regcpy)(void *dut, bool direction) = NULL;
void (*ref_difftest_exec)(uint64_t n) = NULL;
void (*ref_difftest_raise_intr)(uint64_t NO) = NULL;

extern  VysyxSoCFull *top 			    ;
extern  uint8_t pmem[0x8000000];
extern  uint8_t flash[0x1000000];

typedef struct {
  #ifdef ysyx_23060299_E_EXTENSION
  uint32_t gpr[16];
  #else
  uint32_t gpr[32];
  #endif
  uint32_t pc;
} riscv32_CPU_state;

void init_difftest(char *ref_so_file, long img_size, int port) {
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

  printf("ysyx_23060299_NPC Differential testing: ON\n");
  printf("The result of every instruction will be compared with %s. "
      "This will help you a lot for debugging, but also significantly reduce the performance. \n", ref_so_file);

  // init nemu PC, Regs, Memory 
  ref_difftest_init(port);
  ref_difftest_memcpy(RESET_VECTOR, flash, img_size, DIFFTEST_TO_REF);
  // ref_difftest_memcpy(RESET_VECTOR, pmem, img_size, DIFFTEST_TO_REF);

  riscv32_CPU_state npc;
  npc.pc = top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__IFU__DOT__pc;
  npc.gpr[0] = 0;
  #ifdef ysyx_23060299_E_EXTENSION
  for(uint8_t i = 1; i < 16; i++) {
  #else
  for(uint8_t i = 1; i < 32; i++) {
  #endif
    npc.gpr[i] = top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__RegisterFile__DOT__reg_files[i - 1];
  }
  ref_difftest_regcpy(&npc, DIFFTEST_TO_REF);
}
