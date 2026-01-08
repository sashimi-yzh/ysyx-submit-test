ENTRY(_start)
MEMORY {
	mrom (rx)  : ORIGIN = 0x20000000, LENGTH = 4K
	flash (rx)  : ORIGIN = 0x30000000, LENGTH =16M  /* 0x3000_0000~0x4000_0000 */
	sdram (rwx) : ORIGIN = 0xa0000000, LENGTH = 0x2000000  /* 0xa000_0000~0xbfff_ffff,实际上0xa000_0000到0xa200_0000 */
	psram (rwx) : ORIGIN = 0x80000000, LENGTH = 0x100000  /* 0x8000_0000~0x9fff_ffff,实际上0x8000_0000到0x8010_0000 */
	sram (rwx) : ORIGIN = 0x0f000000, LENGTH = 8K   /* 0x0f00_0000~0x0f00_1fff */
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

	.text.bootloader1 : {
    	_bootloader1_start = .;
    	*(.text.bootloader1)
    	_bootloader1_end = .;
	} > flash AT> flash

	.text.bootloader2 : {
    	_bootloader2_start = .;
    	*(.text.bootloader2)
    	_bootloader2_end = .;
	} > sram AT> flash
	_bootloader2_LMA_addr = LOADADDR(.text.bootloader2);
	_bootloader2_len =  SIZEOF(.text.bootloader2);

	.text : {  /* 存放的是所有可执行的指令代码(bootloader之后) */
		_text_start = .;      /* SA: 数据段在SRAM中的起始地址 (VMA) */
		EXCLUDE_FILE (start.* bootloader1.* bootloader2.*) *(.text*)
	}  > psram AT> flash  
	_text_LMA_addr = LOADADDR(.text);
	etext = .;
	_etext = .;   /* 代码段结束标记 */

	.rodata : {     /* 所有只读数据 */
		*(.rodata*)
	} > psram AT> flash 
	
	.data :{   /*数据段:全局变量*/
		. = ALIGN(4);
		_data_start = .;      /* SA: 数据段在SRAM中的起始地址 (VMA) */
		*(.data*)
		. = ALIGN(4);
		_data_end = .;        /* 数据段在SRAM中的结束地址 */
  	} > psram AT> flash    /*  在sram运行，从MROM加载 */
	_data_LMA_addr = LOADADDR(.data);
  	edata = .;
  	_data = .; 

	.bss : {  /*未初始化的全局变量和静态变量*/
		_bss_start = .;
    	*(.bss*)
    	*(.sbss*)
    	*(.scommon)
		. = ALIGN(4);
        _bss_end = .;
  	} > psram

	.heap : {
        _heap_start = .;  /* 堆开始 */
		_heap_end = ORIGIN(psram) + LENGTH(psram);  /* 堆结束*/
    } > psram

    .stack : {           
        _stack_bottom = .;                      /* 栈底：末尾 */
        . = ORIGIN(sram) + LENGTH(sram);                            /* 栈顶 */
        _stack_pointer = .;                                    /* 栈指针指向栈顶 */
    } > sram

	end = .;
	_end = .;	
	
}
