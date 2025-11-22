#include "../include/paddr.h"
#include "../include/common.h"
#include "../include/debug.h"
#include "../include/reg.h"
#include "../include/utils.h"
#include "../include/device/mmio.h"

#ifdef YSYXSOC
#include "VysyxSoCFull.h"
#include "../obj_dir/VysyxSoCFull___024root.h"
extern VysyxSoCFull *top;
#else
#include "Vysyx_25010030_npc.h"
#include "../obj_dir/Vysyx_25010030_npc___024root.h"
extern Vysyx_25010030_npc *top;
#endif


/********extern functions or variables********/
extern vluint64_t main_time;
// extern void ebreak(int station, int inst);
// extern NPCState npc_state;
extern void die();
/*********************************************/



uint8_t pmem[CONFIG_MSIZE] PG_ALIGN = {};

//riscv指令集在线反汇编工具
//https://luplab.gitlab.io/rvcodecjs/#q=34179073&abi=false&isa=AUTO
static const uint32_t img [] = {
  // 测试1：divu 10 / 3 → 商=3（0x3），写入地址0x10000000
  0xa00007b7, // lui a5, 0x10000      // a5 = 0x10000000（目标内存基地址）
  0x00a00613, // addi a2, zero, 10    // a2 = 10（被除数）
  0x00300593, // addi a1, zero, 3     // a1 = 3（除数）
  // 0x00560433, // divu a0, a2, a1      // a0 = 10 / 3（无符号商=3）
  // 0x03e50513, // addi a0, a0, 38      // a0 = 商 + 38 = 41 (ASCII 'A')
  // 0x00a78023, // sb a0, 0(a5)   
  0x02b656b3, // divu a3, a2, a1      // a3 = 10 / 3（无符号商=3）
  0x03e50693, // addi a3, a3, 62      // a3 = 商 + 62 = 65 (ASCII 'A')
  0x00d78023, // sb a3, 0(a5)         // 商3写入0x10000000
  
  0x00100073, // 系统调用/退出指令    

  // // 输出 'A' (ASCII码 65)
  // 0xa00007b7, // lui a5, 0x10000      // 设置内存地址高位（0x10000000）
  // 0x04100713, // addi a4, zero, 65    // a4 = 'A'的ASCII码
  // 0x00e78023, // sb a4, 0(a5)         // 将'A'写入地址0x10000000
  
  // // 输出 'B' (ASCII码 66)
  // 0xa00007b7, // lui a5, 0x10000      // 同一地址高位
  // 0x04200713, // addi a4, zero, 66    // a4 = 'B'的ASCII码
  // 0x00e78023, // sb a4, 1(a5)         // 将'B'写入地址0x10000001（下一个字节）
  
  // // 输出 'C' (ASCII码 67)
  // 0xa00007b7, // lui a5, 0x10000      // 同一地址高位
  // 0x04300713, // addi a4, zero, 67    // a4 = 'C'的ASCII码
  // 0x00e78023, // sb a4, 2(a5)         // 将'C'写入地址0x10000002（再下一个字节）
  
  // // 原代码中的其他指令（保持不变）
  // 0x100007b7, // lui a5, 268435456
  // 0x00a00713, // addi a4, zero, 10
  // 0x00e78023, // sb a4, 0(a5)
  // 0x00100073, // 系统调用/退出指令
  
//   0x00000513,          	//li	a0,0
//   0x100005b7,          	//lui	a1,0x10000
//   0x04100313,          	//li	t1,65
//   0x00000617,          	//auipc	a2,0x0
//   0x01060613,          	//addi	a2,a2,16 # a000001c <again>
//   0x000083b7,          	//lui	t2,0x8
//   0x06738393,          	//addi	t2,t2,103 # 8067 <_stack_size+0x7c67>

//  //<again>:
//   0x00658023,          	//sb	t1,0(a1) # 10000000 <_sram_end+0xffe000>
//   0x00762023,          	//sw	t2,0(a2)
//   0x0000100f,          	//.4byte	0x100f
//   0xff5ff06f,          	//j	a000001c <again>  
//   0x00000513,          	//li	a0,0
//   0x00008067,          	//ret
};
#define MTRACE_LOG_FILE "mtrace.log"
static FILE *mtrace_file=NULL;

void init_mtrace(){
  mtrace_file=fopen(MTRACE_LOG_FILE,"w");
  if(mtrace_file==NULL){
    printf("Fail to open mtrace log file\n");
    return;
  }
  // 初始化 mtrace_thing
  // mtrace_thing.start=0x00000000;
  // mtrace_thing.end=0xFFFFFFFF;
  // mtrace_thing.filter_en=false;
  // mtrace_thing.filter_data=0xFFFFFFFF;
}

void close_mtrace(){
  if(mtrace_file != NULL){
      fclose(mtrace_file);
      mtrace_file = NULL;
  }
}

void mtrace_log(char type,paddr_t addr,word_t data,int len){
  if(mtrace_file==NULL) return;
  // if(addr<mtrace_thing.start || addr>mtrace_thing.end) return;
  // if(mtrace_thing.filter_en && data!=mtrace_thing.filter_data) return;
  switch (type){
    case 'R':
        fprintf(mtrace_file,"[R] 0x%08x    0x%08x %d\n",addr,data,len);
        break;
    case 'W':
        fprintf(mtrace_file,"[W] 0x%08x    0x%08x %d\n",addr,data,len);
        break;
    default:
        printf("No such type,only R or W enable\n");
        break;
  }
}

void mtrace_filter_output(paddr_t start_addr, paddr_t end_addr, bool filter_en, uint32_t filter_data){
    FILE *fp = fopen(MTRACE_LOG_FILE, "r");
    if (fp == NULL) {
        printf("Failed to open mtrace log file\n");
        return;
    }
    char type;
    paddr_t addr;
    uint32_t data;
    int len;
    puts("[mtrace_start]");
    // 逐行读取日志文件
    while(fscanf(fp, " %c 0x%x 0x%x %d",&type,&addr,&data,&len)==4) {
        if (addr < start_addr || addr > end_addr) {
            continue;
        }
        if (filter_en && data != filter_data) {
            continue; 
        }
        printf(" %c 0x%08x value: 0x%08x %d\n", type, addr, data, len);
    }
    fclose(fp);
    puts("[mtrace_end]");
}

uint8_t* guest_to_host(paddr_t paddr) { return pmem + paddr - CONFIG_MBASE; }   //0x8000_0000 -> pmem[0]
paddr_t host_to_guest(uint8_t *haddr) { return haddr - pmem + CONFIG_MBASE; }

uint8_t mrom[CONFIG_SOC_MROM_SIZE] PG_ALIGN = {}; // 4KB MROM
uint8_t flash[CONFIG_SOC_FLASH_SIZE] PG_ALIGN = {}; // 16MB Flash
uint8_t psram[CONFIG_SOC_PSRAM_SIZE] PG_ALIGN = {};
uint8_t sdram[CONFIG_SOC_SDRAM_SIZE] PG_ALIGN = {};
uint8_t* soc_mrom_guest_to_host(paddr_t paddr) { return mrom + paddr - CONFIG_SOC_MROM_BASE; }
uint8_t* soc_flash_guest_to_host(paddr_t paddr) { return flash + paddr - CONFIG_SOC_FLASH_BASE; }
uint8_t* soc_psram_guest_to_host(paddr_t paddr) { return psram + paddr - CONFIG_SOC_PSRAM_BASE; }
uint8_t* soc_sdram_guest_to_host(paddr_t paddr) { return sdram + paddr - CONFIG_SOC_SDRAM_BASE; }

word_t host_read(void *addr, int len) 
{
  switch (len) {
    case 1: return *(uint8_t  *)addr;
    case 2: return *(uint16_t *)addr;
    case 4: return *(uint32_t *)addr;
    IFDEF(CONFIG_ISA64, case 8: return *(uint64_t *)addr;)
    default: assert(0); return 0;
  }
}

void host_write(void *addr, int len, word_t data) {
  switch (len) {
    case 1: *(uint8_t  *)addr = data; return;
    case 2: *(uint16_t *)addr = data; return;
    case 4: *(uint32_t *)addr = data; return;
    IFDEF(CONFIG_ISA64, case 8: *(uint64_t *)addr = data; return;)
    default: assert(0);
  }
}

static inline bool in_pmem(paddr_t addr) {
  return (addr - CONFIG_MBASE < CONFIG_MSIZE);
}

static inline void out_of_bound(paddr_t addr) {
  regs_display();

  #ifdef YSYXSOC
  printf("[npc]address = 0x%08x is out of bound of pmem [0x%08x, 0x%08x] at pc = 0x%08x  time = %ld\n", 
         addr, PMEM_LEFT, PMEM_RIGHT, top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__IF_ID_pc, main_time);
  #else
  printf("[npc]address = 0x%08x is out of bound of pmem [0x%08x, 0x%08x] at pc = 0x%08x  time = %ld\n", 
         addr, PMEM_LEFT, PMEM_RIGHT, top->rootp->ysyx_25010030_npc__DOT__cpu__DOT__IF_ID_pc, main_time);
  #endif

  npc_state.state=NPC_ABORT;
}

word_t pmem_r(paddr_t addr, int len) 
{
#ifdef CONFIG_MTRACE
  mtrace_log('R',addr,host_read(guest_to_host(addr), len),len);
#endif
  // printf("[paddr_read] : addr=0x%08x\n\n",addr);
  if(likely(in_pmem(addr))) return host_read(guest_to_host(addr), len);
  IFDEF(CONFIG_DEVICE, return mmio_read(addr, len));
  out_of_bound(addr);
  return 0;
}

void pmem_w(paddr_t addr, int len, word_t data) 
{
#ifdef CONFIG_MTRACE
  mtrace_log('W',addr,data,len);
#endif
  if(likely(in_pmem(addr)))
  {
    host_write(guest_to_host(addr), len, data);
    return;
  }  
  IFDEF(CONFIG_DEVICE, mmio_write(addr, len, data); return);
  out_of_bound(addr);
}

void init_mem(void) 
{
  // Log("physical memory area [0x%08x, 0x%08x]", PMEM_LEFT, PMEM_RIGHT);
  #ifdef YSYXSOC
  Log("SoC MROM area [0x%08x, 0x%08x]", CONFIG_SOC_MROM_BASE, CONFIG_SOC_MROM_BASE + CONFIG_SOC_MROM_SIZE);
  Log("SoC FLASH area [0x%08x, 0x%08x]", CONFIG_SOC_FLASH_BASE, CONFIG_SOC_FLASH_BASE + CONFIG_SOC_FLASH_SIZE);
  Log("SoC PSRAM area [0x%08x, 0x%08x]", CONFIG_SOC_PSRAM_BASE, CONFIG_SOC_PSRAM_BASE + CONFIG_SOC_PSRAM_SIZE);
  Log("SoC SDRAM area [0x%08x, 0x%08x]", CONFIG_SOC_SDRAM_BASE, CONFIG_SOC_SDRAM_BASE + CONFIG_SOC_SDRAM_SIZE);

  /* Load built-in image. */
  // memcpy(guest_to_host(RESET_VECTOR), img, sizeof(img));

  // memset(mrom, 0, CONFIG_SOC_MROM_SIZE);
  // memcpy(soc_mrom_guest_to_host(CONFIG_SOC_MROM_BASE), img, sizeof(img));
  memset(flash, 0, CONFIG_SOC_FLASH_SIZE);
  memcpy(soc_flash_guest_to_host(CONFIG_SOC_FLASH_BASE), img, sizeof(img));
  #else
  memset(pmem, 0, CONFIG_MSIZE);
  Log("physical memory area [0x%08x, 0x%08x]", PMEM_LEFT, PMEM_RIGHT);
  memcpy(guest_to_host(RESET_VECTOR), img, sizeof(img));
  #endif
}
