// #include <stdint.h>
// #include <bootloader.h>
// #include <klib.h>
// #include <klib-macros.h>
// #include <am.h>

// void _trm_init();

// void fsbl() __attribute__((section(".text.fsbl")));
// void ssbl(volatile char *src) __attribute__((section(".text.ssbl"), noinline));

// extern char _fsbl_start, _fsbl_end;
// extern char _ssbl_start, _ssbl_end;
// extern char _data_start, _data_end;
// extern char _text_start, _text_end;
// extern char _rodata_start, _rodata_end;
// extern char _bss_start, _bss_end;

// void bss_clr(){
//     volatile char *dest = &_bss_start;
//     while (dest < &_bss_end)
//         *dest++ = 0;
// }

// //1字节搬移

// void fsbl(){
//     volatile char *src = &_fsbl_end;
//     volatile char *dest = &_ssbl_start;
//     while(dest < &_ssbl_end)
//         *dest++ = *src++;
//     // printf("fsbl done\n");
//     ssbl(src);
// }

// void ssbl(volatile char *src){
//     volatile char *dest = &_text_start;
//     while(dest < &_data_end)
//         *dest++ = *src++;
//     bss_clr();
//     // printf("bootloader done\n");
//     _trm_init();
// }

















//4字节搬移


#include <stdint.h>
#include <bootloader.h>
#include <klib.h>
#include <klib-macros.h>
#include <am.h>

void _trm_init();

void fsbl() __attribute__((section(".text.fsbl")));
void ssbl(volatile uint32_t *src) __attribute__((section(".text.ssbl"), noinline));

extern char _fsbl_start, _fsbl_end;
extern char _ssbl_start, _ssbl_end;
extern char _data_start, _data_end;
extern char _text_start, _text_end;
extern char _rodata_start, _rodata_end;
extern char _bss_start, _bss_end;

void bss_clr(){
    volatile uint32_t *dest = (volatile uint32_t *)&_bss_start; // 强制类型转换
    // 确保bss_end地址对齐4字节，否则需要额外处理剩余字节
    while ((uint32_t)dest < (uint32_t)&_bss_end) // 比较地址，强制转换以避免警告
        *dest++ = 0;
}



void fsbl(){
    // 确保源和目标地址对齐4字节
    volatile uint32_t *src = (volatile uint32_t *)&_fsbl_end; // 强制类型转换
    volatile uint32_t *dest = (volatile uint32_t *)&_ssbl_start; // 强制类型转换

    // 计算搬移的4字节块数
    size_t ssbl_size_in_bytes = (size_t)(&_ssbl_end - &_ssbl_start);
    size_t ssbl_words = ssbl_size_in_bytes / 4;
    size_t ssbl_remaining_bytes = ssbl_size_in_bytes % 4;

    for (size_t i = 0; i < ssbl_words; ++i) {
        *dest++ = *src++;
    }

    // 处理剩余的不足4字节的部分（如果存在）
    volatile char *char_dest = (volatile char *)dest;
    volatile char *char_src = (volatile char *)src;
    for (size_t i = 0; i < ssbl_remaining_bytes; ++i) {
        *char_dest++ = *char_src++;
    }

    // printf("fsbl done\n");
    ssbl((volatile uint32_t *)char_src); // 传递当前src的char指针的4字节对齐版本
}

void ssbl(volatile uint32_t *src){ // 修改参数类型
    volatile uint32_t *dest = (volatile uint32_t *)&_text_start; // 强制类型转换

    // 计算搬移的4字节块数
    size_t data_size_in_bytes = (size_t)(&_data_end - &_text_start);
    size_t data_words = data_size_in_bytes / 4;
    size_t data_remaining_bytes = data_size_in_bytes % 4;

    for (size_t i = 0; i < data_words; ++i) {
        *dest++ = *src++;
    }

    // 处理剩余的不足4字节的部分（如果存在）
    volatile char *char_dest = (volatile char *)dest;
    volatile char *char_src = (volatile char *)src;
    for (size_t i = 0; i < data_remaining_bytes; ++i) {
        *char_dest++ = *char_src++;
    }

    bss_clr();
    // _trm_init();
    asm volatile (
        "lui t0, %hi(_trm_init)\n"      // 获取 _trm_init 地址的高 20 位
        "addi t0, t0, %lo(_trm_init)\n" // 加上 _trm_init 地址的低 12 位，t0 寄存器现在存储了 _trm_init 的完整地址
        "jalr ra, 0(t0)\n"              // 跳转并链接到 t0 寄存器指向的地址 (即 _trm_init)
    );
}