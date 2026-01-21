# 用于分离地址，从0x30000000处开始
include $(AM_HOME)/scripts/isa/riscv.mk
# include $(AM_HOME)/scripts/platform/nemusoc.mk # 这行对应0x30000000地址空间
include $(AM_HOME)/scripts/platform/nemu.mk  # 这行对应0x80000000地址空间    
CFLAGS  += -DISA_H=\"riscv/riscv.h\"
COMMON_CFLAGS += -march=rv32im_zicsr -mabi=ilp32   # overwrite
LDFLAGS       += -melf32lriscv                     # overwrite

AM_SRCS += riscv/nemu/cte.c \
           riscv/nemu/trap.S \
           riscv/nemu/vme.c 
		   
