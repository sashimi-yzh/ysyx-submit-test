ENTRY(_start)
PHDRS { }

SECTIONS {
  .text.FSBL : {
    *(entry)
    . = ALIGN(8);
  } > flash

  .text.SSBL : {
    _sram_SSBL_start = .;
    *(SSBL)
    . = ALIGN(8);
  } > sram AT> flash
  _flash_SSBL_start = LOADADDR(.text.SSBL);
  _flash_SSBL_end = LOADADDR(.text.SSBL) + SIZEOF(.text.SSBL);
  
  .text : {
    _sdram_text_start = .;
    *(.text*)
    . = ALIGN(8);
  } > sdram AT> flash
  _flash_text_start = LOADADDR(.text);
  _flash_text_end = LOADADDR(.text) + SIZEOF(.text);

  .rodata : {
    _sdram_rodata_start = .;
    *(.srodata*)
    . = ALIGN(8);
    *(.rodata*)
    . = ALIGN(8);
  } > sdram AT> flash
  _flash_rodata_start = LOADADDR(.rodata);
  _flash_rodata_end = LOADADDR(.rodata) + SIZEOF(.rodata);

  PROVIDE(_flash_extra_data_start = 0);
  PROVIDE(_flash_extra_data_end = 0);
  PROVIDE(_sdram_extra_data_start = 0);

  .data : ALIGN(4){
    _sdram_data_start = .;
    *(.data*)
    . = ALIGN(8);
    *(.sdata*)
    . = ALIGN(8);
  } > sdram AT> flash
  _flash_data_start = LOADADDR(.data);
  _flash_data_end = LOADADDR(.data) + SIZEOF(.data);

  .bss : ALIGN(4){
    *(.bss*)
    *(.sbss*)
    *(.scommon)
  } > sdram

  . = ALIGN(4);
  _heap_start = .;
  . = ORIGIN(sdram) + LENGTH(sdram);
  _heap_end = .;
  
  _stack_pointer = ORIGIN(sram) + LENGTH(sram);
}
