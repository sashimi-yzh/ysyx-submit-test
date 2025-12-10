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
#include "../../include/common.h"

enum
{
  DIFFTEST_TO_DUT,
  DIFFTEST_TO_REF
};

void (*ref_difftest_memcpy)(uint32_t addr, void *buf, size_t n, bool direction) = NULL;
void (*ref_difftest_regcpy)(void *dut, bool direction) = NULL;
void (*ref_difftest_exec)(uint64_t n) = NULL;
void (*ref_difftest_raise_intr)(uint32_t NO) = NULL;
void (*ref_difftest_instcheck)(uint32_t dut_pc, uint32_t *ref_inst) = NULL;
void init_difftest(char *ref_so_file, long img_size, int port)
{
  CPU_state cpu;
  for (size_t i = 0; i < REG_NUM; i++)
  {
    cpu.gpr[i] = get_reg(i);
  }
  cpu.pc = RESET_VECTOR;

  assert(ref_so_file != NULL);

  void *handle;
  handle = dlopen(ref_so_file, RTLD_LAZY);
  assert(handle);

  ref_difftest_memcpy = (void (*)(uint32_t, void *, size_t, bool))dlsym(handle, "difftest_memcpy");
  assert(ref_difftest_memcpy);

  ref_difftest_regcpy = (void (*)(void *, bool))dlsym(handle, "difftest_regcpy");
  assert(ref_difftest_regcpy);

  ref_difftest_exec = (void (*)(uint64_t))dlsym(handle, "difftest_exec");
  assert(ref_difftest_exec);

  ref_difftest_raise_intr = (void (*)(uint32_t))dlsym(handle, "difftest_raise_intr");
  assert(ref_difftest_raise_intr);

  ref_difftest_instcheck = (void (*)(uint32_t, uint32_t *))dlsym(handle, "difftest_instcheck");
  assert(ref_difftest_instcheck);

  void (*ref_difftest_init)(int) = (void (*)(int))dlsym(handle, "difftest_init");
  assert(ref_difftest_init);

  Log("每一条指令的结果将与 %s 进行比较. "
      "这将帮助你调试, 但是运行会比较慢. "
      "你可以在common.h中去关闭这个功能. ", ref_so_file);

  ref_difftest_init(port);
  ref_difftest_memcpy(RESET_VECTOR, imem, img_size, DIFFTEST_TO_REF);
  ref_difftest_regcpy(&cpu, DIFFTEST_TO_REF);
}

static void printf_ref_regs(CPU_state *ref)
{
  printf(ANSI_FMT("ref的寄存器状态如下:\n", ANSI_FG_MAGENTA));
  for (size_t i = 0; i < REG_NUM; i++)
  {
    printf("ref[%2lu] : 0x%8x\n", i, ref->gpr[i]);
  }
  printf("ref[16] : 0x%8x\n", ref->pc);
}

static void checkregs(CPU_state *ref)
{
  if (!isa_difftest_checkregs(ref))
  {
    printf_ref_regs(ref);
    printf_regs();
    Assert(0, "寄存器检查不通过\n");
  }
}

static void checkinst()
{
  uint32_t dut_pc = SOC_PC;
  uint32_t ref_inst;
  ref_difftest_instcheck(dut_pc, &ref_inst);
  if (ref_inst != SOC_INST) {
    Log("dut_pc = 0x%08x, ref_inst = 0x%08x, dut_inst = 0x%08x\n", dut_pc, ref_inst, SOC_INST);
    Assert(0 ,ANSI_FMT("指令检查不通过! \n", ANSI_FG_RED));
  }
}
bool if_skip = false;
void difftest_step()
{
  if (if_skip) {
    CPU_state dut_r;
    for (size_t i = 0; i < REG_NUM; i++)
    {
      dut_r.gpr[i] = get_reg(i);
    }
    dut_r.pc = SOC_NPC;
    ref_difftest_regcpy(&dut_r, DIFFTEST_TO_REF);
  } else {
    CPU_state ref_r;
    ref_difftest_exec(1);
    ref_difftest_regcpy(&ref_r, DIFFTEST_TO_DUT);
    checkregs(&ref_r);
  }
  checkinst();
  if_skip = false;
}