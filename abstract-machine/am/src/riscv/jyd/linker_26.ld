ENTRY(_start)

MEMORY {
	irom : ORIGIN = 0x0000, LENGTH = 0x4000
	dram : ORIGIN = 0x4000, LENGTH = 0xB000
	/* heap region is inside dram, just for clarity */
	heap : ORIGIN = 0x8000, LENGTH = 0x7000
}

SECTIONS {
	. = ORIGIN(irom);

	.text : {
    *(entry)
		*(.text*)
	} > irom

	.rodata : {
		*(.rodata*)
		*(.srodata*)
	} > irom

	.data : {
		*(.data*)
		*(.sdata)
	} > dram

	.bss : ALIGN(4) {
		*(.bss*)
		*(.sbss)
		*(.scommon)
	} > dram

  _stack_top = ORIGIN(dram) + LENGTH(dram);
  _stack_pointer  = _stack_top;

  _heap_start = ORIGIN(heap);
	_heap_end = ORIGIN(heap) + LENGTH(heap);
}
