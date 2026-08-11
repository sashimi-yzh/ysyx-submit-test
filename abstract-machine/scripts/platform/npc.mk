NPC_AM_DIR := riscv/npc
NPC_AM_FILES := start.S boot.c trm.c ioe.c timer.c input.c cte.c trap.S
AM_SRCS := $(addprefix $(NPC_AM_DIR)/,$(NPC_AM_FILES))
AM_SRCS += platform/dummy/vme.c platform/dummy/mpe.c

NPC_HOME ?= $(if $(wildcard $(AM_HOME)/../npc-26010028/Makefile),$(AM_HOME)/../npc-26010028,$(AM_HOME)/../npc)
NPC_LINKER := $(AM_HOME)/scripts/linker.ld

CFLAGS += -fdata-sections -ffunction-sections -DMAINARGS_MAX_LEN=64 -DMAINARGS_PLACEHOLDER=the_insert-arg_rule_in_Makefile_will_insert_mainargs_here
LDSCRIPTS += $(NPC_LINKER)
LDFLAGS += --defsym=_pmem_start=0x80000000 --defsym=_entry_offset=0x0 --gc-sections -e _start

NPC_IMAGE_ELF := $(IMAGE).elf
NPC_IMAGE_BIN := $(IMAGE).bin
NPC_IMAGE_DISASM := $(IMAGE).txt
NPC_OUTPUT_DIR := $(dir $(NPC_IMAGE_ELF))
NPCFLAGS += -l $(NPC_OUTPUT_DIR)npc-log.txt -f $(NPC_IMAGE_ELF) \
	-F $(NPC_OUTPUT_DIR)npc-ftrace.txt -E $(NPC_OUTPUT_DIR)npc-etrace.txt \
	-M $(NPC_OUTPUT_DIR)npc-mtrace.txt -D $(NPC_OUTPUT_DIR)npc-dtrace.txt

DEBUG ?= 0
ifeq ($(filter 1 y yes true,$(DEBUG)),)
NPCFLAGS += -b
endif

INSERT_ARG_TOOL := $(AM_HOME)/tools/insert-arg.py

insert-arg: image
	@printf '[am][insert-arg] arch=%s platform=npc image=%s mainargs=%s\n' '$(ARCH)' '$(NPC_IMAGE_BIN)' '$(mainargs)'
	@python $(INSERT_ARG_TOOL) $(NPC_IMAGE_BIN) 64 the_insert-arg_rule_in_Makefile_will_insert_mainargs_here "$(mainargs)"

image: image-dep
	@printf '[am][image] arch=%s platform=npc elf=%s\n' '$(ARCH)' '$(NPC_IMAGE_ELF)'
	@$(OBJDUMP) -d $(NPC_IMAGE_ELF) > $(NPC_IMAGE_DISASM)
	@echo + OBJCOPY "->" $(IMAGE_REL).bin
	@$(OBJCOPY) -S --set-section-flags .bss=alloc,contents -O binary $(NPC_IMAGE_ELF) $(NPC_IMAGE_BIN)
	@printf '[am][image] ready bin=%s disasm=%s\n' '$(NPC_IMAGE_BIN)' '$(NPC_IMAGE_DISASM)'

run: insert-arg
	@printf '[am][run] arch=%s platform=npc npc_home=%s image=%s debug=%s\n' '$(ARCH)' '$(NPC_HOME)' '$(NPC_IMAGE_BIN)' '$(DEBUG)'
	@printf '[am][run] npc_args=%s\n' '$(strip $(NPCFLAGS))'
	$(MAKE) -C $(NPC_HOME) sim SIM_MODE=npc ARGS="$(NPCFLAGS)" IMG="$(NPC_IMAGE_BIN)"

.PHONY: insert-arg run
