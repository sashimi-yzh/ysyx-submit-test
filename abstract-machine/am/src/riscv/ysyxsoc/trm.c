#include <am.h>
#include <klib-macros.h>
#include "riscv/riscv.h"
#include "klib.h"
extern char _heap_start;
extern char _heap_end;

extern char _data_lma_start;
extern char _data_vma_start;
extern char _data_vma_end;

extern char _rodata_lma_start;
extern char _rodata_vma_start;
extern char _rodata_vma_end;

extern char _ssbl_lma_start;
extern char _ssbl_vma_start;
extern char _ssbl_vma_end;

extern char _text_lma_start;
extern char _text_vma_start;
extern char _text_vma_end;

extern char _bss_start;
extern char _bss_end;
int main(const char *args);

#define nemu_trap(code) asm volatile("mv a0, %0; ebreak" : :"r"(code))
Area heap = RANGE(&_heap_start, &_heap_end);
static const char mainargs[MAINARGS_MAX_LEN] = TOSTRING(MAINARGS_PLACEHOLDER); // defined in CFLAGS
#define UART_BASE 0x10000000
#define UART_THR (UART_BASE+0x0)
#define UART_RBR (UART_BASE+0x0)
#define UART_FCR (UART_BASE+0x2)
#define UART_LCR (UART_BASE+0x3)
#define UART_LSR (UART_BASE+0x5)
#define UART_DLL (UART_BASE+0x0)
#define UART_DLM (UART_BASE+0x1)

void uart_init(){
    outb(UART_LCR,0x80);
    outb(UART_DLM,0x00);
    outb(UART_DLL,0x01);//波特率
    outb(UART_LCR,0x03);//[1:0]:字符长度是8位, [3]:不带校验位, [2]:1位停止位.
    outb(UART_FCR,0x07);//[0]openFIFO,[1]clearRFIFO,[2]clearTFIFO
}
void putch(char ch) {
    while ((inb(UART_LSR)&0x20)==0) ;
    outb(UART_THR, ch);
}
void __am_uart_rx(AM_UART_RX_T* rx){
    if((inb(UART_LSR)&0x1))
        rx->data=inb(UART_THR);
    else
        rx->data=0xff;
} 
void halt(int code) {
    nemu_trap(code);
    while (1);
}

//static void test_mcycle(){
//    uint32_t low,high;
//    asm volatile("csrr %0, mcycle" :"=r"(low));
//    asm volatile("csrr %0, mcycleh" :"=r"(high));
//      printf("Number of operating cycles=%lld\n",((uint64_t)high<<32)|low);
//}
void _trm_init() {
    memset(&_bss_start,0,(&_bss_end-&_bss_start));
    uart_init();
    //uint32_t project,id;
    //asm volatile("csrr %0, mvendorid":"=r"(project));
    //asm volatile("csrr %0, marchid":"=r"(id));
    //printf("student number:%c%c%c%c_%d\n",(project&0xff000000)>>24,(project&0xff0000)>>16,(project&0xff00)>>8,(project&0xff),id);
    int ret = main(mainargs);
    //test_mcycle();
    halt(ret);
}
__attribute__((section(".text.ssbl"),noinline))
void ssbl(){
    volatile uint32_t *src;
    volatile uint32_t *dst;
    volatile uint32_t *end;
    src = (volatile uint32_t *)&_text_lma_start;
    dst = (volatile uint32_t *)&_text_vma_start;
    end = (volatile uint32_t *)&_text_vma_end;
    while (dst < end) {
        *dst++ = *src++;
    }

    src = (volatile uint32_t *)&_rodata_lma_start;
    dst = (volatile uint32_t *)&_rodata_vma_start;
    end = (volatile uint32_t *)&_rodata_vma_end;
    while (dst < end) {
        *dst++ = *src++;
    }
    src = (volatile uint32_t *)&_data_lma_start;
    dst = (volatile uint32_t *)&_data_vma_start;
    end = (volatile uint32_t *)&_data_vma_end;
    while (dst < end) {
        *dst++ = *src++;
    }
    asm volatile("fence.i");
    _trm_init();
}
__attribute__((section(".text.fsbl"),noinline))
void fsbl(){
    volatile uint32_t *src;
    volatile uint32_t *dst;
    volatile uint32_t *end;
    src = (volatile uint32_t *)&_ssbl_lma_start;
    dst = (volatile uint32_t *)&_ssbl_vma_start;
    end = (volatile uint32_t *)&_ssbl_vma_end;
    while (dst < end) {
        *dst++ = *src++;
    }
    asm volatile("fence.i");
    
    ssbl();
}
