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
// #define CONFIG_TARGET_SHARE
#include <ysyxsoc.h>
#include "../ysyxsoc/include/ysyxsoc_mem.h"
#include <memory/host.h>
#include <memory/paddr.h>
#include <device/mmio.h>
#include <isa.h>

//difftest
bool dev_skip = false;

#if   defined(CONFIG_PMEM_MALLOC)
static uint8_t *pmem = NULL;
#else // CONFIG_PMEM_GARRAY
static uint8_t pmem[CONFIG_MSIZE] PG_ALIGN = {};
#endif

uint8_t* guest_to_host(paddr_t paddr) {
    uint8_t* ptr = NULL;
    if(in_pmem(paddr))
        ptr = pmem + paddr - CONFIG_MBASE;
    else if(in_mrom(paddr))//write and read mrom
        ptr = mrom + paddr - MROM_BASE;
    else if(in_sram(paddr))//write and read sram
        ptr = sram + paddr - SRAM_BASE;
    else if(in_flash(paddr))//write and read flash
        ptr = flash + paddr - FLASH_BASE;
    else if(in_sdram(paddr))//write and read sdram
        ptr = sdram + paddr - SDRAM_BASE;
    else if(in_psram(paddr))//write and read psram
        ptr = psram + paddr - PSRAM_BASE;
    return ptr;
}

paddr_t host_to_guest(uint8_t *haddr) { return haddr - pmem + CONFIG_MBASE; }

static word_t pmem_read(paddr_t addr, int len) {
  word_t ret = host_read(guest_to_host(addr), len);
    // if(in_sdram(addr)){
    //     printf("now read sdram addr = %x, data = %x\n", addr, ret);
    // }
  return ret;
}

static void pmem_write(paddr_t addr, int len, word_t data) {
  host_write(guest_to_host(addr), len, data);
    // if(in_sdram(addr)){
    //     printf("now write sdram addr = %x, data = %x\n", addr, data);
    // }
}

static void out_of_bound(paddr_t addr) {
  panic("address = " FMT_PADDR " is out of bound of pmem [" FMT_PADDR ", " FMT_PADDR "] at pc = " FMT_WORD,
      addr, PMEM_LEFT, PMEM_RIGHT, cpu.pc);
}

void init_mem() {
#if   defined(CONFIG_PMEM_MALLOC)
  pmem = malloc(CONFIG_MSIZE);
  assert(pmem);
#endif
  IFDEF(CONFIG_MEM_RANDOM, memset(pmem, rand(), CONFIG_MSIZE));
  Log("physical memory area [" FMT_PADDR ", " FMT_PADDR "]", PMEM_LEFT, PMEM_RIGHT);
}









word_t paddr_read(paddr_t addr, int len) {
    // printf("read_now, addr = 0x%x\n", addr);
#ifdef CONFIG_TARGET_SHARE
  if (in_dev(addr)) {dev_skip = true; return 0;}

  if (in_mrom(addr)) return pmem_read(addr, len);
  if (in_sram(addr)) return pmem_read(addr, len);
  if (in_flash(addr)) return pmem_read(addr, len);
  if (in_sdram(addr)) return pmem_read(addr, len);
  if (in_psram(addr)) return pmem_read(addr, len);
#elif CONFIG_ICACHESIM
    if (in_dev(addr)) return soc2nemu_read(addr, len);

    if (in_mrom(addr)) return pmem_read(addr, len);
    if (in_sram(addr)) return pmem_read(addr, len);
    if (in_flash(addr)) return pmem_read(addr, len);
    if (in_sdram(addr)) return pmem_read(addr, len);
    if (in_psram(addr)) return pmem_read(addr, len);
#endif

  IFDEF(CONFIG_MTRACE, if(addr >= CONFIG_MTRACE_START && addr <= CONFIG_MTRACE_END) display_pread(addr, len));
  if (likely(in_pmem(addr))) return pmem_read(addr, len);
  IFDEF(CONFIG_DEVICE, return mmio_read(addr, len));
  out_of_bound(addr);
  return 0;
}






void paddr_write(paddr_t addr, int len, word_t data) {
    // printf("write_now, addr = 0x%x\n", addr);
#ifdef CONFIG_TARGET_SHARE
  if (in_dev(addr)) {dev_skip = true; return;}

  if (in_sram(addr)) { pmem_write(addr, len, data); return; }
  if (in_flash(addr)) { pmem_write(addr, len, data); return; }
  if (in_sdram(addr)) { pmem_write(addr, len, data); return; }
  if (in_psram(addr)) { pmem_write(addr, len, data); return; }
#elif CONFIG_ICACHESIM
  if (in_dev(addr)) { soc2nemu_write(addr, len, data); return;}

  if (in_sram(addr)) { pmem_write(addr, len, data); return; }
  if (in_flash(addr)) { pmem_write(addr, len, data); return; }
  if (in_sdram(addr)) { pmem_write(addr, len, data); return; }
  if (in_psram(addr)) { pmem_write(addr, len, data); return; }
#endif

  IFDEF(CONFIG_MTRACE, if(addr >= CONFIG_MTRACE_START && addr <= CONFIG_MTRACE_END) display_pwrite(addr, len, data));
  if (likely(in_pmem(addr))) { pmem_write(addr, len, data); return; }
  IFDEF(CONFIG_DEVICE, mmio_write(addr, len, data); return);
  out_of_bound(addr);
}




