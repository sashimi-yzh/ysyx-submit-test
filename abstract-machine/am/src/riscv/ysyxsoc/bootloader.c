#include <stdint.h>
#include <stddef.h>
#include <stdio.h>

extern uint8_t _data_lma_start[];
extern uint8_t _data_vma_start[];
extern uint8_t _data_vma_end[];
extern uint8_t _trm_init[];
extern uint8_t _text_end[];
extern uint8_t _text_start[];
extern uint8_t _text_lma_start[];
extern uint8_t _bootloader_start[];
extern uint8_t _bootloader_end[];
extern uint8_t _bootloader_lma_start[];

void __attribute__((section(".bootloader"))) _bootloader_init() {
    // 拷贝 .data 段
    size_t data_size = (size_t)(_data_vma_end - _data_vma_start);
    uint32_t *d32 = (uint32_t *)_data_vma_start;
    uint32_t *s32 = (uint32_t *)_data_lma_start;
    size_t words = data_size >> 2;
    size_t tail  = data_size & 3;

    while (words--) {
        *d32++ = *s32++;
    }

    uint8_t *d8 = (uint8_t *)d32;
    uint8_t *s8 = (uint8_t *)s32;
    while (tail--) {
        *d8++ = *s8++;
    }

    // 拷贝 .text 段
    size_t code_size = (size_t)(_text_end - _text_start);
    d32 = (uint32_t *)_text_start;
    s32 = (uint32_t *)_text_lma_start;
    words = code_size >> 2;
    //tail  = code_size & 3;

    while (words--) {
        *d32++ = *s32++;
    }
    *d32++ = *s32++;
    //d8 = (uint8_t *)d32;
    //s8 = (uint8_t *)s32;
    //while (tail--) {
    //    *d8++ = *s8++;
    //}
}

void __attribute__((section(".fsbl"))) _load_bootloader() {
    size_t bootloader_size = (size_t)(_bootloader_end - _bootloader_start);
    uint32_t *d32 = (uint32_t *)_bootloader_start;
    uint32_t *s32 = (uint32_t *)_bootloader_lma_start;
    size_t words = bootloader_size >> 2;
    size_t tail  = bootloader_size & 3;

    while (words--) {
        *d32++ = *s32++;
    }

    uint8_t *d8 = (uint8_t *)d32;
    uint8_t *s8 = (uint8_t *)s32;
    while (tail--) {
        *d8++ = *s8++;
    }
}