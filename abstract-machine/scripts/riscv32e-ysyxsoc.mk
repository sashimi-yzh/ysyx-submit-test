include $(AM_HOME)/scripts/isa/riscv.mk
include $(AM_HOME)/scripts/platform/soc.mk
CFLAGS  += -DISA_H=\"riscv/riscv.h\" -D_SOC_


COMMON_CFLAGS += -march=rv32e_zicsr_zifencei -mabi=ilp32e  # overwrite
LDFLAGS       += -melf32lriscv                    # overwrite

AM_SRCS += riscv/soc/libgcc/div.S \
           riscv/soc/libgcc/muldi3.S \
           riscv/soc/libgcc/multi3.c \
           riscv/soc/libgcc/ashldi3.c \
           riscv/soc/libgcc/unused.c
