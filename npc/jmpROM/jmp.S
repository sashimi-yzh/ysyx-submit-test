.section .text
.globl _start

_start:
	# dest addr = (0x80000 << 12) = 0x80000000
	lui t0, 0x80000    
	jr t0
