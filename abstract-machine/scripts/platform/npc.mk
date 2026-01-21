AM_SRCS := riscv/npc/start.S \
           riscv/npc/trm.c \
           riscv/npc/ioe.c \
           riscv/npc/uart.c \
           riscv/npc/gpu.c \
           riscv/npc/timer.c \
           riscv/npc/input.c \
           riscv/npc/cte.c \
           riscv/npc/trap.S \
           platform/dummy/vme.c \
           platform/dummy/mpe.c

CFLAGS    += -fdata-sections -ffunction-sections
LDSCRIPTS += $(AM_HOME)/scripts/linker_nemu.ld
LDFLAGS   += --defsym=_pmem_start=0x80000000 --defsym=_entry_offset=0x0
LDFLAGS   += --gc-sections -e _start
IMAGE_NAME = $(basename $(notdir $(IMAGE)))
# override NPCFLAGS += -l $(shell dirname $(IMAGE).elf)/npc-$(IMAGE_NAME)-log.txt \
#                      -i $(IMAGE).bin \
#                      -d $(NEMU_HOME)/build/riscv32-nemu-interpreter-so \
#                      -p 1234 \
#                      -e $(IMAGE).elf \
#                      -g $(shell dirname $(IMAGE).elf)/npc-$(IMAGE_NAME)-ftracerlog.txt \
#                      -b

MAINARGS_MAX_LEN = 64
MAINARGS_PLACEHOLDER = the_insert-arg_rule_in_Makefile_will_insert_mainargs_here
CFLAGS += -DMAINARGS_MAX_LEN=$(MAINARGS_MAX_LEN) -DMAINARGS_PLACEHOLDER=$(MAINARGS_PLACEHOLDER)

insert-arg: image-temp
	@file -b $(IMAGE).bin | grep -q data || echo "$(IMAGE).bin is not binary(data)";
	@@python $(AM_HOME)/tools/insert-arg.py $(IMAGE).bin $(MAINARGS_MAX_LEN) $(MAINARGS_PLACEHOLDER) "$(mainargs)"

image-temp: image-dep
	@$(OBJDUMP) -d $(IMAGE).elf > $(IMAGE).txt
	@echo + OBJCOPY "->" $(IMAGE_REL).bin
	@$(OBJCOPY) -S --set-section-flags .bss=alloc,contents -O binary $(IMAGE).elf $(IMAGE).bin

image: insert-arg

run: insert-arg
	@$(MAKE) -C $(NPC_HOME) sim-iverilog IMG="$(IMAGE).bin"

# gdb: insert-arg
# 	@$(MAKE) -C $(NPC_HOME) gdb ARGS="$(NPCFLAGS)"

# wave: insert-arg
# 	@$(MAKE) -C $(NPC_HOME) wave ARGS="$(NPCFLAGS)"

.PHONY: insert-arg
