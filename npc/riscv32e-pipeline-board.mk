TOPNAME = ysyxSoCFull
VSRCS = $(shell find $(abspath ./build) -name "*.v") $(shell find $(abspath $(YSYX_HOME)/ysyxSoC/perip) -name "*.v") $(YSYX_HOME)/ysyxSoC/build/ysyxSoCFull.v
CSRCS = $(shell find $(abspath ./csrc/riscv32e-pipeline) -name "*.cpp")
IMG ?= resource/mem.bin
ELF ?= 

INC_PATH ?= $(abspath ./csrc/riscv32e-pipeline/include)
LDFLAGS = $(patsubst %, -LDFLAGS %, -lreadline -ldl)
NXDC_FILES = constr/$(TOPNAME).nxdc
VERILATOR = verilator
VERILATOR_CFLAGS += -MMD --build -cc --trace-fst \
				--autoflush -O3 --x-assign fast --x-initial fast --noassert -Wno-style -j 0 -Ibuild -I$(YSYX_HOME)/ysyxSoC/perip/uart16550/rtl -I$(YSYX_HOME)/ysyxSoC/perip/spi/rtl --timescale "1ns/1ns" --no-timing +define+ysyx_26010007_debug=1

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
################ 含TRACE工具 ###############################
LIBCAPSTONE = $(NEMU_HOME)/tools/capstone/repo/libcapstone.so.5
$(LIBCAPSTONE):
	make -C $(NEMU_HOME)/tools/capstone
LIBNEMU-DIFF = $(NEMU_HOME)/build/riscv32-nemu-interpreter-so
INC_PATH += $(NEMU_HOME)/tools/capstone/repo/include
INCFLAGS = $(addprefix -I, $(INC_PATH))
CXXFLAGS += -DCONFIG_BOARD=1 $(INCFLAGS) -DTOP_NAME="\"V$(TOPNAME)\"" # -DCONFIG_WAVEFORM=1
NPCARGS = -b --diff=$(LIBNEMU-DIFF) --elf=$(ELF) $(IMG)
############################################################

################ 不含TRACE工具 ###############################
# INCFLAGS = $(addprefix -I, $(INC_PATH))
# NPCARGS = -b $(IMG)
# CXXFLAGS += -DCONFIG_BOARD=1 $(INCFLAGS) -DTOP_NAME="\"V$(TOPNAME)\""
############################################################

$(BIN): $(VSRCS) $(CSRCS) $(NVBOARD_ARCHIVE)
	@rm -rf $(OBJ_DIR)
	$(VERILATOR) $(VERILATOR_CFLAGS) \
		--top-module $(TOPNAME) $^ \
		$(addprefix -CFLAGS , $(CXXFLAGS)) $(addprefix -LDFLAGS , $(LDFLAGS)) \
		--Mdir $(OBJ_DIR) --exe -o $(abspath $(BIN))

all: default

run: $(BIN)
	@echo running on FPGA...
	@$< $(NPCARGS)

clean:
	rm -rf $(BUILD_DIR)

.PHONY: default all clean run
