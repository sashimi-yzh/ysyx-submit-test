AM_SRCS := riscv/npc/start.S \
           riscv/npc/trm.c \
           riscv/npc/ioe.c \
           riscv/npc/timer.c \
           riscv/npc/input.c \
           riscv/npc/uart.c \
           riscv/npc/cte.c \
           riscv/npc/trap.S \
           riscv/npc/gpu.c \
           platform/dummy/vme.c \
           platform/dummy/mpe.c
# gpu.c 是自己加的

CFLAGS    += -fdata-sections -ffunction-sections
LDFLAGS   += -T $(AM_HOME)/scripts/linker.ld \
						 --defsym=_pmem_start=0x80000000 --defsym=_entry_offset=0x0
LDFLAGS   += --gc-sections -e _start
#CFLAGS += -DMAINARGS=\"$(mainargs)\"

NPCFLAGS =--diff=$(NPC_HOME)/difftest/riscv32e-nemu-npc-so

FLAGS := $(filter-out -b,$(NPCFLAGS))

# 1) CI 环境无条件开启 batch（忽略命令行传入）
ifneq ($(strip $(CI)),)
	override NPCFLAGS += -b
	override BATCH := 1
endif

ifeq ($(BATCH), 1)
  NPCFLAGS += -b
endif


#.PHONY: $(AM_HOME)/am/src/riscv/npc/trm.c

MAINARGS_MAX_LEN = 64
MAINARGS_PLACEHOLDER = The insert-arg rule in Makefile will insert mainargs here.
CFLAGS += -DMAINARGS_MAX_LEN=$(MAINARGS_MAX_LEN) -DMAINARGS_PLACEHOLDER=\""$(MAINARGS_PLACEHOLDER)"\"

insert-arg: image
	@python $(AM_HOME)/tools/insert-arg.py $(IMAGE).bin $(MAINARGS_MAX_LEN) "$(MAINARGS_PLACEHOLDER)" "$(mainargs)"

image: $(IMAGE).elf
	@$(OBJDUMP) -d $(IMAGE).elf > $(IMAGE).txt
	@echo + OBJCOPY "->" $(IMAGE_REL).bin
	@$(OBJCOPY) -S --set-section-flags .bss=alloc,contents -O binary $(IMAGE).elf $(IMAGE).bin

run:  insert-arg
	$(MAKE) -C $(NPC_HOME) run  ARGS="$(NPCFLAGS)" IMG=$(IMAGE).bin

.PHONY: insert-arg
