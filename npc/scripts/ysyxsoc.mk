# ysyxSoC

ifneq ($(ARCH), riscv32e-ysyxsoc)
$(error Shouldn't include soc.mk when not building ysyxSoC, something is wrong)
endif

CXXFLAGS += -DSIM_SOC

SOC_HOME ?= ../ysyxSoC
SOC_PERIP_VSRCS = $(shell find $(abspath $(SOC_HOME)/perip) -name "*.v")
SOC_GENED_FILE = $(abspath $(SOC_HOME)/build/ysyxSoCFull.v)

$(SOC_GENED_FILE):
	$(MAKE) -C $(SOC_HOME) verilog

SIM_VSRCS += $(SOC_GENED_FILE)
SIM_VSRCS += $(SOC_PERIP_VSRCS)

VERILATOR_INCDIRS += $(abspath $(SOC_HOME)/perip/uart16550/rtl)
VERILATOR_INCDIRS += $(abspath $(SOC_HOME)/perip/spi/rtl)

RESET_PC = 30000000

VERILATOR_FLAGS += --timescale "1ns/1ns" --no-timing 
VERILATOR_FLAGS += -Wno-SYMRSVDWORD # make uart verilog happy

VERILATOR_FLAGS += -Wno-WIDTHEXPAND # make chiplink happy
# VERILATOR_FLAGS += -Wno-UNOPTFLAT

CXXFLAGS += -DENABLE_NVBOARD

# NVBOARD
NXDC_FILES = $(addprefix $(BUILD_DIR)/,$(shell find . -maxdepth 1 -name "*.nxdc"))
$(BUILD_DIR)/%.nxdc: %.nxdc
	@sed 's/top=.*/top=$(TOP_NAME)/g' $< > $@
NVB_AUTOBIND_SRC = $(abspath $(BUILD_DIR)/auto_bind.cpp)
$(NVB_AUTOBIND_SRC): $(NXDC_FILES)
	python3 $(NVBOARD_HOME)/scripts/auto_pin_bind.py $^ $@

# rules for NVBoard
SIM_CSRCS += $(NVB_AUTOBIND_SRC)
include $(NVBOARD_HOME)/scripts/nvboard.mk
