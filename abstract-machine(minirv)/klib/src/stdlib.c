#include <am.h>
#include <klib.h>
#include <klib-macros.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)
static unsigned long int next = 1;
static bool flag=false;
static char *start_addr;

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
#if !(defined(__ISA_NATIVE__) && defined(__NATIVE_USE_KLIB__))//如果没有定义...或者用了定义...那么使用自定义malloc否则用库函数
  if(!flag){//如果是第一次使用，需要进行初始化
    start_addr=(void*)ROUNDUP(heap.start,8);//将start_addr初始化为堆的起始位置，并通过宏定义拓展字节(需要对齐)
    flag=true;
  }
  size=(size_t)ROUNDUP(size,8);//将要申请的内存区域拓展到8字节边界
  char *get_start_addr = start_addr;
  start_addr += size;//指向下一个可用内存块的地址
  // panic("Not implemented");
#endif
  return get_start_addr;
}

void free(void *ptr) {
}

#endif
