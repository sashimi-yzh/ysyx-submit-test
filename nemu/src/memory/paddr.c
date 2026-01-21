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

#if   defined(CONFIG_PMEM_MALLOC)
static uint8_t *pmem = NULL;
#else // CONFIG_PMEM_GARRAY
static uint8_t pmem[CONFIG_MSIZE] PG_ALIGN = {};
#endif

uint8_t* guest_to_host(paddr_t paddr) { return pmem + paddr - CONFIG_MBASE; }
paddr_t host_to_guest(uint8_t *haddr) { return haddr - pmem + CONFIG_MBASE; }

static word_t pmem_read(paddr_t addr, int len) {
  return (word_t)host_read(guest_to_host(addr), len);
}

static void pmem_write(paddr_t addr, int len, word_t data) {
  host_write(guest_to_host(addr), len, data);
}

#ifdef CONFIG_SOC_MODE
static uint8_t psram[CONFIG_SRAM_SIZE] PG_ALIGN = {};
static uint8_t psdram[CONFIG_SDRAM_SIZE] PG_ALIGN = {};
uint8_t* guest_to_host_sram(paddr_t paddr) { return psram + paddr - CONFIG_SRAM_BASE; }
uint8_t* guest_to_host_sdram(paddr_t paddr) { return psdram + paddr - CONFIG_SDRAM_BASE; }
static word_t sram_read(paddr_t addr, int len) {
  word_t ret = host_read(guest_to_host_sram(addr), len);
  return ret;
}

static void sram_write(paddr_t addr, int len, word_t data) {
  host_write(guest_to_host_sram(addr), len, data);
}

static word_t sdram_read(paddr_t addr, int len) {
  word_t ret = host_read(guest_to_host_sdram(addr), len);
  return ret;
}

static void sdram_write(paddr_t addr, int len, word_t data) {
  host_write(guest_to_host_sdram(addr), len, data);
}
#endif

// mtrace的实现, 增设mtrace功能, 目的是让nemu作为ref时能追踪指定地址的访存情况
#ifdef CONFIG_MTRACE
  #define traced_addr 0x0f001f58  // 设定要追踪的物理地址
  char mtrace_buf[128];
#endif

static void out_of_bound(paddr_t addr) {
  #ifdef CONFIG_MTRACE
    printf("mtrace 访存出错报告\n");
    printf("PC值         访存地址  操作   字节  写入数据\n");
    puts(mtrace_buf);
  #endif
  panic("address = " FMT_PADDR " is out of bound of pmem [" FMT_PADDR ", " FMT_PADDR "] at pc = " FMT_WORD,
      addr, PMEM_LEFT, PMEM_RIGHT, cpu.pc);
}

void init_mem() {
#if   defined(CONFIG_PMEM_MALLOC)
  pmem = malloc(CONFIG_MSIZE);
  assert(pmem);
#endif
  IFDEF(CONFIG_MEM_RANDOM, memset(pmem, rand(), CONFIG_MSIZE));
#ifdef CONFIG_SOC_MODE
  IFDEF(CONFIG_MEM_RANDOM, memset(psram, rand(), CONFIG_SRAM_SIZE));
  IFDEF(CONFIG_MEM_RANDOM, memset(psdram, rand(), CONFIG_SDRAM_SIZE));
#endif
  Log("NEMU: physical memory area [" FMT_PADDR ", " FMT_PADDR "]", PMEM_LEFT, PMEM_RIGHT);
}

word_t paddr_read(paddr_t addr, int len) {
  #ifdef CONFIG_MTRACE
  char *p = mtrace_buf;
  p += snprintf(p, sizeof(mtrace_buf), FMT_WORD ":  ", cpu.pc);
  p += snprintf(p, mtrace_buf + sizeof(mtrace_buf) - p, "%8x  ", addr);
  p += snprintf(p, mtrace_buf + sizeof(mtrace_buf) - p, "read  %d", len);
  *p = '\0';
  if(traced_addr == addr) {
    puts(mtrace_buf);
  }
  #endif
  if (likely(in_pmem(addr))) return pmem_read(addr, len);
  #ifdef CONFIG_SOC_MODE
  if (in_sram(addr)) return sram_read(addr, len);
  if (in_sdram(addr)) return sdram_read(addr, len);
  #endif
  IFDEF(CONFIG_DEVICE, return mmio_read(addr, len));
  out_of_bound(addr);
  return 0;
}

mem_info_t nemu_mem_info; // 只记录写操作
void paddr_write(paddr_t addr, int len, word_t data) {
  nemu_mem_info.data  = data & (word_t)((1LU << (len << 3))-1);
  nemu_mem_info.len   = len;
  nemu_mem_info.vaddr = addr;
  nemu_mem_info.type  = 2;
  #ifdef CONFIG_MTRACE
    char *p = mtrace_buf;
    p += snprintf(p, sizeof(mtrace_buf), FMT_WORD ":  ", cpu.pc);
    p += snprintf(p, mtrace_buf + sizeof(mtrace_buf) - p, "%8x  ", addr);
    p += snprintf(p, mtrace_buf + sizeof(mtrace_buf) - p, "write  %d     %x", len, data);
    *p = '\0';
    if(traced_addr == addr) {
      puts(mtrace_buf);
    }
  #endif
  if (likely(in_pmem(addr))) { pmem_write(addr, len, data); return; }
  #ifdef CONFIG_SOC_MODE
    if (in_sram(addr)) { sram_write(addr, len, data); return; }
    if (in_sdram(addr)) { sdram_write(addr, len, data); return; }
  #endif
  IFDEF(CONFIG_DEVICE, mmio_write(addr, len, data); return);
  out_of_bound(addr);
}
