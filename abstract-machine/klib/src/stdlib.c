#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)
static unsigned long int next = 1;

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

long strtol(const char *nptr, char **endptr, int base) {
  panic("strtol !!!");
  assert(base == 10);
  long x = 0;
  while (*nptr == ' ') { nptr++; }
  while (*nptr >= '0' && *nptr <= '9') {
    x = x * 10 + *nptr - '0';
    nptr++;
  }
  if (endptr)
    *endptr = (char *)nptr;
  return x;
}

int atoi(const char* nptr) {
  return strtol(nptr, NULL, 10);
}

void *malloc(size_t size) {
  // On native, malloc() will be called during initializaion of C runtime.
  // Therefore do not call panic() here, else it will yield a dead recursion:
  //   panic() -> putchar() -> (glibc) -> malloc() -> panic()
#if !(defined(__ISA_NATIVE__) && defined(__NATIVE_USE_KLIB__))
  // panic("Not implemented");
#endif
  static char *addr = NULL;
  if (addr == NULL) {
    addr = (void *)ROUNDUP(heap.start, 8);
  }
  size = ROUNDUP(size, 8);
  char *old = addr;
  addr += size;
  assert((uintptr_t)addr < (uintptr_t)heap.end);
  return old; 
}

void free(void *ptr) {
}

#endif
