#include <am.h>
#include <klib-macros.h>
#include <klib.h>
#include <stdint.h>

#include <my_putnum.h>
#include <my_utils.h>

#include "soc_devreg.h"

int main(const char *args);

extern char _heap_start;
extern char _heap_end;

Area heap = RANGE(&_heap_start, &_heap_end);
static const char mainargs[MAINARGS_MAX_LEN] =
    TOSTRING(MAINARGS_PLACEHOLDER); // defined in CFLAGS

#define FSBL_TEXT __attribute__((section(".fsbl_text")))
#define SSBL_TEXT __attribute__((section(".ssbl_text")))

// #define NO_BOOT_LOG 1

FSBL_TEXT void init_serial() {

  // set UART to 8 bits, no parity, one stop bit
  // 0x3 = 0b11 : Select each character 8 bits
  // 0x80 = 0b10000000 : Divisor Latch Access bit
  *UART_LCR = 0x83u;
  if (*UART_LCR != 0x83u) {
    halt(-114514);
  }

  // NVBOARD divider is 16 times here DL
  // set here 1 and 16 in NVBOARD to make simulation faster

  // see DOCUMENATION page 18:
  // 	Remember that (Input Clock Speed)/(Divisor Latch value) = 16 x the
  // communication baud rate.

  // MSB first LSB next!!!
  *UART_DL_MSB = 0;
  *UART_DL_LSB = 1;

  // clear DLAB bit
  *UART_LCR = 0x3;
  // enable FIFO with 14-byte threshold
  *UART_FIFO_CTRL = (0x3 << 6);
  // disable all interrupts
  *UART_IER = 0x0;
}

#define WAIT_UART_TX_EMPTY()                                                   \
  do {                                                                         \
    while (!IS_UART_TRANSMIT_EMPTY()) {                                        \
    }                                                                          \
  } while (0)

#ifndef NO_BOOT_LOG
FSBL_TEXT void fsbl_putch(char ch) {
  WAIT_UART_TX_EMPTY();
  *UART_TX = ch;
}
SSBL_TEXT void ssbl_putch(char ch) {
  WAIT_UART_TX_EMPTY();
  *UART_TX = ch;
}
#else
#define fsbl_putch(ch)
#define ssbl_putch(ch)
#endif

char try_getch() {
  if (IS_UART_RECEIVE_READY()) {
    return *UART_RX;
  } else {
    return 0xff;
  }
}
char getch() {
  while (!IS_UART_RECEIVE_READY()) {
  }
  return *UART_RX;
}

void halt(int code) {
  asm volatile("mv a0, %0; ebreak" : : "r"(code));
  while (1) {
  } // make sure no return
}

void print_csr() {
  uint32_t mvendor_id, marchid;
  mvendor_id = get_mvendorid();
  marchid = get_marchid();
  char *vendor = (char *)&mvendor_id;
  putstr("mvendor: 0x");
  putnum_base16(mvendor_id);
  putch(' ');
  putch('(');
  putch(vendor[3]);
  putch(vendor[2]);
  putch(vendor[1]);
  putch(vendor[0]);
  putch(')');
  putch('\n');
  putstr("marchid: 0x");
  // base 10 too slow
  putnum_base16(marchid);
  putch('\n');
}

extern char _text_start[];
extern char _rodata_start[];
extern char _data_start[];

extern char _bss_start[];
extern char __bss_size__[];

extern char _data_extra_start[];
extern char _data_extra_end[];
// Fuck clang opt extern symbol non-null/0
// Fuck clang opt &xxx non-zero
#define DATA_EXTRA_SIZE ((size_t)(_data_extra_end - _data_extra_start))
extern char _bss_extra_start[];
extern char _bss_extra_end[];
#define BSS_EXTRA_SIZE ((size_t)(_bss_extra_end - _bss_extra_start))

extern char _ssbl_start[], _ssbl_end[];
extern char __ssbl_load_start__[];
extern char __ssbl_size__[];

extern char __text_load_start__[];
extern char __text_size__[];

extern char __rodata_load_start__[];
extern char __rodata_size__[];

extern char __data_load_start__[];
extern char __data_size__[];

extern char __data_extra_load_start__[];

extern char __bss_extra_load_start__[];

extern char __sram_start__[];
extern char __sram_end__[];

extern char __psram_start__[];
extern char __psram_end__[];

extern char _stack_top[];

typedef int (*entry_func_t)(const char *args);

#define IS_4BYTE_ALIGNED(x) ((((uintptr_t)(x)) & 0x3) == 0)

FSBL_TEXT static inline const char *_rodata_loadpos(const char *ptr) {
  return ptr - (uintptr_t)_rodata_start + (uintptr_t)__rodata_load_start__;
}
#define ssbl_putstr(s) putstr(_rodata_loadpos(s))
#define boot_log(s) ssbl_putstr("[BOOT] " s)

#define _TOSTR(x) #x
#define TOSTR(x) _TOSTR(x)

#define BOOT_ASSERT(cond)                                                      \
  do {                                                                         \
    if (!(cond)) {                                                             \
      boot_log("ASSERTION FAILED @L:" TOSTR(__LINE__) ": " TOSTR(cond) "\n");  \
      halt(-1);                                                                \
    }                                                                          \
  } while (0)

SSBL_TEXT void _ssbl_clear_word_aligned(void *dst, size_t n) {
  BOOT_ASSERT(IS_4BYTE_ALIGNED(dst));
  BOOT_ASSERT(IS_4BYTE_ALIGNED(n));
  size_t wn = n / 4;
  uint32_t *d = (uint32_t *)dst;
  for (size_t i = 0; i < wn; i++) {
    d[i] = 0;
  }
}

SSBL_TEXT void _ssbl_clear(void *dst, size_t n) {
  if (n == 0)
    return;
  uintptr_t dptr = (uintptr_t)dst;

  BOOT_ASSERT(IS_4BYTE_ALIGNED(dptr));
  size_t aligned_n = n & (~0x3);
  _ssbl_clear_word_aligned((void *)dptr, aligned_n);
  size_t remaining = n - aligned_n;
  if (remaining) {
    uint8_t *byte_dst = (uint8_t *)(dptr + aligned_n);
    for (size_t i = 0; i < remaining; i++) {
      byte_dst[i] = 0;
    }
  }
}

SSBL_TEXT void _ssbl_memcpy(void *dst, const void *src, size_t n) {
  BOOT_ASSERT(n != 0);
  BOOT_ASSERT(IS_4BYTE_ALIGNED(dst));
  BOOT_ASSERT(IS_4BYTE_ALIGNED(src));
  size_t nWords = n / 4;
  size_t i;
  for (i = 0; i < nWords; i += 4) {
    uint32_t *d = &((uint32_t *)dst)[i];
    const uint32_t *s = &((const uint32_t *)src)[i];
    d[0] = s[0];
    d[1] = s[1];
    d[2] = s[2];
    d[3] = s[3];
  }
	// remain words
  for (; i < nWords; i++) {
    ((uint32_t *)dst)[i] = ((const uint32_t *)src)[i];
  }
	// remain bytes
  for (i = nWords * 4; i < n; i++) {
    ((uint8_t *)dst)[i] = ((const uint8_t *)src)[i];
  }
}

FSBL_TEXT void boot_memcpy(void *dst, const void *src, size_t n) {
  BOOT_ASSERT(n != 0);
  BOOT_ASSERT(IS_4BYTE_ALIGNED(dst));
  BOOT_ASSERT(IS_4BYTE_ALIGNED(src));
  size_t nWords = n / 4;
  size_t i;
  for (i = 0; i < nWords; i += 4) {
    uint32_t *d = &((uint32_t *)dst)[i];
    const uint32_t *s = &((const uint32_t *)src)[i];
    d[0] = s[0];
    d[1] = s[1];
    d[2] = s[2];
    d[3] = s[3];
  }
	// remain words
  for (; i < nWords; i++) {
    ((uint32_t *)dst)[i] = ((const uint32_t *)src)[i];
  }
	// remain bytes
  for (i = nWords * 4; i < n; i++) {
    ((uint8_t *)dst)[i] = ((const uint8_t *)src)[i];
  }
}

SSBL_TEXT void _second_boot();
FSBL_TEXT void _trm_init() {
  init_serial();
#define putch fsbl_putch
  boot_log("serial initialized.\n");

  boot_memcpy(_ssbl_start, __ssbl_load_start__, (size_t)__ssbl_size__);
  boot_log("SSBL copied.\n");

  _second_boot();
}

SSBL_TEXT void _ssbl_puthex(uint32_t x) {
  char buf[8];
  int idx = 0;
  if (x == 0)
    buf[idx++] = '0';
  while (x) {
    uint8_t t = x & 0xf;
    if (t < 10)
      buf[idx++] = (t + '0');
    else
      buf[idx++] = (t - 10 + 'A');
    x >>= 4;
  }
  idx--;
  for (; idx >= 0; idx--)
    ssbl_putch(buf[idx]);
}

SSBL_TEXT void _second_boot() {
  ssbl_putstr("rodata load start = ");
  _ssbl_puthex((uintptr_t)__rodata_load_start__);
  ssbl_putstr("\nrodata start = ");
  _ssbl_puthex((uintptr_t)_rodata_start);
  ssbl_putstr("\nrodata size = ");
  _ssbl_puthex((uintptr_t)__rodata_size__);
  putch('\n');

  _ssbl_memcpy(_rodata_start, __rodata_load_start__, (size_t)__rodata_size__);
  // after copy .rodata, we can directly use strings ptr in .rodata
#undef putch
#define putch ssbl_putch
  boot_log(".rodata copied.\n");

// after rodata copy, we can use putstr directly
#undef boot_log
#define boot_log(s) putstr("[BOOT] " s)

#define LOG_STEP(msg, step, ...)                                               \
  do {                                                                         \
    boot_log(msg "...");                                                       \
    step __VA_ARGS__;                                                          \
    putstr(" done.\n");                                                        \
  } while (0)

  LOG_STEP("copy .text", _ssbl_memcpy(_text_start, __text_load_start__,
                                      (size_t)__text_size__));
  LOG_STEP("copy .data", _ssbl_memcpy(_data_start, __data_load_start__,
                                      (size_t)__data_size__));

#ifndef SKIP_BSS_CLEAR
  _ssbl_clear(_bss_start, (size_t)__bss_size__);
  boot_log(".bss cleared.\n");
  if (BSS_EXTRA_SIZE != 0) {
    LOG_STEP("clear .bss.extra", _ssbl_clear(_bss_extra_start, BSS_EXTRA_SIZE));
  }
#else
  boot_log("skip clear .bss\n");
  boot_log("skip clear .bss.extra\n");
#endif

  if (DATA_EXTRA_SIZE != 0) {
    putstr(".data.extra size = ");
    putnum_base16((uint32_t)DATA_EXTRA_SIZE);
    putch('\n');
    LOG_STEP("copy .data.extra",
             _ssbl_memcpy(_data_extra_start, __data_extra_load_start__,
                          DATA_EXTRA_SIZE));
  }

  // NOTE: putnum func is in the sdram area
  // before use putnum must flush icache!!!
  LOG_STEP("flush icache", __asm_call_fence_i__());

  boot_log("checking memory regions...\n");
  // putstr("heap.start = ");
  // putnum_base16((uint32_t)heap.start);
  // putstr(" heap.end = ");
  // putnum_base16((uint32_t)heap.end);
  BOOT_ASSERT(heap.start < heap.end);
  // putstr("\nheap size = ");
  // putnum_base16((uint32_t)(heap.end - heap.start));
  // putch('\n');

  boot_log("enter main function.\n");
  int ret = main(mainargs);
  halt(ret);
}

#undef putch
void putch(char ch) {
  WAIT_UART_TX_EMPTY();
  *UART_TX = ch;
}
