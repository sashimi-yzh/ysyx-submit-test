include $(AM_HOME)/scripts/isa/riscv.mk
include $(AM_HOME)/scripts/platform/soc_nbl.mk
# include $(AM_HOME)/scripts/platform/nemu.mk

CFLAGS  += -DISA_H=\"riscv/riscv.h\"

COMMON_CFLAGS += -march=rv32e_zicsr -mabi=ilp32e  # overwrite
LDFLAGS       += -melf32lriscv                    # overwrite

AM_SRCS += riscv/soc_nbl/libgcc/div.S \
           riscv/soc_nbl/libgcc/muldi3.S \
           riscv/soc_nbl/libgcc/multi3.c \
           riscv/soc_nbl/libgcc/ashldi3.c \
           riscv/soc_nbl/libgcc/unused.c
