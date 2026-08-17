.DEFAULT_GOAL := sim


SOC_HOME := $(NPC_HOME)/../ysyxSoC
include $(NVBOARD_HOME)/scripts/nvboard.mk

NXDC = $(NPC_HOME)/npc_soc/nvboard/top.nxdc
NXDC_CPP_PATH = $(NPC_HOME)/npc_soc/nvboard/generated
NXDC_CPP = $(NPC_HOME)/npc_soc/nvboard/generated/auto_bind.cpp

CSRC = $(shell find csrc -name "*.cpp")
CSRC += $(NPC_HOME)/npc_old/tools/replxx/libreplxx.a $(NVBOARD_ARCHIVE)
CSRC += $(NXDC_CPP)

VSRC = $(wildcard vsrc/*.v)
VSRC += $(wildcard vsrc/*.sv)
VSRC += $(wildcard $(SOC_HOME)/build/*.v)
VSRC += $(shell find $(SOC_HOME)/perip -name *.v)
VSRC += $(shell find $(SOC_HOME)/perip -name *.sv)

CHISELSRC += $(wildcard src/main/scala/empty/*.scala)
TOPNAME = ysyxSoCFull
BIN = $(MDIR)/V$(TOPNAME)

SV_FILELIST = $(NPC_HOME)/generated_svsrc/filelist.f

SVSRC_FILES = $(shell cat $(SV_FILELIST))
SVSRC = $(patsubst %,$(NPC_HOME)/generated_svsrc/%,$(SVSRC_FILES))

VERILATOR = verilator
PYTHON = python

STA_DIR = $(NPC_HOME)/npc_soc/sta
SDC_FILE = $(STA_DIR)/npc.sdc
SCRIPT_FILE = $(STA_DIR)/sta.tcl

VERILATOR_CFLAGS = -Ofast -DFMT_HEADER_ONLY=1 -DSPDLOG_FMT_EXTERNAL=1  \
-march=native -mtune=native \
-funroll-loops -flto=auto -ffast-math -fno-math-errno -funsafe-math-optimizations 
VERILATOR_LDFLAGS = -flto=auto -fipa-pta 


V_CXXFLAGS += -CFLAGS "$(VERILATOR_CFLAGS) -std=c++20 -I$(NPC_HOME)/npc_soc/include -DFMT_HEADER_ONLY=1 -DSPDLOG_FMT_EXTERNAL=1 -I$(NVBOARD_HOME)/usr/include" \
-LDFLAGS "-lSDL2 -lSDL2_image -lSDL2_ttf" 
# VERILATORFLAGS += --noassert --trace --no-coverage --x-assign fast --x-initial fast -O3 --threads 1 --cc --exe --build -j 8 
VERILATORFLAGS += --autoflush -I$(SOC_HOME)/perip/uart16550/rtl -I$(SOC_HOME)/perip/spi/rtl --trace \
--timescale "1ns/1ns" --no-timing -O3 --threads 1 --cc --exe --build -j 8 \
'-Dlayer$$Verifying' '-Dlayer$$PerformanceCounterLayer' '-Dlayer$$AXIAssertLayer'
VERILATOR_DISABLE_WARNINGS += -Wno-UNUSEDSIGNAL -Wno-DECLFILENAME -Wno-SYNCASYNCNET -Wno-PINCONNECTEMPTY \
-Wno-ASSIGNDLY -Wno-DEFPARAM -Wno-UNUSEDPARAM -Wno-PROCASSINIT

FAST_FLAGS = -Ofast -march=native -mtune=native

-include scripts/*.mk

MDIR = $(NPC_HOME)/npc_soc/build/default/

npc: CXXFLAGS+=-fPIC
npc: $(SV_FILELIST) $(LIBCAPSTONE) $(NXDC_CPP) nvboard-archive
	make -C $(SOC_HOME) verilog
	mkdir -p $(MDIR) || true
	$(VERILATOR)  $(VERILATORFLAGS) \
	--top-module $(TOPNAME) --public-flat-rw  \
	-CFLAGS -DTOP_NAME="\"V$(TOPNAME)\"" \
	--MAKEFLAGS "-j12 OPT_FAST=\"$(FAST_FLAGS)\"" \
	$(V_CXXFLAGS) -Wall $(CSRC) $(SVSRC) $(VSRC) $(VERILATOR_DISABLE_WARNINGS) \
	--Mdir $(MDIR)

sbt: $(SV_FILELIST)

$(SV_FILELIST): $(CHISELSRC)
	sbt "run --init-pc 0x30000000 --to-soc" 
# 	bash -c "find generated_svsrc/ -name *.sv -exec sed -i 's+src/main/scala/empty/++g' {} \\;"



PROG ?= $(NPC_HOME)/../am-kernels/benchmarks/microbench/build/microbench-riscv32e-soc.bin
TIME_STAMP := $(shell date +"%Y_%m_%d_%H_%M_%S")
LOG_FILE ?= "log/$(TIME_STAMP).log"

$(NXDC_CPP): $(NXDC)
	mkdir -p $(NXDC_CPP_PATH) || true
	$(PYTHON) $(NVBOARD_HOME)/scripts/auto_pin_bind.py $(NXDC) $(NXDC_CPP)

sim: npc
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	$(BIN) --image $(PROG) --log $(LOG_FILE) --difftest

nvboard: CXXFLAGS+=-fPIC
nvboard: $(NXDC_CPP) nvboard-archive npc
	$(call git_commit, "sim RTL with nvboard")
	$(BIN) --image $(PROG) --log $(LOG_FILE) --difftest --nvboard

CLK_FREQ_MHZ = 1000
sta: sbt
	mkdir -p $(STA_DIR)/result || true
	make -C $(STA_HOME) sta \
	DESIGN=ysyx_25080216 SDC_FILE=$(SDC_FILE) PDK=nangate45 \
	CLK_FREQ_MHZ=$(CLK_FREQ_MHZ) CLK_PORT_NAME=clock O=$(STA_DIR)/result \
	RTL_FILES="$(SVSRC)"


perf: LOG_FILE = /tmp/perf.log
perf: npc
	make -C $(AM_HOME)/../am-kernels/benchmarks/microbench ARCH=riscv32e-soc run mainargs=test LOG_FILE=$(LOG_FILE)
	rm -rf $(STA_DIR)/result
	make sta
	@echo Extracting Statistics
	sleep 3
	clear
	@cat /tmp/perf.log | grep -oP "Total simulated clock periods : \d+"
	@cat /tmp/perf.log | grep -oP "Total simulated instructions : \d+"
	@cat /tmp/perf.log | grep -oP "Clocks per instruction : \d+(\.\d+)?"
	@echo -n "Max Freq(MHz) : "
	@cat $(shell find $(STA_DIR)/result -name "ysyx_25080216.rpt") | grep "Freq" -A 2 | grep -oP "\|\s*\d+(\.\d+)\s*\|\s*$$" | grep -oP "\d+(\.\d+)?"
	@echo -n "Area : "
	@cat $(shell find $(STA_DIR)/result -name "synth_stat.txt") | grep "Chip area" | grep -oP "\d+(\.\d+)?\s*$$"
	@cat /tmp/perf.log | grep -oP "Total/Average/Min/Max.*$$"
	@echo "------------Instruction Type Statistics------------"
	@cat /tmp/perf.log | grep "Instruction Type Statistics" -A 14 | grep -oP "[a-zA-Z ]*\|\s*\d+\s*$$"
	@cat /tmp/perf.log | grep -oP "Total ifu events : \d+"
	@cat /tmp/perf.log | grep -oP "Total lsu read events : \d+"
	@cat /tmp/perf.log | grep -oP "Total icache hit events : \d+"


valgrind: FAST_FLAGS = -O0 -g
valgrind: VERILATOR_CFLAGS = -DSPDLOG_USE_STD_FORMAT -O0 -g
valgrind: MDIR = ./build/valgrind/
valgrind: npc
	valgrind --leak-check=full --show-leak-kinds=all \
	 $(BIN) --image $(PROG) --log $(LOG_FILE) --difftest --batch 



gdb: FAST_FLAGS = -O0 -g
gdb: VERILATOR_CFLAGS = -DSPDLOG_USE_STD_FORMAT -O0 -g
gdb: MDIR = ./build/gdb/
gdb: npc
	gdb --args $(BIN) --image $(PROG) --log $(LOG_FILE) --difftest



clean:
	rm -rf build
	rm -rf ../build
	sbt clean
	rm -rf ../generated_svsrc/*

clean_log:
	rm -rf $(NPC_HOME)/npc_soc/log/*

clean_sta:
	rm -rf $(STA_DIR)/result/*



.PHONY: npc sim nvboard sta clean clean_log clean_sta sbt gdb valgrind perf

include ../../Makefile
