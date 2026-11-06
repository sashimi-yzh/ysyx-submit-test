ENTRY(_start)

MEMORY {
  mrom (r x): ORIGIN = 0x20000000, LENGTH = 4K
  flash(r x): ORIGIN = 0x30000000, LENGTH = 16M
  psram(rwx): ORIGIN = 0x80000000, LENGTH = 4M
  sdram(rwx): ORIGIN = 0xa0000000, LENGTH = 64M
  sram (rwx): ORIGIN = 0x0f000000, LENGTH = 8K
}

SECTIONS {
  . = _pmem_start + _entry_offset;

  .entry : {
    KEEP(*(entry))
  } > flash

  _ssbl_vma = ORIGIN(sram);
  .ssbl _ssbl_vma : {
    *(SSBL)
    _ssbl_end = .;
  } > sram AT> flash
  _ssbl_lma = LOADADDR(.ssbl);

  _copy_vma = ORIGIN(sdram);
  . = _copy_vma;

  .text : {
    *(.text*)
    . = ALIGN(., 8);
  } > sdram AT> flash
  _copy_lma = LOADADDR(.text);

  etext = .;
  _etext = .;

  .rodata . : {
    *(.rodata*)
    *(.srodata*)
    . = ALIGN(., 8);
  } > sdram AT> flash

/***********************/
  /* INCLUDE extra.ld; */

  .data . : {
    __fsymtab_start = .;
    KEEP(*(FSymTab))
    __fsymtab_end = .;
    . = ALIGN(8);
    __vsymtab_start = .;
    KEEP(*(VSymTab))
    __vsymtab_end = .;
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

    *(.data*)
    *(.sdata*)
    _copy_end = .;
  } > sdram AT> flash

  edata = .;
  _data = .;

  .bss :  {
    . = ALIGN(8);
	  _bss_start = .;
    . = ALIGN(8);
    __am_apps_bss_start = .;
    *(__am_apps.bss*)
    *(__am_apps.sbss*)
    *(__am_apps.scommon*)
    __am_apps_bss_end = .;
    . = ALIGN(8);

    *(.bss*)
    *(.sbss*)
    *(.scommon)
    . = ALIGN(8); 
    _bss_end = .;
  } > sdram

  _heap_start = ORIGIN(psram);
  _heap_end = ORIGIN(psram) + LENGTH(psram);

  _stack_top = ORIGIN(sram) + LENGTH(sram);
  _stack_pointer = _stack_top;
  _stack_bottom = ORIGIN(sram);

  end = .;
  _end = .;
}
