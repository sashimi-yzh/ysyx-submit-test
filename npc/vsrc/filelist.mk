#***************************************************************************************
# Copyright (c) 2014-2022 Zihao Yu, Nanjing University
#
# NPC is licensed under Mulan PSL v2.
# You can use this software according to the terms and conditions of the Mulan PSL v2.
# You may obtain a copy of Mulan PSL v2 at:
#          http://license.coscl.org.cn/MulanPSL2
#
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
# EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
# MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
#
# See the Mulan PSL v2 for more details.
#**************************************************************************************/

#VSRCS += $(wildcard vsrc/*.sv)
#VSRCS += $(wildcard vsrc/*.v)
ifdef CONFIG_NPC
VSRCS += vsrc/npc_soc.v

ifdef CONFIG_NPC_IVERILOG_NET
YOSYS_STA_HOME ?= $(NPC_HOME)/../yosys-sta
NETLIST_RTL = vsrc/ysyx_24110012.v
NETLIST_SIM = vsrc/ysyx_24110012.netlist.v.sim
# NETLIST/CELLS can be overridden, e.g. by `make sim-iverilog-netlist`
NETLIST ?= $(NETLIST_SIM)
CELLS ?= $(YOSYS_STA_HOME)/pdk/nangate45/sim/cells.v
VSRCS += $(NETLIST)
VSRCS += $(CELLS)
else
VSRCS += vsrc/ysyx_24110012.v
endif

ifneq ($(or $(CONFIG_NPC_IVERILOG),$(CONFIG_NPC_IVERILOG_NET)),)
VSRCS += vsrc/test/npc.v
endif

else
VSRCS += vsrc/ysyx_24110012.v
endif