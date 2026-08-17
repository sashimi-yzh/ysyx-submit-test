.PHONY: build clean run

RVGCC=riscv64-linux-gnu-gcc
RVOBJCOPY=riscv64-linux-gnu-objcopy
RVOBJDUMP=riscv64-linux-gnu-objdump


CSRC=$(wildcard ./tests/*.c)

MDIR=./build

ELF=$(MDIR)/mromtest.elf
BIN=$(MDIR)/mromtest.bin
ASM=$(MDIR)/mromtest.txt


build: $(ELF) $(BIN) $(ASM)

clean:
	rm -rf $(MDIR)

run: $(BIN)
	make -C $(SOC_NPC_HOME) sim PROG=$(realpath $(BIN))


$(ELF):$(CSRC)
	mkdir -p $(MDIR)
	$(RVGCC) $(CSRC) -march=rv32i -mabi=ilp32 \
	-nostdlib -nostartfiles -fno-stack-protector \
	-fpic -T link.ld \
	-I./include -O2 -o $@

$(BIN): $(ELF)
	$(RVOBJCOPY) -O binary $(ELF) $@

$(ASM): $(BIN)
	$(RVOBJDUMP) -d $(ELF) > $@
