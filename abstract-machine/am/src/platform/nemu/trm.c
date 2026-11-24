#include <am.h>
#include <nemu.h>
#include <klib.h>

extern char _heap_start;

extern char _data_start[];
extern char _data_end[];
extern char _data_lma[];
#define DATA_LEN (uint32_t)(_data_end - _data_start)

// defined by rt-thread's extra.ld; weak so other programs link with len = 0
// (__RTTHREAD__ is not passed to the AM sub-make, so #ifdef can't be used)
extern char _extra_data_start[] __attribute__((weak));
extern char _extra_data_end[] __attribute__((weak));
extern char _extra_data_lma[] __attribute__((weak));
#define EXTRA_DATA_LEN (uint32_t)(_extra_data_end - _extra_data_start)

extern char _text_start[];
extern char _text_lma[];
extern char _etext[];
#define TEXT_LEN (uint32_t)(_etext - _text_start)

extern char _ssboot_start[];
extern char _ssboot_lma[];
extern char _essboot[];
#define SSBOOT_LEN (uint32_t)(_essboot - _ssboot_start)

// extern char _rodata_start[];
// extern char _rodata_lma[];
// extern char _erodata[];
// #define RODATA_LEN (uint32_t)(_erodata - _rodata_start)

extern int  main(const char *args);
extern void _trm_init(void);

extern char _pmem_start;
#define PMEM_SIZE (128 * 1024 * 1024)
#define PMEM_END  ((uintptr_t)&_pmem_start + PMEM_SIZE)

#define HEAP_SIZE (1024 * 1024)
Area heap = RANGE(&_heap_start, &_heap_start + HEAP_SIZE);
static const char mainargs[MAINARGS_MAX_LEN] = MAINARGS_PLACEHOLDER; // defined in CFLAGS

void putch(char ch) { outb(SERIAL_PORT, ch); }

// NEMU serial is output-only: always report "no data" (same as soc timeout)
char getch(void) { return 0xff; }

#define COPY_SECTION_BODY                                                      \
  for (uint32_t i = 0; i < len; ++i)                                           \
    dst[i] = src[i];

__attribute__((section(".fsboot"))) static void
copy_section_fs(uint32_t *dst, uint32_t *src, uint32_t len) {
  COPY_SECTION_BODY
}
__attribute__((section(".fsboot"))) static void fsbootloader() {
  copy_section_fs((uint32_t *)_ssboot_start, (uint32_t *)_ssboot_lma,
                  SSBOOT_LEN / sizeof(uint32_t));
}

__attribute__((section(".fsboot"))) void _fsboot() {
  fsbootloader();
  _trm_init();
}

__attribute__((section(".ssboot"))) void halt(int code) {
  __asm__ volatile("ebreak");
  while (1)
    ;
}

// bootloader: copy .text and .rodata from FLASH to SRAM
__attribute__((section(".ssboot"))) static void
copy_section_ss(uint32_t *dst, uint32_t *src, uint32_t len) {
  COPY_SECTION_BODY
}

__attribute__((section(".ssboot"))) static void ssbootloader() {
  copy_section_ss((uint32_t *)_data_start, (uint32_t *)_data_lma,
                  DATA_LEN / sizeof(uint32_t));
  copy_section_ss((uint32_t *)_text_start, (uint32_t *)_text_lma,
                  TEXT_LEN / sizeof(uint32_t));
  copy_section_ss((uint32_t *)_extra_data_start, (uint32_t *)_extra_data_lma,
                  EXTRA_DATA_LEN / sizeof(uint32_t));
  // copy_section((uint32_t *)_rodata_start, (uint32_t *)_rodata_lma,
  //              RODATA_LEN / sizeof(uint32_t));
}

__attribute__((section(".ssboot"))) void _trm_init() {

  ssbootloader();
  ioe_init();

  uint32_t mvendorid, marchid;
  __asm__ volatile("csrr %0, mvendorid" : "=r"(mvendorid));
  __asm__ volatile("csrr %0, marchid" : "=r"(marchid));
  printf("mvendorid(ascii code) = 0x%x, marchid = %x\n", mvendorid, marchid);

  int ret = main(mainargs);
  halt(ret);
}
