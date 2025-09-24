AM_SRCS := riscv/ysyxsoc/start.S \
           riscv/ysyxsoc/trm.c \
           riscv/ysyxsoc/ioe.c \
           riscv/ysyxsoc/timer.c \
           riscv/ysyxsoc/input.c \
           riscv/ysyxsoc/cte.c \
           riscv/ysyxsoc/trap.S \
           platform/dummy/vme.c \
           platform/dummy/mpe.c

CFLAGS    += -fdata-sections -ffunction-sections -mstrict-align
LDFLAGS   += -T $(AM_HOME)/scripts/linker-ysyxsoc.ld \
						 --defsym=_mrom_start=0x20000000 --defsym=_entry_offset=0x0 \
						 --defsym=_flash_start=0x30000000 \
						 --defsym=_sram_start=0x0f000000 \
						 --defsym=_psram_start=0x80000000 \
						 --defsym=_sdram_start=0xa0000000 \
						#  --print-map
LDFLAGS   += --gc-sections -e _start
YSYXSOCFLAGS += -l $(shell dirname $(IMAGE).elf)/ysyxsoc-log.txt
YSYXSOCFLAGS += -t $(shell dirname $(IMAGE).elf)/trace-log.txt
YSYXSOCFLAGS += -e $(IMAGE).elf
YSYXSOCFLAGS += -c $(shell dirname $(IMAGE).elf)/perf-log.txt

CFLAGS += -DMAINARGS=\"$(mainargs)\"
.PHONY: $(AM_HOME)/am/src/riscv/ysyxsoc/trm.c

image: $(IMAGE).elf
	@$(OBJDUMP) -d $(IMAGE).elf > $(IMAGE).txt
	@echo + OBJCOPY "->" $(IMAGE_REL).bin
	@$(OBJCOPY) -S -O binary $(IMAGE).elf $(IMAGE).bin

run: image
	$(MAKE) -C $(NPC_HOME) sim ARGS="$(YSYXSOCFLAGS) -b" IMG=$(IMAGE).bin

perf: image
	$(MAKE) -C $(NPC_HOME) sim ARGS="$(YSYXSOCFLAGS) -b" IMG=$(IMAGE).bin CONFIG_PERF=1

wave: image
	$(MAKE) -C $(NPC_HOME) wave ARGS="$(YSYXSOCFLAGS) -b" IMG=$(IMAGE).bin

sdb: image
	$(MAKE) -C $(NPC_HOME) sim ARGS="$(YSYXSOCFLAGS)" IMG=$(IMAGE).bin
