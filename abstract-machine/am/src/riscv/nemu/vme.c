#include <am.h>
#include <nemu.h>
#include <klib.h>

static AddrSpace kas = {};
static void* (*pgalloc_usr)(int) = NULL;
static void (*pgfree_usr)(void*) = NULL;
static int vme_enable = 0;

static Area segments[] = {      // Kernel memory mappings
  NEMU_PADDR_SPACE
};

#define USER_SPACE RANGE(0x40000000, 0x80000000)

static inline void set_satp(void *pdir) {
  uintptr_t mode = 1ul << (__riscv_xlen - 1);
  asm volatile("csrw satp, %0" : : "r"(mode | ((uintptr_t)pdir >> 12)));
}

static inline uintptr_t get_satp() {
  uintptr_t satp;
  asm volatile("csrr %0, satp" : "=r"(satp));
  return satp << 12;
}

bool vme_init(void* (*pgalloc_f)(int), void (*pgfree_f)(void*)) {
  pgalloc_usr = pgalloc_f;
  pgfree_usr = pgfree_f;

  kas.ptr = pgalloc_f(PGSIZE);

  int i;
  for (i = 0; i < LENGTH(segments); i ++) {
    void *va = segments[i].start;
    for (; va < segments[i].end; va += PGSIZE) {
      map(&kas, va, va, 0);
    }
  }

  set_satp(kas.ptr);
  vme_enable = 1;

  return true;
}

void protect(AddrSpace *as) {
  PTE *updir = (PTE*)(pgalloc_usr(PGSIZE));
  as->ptr = updir;
  as->area = USER_SPACE;
  as->pgsize = PGSIZE;
  // map kernel space
  memcpy(updir, kas.ptr, PGSIZE);
}

void unprotect(AddrSpace *as) {
}

void __am_get_cur_as(Context *c) {
  c->pdir = (vme_enable ? (void *)get_satp() : NULL);
}

void __am_switch(Context *c) {
  if (vme_enable && c->pdir != NULL) {
    set_satp(c->pdir);
#ifndef __ICS_EXPORT
    asm volatile("sfence.vma");
#endif
  }
}

void map(AddrSpace *as, void *va, void *pa, int prot) {
#ifndef __ICS_EXPORT
#define PTE_ADDR(pte)   (((uintptr_t)(pte) & ~0x3ff) << 2)
#define PTW_SV32 ((ptw_config) { .ptw_level = 2, .vpn_width = 10 })
#define PTW_SV39 ((ptw_config) { .ptw_level = 3, .vpn_width = 9 })

#if __riscv_xlen == 32
# define PTW_CONFIG PTW_SV32
#else
# define PTW_CONFIG PTW_SV39
#endif

  assert((uintptr_t)va % PGSIZE == 0);
  assert((uintptr_t)pa % PGSIZE == 0);
  PTE *pg_base = as->ptr;
  PTE *pte;
  int level;
  for (level = PTW_CONFIG.ptw_level - 1; ; level --) {
    pte = &pg_base[VPNi(PTW_CONFIG, (uintptr_t)va, level)];
    pg_base = (PTE *)PTE_ADDR(*pte);
    if (level == 0) break;
    if (!(*pte & PTE_V)) {
      pg_base = pgalloc_usr(PGSIZE);
      *pte = PTE_V | (PN(pg_base) << 10);
    }
  }

  if (!(*pte & PTE_V)) {
    *pte = PTE_V | PTE_R | PTE_W | PTE_X | PTE_U | PTE_A | PTE_D | (PN(pa) << 10);
  }
#endif
}

Context *ucontext(AddrSpace *as, Area kstack, void *entry) {
#ifdef __ICS_EXPORT
  return NULL;
#else
  Context *c = (Context*)kstack.end - 1;

  c->pdir = as->ptr;
  c->mepc = (uintptr_t)entry;
  const uintptr_t mpie = (1 << 7);
  c->mstatus = MSTATUS_SXL | MSTATUS_UXL | MSTATUS_MXR | MSTATUS_SUM |
               (MODE_U << 11) | mpie;
  c->np = 1;
  // c->gpr[2] = undefined;
  return c;
#endif
}
