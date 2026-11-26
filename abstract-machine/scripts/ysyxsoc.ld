MEMORY {
  SRAM (rwx) : ORIGIN = 0x0f000000, LENGTH = 8K
  FLASH (rx) : ORIGIN = 0x30000000, LENGTH = 16M
  SDRAM (rwx) : ORIGIN = 0xa0000000, LENGTH = 32M
}

ENTRY(_start)

SECTIONS {
  .text.fsbl : {
    *(entry)
    *(.text.fsbl*)
  } > FLASH AT> FLASH

  .text.ssbl : {
    _ssbl_start = .;
    *(.text.ssbl*)
    *(.text.load*)
    _ssbl_end = .;
    . = ALIGN(4);
  } > SRAM AT> FLASH
  _ssbl_lma = LOADADDR(.text.ssbl);

  .text : {
    _text_start = .;
    *(.text*)
    _text_end = .;
    . = ALIGN(4);
  } > SDRAM AT> FLASH
  _text_lma = LOADADDR(.text);

  .rodata : {
    _rodata_start = .;
    *(.rodata*)
    *(.srodata*)
    . = ALIGN(4);
    _rodata_end = .;
  } > SDRAM AT> FLASH
  _rodata_lma = LOADADDR(.rodata);

  .data : {
    _data_start = .;
    *(.data*)
    *(.sdata*)
    . = ALIGN(4);
    _data_end = .;
  } > SDRAM AT> FLASH
  _data_lma = LOADADDR(.data);

  edata = .;
  _data = .;

  .bss (NOLOAD) : {
    _bss_start = .;
    *(.bss*)
    *(.sbss*)
    *(.scommon)
    . = ALIGN(4);
    _bss_end = .;
  } > SDRAM 

  _heap_start = .;
  _heap_end = ORIGIN(SDRAM) + LENGTH(SDRAM);

  . = ORIGIN(SRAM) + LENGTH(SRAM);  
  _stack_pointer = .;

  end = .;
  _end = .;
}

