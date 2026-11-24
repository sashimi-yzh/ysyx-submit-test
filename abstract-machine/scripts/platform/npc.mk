AM_SRCS := riscv/npc/start.S \
           riscv/npc/trm.c \
           riscv/npc/trap.S \
           riscv/npc/cte.c \
           platform/npc/ioe.c \
           platform/npc/timer.c \
           platform/npc/gpu.c \
           platform/npc/uart.c \
           platform/npc/input.c \
           platform/dummy/vme.c \
           platform/dummy/mpe.c

CFLAGS    += -fdata-sections -ffunction-sections
LDFLAGS   += -T $(AM_HOME)/scripts/linker-npc.ld \
						 --defsym=_pmem_start=0x80000000 --defsym=_entry_offset=0x0
LDFLAGS   += --gc-sections -e _start

IMAGE_ELF_DIR := $(patsubst %/,%,$(dir $(IMAGE).elf))
NPCFLAGS += -l $(IMAGE_ELF_DIR)/npc-log.txt
NPCFLAGS += -m $(IMAGE_ELF_DIR)/npc-log-mem.txt
NPCFLAGS += -f $(IMAGE_ELF_DIR)/npc-log-func.txt
NPCFLAGS += -x $(IMAGE_ELF_DIR)/npc-log-devmem.txt
NPCFLAGS += -e $(IMAGE).elf

IVER_ARGS ?= $(IMAGE_ELF_DIR)/mem_iverilog.txt

# batch mode
NPCFLAGS += -b

CFLAGS += -I$(AM_HOME)/am/src/platform/npc/include

MAINARGS_MAX_LEN = 64
MAINARGS_PLACEHOLDER = The insert-arg rule in Makefile will insert mainargs here.
CFLAGS += -DMAINARGS_MAX_LEN=$(MAINARGS_MAX_LEN) -DMAINARGS_PLACEHOLDER=\""$(MAINARGS_PLACEHOLDER)"\"

insert-arg: image
	@python $(AM_HOME)/tools/insert-arg.py $(IMAGE).bin $(MAINARGS_MAX_LEN) "$(MAINARGS_PLACEHOLDER)" "$(mainargs)"

# follow npc menuconfig: iverilog sim has no vga, so ioe.c must skip gpu init
NPC_CONFIG := $(NPC_HOME)/.config
ifneq ($(shell grep -s '^CONFIG_NPC_IVERILOG=y' $(NPC_CONFIG)),)
CFLAGS += -DCONFIG_NPC_IVERILOG
endif
ifneq ($(shell grep -s '^CONFIG_NPC_IVERILOG_NET=y' $(NPC_CONFIG)),)
CFLAGS += -DCONFIG_NPC_IVERILOG_NET
endif
# rebuild the whole am library whenever npc/.config changes
# (prerequisite only, recipes still come from the %.o pattern rules)
ifeq ($(NAME),am)
$(OBJS): $(wildcard $(NPC_CONFIG))
endif

image: $(IMAGE).elf
	$(OBJDUMP) -d $(IMAGE).elf > $(IMAGE).txt
	$(OBJDUMP) -S $(IMAGE).elf > $(IMAGE)_s.txt
	@echo + OBJCOPY "->" $(IMAGE_REL).bin
	@$(OBJCOPY) -S --set-section-flags .bss=alloc,contents -O binary $(IMAGE).elf $(IMAGE).bin
	@echo + OBJCOPY "->" $(IMAGE_ELF_DIR)/mem_iverilog.txt
	@$(OBJCOPY) -I binary -O verilog --verilog-data-width=4 $(IMAGE).bin $(IMAGE_ELF_DIR)/mem_iverilog.txt


run: insert-arg
	$(MAKE) -C $(NPC_HOME) ISA=$(ISA) run ARGS="$(NPCFLAGS)" IVER_ARGS="$(IVER_ARGS)" IMG=$(IMAGE).bin

gdb: insert-arg
	$(MAKE) -C $(NPC_HOME) ISA=$(ISA) gdb ARGS="$(NPCFLAGS)" IMG=$(IMAGE).bin

plot:
	python3 $(AM_HOME)/tools/plot_mem_trace.py $(IMAGE_ELF_DIR)/npc-log-mem.txt --output-dir $(IMAGE_ELF_DIR)/../plots

.PHONY: insert-arg