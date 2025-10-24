AM_SRCS := riscv/ysyxsoc/start.S \
           riscv/ysyxsoc/trm.c \
           riscv/ysyxsoc/ioe.c \
           riscv/ysyxsoc/timer.c \
           riscv/ysyxsoc/input.c \
           riscv/ysyxsoc/cte.c \
           riscv/ysyxsoc/trap.S \
           platform/dummy/vme.c \
           platform/dummy/mpe.c \
\
		   riscv/ysyxsoc/bootloader.c \
		   riscv/ysyxsoc/gpu.c \


CFLAGS    += -fdata-sections -ffunction-sections
LDFLAGS   += -T $(AM_HOME)/scripts/linkerysyxsoc.ld \
						 --defsym=_pmem_start=0x20000000 --defsym=_entry_offset=0x0 \
						 --defsym=_sram_start=0x0f000000 --defsym=_sram_size=0x2000 \
						#  --print-map
LDFLAGS   += --gc-sections -e _start
CFLAGS += -DMAINARGS=\"$(mainargs)\"

NPC_CHISEL_HOME = $(AM_HOME)/../npc

NPCFLAGS += -l $(shell dirname $(IMAGE).elf)/npc-log.txt
NPCFLAGS += -b
NPCFLAGS += -e $(IMAGE).elf

NPCFLAGS += -d $(NPC_HOME)/riscv32-nemu-interpreter-so_ysyxsoc_new

.PHONY: $(AM_HOME)/am/src/riscv/ysyxsoc/trm.c

image: $(IMAGE).elf
	@$(OBJDUMP) -d $(IMAGE).elf > $(IMAGE).txt
	@echo + OBJCOPY "->" $(IMAGE_REL).bin
	@$(OBJCOPY) -S --set-section-flags .bss=alloc,contents -O binary $(IMAGE).elf $(IMAGE).bin


run: image
	$(MAKE) -C $(NPC_CHISEL_HOME) run ARGS="$(NPCFLAGS)" IMG=$(IMAGE).bin
