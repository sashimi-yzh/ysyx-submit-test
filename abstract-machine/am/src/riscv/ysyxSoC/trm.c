#include <am.h>
#include <klib-macros.h>
#include <klib.h>
#include <npc.h>
#include <riscv/riscv.h>
extern char _heap_start;
int main(const char *args);

extern char _pmem_start;
#define PMEM_SIZE (4 * 1024 * 1024)
#define PMEM_END  ((uintptr_t)&_pmem_start + PMEM_SIZE)

Area heap = RANGE(&_heap_start, PMEM_END);
static const char mainargs[MAINARGS_MAX_LEN] = TOSTRING(MAINARGS_PLACEHOLDER); // defined in CFLAGS

void putch(char ch) {
  while ((inb(UART_BASE + UART_REG_LS) & UART_LS_THRE) == 0);

  outb(UART_BASE,ch);
}

void halt(int code) {
  asm volatile("ebreak");
  while (1);
}



extern uint32_t _data_lma_start;
extern uint32_t _data_vma_start;
extern uint32_t _data_vma_end;

void show_id_in_seg(uint32_t marchid){
  uint32_t seg = 0;
  while(marchid > 0){
    seg = (seg >> 4) | (marchid % 10) << 28;
    marchid /= 10;
  }
  outl(GPIO_SEG, seg);
}
void uart_init();

void _trm_init() {
  uart_init();
  char mvendorid[5];
  mvendorid[4] = 0;
  uint32_t marchid;
  asm volatile("csrr %0, mvendorid":"=r"(*(uint32_t *)mvendorid)::);
  asm volatile("csrr %0, marchid":"=r"(marchid)::);
  putch(mvendorid[3]); putch(mvendorid[2]); putch(mvendorid[1]); putch(mvendorid[0]);
  putch('_');
  printf("%u\n",marchid);
  show_id_in_seg(marchid);
  int ret = main(mainargs);
  halt(ret);
}

