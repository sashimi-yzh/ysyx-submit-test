#ifndef HOST_H_
#define HOST_H_
#include <stdint.h>
uint32_t pmem_read(uint8_t *addr, uint32_t len);
void pmem_write(uint8_t *addr, uint32_t len, uint32_t data);

#endif
