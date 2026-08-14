#include <am.h>
#include <klib-macros.h>
#include <klib.h>
// #include <stdio.h>
#include ISA_H // defined in CFLAGS
#define UART_PORT 0x10000000

extern char _heap_start;
extern char _heap_end;
Area heap = RANGE(&_heap_start, &_heap_end);

void putch(char ch) {
  while(!(inb(UART_PORT + 5) & 0x20));
  outb(UART_PORT, ch);
}

void halt(int code) {
  asm volatile("mv a0, %0; ebreak" : :"r"(code));
  while (1);
}

#define CSR_MVENDORID 0xF11
#define CSR_MARCHID   0xF12
#define CSR_MSTATUS   0x300
#define CSR_MEPC      0x341
#define CSR_MCAUSE    0x342
#define CSR_MTVEC     0x305
static inline unsigned long read_csr(int csr_num)
{
  unsigned long value;
  __asm__ volatile ("csrr %0, %1" : "=r"(value) : "i"(csr_num));
  return value;
}

int main(const char *args);
static const char mainargs[MAINARGS_MAX_LEN] = TOSTRING(MAINARGS_PLACEHOLDER); // defined in CFLAGS
extern char _flash_data_start;
extern char _flash_data_end;
extern char _psram_data_start;
extern char _flash_text_start;
extern char _flash_text_end;
extern char _psram_text_start;
extern char _flash_rodata_start;
extern char _flash_rodata_end;
extern char _psram_rodata_start;
void _trm_init() {
  // 初始化串口
  outb(UART_PORT + 3, 0b10000011);
  outb(UART_PORT + 1, 0b00000000);
  outb(UART_PORT + 0, 0b00000001);
  outb(UART_PORT + 3, 0b00000011);
  // 打印学号信息
  // unsigned long mvendorid = read_csr(CSR_MVENDORID);
  // printf("mvendorid = 0x%08x\n", mvendorid);
  // unsigned long marchid = read_csr(CSR_MARCHID);
  // printf("marchid   = 0x%08x\n", marchid);
  // unsigned long mstatus = read_csr(CSR_MSTATUS);
  // printf("mstatus   = 0x%08x\n", mstatus);
  // read_csr(CSR_MSTATUS);
  // printf("mstatus   = 0x%08x\n", mstatus);
  // unsigned long mcause = read_csr(CSR_MCAUSE);
  // printf("mcause   = 0x%08x\n", mcause);
  int ret = main(mainargs);
  halt(ret);
}