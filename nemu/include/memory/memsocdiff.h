// the diff tools for soc
#include <stdint.h>
#include "isa.h"

  typedef struct {
    uint32_t soc_start;
    uint32_t soc_end;
    char *name;
    uint8_t *space;
  } soc_device;

void init_soc();
soc_device *fetch_the_soc(paddr_t addr);
