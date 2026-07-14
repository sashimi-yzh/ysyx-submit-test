AM_SRCS := riscv/npc/start.S \
           riscv/ysyxsoc/trm.c \
           riscv/ysyxsoc/ioe.c \
           riscv/ysyxsoc/uart.c \
           riscv/ysyxsoc/timer.c \
           riscv/ysyxsoc/keyboard.c \
           riscv/ysyxsoc/gpu.c \
           riscv/npc/cte.c \
           riscv/npc/trap.S \
           platform/dummy/vme.c \
           platform/dummy/mpe.c

INC_PATH  += $(AM_HOME)/am/src/riscv/ysyxsoc/include
CFLAGS    += -fdata-sections -ffunction-sections
LDFLAGS   += --gc-sections -e _start

ifneq ($(findstring extra.ld,$(LDFLAGS)),)
LDFLAGS := $(subst extra.ld,extra-soc.ld,$(LDFLAGS))
else
LDSCRIPTS += $(AM_HOME)/am/src/riscv/ysyxsoc/linker.ld
endif

MAINARGS_MAX_LEN = 64
MAINARGS_PLACEHOLDER = the_insert-arg_rule_in_Makefile_will_insert_mainargs_here
CFLAGS += -DMAINARGS_MAX_LEN=$(MAINARGS_MAX_LEN) -DMAINARGS_PLACEHOLDER=$(MAINARGS_PLACEHOLDER)

insert-arg: image
	@python $(AM_HOME)/tools/insert-arg.py $(IMAGE).bin $(MAINARGS_MAX_LEN) $(MAINARGS_PLACEHOLDER) "$(mainargs)"

image: image-dep
	@$(OBJDUMP) -d $(IMAGE).elf > $(IMAGE).txt
	@echo + OBJCOPY "->" $(IMAGE_REL).bin
	@$(OBJCOPY) -S --set-section-flags .bss=alloc -O binary $(IMAGE).elf $(IMAGE).bin

run: insert-arg
	$(MAKE) -C $(NPC_HOME) sim-ysyxsoc IMG=$(IMAGE).bin
    

.PHONY: insert-arg
