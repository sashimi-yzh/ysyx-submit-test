/***************************************************************************************
* Copyright (c) 2014-2022 Zihao Yu, Nanjing University
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
#include <ysyxsoc.h>

#define MSTATUS 0x300
#define MTVEC   0x305
#define MEPC    0x341
#define MCAUSE  0x342

struct diff_context_t {
  word_t gpr[32];
  word_t pc;
  word_t csr[4];
};

__EXPORT void difftest_memcpy(paddr_t addr, void *buf, size_t n, bool direction) {
  void *nemu_buf = (void *)guest_to_host(addr);
  if(direction == DIFFTEST_TO_REF)  //dut -> ref (buf -> addr(nemu_buf))
    memcpy(nemu_buf , buf , n);
  else                              //ref -> dut (addr(nemu_buf) -> buf)
    memcpy(buf , nemu_buf, n);
}

__EXPORT void difftest_regcpy(void *dut, bool direction) {
  int i = 0;
  struct diff_context_t *dut_state = (struct diff_context_t *)dut;
  if(direction == DIFFTEST_TO_REF){
    for(i = 0;i < 32 ; i++){
      cpu.gpr[i] = dut_state->gpr[i];
    }
    cpu.pc = dut_state->pc;
    cpu.csr[MSTATUS] = dut_state->csr[0];
    cpu.csr[MTVEC]   = dut_state->csr[1];
    cpu.csr[MEPC]    = dut_state->csr[2];
    cpu.csr[MCAUSE]  = dut_state->csr[3];
  }
  else{
    for(i = 0;i < 32 ; i++){
      dut_state->gpr[i] = cpu.gpr[i];
    }
    dut_state->pc = cpu.pc;
    dut_state->csr[0] = cpu.csr[MSTATUS];
    dut_state->csr[1] = cpu.csr[MTVEC];
    dut_state->csr[2] = cpu.csr[MEPC];
    dut_state->csr[3] = cpu.csr[MCAUSE];
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
  init_ysyxsoc_mem();
  /* Perform ISA dependent initialization. */
  init_isa();
}

extern bool dev_skip;
bool skip_temp = false;

__EXPORT bool difftest_skip() {
  skip_temp = dev_skip;
  dev_skip = false;
  return skip_temp;
}