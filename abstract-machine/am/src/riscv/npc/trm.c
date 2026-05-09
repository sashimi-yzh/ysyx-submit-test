#include <am.h>
#include <klib-macros.h>
#include <npc.h>

# define npc_trap(code) asm volatile("mv a0, %0; ebreak" : :"r"(code)) // 內联汇编

extern char _heap_start;
int main(const char *args);

extern char _pmem_start;
#define PMEM_SIZE (128 * 1024 * 1024)
#define PMEM_END  ((uintptr_t)&_pmem_start + PMEM_SIZE)

Area heap = RANGE(&_heap_start, PMEM_END);
static const char mainargs[MAINARGS_MAX_LEN] = MAINARGS_PLACEHOLDER; // defined in CFLAGS

void putch(char ch) {
  outb(SERIAL_PORT, ch);
}

void halt(int code) {
  
  npc_trap(code);

  while (1);

}

static inline uint32_t read_csr(uint32_t addr) {
    uint32_t val;
    __asm__ volatile("csrr %0, %1" : "=r"(val) : "i"(addr));
    return val;
}

static void putch_hex32(uint32_t val, bool asiic) {
    const char hex[] = "0123456789ABCDEF";
    if(asiic == true){
      for (int i = 28; i >= 0; i -= 4) {
        putch(hex[(val >> i) & 0xF]);
      }
    }
    else {
      for (int i = 24; i >= 0; i -= 8) {
        putch((char)((val >> i) & 0xff));
      }
    }
    
    putch('\r'); putch('\n');
}

void _trm_init() {

  uint32_t  mvendorid = 0;
  uint32_t  marchid = 0;

  mvendorid = read_csr(0xF11);
  marchid = read_csr(0xF12);

  putch_hex32(mvendorid, false);
  putch_hex32(marchid, true);
  
  int ret = main(mainargs);
  halt(ret);
}
