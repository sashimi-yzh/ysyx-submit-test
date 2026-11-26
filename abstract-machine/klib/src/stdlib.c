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

void *malloc(size_t size) {
  // On native, malloc() will be called during initializaion of C runtime.
  // Therefore do not call panic() here, else it will yield a dead recursion:
  //   panic() -> putchar() -> (glibc) -> malloc() -> panic()
#if !(defined(__ISA_NATIVE__) && defined(__NATIVE_USE_KLIB__))
  // 静态变量，维护当前堆顶位置
  static char *hbrk = NULL;
  
  // 首次调用时初始化
  if (hbrk == NULL) {
    hbrk = (char *)ROUNDUP((uintptr_t)heap.start, 8);
  }
  
  // 如果请求大小为0，返回NULL
  if (size == 0) {
    return NULL;
  }
  
  // 将size向上对齐到8字节边界（malloc要求返回的地址按照最大基本类型对齐）
  size = ROUNDUP(size, 8);
  
  // 保存当前位置
  char *old = hbrk;
  
  // 移动堆顶指针
  hbrk += size;
  
  // 检查是否超出堆区范围
  if ((uintptr_t)hbrk > (uintptr_t)heap.end) {
    // 内存不足，恢复指针并返回NULL
    hbrk = old;
    return NULL;
  }
  
  // 返回分配的内存起始地址
  return old;
#endif
  return NULL;
}

void free(void *ptr) {
}

#endif
