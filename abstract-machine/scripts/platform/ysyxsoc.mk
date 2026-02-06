AM_SRCS := riscv/ysyxsoc/start.S \
           riscv/ysyxsoc/trm.c \
           riscv/ysyxsoc/ioe.c \
           riscv/ysyxsoc/timer.c \
           riscv/ysyxsoc/input.c \
           riscv/ysyxsoc/cte.c \
           riscv/ysyxsoc/trap.S \
           platform/dummy/vme.c \
           platform/dummy/mpe.c \
           riscv/ysyxsoc/uart.c\
           riscv/ysyxsoc/gpu.c

CFLAGS    += -fdata-sections -ffunction-sections # 让编译器将每个函数和数据段分别放置在独立的节（section）
CFLAGS    += -Os
LDFLAGS   += -T $(AM_HOME)/scripts/ysyxSoclinker.ld \
						 --defsym=_pmem_start=0x80000000 --defsym=_entry_offset=0x0 
LDFLAGS   += --gc-sections -e _start #告诉链接器移除未被使用的节
#LDFLAGS   += --print-map
SOCFLAGS  += -b 
MAINARGS_MAX_LEN = 64
MAINARGS_PLACEHOLDER = The insert-arg rule in Makefile will insert mainargs here.
CFLAGS += -DMAINARGS_MAX_LEN=$(MAINARGS_MAX_LEN) -DMAINARGS_PLACEHOLDER=\""$(MAINARGS_PLACEHOLDER)"\"

insert-arg: image
	@python $(AM_HOME)/tools/insert-arg.py $(IMAGE).bin $(MAINARGS_MAX_LEN) "$(MAINARGS_PLACEHOLDER)" "$(mainargs)"


image: $(IMAGE).elf
	@$(OBJDUMP) -d $(IMAGE).elf > $(IMAGE).txt
	@echo + OBJCOPY "->" $(IMAGE_REL).bin
	@$(OBJCOPY) -S --set-section-flags .bss=alloc,contents -O binary $(IMAGE).elf $(IMAGE).bin

run: insert-arg
	$(MAKE) -C $(NPC_HOME) run IMG=$(IMAGE).bin ELF=$(IMAGE).elf ARGS="$(SOCFLAGS)" ARCH=$(ARCH)

gdb: insert-arg
	$(MAKE) -C $(NPC_HOME) gdb IMG=$(IMAGE).bin ELF=$(IMAGE).elf
