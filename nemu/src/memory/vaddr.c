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
#include <memory/paddr.h>
extern char *mtrace_p;

word_t vaddr_ifetch(vaddr_t addr, int len) {
  return paddr_read(addr, len);
}

word_t vaddr_read(vaddr_t addr, int len) {
	word_t result = paddr_read(addr, len);
#ifdef CONFIG_MTRACE
	mtrace_p += sprintf(mtrace_p, "pc:0x%08x addr:0x%08x read:0x%08x\n", cpu.pc, addr, result);
#endif
	return result;
}

void vaddr_write(vaddr_t addr, int len, word_t data) {
#ifdef CONFIG_MTRACE
	mtrace_p += sprintf(mtrace_p, "pc:0x%08x addr:0x%08x write:0x%08x\n", cpu.pc, addr, data);
#endif
  paddr_write(addr, len, data);
}
