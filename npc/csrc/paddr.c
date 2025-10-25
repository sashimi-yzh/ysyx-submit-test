#include <stdint.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "config.h"

uint8_t pmem[MAX_SIZE] = {0};

uint8_t *guest_to_host(uint32_t paddr)
{
	return pmem + paddr - START_ADDR;
}
uint32_t host_read(uint8_t *haddr, int len)
{
	uint32_t ret = 0;
	switch (len)
	{
	case 1:
		ret = *(uint8_t *)haddr;
		break;
	case 2:
		ret = *(uint16_t *)haddr;
		break;
	case 4:
		ret = *(uint32_t *)haddr;
		break;
	default:
		assert(0);
	}
	return ret;
}
extern "C" uint32_t paddr_read(uint32_t addr, int len, int is_fetch, int is_avail)
{

	if (!is_avail)
	{
		return 0;
	}
	uint32_t ret = 0;
	if (addr >= START_ADDR && addr < START_ADDR + MAX_SIZE)
	{
		ret = host_read(guest_to_host(addr), len);
	}
	else
	{
		printf("paddr_read: Invalid address 0x%08x\n", addr);
		assert(0);
	}
#ifdef MEMTRACE
	if (!is_fetch)
		printf("paddr read addr=0x%08x len=%d data = 0x%08x\n", addr, len, ret);
#endif

	return ret;
}
extern "C" void paddr_write(uint32_t addr, int len, uint32_t data, int is_avail)
{
	if (!is_avail)
	{
		return;
	}
	if (addr == 0)
		return;
	if (addr >= START_ADDR && addr < START_ADDR + MAX_SIZE)
	{
		switch (len)
		{
		case 1:
			*(uint8_t *)guest_to_host(addr) = data;
			break;
		case 2:
			*(uint16_t *)guest_to_host(addr) = data;
			break;
		case 4:
			*(uint32_t *)guest_to_host(addr) = data;
			break;
		default:
			assert(0);
		}
	}
	else
	{
		assert(0);
	}

#ifdef MEMTRACE
	printf("paddr write addr=0x%08x len=%d data=0x%08x\n", addr, len, data);
#endif
}
extern "C" void mrom_read(int32_t addr, int32_t *data)
{

	*data = paddr_read(addr & (~3), 4, 0, 1);
}
extern "C" void flash_read(int32_t addr, int32_t *data)
{

	addr += 0x20000000;
	*data = paddr_read(addr & (~3), 4, 0, 1);
}