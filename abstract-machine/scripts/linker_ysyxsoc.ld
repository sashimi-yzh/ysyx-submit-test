ENTRY( _start )
MEMORY
{
  mrom  : ORIGIN = 0x20000000, LENGTH = 4K  /* 代码段 */
  sram  : ORIGIN = 0x0f000000, LENGTH = 8K  /* 数据段、栈、堆 2000*/
  flash : ORIGIN = 0x30000000, LENGTH = 16M /*  0x1000000 */
  psram : ORIGIN = 0x80000000, LENGTH = 4M  /*  0x400000 */
  sdram : ORIGIN = 0xa0000000, LENGTH = 32M /*  0x2000000 */
}

SECTIONS {
  .fsbl : {
    *(entry)
    *(.fsbl*)
  } > flash AT>flash

  .bootloader : {
    _siflash_ssbl = .;
    *(.bootloader*)
    _eiflash_ssbl = .;
  } > sram  AT> flash
  _ssbl_lma_start = LOADADDR(.bootloader);

  /* 将代码段放到 flash */
  . = ALIGN(0x10);
  .text : {
    _stext  = .;
    stext = .;
    *(.text*)
    . = ALIGN(0x10);
  } > sdram AT>flash
  etext = .;
  _etext = .;

  _text_lma_start = LOADADDR(.text);
  . = ALIGN(0x10);

  /* 将只读数据段放到 flash */
  .rodata : ALIGN(0x10){
    . = ALIGN(0x10);
    _srodata  = .;
    *(.rodata*)
    . = ALIGN(0x10);
    *(.srodata*)
    . = ALIGN(0x10);
  } > sdram AT>flash
  _erodata  = .;

  _rodata_lma_start = LOADADDR(.rodata);

  . = ALIGN(0x10);

  .data.extra : {
    . = ALIGN(0x10);
    _sdata  = .;
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
  } > sdram AT> flash

  . = ALIGN(0x10);

  /* 将数据段放到 sdram，但加载地址在 flash */
  .data : {
    . = ALIGN(0x10);
    PROVIDE( _data_start = . );
    *(.data*)
    . = ALIGN(0x10);
    *(.sdata*)
    . = ALIGN(0x10);
  } > sdram AT> flash
  _edata  = .;
  . = ALIGN(0x10);
  PROVIDE( _data_end = . );

  _data_lma_start = LOADADDR(.data.extra);

  PROVIDE( _fbss = . );
  PROVIDE( __bss_start = . );

  .bss.extra : {
    . = ALIGN(0x10);
    __am_apps_bss_start = .;
    *(__am_apps.bss*)
    *(__am_apps.sbss*)
    *(__am_apps.scommon*)
    __am_apps_bss_end = .;
    . = ALIGN(0x10);
  } > sdram

  /* 将未初始化数据段放到 sdram */
  .bss : {
    *(.bss*)
    *(.sbss*)
    *(.scommon)
  } > sdram
  PROVIDE( _bss_end = . );

  /* 设置堆的起始位置 */
  _heap_start = ALIGN(0x4);  /* 对齐到 4 字节 */

  /* 堆的结束地址 */
  _heap_end = _heap_start + 0x2000; /* 8K */
  _heap_end = 0xa2000000;

  /* 栈的设置 */
  _stack_top = ORIGIN(sram) + LENGTH(sram); /* 栈从 sram 的顶端开始 */
  _stack_pointer = _stack_top;
  
  /* 定义程序结束位置 */
  end = .;
  _end = .;
}