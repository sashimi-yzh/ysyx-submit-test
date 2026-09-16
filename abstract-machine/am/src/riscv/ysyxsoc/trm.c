#include <am.h>
#include <klib-macros.h>
#include <klib.h>
#include <riscv/riscv.h>
#define UART_BASE 0x10000000
#define THR_ADDR (UART_BASE + 0x0)
#define RB_ADDR  (UART_BASE + 0x0)
#define IER_ADDR (UART_BASE + 0x1)
#define IIR_ADDR (UART_BASE + 0x2)
#define FCR_ADDR (UART_BASE + 0x2)
#define LCR_ADDR (UART_BASE + 0x3)
#define MCR_ADDR (UART_BASE + 0x4)
#define LSR_ADDR (UART_BASE + 0x5)
#define MSR_ADDR (UART_BASE + 0x6)
#define LSB_ADDR (UART_BASE + 0x0)
#define MSB_ADDR (UART_BASE + 0x1)

extern char _heap_start;
extern char _heap_end;
int main(const char *args);


Area heap = RANGE(&_heap_start, &_heap_end);
static const char mainargs[MAINARGS_MAX_LEN] = TOSTRING(MAINARGS_PLACEHOLDER); // defined in CFLAGS

void putch(char ch) {
  while ((inb(LSR_ADDR) & 0x20) == 0) {}
  outb(THR_ADDR, ch);
}

uint8_t getch() {
  while ((inb(LSR_ADDR) & 0x01) == 0) {}
  return inb(RB_ADDR);
}

void halt(int code) {
  register long a0 asm("a0") = code;
  asm volatile("ebreak" : : "r"(a0));
  while (1);
}

void _uart_init() {
  // 配置除数寄存器
  outb(LCR_ADDR, 0x80); // LCR
  outb(MSB_ADDR, 0x00); // MSB
  outb(LSB_ADDR, 0x01); // LSB

  outb(LCR_ADDR, 0x03); // LCR
  outb(FCR_ADDR, 0x07);
  outb(MCR_ADDR, 0x03); 
  outb(IER_ADDR, 0x00);
}

#define SPI_BASE            0x10001000
#define SPI_RX0       (SPI_BASE + 0x00) 
#define SPI_RX1       (SPI_BASE + 0x04)
#define SPI_RX2       (SPI_BASE + 0x08)
#define SPI_RX3       (SPI_BASE + 0x0c)
#define SPI_TX0       (SPI_BASE + 0x00) //32 bit
#define SPI_TX1       (SPI_BASE + 0x04)
#define SPI_TX2       (SPI_BASE + 0x08)
#define SPI_TX3       (SPI_BASE + 0x0c)
#define SPI_CTRL      (SPI_BASE + 0x10)
#define SPI_DIVIDER   (SPI_BASE + 0x14)
#define SPI_SS        (SPI_BASE + 0x18)

// void _spi_init() {
//   outl(SPI_SS     , 0x01); //only 7
//   outl(SPI_DIVIDER, 0x01); 

//   uint32_t ctrl_value = 0x00000000;
//   ctrl_value |= 0x40; // char 64 lenth
//   ctrl_value |= 1 << 10; // Tx negedge change

//   outl(SPI_CTRL   , ctrl_value); 

//   /*
//   outl(SPI_SS     , 0x80); //only 7
//   outl(SPI_DIVIDER, 0x01); 

//   uint32_t ctrl_value = 0x00000000;
//   ctrl_value |= 0x10; // char 8 lenth
//   ctrl_value |= 1 << 9; // negedge change
//   ctrl_value |= 1 << 11; // low frist

//   outl(SPI_CTRL   , ctrl_value); */
// }
#define SPI_CTRL_GO_BSY   (1 << 8)
#define ADDR_MASK         0x00ffffff


// uint32_t flash_read(uint32_t addr) {
//   return *(uint32_t*)(addr);
//   uint32_t read_ctrl = 0;
//   read_ctrl |= 0x3 << 24; // read cmd
//   read_ctrl |= (addr) & ADDR_MASK; // 32 bit mode
//   outl(SPI_TX1, read_ctrl);

//   outl(SPI_SS     , 0x01); //flash
//   outl(SPI_DIVIDER, 0x01); 
//   uint32_t ctrl_value = 0x00000000;
//   ctrl_value |= 0x40; // char 64 lenth
//   ctrl_value |= 1 << 10; // Tx negedge change
//   // ctrl_value |= 1 << 9; // Rx negedge change
//   // outl(SPI_CTRL   , ctrl_value); 
//   ctrl_value |= SPI_CTRL_GO_BSY; 
//   outl(SPI_CTRL    , ctrl_value); // start

//   // read data
//   while ((inl(SPI_CTRL) & SPI_CTRL_GO_BSY) != 0) {}
//     uint32_t data = inl(SPI_RX0);
//     uint32_t data1 = 0;
//     data1 |= (data & 0xff) << 24;
//     data1 |= (data & 0xff00) << 8;
//     data1 |= (data & 0xff0000) >> 8;
//     data1 |= (data & 0xff000000) >> 24;

//   outl(SPI_SS     , 0x00); 
//   return data1;
// }

uint32_t read_mvendorid(void);
uint32_t read_marchid(void);

void _print_info() {
  uint32_t vendorid = read_mvendorid();
  uint32_t archid = read_marchid();
  printf("vendorid: %d\n", vendorid);
  printf("archid: %d\n", archid);
}

// extern void _boot_loader(void);

void _trm_init() {
  _uart_init();
  // _boot_loader();
  _print_info();
  int ret = main(mainargs);
  halt(ret);
}
