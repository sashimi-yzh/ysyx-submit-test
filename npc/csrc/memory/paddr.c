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

#include <memory/host.h>
#include <memory/paddr.h>
#include <device/mmio.h>
#include <isa.h>
#include <autoconf.h>

#if   defined(CONFIG_PMEM_MALLOC)
static uint8_t *pmem = NULL;
#else // CONFIG_PMEM_GARRAY
static uint8_t pmem[CONFIG_MSIZE] PG_ALIGN = {};
#endif

uint8_t* guest_to_host(paddr_t paddr) { return pmem + paddr - CONFIG_MBASE; }
paddr_t host_to_guest(uint8_t *haddr) { return haddr - pmem + CONFIG_MBASE; }


//打印内存写入信息，内存读取信息的打印没有单独设置为函数
void print_memwrite(paddr_t addr, int len, word_t data);
void print_memwrite_wmask(paddr_t addr, word_t data, char wmask);



static word_t pmem_read(paddr_t addr, int len) {
  word_t ret = host_read(guest_to_host(addr), len);
  return ret;
}


static void pmem_write(paddr_t addr, int len, word_t data) {
  host_write(guest_to_host(addr), len, data);
}



static void out_of_bound(paddr_t addr) {
  panic("npc: address = " FMT_PADDR " is out of bound of pmem [" FMT_PADDR ", " FMT_PADDR "] at pc = " FMT_WORD,
      addr, PMEM_LEFT, PMEM_RIGHT, npc_cpu.pc);
}


#ifdef CONFIG_MTRACE
// 必须要在写入内存前调用
void print_memwrite(paddr_t addr, int len, word_t data){
#ifdef CONFIG_MTRACE_RANGE_COND
  if (addr < CONFIG_MTRACE_RANGE_MIN || addr + len > CONFIG_MTRACE_RANGE_MAX) return;
#endif
  word_t origin_mem = 0;
  printf("\nmemwrite:\n");
  for(int i = len-1; i >= 0; i--){
    printf("0x%08x:    ", (paddr_t)addr + i);
    if (likely(in_pmem(addr))) 
      origin_mem=  pmem_read(addr+i, 1);
    else{
#ifdef CONFIG_DEVICE
      printf("do not support mmio  =>  " );

      printf("0x%02x\n", (unsigned int)(data >> (i * 8) & 0xff));
#endif 
    }
    //out_of_bound(addr);
    printf("0x%02x  =>  ", (unsigned int)origin_mem);

    printf("0x%02x\n", (unsigned int)(data >> (i * 8) & 0xff));
  }
}

#ifdef CONFIG_MTRACE 
void print_memwrite_wmask(paddr_t addr, word_t data, char wmask){
#ifdef CONFIG_MTRACE_RANGE_COND
  if (addr < CONFIG_MTRACE_RANGE_MIN || addr > CONFIG_MTRACE_RANGE_MAX) return;
#endif
  word_t origin_mem = 0;
  for(int i = 0; i < 4; i++){
      if(wmask & (1 << i)){
        //host_write(guest_to_host(waddr + i), 1, (wdata >> (i * 8)) & 0xff);
        origin_mem = pmem_read(addr + i, 1);
        printf("0x%08x:    ", addr + i);
        printf("0x%02x  =>  ", (unsigned int)origin_mem);
        printf("0x%02x\n", (unsigned int)(data >> (i * 8) & 0xff));
    }
  }
}
#endif // DEBUG



void print_memread(paddr_t addr,int len){
#ifdef CONFIG_MTRACE
   word_t mem_read = pmem_read(addr, len);
#ifdef CONFIG_MTRACE_RANGE_COND
    if (addr < CONFIG_MTRACE_RANGE_MIN || addr + len > CONFIG_MTRACE_RANGE_MAX) return mem_read;
#endif
    printf("\nmemread:\n");
    for(int i = len-1; i>=0; i--){
      printf("0x%08x:    ", (paddr_t)addr + i);
      printf("0x%02x\n", (unsigned int)(mem_read >> (i * 8) & 0xff));
    }
#endif
}

#else 
void print_memwrite(paddr_t addr, int len, word_t data){};
void print_memread(paddr_t addr, int len, word_t data){};
void print_memwrite_wmask(paddr_t addr, word_t data, char wmask){};
#endif

void init_mem() {
#if   defined(CONFIG_PMEM_MALLOC)
  pmem = malloc(CONFIG_MSIZE);
  assert(pmem);
#endif
  IFDEF(CONFIG_MEM_RANDOM, memset(pmem, rand(), CONFIG_MSIZE));
  Log("physical memory area [" FMT_PADDR ", " FMT_PADDR "]", PMEM_LEFT, PMEM_RIGHT);
}

word_t paddr_read(paddr_t addr, int len) {
  word_t mem_read = 0;
  if (likely(in_pmem(addr))) {
    mem_read = pmem_read(addr, len);

    return mem_read;
  }
  else
    IFDEF(CONFIG_DEVICE, return mmio_read(addr, len));
  out_of_bound(addr);

  return 0;
}

void paddr_write(paddr_t addr, int len, word_t data) {
#ifdef CONFIG_MTRACE
  print_memwrite(addr, len, data);
#endif
  if (likely(in_pmem(addr))) { pmem_write(addr, len, data); return; }
  IFDEF(CONFIG_DEVICE, mmio_write(addr, len, data); return);
  out_of_bound(addr);
}
