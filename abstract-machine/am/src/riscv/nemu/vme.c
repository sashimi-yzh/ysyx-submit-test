#include "arch/riscv.h"
#include <am.h>
#include <klib.h>
#include <nemu.h>

static AddrSpace kas = {};
static void *(*pgalloc_usr)(int) = NULL;
static void (*pgfree_usr)(void *) = NULL;
static int vme_enable = 0;

#define MSTATUS_SIE (1u << 1)
#define MSTATUS_MPIE (1u << 7)
#define MSTATUS_MPP (3u << 11)

static inline uintptr_t ucontext_mstatus(void) {
  // Keep interrupts off during trap unwinding and let mret restore MIE from
  // MPIE so the user context returns with interrupts enabled.
  return MSTATUS_MPIE | MSTATUS_SIE | MSTATUS_SUM | MSTATUS_MXR;
}

static Area segments[] = { // Kernel memory mappings
    NEMU_PADDR_SPACE};

#define USER_SPACE RANGE(0x40000000, 0x80000000)

static inline void set_satp(void *pdir) {
  uintptr_t mode = 1ul << (__riscv_xlen - 1);
  asm volatile("csrw satp, %0" : : "r"(mode | ((uintptr_t)pdir >> 12)));
}

static inline void *get_pdir(void) {
  uintptr_t satp;
  asm volatile("csrr %0, satp" : "=r"(satp));
  return (void *)((satp & ((1ul << 22) - 1)) << 12);
}

static PTE *walk(AddrSpace *as, void *va, bool alloc) {
  PTE *pgt1 = as->ptr;
  assert(pgt1 != NULL);

  uintptr_t addr = (uintptr_t)va;
  int pte1_idx = (addr >> VPN1_SHIFT) & 0x3ff;
  PTE pte1 = pgt1[pte1_idx];
  PTE *pgt0;

  if (!(pte1 & PTE_V)) {
    if (!alloc)
      return NULL;
    pgt0 = pgalloc_usr(PGSIZE);
    if (pgt0 == NULL)
      return NULL;
    memset(pgt0, 0, PGSIZE);
    pgt1[pte1_idx] = (((uintptr_t)pgt0 >> 2) & PPN_MASK) | PTE_V;
  } else {
    assert((pte1 & (PTE_R | PTE_W | PTE_X)) == 0);
    pgt0 = (PTE *)((pte1 & PPN_MASK) << 2);
  }

  return &pgt0[(addr >> VPN0_SHIFT) & 0x3ff];
}

bool vme_init(void *(*pgalloc_f)(int), void (*pgfree_f)(void *)) {
  pgalloc_usr = pgalloc_f;
  pgfree_usr = pgfree_f;

  kas.ptr = pgalloc_f(PGSIZE);
  if (kas.ptr == NULL)
    return false;
  memset(kas.ptr, 0, PGSIZE);
  kas.pgsize = PGSIZE;

  int i;
  for (i = 0; i < LENGTH(segments); i++) {
    void *va = segments[i].start;
    for (; va < segments[i].end; va += PGSIZE) {
      map(&kas, va, va, PTE_R | PTE_W | PTE_X | PTE_A | PTE_D);
    }
  }

  set_satp(kas.ptr);
  vme_flush(&kas, NULL);
  vme_enable = 1;

  return true;
}

bool vme_attach(AddrSpace *kernel_as, void *(*pgalloc_f)(int),
                void (*pgfree_f)(void *)) {
  if (kernel_as == NULL || kernel_as->ptr == NULL || pgalloc_f == NULL ||
      pgfree_f == NULL)
    return false;

  pgalloc_usr = pgalloc_f;
  pgfree_usr = pgfree_f;
  kas = *kernel_as;
  if (kas.pgsize == 0)
    kas.pgsize = PGSIZE;
  vme_enable = 1;
  return true;
}

void protect(AddrSpace *as) {
  PTE *updir = (PTE *)(pgalloc_usr(PGSIZE));
  assert(updir != NULL);
  as->ptr = updir;
  as->area = USER_SPACE;
  as->pgsize = PGSIZE;
  // map kernel space
  memcpy(updir, kas.ptr, PGSIZE);
}

void unprotect(AddrSpace *as) {
  if (as == NULL || as->ptr == NULL)
    return;
  if (vme_enable && as->ptr == get_pdir())
    vme_switch(NULL);

  PTE *pgt1 = as->ptr;
  PTE *kpgt1 = kas.ptr;
  for (int i = 0; i < 1024; i++) {
    PTE pte = pgt1[i];
    if (!(pte & PTE_V) || pte == kpgt1[i])
      continue;
    assert((pte & (PTE_R | PTE_W | PTE_X)) == 0);
    pgfree_usr((void *)((pte & PPN_MASK) << 2));
  }

  pgfree_usr(pgt1);
  as->ptr = NULL;
}

void __am_get_cur_as(Context *c) {
  c->pdir = (vme_enable ? get_pdir() : NULL);
}

void __am_switch(Context *c) {
  if (vme_enable && c->pdir != NULL && c->pdir != get_pdir()) {
    set_satp(c->pdir);
    vme_flush(NULL, NULL);
  }
}

void map(AddrSpace *as, void *va, void *pa, int prot) {
  assert(vme_map(as, va, pa, prot));
}

bool vme_map(AddrSpace *as, void *va, void *pa, int prot) {
  assert(as != NULL && as->ptr != NULL);
  assert(((uintptr_t)va & OFFSET_MASK) == 0);
  assert(((uintptr_t)pa & OFFSET_MASK) == 0);
  assert(!(prot & PTE_W) || (prot & PTE_R));

  PTE *pte = walk(as, va, true);
  if (pte == NULL || (*pte & PTE_V) != 0)
    return false;
  *pte = (((uintptr_t)pa >> 2) & PPN_MASK) | PTE_V | prot;
  vme_flush(as, va);
  return true;
}

void unmap(AddrSpace *as, void *va, void **pa) {
  assert(as != NULL && as->ptr != NULL);
  assert(((uintptr_t)va & OFFSET_MASK) == 0);

  PTE *pte = walk(as, va, false);
  if (pte == NULL || (*pte & PTE_V) == 0) {
    if (pa != NULL)
      *pa = NULL;
    return;
  }

  assert((*pte & (PTE_R | PTE_W | PTE_X)) != 0);
  if (pa != NULL)
    *pa = (void *)((*pte & PPN_MASK) << 2);
  *pte = 0;
  vme_flush(as, va);
}

bool vme_query(AddrSpace *as, void *va, void **pa, int *prot) {
  if (as == NULL || as->ptr == NULL)
    return false;

  PTE *pte = walk(as, va, false);
  if (pte == NULL || (*pte & PTE_V) == 0 ||
      (*pte & (PTE_R | PTE_W | PTE_X)) == 0)
    return false;

  uintptr_t offset = (uintptr_t)va & OFFSET_MASK;
  if (pa != NULL)
    *pa = (void *)(((*pte & PPN_MASK) << 2) + offset);
  if (prot != NULL)
    *prot = *pte & (PTE_R | PTE_W | PTE_X | PTE_U | PTE_A | PTE_D);
  return true;
}

void vme_switch(AddrSpace *as) {
  assert(vme_enable);
  void *pdir = as == NULL ? kas.ptr : as->ptr;
  assert(pdir != NULL);
  if (pdir != get_pdir())
    set_satp(pdir);
  vme_flush(as, NULL);
}

void vme_flush(AddrSpace *as, void *va) {
  if (as != NULL && as->ptr != get_pdir())
    return;
  if (va == NULL)
    asm volatile("sfence.vma zero, zero" ::: "memory");
  else
    asm volatile("sfence.vma %0, zero" : : "r"(va) : "memory");
}

Context *ucontext(AddrSpace *as, Area kstack, void *entry) {
  Context *context = (Context *)kstack.end - 1;
  memset(context, 0, sizeof(*context));
  context->mstatus = ucontext_mstatus();
  context->mepc = (uintptr_t)entry;
  context->pdir = as->ptr;
  return context;
}
