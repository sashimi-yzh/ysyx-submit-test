AM_SRCS := riscv/jyd/start.S \
           riscv/jyd/trm.c 
           # riscv/npc/ioe.c \
           # riscv/npc/timer.c \
           # riscv/npc/input.c \
           # riscv/npc/cte.c \
           # riscv/npc/trap.S \
           # platform/dummy/vme.c \
           # platform/dummy/mpe.c

CFLAGS += -g

CFLAGS    += -fdata-sections -ffunction-sections
LDSCRIPTS += $(AM_HOME)/am/src/riscv/jyd/linker.ld
LDFLAGS   += --gc-sections -e _start

MAINARGS_MAX_LEN = 64
MAINARGS_PLACEHOLDER = the_insert-arg_rule_in_Makefile_will_insert_mainargs_here
CFLAGS += -DMAINARGS_MAX_LEN=$(MAINARGS_MAX_LEN) -DMAINARGS_PLACEHOLDER=$(MAINARGS_PLACEHOLDER)

insert-arg: image
	@python $(AM_HOME)/tools/insert-arg.py $(IMAGE).bin $(MAINARGS_MAX_LEN) $(MAINARGS_PLACEHOLDER) "$(mainargs)"

IMG_DATA_COE = $(IMAGE_REL).data.coe

image: image-dep
	@$(OBJDUMP) -d $(IMAGE).elf > $(IMAGE).txt
	@echo + OBJCOPY "->" $(IMAGE_REL).bin without .data section
	@$(OBJCOPY) -S -R .data -O binary $(IMAGE).elf $(IMAGE).bin
	@echo + Extract .data section "->" $(IMAGE_REL).data.bin
	@$(OBJCOPY) -j .data -O binary $(IMAGE).elf $(IMAGE_REL).data.bin
	@echo + Convert .data section "->" $(IMG_DATA_COE)
	@echo "memory_initialization_radix=16;" > $(IMG_DATA_COE)
	@echo "memory_initialization_vector=" >> $(IMG_DATA_COE)

	# 处理二进制数据：
	# -v: 显示所有数据（不压缩重复行）
	# -e: 定义输出格式，每4个字节转为8位16进制，加逗号和换行
	@hexdump -v -e '1/4 "%08X" ",\n"' $(IMAGE_REL).data.bin >> $(IMG_DATA_COE)

	@# 注意：最后一行需要以分号结尾，手动或用 sed 修正最后一行
	@sed -i '$$s/,/;/' $(IMG_DATA_COE)

run: insert-arg
	@$(MAKE) -C $(NPC_HOME) sim ARGS='-b' IMG=$(IMAGE).bin

.PHONY: insert-arg
