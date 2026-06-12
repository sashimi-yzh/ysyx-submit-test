MILL = $(NPC_HOME)/mill
RSYNC = rsync
PRJ = playground

RELEASE_FILE = $(NPC_HOME)/build/ysyx_26010008.sv

VSRC_TMP_DIR = $(BUILD_DIR)/$(ARCH)-vsrc_tmp
VSRC_DIR = $(BUILD_DIR)/$(ARCH)-vsrc

RSYNC_CMD = $(RSYNC) -rlpgoD --checksum --delete --itemize-changes \
						--omit-dir-times $(VSRC_TMP_DIR:/=)/ $(VSRC_DIR)

SRC_DIRS = common playground generator
SEARCH_DIRS = $(addprefix $(NPC_HOME)/,$(SRC_DIRS))
FIND_FILTER = -type f -name '*.scala'
MILL_SRCS = $(shell find $(SEARCH_DIRS) $(FIND_FILTER))
VSRC_TIMESTAMP = $(BUILD_DIR)/.$(ARCH)-vsrc_timestamp

test:
	$(MILL) $(PRJ).test.testOnly $(PACKAGE_NAME).* $(if $(ALL),-- -z $(ALL),)

$(VSRC_TIMESTAMP): $(MILL_SRCS) $(SEARCH_DIRS)
	# Generate verilogs
	$(call git_commit, "generate verilog")
	-rm -rf $(VSRC_TMP_DIR)
	-mkdir -p $(VSRC_TMP_DIR)
	-mkdir -p $(VSRC_DIR)
	$(MILL) -i $(PRJ).runMain $(PACKAGE_NAME).Elaborate \
		--target-dir $(VSRC_TMP_DIR) $(SCALA_FLAGS)
	$(RSYNC_CMD)
	-$(MAKE) lint
	touch $@

verilog: $(VSRC_TIMESTAMP)
	-cat $(VSRC_DIR)/*.sv > $(RELEASE_FILE)
	-sed -i '1i\/\/ BUILD MODE: $(ARCH)\n' $(RELEASE_FILE)
	-sed -i 's/^module .*/\n&/' $(RELEASE_FILE)
	-sed -i 's/\"THIS_IS_THE_IVERILOG_HEX_PATH_PLACEHOLDER\"/\`IVERILOG_HEX_PATH/' \
		$(BUILD_DIR)/iverilog/*.sv

chisel_help:
	$(MILL) -i $(PRJ).runMain $(PACKAGE_NAME).Elaborate --help

reformat:
	$(MILL) -i __.reformat

checkformat:
	$(MILL) -i __.checkFormat

bsp:
	$(MILL) -i mill.bsp.BSP/install

idea:
	$(MILL) -i mill.idea.GenIdea/idea



.PHONY: test verilog help reformat checkformat bsp idea
