#include <common.h>
#include <utils.h>
#include <mem.h>

void display_pread(paddr_t addr) {
  printf("pread at " FMT_PADDR " data = " FMT_WORD "\n", addr, *(uint32_t *)guest_to_host(addr));
}

void display_pwrite(paddr_t addr, word_t data) {
  printf("pwrite at " FMT_PADDR " data = " FMT_WORD "\n", addr, data);
}
