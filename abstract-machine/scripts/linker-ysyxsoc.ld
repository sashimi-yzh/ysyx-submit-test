ENTRY(_start)
PHDRS { 
    boot PT_LOAD FLAGS(5); 
    ssbl PT_LOAD FLAGS(5);
    text PT_LOAD FLAGS(5); 
    rodata PT_LOAD FLAGS(4);
    data PT_LOAD FLAGS(6); 
    bss PT_LOAD  FLAGS(6);
}
MEMORY {
  flash : ORIGIN = 0x30000000, LENGTH = 16M
  sram  : ORIGIN = 0x0f000000, LENGTH = 8K
  psram : ORIGIN = 0x80000000, LENGTH = 4M
  sdram : ORIGIN = 0xa0000000, LENGTH = 32M
}
SECTIONS {
  . = ORIGIN(flash);
  .boot : {
      *(entry)
      *(.text.fsbl*)
  } > flash AT> flash : boot

  .ssbl : ALIGN(4){
      _ssbl_vma_start = .;
      *(.text.ssbl*)
      . = ALIGN(4);
      _ssbl_vma_end = .;
  } > sram AT> flash : ssbl
  _ssbl_lma_start = LOADADDR(.ssbl);

  .text : ALIGN(4){
    _text_vma_start = .;
    *(.text*)
    . = ALIGN(4);
    _text_vma_end = .;
  } > sdram AT> flash : text
    _text_lma_start = LOADADDR(.text);

  .rodata : ALIGN(4){
    _rodata_vma_start = .;
    *(.rodata*)
    *(.srodata*)
    . = ALIGN(4);
    _rodata_vma_end = .;
  } > sdram AT> flash : rodata
    _rodata_lma_start = LOADADDR(.rodata);

  .data : ALIGN(4){
    PROVIDE(_data_vma_start = .);
    *(.data*)
    *(.sdata*)
    *(.sdata2*)
    . = ALIGN(4);
    _data_vma_end = .;
  } > sdram AT> flash : data
  PROVIDE(_data_lma_start = LOADADDR(.data));

  .bss(NOLOAD) : ALIGN(4){
	PROVIDE(_bss_start = .);
    *(.bss*)
    *(.sbss*)
    *(.scommon)
    _bss_end = .;
  } > sdram : bss

  _heap_start = ALIGN(4);
  _stack_pointer = ORIGIN(sdram) + LENGTH(sdram);
  _stack_top = _stack_pointer-32k;
  _heap_end = _stack_top;
}
