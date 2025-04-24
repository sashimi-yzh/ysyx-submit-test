include $(AM_HOME)/scripts/isa/riscv.mk
COMMON_CFLAGS += -march=rv32g -mabi=ilp32  # overwrite
LDFLAGS       += -melf32lriscv             # overwrite

AM_SRCS := riscv/qemu/trm.c \
           riscv/qemu/ioe.c \
           riscv/qemu/timer.c \
           riscv/qemu/start.S \
           riscv/qemu/uart16550.c \
           platform/dummy/cte.c \
           platform/dummy/vme.c \
           platform/dummy/mpe.c

CFLAGS += -DMAINARGS=\"$(mainargs)\"
.PHONY: $(AM_HOME)/am/src/riscv/qemu/trm.c

LDSCRIPTS += $(AM_HOME)/scripts/linker.ld
LDFLAGS   += --defsym=_pmem_start=0x80000000 --defsym=_entry_offset=0x0

image: image-dep

run: image
	qemu-system-riscv32 -nographic -kernel $(IMAGE).elf -machine virt
