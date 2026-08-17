ENTRY(_start)

MEMORY
{
    RAM (x) : ORIGIN = 0x20000000, LENGTH = 2K
}

SECTIONS
{
    .text : {
        *(.text*)
        *(.rodata*)
    } > RAM

    .data : {
        *(.data*)
    } > RAM

    .bss : {
        *(.bss*)
        *(COMMON)
    } > RAM

    /DISCARD/ : {
    *(.interp)
    *(.comment)
    *(.note*)
    }
    
    _stack_top = ALIGN(0x1000);
    . = _stack_top + 0x1000;
    _stack_pointer = .;
}
