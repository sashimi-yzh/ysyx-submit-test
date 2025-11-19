#include <common.h>
#include <utils.h>
#include <device/map.h>

void display_dread(paddr_t addr, int len, IOMap *map) {
	printf("\ndtrace: read %10s at " FMT_PADDR ", len = %d\n",
		map->name, addr, len);
}

void display_dwrite(paddr_t addr, int len, word_t data, IOMap *map) {
	printf("\ndtrace: write %10s at " FMT_PADDR ", len = %d, data = " FMT_WORD "\n",
		map->name, addr, len, data);
}