include $(NPC_HOME)/scripts/init.mk

CONFIG_NPC_PACKAGE_NAME ?= sirius
CONFIG_NPC_TOP_NAME ?= Top
CFG_DIR ?= $(NPC_HOME)/config/npc
ARCH ?= iverilog

remove_quote = $(patsubst "%",%,$(1))

# ifneq ($(filter $(MAKECMDGOALS),verilog run gdb runbatch menuconfig savedefconfig),)
ifneq ($(findstring ysyxsoc,$(ARCH)),) # ysyxsoc
CFG_DIR = $(NPC_HOME)/config/ysyxsoc
SCALA_FLAGS = --ysyxsoc true --pc-init 0x30000000 --debug true --perf true
VSRCS += $(shell find $(abspath $(YSYXSOC_DIR)/perip) -name "*.v")
VSRCS += $(YSYXSOC_DIR)/build/ysyxSoCFull.v
VERILATOR_FLAGS += $(addprefix -y , $(YSYXSOC_LIBDIR))
VERILATOR_FLAGS += --timescale "1ns/1ns" --no-timing

else ifneq ($(findstring syn,$(ARCH)),) # syn
SCALA_FLAGS = --ysyxsoc true --pc-init 0x30000000 --debug false --perf false

else ifneq ($(findstring npc,$(ARCH)),) # normal npc
CFG_DIR = $(NPC_HOME)/config/npc
SCALA_FLAGS = --ysyxsoc false --pc-init 0x80000000 --debug true --perf false

else ifneq ($(findstring iverilog,$(ARCH)),) # iverilog
SCALA_FLAGS = --ysyxsoc true --pc-init 0x30000000 \
	--debug false --perf false --iverilog true --prefix ysyx_26010008 \
	--iverilog-dir $(BUILD_DIR)/iverilog

else ifneq ($(findstring release,$(ARCH)),) # release
SCALA_FLAGS = --ysyxsoc true --pc-init 0x30000000 \
	--debug false --perf false --prefix ysyx_26010008

else
$(error Unknown ARCH)
endif


BUILD_DIR ?= $(NPC_HOME)/build
$(info NPC BUILD_DIR $(BUILD_DIR))
$(shell mkdir -p $(BUILD_DIR))

VSRC_TIMESTAMP = $(BUILD_DIR)/.vsrc_timestamp

all: build_ar
	$(MAKE) -C $(NEMU_HOME) $(NEMU_MAKE_FLAGS)

# Menuconfig
-include $(CFG_DIR)/include/config/auto.conf
-include $(CFG_DIR)/include/config/auto.conf.cmd

ifeq ($(CONFIG_NPC_PACKAGE_NAME),)
$(error PACKAGE_NAME cannot be empty)
else
PACKAGE_NAME = $(call remove_quote,$(CONFIG_NPC_PACKAGE_NAME))
$(info PACKAGE_NAME is $(PACKAGE_NAME))
ELABORATE_SCALA = ./playground/src/$(PACKAGE_NAME)/Elaborate.scala
TOPNAME = $(call remove_quote,$(CONFIG_NPC_TOP_NAME))
ifeq ($(TOPNAME),)
$(error TOPNAME cannot be empty)
else
$(info TOPNAME is $(TOPNAME))
endif # TOPNAME
endif # PACKAGE_NAME

# Verilator
include $(NPC_HOME)/scripts/verilator.mk

# Chisel
include $(NPC_HOME)/scripts/chisel.mk

# iverilog
include $(NPC_HOME)/scripts/iverilog.mk

# Util
include $(NPC_HOME)/../Makefile

run: all
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	$(MAKE) -C $(NEMU_HOME) run $(NEMU_MAKE_FLAGS)

gdb: all
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	$(MAKE) -C $(NEMU_HOME) gdb $(NEMU_MAKE_FLAGS)

runbatch: all
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	$(MAKE) -C $(NEMU_HOME) run $(NEMU_MAKE_FLAGS)

clean:
	-rm -rf $(BUILD_DIR)

MENUCONFIG_CMD = $(MAKE) -C $(CFG_DIR) -f $(NEMU_HOME)/scripts/config.mk

menuconfig:
	$(MENUCONFIG_CMD) $@

DEFCONFIG = $(CFG_DIR)/configs/_defconfig

savedefconfig:
	$(MENUCONFIG_CMD) $@
	mv $(CFG_DIR)/configs/defconfig $(DEFCONFIG)

MK_INCLUDE = $(CFG_DIR)/include/config/auto.conf $(CFG_DIR)/include/config/auto.conf.cmd

$(MK_INCLUDE):
	$(MENUCONFIG_CMD) $(notdir $(DEFCONFIG))

.PHONY: force all run gdb runbatch clean menuconfig savedefconfig load-defconfig
