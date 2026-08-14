TOPNAME = ysyxSoCFull
VSRCS = $(shell find $(abspath ./vsrc/riscv32e-multi) -name "*.v") $(shell find $(abspath $(SOC_HOME)/perip) -name "*.v") $(SOC_HOME)/build/ysyxSoCFull.v
CSRCS = $(shell find $(abspath ./csrc/riscv32e-multi) -name "*.cpp")
IMG ?= resource/mem.bin
ELF ?= 

LIBCAPSTONE = $(NEMU_HOME)/tools/capstone/repo/libcapstone.so.5
$(LIBCAPSTONE):
	make -C $(NEMU_HOME)/tools/capstone

LIBNEMU-DIFF = $(NEMU_HOME)/build/riscv32-nemu-interpreter-so

LDFLAGS = $(patsubst %, -LDFLAGS %, -lreadline -ldl)

NXDC_FILES = constr/$(TOPNAME).nxdc
INC_PATH ?= $(abspath ./csrc/riscv32e-multi/include) $(NEMU_HOME)/tools/capstone/repo/include

VERILATOR = verilator
VERILATOR_CFLAGS += -MMD --build -cc \
				--autoflush -O3 --x-assign fast --x-initial fast --noassert -Wno-style -j 0  -Ivsrc/riscv32e-multi -I$(SOC_HOME)/perip/uart16550/rtl -I$(SOC_HOME)/perip/spi/rtl --timescale "1ns/1ns" --no-timing +define+debug=1

BUILD_DIR = ./build
OBJ_DIR = $(BUILD_DIR)/obj_dir
BIN = $(BUILD_DIR)/$(TOPNAME)

default: $(BIN)

$(shell mkdir -p $(BUILD_DIR))

# constraint file
SRC_AUTO_BIND = $(abspath $(BUILD_DIR)/auto_bind.cpp)
$(SRC_AUTO_BIND): $(NXDC_FILES)
	python3 $(NVBOARD_HOME)/scripts/auto_pin_bind.py $^ $@

CSRCS += $(SRC_AUTO_BIND)

# rules for NVBoard
include $(NVBOARD_HOME)/scripts/nvboard.mk

# rules for verilator
INCFLAGS = $(addprefix -I, $(INC_PATH))
CXXFLAGS += -DCONFIG_BOARD=1 $(INCFLAGS) -DTOP_NAME="\"V$(TOPNAME)\"" # -DCONFIG_WAVEFORM=1

NPCARGS = --diff=$(LIBNEMU-DIFF) -b --elf=$(ELF) $(IMG)

$(BIN): $(VSRCS) $(CSRCS) $(NVBOARD_ARCHIVE)
	@rm -rf $(OBJ_DIR)
	$(VERILATOR) $(VERILATOR_CFLAGS) \
		--top-module $(TOPNAME) $^ \
		$(addprefix -CFLAGS , $(CXXFLAGS)) $(addprefix -LDFLAGS , $(LDFLAGS)) \
		--Mdir $(OBJ_DIR) --exe -o $(abspath $(BIN))

all: default

run: $(BIN)
	@echo running on FPGA...
	@$^ $(NPCARGS)

clean:
	rm -rf $(BUILD_DIR)

.PHONY: default all clean run
