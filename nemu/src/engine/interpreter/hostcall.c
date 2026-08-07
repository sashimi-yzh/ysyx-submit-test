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

#include <cpu/difftest.h>
#include <cpu/ifetch.h>
#include <isa.h>
#include <stdio.h>
#include <utils.h>
void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);
void set_nemu_state(int state, vaddr_t pc, int halt_ret) {
  difftest_skip_ref();
  nemu_state.state = state;
  nemu_state.halt_pc = pc;
  nemu_state.halt_ret = halt_ret;
}
IFDEF(CONFIG_ITRACE, static char str[32]);
__attribute__((noinline)) void invalid_inst(vaddr_t thispc) {
#ifdef CONFIG_ITRACE
  iringbuf_elem elem;
  while (iringbuf_elem_size() > 1) {
    iringbuf_pop(&elem);
    disassemble(str, 32, elem.pc, (uint8_t *)&elem.inst, 4);
    printf(ANSI_FMT("    " FMT_WORD ": %-32s\t %02x %02x %02x %02x ", ANSI_FG_BLUE) "\n",
           elem.pc,
           str,
           (elem.inst >> 24) & 0xFF,
           (elem.inst >> 16) & 0xFF,
           (elem.inst >> 8) & 0xFF,
           elem.inst & 0xFF);
  }
  while (iringbuf_elem_size()) {
    iringbuf_pop(&elem);
    disassemble(str, 32, elem.pc, (uint8_t *)&elem.inst, 4);
    printf(ANSI_FMT("--> " FMT_WORD ": %-32s\t %02x %02x %02x %02x ", ANSI_BG_RED) "\n",
           elem.pc,
           str,
           (elem.inst >> 24) & 0xFF,
           (elem.inst >> 16) & 0xFF,
           (elem.inst >> 8) & 0xFF,
           elem.inst & 0xFF);
  }

  int cnt = 7;
  elem.pc = thispc + 4;
  while (cnt-- && (elem.inst = vaddr_ifetch(elem.pc, 4))) {

    disassemble(str, 32, elem.pc, (uint8_t *)&elem.inst, 4);
    printf(ANSI_FMT("    " FMT_WORD ": %-32s\t %02x %02x %02x %02x ", ANSI_FG_BLUE) "\n",
           elem.pc,
           str,
           (elem.inst >> 24) & 0xFF,
           (elem.inst >> 16) & 0xFF,
           (elem.inst >> 8) & 0xFF,
           elem.inst & 0xFF);
    elem.pc += 4;
  }
#endif
  printf("pc: %08x elem.inst:%08x\n", thispc, vaddr_ifetch(thispc, 4));
  set_nemu_state(NEMU_ABORT, thispc, -1);
}
