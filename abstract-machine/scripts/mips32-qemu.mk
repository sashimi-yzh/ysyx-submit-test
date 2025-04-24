include $(AM_HOME)/scripts/isa/mips32.mk

AM_SRCS := mips/qemu/trm.c \
           mips/qemu/ioe.c \
           mips/qemu/timer.c \
           mips/qemu/start.S \
           mips/qemu/uart16550.c \
           platform/dummy/cte.c \
           platform/dummy/vme.c \
           platform/dummy/mpe.c

CFLAGS += -DMAINARGS=\"$(mainargs)\"
.PHONY: $(AM_HOME)/am/src/mips/qemu/trm.c

LDSCRIPTS += $(AM_HOME)/scripts/linker.ld
LDFLAGS   += --defsym=_pmem_start=0x80000000 --defsym=_entry_offset=0x0

image: image-dep

run: image
	qemu-system-mipsel -nographic -kernel $(IMAGE).elf -machine mips
