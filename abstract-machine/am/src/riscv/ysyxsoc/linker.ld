MEMORY {
    mrom : ORIGIN = 0x30000000, LENGTH = 256M
    psram : ORIGIN = 0x80000000, LENGTH = 4M
    sram : ORIGIN = 0x0f000000, LENGTH = 8K
	sdram : ORIGIN = 0xa0000000, LENGTH = 128M
}
ENTRY(_start)
SECTIONS {
	.entry :{
		*(entry)
	} >mrom
	.loader :{
		_loader_vma = .;
		*(loader)
		_loader_vma_end = .;
	} >sdram AT> mrom
	_loader_lma = LOADADDR(.loader);
    .text : {
		_text_vma = .;
        *(.text*) 
		_text_vma_end = .;        
    } > sdram AT> mrom
	 _text_lma = LOADADDR(.text);
	.rodata : {
		_rodata_vma = .;
		*(.rodata*)
		*(.srodata*)
		_rodata_vma_end = .;
	} > sdram AT> mrom
	_rodata_lma = LOADADDR(.rodata);

	.data.extra : {
	_data_extra_vma = .;
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
	_data_extra_vma_end = .;
  	}>sdram AT> mrom
	
	_data_extra_lma = LOADADDR(.data.extra);

    .data : {
        _data_vma = .; 
		*(.sdata*)
        *(.data*)
        _data_vma_end = .;
    } > sdram AT> mrom

    _data_lma = LOADADDR(.data);

  .bss.extra : {
	_bss_extra_start = .;
    . = ALIGN(8);
    __am_apps_bss_start = .;
    *(__am_apps.bss*)
    *(__am_apps.sbss*)
    *(__am_apps.scommon*)
    __am_apps_bss_end = .;
    . = ALIGN(8);
	_bss_extra_end = .;
  }>sdram AT> mrom
  
  .bss : {
		. = ALIGN(8);
        _bss_start = .;
         *(.bss*)
		*(.sbss*)
		*(.scommon)
        _bss_end = .;
    } >sdram AT> mrom

   .stack : {
	. = ALIGN(8);
	_stack_top = .;
	. = _stack_top + 0x400000;
	_stack_pointer = .;
   } >sdram
   
	. = _stack_pointer;
	. = ALIGN(16);
    _heap_start = .;
	_heap_end = 0xa8000000;
}