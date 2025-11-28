# Verilog专用配置
BUILD_DIR = $(BUILD_DIR_BASE)/npc
VERILATOR_FLAGS = $(VERILATOR_BASE_FLAGS) --Mdir $(BUILD_DIR)
TOP_NAME = ysyx_24100012_top
NAME = V$(TOP_NAME)

# Verilog源文件
VSOURCES = $(wildcard $(NPC_HOME)/vsrc/**/*.v $(NPC_HOME)/vsrc/*.v)
BINARY = $(BUILD_DIR)/$(NAME)
NPC_EXEC = $(BINARY) $(ARGS) $(IMG)

# Verilator基础配置
VERILATOR_BASE_FLAGS := --cc --exe --build -j 8 --vpi
VERILATOR_BASE_FLAGS += $(VCFLAGS)
VERILATOR_BASE_FLAGS += $(LDFLAGS)
VERILATOR_BASE_FLAGS += --top-module $(TOP_NAME)

build:
	mkdir -p $(BUILD_DIR)
	verilator $(VERILATOR_FLAGS) $(SOURCES) $(VSOURCES) --trace