YSYXSOC_AM_DIR := riscv/ysyxsoc
YSYXSOC_AM_FILES := start.S fsbl.S trm.c ioe.c gpu.c timer.c input.c cte.c trap.S vme.c mpe.c ssbl.c boot.c
AM_SRCS := $(addprefix $(YSYXSOC_AM_DIR)/,$(YSYXSOC_AM_FILES))

NPC_HOME ?= $(if $(wildcard $(AM_HOME)/../npc-26010028/Makefile),$(AM_HOME)/../npc-26010028,$(AM_HOME)/../npc)
YSYXSOC_LINKER := $(AM_HOME)/scripts/linker-ysyxsoc.ld
YSYXSOC_EXTRA := $(AM_HOME)/scripts/extra-ysyxsoc.ld

CFLAGS += -fdata-sections -ffunction-sections -DMAINARGS_MAX_LEN=64 -DMAINARGS_PLACEHOLDER=the_insert-arg_rule_in_Makefile_will_insert_mainargs_here
LDSCRIPTS += $(YSYXSOC_LINKER)
LDFLAGS += --defsym=_pmem_start=0x30000000 --defsym=_entry_offset=0x0 --gc-sections -e _start
LDFLAGS := $(subst -T extra.ld,-T $(YSYXSOC_EXTRA),$(LDFLAGS))
LDFLAGS := $(subst -T extra-ysyxsoc.ld,-T $(YSYXSOC_EXTRA),$(LDFLAGS))
ifneq ($(findstring $(YSYXSOC_EXTRA),$(LDFLAGS)),)
$(IMAGE).elf: $(YSYXSOC_EXTRA)
endif

YSYXSOC_IMAGE_ELF := $(IMAGE).elf
YSYXSOC_IMAGE_BIN := $(IMAGE).bin
YSYXSOC_IMAGE_DISASM := $(IMAGE).txt
YSYXSOC_OUTPUT_DIR := $(dir $(YSYXSOC_IMAGE_ELF))
YSYXSOCFLAGS += -l $(YSYXSOC_OUTPUT_DIR)npc-log.txt -f $(YSYXSOC_IMAGE_ELF) \
	-F $(YSYXSOC_OUTPUT_DIR)npc-ftrace.txt -E $(YSYXSOC_OUTPUT_DIR)npc-etrace.txt \
	-M $(YSYXSOC_OUTPUT_DIR)npc-mtrace.txt -D $(YSYXSOC_OUTPUT_DIR)npc-dtrace.txt

DEBUG ?= 0
ifeq ($(filter 1 y yes true,$(DEBUG)),)
YSYXSOCFLAGS += -b
endif

INSERT_ARG_TOOL := $(AM_HOME)/tools/insert-arg.py

insert-arg: image
	@printf '[am][insert-arg] arch=%s platform=ysyxsoc image=%s mainargs=%s\n' '$(ARCH)' '$(YSYXSOC_IMAGE_BIN)' '$(mainargs)'
	@python $(INSERT_ARG_TOOL) $(YSYXSOC_IMAGE_BIN) 64 the_insert-arg_rule_in_Makefile_will_insert_mainargs_here "$(mainargs)"

image: image-dep
	@printf '[am][image] arch=%s platform=ysyxsoc elf=%s\n' '$(ARCH)' '$(YSYXSOC_IMAGE_ELF)'
	@$(OBJDUMP) -d $(YSYXSOC_IMAGE_ELF) > $(YSYXSOC_IMAGE_DISASM)
	@echo + OBJCOPY "->" $(IMAGE_REL).bin
	@$(OBJCOPY) -S -O binary $(YSYXSOC_IMAGE_ELF) $(YSYXSOC_IMAGE_BIN)
	@printf '[am][image] ready bin=%s disasm=%s\n' '$(YSYXSOC_IMAGE_BIN)' '$(YSYXSOC_IMAGE_DISASM)'

run: insert-arg
	@printf '[am][run] arch=%s platform=ysyxsoc npc_home=%s image=%s debug=%s\n' '$(ARCH)' '$(NPC_HOME)' '$(YSYXSOC_IMAGE_BIN)' '$(DEBUG)'
	@printf '[am][run] npc_args=%s\n' '$(strip $(YSYXSOCFLAGS))'
	$(MAKE) -C $(NPC_HOME) sim SIM_MODE=ysyxsoc ARGS="$(YSYXSOCFLAGS)" IMG="$(YSYXSOC_IMAGE_BIN)"

.PHONY: insert-arg run
