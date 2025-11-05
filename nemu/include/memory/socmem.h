#ifndef __SOCMEM_H_
#define __SOCMEM_H_ 


#include <common.h>
#include <memory/paddr.h>
#include <memory/host.h>

typedef enum{
    MROM,
    SRAM,
    FLASH,
    PSRAM,
    SDRAM,
} socmem_type_t;


extern const char *socmem_name[];

extern paddr_t socmem_base[];

extern word_t socmem_size[];


#define SOCMEM_DEV_NUM 5

#define get_socmem_name(dev) socmem_name[dev]
#define get_socmem_base(dev) socmem_base[dev]
#define get_socmem_size(dev) socmem_size[dev]

#define SOCMEM_LEFT(dev) (get_socmem_base(dev))
#define SOCMEM_RIGHT(dev) (SOCMEM_LEFT(dev) + get_socmem_size(dev) - 1)


uint8_t* socmem_guest_to_host(paddr_t addr);
word_t socmem_read(paddr_t addr, int len);
void socmem_write(paddr_t addr, int len, word_t data);

#endif // !__SOCMEM_H_