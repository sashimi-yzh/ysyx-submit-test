#ifndef __MEMORY_PADDR_H__
#define __MEMORY_PADDR_H__

#include <common.h>

#ifdef PLATFORM_YSYXSOC

#define MROM_LEFT  ((paddr_t)CONFIG_MROM_BASE)
#define MROM_RIGHT ((paddr_t)CONFIG_MROM_BASE + CONFIG_MROM_SIZE - 1)
#define MROM_RESET_VECTOR (MROM_LEFT + CONFIG_PC_RESET_OFFSET)
#define FLASH_LEFT  ((paddr_t)CONFIG_FLASH_BASE)
#define FLASH_RIGHT ((paddr_t)CONFIG_FLASH_BASE + CONFIG_FLASH_SIZE - 1)
#define FLASH_RESET_VECTOR (FLASH_LEFT + CONFIG_PC_RESET_OFFSET)
uint8_t* mrom_guest_to_host(paddr_t paddr);
uint8_t* flash_guest_to_host(paddr_t paddr);

#endif

#define PMEM_LEFT  ((paddr_t)CONFIG_MBASE)
#define PMEM_RIGHT ((paddr_t)CONFIG_MBASE + CONFIG_MSIZE - 1)
#define RESET_VECTOR (PMEM_LEFT + CONFIG_PC_RESET_OFFSET)


uint8_t* guest_to_host(paddr_t paddr);
paddr_t host_to_guest(uint8_t *haddr);

extern "C" {
  #ifdef PLATFORM_NPC
    int pmem_read(int addr, int len);
    void pmem_write(int addr, int len, int data);
    #else 
    void flash_read(int32_t addr, int32_t *data);
    void mrom_read(int32_t addr, int32_t *data);
    uint32_t sdb_mrom_read(int32_t addr);
    uint32_t sdb_flash_read(int32_t addr);
    #endif
}
#ifdef PLATFORM_NPC
static inline bool in_pmem(paddr_t addr) {

  // if (addr >= CLINT_BASE && addr < CLINT_BASE + CLINT_SIZE){
  //   return addr - CLINT_BASE < CLINT_SIZE;
  // }
  return addr - CONFIG_MBASE < CONFIG_MSIZE;
}

word_t paddr_read(paddr_t addr, int len);
void paddr_write(paddr_t addr, int len, word_t data);
#endif

#endif