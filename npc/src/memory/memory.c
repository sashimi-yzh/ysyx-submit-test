#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

#include "VysyxSoCFull.h"
#include "VysyxSoCFull___024root.h"

#include <assert.h>
#include "memory.h"
#include "config.h"

#include <sys/time.h>
struct timeval time_cur;
struct timeval time_ini;
uint64_t  init_us = 0;

void init_timer() {
    gettimeofday(&time_ini, NULL);
    init_us = time_ini.tv_sec * 1000000LL + time_ini.tv_usec  ;
}

uint64_t current_time_us() {
    gettimeofday(&time_cur, NULL);
    uint64_t  cur_us  = time_cur.tv_sec * 1000000LL + time_cur.tv_usec  ;
    return (cur_us - init_us);
}

extern  VysyxSoCFull *top 			    ;

// uint8_t pmem[0x8000000] = {}; //flash

// 0x3000_0000
uint8_t flash[0x8000000] = {};

// 0x0f00_0000
uint8_t sram[0x800000] = {};

// read load
uint8_t* guest_to_host_sram(uint32_t paddr) { return sram + paddr - CONFIG_SRAM_BASE; }
uint8_t* guest_to_host(uint32_t paddr) { return flash + paddr - CONFIG_MBASE; }

static inline uint32_t host_read(void *addr, int len) {
  switch (len) {
    case 1: return *(uint8_t  *)addr;
    case 2: return *(uint16_t *)addr;
    case 4: return *(uint32_t *)addr;
    default: assert(0);
  }
}

uint32_t pmem_read(uint32_t addr, int len) {
  assert((addr >= 0xf000000 && addr < 0x10000000) || (addr >= 0x30000000 && addr < 0x38000000) || (addr >= 0x02000000 && addr < 0x02000010));
  uint32_t ret;
  #ifdef  mtrace
    printf("mtrace: pmem_read at 0x%x, len = %d\n", addr, len);
  #endif
  // printf("pmem_read 0x%x len 0x%x\n", addr, len);
  if(addr >= 0xf000000 && addr < 0x10000000)
    ret = host_read(guest_to_host_sram(addr), len);
  else if(addr >= 0x30000000 && addr < 0x38000000)
    ret = host_read(guest_to_host(addr), len);
  return ret;
}

extern "C" uint32_t load_word(int raddr) {
  // printf("the addr 0x%x\n", raddr);
  uint32_t ret;
  if(raddr == 0x02000000) //timer us lower
  {
    ret = (uint32_t)top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__CLINT__DOT__cnt;
    return ret;
  }
  else if(raddr == 0x02000004) // timer us higher
  {
    ret = (uint32_t)(top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__CLINT__DOT__cnt >> 32);
    return ret;
  }
  // printf("the addr 0x%x is 0x%x\n", raddr, pmem_read(raddr, 1));
    return pmem_read(raddr, 4);
}

extern "C" uint16_t load_half(int raddr) {
    // printf("addr 0x%08x = 0x%08x\n",raddr , pmem_read(raddr, 2));
    return pmem_read(raddr, 2);
}

extern "C" uint8_t load_byte(int raddr) {
    // printf("the addr 0x%x is 0x%x\n", raddr, pmem_read(raddr, 1));
    return pmem_read(raddr, 1);
}

// write store
// uint32_t host_to_guest(uint8_t *haddr) { return haddr - pmem + CONFIG_MBASE; }

static inline void host_write(void *addr, int len, uint32_t data) {
  switch (len) {
    case 1: *(uint8_t  *)addr = data; return;
    case 2: *(uint16_t *)addr = data; return;
    case 4: *(uint32_t *)addr = data; return;
    default: assert(0);
  }
}

static void pmem_write(uint32_t addr, int len, uint32_t data) {
  if (addr == 0x0200000c || addr == 0xa00003f8)
  {
    // printf("putch\n");
    putchar(data);
    fflush(stdout);
    return;
  }
  if (addr == 0x02000008  &&  data  ==  1)
  {
    printf("ysyx_23060299_NPC Environment:  Timer enable !!!\n");
    top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__CLINT__DOT__cnt_en = 1 ;
    return;
  }
  // printf("addr == 0x%x len == %d data == 0x%x \n", addr, len, data);
  assert((addr >= 0xf000000 && addr < 0x10000000) || (addr >= 0x30000000 && addr < 0x38000000) || (addr >= 0x02000000 && addr < 0x02000010));
  #ifdef  mtrace
    printf("mtrace: pmem_write at 0x%x, len = %d, data = 0x%x\n", addr, len, data);
  #endif

  // printf("pmem_write addr = 0x%08x data = 0x%08x\n", addr, data);
  if(addr >= 0xf000000 && addr < 0x10000000)
    host_write(guest_to_host_sram(addr), len, data);
  else if(addr >= 0x30000000 && addr < 0x38000000)
    host_write(guest_to_host(addr), len, data);
}

extern "C" void store_word(int waddr, int wdata) {
  // printf("store_word addr = 0x%08x data = 0x%08x\n", waddr, wdata);
  pmem_write(waddr, 4, wdata);
}

extern "C" void store_half(int waddr, int wdata) {
  // printf("store_half waddr = 0x%x wdata = 0x%x\n", waddr, wdata);
  pmem_write(waddr, 2, wdata);
}

extern "C" void store_byte(int waddr, int wdata) {
  // printf("store_byte addr = 0x%08x data = 0x%08x\n", waddr, wdata);
  pmem_write(waddr, 1, wdata);
}

uint8_t* guest_to_host_flash(uint32_t paddr) { return flash + paddr; }

// paddr_t host_to_guest_flash(uint8_t *haddr) { return haddr - flash + CONFIG_FLASH_BASE; }
static uint32_t flash_read_align(uint32_t addr, int len) {
  uint32_t ret = host_read(guest_to_host_flash(addr), len);
  return ret;
}

// extern "C" void flash_write(int waddr, int len, int data) {
//   host_write(guest_to_host_flash(addr), len, data);
// }

extern "C" void flash_read(int32_t addr, int32_t *data) {
  uint32_t  addr_temp = (addr  & 0xFFFFFFFC);
  *data  =  flash_read_align(addr_temp, 4);
}

extern "C" void mrom_read(int32_t addr, int32_t *data) {
  // printf("mrom_read addr = 0x%08x data = 0x%08x\n", addr, pmem_read(addr, 4));
  uint32_t  addr_temp = (addr  & 0xFFFFFFFC);
  // printf("mrom_read addr_temp = 0x%08x data = 0x%08x\n", addr_temp, pmem_read(addr_temp, 4));
  *data  =  pmem_read(addr_temp, 4);
}


long load_img(char *img_file) {

  FILE *fp;

  if(img_file == NULL) {
    printf("img_file == NULL\n");
    img_file  = (char*)"/home/ysyx/Desktop/ysyx/ics2023/am-kernels/tests/am-tests/build/amtest-riscv32e-ysyxsoc.bin";
  }

  fp = fopen(img_file, "rb");

//  Assert(fp, "Can not open '%s'", img_file);
  if(fp == NULL)
  {
  	printf("File Open Failed !\n");
  	assert(fp != NULL);
  }

  fseek(fp, 0, SEEK_END);
  long size = ftell(fp);

  printf("The image is %s, size = %ld\n", img_file, size);

  // fseek(fp, 0, SEEK_SET);
  // int ret = fread(guest_to_host(RESET_VECTOR), size, 1, fp);

  fseek(fp, 0, SEEK_SET);
  
  int ret1 = fread(guest_to_host_flash(0), size, 1, fp);

  assert(ret1 == 1);

  fclose(fp);

  return size;
}


extern "C" uint32_t inst_fetch(uint32_t pc) {
  assert(pc >= 0x80000000 || (pc >= 0x30000000 && pc < 0x38000000));
  uint32_t inst = 0;
  if(pc >= 0x80000000 || (pc >= 0x30000000 && pc < 0x38000000))
    inst =  pmem_read(pc, 4);
  else
    inst =  0;
  return inst;
}

