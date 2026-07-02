#include <contract_suite.h>
extern char _data_start, _data_end, _data_load_start;
extern char _bss_start, _bss_end;
extern char _heap_start, _heap_end;
extern char _stack_pointer;
static uint32_t data_probe = 0x10203040u;
static uint32_t bss_probe;
static void check_range(uintptr_t x, uintptr_t lo, uintptr_t hi, const char *stage) { CONTRACT_CHECK_POINT("ysyxsoc-layout-flash-sdram", x >= lo && x < hi, stage); }
static void point_layout(void) {
  const uintptr_t sdram_lo = 0xa0000000u, sdram_hi = 0xa2000000u, flash_lo = 0x30000000u, flash_hi = 0x31000000u;
  check_range((uintptr_t)&_data_start, sdram_lo, sdram_hi, "data-start"); check_range((uintptr_t)&_data_end - 1u, sdram_lo, sdram_hi, "data-end"); check_range((uintptr_t)&_data_load_start, flash_lo, flash_hi, "data-lma");
  check_range((uintptr_t)&_bss_start, sdram_lo, sdram_hi, "bss-start"); check_range((uintptr_t)&_bss_end - 1u, sdram_lo, sdram_hi, "bss-end"); check_range((uintptr_t)&_heap_start, sdram_lo, sdram_hi, "heap-start"); check_range((uintptr_t)&_heap_end - 1u, sdram_lo, sdram_hi, "heap-end"); check_range((uintptr_t)&_stack_pointer - 1u, sdram_lo, sdram_hi, "stack-top");
  CONTRACT_CHECK_POINT("ysyxsoc-layout-flash-sdram", data_probe == 0x10203040u, "data-probe"); CONTRACT_CHECK_POINT("ysyxsoc-layout-flash-sdram", bss_probe == 0, "bss-probe"); bss_probe = 0x50607080u; CONTRACT_CHECK_POINT("ysyxsoc-layout-flash-sdram", bss_probe == 0x50607080u, "bss-write");
}
int main(const char *args) { (void)args; contract_suite_begin(); CONTRACT_RUN("ysyxsoc-layout-flash-sdram", point_layout); contract_suite_pass(); }
