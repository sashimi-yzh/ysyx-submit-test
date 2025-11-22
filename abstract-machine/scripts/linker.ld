ENTRY(_start)
PHDRS { text PT_LOAD; data PT_LOAD; }

SECTIONS {
  /* _pmem_start and _entry_offset are defined in LDFLAGS */
  . = _pmem_start + _entry_offset;
  .text : {
    *(entry)
    *(.text*)
  } : text
  etext = .;
  _etext = .;
  .rodata : {
    *(.rodata*)
  }
  .data : {
    *(.data*)
  } : data
  edata = .;
  _data = .;
  .bss : {
	_bss_start = .;
    *(.bss*)
    *(.sbss*)
    *(.scommon)
  }
  _stack_top = ALIGN(0x1000);
  . = _stack_top + 0x8000;
  _stack_pointer = .;
  end = .;
  _end = .;
  _heap_start = ALIGN(0x1000);
}
/* 低地址
┌───────────────────┐
│      .text        │ ← _pmem_start
│   (entry, code)   │
├───────────────────┤
│     .rodata       │
│   (read-only)     │
├───────────────────┤
│      .data        │
│ (initialized data)│
├───────────────────┤
│       .bss        │ ← _bss_start
│ (uninitialized)   │
├───────────────────┤
│                   │
│     栈空间        │ ← _stack_top (栈底)
│    (32KB)         │
│                   │ ← _stack_pointer (初始SP)
├───────────────────┤
│                   │
│     未分配空间     │ ← end/_end
├───────────────────┤
│                   │
│      堆空间        │ ← _heap_start
│   (动态分配)       │
└───────────────────┘ 高地址 */