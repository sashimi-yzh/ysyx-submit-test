AM_SRCS := riscv/ysyxSoC/start.S \
           riscv/ysyxSoC/trm.c \
           riscv/ysyxSoC/ioe.c \
           riscv/ysyxSoC/timer.c \
           riscv/ysyxSoC/input.c \
           riscv/ysyxSoC/gpu.c \
           riscv/ysyxSoC/cte.c \
           riscv/ysyxSoC/trap.S \
           platform/dummy/vme.c \
           platform/dummy/mpe.c

      
# AM_HOME = $(YSYX_HOME)/abstract-machine
YSYXSOC_HOME  = $(YSYX_HOME)/ysyxSoC
CFLAGS    += -fdata-sections -ffunction-sections
CFLAGS    += -I$(AM_HOME)/am/src/riscv/ysyxSoC/include
LDSCRIPTS += $(AM_HOME)/scripts/linker_soc.ld
# LDFLAGS   += --defsym=_pmem_start=0x0f000000 --defsym=_entry_offset=0x0
LDFLAGS   += --gc-sections -e _start
YSYXSOCFLAGS += -l $(shell dirname $(IMAGE).elf)/ysyxSoC-log.txt
YSYXSOCFLAGS += -f $(IMAGE).elf
YSYXSOCFLAGS  += -b
YSYXSOCFLAGS  += -d /home/dengzibin/ysyx-workbench/ysyxSoC/csrc/src/tools/nemu-diff/build/riscv32-nemu-interpreter-so

MAINARGS_MAX_LEN = 64
MAINARGS_PLACEHOLDER = The insert-arg rule in Makefile will insert mainargs here.
CFLAGS += -DMAINARGS_MAX_LEN=$(MAINARGS_MAX_LEN) -DMAINARGS_PLACEHOLDER=\""$(MAINARGS_PLACEHOLDER)"\"

insert-arg: image
	@python3 $(AM_HOME)/tools/insert-arg.py $(IMAGE).bin $(MAINARGS_MAX_LEN) "$(MAINARGS_PLACEHOLDER)" "$(mainargs)"

image: image-dep
	@$(OBJDUMP) -d $(IMAGE).elf > $(IMAGE).txt
	@echo + OBJCOPY "->" $(IMAGE_REL).bin
	@$(OBJCOPY) -O binary $(IMAGE).elf $(IMAGE).bin

run: insert-arg
	$(MAKE) -C $(YSYXSOC_HOME) ISA=$(ISA) run ARGS="$(YSYXSOCFLAGS)" IMG=$(IMAGE).bin

nvboard: insert-arg
	$(MAKE) -C $(YSYXSOC_HOME) ISA=$(ISA) nvboard ARGS="$(YSYXSOCFLAGS)" IMG=$(IMAGE).bin

.PHONY: insert-arg

#	@$(OBJCOPY) -O binary --only-section=.entry --only-section=.copy_routine --only-section=.main_text --only-section=.rodata --only-section=.srodata* --only-section=.data $(IMAGE).elf $(IMAGE).bin