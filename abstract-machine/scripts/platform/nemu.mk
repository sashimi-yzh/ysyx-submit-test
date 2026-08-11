AM_SRCS := platform/nemu/trm.c \
           platform/nemu/ioe/ioe.c \
           platform/nemu/ioe/timer.c \
           platform/nemu/ioe/input.c \
           platform/nemu/ioe/gpu.c \
           platform/nemu/ioe/audio.c \
           platform/nemu/ioe/disk.c \
           platform/nemu/mpe.c

CFLAGS    += -fdata-sections -ffunction-sections
CFLAGS    += -I$(AM_HOME)/am/src/platform/nemu/include
LDSCRIPTS += $(AM_HOME)/scripts/linker.ld
LDFLAGS   += --defsym=_pmem_start=0x80000000 --defsym=_entry_offset=0x0
LDFLAGS   += --gc-sections -e _start
NEMUFLAGS += -l $(shell dirname $(IMAGE).elf)/nemu-log.txt
# 新增：batch 模式参数（只给 run 用）
#NEMUFLAGS_BATCH = -b
# 默认批处理；需要交互调试时 make ... run SDB=1
ifeq ($(SDB),1)
  NEMUFLAGS_BATCH =
else
  NEMUFLAGS_BATCH = -b
endif

MAINARGS_MAX_LEN = 64
MAINARGS_PLACEHOLDER = the_insert-arg_rule_in_Makefile_will_insert_mainargs_here
CFLAGS += -DMAINARGS_MAX_LEN=$(MAINARGS_MAX_LEN) -DMAINARGS_PLACEHOLDER=$(MAINARGS_PLACEHOLDER)

insert-arg: image
	@python $(AM_HOME)/tools/insert-arg.py $(IMAGE).bin $(MAINARGS_MAX_LEN) $(MAINARGS_PLACEHOLDER) "$(mainargs)"

image: image-dep
	@$(OBJDUMP) -d $(IMAGE).elf > $(IMAGE).txt
	@echo + OBJCOPY "->" $(IMAGE_REL).bin
	@$(OBJCOPY) -S --set-section-flags .bss=alloc,contents -O binary $(IMAGE).elf $(IMAGE).bin

#run: insert-arg
#	$(MAKE) -C $(NEMU_HOME) ISA=$(ISA) run ARGS="$(NEMUFLAGS)" IMG=$(IMAGE).bin

#gdb: insert-arg
#	$(MAKE) -C $(NEMU_HOME) ISA=$(ISA) gdb ARGS="$(NEMUFLAGS)" IMG=$(IMAGE).bin
# 默认 run 进入 batch 模式
run: insert-arg
	$(MAKE) -C $(NEMU_HOME) ISA=$(ISA) run \
	ARGS="$(NEMUFLAGS_BATCH) $(NEMUFLAGS) $(ARGS)" \
	IMG=$(IMAGE).bin

# gdb 保持交互模式（不加 -b）
gdb: insert-arg
	$(MAKE) -C $(NEMU_HOME) ISA=$(ISA) gdb \
	ARGS="$(NEMUFLAGS)" \
	IMG=$(IMAGE).bin
.PHONY: insert-arg
