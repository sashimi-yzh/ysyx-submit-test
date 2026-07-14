SECTIONS {
  . = 0x20000000;
  .text : { *(.text) *(.text.*) }
}