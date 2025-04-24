#include <am.h>
#include <nemu.h>
#ifndef __ICS_EXPORT
#include <klib.h>
#endif

#define USER_SPACE RANGE(0x40000000, 0x80000000)

static void* (*pgalloc_usr)(int) = NULL;
static void (*pgfree_usr)(void*) = NULL;
static int vme_enable = 0;
static PTE *cur_pdir = NULL;

#ifndef __ICS_EXPORT

#define NR_TLB 16
#define TLBIDX(idx) ((idx) | (12 << 24))
#define PTE_ADDR(pte)   ((uint32_t)(pte) & ~0xfff)

void __am_tlb_refill() {
  uint32_t va; //, lo0, lo1;
  asm volatile ("csrrd %0, 0x11": "=r"(va));  // tlbehi

  assert(cur_pdir != NULL);
  PTE *pde = &cur_pdir[PDX(va)];
  assert(*pde & PTE_V);

  PTE *pte = &((PTE*)PTE_ADDR(*pde))[PTX(va)];
  //assert(*pte & PTE_V);
  asm volatile ("csrwr %0, 0x12": : "r"(*pte)); // tlbelo0
  asm volatile ("csrwr %0, 0x13": : "r"(*(pte + 1))); // tlbelo1

//  printf("pte = 0x%x, lo0 = 0x%x, lo1 = 0x%x\n", pte, *pte, *(pte + 1));

  asm volatile ("tlbsrch");
  int idx;
  asm volatile ("csrrd %0, 0x10": "=r"(idx)); // tlbidx
  if (idx & 0x80000000u) {
    // not found
    static int ptr = 0;
    asm volatile ("csrwr %0, 0x10": :"r"(TLBIDX(ptr))); // tlbidx
    asm volatile ("tlbwr");
    ptr = (ptr + 1) % NR_TLB;
  }
  else {
    asm volatile ("tlbwr");
  }
}

static void invtlb() {
  asm volatile ("invtlb 0, $zero, $zero");
}

static void enable_pg() {
  uint32_t crmd;
  asm volatile("csrrd %0, 0x0": "=r"(crmd));
  crmd |= (1 << 4); // set crmd.PG
  asm volatile("csrwr %0, 0x0": : "r"(crmd));
}
#endif
bool vme_init(void* (*pgalloc_f)(int), void (*pgfree_f)(void*)) {
  pgalloc_usr = pgalloc_f;
  pgfree_usr = pgfree_f;
#ifndef __ICS_EXPORT
  invtlb();
  enable_pg();
#endif
  vme_enable = 1;
  return true;
}

void protect(AddrSpace *as) {
  as->ptr = (PTE*)(pgalloc_usr(PGSIZE));
  as->pgsize = PGSIZE;
  as->area = USER_SPACE;
}

void unprotect(AddrSpace *as) {
}

void __am_get_cur_as(Context *c) {
  c->pdir = (vme_enable ? cur_pdir : NULL);
}

void __am_switch(Context *c) {
  if (vme_enable && c->pdir != NULL) {
#ifndef __ICS_EXPORT
    if (cur_pdir != c->pdir) { invtlb(); }
#endif
    cur_pdir = c->pdir;
  }
}

void map(AddrSpace *as, void *va, void *pa, int prot) {
#ifndef __ICS_EXPORT
  assert((uintptr_t)va % PGSIZE == 0);
  assert((uintptr_t)pa % PGSIZE == 0);
  PTE *pdir = (PTE*)as->ptr;
  PTE *pde = &pdir[PDX(va)];
  if (!(*pde & PTE_V)) {
    *pde = PTE_V | (uint32_t)pgalloc_usr(PGSIZE);
  }
  PTE *pte = &((PTE*)PTE_ADDR(*pde))[PTX(va)];
  if (!(*pte & PTE_V)) {
    const uint32_t plv = 3;  // user mode
    const uint32_t mat = 0;
    *pte = PTE_V | PTE_D | plv | mat | (((uint32_t)pa >> PGSHFT) << 8);

//    printf("va = %x -> pa = %x, pte = %x\n", va, pa, pte);
    asm volatile ("csrwr %0, 0x11": :"r"((uintptr_t)va & ~0x1fff)); // tlbehi
    asm volatile ("tlbsrch");

    int idx;
    asm volatile ("csrrd %0, 0x10": "=r"(idx)); // tlbidx
    if (!(idx & 0x80000000u)) {
      // found
      asm volatile ("csrwr %0, 0x12": : "r"(0)); // tlbelo0
      asm volatile ("csrwr %0, 0x13": : "r"(0)); // tlbelo1
      asm volatile ("tlbwr");
    }
  } else {
    panic("already mapped");
  }
#endif
}

Context *ucontext(AddrSpace *as, Area kstack, void *entry) {
#ifdef __ICS_EXPORT
  return NULL;
#else
  Context *c = (Context*)kstack.end - 1;
  c->pdir = as->ptr;
  c->era = (uintptr_t)entry;
  const uint32_t PLV_USER = 0x3;
  const uint32_t IE = 1 << 2;
  c->prmd = PLV_USER | IE;
  // c->gpr[3] = 1; // sp is undefined
  return c;
#endif
}
