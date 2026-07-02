#ifndef AM_CONTRACT_SUITE_H__
#define AM_CONTRACT_SUITE_H__

#include <am.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#ifndef CONTRACT_SUITE
#define CONTRACT_SUITE "unknown-suite"
#endif

static inline void contract_puts(const char *s) {
  while (*s) putch(*s++);
}

static inline void contract_putc(char ch) {
  putch(ch);
}

static inline void contract_puthex4(uint32_t v) {
  v &= 0xfu;
  putch((char)(v < 10 ? '0' + v : 'a' + v - 10));
}

static inline void contract_puthex32(uint32_t v) {
  contract_puts("0x");
  for (int i = 7; i >= 0; i--) contract_puthex4(v >> (i * 4));
}

static inline void contract_putu64(uint64_t v) {
  char buf[21];
  int n = 0;
  if (v == 0) {
    putch('0');
    return;
  }
  while (v != 0) {
    buf[n++] = (char)('0' + (v % 10));
    v /= 10;
  }
  while (n > 0) putch(buf[--n]);
}

static inline void contract_line(const char *point, const char *status, const char *stage) {
  contract_puts("CONTRACT " CONTRACT_SUITE " TEST ");
  contract_puts(point);
  contract_putc(' ');
  contract_puts(status);
  if (stage != NULL && *stage != '\0') {
    contract_putc(' ');
    contract_puts(stage);
  }
  contract_putc('\n');
}

static inline void contract_suite_begin(void) {
  contract_puts("CONTRACT " CONTRACT_SUITE " BEGIN\n");
}

static inline void contract_suite_pass(void) __attribute__((noreturn));
static inline void contract_suite_pass(void) {
  contract_puts("CONTRACT " CONTRACT_SUITE " PASS\n");
  halt(0);
}

static inline void contract_suite_fail(const char *point, const char *stage) __attribute__((noreturn));
static inline void contract_suite_fail(const char *point, const char *stage) {
  contract_line(point, "FAIL", stage);
  contract_puts("CONTRACT " CONTRACT_SUITE " FAIL\n");
  halt(1);
}

static inline void contract_begin_point(const char *point) {
  contract_line(point, "BEGIN", NULL);
}

static inline void contract_pass_point(const char *point) {
  contract_line(point, "PASS", NULL);
}

static inline void contract_block_point(const char *point, const char *stage) {
  contract_line(point, "BLOCKED", stage);
}

#define CONTRACT_CHECK_POINT(point, cond, stage) \
  do { \
    if (!(cond)) contract_suite_fail((point), (stage)); \
  } while (0)

#define CONTRACT_RUN(point, fn) \
  do { \
    contract_begin_point((point)); \
    (fn)(); \
    contract_pass_point((point)); \
  } while (0)

#define CONTRACT_RUN_ARGS(point, fn, arg) \
  do { \
    contract_begin_point((point)); \
    (fn)(arg); \
    contract_pass_point((point)); \
  } while (0)

#endif
