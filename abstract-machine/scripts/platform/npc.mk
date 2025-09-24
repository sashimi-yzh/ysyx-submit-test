AM_SRCS := riscv/npc/start.S \
           riscv/npc/trm.c \
           riscv/npc/ioe.c \
           riscv/npc/timer.c \
           riscv/npc/input.c \
           riscv/npc/cte.c \
           riscv/npc/trap.S \
           platform/dummy/vme.c \
           platform/dummy/mpe.c

CFLAGS    += -fdata-sections -ffunction-sections
LDFLAGS   += -T $(AM_HOME)/scripts/linker.ld \
						 --defsym=_pmem_start=0x80000000 --defsym=_entry_offset=0x0 \
						#  --print-map
						 --defsym=_pmem_start=0x80000000 --defsym=_entry_offset=0x0 \
						#  --print-map
LDFLAGS   += --gc-sections -e _start
NPCFLAGS += -l $(shell dirname $(IMAGE).elf)/npc-log.txt
NPCFLAGS += -t $(shell dirname $(IMAGE).elf)/trace-log.txt
NPCFLAGS += -e $(IMAGE).elf
NPCFLAGS += -c $(shell dirname $(IMAGE).elf)/perf-log.txt
NPCFLAGS += -c $(shell dirname $(IMAGE).elf)/perf-log.txt

CFLAGS += -DMAINARGS=\"$(mainargs)\"
.PHONY: $(AM_HOME)/am/src/riscv/npc/trm.c

image: $(IMAGE).elf
	@$(OBJDUMP) -d $(IMAGE).elf > $(IMAGE).txt
	@echo + OBJCOPY "->" $(IMAGE_REL).bin
	@$(OBJCOPY) -S --set-section-flags .bss=alloc,contents -O binary $(IMAGE).elf $(IMAGE).bin
	@$(OBJCOPY) -S --set-section-flags .bss=alloc,contents --adjust-vma -0x80000000 -O verilog $(IMAGE).elf $(IMAGE).vbin

run: image
	$(MAKE) -C $(NPC_HOME) sim ARGS="$(NPCFLAGS) -b" IMG=$(IMAGE).bin CONFIG_NPC=1 MEM_FILE=$(IMAGE).vbin

iverilog: image
	$(MAKE) -C $(NPC_HOME) iverilog CONFIG_NPC=1 \
	MEM_FILE=$(IMAGE).vbin \
	LOG_FILE=$(shell dirname $(IMAGE).elf)/iv-npc-log.txt \
	REF_FILE=$(shell dirname $(IMAGE).elf)/../alog/npc-log.txt

netlist: image
	$(MAKE) -C $(NPC_HOME) netlist CONFIG_NPC=1 \
	MEM_FILE=$(IMAGE).vbin \
	LOG_FILE=$(shell dirname $(IMAGE).elf)/iv-npc-log.txt \
	REF_FILE=$(shell dirname $(IMAGE).elf)/../alog/npc-log.txt

perf: image
	$(MAKE) -C $(NPC_HOME) sim ARGS="$(NPCFLAGS) -b" IMG=$(IMAGE).bin CONFIG_PERF=1 CONFIG_NPC=1

wave: image
	$(MAKE) -C $(NPC_HOME) wave ARGS="$(NPCFLAGS) -b" IMG=$(IMAGE).bin CONFIG_NPC=1
	$(MAKE) -C $(NPC_HOME) wave ARGS="$(NPCFLAGS) -b" IMG=$(IMAGE).bin CONFIG_NPC=1

sdb: image
	$(MAKE) -C $(NPC_HOME) sim ARGS="$(NPCFLAGS)" IMG=$(IMAGE).bin CONFIG_NPC=1
	$(MAKE) -C $(NPC_HOME) sim ARGS="$(NPCFLAGS)" IMG=$(IMAGE).bin CONFIG_NPC=1
