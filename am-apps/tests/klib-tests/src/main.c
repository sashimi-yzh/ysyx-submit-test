#include <am.h>
#include <klib.h>
#include <limits.h>
#include <stdint.h>

#define N 32

static uint8_t data[N];
static uint8_t src_data[N];
static uint8_t model[N];

static void reset_seq(uint8_t *buf) {
  for (int i = 0; i < N; i++) {
    buf[i] = (uint8_t)(i + 1);
  }
}

static void copy_buf(uint8_t *dst, const uint8_t *src) {
  for (int i = 0; i < N; i++) {
    dst[i] = src[i];
  }
}

static void check_seq(const uint8_t *buf, int l, int r, int val) {
  for (int i = l; i < r; i++) {
    assert(buf[i] == (uint8_t)(val + i - l));
  }
}

static void check_eq(const uint8_t *buf, int l, int r, uint8_t val) {
  for (int i = l; i < r; i++) {
    assert(buf[i] == val);
  }
}

static void check_same(const uint8_t *a, const uint8_t *b) {
  for (int i = 0; i < N; i++) {
    assert(a[i] == b[i]);
  }
}

static void make_ascii_string(char *dst, int len, int seed) {
  for (int i = 0; i < len; i++) {
    dst[i] = (char)('a' + (seed + i) % 26);
  }
  dst[len] = '\0';
}

static int model_memcmp(const uint8_t *a, const uint8_t *b, int n) {
  for (int i = 0; i < n; i++) {
    if (a[i] != b[i]) {
      return (int)a[i] - (int)b[i];
    }
  }
  return 0;
}

static int model_strcmp(const char *a, const char *b) {
  int i = 0;
  while (a[i] && b[i] && a[i] == b[i]) {
    i++;
  }
  return (unsigned char)a[i] - (unsigned char)b[i];
}

static int model_strncmp(const char *a, const char *b, int n) {
  for (int i = 0; i < n; i++) {
    unsigned char ca = (unsigned char)a[i];
    unsigned char cb = (unsigned char)b[i];
    if (ca != cb) {
      return (int)ca - (int)cb;
    }
    if (ca == 0) {
      return 0;
    }
  }
  return 0;
}

static void assert_sprintf_eq(const char *exp, const char *fmt, ...) {
  char buf[128];
  va_list ap;
  va_start(ap, fmt);
  int ret = vsprintf(buf, fmt, ap);
  va_end(ap);
  assert(ret == (int)strlen(exp));
  assert(strcmp(buf, exp) == 0);
}

static void test_sprintf_int_d(void) {
  int data[] = {
    0,
    INT_MAX / 17,
    INT_MAX,
    INT_MIN,
    INT_MIN + 1,
    (int)(UINT_MAX / 17u),
    (int)(INT_MAX / 17u),
    (int)UINT_MAX,
  };

  static const char *exp_d[] = {
    "0",
    "126322567",
    "2147483647",
    "-2147483648",
    "-2147483647",
    "252645135",
    "126322567",
    "-1",
  };

  static const char *exp_d10[] = {
    "         0",
    " 126322567",
    "2147483647",
    "-2147483648",
    "-2147483647",
    " 252645135",
    " 126322567",
    "        -1",
  };

  static const char *exp_d010[] = {
    "0000000000",
    "0126322567",
    "2147483647",
    "-2147483648",
    "-2147483647",
    "0252645135",
    "0126322567",
    "-000000001",
  };

  static const char *exp_d_left[] = {
    "0         |",
    "126322567 |",
    "2147483647|",
    "-2147483648|",
    "-2147483647|",
    "252645135 |",
    "126322567 |",
    "-1        |",
  };

  int cnt = (int)(sizeof(data) / sizeof(data[0]));
  for (int i = 0; i < cnt; i++) {
    assert_sprintf_eq(exp_d[i], "%d", data[i]);
    assert_sprintf_eq(exp_d10[i], "%10d", data[i]);
    assert_sprintf_eq(exp_d010[i], "%010d", data[i]);
    assert_sprintf_eq(exp_d_left[i], "%-10d|", data[i]);
  }
}

static void test_sprintf_uint_hex(void) {
  unsigned data[] = {0u, UINT_MAX / 17u, (unsigned)INT_MAX, (unsigned)INT_MIN, UINT_MAX};

  static const char *exp_u[] = {
    "0",
    "252645135",
    "2147483647",
    "2147483648",
    "4294967295",
  };

  static const char *exp_x[] = {
    "0",
    "f0f0f0f",
    "7fffffff",
    "80000000",
    "ffffffff",
  };

  int cnt = (int)(sizeof(data) / sizeof(data[0]));
  for (int i = 0; i < cnt; i++) {
    assert_sprintf_eq(exp_u[i], "%u", data[i]);
    assert_sprintf_eq(exp_x[i], "%x", data[i]);
  }
}

static void test_sprintf_misc(void) {
  assert_sprintf_eq("hello", "%s", "hello");
  assert_sprintf_eq("      hi", "%8s", "hi");
  assert_sprintf_eq("hi      |", "%-8s|", "hi");
  assert_sprintf_eq("A", "%c", 'A');
  assert_sprintf_eq("%", "%%");
}

static void test_snprintf_truncation(void) {
  char buf[8];
  int ret = snprintf(buf, sizeof(buf), "%d-%x", INT_MIN, UINT_MAX);
  assert(ret == (int)strlen("-2147483648-ffffffff"));
  assert(strcmp(buf, "-214748") == 0);
}

static void test_memset(void) {
  for (int l = 0; l <= N; l++) {
    for (int r = l; r <= N; r++) {
      reset_seq(data);
      uint8_t val = (uint8_t)((l * 7 + r * 11) & 0xff);
      void *ret = memset(data + l, val, (size_t)(r - l));
      assert(ret == data + l);
      check_seq(data, 0, l, 1);
      check_eq(data, l, r, val);
      check_seq(data, r, N, r + 1);
    }
  }
}

static void test_memcpy(void) {
  for (int dl = 0; dl <= N; dl++) {
    for (int sl = 0; sl <= N; sl++) {
      int max_len = N - (dl > sl ? dl : sl);
      for (int len = 0; len <= max_len; len++) {
        reset_seq(data);
        reset_seq(src_data);
        copy_buf(model, data);
        for (int i = 0; i < len; i++) {
          model[dl + i] = src_data[sl + i];
        }

        void *ret = memcpy(data + dl, src_data + sl, (size_t)len);
        assert(ret == data + dl);
        check_same(data, model);
        check_seq(src_data, 0, N, 1);
      }
    }
  }
}

static void test_memmove(void) {
  for (int dl = 0; dl <= N; dl++) {
    for (int sl = 0; sl <= N; sl++) {
      int max_len = N - (dl > sl ? dl : sl);
      for (int len = 0; len <= max_len; len++) {
        reset_seq(data);
        copy_buf(model, data);

        if (dl <= sl) {
          for (int i = 0; i < len; i++) {
            model[dl + i] = model[sl + i];
          }
        } else {
          for (int i = len - 1; i >= 0; i--) {
            model[dl + i] = model[sl + i];
          }
        }

        void *ret = memmove(data + dl, data + sl, (size_t)len);
        assert(ret == data + dl);
        check_same(data, model);
      }
    }
  }
}

static void test_strcpy(void) {
  char src[N + 1];

  for (int l = 0; l < N; l++) {
    for (int len = 0; l + len < N; len++) {
      reset_seq(data);
      make_ascii_string(src, len, l);

      char *ret = strcpy((char *)data + l, src);
      assert(ret == (char *)data + l);
      check_seq(data, 0, l, 1);
      for (int i = 0; i < len; i++) {
        assert(data[l + i] == (uint8_t)src[i]);
      }
      assert(data[l + len] == 0);
      check_seq(data, l + len + 1, N, l + len + 2);
    }
  }
}

static void test_strncpy(void) {
  char src[N + 1];

  for (int l = 0; l <= N; l++) {
    for (int src_len = 0; src_len < N; src_len++) {
      make_ascii_string(src, src_len, l + 3);
      for (int n = 0; l + n <= N; n++) {
        reset_seq(data);

        copy_buf(model, data);
        int cpy = (src_len < n ? src_len : n);
        for (int i = 0; i < cpy; i++) {
          model[l + i] = (uint8_t)src[i];
        }
        for (int i = cpy; i < n; i++) {
          model[l + i] = 0;
        }

        char *ret = strncpy((char *)data + l, src, (size_t)n);
        assert(ret == (char *)data + l);
        check_same(data, model);
      }
    }
  }
}

static void test_strcat(void) {
  char src[N + 1];

  for (int l = 0; l < N; l++) {
    for (int dst_len = 0; l + dst_len < N; dst_len++) {
      for (int src_len = 0; l + dst_len + src_len < N; src_len++) {
        reset_seq(data);
        make_ascii_string((char *)data + l, dst_len, src_len + 5);
        make_ascii_string(src, src_len, l + 7);

        char *ret = strcat((char *)data + l, src);
        assert(ret == (char *)data + l);

        check_seq(data, 0, l, 1);
        for (int i = 0; i < dst_len; i++) {
          assert(data[l + i] == (uint8_t)('a' + (src_len + 5 + i) % 26));
        }
        for (int i = 0; i < src_len; i++) {
          assert(data[l + dst_len + i] == (uint8_t)src[i]);
        }
        assert(data[l + dst_len + src_len] == 0);
        check_seq(data, l + dst_len + src_len + 1, N, l + dst_len + src_len + 2);
      }
    }
  }
}

static void test_memcmp(void) {
  uint8_t a[N], b[N];

  for (int seed = 0; seed < N; seed++) {
    for (int i = 0; i < N; i++) {
      a[i] = (uint8_t)((seed + i * 3) & 0xff);
      b[i] = a[i];
    }

    for (int n = 0; n <= N; n++) {
      int ret = memcmp(a, b, (size_t)n);
      assert(ret == 0);
    }

    for (int pos = 0; pos < N; pos++) {
      for (int delta = -2; delta <= 2; delta++) {
        if (delta == 0) {
          continue;
        }

        for (int i = 0; i < N; i++) {
          b[i] = a[i];
        }
        int v = (int)b[pos] + delta;
        if (v < 0) {
          v = 0;
        }
        if (v > 255) {
          v = 255;
        }
        b[pos] = (uint8_t)v;

        for (int n = 0; n <= N; n++) {
          int exp = model_memcmp(a, b, n);
          int got = memcmp(a, b, (size_t)n);
          if (exp == 0) {
            assert(got == 0);
          } else if (exp < 0) {
            assert(got < 0);
          } else {
            assert(got > 0);
          }
        }
      }
    }
  }
}

static void test_strlen(void) {
  char s[N + 1];

  for (int len = 0; len <= N; len++) {
    make_ascii_string(s, len, len + 9);
    size_t got = strlen(s);
    assert(got == (size_t)len);
  }
}

static void test_strcmp(void) {
  char a[N + 1], b[N + 1];

  for (int la = 0; la <= N; la++) {
    make_ascii_string(a, la, la + 1);
    for (int lb = 0; lb <= N; lb++) {
      make_ascii_string(b, lb, lb + 2);

      int exp = model_strcmp(a, b);
      int got = strcmp(a, b);
      if (exp == 0) {
        assert(got == 0);
      } else if (exp < 0) {
        assert(got < 0);
      } else {
        assert(got > 0);
      }
    }
  }
}

static void test_strncmp(void) {
  char a[N + 1], b[N + 1];

  for (int la = 0; la <= N; la++) {
    make_ascii_string(a, la, la + 4);
    for (int lb = 0; lb <= N; lb++) {
      make_ascii_string(b, lb, lb + 5);
      for (int n = 0; n <= N; n++) {
        int exp = model_strncmp(a, b, n);
        int got = strncmp(a, b, (size_t)n);
        if (exp == 0) {
          assert(got == 0);
        } else if (exp < 0) {
          assert(got < 0);
        } else {
          assert(got > 0);
        }
      }
    }
  }
}

static void run_write_tests(void) {
  test_memset();
  printf("[klib-tests] memset OK\n");

  test_memcpy();
  printf("[klib-tests] memcpy OK\n");

  test_memmove();
  printf("[klib-tests] memmove OK\n");

  test_strcpy();
  printf("[klib-tests] strcpy OK\n");

  test_strncpy();
  printf("[klib-tests] strncpy OK\n");

  test_strcat();
  printf("[klib-tests] strcat OK\n");

  printf("[klib-tests] all write-function tests passed\n");
}

static void run_read_tests(void) {
  test_memcmp();
  printf("[klib-tests] memcmp OK\n");

  test_strlen();
  printf("[klib-tests] strlen OK\n");

  test_strcmp();
  printf("[klib-tests] strcmp OK\n");

  test_strncmp();
  printf("[klib-tests] strncmp OK\n");

  printf("[klib-tests] all read-function tests passed\n");
}

static void run_format_tests(void) {
  test_sprintf_int_d();
  printf("[klib-tests] sprintf %%d/width OK\n");

  test_sprintf_uint_hex();
  printf("[klib-tests] sprintf %%u/%%x OK\n");

  test_sprintf_misc();
  printf("[klib-tests] sprintf string/char/%% OK\n");

  test_snprintf_truncation();
  printf("[klib-tests] snprintf truncation OK\n");

  printf("[klib-tests] all format-function tests passed\n");
}

int main(const char *args) {
  char mode = (args && args[0]) ? args[0] : 'w';

  switch (mode) {
    case 'w':
      run_write_tests();
      break;
    case 'r':
      run_read_tests();
      break;
    case 'h':
    default:
      printf("Usage: make run mainargs={w|r|f}\n");
      printf("  w: write-function tests (memset/memcpy/memmove/strcpy/strncpy/strcat)\n");
      printf("  r: read-function tests (memcmp/strlen/strcmp/strncmp)\n");
      printf("  f: format-function tests (sprintf/snprintf)\n");
      return 1;
    case 'f':
      run_format_tests();
      break;
  }

  return 0;
}
