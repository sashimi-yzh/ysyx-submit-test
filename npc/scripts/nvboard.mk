NXDC_FILES = $(NPC_HOME)/constr/$(TOPNAME).nxdc
# constraint file
SRC_AUTO_BIND = $(abspath $(BUILD_DIR)/auto_bind.cpp)
$(SRC_AUTO_BIND): $(NXDC_FILES)
	python3 $(NVBOARD_HOME)/scripts/auto_pin_bind.py $^ $@

nvboard_test_path:
	@echo "[$(NXDC_FILES)]"
	@echo "[$(TOPNAME)]"

# project source
CSRCS += $(SRC_AUTO_BIND)

# rules for NVBoard
include $(NVBOARD_HOME)/scripts/nvboard.mk
