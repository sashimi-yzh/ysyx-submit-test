#include <am.h>
#include <klib-macros.h>
#include <klib.h>
#include <limits.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)
typedef enum {
  FMT_LEN_DEFAULT,
  FMT_LEN_HH,
  FMT_LEN_H,
  FMT_LEN_L,
  FMT_LEN_LL,
  FMT_LEN_Z,
} fmt_length;

/*
* width: fmt occupide width
* precision: fmt output width (spec by num aft .)
*/
typedef struct {
  unsigned base; // 8、10、16
  fmt_length len;
  size_t width;
  int precision; // -1 mean not spec
  bool left_align;
  bool zero_pad;
  bool alternate;
  bool uppercase;
} fmt_spec;

typedef int (*fmt_write_fn)(void *ctx, const char *data, size_t len);

typedef struct {
  fmt_write_fn write;
  void *ctx;
} fmt_writer;

typedef struct {
  char *cursor;
  size_t remaining;
} fmt_buffer;

static fmt_length parse_length(const char **fmt) {
  if((*fmt)[0] == 'h' && (*fmt)[1] == 'h') {
    *fmt += 2;
    return FMT_LEN_HH;
  }

  if((*fmt)[0] == 'h') {
    *fmt += 1;
    return FMT_LEN_H;
  }

  if((*fmt)[0] == 'l' && (*fmt)[1] == 'l') {
    *fmt += 2;
    return FMT_LEN_LL;
  }

  if((*fmt)[0] == 'l') {
    *fmt += 1;
    return FMT_LEN_L;
  }

  if((*fmt)[0] == 'z') {
    *fmt += 1;
    return FMT_LEN_Z;
  }

  return FMT_LEN_DEFAULT;
}

static bool parse_decimal(const char **fmt, size_t maximum, size_t *value) {
  size_t parsed = 0;

  while(**fmt >= '0' && **fmt <= '9') {
    size_t digit = (size_t)(**fmt - '0');
    if(parsed > (maximum - digit) / 10) return false;
    parsed = parsed * 10 + digit;
    (*fmt)++;
  }

  *value = parsed;
  return true;
}

static bool parse_format_spec(const char **fmt, fmt_spec *spec) {
  *spec = (fmt_spec) {
    .precision = -1,
  };

  bool parsing_flags = true;
  while(parsing_flags) {
    switch(**fmt) {
      case '-':
        spec->left_align = true;
        (*fmt)++;
        break;
      case '0':
        spec->zero_pad = true;
        (*fmt)++;
        break;
      case '#':
        spec->alternate = true;
        (*fmt)++;
        break;
      default:
        parsing_flags = false;
        break;
    }
  }

  if(!parse_decimal(fmt, SIZE_MAX, &spec->width)) return false;

  if(**fmt == '.') {
    size_t precision = 0;
    (*fmt)++;
    if(!parse_decimal(fmt, INT_MAX, &precision)) return false;
    spec->precision = (int)precision;
  }

  spec->len = parse_length(fmt);
  return **fmt != '\0';
}

static intmax_t read_signed_arg(va_list *args, fmt_length length) {
  switch(length) {
    case FMT_LEN_HH:
      return (signed char)va_arg(*args, int);
    case FMT_LEN_H:
      return (short)va_arg(*args, int);
    case FMT_LEN_L:
      return va_arg(*args, long);
    case FMT_LEN_LL:
      return va_arg(*args, long long);
    case FMT_LEN_DEFAULT:
    default:
      return va_arg(*args, int);
  }
}

static uintmax_t read_unsigned_arg(va_list *args, fmt_length length) {
  switch(length) {
    case FMT_LEN_HH:
      return (unsigned char)va_arg(*args, unsigned int);
    case FMT_LEN_H:
      return (unsigned short)va_arg(*args, unsigned int);
    case FMT_LEN_L:
      return va_arg(*args, unsigned long);
    case FMT_LEN_LL:
      return va_arg(*args, unsigned long long);
    case FMT_LEN_Z:
      return va_arg(*args, size_t);
    case FMT_LEN_DEFAULT:
    default:
      return va_arg(*args, unsigned int);
  }
}

// stdio writer
static int console_writer(void *ctx, const char *data, size_t len) {
  (void)ctx;
  if(len > INT_MAX) return -1;

  size_t count = 0;
  while(count < len) {
    putch(data[count]);
    count++;
  }
  return (int)count;
}

static int buffer_writer(void *ctx, const char *data, size_t len) {
  fmt_buffer *buffer = ctx;
  if(len > INT_MAX) return -1;

  size_t writable =
      buffer->remaining > 0 ? buffer->remaining - 1 : 0;
  size_t copy_size = len < writable ? len : writable;

  if(copy_size > 0) {
    memcpy(buffer->cursor, data, copy_size);
    buffer->cursor += copy_size;
    buffer->remaining -= copy_size;
  }

  return (int)len;
}

static void finish_buffer(fmt_buffer *buffer) {
  if(buffer->remaining > 0) {
    *buffer->cursor = '\0';
  }
}

// stdio impl
static int emit_string(fmt_writer *writer, const char *src,
                       const fmt_spec *spec) {
  const char *str = (src == NULL) ? "(null)" : src;
  int rt_size = 0;
  size_t outlen = 0;

  while(str[outlen] != '\0' &&
    ((spec->precision == -1) || (outlen < (size_t)spec->precision))) {
      outlen++;
    }

  if(spec->width == 0) {
    // width is zero mean that width is no spec
    return writer->write(writer->ctx, str, outlen);
  }

  size_t padding_size = spec->width > outlen ? spec->width - outlen : 0;
  if(!spec->left_align) {
    while(padding_size > 0) {
      rt_size += writer->write(writer->ctx, " ", 1);
      padding_size--;
    }
    rt_size += writer->write(writer->ctx, str, outlen);
    return rt_size;
  } else {
    rt_size += writer->write(writer->ctx, str, outlen);
    while(padding_size > 0) {
      rt_size += writer->write(writer->ctx, " ", 1);
      padding_size--;
    }
    return rt_size;
  }
}

static int emit_character(fmt_writer *writer, char ch, const fmt_spec *spec) {
  char buffer[2] = {};
  buffer[0] = ch;
  return writer->write(writer->ctx, buffer, 1);
}

static int emit_integer(fmt_writer *writer, uintmax_t magnitude,
                        bool negative, const fmt_spec *spec) {
  char buffer[sizeof(uintmax_t) * CHAR_BIT];
  char *const buffer_end = buffer + sizeof(buffer);
  char *digits_begin = buffer_end;
  static const char lower_digits[] = "0123456789abcdef";
  static const char upper_digits[] = "0123456789ABCDEF";
  const char *digit_table = spec->uppercase ? upper_digits : lower_digits;
  int rt_size = 0;

  if(spec->base == 10) {
    do {
      *--digits_begin = digit_table[magnitude % 10];
      magnitude /= 10;
    } while(magnitude != 0);
  } else {
    uint32_t mask = 0;
    uint32_t shift = 0;
    switch (spec->base) {
      case 2:
        mask = 0b1;
        shift = 1;
        break;
      case 8:
        mask = 0b111;
        shift = 3;
        break;
      case 16:
        mask = 0b1111;
        shift = 4;
        break;
      default:
        panic("[klib printf error] unsupport fmt base");
    }

    do {
      *--digits_begin = digit_table[magnitude & mask];
      magnitude >>= shift;
    } while(magnitude != 0);
  }

  size_t counter = (size_t)(buffer_end - digits_begin);
  size_t content_size = counter + (negative ? 1 : 0);
  size_t padding_size =
      spec->width > content_size ? spec->width - content_size : 0;

  if(!spec->left_align) {
    while(padding_size > 0) {
      rt_size += writer->write(writer->ctx, " ", 1);
      padding_size--;
    }
    if(negative) rt_size += writer->write(writer->ctx, "-", 1);
    rt_size += writer->write(writer->ctx, digits_begin, counter);
    return rt_size;
  } else {
    if(negative) rt_size += writer->write(writer->ctx, "-", 1);
    rt_size += writer->write(writer->ctx, digits_begin, counter);
    while(padding_size > 0) {
      rt_size += writer->write(writer->ctx, " ", 1);
      padding_size--;
    }
    return rt_size;
  }
}

static int format_signed_integer(fmt_writer *writer, intmax_t value,
                                 const fmt_spec *spec) {
  bool negative = value < 0;
  uintmax_t magnitude = (uintmax_t)value;

  if(negative) {
    magnitude = 0 - magnitude;
  }

  return emit_integer(writer, magnitude, negative, spec);
}

static int format_unsigned_integer(fmt_writer *writer, uintmax_t value,
                                   const fmt_spec *spec) {
  return emit_integer(writer, value, false, spec);
}

static int format_conversion(fmt_writer *writer, va_list *args,
                             char conversion, fmt_spec spec) {
  switch(conversion) {
    case 'd':
    case 'i':
      if(spec.len == FMT_LEN_Z) return -1;
      spec.base = 10;
      return format_signed_integer(
          writer, read_signed_arg(args, spec.len), &spec);

    case 'u':
      spec.base = 10;
      return format_unsigned_integer(
          writer, read_unsigned_arg(args, spec.len), &spec);

    case 'o':
      spec.base = 8;
      return format_unsigned_integer(
          writer, read_unsigned_arg(args, spec.len), &spec);

    case 'x':
    case 'X':
      spec.base = 16;
      spec.uppercase = conversion == 'X';
      return format_unsigned_integer(
          writer, read_unsigned_arg(args, spec.len), &spec);

    case 's': {
      if(spec.len != FMT_LEN_DEFAULT) return -1;
      char *value = va_arg(*args, char *);
      return emit_string(writer, value, &spec);
    }

    case 'c': {
      if(spec.len != FMT_LEN_DEFAULT) return -1;
      int value = va_arg(*args, int);
      return emit_character(writer, (char)value, &spec);
    }

    case 'p': {
      if(spec.len != FMT_LEN_DEFAULT) return -1;
      void *value = va_arg(*args, void *);
      spec.base = 16;
      return format_unsigned_integer(
          writer, (uintmax_t)(uintptr_t)value, &spec);
    }

    case '%':
      if(spec.len != FMT_LEN_DEFAULT) {
        // it should regard invalid fmt as usual str
        // but I dont want to spend time here
        panic("[klib printf error] invalid fmt");
      }
      return writer->write(writer->ctx, "%", 1);

    default:
      return -1;
  }
}

static int format_all(fmt_writer *writer, const char *fmt, va_list *args) {
  int rt_size = 0;

  while(*fmt != '\0') {
    const char *literal_begin = fmt;
    while(*fmt != '\0' && *fmt != '%') fmt++;

    size_t literal_size = (size_t)(fmt - literal_begin);
    if(literal_size > 0) {
      if(literal_size > (size_t)(INT_MAX - rt_size)) goto fail;

      int written = writer->write(writer->ctx, literal_begin, literal_size);
      if(written < 0 || (size_t)written != literal_size) goto fail;
      rt_size += written;
    }

    if(*fmt == '\0') break;
    fmt++;

    fmt_spec spec;
    if(!parse_format_spec(&fmt, &spec)) goto fail;
    if(spec.width > (size_t)(INT_MAX - rt_size)) goto fail;

    char conversion = *fmt++;
    int written = format_conversion(writer, args, conversion, spec);
    if(written < 0 || written > INT_MAX - rt_size) goto fail;
    rt_size += written;
  }

  return rt_size;

fail:
  return -1;
}

int vprintf(const char *fmt, va_list ap) {
  fmt_writer writer = {
    .write = console_writer,
    .ctx = NULL,
  };

  va_list args;
  va_copy(args, ap);
  int result = format_all(&writer, fmt, &args);
  va_end(args);
  return result;
}

int printf(const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  int result = vprintf(fmt, ap);
  va_end(ap);
  return result;
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  fmt_buffer buffer = {
    .cursor = out,
    .remaining = n,
  };
  fmt_writer writer = {
    .write = buffer_writer,
    .ctx = &buffer,
  };

  va_list args;
  va_copy(args, ap);
  int result = format_all(&writer, fmt, &args);
  va_end(args);

  finish_buffer(&buffer);
  return result;
}

int vsprintf(char *out, const char *fmt, va_list ap) {
  return vsnprintf(out, SIZE_MAX, fmt, ap);
}

int sprintf(char *out, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  int result = vsprintf(out, fmt, ap);
  va_end(ap);
  return result;
}

int snprintf(char *out, size_t n, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  int result = vsnprintf(out, n, fmt, ap);
  va_end(ap);
  return result;
}

#endif
