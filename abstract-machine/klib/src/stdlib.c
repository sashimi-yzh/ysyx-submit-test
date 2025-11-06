#include <am.h>
#include <klib.h>
#include <klib-macros.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)
static unsigned long int next = 1;
// 分配的内存的首地址
static void* malloc_addr = NULL;

int rand(void) {
  // RAND_MAX assumed to be 32767
  next = next * 1103515245 + 12345;
  return (unsigned int)(next/65536) % 32768;
}

void srand(unsigned int seed) {
  next = seed;
}

int abs(int x) {
  return (x < 0 ? -x : x);
}

int atoi(const char* nptr) {
  int x = 0;
  while (*nptr == ' ') { nptr ++; }
  while (*nptr >= '0' && *nptr <= '9') {
    x = x * 10 + *nptr - '0';
    nptr ++;
  }
  return x;
}

void *malloc(size_t size) {
  // On native, malloc() will be called during initializaion of C runtime.
  // Therefore do not call panic() here, else it will yield a dead recursion:
  //   panic() -> putchar() -> (glibc) -> malloc() -> panic()
#if !(defined(__ISA_NATIVE__) && defined(__NATIVE_USE_KLIB__))
  // panic("Not implemented");
  if(malloc_addr == NULL){
    malloc_addr = (void*)ROUNDUP(heap.start, 4);
  }
  size_t align_size = (size_t)ROUNDUP(size, 4);
  void* assign_addr = malloc_addr;
  malloc_addr = malloc_addr + align_size;
  assert(malloc_addr < heap.end);
  for(int i = 0;i < align_size;i++){
    char* p = assign_addr + i;
    *p = '\0';
  }

#endif
  return assign_addr;
}

void free(void *ptr) {
}

#endif
