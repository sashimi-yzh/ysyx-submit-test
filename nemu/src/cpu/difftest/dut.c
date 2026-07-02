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

#include <isa.h>
#include <cpu/cpu.h>
#include <memory/paddr.h>
#include <utils.h>
#include <difftest-def.h>

void (*ref_difftest_memcpy)(paddr_t addr, void *buf, size_t n, bool direction) = NULL;
void (*ref_difftest_regcpy)(void *dut, bool direction) = NULL;
void (*ref_difftest_exec)(uint64_t n) = NULL;
void (*ref_difftest_raise_intr)(uint64_t NO) = NULL;

#ifdef CONFIG_DIFFTEST

static bool is_skip_ref = false;
static int skip_dut_nr_inst = 0;

// this is used to let ref skip instructions which
// can not produce consistent behavior with NEMU
void difftest_skip_ref() {
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

// this is used to deal with instruction packing in QEMU.
// Sometimes letting QEMU step once will execute multiple instructions.
// We should skip checking until NEMU's pc catches up with QEMU's pc.
// The semantic is
//   Let REF run `nr_ref` instructions first.
//   We expect that DUT will catch up with REF within `nr_dut` instructions.
void difftest_skip_dut(int nr_ref, int nr_dut) {
  Assert(nr_ref >= 0 && nr_dut >= 0,
      "bad difftest_skip_dut arguments: nr_ref=%d nr_dut=%d skip_dut_nr_inst=%d",
      nr_ref, nr_dut, skip_dut_nr_inst);
  skip_dut_nr_inst += nr_dut;

  while (nr_ref -- > 0) {
    ref_difftest_exec(1);
  }
}

void init_difftest(char *ref_so_file, long img_size, int port) {
  Assert(ref_so_file != NULL, "DiffTest is enabled but ref_so_file is NULL");
  Assert(img_size >= 0,
      "DiffTest image size is negative: img_size=%ld reset_vector=" FMT_PADDR,
      img_size, RESET_VECTOR);
  Assert((uint64_t)img_size <= (uint64_t)PMEM_RIGHT - (uint64_t)RESET_VECTOR + 1,
      "DiffTest image is too large: img_size=%ld reset_vector=" FMT_PADDR
      " pmem=[" FMT_PADDR ", " FMT_PADDR "]",
      img_size, RESET_VECTOR, PMEM_LEFT, PMEM_RIGHT);

  void *handle;
  handle = dlopen(ref_so_file, RTLD_LAZY);
  Assert(handle != NULL, "Can not open DiffTest reference '%s': %s",
      ref_so_file, dlerror());

  ref_difftest_memcpy = dlsym(handle, "difftest_memcpy");
  Assert(ref_difftest_memcpy, "Can not find DiffTest symbol 'difftest_memcpy'");

  ref_difftest_regcpy = dlsym(handle, "difftest_regcpy");
  Assert(ref_difftest_regcpy, "Can not find DiffTest symbol 'difftest_regcpy'");

  ref_difftest_exec = dlsym(handle, "difftest_exec");
  Assert(ref_difftest_exec, "Can not find DiffTest symbol 'difftest_exec'");

  ref_difftest_raise_intr = dlsym(handle, "difftest_raise_intr");
  Assert(ref_difftest_raise_intr, "Can not find DiffTest symbol 'difftest_raise_intr'");

  void (*ref_difftest_init)(int) = dlsym(handle, "difftest_init");
  Assert(ref_difftest_init, "Can not find DiffTest symbol 'difftest_init'");

  Log("Differential testing: %s", ANSI_FMT("ON", ANSI_FG_GREEN));
  Log("The result of every instruction will be compared with %s. "
      "This will help you a lot for debugging, but also significantly reduce the performance. "
      "If it is not necessary, you can turn it off in menuconfig.", ref_so_file);

  ref_difftest_init(port);
  ref_difftest_memcpy(RESET_VECTOR, guest_to_host(RESET_VECTOR), img_size, DIFFTEST_TO_REF);
  ref_difftest_regcpy(&cpu, DIFFTEST_TO_REF);
}

static void checkregs(CPU_state *ref, vaddr_t pc) {
  if (!isa_difftest_checkregs(ref, pc)) {
    nemu_state.state = NEMU_ABORT;
    nemu_state.halt_pc = pc;
    isa_reg_display();
  }
}

void difftest_step(vaddr_t pc, vaddr_t npc) {
  CPU_state ref_r;

  if (skip_dut_nr_inst > 0) {
    ref_difftest_regcpy(&ref_r, DIFFTEST_TO_DUT);
    Assert((ref_r.pc & 0x3) == 0,
        "DiffTest ref pc is unaligned while catching up: ref_pc=" FMT_WORD
        " dut_pc=" FMT_WORD " npc=" FMT_WORD,
        ref_r.pc, pc, npc);
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
    is_skip_ref = false;
    return;
  }

  ref_difftest_exec(1);
  ref_difftest_regcpy(&ref_r, DIFFTEST_TO_DUT);
  Assert((ref_r.pc & 0x3) == 0,
      "DiffTest ref pc is unaligned: ref_pc=" FMT_WORD " dut_pc=" FMT_WORD " npc=" FMT_WORD,
      ref_r.pc, pc, npc);

  checkregs(&ref_r, pc);
}
#else
void init_difftest(char *ref_so_file, long img_size, int port) { }
#endif
