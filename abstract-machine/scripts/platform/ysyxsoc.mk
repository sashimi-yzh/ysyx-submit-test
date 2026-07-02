AM_SRCS := riscv/ysyxsoc/start.S \
           riscv/ysyxsoc/trm.c \
           riscv/ysyxsoc/ioe.c \
           riscv/ysyxsoc/gpu.c \
           riscv/ysyxsoc/timer.c \
           riscv/ysyxsoc/input.c \
           riscv/ysyxsoc/cte.c \
           riscv/ysyxsoc/trap.S \
           riscv/ysyxsoc/vme.c \
           riscv/ysyxsoc/mpe.c

CFLAGS    += -fdata-sections -ffunction-sections
LDSCRIPTS += $(AM_HOME)/scripts/linker-ysyxsoc.ld
LDFLAGS   += --defsym=_pmem_start=0x30000000 --defsym=_entry_offset=0x0
LDFLAGS   += --gc-sections -e _start

YSYXSOCFLAGS += -l $(shell dirname $(IMAGE).elf)/npc-log.txt
YSYXSOCFLAGS += -f $(IMAGE).elf
YSYXSOCFLAGS += -F $(shell dirname $(IMAGE).elf)/npc-ftrace.txt
YSYXSOCFLAGS += -E $(shell dirname $(IMAGE).elf)/npc-etrace.txt
YSYXSOCFLAGS += -M $(shell dirname $(IMAGE).elf)/npc-mtrace.txt
YSYXSOCFLAGS += -D $(shell dirname $(IMAGE).elf)/npc-dtrace.txt

DEBUG ?= 0
ifeq ($(filter 1 y yes true,$(DEBUG)),)
YSYXSOCFLAGS += -b
endif
MAINARGS_MAX_LEN = 64
MAINARGS_PLACEHOLDER = the_insert-arg_rule_in_Makefile_will_insert_mainargs_here
CFLAGS += -DMAINARGS_MAX_LEN=$(MAINARGS_MAX_LEN) -DMAINARGS_PLACEHOLDER=$(MAINARGS_PLACEHOLDER)

insert-arg: image
	@python $(AM_HOME)/tools/insert-arg.py $(IMAGE).bin $(MAINARGS_MAX_LEN) $(MAINARGS_PLACEHOLDER) "$(mainargs)"

image: image-dep
	@$(OBJDUMP) -d $(IMAGE).elf > $(IMAGE).txt
	@echo + OBJCOPY "->" $(IMAGE_REL).bin
	@$(OBJCOPY) -S -O binary $(IMAGE).elf $(IMAGE).bin

run: insert-arg
	$(MAKE) -C $(NPC_HOME) SIM_MODE=ysyxsoc sim ARGS="$(YSYXSOCFLAGS)" IMG="$(IMAGE).bin"

.PHONY: insert-arg
