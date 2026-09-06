#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <common.h>

#ifndef PGSIZE
#define PGSIZE 4096
#endif

#define PG_ALIGN __attribute((aligned(PGSIZE)))

/* 页表项位定义 */
#define PTE_V (1 << 0) /* Valid */
#define PTE_R (1 << 1) /* Read */
#define PTE_W (1 << 2) /* Write */
#define PTE_X (1 << 3) /* Execute */
#define PTE_U (1 << 4) /* User */
#define PTE_G (1 << 5) /* Global */
#define PTE_A (1 << 6) /* Accessed */
#define PTE_D (1 << 7) /* Dirty */

void *new_page(size_t);
int mm_brk(uintptr_t brk);

#endif
