#include <contract_suite.h>

static uint32_t data_word = 0x13579bdfu;
static uint8_t data_bytes[8] = {0x13, 0x57, 0x9b, 0xdf, 0x24, 0x68, 0xac, 0xe0};
static uint32_t bss_word;
static uint8_t bss_bytes[64];

static bool local_streq(const char *a, const char *b) {
  while (*a && *b && *a == *b) { a++; b++; }
  return *a == *b;
}

static void write_pattern(uintptr_t base, size_t n, uint8_t seed) {
  volatile uint8_t *p = (volatile uint8_t *)base;
  for (size_t i = 0; i < n; i++) p[i] = (uint8_t)(seed + i * 13u);
}

static void check_pattern(uintptr_t base, size_t n, uint8_t seed, const char *stage) {
  volatile uint8_t *p = (volatile uint8_t *)base;
  for (size_t i = 0; i < n; i++) CONTRACT_CHECK_POINT("heap-contract", p[i] == (uint8_t)(seed + i * 13u), stage);
}

static void point_entry_putch_halt(void) {
  contract_puts("TRM_PUTCH_TOKEN\n");
}

static void point_mainargs_runtime(const char *args) {
  CONTRACT_CHECK_POINT("mainargs-runtime", args != NULL, "args-nonnull");
  CONTRACT_CHECK_POINT("mainargs-runtime", local_streq(args, "contract-mainargs-0123456789abcdef0123456789abcdef"), "args-match");
}

static void point_sections_init(void) {
  static const uint8_t exp[8] = {0x13, 0x57, 0x9b, 0xdf, 0x24, 0x68, 0xac, 0xe0};
  CONTRACT_CHECK_POINT("sections-init", data_word == 0x13579bdfu, "data-word");
  for (int i = 0; i < 8; i++) CONTRACT_CHECK_POINT("sections-init", data_bytes[i] == exp[i], "data-bytes");
  CONTRACT_CHECK_POINT("sections-init", bss_word == 0, "bss-word");
  for (int i = 0; i < 64; i++) {
    CONTRACT_CHECK_POINT("sections-init", bss_bytes[i] == 0, "bss-bytes");
    bss_bytes[i] = (uint8_t)(0x40 + i);
  }
  for (int i = 0; i < 64; i++) CONTRACT_CHECK_POINT("sections-init", bss_bytes[i] == (uint8_t)(0x40 + i), "bss-write");
}

static void point_stack_probe(void) {
  volatile uint32_t stack_words[32];
  for (int i = 0; i < 32; i++) stack_words[i] = 0xa5a50000u + (uint32_t)i;
  for (int i = 0; i < 32; i++) CONTRACT_CHECK_POINT("stack-probe", stack_words[i] == 0xa5a50000u + (uint32_t)i, "stack-data");
}

static void point_heap_contract(void) {
  uintptr_t start = (uintptr_t)heap.start;
  uintptr_t end = (uintptr_t)heap.end;
  CONTRACT_CHECK_POINT("heap-contract", start != 0 && end > start, "heap-range");
  CONTRACT_CHECK_POINT("heap-contract", (start & 0x3u) == 0 && (end & 0x3u) == 0, "heap-align");
  CONTRACT_CHECK_POINT("heap-contract", end - start >= 4096, "heap-size");
  uintptr_t head = start;
  uintptr_t mid = (start + (end - start) / 2u) & ~(uintptr_t)0x3u;
  uintptr_t tail = (end - 512u) & ~(uintptr_t)0x3u;
  CONTRACT_CHECK_POINT("heap-contract", head + 256 <= mid && mid + 256 <= tail && tail + 256 <= end, "heap-windows");
  write_pattern(head, 256, 0x10);
  write_pattern(mid, 256, 0x40);
  write_pattern(tail, 256, 0x80);
  check_pattern(head, 256, 0x10, "heap-head");
  check_pattern(mid, 256, 0x40, "heap-mid");
  check_pattern(tail, 256, 0x80, "heap-tail");
}

int main(const char *args) {
  contract_suite_begin();
  CONTRACT_RUN("entry-putch-halt", point_entry_putch_halt);
  CONTRACT_RUN_ARGS("mainargs-runtime", point_mainargs_runtime, args);
  CONTRACT_RUN("sections-init", point_sections_init);
  CONTRACT_RUN("stack-probe", point_stack_probe);
  CONTRACT_RUN("heap-contract", point_heap_contract);
  contract_suite_pass();
}
