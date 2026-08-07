ENTRY(_fsbl)
PHDRS { boot.fsbl PT_LOAD; boot.ssbl PT_LOAD; text PT_LOAD; rodata PT_LOAD; data PT_LOAD; }
MEMORY {
  mrom (RX): ORIGIN = 0x20000000, LENGTH = 4K
  sram (WX): ORIGIN = 0x0f000000, LENGTH = 8K
  psram(WX): ORIGIN = 0x80000000, LENGTH = 4M
  sdram(WX): ORIGIN = 0xa0000000, LENGTH = 128M
  flash(RX): ORIGIN = 0x30000000, LENGTH = 256M
}

SECTIONS {
  /* _pmem_start and _entry_offset are defined in LDFLAGS */
  . = _pmem_start + _entry_offset;
  .boot.fsbl ALIGN(4): {
    *(entry.fsbl)
  }  > flash : boot.fsbl

  . = ORIGIN(sram);
  .boot.ssbl ALIGN(4): {
    _ssbl_start = .;
    *(entry.ssbl)
    . = ALIGN(4);
    _essbl = .;
  }  > sram AT > flash : boot.ssbl
  _ssbl_load_start = LOADADDR(.boot.ssbl);
  
  . = ORIGIN(sdram);
  .rodata ALIGN(4): {
    _rodata_start = .;
    *(.rodata*)
    *(.srodata*)
    . = ALIGN(4);
    _erodata = .;
  } > sdram AT > flash : rodata
  _erodata_load_start = LOADADDR(.rodata);
  
  .text ALIGN(4) : {
    _text_start = .;
    /* FILL(0x00);
    . += 252; */
    *(.text*)
    . = ALIGN(4);
    _etext = .;
  } > sdram AT > flash : text 
  _text_load_start = LOADADDR(.text);

  .data ALIGN(4) : {
    _data_start = .;
    *(.data*)
    *(.sdata*)
    . = ALIGN(4);
    _edata = .;
  } > sdram AT > flash : data
  _data_load_start = LOADADDR(.data);

  .bss ALIGN(4) (NOLOAD) : {
	  _bss_start = .;
    *(.bss*)
    *(.sbss*)
    *(.scommon)
    . = ALIGN(4);
    _ebss = .;
  } > sdram : NONE
  . = ALIGN(4);
  end = .;
  _end = .;
  _heap_start = _end;
  _heap_end   = ORIGIN(sdram) + LENGTH(sdram);
  _stack_area_start = ORIGIN(sram);
  _stack_area_end = ORIGIN(sram) + LENGTH(sram);
  _stack_pointer = _stack_area_end;
}
