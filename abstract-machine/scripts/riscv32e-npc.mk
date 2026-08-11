include $(AM_HOME)/scripts/isa/riscv.mk
include $(AM_HOME)/scripts/platform/npc.mk
#COMMON_CFLAGS += -march=rv32e_zicsr -mabi=ilp32e # overwrite
#LDFLAGS       += -melf32lriscv                    # overwrite
KLIB_PICOLIBC_MULTILIB := rv32e/ilp32e
COMMON_CFLAGS += -march=rv32e_zicsr_zifencei -mabi=ilp32e  
LDFLAGS       += -melf32lriscv                  

AM_SRCS += riscv/npc/libgcc/div.S \
           riscv/npc/libgcc/muldi3.S \
           riscv/npc/libgcc/multi3.c \
           riscv/npc/libgcc/ashldi3.c \
           riscv/npc/libgcc/unused.c
