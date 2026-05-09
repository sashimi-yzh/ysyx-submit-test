#include <paddr.h>
#include "svdpi.h"
#include "Vnpc_top__Dpi.h"
#include <cpu/difftest.h>
#include <time.h>

static time_t raw_time;          // time_t 是时间戳类型（通常是 long）
static struct tm *time_info;     // tm 结构体存储年月日等时间信息

// 内存数组
static uint8_t pmem[CONFIG_MSIZE] PG_ALIGN = {}; // 0x8000000

uint8_t* guest_to_host(paddr_t paddr) { return pmem + paddr - CONFIG_MBASE; } // 0x80000000
paddr_t host_to_guest(uint8_t *haddr) { return haddr - pmem + CONFIG_MBASE; }


void init_mem() {
#if   defined(CONFIG_PMEM_MALLOC)
  pmem = malloc(CONFIG_MSIZE);
  assert(pmem);
#endif
  IFDEF(CONFIG_MEM_RANDOM, memset(pmem, rand(), CONFIG_MSIZE));
  Log("physical memory area [" FMT_PADDR ", " FMT_PADDR "]", PMEM_LEFT, PMEM_RIGHT);
}

extern "C" int pmem_read(int addr) {

    paddr_t addrr = (paddr_t)addr;
    uint8_t* addr_r = pmem + addrr;
    uint32_t temp = *(uint32_t *)addr_r;

    return temp;
  return 0;
}

extern "C" void pmem_write(int addr, char mask, int data) {

  paddr_t addr_r = (paddr_t)addr;
  word_t data_r = (word_t)data;
  uint8_t mask_r = (uint8_t)mask;

  if(mask_r == 0x01){
    // printf("%08x, %02x, %08x\n", addr_r, mask, data); 
    pmem[addr_r] = (uint8_t)(data_r & 0x000000FF);
  }
  else if(mask_r == 0x02){
    // printf("%08x, %08x\n", addr_r, data);
    pmem[addr_r + 1] = (uint8_t)((data_r & 0x0000FF00) >> 8);
  }
  else if(mask_r == 0x04){
    // printf("%08x, %08x\n", addr_r, data);
    pmem[addr_r + 2] = (uint8_t)((data_r & 0x00FF0000) >> 16);
  }
  else if(mask_r == 0x08){
    // printf("%08x, %08x\n", addr_r, data);
    pmem[addr_r + 3] = (uint8_t)((data_r & 0xFF000000) >> 24);
  }
  else if(mask_r == 0x03){
    // printf("%08x, %08x\n", addr_r, data);
    pmem[addr_r] = (uint8_t)((data_r & 0x000000FF));
    pmem[addr_r + 1] = (uint8_t)((data_r & 0x0000FF00) >> 8);
  }
  else if(mask_r == 0x0C){
    // printf("%08x, %08x\n", addr_r, data);
    pmem[addr_r + 2] = (uint8_t)((data_r & 0x00FF0000) >> 16);
    pmem[addr_r + 3] = (uint8_t)((data_r & 0xFF000000) >> 24);
  }
  else if(mask_r == 0x0F){
    // printf("%08x, %08x\n", addr_r, data);
    pmem[addr_r] = (uint8_t)((data_r & 0x000000FF));
    pmem[addr_r + 1] = (uint8_t)((data_r & 0x0000FF00) >> 8);
    pmem[addr_r + 2] = (uint8_t)((data_r & 0x00FF0000) >> 16);
    pmem[addr_r + 3] = (uint8_t)((data_r & 0xFF000000) >> 24);
  }
  else{
    printf("wrong: mask = %02x\n", mask);
    assert(0);
  }
}

// extern "C" int pmem_read_v(int addr, char len){
//   paddr_t addr_r = (paddr_t)addr;
//   word_t ret = 0x00000000;
//   uint64_t us = get_time();

//   if(addr_r == CONFIG_RTC_MMIO){
//     ret = (uint32_t)us;
//     // printf("80 mark\n");
//     difftest_skip_ref();
//   }
//   else if(addr_r == CONFIG_RTC_MMIO + 4){
//     ret = us >> 32;
//     difftest_skip_ref();
//   }
//   else if(addr_r == CONFIG_TIME){
//     time(&raw_time);
//     time_info = localtime(&raw_time);
//     ret = (uint32_t)time_info->tm_sec;
//     difftest_skip_ref();
//   }
//   else if(addr_r == CONFIG_TIME + 4){
//     time(&raw_time);
//     time_info = localtime(&raw_time);
//     ret = (uint32_t)time_info->tm_min;
//     difftest_skip_ref();
//   }
//   else if(addr_r == CONFIG_TIME + 8){
//     time(&raw_time);
//     time_info = localtime(&raw_time);
//     ret = (uint32_t)time_info->tm_hour;
//     difftest_skip_ref();
//   }
//   else if(addr_r == CONFIG_TIME + 12){
//     time(&raw_time);
//     time_info = localtime(&raw_time);
//     ret = (uint32_t)time_info->tm_mday;
//     difftest_skip_ref();
//   }
//   else if(addr_r == CONFIG_TIME + 16){
//     time(&raw_time);
//     time_info = localtime(&raw_time);
//     ret = (uint32_t)time_info->tm_mon;
//     difftest_skip_ref();
//   }
//   else if(addr_r == CONFIG_TIME + 20){
//     time(&raw_time);
//     time_info = localtime(&raw_time);
//     ret = (uint32_t)time_info->tm_year;
//     difftest_skip_ref();
//   }
//   else{
//     ret = pmem_read(addr_r, (uint8_t)len);
//   }
//   return (int)ret;
// }

// extern "C" void pmem_write_v(int addr, char mask, int data){
//   paddr_t addr_r = (paddr_t)addr;
//   word_t data_r = (word_t)data;
//   uint8_t mask_r = (uint8_t)mask;
//   if (addr_r == CONFIG_SERIAL_MMIO){ // uart
//     char ch = (char)(data & 0x000000ff);
//     putc(ch, stderr);
//     difftest_skip_ref();
//   }
//   else if(addr_r == CONFIG_RTC_MMIO || addr_r == CONFIG_RTC_MMIO + 4){
//     difftest_skip_ref();
//   }
//   else{
//     pmem_write(addr_r, mask_r, data_r);
//   } 
// }

// extern "C" int rand_v(){
//   // return rand() % 16 + 1;
//   return 32;
// }






