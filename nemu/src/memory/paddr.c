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
#include <debug.h>


// 0x80404000 - 0x80405000
#define MROM_START  (0x20000000)
#define MROM_END    (0x20001000)

// 0x81000000 - 0x82000000
#define FLASH_START (0x30000000)
#define FLASH_END   (0x31000000)

// 0x80401000 - 0x80403000
#define SRAM_START  (0xf000000)
#define SRAM_END    (0xf002000)

// 0x80000000 - 0x80400000 
#define PSRAM_START (0x80000000)  
#define PSRAM_END   (0x80400000)

// 0x83000000 - 0x87000000
#define SDRAM_START (0xa0000000)
#define SDRAM_END   (0xa4000000)


#if   defined(CONFIG_PMEM_MALLOC)
static uint8_t *pmem = NULL;
#else // CONFIG_PMEM_GARRAY
// ---- 内存块
static uint8_t pmem[CONFIG_MSIZE] PG_ALIGN = {};
#endif

bool mem_err_ignore = false;


uint8_t* guest_to_host(paddr_t paddr) { return pmem + paddr - CONFIG_MBASE; }


paddr_t host_to_guest(uint8_t *haddr) { return haddr - pmem + CONFIG_MBASE; }


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
  printf("address = " FMT_PADDR " is out of bound of pmem [" FMT_PADDR ", " FMT_PADDR "] at pc = " FMT_WORD,
      addr, PMEM_LEFT, PMEM_RIGHT, cpu.pc);
  putchar('\n');
  nemu_state.state = NEMU_ABORT;
}


void init_mem() 
{
#if defined(CONFIG_PMEM_MALLOC)
  pmem = malloc(CONFIG_MSIZE);
  assert(pmem);
#endif
  IFDEF(CONFIG_MEM_RANDOM, memset(pmem, 0, CONFIG_MSIZE));
  // Log("physical memory area [" FMT_PADDR ", " FMT_PADDR "]", PMEM_LEFT, PMEM_RIGHT);
}

#ifdef TARGET_SHARE
static paddr_t npc_addr_map(paddr_t addr)
{  
  if (addr >= FLASH_START && addr < FLASH_END)
    return addr + 0x51000000;
  else if (addr >= MROM_START && addr < MROM_END)
    return addr + 0x60404000;
  else if (addr >= SRAM_START && addr < SRAM_END)
    return addr + 0x71401000;
  else if (addr >= PSRAM_START && addr < PSRAM_END)
    return addr;
  else if (addr >= SDRAM_START && addr < SDRAM_END)
    return addr - 0x1D000000;

  return 0;
}
#endif // TARGET_SHARE

word_t paddr_read(paddr_t addr, int len) 
{
#if defined(CONFIG_MTRACE) && CONFIG_MTRACE == 1
  if (!(len == 4 && cpu.pc == addr))
  {
    printf("[read ] address = " FMT_PADDR "; pc = " FMT_WORD "; len = %d",
      addr, cpu.pc, len);
    putchar('\n');
  }
#endif // CONFIG_MTRACE

#ifdef TARGET_SHARE
  paddr_t address = npc_addr_map(addr);
  if (address == 0 && mem_err_ignore) { 
    return 0xffffffff;
  }
#else
  paddr_t address = addr;
#endif // TARGET_SHARE

  // printf(ANSI_FMT("[r : 0x%08x <=> 0x%08x]\n", ANSI_FG_CYAN), addr, address);

  if (likely(in_pmem(address))) return pmem_read(address, len);
  IFDEF(CONFIG_DEVICE, return mmio_read(address, len));
  out_of_bound(address);
  return 0;
}


void paddr_write(paddr_t addr, int len, word_t data)
{
#if defined(CONFIG_MTRACE) && CONFIG_MTRACE == 1
  printf("[write] address = " FMT_PADDR "; pc = " FMT_WORD "; len = %d; data = " FMT_WORD "\n",
    addr, cpu.pc, len, data);
#endif // CONFIG_MTRACE

#ifdef TARGET_SHARE
  paddr_t address = npc_addr_map(addr);
  if (address == 0 && mem_err_ignore) { 
    return;
  }
#else
  paddr_t address = addr;
#endif // TARGET_SHARE

  // printf(ANSI_FMT("[w : 0x%08x <=> 0x%08x]\n", ANSI_FG_CYAN), addr, address);

  if (likely(in_pmem(address))) { pmem_write(address, len, data); return; }
  IFDEF(CONFIG_DEVICE, mmio_write(address, len, data); return);
  out_of_bound(address);
}
