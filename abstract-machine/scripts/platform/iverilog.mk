AM_SRCS := riscv/npc/start.S \
           riscv/npc/trm.c \
           riscv/npc/ioe.c \
           riscv/npc/timer.c \
           riscv/npc/input.c \
           riscv/npc/cte.c \
           riscv/npc/trap.S \
           platform/dummy/vme.c \
           platform/dummy/mpe.c

CFLAGS    += -fdata-sections -ffunction-sections
LDSCRIPTS += $(AM_HOME)/scripts/linker.ld
LDFLAGS   += --defsym=_pmem_start=0x80000000 --defsym=_entry_offset=0x0
LDFLAGS   += --gc-sections -e _start
NPC_FLAGS += $(IMAGE).elf
#NPC_FLAGS += -l $(shell dirname $(IMAGE).elf)/nemu-log.txt
#NPC_FLAGS += -b

MAINARGS_MAX_LEN = 64
MAINARGS_PLACEHOLDER = the_insert-arg_rule_in_Makefile_will_insert_mainargs_here
CFLAGS += -DMAINARGS_MAX_LEN=$(MAINARGS_MAX_LEN) -DMAINARGS_PLACEHOLDER=$(MAINARGS_PLACEHOLDER)

NPC_HOME = $(AM_HOME)/../npc

insert-arg: image#命令行参数传递给测试程序。
	@python $(AM_HOME)/tools/insert-arg.py $(IMAGE).bin $(MAINARGS_MAX_LEN) $(MAINARGS_PLACEHOLDER) "$(mainargs)"

image: image-dep#将elf中代码和数据段提取出来，生成一个二进制文件.bin（可以直接被写入内存）
	@$(OBJDUMP) -d $(IMAGE).elf > $(IMAGE).txt
	@echo + OBJCOPY "->" $(IMAGE_REL).bin
	@$(OBJCOPY) -S --set-section-flags .bss=alloc,contents -O binary $(IMAGE).elf $(IMAGE).bin

run: insert-arg
	$(MAKE) -C $(NPC_HOME) sim-iverilog IMG=$(IMAGE).bin ARGS="$(NPC_FLAGS)" 

gdb: insert-arg
	$(MAKE) -C $(NPC_HOME) ISA=$(ISA) gdb IMG=$(IMAGE).bin ARGS="$(NPC_FLAGS)"
    
.PHONY: insert-arg
 