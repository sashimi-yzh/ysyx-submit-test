#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdint.h>
#include "../riscv.h"

#include "device/device.h"

// #define DBG_NOTE

extern char _ssbl_load;
extern char _ssbl_op;
extern char _ssbl_ed;

extern char _code_start;
extern char _code_op;
extern char _code_ed;

extern char _rodata_start;
extern char _rodata_op;
extern char _rodata_ed;

extern char _data_start;
extern char _data_op;
extern char _data_ed;

typedef void (*voidfunc)();


__attribute__((section("entry"))) void _first_bootloader()
{
    uint8_t *dst = (uint8_t*)&_ssbl_op;
    const uint8_t *src = (uint8_t*)&_ssbl_load;
    uint32_t len = (uintptr_t)&_ssbl_ed - (uintptr_t)&_ssbl_op;

    uint32_t *d = (uint32_t *)dst;
    const uint32_t *s = (uint32_t *)src;
    uintptr_t cnt32 = len / 4;

    while (cnt32--) {
        *d++ = *s++;
    }

    dst = (uint8_t *)d;
    src = (const uint8_t *)s;
    uintptr_t rem = len % 4;

    while (rem--) {
        *dst++ = *src++;
    }

    voidfunc ssbl = (voidfunc)(&_ssbl_op);
    ssbl();
}


#ifdef DBG_NOTE
__attribute__((section("ssbl"))) void putch_(char ch) {
  volatile uint8_t* uart_lsr = (volatile uint8_t*)(DEV_SERIAL + 5);
  while (!(*uart_lsr & 0x20));
  outb(DEV_SERIAL, ch);
}


__attribute__((section("ssbl"))) void print_hex_(uint32_t num) {
    for (int i = 7; i >= 0; i--) {
        uint8_t nibble = (num >> (i * 4)) & 0xF;
        char hex_char;

        if (nibble < 10)
            hex_char = '0' + nibble;
        else
            hex_char = 'A' + (nibble - 10);

        putch_(hex_char);
    }
}
#endif


__attribute__((section("ssbl"))) void loader(uint8_t* dst, const uint8_t* src, uintptr_t len) 
{
    uint32_t *d = (uint32_t *)dst;
    const uint32_t *s = (uint32_t *)src;
    uintptr_t cnt32 = len / 4;

    while (cnt32--) {
        *d++ = *s++;
    }

    dst = (uint8_t *)d;
    src = (const uint8_t *)s;
    uintptr_t rem = len % 4;

    while (rem--) {
        *dst++ = *src++;
    }
}


__attribute__((section("ssbl.boot"))) void _second_bootloader()
{
#ifdef DBG_NOTE
    device_ctrl uart_lcr = (device_ctrl)(DEV_SERIAL + 3);
    *uart_lcr = 0x83;

    device_ctrl uart_divisor = (device_ctrl)DEV_SERIAL;
    uart_divisor[1] = 0x00;
    uart_divisor[0] = 0x01;

    *uart_lcr = 0x03;

    putch_('c');putch_('o');putch_('d');putch_('e');
    putch_(':');putch_(' ');putch_(' ');
    putch_('[');print_hex_((uintptr_t)&_code_op);putch_('-');
    putch_('>');print_hex_((uintptr_t)&_code_ed);putch_(']');
    putch_('\n');
#endif

    // 代码加载
    uint8_t *d = (uint8_t*)&_code_op;
    const uint8_t *s = (uint8_t*)&_code_start;
    uint32_t n = (uintptr_t)&_code_ed - (uintptr_t)&_code_op;
    loader(d, s, n);

#ifdef DBG_NOTE
    putch_('r');putch_('o');putch_('d');putch_('a');putch_('t');putch_('a');
    putch_(':');
    putch_('[');print_hex_((uintptr_t)&_rodata_op);putch_('-');
    putch_('>');print_hex_((uintptr_t)&_rodata_ed);putch_(']');
    putch_('\n');
#endif

    // 只读全局变量加载
    d = (uint8_t*)&_rodata_op;
    s = (uint8_t*)&_rodata_start;
    n = (uintptr_t)&_rodata_ed - (uintptr_t)&_rodata_op;
    loader(d, s, n);

#ifdef DBG_NOTE
    putch_('d');putch_('a');putch_('t');putch_('a');
    putch_(':');putch_(' ');putch_(' ');
    putch_('[');print_hex_((uintptr_t)&_data_op);putch_('-');
    putch_('>');print_hex_((uintptr_t)&_data_ed);putch_(']');
    putch_('\n');
#endif

    // 全局变量加载
    d = (uint8_t*)&_data_op;
    s = (uint8_t*)&_data_start;
    n = (uintptr_t)&_data_ed - (uintptr_t)&_data_op;
    loader(d, s, n);

#ifdef DBG_NOTE
    putch_('o');putch_('k');putch_('e');putch_('y');
    putch_('\n');
#endif

    voidfunc start = (voidfunc)(&_code_op);

    start();
}