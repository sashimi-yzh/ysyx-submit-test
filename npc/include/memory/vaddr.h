#ifndef __MEMORY_VADDR_H__
#define __MEMORY_VADDR_H__

#include <common.h>

#ifdef __cplusplus
extern "C" {
#endif

word_t vaddr_read(vaddr_t addr, int len);
void vaddr_write(vaddr_t addr, int len, word_t data);

#ifdef __cplusplus
}
#endif

#endif
