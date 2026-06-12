#include <utils.h>
#include <device/map.h>

static uint8_t *mrom_base = NULL;

static inline void mrom_io_handler(uint32_t offset, int len, bool is_write) {
  Assert(!is_write, "MROM is read only");
}


void init_mrom(device_init_param_t *param) {
  mrom_base = new_space(CONFIG_MROM_SIZE);
  IOMap *map = add_mmio_map("mrom", CONFIG_MROM_MMIO, mrom_base, CONFIG_MROM_SIZE, mrom_io_handler, false);
  if (param->mrom_img) {
    device_load_img(map, param->mrom_img);
  }
}
