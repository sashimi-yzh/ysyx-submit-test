#include <klib.h>

void _ssbl();

void __attribute__((section(".entry"))) _fsbl() {
  extern char _ssbl_size[], _ssbl_start[], _sram_start[];
  uint32_t loop = (uint32_t)_ssbl_size >> 2;
  uint32_t *origin_addr = (uint32_t *)_ssbl_start;
  uint32_t *target_addr = (uint32_t *)_sram_start;

  while (loop--) {
    *target_addr = *origin_addr;
    origin_addr++;
    target_addr++;
  }
  uint32_t remain = (uint32_t)_ssbl_size & 0x3;
  uint8_t *remain_origin_addr = (uint8_t *)origin_addr;
  uint8_t *remain_target_addr = (uint8_t *)target_addr;

  while (remain--) {
    *remain_target_addr = *remain_origin_addr;
    remain_origin_addr++;
    remain_target_addr++;
  }
  _ssbl();
}

void __attribute__((section(".ssbl"))) __attribute__((noinline))
ssbl_memcpy(uint32_t size, uint32_t *origin_addr, uint32_t *target_addr) {
  uint32_t loop = (uint32_t)size >> 2;

  while (loop--) {
    *target_addr = *origin_addr;
    origin_addr++;
    target_addr++;
  }
  uint32_t remain = (uint32_t)size & 0x3;
  uint8_t *remain_origin_addr = (uint8_t *)origin_addr;
  uint8_t *remain_target_addr = (uint8_t *)target_addr;

  while (remain--) {
    *remain_target_addr = *remain_origin_addr;
    remain_origin_addr++;
    remain_target_addr++;
  }
}

void _trm_init();

void __attribute__((section(".ssbl"))) __attribute__((noinline)) _ssbl() {
  extern char _text_size[], _text_start[], _sdram_start[];
  ssbl_memcpy((uint32_t)_text_size, (uint32_t *)_text_start,
              (uint32_t *)_sdram_start);

  extern char _rodata_size[], _rodata_start[], _rodata_target[];
  ssbl_memcpy((uint32_t)_rodata_size, (uint32_t *)_rodata_start,
              (uint32_t *)_rodata_target);

  extern char _data_size[], _data_start[], _data_target[];
  ssbl_memcpy((uint32_t)_data_size, (uint32_t *)_data_start,
              (uint32_t *)_data_target);

  _trm_init();
}