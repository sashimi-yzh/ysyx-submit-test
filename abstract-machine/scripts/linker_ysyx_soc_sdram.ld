ENTRY(_start)

MEMORY {
  mrom (rx): ORIGIN = 0x20000000, LENGTH = 4K
  flash (rx): ORIGIN = 0x30000000, LENGTH = 0x10000000
  sram (rwx): ORIGIN = 0x0f000000, LENGTH = 8K
  psram (rwx): ORIGIN = 0x80000000, LENGTH = 32M
  sdram (rwx): ORIGIN = 0xa0000000, LENGTH = 128M
}
SECTIONS {
  /* _pmem_start and _entry_offset are defined in LDFLAGS */
  /* . = _pmem_start + _entry_offset;  */
  .entry : {
    _entry_start = .;
    KEEP(*(.entry))
  } > flash
  .first_boost : {
    _first_boost_start = .;
    KEEP(*(.first_boost))
  } > flash

  _lma_sec_boost_start = LOADADDR (.sec_boost);
  .sec_boost : {
    _sec_boost_start = .;
    KEEP(*(.sec_boost))
    KEEP(*(.bootutils))
  } > sram AT> flash
  _sec_boost_end = .;

  _lma_code_start = LOADADDR (.text);
  .text : {
    _text_start = .;
    KEEP(*(.text._trm_init))
    *(.text*)
  } > sdram AT> flash
  _etext = .;

  _lma_rodata_start = LOADADDR (.rodata);
  .rodata  :ALIGN(8) {
    *(.rodata*)
    *(.srodata*)
  } > sdram AT> flash
  _erodata = .;
  
  . = ALIGN(4);
  _lma_data_start = LOADADDR (.data);
  .data : ALIGN(4) { 
    _data_start = .;
    
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

    *(.data*)
    *(.data.*)
    *(.sdata.*)

  } > sdram AT> flash
  . = . ;
  _data_end = . ;
  
  .bss.extra : {
    . = ALIGN(8);
    _bss_start = .;
    __am_apps_bss_start = .;
    *(__am_apps.bss*)
    *(__am_apps.sbss*)
    *(__am_apps.scommon*)
    __am_apps_bss_end = .;
    . = ALIGN(8);
  } > sdram AT> flash
  .bss :  {
    *(.bss*)
    *(.sbss*)
    *(.scommon)
  } > sdram AT> flash
  _bss_end = .;
  _heap_start = ALIGN(0x2000000);
  . = 0x0f000000;
  _stack_top =  ALIGN(0x1000) ;
  . = 0x0f002000;
  _stack_pointer = .;
  end = .;
  _end = .;
}

