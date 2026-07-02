NPC_HOME := $(abspath $(dir $(lastword $(MAKEFILE_LIST))))
NEMU_HOME ?= $(abspath ../nemu)
YSYX_SOC_HOME ?= $(abspath ../ysyxSoC)
NVBOARD_HOME ?= $(abspath ../nvboard)

ifeq ($(wildcard $(NPC_HOME)/src/npc-main.c),)
  $(error NPC_HOME=$(NPC_HOME) is not an NPC repo)
endif
ifneq ($(CURDIR),$(NPC_HOME))
  $(error Please run NPC make targets with 'make -C $(NPC_HOME) ...')
endif

config-only-goals := help menuconfig savedefconfig $(filter %defconfig,$(MAKECMDGOALS))
ifneq ($(MAKECMDGOALS),$(filter $(config-only-goals),$(MAKECMDGOALS)))
-include $(NPC_HOME)/include/config/auto.conf
-include $(NPC_HOME)/include/config/auto.conf.cmd
endif

remove_quote = $(patsubst "%",%,$(1))

GUEST_ISA := riscv32
SIM_MODE ?= npc
DEBUG_ENABLED := $(if $(filter 1 y yes true,$(DEBUG)),1,$(if $(CONFIG_CC_DEBUG),1,))
UART_STDOUT ?= 0
UART_STDOUT_ENABLED := $(if $(filter 0 n no false,$(UART_STDOUT)),,1)
NAME = $(GUEST_ISA)-$(SIM_MODE)-interpreter$(if $(DEBUG_ENABLED),-debug,)$(if $(UART_STDOUT_ENABLED),,-no-uart-stdout)

ifneq ($(filter npc ysyxsoc,$(SIM_MODE)),$(SIM_MODE))
  $(error Unsupported SIM_MODE='$(SIM_MODE)'. Expected 'npc' or 'ysyxsoc')
endif
ifeq ($(SIM_MODE),npc)
NPC_PLATFORM_NPC := y
NPC_PLATFORM_YSYXSOC :=
else
NPC_PLATFORM_NPC :=
NPC_PLATFORM_YSYXSOC := y
endif

FILELIST_MK = $(shell cd $(NPC_HOME) && find -L ./src -name "filelist.mk")
include $(FILELIST_MK)

DIRS-BLACKLIST-y += $(DIRS-BLACKLIST)
SRCS-BLACKLIST-y += $(if $(DIRS-BLACKLIST-y), $(shell cd $(NPC_HOME) && find -L $(DIRS-BLACKLIST-y) \( -name "*.c" -o -name "*.cc" -o -name "*.cpp" \)),)
SRCS-BLACKLIST-y += $(SRCS-BLACKLIST)
SRCS-y += $(if $(DIRS-y), $(shell cd $(NPC_HOME) && find -L $(DIRS-y) \( -name "*.c" -o -name "*.cc" -o -name "*.cpp" \)),)
SRCS = $(filter-out $(SRCS-BLACKLIST-y),$(SRCS-y))

CC := gcc
CFLAGS_BUILD += $(call remove_quote,$(CONFIG_CC_OPT))
CFLAGS_BUILD += $(if $(DEBUG_ENABLED),-Og -ggdb3,)
CFLAGS_BUILD += $(if $(DEBUG_ENABLED),-DDEBUG,)
CFLAGS_TRACE += -DITRACE_COND='$(if $(CONFIG_ITRACE_COND),$(subst ",,$(CONFIG_ITRACE_COND)),true)'
CFLAGS_TRACE += -DMTRACE_COND='$(if $(CONFIG_MTRACE_COND),$(subst ",,$(CONFIG_MTRACE_COND)),true)'
CFLAGS += $(CFLAGS_BUILD) $(CFLAGS_TRACE)
LDFLAGS += $(CFLAGS_BUILD)

include $(NPC_HOME)/scripts/config.mk

ifneq ($(MAKECMDGOALS),$(filter $(config-only-goals),$(MAKECMDGOALS)))
include $(NPC_HOME)/scripts/native.mk
iverilog-targets := sim-iverilog sim-iverilog-netlist
ifneq ($(filter $(iverilog-targets),$(MAKECMDGOALS)),)
include $(NPC_HOME)/scripts/iverilog.mk
endif
endif
