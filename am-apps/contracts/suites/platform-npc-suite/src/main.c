#include <contract_suite.h>
#include <klib-macros.h>

extern char _pmem_start;
extern char _heap_start;

static void point_npc_map(void) {
  uintptr_t pmem = (uintptr_t)&_pmem_start;
  uintptr_t hs = (uintptr_t)&_heap_start;
  CONTRACT_CHECK_POINT("npc-map", pmem == 0x80000000u, "pmem-start");
  CONTRACT_CHECK_POINT("npc-map", hs >= 0x80000000u && hs < 0x88000000u, "heap-start");
  CONTRACT_CHECK_POINT("npc-map", (uintptr_t)heap.end == 0x88000000u, "heap-end");
}

int main(const char *args) { (void)args; contract_suite_begin(); CONTRACT_RUN("npc-map", point_npc_map); contract_suite_pass(); }
