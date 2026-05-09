ENTRY(_start)

MEMORY {
    FLASH (rx) : ORIGIN = 0x30000000, LENGTH = 0x1000000
    SDRAM (rwx) : ORIGIN = 0xa0000000, LENGTH = 0x8000000
}

SECTIONS {

    .entry : {
        KEEP(*(.entry))
        . = ALIGN(0x10); 
    } > SDRAM AT > FLASH

    .copy_routine : {
        _copy_routine_load_start = LOADADDR(.copy_routine);
        _copy_routine_start = .;
        KEEP(*(.copy_routine))
        . = ALIGN(0x10); 
        _copy_routine_end = .;
    } > SDRAM AT > FLASH

    .main_text : {
        _text_load_start = LOADADDR(.main_text);
        _text_start = .;
        *(.text .text.*)
        _text_end = .;
    } > SDRAM AT > FLASH

    .rodata : {
        _rodata_load_start = LOADADDR(.rodata);
        . = ALIGN(0x4);
        _rodata_start = .;
        *(.rodata*)
        *(.srodata*)
        . = ALIGN(0x4);
        _rodata_end = .;
    } > SDRAM AT > FLASH

    _data_extra_start = DEFINED(_data_extra_start) ? _data_extra_start : 0;
    _data_extra_end  = DEFINED(_data_extra_end) ? _data_extra_end : 0;
    _data_extra_load = DEFINED(_data_extra_load) ? _data_extra_load : 0;

    .data : {
        _data_load_start = LOADADDR(.data);
        . = ALIGN(0x4);
        _data_start = .;
        *(.data*)
        *(.sdata*)
        . = ALIGN(0x4);
        _data_end = .;
    } > SDRAM AT > FLASH

    _bss_extra_start = DEFINED(_bss_extra_start) ? _bss_extra_start : 0;
    _bss_extra_end  = DEFINED(_bss_extra_end) ? _bss_extra_end : 0;
    /* _bss_extra_load = DEFINED(_bss_extra_load) ? _bss_extra_load : 0; */

    .bss (NOLOAD) : {
        _bss_start = .;
        *(.bss*)
        *(.sbss*)
        *(.scommon)
        _bss_end = .;
    } > SDRAM

    _stack_top = ALIGN(_bss_end, 0x10);
    . = _stack_top + 0x8000;
    _stack_pointer = .;

    end = .;
    _end = .;

    _heap_start = ALIGN(0x10);
    _heap_end = ORIGIN(SDRAM) + LENGTH(SDRAM);
}
