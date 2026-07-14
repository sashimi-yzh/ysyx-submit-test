#include <am.h>
#include <riscv/riscv.h>
#include <klib-macros.h>
#include <ysyxsoc.h>
#include <klib.h>

extern char _heap_start[];
extern char _heap_end[];
int main(const char *args);

Area heap = RANGE(_heap_start, _heap_end);
static const char mainargs[MAINARGS_MAX_LEN] = TOSTRING(MAINARGS_PLACEHOLDER); // defined in CFLAGS

void halt(int code)
{

  asm volatile("mv a0, %0" : : "r"(code));

  asm volatile("ebreak");

  // should not reach here
  while (1)
    ;
}

extern char _init2_start[], _init2_end[], _init2_lma[];
extern char _text_start[], _text_end[], _text_lma[];
// extern char _rodata_start[], _rodata_end[], _rodata_lma[];
extern char _data_start[], _data_end[], _data_lma[];
extern char _bss_start[], _bss_end[];

#define early_memcpy(dst, src, n) do { \
    uint32_t *d = (uint32_t *)(dst); \
    const uint32_t *s = (const uint32_t *)(src); \
    unsigned int count = (n) / sizeof(uint32_t); \
    while (count--) { \
        *d++ = *s++; \
    } \
} while (0)


#define early_memset(dst, i, n) do { \
    uint32_t *d = (uint32_t *)(dst); \
    unsigned int count = (n) / sizeof(uint32_t); \
    while (count--) { \
        *d++ = i; \
    } \
} while (0)
__attribute__((section(".init"))) void first_bootloader()
{
  early_memcpy(_init2_start, _init2_lma, _init2_end - _init2_start);
}

__attribute__((section(".init2"))) void second_bootloader()
{
  early_memcpy(_text_start, _text_lma, _text_end - _text_start);
  // early_memcpy(_rodata_start, _rodata_lma, _rodata_end - _rodata_start);
  early_memcpy(_data_start, _data_lma, _data_end - _data_start);
  early_memset(_bss_start, 0, _bss_end - _bss_start);
}

void print_sections()
{
  printf("text: [0x%08x, 0x%08x)\n", (unsigned int)_text_start, (unsigned int)_text_end);
  // printf("rodata: [0x%08x, 0x%08x)\n", (unsigned int)_rodata_start, (unsigned int)_rodata_end);
  printf("data: [0x%08x, 0x%08x)\n", (unsigned int)_data_start, (unsigned int)_data_end);
  printf("bss: [0x%08x, 0x%08x)\n", (unsigned int)_bss_start, (unsigned int)_bss_end);
  printf("heap&stack: [0x%08x, 0x%08x)\n", (unsigned int)&_heap_start, (unsigned int)&_heap_end);
}

void init_uart()
{
  outb(UART_FCR, 0b00000111);
  outb(UART_IER, 0);

  outb(UART_LCR, 0b10000011);
  outb(UART_DLM, 0x0); // 除数高字节
  outb(UART_DLL, 0x1); // 除数低字节
  outb(UART_LCR, 0b00000011);

  outb(UART_FCR, 0b11000001);
}
void putch(char ch)
{
  while (!(inb(UART_LSR) & 0b00100000))
    ; // 等待 bit5=1
  outl(UART_BASE, ch);
}

#define SEG_REGISTER (*(volatile uint32_t *)0x10002008)
void print_csr_id()
{
  uint32_t mvendorid, marchid;
  asm volatile("csrr %0, mvendorid" : "=r"(mvendorid) : :);
  asm volatile("csrr %0, marchid" : "=r"(marchid) : :);
  char mvendorid_char[5];
  for (int i = 0; i < 4; i++)
  {
    mvendorid_char[i] = (mvendorid >> (24 - (i * 8))) & 0xff;
  }
  mvendorid_char[4] = '\0';
  printf("mvendorid: %s, marchid: %d\n", mvendorid_char, marchid);

  uint32_t bcd_marchid = 0;
  uint32_t temp = marchid;
  int shift = 0;
  while (temp > 0 && shift < 32)
  {
    uint32_t digit = temp % 10;
    bcd_marchid |= (digit << shift);
    temp /= 10;
    shift += 4;
  }
  SEG_REGISTER = bcd_marchid;

  uint32_t hi, lo;
  __asm__ volatile(
      "csrr %[hi], mcycleh\n\t"
      "csrr %[lo], mcycle\n\t"
      : [hi] "=r"(hi),
        [lo] "=r"(lo)
      :
      : "memory");
  printf("Entering main() at cycle %d_%d\n", hi, lo);
}

#define SW_REGISTER (*(volatile uint16_t *)0x10002004)
void check_password()
{
  printf("Please input the password: \n");
  while (SW_REGISTER != 0x000c)
    ;
  printf("Password correct!\n");
}

__attribute__((section(".init"))) void _trm_init()
{
  first_bootloader();
  second_bootloader();
  init_uart();
  print_sections();

  print_csr_id();
  // check_password();

  int ret = main(mainargs);
  halt(ret);
}