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
#define PTE_ADDR(pte)   ((uint32_t)(pte) & ~0xfff)

void __am_tlb_refill() {
  uint32_t hi; //, lo0, lo1;
  asm volatile ("mfc0 %0, $10": "=r"(hi));

  uint32_t va = hi & ~0x1fff;
  assert(cur_pdir != NULL);
  PTE *pde = &cur_pdir[PDX(va)];
  assert(*pde & PTE_V);

  PTE *pte = &((PTE*)PTE_ADDR(*pde))[PTX(va)];
  //assert(*pte & PTE_V);
  asm volatile ("mtc0 %0, $2": : "r"(*pte)); // lo0
  asm volatile ("mtc0 %0, $3": : "r"(*(pte + 1))); // lo1

//  printf("pte = 0x%x, lo0 = 0x%x, lo1 = 0x%x\n", pte, *pte, *(pte + 1));

  asm volatile ("tlbp");
  int idx;
  asm volatile ("mfc0 %0, $0": "=r"(idx)); // index
  if (idx & 0x80000000u) {
    // not found
    static int ptr = 0;
    asm volatile ("mtc0 %0, $0": :"r"(ptr)); // index
    asm volatile ("tlbwi");
    ptr = (ptr + 1) % NR_TLB;
  }
  else {
    asm volatile ("tlbwi");
  }
}

static void invtlb() {
  asm volatile ("mtc0 %0, $10": :"r"(0)); // hi
  asm volatile ("mtc0 %0, $2": : "r"(0)); // lo0
  asm volatile ("mtc0 %0, $3": : "r"(0)); // lo1

  int i;
  for (i = 0; i < NR_TLB; i ++) {
    asm volatile ("mtc0 %0, $0": :"r"(i)); // index
    asm volatile ("tlbwi");
  }
}
#endif
bool vme_init(void* (*pgalloc_f)(int), void (*pgfree_f)(void*)) {
  pgalloc_usr = pgalloc_f;
  pgfree_usr = pgfree_f;
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
  pa -= 0x80000000;
  if (!(*pde & PTE_V)) {
    *pde = PTE_V | (uint32_t)pgalloc_usr(PGSIZE);
  }
  PTE *pte = &((PTE*)PTE_ADDR(*pde))[PTX(va)];
  if (!(*pte & PTE_V)) {
    *pte = PTE_V | PTE_D | (((uint32_t)pa >> PGSHFT) << 6);

//    printf("va = %x -> pa = %x, pte = %x\n", va, pa, pte);
    asm volatile ("mtc0 %0, $10": :"r"(va)); // hi
    asm volatile ("tlbp");

    int idx;
    asm volatile ("mfc0 %0, $0": "=r"(idx)); // index
    if (!(idx & 0x80000000u)) {
      // found
      asm volatile ("mtc0 %0, $2": : "r"(0)); // lo0
      asm volatile ("mtc0 %0, $3": : "r"(0)); // lo1
      asm volatile ("tlbwi");
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
  c->epc = (uintptr_t)entry;
  c->status = 0x1;
  // c->gpr[29] = 1; // sp is undefined
  return c;
#endif
}
