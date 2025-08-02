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

static char* start_addr;    // addr的初始值
static bool init_flag = 0;  // 初始化的标志, 初始化完成后置1

void *malloc(size_t size) {
    if(!init_flag) {
        start_addr = (void*)ROUNDUP(heap.start, 8);
        init_flag = 1;
    }
    size = (size_t)ROUNDUP(size, 8);
    char* old = start_addr; // 获取addr
    start_addr += size;
    return old; // [addr, addr + size]
}

void free(void *ptr) {
}

#endif
