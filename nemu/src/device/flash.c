#include <utils.h>
#include <device/map.h>

static uint8_t *flash_base = NULL;

static inline void flash_io_handler(uint32_t offset, int len, bool is_write) {
  Assert(!is_write, "Flash is read only");
}


void init_flash(device_init_param_t *param) {
  flash_base = new_space(CONFIG_FLASH_SIZE);
  IOMap *map = add_mmio_map("flash", CONFIG_FLASH_MMIO, flash_base, CONFIG_FLASH_SIZE, flash_io_handler, false);
  if (param->flash_img) {
    device_load_img(map, param->flash_img);
  }
}
