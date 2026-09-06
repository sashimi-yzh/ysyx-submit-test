/***************************************************************************************
 * Copyright (c) 2014-2022 Zihao Yu, Nanjing University
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

#include "macro.h"
#include <device/mmio.h>
#include <isa.h>
#include <memory/host.h>
#include <memory/lrsc.h>
#include <memory/paddr.h>

#include <stdio.h>

#include <memory/memsocdiff.h>

#if defined(CONFIG_PMEM_MALLOC)
static uint8_t *pmem = NULL;
#else // CONFIG_PMEM_GARRAY
static uint8_t pmem[CONFIG_MSIZE] PG_ALIGN = {};
#endif

static void out_of_bound(paddr_t addr);
#if defined(CONFIG_TARGET_SHARE) || defined(CONFIG_YSYXSOC_EMU)
  word_t soc_read(paddr_t addr, int len) {
    soc_device *dev = fetch_the_soc(addr);
    if(dev!= NULL){
      if(dev->space == NULL)
        return 0;
      return host_read(dev->space + addr - dev->soc_start, len);
    }
    out_of_bound(addr);
    return 0;
  }

  void soc_write(paddr_t addr, int len, word_t data) {
    soc_device *dev = fetch_the_soc(addr);
    if(dev != NULL){
      if(dev->space == NULL)
        return;
      host_write(dev->space + addr - dev->soc_start, len, data);
      return ;
    }
    out_of_bound(addr);
  }
#endif

uint8_t *guest_to_host(paddr_t paddr) { return pmem + paddr - CONFIG_MBASE; }
paddr_t host_to_guest(uint8_t *haddr) { return haddr - pmem + CONFIG_MBASE; }

static word_t pmem_read(paddr_t addr, int len) {
  word_t ret = host_read(guest_to_host(addr), len);
#ifdef CONFIG_MTRACE
  printf("[memory read] %u from 0x%08x\n", ret, addr);
#endif
  return ret;
}

static void pmem_write(paddr_t addr, int len, word_t data) {
  host_write(guest_to_host(addr), len, data);
#ifdef CONFIG_MTRACE
  printf("[memory write] %u to 0x%08x\n", data, addr);
#endif
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
  IFDEF(CONFIG_MEM_RANDOM, memset(pmem, rand(), CONFIG_MSIZE));
  IFDEF(CONFIG_TARGET_SHARE, init_soc());
  Log("physical memory area [" FMT_PADDR ", " FMT_PADDR "]", PMEM_LEFT,
      PMEM_RIGHT);
}

word_t paddr_read(paddr_t addr, int len) {
  if (likely(in_pmem(addr)))
    return pmem_read(addr, len);
  IFDEF(CONFIG_DEVICE, return mmio_read(addr, len));
  IFDEF(CONFIG_TARGET_SHARE, return soc_read(addr, len));
  IFDEF(CONFIG_YSYXSOC_EMU, return soc_read(addr, len));
  out_of_bound(addr);
  return 0;
}

void paddr_write(paddr_t addr, int len, word_t data) {
  lrsc_invalidate_store(addr, len);

  if (likely(in_pmem(addr))) {
    pmem_write(addr, len, data);
    return;
  }
  IFDEF(CONFIG_DEVICE, mmio_write(addr, len, data); return);
  IFDEF(CONFIG_TARGET_SHARE, soc_write(addr, len, data); return);
  IFDEF(CONFIG_YSYXSOC_EMU, soc_write(addr, len, data); return);
  out_of_bound(addr);
}
