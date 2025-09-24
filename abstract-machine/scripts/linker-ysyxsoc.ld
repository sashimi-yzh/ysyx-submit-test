ENTRY(_start)
PHDRS {
  text_fsbl   PT_LOAD FLAGS(5);
  text_ssbl   PT_LOAD FLAGS(5);
  text_sdram  PT_LOAD FLAGS(5);
  rodata      PT_LOAD FLAGS(5);
  data        PT_LOAD FLAGS(6);
  bss         PT_LOAD FLAGS(6);
}

MEMORY {
  mrom  : ORIGIN = 0x20000000, LENGTH = 4K
  flash : ORIGIN = 0x30000000, LENGTH = 16M
  sram  : ORIGIN = 0x0f000000, LENGTH = 8K
  psram : ORIGIN = 0x80000000, LENGTH = 4M
  sdram : ORIGIN = 0xa0000000, LENGTH = 64M
}

SECTIONS {
  /* _flash and _entry_offset are defined in LDFLAGS */
  . = _flash_start + _entry_offset;

  /* ==================== 代码段 ==================== */
  .fsbl : {
    . = ALIGN(4);
    *(entry)
    *(.fsbl*)
    . = ALIGN(4);
  } > flash AT> flash : text_fsbl


  _ssbl_load_start = LOADADDR(.ssbl);
  .ssbl : {
    _ssbl_start = .;
    . = ALIGN(4);
    *(.ssbl*)
    . = ALIGN(4);
    _ssbl_end = .;
  } > sdram AT> flash : text_ssbl
  _ssbl_size = SIZEOF(.ssbl);

  _text_load_start = LOADADDR(.text);
  .text : {
    _text_start = .;
    *(.text*)
    . = ALIGN(4);
    _text_end = .;
  } > sdram AT> flash : text_sdram
  etext = .;
  _etext = .;
  _text_size = SIZEOF(.text);

  /* ==================== 数据段 ==================== */
  _rodata_load_start = LOADADDR(.rodata);
  .rodata : {
    _rodata_start = .;
    . = ALIGN(4);
    *(.rodata*)
    *(.srodata*)
    . = ALIGN(4);
    _rodata_end = .;
  } > sdram AT> flash : rodata
  _rodata_size = SIZEOF(.rodata);

  _data_load_start = LOADADDR(.data);
  .data : {
    _data_start = .;
    *(.data*)
    *(.sdata*)

    /* section information for finsh shell */
    __fsymtab_start = .;
    KEEP(*(FSymTab))
    __fsymtab_end = .;
    . = ALIGN(4);
    __vsymtab_start = .;
    KEEP(*(VSymTab))
    __vsymtab_end = .;
    . = ALIGN(4);

    /* section information for initial. */
    . = ALIGN(4);
    __rt_init_start = .;
    KEEP(*(SORT(.rti_fn*)))
    __rt_init_end = .;
    . = ALIGN(4);

    __rt_utest_tc_tab_start = .;
    KEEP(*(UtestTcTab))
    __rt_utest_tc_tab_end = .;

    . = ALIGN(4);
    __am_apps_data_start = .;
    *(__am_apps.data*)
    *(__am_apps.sdata*)
    __am_apps_data_end = .;
    _data_end = .;
  } > sdram AT> flash : data
  edata = .;
  _data = .;
  _data_size = SIZEOF(.data);

  .bss : {
	  _bss_start = .;
    *(.bss*)
    *(.sbss*)
    *(.scommon)
    . = ALIGN(4);
    __am_apps_bss_start = .;
    *(__am_apps.bss*)
    *(__am_apps.sbss*)
    *(__am_apps.scommon*)
    __am_apps_bss_end = .;
    _bss_end = .;
  }  > sdram AT> flash : bss
  _bss_size =  SIZEOF(.bss);

  /* ==================== 栈和堆 ==================== */
  . = _sram_start;
  _stack_top = ALIGN(0x10);
  . = _stack_top + 0x2000;
  _stack_pointer = .;

  . = _bss_start + _bss_size;
  _heap_start = ALIGN(0x10);
}
