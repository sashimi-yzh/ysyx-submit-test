ENTRY(_start)

PHDRS {
  text       PT_LOAD;
  data       PT_LOAD;
  fsbl       PT_LOAD;
  bootloader PT_LOAD;
  rodata     PT_LOAD;
  data_ext   PT_LOAD;
  bss_ext    PT_LOAD;
  bss        PT_LOAD;
}

MEMORY {
  mrom(rx)   : ORIGIN = 0x20000000, LENGTH = 4K
  sram(rwx)  : ORIGIN = 0x0f000000, LENGTH = 8K
  flash(rx)  : ORIGIN = 0x30000000, LENGTH = 16M
  psram(rwx) : ORIGIN = 0x80000000, LENGTH = 4M
  sdram(rwx) : ORIGIN = 0xa0000000, LENGTH = 64M
}

SECTIONS {

  . = ORIGIN(flash);

  .fsbl :{
  . = ALIGN(8);
   *(entry)
    *(.fsbl*)
    . = ALIGN(8);
  } > flash :fsbl

  . = ALIGN(8);
  _bootloader_src = LOADADDR(.bootloader);

  .bootloader :{
    . = ALIGN(8);
    _siflash_ssbl = .;
    *(.bootloader*)
    _eiflash_ssbl = .;
    . = ALIGN(8);
  } > sdram AT> flash : bootloader

  . = ALIGN(8);
  _text_src = LOADADDR(.text);

  .text : {
    . = ALIGN(8);
    _text_start = .;
    *(.text*)
    *(.text.*)
    _text_end = .;
    . = ALIGN(8);
  } > sdram AT> flash : text

  . = ALIGN(8);
  etext = .;
  _etext = .;

  .rodata : {
    . = ALIGN(8);
    _rodata_start = .;
    *(.rodata*)
    *(.srodata*)
    _rodata_end = .;
    . = ALIGN(8);
  } > sdram AT> flash : rodata

  _rodata_src = LOADADDR(.rodata);
  
. = ALIGN(8);
  _data_src = LOADADDR(.data);

   .data.extra : {
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
  }> sdram AT> flash : data_ext

  .data : {
  . = ALIGN(8);
    _data_start = .;
    *(.data*)
    *(.data.*)
    *(.sdata*)
    _data_end = .;
    . = ALIGN(8);
  } > sdram AT>flash : data


  . = ALIGN(8);
  edata = .;
  _data = .;

  .bss.extra : {
    _bss_start = .;
    . = ALIGN(8);
    __am_apps_bss_start = .;
    *(__am_apps.bss*)
    *(__am_apps.bss.*)
    *(__am_apps.sbss*)
    *(__am_apps.scommon*)
    __am_apps_bss_end = .;
    . = ALIGN(8);
  }> sdram AT> flash : bss_ext


  .bss : {
    . = ALIGN(8);
    *(.bss*)
    *(.bss.*)
    *(.sbss*)
    *(.scommon)
    . = ALIGN(8);
    _bss_end = .;
  } > sdram AT> flash : bss

  _stack_top = ORIGIN(sram);

  _stack_pointer = ORIGIN(sram) + LENGTH(sram);


  . = ORIGIN(psram);
  _heap_start = .;
  . = ORIGIN(psram) + LENGTH(psram);
  _heap_end = .;

/*   end = .; */
/*   _end = .; */
}

