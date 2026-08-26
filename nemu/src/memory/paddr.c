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

#if !defined(CONFIG_TARGET_YSYXSOC)
  #if   defined(CONFIG_PMEM_MALLOC)
  static uint8_t *pmem = NULL;
  #else // CONFIG_PMEM_GARRAY
  static uint8_t pmem[CONFIG_MSIZE] PG_ALIGN = {};
  #endif
#else
  #if   defined(CONFIG_PMEM_MALLOC)
  static uint8_t *mrom = NULL;
  static uint8_t *sram = NULL;
  static uint8_t *flash = NULL;
  static uint8_t *psram = NULL;
  static uint8_t *sdram = NULL;
  #else
  static uint8_t mrom[YSYXSOC_MROM_SIZE] PG_ALIGN = {}; //4KB
  static uint8_t sram[YSYXSOC_SRAM_SIZE] PG_ALIGN = {}; //8KB
  static uint8_t flash[YSYXSOC_FLASH_SIZE] PG_ALIGN = {}; //16MB
  static uint8_t psram[YSYXSOC_PSRAM_SIZE] PG_ALIGN = {}; //4MB
  static uint8_t sdram[YSYXSOC_SDRAM_SIZE] PG_ALIGN = {}; //32MB
  #endif
#endif



#if !defined(CONFIG_TARGET_YSYXSOC)


#ifdef CONFIG_MTRACE
#include <SDL2/SDL.h>
#define SCREEN_W 1920
#define SCREEN_H 1080
static SDL_Renderer *renderer = NULL;
static uint8_t is_init_mem_screen = 0;
static SDL_Texture *texture = NULL;
static void *mtrace_mem = NULL;
static void init_mem_screen() {
  mtrace_mem = malloc(SCREEN_W * SCREEN_H * sizeof(uint32_t));
  assert(mtrace_mem);
  memset(mtrace_mem, 0x004b, SCREEN_W * SCREEN_H * sizeof(uint32_t));
  SDL_Window *window = NULL;
  char title[128];
  sprintf(title, "%s-MTrace", str(__GUEST_ISA__));
  SDL_Init(SDL_INIT_VIDEO);
  SDL_CreateWindowAndRenderer(
      SCREEN_W,
      SCREEN_H,
      0, &window, &renderer);
  SDL_SetWindowTitle(window, title);
  texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888,
      SDL_TEXTUREACCESS_STATIC, SCREEN_W, SCREEN_H);
  SDL_RenderPresent(renderer);
}

static inline void update_mem_screen() {
  SDL_UpdateTexture(texture, NULL, mtrace_mem, SCREEN_W * sizeof(uint32_t));
  SDL_RenderClear(renderer);
  SDL_RenderCopy(renderer, texture, NULL, NULL);
  SDL_RenderPresent(renderer);
}
#endif


typedef enum{MEMREAD,MEMWRITE} mtrace_t;
static void print_mtrace(mtrace_t op,paddr_t addr,uint32_t val){
#ifdef CONFIG_MTRACE
  if(!is_init_mem_screen){
    init_mem_screen();
    is_init_mem_screen = 1;
  }

  if(nemu_state.state != NEMU_RUNNING) return;
  #if   defined(CONFIG_MTRACE_RANGE)
    if(!(addr>=CONFIG_MTRACE_RANGE_START && addr<=CONFIG_MTRACE_RANGE_END)) return;
  #endif
  static uint32_t mtrace_skip_cnt = 0;
  
  if(mtrace_skip_cnt ++ > 5000){
    mtrace_skip_cnt = 0;
    update_mem_screen();
  }
  uint32_t pix_index = (((addr - PMEM_LEFT)) % (SCREEN_W * SCREEN_H));
  ((uint32_t*)mtrace_mem)[pix_index] = val;
  
  if(op==MEMREAD){
    // Log("MEMTracer: READ  memory [0x%08x] = '0x%08x' at pc = '0x%08x'",addr,val,cpu.pc);
  }
  if(op==MEMWRITE){
    // Log("MEMTracer: WRITE memory [0x%08x] = '0x%08x' at pc = '0x%08x'",addr,val,cpu.pc);
  }

#endif
}

uint8_t* guest_to_host(paddr_t paddr) { return pmem + paddr - CONFIG_MBASE; }
paddr_t host_to_guest(uint8_t *haddr) { return haddr - pmem + CONFIG_MBASE; }

static word_t pmem_read(paddr_t addr, int len) {
  word_t ret = host_read(guest_to_host(addr), len);
  return ret;
}

static void pmem_write(paddr_t addr, int len, word_t data) {
  host_write(guest_to_host(addr), len, data);
}

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

word_t paddr_read(paddr_t addr, int len) {
  if (likely(in_pmem(addr))){
    uint32_t val = pmem_read(addr, len);
    print_mtrace(MEMREAD,addr,val);
    return val;
  }
  IFDEF(CONFIG_DEVICE, return mmio_read(addr, len));
  out_of_bound(addr);
  return 0;
}

void paddr_write(paddr_t addr, int len, word_t data) {
  if (likely(in_pmem(addr))) {
    print_mtrace(MEMWRITE,addr,data);
    pmem_write(addr, len, data);
    return;
  }
  IFDEF(CONFIG_DEVICE, mmio_write(addr, len, data); return);
  out_of_bound(addr);
}

#else//////////////////////////////////////////////////////////////////////////////////

typedef enum{MEMREAD,MEMWRITE} mtrace_t;
void print_mtrace(mtrace_t op,paddr_t addr,uint32_t val,int len){
#ifdef CONFIG_MTRACE

  if(nemu_state.state != NEMU_RUNNING) return;
  #if   defined(CONFIG_MTRACE_RANGE)
    if(!(addr>=CONFIG_MTRACE_RANGE_START && addr<=CONFIG_MTRACE_RANGE_END)) return;
  #endif
  #ifdef CONFIG_TRACE_FILE_LOG
  static bool mtrace_log_init = false;
  static FILE *mtrace_log_fp = NULL;
  if(!mtrace_log_init){
    if (mtrace_log_fp == NULL) {
      FILE *fp = fopen("mtrace.log", "w");
      Assert(fp, "Can not open '%s'", "./mtrace.log");
      mtrace_log_fp = fp;
    }
    Log("MTrace log is written to %s", "./mtrace.log");
    mtrace_log_init = true;
  }
  uint32_t s;
  if(op==MEMREAD){
    s=0;
    fwrite(&addr, sizeof(addr), 1, mtrace_log_fp);
    fwrite(&s, sizeof(uint32_t), 1, mtrace_log_fp);
  }
  if(op==MEMWRITE){
    s=1;
    fwrite(&addr, sizeof(addr), 1, mtrace_log_fp);
    fwrite(&s, sizeof(uint32_t), 1, mtrace_log_fp);
  }
  

  #endif
  if(op==MEMREAD){
    Log("MEMTracer: READ  memory [0x%08x] = '0x%08x' at pc = '0x%08x' len = %d",addr,val,cpu.pc,len);
  }
  if(op==MEMWRITE){
    Log("MEMTracer: WRITE memory [0x%08x] = '0x%08x' at pc = '0x%08x' len = %d",addr,val,cpu.pc,len);
  }

#endif
}

static void out_of_bound(paddr_t addr) {
  panic("address = " FMT_PADDR " is out of bound at pc = " FMT_WORD,
      addr, cpu.pc);
}

uint8_t* guest_to_host(paddr_t paddr) {
  if(paddr >= YSYXSOC_MROM_LEFT && paddr <= YSYXSOC_MROM_RIGHT){
    return mrom + paddr - YSYXSOC_MROM_LEFT;
  }else if(paddr >= YSYXSOC_SRAM_LEFT && paddr <= YSYXSOC_SRAM_RIGHT){
    return sram + paddr - YSYXSOC_SRAM_LEFT;
  }else if(paddr >= YSYXSOC_PSRAM_LEFT && paddr <= YSYXSOC_PSRAM_RIGHT){
    return psram + paddr - YSYXSOC_PSRAM_LEFT;
  }else if(paddr >= YSYXSOC_SDRAM_LEFT && paddr <= YSYXSOC_SDRAM_RIGHT){
    return sdram + paddr - YSYXSOC_SDRAM_LEFT;
  }else if(paddr >= YSYXSOC_FLASH_LEFT && paddr <= YSYXSOC_FLASH_RIGHT){
    return flash + paddr - YSYXSOC_FLASH_LEFT;
  }else{
    
    out_of_bound(paddr);
  }
  return NULL;
}
paddr_t host_to_guest(uint8_t *haddr) {
  if(haddr >= mrom && haddr < mrom + YSYXSOC_MROM_SIZE){
    return haddr - mrom + YSYXSOC_MROM_LEFT;
  }else if(haddr >= sram && haddr < sram + YSYXSOC_SRAM_SIZE){
    return haddr - sram + YSYXSOC_SRAM_LEFT;
  }else if(haddr >= psram && haddr < psram + YSYXSOC_PSRAM_SIZE){
    return haddr - psram + YSYXSOC_PSRAM_LEFT;
  }else if(haddr >= sdram && haddr < sdram + YSYXSOC_SDRAM_SIZE){
    return haddr - sdram + YSYXSOC_SDRAM_LEFT;
  }else if(haddr >= flash && haddr < flash + YSYXSOC_FLASH_SIZE){
    return haddr - flash + YSYXSOC_FLASH_LEFT;
  }else{
    out_of_bound(host_to_guest(haddr));
  }
  return 0;
}

static word_t pmem_read(paddr_t addr, int len) {
  word_t ret = host_read(guest_to_host(addr), len);
  return ret;
}

static void pmem_write(paddr_t addr, int len, word_t data) {
  host_write(guest_to_host(addr), len, data);
}



void init_mem() {
  #if   defined(CONFIG_PMEM_MALLOC)
    mrom = malloc(YSYXSOC_MROM_SIZE);
    assert(mrom);
    sram = malloc(YSYXSOC_SRAM_SIZE);
    assert(sram);
    flash = malloc(YSYXSOC_FLASH_SIZE);
    assert(flash);
    psram = malloc(YSYXSOC_PSRAM_SIZE);
    assert(psram);
    sdram = malloc(YSYXSOC_SDRAM_SIZE);
    assert(sdram);
  #endif
    IFDEF(CONFIG_MEM_RANDOM, memset(sram, rand(), YSYXSOC_SRAM_SIZE));
    IFDEF(CONFIG_MEM_RANDOM, memset(mrom, rand(), YSYXSOC_MROM_SIZE));
    IFDEF(CONFIG_MEM_RANDOM, memset(flash, rand(), YSYXSOC_FLASH_SIZE));
    IFDEF(CONFIG_MEM_RANDOM, memset(psram, rand(), YSYXSOC_PSRAM_SIZE));
    IFDEF(CONFIG_MEM_RANDOM, memset(sdram, rand(), YSYXSOC_SDRAM_SIZE));
    Log("mrom memory area [" FMT_PADDR ", " FMT_PADDR "]", YSYXSOC_MROM_LEFT, YSYXSOC_MROM_RIGHT);
    Log("sram memory area [" FMT_PADDR ", " FMT_PADDR "]", YSYXSOC_SRAM_LEFT, YSYXSOC_SRAM_RIGHT);
    Log("flash memory area [" FMT_PADDR ", " FMT_PADDR "]", YSYXSOC_FLASH_LEFT, YSYXSOC_FLASH_RIGHT);
    Log("psram memory area [" FMT_PADDR ", " FMT_PADDR "]", YSYXSOC_PSRAM_LEFT, YSYXSOC_PSRAM_RIGHT);
    Log("sdram memory area [" FMT_PADDR ", " FMT_PADDR "]", YSYXSOC_SDRAM_LEFT, YSYXSOC_SDRAM_RIGHT);
    
}

word_t paddr_read(paddr_t addr, int len) {
  if (likely(in_pmem(addr))){
    
    uint32_t val = pmem_read(addr, len);
    
    return val;
  }
  IFDEF(CONFIG_DEVICE, return mmio_read(addr, len));
  out_of_bound(addr);
  return 0;
}

void paddr_write(paddr_t addr, int len, word_t data) {
  if (likely(in_pmem(addr))) {
    pmem_write(addr, len, data);
    
    return;
  }
  IFDEF(CONFIG_DEVICE, mmio_write(addr, len, data); return);
  out_of_bound(addr);
}
#endif