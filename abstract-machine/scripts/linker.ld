ENTRY(_start)
PHDRS {
  fsboot PT_LOAD;
  nopsection PT_LOAD;
  ssboot PT_LOAD;
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
  .fsboot : ALIGN(4) {
    KEEP(*start.o(.fsboot))
    KEEP(*(.fsboot))
    . = ALIGN(4);
  } > FLASH : fsboot

  .nopsection : ALIGN(4) {
    _nopsection_start = .;
    KEEP(*(.nopsection))
    . = ALIGN(4);
    _nopsection_end = .;
  } > FLASH : nopsection

  .ssboot : ALIGN(4) {
    _ssboot_start = .;
    KEEP(*(.ssboot))
    . = ALIGN(4);
    _essboot = .;
    _ssboot_lma = LOADADDR(.ssboot);
  }> SDRAM AT > FLASH : ssboot

  /* _pmem_start and _entry_offset are defined in LDFLAGS */
  .text : ALIGN(4) {
    _text_start = .;
    *(entry)
    *(.text*)
    etext = .;
    . = ALIGN(4);
    _etext = .;
    _text_lma = LOADADDR(.text);
  } > SDRAM AT > FLASH : text

  .rodata : ALIGN(4) {
    _rodata_start = .;
    *(.rodata*)
    *(.srodata*)
    erodata = .;
    . = ALIGN(4);
    _erodata = .;
    _rodata_lma = LOADADDR(.rodata);
  } > FLASH : rodata

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
  } > SDRAM AT > FLASH : data

  .bss (NOLOAD): ALIGN(4) {
    _bss_start = .;
    *(.bss*)
    *(.sbss*)
    *(.scommon)
    _bss_end = .;
  } > SDRAM

  /* For Testing purpose in test code */
  /*
  .dload_in_sram (NOLOAD): ALIGN(4) {
        _sram_code_start = .;
        . = . + 1K;
        _sram_code_end = .;
  } > SRAM
 */

  _heap_start = _bss_end;

 .stack (NOLOAD): ALIGN(4) {
    _stack_top = ORIGIN(SRAM);
    _stack_size = LENGTH(SRAM);    /* 8KB */
    . = _stack_top + _stack_size;  /* Define stack size as 8KB */
    _stack_pointer = .;
  } > SRAM

  end = .;
  _end = .;

}
