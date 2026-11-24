AM_SRCS := platform/soc/ioe.c \
           platform/soc/spiflash.c \
           platform/soc/uart.c \
           platform/soc/input.c \
           platform/soc/gpu.c \
           platform/soc/timer.c \
           platform/dummy/vme.c \
           platform/dummy/mpe.c

CFLAGS    += -fdata-sections -ffunction-sections -g
LDFLAGS   += -T $(AM_HOME)/scripts/linker.ld \
						 --defsym=_pmem_start=0x80000000 --defsym=_entry_offset=0x0
LDFLAGS   += --gc-sections -e _start
NPCFLAGS += -l $(shell dirname $(IMAGE).elf)/soc-log.txt
NPCFLAGS += -m $(shell dirname $(IMAGE).elf)/soc-log-mem.txt
NPCFLAGS += -f $(shell dirname $(IMAGE).elf)/soc-log-func.txt
NPCFLAGS += -x $(shell dirname $(IMAGE).elf)/soc-log-devmem.txt
NPCFLAGS += -e $(IMAGE).elf

# batch mode
NPCFLAGS += -b

CFLAGS += -DMAINARGS=\"$(mainargs)\"
CFLAGS += -I$(AM_HOME)/am/src/platform/soc/include
.PHONY: $(AM_HOME)/am/src/riscv/soc/trm.c

CONFIG_MTRACE_COMPRESS := y

image: $(IMAGE).elf
	$(OBJDUMP) -d $(IMAGE).elf > $(IMAGE).txt
	$(OBJDUMP) -S $(IMAGE).elf > $(IMAGE)_s.txt
	@echo + OBJCOPY "->" $(IMAGE_REL).bin
	@$(OBJCOPY) -S --set-section-flags .bss=alloc -O binary $(IMAGE).elf $(IMAGE).bin

run: image
	$(MAKE) -C $(NPC_HOME) ISA=$(ISA) run ARGS="$(NPCFLAGS)" IMG=$(IMAGE).bin

gdb:
	$(MAKE) -C $(NPC_HOME) ISA=$(ISA) gdb ARGS="$(NPCFLAGS)" IMG=$(IMAGE).bin

sim: image
	$(MAKE) -C $(NEMU_HOME) ISA=$(ISA) run ARGS="$(NPCFLAGS)" IMG=$(IMAGE).bin
ifdef CONFIG_ITRACE_COMPRESS
	$(NEMU_HOME)/../cachesim/cachesim build/soc-log.txt 16 1 4 --policy=fifo --bin
endif
ifdef CONFIG_MTRACE_COMPRESS
	$(NEMU_HOME)/../cachesim/cachesim build/soc-log-mem.txt 16 1 4 --policy=fifo --bin
endif