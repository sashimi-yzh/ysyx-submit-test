#用作Second Stage Bootloader,位于flash基地址
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
        #lui a2, %hi(_edata_extra_rom)
        #addi a2,a2,%lo(_edata_extra_rom)
        #lui a5, %hi(_sdata_extra_rom)
        #addi a5,a5,%lo(_sdata_extra_rom)
        #lui a4, %hi(_sdata_extra_ram)
        #addi a4,a4,%lo(_sdata_extra_ram)
        #beq a2,a5,end_data_extra_copy_loop
    #data_extra_copy_loop:
        #lw a3,0(a5)
        #addi a5,a5,4
        #addi a4,a4,4
        #sw a3,-4(a4)
        #bne a2,a5,data_extra_copy_loop
    #end_data_extra_copy_loop:


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


		#跳转至text段起始位置(位于ram中)
		lui a0,%hi(_stext_ram)
		addi a0,a0,%lo(_stext_ram)
		jalr ra,a0,0
		
