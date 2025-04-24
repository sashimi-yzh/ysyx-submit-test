include $(AM_HOME)/scripts/isa/riscv.mk
include $(AM_HOME)/scripts/platform/npc.mk
COMMON_CFLAGS += -march=rv32e_zicsr_zifencei -mabi=ilp32e  # overwrite
LDSCRIPTS     := $(subst $(AM_HOME)/scripts/linker.ld,$(AM_HOME)/am/src/riscv/ysyxsoc/linker.ld,$(LDSCRIPTS))
LDFLAGS       := $(filter-out --defsym=%,$(LDFLAGS))
LDFLAGS       += -melf32lriscv

AM_SRCS := riscv/ysyxsoc/start.S \
           riscv/ysyxsoc/trm.c \
           riscv/ysyxsoc/ioe.c \
           riscv/npc/timer.c \
           riscv/ysyxsoc/input.c \
           riscv/ysyxsoc/gpu.c \
           riscv/npc/cte.c \
           riscv/npc/trap.S \
           platform/dummy/vme.c \
           platform/dummy/mpe.c

AM_SRCS += riscv/npc/libgcc/div.S \
           riscv/npc/libgcc/muldi3.S \
           riscv/npc/libgcc/multi3.c \
           riscv/npc/libgcc/ashldi3.c \
           riscv/npc/libgcc/unused.c
