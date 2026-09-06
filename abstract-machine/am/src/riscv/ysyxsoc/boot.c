#include <am.h>

extern char _sdata_lma;
extern char _srodata_lma;
extern char _bss_lma;
extern char _stext_lma;

extern char _sstage2_lma;

extern char _sdata_vma;
extern char _edata_vma;
extern char _srodata_vma;
extern char _erodata_vma;
extern char _sbss_vma;
extern char _ebss_vma;
extern char _stext_vma;
extern char _etext_vma;

extern char _sstage2_vma;
extern char _estage2_vma;

DECLARE_WEAK_SYMBOL(char, __am_apps_bss_start)
DECLARE_WEAK_SYMBOL(char, __am_apps_bss_end)

DECLARE_WEAK_SYMBOL(char, _sdata_extra_vma)
DECLARE_WEAK_SYMBOL(char, _edata_extra_vma)
DECLARE_WEAK_SYMBOL(char, _data_extra_lma)

#define NOP_INST 0x00000013
#define RET_INST 0x00008067

__attribute__((section(".stage1")))
void loader_fsbl() {
    // this funciton implement the first stage load
    // it nonly load the loader_ssbl() to the psram
    // then the loder_ssbl finish the follow things
    COPY_SECTION(_sstage2_lma, _sstage2_vma, _estage2_vma, char);
}

__attribute__((section(".stage2")))
void extra_lode() {
    char *lma_start = _data_extra_lma;
    
    /* 加载finsh符号表 */
    COPY_OPTIONAL_SECTION(lma_start, _sdata_extra_vma, _edata_extra_vma, char, "FSymTab");
    
    if (CHECK_SECTION_EXISTS(__am_apps_bss_start, __am_apps_bss_end)) {
        CLEAR_BSS(__am_apps_bss_start, __am_apps_bss_end);
    }
}

__attribute__((section(".stage2")))
void loader_ssbl() {
    COPY_SECTION(_sdata_lma, _sdata_vma, _edata_vma, int);
    COPY_SECTION(_srodata_lma, _srodata_vma, _erodata_vma, int);
    CLEAR_BSS(_sbss_vma, _ebss_vma);

    COPY_SECTION(_stext_lma, _stext_vma, _etext_vma, char);
    asm volatile ("fence.i" ::: "memory");

    extra_lode();
}

__attribute__((section(".stage1")))
void loader_init() {
    loader_fsbl();
    loader_ssbl();
}