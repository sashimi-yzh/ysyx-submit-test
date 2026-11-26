PROJECT_DIR := $(abspath $(CURDIR))
WORKBENCH_ROOT := $(abspath $(PROJECT_DIR)/..)
SRC_ROOT := $(PROJECT_DIR)/csrc
NEMU_HOME ?= $(WORKBENCH_ROOT)/nemu
YSYXSOC_ROOT ?= $(WORKBENCH_ROOT)/ysyxSoC
YSYXSOC_BUILD := $(YSYXSOC_ROOT)/build
YSYXSOC_PERIP := $(YSYXSOC_ROOT)/perip

include ../Makefile

ifneq ($(words $(CURDIR)),1)
  $(error Unsupported: GNU Make cannot build in directories containing spaces, build elsewhere: '$(CURDIR)')
endif

ifeq ($(VERILATOR_ROOT),)
  VERILATOR := verilator
else
  export VERILATOR_ROOT
  VERILATOR := $(VERILATOR_ROOT)/bin/verilator
endif

SOC ?= 0
FST ?= 0
TRACE ?= 0
LOG ?= 0
DIFFTEST ?= 0
FFLASH  ?= 0
NVBOARD ?= 0
PERF    ?= 0
LOG_DIR ?= $(PROJECT_DIR)/log

F_CONFIG_FILE ?= $(PROJECT_DIR)/config/f_cpu
F_DEFAULT     ?= 0
ifeq ($(origin F),undefined)
  ifneq ($(wildcard $(F_CONFIG_FILE)),)
    F_FROM_FILE := $(strip $(shell head -n1 $(F_CONFIG_FILE) 2>/dev/null))
    ifneq ($(F_FROM_FILE),)
      ifeq ($(shell printf '%s' '$(F_FROM_FILE)' | grep -Eq '^[0-9]+$$' && echo ok),ok)
        F := $(F_FROM_FILE)
      else
        $(warning NPC: invalid F value '$(F_FROM_FILE)' in $(F_CONFIG_FILE); using default $(F_DEFAULT))
      endif
    endif
  endif
endif
ifeq ($(origin F),undefined)
  F := $(F_DEFAULT)
endif

BUILD_DIR := $(PROJECT_DIR)/build
WAVE_DIR := $(PROJECT_DIR)/wave
EVAL_DIR ?= $(PROJECT_DIR)/eval
MICROBENCH_DIR ?= $(WORKBENCH_ROOT)/am-kernels/benchmarks/microbench
PERF_EVAL_LOG := $(BUILD_DIR)/perf-eval.log
PERF_MICROBENCH_LOG := $(BUILD_DIR)/perf-microbench.log
$(shell mkdir -p $(BUILD_DIR) $(WAVE_DIR))

GEN_VERILOG := $(PROJECT_DIR)/scripts/gen_verilog.py
VERILOG_OUT := $(BUILD_DIR)/$(STUID).v

SIM_DIR := $(PROJECT_DIR)/sim
SIM_TB := $(SIM_DIR)/tb_iverilog.v
BIN2HEX := $(PROJECT_DIR)/scripts/bin2hex.py
IVERILOG ?= iverilog
VVP ?= vvp
IMG ?= $(WORKBENCH_ROOT)/am-kernels/kernels/hello/build/hello-riscv32e-npc.bin
IMG_ABS := $(abspath $(IMG))
SIM_HEX := $(BUILD_DIR)/sim-iverilog.hex
SIM_NETLIST_HEX := $(BUILD_DIR)/sim-netlist.hex
SIM_IVERILOG_VVP := $(BUILD_DIR)/sim-iverilog.vvp
SIM_NETLIST_VVP := $(BUILD_DIR)/sim-netlist.vvp
SIM_MAX_CYCLES ?= 5000000

CORE_RTL_SRCS := $(sort \
  $(wildcard $(PROJECT_DIR)/vsrc/*.v) \
  $(wildcard $(PROJECT_DIR)/vsrc/*.sv))
SIM_SRCS := \
  $(SRC_ROOT)/main.cpp \
  $(wildcard $(SRC_ROOT)/core/*.cpp) \
  $(wildcard $(SRC_ROOT)/sdb/*.cpp) \
  $(wildcard $(SRC_ROOT)/utils/*.cpp) \
  $(wildcard $(SRC_ROOT)/trace/*.cpp)

EXTRA_CFLAGS := -pthread
VERILATOR_TRACE_FLAGS :=

ifeq ($(SOC),1)
  MODE := soc
  TOP := ysyxSoCFull
  TOP_CLASS := VysyxSoCFull
  OBJ_DIR := $(BUILD_DIR)/obj_dir_soc
  PROG ?= /dev/null
  DIFFTEST_SO ?= $(NEMU_HOME)/build/riscv32-nemu-interpreter-ysyxsoc-so
  SOC_RTL_SRCS := \
    $(YSYXSOC_BUILD)/ysyxSoCFull.v \
    $(wildcard $(YSYXSOC_PERIP)/uart16550/rtl/*.v) \
    $(wildcard $(YSYXSOC_PERIP)/spi/rtl/*.v) \
    $(wildcard $(YSYXSOC_PERIP)/sdram/core_sdram_axi4/*.v) \
    $(wildcard $(YSYXSOC_PERIP)/sdram/*.v) \
    $(wildcard $(YSYXSOC_PERIP)/psram/efabless/*.v) \
    $(wildcard $(YSYXSOC_PERIP)/psram/*.v) \
    $(wildcard $(YSYXSOC_PERIP)/vga/*.v) \
    $(wildcard $(YSYXSOC_PERIP)/ps2/*.v) \
    $(wildcard $(YSYXSOC_PERIP)/gpio/*.v) \
    $(wildcard $(YSYXSOC_PERIP)/flash/*.v) \
    $(wildcard $(YSYXSOC_PERIP)/bitrev/*.v) \
    $(wildcard $(YSYXSOC_PERIP)/amba/*.v)
  RTL_SRCS := $(SOC_RTL_SRCS) $(CORE_RTL_SRCS)
  EXTRA_CFLAGS += -DSOC_MODE
  VERILATOR_MODE_FLAGS := \
    -DSOC_MODE \
    -I$(YSYXSOC_PERIP)/uart16550/rtl \
    -I$(YSYXSOC_PERIP)/spi/rtl \
	  --autoflush
  MODE_PREREQUISITE := check-soc
else
  MODE := standalone
  TOP := top
  TOP_CLASS := Vtop
  OBJ_DIR := $(BUILD_DIR)/obj_dir
  PROG ?= test/mem.bin
  DIFFTEST_SO ?= $(NEMU_HOME)/build/riscv32-nemu-interpreter-standalone-so
  RTL_SRCS := $(CORE_RTL_SRCS)
endif

ifeq ($(NVBOARD), 1)
  EXTRA_CFLAGS += -DENABLE_NVBOARD
  NVBOARD_PREREQ = $(SRC_AUTO_BIND) nvboard-archive
  NVBOARD_CSRCS  = $(SRC_AUTO_BIND)
  NVBOARD_LDFLAGS = $(NVBOARD_ARCHIVE)
  NVBOARD_HOME ?= $(WORKBENCH_ROOT)/nvboard
  NXDC_FILES = $(PROJECT_DIR)/constr/soc.nxdc
  SRC_AUTO_BIND = $(BUILD_DIR)/auto_bind.cpp

$(SRC_AUTO_BIND): $(NXDC_FILES)
	python3 $(NVBOARD_HOME)/scripts/auto_pin_bind.py $^ $@

include $(NVBOARD_HOME)/scripts/nvboard.mk
else
  NVBOARD_PREREQ =
  NVBOARD_CSRCS  =
  NVBOARD_LDFLAGS =
endif

PROG_ABS := $(abspath $(PROG))
ELF ?=
ELF_ABS := $(if $(ELF),$(abspath $(ELF)))
BATCH ?= -b

VERILATOR_FLAGS := \
  --top-module $(TOP) \
  --x-assign fast --x-initial fast \
  --timescale "1ns/1ns" --no-timing \
  $(VERILATOR_MODE_FLAGS)

ifeq ($(FST),1)
  VERILATOR_TRACE_FLAGS += --trace-fst --trace-structs
  EXTRA_CFLAGS += -DENABLE_FST
endif

ifeq ($(TRACE),1)
  EXTRA_CFLAGS += -DENABLE_TRACE
endif

ifeq ($(LOG),1)
  EXTRA_CFLAGS += -DENABLE_LOG
endif

ifneq ($(ELF),)
  ELF_ARG := -e $(ELF_ABS)
endif

ifeq ($(DIFFTEST),1)
  DIFFTEST_ARG := -d $(DIFFTEST_SO)
endif

ifeq ($(FFLASH), 1)
  VERILATOR_FLAGS += -DFAST_FLASH
  EXTRA_CFLAGS += -DFAST_FLASH
endif

ifeq ($(PERF), 1)
  VERILATOR_FLAGS += -DENABLE_PERF
  EXTRA_CFLAGS += -DENABLE_PERF
endif

ifneq ($(filter IC_SETS IC_WORDS,$(MAKEOVERRIDES)),)
  VERILATOR_FLAGS += -DIC_SETS=$(IC_SETS) -DIC_WORDS=$(IC_WORDS)
endif

ifneq ($(strip $(F)),)
  ifneq ($(strip $(F)),0)
    EXTRA_CFLAGS += -DF_CPU=$(strip $(F))
  endif
endif

SDL_CFLAGS := $(shell sdl2-config --cflags)
SDL_LIBS := $(shell sdl2-config --libs) -lSDL2_image -lSDL2_ttf

define VERILATE_CMD
	$(VERILATOR) $(VERILATOR_FLAGS) $(VERILATOR_TRACE_FLAGS) \
	  -cc --exe --build -j \
	  -CFLAGS "-std=c++14 -O3 \
	    -I$(SRC_ROOT) \
	    -I$(NEMU_HOME)/tools/capstone/repo/include \
	    -I$(NEMU_HOME)/include \
      -I$(NVBOARD_HOME)/usr/include \
	    $(SDL_CFLAGS) $(EXTRA_CFLAGS)" \
	  -LDFLAGS "$(NVBOARD_LDFLAGS) -lreadline -ldl $(SDL_LIBS) -pthread" \
	  $(RTL_SRCS) $(SIM_SRCS) \
	  --Mdir $(OBJ_DIR) \
    $(NVBOARD_CSRCS)
endef

all: build

show-config:
	@echo "MODE=$(MODE) SOC=$(SOC) TOP=$(TOP) TOP_CLASS=$(TOP_CLASS)"
	@echo "OBJ_DIR=$(OBJ_DIR)"
	@echo "FST=$(FST) TRACE=$(TRACE) LOG=$(LOG) DIFFTEST=$(DIFFTEST) FFLASH=$(FFLASH)"
	@echo "PERF=$(PERF) NVBOARD=$(NVBOARD) F=$(F)"
	@echo "LOG_DIR=$(LOG_DIR)"
	@echo "PROG=$(PROG_ABS) ELF=$(ELF_ABS)"
	@echo "YSYXSOC_ROOT=$(YSYXSOC_ROOT)"

check-soc:
	@test -f "$(YSYXSOC_BUILD)/ysyxSoCFull.v" || { \
	  echo "Error: missing $(YSYXSOC_BUILD)/ysyxSoCFull.v; run 'make -C $(YSYXSOC_ROOT) verilog'."; \
	  exit 1; \
	}
	@grep -q 'ysyx_26020070' "$(YSYXSOC_BUILD)/ysyxSoCFull.v" || { \
	  echo "Error: ysyxSoCFull.v does not instantiate ysyx_26020070."; \
	  exit 1; \
	}

lint: $(MODE_PREREQUISITE)
	$(VERILATOR) --lint-only -Wno-fatal $(VERILATOR_FLAGS) $(RTL_SRCS)

build: $(NVBOARD_PREREQ) $(MODE_PREREQUISITE) $(if $(filter 1,$(DIFFTEST)),$(DIFFTEST_SO))
	@mkdir -p $(BUILD_DIR) $(WAVE_DIR)
	@echo "-- BUILD NPC [MODE=$(MODE) FST=$(FST) TRACE=$(TRACE) LOG=$(LOG) FFLASH=$(FFLASH)] --"
	$(VERILATE_CMD)

run: build
	@if [ ! -r "$(PROG_ABS)" ]; then \
	  echo "Error: program '$(PROG_ABS)' not found."; exit 1; \
	fi
	@if [ "$(DIFFTEST)" = "1" ] && [ ! -f "$(DIFFTEST_SO)" ]; then \
	  echo "Error: DiffTest REF '$(DIFFTEST_SO)' not found."; exit 1; \
	fi
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	@echo "-- RUN NPC [MODE=$(MODE) DIFFTEST=$(DIFFTEST)] --"
	@cd $(PROJECT_DIR) && \
	  NPC_LOG_DIR=$(LOG_DIR) \
	  $(OBJ_DIR)/$(TOP_CLASS) $(PROG_ABS) \
	  $(ELF_ARG) $(DIFFTEST_ARG) $(BATCH)

verilog:
	@test -f "$(GEN_VERILOG)" || { \
	  echo "Error: missing $(GEN_VERILOG)"; exit 1; \
	}
	STUID=$(STUID) python3 $(GEN_VERILOG)
	@test -f "$(VERILOG_OUT)" || { \
	  echo "Error: $(VERILOG_OUT) was not generated"; exit 1; \
	}
	@echo "[verilog] generated $(VERILOG_OUT)"

sim-iverilog: verilog
	@test -r "$(IMG_ABS)" || { \
	  echo "Error: program '$(IMG_ABS)' not found (pass IMG=xxx.bin)."; exit 1; \
	}
	@test -f "$(SIM_TB)" || { \
	  echo "Error: missing $(SIM_TB)"; exit 1; \
	}
	python3 $(BIN2HEX) $(IMG_ABS) $(SIM_HEX)
	$(IVERILOG) -g2012 -DSOC_MODE -DSYNTHESIS -DSIM_IVERILOG \
	  -o $(SIM_IVERILOG_VVP) $(SIM_TB) $(VERILOG_OUT)
	@echo "[sim-iverilog] running $(IMG_ABS)"
	$(VVP) $(SIM_IVERILOG_VVP) \
	  +hex=$(abspath $(SIM_HEX)) +max_cycles=$(SIM_MAX_CYCLES)

sim-iverilog-netlist:
	@test -r "$(IMG_ABS)" || { \
	  echo "Error: program '$(IMG_ABS)' not found (pass IMG=xxx.bin)."; exit 1; \
	}
	@test -n "$(NETLIST)" || { \
	  echo "Error: NETLIST is required (pass NETLIST=xxx.v)."; exit 1; \
	}
	@test -n "$(CELLS)" || { \
	  echo "Error: CELLS is required (pass CELLS=xxx.v)."; exit 1; \
	}
	@test -f "$(SIM_TB)" || { \
	  echo "Error: missing $(SIM_TB)"; exit 1; \
	}
	python3 $(BIN2HEX) $(IMG_ABS) $(SIM_NETLIST_HEX)
	$(IVERILOG) -g2012 -DSIM_NETLIST \
	  -o $(SIM_NETLIST_VVP) $(SIM_TB) $(NETLIST) $(CELLS)
	@echo "[sim-iverilog-netlist] running $(IMG_ABS) with $(NETLIST)"
	$(VVP) $(SIM_NETLIST_VVP) \
	  +hex=$(abspath $(SIM_NETLIST_HEX)) +max_cycles=$(SIM_MAX_CYCLES)

# 一键性能评估：清理 NPC -> eval 综合 -> microbench train -> 打印报告
perf:
	@set -e; \
	echo "[perf] 1/3 clean NPC build"; \
	$(MAKE) --no-print-directory -C $(PROJECT_DIR) clean; \
	mkdir -p $(BUILD_DIR) $(WAVE_DIR); \
	echo "[perf] 2/3 eval: $(EVAL_DIR)"; \
	if ! $(MAKE) --no-print-directory -C $(EVAL_DIR) all > $(PERF_EVAL_LOG) 2>&1; then \
	  echo "[perf] eval failed; tail of $(PERF_EVAL_LOG):"; \
	  tail -n 80 $(PERF_EVAL_LOG); \
	  exit 1; \
	fi; \
	echo "[perf] 3/3 microbench train: $(MICROBENCH_DIR)"; \
	if ! $(MAKE) --no-print-directory -C $(MICROBENCH_DIR) \
	      AM_HOME=$(WORKBENCH_ROOT)/abstract-machine \
	      NPC_HOME=$(PROJECT_DIR) \
	      ARCH=riscv32e-ysyxsoc SOC=1 FFLASH=0 PERF=1 \
	      TRACE=0 FST=0 DIFFTEST=0 NVBOARD=0 LOG=1 LOG_DIR=$(LOG_DIR) \
	      mainargs=train run \
	      > $(PERF_MICROBENCH_LOG) 2>&1; then \`
	  echo "[perf] microbench failed; tail of $(PERF_MICROBENCH_LOG):"; \
	  tail -n 80 $(PERF_MICROBENCH_LOG); \
	  exit 1; \
	fi; \
	echo ""; \
	echo "==================== PERF REPORT ===================="; \
	if grep -q "Performance Report" $(PERF_MICROBENCH_LOG); then \
	  awk '/Performance Report/ {show=1} show {print} show && /^=+$$/ {exit}' $(PERF_MICROBENCH_LOG); \
	else \
	  echo "(未找到 NPC Performance Report，完整日志: $(PERF_MICROBENCH_LOG))"; \
	fi; \
	echo ""; \
	echo "==================== EVAL REPORT ===================="; \
	$(MAKE) --no-print-directory -C $(EVAL_DIR) report; \
	echo ""; \
	echo "[perf] logs: $(PERF_EVAL_LOG), $(PERF_MICROBENCH_LOG)"

clean:
	-rm -rf $(BUILD_DIR) $(WAVE_DIR) $(PROJECT_DIR)/npc.log

clean-log:
	-rm -rf $(LOG_DIR)

.PHONY: all show-config check-soc lint build run \
	build-standalone run-standalone build-soc run-soc perf clean clean-log \
	verilog sim-iverilog sim-iverilog-netlist