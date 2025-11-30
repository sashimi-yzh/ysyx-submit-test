#include <memory/host.h>
#include <memory/paddr.h>

static uint8_t sram[0x2000] PG_ALIGN = {};

static uint8_t* guest_to_host_sram(paddr_t paddr) { return sram + paddr - 0x0f000000;}

word_t sram_read(paddr_t addr, int len) {
	word_t ret = host_read(guest_to_host_sram(addr), len);
  return ret;
}

void sram_write(paddr_t addr, int len, word_t data) {
  host_write(guest_to_host_sram(addr), len, data);
}
