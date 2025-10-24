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
LDFLAGS   += -T $(AM_HOME)/scripts/linkernpc.ld \
						 --defsym=_pmem_start=0x80000000 --defsym=_entry_offset=0x0 \
						 --defsym=_sram_start=0x0f000000 --defsym=_sram_size=0x2000
LDFLAGS   += --gc-sections -e _start
# CFLAGS += -DMAINARGS=\"$(mainargs)\"


MAINARGS_MAX_LEN = 64
MAINARGS_PLACEHOLDER = The insert-arg rule in Makefile will insert mainargs here.
CFLAGS += -DMAINARGS_MAX_LEN=$(MAINARGS_MAX_LEN) -DMAINARGS_PLACEHOLDER=\""$(MAINARGS_PLACEHOLDER)"\"

insert-arg: image
	@python $(AM_HOME)/tools/insert-arg.py $(IMAGE).bin $(MAINARGS_MAX_LEN) "$(MAINARGS_PLACEHOLDER)" "$(mainargs)"

NPC_CHISEL_HOME = $(AM_HOME)/../npc

NPCFLAGS += -l $(shell dirname $(IMAGE).elf)/npc-log.txt
NPCFLAGS += -b
NPCFLAGS += -e $(IMAGE).elf

NPCFLAGS += -d $(NPC_HOME)/riscv32-nemu-interpreter-so_npc_new

# .PHONY: $(AM_HOME)/am/src/riscv/npc/trm.c

image: $(IMAGE).elf
	@$(OBJDUMP) -d $(IMAGE).elf > $(IMAGE).txt
	@echo + OBJCOPY "->" $(IMAGE_REL).bin
	@$(OBJCOPY) -S --set-section-flags .bss=alloc,contents -O binary $(IMAGE).elf $(IMAGE).bin

# run: image
run: insert-arg
	$(MAKE) -C $(NPC_CHISEL_HOME) run ARGS="$(NPCFLAGS)" IMG=$(IMAGE).bin

.PHONY: insert-arg