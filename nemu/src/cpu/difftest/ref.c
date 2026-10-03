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
static void diff_set_regs(void * diff_context){
    CPU_state* ctx=(CPU_state*)diff_context;
    for(int i=0;i<16;i++){
        cpu.gpr[i]=ctx->gpr[i];
    } 
    cpu.pc=ctx->pc;
}
static void diff_get_regs(void* diff_context){
    CPU_state* ctx=(CPU_state*)diff_context;
    for(int i=0;i<16;i++){
        ctx->gpr[i]=cpu.gpr[i];
    }
    ctx->pc=cpu.pc;
}

__EXPORT void difftest_memcpy(paddr_t addr, void *buf, size_t n, bool direction) {
    if(direction==DIFFTEST_TO_REF){
        size_t i;
        uint8_t * src=(uint8_t*)buf;
        for(i=0;i<n;i++){
            paddr_write(addr+i,1,src[i]);
        }
    }else{
        assert(0);
    }
}
__EXPORT void difftest_regcpy(void *dut, bool direction) {
    if(direction==DIFFTEST_TO_REF){
        diff_set_regs(dut);
    }else{
        diff_get_regs(dut);
    }
}

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
}
