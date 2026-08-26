ENTRY(_start)

MEMORY
{
  /* 指令空间：0x80000000 ~ 0x80003FFF (16KB) */
  imem (rx)  : ORIGIN = 0x80000000, LENGTH = 16K
  /* 数据空间：0x80100000 ~ 0x8013FFFF (128KB) */
  dmem (rw)  : ORIGIN = 0x80100000, LENGTH = 128K
}

SECTIONS
{
  .text : {
    *(entry)
    *(.text*)
  } > imem

  .rodata : {
    *(.rodata*)
    *(.srodata*)
  } > dmem

  .data : {
    *(.data*)
  } > dmem

  .bss : {
    _bss_start = .;
    *(.bss*)
    *(.sbss*)
    *(.scommon)
  } > dmem

  _stack_top = ALIGN(0x1000);
  . = _stack_top + 0x8000;
  _stack_pointer = .;
  end = .;
  _end = .;
  _heap_start = ALIGN(0x1000);

  /DISCARD/ : { *(.comment) *(.note*) *(.eh_frame) }
}
