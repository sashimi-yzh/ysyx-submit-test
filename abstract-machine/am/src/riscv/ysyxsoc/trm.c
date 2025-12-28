#include <am.h>
#include <klib-macros.h>
#include <riscv/riscv.h>
#include <klib.h>
#define DEVICE_BASE 0xa0000000
#define SERIAL_PORT (DEVICE_BASE + 0x000003f8)

#define UART_BASE 0x10000000L
#define UART_TX   0
#define UART_dL1   0
#define UART_dL2   1
#define UART_FC   2
#define UART_LC   3
#define UART_LS   5
extern char _heap_start;
extern char _psram_end;
int main(const char *args);

extern char _pmem_start;
#define PMEM_SIZE (128 * 1024 * 1024)
#define PMEM_END  ((uintptr_t)&_pmem_start + PMEM_SIZE)

Area heap = RANGE(&_heap_start, &_psram_end);
static const char mainargs[MAINARGS_MAX_LEN] = MAINARGS_PLACEHOLDER; // defined in CFLAGS

void init_uart(){
  *(volatile uint8_t *)(UART_BASE + UART_LC) = *(volatile uint8_t  *)(UART_BASE + UART_LC) | 0b10000000;    // 1停止位，无校验位，禁止中断，开始写divisor
  //uint16_t divisor = 50000000/(16*rate);
  *(volatile uint8_t  *)(UART_BASE + UART_dL2) = (char)0x00;    // 
  *(volatile uint8_t  *)(UART_BASE + UART_dL1) = (char)0x01; ;    // 
  *(volatile uint8_t *)(UART_BASE + UART_LC) = *(volatile uint8_t  *)(UART_BASE + UART_LC) & (~0b10000000); 
}

void putch(char ch) {
    while(((inb(UART_BASE + UART_LS) & (0x2 << 5)) == 0x0) || ((inb(UART_BASE + UART_LS) & (0x1 << 5)) == 0x0));
   // while(((*(volatile char *)(UART_BASE + UART_LS))&0x20) == 0);
  *(volatile uint8_t *)(UART_BASE + UART_TX) = ch;/*
  uint8_t TX_ISEMPTY = *(volatile char *)(UART_BASE + UART_LS);
    while ((TX_ISEMPTY & 0x40) != 0x40) { //等待uart数据发送完成
        TX_ISEMPTY = *(volatile char *)(UART_BASE + UART_LS);
    }
    while(((*(volatile char *)(UART_BASE + UART_LS))&0x20) != 0x20); //等待传输FIFO为空
    *(volatile char *)(UART_BASE + UART_FC) = 0b11000100; //清空缓存区*/
}

void puts(char *s) {
    while (*s) {
        putch(*s++);
    }
}
/*
// 十进制数字输出函数
void print_dec(uint32_t num) {
    if (num == 0) {
        putch('0');
        return;
    }
    
    // 处理小数字的快速路径（0-99）
    if (num < 100) {
        if (num < 10) {
            putch('0' + num);
        } else {
            putch('0' + num / 10);
            putch('0' + num % 10);
        }
        return;
    }
    
    // 计算数字位数（避免除法）
    uint32_t temp = num;
    int digits = 0;
    uint32_t divisor = 1;
    
    while (temp >= 10) {
        temp /= 10;
        divisor *= 10;
        digits++;
    }
    
    // 从最高位开始输出
    while (divisor > 0) {
        uint32_t digit = num / divisor;
        putch('0' + digit);
        num %= divisor;
        divisor /= 10;
    }
}

static inline uint32_t csr_read(uint32_t csr) {
    uint32_t val;
    asm volatile ("csrr %0, %1" : "=r"(val) : "i"(csr));
    return val;
}
*/
/*
static void printf_ysyx() {
    uint32_t mvendorid = csr_read(0xF11);
    uint32_t marchid = csr_read(0xF12);
    putch((mvendorid >> 24) & 0xFF);
    putch((mvendorid >> 16) & 0xFF);
    putch((mvendorid >> 8)  & 0xFF);
    putch(mvendorid & 0xFF);
    print_dec(marchid);

}*/
void halt(int code) {
  asm volatile("mv a0, %0; ebreak" : :"r"(code));
  while (1);
}
volatile void _memcpy(void *dest, const void *src, size_t n)__attribute__((section(".entry")));
volatile void _memcpy(void *dest, const void *src, size_t n) {
    uint8_t *d = (uint8_t *)dest;
    const uint8_t *s = (const uint8_t *)src;
    while (n--) *d++ = *s++;
}

volatile void _memcpy1(void *dest, const void *src, size_t n)__attribute__((section(".ssbl")));
volatile void _memcpy1(void *dest, const void *src, size_t n) {
    uint8_t *d = (uint8_t *)dest;
    const uint8_t *s = (const uint8_t *)src;
    while (n--) *d++ = *s++;
}


extern char _text_SA [];
extern char _text_MA [];
extern char _text_end [];
extern char _rodata_SA [];
extern char _rodata_MA [];
extern char _rodata_end [];
extern char _data_SA [];
extern char _data_MA [];
extern char _data_end [];
extern char _ssbl_SA [];
extern char _ssbl_MA [];
extern char _ssbl_end [];

extern char _data_extra_start_VMA [] __attribute__((weak));
extern char _data_extra_end_VMA [] __attribute__((weak));
extern char _data_extra_start_LMA [] __attribute__((weak));
extern char _data_extra_end_LMA [] __attribute__((weak));
extern char _bss_extra_start [] __attribute__((weak));
extern char _bss_extra_end [] __attribute__((weak));
extern char __am_apps_bss_start [] __attribute__((weak));
extern char __am_apps_bss_end [] __attribute__((weak));



void _bootloader (void)__attribute__((section(".entry")));
void _bootloader (void) {
    // 1. 复制代码段到SRAM
    _memcpy(_ssbl_SA, _ssbl_MA, (_ssbl_end - _ssbl_SA));
    
    
    // 6. 跳转到SRAM中的入口点
    asm volatile (
        "lui t0, %hi(_bootloader_2)\n"  // main的高20位
        "addi t0, t0, %lo(_bootloader_2)\n" // 得到main的低12位跳转到main
        "jalr ra, 0(t0)\n"
    );
}

void _bootloader_2 (void) __attribute__((section(".ssbl")));
void _bootloader_2 (void) {
    
    _memcpy1(_text_SA, _text_MA, (_text_end - _text_SA));
    
    // 2. 复制只读数据段到SRAM
    //_memcpy1(_rodata_SA, _rodata_MA, (_rodata_end - _rodata_SA));
    
    // 3. 复制初始化数据段到SRAM
    if(_data_extra_start_VMA != 0){
        _memcpy1(_data_extra_start_VMA, _data_extra_start_LMA, (_data_extra_end_VMA - _data_extra_start_VMA));
    }
    _memcpy1(_data_SA, _data_MA, (_data_end - _data_SA));
    // 5. 设置堆栈指针（指向PSRAM中的栈顶）
    //asm volatile("mv sp, %0" : : "r" (_stack_top));
    
    // 6. 跳转到SRAM中的入口点
    asm volatile (
        "lui t0, %hi(_trm_init)\n"  // main的高20位
        "addi t0, t0, %lo(_trm_init)\n" // 得到main的低12位跳转到main
        "jalr ra, 0(t0)\n"
    );
}
void _trm_init() {
  //printf_ysyx();
  init_uart();
  //_memcpy(&_sdata, &_sidata, &_edata - &_sdata);
  int ret = main(mainargs);
  halt(ret);
}
