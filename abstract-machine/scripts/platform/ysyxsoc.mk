AM_SRCS := riscv/ysyxsoc/start.S \
           riscv/ysyxsoc/trm.c \
           riscv/ysyxsoc/bootloader.c \
           riscv/ysyxsoc/ioe.c \
           riscv/ysyxsoc/timer.c \
           riscv/ysyxsoc/input.c \
           riscv/ysyxsoc/serial.c \
           riscv/ysyxsoc/gpu.c \
           riscv/ysyxsoc/cte.c \
           riscv/ysyxsoc/trap.S \
           platform/dummy/vme.c \
           platform/dummy/mpe.c

CFLAGS    += -fdata-sections -ffunction-sections -Os
LDSCRIPTS += $(AM_HOME)/scripts/linkersoc.ld
LDFLAGS   += --defsym=_pmem_start=0x20000000 --defsym=_entry_offset=0x0
LDFLAGS   += --defsym=_sram_start=0x0f000000 --defsym=_sram_offset=0x0
LDFLAGS   += --defsym=_flash_start=0x30000000 --defsym=_flash_offset=0x0
LDFLAGS   += --defsym=_psram_start=0x80000000 --defsym=_psram_size=0x400000
LDFLAGS   += --gc-sections -e _start 
# LDFLAGS   += --print-map

# CFLAGS += -fsanitize=address         # 启用 ASan
# LDFLAGS += -fsanitize=address        # 链接 ASan 库

# NPC的一些参数
NPCFLAGS += -l $(shell dirname $(IMAGE).bin)/npc_log.txt
NPCFLAGS += -e $(IMAGE).elf	#这是elf文件

NPCFLAGS += -d /home/lq/ysyx-workbench/npc/tools/nemu-diff/riscv32-nemu-ysyxsoc-interpreter-so	#加入difftest测试
#NPCFLAGS += -d /home/lq/ysyx-workbench/npc/tools/spike-diff/build/riscv32-spike-so
NPCFLAGS += -b

MAINARGS_MAX_LEN = 64
MAINARGS_PLACEHOLDER = The insert-arg rule in Makefile will insert mainargs here.
CFLAGS += -DMAINARGS_MAX_LEN=$(MAINARGS_MAX_LEN) -DMAINARGS_PLACEHOLDER=\""$(MAINARGS_PLACEHOLDER)"\"

insert-arg: image
	@python $(AM_HOME)/tools/insert-arg.py $(IMAGE).bin $(MAINARGS_MAX_LEN) "$(MAINARGS_PLACEHOLDER)" "$(mainargs)"

# bss不含有数据，所以不能设置为contents属性，contents属性表示该段在目标文件中包含实际数据（即在文件中占用存储空间），但是bss本来就不应该在文件中占空间
# bss如果不设置contents属性就表示不会被写入到bin文件中，只有在实际运行的时候才会别分配空间
image: image-dep
	@$(OBJDUMP) -d $(IMAGE).elf > $(IMAGE).txt
	@echo + OBJCOPY "->" $(IMAGE_REL).bin
	@$(OBJCOPY) -S --set-section-flags .bss=alloc -O binary $(IMAGE).elf $(IMAGE).bin

run: insert-arg
	$(MAKE) -C $(NPC_HOME) ISA=$(ISA) run ARGS="$(NPCFLAGS)" IMG=$(IMAGE).bin

.PHONY: insert-arg
