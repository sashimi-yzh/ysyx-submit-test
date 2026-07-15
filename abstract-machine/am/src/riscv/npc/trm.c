#include <am.h>
#include <klib-macros.h>
#include <klib.h>

extern char _heap_start;
int main(const char *args);

extern char _pmem_start;
#define PMEM_SIZE (32 * 1024 * 1024)
#define PMEM_END  ((uintptr_t)&_pmem_start + PMEM_SIZE)

Area heap = RANGE(&_heap_start, PMEM_END);
static const char mainargs[MAINARGS_MAX_LEN] = TOSTRING(MAINARGS_PLACEHOLDER); // defined in CFLAGS

void putch(char ch) {
  *(volatile uint8_t*)0x10000000 = ch;
}

void halt(int code) {
  asm volatile("mv a0, %0; ebreak" : :"r"(code));
  while (1);
}

static void machine_info()
{
  //read the mvendorid and marchid
  uint32_t mvendorid, marchid;
  __asm__ volatile ("csrr %0, mvendorid" : "=r"(mvendorid));
  __asm__ volatile ("csrr %0, marchid" : "=r"(marchid));

  //treat the mvendorid as 4 characters and print it out
  char vendor[5];
  vendor[0] = (mvendorid >> 24) & 0xFF;
  vendor[1] = (mvendorid >> 16) & 0xFF;
  vendor[2] = (mvendorid >> 8) & 0xFF;
  vendor[3] = mvendorid & 0xFF;
  vendor[4] = '\0';
  printf("%s_%d\n", vendor, marchid);
}

void _trm_init() {
  cte_init(NULL);
  machine_info();
  int ret = main(mainargs);
  halt(ret);
}
