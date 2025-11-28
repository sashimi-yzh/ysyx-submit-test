AM_SRCS :=  platform/ysyxsoc/trm.c         \
            platform/ysyxsoc/mpe.c         \
            platform/ysyxsoc/bootloader.c  \
            platform/ysyxsoc/ioe/ioe.c     \
            platform/ysyxsoc/ioe/timer.c   \
            platform/ysyxsoc/ioe/gpu.c     \
            platform/ysyxsoc/ioe/audio.c   \
            platform/ysyxsoc/ioe/uart.c    \
            platform/ysyxsoc/ioe/input.c 
           

CFLAGS    += -fdata-sections -ffunction-sections
CFLAGS    += -I$(AM_HOME)/am/src/platform/ysyxsoc/include
CFLAGS    += -I$(AM_HOME)/am/src/riscv
LDSCRIPTS += $(AM_HOME)/scripts/linker_ysyx_soc_sdram.ld
LDFLAGS   += --defsym=_pmem_start=0xa20000000 --defsym=_entry_offset=0x00
LDFLAGS   += --gc-sections -e _start

YSYXSOCFLAGS += -l $(shell dirname $(IMAGE).elf)/ysyxsoc-log.txt
# YSYXSOCFLAGS += -e $(IMAGE).elf
YSYXSOCFLAGS += -b
# YSYXSOCFLAGS += --flash_file=$(AM_KERNELS_HOME)/tests/soc-tests/build/char-test-riscv32e-ysyxsoc.bin

MAINARGS_MAX_LEN = 64
MAINARGS_PLACEHOLDER = The insert-arg rule in Makefile will insert mainargs here.
CFLAGS += -DMAINARGS_MAX_LEN=$(MAINARGS_MAX_LEN) -DMAINARGS_PLACEHOLDER=\""$(MAINARGS_PLACEHOLDER)"\"

insert-arg: image
	@python3 $(AM_HOME)/tools/insert-arg.py $(IMAGE).bin $(MAINARGS_MAX_LEN) "$(MAINARGS_PLACEHOLDER)" "$(mainargs)"

image: image-dep
	@$(OBJDUMP) -d $(IMAGE).elf > $(IMAGE).txt
	@echo + OBJCOPY "->" $(IMAGE_REL).bin
# 	@$(OBJCOPY) -S --set-section-flags .bss=alloc,contents -O binary $(IMAGE).elf $(IMAGE).bin
	@$(OBJCOPY) -O binary $(IMAGE).elf $(IMAGE).bin
	@$(MAKE) -C $(NPC_HOME) $(ARCH)_defconfig

run: insert-arg
	$(MAKE) -C $(NPC_HOME) ISA=$(ISA) run ARGS="$(YSYXSOCFLAGS)" IMG=$(IMAGE).bin
#$(MAKE) -C $(NPC_HOME) ISA=$(ISA) run ARGS="$(YSYXSOCFLAGS)" IMG=$(IMAGE).bin

perf: insert-arg
	$(MAKE) -C $(NPC_HOME) ISA=$(ISA) perf ARGS="$(YSYXSOCFLAGS)" IMG=$(IMAGE).bin

gdb: insert-arg
	$(MAKE) -C $(NPC_HOME) ISA=$(ISA) gdb IMG=$(IMAGE).bin
#$(MAKE) -C $(NPC_HOME) ISA=$(ISA) gdb  ARGS="$(YSYXSOCFLAGS)" IMG=$(IMAGE).bin

.PHONY: insert-arg
