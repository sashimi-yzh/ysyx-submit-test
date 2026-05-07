ENTRY(_start)


MEMORY {
  flash : ORIGIN = 0x30000000, LENGTH = 256M
  sram : ORIGIN = 0x0f000000, LENGTH = 8K
  psram : ORIGIN = 0x80000000, LENGTH = 4M
  sdram : ORIGIN = 0xa0000000, LENGTH = 128M
}

SECTIONS {
  
  . = ORIGIN(flash);
  _pmem_start = .;

  .start :{
    *(entry)
  } > flash AT> flash 

  .fsbl :{
    . = ALIGN(4);
    _fsbl_start = .;
    *(.fsbl*)
  } > flash AT> flash 

  .bootloader :{
    . = ALIGN(4);
    _bootloader_start = .;
    *(.bootloader*)
    _bootloader_end = .;
  } > sdram AT> flash  

  _bootloader_lma_start = LOADADDR(.bootloader);

  

  .data :
  {
    . = ALIGN(4);
    _data_vma_start = .;
    *(.data)           /* 主要数据段 */
    *(.data*)         /* 数据子段 */
    *(.sdata)          /* 小数据段 */
    *(.sdata*)        /* 小数据子段 */
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
    _data_vma_end = .;
  } > sdram AT>flash

  _data_lma_start = LOADADDR(.data);

  .text : {
    . = ALIGN(4);
    _text_start = .;
    *(.text)
    *(.text*)
    *(.rodata*)
    *(.srodata)       
    *(.srodata*) 
    _text_end = .;
  } > sdram AT> flash 

  _text_lma_start = LOADADDR(.text);

  .bss :
  {
    *(.bss)
    *(.bss*)
    *(.sbss)
    *(.sbss*)
    . = ALIGN(8);
    __am_apps_bss_start = .;
    *(__am_apps.bss*)
    *(__am_apps.sbss*)
    *(__am_apps.scommon*)
    __am_apps_bss_end = .;
    . = ALIGN(8);
  } > sdram 
  
  
  /* 堆区在数据段和BSS段之后 */
  .heap : ALIGN(4) {
      _heap_start = .;
      . = . + 2M;        /* 16KB堆区 */
      _heap_end = .;
  } > sdram
  
  /* 栈区在SRAM末尾 */
  .stack : ALIGN(4) {
      _stack_top = .;
      . = . + 8K;         /* 4KB栈区 */
      _stack_pointer = .;
  } > sram
  
}
