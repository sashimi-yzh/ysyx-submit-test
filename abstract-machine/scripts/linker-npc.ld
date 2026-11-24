ENTRY(_start)
PHDRS {
  text PT_LOAD;
  rodata PT_LOAD;
  data PT_LOAD;
}

MEMORY {
    SRAM : ORIGIN = 0x0f000000, LENGTH = 8K     /* SRAM region */
    MROM : ORIGIN = 0x20000000, LENGTH = 4K     /* ROM region */
    FLASH : ORIGIN = 0x30000000, LENGTH = 256M  /* FLASH region */
    PSRAM : ORIGIN = 0x80000000, LENGTH = 4M    /* PSRAM region */
    SDRAM : ORIGIN = 0Xa0000000, LENGTH = 32M   /* SDRAM regon */
}

SECTIONS {

  /* _pmem_start and _entry_offset are defined in LDFLAGS */
  .text : ALIGN(4) {
    _text_start = .;
    *(entry)
    *(.text*)
    etext = .;
    . = ALIGN(4);
    _etext = .;
    _text_lma = LOADADDR(.text);
  } > PSRAM : text

  .rodata : ALIGN(4) {
    _rodata_start = .;
    *(.rodata*)
    *(.srodata*)
    erodata = .;
    . = ALIGN(4);
    _erodata = .;
    _rodata_lma = LOADADDR(.rodata);
  } > PSRAM : rodata

  .data : ALIGN(4) {
    _data_start = .;
    *(.data*)
    *(.gnu.linkonce.d.*)
    *(.sdata*)
    *(.gnu.linkonce.s.*)
    edata = .;
    . = ALIGN(4);
    _data_end = .;
    _data_lma = LOADADDR(.data);
    _data_len = _data_end - _data_start;
  } > PSRAM : data

  .bss (NOLOAD): ALIGN(4) {
    _bss_start = .;
    *(.bss*)
    *(.sbss*)
    *(.scommon)
    _bss_end = .;
  } > PSRAM

  _heap_start = _bss_end;

 .stack (NOLOAD): ALIGN(4) {
    _stack_top = ORIGIN(PSRAM);
    _stack_size = LENGTH(PSRAM);
    . = _stack_top + _stack_size;   /* End of PSRAM */
    _stack_pointer = .;
  } > PSRAM

  end = .;
  _end = .;

}
