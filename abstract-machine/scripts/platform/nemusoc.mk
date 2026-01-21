AM_SRCS := platform/nemusoc/start.S \
           platform/nemusoc/trm.c \
           platform/nemusoc/timer.c \
           platform/nemu/ioe/ioe.c \
           platform/nemu/ioe/input.c \
           platform/nemu/ioe/gpu.c \
           platform/nemu/ioe/audio.c \
           platform/nemu/ioe/disk.c \
           platform/nemu/mpe.c

CFLAGS    += -fdata-sections -ffunction-sections
CFLAGS    += -I$(AM_HOME)/am/src/platform/nemu/include
LDSCRIPTS += $(AM_HOME)/scripts/linker_soc.ld
LDFLAGS   += --defsym=_pmem_start=0x30000000 --defsym=_entry_offset=0x0
LDFLAGS   += --gc-sections -e _start
override NEMUFLAGS += -l $(shell dirname $(IMAGE).elf)/nemu-log.txt  \
                      -r $(shell dirname $(IMAGE).elf)/tracer.bin  \
                      -k $(shell dirname $(IMAGE).elf)/nemu-dtracer-log.txt \
                      -b

MAINARGS_MAX_LEN = 64
MAINARGS_PLACEHOLDER = the_insert-arg_rule_in_Makefile_will_insert_mainargs_here
CFLAGS += -DMAINARGS_MAX_LEN=$(MAINARGS_MAX_LEN) -DMAINARGS_PLACEHOLDER=$(MAINARGS_PLACEHOLDER)

insert-arg: image
	@file -b $(IMAGE).bin | grep -q data || echo "$(IMAGE).bin is not binary(data)"
	@python $(AM_HOME)/tools/insert-arg.py $(IMAGE).bin $(MAINARGS_MAX_LEN) $(MAINARGS_PLACEHOLDER) "$(mainargs)"

image: image-dep
	@$(OBJDUMP) -d $(IMAGE).elf > $(IMAGE).txt
	@echo + OBJCOPY "->" $(IMAGE_REL).bin
	@$(OBJCOPY) -S --set-section-flags .bss=alloc,contents -O binary $(IMAGE).elf $(IMAGE).bin

run: insert-arg
	@$(MAKE) -C $(NEMU_HOME) ISA=$(ISA) run ARGS="$(NEMUFLAGS)" IMG="-i $(IMAGE).bin" ELF_ARGS="-e $(IMAGE).elf -g $(shell dirname $(IMAGE).elf)/nemu-ftracer-log.txt"

gdb: insert-arg
	@$(MAKE) -C $(NEMU_HOME) ISA=$(ISA) gdb ARGS="$(NEMUFLAGS)" IMG="-i $(IMAGE).bin" ELF_ARGS="-e $(IMAGE).elf -g $(shell dirname $(IMAGE).elf)/nemu-ftracer-log.txt"

.PHONY: insert-arg
