#include <contract_suite.h>
#include <klib.h>
#include <limits.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>

static uint8_t buf[128];
static uint8_t src[128];

static void fill_seq(uint8_t *p, size_t n, uint8_t seed) { for (size_t i = 0; i < n; i++) p[i] = (uint8_t)(seed + i); }
static bool local_streq(const char *a, const char *b) { size_t i = 0; while (a[i] && b[i] && a[i] == b[i]) i++; return a[i] == b[i]; }
static bool local_memeq(const uint8_t *a, const uint8_t *b, size_t n) { for (size_t i = 0; i < n; i++) if (a[i] != b[i]) return false; return true; }
static size_t local_strlen(const char *s) { size_t n = 0; while (s[n]) n++; return n; }
static void check_range(const uint8_t *p, size_t n, uint8_t val, const char *stage) { for (size_t i = 0; i < n; i++) CONTRACT_CHECK_POINT("string-api", p[i] == val, stage); }
static void check_seq(const uint8_t *p, size_t n, uint8_t seed, const char *stage) { for (size_t i = 0; i < n; i++) CONTRACT_CHECK_POINT("string-api", p[i] == (uint8_t)(seed + i), stage); }

static void point_string_api(void) {
  CONTRACT_CHECK_POINT("string-api", strlen("") == 0, "strlen-empty");
  CONTRACT_CHECK_POINT("string-api", strlen("abcdef") == 6, "strlen");
  CONTRACT_CHECK_POINT("string-api", strlen("ab\0hidden") == 2, "strlen-early-nul");
  fill_seq(buf, sizeof(buf), 0xa0); char *dst = (char *)buf + 8;
  CONTRACT_CHECK_POINT("string-api", strcpy(dst, "riscv") == dst, "strcpy-ret");
  CONTRACT_CHECK_POINT("string-api", local_streq(dst, "riscv"), "strcpy-data");
  check_seq(buf, 8, 0xa0, "strcpy-before"); check_seq(buf + 14, 8, (uint8_t)(0xa0 + 14), "strcpy-after");
  fill_seq(buf, sizeof(buf), 0xb0); dst = (char *)buf + 8;
  CONTRACT_CHECK_POINT("string-api", strncpy(dst, "xy", 5) == dst, "strncpy-pad-ret");
  CONTRACT_CHECK_POINT("string-api", dst[0] == 'x' && dst[1] == 'y' && dst[2] == '\0' && dst[3] == '\0' && dst[4] == '\0', "strncpy-pad");
  check_seq(buf, 8, 0xb0, "strncpy-pad-before"); check_seq(buf + 13, 8, (uint8_t)(0xb0 + 13), "strncpy-pad-after");
  fill_seq(buf, sizeof(buf), 0xc0); dst = (char *)buf + 8;
  CONTRACT_CHECK_POINT("string-api", strncpy(dst, "abcdef", 3) == dst, "strncpy-cut-ret");
  CONTRACT_CHECK_POINT("string-api", dst[0] == 'a' && dst[1] == 'b' && dst[2] == 'c' && (uint8_t)dst[3] == (uint8_t)(0xc0 + 11), "strncpy-cut");
  fill_seq(buf, sizeof(buf), 0xd0); dst = (char *)buf + 8; dst[0] = 'h'; dst[1] = 'i'; dst[2] = '\0';
  CONTRACT_CHECK_POINT("string-api", strcat(dst, "!42") == dst, "strcat-ret");
  CONTRACT_CHECK_POINT("string-api", local_streq(dst, "hi!42"), "strcat-data");
  CONTRACT_CHECK_POINT("string-api", strcmp("abc", "abc") == 0, "strcmp-eq");
  CONTRACT_CHECK_POINT("string-api", strcmp("abc", "abd") < 0, "strcmp-lt");
  CONTRACT_CHECK_POINT("string-api", strcmp("abe", "abd") > 0, "strcmp-gt");
  CONTRACT_CHECK_POINT("string-api", strcmp("abc", "abcd") < 0, "strcmp-prefix-lt");
  CONTRACT_CHECK_POINT("string-api", strcmp("\xff", "\x7f") > 0, "strcmp-unsigned");
  CONTRACT_CHECK_POINT("string-api", strncmp("abc", "xyz", 0) == 0, "strncmp-zero");
  CONTRACT_CHECK_POINT("string-api", strncmp("abcdef", "abcxyz", 3) == 0, "strncmp-prefix");
  CONTRACT_CHECK_POINT("string-api", strncmp("abcdef", "abcxyz", 4) < 0, "strncmp-diff");
  CONTRACT_CHECK_POINT("string-api", strncmp("abc", "abcd", 4) < 0, "strncmp-nul-lt");
  CONTRACT_CHECK_POINT("string-api", strncmp("\xff", "\x7f", 1) > 0, "strncmp-unsigned");
  fill_seq(buf, sizeof(buf), 0x10);
  CONTRACT_CHECK_POINT("string-api", memset(buf + 8, 0x5a, 16) == buf + 8, "memset-ret");
  check_seq(buf, 8, 0x10, "memset-before"); check_range(buf + 8, 16, 0x5a, "memset-mid");
  fill_seq(buf, sizeof(buf), 0x30); fill_seq(src, sizeof(src), 0x80);
  CONTRACT_CHECK_POINT("string-api", memcpy(buf + 4, src + 9, 23) == buf + 4, "memcpy-ret");
  CONTRACT_CHECK_POINT("string-api", local_memeq(buf + 4, src + 9, 23), "memcpy-data");
  CONTRACT_CHECK_POINT("string-api", memcpy(buf + 1, src + 1, 0) == buf + 1, "memcpy-zero-ret");
  fill_seq(buf, sizeof(buf), 0x40); memmove(buf + 7, buf, 32); for (int i = 0; i < 32; i++) CONTRACT_CHECK_POINT("string-api", buf[7 + i] == (uint8_t)(0x40 + i), "memmove-overlap-right");
  fill_seq(buf, sizeof(buf), 0x50); memmove(buf, buf + 7, 32); for (int i = 0; i < 32; i++) CONTRACT_CHECK_POINT("string-api", buf[i] == (uint8_t)(0x50 + 7 + i), "memmove-overlap-left");
  fill_seq(buf, sizeof(buf), 0x60); CONTRACT_CHECK_POINT("string-api", memmove(buf + 5, buf + 5, 20) == buf + 5, "memmove-same-ret"); check_seq(buf, 48, 0x60, "memmove-same-data");
  uint8_t a0[] = {0x00, 0x7f, 0x80, 0xff}; uint8_t a1[] = {0x00, 0x7f, 0x80, 0xff}; uint8_t a2[] = {0x00, 0x7f, 0x81, 0x00};
  CONTRACT_CHECK_POINT("string-api", memcmp(a0, a1, 4) == 0, "memcmp-eq");
  CONTRACT_CHECK_POINT("string-api", memcmp(a0, a2, 4) < 0, "memcmp-lt");
  CONTRACT_CHECK_POINT("string-api", memcmp(a2, a0, 4) > 0, "memcmp-gt");
  CONTRACT_CHECK_POINT("string-api", memcmp(a0, a2, 0) == 0, "memcmp-zero");
}

static void fill_guard(char *p, size_t n) { for (size_t i = 0; i < n; i++) p[i] = (char)0xcc; }

static void check_vsprintf(const char *stage, const char *exp, const char *fmt, ...) {
  char out[160]; fill_guard(out, sizeof(out));
  va_list ap; va_start(ap, fmt); int ret = vsprintf(out, fmt, ap); va_end(ap);
  CONTRACT_CHECK_POINT("stdio-format-buffer", ret == (int)local_strlen(exp), stage);
  CONTRACT_CHECK_POINT("stdio-format-buffer", local_streq(out, exp), stage);
  CONTRACT_CHECK_POINT("stdio-format-buffer", out[local_strlen(exp) + 1] == (char)0xcc, stage);
}

static void check_vsnprintf_ret(const char *stage, const char *out_exp, int ret_exp, size_t n, const char *fmt, ...) {
  char out[160]; fill_guard(out, sizeof(out));
  va_list ap; va_start(ap, fmt); int ret = vsnprintf(out, n, fmt, ap); va_end(ap);
  CONTRACT_CHECK_POINT("stdio-format-buffer", ret == ret_exp, stage);
  if (n > 0) {
    CONTRACT_CHECK_POINT("stdio-format-buffer", local_streq(out, out_exp), stage);
    if (n < sizeof(out)) CONTRACT_CHECK_POINT("stdio-format-buffer", out[n] == (char)0xcc, stage);
  }
}

static void point_stdio_format_buffer(void) {
  char out[160]; fill_guard(out, sizeof(out));
  int ret = sprintf(out, "%d %i %u %x %X", -12345, -7, 4000000000u, 0x1a2b3c4du, 0xfeedu);
  CONTRACT_CHECK_POINT("stdio-format-buffer", ret == 34, "sprintf-ret");
  CONTRACT_CHECK_POINT("stdio-format-buffer", local_streq(out, "-12345 -7 4000000000 1a2b3c4d FEED"), "sprintf-basic");
  CONTRACT_CHECK_POINT("stdio-format-buffer", out[ret + 1] == (char)0xcc, "sprintf-guard");
  fill_guard(out, sizeof(out)); const char *long_exp = "-2147483647 -1234567890123 123456789abcdef0";
  ret = sprintf(out, "%ld %lld %llx", (long)-2147483647L, -1234567890123ll, 0x123456789abcdef0ull);
  CONTRACT_CHECK_POINT("stdio-format-buffer", ret == (int)local_strlen(long_exp), "sprintf-long-ret");
  CONTRACT_CHECK_POINT("stdio-format-buffer", local_streq(out, long_exp), "sprintf-long");
  check_vsprintf("vsprintf-basic", "ptr=0x1234abcd end", "ptr=%p %s", (void *)0x1234abcd, "end");
  ret = snprintf(out, sizeof(out), "%08d|%-5c|%q", -42, 'Z');
  CONTRACT_CHECK_POINT("stdio-format-buffer", ret == 17, "snprintf-ret");
  CONTRACT_CHECK_POINT("stdio-format-buffer", local_streq(out, "-0000042|Z    |%q"), "snprintf-basic");
  check_vsnprintf_ret("vsnprintf-string", "hi      |00042|%", 16, sizeof(out), "%-8s|%05d|%%", "hi", 42);
  check_vsnprintf_ret("vsnprintf-char", "A 0", 3, sizeof(out), "%c %u", 'A', 0u);
  check_vsnprintf_ret("vsnprintf-null", "(null)", 6, sizeof(out), "%s", (const char *)NULL);
  check_vsnprintf_ret("vsnprintf-int-min", "-2147483648", 11, sizeof(out), "%d", (int)0x80000000u);
  check_vsnprintf_ret("vsnprintf-trunc", "-214748", 20, 8, "%d-%x", (int)0x80000000u, 0xffffffffu);
  ret = snprintf(NULL, 0, "%x", 0x1234u);
  CONTRACT_CHECK_POINT("stdio-format-buffer", ret == 4, "snprintf-null");
  check_vsnprintf_ret("vsnprintf-zero", "", 4, 0, "%x", 0x1234u);
}

static void point_stdio_printf_output(void) {
  int pret = printf("KLIB_PRINTF_TOKEN\n");
  CONTRACT_CHECK_POINT("stdio-printf-output", pret == 18, "printf-ret");
}

static bool range_overlap(const uint8_t *a, size_t an, const uint8_t *b, size_t bn) {
  uintptr_t al = (uintptr_t)a, ar = al + an, bl = (uintptr_t)b, br = bl + bn;
  return al < br && bl < ar;
}
static void fill_block(uint8_t *p, size_t n, uint8_t seed) { for (size_t i = 0; i < n; i++) p[i] = (uint8_t)(seed + i); }
static void check_block(const uint8_t *p, size_t n, uint8_t seed, const char *stage) { for (size_t i = 0; i < n; i++) CONTRACT_CHECK_POINT("stdlib-api", p[i] == (uint8_t)(seed + i), stage); }

static void point_stdlib_api(void) {
  CONTRACT_CHECK_POINT("stdlib-api", atoi("0") == 0, "atoi-zero");
  CONTRACT_CHECK_POINT("stdlib-api", atoi("") == 0, "atoi-empty");
  CONTRACT_CHECK_POINT("stdlib-api", atoi("abc") == 0, "atoi-no-digit");
  CONTRACT_CHECK_POINT("stdlib-api", atoi("0012") == 12, "atoi-leading-zero");
  CONTRACT_CHECK_POINT("stdlib-api", atoi("  12345xyz") == 12345, "atoi-space");
  CONTRACT_CHECK_POINT("stdlib-api", atoi("77 88") == 77, "atoi-stop-space");
  CONTRACT_CHECK_POINT("stdlib-api", abs(0) == 0 && abs(123) == 123 && abs(-123) == 123, "abs");
  srand(1); int r0 = rand(); int r1 = rand(); int r2 = rand(); srand(1);
  CONTRACT_CHECK_POINT("stdlib-api", rand() == r0 && rand() == r1 && rand() == r2, "rand-repeat");
  CONTRACT_CHECK_POINT("stdlib-api", r0 != r1 || r1 != r2, "rand-advance");
  CONTRACT_CHECK_POINT("stdlib-api", r0 >= 0 && r0 < 32768 && r1 >= 0 && r1 < 32768 && r2 >= 0 && r2 < 32768, "rand-range");
  uint8_t *a = (uint8_t *)malloc(16), *b = (uint8_t *)malloc(24), *c = (uint8_t *)malloc(1), *d = (uint8_t *)malloc(40);
  CONTRACT_CHECK_POINT("stdlib-api", a && b && c && d, "malloc-nonnull");
  CONTRACT_CHECK_POINT("stdlib-api", !range_overlap(a,16,b,24) && !range_overlap(a,16,c,1) && !range_overlap(a,16,d,40), "malloc-a-overlap");
  CONTRACT_CHECK_POINT("stdlib-api", !range_overlap(b,24,c,1) && !range_overlap(b,24,d,40) && !range_overlap(c,1,d,40), "malloc-bcd-overlap");
  fill_block(a,16,0xa0); fill_block(b,24,0xb0); fill_block(c,1,0xc0); fill_block(d,40,0xd0);
  check_block(a,16,0xa0,"malloc-a"); check_block(b,24,0xb0,"malloc-b"); check_block(c,1,0xc0,"malloc-c"); check_block(d,40,0xd0,"malloc-d");
  free(a); free(b); check_block(c,1,0xc0,"free-live-c"); check_block(d,40,0xd0,"free-live-d");
  uint8_t *e = (uint8_t *)malloc(8); CONTRACT_CHECK_POINT("stdlib-api", e != NULL, "malloc-after-free");
  CONTRACT_CHECK_POINT("stdlib-api", !range_overlap(e,8,c,1) && !range_overlap(e,8,d,40), "malloc-e-overlap");
  fill_block(e,8,0xe0); check_block(c,1,0xc0,"malloc-e-live-c"); check_block(d,40,0xd0,"malloc-e-live-d"); check_block(e,8,0xe0,"malloc-e");
  free(c); free(d); free(e);
}

static void point_int64_runtime_rv32e(void) {
#if defined(__riscv_e)
  volatile uint64_t a = 0x123456789abcdef0ull;
  volatile uint64_t b = 0x12345ull;
  CONTRACT_CHECK_POINT("int64-runtime-rv32e", a / b == 0x100005b00205ull, "udiv64");
  CONTRACT_CHECK_POINT("int64-runtime-rv32e", a % b == 0xa497ull, "umod64");
  volatile int64_t s = -1234567890123ll;
  volatile int64_t d = 321ll;
  CONTRACT_CHECK_POINT("int64-runtime-rv32e", s / d == -3846005888ll, "sdiv64");
  CONTRACT_CHECK_POINT("int64-runtime-rv32e", s % d == -75ll, "smod64");
  volatile uint64_t m0 = 0x12345678abcdef01ull;
  volatile uint64_t m1 = 0x100000001ull;
  CONTRACT_CHECK_POINT("int64-runtime-rv32e", (m0 * m1) == 0xbe024579abcdef01ull, "umul64");
  CONTRACT_CHECK_POINT("int64-runtime-rv32e", (m0 << 13) == 0x8acf1579bde02000ull, "shl64");
  CONTRACT_CHECK_POINT("int64-runtime-rv32e", (m0 >> 17) == 0x0000091a2b3c55e6ull, "shr64");
#else
  CONTRACT_CHECK_POINT("int64-runtime-rv32e", true, "not-rv32e");
#endif
}

int main(const char *args) {
  (void)args;
  contract_suite_begin();
  CONTRACT_RUN("string-api", point_string_api);
  CONTRACT_RUN("stdio-format-buffer", point_stdio_format_buffer);
  CONTRACT_RUN("stdio-printf-output", point_stdio_printf_output);
  CONTRACT_RUN("int64-runtime-rv32e", point_int64_runtime_rv32e);
  CONTRACT_RUN("stdlib-api", point_stdlib_api);
  contract_suite_pass();
}
