AM_SRCS := riscv/ysyxsoc/start.S \
           riscv/ysyxsoc/trm.c \
           riscv/ysyxsoc/ioe.c \
           riscv/ysyxsoc/timer.c \
           riscv/ysyxsoc/input.c \
           riscv/ysyxsoc/cte.c \
           riscv/ysyxsoc/trap.S \
		   riscv/ysyxsoc/vme.c \
		   riscv/ysyxsoc/uart.c \
		   riscv/ysyxsoc/gpu.c \
           riscv/ysyxsoc/mpe.c \
           riscv/ysyxsoc/bootloader.c \

CFLAGS    += -fdata-sections -ffunction-sections
LDSCRIPTS += $(AM_HOME)/scripts/linker-ysyxsoc.ld
LDFLAGS   += --gc-sections -e _start

MAINARGS_MAX_LEN = 64
MAINARGS_PLACEHOLDER = The insert-arg rule in Makefile will insert mainargs here.
CFLAGS += -DMAINARGS_MAX_LEN=$(MAINARGS_MAX_LEN) -DMAINARGS_PLACEHOLDER=\""$(MAINARGS_PLACEHOLDER)"\"

image: image-dep
	@$(OBJDUMP) -d $(IMAGE).elf > $(IMAGE).txt
	@echo + OBJCOPY "->" $(IMAGE_REL).bin
	@$(OBJCOPY) -S --set-section-flags .bss=alloc,contents -O binary $(IMAGE).elf $(IMAGE).bin
	@python $(AM_HOME)/tools/insert-arg.py $(IMAGE).bin $(MAINARGS_MAX_LEN) "$(MAINARGS_PLACEHOLDER)" "$(mainargs)"

rebuild:
ifdef REBUILD
	$(MAKE) -C $(NPC_HOME) clean
endif

run: image rebuild
	$(MAKE) -C $(NPC_HOME) sim IMG=$(IMAGE).bin OPT_FAST=""

gdb: image rebuild
	$(MAKE) -C $(NPC_HOME) gdb IMG=$(IMAGE).bin OPT_FAST=""
    
.PHONY: rebuild
