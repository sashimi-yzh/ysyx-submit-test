include ../Makefile
include $(NVBOARD_HOME)/scripts/nvboard.mk
BUILD_DIR := ./build
RTL_DIR := $(BUILD_DIR)/rtl
CXX_SRC := src/cpp
ARGS ?=
VERILATOR_ROOT := $(shell verilator --getenv VERILATOR_ROOT)
include NPCConfig.mk
ifneq ($(filter bear sim ysyxsoc-run ysyxsoc-gdb ysyxsoc,$(MAKECMDGOALS)),)
  TOP := ysyxSoCFull
  YSYXSOC_SV_FILES := $(shell find ../ysyxSoC/perip -name '*.v') ../ysyxSoC/build/ysyxSoCFull.v
  YSYXSOC_SV_INCLUDE := ../ysyxSoC/perip/uart16550/rtl ../ysyxSoC/perip/spi/rtl
  CXXFLAGS += -DUSE_YSYXSOC
else
  TOP := $(STUID)
  YSYXSOC_SV_FILES :=
  YSYXSOC_SV_INCLUDE :=
endif
ifneq ($(filter itrace,$(MAKECMDGOALS)),)
  CXXFLAGS += -DFAST_ITRACE
endif
ifneq ($(filter btrace,$(MAKECMDGOALS)),)
  CXXFLAGS += -DFAST_BTRACE
endif
SV_FILES = $(BUILD_DIR)/$(STUID).v $(YSYXSOC_SV_FILES)

TARGET_SUFFIX := $(TOP)
OBJ_DIR := $(BUILD_DIR)/compile-$(TARGET_SUFFIX)
CXXFLAGS_STAMP := $(OBJ_DIR)/.cxxflags
VERILATOR_DIR := $(BUILD_DIR)/verilator-$(TARGET_SUFFIX)
VERILOG_STAMP := $(BUILD_DIR)/.verilog-$(TARGET_SUFFIX).stamp
MILL_ARGS_STAMP := $(BUILD_DIR)/.mill-args.stamp
MILL_STAMP := $(BUILD_DIR)/.mill.stamp

EXE := $(BUILD_DIR)/$(TOP)
SV_INCLUDE := $(YSYXSOC_SV_INCLUDE) $(RTL_DIR)/verification

VERILATOR_RUNTIME_CPP := \
						$(VERILATOR_ROOT)/include/verilated.cpp \
						$(VERILATOR_ROOT)/include/verilated_vcd_c.cpp \
						$(VERILATOR_ROOT)/include/verilated_threads.cpp
VERILATOR_RUNTIME_OBJ = $(patsubst $(VERILATOR_ROOT)/include/%.cpp, $(OBJ_DIR)/%.o, $(VERILATOR_RUNTIME_CPP))
EXE_GOALS := sim npc-run npc-gdb ysyxsoc-run ysyxsoc-gdb ysyxsoc npc itrace btrace
ifneq ($(filter $(EXE_GOALS) $(EXE),$(MAKECMDGOALS)),)
-include $(VERILOG_STAMP)
endif
ifneq ($(filter sim-iverilog,$(MAKECMDGOALS)),)
-include $(MILL_STAMP)
endif
VERILATOR_OBJ += $(VERILATOR_RUNTIME_OBJ)
CXX_FILES := $(shell find $(CXX_SRC) -name '*.cpp')
CXX_H_FILES := $(shell find $(CXX_SRC) -name '*.hpp')
CXX_OBJ = $(patsubst src/cpp/%.cpp, $(OBJ_DIR)/%.o, $(CXX_FILES))
SCALA_FILES := $(shell find ./src/scala -name '*.scala')
IMG := char-test.bin

AM_HOME  ?= $(abspath ../abstract-machine)
ARCH     ?= riscv32e-ysyxsoc
TEST     ?= char-test.c

TEST_PATH   := $(abspath $(TEST))
TEST_SRCDIR := $(dir $(TEST_PATH))
TEST_NAME   := $(basename $(notdir $(TEST_PATH)))

SIM_IMG  := $(TEST_SRCDIR)build/$(TEST_NAME)-$(ARCH).bin
SIM_ARGS := elf=$(TEST_SRCDIR)build/$(TEST_NAME)-$(ARCH).elf
SIM_DEPS := sim-am-build
include CXXFLAGS.mk

$(CXXFLAGS_STAMP): FORCE
	@mkdir -p $(OBJ_DIR)
	@echo "$(CXXFLAGS)" | cmp -s - $@ 2>/dev/null || echo "$(CXXFLAGS)" > $@

$(OBJ_DIR)/%.o: $(VERILATOR_DIR)/%.cpp $(CXXFLAGS_STAMP)
	@mkdir -p $(OBJ_DIR)
	@echo "CXX $<"
	@g++ $(CXXFLAGS) -c $< -o $@
$(OBJ_DIR)/%.o: $(VERILATOR_ROOT)/include/%.cpp $(CXXFLAGS_STAMP)
	@mkdir -p $(OBJ_DIR)
	@echo "CXX $<"
	@g++ $(CXXFLAGS) -c $< -o $@
$(OBJ_DIR)/%.o: src/cpp/%.cpp $(CXX_H_FILES) $(VERILOG_STAMP) $(CXXFLAGS_STAMP)
	@mkdir -p $(OBJ_DIR)
	@echo "CXX $<"
	@g++ $(CXXFLAGS) -c $< -o $@
test:
	mill -i test

FUCK_CI:
	@if [ ! -d dependencies/diplomacy/.git ]; then \
		rm -rf dependencies/diplomacy; \
		git clone --depth 1 https://github.com/chipsalliance/diplomacy.git dependencies/diplomacy; \
	fi
	@if [ ! -d dependencies/cde/.git ]; then \
		rm -rf dependencies/cde; \
		git clone --depth 1 https://github.com/chipsalliance/cde.git dependencies/cde; \
	fi
	@mkdir -p ~/.local/bin ~/.local/lib ~/.local/jdk17 ~/.local/oss-cad-suite
	@if [ ! -f ~/.local/jdk17/bin/java ]; then \
		curl -L "https://github.com/adoptium/temurin17-binaries/releases/download/jdk-17.0.9%2B9/OpenJDK17U-jdk_x64_linux_hotspot_17.0.9_9.tar.gz" -o ~/.local/jdk17.tar.gz && \
		tar xzf ~/.local/jdk17.tar.gz -C ~/.local/jdk17 --strip-components=1 && \
		rm -f ~/.local/jdk17.tar.gz; \
	fi
	@if [ ! -f ~/.local/oss-cad-suite/environment ]; then \
		curl -L "https://github.com/YosysHQ/oss-cad-suite-build/releases/download/2026-08-03/oss-cad-suite-linux-x64-20260803.tgz" -o ~/.local/oss-cad-suite.tgz && \
		rm -rf ~/.local/oss-cad-suite/*; \
		tar xzf ~/.local/oss-cad-suite.tgz -C ~/.local/oss-cad-suite --strip-components=1 && \
		rm -f ~/.local/oss-cad-suite.tgz; \
	fi
	@echo '#!/bin/bash' > ~/.local/bin/mill
	@echo 'export JAVA_HOME=$$HOME/.local/jdk17' >> ~/.local/bin/mill
	@echo 'source $$HOME/.local/oss-cad-suite/environment 2>/dev/null || true' >> ~/.local/bin/mill
	@echo 'export PATH=$$JAVA_HOME/bin:$$PATH' >> ~/.local/bin/mill
	@echo 'exec $$HOME/.local/lib/mill.sh "$$@"' >> ~/.local/bin/mill
	@chmod +x ~/.local/bin/mill
	@if [ ! -f ~/.local/lib/mill.sh ]; then \
		curl -L https://repo1.maven.org/maven2/com/lihaoyi/mill-dist/1.1.7/mill-dist-1.1.7-mill.sh -o ~/.local/lib/mill.sh && \
		chmod +x ~/.local/lib/mill.sh; \
	fi

$(MILL_ARGS_STAMP): FORCE
	@mkdir -p $(BUILD_DIR)
	@echo "$(NPC_CONFIG_VALS)" | cmp -s - $@ 2>/dev/null || echo "$(NPC_CONFIG_VALS)" > $@

$(MILL_STAMP): $(SCALA_FILES) build.mill $(MILL_ARGS_STAMP) | FUCK_CI
	$(call git_commit, "generate verilog")
	@$(NPC_CONFIG_ENV) mill -i runMain Elaborate --target-dir $(RTL_DIR) --throw-on-first-error
# 	@cp src/scala/dpic/dpi_pkg.sv $(RTL_DIR)/dpi_pkg.sv
	@cd $(RTL_DIR) && cat $$(grep -v '^$$' filelist.f | grep -v '^$(STUID)\.sv$$') $(STUID).sv > ../$(STUID).v
	@touch $@

lint: $(VERILOG_STAMP)
	@verilator --lint-only $(SV_FILES) --top $(TOP) \
		-Wall -Wno-DECLFILENAME \
		$(addprefix -I, $(SV_INCLUDE))

IVERILOG_FILES := src/sv/Top.sv src/sv/AXIMemory.sv
IVERILOG_FLAGS := -g2012

MAINARGS_MAX_LEN = 64
MAINARGS_PLACEHOLDER = the_insert-arg_rule_in_Makefile_will_insert_mainargs_here
# NETLIST ?= ../yosys-sta/result/ysyx_25060161-500MHz/ysyx_25060161.netlist.v.sim
NETLIST ?= ../yosys-sta/result/ysyx_25060161-500MHz/ysyx_25060161.netlist.fixed.v
CELLS ?= ../yosys-sta/pdk/nangate45/sim/cells.v

ifeq ($(filter sim-iverilog-netlist,$(MAKECMDGOALS)),sim-iverilog-netlist)
IVERILOG_BUILD_DIR := $(BUILD_DIR)/netlist
IVERILOG_FILES += $(NETLIST) $(CELLS)
IVERILOG_FLAGS += -DNETLIST
else
IVERILOG_BUILD_DIR := $(BUILD_DIR)/iverilog
IVERILOG_FILES += $(SV_FILES)
IVERILOG_FLAGS += 
endif

IVERILOG_VVP := $(IVERILOG_BUILD_DIR)/a.out
IVERILOG_MEM_HEX := $(IVERILOG_BUILD_DIR)/mem.hex

$(IVERILOG_MEM_HEX): FORCE
	@mkdir -p $(IVERILOG_BUILD_DIR)
	@test -n "$(IMG)" || (echo "ERROR: IMG is required, e.g. IMG=char-test.bin" && false)
	@cp $(IMG) $(IVERILOG_BUILD_DIR)/tmp.bin
	@-python $(AM_HOME)/tools/insert-arg.py $(IVERILOG_BUILD_DIR)/tmp.bin $(MAINARGS_MAX_LEN) $(MAINARGS_PLACEHOLDER) "$(mainargs)" 2>/dev/null
	@od --endian=little -An -tx4 -w4 -v $(IVERILOG_BUILD_DIR)/tmp.bin | awk '{print $$1}' > $@
	@rm -f $(IVERILOG_BUILD_DIR)/tmp.bin

$(IVERILOG_VVP): $(IVERILOG_FILES) $(IVERILOG_MEM_HEX)
	@mkdir -p $(IVERILOG_BUILD_DIR)
	@iverilog $(IVERILOG_FLAGS) -o $@ $(IVERILOG_FILES)

sim-iverilog sim-iverilog-netlist: $(IVERILOG_VVP)
	@cd $(IVERILOG_BUILD_DIR) && vvp a.out

verilog: $(VERILOG_STAMP)
$(VERILOG_STAMP): $(MILL_STAMP) $(YSYXSOC_SV_FILES) Makefile
	@rm -rf $(VERILATOR_DIR) $(OBJ_DIR)
	@verilator --cc $(SV_FILES) --Mdir $(VERILATOR_DIR) \
				--top $(TOP) --trace \
				--public \
				--timescale "1ns/1ns" --no-timing \
				$(addprefix -I, $(SV_INCLUDE)) --autoflush
	@echo "VERILATOR_CPP := \$$(wildcard $(VERILATOR_DIR)/*.cpp)" > $@
	@echo "VERILATOR_OBJ := \$$(patsubst $(VERILATOR_DIR)/%.cpp, $(OBJ_DIR)/%.o, \$$(VERILATOR_CPP))" >> $@

$(EXE): $(VERILATOR_OBJ) $(CXX_OBJ) $(NVBOARD_ARCHIVE)
	@echo LINK $@
	@$(CXX) $^ $(LDFLAGS) -o $@
ysyxsoc-run: $(EXE)
	$(EXE) bin=$(IMG) $(ARGS)
ysyxsoc-gdb: $(EXE)
	gdb --args $(EXE) $(IMG) $(ARGS)
ysyxsoc: $(EXE)
npc-run: $(EXE)
	$(EXE) bin=$(IMG) $(ARGS)
npc-gdb: $(EXE)
	gdb --args $(EXE) $(IMG) $(ARGS)
npc: $(EXE)
bear: bear-ysyxsoc
bear-ysyxsoc:
	$(MAKE) clean
	$(MAKE) verilog
	bear -- $(MAKE) ysyxsoc
bear-npc:
	$(MAKE) clean
	$(MAKE) verilog
	bear -- $(MAKE) npc
help:
	mill -i runMain Elaborate --help

reformat:
	mill -i __.reformat

checkformat:
	mill -i __.checkFormat

bsp:
	mill -i mill.bsp.BSP/install

idea:
	mill -i mill.idea.GenIdea/idea

clean:
	-rm -rf $(BUILD_DIR)

.PHONY: test help reformat checkformat clean verilog lint sim-iverilog sim-iverilog-netlist npc-run npc-gdb ysyxsoc-run ysyxsoc-gdb ysyxsoc npc bear bear-ysyxsoc bear-npc itrace btrace FUCK_CI FORCE

sim: $(SIM_DEPS) $(EXE)
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	$(EXE) bin=$(SIM_IMG) $(SIM_ARGS)

itrace: $(SIM_DEPS) $(EXE)
	$(call git_commit, "itrace RTL")
	$(EXE) bin=$(SIM_IMG) $(SIM_ARGS)

btrace: $(SIM_DEPS) $(EXE)
	$(call git_commit, "btrace RTL")
	$(EXE) bin=$(SIM_IMG) $(SIM_ARGS)

sim-am-build:
	@mkdir -p $(BUILD_DIR)
	@echo "NAME = $(TEST_NAME)"            >  $(BUILD_DIR)/Makefile.am
	@echo "SRCS = $(notdir $(TEST_PATH))"  >> $(BUILD_DIR)/Makefile.am
	@echo "include $(AM_HOME)/Makefile"    >> $(BUILD_DIR)/Makefile.am
	@$(MAKE) -s -C $(TEST_SRCDIR) -f $(abspath $(BUILD_DIR)/Makefile.am) ARCH=$(ARCH) image

