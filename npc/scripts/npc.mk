#=======================================================================================
# NPC & Iverilog 配置模块 (npc.mk)
#=======================================================================================

#--- 工具 ---
IVERILOG 	 := iverilog
VVP_BIN      := vvp

#--- 源文件与参数 ---
IMG      ?= $(NPC_HOME)/sim/iverilog/yield.bin
IMG_HEX  := $(IVER_DIR)/$(shell basename $(IMG) .bin).hex
IVER_TOP := tb_fullsoc
IVER_VSRC := vsrc/idle/fullsoc.v vsrc/idle/sram.v vsrc/idle/tb_fullsoc.v vsrc/idle/uart.v vsrc/idle/xbar.v
IVER_OUT  := $(IVER_DIR)/iverilog_sim.out

IVERFLAGS = -o $(IVER_OUT) -g2012 -s $(IVER_TOP) -P$(IVER_TOP).PROG_FILE='"$(IMG_HEX)"'
VVPFLAGS  = -n $(IVER_OUT)

#--- 规则 ---
$(IMG_HEX): $(IMG)
	@xxd -c 1 -p $^ > $@

sim-iverilog: verilog $(IMG_HEX)
	@echo "[IVERILOG] Starting behavior simulation with $(IMG)"
	@$(IVERILOG) $(IVERFLAGS) $(NPC_VSRC) $(IVER_VSRC)
	@$(VVP_BIN) $(VVPFLAGS)

# 网表仿真相关
NETLIST := $(NPC_HOME)/../yosys-sta/result/ysyx_25050136-1500MHz/ysyx_25050136.v
CELLS   := $(NPC_HOME)/../yosys-sta/pdk/nangate45/sim/cells.v

sim-iverilog-netlist: $(IMG_HEX)
	@echo "[IVERILOG] Starting Netlist simulation"
	@$(IVERILOG) $(IVERFLAGS) $(IVER_VSRC) $(NETLIST) $(CELLS)
	@$(VVP_BIN) $(VVPFLAGS)

#--- 逻辑综合工具入口 (Fuck Targets) ---
fuck: $(SOC_DEPEMD)
	@python3 scripts/synthesis.py

synth-single: $(SOC_DEPEMD)
	@python3 scripts/synthesis.py add 2000 clk "$(NPC_VSRC)"

.PHONY: sim-iverilog sim-iverilog-netlist fuck synth-single