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

#include <isa.h>
#include <cpu/cpu.h>
#include <difftest-def.h>
#include <memory/paddr.h>

#define NPC_REGS_NUM 16
__EXPORT void difftest_memcpy(paddr_t addr, void *buf, size_t n, bool direction) {
  size_t word = n / 4;
  size_t word_n = n - word * 4;
  if (direction == DIFFTEST_TO_DUT) {
    // 直接从addr开始读取，不需要指针转换
    for (size_t i = 0; i < word; i++) {
      ((uint32_t *)buf)[i] = paddr_read(addr + i * 4, 4);  // 以4字节为单位读取
    }
    if(word_n) {
      for (size_t i = 0; i < word_n; i++) {
        ((uint8_t *)buf)[word * 4 + i] = (uint8_t)paddr_read(addr + word * 4 + i, 1);  // 以4字节为单位读取
      }
    }
  } 
  else if (direction == DIFFTEST_TO_REF) {
    // 直接从addr开始写入，不需要指针转换
    for (size_t i = 0; i < word; i++) {
      paddr_write(addr + i * 4, 4, ((uint32_t *)buf)[i]);  // 以4字节为单位写入
    }
    if(word_n) {
      for (size_t i = 0; i < word_n; i++) {
        paddr_write(addr + word * 4 + i, 1, ((uint8_t *)buf)[word * 4 + i]);
      }
    }
  }
}

__EXPORT void difftest_regcpy(void *dut, bool direction) {
  if (direction == DIFFTEST_TO_DUT)
  {
    for (size_t i = 0; i < NPC_REGS_NUM; i++)
    {
      *((word_t *)dut + i) = cpu.gpr[i];
    }
    *((word_t *)dut + NPC_REGS_NUM) = cpu.pc;
  }
  if (direction == DIFFTEST_TO_REF)
  {
    for (size_t i = 0; i < NPC_REGS_NUM; i++)
    {
      cpu.gpr[i] = *((word_t *)dut + i) ;
    }
    cpu.pc = *((word_t *)dut + NPC_REGS_NUM);
  }
}

__EXPORT void difftest_exec(uint64_t n) {
  cpu_exec(n);
}

__EXPORT void difftest_raise_intr(word_t NO) {
  // assert(0);
}

__EXPORT void difftest_init(int port) {
  void init_mem();
  init_mem();
  /* Perform ISA dependent initialization. */
  init_isa();
}

__EXPORT void difftest_instcheck(uint32_t dut_pc, uint32_t *ref_inst) {
  *ref_inst = (uint32_t)paddr_read(dut_pc, 4);
}

__EXPORT void difftest_get_store(void *dut) {
  mem_info_t *ref_mem_t = (mem_info_t *)dut;
  ref_mem_t->data = nemu_mem_info.data;
  ref_mem_t->vaddr = nemu_mem_info.vaddr;
  ref_mem_t->len = nemu_mem_info.len;
  ref_mem_t->type = nemu_mem_info.type;
}