CROSS_COMPILE := riscv64-linux-gnu-
COMMON_CFLAGS := -fno-pic -march=rv64g -mcmodel=medany -mstrict-align
CFLAGS        += $(COMMON_CFLAGS) -static
ASFLAGS       += $(COMMON_CFLAGS) -O0
LDFLAGS       += -melf64lriscv

# overwrite ARCH_H defined in $(AM_HOME)/Makefile
ARCH_H := arch/riscv.h

ifeq ($(PICOLIBC),1)
KLIB_PICOLIBC_HOME ?= /usr/lib/picolibc/riscv64-unknown-elf
KLIB_LIBC ?= $(KLIB_PICOLIBC_HOME)/lib/$(KLIB_PICOLIBC_MULTILIB)/libc.a
KLIB_LIBGCC ?= /usr/lib/gcc/riscv64-unknown-elf/10.2.0/$(KLIB_PICOLIBC_MULTILIB)/libgcc.a
CFLAGS += -D__KLIB_USE_PICOLIBC__ -isystem $(KLIB_PICOLIBC_HOME)/include
LINKAGE += $(KLIB_LIBC) $(KLIB_LIBGCC)
endif
