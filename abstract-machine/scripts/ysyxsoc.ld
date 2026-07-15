ENTRY(_fsbl)
PHDRS {fsbl PT_LOAD; ssbl PT_LOAD; text PT_LOAD; rodata PT_LOAD; data PT_LOAD; bss PT_NULL; }

MEMORY {
  mrom : ORIGIN = 0x20000000, LENGTH = 4K
  flash : ORIGIN = 0x30000000, LENGTH = 16M
  psram : ORIGIN = 0x80000000, LENGTH = 4M
  sram : ORIGIN = 0x0f000000, LENGTH = 8K
  sdram : ORIGIN = 0xa0000000, LENGTH = 32M
}

SECTIONS {
  .fsbl : ALIGN(8) {
    _sfsbl = .;
    *(fsbl)
  } > flash AT > flash :fsbl
  _efsbl = .;

  .ssbl : ALIGN(8) {
    _sssbl = .;
    *(ssbl)
  } > sram AT > flash :ssbl
  _essbl = .;

  .text : ALIGN(8){
    _stext = .;
    *(entry)
    *(.text*)
  } > sdram AT > flash :text
  _etext = .;

  .rodata : ALIGN(8){
    _srodata = .;
    *(.rodata*)
    *(.srodata*)
  } > sdram AT > flash :rodata
  _erodata = .;

  .data : ALIGN(8){
    _sdata = .;
    *(.data*)
    *(.sdata*)
  } > sdram AT > flash :data
  .data.extra : ALIGN(8){
    /* section information for finsh shell */
    __fsymtab_start = .;
    KEEP(*(FSymTab))
    __fsymtab_end = .;
    . = ALIGN(8);
    __vsymtab_start = .;
    KEEP(*(VSymTab))
    __vsymtab_end = .;
    . = ALIGN(8);

    /* section information for initial. */
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
  } > sdram AT > flash :data
  _edata = .;

  .bss : ALIGN(8){
    _sbss = .;
    *(.bss*)
    *(.sbss*)
    *(.scommon)
  } > sdram AT > flash :bss

  .bss.extra : ALIGN(8){
    . = ALIGN(8);
    __am_apps_bss_start = .;
    *(__am_apps.bss*)
    *(__am_apps.sbss*)
    *(__am_apps.scommon*)
    __am_apps_bss_end = .;
    . = ALIGN(8);
  } > sdram AT > flash :bss

  _ebss = .;

  _heap_start = ALIGN(0x1000);

  . = ORIGIN(sram) + LENGTH(sram);
  _stack_pointer = .;
  
  _ssbl_lma = LOADADDR(.ssbl);
  _text_lma = LOADADDR(.text);
  _rodata_lma = LOADADDR(.rodata);
  _data_lma = LOADADDR(.data);
  _bss_lma = LOADADDR(.bss);
}
