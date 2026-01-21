# 用于连续地址，从0x80000000处开始
include $(AM_HOME)/scripts/isa/riscv.mk
include $(AM_HOME)/scripts/platform/nemu.mk
CFLAGS  += -DISA_H=\"riscv/riscv.h\"
COMMON_CFLAGS += -march=rv32em_zicsr -mabi=ilp32e  # overwrite
LDFLAGS       += -melf32lriscv                     # overwrite

AM_SRCS += riscv/nemu/cte.c \
           riscv/nemu/trap.S \
           riscv/nemu/vme.c
           