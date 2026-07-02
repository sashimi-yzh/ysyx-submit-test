#include <memory/paddr.h>
#include <isa.h>
#include <platform/platform.h>

void init_mem() {
  platform_log_memory();
}

static bool valid_access_len(int len) {
  return len == 1 || len == 2 || len == 4;
}

word_t paddr_read(paddr_t addr, int len) {
  word_t data = 0;
  Assert(valid_access_len(len),
      "invalid paddr read length: pc=" FMT_WORD " addr=" FMT_PADDR " len=%d",
      cpu.pc, addr, len);
  if (likely(platform_read(addr, len, &data))) {
    return data;
  }
  platform_out_of_bound(addr);
  return 0;
}

void paddr_write(paddr_t addr, int len, word_t data) {
  Assert(valid_access_len(len),
      "invalid paddr write length: pc=" FMT_WORD " addr=" FMT_PADDR
      " len=%d data=" FMT_WORD,
      cpu.pc, addr, len, data);
  if (likely(platform_write(addr, len, data))) {
    return;
  }
  platform_out_of_bound(addr);
}
