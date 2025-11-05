NPC_TOPNAME = ysyx_23060246
MAIN = $(NPC_TOPNAME).npcMain
BUILD_DIR = $(NPC_HOME)/build

NXDC_FILES = $(NPC_HOME)/constr/soc.nxdc
SDC_FILE = $(NPC_HOME)/scripts/top.sdc

-include .config

USE_SOC ?= y
ifneq ($(ARCH),riscv32e-npc)
USE_SOC = y
$(info ***************************)
$(info * Use SoC for Simulation! *)
$(info ***************************)
else
USE_SOC = n
endif 

USE_NVBOARD ?= y
ifneq ($(USE_SOC),y)
USE_NVBOARD := n 
endif 

OBJ_DIR := $(BUILD_DIR)/OBJ_DIR
ifeq ($(USE_SOC),y)
OBJ_DIR := $(BUILD_DIR)/OBJ_DIR_SOC
else 
OBJ_DIR := $(BUILD_DIR)/OBJ_DIR_NPC
endif

IMG ?=
ifeq ($(IMG),)
ifeq ($(USE_SOC),y)
IMG = "$(YSYX_HOME)/am-kernels/tests/cpu-tests/build/sum-riscv32e-ysyxsoc.bin"
else
IMG = "$(YSYX_HOME)/am-kernels/tests/cpu-tests/build/sum-riscv32e-npc.bin"
endif
endif

ifeq ($(USE_SOC),y)
DIFF_REF="$(NPC_HOME)/difftest/riscv32e-nemu-soc-so"
else
DIFF_REF="$(NPC_HOME)/difftest/riscv32e-nemu-npc-so"
endif
ARGS = -v --diff=$(DIFF_REF)

CLK_FREQ_MHZ?=890

SCALA_DIR := $(NPC_HOME)/src/main/scala
VERILOG_DIR := $(BUILD_DIR)/verilog
MILLFLAGS ?= 

ifeq ($(USE_SOC),y)
MILLENV += USE_SOC=y
endif 

VERILATOR = verilator
VERILATOR_COVERAGE = verilator_coverage

V_INCPATH+=$(abspath $(YSYX_HOME)/npc/vsrc)
V_INCPATH+=$(shell find $(YSYX_HOME)/ysyxSoC/perip -type f -name '*defines*.v' -exec dirname {} \;)
V_INCFLAGS=$(addprefix -I, $(V_INCPATH))
VERILATOR_FLAGS = -MMD --build -cc --public \
				--x-assign fast --x-initial fast --noassert \
				$(V_INCFLAGS) --threads 1 --autoflush --trace-underscore    --trace-max-array 2048 \
				 --trace-max-width 128

# timescale set
VERILATOR_FLAGS += --timescale 1us/1us --no-timing
VERILATOR_CONFIG = ./scripts/verilator.vlt



ifeq ($(CONFIG_WAVE_FST),y)
	VERILATOR_FLAGS += --trace-fst
endif
ifeq ($(CONFIG_WAVE_VCD),y)
	VERILATOR_FLAGS += --trace
endif 

ifeq ($(USE_SOC),y)
	TOPNAME = ysyxSoCFull
else
	TOPNAME = npcSimTop
endif


# C flags
INC_PATH +=$(abspath csrc/include)
INC_PATH +=$(abspath csrc/isa/$(CONFIG_ISA)/include)
INC_PATH +=$(abspath csrc/isa/$(CONFIG_ISA)/local-include)

INCFLAGS = $(addprefix -I, $(INC_PATH))
CXXFLAGS += $(INCFLAGS)
CXXFLAGS += $(CFLAGS)
CXXFLAGS += -fmacro-prefix-map=$(NPC_HOME)=npc
CXXFLAGS += -fno-stack-protector
CXXFLAGS += -Wall $(INCFLAGS) -g -DTOP_NAME="\"V$(TOPNAME)\"" -fpermissive
ifeq ($(USE_SOC),y)
	CXXFLAGS += -DUSE_SOC=1
endif

ifeq ($(USE_NVBOARD),y)
  CXXFLAGS += -DUSE_NVBOARD=1
endif
$(info USE_NVBOARD=$(USE_NVBOARD))
$(info CXXFLAGS=$(CXXFLAGS))
#CXXFLAGS += $(shell llvm-config --cxxflags)
LDFLAGS += $(shell  llvm-config --ldflags --libs --system-libs) -fPIE
LDFLAGS += -lreadline
LDFLAGS += -lz


# source file
VSRCS = $(shell find $(abspath ./vsrc) -name "*.v")
VSRCS += $(shell find $(abspath $(VERILOG_DIR)) -name "*.v" -or -name "*.sv")

ifeq ($(USE_SOC),y)
VSRCS += $(shell find $(YSYX_HOME)/ysyxSoC/perip -name "*.v")
VSRCS += $(shell find $(YSYX_HOME)/ysyxSoC/build -name "*.v")
endif

SCALA_FILE = $(shell find ./src/main -name '*.scala')

CSRCS = $(shell find $(abspath ./csrc) \( -path $(abspath ./csrc/device) \-prune \
 		-or -path $(abspath ./csrc/utils/disasm.cc) -prune \) \
		-o \( -name "*.c" -or -name "*.cc" -or -name "*.cpp" \) -print)

SYN_ADDITION_FILES = $(NPC_HOME)/vsrc/debug.v


BIN = $(BUILD_DIR)/$(TOPNAME)
NPC_EXEC := $(BIN)

default: all 
all: $(BIN)

# constraint file
ifeq ($(USE_NVBOARD),y)
SRC_AUTO_BIND = $(abspath $(BUILD_DIR)/auto_bind.cpp)
$(SRC_AUTO_BIND): $(NXDC_FILES)
		python3 $(NVBOARD_HOME)/scripts/auto_pin_bind.py $^ $@

CSRCS += $(SRC_AUTO_BIND)
endif
include $(NPC_HOME)/csrc/device/filelist.mk

$(OBJ_DIR)/disasm.o: $(abspath csrc/utils/disasm.cc)
	@mkdir -p $(OBJ_DIR)
	$(CXX)  $(shell llvm-config --cxxflags) \
		-fPIE -c $< -o $@ 

# rules for NVBoard
include $(NVBOARD_HOME)/scripts/nvboard.mk


$(BIN): $(CSRCS) verilog $(NVBOARD_ARCHIVE) $(OBJ_DIR)/disasm.o
	$(VERILATOR) $(VERILATOR_CONFIG) $(VERILATOR_FLAGS) -top $(TOPNAME) $(CSRCS) $(VSRCS) $(OBJ_DIR)/disasm.o $(NVBOARD_ARCHIVE)\
		$(addprefix -CFLAGS , $(CXXFLAGS)) $(addprefix -LDFLAGS , $(LDFLAGS)) \
		--Mdir $(OBJ_DIR) --exe -o $(abspath $(BIN)) --top-module $(TOPNAME)


#SCALA_TIME = $(shell find $(SCALA_DIR) -type f -exec stat --format '%Y' {} \; | sort -n | tail -n 1)
SCALA_TIME = $(shell ( find ./src -type f -exec stat --format '%Y' {} \; ;  find . -name ".config.json" -exec stat --format '%Y' {} \; ) | sort -n | tail -n 1)

$(shell mkdir -p $(BUILD_DIR)/verilog)
VERILOG_TIME = $(shell find $(VERILOG_DIR) -type f -exec stat --format '%Y' {} \; | sort -n | tail -n 1)
VERILOG_TIME := $(if $(VERILOG_TIME),$(VERILOG_TIME),0)


RC_DIR     := $(NPC_HOME)/rocket-chip
RC_URL     := https://github.com/chipsalliance/rocket-chip.git
RC_MARKER  := $(RC_DIR)/common.sc
RC_COMMIT  := d0c6b50fdefcdbe121e9788433ea51f7efaf1d32


$(RC_MARKER):
	@echo "[init] ensuring rocket-chip exists (submodule or fresh clone)"
	
	@git -C "$(NPC_HOME)" config url."https://github.com/".insteadOf "git@github.com:"

	@if git -C "$(NPC_HOME)" config -f .gitmodules --get-regexp '^submodule\.rocket-chip\.url' >/dev/null 2>&1; then \
	  echo "[init] detected submodule entry for rocket-chip -> using submodule update"; \
	  git -C "$(NPC_HOME)" submodule set-url -- rocket-chip "$(RC_URL)"; \
	  git -C "$(NPC_HOME)" submodule update --init --recursive rocket-chip; \
	else \
	  echo "[init] no submodule mapping; cloning rocket-chip via HTTPS"; \
	  rm -rf "$(RC_DIR)"; \
	  git clone --filter=tree:0 "$(RC_URL)" "$(RC_DIR)"; \
	fi

	@if [ -n "$(RC_COMMIT)" ]; then \
	  echo "[init] checking out RC_COMMIT=$(RC_COMMIT)"; \
	  git -C "$(RC_DIR)" fetch --depth 1 origin "$(RC_COMMIT)"; \
	  git -C "$(RC_DIR)" checkout --detach "$(RC_COMMIT)"; \
	fi

	@git -C "$(RC_DIR)" submodule update --init --recursive --depth 1 || \
	  git -C "$(RC_DIR)" submodule update --init --recursive
	@git -C "$(RC_DIR)" config url."https://github.com/".insteadOf "git@github.com:"
	@touch "$(RC_MARKER)"


verilog: $(SCALA_FILE) sigmap .config.json $(RC_MARKER)
ifeq ($(CHECK_SCALA),1)
	@if [ "$(SCALA_TIME)" -gt "$(VERILOG_TIME)" ]; then \
		echo "Scala directory changed or Verilog directory missing, generating Verilog..."; \
		($(MILLENV) ./mill -i $(NPC_TOPNAME).runMain $(MAIN) -td $(VERILOG_DIR) $(MILLFLAGS)); \
	else \
		echo "No changes detected in Scala directory, skipping Verilog generation."; \
	fi
else
	($(MILLENV) ./mill -i $(NPC_TOPNAME).runMain $(MAIN) -td $(VERILOG_DIR) $(MILLFLAGS)); 
endif
	sed -i '/firrtl_black_box_resource_files.f/, $$d' $(NPC_HOME)/build/verilog/$(NPC_TOPNAME).sv
	# add prefix 
	sed -i 's/\<regs_16x32\>/ysyx_23060246_regs_16x32/g' $(NPC_HOME)/build/verilog/$(NPC_TOPNAME).sv
	sed -i 's/\<regs_15x32\>/ysyx_23060246_regs_15x32/g' $(NPC_HOME)/build/verilog/$(NPC_TOPNAME).sv
	sed -i 's/\<regs_31x32\>/ysyx_23060246_regs_31x32/g' $(NPC_HOME)/build/verilog/$(NPC_TOPNAME).sv
	sed -i 's/\<regs_32x32\>/ysyx_23060246_regs_32x32/g' $(NPC_HOME)/build/verilog/$(NPC_TOPNAME).sv

	# CI needs SV file in the build/
	cp $(NPC_HOME)/build/verilog/$(NPC_TOPNAME).sv $(NPC_HOME)/build/$(NPC_TOPNAME).sv
	cat $(NPC_HOME)/iverilog/debug_iverilog.v >> $(NPC_HOME)/build/$(NPC_TOPNAME).sv
	
	



SIGMAP_TIME = $(shell find $(SCALA_DIR) -name sigmap.scala -exec stat --format '%Y' {} \; | sort -n | tail -n 1)
SIGMAP_TABLE_TIME = $(shell find $(NPC_HOME)/tools -name control_table.xlsx -exec stat --format '%Y' {} \; | sort -n | tail -n 1)

sigmap: $(NPC_HOME)/tools/control_gen/control_table.xlsx
	@if [ "$(SIGMAP_TABLE_TIME)" -gt "$(SIGMAP_TIME)" ]; then \
		echo "Sigmap (Control Signal) Table Changed, Generating Code..."; \
		cd $(NPC_HOME)/tools/control_gen/ && python control_gen.py > $(NPC_HOME)/src/main/scala/sigmap.scala; \
	else \
		echo "No changes detected in Sigmap (Control Signal) Table"; \
	fi


sim: run
run: $(BIN)
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	$^ $(ARGS) $(IMG)


syn: verilog $(SYN_ADDITION_FILES)
	make -C $(YOSYSSTA_PATH) sta DESIGN=$(NPC_TOPNAME) SDC_FILE=$(SDC_FILE) \
	RTL_FILES="$(BUILD_DIR)/verilog/$(NPC_TOPNAME).sv $(SYN_ADDITION_FILES)" CLK_FREQ_MHZ=$(CLK_FREQ_MHZ)
clean_syn:
	make -C $(YOSYSSTA_PATH) clean

syn_new: verilog $(SYN_ADDITION_FILES)
	source /opt/oss-cad-suite/environment && \
	make -C $(YOSYSSTA_NEW_PATH) sta DESIGN=$(NPC_TOPNAME) SDC_FILE=$(SDC_FILE) \
	RTL_FILES="$(BUILD_DIR)/verilog/$(NPC_TOPNAME).sv $(SYN_ADDITION_FILES)" CLK_FREQ_MHZ=$(CLK_FREQ_MHZ)


PERF_DATE=$(shell date +%Y-%m%d-%H%M%S)
PERF_PATH=$(NPC_HOME)/data/$(PERF_DATE)

perf: verilog syn
	@make -C /home/han/Disk/Document/PROJECT/ysyx/ysyx-workbench/am-kernels/benchmarks/microbench \
		 ARCH=riscv32e-ysyxsoc run BATCH=1 mainargs="train"
	@mkdir -p $(PERF_PATH)
	@bash $(NPC_HOME)/scripts/perf.sh  $(NPC_TOPNAME) $(CLK_FREQ_MHZ) | \
	tee >(sed -r "s/\x1B\[[0-9;]*m//g" > $(PERF_PATH)/perf.txt)
	@git rev-parse HEAD > $(PERF_PATH)/commit_hash.txt
	@echo $(DESP) > $(PERF_PATH)/description.txt
	@git add -f $(PERF_PATH)/*


rsync: 
	bash ./scripts/rsync.sh $(NPC_TOPNAME) $(CLK_FREQ_MHZ)


# It needs `-B`, because the time on the server is not accurate
vcs_build: rsync
	ssh -X -C ${GZIC_SERVER_USER}@${GZIC_SERVER_IP} "cd ${GZIC_SERVER_USER_HOME}/PROJECT/npc && make -f vcs/vcs.mk -B"

vcs_sim: rsync
	ssh -X -C ${GZIC_SERVER_USER}@${GZIC_SERVER_IP} "cd ${GZIC_SERVER_USER_HOME}/PROJECT/npc && make -f vcs/vcs.mk -B && ./build/simv"

vcs_build_netlist: rsync
	ssh -X -C ${GZIC_SERVER_USER}@${GZIC_SERVER_IP} "cd ${GZIC_SERVER_USER_HOME}/PROJECT/npc && make -f vcs/vcs.mk -B NETLIST=1"

vcs_sim_netlist: rsync
	ssh -X -C ${GZIC_SERVER_USER}@${GZIC_SERVER_IP} "cd ${GZIC_SERVER_USER_HOME}/PROJECT/npc && make -f vcs/vcs.mk -B NETLIST=1 && ./build/simv"


# menuconfig and autoconf.h
include $(NPC_HOME)/scripts/config.mk

clean:
	-rm -rf $(BUILD_DIR) logs

clean_mill:
	-rm -rf out

clean_all: clean clean_mill

.PHONY: clean clean_all clean_mill srun run sim verilog all default

include ../Makefile

include ./iverilog/iverilog.mk
