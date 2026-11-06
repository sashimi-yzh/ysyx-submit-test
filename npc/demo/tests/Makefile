FILE ?= char-test
OBJCOPY := riscv64-linux-gnu-objcopy
GCC := riscv64-linux-gnu-gcc
OBJDUMP := riscv64-linux-gnu-objdump

$(FILE).bin: $(FILE).elf $(FILE).txt
	$(OBJCOPY) -O binary -j .text $(FILE).elf $(FILE).bin

$(FILE).txt: $(FILE).elf
	$(OBJDUMP) -d $(FILE).elf > $(FILE).txt
	
$(FILE).elf: $(FILE).c
	$(GCC) -nostdlib -ffreestanding -fomit-frame-pointer -e _start -march=rv32em_zicsr -mabi=ilp32e -o $(FILE).elf $(FILE).c

.PHONY: clean
clean:
	rm -f $(FILE).bin $(FILE).elf $(FILE).txt