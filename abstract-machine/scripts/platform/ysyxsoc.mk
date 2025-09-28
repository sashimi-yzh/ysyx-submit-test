AM_SRCS := riscv/ysyxsoc/start.S \
           riscv/ysyxsoc/fsbl.S \
           riscv/ysyxsoc/ssbl.S \
           riscv/ysyxsoc/trm.c \
           riscv/ysyxsoc/cte.c \
           riscv/ysyxsoc/trap.S \
           riscv/ysyxsoc/ioe/ioe.c \
           riscv/ysyxsoc/ioe/uart.c \
           riscv/ysyxsoc/ioe/timer.c \
           riscv/ysyxsoc/ioe/gpio.c \
           riscv/ysyxsoc/ioe/input.c \
           riscv/ysyxsoc/ioe/gpu.c \
           platform/dummy/vme.c \
           platform/dummy/mpe.c

CFLAGS    += -fdata-sections -ffunction-sections
LDFLAGS   += -T $(AM_HOME)/am/src/riscv/ysyxsoc/linker.ld
LDFLAGS   += --gc-sections -e _fsbl # --orphan-handling=warn --print-map
CFLAGS += -I$(AM_HOME)/am/src/riscv/ysyxsoc/include

NPCFLAGS += --log=$(shell dirname $(IMAGE).elf)/ysyxsoc-log.txt --batch

MAINARGS_MAX_LEN = 64
MAINARGS_PLACEHOLDER = The insert-arg rule in Makefile will insert mainargs here.
CFLAGS += -DMAINARGS_MAX_LEN=$(MAINARGS_MAX_LEN) -DMAINARGS_PLACEHOLDER=\""$(MAINARGS_PLACEHOLDER)"\"

insert-arg: image
	@python $(AM_HOME)/tools/insert-arg.py $(IMAGE).bin $(MAINARGS_MAX_LEN) "$(MAINARGS_PLACEHOLDER)" "$(mainargs)"

image: $(IMAGE).elf
	@$(OBJDUMP) -d $(IMAGE).elf > $(IMAGE).txt
	@echo + OBJCOPY "->" $(IMAGE_REL).bin
	@$(OBJCOPY) -S -O binary $(IMAGE).elf $(IMAGE).bin

run: insert-arg
	@echo run
	$(MAKE) -C $(NPC_HOME) ARGS="$(NPCFLAGS)" IMG=$(IMAGE).bin ELF=$(IMAGE).elf ENABLE_YSYXSOC=1 run

run_nvboard: insert-arg
	@echo run
	$(MAKE) -C $(NPC_HOME) ARGS="$(NPCFLAGS)" IMG=$(IMAGE).bin ELF=$(IMAGE).elf ENABLE_YSYXSOC=1 ENABLE_NVBOARD=1 run

.PHONY: insert-arg
