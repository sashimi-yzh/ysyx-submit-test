SRC = ./jmp.S

CROSS_COMPILE := riscv64-linux-gnu-
AS        = $(CROSS_COMPILE)gcc
CC        = $(CROSS_COMPILE)gcc
CXX       = $(CROSS_COMPILE)g++
LD        = $(CROSS_COMPILE)ld
FLAGS = -march=rv32e -mabi=ilp32e -ffreestanding

BUILD_DIR = build

OUT_O = $(BUILD_DIR)/jmp.o
OUT_ELF = $(BUILD_DIR)/jmp.elf
OUT_BIN = $(BUILD_DIR)/jmp.bin
OUT_HEX = $(BUILD_DIR)/jmp.hex

$(shell mkdir -p $(BUILD_DIR))

hex: $(OUT_BIN)
	objcopy -O verilog --verilog-data-width=4 -I binary --reverse-bytes=4 $(OUT_BIN) $(OUT_HEX)

$(OUT_BIN): $(SRC)
	$(AS) $(FLAGS) -c $(SRC) -o $(OUT_O)
	$(LD) -melf32lriscv $(OUT_O) -o $(OUT_ELF)
	$(CROSS_COMPILE)objcopy -O binary $(OUT_ELF) $(OUT_BIN)
