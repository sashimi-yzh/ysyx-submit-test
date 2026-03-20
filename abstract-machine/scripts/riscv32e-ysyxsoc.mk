include $(AM_HOME)/scripts/isa/riscv.mk
include $(AM_HOME)/scripts/platform/ysyxsoc.mk
# COMMON_CFLAGS += -march=rv32i_zicsr -mabi=ilp32  # overwrite
COMMON_CFLAGS += -march=rv32e$(RISCV_MARCH_EXT_CSRS_AND_FENCE_I) -mabi=ilp32e  # overwrite
LDFLAGS       += -melf32lriscv                    # overwrite

AM_SRCS += riscv/npc/libgcc/div.S \
           riscv/npc/libgcc/muldi3.S \
           riscv/npc/libgcc/multi3.c \
           riscv/npc/libgcc/ashldi3.c \
           riscv/npc/libgcc/unused.c
