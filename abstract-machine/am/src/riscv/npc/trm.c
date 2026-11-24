#include <am.h>
#include <klib-macros.h>
#include <npc.h>
#include <klib.h>

#ifdef __RTTHREAD__
extern char _extra_data_start[];
extern char _extra_data_end[];
extern char _extra_data_lma[];
#define EXTRA_DATA_LEN (uint32_t)(_extra_data_end - _extra_data_start)
#endif

extern int main(const char *args);
extern void _trm_init(void);

extern char _heap_start;
#define HEAP_SIZE (1024 * 1024)
Area heap = RANGE(&_heap_start, &_heap_start + HEAP_SIZE);
static const char mainargs[MAINARGS_MAX_LEN] = MAINARGS_PLACEHOLDER; // defined in CFLAGS

// finisher: writing the exit code here tells the simulation environment
// (npc_soc.v vuart, offset 4) that the program has finished. Unlike ebreak it is
// a bus write, so it is visible in both RTL and gate-level netlist simulation,
// and it is never prefetched.
#define NPC_FINISHER_ADDR 0xa00003fc

void halt(int code) {
  *(volatile uint32_t *)NPC_FINISHER_ADDR = code;
  __asm__ volatile ("ebreak");  // still used by verilator/difftest flow
  while (1);
}

void _trm_init() {

  ioe_init();

  uint32_t mvendorid, marchid;
  __asm__ volatile("csrr %0, mvendorid" : "=r"(mvendorid));
  __asm__ volatile("csrr %0, marchid" : "=r"(marchid));
  printf("mvendorid(ascii code) = 0x%x, marchid = %x\n", mvendorid, marchid);


  int ret = main(mainargs);
  halt(ret);
}
