include $(AM_HOME)/scripts/isa/riscv.mk
include $(AM_HOME)/scripts/platform/ysyxsoc.mk
COMMON_CFLAGS += -march=rv32e_zicsr_zifencei -mabi=ilp32e  # overwrite
LDFLAGS       += -melf32lriscv                    # overwrite

AM_SRCS += riscv/ysyxSoC/libgcc/div.S \
           riscv/ysyxSoC/libgcc/muldi3.S \
           riscv/ysyxSoC/libgcc/multi3.c \
           riscv/ysyxSoC/libgcc/ashldi3.c \
           riscv/ysyxSoC/libgcc/unused.c
