ENTRY(_start)
/* PHDRS { text PT_LOAD; data PT_LOAD; } */

MEMORY {
  mrom : ORIGIN = 0x20000000, LENGTH = 4K
  sram : ORIGIN = 0x0f000000, LENGTH = 8K
	flash : ORIGIN = 0x30000000, LENGTH = 16M
	psram : ORIGIN = 0x80000000, LENGTH = 4M
	sdram : ORIGIN = 0xa0000000, LENGTH = 32M

	/* flash */
	/* load_region : ORIGIN = 0x30000000, LENGTH = 1M */

	/* sdram */
	runtime : ORIGIN = 0xa0000000, LENGTH = 32M

	/* psram */
	/* runtime : ORIGIN = 0x80000000, LENGTH = 4M */
}

SECTIONS {
	. = ORIGIN(flash);

	.boot : {
		_boot_start = .;
		*(entry)
		*(.fsbl_text)
		_boot_end = .;
	} > flash AT> flash

	.secondary_boot : {
		_ssbl_start = .;
		*(.ssbl_text)
		_ssbl_end = .;
	} > sram AT> flash

	__ssbl_load_start__ = LOADADDR(.secondary_boot);
	__ssbl_size__       = SIZEOF(.secondary_boot);

	/* .psram_padding (NOLOAD) : { */
	/* 		. = ORIGIN(psram) + SIZEOF(.boot) + 4; */
	/* } > psram */

	/* .text_padding (NOLOAD) : { */
	/* 	. = ORIGIN(runtime) + 8; */
	/* } > runtime */

  .text : {
		_text_start = .;
    *(.text*)
		_text_end = .;
  } > runtime AT> flash

	__text_load_start__ = LOADADDR(.text); /* flash addr */
	__text_size__       = SIZEOF(.text);   /* LEN */

  .rodata : {
		_rodata_start = .;
    *(.rodata*)
		*(.srodata*)
		_rodata_end = .;
  } > runtime AT> flash

	__rodata_load_start__ = LOADADDR(.rodata);
	__rodata_size__       = SIZEOF(.rodata);

	PROVIDE(_data_extra_start = .);
	PROVIDE(__data_extra_load_start__ = .);
  PROVIDE(__data_extra_size__ = 0);
	_data_extra_end = . + __data_extra_size__;

  .data : ALIGN(4) {
		_data_start = .;
    *(.sdata*)
    *(.data*)
		_data_end = .;
  } > runtime AT> flash

	__data_load_start__ = LOADADDR(.data); /* MA */
	__data_size__       = SIZEOF(.data);   /* LEN */

  .bss : ALIGN(4) {
		_bss_start = .;
    *(.bss*)
    *(.sbss*)
    *(.scommon)
		_bss_end = .;
  } > runtime

	__bss_size__ = SIZEOF(.bss);

	PROVIDE(_bss_extra_start = .);
	PROVIDE(__bss_extra_size__ = 0);
	_bss_extra_end = . + __bss_extra_size__;


	__sram_start__ = ORIGIN(sram);
	__sram_size__ = LENGTH(sram);
	__sram_end__ = __sram_start__ + __sram_size__;

	__psram_start__ = ORIGIN(psram);
	__psram_size__ = LENGTH(psram);
	__psram_end__ = __psram_start__ + __psram_size__;

	__sdram_start__ = ORIGIN(sdram);
	__sdram_size__ = LENGTH(sdram);
	__sdram_end__ = __sdram_start__ + __sdram_size__;

	__runtime_addr_start__ = ORIGIN(runtime);
	__runtime_addr_end__ = ORIGIN(runtime) + LENGTH(runtime);

  _stack_top = __sram_end__;
  _stack_pointer  = _stack_top;

  _heap_start = _bss_end;
	_heap_end = __runtime_addr_end__;
}
