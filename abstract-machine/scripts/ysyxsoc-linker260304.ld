ENTRY(_start)
PHDRS { text PT_LOAD; rodata PT_LOAD; data PT_LOAD;}

MEMORY {
  mrom (r x): ORIGIN = 0x20000000, LENGTH = 4K
  flash(r x): ORIGIN = 0x30000000, LENGTH = 16M
  psram(rwx): ORIGIN = 0x80000000, LENGTH = 4M
  sdram(rwx): ORIGIN = 0xa0000000, LENGTH = 64M
  sram (rwx): ORIGIN = 0x0f000000, LENGTH = 8K
}

SECTIONS {

  /* . = ORIGIN(flash); */

  .text : {
    _entry_start = .;
    *(entry) 
    _entry_end = .;
    *(.text.fsbl)
    _boot_loader_start = .;
    KEEP(*(.text.boot))
    _boot_loader_end = .;
    _text_start = .;
    *(.text*)
  } > sdram AT> flash : text

  etext = .;
  _etext = .;
  entry_lma_addr = LOADADDR(.text);
  boot_loader_lma_addr = entry_lma_addr - _entry_start + _boot_loader_start;
  text_lma_addr = entry_lma_addr - _entry_start + _boot_loader_end;
  sram_boot_loader_start = ORIGIN(sram);
  sram_boot_loader_end = ORIGIN(sram) + (_boot_loader_end - _boot_loader_start);

  
  /* _boot_loader_end = _boot_loader_start + SIZEOF(.text.boot); */

  /* . = ORIGIN(psram) + SIZEOF(.bootloader); */

  .rodata : ALIGN(4) {
    _rodata_start = .;
    *(.rodata*)
    *(.srodata*)
    *(.srodata.*)
    . = ALIGN(4);
    _rodata_end = .;
  } > sdram AT> flash : rodata
  _text_end = .;

/***********************/
  /* INCLUDE extra.ld; */

  .data : ALIGN(4) {
    _data_start = .;
    *(.data .data.*)
    *(.sdata .sdata.*)

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

    . = ALIGN(4);
    _data_end = .;
  } > sdram AT> flash : data

  rodata_lma_addr = LOADADDR(.rodata);
  data_lma_addr = LOADADDR(.data);
  edata = .;
  _data = .;

  .bss (NOLOAD) : {
	_bss_start = .;
    *(.sbss .sbss.*)
    *(.scommon)
    *(.bss .bss.*)
    /* *(.bss.extra) */
    . = ALIGN(8);
    __am_apps_bss_start = .;
    *(__am_apps.bss*)
    *(__am_apps.sbss*)
    *(__am_apps.scommon*)
    __am_apps_bss_end = .;
    . = ALIGN(8);
    
    _bss_end = .;
  } > sdram : data

  /* _heap_start = _bss_end; */
  _heap_start = ORIGIN(psram);
  _heap_end = ORIGIN(psram) + LENGTH(psram);

  _stack_top = ORIGIN(sram) + LENGTH(sram);
  _stack_pointer = _stack_top;
  _stack_bottom = ORIGIN(sram);

  _sram_start = ORIGIN(sram);


  
  end = .;
  _end = .;
}
