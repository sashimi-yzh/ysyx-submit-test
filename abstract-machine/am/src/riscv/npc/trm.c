#include <am.h>
#include <klib-macros.h>
#include <stdio.h>


extern char _heap_start;
extern char _heap_end;
int main(const char *args);

# define DEVICE_BASE 0xa0000000
#define SERIAL_PORT     (DEVICE_BASE + 0x00003f8)
static inline uint8_t  inb(uintptr_t addr) { return *(volatile uint8_t  *)addr; }
static inline uint16_t inw(uintptr_t addr) { return *(volatile uint16_t *)addr; }
static inline uint32_t inl(uintptr_t addr) { return *(volatile uint32_t *)addr; }

static inline void outb(uintptr_t addr, uint8_t  data) { *(volatile uint8_t  *)addr = data; }
static inline void outw(uintptr_t addr, uint16_t data) { *(volatile uint16_t *)addr = data; }
static inline void outl(uintptr_t addr, uint32_t data) { *(volatile uint32_t *)addr = data; }

extern char _pmem_start;
#define PMEM_SIZE (128 * 1024 * 1024)
#define PMEM_END  ((uintptr_t)&_pmem_start + PMEM_SIZE)

Area heap = RANGE(&_heap_start, PMEM_END);
static const char mainargs[MAINARGS_MAX_LEN] = MAINARGS_PLACEHOLDER; // defined in CFLAGS

void putch(char ch) {
  outb(SERIAL_PORT, ch);
}


// CSR寄存器地址定义
#define CSR_MVENDORID 0xF11
#define CSR_MARCHID   0xF12
void halt(int code) {
  asm volatile("mv a0, %0; ebreak" : :"r"(code));
  while (1);
}

// 内联汇编读取CSR寄存器
static inline uint32_t read_csr(uint32_t csr_addr) {
    uint32_t value;
    asm volatile ("csrr %0, %1" : "=r"(value) : "i"(csr_addr));
    return value;
}

void print_mycsr() {
  // 读取CSR寄存器
  uint32_t mvendorid = read_csr(CSR_MVENDORID);
  uint32_t marchid = read_csr(CSR_MARCHID);
  putch(mvendorid>>24);
  putch(mvendorid>>16);
  putch(mvendorid>>8);
  putch(mvendorid);
  printf("%d\n",marchid);
}

void _trm_init() {
  print_mycsr();
  int ret = main(mainargs);
  halt(ret);
}
