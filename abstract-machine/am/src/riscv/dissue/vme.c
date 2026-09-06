#include "arch/riscv.h"
#include <am.h>
#include <dissue.h>
#include <klib.h>

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
    DISSUE_PADDR_SPACE};

#define USER_SPACE RANGE(0x40000000, 0x80000000)

static inline void set_satp(void *pdir) {
  uintptr_t mode = 1ul << (__riscv_xlen - 1);
  printf("[vme] set_satp: pdir=%p ppn=0x%08x satp=0x%08x\n", pdir,
         (uint32_t)((uintptr_t)pdir >> 12),
         (uint32_t)(mode | ((uintptr_t)pdir >> 12)));
  asm volatile("csrw satp, %0" : : "r"(mode | ((uintptr_t)pdir >> 12)));
}

static inline uintptr_t get_satp() {
  uintptr_t satp;
  asm volatile("csrr %0, satp" : "=r"(satp));
  return satp << 12;
}

bool vme_init(void *(*pgalloc_f)(int), void (*pgfree_f)(void *)) {
  pgalloc_usr = pgalloc_f;
  pgfree_usr = pgfree_f;

  kas.ptr = pgalloc_f(PGSIZE);

  int i;
  for (i = 0; i < LENGTH(segments); i++) {
    void *va = segments[i].start;
    for (; va < segments[i].end; va += PGSIZE) {
      map(&kas, va, va, PTE_R | PTE_W | PTE_X | PTE_A | PTE_D);
    }
  }

  set_satp(kas.ptr);
  vme_enable = 1;

  return true;
}

void protect(AddrSpace *as) {
  PTE *updir = (PTE *)(pgalloc_usr(PGSIZE));
  as->ptr = updir;
  as->area = USER_SPACE;
  as->pgsize = PGSIZE;
  printf("[vme] protect: new user pdir base=%p\n", updir);
  // map kernel space
  memcpy(updir, kas.ptr, PGSIZE);
  printf("[vme] protect: copied kernel mappings from kas=%p to user pdir=%p\n",
         kas.ptr, updir);
}

void unprotect(AddrSpace *as) {}

void __am_get_cur_as(Context *c) {
  c->pdir = (vme_enable ? (void *)get_satp() : NULL);
}

void __am_switch(Context *c) {
  (void)c;
  // Delay the satp switch until the trap assembly is about to mret. When this
  // function is reached from a user syscall, C is still running on the user's
  // stack, so switching page tables here would unmap that stack frame before
  // the function returns.
}

void map(AddrSpace *as, void *va, void *pa, int prot) {
  // 从satp寄存器之中得到页表基址，然后将这个地方的ppn改为pa所在的地址
  // 通过as->ptr获得页目录的基地址
  PTE *pgt1_start = as->ptr;
  assert(pgt1_start != NULL);
  PTE *pgt0_start = NULL;
  int pte1_idx = ((uint32_t)(uintptr_t)va >> VPN1_SHIFT) & 0x3FF;
  PTE pte1 = (pgt1_start[pte1_idx]);

  if (!(pte1 & PTE_V)) {
    // 如果页表无效
    pgt0_start = (PTE *)(pgalloc_usr(PGSIZE));
    assert(pgt0_start != NULL);
    pgt1_start[pte1_idx] =
        (((uint32_t)(uintptr_t)pgt0_start >> 2) & PPN_MASK) | PTE_V;
    printf(
        "[vme] map: alloc l0 pgt base=%p for l1_idx=%d (va=%p), l1_base=%p\n",
        pgt0_start, pte1_idx, va, pgt1_start);
  } else {
    pgt0_start = (PTE *)((pte1 & PPN_MASK) << 2);
  }

  int pte0_idx = ((uint32_t)(uintptr_t)va >> VPN0_SHIFT) & 0x3FF;

  if (pgt0_start[pte0_idx] & PTE_V) {
    return;
  }

  pgt0_start[pte0_idx] =
      (((uint32_t)(uintptr_t)pa >> 2) & PPN_MASK) | PTE_V | prot;
}

Context *ucontext(AddrSpace *as, Area kstack, void *entry) {
  Context *context = (Context *)kstack.end - 1;
  context->mstatus = ucontext_mstatus();
  context->mepc = (uintptr_t)entry;
  context->pdir = as->ptr;
  return context;
}
