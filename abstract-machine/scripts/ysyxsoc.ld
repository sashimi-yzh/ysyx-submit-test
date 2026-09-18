ENTRY(_start)

MEMORY {
  flash : ORIGIN = 0x30000000, LENGTH = 16M
  sram  : ORIGIN = 0x0f000000, LENGTH = 8K
  psram : ORIGIN = 0x80000000, LENGTH = 4M
  sdram : ORIGIN = 0xa0000000, LENGTH = 32M
}

SECTIONS {
  . = _pmem_start + _entry_offset;

  .entry : {
    KEEP(*(entry))
  } > flash

  _ssbl_vma = ORIGIN(sram);
  .ssbl _ssbl_vma : {
    *(ssbl)
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

  .data . : {
    /* RT-Thread: FSymTab, VSymTab, init, utest */
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
    /*********************************************/

    *(.data*)
    *(.sdata*)
    _copy_end = .;
  } > sdram AT> flash

  edata = .;
  _data = .;

  .bss : {
    _bss_start = .;

    /***** RT-Thread bss (am_apps) *****/
    . = ALIGN(8);
    __am_apps_bss_start = .;
    *(__am_apps.bss*)
    *(__am_apps.sbss*)
    *(__am_apps.scommon*)
    __am_apps_bss_end = .;
    . = ALIGN(8);
    /**********************************/

    *(.bss*)
    *(.sbss*)
    *(.scommon)
  } > sdram

  _heap_start = ALIGN(0x1000);
  _heap_end = ORIGIN(sdram) + LENGTH(sdram);

  _stack_top = ORIGIN(sram);
  . = _stack_top + LENGTH(sram);
  _stack_pointer = .;

  end = .;
  _end = .;
}
