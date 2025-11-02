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

extern Area heap;//defined in trm.c
extern char _heap_start;//defined in linker.ld, referenced in trm.c

//size_t addr = 0x0f00000c;

void *malloc(size_t size) {
  // On native, malloc() will be called during initializaion of C runtime.
  // Therefore do not call panic() here, else it will yield a dead recursion:
  //   panic() -> putchar() -> (glibc) -> malloc() -> panic()
#if !(defined(__ISA_NATIVE__) && defined(__NATIVE_USE_KLIB__))
  	static size_t addr = (size_t)&_heap_start;//注意addr应该位于sdata段
	//assert(addr != 0x0f00000c);
	
	//assert(addr == 0x0f00000c);
	
	addr += size;
  	if(addr >= (size_t)heap.start && addr <= (size_t)heap.end)
  		return (void *)(addr - size);
	else{
		return NULL;
	}
#endif
  return NULL;
}


void free(void *ptr) {
}

#endif
