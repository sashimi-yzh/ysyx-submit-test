ENTRY(_start)


MEMORY {
  mrom : ORIGIN = 0x20000000, LENGTH = 4K
  sram : ORIGIN = 0x0f000000, LENGTH = 8K
  flash : ORIGIN = 0x30000000, LENGTH = 64M
  psram : ORIGIN = 0x80000000, LENGTH = 4M
  sdram : ORIGIN = 0xA0000000, LENGTH = 64M
}

SECTIONS {
  /* _pmem_start and _entry_offset are defined in LDFLAGS */
  _sram_start = ORIGIN(sram);
  _sram_end = _sram_start + LENGTH(sram);
  . = ORIGIN(flash);
  .entry : {
    _entry_start = .;
    *(entry)
    *(.entry)
    _entry_end = .;
  } > flash

  .ssbl :{
    _ssbl_MA = LOADADDR(.ssbl);
    _ssbl_SA = .; 
    *(.ssbl)
    *(.scommon)
    _ssbl_end = .;
  } > sram AT> flash
  .text : {
    _text_MA = LOADADDR(.text);
    _text_SA = .;
    *(.text*)
    _text_end = .;
  } > sdram AT> flash 
  etext = .;
  _etext = .;
  .rodata : { 
    _rodata_MA = LOADADDR(.rodata); 
    _rodata_SA = .; 
    *(.rodata*)
    *(.srodata*)
    _rodata_end = .;
  } > flash 
  _data_lma_start = LOADADDR(.rodata) + SIZEOF(.rodata);
 
  .data : {
    _data_MA = LOADADDR(.data); 
    _data_SA = .;  
    *(.data*)
    *(.sdata*)
    _data_end = .;
  } > sdram AT> flash
 
  .bss : {
	_bss_start = .;
    *(.bss*)
    *(.sbss*)
    *(.scommon)
  } > sdram

  _heap_start = ORIGIN(psram);
  _psram_end = ORIGIN(psram) + LENGTH(psram);

  .stack (NOLOAD) : ALIGN(8) {
    . = ORIGIN(sram) + LENGTH(sram) - 0x800;
    . = ALIGN(8);
    _stack_top = .;
    . += 0x800;
    _stack_pointer = .;
  } > sram
  
  
}
