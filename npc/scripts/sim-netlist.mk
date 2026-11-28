# 门级网表仿真（iverilog + nangate45 标准单元）
#
#   make sim-iverilog-netlist IMG=xxx.bin NETLIST=<netlist.v> CELLS=<cells.v>
#
# NETLIST 为空时，先用 yosys + $(SCRIPT_DIR)/yosys.tcl 把 CORE 综合成本地网表；
# 传入 NETLIST（比如 yosys-sta 的 netlist.fixed.v）时直接用它。
# testbench 由 scripts/gen_netlist_tb.py 根据网表的端口自动生成。

YOSYS_STA_HOME ?= /home/wjm/temp/sta-ci
CELLS ?= $(YOSYS_STA_HOME)/pdk/nangate45/sim/cells.v

NET_TB = $(SIM_DIR)/tb_netlist.v
NETLIST_SIM_DIR = $(SIM_DIR)/netlist
NETLIST_SIM_V = $(NETLIST_SIM_DIR)/ysyx_26030092.netlist.v
NET_CORE = $(SIM_DIR)/ysyx_26030092_netlist_sim.sv

ifeq ($(NETLIST),)
NETLIST_USE = $(NETLIST_SIM_V)
else
NETLIST_USE = $(abspath $(NETLIST))
endif

$(NET_CORE): $(CORE)
	@mkdir -p $(SIM_DIR)
	{ echo '`define NETLIST_SIM'; cat $<; } > $@

$(NETLIST_SIM_V): $(NET_CORE)
	@mkdir -p $(NETLIST_SIM_DIR)
	echo tcl $(SCRIPT_DIR)/yosys.tcl $(DESIGN) $(PDK_NAME) \"$(NET_CORE)\" $@ | \
	  yosys -g -l $(NETLIST_SIM_DIR)/yosys.log -s -

$(NET_TB): $(NETLIST_USE) scripts/gen_netlist_tb.py
	@mkdir -p $(SIM_DIR)
	python3 scripts/gen_netlist_tb.py $(NETLIST_USE) $(NET_TB)

$(SIM_DIR)/tb_net.vvp: $(NETLIST_USE) $(CELLS) sim/axi_mem.v $(NET_TB)
	@mkdir -p $(SIM_DIR)
	$(IVERILOG) $(IVERILOG_FLAGS) -DNETLIST_SIM -s tb_netlist -o $@ $(NETLIST_USE) $(CELLS) sim/axi_mem.v $(NET_TB)

sim-iverilog-netlist: $(SIM_HEX) $(SIM_DIR)/tb_net.vvp
	$(VVP) $(SIM_DIR)/tb_net.vvp +HEX=$(CURDIR)/$(SIM_HEX) +CYCLES=$(SIM_CYCLES)
