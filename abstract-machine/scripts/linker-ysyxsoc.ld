ENTRY(_start)
PHDRS { entry PT_LOAD; ssbl PT_LOAD; text PT_LOAD; rdata PT_LOAD; data PT_LOAD; bss PT_LOAD; }
MEMORY {
  flash : ORIGIN = 0x30000000, LENGTH = 16M
  sram : ORIGIN = 0x0f000000, LENGTH = 8K
  sdram : ORIGIN = 0xa0000000, LENGTH = 64M
}

SECTIONS {
  . = ORIGIN(flash);
  _sram_start = ORIGIN(sram);
  _sdram_start = ORIGIN(sdram);

  .entry : {
    *(entry)
  } > flash : entry

  .ssbl : {} > sram AT > flash : ssbl
  _ssbl_start = LOADADDR(.ssbl);
  _ssbl_size = SIZEOF(.ssbl);
  
  .text : {
    *(.text*)
    . = ALIGN(16);
  } > sdram AT > flash : text
  _text_start = LOADADDR(.text);
  _text_size = SIZEOF(.text);

  .rodata : {
    . = ALIGN(16);
    _rodata_target = .;
    *(.rodata*)
    *(.srodata*)
    . = ALIGN(16);
  } > sdram AT > flash : rdata
  _rodata_start = LOADADDR(.rodata);
  _rodata_size = SIZEOF(.rodata);

  .data : {
    . = ALIGN(16);
    _data_target = .;
    *(.data*)
    *(.sdata*)
    . = ALIGN(16);
  } > sdram AT > flash : data
  _data_start = LOADADDR(.data);
  _data_size = LOADADDR(.bss) - _data_start;

  .bss : {
    . = ALIGN(16);
    *(.bss*)
    *(.sbss*)
    *(.scommon)
    . = ALIGN(16);
  } > sdram AT > flash : bss
  _heap_start = .;

  _stack_pointer = ORIGIN(sram) + LENGTH(sram);
}
