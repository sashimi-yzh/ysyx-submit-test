#include <am.h>
#include <klib-macros.h>
#include <klib.h>
#include "npc.h"
#include <bootloader.h>
#include "ysyxsoc.h"

extern char _heap_start;
extern char _heap_end;

int main(const char *args);

extern char _pmem_start;
#define PMEM_SIZE (128 * 1024 * 1024)
#define PMEM_END  ((uintptr_t)&_pmem_start + PMEM_SIZE)
#define npc_trap(code) asm volatile("mv a0, %0; ebreak" : :"r"(code))

Area heap = RANGE(&_heap_start, &_heap_end);
#ifndef MAINARGS
#define MAINARGS ""
#endif
const char mainargs[] = MAINARGS;

void putch(char ch) {
    /*added by ypc begin 2024.11.24*/
    uint8_t LSR;
    uint8_t TFE;
    do{
        LSR = inb(UART_BASE + UART_REG_LS);
        TFE = (LSR >> UART_LS_TFE) & 1;
    } while(TFE == 0);
    /*added by ypc eng 2024.11.24*/
    outb(UART_BASE + UART_REG_RB, ch);
    // outb(SERIAL_PORT, ch);
}

void halt(int code) {
  npc_trap(code);
  while (1);
}

/*added by ypc begin 2024.11.24*/
void init_uart(uint16_t div){
    outb(UART_BASE + UART_REG_LC, 0b10000011);
    outb(UART_BASE + UART_REG_DL2, (uint8_t)(div >> 8));
    outb(UART_BASE + UART_REG_DL1, (uint8_t)div);
    outb(UART_BASE + UART_REG_LC, 0b00000011);
}
/*added by ypc eng 2024.11.24*/

/*added by ypc begin 2024.11.27*/
void show_id(){
    int i;
    uint32_t mvendorid;
    uint32_t marchid;
    asm volatile("csrr %0, mvendorid" : "=r"(mvendorid));
    asm volatile("csrr %0, marchid" : "=r"(marchid));
    int j = 0;
    int id = marchid;
    char buf[10];
    while(id > 0){
        buf[j++] = id % 10 + '0';
        id /= 10;
    }
    //show ysyx
    //show id
    for(i = 3; i >= 0; i--){
        putch((char)((mvendorid >> i * 8) & 0xff));
    }
    putch('_');
    for(i = j - 1; i >= 0; i--){
        putch(buf[i]);
    }
    putch('\n');
}
/*added by ypc begin 2024.11.27*/

void _trm_init() {
    init_uart(1);
    ioe_init();
    // show_id();//not supported in difftest because mvendorid and marchid are not supported in nemu as a ref
    // printf("hello ypc\n");
    // int ret = main("test");
    int ret = main(mainargs);
    halt(ret);
    // printf("finish\n");
}
