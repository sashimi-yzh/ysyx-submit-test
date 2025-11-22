AM_SRCS := riscv/ysyxsoc/start.S \
           riscv/ysyxsoc/trm.c \
           riscv/ysyxsoc/ioe.c \
           riscv/ysyxsoc/timer.c \
           riscv/ysyxsoc/input.c \
           riscv/ysyxsoc/cte.c \
           riscv/ysyxsoc/trap.S \
           riscv/ysyxsoc/uart.c \
           riscv/ysyxsoc/gpu.c \
           platform/dummy/vme.c \
           platform/dummy/mpe.c

CFLAGS    += -fdata-sections -ffunction-sections #每个函数（function-sections）和全局变量（data-sections）单独编译到一个目标文件段（section）中
CFLAGS    += -I$(AM_HOME)/am/src/riscv/ysyxsoc/include
LDSCRIPTS += $(AM_HOME)/scripts/linker-ysyxsoc.ld
# LDFLAGS   += --defsym=_pmem_start=0x20000000 --defsym=_entry_offset=0x0
# LDFLAGS   += --defsym=_rom_start=0x20000000 --defsym=_sram_start=0x0f000000 --defsym=_stack_size=0x1000
LDFLAGS   += --defsym=_stack_size=2K --defsym=_entry_offset=0x0
LDFLAGS   += --gc-sections -e _start #配合前面 CFLAGS 的 -fdata-sections，剔除未使用的函数 / 变量，减小镜像体积; 同时指定程序入口为 _start
NPCFLAGS += -l $(shell dirname $(IMAGE).elf)/ysyxsoc-log.txt
NPCFLAGS += -e $(IMAGE).elf
NPCFLAGS += -b
NPCFLAGS += -d $(NEMU_HOME)/build/riscv32-nemu-interpreter-so 

MAINARGS_MAX_LEN = 64
MAINARGS_PLACEHOLDER = The insert-arg rule in Makefile will insert mainargs here.
CFLAGS += -DMAINARGS_MAX_LEN=$(MAINARGS_MAX_LEN) -DMAINARGS_PLACEHOLDER=\""$(MAINARGS_PLACEHOLDER)"\"

insert-arg: image
	@python3 $(AM_HOME)/tools/insert-arg.py $(IMAGE).bin $(MAINARGS_MAX_LEN) "$(MAINARGS_PLACEHOLDER)" "$(mainargs)"

image: image-dep
	@$(OBJDUMP) -d $(IMAGE).elf > $(IMAGE).txt
	@echo + OBJCOPY "->" $(IMAGE_REL).bin
	@$(OBJCOPY) -S --set-section-flags .bss=alloc,contents -O binary $(IMAGE).elf $(IMAGE).bin

run: insert-arg
	$(MAKE) -C $(NPC_HOME) ISA=$(ISA) run ARGS="$(NPCFLAGS)" IMG=$(IMAGE).bin
	
gdb: insert-arg
	$(MAKE) -C $(NPC_HOME) ISA=$(ISA) gdb ARGS="$(NPCFLAGS)" IMG=$(IMAGE).bin

.PHONY: insert-arg
