#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <stdint.h>
#include <assert.h>
#include <generated/autoconf.h>

// use DPI-C should add this macro#ifdef __cplusplus
#ifdef __cplusplus

extern "C" {
#endif

    typedef struct {
        uint32_t addr;
        uint32_t data;
        uint32_t enable;
        uint32_t fcn;
    } mem_access_state;

    

    #define MBASE CONFIG_MBASE 
    #define MSIZE CONFIG_MSIZE 
    #define PMEM_LEFT  ((paddr_t)CONFIG_MBASE)
    #define PMEM_RIGHT ((paddr_t)CONFIG_MBASE + CONFIG_MSIZE - 1)
    #define WORD_SIZE 4

    void init_memory();
    void init_mrom();
    uint8_t* guest_to_host(uint32_t paddr) ;
    uint8_t* guest_to_mrom(uint32_t paddr) ;
    uint8_t* guest_to_flash(uint32_t paddr) ;
    bool in_uart(uint32_t addr);

    static inline bool in_pmem(uint32_t addr) {
        return addr - MBASE < MSIZE;
    }

    static inline uint32_t host_read(void *addr, int len) {
        switch (len) {
            case 1: return *(uint8_t  *)addr;
            case 2: return *(uint16_t *)addr;
            case 4: return *(uint32_t *)addr;
            default: return 0;
        }
    }

    static inline void host_write(void *addr, int len, uint32_t data) {
        switch (len) {
            case 1: *(uint8_t  *)addr = data; return;
            case 2: *(uint16_t *)addr = data; return;
            case 4: *(uint32_t *)addr = data; return;
            default: assert(0);
        }
    }
    

#ifdef __cplusplus
}
#endif
#endif