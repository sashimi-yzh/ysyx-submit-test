ENTRY(_start)
MEMORY {
	mrom (rx)  : ORIGIN = 0x20000000, LENGTH = 4K
	flash (rx)  : ORIGIN = 0x30000000, LENGTH =0x10000000  /* 0x3000_0000~0x4000_0000 */
	sdram (rwx) : ORIGIN = 0xa0000000, LENGTH = 0x8000000  /* 0xa000_0000~0xbfff_ffff,实际上0xa000_0000到0xa800_0000 */
	psram (rwx) : ORIGIN = 0x80000000, LENGTH = 0x100000  /* 0x8000_0000~0x9fff_ffff,实际上0x8000_0000到0x8010_0000 */
	sram (rwx) : ORIGIN = 0x0f000000, LENGTH = 0x2000   /* 0x0f00_0000~0x0fff_ffff 实际上0x0f00_0000~0x0f00_1fff */
} 	
SECTIONS {
	/* _mrom_start and _entry_offset are defined in LDFLAGS */
	. = ORIGIN(flash);          /* flash 位置 */

	.text.start :
  	ALIGN(8)
  	{
    	. = ALIGN(8);
    	*(entry)
    	. = ALIGN(8);
  	} > flash AT> flash
	
	. = ALIGN(8);
	_bootloader2_LMA_addr = .;
	.text.bootloader2 : 
	ALIGN(8)
	{
    	_bootloader2_start = .;
		. = ALIGN(8);
    	*(.text.bootloader2)
		. = ALIGN(8);
    	_bootloader2_end = .;
	} > flash AT> flash
	_bootloader2_len =  SIZEOF(.text.bootloader2);
	. = LOADADDR(.text.bootloader2) + SIZEOF(.text.bootloader2);

	. = ALIGN(8);
	_text_LMA_addr = .;
	.text : 
	ALIGN(8)
	{  /* 存放的是所有可执行的指令代码(bootloader之后) */
		_text_start = .;      /* SA: 数据段在SRAM中的起始地址 (VMA) */
		EXCLUDE_FILE (start.* bootloader2.*) *(.text*)
		. = ALIGN(8);
	} > flash
	_text_len =  SIZEOF(.text);  

	. = ALIGN(8);
	etext = .;
	_etext = .;   /* 代码段结束标记 */

	.rodata : 
	ALIGN(8)
	{     /* 所有只读数据 */
		. = ALIGN(8);
		*(.rodata*)
		. = ALIGN(8);
	} > flash
  . = ALIGN(8);  
  _rodata_end = ADDR(.rodata) + SIZEOF(.rodata);
  erodata = .;      /* 只读数据段结束 */
  _erodata = .;

  . = ORIGIN(sdram);

	.data.extra : 
	ALIGN(8)
	{
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
  }  >sdram AT> flash
  _data_EXTRA_LMA_addr = LOADADDR(.data.extra);

	. = ALIGN(8);	
	.data :{   /*数据段:全局变量*/
		. = ALIGN(8);
		_data_start = .;      /* SA: 数据段在SRAM中的起始地址 (VMA) */
		*(.data*)
		*(.sdata*)
		. = ALIGN(8);
		_data_end = .;        /* 数据段在SRAM中的结束地址 */
  	} > sdram AT> flash    /*  在sram运行，从MROM加载 */
	_data_LMA_addr = LOADADDR(.data);
	_data_len =  SIZEOF(.data);  
  	edata = .;
  	_data = .; 

  .bss.extra : {
    . = ALIGN(8);
    __am_apps_bss_start = .;
    *(__am_apps.bss*)
    *(__am_apps.sbss*)
    *(__am_apps.scommon*)
    __am_apps_bss_end = .;
    . = ALIGN(8);
  }  >sdram AT> flash

	.bss : {  /*未初始化的全局变量和静态变量*/
		. = ALIGN(8);
		_bss_start = .;
		*(.bss*)
    	*(.sbss*)
    	*(.scommon)
		. = ALIGN(8);
        _bss_end = .;
  	} > sdram AT> flash
	. = _bss_end;
    . = ALIGN(8);

	.heap : {
		. = ALIGN(8);
        _heap_start = .;  /* 堆开始 */
		. = ALIGN(8);
		_heap_end = ORIGIN(sdram) + LENGTH(sdram);  /* 堆结束*/
    } > sdram

    .stack : {     
		. = ALIGN(8);      
        _stack_bottom = .;                      /* 栈底：末尾 */
		. = ALIGN(8);
        . = ORIGIN(sram) + LENGTH(sram);                            /* 栈顶 */
        _stack_pointer = .;                                    /* 栈指针指向栈顶 */
    } > sram

	end = .;
	_end = .;	
	
}
