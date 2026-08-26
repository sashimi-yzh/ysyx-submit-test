ENTRY(_start)

MEMORY
{
  /* 指令空间：0x20000000 ~ 0x20000FFF (4KB) */
  mrom (rx)  : ORIGIN = 0x20000000, LENGTH = 4K
  /* 数据空间：0x0f000000 ~ 0x0f001FFF (8KB) */
  sram (rw)  : ORIGIN = 0x0f000000, LENGTH = 8K
}

SECTIONS
{
  .text : {
    *(entry)
    *(.text*)
  } > mrom

  .rodata : {
    *(.rodata*)
    *(.srodata*)
  } > mrom

  .data : {
    *(.data*)
    *(.sdata*)
  } > mrom

  .bss : {
    _bss_start = .;
    *(.bss*)
    *(.sbss*)
    *(.scommon)
  } > sram

  _stack_top = ALIGN(0x1000);
  . = _stack_top + 0x2000;
  _stack_pointer = .;
  end = .;
  _end = .;
  _heap_start = .;
  ASSERT(. <= ORIGIN(sram) + LENGTH(sram), "Error: sram overflow!")
  _heap_end = ORIGIN(sram) + LENGTH(sram);
  _sram_start = ORIGIN(sram);
  /DISCARD/ : { *(.comment) *(.note*) *(.eh_frame) }
}
