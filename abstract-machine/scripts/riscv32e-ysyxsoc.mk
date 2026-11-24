include $(AM_HOME)/scripts/isa/riscv.mk
include $(AM_HOME)/scripts/platform/ysyxsoc.mk
CFLAGS  += -DISA_H=\"riscv/riscv.h\"
COMMON_CFLAGS += -march=rv32e_zicsr -mabi=ilp32e  # overwrite
LDFLAGS       += -melf32lriscv -Map=output.map    # overwrite

AM_SRCS += riscv/soc/libgcc/div.S \
           riscv/soc/libgcc/muldi3.S \
           riscv/soc/libgcc/multi3.c \
           riscv/soc/libgcc/ashldi3.c \
           riscv/soc/libgcc/unused.c \
           riscv/soc/start.S \
           riscv/soc/trm.c \
           riscv/soc/trap.S \
           riscv/soc/cte.c \
