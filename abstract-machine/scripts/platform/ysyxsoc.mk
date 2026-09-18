AM_SRCS = riscv/ysyxsoc/start.S \
		  riscv/ysyxsoc/start_ss.S \
		  riscv/ysyxsoc/trm.c \
		  riscv/ysyxsoc/trap.S \
		  riscv/ysyxsoc/ioe.c \
		  riscv/ysyxsoc/timer.c \
		  riscv/ysyxsoc/input.c \
		  riscv/ysyxsoc/gpu.c \
		  riscv/ysyxsoc/cte.c \
		  platform/dummy/vme.c \
		  platform/dummy/mpe.c

CFLAGS	+= -O3 -fdata-sections -ffunction-sections
LDSCRIPTS += $(AM_HOME)/scripts/ysyxsoc.ld
LDFLAGS	+= --defsym=_pmem_start=0x30000000 --defsym=_entry_offset=0x0
LDFLAGS	+= --gc-sections -e _start
YSYXSOCFLAGS  +=

DUMP = $(shell find ./ysyxsoc -name "wave.fst")

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
	@echo "Passing IMG = $(abspath $(IMAGE).bin) to YSYXSOC"
	$(MAKE)	-C $(NPC_HOME) run CONFIG_SOC=y ARGS="$(YSYXSOCFLAGS)" IMG=$(abspath $(IMAGE).bin) ELF=$(abspath $(IMAGE).elf)

wave:
	surfer $(DUMP) &

.PHONY: insert-arg wave