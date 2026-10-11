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

static uint8_t flash[CONFIG_MSIZE] PG_ALIGN = {};
static uint8_t sram[CONFIG_SSIZE] PG_ALIGN = {};
static uint8_t psram[CONFIG_PSSIZE] PG_ALIGN = {};
static uint8_t sdram[CONFIG_SDSIZE] PG_ALIGN = {};

uint8_t* guest_to_host(paddr_t paddr) { 
    if(in_flash(paddr)) return flash + paddr - CONFIG_MBASE;
    if(in_sram(paddr)) return sram + paddr - CONFIG_SBASE;
    if(in_psram(paddr)) return psram + paddr - CONFIG_PSBASE;
    if(in_sdram(paddr)) return sdram + paddr - CONFIG_SDBASE;
    return NULL;
}
paddr_t host_to_guest(uint8_t *haddr) { 
    if(haddr>=flash&&haddr<=flash+CONFIG_MSIZE) return haddr - flash + CONFIG_MBASE;
    if(haddr>=sram&&haddr<=sram+CONFIG_SSIZE) return haddr - sram + CONFIG_SBASE;
    if(haddr>=psram&&haddr<=psram+CONFIG_PSSIZE) return haddr - psram + CONFIG_PSBASE;
    if(haddr>=sdram&&haddr<=sdram+CONFIG_SDSIZE) return haddr - sdram + CONFIG_SDBASE;
    return 0;
}

static word_t pmem_read(paddr_t addr, int len) {
    word_t ret = host_read(guest_to_host(addr), len);
    #ifdef CONFIG_MTRACE
       if(addr>=CONFIG_MTRACE_START&&addr<=CONFIG_MTRACE_END)
           Log("Read memory at addr=" FMT_PADDR ",data="FMT_WORD,addr,ret);
    #endif
    return ret;
}

static void pmem_write(paddr_t addr, int len, word_t data) {
    host_write(guest_to_host(addr), len, data);
    #ifdef CONFIG_MTRACE
        if(addr>=CONFIG_MTRACE_START&&addr<=CONFIG_MTRACE_END)
            Log("Write memory at addr=" FMT_PADDR ",data="FMT_WORD,addr,data);
    #endif
}
void iringbuf_print();
static void out_of_bound(paddr_t addr) {
    iringbuf_print();
    panic("address = " FMT_PADDR " is out of bound of pmem [" FMT_PADDR ", " FMT_PADDR "] at pc = " FMT_WORD,addr, PMEM_LEFT, PMEM_RIGHT, cpu.pc);
}

void init_mem() {
  IFDEF(CONFIG_MEM_RANDOM, memset(flash, rand(), CONFIG_MSIZE));
  Log("physical memory area [" FMT_PADDR ", " FMT_PADDR "]", PMEM_LEFT, PMEM_RIGHT);
}

word_t paddr_read(paddr_t addr, int len) {
  if (likely(in_pmem(addr))) return pmem_read(addr, len);
  IFDEF(CONFIG_DEVICE, return mmio_read(addr, len));
  out_of_bound(addr);
  return 0;
}

void paddr_write(paddr_t addr, int len, word_t data) {
  if (likely(in_pmem(addr))) { pmem_write(addr, len, data); return; }
  IFDEF(CONFIG_DEVICE, mmio_write(addr, len, data); return);
  out_of_bound(addr);
}
