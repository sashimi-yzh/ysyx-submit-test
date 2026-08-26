ENTRY(_start)

MEMORY
{
  mrom  : ORIGIN = 0x20000000, LENGTH = 4
  /* 指令空间：0x30000000 ~ 0x31000000 (16MB) */
  flash : ORIGIN = 0x30000000, LENGTH = 16M
  /* 数据空间：0x0f000000 ~ 0x0f002000 (8KB) */
  sram : ORIGIN = 0x0f000000, LENGTH = 8K
  /* 数据空间：0x80000000 ~ 0x80400000 (4MB) */
  psram : ORIGIN = 0x80000000, LENGTH = 4M
  /* 数据空间：0xa0000000 ~ 0xa8000000 (128MB)*/
  sdram : ORIGIN = 0xa0000000, LENGTH = 128M
}


SECTIONS
{
  . = ORIGIN(flash);
  .flash : {
    *(entry)
    . = ALIGN(4);
  } > flash AT> flash

  . = ORIGIN(sram);
  _ssbl_vma_start = .;
  .ssbl : {
    *(ssbl)
    . = ALIGN(4);
    _ssbl_vma_end = .;
  } > sram AT> flash
  _ssbl_lma_start = LOADADDR(.ssbl);
  _ssbl_lma_size = SIZEOF(.ssbl);
  _ssbl_lma_end = _ssbl_lma_start + _ssbl_lma_size;

  . = ORIGIN(sdram);
  _text_vma_start = .;
  .text : {
    . = ALIGN(4);
    *(.text*)
    . = ALIGN(4);
    _text_vma_end = .;
  } > sdram AT> flash
  _text_lma_start = LOADADDR(.text);
  _text_lma_size = SIZEOF(.text);
  _text_lma_end = _text_lma_start + _text_lma_size;

  .rodata : {
    . = ALIGN(4);
    _rodata_vma_start = .;
    *(.rodata*)
    *(.srodata*)
    . = ALIGN(4);
    _rodata_vma_end = .;
  } > sdram AT> flash
  _rodata_lma_start = LOADADDR(.rodata);
  _rodata_lma_size = SIZEOF(.rodata);
  _rodata_lma_end = _rodata_lma_start + _rodata_lma_size;



  .data : {
    . = ALIGN(4);
    _data_vma_start = .;
    *(.data*)
    *(.sdata*)
    . = ALIGN(4);
    _data_vma_end = .;
  } > sdram AT> flash
  _data_lma_start = LOADADDR(.data);
  _data_lma_size = SIZEOF(.data);
  _data_lma_end = _data_lma_start + _data_lma_size;

  .bss : {
    . = ALIGN(4);
    _bss_vma_start = .;
    *(.bss*)
    *(.sbss*)
    *(.scommon)
    . = ALIGN(4);
    _bss_vma_end = .;
  } > sdram AT>flash
  _bss_lma_start = LOADADDR(.bss);
  _bss_lma_size = SIZEOF(.bss);
  _bss_lma_end = _bss_lma_start + _bss_lma_size;

  . = ALIGN(0x10000);

  _heap_start = .;
  . = _heap_start + 0x2000000;
  _heap_end = .;

  . = ORIGIN(sram);
  . = ALIGN(0x0004);
  _sram_start = .;
  _stack_top = .;
  _stack_pointer = . + 0x1ffc;
  . = _stack_pointer;
  end = .;
  _end = .;
  
  ASSERT(. <= ORIGIN(sram) + LENGTH(sram), "Error: sram overflow!")
  
  /DISCARD/ : { *(.comment) *(.note*) *(.eh_frame) }
}
