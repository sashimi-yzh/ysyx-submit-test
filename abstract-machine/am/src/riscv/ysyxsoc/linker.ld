ENTRY(_start)
PHDRS { init PT_LOAD;init2 PT_LOAD; text PT_LOAD; data PT_LOAD; }

MEMORY {
  sram (xrw) : ORIGIN = 0x0f000000, LENGTH = 8k
  psram (xrw) : ORIGIN = 0x80000000, LENGTH = 4M
  flash (rx) : ORIGIN = 0x30000000, LENGTH = 16M
  sdram (xrw) : ORIGIN = 0xa0000000, LENGTH =128M
}


SECTIONS {
  . = ORIGIN(flash);
  .init : {
    *(entry)
    *(.init) 
    . = ALIGN(4);
  } > flash : init

  .init2 : {
      _init2_start = .;
      *(.init2)
      . = ALIGN(4);
    } > sram AT> flash : init2
    _init2_end = .;
    _init2_lma = LOADADDR(.init2);

  .text : {
    _text_start = .;
    *(.text*)

    *(.rodata*)
    *(.srodata*)
    . = ALIGN(4);
  } > sdram AT> flash : text
  _text_end = .;
  _text_lma = LOADADDR(.text);

  /* .rodata : {
    _rodata_start = .;


  } > sdram AT> flash 
  _rodata_end = .;
  _rodata_lma = LOADADDR(.rodata); */

  .data : {
    _data_start = .;
    *(.data*)
    *(.sdata*)
    . = ALIGN(4); 
  } > sdram AT> flash : data

  _data_lma = LOADADDR(.data);

  _data_end = .;
  
  .bss (NOLOAD) : {
	  _bss_start = .;
    *(.bss*)
    *(.sbss*)
    *(.scommon)
    . = ALIGN(4);
  } > sdram 
  _bss_end = .;
  _heap_start = .;
  

  . = ORIGIN(sdram) + LENGTH(sdram);
  _heap_end = .;
  _stack_pointer = .;
  end = .;
  _end = .;
}
