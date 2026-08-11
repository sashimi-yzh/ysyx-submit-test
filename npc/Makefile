# NPC build entry point.  The top-level file only selects a build mode; the
# implementation details live in scripts/ and the source manifest.

NPC_HOME ?= $(abspath $(dir $(lastword $(MAKEFILE_LIST))))
NPC_DIR := $(abspath $(NPC_HOME))
ROOT_NEMU ?= $(abspath $(NPC_DIR)/../nemu)
ROOT_SOC ?= $(abspath $(NPC_DIR)/../ysyxSoC)
ROOT_NVBOARD ?= $(abspath $(NPC_DIR)/../nvboard)
NEMU_HOME ?= $(ROOT_NEMU)
YSYX_SOC_HOME ?= $(ROOT_SOC)
NVBOARD_HOME ?= $(ROOT_NVBOARD)
export NVBOARD_HOME

.DEFAULT_GOAL := app

ifeq ($(wildcard $(NPC_DIR)/csrc/npc-main.c),)
$(error NPC_DIR=$(NPC_DIR) does not contain the NPC host sources)
endif
ifneq ($(abspath $(CURDIR)),$(NPC_DIR))
$(error invoke NPC targets with: make -C $(NPC_DIR) ...)
endif

MAKE_TASKS := $(if $(strip $(MAKECMDGOALS)),$(MAKECMDGOALS),app)
SETUP_TASKS := help menuconfig npc_set saveconfig $(filter %config,$(MAKE_TASKS))
NEEDS_ARTIFACTS := $(filter-out $(SETUP_TASKS),$(MAKE_TASKS))

ifneq ($(strip $(NEEDS_ARTIFACTS)),)
-include $(NPC_DIR)/include/config/auto.conf
-include $(NPC_DIR)/include/config/auto.conf.cmd
endif

unquote = $(patsubst "%",%,$(1))

ISA_FAMILY := riscv32
SIM_MODE ?= npc
UART_STDOUT ?= 1

ifneq ($(filter npc ysyxsoc,$(SIM_MODE)),$(SIM_MODE))
$(error SIM_MODE='$(SIM_MODE)' is unsupported; choose npc or ysyxsoc)
endif

DEBUG_BUILD := $(if $(filter 1 y yes true,$(DEBUG)),1,$(if $(CONFIG_CC_DEBUG),1,))
UART_RTL := $(if $(filter 0 n no false,$(UART_STDOUT)),,1)
SIM_NAME := $(ISA_FAMILY)-$(SIM_MODE)-interpreter$(if $(DEBUG_BUILD),-debug,)$(if $(UART_RTL),,-no-uart-stdout)

USE_NPC := $(if $(filter npc,$(SIM_MODE)),y,)
USE_SOC := $(if $(filter ysyxsoc,$(SIM_MODE)),y,)

include $(NPC_DIR)/csrc/sources.mk

find_host_sources = $(if $(strip $(1)),$(shell cd $(NPC_DIR) && find -L $(1) -type f \( -name '*.c' -o -name '*.cc' -o -name '*.cpp' \)),)
SOURCE_FILES += $(call find_host_sources,$(SOURCE_DIRS))
EXCLUDE_FILES += $(call find_host_sources,$(EXCLUDE_DIRS))
SRCS := $(filter-out $(EXCLUDE_FILES),$(SOURCE_FILES))

CC := gcc
CFLAGS += $(call unquote,$(CONFIG_CC_OPT))
CFLAGS += $(if $(DEBUG_BUILD),-Og -ggdb3 -DDEBUG,)
CFLAGS += -DITRACE_COND='$(if $(CONFIG_ITRACE_COND),$(subst ",,$(CONFIG_ITRACE_COND)),true)'
CFLAGS += -DMTRACE_COND='$(if $(CONFIG_MTRACE_COND),$(subst ",,$(CONFIG_MTRACE_COND)),true)'
LDFLAGS += $(call unquote,$(CONFIG_CC_OPT))

include $(NPC_DIR)/scripts/config.mk

ifneq ($(strip $(NEEDS_ARTIFACTS)),)
include $(NPC_DIR)/scripts/run.mk

RTL_TASKS := sim-iverilog sim-iverilog-netlist
ifneq ($(filter $(RTL_TASKS),$(MAKE_TASKS)),)
include $(NPC_DIR)/scripts/icarus-sim.mk
endif

include $(NPC_DIR)/scripts/safety.mk
endif
