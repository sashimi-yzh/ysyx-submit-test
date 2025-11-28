#include <am.h>
#include <klib-macros.h>
#include <ysyxsoc.h>
#include <riscv.h>

extern char _heap_start;
extern char _data_start;

extern char _lma_code_start,_text_start,_etext,_lma_rodata_start,_erodata;
extern char _lma_data_start,_data_start, _data_end,_bss_start, _bss_end;
extern char _lma_sec_boost_start,_sec_boost_start, _sec_boost_end;
extern char _trm_init;
void init_uart();

__attribute__ ((section(".first_boost"))) void _load_sec_boost() {
    unsigned* src = (unsigned*)&_lma_sec_boost_start;
    unsigned* dst = (unsigned*)&_sec_boost_start;
    while (dst < (unsigned*)&_sec_boost_end) {
        *dst++ = *src++;
    }
    char *cdst = (char*)dst;
    char *csrc = (char*)src;
    while (cdst < &_sec_boost_end ) *cdst++ = *csrc++;
    void (*sec_boost)(void) = (void(*)(void))&_sec_boost_start;
    sec_boost();
}

__attribute__ ((section(".sec_boost"))) void _sec_boost(){
    init_uart();        

    // void (*app_entry)(void) = (void(*)(void))&_trm_init;
    // app_entry();
    // asm volatile(".word 0x0000100F");

    // load code from LMA to VMA
    unsigned *src = (unsigned*)&_lma_code_start;
    unsigned *dst = (unsigned*)&_text_start;
    while (dst < (unsigned*)&_erodata)  *dst++ = *src++;
    char *csrc = (char*)src;
    char *cdst = (char*)dst;
    while (cdst < &_erodata ) *cdst++ = *csrc++;

    src = (unsigned*)&_lma_data_start;
    dst = (unsigned*)&_data_start;
    while (dst < (unsigned*)&_data_end)  *dst++ = *src++;
    csrc = (char*)src;
    cdst = (char*)dst;
    while (cdst < &_data_end ) *cdst++ = *csrc++;
    
    putch('l'); putch('o'); putch('a'); putch('d'); putch('e'); putch('d');putch('\n');

    void (*app_entry)(void) = (void(*)(void))&_trm_init;
    app_entry();
}