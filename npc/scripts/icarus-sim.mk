# Make-facing entry points for the Icarus smoke driver.

IV_CC ?= iverilog
IV_VM ?= vvp
IV_OPTIONS ?=
GATE_OPTIONS ?= -Dfunctional -DNPC_NETLIST_SIM

IV_DRIVER := $(NPC_DIR)/scripts/iv-smoke.sh
SMOKE_ROOT := $(ARTIFACT_ROOT)/iverilog
GATE_ROOT := $(ARTIFACT_ROOT)/iverilog-netlist
SMOKE_TB := $(abspath $(NPC_DIR)/vsrc/testbench/tb_iverilog.v)
GATE_TB := $(abspath $(NPC_DIR)/vsrc/testbench/tb_iverilog_netlist.v)
SMOKE_INPUTS := $(RTL_CORE) $(RTL_TOP_FILE) $(SMOKE_TB)
GATE_INPUTS := $(RTL_TOP_FILE) $(GATE_TB)
WAVE_SWITCH := $(if $(CONFIG_WAVE),+WAVE=1,)

sim-iverilog: $(SMOKE_INPUTS)
	@IV_MODE=rtl IV_WORK="$(SMOKE_ROOT)" IV_IMAGE="$(abspath $(IMG))" \
		IV_CC="$(IV_CC)" IV_VM="$(IV_VM)" IV_OPTIONS="$(IV_OPTIONS)" \
		IV_TOP=tb_iverilog IV_INCLUDE="$(NPC_DIR)/vsrc/testbench" \
		IV_SOURCES="$(SMOKE_INPUTS)" IV_WAVE="$(WAVE_SWITCH)" \
		IV_VVP_ARGS="$(VVP_ARGS)" bash "$(IV_DRIVER)"

sim-iverilog-netlist: $(GATE_INPUTS)
	@IV_MODE=netlist IV_WORK="$(GATE_ROOT)" IV_IMAGE="$(abspath $(IMG))" \
		IV_CC="$(IV_CC)" IV_VM="$(IV_VM)" IV_OPTIONS="$(GATE_OPTIONS)" \
		IV_TOP=tb_iverilog_netlist IV_INCLUDE="$(NPC_DIR)/vsrc/testbench" \
		IV_SOURCES="$(GATE_INPUTS)" IV_NETLIST="$(NETLIST)" IV_CELLS="$(CELLS)" \
		IV_WAVE="$(WAVE_SWITCH)" IV_VVP_ARGS="$(VVP_ARGS)" bash "$(IV_DRIVER)"

.PHONY: sim-iverilog sim-iverilog-netlist
