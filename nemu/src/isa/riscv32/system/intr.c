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
#include <fmt-def.h>

word_t isa_raise_intr(word_t NO, vaddr_t epc) {
  /* TODO: Trigger an interrupt/exception with ``NO''.
   * Then return the address of the interrupt/exception vector.
   */
 /* *get_isa_csr_str2addr("mepc") = epc;
  *get_isa_csr_str2addr("mcause") = NO;
  return *get_isa_csr_str2addr("mtvec");*/
  // if(NO == 0)
  //   epc += 4;
  

//  printf("\nNO: %d\n", NO);

  cpu.csr.mcause = NO;
  cpu.csr.mepc = epc;
  //cpu.csr.mstatus = 0x1800;

#define MSTATUS_MIE   (1 << 3)
#define MSTATUS_MPIE  (1 << 7)
#define MSTATUS_MPP   (3 << 11)  // MPP 占用 11 和 12 位

// 保存当前的 MIE 到 MPIE
uint32_t mie = (cpu.csr.mstatus & MSTATUS_MIE) ? 1 : 0;
cpu.csr.mstatus &= ~MSTATUS_MIE;                      // 清除 MIE
cpu.csr.mstatus = (cpu.csr.mstatus & ~MSTATUS_MPIE) | (mie << 7); // 设置 MPIE


cpu.csr.mstatus = (cpu.csr.mstatus & ~MSTATUS_MPP) | (0x3 << 11); // 设置 MPP = 11 (Machine Mode)

#ifdef CONFIG_ETRACE 
  printf("ETRACE: pc: 0x"FMT_WORD_HEX", mepc = " FMT_WORD_HEX ", mstatus = " FMT_WORD_HEX 
  ", mtvec = " FMT_WORD_HEX ", mcause = " FMT_WORD_HEX "\n",
  cpu.pc, cpu.csr.mepc, cpu.csr.mstatus, cpu.csr.mtvec, cpu.csr.mcause);
#endif 

  return cpu.csr.mtvec;
}

word_t isa_query_intr() {
  return INTR_EMPTY;
}
