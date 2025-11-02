#用作First Stage Bootloader,位于flash基地址
.section FSBL, "ax"
.globl _FSBL
.type _FSBL, @function

_FSBL:
		#模拟first stage bootloader从rom加载SSBL段至SRAM
		lui a2, %hi(_eSSBL_rom)
        addi a2, a2, %lo(_eSSBL_rom)
        lui a5, %hi(_sSSBL_rom)
        addi a5,a5,%lo(_sSSBL_rom)
        lui a4, %hi(_sSSBL_sram)
        addi a4,a4,%lo(_sSSBL_sram)
        beq a2,a5,end_SSBL_copy_loop
	SSBL_copy_loop:
		lw a3,0(a5)
        addi a5,a5,4
        addi a4,a4,4
        sw a3,-4(a4)
        bne a2,a5,SSBL_copy_loop
    end_SSBL_copy_loop:
	
		#跳转至SSBL
		lui a0,%hi(_sSSBL_sram)
		addi a0,a0,%lo(_sSSBL_sram)
		jalr ra,a0,0
