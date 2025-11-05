#include "color.h"
#include "fmt-def.h"
#include "stdlib.h"
#include <stdint.h>
#include <svdpi.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <time.h>
#include <assert.h>
#include "vpi_user.h"
#include <stddef.h>

typedef uint32_t word_t;
typedef uint32_t paddr_t;

#define CONFIG_MSIZE (8*1024*1024)
#define CONFIG_MBASE 0x80000000

bool img_init = false;


static uint8_t pmem[CONFIG_MSIZE] = {};

uint8_t* guest_to_host(paddr_t paddr) { return pmem + paddr - CONFIG_MBASE; }
paddr_t host_to_guest(uint8_t *haddr) { return haddr - pmem + CONFIG_MBASE; }

#ifndef NETLIST
const char* pc = "tb.soc.dut.asic.cpu.cpu.cpu_npc.idu.io_in_bits_pc";
#else
const char* pc = NULL;
#endif 
// const char* img_file = "./img/sum-riscv32e-ysyxsoc.bin";
const char* img_file = "./img/microbench-riscv32e-ysyxsoc_test.bin";



const char* get_pc(){
  vpiHandle handle;
  s_vpi_value value_s;

  handle = vpi_handle_by_name(pc, NULL);
  if (!handle) {
    printf("Error: Cannot find %s\n", pc);
    fflush(stdout);
    return NULL;
  }
  value_s.format = vpiHexStrVal;
  vpi_get_value(handle, &value_s);
  return value_s.value.str;
}

const char* get_reg(int i){
  char buf[100];
  sprintf(buf, "tb.soc.dut.asic.cpu.cpu.cpu_npc.regfile.regs_ext.Memory[%d]", i);
  vpiHandle handle;
  s_vpi_value value_s;

  handle = vpi_handle_by_name(buf, NULL);
  if (!handle) {
	  printf("Error: Cannot find %s\n", buf);
    fflush(stdout);
    return NULL;
  }
  value_s.format = vpiHexStrVal;
  vpi_get_value(handle, &value_s);
  return value_s.value.str;
}



void load_img(){
  if(!img_init){
    FILE *fp = fopen(img_file, "rb");

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);

    printf("LOAD_IMG: The image is %s, size = %ld\n", img_file, size);
    fflush(stdout);
    fseek(fp, 0, SEEK_SET);
    int ret = fread(guest_to_host(CONFIG_MBASE), size, 1, fp);
    assert(ret == 1);

    fclose(fp);
    img_init = true;
  }
}


static inline word_t host_read(void *addr, int len) {
  load_img();
  switch (len) {
    case 1: return *(uint8_t  *)addr;
    case 2: return *(uint16_t *)addr;
    case 4: return *(uint32_t *)addr;
//#IFDEF(CONFIG_ISA64, case 8: return *(uint64_t *)addr);
//    default: MUXDEF(CONFIG_RT_CHECK, assert(0), return 0);
    default : assert(0);
  }
}

static inline void host_write(void *addr, int len, word_t data) {
  load_img();
  switch (len) {
    case 1: *(uint8_t  *)addr = data; return;
    case 2: *(uint16_t *)addr = data; return;
    case 4: *(uint32_t *)addr = data; return;
//    IFDEF(CONFIG_ISA64, case 8: *(uint64_t *)addr = data; return);
//IFDEF(CONFIG_RT_CHECK, default: assert(0));
    default: assert(0);
  }
}




void npc_ebreak(){
	//NPCTRAP(PC, REGS[10]);
	//
	//
  printf("EBREAK!\n");
//#ifndef NETLIST
//  int isgood = !strcmp("00000000",get_reg(10));
//  if(isgood){
//  	printf("npc: " L_GREEN  "HIT GOOD TRAP" COLOR_NONE " at pc = 0x%s\n" , get_pc());
//  }else{
//  	printf("npc: " L_RED    "HIT BAD TRAP" COLOR_NONE " at pc = 0x%s\n" , get_pc());
//  }
//#endif
  fflush(stdout);
  vpi_control(vpiFinish, 1);
  exit(0);
}


 void inst_invalid(){
	// if(npc_state.state == NPC_ABORT)
	// 	return;
	// char logbuf[64];
	// word_t pc = PC;
	//printf(L_RED "%s" COLOR_NONE "\n", isa_logo);
	printf(L_RED "Invalid or Unimplemented Inst" COLOR_NONE "\n");
  //printf("0x" FMT_WORD_HEX_WIDTH ":    ", PC);
  fflush(stdout);
  
  
  // for(int j = 3; j >= 0; j--){
  //   printf("%02x ", ((uint8_t*)(&INST))[j]);
  // }
  // fflush(stdout);
  // printf("\n");
  //disassemble(logbuf, 64, PC , (uint8_t*)(&INST), 4);
  //printf("%s\n", logbuf);
	//set_npc_state(NPC_ABORT, PC, -1);
}

uint64_t get_rtc_time(){
  time_t t = time(NULL);
  return t;
}


int get_inst(int pc){
  return pmem_read(pc);
}



 int pmem_read(int raddr){

  
  if(raddr < CONFIG_MBASE || raddr > CONFIG_MBASE + CONFIG_MSIZE)
    return 0;
  
#ifdef CONFIG_MTRACE
  static word_t addr_last  = 0;
  if(addr_last != raddr){
    printf("--------MTRACE---------\n");
    //print_memread(raddr, 4);
    addr_last = raddr;
  }
#endif 
  
  word_t data = host_read(guest_to_host(raddr), 4);
  return data;
}






 void pmem_write(int waddr, int wdata, char wmask){
  //waddr = waddr - 0x80000000;
  ///static memwrite_info mwinfo;   //防止多次输出
  
  if(waddr < CONFIG_MBASE){
    printf(L_RED "WARNING: %s waddr = 0x%x < CONFIG_MBASE" COLOR_NONE "\n", __func__, waddr);
    return;
  }

    if (waddr > CONFIG_MBASE + CONFIG_MSIZE){
      return;
    }

    #ifdef CONFIG_MTRACE
    printf("--------MTRACE---------\n");
    printf("wmask = 0x%x\n", wmask);
    //print_memwrite_wmask(waddr, wdata, wmask);
    #endif

    for(int i = 0; i < 4; i++){
      if(wmask & (1 << i)){
        host_write(guest_to_host(waddr + i), 1, (wdata >> (i * 8)) & 0xff);
      }
    }


}



 void flash_read(int32_t addr, int32_t *data) {

 //*data = addr ;
 *data = host_read(guest_to_host(CONFIG_MBASE + (addr& ~0x3u)), 4);
 //printf("read flash addr = %x, data = %08x\n", addr, *data);

}
 void mrom_read(int32_t addr, int32_t *data) {
  //*data =0x100073; // ebreak

  *data = host_read(guest_to_host(CONFIG_MBASE + (addr& ~0x3u)) - 0x20000000, 4);
 // *data = 0x00e78023;

}

 void axi_error(unsigned char errno, unsigned char isRead) {
  printf(L_RED "AXI ERROR: errno = %x, isRead = %d" COLOR_NONE "\n", errno, isRead);
  //set_npc_state(NPC_ABORT, PC, -1);
  exit(-1);
}

uint8_t psram[1024*1024*4]; // 4MB PSRAM

 void psram_write(int addr, int data, char wmask) {
  //addr = addr / 4 * 4;
  for(int i = 0; i < 4; i++){
    if(wmask & (1 << i)){
      *(psram + addr + i) = (data >> (i * 8)) & 0xff;
    }
  }
  //printf("write psram addr = %x, data = %x, wmask = %0x\n", addr, data, wmask);
}

 int psram_read(int addr) {
  //addr = addr / 4 * 4;
  //printf("read psram addr = %x, data = %x\n", addr, *((uint32_t*)(psram + addr)));
  return *((uint32_t*)(psram + addr));
}


// block_num: bank: row: col
uint16_t sdram [4][4][8192][512];

/*
int sdram_read(input byte bank, input int row, input int col,
               input byte block_num);
void sdram_write(input byte bank, input int row, input int col,
                 input int wdata, input byte wmask, input byte block_num);
*/

 int sdram_read(char bank, int row, int col, char block_num) {
  //printf("sdram_read bank = %d, row = %d, col = %d, block_num = %d, data = %x\n", bank, row, col, 
  //              block_num, sdram[block_num][bank][row][col]);
  return sdram[(int)block_num][(int)bank][row][col];
}

 void sdram_write(char bank, int row, int col , int wdata, char wmask, char block_num) {

  if(wmask > 3){
    printf("ERROR, Can only write 1/2 bytes at once, wmask = %d\n", wmask);
  }

  for(int i = 0; i < 2; i++){
    if(wmask & (1 << i)){
      sdram[(int)block_num][(int)bank][row][col] &= ~(0xff << (i * 8));
      sdram[(int)block_num][(int)bank][row][col] |= ((wdata >> (i * 8)) & 0xff) << (i * 8);
    }
  }

  //printf("sdram_write bank = %d, row = %d, col = %d, block_num = %d, wdata = %x, wmask = %x\n", bank, row, col,
  //               block_num, wdata, wmask);
}

