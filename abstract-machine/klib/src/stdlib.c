#include <am.h>
#include <klib-macros.h>
#include <klib.h>
#include <limits.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)
static unsigned long int next = 1;
static unsigned long int addr = 0;

int rand(void) {
  // RAND_MAX assumed to be 32767
  next = next * 1103515245 + 12345;
  return (unsigned int)(next / 65536) % 32768;
}

void srand(unsigned int seed) { next = seed; }

int abs(int x) { return (x < 0 ? -x : x); }

int atoi(const char *nptr) {
  int x = 0;
  while (*nptr == ' ') {
    nptr++;
  }
  while (*nptr >= '0' && *nptr <= '9') {
    x = x * 10 + *nptr - '0';
    nptr++;
  }
  return x;
}

void *malloc(size_t size) {
  // On native, malloc() will be called during initializaion of C runtime.
  // Therefore do not call panic() here, else it will yield a dead recursion:
  //   panic() -> putchar() -> (glibc) -> malloc() -> panic()
#if !(defined(__ISA_NATIVE__) && defined(__NATIVE_USE_KLIB__))
  if (addr == 0)
    addr = (unsigned long int)heap.start;
  printf("111");
  unsigned long int ret = addr;
  addr += (size - (size % sizeof(int)) + sizeof(int));
  return (void *)ret;
#endif
  return NULL;
}

void free(void *ptr) {}

typedef struct {
  uintmax_t magnitude; // means number without sign-sym 
  const char *end;
  bool negative;
  bool overflow;
} strto_parse_result;

static inline int digit_value(unsigned char ch) {
  if(ch >= '0' && ch <= '9') return ch - '0';
  if(ch >= 'a' && ch <= 'z') return ch - 'a' + 10;
  if(ch >= 'A' && ch <= 'Z') return ch - 'A' + 10;
  return -1;
}

static inline int resolve_base_and_prefix(const char **cursor, int base) {
  const char *current = *cursor;
  int prefixed_base = 0;

  if(current[0] == '0') {
    switch(current[1]) {
      case 'x':
      case 'X':
        prefixed_base = 16;
        break;
      case 'b':
      case 'B':
        prefixed_base = 2;
        break;
      case 'o':
      case 'O':
        prefixed_base = 8;
        break;
      default:
        break;
    }
  }

  if(prefixed_base != 0 && (base == 0 || base == prefixed_base)) {
    int first_digit = digit_value((unsigned char)current[2]);
    if(first_digit >= 0 && first_digit < prefixed_base) {
      *cursor = current + 2;
      return prefixed_base;
    }
  }

  if(base == 0) {
    return current[0] == '0' ? 8 : 10;
  }

  return base;
}

static inline strto_parse_result parse_integer(
    const char *nptr,
    int base,
    uintmax_t positive_limit,
    uintmax_t negative_limit) {

  strto_parse_result result = {
    .end = nptr,
  };

  if(base != 0 && (base < 2 || base > 36)) return result;

  const char *cursor = nptr;
  while(isspace((unsigned char)*cursor)) cursor++;

  if(*cursor == '+' || *cursor == '-') {
    result.negative = *cursor == '-';
    cursor++;
  }

  base = resolve_base_and_prefix(&cursor, base);

  uintmax_t limit = result.negative ? negative_limit : positive_limit;
  uintmax_t cutoff = limit / (unsigned)base;
  unsigned cutlim = (unsigned)(limit % (unsigned)base);
  bool converted = false;

  for(;; cursor++) {
    int digit = digit_value((unsigned char)*cursor);
    if(digit < 0 || digit >= base) break;
    converted = true;

    if(!result.overflow) {
      if(result.magnitude > cutoff ||
         (result.magnitude == cutoff && (unsigned)digit > cutlim)) {
        result.magnitude = limit;
        result.overflow = true;
      } else {
        result.magnitude =
            result.magnitude * (unsigned)base + (unsigned)digit;
      }
    }
  }

  if(converted) result.end = cursor;
  return result;
}

long strtol(const char *nptr, char **endptr, int base) {
  uintmax_t negative_limit = (uintmax_t)LONG_MAX + 1;
  strto_parse_result parsed =
      parse_integer(nptr, base, (uintmax_t)LONG_MAX, negative_limit);

  if(endptr != NULL) *endptr = (char *)parsed.end;

  if(parsed.overflow) {
    return parsed.negative ? LONG_MIN : LONG_MAX;
  }

  if(!parsed.negative) return (long)parsed.magnitude;
  if(parsed.magnitude == negative_limit) return LONG_MIN;
  return -(long)parsed.magnitude;
}

unsigned long strtoul(const char *nptr, char **endptr, int base) {
  strto_parse_result parsed =
      parse_integer(nptr, base, (uintmax_t)ULONG_MAX, (uintmax_t)ULONG_MAX);

  if(endptr != NULL) *endptr = (char *)parsed.end;
  if(parsed.overflow) return ULONG_MAX;

  unsigned long magnitude = (unsigned long)parsed.magnitude;
  return parsed.negative ? 0UL - magnitude : magnitude;
}

long long strtoll(const char *nptr, char **endptr, int base) {
  uintmax_t negative_limit = (uintmax_t)LLONG_MAX + 1;
  strto_parse_result parsed =
      parse_integer(nptr, base, (uintmax_t)LLONG_MAX, negative_limit);

  if(endptr != NULL) *endptr = (char *)parsed.end;

  if(parsed.overflow) {
    return parsed.negative ? LLONG_MIN : LLONG_MAX;
  }

  if(!parsed.negative) return (long long)parsed.magnitude;
  if(parsed.magnitude == negative_limit) return LLONG_MIN;
  return -(long long)parsed.magnitude;
}

unsigned long long strtoull(const char *nptr, char **endptr, int base) {
  strto_parse_result parsed = parse_integer(
      nptr, base, (uintmax_t)ULLONG_MAX, (uintmax_t)ULLONG_MAX);

  if(endptr != NULL) *endptr = (char *)parsed.end;
  if(parsed.overflow) return ULLONG_MAX;

  unsigned long long magnitude = (unsigned long long)parsed.magnitude;
  return parsed.negative ? 0ULL - magnitude : magnitude;
}

#endif
