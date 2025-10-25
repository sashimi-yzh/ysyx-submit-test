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
#include <memory/paddr.h>
word_t trans_check(vaddr_t addr, int len, int type)
{
	int res = isa_mmu_check(addr, len, type);
	if (res == MMU_DIRECT)
		return addr;
	else if (res == MMU_TRANSLATE)
		return isa_mmu_translate(addr, len, type);
	else
		panic("MMU check failed for vaddr %x,type %d\n", addr, type);
}
word_t map_to_rom_and_ram(word_t addr)
{
	if (addr >= 0x0f000000 && addr < 0x0f002000)	  // RAM
		return addr + 0x83000000 - 0x0f000000;		  // 实际地址为0x83000000-0x83002000
	else if (addr >= 0x30000000 && addr < 0x33000000) // Flash
		return addr + 0x50000000;					  // 实际地址为0x80000000-0x83000000
	else if (addr >= 0x80000000 && addr < 0x80400000) // PSRAM
		return addr + 0x4000000;					  // 实际地址为0x84000000-0x84400000
	else if (addr >= 0xa0000000 && addr < 0xa5000000) // SDRAM
		return addr - 0x1b000000;					  // 实际地址为0x85000000-0x88000000
	return addr;									  // Other addresses remain unchanged
}
word_t vaddr_ifetch(vaddr_t addr, int len)
{
#ifdef CONFIG_TARGET_SHARE
	addr = map_to_rom_and_ram(addr);
#endif
	return paddr_read(addr, len);
}

word_t vaddr_read(vaddr_t addr, int len)
{
#ifdef CONFIG_TARGET_SHARE
	if (addr >= 0xa5000000 && addr < 0xa8000000)
	{
		return 0xdeadbeef;
	}
	addr = map_to_rom_and_ram(addr);
#endif
	return paddr_read(addr, len);
}

void vaddr_write(vaddr_t addr, int len, word_t data)
{
#ifdef CONFIG_TARGET_SHARE
	if (addr >= 0xa5000000 && addr < 0xa8000000)
	{
		return;
	}
	addr = map_to_rom_and_ram(addr);
#endif
	paddr_write(addr, len, data);
}
