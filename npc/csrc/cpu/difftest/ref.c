#include "utils.h"
#include "difftest_def.h"

__EXPORT void difftest_memcpy(paddr_t addr, void *buf, size_t n, bool direction) {
  assert(0);
}

__EXPORT void difftest_regcpy(void *dut, bool direction) {
  assert(0);
}

__EXPORT void difftest_exec(uint64_t n) {
  assert(0);
}

__EXPORT void difftest_raise_intr(word_t NO) {
  assert(0);
}

// __EXPORT void difftest_init(int port) {
//   void init_mem();
//   init_mem();
//   /* Perform ISA dependent initialization. */
//   init_isa();
// }
