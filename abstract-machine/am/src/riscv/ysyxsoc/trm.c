#include <am.h>
#include <klib-macros.h>
#include "ysyxsoc.h"

extern char _heap_start,_heap_end;
int main(const char *args);

extern char _pmem_start;
#define PMEM_SIZE (128 * 1024 * 1024)
#define PMEM_END  ((uintptr_t)&_pmem_start + PMEM_SIZE)
#define npc_trap(code) asm volatile("mv a0, %0; ebreak" : :"r"(code))

Area heap = RANGE(&_heap_start, &_heap_end);
static const char mainargs[MAINARGS_MAX_LEN] = MAINARGS_PLACEHOLDER; // defined in CFLAGS

void init_uart(uint16_t div){
  // 允许访问 Divisor Latch 寄存器。
  outb(UART_REG_LC, 0b10000011);
  outb(UART_REG_DL2, (uint8_t)(div >> 8));
  outb(UART_REG_DL1, (uint8_t)div);
  // 关闭 Divisor Latch 寄存器设置
  outb(UART_REG_LC, 0b00000011);
}

void putch(char ch) {
  uint8_t lsr;     // 读取LS寄存器
  uint8_t tfe;    // 判断发送FIFO是否有数据
  // 下面是负责串口轮询的
  do{
    lsr  = inb(UART_REG_LS);
    tfe = (lsr >> UART_LS_TFE) & 1;
  }while(tfe == 0); // tfe==1表示FIFO中没有数据
  outb(UART_REG_RB, ch);
}

// 展示名字
void show_name(){
  int i;
  uint32_t mvendorid;
  uint32_t marchid;
  // 读取系统寄存器的内容
  asm volatile("csrr %0, mvendorid" : "=r"(mvendorid));
  asm volatile("csrr %0, marchid" : "=r"(marchid));
  // 输出ysyx标识
  for(i = 3;i >= 0;i--){
      putch((char)((mvendorid >> i*8) & 0xFF));
  }
  // 输出学号
  uint32_t number;
  number = marchid;
  char buf[10];
  int index = 0;
  while(number > 0){
    buf[index++] = (number % 10) + '0';
    number /= 10;
  }
  for(i = index - 1;i >= 0;i--){
    putch(buf[i]);
  }
  putch('\n');
}

void halt(int code) {
  npc_trap(code);
  while (1);
}

void _trm_init() {
  init_uart(1);
  // show_name();
  int ret = main(mainargs);
  halt(ret);
}

// 初始化SPI协议的配置
void init_spi(uint32_t spi_clock, uint8_t spi_ss, uint8_t char_len, uint8_t tx_neg, uint8_t rx_neg, uint8_t lsb){
  uint16_t divider = 500000000 / (spi_clock * 2) - 1;  // 除数设置寄存器
  // uint16_t divider = spi_clock;
  outw(SPI_DEVIDE, divider);
  outb(SPI_SS, spi_ss);
  uint32_t ctrl_reg = (1 << 13 | 0 << 12 | lsb << 11 | tx_neg << 10 | rx_neg << 9 | 0 << 8 | char_len); // ASS: 1  IE: 0
  outl(SPI_CTRL,ctrl_reg);
}

// 给SPI的tx寄存器写入数据
void spi_tx(uint8_t* tx_data, uint8_t len){
  switch(len){
    case 8: 
      outb(SPI_TX_0,*tx_data);
      break;
    case 16:
      outw(SPI_TX_0,*(uint16_t *)tx_data);
      break;
    case 32:
      outl(SPI_TX_0,*(uint32_t *)tx_data);
      break;
    case 64:
      outl(SPI_TX_0, *(uint64_t *)tx_data);
      outl(SPI_TX_1, *(uint64_t *)tx_data >> 32);
      break;
    default: panic("写入spi的数据长度非法了");
  }
}

// 接收SPI的rx寄存器的内容
void spi_rx(uint8_t* rx_data, uint8_t len){
  // 下面的循环是等待数据的传输完成之后才能采样数据
  while((inl(SPI_CTRL) & 0x100) == 0x100);  // 若CTRL寄存器的GO_BUSY位还是为1则表示数据传输还在进行
  switch(len){
    case 8:
      *rx_data = inb(SPI_RX_0);
      break;
    case 16:
      *(uint16_t *)rx_data = inw(SPI_RX_0);
      break;
    case 32:
      *(uint32_t *)rx_data = inl(SPI_RX_0);
      break;
    case 64:
      *(uint64_t *)rx_data = ((uint64_t)inl(SPI_RX_1)) << 32 | inl(SPI_RX_0);
      break;
    default: panic("读取spi的数据长度非法");
  }
}

// 开始发送数据
void spi_tx_start(){
  uint32_t ctrl = inl(SPI_CTRL);
  ctrl &= ~0x100;    // 清除GO_BUSY
  outl(SPI_CTRL, ctrl);
  outl(SPI_CTRL, ctrl | 0x100);  // 将SPI_CTRL的GO_BUSSY位置为高表示要发送数据
}