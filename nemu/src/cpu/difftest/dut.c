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
void (*ref_difftest_getinst)(void *dut) = NULL;
void (*ref_difftest_get_store_event)(void *dut) = NULL;
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

  ref_difftest_memcpy = dlsym(handle, "difftest_memcpy");
  assert(ref_difftest_memcpy);

  ref_difftest_regcpy = dlsym(handle, "difftest_regcpy");
  assert(ref_difftest_regcpy);

  ref_difftest_exec = dlsym(handle, "difftest_exec");
  assert(ref_difftest_exec);

  ref_difftest_raise_intr = dlsym(handle, "difftest_raise_intr");
  assert(ref_difftest_raise_intr);

  ref_difftest_getinst = dlsym(handle, "difftest_getinst");
  assert(ref_difftest_getinst);

  ref_difftest_get_store_event = dlsym(handle, "difftest_get_store_event");
  assert(ref_difftest_get_store_event);

  void (*ref_difftest_init)(int) = dlsym(handle, "difftest_init");
  assert(ref_difftest_init);

  Log("Differential testing: %s", ANSI_FMT("ON", ANSI_FG_GREEN));
  Log("The result of every instruction will be compared with %s. "
      "This will help you a lot for debugging, but also significantly reduce the performance. "
      "If it is not necessary, you can turn it off in menuconfig.", ref_so_file);

  ref_difftest_init(port);
  ref_difftest_memcpy(RESET_VECTOR, guest_to_host(RESET_VECTOR), img_size, DIFFTEST_TO_REF);
  ref_difftest_regcpy(&cpu, DIFFTEST_TO_REF);
}

static void printf_ref_regs(CPU_state *ref)
{
  printf(ANSI_FMT("ref的寄存器状态如下:\n", ANSI_FG_MAGENTA));
  for (size_t i = 0; i < MUXDEF(CONFIG_RVE, 16, 32); i++)
  {
    printf("x%2lu     : 0x%8x\n", i, ref->gpr[i]);
  }
  printf("PC      : 0x%8x\n", ref->pc);
}

static void checkinst(word_t ref_inst, word_t pc) {
	Assert(ref_inst == paddr_read(pc, 4), "inst值的difftest检查不通过，发生在pc = 0x%8x, dut: %08x, ref: %08x", pc, paddr_read(pc, 4), ref_inst);
}

static void checkregs(CPU_state *ref, vaddr_t pc) {
	if (!isa_difftest_checkregs(ref,pc)) {
		nemu_state.state = NEMU_ABORT;
		nemu_state.halt_pc = pc;
		printf_ref_regs(ref);
		isa_reg_display();
  }
}

static void checkstore(mem_info_t *ref_mem, word_t pc) {
  if(ref_mem->type == 2) {
    Assert(ref_mem->type == nemu_mem_info.type, "store的difftest检查不通过，发生在pc = 0x%8x, dut: %d, ref %d, 访存类型不一致", pc, nemu_mem_info.type, ref_mem->type);
    Assert(ref_mem->vaddr == nemu_mem_info.vaddr,"store的difftest检查不通过，发生在pc = 0x%8x, dut: %8x, ref %8x, 访存地址不一致", pc, nemu_mem_info.vaddr, ref_mem->vaddr);
    Assert(ref_mem->data == nemu_mem_info.data,"store的difftest检查不通过，发生在pc = 0x%8x, dut: %8x, ref %8x, 访存数据不一致", pc, nemu_mem_info.data, ref_mem->data);
    Assert(ref_mem->len == nemu_mem_info.len,"store的difftest检查不通过，发生在pc = 0x%8x, dut: %d, ref %d, 访存长度不一致", pc, nemu_mem_info.len, ref_mem->len);
  }
}

void difftest_step(vaddr_t pc, vaddr_t npc) {
  CPU_state ref_r;
  word_t ref_inst;
  mem_info_t ref_mem;
	// printf("skip_dut_nr_inst = %d\n",skip_dut_nr_inst);
	if (skip_dut_nr_inst > 0) {
		ref_difftest_regcpy(&ref_r, DIFFTEST_TO_DUT);
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

	// printf("is_skip_ref = %d", is_skip_ref);
	if (is_skip_ref) {
		// to skip the checking of an instruction, just copy the reg state to reference design
		ref_difftest_regcpy(&cpu, DIFFTEST_TO_REF);
		is_skip_ref = false;
		return;
	}

	ref_difftest_getinst(&ref_inst);
	ref_difftest_exec(1);
	ref_difftest_regcpy(&ref_r, DIFFTEST_TO_DUT);
  ref_difftest_get_store_event(&ref_mem);
	checkinst(ref_inst, pc);
	checkregs(&ref_r, pc);
  checkstore(&ref_mem, pc);
}
#else
void init_difftest(char *ref_so_file, long img_size, int port) { }
#endif
