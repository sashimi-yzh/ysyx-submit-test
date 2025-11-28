#include <am.h>
#include <klib-macros.h>
#include <klib.h>
#include <ysyxsoc.h>
#include <riscv.h>

extern char _heap_start;
extern char _data_start;

int main(const char *args);
void init_uart();
void bootloader();

extern char _pmem_start;
#define PMEM_SIZE (256 * 1024)
#define PMEM_END  ((uintptr_t)&_pmem_start + PMEM_SIZE)
#define npc_trap(code) asm volatile ("mv a0, %0; ebreak" : :"r"(code))

Area heap = RANGE(&_heap_start, &_heap_start+0x100000);
static const char mainargs[MAINARGS_MAX_LEN] = MAINARGS_PLACEHOLDER; // defined in CFLAGS

__attribute__ ((section(".bootutils"))) void putch(char ch) {
  while(!(inb(UART_LSR)&0x20)); 
  outb(UART_RBR,ch);
  return;
}

__attribute__ ((section(".bootutils"))) void print_hex(uint32_t num) {
    for (int i = 7; i >= 0; i--) {
        uint8_t nibble = (num >> (i * 4)) & 0x0F;  
        char hex_char = (nibble < 10) ? ('0' + nibble) : ('a' + nibble - 10);
        putch(hex_char);  
    }
}
void halt(int code) {
  npc_trap(code);
  // should not reach here.
  while (1);
}

void print_id(){
  // mvendorid: 0xf11 marchid: 0xf12
  uint32_t marchid=0,mvendorid=0;
  char name[4];
  asm volatile("csrr %0, mvendorid"
    : "=r"(mvendorid)
  );
  asm volatile("csrr %0, marchid"
    : "=r"(marchid)
  );
  memcpy(name,&mvendorid,4);
  printf("%s_%d\n",name,marchid);
}
void _trm_init() {
  print_id();
  int ret = main(mainargs);
  halt(ret);
}
