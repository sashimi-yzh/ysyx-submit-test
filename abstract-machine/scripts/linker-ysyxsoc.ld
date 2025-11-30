ENTRY(_start)
PHDRS { entry PT_LOAD; ssbl PT_LOAD; text PT_LOAD; rodata PT_LOAD; data PT_LOAD; }

MEMORY {
	flash (rx): ORIGIN = 0x30000000, LENGTH = 16M
  sdram (wrx): ORIGIN = 0xa0000000, LENGTH = 32M
	sram (wrx): ORIGIN = 0x0f000000, LENGTH = 2K
}

SECTIONS {
  /* _pmem_start and _entry_offset are defined in LDFLAGS /0x20000000/*/
  . = ORIGIN(flash);
  .entry : {
		*(entry)
		*(.text._trm_init)
		*(.text.uart_init)
		*(.text.idcsrs_init)
		*(.text.bootloader_fsbl)
	} > flash AT > flash : entry
	
	.ssbl : {
		ssbl_vma_start = .;
		*(.text.bootloader_ssbl)
	} > sram AT > flash : ssbl
	ssbl_size = SIZEOF(.ssbl);
	ssbl_lma_start = LOADADDR(.ssbl);
	
	. = ALIGN(4);
	.text : ALIGN(4) {
		*(.text*)
		. = ALIGN(16);
		*(.text.hot)
		. = ALIGN(4);
  } > sdram AT > flash : text
  etext = .;
  _etext = .;
	text_lma_start = LOADADDR(.text);
	text_size = SIZEOF(.text);

	. = ALIGN(4);
	.rodata : ALIGN(4) {
		rodata_vma_start = .;
    *(.rodata*)
		*(.srodata*)
		. = ALIGN(4);
  } > sdram AT > flash : rodata
	rodata_size = SIZEOF(.rodata);
	rodata_lma_start = LOADADDR(.rodata);

	.data : ALIGN(4) {
		data_vma_start = .;
		*(.data*)
		*(.sdata*)
		. = ALIGN(4);

    __fsymtab_start = .;
    KEEP(*(FSymTab))
    __fsymtab_end = .;
    . = ALIGN(8);
    __vsymtab_start = .;
    KEEP(*(VSymTab))
    __vsymtab_end = .;
    . = ALIGN(8);

		. = ALIGN(8);
		__rt_init_start = .;
    KEEP(*(SORT(.rti_fn*)))
    __rt_init_end = .;
    . = ALIGN(8);

    __rt_utest_tc_tab_start = .;
    KEEP(*(UtestTcTab))
    __rt_utest_tc_tab_end = .;

    . = ALIGN(8);
    __am_apps_data_start = .;
    *(__am_apps.data*)
    *(__am_apps.sdata*)
    __am_apps_data_end = .;
    . = ALIGN(8);
	} > sdram AT > flash : data
	data_size = SIZEOF(.data);
	data_lma_start = LOADADDR(.data);

	.bss : ALIGN(4) {
		bss_vma_start = .;
		*(.bss*)
    *(.sbss*)
    *(.scommon)
		. = ALIGN(4);
    __am_apps_bss_start = .;
    *(__am_apps.bss*)
    *(__am_apps.sbss*)
    *(__am_apps.scommon*)
    __am_apps_bss_end = .;
    . = ALIGN(8);
  } > sdram AT > flash
	bss_size = SIZEOF(.bss);
  bss_lma_start = LOADADDR(.bss);

	. = ORIGIN(sram);
  _stack_top = ALIGN(0X10);
  . = _stack_top + 0x2000;
  _stack_pointer = .;

	end = .;
  _end = .;
	_heap_start = bss_vma_start + SIZEOF(.bss);
	_heap_end = ORIGIN(sdram) + LENGTH(sdram);
}
