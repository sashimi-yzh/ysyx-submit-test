include $(AM_HOME)/scripts/isa/riscv.mk
include $(AM_HOME)/scripts/platform/ysyxsoc.mk
CFLAGS  += -DISA_H=\"riscv/riscv.h\"
COMMON_CFLAGS += -march=rv32e_zicsr -mabi=ilp32e -mlittle-endian # overwrite
LDFLAGS       += -melf32lriscv                    # overwrite
# LDFLAGS       += --print-map

AM_SRCS += riscv/ysyxSoC/libgcc/div.S \
           riscv/ysyxSoC/libgcc/muldi3.S \
           riscv/ysyxSoC/libgcc/multi3.c \
           riscv/ysyxSoC/libgcc/ashldi3.c \
           riscv/ysyxSoC/libgcc/unused.c
