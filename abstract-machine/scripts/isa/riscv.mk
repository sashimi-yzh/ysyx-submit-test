# CROSS_COMPILE := riscv64-linux-gnu-
# CROSS_COMPILE := riscv64-unknown-elf
CROSS_COMPILE := riscv64-linux-gnu-
COMMON_CFLAGS := -fno-pic -march=rv32im -mcmodel=medany -mstrict-align
CFLAGS        += $(COMMON_CFLAGS) -static
ASFLAGS       += $(COMMON_CFLAGS) -O0
LDFLAGS       += -melf32lriscv

# overwrite ARCH_H defined in $(AM_HOME)/Makefile
ARCH_H := arch/riscv.h
