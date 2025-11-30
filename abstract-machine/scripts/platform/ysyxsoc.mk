AM_SRCS := riscv/ysyxsoc/start.S \
           riscv/ysyxsoc/trm.c \
           riscv/ysyxsoc/ioe.c \
					 riscv/ysyxsoc/gpu.c \
           riscv/ysyxsoc/timer.c \
					 riscv/ysyxsoc/input.c \
           riscv/ysyxsoc/cte.c \
           riscv/ysyxsoc/trap.S \
           riscv/ysyxsoc/uart.c \
					 platform/dummy/vme.c \
           platform/dummy/mpe.c

CFLAGS    += -fdata-sections -ffunction-sections
CFLAGS		+= -freorder-functions	#hot函数
LDFLAGS   += -T $(AM_HOME)/scripts/linker-ysyxsoc.ld \
             --defsym=_pmem_start=0x30000000 --defsym=_entry_offset=0x0
						 #--script=$(AM_HOME)/scripts/linker-ysyxsoc.ld \
						 --defsym=_pmem_start=0x30000000 --defsym=_entry_offset=0x0
LDFLAGS   += --gc-sections -e _start
CFLAGS += -DMAINARGS=\"$(mainargs)\"
.PHONY: $(AM_HOME)/am/src/riscv/ysyxsoc/trm.c

image: $(IMAGE).elf
	@$(OBJDUMP) -d $(IMAGE).elf > $(IMAGE).txt
	@echo + OBJCOPY "->" $(IMAGE_REL).bin
	@$(OBJCOPY) -S --set-section-flags .bss=alloc,contents -O binary $(IMAGE).elf $(IMAGE).bin

run: image
	$(MAKE) -C $(NPC_HOME)	run IMG=$(IMAGE).bin ELF=$(IMAGE).elf

gdb: image
	$(MAKE) -C $(NPC_HOME)	run IMG=$(IMAGE).bin ELF=$(IMAGE).elf
