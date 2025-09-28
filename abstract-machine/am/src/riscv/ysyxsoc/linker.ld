ENTRY(_fsbl)
PHDRS {
  fsbl PT_LOAD;
  ssbl PT_LOAD;
  text PT_LOAD;
  rodata PT_LOAD;
  data PT_LOAD;
}

MEMORY {
  sram  : ORIGIN = 0x0f000000, LENGTH = 8K
  mrom  : ORIGIN = 0x20000000, LENGTH = 4K
  flash : ORIGIN = 0x30000000, LENGTH = 16M
  psram : ORIGIN = 0x80000000, LENGTH = 4M
  sdram : ORIGIN = 0xa0000000, LENGTH = 128M
}

SECTIONS {
  fsbl : {
    *(fsbl)
  } >flash AT>flash : fsbl

  ssbl : ALIGN(0x8) {
    _ssbl_start = .;
    *(ssbl)
    . = ALIGN(0x8);
    _ssbl_end = .;
  } >sram AT>flash : ssbl =0x0

  .text : ALIGN(0x8) {
    _text_start = .;
    *(entry)
    *(.text*)
    . = ALIGN(0x8);
    _text_end = .;
  } >sdram AT>flash : text =0x0

  .rodata : ALIGN(0x8) {
    _rodata_start = .;
    *(.srodata*)
    *(.rodata*)
    . = ALIGN(0x8);
    _rodata_end = .;
  } >sdram AT>flash : rodata =0x0
  
  .data : ALIGN(0x8) {
    _data_start = .;
    *(.data*)
    *(.sdata*)
    . = ALIGN(0x8);
    _data_end = .;
  } >sdram AT>flash : data =0x0

  .bss (NOLOAD) : ALIGN(0x8) {
    _bss_start = .;
    *(.bss*)
    *(.sbss*)
    *(.scommon)
    . = ALIGN(0x8);
    _bss_end = .;
  } >sdram

  _ssbl_src = LOADADDR(ssbl);
  _text_src = LOADADDR(.text);
  _rodata_src = LOADADDR(.rodata);
  _data_src = LOADADDR(.data);
  . = _bss_end;
  _heap_start = ALIGN(0x1000);

  _stack_top = ORIGIN(sram);
  _stack_pointer = ORIGIN(sram) + LENGTH(sram);
}
