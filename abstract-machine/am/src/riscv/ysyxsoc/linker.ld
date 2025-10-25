ENTRY(_fsbl)

MEMORY {
  flash : ORIGIN = 0x30000000, LENGTH = 16M
  sram  : ORIGIN = 0x0f000000, LENGTH = 8K
  psram : ORIGIN = 0x80000000, LENGTH = 4M
  sdram : ORIGIN = 0xa0000000, LENGTH = 128M
}

SECTIONS {
  . = ORIGIN(flash);

  .fsbl : ALIGN(4) {
    *(entry)
  } > flash
  
  _ssbl_load = .;
  .ssbl : ALIGN(4) {
    _ssbl_op = .;
    KEEP(*(ssbl.boot))
    KEEP(*(ssbl*))
    _ssbl_ed = .;
  } > sdram AT> flash

  _code_start = LOADADDR(.text);
  .text : ALIGN(4) { /* 代码段 */
    _code_op = .;
    KEEP(*(.text._trm_init))
    *(.text*)
    _code_ed = .;
  } > sdram AT> flash

  _rodata_start = LOADADDR(.rodata);
  .rodata : ALIGN(4) { /* 只读全局变量 */
    _rodata_op = .;
    *(.rodata*)
    *(.srodata*)
    _rodata_ed = .;
  } > sdram AT> flash

  _data_start = LOADADDR(.data);
  .data : ALIGN(4) { /* 可读写全局变量 */
    _data_op = .;
    
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

    _data_ed = .;
  } > sdram AT> flash

  .bss : {
    *(.bss*)
    *(.sbss*)
    *(.scommon)
  } > sdram

  _heap_start = 0xa2000000;
  _heap_end = 0xa4000000;

  _stack_top = 0x0f000000;
  _stack_pointer = 0x0f002000;
}
