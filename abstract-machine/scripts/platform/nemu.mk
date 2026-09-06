AM_SRCS := platform/nemu/trm.c \
           platform/nemu/ioe/ioe.c \
           platform/nemu/ioe/timer.c \
           platform/nemu/ioe/input.c \
           platform/nemu/ioe/gpu.c \
           platform/nemu/ioe/audio.c \
           platform/nemu/ioe/disk.c \
           platform/nemu/mpe.c

LDSCRIPT  ?= $(AM_HOME)/scripts/linker.ld
ENTRY     ?= _start

CFLAGS    += -fdata-sections -ffunction-sections
LDFLAGS   += -T $(LDSCRIPT) \
             --defsym=_pmem_start=0x80000000 --defsym=_entry_offset=0x0
LDFLAGS   += --gc-sections -e $(ENTRY)
NEMUFLAGS += -l $(shell dirname $(IMAGE).elf)/nemu-log.txt -f$(IMAGE).elf
# NEMUFLAGS += -b
# NEMUFLAGS += -k
# NEMUFLAGS += -g 10000

CFLAGS += -I$(AM_HOME)/am/src/platform/nemu/include
.PHONY: $(AM_HOME)/am/src/platform/nemu/trm.c

MAINARGS_MAX_LEN = 64
MAINARGS_PLACEHOLDER = the_insert-arg_rule_in_Makefile_will_insert_mainargs_here
CFLAGS += -DMAINARGS_MAX_LEN=$(MAINARGS_MAX_LEN) -DMAINARGS_PLACEHOLDER=$(MAINARGS_PLACEHOLDER)

insert-arg: image
	@python $(AM_HOME)/tools/insert-arg.py $(IMAGE).bin $(MAINARGS_MAX_LEN) $(MAINARGS_PLACEHOLDER) "$(mainargs)"

image: $(IMAGE).elf
	@$(OBJDUMP) -d $(IMAGE).elf > $(IMAGE).txt
	@echo + OBJCOPY "->" $(IMAGE_REL).bin
	@$(OBJCOPY) -S --set-section-flags .bss=alloc,contents -O binary $(IMAGE).elf $(IMAGE).bin

run: insert-arg
	$(MAKE) -C $(NEMU_HOME) ISA=$(ISA) run ARGS="$(NEMUFLAGS)" IMG=$(IMAGE).bin

gdb: image
	$(MAKE) -C $(NEMU_HOME) ISA=$(ISA) gdb ARGS="$(NEMUFLAGS)" IMG=$(IMAGE).bin

perf: image
	$(MAKE) -C $(NEMU_HOME) ISA=$(ISA) perf ARGS="$(NEMUFLAGS)" IMG=$(IMAGE).bin
