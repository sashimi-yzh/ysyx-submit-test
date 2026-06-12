#ifndef __DEVICE_H__
#define __DEVICE_H__

typedef struct {
  char *mrom_img;
  char *sram_img;
  char *flash_img;
  char *sdram_img;
} device_init_param_t;

#endif
