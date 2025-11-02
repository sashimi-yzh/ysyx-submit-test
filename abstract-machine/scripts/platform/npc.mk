CURPATH = $(dir $(filter %platform/npc.mk,$(MAKEFILE_LIST)))
ROOTPATH = $(abspath $(CURPATH)../../..)
NPC_HOME = $(ROOTPATH)/npc


AM_SRCS := riscv/npc/start.S \
           riscv/npc/trm.c \
           riscv/npc/ioe/ioe.c \
           riscv/npc/ioe/timer.c \
           riscv/npc/ioe/input.c \
		   riscv/npc/ioe/audio.c \
		   riscv/npc/ioe/gpu.c \
           riscv/npc/cte.c \
           riscv/npc/trap.S \
           platform/dummy/vme.c \
           platform/dummy/mpe.c

CFLAGS    += -fdata-sections -ffunction-sections
LDFLAGS   += -T $(AM_HOME)/scripts/linker.ld \
						 --defsym=_pmem_start=0x80000000 --defsym=_entry_offset=0x0
LDFLAGS   += --gc-sections -e _start
CFLAGS += -DMAINARGS=\"$(mainargs)\"
CFLAGS += -I$(AM_HOME)/am/src/riscv/npc/include


MAINARGS_MAX_LEN = 64
MAINARGS_PLACEHOLDER = The insert-arg rule in Makefile will insert mainargs here.
CFLAGS += -DMAINARGS_MAX_LEN=$(MAINARGS_MAX_LEN) -DMAINARGS_PLACEHOLDER=\""$(MAINARGS_PLACEHOLDER)"\"

insert-arg: image
	@python $(AM_HOME)/tools/insert-arg.py $(IMAGE).bin $(MAINARGS_MAX_LEN) "$(MAINARGS_PLACEHOLDER)" "$(mainargs)"



image: $(IMAGE).elf
	@$(OBJDUMP) -d $(IMAGE).elf > $(IMAGE).txt
	@echo + OBJCOPY "->" $(IMAGE_REL).bin
	@$(OBJCOPY) -S --set-section-flags .bss=alloc,contents -O binary $(IMAGE).elf $(IMAGE).bin


#$(MAKE) -C $(NPC_$(VERSION)_HOME) wave BIN=$(IMAGE).bin
#run: image
#	@echo "***** Execute target:run in $(CURPATH) *****"
#	@$(MAKE) -C $(NPC_HOME) sim-iverilog IMG=$(IMAGE)


run: insert-arg
	@echo "***** Execute target:run in $(CURPATH) *****"
	@$(MAKE) -C $(NPC_HOME) sim-iverilog IMG=$(IMAGE)
	#@$(MAKE) -C $(NPC_V4_HOME) wave BIN=$(IMAGE).bin ELF=$(IMAGE).elf

.PHONY: insert-arg
