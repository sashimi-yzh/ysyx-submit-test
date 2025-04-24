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

#define USER_SPACE RANGE(0x40000000, 0xc0000000)

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

  set_cr3(kas.ptr);
  set_cr0(get_cr0() | CR0_PG);
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
  c->cr3 = (vme_enable ? (void *)get_cr3() : NULL);
}

void __am_switch(Context *c) {
  if (vme_enable && c->cr3 != NULL) {
    set_cr3(c->cr3);
  }
}

void map(AddrSpace *as, void *va, void *pa, int prot) {
#ifndef __ICS_EXPORT
#define PTW_CONFIG ((ptw_config) { .ptw_level = 2, .vpn_width = 10 })
#define PTE_ADDR(pte)    ((uintptr_t)(pte) & ~0xfff)
  assert((uintptr_t)va % PGSIZE == 0);
  assert((uintptr_t)pa % PGSIZE == 0);
  PTE *pg_base = as->ptr;
  PTE *pte;
  int level;
  for (level = PTW_CONFIG.ptw_level - 1; ; level --) {
    pte = &pg_base[VPNi(PTW_CONFIG, (uintptr_t)va, level)];
    pg_base = (PTE *)PTE_ADDR(*pte);
    if (level == 0) break;
    if (!(*pte & PTE_P)) {
      pg_base = pgalloc_usr(PGSIZE);
      *pte = PTE_P | PTE_W | PTE_U | (uintptr_t)pg_base;
    }
  }

  if (!(*pte & PTE_P)) {
    *pte = PTE_P | PTE_W | PTE_U | (uintptr_t)pa;
  }
#endif
}

Context* ucontext(AddrSpace *as, Area kstack, void *entry) {
#ifdef __ICS_EXPORT
  return NULL;
#else
  Context *c = (Context *)kstack.end - 1;
  c->cr3 = as->ptr;
  c->cs = USEL(3);
  c->eip = (uintptr_t)entry;
  c->eflags = 0x2 | FL_IF;
  c->ss3 = USEL(4);
  // esp3 is undefined
  return c;
#endif
}
