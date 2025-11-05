#include <breakpoint.h>
#include <fmt-def.h>
#define BP_POOL_SIZE 32

typedef struct {
  int NO;
  bool valid;
  vaddr_t addr;
} BP; 

BP bp_pool[BP_POOL_SIZE];


void init_bp_pool() {
  for (int i = 0; i < BP_POOL_SIZE; i++) {
    bp_pool[i].NO = i;
    bp_pool[i].valid = false;
  }
}


bool add_breakpoint(vaddr_t addr) {
  for (int i = 0; i < BP_POOL_SIZE; i++) {
    if (!bp_pool[i].valid) {
      bp_pool[i].valid = true;
      bp_pool[i].addr = addr;
      //printf("Breakpoint %d: 0x" FMT_WORD_HEX_WIDTH "\n", i, addr);
      return true;
    }
  }
  printf("No more space for breakpoint\n");
  return false;
}

bool del_breakpoint(vaddr_t addr ) {
  for (int i = 0; i < BP_POOL_SIZE; i++) {
    if (bp_pool[i].valid && bp_pool[i].addr == addr) {
      bp_pool[i].valid = false;
      //printf("Delete breakpoint %d: 0x" FMT_WORD_HEX_WIDTH "\n", i, addr);
      return true;
    }
  }
  printf("No such breakpoint\n");
  return false;
}

void scan_breakpoint(vaddr_t addr)
{
  for (int i = 0; i < BP_POOL_SIZE; i++)
  {
    if (bp_pool[i].valid && bp_pool[i].addr == addr)
    {
      printf("Breakpoint %d: 0x" FMT_WORD_HEX_WIDTH "\n", i, addr);
      nemu_state.state = NEMU_STOP;
      return;
    }
  }
}