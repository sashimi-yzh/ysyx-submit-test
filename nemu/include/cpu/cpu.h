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

#ifndef __CPU_CPU_H__
#define __CPU_CPU_H__

#include <common.h>
#include <isa.h>


void cpu_exec(uint64_t n);

void set_nemu_state(int state, vaddr_t pc, int halt_ret);
void invalid_inst(vaddr_t thispc);

#define NEMUTRAP(thispc, code) set_nemu_state(NEMU_END, thispc, code)
#define INV(thispc) invalid_inst(thispc)

#ifdef CONFIG_IRINGBUF
#define IRINGBUF_SIZE 16 
typedef struct {
    vaddr_t pc;           // 指令的PC值
    uint32_t inst;        // 指令的机器码
    char asm_buf[128];    // 反汇编后的指令文本
  } IRingBufEntry;

  extern IRingBufEntry iringbuf[IRINGBUF_SIZE];  // 使用extern声明
  extern int iringbuf_index;                     // 使用extern声明

  void iringbuf_add_inst(vaddr_t pc, uint32_t inst, const char *asm_str);
  void print_iringbuf(vaddr_t pc);
#endif

#endif
