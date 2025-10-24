#include "../include/paddr.h"
#include "VysyxSoCFull.h"
#include "../obj_dir/VysyxSoCFull___024root.h"
#include "../include/common.h"
#include "../include/debug.h"
#include "../include/reg.h"
#include "../include/utils.h"
#include "../include/device/mmio.h"


/********extern functions or variables********/
extern VysyxSoCFull *top;
extern vluint64_t main_time;
// extern void ebreak(int station, int inst);
// extern NPCState npc_state;
extern void die();
/*********************************************/



uint8_t pmem[CONFIG_MSIZE] PG_ALIGN = {};
// static const word_t img[] = {
//   0x80001137,          // lui   sp, 0x80001       // sp = 0x80001000（高位设为 0x80001）
//   0xffc10113,          // addi  sp, sp, -4        // sp = 0x80001000 - 4 = 0x80000ffc（合法地址）
//   0x06400593,          // li    a1, 100           // a1 = 100
//   0x03258613,          // addi  a2, a1, 50        // a2 = 150
//   0x00c12023,          // sw    a2, 0(sp)         // 地址: 0x80000ffc
//   0x00012683,          // lw    a3, 0(sp)         // 地址: 0x80000ffc
//   0x06468693,          // addi  a3, a3, 100       // a3 = 250
//   0xf0068713,          // addi  a4, a3, -256      // a4 = -6
//   0x00e61463,          // bne   a2, a4, 8         // 条件跳转
//   0x00100073,          // ebreak                  // 触发调试
//   0x80000297,          // auipc t0, 0x80000       // t0 = 0x80000000 + PC
//   0x00428293,          // addi  t0, t0, 4         // t0 += 4
//   0x00c58863,          // bne   a1, a2, 16        // 条件跳转
//   0x06458593,          // addi  a1, a1, 100       // a1 = 200（跳过）
//   0x00100073,          // ebreak                  // 触发调试
//   0xdeadbeef           // 数据段：0xdeadbeef
// };
static const uint32_t img [] = {
  0x100007b7, //lui a5, 268435456
  0x04100713, //addi a4, zero, 65
  0x00e78023, //sb a4, 0(a5)
  0x100007b7, //lui a5, 268435456
  0x00a00713, //addi a4, zero, 10
  0x00e78023, //sb a4, 0(a5)
  0x00100073,
  // 0x00000297,  // auipc t0,0
  // 0x00028823,  // sb  zero,16(t0)
  // 0x0102c503,  // lbu a0,16(t0)
  // 0x00100073,  // ebreak (used as nemu_trap)
  // 0xdeadbeef,  // some data
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
        fprintf(mtrace_file,"R 0x%08x 0x%08x %d\n",addr,data,len);
        break;
    case 'W':
        fprintf(mtrace_file,"W 0x%08x 0x%08x %d\n",addr,data,len);
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
  printf("[npc]address = 0x%08x is out of bound of pmem [0x%08x, 0x%08x] at pc = 0x%08x  time = %ld\n", 
         addr, PMEM_LEFT, PMEM_RIGHT, top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__pc, main_time);
  npc_state.state=NPC_ABORT;
  // die();
  // _Log(ANSI_FG_RED "address = 0x%08x is out of bound of pmem [0x%08x, 0x%08x] at pc = 0x%08x  time = %ld", 
  //        addr, PMEM_LEFT, PMEM_RIGHT, top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__pc_now, main_time ANSI_NONE);
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
  memset(pmem, 0, CONFIG_MSIZE);
  // Log("physical memory area [0x%08x, 0x%08x]", PMEM_LEFT, PMEM_RIGHT);
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
}
