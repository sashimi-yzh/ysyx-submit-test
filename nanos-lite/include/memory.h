#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <common.h>

#ifndef PGSIZE
#define PGSIZE 4096
#endif

#define PG_ALIGN __attribute((aligned(PGSIZE)))

#define PROT_READ  0x1
#define PROT_WRITE 0x2
#define PROT_EXEC  0x4

#define PROT_RW ((PROT_READ | PROT_WRITE))
#define PROT_RWX ((PROT_RW | PROT_EXEC))

void* new_page(size_t);

#endif
