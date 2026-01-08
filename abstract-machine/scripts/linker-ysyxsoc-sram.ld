ENTRY(_start)
PHDRS { text PT_LOAD; data PT_LOAD; }

MEMORY {
	mrom (rx)  : ORIGIN = 0x20000000, LENGTH = 4K
	flash (rx)  : ORIGIN = 0x30000000, LENGTH =256M  /* 0x3000_0000~0x4000_0000 */
	sram (rwx) : ORIGIN = 0x0f000000, LENGTH = 8K   /* 0x0f00_0000~0x0f00_1fff */
}

/* > mrom AT> mrom 虚拟内存地址(virtual memory address, VMA):程序运行时对象所在的地址;  */ 
                /*加载内存地址(load memory address, LMA):程序运行前对象所在的地址. */
    	
SECTIONS {
	/* _mrom_start and _entry_offset are defined in LDFLAGS */
	. = ORIGIN(flash);          /* flash 位置 */

	.text : {  /* 存放的是所有可执行的指令代码 */
		*(entry)
		*(.text*)
	}  > flash AT> flash : text
	etext = .;
	_etext = .;   /* 代码段结束标记 */

	.rodata : {     /* 所有只读数据 */
		*(.rodata*)
	} > flash AT> flash : text  
	
	.data :{   /* 数据段:全局变量*/
		. = ALIGN(4);
		_data_start = .;      /* SA: 数据段在SRAM中的起始地址 (VMA) */
		*(.data*)
		. = ALIGN(4);
		_data_end = .;        /* 数据段在SRAM中的结束地址 */
  	} > sram AT> flash : data   /*  在sram运行，从MROM加载 */
	_data_LMA_addr = LOADADDR(.data);
	_data_len =  SIZEOF(.data);
  	edata = .;
  	_data = .; 

	.heap : {
        _heap_start = .;  /* 堆开始 */
		_heap_end = ORIGIN(sram) + LENGTH(sram) - 0x800;  /* 堆结束 = 栈开始 */
    } > sram

    .stack : {           
        _stack_bottom = ORIGIN(sram) + LENGTH(sram) - 0x800; /* 栈底：sram末尾 */
        . = _stack_bottom + 0x800;                            /* 栈顶 */
        _stack_pointer = .;                                    /* 栈指针指向栈顶 */
    } > sram

	end = .;
	_end = .;	
	
}
