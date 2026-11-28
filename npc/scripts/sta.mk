# 面积与时序：直接调用 CI 用的那套 yosys-sta（ci 分支的顶层 Makefile）
#
#   make -C npc sta                      默认 500MHz / clock 端口 / nangate45
#   make -C npc sta CLK_FREQ_MHZ=800     换约束
#
# CI 侧等价的命令是：
#   make -C <yosys-sta ci 分支> sta DESIGN=ysyx_26030092 CLK_FREQ_MHZ=500 \
#        CLK_PORT_NAME=clock RTL_FILES=<npc>/build/ysyx_26030092.sv
# 所以这里跑出来的面积/时序和 CI 的报告可以直接对。

YOSYS_STA_HOME ?= /home/wjm/temp/sta-ci

DESIGN = ysyx_26030092
STA_RTL = $(abspath $(CORE))
CLK_FREQ_MHZ ?= 500
CLK_PORT_NAME ?= clock
STA_OUT ?= $(abspath $(BUILD_DIR)/sta)

sta: $(CORE)
	$(MAKE) -C $(YOSYS_STA_HOME) sta \
	  DESIGN=$(DESIGN) CLK_FREQ_MHZ=$(CLK_FREQ_MHZ) \
	  CLK_PORT_NAME=$(CLK_PORT_NAME) RTL_FILES=$(STA_RTL) O=$(STA_OUT)

PDK_NAME = nangate45
