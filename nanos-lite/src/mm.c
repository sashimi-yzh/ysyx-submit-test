#include <memory.h>
#include <proc.h>
static void *pf = NULL;

void* new_page(size_t nr_page) {
  //return NULL;
  void *ret = pf;
  pf += nr_page * PGSIZE;
  return ret;
}

#ifdef HAS_VME
static void* pg_alloc(int n) {
  return NULL;
}
#endif

void free_page(void *p) {
  panic("not implement yet");
}

/* The brk() system call handler. */
int mm_brk(uintptr_t brk) {
  // if (current->max_brk == 0) {
  //   current->max_brk = brk;
  //   return 0;
  // }
  // if (brk > current->max_brk) {
  //   intptr_t prevbrk = current->max_brk + PGSIZE ;
  //   while (prevbrk < brk) {
  //     void *p = new_page(1);
  //      map(&current->as, (void *)(prevbrk), p, 0b111);
  //     prevbrk += PGSIZE;
  //   }
  //   current->max_brk = brk;
  // }
  return 0;
}

void init_mm() {
  pf = (void *)ROUNDUP(heap.start, PGSIZE);
  Log("free physical pages starting from %p", pf);

#ifdef HAS_VME
  vme_init(pg_alloc, free_page);
#endif
}
