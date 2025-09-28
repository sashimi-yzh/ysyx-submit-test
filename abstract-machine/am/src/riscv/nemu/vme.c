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
  }
}

void map(AddrSpace *as, void *va, void *pa, int prot) {
  // TEMP: Sv32 only
  
  uintptr_t vpn1 = ((uintptr_t)va >> 22) & 0x3ff; // [9:0] vpn1 = va[31:22]
  uintptr_t vpn0 = ((uintptr_t)va >> 12) & 0x3ff; // [9:0] vpn2 = va[21:12]

  // page table 1 address
  // [31:0] as->ptr = { ... , 12'b0}
  uintptr_t pt1 = (uintptr_t)as->ptr;
  assert((pt1 & 0xfff) == 0);

  // page table 1 entry address
  // [31:0] pte1_addr = { as->ptr[31:12], vpn1[9:0], 2'b0 }
  uintptr_t *pte1 = (uintptr_t *)(pt1 | (vpn1 << 2));

  // page table 0 address
  uintptr_t pt0;

  // page table 1 entry doesn't exist
  // create pt0 & pte1
  if ((*pte1 & 1) == 0) {

    // create page table 0
    pt0 = (uintptr_t)pgalloc_usr(PGSIZE);

    // create page table 1 entry
    // [31:0] pte1 = { 2'b0, pt0_addr[31:12], 9'b0, 1'b1 }
    *pte1 = (pt0 >> 2) | 1;
  } else {
    // [31:0] pt0_addr = { pte1[29:10], 12'b0 }
    pt0 = (*pte1 << 2) & ~0xfff;
  }

  // page table 0 address
  // [31:0] pt0_addr = { ... , 12'b0}
  assert((pt0 & 0xfff) == 0);

  // create page table 0 entry
  // [31:0] pte0_addr = { pt0[31:12], vpn0[9:0], 2'b0 }
  uintptr_t *pte0 = (uintptr_t *)(pt0 | (vpn0 << 2));
  // [31:0] pte0 = { 2'b0, pa[31:12], 10'b0000001111 }
  *pte0 = (((uintptr_t)pa >> 2) & ~0x3ff) | 0xf;
}

Context *ucontext(AddrSpace *as, Area kstack, void *entry) {
  Context *ctx = kstack.end - sizeof(Context);
  ctx->pdir = as->ptr;
  ctx->mcause = 11;
  ctx->mstatus = 0x1880;
  ctx->mepc = (uintptr_t)entry;
  ctx->R_SP = (uintptr_t)ctx;
  ctx->R_PRIV = PRIV_USER;
  return ctx;
}
