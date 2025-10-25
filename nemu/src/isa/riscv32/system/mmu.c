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
#include <memory/vaddr.h>
#include <memory/paddr.h>
extern void print_iringbuf();
paddr_t isa_mmu_translate(vaddr_t vaddr, int len, int type)
{
	word_t satp = cpu.satp;
	assert((satp & 0x80000000));
	word_t root_idx = (satp << 12);
	word_t vpn1 = (vaddr >> 22);
	word_t vpn2 = (vaddr >> 12) & 0x3FF;
	word_t offset = vaddr & 0xFFF;
	word_t pte1 = paddr_read(root_idx + vpn1 * 4, 4);
	if ((pte1 & 0x1) == 0)
	{
		print_iringbuf();
		isa_reg_display();
		printf("PTE1 invalid for vaddr 0x%x, pte1=0x%x,pos=0x%x\n", vaddr, pte1, root_idx + vpn1 * 4);
	}
	assert((pte1 & 0x1) == 0x1); // PTE valid bit must be set
	word_t table_idx = ((pte1 >> 10) << 12);
	word_t pte2 = paddr_read(table_idx + vpn2 * 4, 4);
	if ((pte2 & 0x1) == 0)
	{
		printf("PTE2 invalid for vaddr 0x%x, pte2=0x%x,pos=0x%x\n", vaddr, pte2, table_idx + vpn2 * 4);
	}
	assert((pte2 & 0x1) == 0x1); // PTE valid bit must be set
	paddr_t paddr = ((pte2 >> 10) << 12) | offset;
	return paddr;
}
