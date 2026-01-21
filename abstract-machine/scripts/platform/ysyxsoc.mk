AM_SRCS := riscv/ysyxsoc/start.S \
           riscv/ysyxsoc/ioe/ioe.c \
           riscv/ysyxsoc/ioe/timer.c \
           riscv/ysyxsoc/ioe/uart.c \
           riscv/ysyxsoc/ioe/input.c \
           riscv/ysyxsoc/ioe/gpu.c \
           riscv/ysyxsoc/cte.c \
           riscv/ysyxsoc/trap.S \
           riscv/ysyxsoc/trm.c \
		   riscv/ysyxsoc/spi.c \
		   riscv/ysyxsoc/gpio.c \
           platform/dummy/vme.c \
           platform/dummy/mpe.c

CFLAGS    += -fdata-sections -ffunction-sections
LDSCRIPTS += $(AM_HOME)/scripts/linker_soc.ld
LDFLAGS   += --defsym=_pmem_start=0x30000000 --defsym=_entry_offset=0x0 
LDFLAGS   += --gc-sections -e _start
IMAGE_NAME = $(basename $(notdir $(IMAGE)))
override NPCFLAGS += -l $(shell dirname $(IMAGE).elf)/ysyxsoc-log.txt \
                     -i $(IMAGE).bin \
                     -d $(NEMU_HOME)/build/riscv32-nemu-interpreter-so \
                     -p 1234 \
                     -e $(IMAGE).elf \
                     -g $(shell dirname $(IMAGE).elf)/ysyxsoc-ftracerlog.txt \
					 -b 

MAINARGS_MAX_LEN = 64
MAINARGS_PLACEHOLDER = the_insert-arg_rule_in_Makefile_will_insert_mainargs_here
CFLAGS += -DMAINARGS_MAX_LEN=$(MAINARGS_MAX_LEN) -DMAINARGS_PLACEHOLDER=$(MAINARGS_PLACEHOLDER)

insert-arg: image
	@python $(AM_HOME)/tools/insert-arg.py $(IMAGE).bin $(MAINARGS_MAX_LEN) $(MAINARGS_PLACEHOLDER) "$(mainargs)"

image: image-dep
	@$(OBJDUMP) -d $(IMAGE).elf > $(IMAGE).txt
	@echo + OBJCOPY "->" $(IMAGE_REL).bin
	@$(OBJCOPY) -S --set-section-flags .bss=alloc,contents -O binary $(IMAGE).elf $(IMAGE).bin

run: insert-arg
	@$(MAKE) -C $(NPC_HOME) run ARGS="$(NPCFLAGS)"

gdb: insert-arg
	@$(MAKE) -C $(NPC_HOME) gdb ARGS="$(NPCFLAGS)"

wave: insert-arg
	@$(MAKE) -C $(NPC_HOME) wave ARGS="$(NPCFLAGS)"

# nemu: insert-arg
# 	@$(MAKE) -C $(NEMU_HOME) run ARGS="$(NPCFLAGS) -t $(IMAGE)_itrace.bin"

.PHONY: insert-arg
