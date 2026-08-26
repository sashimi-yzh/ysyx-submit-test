include $(AM_HOME)/scripts/isa/riscv.mk
include $(AM_HOME)/scripts/platform/jyd.mk
COMMON_CFLAGS += -march=rv32im_zicsr -mabi=ilp32   # overwrite
LDFLAGS       += -melf32lriscv                    # overwrite

AM_SRCS += riscv/jyd/libgcc/div.S \
           riscv/jyd/libgcc/muldi3.S \
           riscv/jyd/libgcc/multi3.c \
           riscv/jyd/libgcc/ashldi3.c \
           riscv/jyd/libgcc/unused.c