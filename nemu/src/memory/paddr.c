/***************************************************************************************
 * Copyright (c) 2014-2024 Zihao Yu, Nanjing University
 *
 * NEMU is licensed under Mulan PSL v2.
 * You can use this software according to the terms and conditions of the Mulan
 *PSL v2. You may obtain a copy of Mulan PSL v2 at:
 *          http://license.coscl.org.cn/MulanPSL2
 *
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY
 *KIND, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
 *NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
 *
 * See the Mulan PSL v2 for more details.
 ***************************************************************************************/

#include "common.h"
#include "macro.h"
#include "utils.h"
#include <device/mmio.h>
#include <isa.h>
#include <memory/host.h>
#include <memory/paddr.h>
#include <stdint.h>
#include <stdio.h>

#include <time.h>

#include <itrace_pack.h>

#if defined(CONFIG_PMEM_MALLOC)
static uint8_t *pmem = NULL;
#else // CONFIG_PMEM_GARRAY
static uint8_t pmem[CONFIG_MSIZE] PG_ALIGN = {};
#endif

#define SOC_SERIAL_BASE 0x10000000u
#define SOC_SERIAL_END 0x10001000u

#define SOC_TIMER_BASE 0x02000048u
#define SOC_TIMER_END 0x02000100u

#define SRAM_BASE 0x0f000000u
#define MROM_BASE 0x20000000u
#define FLASH_BASE 0x30000000u
#define FLASH_END 0x40000000u


// #define SDRAM_BASE 0xa0000000u
// #define SDRAM_END 0xb0000000u

// NEMU device is conflicted with SDRAM
#define NEMU_DEVICE_BASE 0xa0000000u
#define NEMU_DEVICE_END 0xb0000000u

#ifdef CONFIG_DEVICE
#define SDRAM_BASE (isSoC ? 0xa0000000u : 0xffffffffu)
#define SDRAM_END (isSoC ? 0xb0000000u : 0xffffffffu)
#else
#define SDRAM_BASE 0xa0000000u
#define SDRAM_END 0xb0000000u
#endif

static uint8_t mrom[0x1000] PG_ALIGN; // 4KB
static uint8_t sram[0x2000] PG_ALIGN; // 8KB

static uint8_t flash[0x1000000] PG_ALIGN; // 16MB
static uint8_t sdram[0x2000000] PG_ALIGN; // 32MB

static bool in_mrom(paddr_t addr) { return addr - MROM_BASE < sizeof(mrom); }
static bool in_sram(paddr_t addr) { return addr - SRAM_BASE < sizeof(sram); }
static bool in_flash(paddr_t addr) { 
	return FLASH_BASE <= addr && addr < FLASH_END;
}
static bool in_sdram(paddr_t addr) { 
	// printf("SDRAM addr check: " FMT_PADDR " base: " FMT_PADDR " end: " FMT_PADDR "\n", addr, SDRAM_BASE, SDRAM_END);
	return SDRAM_BASE <= addr && addr < SDRAM_END;
}

uint8_t *guest_to_host(paddr_t paddr) {
  if (likely(in_pmem(paddr))) {
		// printf("pmem addr translate: " FMT_PADDR " to host addr %p\n", paddr, pmem + paddr - CONFIG_MBASE);
    return pmem + paddr - CONFIG_MBASE;
  } else if (in_mrom(paddr)) {
    return mrom + paddr - MROM_BASE;
  } else if (in_sram(paddr)) {
    return sram + paddr - SRAM_BASE;
  } else if (in_flash(paddr)) {
		if(paddr - FLASH_BASE >= sizeof(flash)) {
			printf("Flash address out of range: " FMT_PADDR, paddr);
			return NULL;
		}
	  return flash + paddr - FLASH_BASE;
	} else if (in_sdram(paddr)) {
		if(paddr - SDRAM_BASE >= sizeof(sdram)) {
			printf("SDRAM address out of range: " FMT_PADDR, paddr);
			return NULL;
		}
	  return sdram + paddr - SDRAM_BASE;
	} else if (NEMU_DEVICE_BASE <= paddr && paddr < NEMU_DEVICE_END) {
		return NULL;
	} else if (SOC_SERIAL_BASE <= paddr && paddr < SOC_SERIAL_END) {
		return NULL;
	} else if (SOC_TIMER_BASE <= paddr && paddr < SOC_TIMER_END) {
		return NULL;
	}
	printf("Failed to translate guest to host address: " FMT_PADDR, paddr);
  return NULL;
}
paddr_t host_to_guest(uint8_t *haddr) {
  if (likely(haddr >= pmem && haddr < pmem + CONFIG_MSIZE)) {
    return haddr - pmem + CONFIG_MBASE;
  } else if (haddr >= mrom && haddr < mrom + sizeof(mrom)) {
		return haddr - mrom + MROM_BASE;
	} else if (haddr >= sram && haddr < sram + sizeof(sram)) {
		return haddr - sram + SRAM_BASE;
	} else if (haddr >= flash && haddr < flash + sizeof(flash)) {
		return haddr - flash + FLASH_BASE;
	} else if (haddr >= sdram && haddr < sdram + sizeof(sdram)) {
		return haddr - sdram + SDRAM_BASE;
	}
	printf("Failed to translate host to guest address: %p", haddr);
	return 0;
}

static bool builtin_read(paddr_t addr, int len, word_t *data) {
  uint8_t *haddr = guest_to_host(addr);
  if (haddr == NULL) {
    return false;
  }
  *data = host_read(haddr, len);
  return true;
}

static bool builtin_write(paddr_t addr, int len, word_t data) {
	if(in_mrom(addr)) {
		panic("can not write ROM address = " FMT_PADDR " at pc = " FMT_WORD, addr, cpu.pc);
		return false;
	}
	uint8_t *haddr = guest_to_host(addr);
	if (haddr == NULL) {
		return false;
	}
	host_write(haddr, len, data);
	return true;
}

static void out_of_bound(paddr_t addr) {
  panic("address = " FMT_PADDR " is out of bound of pmem [" FMT_PADDR
        ", " FMT_PADDR "] at pc = " FMT_WORD,
        addr, PMEM_LEFT, PMEM_RIGHT, cpu.pc);
}

void init_mem() {
#if defined(CONFIG_PMEM_MALLOC)
  pmem = malloc(CONFIG_MSIZE);
  assert(pmem);
#endif
	IFDEF(CONFIG_MEM_RANDOM, srand(time(0)));
  IFDEF(CONFIG_MEM_RANDOM, memset(pmem, rand(), CONFIG_MSIZE));
  Log("physical memory area [" FMT_PADDR ", " FMT_PADDR "]", PMEM_LEFT,
      PMEM_RIGHT);

	// memset the ASAN shadow memory to zero
	// instead at trm_init to optimise the init time
#define ASAN_SHADOW_MEMORY_START 0x7000000
#define ASAN_SHADOW_MEMORY_SIZE 0x1000000

	memset(pmem + ASAN_SHADOW_MEMORY_START, 0, ASAN_SHADOW_MEMORY_SIZE);
}

#define is_addr_inmtrace(p)                                                    \
  (((p) >= CONFIG_MTRACE_BEG) && ((p) < CONFIG_MTRACE_END))
#define mtrace(p, expr)                                                        \
  IFDEF(CONFIG_MTRACE, if (is_addr_inmtrace(addr)) { expr; });

extern uint64_t g_nr_guest_inst;

extern itrace_pack_t g_mtrace_pack;

word_t paddr_read(paddr_t addr, int len) {
  mtrace(addr, printf("%ld mem r %08X %db\n",g_nr_guest_inst, addr, len));
	if(g_mtrace_pack){
		itrace_pack_add(g_mtrace_pack, addr);
	}
  word_t data;
  if (builtin_read(addr, len, &data)) {
		// IFDEF(CONFIG_MTRACE, printf("%ld mem r from builtin return %08X\n",g_nr_guest_inst, data););
    return data;
  }
#ifdef CONFIG_DEVICE
	if(SOC_SERIAL_BASE <= addr && addr < SOC_SERIAL_END) {
		addr -= SOC_SERIAL_BASE;
		addr += CONFIG_SERIAL_MMIO;
	} else if(SOC_TIMER_BASE <= addr && addr < SOC_TIMER_END) {
		addr -= SOC_TIMER_BASE;
		addr += CONFIG_RTC_MMIO;
	}
#endif

  IFDEF(CONFIG_DEVICE, return mmio_read(addr, len));
  out_of_bound(addr);
  return 0;
}

void paddr_write(paddr_t addr, int len, word_t data) {
  mtrace(addr, printf("%ld mem w %08X %db %08X\n",g_nr_guest_inst, addr, len, data));
	// if(pmem[0x7000460] != 0){
	// 	printf("Debug: paddr_write addr=" FMT_PADDR " len=%d data=" FMT_WORD " pmem[0x7000460]=%02X\n", addr, len, data, pmem[0x7000460]);
	// }
	if (builtin_write(addr, len, data)) {
		return;
	}
#ifdef CONFIG_DEVICE
	if(SOC_SERIAL_BASE <= addr && addr < SOC_SERIAL_END) {
		addr -= SOC_SERIAL_BASE;
		addr += CONFIG_SERIAL_MMIO;
	}
#endif
  IFDEF(CONFIG_DEVICE, mmio_write(addr, len, data); return);
  out_of_bound(addr);
}
