.DEFAULT_GOAL := sim


verilog:
	make -C ./npc_soc sbt
	mkdir -p build || true
	iverilog -E -o ./build/__ysyx_25080216__temp__.sv -s ysyx_25080216 ./generated_svsrc/*.sv
	sed -i 's+//.*$$++g' ./build/__ysyx_25080216__temp__.sv
	awk 'NF{print;blank=0}!NF{if(!blank)print;blank=1}' ./build/__ysyx_25080216__temp__.sv > ./build/ysyx_25080216.sv
	rm ./build/__ysyx_25080216__temp__.sv

IMG ?= ./test_progs/microbench.bin


STA_DIR = $(NPC_HOME)/sta
SDC_FILE = $(STA_DIR)/npc.sdc
SCRIPT_FILE = $(STA_DIR)/sta.tcl
FORMAL_SCRIPT_FILE = $(STA_DIR)/equiv_check.tcl

sim-iverilog: verilog
	mkdir -p ./iv_temp/ || true
	objcopy -I binary -O verilog --verilog-data-width=4 $(IMG) ./iv_temp/temp.hex
	iverilog -o ./iv_temp/tb.vvp -s tb_npc ./build/ysyx_25080216.sv iverilog_tb/*.sv -g2012
	vvp -n ./iv_temp/tb.vvp

CLK_FREQ_MHZ = 1000
sta: verilog
	rm -rf $(STA_DIR)/result
	mkdir -p $(STA_DIR)
	make -C $(STA_HOME) sta \
	DESIGN=ysyx_25080216 SDC_FILE=$(SDC_FILE) PDK=nangate45 \
	CLK_FREQ_MHZ=$(CLK_FREQ_MHZ) CLK_PORT_NAME=clock O=$(STA_DIR)/result \
	RTL_FILES="$(NPC_HOME)/build/ysyx_25080216.sv"

CELLS ?= $(STA_HOME)/pdk/nangate45/sim/cells.v
NETLIST ?= $(shell find $(STA_DIR)/result -name "ysyx_25080216.netlist.v.sim")

formal: sta
	yosys -c $(FORMAL_SCRIPT_FILE) -- \
	-top ysyx_25080216 \
	-rtl $(NPC_HOME)/build/ysyx_25080216.sv \
	-netlist $(NETLIST_PATH) \
	-stdcell $(PDK_CELLS) \
	-reset reset \
	-reset-active 1 \
	-reset-cycles 2 \
	-warmup 1 \
	-cycles 12 \
	-outdir reports/io_equiv \
	-dump



sim-iverilog-netlist:
	mkdir -p ./iv_temp/ || true
	cp $(NETLIST) ./iv_temp/netlist.v
	objcopy -I binary -O verilog --verilog-data-width=4 $(IMG) ./iv_temp/temp.hex
	iverilog -o ./iv_temp/tb.vvp -s tb_npc ./iv_temp/netlist.v $(CELLS) iverilog_tb/*.sv -g2012 -DSOC=1
	vvp -n ./iv_temp/tb.vvp

clean:
	rm -rf sta/result/*
	rm -rf build/*.sv generated_svsrc/*.* iv_temp/*


.PHONY: clean verilog iverilog sta
