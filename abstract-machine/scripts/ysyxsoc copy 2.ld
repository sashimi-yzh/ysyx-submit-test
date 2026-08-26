ENTRY(_start)

MEMORY
{
  /* 指令空间：0x30000000 ~ 0x30100000 (1MB) */
  flash : ORIGIN = 0x30000000, LENGTH = 1M
  /* 数据空间：0x0f000000 ~ 0x0f001FFF (8KB) */
  sram : ORIGIN = 0x0f000000, LENGTH = 8K
  /* 数据空间：0x80000000 ~ 0x80400000 (4MB) */
  psram : ORIGIN = 0x80000000, LENGTH = 4M
}


SECTIONS
{
  . = ORIGIN(flash);
  .text : {
    *(entry)
    *(.text*)
  } > flash AT> flash


  .rodata : {
    _rodata_vma_start = .;
    *(.rodata*)
    *(.srodata*)
    . = ALIGN(4);
    _rodata_vma_end = .;
  } > flash AT> flash
  _rodata_lma_start = LOADADDR(.rodata);
  _rodata_lma_end = _rodata_lma_start + SIZEOF(.rodata);



  .data : {
    _data_vma_start = .;
    *(.data*)
    *(.sdata*)
    . = ALIGN(4);
    _data_vma_end = .;
  } > psram AT> flash
  _data_lma_start = LOADADDR(.data);
  _data_lma_end = _data_lma_start + SIZEOF(.data);

  .bss : {
    _bss_vma_start = .;
    *(.bss*)
    *(.sbss*)
    *(.scommon)
    . = ALIGN(4);
    _bss_vma_end = .;
  } > psram AT>flash
  _bss_lma_start = LOADADDR(.bss);
  _bss_lma_end = _bss_lma_start + SIZEOF(.bss);

  . = _bss_vma_end;
  . = ALIGN(0x010000);

  _heap_start = .;
  . = _heap_start + 0x200000;
  _heap_end = .;
  _stack_top = .;
  _stack_pointer = . + 0x100000;
  . = _stack_pointer;
  end = .;
  _end = .;
  
  ASSERT(. <= ORIGIN(psram) + LENGTH(psram), "Error: psram overflow!")
  _sram_start = ORIGIN(psram);
  /DISCARD/ : { *(.comment) *(.note*) *(.eh_frame) }
}
