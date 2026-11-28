ENTRY(_start)

MEMORY {
  flash : ORIGIN = 0x30000000, LENGTH = 16M
  sdram : ORIGIN = 0xa0000000, LENGTH = 64M
}

SECTIONS {
  . = ORIGIN(flash);
  .text_start : {
    *(entry)
    *(.FSBL)
  } > flash AT> flash

  . = ORIGIN(sdram);
  _pmem_start = .;

  .SSBL : {
    _SSBL_start = .;
    *(.SSBL)
    _SSBL_end = .;
  } > sdram AT> flash
  _SSBL_lma_start = LOADADDR(.SSBL);

  .text : {
    _text_vma_start = .;
    *(.text*)
    *(.rodata*)
    *(.srodata*)
    . = ALIGN(4);
    _text_vma_end = .;
  } > sdram AT> flash
  _text_lma_start = LOADADDR(.text);

  .data : {
    _data_vma_start = .;
    *(.data*)
    *(.sdata*)
    . = ALIGN(4);
    _data_vma_end = .;
  } > sdram AT> flash
  _data_lma_start = LOADADDR(.data);

  .bss : {
	  _bss_start = .;
    *(.bss*)
    *(.sbss*)
    *(.scommon)
    _bss_end = .;
  } > sdram

  . = ALIGN(8);
  _heap_start = .;

  _stack_pointer = ORIGIN(sdram) + LENGTH(sdram);

}
