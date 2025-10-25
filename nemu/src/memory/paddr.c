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

#include <memory/host.h>
#include <memory/paddr.h>
#include <device/mmio.h>
#include <isa.h>

#if defined(CONFIG_PMEM_MALLOC)
static uint8_t *pmem = NULL;
#else // CONFIG_PMEM_GARRAY
static uint8_t pmem[CONFIG_MSIZE] PG_ALIGN = {};
#endif
// static int is_set = 0;
uint8_t *guest_to_host(paddr_t paddr) { return pmem + paddr - CONFIG_MBASE; }
paddr_t host_to_guest(uint8_t *haddr) { return haddr - pmem + CONFIG_MBASE; }
extern void print_iringbuf();
extern void isa_reg_display();
static word_t pmem_read(paddr_t addr, int len)
{
	word_t ret = host_read(guest_to_host(addr), len);
	return ret;
}

static void pmem_write(paddr_t addr, int len, word_t data)
{
	host_write(guest_to_host(addr), len, data);
}

static void out_of_bound(paddr_t addr)
{
	panic("address = " FMT_PADDR " is out of bound of pmem [" FMT_PADDR ", " FMT_PADDR "] at pc = " FMT_WORD,
		  addr, PMEM_LEFT, PMEM_RIGHT, cpu.pc);
}

void init_mem()
{
#if defined(CONFIG_PMEM_MALLOC)
	pmem = malloc(CONFIG_MSIZE);
	assert(pmem);
#endif
	IFDEF(CONFIG_MEM_RANDOM, memset(pmem, rand(), CONFIG_MSIZE));
	Log("physical memory area [" FMT_PADDR ", " FMT_PADDR "]", PMEM_LEFT, PMEM_RIGHT);
}

word_t paddr_read(paddr_t addr, int len)
{
	word_t ret = 0;
	if (likely(in_pmem(addr)))
	{

		ret = pmem_read(addr, len);
		// if (addr >= 0x82e66780 && addr <= 0x82e66790)
		// {

		// 	printf("paddr_read addr = %08x len = %d data = 0x%08x\t%010u,pc = %08x\n", addr, len, ret, ret, cpu.pc);
		// }
		IFDEF(CONFIG_MTRACE, if (addr > 0x83000000 && addr < 0x83050000) printf("paddr_read addr = %08x len = %d data = 0x%08x\t%010u\n", addr, len, ret, ret));
		return ret;
	}

	IFDEF(CONFIG_DEVICE, return mmio_read(addr, len));
	out_of_bound(addr);
	return 0;
}

void paddr_write(paddr_t addr, int len, word_t data)
{
	if (likely(in_pmem(addr)))
	{

		// if (addr >= 0x82e66780 && addr <= 0x82e66790)
		// {
		// 	printf("paddr_write addr = %08x len = %d data = 0x%08x\t%010u,pc = %08x\n", addr, len, data, data, cpu.pc);
		// 	// if (addr == 0x82e64954)
		// 	// {
		// 	// 	print_iringbuf();
		// 	// 	isa_reg_display();
		// 	// 	assert(0);
		// 	// }
		// }
		IFDEF(CONFIG_MTRACE, if (addr > 0x82e0ff10 && addr < 0x82e0ff20) printf("paddr_write addr = %08x len = %d data = 0x%08x\t%010u\n", addr, len, data, data));
		pmem_write(addr, len, data);
		return;
	}
	IFDEF(CONFIG_DEVICE, mmio_write(addr, len, data); return);
	out_of_bound(addr);
}
