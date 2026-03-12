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


extern bool dcache;

#if   defined(CONFIG_PMEM_MALLOC)
static uint8_t *pmem = NULL;
#else // CONFIG_PMEM_GARRAY
static uint8_t pmem[CONFIG_MROM_SIZE + CONFIG_SRAM_SIZE + 
                    CONFIG_FLASH_SIZE + CONFIG_PSRAM_SIZE] PG_ALIGN = {};
#endif

#ifdef CONFIG_SOC

uint8_t* guest_to_host(paddr_t paddr) {
  if(in_mrom(paddr))  return pmem + paddr - CONFIG_MROM_BASE;
  else if(in_sram(paddr))  return pmem + paddr - CONFIG_SRAM_BASE + CONFIG_MROM_SIZE;
  else if(in_flash(paddr))  return pmem + paddr - CONFIG_FLASH_BASE + CONFIG_MROM_SIZE + CONFIG_SRAM_SIZE;
  else if(in_psram(paddr))  return pmem + paddr - CONFIG_PSRAM_BASE + CONFIG_MROM_SIZE + CONFIG_SRAM_SIZE + CONFIG_FLASH_SIZE;
  else if(in_sdram(paddr))  return pmem + paddr - CONFIG_SDRAM_BASE + CONFIG_MROM_SIZE + CONFIG_SRAM_SIZE + CONFIG_FLASH_SIZE + CONFIG_PSRAM_SIZE;
  else return NULL;
}
paddr_t host_to_guest(uint8_t *haddr) { 
  if((haddr-pmem) < CONFIG_MROM_SIZE) return haddr - pmem + CONFIG_MROM_BASE;
  else if((haddr-pmem) < (CONFIG_MROM_SIZE + CONFIG_SRAM_SIZE)) return haddr - pmem - CONFIG_MROM_SIZE + CONFIG_SRAM_BASE;
  else if((haddr-pmem) < (CONFIG_MROM_SIZE + CONFIG_SRAM_SIZE + CONFIG_FLASH_SIZE)) return haddr - pmem - CONFIG_MROM_SIZE - CONFIG_SRAM_SIZE + CONFIG_FLASH_BASE;
  else if((haddr-pmem) < (CONFIG_MROM_SIZE + CONFIG_SRAM_SIZE + CONFIG_FLASH_SIZE + CONFIG_PSRAM_SIZE)) return haddr - pmem - CONFIG_MROM_SIZE - CONFIG_SRAM_SIZE - CONFIG_FLASH_SIZE + CONFIG_PSRAM_BASE;
  else if((haddr-pmem) < (CONFIG_MROM_SIZE + CONFIG_SRAM_SIZE + CONFIG_FLASH_SIZE + CONFIG_PSRAM_SIZE + CONFIG_SDRAM_SIZE)) return haddr - pmem - CONFIG_MROM_SIZE - CONFIG_SRAM_SIZE - CONFIG_FLASH_SIZE - CONFIG_PSRAM_SIZE + CONFIG_SDRAM_BASE;
  else return 0;
}

void init_mem() {
#if   defined(CONFIG_PMEM_MALLOC)
  pmem = malloc(CONFIG_MROM_SIZE + CONFIG_SRAM_SIZE + CONFIG_FLASH_SIZE + CONFIG_PSRAM_SIZE + CONFIG_SDRAM_SIZE);
  assert(pmem);
#endif
  IFDEF(CONFIG_MEM_RANDOM, memset(pmem, rand(), CONFIG_MROM_SIZE + CONFIG_SRAM_SIZE + CONFIG_FLASH_SIZE + CONFIG_PSRAM_SIZE + CONFIG_SDRAM_SIZE));
  Log("physical memory area mrom [" FMT_PADDR ", " FMT_PADDR "], sram [" FMT_PADDR ", " FMT_PADDR "], flash [" FMT_PADDR ", " FMT_PADDR "], psram [" FMT_PADDR ", " FMT_PADDR "], sdram [" FMT_PADDR ", " FMT_PADDR "]",
      PMEM_LEFT_MROM, PMEM_RIGHT_MROM, PMEM_LEFT_SRAM, PMEM_RIGHT_SRAM, PMEM_LEFT_FLASH, PMEM_RIGHT_FLASH, PMEM_LEFT_PSRAM, PMEM_RIGHT_PSRAM, PMEM_LEFT_SDRAM, PMEM_RIGHT_SDRAM);
}

static void out_of_bound(paddr_t addr) {
  panic("address = " FMT_PADDR " is out of bound of mrom [" FMT_PADDR ", " FMT_PADDR "] or sram [" FMT_PADDR ", " FMT_PADDR "] or flash [" FMT_PADDR ", " FMT_PADDR "] or psram [" FMT_PADDR ", " FMT_PADDR "] or sdram [" FMT_PADDR ", " FMT_PADDR "] at pc = " FMT_WORD,
      addr, PMEM_LEFT_MROM, PMEM_RIGHT_MROM, PMEM_LEFT_SRAM, PMEM_RIGHT_SRAM, PMEM_LEFT_FLASH, PMEM_RIGHT_FLASH, PMEM_LEFT_PSRAM, PMEM_RIGHT_PSRAM, PMEM_LEFT_SDRAM, PMEM_RIGHT_SDRAM, cpu.pc);
}

#else

uint8_t* guest_to_host(paddr_t paddr) { return pmem + paddr - CONFIG_MBASE; }
paddr_t host_to_guest(uint8_t *haddr) { return haddr - pmem + CONFIG_MBASE; }

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

#endif

static word_t pmem_read(paddr_t addr, int len) {
  word_t ret = host_read(guest_to_host(addr), len);
  return ret;
}


static void pmem_write(paddr_t addr, int len, word_t data) {
  host_write(guest_to_host(addr), len, data);
}


#ifdef CONFIG_MTRACE

#define MTRACE_BASE 0x80000140
#define MTRACE_SIZE 3

static void mtrace(paddr_t addr, word_t data, int op) {

    if(addr > MTRACE_BASE && addr < MTRACE_BASE+4*MTRACE_SIZE) printf("MTRACE===>>>  addr(0x%08x): data(0x%08x) op(%s)\n", addr, data, op==0? "read" : op==1? "sb  " : op==2? "sh  " : "sw  ");
}

// static void mtrace(paddr_t addr, word_t data, int op) {

//     if(!dcache) return;

//     static FILE *mtrace_fp = NULL;
        
//     if (mtrace_fp == NULL) {
//         mtrace_fp = fopen("/home/hhh/Templates/dcachesim.bin", "wb");
//         if (mtrace_fp == NULL) {
//             perror("Failed to open mtrace file");
//         }
//     }

//     // if(op != 0) printf("op is %x\n", op);

//     uint64_t entry = ((uint64_t)op << 32) | (addr & 0xffffffff);
    
//     if (mtrace_fp != NULL) {
//         // 写入PC值（十六进制
//         fwrite(&entry, sizeof(uint64_t), 1, mtrace_fp);
        
//         // 定期flush防止数据丢失
//         static int count = 0;
//         if (++count % 10000 == 0) {
//             fflush(mtrace_fp);
//         }
//     }
//     dcache = false;
// }

#endif

word_t paddr_read(paddr_t addr, int len) {
    if (likely(in_pmem(addr))) {
        word_t read_data = pmem_read(addr, len);
        IFDEF(CONFIG_MTRACE, mtrace(addr, read_data, 0));
        return read_data;
    }
  IFDEF(CONFIG_DEVICE, word_t mmio_data = mmio_read(addr, len); IFDEF(CONFIG_MTRACE, mtrace(addr, mmio_data, 0)); return mmio_data);
  out_of_bound(addr);
  return 0;
}

void paddr_write(paddr_t addr, int len, word_t data) {
  if (likely(in_pmem(addr))) {
      pmem_write(addr, len, data); 
      IFDEF(CONFIG_MTRACE, mtrace(addr, len==1? data&0x000000ff : len==2? data&0x0000ffff : data&0xffffffff, len));
      return; 
  }
  IFDEF(CONFIG_DEVICE, mmio_write(addr, len, data); IFDEF(CONFIG_MTRACE, mtrace(addr, len==1? data&0x000000ff : len==2? data&0x0000ffff : data&0xffffffff, len)); return);
  out_of_bound(addr);
}
