#include <contract_suite.h>

extern char _ssbl_vma_start, _ssbl_vma_end, _ssbl_lma_start;
extern char _data_start, _data_end, _data_load_start;
extern char _bss_start, _bss_end;
extern char _heap_start, _heap_end;

static inline uintptr_t read_sp(void) { uintptr_t sp; asm volatile("mv %0, sp" : "=r"(sp)); return sp; }
static void check_range_point(const char *point, uintptr_t x, uintptr_t lo, uintptr_t hi, const char *stage) { CONTRACT_CHECK_POINT(point, x >= lo && x < hi, stage); }
static void check_window(uintptr_t base, const char *point, const char *stage) { volatile uint32_t *p = (volatile uint32_t *)base; for (int i = 0; i < 16; i++) p[i] = 0x5a5a0000u + (uint32_t)i; for (int i = 0; i < 16; i++) CONTRACT_CHECK_POINT(point, p[i] == 0x5a5a0000u + (uint32_t)i, stage); }

static void point_address_map(void) {
  const uintptr_t sram_lo = 0x0f000000u, sram_hi = 0x0f002000u;
  const uintptr_t flash_lo = 0x30000000u, flash_hi = 0x31000000u;
  const uintptr_t sdram_lo = 0xa0000000u, sdram_hi = 0xa2000000u;
  check_range_point("ysyxsoc-address-map", (uintptr_t)&_ssbl_vma_start, sram_lo, sram_hi, "ssbl-start");
  check_range_point("ysyxsoc-address-map", (uintptr_t)&_ssbl_vma_end - 1u, sram_lo, sram_hi, "ssbl-end");
  check_range_point("ysyxsoc-address-map", (uintptr_t)&_ssbl_lma_start, flash_lo, flash_hi, "ssbl-lma");
  check_range_point("ysyxsoc-address-map", (uintptr_t)&_data_start, sdram_lo, sdram_hi, "data-start");
  check_range_point("ysyxsoc-address-map", (uintptr_t)&_data_end - 1u, sdram_lo, sdram_hi, "data-end");
  check_range_point("ysyxsoc-address-map", (uintptr_t)&_data_load_start, flash_lo, flash_hi, "data-lma");
  check_range_point("ysyxsoc-address-map", (uintptr_t)&_bss_start, sdram_lo, sdram_hi, "bss-start");
  check_range_point("ysyxsoc-address-map", (uintptr_t)&_bss_end - 1u, sdram_lo, sdram_hi, "bss-end");
  check_range_point("ysyxsoc-address-map", (uintptr_t)&_heap_start, sdram_lo, sdram_hi, "heap-start");
  check_range_point("ysyxsoc-address-map", (uintptr_t)&_heap_end - 1u, sdram_lo, sdram_hi, "heap-end");
}
static void point_boot_default(void) {
  const uintptr_t sram_lo = 0x0f000000u, sram_hi = 0x0f002000u;
  check_range_point("ysyxsoc-boot-default", read_sp(), sram_lo, sram_hi, "stack-pointer");
  CONTRACT_CHECK_POINT("ysyxsoc-boot-default", (uintptr_t)&_ssbl_vma_start < (uintptr_t)&_ssbl_vma_end, "ssbl-order");
  CONTRACT_CHECK_POINT("ysyxsoc-boot-default", (uintptr_t)&_data_start < (uintptr_t)&_data_end, "data-order");
}
static void point_runtime_copy(void) {
  static uint32_t data_probe = 0x11223344u;
  static uint32_t bss_probe;
  CONTRACT_CHECK_POINT("ysyxsoc-runtime-copy", data_probe == 0x11223344u, "data-probe");
  CONTRACT_CHECK_POINT("ysyxsoc-runtime-copy", bss_probe == 0, "bss-probe");
  bss_probe = 0xaabbccddu;
  CONTRACT_CHECK_POINT("ysyxsoc-runtime-copy", bss_probe == 0xaabbccddu, "bss-write");
  check_window((uintptr_t)&_heap_start, "ysyxsoc-runtime-copy", "heap-head-write");
  check_window(((uintptr_t)&_heap_end - 128u) & ~(uintptr_t)0x3u, "ysyxsoc-runtime-copy", "heap-tail-write");
}
static void point_trm_init_order(void) {
  CONTRACT_CHECK_POINT("ysyxsoc-trm-init-order", (uintptr_t)heap.start == (uintptr_t)&_heap_start, "heap-start");
  CONTRACT_CHECK_POINT("ysyxsoc-trm-init-order", (uintptr_t)heap.end == (uintptr_t)&_heap_end, "heap-end");
}
int main(const char *args) { (void)args; contract_suite_begin(); CONTRACT_RUN("ysyxsoc-address-map", point_address_map); CONTRACT_RUN("ysyxsoc-boot-default", point_boot_default); CONTRACT_RUN("ysyxsoc-runtime-copy", point_runtime_copy); CONTRACT_RUN("ysyxsoc-trm-init-order", point_trm_init_order); contract_suite_pass(); }
