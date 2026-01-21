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
void (*ref_difftest_get_store)(void *dut) = NULL;
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
  
  ref_difftest_get_store = (void (*)(void *))dlsym(handle, "difftest_get_store");
  assert(ref_difftest_get_store);

  void (*ref_difftest_init)(int) = (void (*)(int))dlsym(handle, "difftest_init");
  assert(ref_difftest_init);


  Log("每一条指令的结果将与 %s 进行比较. ", ref_so_file);

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
  }
}

static void checkinst()
{
  uint32_t dut_pc = SOC_PC;
  uint32_t ref_inst;
  ref_difftest_instcheck(dut_pc, &ref_inst);
  Assert(ref_inst == SOC_INST, ANSI_FMT("inst值的difftest检查不通过，发生在pc = 0x%8x, dut: %08x, ref: %08x", ANSI_FG_RED), dut_pc, SOC_INST, ref_inst);
}

static void checkstore()
{
  uint32_t dut_pc = SOC_PC;
  mem_info_t ref_mem_r;
  ref_difftest_get_store(&ref_mem_r);
  if(ref_mem_r.type == 2) {
    Assert(ref_mem_r.type == npc_mem_info.type, "store的difftest检查不通过，发生在pc = 0x%8x, dut: %d, ref %d, 访存类型不一致", dut_pc, npc_mem_info.type, ref_mem_r.type);
    Assert(ref_mem_r.vaddr == npc_mem_info.vaddr,"store的difftest检查不通过，发生在pc = 0x%8x, dut: %8x, ref %8x, 访存地址不一致", dut_pc, npc_mem_info.vaddr, ref_mem_r.vaddr);
    Assert(ref_mem_r.data == npc_mem_info.data,"store的difftest检查不通过，发生在pc = 0x%8x, dut: %8x, ref %8x, 访存数据不一致", dut_pc, npc_mem_info.data, ref_mem_r.data);
    Assert(ref_mem_r.len == npc_mem_info.len,"store的difftest检查不通过，发生在pc = 0x%8x, dut: %d, ref %d, 访存长度不一致", dut_pc, npc_mem_info.len, ref_mem_r.len);
  }
}

bool if_skip = false;

/* difftest三步走：
1. 检查指令是否一致
2. 检查pc，gpr以及白名单上的csr是否一致
3. 判断访存指令，检查访存数据，访存地址，访存长度是否一致
 */
void difftest_step()
{
  CPU_state ref_r;
  
  checkinst();
  if (if_skip) {
    CPU_state dut_r;
    for (size_t i = 0; i < REG_NUM; i++)
    {
      dut_r.gpr[i] = get_reg(i);
    }
    dut_r.pc = SOC_NPC;
    ref_difftest_regcpy(&dut_r, DIFFTEST_TO_REF);
    return;
  }
  ref_difftest_exec(1);
  ref_difftest_regcpy(&ref_r, DIFFTEST_TO_DUT);  
  checkregs(&ref_r);
  checkstore();
  if_skip = false;
}