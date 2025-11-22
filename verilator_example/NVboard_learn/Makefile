TOP_NAME=ps2_keyboard
VERILATOR=verilator
NXDC_FILE=constr/ps2_keyboard.nxdc
INC_PATH ?= 
#CSRCS= $(abspath ./csrc/light_main.cpp)

VERILATOR_CFLAGS += -MMD --build -cc \
				-O3 --x-assign fast --x-initial fast --noassert

BUILD_DIR=./build
OBJ_DIR=$(BUILD_DIR)/obj_dir
BIN=$(BUILD_DIR)/$(TOP_NAME)

default:$(BIN)
$(shell mkdir -p $(BUILD_DIR))
SRC_AUTO_BIND = $(abspath $(BUILD_DIR)/auto_bind.cpp)
$(SRC_AUTO_BIND):$(NXDC_FILE)
	python3 $(NVBOARD_HOME)/scripts/auto_pin_bind.py $^ $@

VSRCS=$(shell find $(abspath ./vsrc) -name "*.v")
CSRCS = $(shell find $(abspath ./csrc) -name "*.c" -or -name "*.cc" -or -name "*.cpp")
CSRCS += $(SRC_AUTO_BIND)

include $(NVBOARD_HOME)/scripts/nvboard.mk

INCFLAGS = $(addprefix -I, $(INC_PATH))
CXXFLAGS += $(INCFLAGS) -DTOP_NAME="\"V$(TOP_NAME)\""

$(BIN): $(VSRCS) $(CSRCS) $(NVBOARD_ARCHIVE)
	@rm -rf $(OBJ_DIR)
	$(VERILATOR) $(VERILATOR_CFLAGS) \
		--top-module $(TOP_NAME) $^ \
		$(addprefix -CFLAGS , $(CXXFLAGS)) $(addprefix -LDFLAGS , $(LDFLAGS)) \
		--Mdir $(OBJ_DIR) --exe -o $(abspath $(BIN))

all:default
	@echo "Write this Makefile by your self."

sim: $(BIN)
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	@echo "Write this Makefile by your self."
	@$^
clean:
	rm -rf $(BUILD_DIR)
.PHONY: all sim clean default

#include ../Makefile
