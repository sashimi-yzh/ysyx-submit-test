#include <am.h>
#include <klib.h>
#include <klib-macros.h>

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

int atoi(const char* nptr) {
  int x = 0;
  while (*nptr == ' ') { nptr ++; }
  while (*nptr >= '0' && *nptr <= '9') {
    x = x * 10 + *nptr - '0';
    nptr ++;
  }
  return x;
}

#define ALIGN(x, ALIGN) (((uintptr_t)(x) + (ALIGN) - 1) & ~((ALIGN) - 1))
extern char _heap_start;
uint8_t *addr = (uint8_t *)&_heap_start;
void *malloc(size_t size) {

#if !(defined(__ISA_NATIVE__) && defined(__NATIVE_USE_KLIB__))
  addr = (uint8_t *)ALIGN(addr, 8); 

  void* ret = addr;
    
  addr += size;
    
  return ret;
#endif
  return NULL;
}

void free(void *ptr) {
}

#endif
