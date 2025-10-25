#include <am.h>
#include <nemu.h>
#include <klib.h>
static AddrSpace kas = {};
static void *(*pgalloc_usr)(int) = NULL;
static void (*pgfree_usr)(void *) = NULL;
static int vme_enable = 0;

static Area segments[] = { // Kernel memory mappings
	NEMU_PADDR_SPACE};

#define USER_SPACE RANGE(0x40000000, 0x80000000)

static inline void set_satp(void *pdir)
{
	uintptr_t mode = 1ul << (__riscv_xlen - 1);
	asm volatile("csrw satp, %0" : : "r"(mode | ((uintptr_t)pdir >> 12)));
}

static inline uintptr_t get_satp()
{
	uintptr_t satp;
	asm volatile("csrr %0, satp" : "=r"(satp));
	return satp << 12;
}

bool vme_init(void *(*pgalloc_f)(int), void (*pgfree_f)(void *))
{
	pgalloc_usr = pgalloc_f;
	pgfree_usr = pgfree_f;

	kas.pgsize = PGSIZE;
	kas.ptr = pgalloc_f(PGSIZE);

	int i;
	for (i = 0; i < LENGTH(segments); i++)
	{
		void *va = segments[i].start;
		for (; va < segments[i].end; va += PGSIZE)
		{
			map(&kas, va, va, 0);
		}
	}

	set_satp(kas.ptr);
	vme_enable = 1;

	return true;
}

void protect(AddrSpace *as)
{
	PTE *updir = (PTE *)(pgalloc_usr(PGSIZE));
	as->ptr = updir;
	as->area = USER_SPACE;
	as->pgsize = PGSIZE;
	// map kernel space
	memcpy(updir, kas.ptr, PGSIZE);
	printf("Protecting address space %p with page directory %p\n", as, updir);
}

void unprotect(AddrSpace *as)
{
}

void __am_get_cur_as(Context *c)
{
	c->pdir = (vme_enable ? (void *)get_satp() : NULL);
}

void __am_switch(Context *c)
{
	if (vme_enable && c->pdir != NULL)
	{
		set_satp(c->pdir);
	}
}

void map(AddrSpace *as, void *va, void *pa, int prot)
{
	// assert((uintptr_t)as->area.start <= (uintptr_t)va && (uintptr_t)va < (uintptr_t)as->area.end);
	// 鉴于目前是恒等映射，所以推测，这个断言必定会失败
	assert(as->pgsize == PGSIZE);
	if (va != pa)
		printf("Mapping virtual address %p to physical address %p\n", va, pa);
	assert(((uintptr_t)pa) % PGSIZE == 0);
	assert(((uintptr_t)va) % PGSIZE == 0);
	PTE *updir = (PTE *)as->ptr;
	uintptr_t vpn1 = (uintptr_t)va >> 22;
	uintptr_t vpn2 = ((uintptr_t)va >> 12) & 0x3ff;
	PTE *pte1 = &updir[vpn1];
	if ((*pte1 & PTE_V) == 0)
	{
		PTE *pgtable = (PTE *)(pgalloc_usr(PGSIZE));
		assert(pgtable != NULL && ((uintptr_t)pgtable) % PGSIZE == 0);
		uintptr_t ppn = ((uintptr_t)pgtable >> 12) << 10;
		*pte1 = (ppn) | PTE_V;
		// printf("Creating new page table at %p , its tle is %p , at position %p\n",
		// 	   pgtable, *pte1, (uintptr_t)updir + vpn1 * sizeof(PTE));
	}
	PTE ppn2 = (*pte1 >> 10) << 12;
	PTE *pgtable2 = (PTE *)(ppn2);
	PTE *pte2 = &pgtable2[vpn2];
	if ((*pte2 & PTE_V) == 0)
	{
		uintptr_t ppn = ((uintptr_t)pa >> 12) << 10;
		*pte2 = (uintptr_t)ppn | PTE_V | PTE_R | PTE_W | PTE_X;
		// if (va != pa)
		// {
		// 	printf("Creating new page table entry at %p, its value is %p, at position %p\n",
		// 		   pgtable2, *pte2, (uintptr_t)pgtable2 + vpn2 * sizeof(PTE));
		// 	printf("Mapping virtual address %p to physical address %p\n",
		// 		   va, pa);
		// }
	}
	else
	{
		uintptr_t ppn = ((uintptr_t)(*pte2) >> 10) << 12;
		if ((ppn) != (uintptr_t)pa)
		{
			printf("You are trying to map %p to %p, but it is already mapped to %p\n",
				   va, pa, (void *)ppn);
		}
		assert(((ppn) == (uintptr_t)pa));
	}
}

Context *ucontext(AddrSpace *as, Area kstack, void *entry)
{
	Context *ctx = (Context *)((uintptr_t)kstack.end - sizeof(Context));
	ctx->mepc = (uintptr_t)entry;
	ctx->gpr[2] = (uintptr_t)kstack.end; // stack pointer
	ctx->next_priv = 1;					 // Set next privilege level to USER
	ctx->mstatus = 0x80;				 // MPP = 0b11, MPIE = 1, MIE = 1
	ctx->pdir = (vme_enable ? as->ptr : NULL);
	return ctx;
}
