# 四值仿真（iverilog + vvp）
#
#   make sim-iverilog IMG=xxx.bin        # 用 CORE（Verilator 生成的 RTL）跑 tb_npc
#
# 镜像先由 scripts/bin2hex.py 转成 $readmemh 用的 hex，
# 周期上限通过 SIM_CYCLES 传给 tb_npc.v 的 +CYCLES。

IVERILOG ?= iverilog
VVP ?= vvp

SIM_DIR = $(BUILD_DIR)/sim
SIM_HEX = $(SIM_DIR)/img.hex
SIM_CYCLES ?= 8000000
IVERILOG_FLAGS = -g2012 -DSYNTHESIS -DNPC

$(SIM_HEX): FORCE
	@test -n "$(IMG)" || (echo "用法: make sim-iverilog IMG=xxx.bin" && exit 1)
	@mkdir -p $(SIM_DIR)
	python3 scripts/bin2hex.py $(IMG) $@
FORCE:

$(SIM_DIR)/tb.vvp: $(CORE) sim/tb_npc.v sim/axi_mem.v
	@mkdir -p $(SIM_DIR)
	$(IVERILOG) $(IVERILOG_FLAGS) -s tb_npc -o $@ $(CORE) sim/axi_mem.v sim/tb_npc.v

sim-iverilog: $(SIM_HEX) $(SIM_DIR)/tb.vvp
	$(VVP) $(SIM_DIR)/tb.vvp +HEX=$(CURDIR)/$(SIM_HEX) +CYCLES=$(SIM_CYCLES)

$(SIM_DIR)/tb_strict.vvp: $(CORE) sim/tb_strict.v sim/axi_strict.v
	@mkdir -p $(SIM_DIR)
	$(IVERILOG) $(IVERILOG_FLAGS) -s tb_strict -o $@ $(CORE) sim/axi_strict.v sim/tb_strict.v

sim-iverilog-strict: $(SIM_HEX) $(SIM_DIR)/tb_strict.vvp
	$(VVP) $(SIM_DIR)/tb_strict.vvp +HEX=$(CURDIR)/$(SIM_HEX) +CYCLES=$(SIM_CYCLES)
