AM_SRCS := riscv/ysyxsoc/start.S 	\
		   riscv/ysyxsoc/trap.S 	\
           riscv/ysyxsoc/trm.c		\
		   riscv/ysyxsoc/ioe.c		\
		   riscv/ysyxsoc/input.c	\
		   riscv/ysyxsoc/uart.c		\
		   riscv/ysyxsoc/gpu.c		\
		   riscv/ysyxsoc/timer.c		\
		   riscv/ysyxsoc/cte.c		\
		   riscv/ysyxsoc/mpe.c		\
		   riscv/ysyxsoc/vme.c	



CFLAGS    += -fdata-sections -ffunction-sections
LDFLAGS   += -T $(AM_HOME)/scripts/linker_ysyxsoc.ld
ifneq ($(filter extra.ld,$(LDFLAGS)),)
    # 如果包含，则移除 -T extra.ld
    LDFLAGS := -z noexecstack -melf64lriscv -T $(AM_HOME)/scripts/linker_ysyxsoc.ld
endif

LDFLAGS   += --gc-sections -e _start
CFLAGS += -DMAINARGS=\"$(mainargs)\"

YSYXSOCFLAGS += -e $(IMAGE).elf
YSYXSOCFLAGS += -d $(NEMU_HOME)/build/riscv32-nemu-interpreter-so

.PHONY: $(AM_HOME)/am/src/riscv/ysyxsoc/trm.c

image: $(IMAGE).elf
	@$(OBJDUMP) -d $(IMAGE).elf > $(IMAGE).txt
	@echo + OBJCOPY "->" $(IMAGE_REL).bin
	@$(OBJCOPY) -S -O binary $(IMAGE).elf $(IMAGE).bin
	
run: image
	$(MAKE) -C $(NPC_HOME) build ARGS="$(YSYXSOCFLAGS)" IMG=$(IMAGE).bin PLATFORM=ysyxsoc

nvboard: image
	$(MAKE) -C $(NVBOARD_HOME)/ysyxsoc run ARGS="$(YSYXSOCFLAGS)" IMG=$(IMAGE).bin
