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
#include <string.h>
#include <stdlib.h>

// 在DUT host memory的`buf`和REF guest memory的`addr`之间拷贝`n`字节,
// `direction`指定拷贝的方向, `DIFFTEST_TO_DUT`表示往DUT拷贝, `DIFFTEST_TO_REF`表示往REF拷贝
__EXPORT void difftest_memcpy(paddr_t addr, void *buf, size_t n, bool direction) {
  if(direction == DIFFTEST_TO_REF){
    // printf("addr->%x  imm:%ld\n", addr,(word_t)buf);
    memcpy(guest_to_host(addr), buf, n);
  }else if(direction == DIFFTEST_TO_DUT){
    memcpy(buf, guest_to_host(addr), n);
    paddr_read(addr,n);
  }else{
    printf("Invaild direction in difftest_memcpy\n");
    assert(0);  
  }
}
// `direction`为`DIFFTEST_TO_DUT`时, 获取REF的寄存器状态到`dut`;
// `direction`为`DIFFTEST_TO_REF`时, 设置REF的寄存器状态为`dut`;
__EXPORT void difftest_regcpy(void *dut, bool direction) {
  // CPU_state *dut_r = (CPU_state *)dut;
  // if (direction==DIFFTEST_TO_REF) {
  //   cpu = *dut_r;
  // } else {
  //   *dut_r = cpu;
  // }
  CPU_state *diff_dut = (CPU_state *)dut;
  if(direction == DIFFTEST_TO_REF){
    memcpy(&cpu, diff_dut, DIFFTEST_REG_SIZE);
  }else if(direction == DIFFTEST_TO_DUT){
    memcpy(diff_dut, &cpu, DIFFTEST_REG_SIZE);
  }else{
    printf("Invaild direction in difftest_regcpy\n");
    assert(0);
  }
}
// 让REF执行`n`条指令
__EXPORT void difftest_exec(uint64_t n) {
  cpu_exec(n);
}

__EXPORT void difftest_raise_intr(word_t NO) {
  assert(0);
}

__EXPORT void difftest_init(int port) {
  void init_mem();
  init_mem();
  /* Perform ISA dependent initialization. */
  init_isa();
  cpu.gpr[0]=0;
  cpu.pc=RESET_VECTOR;
}
