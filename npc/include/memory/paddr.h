#ifndef __MEMORY_PADDR_H__
#define __MEMORY_PADDR_H__

#include <common.h>
#ifdef __cplusplus
extern "C" {
#endif

word_t paddr_read(paddr_t addr, int len);
void paddr_write(paddr_t addr, int len, word_t data);

#ifdef __cplusplus
}
#endif

#endif
