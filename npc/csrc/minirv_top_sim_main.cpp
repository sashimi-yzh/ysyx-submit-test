#include "Vminirv_top.h"
#include "verilated.h"
#include "verilated_fst_c.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <sys/time.h>
#define SERIAL_ADDR     0xa00003f8
#define UPDATE_ADDR        0xa0000048

#define CONFIG_MSIZE            0x8000000  // 128MB
bool trap = false;
static struct timeval tv;
static long int start_time;
static uint8_t mem[CONFIG_MSIZE] = {};
extern "C" int pmem_read(int raddr) {
  // 总是读取地址为`raddr & ~0x3u`的4字节返回
  if (raddr == UPDATE_ADDR || raddr == UPDATE_ADDR + 4) {
    // rct
    gettimeofday(&tv, NULL);
    long int cur_time = tv.tv_sec * 1000000 + tv.tv_usec - start_time;
    return (raddr == UPDATE_ADDR) ? cur_time & 0xffffffff : (cur_time >> 32) & 0xffffffff;
  }
  else {
    raddr &= ~0x3u;
    raddr &= 0x7ffffff;
    if((uint32_t)raddr >= CONFIG_MSIZE) {
      printf("raddr: 0x%08x out of mem\n", (uint32_t)raddr);
      exit(1);
    }
  }
  return mem[raddr] | (mem[raddr+1] << 8) | (mem[raddr+2] << 16) | (mem[raddr+3] << 24);
}

extern "C" void npctrap(int a0) {
  if(a0 == 0) printf("\33[1;32mHIT GOOD TRAP\033[0m\n");
  else printf("\033[1;31mHIT BAD TRAP\033[0m\n");
  trap = true;
}

extern "C" void pmem_write(int waddr, int wdata, char wmask) {
  if (waddr == SERIAL_ADDR) {
    // serial
    putchar(wdata);
  }
  else {
    waddr &= ~0x3u;
    waddr &= 0x7ffffff;
    if((uint32_t)waddr >= CONFIG_MSIZE) {
      printf("waddr: 0x%08x out of mem\n", (uint32_t)waddr);
      exit(1);
    }
    if(wmask & 0x1) mem[waddr] = (wdata >>  0) & 0xff;
    if(wmask & 0x2) mem[waddr + 1] = (wdata >>  8) & 0xff;
    if(wmask & 0x4) mem[waddr + 2] = (wdata >> 16) & 0xff;
    if(wmask & 0x8) mem[waddr + 3] = (wdata >> 24) & 0xff;
  }
  // 总是往地址为`waddr & ~0x3u`的4字节按写掩码`wmask`写入`wdata`
  // `wmask`中每比特表示`wdata`中1个字节的掩码,
  // 如`wmask = 0x3`代表只写入最低2个字节, 内存中的其它字节保持不变
}

int main(int argc, char** argv) {
  gettimeofday(&tv, NULL);
  start_time = tv.tv_sec * 1000000 + tv.tv_usec;
  if(argc == 1){
    printf("please appoint img\n");
    return 0;
  }
  char filename[1024];
  strcpy(filename, argv[1]);
  FILE *fp = fopen(filename, "rb");
  if(fp == NULL) {
    printf("file not found\n");
    return 0;
  }
  size_t items = fread(mem, sizeof(uint8_t), CONFIG_MSIZE, fp);
  if(strcmp(filename, "resource/mem.bin") == 0){
      mem[0x1220] = 0x73;
      mem[1 + 0x1220] = 0;
      mem[2 + 0x1220] = 0x10;
      mem[3 + 0x1220] = 0;
  }
  else if(strcmp(filename, "resource/sum.bin") == 0){
      mem[0x228] = 0x73;
      mem[1 + 0x228] = 0;
      mem[2 + 0x228] = 0x10;
      mem[3 + 0x228] = 0;
  }
  printf("load file success, items: %lu\n", items);
  fclose(fp);
  
  // 顶层模块定义
  VerilatedContext* contextp = new VerilatedContext;
  contextp->commandArgs(argc, argv);
  Vminirv_top* minirv_top = new Vminirv_top{contextp};

  // 导出波形图
  Verilated::traceEverOn(true);
  VerilatedFstC* tfp = new VerilatedFstC;
  minirv_top->trace(tfp, 99);
  tfp->open("waveform/minirv_top_waveform.fst");
  minirv_top->clk = 0;
  while (!contextp->gotFinish()) {
    if(trap) break;
    // 先更新时钟
    minirv_top->clk = ~minirv_top->clk;
    minirv_top->eval();
    contextp->timeInc(1);
    tfp->dump(contextp->time());
  }
  tfp->close();
  delete minirv_top;
  delete contextp;
  return 0;
}
