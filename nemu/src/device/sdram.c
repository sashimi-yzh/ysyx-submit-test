#include <utils.h>
#include <device/map.h>

static uint8_t *sdram_base = NULL;

static inline void sdram_io_handler(uint32_t offset, int len, bool is_write) {}

void init_sdram(device_init_param_t *param) {
  sdram_base = new_space(CONFIG_SDRAM_SIZE);
  IOMap *map = add_mmio_map("sdram", CONFIG_SDRAM_MMIO, sdram_base, CONFIG_SDRAM_SIZE, sdram_io_handler, false);
  if (param->sdram_img) {
    device_load_img(map, param->sdram_img);
  }
}
