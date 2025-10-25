AM_SRCS :=	riscv/ysyxsoc/fsbl.S \
			riscv/ysyxsoc/trap.S \
			riscv/ysyxsoc/bootloader.c \
			riscv/ysyxsoc/trm.c \
			riscv/ysyxsoc/ioe.c \
			riscv/ysyxsoc/vme.c \
			riscv/ysyxsoc/mpe.c \
			riscv/ysyxsoc/cte.c \
			riscv/ysyxsoc/device/uart.c \
			riscv/ysyxsoc/device/flash.c \
			riscv/ysyxsoc/device/keyboard.c \
			riscv/ysyxsoc/device/gpu.c \
			riscv/ysyxsoc/device/timer.c

CFLAGS    += -fdata-sections -ffunction-sections
LDSCRIPTS += $(AM_HOME)/am/src/riscv/ysyxsoc/linker.ld
LDFLAGS   += --gc-sections -e _fsbl --undefined=_trm_init

MAINARGS_MAX_LEN = 64
MAINARGS_PLACEHOLDER = The insert-arg rule in Makefile will insert mainargs here.
CFLAGS += -DMAINARGS_MAX_LEN=$(MAINARGS_MAX_LEN) -DMAINARGS_PLACEHOLDER=\""$(MAINARGS_PLACEHOLDER)"\"

NPCFLAGS = -b$(IMAGE).bin -e$(IMAGE).elf -r #-v

insert-arg: image
	@python3 $(AM_HOME)/tools/insert-arg.py $(IMAGE).bin $(MAINARGS_MAX_LEN) "$(MAINARGS_PLACEHOLDER)" "$(mainargs)"

image: image-dep
	@$(OBJDUMP) -d $(IMAGE).elf > $(IMAGE).txt
	@echo + OBJCOPY "->" $(IMAGE_REL).bin
	@$(OBJCOPY) -O binary $(IMAGE).elf $(IMAGE).bin

run: insert-arg
	@echo $(NPCFLAGS)
	$(MAKE) -C$(NPC_HOME) run ARGS="$(NPCFLAGS)" TOPNAME=ysyxSoCFull

.PHONY: insert-arg
