#include <common.h>
#include <isa.h>
#include <paddr.h>
#include <Vtop.h>
#include "svdpi.h"
#include "Vtop__Dpi.h"
#define CONFIG_MTRACE
#define PG_ALIGN __attribute((aligned(4096))) 

#define likely(cond)   __builtin_expect(cond, 1)
#define unlikely(cond) __builtin_expect(cond, 0)

static uint8_t pmem[0x8000000] PG_ALIGN = {};

uint8_t* guest_to_host(paddr_t paddr) { return pmem + paddr - 0x80000000; }
paddr_t host_to_guest(uint8_t *haddr) { return haddr - pmem + 0x80000000; }

static word_t pmem_read(paddr_t addr, int len) {
  
    word_t ret = host_read(guest_to_host(addr), len);

   
    return ret;
}

static void pmem_write(paddr_t addr, int len, word_t data) {
    host_write(guest_to_host(addr), len, data);
#ifdef CONFIG_MTRACE
     //printf("Write: (%08x) = %08lx  \n", addr, data);
#endif
}

void delete_module();
extern Vtop* top;


static void out_of_bound(paddr_t addr) {

  //top->clk = !top->clk;
  top->eval();
 
  top->clk = !top->clk;
  top->eval();
 
  delete_module();

    panic("address = " FMT_PADDR " is out of bound of pmem [" FMT_PADDR ", " FMT_PADDR "] at pc = " FMT_WORD,
              addr, (paddr_t)CONFIG_MBASE, (paddr_t)CONFIG_MBASE + CONFIG_MSIZE - 1, cpu.pc);

}

void init_mem() {
  #ifdef CONFIG_PMEM_MALLOC
    printf("CONFIG_PMEM_MALLOC defined\n")
    pmem = malloc(CONFIG_MSIZE);
    assert(pemm);
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
  #ifdef CONFIG_DEVICE
    return mmio_read(addr, len);
  #endif
  
  out_of_bound(addr);
  printf("1\n");
  return 0;
}


void paddr_write(paddr_t addr, int len, word_t data) {
  if (likely(in_pmem(addr))) { pmem_write(addr, len, data); return; }
  #ifdef CONFIG_DEVICE
    mmio_write(addr, len, data);
    return ;
  #endif
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


