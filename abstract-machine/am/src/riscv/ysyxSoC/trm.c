#include <am.h>

#include <ysyxSoC.h>

# define ysyxSoC_trap(code) asm volatile("mv a0, %0; ebreak" : :"r"(code))

extern char _data_load_start[];  
extern char _data_start[];
extern char _data_end[];
extern char _rodata_load_start[];  
extern char _rodata_start[];
extern char _rodata_end[];
extern char _bss_start[];
extern char _bss_end[];
extern char _data_extra_start[];
extern char _data_extra_end[];
extern char _data_extra_load[];
extern char _bss_extra_start[];
extern char _bss_extra_end[];
// extern char _bss_extra_load[];


extern char _heap_start;
extern char _heap_end;
int main(const char *args);

// extern char _mrom_start;

Area heap = RANGE(&_heap_start, &_heap_end);
static const char mainargs[MAINARGS_MAX_LEN] = MAINARGS_PLACEHOLDER; // defined in CFLAGS

static void uart_init() {

  outb(UART_BASE + UART_LCR, 0x83); // 跳转
  outb(UART_BASE + UART_IE, 0x00); // 高八位为00
  outb(UART_BASE + UART_TX, 0x01); // 低八位为0D
  outb(UART_BASE + UART_LCR, 0x03); // 8n1

}

void putch(char ch) {

  uint8_t a = 0;
  uint8_t b = 0;

  while(b == 0){
    a = inb(UART_BASE + UART_LSR);
    b = a & 0x20;
    for(int i = 0; i < 10; i++);
  }

  outb(UART_BASE + UART_TX, ch);
}

void halt(int code) {
  
  ysyxSoC_trap(code);

  while (1);

}

static void _zero_bss_section(void) {

  size_t bss_size = _bss_end - _bss_start;

  uint32_t *ch = (uint32_t *) _bss_start;

  int size = bss_size >> 2;

  if (size > 0) {
    while(size > 0)
      {
	      *ch = 0;
	      ch ++;
        size --;
      }
  }
}

static void _zero_bss_extra_section(void) {

  size_t bss_size = _bss_extra_end - _bss_extra_start;

  uint32_t *ch = (uint32_t *) _bss_extra_start;

  int size = bss_size >> 2;

  if (size > 0) {
    while(size > 0)
      {
	      *ch = 0;
	      ch ++;
        size --;
      }
  }
}

static void _copy_data_extra_section(void) {

  if(_data_extra_start == 0) {
    return;
  }
  else{
    size_t data_extra_size = _data_extra_end - _data_extra_start;

    uint32_t *d = (uint32_t *) _data_extra_start;
    uint32_t *s = (uint32_t *) _data_extra_load;

    int size = data_extra_size >> 2;
  
  if (size > 0) {
    while(size > 0)
    {
	    *d = *s;
	    d ++;
	    s ++;
      size --;
    }
  }
    return;
  }
}

static void _copy_rodata_section(void) {

  size_t rodata_size = _rodata_end - _rodata_start;

  uint32_t *d = (uint32_t *) _rodata_start;
  uint32_t *s = (uint32_t *) _rodata_load_start;

  int size = rodata_size >> 2;
  
  if (size > 0) {
    while(size > 0)
    {
	    *d = *s;
	    d ++;
	    s ++;
      size --;
    }
  }
  return;
}

static void _copy_data_section(void) {

  size_t data_size = _data_end - _data_start;

  uint32_t *d = (uint32_t *) _data_start;
  uint32_t *s = (uint32_t *) _data_load_start;

  int size = data_size >> 2;
  
  if (size > 0) {
    while(size > 0)
    {
	    *d = *s;
	    d ++;
	    s ++;
      size --;
    }
  }
  return;
}

static inline uint32_t read_csr(uint32_t addr) {
    uint32_t val;
    __asm__ volatile("csrr %0, %1" : "=r"(val) : "i"(addr));
    return val;
}

static void putch_hex32(uint32_t val, bool asiic) {
    const char hex[] = "0123456789ABCDEF";
    // putch('0'); putch('x');
    if(asiic == true){
      for (int i = 28; i >= 0; i -= 4) {
        putch(hex[(val >> i) & 0xF]);
      }
    }
    else {
      for (int i = 24; i >= 0; i -= 8) {
        putch((char)((val >> i) & 0xff));
      }
    }
    
    putch('\r'); putch('\n');
}

void _trm_init() {

  _zero_bss_section();
  _zero_bss_extra_section();
  _copy_rodata_section();
  _copy_data_extra_section();
  _copy_data_section();

  uart_init();
  
  uint32_t  mvendorid = 0;
  uint32_t  marchid = 0;

  mvendorid = read_csr(0xF11);
  marchid = read_csr(0xF12);

  putch_hex32(mvendorid, false);
  putch_hex32(marchid, true);

  int ret = main(mainargs);

  halt(ret);
}
