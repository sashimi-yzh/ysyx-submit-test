/* 该脚本使用两级bootloader, 第一级引导加载程序将第二级引导加载程序加载到sram中, 跳转至sram中执行,
第二级引导加载程序将程序和数据加载到sdram中, 跳转至sdram中执行, 栈使用sram, 堆使用sdram. */

ENTRY(_start)

MEMORY {
    sram  (rwx)      : ORIGIN = 0x0f000000, LENGTH = 8K
    sdram_text (rx)  : ORIGIN = 0xa0000000, LENGTH = 16M
    sdram_data (rw)  : ORIGIN = 0xa1000000, LENGTH = 48M
    flash (rx)       : ORIGIN = 0x30000000, LENGTH = 32M
}

REGION_ALIAS("SRAM", sram);
REGION_ALIAS("TRAM", sdram_text);
REGION_ALIAS("DRAM", sdram_data);
REGION_ALIAS("ROM", flash);

_STACK_SIZE = 0x10000;     /* 栈大小：64KB */
SECTIONS {
  .entry : {
    *(entry)
  } > ROM AT> ROM
  
  .boot : {
    boot_start = .;
    *(boot)
  } > SRAM AT> ROM
  boot_size = SIZEOF(.boot);
  boot_load_start = LOADADDR(.boot);

  .text : {
    text_start = .;
    *(.text*)
  } > TRAM AT> ROM
  text_size = SIZEOF(.text);
  text_load_start = LOADADDR(.text);


  .rodata : {
    rodata_start = .;
    *(.rodata*)
    *(.srodata*)
    . = ALIGN(8);
  } > TRAM AT> ROM
  rodata_size = SIZEOF(.rodata);
  rodata_load_start = LOADADDR(.rodata);

  .data : {
    data_start = .;
    *(.data*)
    *(.sdata*)
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
  } > DRAM AT > ROM
  data_size = SIZEOF(.data);
  data_load_start = LOADADDR(.data);
  
  .bss : {
    bss_start = .;
    *(.bss*)
    *(.sbss*)
    *(.scommon)
    . = ALIGN(8);
    __am_apps_bss_start = .;
    *(__am_apps.bss*)
    *(__am_apps.sbss*)
    *(__am_apps.scommon*)
    __am_apps_bss_end = .;
    . = ALIGN(8);
  } > DRAM AT> ROM
  bss_size = SIZEOF(.bss);

  /* 堆区（动态计算剩余空间） */
  _heap_start = ALIGN(4);  /* 堆起始地址（4字节对齐） */
  _heap_end = ORIGIN(DRAM) + LENGTH(DRAM); 
  . = _heap_end;   
  end = .;
  _end = .;  
  
  _stack_top = ORIGIN(SRAM);
  _stack_pointer = ORIGIN(SRAM) + LENGTH(SRAM);
}

