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
#include "../local-include/csr.h"
word_t isa_raise_intr(word_t NO, vaddr_t epc) {
  csrs[0].value = epc;
  csrs[1].value = NO;
#ifdef CONFIG_ETRACE
  Log("触发了异常/中断, mepc = %8x, mcause = %d, mstatus = %08x", csrs[0].value, csrs[1].value, csrs[3].value);
#endif
  return csrs[2].value;
}

word_t isa_query_intr() {
  return INTR_EMPTY;
}
