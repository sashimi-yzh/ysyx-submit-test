CROSS = riscv64-linux-gnu
CC    = $(CROSS)-gcc
COPY  = $(CROSS)-objcopy
DUMP  = $(CROSS)-objdump

CFLAGS = -march=rv32e -mabi=ilp32e -nostdlib -nostartfiles -static -Wl,--build-id=none -O2

all: char-test.bin

char-test.elf: char-test.c char-test.ld
	$(CC) $(CFLAGS) -T char-test.ld -o char-test.elf char-test.c

char-test.bin: char-test.elf
	$(COPY) -O binary -j .text char-test.elf char-test.bin

dump: char-test.elf
	$(DUMP) -d char-test.elf

clean:
	rm -f char-test.elf char-test.bin

.PHONY: all dump clean