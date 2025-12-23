#include <common.h>
#include <utils.h>

void display_pread(paddr_t addr, int len) {
  printf("pread at " FMT_PADDR " len = %d\n", addr, len);
}

void display_pwrite(paddr_t addr, int len, word_t data) {
  printf("pwrite at " FMT_PADDR " len = %d  data = " FMT_WORD "\n", addr, len, data);
}
