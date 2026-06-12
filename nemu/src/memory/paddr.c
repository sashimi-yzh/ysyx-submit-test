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

#include "common.h"
#include "macro.h"
#include <memory/host.h>
#include <memory/paddr.h>
#include <device/mmio.h>
#include <isa.h>

#if   defined(CONFIG_PMEM_MALLOC)
static uint8_t *pmem = NULL;
#else // CONFIG_PMEM_GARRAY
static uint8_t pmem[CONFIG_MSIZE] PG_ALIGN = {};
#endif

inline uint8_t* guest_to_host(paddr_t paddr) { return pmem + paddr - CONFIG_MBASE; }
inline paddr_t host_to_guest(uint8_t *haddr) { return haddr - pmem + CONFIG_MBASE; }

static inline word_t pmem_read(paddr_t addr, int len) {
  word_t ret = host_read(guest_to_host(addr), len);
  // IFDEF(CONFIG_TARGET_SHARE, printf("SHARE"));
  // printf("[NEMU] READ %d Byte: *" FMT_PADDR "=" FMT_WORD "\n", len, addr, ret);
  return ret;
}

static inline void pmem_write(paddr_t addr, int len, word_t data) {
  // IFDEF(CONFIG_TARGET_SHARE, printf("SHARE"));
  // printf("[NEMU] WRITE %d Byte: *" FMT_PADDR "=" FMT_WORD "\n", len, addr, data);
  host_write(guest_to_host(addr), len, data);
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

void mtrace(bool is_write, paddr_t addr, int len, word_t data);
void mbintrace(bool is_write, paddr_t addr, int len);

word_t paddr_read(paddr_t addr, int len) {
  IFDEF(CONFIG_MBINTRACE, mbintrace(false, addr, len));
  if (likely(in_pmem(addr))) {
    word_t data = pmem_read(addr, len);
    IFDEF(CONFIG_MTRACE, mtrace(false, addr, len, data));
    return data;
  }
  IFDEF(CONFIG_DEVICE, return mmio_read(addr, len));
  out_of_bound(addr);
  return 0;
}

void paddr_write(paddr_t addr, int len, word_t data) {
  IFDEF(CONFIG_MBINTRACE, mbintrace(true, addr, len));
  if (likely(in_pmem(addr))) { 
    IFDEF(CONFIG_MTRACE, mtrace(true, addr, len, data));
    pmem_write(addr, len, data); 
    return; 
  }
  IFDEF(CONFIG_DEVICE, mmio_write(addr, len, data); return);
  out_of_bound(addr);
}

bool try_paddr_read(paddr_t addr, int len, void *dest) {
  if (in_pmem(addr)) {
    memcpy(dest, guest_to_host(addr), len);
    return true;
  }
  IFDEF(CONFIG_DEVICE, return try_mmio_read(addr, len, dest));
  return false;
}

bool try_paddr_write(paddr_t addr, int len, void* data) {
  if (in_pmem(addr)) { 
    memcpy(guest_to_host(addr), data, len);
    return true; 
  }
  IFDEF(CONFIG_DEVICE, return try_mmio_write(addr, len, data));
  return false;
}
