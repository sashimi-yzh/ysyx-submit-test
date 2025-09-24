#include <am.h>
#include <klib-macros.h>
#include <klib.h>
#include <riscv/riscv.h>
#include <riscv/ysyxsoc/include/ysyxsoc.h>

int main(const char *args);

extern char _sram_start;
#define SRAM_SIZE (8 * 1024)
#define SRAM_END  ((uintptr_t)&_sram_start + SRAM_SIZE)

extern char _psram_start;
#define PSRAM_SIZE (4 * 1024 * 1024)
#define PSRAM_END  ((uintptr_t)&_psram_start + PSRAM_SIZE)

extern char _sdram_start;
#define SDRAM_SIZE (64 * 1024 * 1024)
#define SDRAM_END  ((uintptr_t)&_sdram_start + SDRAM_SIZE)

extern char _heap_start;
extern char _heap_end;
Area heap = RANGE(&_heap_start, SDRAM_END);

#ifndef MAINARGS
#define MAINARGS ""
#endif
static const char mainargs[] = MAINARGS;

void putch(char ch) {
  while (1){
    volatile uint8_t lsr = inb(UART_REG_LS);
    // if ((lsr & 0x20) != 0 && (lsr & 0x40) != 0) break;
    if ((lsr & 0x20) != 0) break;
  };
  outb(UART_REG_RB_TH, ch);
}

void halt(int code) {
  asm volatile("mv a0, %0; ebreak" : :"r"(code));
  while (1);
}

void uart_init() {
  outb(UART_REG_LC, 0x80); // Enable DLAB
  outb(UART_REG_RB_TH, 0x01); // 38400 baud
  outb(UART_REG_LC, 0x03); // 8 bits, no parity, one stop bit
  outb(UART_REG_II_FC, 0xC7); // Enable FIFO, clear them, with 14-byte threshold
}

void csr_read() {
  uint32_t mvendorid;
  asm volatile("csrr %0, 0x343" : "=r"(mvendorid));
  printf("ysyx's ASCII = %x\n", mvendorid);
  uint32_t marchid;
  asm volatile("csrr %0, 0x344" : "=r"(marchid));
  printf("ysyx's student ID = %d\n", marchid);
}

extern void __am_asm_trap(void);

void _trm_init() {

  /** Necessary initialiazation */
  uart_init();
  // printf("Bootloader completed.\n");
  csr_read();
  printf("\n");

  /** Jump to main function */
  int ret = main(mainargs);
  halt(ret);
}

extern char _ssbl_start [];
extern char _ssbl_size [];
extern char _ssbl_load_start [];
extern char _text_start [];
extern char _text_end [];
extern char _text_size [];
extern char _text_load_start [];
extern char _rodata_start [];
extern char _rodata_end [];
extern char _rodata_size [];
extern char _rodata_load_start [];
extern char _data_start [];
extern char _data_end [];
extern char _data_size [];
extern char _data_load_start [];
extern char _bss_start [];
extern char _bss_end [];
extern char _bss_size [];

void __attribute__((section(".ssbl"))) _ssbl();

/** First stage bootloader. */
void __attribute__((section(".fsbl"))) _fsbl() {
  for (int i = 0; i < (size_t) _ssbl_size; i++) {
    _ssbl_start[i] = _ssbl_load_start[i];
  }

  _ssbl();
}

/** Second stage bootloader. */
void __attribute__((section(".ssbl"))) _ssbl() {
  /** copy .text */
  if (_text_start != _text_end) {
    for (int i = 0; i < (size_t) _text_size; i++) {
      _text_start[i] = _text_load_start[i];
    }
  }
  /** copy .rodata */
  if (_rodata_start != _rodata_end) {
    for (int i = 0; i < (size_t) _rodata_size; i++) {
      _rodata_start[i] = _rodata_load_start[i];
    }
  }
  /** copy .data */
  if (_data_start != _data_end) {
    for (int i = 0; i < (size_t) _data_size; i++) {
      _data_start[i] = _data_load_start[i];
    }
  }
  /** reset .bss to 0 */
  if (_bss_start != _bss_end) {
    for (int i = 0; i < (size_t) _bss_size; i++) {
      _bss_start[i] = 0;
    }
  }

  asm volatile("fence.i");
  asm volatile("csrw mtvec, %0" : : "r"(__am_asm_trap));

  _trm_init();
}