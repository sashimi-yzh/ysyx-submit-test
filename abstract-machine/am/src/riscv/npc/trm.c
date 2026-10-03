#include <am.h>
#include <klib-macros.h>
#include "riscv/riscv.h"
#include "klib.h"
extern char _heap_start;
int main(const char *args);

extern char _pmem_start;
#define PMEM_SIZE (1 * 1024 * 1024)//128 1024 1024
#define PMEM_END  ((uintptr_t)&_pmem_start + PMEM_SIZE)
# define nemu_trap(code) asm volatile("mv a0, %0; ebreak" : :"r"(code))
Area heap = RANGE(&_heap_start, PMEM_END);
static const char mainargs[MAINARGS_MAX_LEN] = TOSTRING(MAINARGS_PLACEHOLDER); // defined in CFLAGS

void putch(char ch) {
    outb(0x10000000, ch);
}

void halt(int code) {
    nemu_trap(code);
    while (1);
}
/*
static void test_mcycle(){
    uint32_t low,high;
    asm volatile("csrr %0, mcycle" :"=r"(low));
    asm volatile("csrr %0, mcycleh" :"=r"(high));
    //printf("Number of operating cycles=%ld\n",((uint64_t)high<<32)|low);
}
*/
void _trm_init() {
    uint32_t project,id;
    asm volatile("csrr %0, mvendorid":"=r"(project));
    asm volatile("csrr %0, marchid":"=r"(id));
    printf("student number:%c%c%c%c_%d\n",(project&0xff000000)>>24,(project&0xff0000)>>16,(project&0xff00)>>8,(project&0xff),id);
    int ret = main(mainargs);
    //test_mcycle();
    halt(ret);
}
