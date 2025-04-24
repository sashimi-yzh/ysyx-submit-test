include $(AM_HOME)/scripts/isa/riscv.mk

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

LDFLAGS += -T $(AM_HOME)/scripts/linker.ld --defsym=_pmem_start=0x80000000 --defsym=_entry_offset=0x0

image: image-dep
	@$(OBJDUMP) -d $(IMAGE).elf > $(IMAGE).txt
	@echo + OBJCOPY "->" $(IMAGE_REL).bin
	@$(OBJCOPY) -S --set-section-flags .bss=alloc,contents -b 0 -i 1 --interleave-width=1 -O binary $(IMAGE).elf $(IMAGE).bin

run: image
	qemu-system-riscv64 -nographic -bios none -kernel $(IMAGE).elf -machine virt
