/*入口为first stage bootloader*/
ENTRY(_FSBL)
/*PHDRS { text PT_LOAD; data PT_LOAD; }*/

MEMORY {
 	/*rom : ORIGIN = 0x20000000, LENGTH = 4K*/
 	sram : ORIGIN = 0x0f000000, LENGTH = 8K
	rom  : ORIGIN = 0x30000000, LENGTH = 16M
 	/*ram  : ORIGIN = 0x80000000, LENGTH = 4M*/
 	ram  : ORIGIN = 0xa0000000, LENGTH = 32M
}

SECTIONS {
	. = ORIGIN(rom);
	/*有关FSBL的分配*/
	_sFSBL_rom = LOADADDR(.FSBL);
	.FSBL : {
		*(FSBL)
		. = ALIGN(8);
	} > rom AT > rom
	_eFSBL_rom = _sFSBL_rom + SIZEOF(.FSBL);
	

	/*有关SSBL的分配*/
	_sSSBL_rom = LOADADDR(.SSBL);
	.SSBL : {
		_sSSBL_sram = .;
		*(SSBL)
		. = ALIGN(8);
		_eSSBL_sram = .;
	} > sram AT > rom
	_eSSBL_rom = _sSSBL_rom + SIZEOF(.SSBL);


	/*有关text的分配*/
	_stext_rom = LOADADDR(.text);
	.text :{
		_stext_ram = .;
		*(entry)
		*(.text*)
		. = ALIGN(8);/*主要是由于rtt*/
		_etext_ram = . ;
	} > ram AT > rom
	_etext_rom = _stext_rom + SIZEOF(.text);

	
	/*有关rodata的分配*/
	_srodata_rom = LOADADDR(.rodata);
	.rodata : {
		_srodata_ram = .;
		*(.rodata*)
		*(.srodata*)
		. = ALIGN(8);
		_erodata_ram = .;
	} > ram AT > rom
	_erodata_rom = _srodata_rom + SIZEOF(.rodata);

	
	_sdata_extra_rom = LOADADDR(.data.extra);
  .data.extra : {
    _sdata_extra_ram = .;
    __fsymtab_start = .;
    KEEP(*(FSymTab))
    __fsymtab_end = .;
    . = ALIGN(8);
    __vsymtab_start = .;
    KEEP(*(VSymTab))
    __vsymtab_end = .;
    . = ALIGN(8);

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
    _edata_extra_ram = .;
  } > ram AT > rom

  _edata_extra_rom = _sdata_extra_rom + SIZEOF(.data.extra);


	/*有关data的分配*/
	_sdata_rom = LOADADDR(.data);
	.data : {  
        _sdata_ram = .;
		*(.data*)
		*(.sdata*)
	  	. = ALIGN(8);
        _edata_ram = .;  
    } > ram AT > rom
	_edata_rom = _sdata_rom + SIZEOF(.data);



	/*有关bss.extra的分配*/
	/*_sbss_extra_rom = LOADADDR(.bss.extra);*/
	.bss.extra : {
    	. = ALIGN(8);
		_sbss_extra_ram = .;
    	__am_apps_bss_start = .;
    	*(__am_apps.bss*)
    	*(__am_apps.sbss*)
    	*(__am_apps.scommon*)
    	__am_apps_bss_end = .;
    	. = ALIGN(8);
		_ebss_extra_ram = .;
  	} > ram AT > ram
	/*_ebss_extra_rom = _sbss_extra_rom + SIZEOF(.bss.extra);*/
		
	
	/*有关bss的分配*/
	/*_sbss_rom = LOADADDR(.bss);*/
	.bss : {
    	_sbss_ram = .;
    	*(.bss*)
    	*(.sbss*)
    	*(.scommon)
		. = ALIGN(8);
		_ebss_ram = .;
  	} > ram AT > ram
	/*_ebss_rom = _sbss_rom + SIZEOF(.bss);*/

	
	_heap_start = _ebss_ram;
	/*. = ORIGIN(ram) + 0x1fff + 1;*/
	. = ORIGIN(ram) + 0x3fffff + 1;
	_stack_pointer = . ;
	_heap_end = . ;
}


/*
SECTIONS {
  .bss.extra : {
    . = ALIGN(8);
    __am_apps_bss_start = .;
    *(__am_apps.bss*)
    *(__am_apps.sbss*)
    *(__am_apps.scommon*)
    __am_apps_bss_end = .;
    . = ALIGN(8);
  } > ram AT > ram
}
INSERT BEFORE .bss;


SECTIONS {
	_sdata_extra_rom = LOADADDR(.data.extra);
  .data.extra : {
	_sdata_extra_ram = .;
    __fsymtab_start = .;
    KEEP(*(FSymTab))
    __fsymtab_end = .;
    . = ALIGN(8);
    __vsymtab_start = .;
    KEEP(*(VSymTab))
    __vsymtab_end = .;
    . = ALIGN(8);

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
	_edata_extra_ram = .;
  } > ram AT > rom

  _edata_extra_rom = _sdata_extra_rom + SIZEOF(.data.extra);

}
INSERT BEFORE .data;
*/
