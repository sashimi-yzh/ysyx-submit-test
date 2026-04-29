YOSYS_STA_PATH ?= /home/wuser/gitclones/yosys-sta

$(shell mkdir -p $(STA_OUT_DIR))

STA_VSRCS = $(abspath $(SYNTH_VSRCS))

STA_FREQ_MHZ ?= 500

STA_DEST ?= 
ifeq ($(STA_DEST),)
STA_DEST_FULL_NAME = $(CPU_DESIGN_NAME)
else
STA_DEST_FULL_NAME = $(STA_DEST)
endif

sta: verilog $(STA_VSRCS)
	# @echo "Removing DPI-C void functions from verilog sources..."
	# ./scripts/remove_dpi.sh $(CHISEL2V_EMIT_DIR) $(STA_NODPI_PATH)
	$(MAKE) -C $(YOSYS_STA_PATH) sta \
		DESIGN=$(STA_DEST_FULL_NAME) \
		CLK_FREQ_MHZ=$(STA_FREQ_MHZ) \
		CLK_PORT_NAME=clock \
		O=$(STA_OUT_DIR) \
		RTL_FILES="$(STA_VSRCS)" 

sta-area: verilog $(STA_VSRCS)
	# @echo "Removing DPI-C void functions from verilog sources..."
	# ./scripts/remove_dpi.sh $(CHISEL2V_EMIT_DIR) $(STA_NODPI_PATH)
	$(MAKE) -C $(YOSYS_STA_PATH) stat_only \
		DESIGN=$(STA_DEST_FULL_NAME) \
		CLK_FREQ_MHZ=$(STA_FREQ_MHZ) \
		CLK_PORT_NAME=clock \
		O=$(STA_OUT_DIR) \
		RTL_FILES="$(STA_VSRCS)" \

sta-all-area: verilog
	+./scripts/sta_all.sh $(CHISEL2V_EMIT_ROOT)/riscv32e/filelist.f $(STA_OUT_DIR)
