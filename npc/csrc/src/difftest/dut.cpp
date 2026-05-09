/***************************************************************************************
* Copyright (c) 2014-2024 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include <dlfcn.h>

// #include <isa.h>
#include <cpu/cpu.h>
#include <paddr.h>
#include <utils.h>
#include "svdpi.h"
#include "Vnpc_top__Dpi.h"
#include <cpu/difftest.h>
// #include <difftest-def.h>

void (*ref_difftest_memcpy)(paddr_t addr, void *buf, size_t n, bool direction) = NULL;
void (*ref_difftest_regcpy)(void *dut, bool direction) = NULL;
void (*ref_difftest_exec)(uint64_t n) = NULL;
// void (*ref_difftest_raise_intr)(uint64_t NO) = NULL;

enum { DIFFTEST_TO_DUT, DIFFTEST_TO_REF };

#ifdef CONFIG_DIFFTEST

static bool is_skip_ref = false;
// static bool load_skip = false; // load需要延迟一个skip
static int skip_dut_nr_inst = 0;


bool isa_difftest_checkregs(NPC_state *ref_r, vaddr_t pc) {

  // printf("%08x %08x %08x\n", pc, ref_r->pc, cpu.pc);
  if(cpu.pc != ref_r->pc){
    printf("41 %08x, %08x\n", cpu.pc, ref_r->pc);
    return false;
  }
  for (int i = 0; i < 16; i++) {
    if (cpu.reg[i] != ref_r->reg[i]){
      printf("46 %d %08x, %08x\n", i, cpu.reg[i], ref_r->reg[i]);
      return false;
    }
    else{
      continue;
    }
  }
  return true;
}

// this is used to let ref skip instructions which
// can not produce consistent behavior with NEMU
extern "C" void difftest_skip_ref() {
  is_skip_ref = true;
  // If such an instruction is one of the instruction packing in QEMU
  // (see below), we end the process of catching up with QEMU's pc to
  // keep the consistent behavior in our best.
  // Note that this is still not perfect: if the packed instructions
  // already write some memory, and the incoming instruction in NEMU
  // will load that memory, we will encounter false negative. But such
  // situation is infrequent.
  skip_dut_nr_inst = 0;
}

// void difftest_skip_load() {
//   load_skip = true;

//   skip_dut_nr_inst = 0;
// }

// this is used to deal with instruction packing in QEMU.
// Sometimes letting QEMU step once will execute multiple instructions.
// We should skip checking until NEMU's pc catches up with QEMU's pc.
// The semantic is
//   Let REF run `nr_ref` instructions first.
//   We expect that DUT will catch up with REF within `nr_dut` instructions.
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

  ref_difftest_memcpy = (void (*)(paddr_t, void*, size_t, bool))dlsym(handle, "difftest_memcpy");
  assert(ref_difftest_memcpy);

  ref_difftest_regcpy = (void (*)(void*, bool))dlsym(handle, "difftest_regcpy");
  assert(ref_difftest_regcpy);

  ref_difftest_exec = (void (*)(uint64_t))dlsym(handle, "difftest_exec");
  assert(ref_difftest_exec);

  // ref_difftest_raise_intr = (void (*)(word_t))dlsym(handle, "difftest_raise_intr");
  // assert(ref_difftest_raise_intr);

  void (*ref_difftest_init)(int) = (void (*)(int))dlsym(handle, "difftest_init");
  assert(ref_difftest_init);

  Log("Differential testing: %s", ANSI_FMT("ON", ANSI_FG_GREEN));
  Log("The result of every instruction will be compared with %s. "
      "This will help you a lot for debugging, but also significantly reduce the performance. "
      "If it is not necessary, you can turn it off in menuconfig.", ref_so_file);

  ref_difftest_init(port);
  ref_difftest_memcpy(RESET_VECTOR, guest_to_host(RESET_VECTOR), img_size, DIFFTEST_TO_REF);
  ref_difftest_regcpy(&cpu, DIFFTEST_TO_REF);
}

static void checkregs(NPC_state *ref, vaddr_t pc) {
  if (!isa_difftest_checkregs(ref, pc)) {
    npc_state.state = NPC_ABORT;
    npc_state.halt_pc = pc;
    reg_display();
  }
}

void difftest_step(vaddr_t pc, vaddr_t npc) { // pc dnpc
  NPC_state ref_r;

  if (skip_dut_nr_inst > 0) {
    ref_difftest_regcpy(&ref_r, DIFFTEST_TO_DUT); // riscv32 0
    if (ref_r.pc == npc) {
      skip_dut_nr_inst = 0;
      checkregs(&ref_r, npc);
      return;
    }
    skip_dut_nr_inst --;
    if (skip_dut_nr_inst == 0)
      panic("can not catch up with ref.pc = " FMT_WORD " at pc = " FMT_WORD, ref_r.pc, pc);
    return;
  }

  if (is_skip_ref) {
    // to skip the checking of an instruction, just copy the reg state to reference design
    ref_difftest_regcpy(&cpu, DIFFTEST_TO_REF);
    // printf("skip\n");
    is_skip_ref = false;
    return;
  }

  // printf("155 ref_r.pc = %08x\n", ref_r.pc);
  ref_difftest_exec(1);
  ref_difftest_regcpy(&ref_r, DIFFTEST_TO_DUT);

  checkregs(&ref_r, pc);
}
#else
void init_difftest(char *ref_so_file, long img_size, int port) { }
// static inline void difftest_skip_ref() { }
#endif


  // ref_difftest_regcpy(&ref_r, DIFFTEST_TO_DUT);
  // printf("pc = %08x, ref_pc = %08x\n", pc, ref_r.pc);

  // if (is_skip_ref) {
  //   ref_difftest_regcpy(&cpu, DIFFTEST_TO_REF);
  //   if(load_skip){
  //     is_skip_ref = true;
  //     load_skip = false;
  //   }
  //   else{
  //     is_skip_ref = false;
  //   }
  //   return;
  // }
  


  // if(load_skip) {
  //   is_skip_ref = true;
  //   load_skip = false;
  // }