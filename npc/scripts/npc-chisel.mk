# Chisel专用配置
SOC_HOME = $(YSYX_HOME)/ysyxSoC
ifdef CONFIG_IVERILOG
	BUILD_DIR = $(BUILD_DIR_BASE)/npc-chisel-iverilog
else
	ifdef CONFIG_SOC
		BUILD_DIR = $(BUILD_DIR_BASE)/npc-chisel-soc
	else 
		BUILD_DIR = $(BUILD_DIR_BASE)/npc-chisel
	endif
endif

ifdef CONFIG_SOC
	TOP_NAME = ysyxSoCFull
else 
	TOP_NAME = Top
endif

NAME = V$(TOP_NAME)
ARCH ?= riscv32e-ysyxsoc

VERILATOR_DEFS = $(foreach v, \
    $(filter CONFIG_%, $(.VARIABLES)), \
    -D$(v)=1)

# SV源文件
ifdef CONFIG_IVERILOG
    SVSOURCES = $(wildcard $(NPC_HOME)/build/Iverilog*.v wildcard $(NPC_HOME)/build/Iverilog*.sv  $(NPC_HOME)/build/TopAXI4LiteSlave.sv $(NPC_HOME)/build/Top_mask_expander.v)
else 
	ifdef CONFIG_SOC
		SVSOURCES = $(wildcard $(NPC_HOME)/build/ysyx_24100012.v)
		SVSOURCES += $(wildcard $(YSYX_HOME)/ysyxSoC/build/*.v  $(YSYX_HOME)/ysyxSoC/build/*.sv)
	else
		SVSOURCES = $(wildcard $(NPC_HOME)/build/Top*.v wildcard $(NPC_HOME)/build/Top*.sv $(NPC_HOME)/build/ysyx_24100012.v)
	endif
endif

ifdef CONFIG_SOC
	START_ADDR = 30000000
else 
	START_ADDR = 80000000
endif


BINARY = $(BUILD_DIR)/$(NAME)
NPC_EXEC = $(BINARY) $(ARGS) $(IMG)
NPC_PERF = $(BINARY) $(PERF_ARGS) $(IMG)

VSINC_PATH := $(SOC_HOME)/perip/uart16550/rtl
VSINC_PATH += $(SOC_HOME)/perip/spi/rtl
VINCLUDES = $(addprefix -I, $(VSINC_PATH))
VERILATOR_BASE_FLAGS += $(VINCLUDES)
VERILATOR_BASE_FLAGS += --top-module $(TOP_NAME)
VERILATOR_FLAGS = $(VERILATOR_BASE_FLAGS) --Mdir $(BUILD_DIR)
VERILATOR_FLAGS +=  $(VERILATOR_DEFS) 

# build: $(SVSOURCES) $(SOURCES) $(NVBOARD_ARCHIVE) 
build: $(SVSOURCES) $(SOURCES) $(NVBOARD_ARCHIVE) 
	mkdir -p $(BUILD_DIR)
	$(MAKE) -C $(NPC_HOME) verilator-build 

verilator-build:
	@echo VERILATOR_DEFS $(VERILATOR_DEFS)
	verilator -Wno-WIDTHEXPAND $(VERILATOR_FLAGS) $(SOURCES) $(SVSOURCES)  --trace-fst --autoflush

lint:$(SVSOURCES) $(SOURCES) 
	verilator --lint-only -Wall -Wno-DECLFILENAME  $(VERILATOR_FLAGS) $(SOURCES) $(SVSOURCES) 

