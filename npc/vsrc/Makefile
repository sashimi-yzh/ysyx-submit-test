TOPNAME = top
NXDC_FILES = constr/top.nxdc

VERILATOR = verilator
VERILATOR_CFLAGS += -MMD --build -cc  \
			-O0 --x-assign fast --x-initial fast --noassert --trace

BUILD_DIR = ./build
OBJ_DIR = $(BUILD_DIR)/obj_dir
BIN = $(BUILD_DIR)/$(TOPNAME)

default: $(BIN)
$(shell mkdir -p $(BUILD_DIR))

# constraint file
#SRC_AUTO_BIND = $(abspath $(BUILD_DIR)/auto_bind.cpp)
#$(SRC_AUTO_BIND): $(NXDC_FILES)
#	python3 $(NVBOARD_HOME)/scripts/auto_pin_bind.py $^ $@

# project source
#VSRCS = $(shell find $(abspath ./vsrc) -name "*.v")

# rules for NVboard
#include $(NVBOARD_HOME)/scripts/nvboard.mk

# rules for verilator
INCFLAGS = $(addprefix -I, $(INC_PATH))
CXXFLAGS += $(INCFLAGS) -DTOP_NAME="\"V$(TOPNAME)\""
CXXFLAGS += -g -O0

#$(BIN): $(VSRCS) $(CSRCS) $(NVBOARD_ARCHIVE)
$(BIN): $(VSRCS) $(CSRCS)
	@rm -rf $(OBJ_DIR)
	$(VERILATOR) $(VERILATOR_CFLAGS) \
		--top-module $(TOPNAME) $^ \
		$(addprefix -CFLAGS , $(CXXFLAGS)) $(addprefix -LDFLAGS , $(LDFLAGS)) \
		--Mdir $(OBJ_DIR) --exe -o $(abspath $(BIN))

all: default
	@echo "Write this Makefile by your self."

# +trace is needed to gengerate waveforms for gtkwave
sim: $(BIN)
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	@echo "-- VERILATE ----------------"
	@$^ $(IMG) +trace
	@echo "-- RUN ---------------------"

debug: $(BIN)
	@echo "-- VERILATE debug ----------"
	@cgdb --args $^ $(IMG) +trace
	@echo "-- VERILATE debug done------"

clean:
	rm -rf $(BUILD_DIR)

.PHONY: default all clean run
include ../Makefile
