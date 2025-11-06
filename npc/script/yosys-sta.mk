# 进入ysyx-workbench/npc/script进行综合
# 进行综合的指令：make -f yosys-sta.mk sta

PROJ_PATH = $(CURDIR)/..

IEDA = $(PROJ_PATH)/yosys-sta/bin/iEDA
DESIGN ?= ysyx_24100006
# DEFINES ?= -DNPC
DEFINES ?= -D__ICARUS__

SDC_FILE ?= $(PROJ_PATH)/vsrc/cpu.sdc
# RTL_FILES ?= $(shell find $(PROJ_PATH)/vsrc -name "*.v")
RTL_FILES ?= $(shell find $(PROJ_PATH)/vsrc -name "*.v" \
				-not -path "$(PROJ_PATH)/vsrc/ysyx_24100006_mem.v"	\
				-not -path "$(PROJ_PATH)/vsrc/ysyx_24100006_i_testbench.v"	\
				-not -path "$(PROJ_PATH)/vsrc/ysyx_24100006_uart.v" \
				-not -path "$(PROJ_PATH)/vsrc/IF/ysyx_24100006_im.v" \
				-not -path "$(PROJ_PATH)/vsrc/cache/Icache_gpt.v" \
				-not -path "$(PROJ_PATH)/vsrc/axi/ysyx_24100006_axi_arbiter.v" \
				-not -path "$(PROJ_PATH)/vsrc/axi/ysyx_24100006_axi_xbar.v" )
# RTL_FILES ?= $(PROJ_PATH)/vsrc/EX/ysyx_24100006_alu.v $(PROJ_PATH)/vsrc/template/ysyx_24100006_MuxKey.v
export CLK_FREQ_MHZ ?= 430

RESULT_DIR = $(PROJ_PATH)/result/$(DESIGN)-$(CLK_FREQ_MHZ)MHz
SCRIPT_DIR = $(PROJ_PATH)/yosys-sta/scripts
NETLIST_SYN_V   = $(RESULT_DIR)/$(DESIGN).netlist.syn.v
NETLIST_FIXED_V = $(RESULT_DIR)/$(DESIGN).netlist.fixed.v
TIMING_RPT = $(RESULT_DIR)/$(DESIGN).rpt

init:
	bash -c "$$(wget -O - https://ysyx.oscc.cc/slides/resources/scripts/init-yosys-sta.sh)"

syn: $(NETLIST_SYN_V)
$(NETLIST_SYN_V): $(RTL_FILES) $(SCRIPT_DIR)/yosys.tcl
	mkdir -p $(@D)
	echo tcl $(SCRIPT_DIR)/yosys.tcl $(DESIGN) \"$(RTL_FILES)\" $@ $(DEFINES) | yosys -l $(@D)/yosys.log -s -

fix-fanout: $(NETLIST_FIXED_V)
$(NETLIST_FIXED_V): $(SCRIPT_DIR)/fix-fanout.tcl $(SDC_FILE) $(NETLIST_SYN_V)
	$(IEDA) -script $^ $(DESIGN) $@ 2>&1 | tee $(RESULT_DIR)/fix-fanout.log

sta: $(TIMING_RPT)
$(TIMING_RPT): $(SCRIPT_DIR)/sta.tcl $(SDC_FILE) $(NETLIST_FIXED_V)
	$(IEDA) -script $^ $(DESIGN) 2>&1 | tee $(RESULT_DIR)/sta.log

.PHONY: init syn fix-fanout sta