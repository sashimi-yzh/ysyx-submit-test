#include <am.h>
#include <klib-macros.h>
#include <klib.h>

#define SERIAL_ADDR 0x10000000

extern char _heap_start;
int main(const char *args);

extern char _pmem_start;
#define PMEM_SIZE (128 * 1024 * 1024)
#define PMEM_END  ((uintptr_t)&_pmem_start + PMEM_SIZE)

Area heap = RANGE(&_heap_start, PMEM_END);
static const char mainargs[MAINARGS_MAX_LEN] = TOSTRING(MAINARGS_PLACEHOLDER); // defined in CFLAGS

void putch(char ch) {
  *(volatile uint8_t  *)SERIAL_ADDR = ch;
}

void halt(int code) {
  asm volatile("mv a0, %0; ebreak" : :"r"(code));
  while (1);
}

#define CSR_MVENDORID  0xF11
#define CSR_MARCHID    0xF12
static inline unsigned long read_csr(int csr_num)
{
  unsigned long value;
  __asm__ volatile ("csrr %0, %1" : "=r"(value) : "i"(csr_num));
  return value;
}

void _trm_init() {
  // // 打印学号信息
  // unsigned long mvendorid = read_csr(CSR_MVENDORID);
  // printf("mvendorid = 0x%08x\n", mvendorid);
  
  // // 读取并打印marchid
  // unsigned long marchid = read_csr(CSR_MARCHID);
  // printf("marchid   = 0x%08x\n", marchid);

  int ret = main(mainargs);
  halt(ret);
}
