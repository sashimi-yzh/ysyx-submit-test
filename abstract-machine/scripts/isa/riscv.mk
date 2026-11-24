HOST_OS_FAMILY := $(strip $(shell if [ -r /etc/os-release ]; then . /etc/os-release && echo $$ID $$ID_LIKE; fi))

ifneq ($(filter ubuntu debian,$(HOST_OS_FAMILY)),)
	CROSS_COMPILE ?= riscv64-linux-gnu-
else
	CROSS_COMPILE ?= riscv-none-elf-
endif

COMMON_CFLAGS := -fno-pic -march=rv64g -mcmodel=medany -mstrict-align
CFLAGS        += $(COMMON_CFLAGS) -static
ASFLAGS       += $(COMMON_CFLAGS) -O0
LDFLAGS       += -melf64lriscv

# overwrite ARCH_H defined in $(AM_HOME)/Makefile
ARCH_H := arch/riscv.h
