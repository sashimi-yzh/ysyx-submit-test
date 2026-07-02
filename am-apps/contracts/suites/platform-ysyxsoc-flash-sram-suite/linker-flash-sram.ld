ENTRY(_start)
MEMORY {
  flash (rx)  : ORIGIN = _pmem_start + _entry_offset, LENGTH = 0x1000000
  sram  (rwx) : ORIGIN = 0x0f000000, LENGTH = 0x2000
}
SECTIONS {
  . = ORIGIN(flash);
  .entry : { *(entry) } > flash
  . = ORIGIN(sram);
  _data_start = .;
  .data : AT(ALIGN(LOADADDR(.entry) + SIZEOF(.entry), 4)) {
    *(.text*) . = ALIGN(4); *(.rodata*) *(.srodata*) . = ALIGN(4); *(.data*) *(.sdata*) . = ALIGN(4);
  } > sram
  _data_end = .;
  _data_load_start = LOADADDR(.data);
  . = ALIGN(16);
  .bss : { _bss_start = .; *(.bss*) *(.sbss*) *(.scommon) *(COMMON) } > sram
  . = ALIGN(16);
  _bss_end = .;
  _heap_start = .;
  _stack_pointer = ORIGIN(sram) + LENGTH(sram);
  _heap_end = _stack_pointer - 0x400;
  ASSERT((LOADADDR(.data) + SIZEOF(.data)) <= (ORIGIN(flash) + LENGTH(flash)), "Flash overflow")
  ASSERT(_heap_start <= _heap_end, "SRAM overflow")
  end = .; _end = .;
}
