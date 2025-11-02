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
        #lui a0,%hi(_sSSBL_sram)
       	#addi a0,a0,%lo(_sSSBL_sram)
        #jalr ra,a0,0
		#la a0,_SSBL
        lui a0,%hi(_SSBL)
       	addi a0,a0,%lo(_SSBL)
		jalr ra,a0,0




.section SSBL, "ax"
.globl _SSBL
.type _SSBL, @function
_SSBL:
        #模拟second stage bootloader从rom加载text段至ram
        lui a2, %hi(_etext_rom)
        addi a2, a2, %lo(_etext_rom)
        lui a5, %hi(_stext_rom)
        addi a5,a5,%lo(_stext_rom)
        lui a4, %hi(_stext_ram)
        addi a4,a4,%lo(_stext_ram)
        beq a2,a5,end_text_copy_loop
    text_copy_loop:
        lw a3,0(a5)
        addi a5,a5,4
        addi a4,a4,4
        sw a3,-4(a4)
        bne a2,a5,text_copy_loop
    end_text_copy_loop:


		#模拟SSBL从rom加载rodata段至ram
        lui a2, %hi(_erodata_rom)
        addi a2,a2,%lo(_erodata_rom)
        lui a5, %hi(_srodata_rom)
        addi a5,a5,%lo(_srodata_rom)
        lui a4, %hi(_srodata_ram)
        addi a4,a4,%lo(_srodata_ram)
        beq a2,a5,end_rodata_copy_loop
    rodata_copy_loop:
        lw a3,0(a5)
        addi a5,a5,4
        addi a4,a4,4
        sw a3,-4(a4)
        bne a2,a5,rodata_copy_loop
    end_rodata_copy_loop:

		
		
		#模拟data.extra段的加载,仅针对rtt有效
        lui a2, %hi(_edata_extra_rom)
        addi a2,a2,%lo(_edata_extra_rom)
        lui a5, %hi(_sdata_extra_rom)
        addi a5,a5,%lo(_sdata_extra_rom)
        lui a4, %hi(_sdata_extra_ram)
        addi a4,a4,%lo(_sdata_extra_ram)
        beq a2,a5,end_data_extra_copy_loop
    data_extra_copy_loop:
        lw a3,0(a5)
        addi a5,a5,4
        addi a4,a4,4
        sw a3,-4(a4)
        bne a2,a5,data_extra_copy_loop
    end_data_extra_copy_loop:



		#模拟bootloader从rom加载data段至ram
        lui a2, %hi(_edata_rom)
        addi a2,a2,%lo(_edata_rom)
        lui a5, %hi(_sdata_rom)
        addi a5,a5,%lo(_sdata_rom)
        lui a4, %hi(_sdata_ram)
        addi a4,a4,%lo(_sdata_ram)
        beq a2,a5,end_data_copy_loop
    data_copy_loop:
        lw a3,0(a5)
        addi a5,a5,4
        addi a4,a4,4
        sw a3,-4(a4)
        bne a2,a5,data_copy_loop
    end_data_copy_loop:



		#模拟bss.extra的加载(直接对RAM区域置0),仅对rtt有效
        lui a2, %hi(_ebss_extra_ram)
        addi a2,a2,%lo(_ebss_extra_ram)
        lui a5, %hi(_sbss_extra_ram)
        addi a5,a5,%lo(_sbss_extra_ram)
        beq a2,a5,end_bss_extra_copy_loop
    bss_extra_copy_loop:
        li a3,0
        addi a5,a5,4
        sw a3,-4(a5)
        bne a2,a5,bss_extra_copy_loop
    end_bss_extra_copy_loop:



		#模拟bss的加载
        lui a2, %hi(_ebss_ram)
        addi a2,a2,%lo(_ebss_ram)
        lui a5, %hi(_sbss_ram)
        addi a5,a5,%lo(_sbss_ram)
        beq a2,a5,end_bss_copy_loop
    bss_copy_loop:
        li a3,0
        addi a5,a5,4
        sw a3,-4(a5)
        bne a2,a5,bss_copy_loop
    end_bss_copy_loop:






		#la a0,_start
		lui a0,%hi(_start)
        addi a0,a0,%lo(_start)
		jalr ra,a0,0



.section entry, "ax"
.globl _start
.type _start, @function
_start:
	mv s0,zero
	la sp,_stack_pointer
	la ra, _trm_init # 先将 _trm_init 地址加载到 ra 寄存器中
 	jalr ra, 0(ra) # 然后使用间接寻址的方式跳转
	#jal _trm_init


