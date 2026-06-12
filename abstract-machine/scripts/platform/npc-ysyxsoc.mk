AM_SRCS := riscv/npc-ysyxsoc/start.S \
           riscv/npc-ysyxsoc/trm.c \
           riscv/npc-ysyxsoc/bootloader.c \
           riscv/npc-ysyxsoc/ioe/ioe.c \
           riscv/npc-ysyxsoc/ioe/gpu.c \
           riscv/npc-ysyxsoc/ioe/timer.c \
           riscv/npc-ysyxsoc/ioe/input.c \
           riscv/npc-ysyxsoc/ioe/uart.c \
           riscv/npc-ysyxsoc/cte.c \
           riscv/npc-ysyxsoc/trap.S \
           platform/dummy/vme.c \
           platform/dummy/mpe.c

CFLAGS    += -fdata-sections -ffunction-sections
# CFLAGS += -falign-functions=8 -falign-loops=8
CFLAGS += $(if $(AFDO),-fauto-profile=$(AFDO),)
LDSCRIPTS += $(AM_HOME)/scripts/linker-ysyxsoc.ld
LDSCRIPTS_MEM += $(AM_HOME)/scripts/linker-ysyxsoc-mem.ld
# LDFLAGS   += --defsym=_pmem_start=0x80000000 --defsym=_entry_offset=0x0
LDFLAGS   += --gc-sections -e _start -Map=$(IMAGE).map
ASFLAGS += -mno-relax -Wa,-mno-relax

MAINARGS_MAX_LEN = 64
MAINARGS_PLACEHOLDER = the_insert-arg_rule_in_Makefile_will_insert_mainargs_here
CFLAGS += -DMAINARGS_MAX_LEN=$(MAINARGS_MAX_LEN) -DMAINARGS_PLACEHOLDER=$(MAINARGS_PLACEHOLDER)

# export IMG = "$(IMAGE).bin"
export ADD_ARGS += --elf "$(IMAGE).elf" --flash "$(IMAGE).bin"
export BUILD_DIR = $(shell pwd)/build
export GDB_ELF = $(IMAGE).elf

insert-arg: image
	@python $(AM_HOME)/tools/insert-arg.py $(IMAGE).bin $(MAINARGS_MAX_LEN) $(MAINARGS_PLACEHOLDER) "$(mainargs)"

image: image-dep
	@$(OBJDUMP) -d $(IMAGE).elf > $(IMAGE).txt
	@echo + OBJCOPY "->" $(IMAGE_REL).bin
	@$(OBJCOPY) -S -O binary $(IMAGE).elf $(IMAGE).bin

run: insert-arg
	$(MAKE) -C $(NPC_HOME) run 

gdb: insert-arg
	$(MAKE) -C $(NPC_HOME) gdb

runbatch: ADD_ARGS += -b
runbatch: export AM_GDB_FLAGS += --batch -ex "continue"
runbatch: insert-arg
	$(MAKE) -C $(NPC_HOME) runbatch 

.PHONY: insert-arg
