ENTRY(_start)

PHDRS { 
  text PT_LOAD; 
  data PT_LOAD; 
  fsbl PT_LOAD; 
  bootloader PT_LOAD; 
  rodata PT_LOAD; 
  bss PT_LOAD;
}

MEMORY {
  mrom(rx)   : ORIGIN = 0x20000000, LENGTH = 4K
  sram(rwx)  : ORIGIN = 0x0f000000, LENGTH = 8K
  flash(rx)  : ORIGIN = 0x30000000, LENGTH = 16M
  psram(rwx) : ORIGIN = 0x80000000, LENGTH = 4M
  sdram(rwx) : ORIGIN = 0xa0000000, LENGTH = 64M
}

SECTIONS {

  . = ORIGIN(flash);

  .fsbl :{
  . = ALIGN(8);
   *(entry)
    *(.fsbl*)
    . = ALIGN(8);
  } > flash :fsbl
  . = ALIGN(8);
  _bootloader_src = LOADADDR(.bootloader);
  .bootloader :{
  . = ALIGN(8);
    _siflash_ssbl = .;
    *(.bootloader*)
    _eiflash_ssbl = .;
  } > sdram AT> flash : bootloader

. = ALIGN(8);
  _text_src = LOADADDR(.text);

  .text : {
  . = ALIGN(8);
    _text_start = .;
    *(.text*)
    _text_end = .;
    . = ALIGN(8);
  } > sdram AT> flash : text



. = ALIGN(8);
  etext = .;
  _etext = .;

  .rodata : {
  . = ALIGN(8);
    *(.rodata*)
    *(.srodata*)
    . = ALIGN(8);
  } > sdram AT> flash : rodata


. = ALIGN(8);
  _data_src = LOADADDR(.data);

  .data : {
  . = ALIGN(8);
    _data_start = .;
    *(.data*)
    *(.sdata*)
    _data_end = .;
    . = ALIGN(8);
  } > sdram AT>flash : data

  edata = .;
  _data = .;

. = ALIGN(8);

  .bss : {
    _bss_start = .;
    *(.bss*)
    *(.sbss*)
    *(.scommon)
    _bss_end = .;
  } > sdram AT> flash : bss

  _stack_top = ORIGIN(sram);

  _stack_pointer = ORIGIN(sram) + LENGTH(sram);


  . = ORIGIN(psram);
  _heap_start = .;
  . = ORIGIN(psram) + LENGTH(psram);
  _heap_end = .;

/*   end = .; */
/*   _end = .; */
}
