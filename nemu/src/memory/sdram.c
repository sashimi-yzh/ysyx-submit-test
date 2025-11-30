#include <memory/host.h>                                                    
#include <memory/paddr.h>

static uint8_t sdram[0x20000000] PG_ALIGN = {0};

static uint8_t* guest_to_host_sdram(paddr_t paddr) { return sdram + paddr - 0xa0000000;}

word_t sdram_read(paddr_t addr, int len) {
	word_t ret = host_read(guest_to_host_sdram(addr), len);
	return ret;
}

void sdram_write(paddr_t addr, int len, word_t data) {
  host_write(guest_to_host_sdram(addr), len, data);
}

