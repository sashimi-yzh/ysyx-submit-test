ENTRY(_start)
/* PHDRS { text PT_LOAD; data PT_LOAD; } */

MEMORY {
  flash : ORIGIN = 0x30000000, LENGTH = 16M
  sram  : ORIGIN = 0x0f000000, LENGTH = 8K
  psram : ORIGIN = 0x80000000, LENGTH = 4M
  sdram : ORIGIN = 0xa0000000, LENGTH = 32M
}

SECTIONS {
  . = ORIGIN(flash);
  .text_entry : ALIGN(4) {
    *(entry)
  } > flash AT> flash
  .text : ALIGN(4) {
    *(.text*)
    . = ALIGN(8);
    *(.rodata*)
    *(.srodata*)
    . = ALIGN(8);
  } > sram AT> flash
  .data : ALIGN(8) {
    *(.data*)
    *(.sdata*)
    . = ALIGN(8);
  } > sram AT> flash
  .bss : ALIGN(8) {
    *(.bss*)
    *(.sbss*)
    *(.scommon*)
    . = ALIGN(8);
  } > sram AT> flash
  end = .;
  _end = .;
  _heap_start = .;
  _heap_end = ORIGIN(sram) + LENGTH(sram) - 0x1000;
  _stack_pointer = ORIGIN(sram) + LENGTH(sram);

  _data_vma = ADDR(.data);
  _data_lma = LOADADDR(.data);
  _data_size = SIZEOF(.data);
  _bss_vma = ADDR(.bss);
  _bss_size = SIZEOF(.bss);
  _text_vma = ADDR(.text);
  _text_lma = LOADADDR(.text);
  _text_size = _data_vma - _text_vma;
}
