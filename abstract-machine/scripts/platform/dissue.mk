AM_SRCS := riscv/dissue/start.S \
           riscv/dissue/trm.c \
           riscv/dissue/ioe/ioe.c \
           riscv/dissue/cte.c \
           riscv/dissue/trap.S \
           riscv/dissue/vme.c \
           riscv/dissue/mpe.c

CFLAGS    += -fdata-sections -ffunction-sections
LDFLAGS   += -T $(AM_HOME)/scripts/linker.ld \
						 --defsym=_pmem_start=0x80000000 --defsym=_entry_offset=0x0
LDFLAGS   += --gc-sections -e _start
CFLAGS += -DMAINARGS=\"$(mainargs)\"

.PHONY: $(AM_HOME)/am/src/riscv/dissue/trm.c

CFLAGS += -I$(AM_HOME)/am/src/riscv/dissue/include

ARGS = --image $(IMAGE).bin
ARGS += --batch
# ARGS += --wave-path $(DISSUE_HOME)/run/wave.vcd
ARGS += --difftest-ref nemu
# ARGS += --wave
ARGS += --konata-path $(DISSUE_HOME)/run/konata.log

image: $(IMAGE).elf
	@$(OBJDUMP) -d $(IMAGE).elf > $(IMAGE).txt
	@echo + OBJCOPY "->" $(IMAGE_REL).bin
	@$(OBJCOPY) -S --set-section-flags .bss=alloc,contents -O binary $(IMAGE).elf $(IMAGE).bin

run: image
	$(MAKE) -C $(DISSUE_HOME) ARGS='$(ARGS)' run

sim:
	$(MAKE) -C $(DISSUE_HOME) sim
