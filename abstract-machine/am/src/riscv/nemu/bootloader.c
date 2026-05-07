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
    
    size_t data_size = (size_t)(_data_vma_end - _data_vma_start);
    uint8_t *d = (uint8_t *)_data_vma_start;
    uint8_t *s = (uint8_t *)_data_lma_start;
    if (data_size > 0) {
        //memcpy(_data_vma_start, _data_lma_start, data_size); 
               
        while (data_size--) {
            *d = *s;
            d++;
            s++;
        }
    }
    
    size_t code_size = (size_t)(_text_end - _text_start);
    d = (uint8_t *)_text_start;
    s = (uint8_t *)_text_lma_start;
    if(code_size > 0) {
        while(code_size--) {
            *d = *s;
            d++;
            s++;
        }
    }
}

void __attribute__((section(".fsbl"))) _load_bootloader() {
    size_t bootloader_size = (size_t)(_bootloader_end - _bootloader_start);
    uint8_t *d = (uint8_t *)_bootloader_start;
    uint8_t *s = (uint8_t *)_bootloader_lma_start;
    if (bootloader_size > 0) {               
        while (bootloader_size--) {
            *d = *s;
            d++;
            s++;
        }
    }
}