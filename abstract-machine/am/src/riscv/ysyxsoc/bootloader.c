#include <stdint.h>
#include <stddef.h>

/* 外部符号（与原先一致） */
extern void _trm_init();

/* 段符号 */
extern char _ssbl, _essbl, _ssbl_lma;

extern char _text,   _etext;
extern char _rodata, _erodata;
extern char _data,   _edata;

extern char _stext_lma;
extern char _srodata_lma;
extern char _sdata_lma;

extern char _bss_start, _bss_end;

/* RTT 可能存在的扩展段（其对齐无法在此强制，保留尾字节兜底） */
extern char _data_extra, _edata_extra, _data_extra_lma, _edata_extra_lma;
extern char _bss_extra,  _ebss_extra;

/* 复制 .text 段（Flash -> SDRAM），纯 32 位 */
void copy_text() __attribute__((section(".text.ssbl")));
void copy_text() {
    const uint32_t *src = (const uint32_t *)&_stext_lma;
    uint32_t *dst       = (uint32_t *)&_text;
    size_t nwords = ((size_t)(&_etext - &_text)) >> 2;
    for (size_t i = 0; i < nwords; i++) dst[i] = src[i];
}

/* 复制 .rodata 段（Flash -> SDRAM），纯 32 位 */
void copy_rodata() __attribute__((section(".text.ssbl")));
void copy_rodata() {
    const uint32_t *src = (const uint32_t *)&_srodata_lma;
    uint32_t *dst       = (uint32_t *)&_rodata;
    size_t nwords = ((size_t)(&_erodata - &_rodata)) >> 2;
    for (size_t i = 0; i < nwords; i++) dst[i] = src[i];
}

/* 复制 .data 段（Flash -> SDRAM），纯 32 位；extra 也按 32 位拷贝 */
void copy_data() __attribute__((section(".text.ssbl")));
void copy_data() {
    const uint32_t *src = (const uint32_t *)&_sdata_lma;
    uint32_t *dst       = (uint32_t *)&_data;
    size_t nwords = ((size_t)(&_edata - &_data)) >> 2;
    for (size_t i = 0; i < nwords; i++) dst[i] = src[i];

    /* RTT 的 data_extra：已 8/4 对齐，可直接 32 位拷贝 */
    size_t nwords2 = ((size_t)(&_edata_extra - &_data_extra)) >> 2;
    if (nwords2) {
        const uint32_t *src2 = (const uint32_t *)&_data_extra_lma;
        uint32_t *dst2       = (uint32_t *)&_data_extra;
        for (size_t i = 0; i < nwords2; i++) dst2[i] = src2[i];
    }
}

/* 清零 BSS（纯 32 位）；extra 也按 32 位清零 */
// void clear_bss() __attribute__((section(".text.ssbl")));
// void clear_bss() {
//     uint32_t *dst = (uint32_t *)&_bss_start;
//     size_t nwords = ((size_t)(&_bss_end - &_bss_start)) >> 2;
//     for (size_t i = 0; i < nwords; i++) dst[i] = 0u;

//     size_t nwords2 = ((size_t)(&_ebss_extra - &_bss_extra)) >> 2;
//     if (nwords2) {
//         uint32_t *dst2 = (uint32_t *)&_bss_extra;
//         for (size_t i = 0; i < nwords2; i++) dst2[i] = 0u;
//     }
// }

/* 复制 .text.ssbootloader（Flash -> SRAM），纯 32 位 */
void copy_ssbl() __attribute__((section(".text.fsbl")));
void copy_ssbl() {
    const uint32_t *src = (const uint32_t *)&_ssbl_lma;
    uint32_t *dst       = (uint32_t *)&_ssbl;
    size_t nwords = ((size_t)(&_essbl - &_ssbl)) >> 2;
    for (size_t i = 0; i < nwords; i++) dst[i] = src[i];
}

/* 入口保持不变 */
void bootloader() __attribute__((section(".text.ssbl")));
void bootloader() {
    copy_text();
    copy_rodata();
    if (&_edata > &_data) { copy_data(); }
    // clear_bss();
    _trm_init();
}

void fsbl() __attribute__((section(".text.fsbl")));
void fsbl() {
    copy_ssbl();
    bootloader();
}
