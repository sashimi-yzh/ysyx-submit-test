#include <proc.h>
#include <memory.h>

static void *pf = NULL;

void* new_page(size_t nr_page) {
  void *res = pf;
  pf += nr_page * PGSIZE;
  return res;
}

#ifdef HAS_VME
static void* pg_alloc(int n) {
  assert(n % PGSIZE == 0);
  void *p = new_page(n / PGSIZE);
  memset(p, 0, n);
  return p;
}
#endif

void free_page(void *p) {
  panic("not implement yet");
}

/* The brk() system call handler. */
int mm_brk(uintptr_t brk) {
  if (current->max_brk >= brk) return 0;
  while (current->max_brk < brk) {
    map(&current->as, (void *)current->max_brk, new_page(1), PROT_RW);
    current->max_brk += PGSIZE;
  }
  return 0;
}

void init_mm() {
  pf = (void *)ROUNDUP(heap.start, PGSIZE);
  Log("free physical pages starting from %p", pf);

#ifdef HAS_VME
  vme_init(pg_alloc, free_page);
#endif
}
