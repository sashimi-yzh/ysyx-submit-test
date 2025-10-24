#include "../include/paddr.h"
#include "Vrv32e.h"
#include "../obj_dir/Vrv32e___024root.h"
#include "../include/common.h"
#include "../include/debug.h"
#include "../include/reg.h"
#include "../include/utils.h"
#include "../include/device/mmio.h"


/********extern functions or variables********/
extern Vrv32e *top;
extern vluint64_t main_time;
// extern void ebreak(int station, int inst);
// extern NPCState npc_state;
extern void die();
/*********************************************/



uint8_t pmem[CONFIG_MSIZE] PG_ALIGN = {};
//测试bltu指令
// static const uint32_t img[] = {
//   0x00000513,  // 0x80000000: addi x10, x0, 0        # $a0 = 0
//   0x00500293,  // 0x80000004: addi x5, x0, 5         # x5 = 5
//   0x00a00313,  // 0x80000008: addi x6, x0, 10        # x6 = 10
//   0x0062d663,  // 0x8000000c: bltu x5, x6, 0x8       # 5 < 10，跳转
//   0x00100073,  // 0x80000010: ebreak                 # 失败
//   0x00150513,  // 0x80000014: addi x10, x10, 1       # $a0 += 1
//   0x00a00293,  // 0x80000018: addi x5, x0, 10        # x5 = 10
//   0x00500313,  // 0x8000001c: addi x6, x0, 5         # x6 = 5
//   0x0062d663,  // 0x80000020: bltu x5, x6, 0x8       # 10 > 5，不跳转
//   0x00150513,  // 0x80000024: addi x10, x10, 1       # $a0 += 1
//   0x0000006f,  // 0x80000028: j 0x0                  # 跳转到test3 (0x80000028 + 0x14 = 0x8000003c)
//   0x00100073,  // 0x8000002c: ebreak                 # 失败
//   0x00000293,  // 0x80000030: addi x5, x0, 0         # x5 = 0
//   0x00100313,  // 0x80000034: addi x6, x0, 1         # x6 = 1
//   0x0062d663,  // 0x80000038: bltu x5, x6, 0x8       # 0 < 1，跳转
//   0x00100073,  // 0x8000003c: ebreak                 # 失败
//   0x00150513,  // 0x80000040: addi x10, x10, 1       # $a0 += 1
//   0xfff002b7,  // 0x80000044: lui x5, 0x7fffffff     # x5 = 0x7fffffff000
//   0x0012d293,  // 0x80000048: slli x5, x5, 1         # x5 = 0x7fffffff
//   0x00080337,  // 0x8000004c: lui x6, 0x80000        # x6 = 0x80000000
//   0x0062d663,  // 0x80000050: bltu x5, x6, 0x8       # 0x7fffffff < 0x80000000，跳转
//   0x00100073,  // 0x80000054: ebreak                 # 失败
//   0x00150513,  // 0x80000058: addi x10, x10, 1       # $a0 += 1
//   0x00100073,  // 0x8000005c: ebreak                 # 终止
//   0xdeadbeef,  // 0x80000060: data                   # 数据
// };
static const uint32_t img [] = {
  0x00000297,  // auipc t0,0
  0x00028823,  // sb  zero,16(t0)
  0x0102c503,  // lbu a0,16(t0)
  0x00100073,  // ebreak (used as nemu_trap)
  0xdeadbeef,  // some data
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
         addr, PMEM_LEFT, PMEM_RIGHT, top->rootp->rv32e__DOT__IF_ID_pc, main_time);
  npc_state.state=NPC_ABORT;
  // die();
  // _Log(ANSI_FG_RED "address = 0x%08x is out of bound of pmem [0x%08x, 0x%08x] at pc = 0x%08x  time = %ld", 
  //        addr, PMEM_LEFT, PMEM_RIGHT, top->rootp->rv32e__DOT__pc_now, main_time ANSI_NONE);
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
  Log("physical memory area [0x%08x, 0x%08x]", PMEM_LEFT, PMEM_RIGHT);

  /* Load built-in image. */
  memcpy(guest_to_host(RESET_VECTOR), img, sizeof(img));
}
