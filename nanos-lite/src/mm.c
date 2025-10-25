#include <memory.h>
#include "strace.h"
#include <proc.h>
#include <stdio.h>
static void *pf = NULL;

void *new_page(size_t nr_page)
{
	CASE_LOG("new_page: Allocating %u pages", nr_page);

	assert(pf);
	void *p = pf;
	memset(p, 0, nr_page * PGSIZE);
	pf += nr_page * PGSIZE;

	return p;
}

#ifdef HAS_VME
static void *pg_alloc(int n)
{
	assert(!(n % PGSIZE)); // Ensure n is a multiple of PGSIZE
	return new_page(n / PGSIZE);
}
#endif

void free_page(void *p)
{
	CASE_LOG("not implement yet");
}

/* The brk() system call handler. */
int mm_brk(uintptr_t brk)
{
	// printf("mm_brk: brk = %p\n", (void *)brk);
	if (brk > current->max_brk)
	{
		printf("mm_brk: current->max_brk = %p, brk = %p\n", (void *)current->max_brk, (void *)brk);
		uint32_t pg_num = (brk - current->max_brk - 1) / PGSIZE + 1;
		// printf("pgnum = %u\n", pg_num);
		void *new_pages = new_page(pg_num);
		if (new_pages == NULL)
			assert(0);
		void *newpgptr = new_pages;
		for (uint32_t i = 0; i < pg_num; i++)
		{
			map(&current->as, (void *)(current->max_brk + i * PGSIZE), newpgptr, 0);
			newpgptr += PGSIZE;
		}
		current->max_brk = ROUNDUP(brk, PGSIZE);
	}

	return 0;
}

void init_mm()
{
	pf = (void *)ROUNDUP(heap.start, PGSIZE);
	Log("free physical pages starting from %p", pf);

#ifdef HAS_VME
	vme_init(pg_alloc, free_page);
#endif
}
