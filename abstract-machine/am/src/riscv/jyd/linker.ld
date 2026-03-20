ENTRY(_start)

MEMORY {
  IROM (rx) : ORIGIN = 0x80000000, LENGTH = 16K
  DRAM (rwx) : ORIGIN = 0x80100000, LENGTH = 128K
	/* 赛题文档中没有指定堆区，是直接给出编译产物的结果，具体的堆区地址和大小是
	 * 主办方那边设置的，这里设置的堆区只是提供给自己的测试程序使用，实际比赛时
	 * 是跑给出的编译产物的 */
	heap (rwx) : ORIGIN = 0x80140000, LENGTH = 128K
}

SECTIONS {

	.text : {
		*(entry)
		*(.text*)
	} > IROM

	.rodata : ALIGN(4) {
		*(.rodata*)
		*(.srodata*)
	} > IROM

	.data : {
		*(.data*)
		*(.sdata*)
	} > DRAM
	/* NOTE: when dump to binary, .data section should not be included in 
	 * main binary, it should be placed in a separate binary */

	.bss : {
		*(.bss*)
		*(.sbss*)
		*(.scommon*)
	} > DRAM

	PERIPHERAL_BASE = 0x80200000;
	
	SW_LOW   = PERIPHERAL_BASE + 0x00;
	SW_HIGH  = PERIPHERAL_BASE + 0x04;
	KEY_REG  = PERIPHERAL_BASE + 0x10;
	SEG_REG  = PERIPHERAL_BASE + 0x20;
	LED_REG  = PERIPHERAL_BASE + 0x40;
	CNT_REG  = PERIPHERAL_BASE + 0x50;

	_my_ext_serial_port = 0x10000000;

	_stack_top = ORIGIN(DRAM) + LENGTH(DRAM);
  _stack_pointer  = _stack_top;

  _heap_start = ORIGIN(heap);
	_heap_end = ORIGIN(heap) + LENGTH(heap);
}
