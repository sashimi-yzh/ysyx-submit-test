ENTRY(_start)
PHDRS { text PT_LOAD; data PT_LOAD; }

SECTIONS {
  /* _pmem_start and _entry_offset are defined in LDFLAGS */
  . = _pmem_start + _entry_offset;

  /* .text段，明确4字节对齐 */
  .text : ALIGN(4) {
    *(entry)
    *(.text*)
  } : text
  etext = .;
  _etext = .;

  /* .rodata段，明确4字节对齐 */
  .rodata : ALIGN(4) {
    *(.rodata*)
  }

  .data.extra : ALIGN(4) {
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
  } : data

  /* .data段，确保4字节对齐 */
  .data : ALIGN(4) {
    *(.data)
  } : data
  edata = .;
  _data = .;

  .bss.extra : ALIGN(4) {
    . = ALIGN(0x10);
    __am_apps_bss_start = .;
    *(__am_apps.bss*)
    *(__am_apps.sbss*)
    *(__am_apps.scommon*)
    __am_apps_bss_end = .;
    . = ALIGN(0x10);
  } : data

  /* .bss段，确保4字节对齐 */
  .bss : ALIGN(4) {
    _bss_start = .;
    *(.bss*)
    *(.sbss*)
    *(.scommon)
  } : data

  /* 确保堆栈顶部是8字节对齐 */
  _stack_top = ALIGN(8);
  . = _stack_top + 0x8000;
  _stack_pointer = .;

  /* 结束符号 */
  end = .;
  _end = .;

  /* 堆对齐 */
  _heap_start = ALIGN(8);
}
