ENTRY(_start)

MEMORY {
  mrom (rx): ORIGIN = 0x20000000, LENGTH = 4K
  flash (rx): ORIGIN = 0x30000000, LENGTH = 0x01000000
  sram (rwx): ORIGIN = 0x0f000000, LENGTH = 8K
  psram (rwx): ORIGIN = 0x80000000, LENGTH = 4M
}
SECTIONS {
  /* _pmem_start and _entry_offset are defined in LDFLAGS */
  . = _pmem_start + _entry_offset;
  .entry : {
    _entry_start = .;
    KEEP(*(.entry))
  } > flash
  .text : {
    *(entry)
    *(.text*)
  } > flash 
  _etext = .;
  . = ALIGN(4);
  .rodata  :ALIGN(4) {
    *(.rodata*)
  } > flash
  _erodata = .;
  _lma_data_start = LOADADDR (.data);
  . = ALIGN(4);
  .data : {
    _data_start = .;
    *(.data)
  }  > psram AT> flash
  . = . ;
  _data_end = . ;
  .bss :  {
	  _bss_start = .;
    *(.bss*)
    *(.sbss*)
    *(.scommon)
  } > psram AT> flash
  _bss_end = .;
  _heap_start = ALIGN(0x1000);
  _stack_top =  ALIGN(0x1000) ;
  . = _stack_top + 0x1000;
  _stack_pointer = .;
  end = .;
  _end = .;
}
