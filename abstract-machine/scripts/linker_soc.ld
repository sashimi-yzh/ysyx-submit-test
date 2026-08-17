/* ENTRY(_start)

MEMORY {
  sram (rw) : ORIGIN = 0x0f000000, LENGTH = 8K
  prog (rx)  : ORIGIN = 0x30000000, LENGTH = _pmem_size
  psram (rwx) : ORIGIN = 0x80000000, LENGTH = 2M
  psram_heap (rw) : ORIGIN = 0x80200000, LENGTH = 2M
}

SECTIONS
{
  . = ORIGIN(prog);

  .text : {
    *(entry)
    *(.fsbl)
  } > prog AT> prog

  . = ORIGIN(sram);  
  
  .first_stage : {
    . = ALIGN(4);
    __ssbl_start = .;
    *(.ssbl)
    . = ALIGN(4);
    __ssbl_end = .;
  } > sram AT> prog

  __ssbl_load_start = LOADADDR(.first_stage);
  __ssbl_load_end   = __ssbl_load_start + SIZEOF(.first_stage);

  . = ORIGIN(psram);  

  .rodata : {
    __prog_start = .;
    *(.text*)
    *(.rodata*)
    __prog_end = .;
  } > psram AT> prog

  __prog_load_start = LOADADDR(.rodata);
  __prog_load_end   = __prog_load_start + SIZEOF(.rodata);


  .data : {
  __data_start = .;
  *(.data*)
  *(.sdata*)
  __data_end = .;
  } > psram AT> prog

  __data_load_start = LOADADDR(.data);
  __data_load_end   = __data_load_start + SIZEOF(.data);

  .bss (NOLOAD) : {
    __bss_start = .;
    *(.bss*)
    *(.sbss*)
    *(.scommon)
    __bss_end = .;
  } > psram

  _heap_start = ORIGIN(psram_heap);
  _heap_end = ORIGIN(psram_heap) + LENGTH(psram_heap);
  _stack_pointer = ORIGIN(sram) + LENGTH(sram);
} */




ENTRY(_start)

MEMORY {
  sram (rw) : ORIGIN = 0x0f000000, LENGTH = 8K
  prog (rx)  : ORIGIN = 0x30000000, LENGTH = _pmem_size
  psram (rw) : ORIGIN = 0x80000000, LENGTH = 4M 
  sdram (rwx) : ORIGIN = 0xa0000000, LENGTH = 64M
  sdram_heap (rwx) : ORIGIN = 0xa4000000, LENGTH = 64M

}

SECTIONS
{
  . = ORIGIN(prog);

  .text : {
    *(entry)
    *(.fsbl)
  } > prog AT> prog

  . = ORIGIN(sram);  
  
  .first_stage : {
    . = ALIGN(4);
    __ssbl_start = .;
    *(.ssbl)
    . = ALIGN(4);
    __ssbl_end = .;
  } > sram AT> prog

  __ssbl_load_start = LOADADDR(.first_stage);
  __ssbl_load_end   = __ssbl_load_start + SIZEOF(.first_stage);

  . = ORIGIN(sdram);  

  .rodata : {
    __prog_start = .;
    *(.text*)
    *(.rodata*)
    __prog_end = .;
  } > sdram AT> prog

  __prog_load_start = LOADADDR(.rodata);
  __prog_load_end   = __prog_load_start + SIZEOF(.rodata);


  .data : {
  __data_start = .;
  *(.data*)
  *(.sdata*)
  __data_end = .;
  } > sdram AT> prog

  __data_load_start = LOADADDR(.data);
  __data_load_end   = __data_load_start + SIZEOF(.data);

  .bss (NOLOAD) : {
    __bss_start = .;
    *(.bss*)
    *(.sbss*)
    *(.scommon)
    __bss_end = .;
  } > sdram

  _heap_start = ORIGIN(sdram_heap);
  _heap_end = ORIGIN(sdram_heap) + LENGTH(sdram_heap);
  _stack_pointer = ORIGIN(sram) + LENGTH(sram);
  /* _stack_pointer = ORIGIN(psram) + LENGTH(psram); */
}


