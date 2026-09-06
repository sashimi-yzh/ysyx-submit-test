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
LDFLAGS   += -T $(AM_HOME)/scripts/linker.ld \
						 --defsym=_pmem_start=0x80000000 --defsym=_entry_offset=0x0
LDFLAGS   += --gc-sections -e _start
CFLAGS += -DMAINARGS=\"$(mainargs)\"
.PHONY: $(AM_HOME)/am/src/riscv/npc/trm.c

ARGS = -f$(IMAGE).bin
ARGS += -b
ARGS += --diff=$(NPC_HOME)/../nemu/build/riscv32-nemu-interpreter-so
# ARGS += --itrace-log=$(NPC_HOME)/../simulator/itrace-log.txt
# ARGS += --mtrace-log=$(NPC_HOME)/../simulator/mtrace_log.txt
ARGS += --wave=$(NPC_HOME)/wave.vcd
ARGS += --perf-output=$(NPC_HOME)/performance.txt
ARGS += -m
# ARGS += -r 79517000
# ARGS += -i 1000000
# ARGS += -d 1926100
# ARGS += -e
# ARGS += "-w\$$$$pc==0x100027b7"

MAINARGS_MAX_LEN = 64
MAINARGS_PLACEHOLDER = the_insert-arg_rule_in_Makefile_will_insert_mainargs_here
CFLAGS += -DMAINARGS_MAX_LEN=$(MAINARGS_MAX_LEN) -DMAINARGS_PLACEHOLDER=$(MAINARGS_PLACEHOLDER)

insert-arg: image
	@python $(AM_HOME)/tools/insert-arg.py $(IMAGE).bin $(MAINARGS_MAX_LEN) $(MAINARGS_PLACEHOLDER) "$(mainargs)"

image: $(IMAGE).elf
	@$(OBJDUMP) -d $(IMAGE).elf > $(IMAGE).txt
	@echo + OBJCOPY "->" $(IMAGE_REL).bin
	@$(OBJCOPY) -S --set-section-flags .bss=alloc,contents -O binary $(IMAGE).elf $(IMAGE).bin

run: insert-arg
	$(MAKE) -C $(NPC_HOME) ARGS='$(ARGS)' BUILD_MODE=npc run

sim:
	$(MAKE) -C $(NPC_HOME) sim

ivg-image: $(IMAGE).elf
	@$(OBJDUMP) -d $(IMAGE).elf > $(IMAGE).txt
	@echo + OBJCOPY "->" $(IMAGE_REL).ivg 
	$(OBJCOPY) -S --set-section-flags .bss=alloc,contents --adjust-vma -0x80000000 -O verilog $(IMAGE).elf $(IMAGE).ivg

ivg: ivg-image
	$(MAKE) -C $(NPC_HOME) ARGS='$(ARGS)' IVG=$(IMAGE).ivg ivg 
