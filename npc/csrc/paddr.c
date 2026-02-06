#include <common.h>
//#include <isa.h>
#include <paddr.h>
#include "svdpi.h"
#ifdef YSYXSOC
#include <VysyxSoCFull.h>
#include "VysyxSoCFull__Dpi.h"
extern VysyxSoCFull* top;
#else 
#include <Vysyx_24070003_npc.h>
#include "Vysyx_24070003_npc__Dpi.h"
extern Vysyx_24070003_npc* top;
#endif
#define CONFIG_MTRACE
#define PG_ALIGN __attribute((aligned(4096))) 

#define likely(cond)   __builtin_expect(cond, 1)
#define unlikely(cond) __builtin_expect(cond, 0)

static uint8_t pmem[0x10000000] PG_ALIGN = {};
static uint8_t psram_mem[0x20000000] = {};
#ifdef YSYXSOC
uint8_t* guest_to_host(paddr_t paddr) {  return pmem + paddr - 0x30000000; }
#else 
uint8_t* guest_to_host(paddr_t paddr) {  return pmem + paddr - 0x80000000; }
#endif
uint8_t* guest_to_host_psram(paddr_t paddr) {  return psram_mem + paddr ; }
uint8_t* mrom_to_host(paddr_t paddr) {
    return pmem + paddr - 0x20000000;
}
uint8_t* flash_to_host(paddr_t paddr) {
    return pmem + paddr;
}
paddr_t host_to_guest(uint8_t *haddr) { return haddr - pmem + CONFIG_MBASE; }

static word_t pmem_read(paddr_t addr, int len) {
  
    word_t ret = host_read(guest_to_host(addr), len);

   
    return ret;
}

word_t mrom_read(paddr_t addr, int len) {
  
    word_t ret = host_read(mrom_to_host(addr), len);

   
    return ret;
}

word_t flash_read(paddr_t addr, int len) {
  
    word_t ret = host_read(flash_to_host(addr), len);

    return ret;
}


word_t psram_read(paddr_t addr, int len) {
    word_t ret = host_read(guest_to_host_psram(addr), len);
    //printf("psram_read ret = %x\n", ret);
    return ret;
}

void _psram_write(paddr_t addr,word_t data,int len) {
    
    host_write(guest_to_host_psram(addr), len, data);
}

static void pmem_write(paddr_t addr, int len, word_t data) {
    host_write(guest_to_host(addr), len, data);
#ifdef CONFIG_MTRACE
//      printf("Write: (%08x) = %08lx  \n", addr, data);
#endif
}

void delete_module();



static void out_of_bound(paddr_t addr) {

  //top->clk = !top->clk;
  top->eval();
 
  top->clock = !top->clock;
  top->eval();
 
  delete_module();

    panic("address = " FMT_PADDR " is out of bound of pmem [" FMT_PADDR ", " FMT_PADDR "] at pc = " FMT_WORD,
              addr, (paddr_t)CONFIG_MBASE, (paddr_t)CONFIG_MBASE + CONFIG_MSIZE - 1, cpu.pc);

}

void init_mem() {
  #ifdef CONFIG_PMEM_MALLOC
    printf("CONFIG_PMEM_MALLOC defined\n")
    pmem = malloc(CONFIG_MSIZE);
    assert(pmem);
  #endif
  #ifdef CONFIG_MEM_RANDOM
    printf("CONFIG_PMEM_MALLOC defined\n")
    uint32_t *p = (uint32_t *)pmem;
    int i;
    for( i=0; i<(int)(CONFIG_MSIZE / sizeof(p[0])); i++ ) {
      p[i] = rand();
    }
  #endif

    Log("Physical memory area [" FMT_PADDR ", " FMT_PADDR "]",
      (paddr_t)CONFIG_MBASE, (paddr_t)CONFIG_MBASE + CONFIG_MSIZE - 1);
}

word_t mmio_read(paddr_t addr, int len);
void  mmio_write(paddr_t addr, int len, word_t data);

word_t paddr_read(paddr_t addr, int len) {
  if (likely(in_pmem(addr))) return pmem_read(addr, len);
  
  out_of_bound(addr);
  return 0;
}


void paddr_write(paddr_t addr, int len, word_t data) {
  if (likely(in_pmem(addr))) { pmem_write(addr, len, data); return; }
  
  out_of_bound(addr);
}

static inline word_t vaddr_ifetch(vaddr_t addr, int len){
    return paddr_read(addr, len);
}

uint32_t inst_fetch(vaddr_t *pc, int len){
  
  uint32_t inst = vaddr_ifetch(*pc, len);
  (*pc) += len;
  return inst;
}


