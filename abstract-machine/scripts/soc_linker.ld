ENTRY(_start)
PHDRS { 
  fsbl PT_LOAD;
  ssbl PT_LOAD;
  text PT_LOAD;
  data PT_LOAD;
}

MEMORY {
  mrom(rx)   : ORIGIN = 0x20000000, LENGTH = 0x1000
  flash(rx)  : ORIGIN = 0x30000000, LENGTH = 0x10000000
  sram(rwx)  : ORIGIN = 0x0f000000, LENGTH = 0x2000
  psram(rwx) : ORIGIN = 0x80000000, LENGTH = 0x400000
  sdram(rwx) : ORIGIN = 0xa0000000, LENGTH = 0x8000000
}

SECTIONS {
  .fsbl : {
    _sfsbl = ALIGN(4);
    *(fsbl_entry)
    _efsbl = ALIGN(4);
  } > flash AT>flash : fsbl

  .ssbl : {
    _sssbl = ALIGN(4);
    *(ssbl_entry)
    _essbl = ALIGN(4);
  } > sram AT>flash : ssbl

  _ssbl_loadaddr = LOADADDR(.ssbl);
  
  .text : {
    _stext = ALIGN(4);
    *(text_entry)
    *(.text*)
    *(.rodata*)
    *(.srodata*)
    . = ALIGN(8);
    _etext = .;
  } > sdram AT>flash : text

  _text_loadaddr = LOADADDR(.text);

  .data : {
    . = ALIGN(4);
    _sdata = .;
    *(.data*)
    *(.sdata*)
    . = ALIGN(4);
  } > sdram AT>flash : data

  _data_loadaddr = LOADADDR(.data);

  .bss (NOLOAD) : {
    . = ALIGN(4);
    _edata = .;
    _szero = .;
    *(.bss*)
    *(.sbss*)
    *(.scommon)
    *(COMMON)
    . = ALIGN(4);
  } > sdram

  .heap (NOLOAD) : {
	  _ezero = .;
    _heap_start = ALIGN(4);
    . = ORIGIN(sdram) + LENGTH(sdram);
    _heap_end = ALIGN(4);
  } > sdram

  .stack (NOLOAD) : {
    . = _essbl;
    _stack_end = .;
    _stack_top = .;
    . = ORIGIN(sram) + LENGTH(sram);
    _stack_start = .;
    _stack_pointer = .;
  } > sram
}
