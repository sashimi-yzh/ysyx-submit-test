AM_SRCS := riscv/soc/start.S \
           riscv/soc/trm.c \
           riscv/soc/ioe.c \
           riscv/soc/gpu.c \
           riscv/soc/audio.c \
           riscv/soc/timer.c \
           riscv/soc/input.c \
           riscv/soc/cte.c \
           riscv/soc/trap.S \
           platform/dummy/vme.c \
           platform/dummy/mpe.c

CFLAGS    += -fdata-sections -ffunction-sections
CFLAGS    += -I$(AM_HOME)/am/src/platform/soc/include -I$(AM_HOME)/am/src
LDSCRIPTS += $(AM_HOME)/scripts/linker_soc.ld
LDFLAGS   += --gc-sections -e _start --defsym=_pmem_size=32M --defsym=_SOC_=1

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
	$(MAKE) -C $(NPC_HOME)/npc_soc nvboard PROG=$(IMAGE).bin NPC_FLAGS="--batch"

nvboard: insert-arg
	$(MAKE) -C $(NPC_HOME)/npc_soc nvboard PROG=$(IMAGE).bin NPC_FLAGS="--batch"


.PHONY: insert-arg
