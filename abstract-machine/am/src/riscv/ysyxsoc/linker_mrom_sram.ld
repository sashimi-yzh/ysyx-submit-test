ENTRY(_start)
MEMORY {
  mrom : ORIGIN = 0x20000000, LENGTH = 4K
  sram : ORIGIN = 0x0f000000, LENGTH = 8K
}

SECTIONS {
  /* _pmem_start and _entry_offset are defined in LDFLAGS */
 /* . = _pmem_start + _entry_offset; */
  . = ORIGIN(mrom);
  .text : {
    *(entry)
    *(.text*)
  } > mrom AT> mrom
  etext = .;
  _etext = .;
  .rodata : {
    *(.rodata*)
    _rodata_end = .;
  } > mrom AT> mrom
  .data : {
    *(.data)
  } > sram AT> mrom
  _data_lma_start = LOADADDR(.data);
  _data_lma_end   = .;
  _data_vma_start = ORIGIN(sram);
  edata = .;
  .bss : {
	_bss_start = .;
    *(.bss*)
    *(.sbss*)
    *(.scommon)
  } > sram AT> mrom
  _stack_top = 0x0f001400;
  . = _stack_top + 0x00000400;
  _stack_pointer = .;
  end = .;
  _end = .;
  _heap_start = 0x0f001000;
  _heap_end   = 0x0f001400;
}