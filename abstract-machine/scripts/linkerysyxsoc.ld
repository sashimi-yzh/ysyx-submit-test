ENTRY(_start)

PHDRS {
    text PT_LOAD;
    data PT_LOAD;
    fsbl PT_LOAD;
    ssbl PT_LOAD;
}

MEMORY {
    flash : ORIGIN = 0x30000000, LENGTH = 256M
    psram : ORIGIN = 0x80000000, LENGTH = 4M
    sram : ORIGIN = 0x0f000000, LENGTH = 8K
    sdram : ORIGIN = 0xa0000000, LENGTH = 512M

    mrom : ORIGIN = 0x20000000, LENGTH = 4K /*no use*/
}

SECTIONS {
    . = ORIGIN(flash);

    .text.fsbootloader :
    {
        *(entry)
        _fsbl_start = .;
        *(.text.fsbl)
        _fsbl_end = .;
    } > flash AT > flash : fsbl

    .text.ssbootloader :
    {
        _ssbl_start = .;
        *(.text.ssbl)
        _ssbl_end = .;
    } > sram AT > flash : ssbl



    .text :
    ALIGN_WITH_INPUT
    SUBALIGN(4)
    {
        _text_start = .;
        *(.text*)
        _text_end = .;
    } > sdram AT > flash : text



    .rodata :
    ALIGN_WITH_INPUT
    SUBALIGN(4)
    {
        _rodata_start = .;
        *(.rodata*)
        *(.srodata*)
        _rodata_end = .;
    } > sdram AT > flash

/*data.extra*/

    .data :
    ALIGN_WITH_INPUT
    SUBALIGN(4)
    {
        _data_start = .;
        *(.data*)
        *(.sdata*)
        _data_end = .;
    } > sdram AT > flash : data

/*bss.extra*/

    .bss :
    ALIGN_WITH_INPUT
    SUBALIGN(4)
    {
        _bss_start = .;
        *(.bss*)
        *(.sbss*)
        *(.scommon)
        _bss_end = .;
    } > sdram AT > flash




    end = .;
    _end = .;

    _heap_start = ALIGN(0x10);
    _heap_end = _heap_start + 2M;

    _stack_top = ORIGIN(sram);
    . = _stack_top + LENGTH(sram) - 0x100;
    _stack_pointer = .;

}