AM_SRCS := riscv/Oc405/start.S 	\
		   riscv/Oc405/trap.S 	\
           riscv/Oc405/trm.c		\
		   riscv/Oc405/ioe.c		\
		   riscv/Oc405/input.c	\
		   riscv/Oc405/uart.c		\
		   riscv/Oc405/gpu.c		\
		   riscv/Oc405/timer.c		\
		   riscv/Oc405/cte.c		\
		   riscv/Oc405/mpe.c		\
		   riscv/Oc405/vme.c	

CFLAGS    += -fdata-sections -ffunction-sections
LDFLAGS   += -T $(AM_HOME)/scripts/linker_Oc405.ld
ifneq ($(filter extra.ld,$(LDFLAGS)),)
    # 如果包含，则移除 -T extra.ld
    LDFLAGS := -z noexecstack -melf64lriscv -T $(AM_HOME)/scripts/linker_ysyxsoc.ld
endif

LDFLAGS   += --gc-sections -e _start
CFLAGS += -DMAINARGS=\"$(mainargs)\"

.PHONY: $(AM_HOME)/am/src/riscv/ysyxsoc/trm.c

image: $(IMAGE).elf
	@$(OBJDUMP) -d $(IMAGE).elf > $(IMAGE).txt
	@echo + OBJCOPY "->" $(IMAGE_REL).bin
	@$(OBJCOPY) -S -O binary $(IMAGE).elf $(IMAGE).bin

