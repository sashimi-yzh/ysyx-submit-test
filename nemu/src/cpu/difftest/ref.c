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

#include <cpu/decode.h>
#include <isa.h>
#include <cpu/cpu.h>
#include <difftest-def.h>
#include <memory/paddr.h>

// extern uint8_t mrom[MROM_SIZE] PG_ALIGN = {};

__EXPORT void difftest_memcpy(paddr_t addr, void *buf, size_t n, bool direction) {
  if (direction == DIFFTEST_TO_REF) {
   uint8_t *src = (uint8_t*)buf;
    for (size_t i = 0; i < n; i++) {
      paddr_write(addr + i, 1, src[i]); // 逐字节写入 REF
    }
  }
  else{
    uint8_t *dst = (uint8_t*)buf;
    for (size_t i = 0; i < n; i++) {
      dst[i] = (uint8_t)paddr_read(addr + i, 1); // 逐字节读取 REF
    }
  }
}
void difftest_exec(uint64_t n);

int count = 0;
__EXPORT void difftest_regcpy(void *dut, bool direction) {
  CPU_state* top = (CPU_state*)(dut);

  if (direction == DIFFTEST_TO_REF) {
    for(int i = 0; i < RISCV_GPR_NUM; i++){
      // printf("cpu.gpr[%d] = %08x top->gpr[%d] = %08x\n", i, cpu.gpr[i], i, top->gpr[i]);
      cpu.gpr[i] = top->gpr[i];
    }
    // printf("cpu.pc = 0x%08x dut->pc = 0x%08x\n", cpu.pc, top->pc);
    // cpu.csr[0] = top->diff_mstatus; // 只复制mstatus寄存器
    // cpu.csr[5] = top->diff_mepc; // 只复制mepc寄存器
    // cpu.csr[6] = top->diff_mcause; // 只复制mcause寄存器
    // cpu.csr[3] = top->diff_mtvec; // 只复制mtvec寄存器
      if (count == 1) {
        cpu.pc = top->pc + 4;
      }
      else {
        count = 1;
        cpu.pc = top->pc;
      }
  }
  else{
    for(int i = 0; i < RISCV_GPR_NUM; i++){
      top->gpr[i] = cpu.gpr[i];
    }
    top->pc = cpu.pc;
    // top->diff_mstatus = cpu.csr[0]; // 只复制mstatus寄存器
    // top->diff_mepc = cpu.csr[5]; // 只复制mepc寄存器
    // top->diff_mcause = cpu.csr[6]; // 只复制mcause寄存器
    // top->diff_mtvec = cpu.csr[3]; // 只复制mtvec寄存器
  }
}

__EXPORT void difftest_exec(uint64_t n) {
  Decode s;
  for(uint64_t i = 0; i < n; i ++){
    //printf("0x%08x\n", cpu.pc);
    void exec_once(Decode *s, vaddr_t pc);
    exec_once(&s, cpu.pc);
  }
}


__EXPORT void difftest_raise_intr(word_t NO) {
  assert(0);
}

__EXPORT void difftest_init(int port) {
  void init_mem();
  init_mem();
  /* Perform ISA dependent initialization. */
  init_isa();
}


