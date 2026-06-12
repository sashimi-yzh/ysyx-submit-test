ENTRY(_start)

/* PHDRS { text PT_LOAD; data PT_LOAD; } */

SECTIONS {
  .xiptext : ALIGN_WITH_INPUT SUBALIGN(4) {
    *(entry)
    *(.fsbl)
    . = ALIGN(4);
  } >ROM AT>ROM

  /* Fast RAM load start */
  _fastram_load_start = LOADADDR(.fasttext);
  _fastram_start = ADDR(.fasttext);
  .fasttext : ALIGN_WITH_INPUT SUBALIGN(4) {
    *(.ssbl)
    . = ALIGN(4);
  } >FASTRAM AT>ROM
  _fastram_end = .;
  _fastram_size = _fastram_end - _fastram_start;
  /* Fast RAM load end */

  /* Load start */
  _data_load_start = LOADADDR(.text);
  _data_start = ADDR(.text);
  .text : ALIGN_WITH_INPUT {
    *(.text*)
    . = ALIGN(4);
  } >RAM AT>ROM

  .rodata : ALIGN_WITH_INPUT {
    *(.rodata*)
    *(.srodata*)
    . = ALIGN(4);
  } >RAM AT>ROM

  .data : ALIGN_WITH_INPUT {
    *(.data*)
    . = ALIGN(4);
  } >RAM AT>ROM

  .sdata : ALIGN_WITH_INPUT {
    . = ALIGN(16);
    /* __global_pointer$ = . + 0x800; */
    *(.sdata*)
    . = ALIGN(4);
  } >RAM AT>ROM
  _data_end = .;
  _data_size = _data_end - _data_start;
  /* Load end */

  /* Clear start */
	_bss_start = ADDR(.sbss);
  .sbss : {
    *(.sbss*)
    *(.scommon)
    . = ALIGN(4);
  } >RAM

  .bss : {
    *(.bss*)
    *(COMMON)
    . = ALIGN(4);
  } >RAM
  _bss_end = .;
  _bss_size = _bss_end - _bss_start;
  /* Clear end */

  . = ALIGN(16);
  _heap_start = .;
  . = (ORIGIN(RAM) + LENGTH(RAM)) & ~(16 - 1);
  _heap_end = .;
  /* _stack_pointer = .; */
  _stack_pointer = (ORIGIN(FASTRAM) + LENGTH(FASTRAM)) & ~(16 - 1);

  /* _stack_top = ALIGN(16); */
  /* . = _stack_top + 0x1000; */
  /* _stack_pointer = .; */
  /* Clear start */
  /* _heap_start = ALIGN(16); */
  /* . = (ORIGIN(SRAM) + LENGTH(SRAM)) & ~(16 - 1); */
  /* _heap_end = .; */
}
