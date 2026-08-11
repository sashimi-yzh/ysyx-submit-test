# Host compiler and Verilator link rules.

.DEFAULT_GOAL := app

ARTIFACT_ROOT := $(NPC_DIR)/build
MODE_ARTIFACT := $(ARTIFACT_ROOT)/$(SIM_MODE)
OBJECT_DIR := $(MODE_ARTIFACT)/obj-$(SIM_NAME)
NPC_BIN := $(MODE_ARTIFACT)/$(SIM_NAME)

VERILATOR ?= verilator
OBJCACHE ?=
export OBJCACHE

CAPSTONE_ROOT := $(NPC_DIR)/tools/capstone
CAPSTONE_LIB := $(CAPSTONE_ROOT)/repo/libcapstone.so.5
make_comma := ,

include $(NPC_DIR)/scripts/rtl.mk

INCLUDE_DIRS := $(NPC_DIR)/include $(HOST_INCLUDES) $(RTL_INC)
INCLUDE_FLAGS := $(addprefix -I,$(INCLUDE_DIRS))
CFLAGS := -MMD -Wall -Werror $(INCLUDE_FLAGS) $(CFLAGS)
CFLAGS += -fmacro-prefix-map=$(NPC_DIR)/=
CFLAGS += -DTOP_NAME=\"V$(SIM_TOP)\"
CFLAGS += $(if $(filter npc,$(SIM_MODE)),-DNPC_BUILD_PLATFORM_NPC=1,-DNPC_BUILD_PLATFORM_YSYXSOC=1)
CFLAGS += $(if $(CONFIG_ITRACE),-I$(CAPSTONE_ROOT)/repo/include,)
LDFLAGS += -lreadline -ldl
LDFLAGS += $(if $(CONFIG_ITRACE),-Wl$(make_comma)-rpath$(make_comma)$(CAPSTONE_ROOT)/repo $(CAPSTONE_LIB),)

C_UNITS := $(filter %.c,$(SRCS))
CPP_UNITS := $(abspath $(filter %.cc %.cpp,$(SRCS)))
C_OBJECTS := $(patsubst %.c,$(OBJECT_DIR)/%.o,$(C_UNITS))
HOST_HEADER := $(shell find $(NPC_DIR)/include $(NPC_DIR)/csrc -type f \( -name '*.h' -o -name '*.hpp' \))

VL_FLAGS := -MMD --build -cc $(call unquote,$(CONFIG_VERILATOR_OPT)) \
	--x-assign fast --x-initial fast --noassert \
	-Wno-PINMISSING -Wno-WIDTHEXPAND --timescale 1ns/1ns --no-timing \
	--autoflush -MAKEFLAGS VM_DEFAULT_RULES=0 $(if $(CONFIG_WAVE),--trace,)
VL_DEFS := -DNPC_SIMULATION $(if $(UART_RTL),-DNPC_UART_STDOUT_RTL,)

# A changed command vector selects a new mark and naturally invalidates objects.
BUILD_VECTOR := SIM_MODE=$(SIM_MODE) SIM_TOP=$(SIM_TOP) SIM_NAME=$(SIM_NAME) \
	CFLAGS=$(CFLAGS) LDFLAGS=$(LDFLAGS) VL_FLAGS=$(VL_FLAGS) \
	VL_DEFS=$(VL_DEFS) SRCS=$(SRCS) SIM_RTL=$(SIM_RTL)
BUILD_MARK := $(MODE_ARTIFACT)/.inputs

.PHONY: NPC_REFRESH
NPC_REFRESH:

$(MODE_ARTIFACT):
	@mkdir -p $@

$(BUILD_MARK): NPC_REFRESH | $(MODE_ARTIFACT)
	@tmp="$@.tmp"; printf '%s\n' '$(BUILD_VECTOR)' > "$$tmp"; \
	if test -r "$@" && cmp -s "$$tmp" "$@"; then rm -f "$$tmp"; else \
	printf '[npc][config] build inputs changed mode=%s artifact=%s\n' '$(SIM_MODE)' '$(MODE_ARTIFACT)'; \
	mv -f "$$tmp" "$@"; fi

$(C_OBJECTS): $(OBJECT_DIR)/%.o: %.c $(BUILD_MARK)
	@mkdir -p $(dir $@)
	@printf '[npc][cc] %s\n' '$<'
	@$(CC) $(CFLAGS) -c -o $@ $<
	$(call call_fixdep,$(@:.o=.d),$@)

-include $(C_OBJECTS:.o=.d)

$(CAPSTONE_LIB):
	@printf '[npc][tool] building capstone=%s\n' '$(CAPSTONE_LIB)'
	@$(MAKE) -C $(CAPSTONE_ROOT)

ifeq ($(CONFIG_ITRACE),y)
TRACE_DEPS += $(CAPSTONE_LIB)
endif

CONFIG_DEPS := $(NPC_DIR)/include/generated/autoconf.h $(NPC_DIR)/include/config/auto.conf
NPC_LINK_DEPS := $(SIM_RTL) $(RTL_HEADER) $(CPP_UNITS) $(HOST_HEADER) \
	$(C_OBJECTS) $(BUILD_MARK) $(SOC_DEPS) \
	$(TRACE_DEPS) $(CONFIG_DEPS) $(NPC_DIR)/csrc/sources.mk \
	$(NPC_DIR)/Makefile $(NPC_DIR)/scripts/host-build.mk \
	$(NPC_DIR)/scripts/rtl.mk $(NPC_DIR)/scripts/run.mk

app build: $(NPC_BIN)

$(NPC_BIN): $(NPC_LINK_DEPS) | $(MODE_ARTIFACT)
	@printf '[npc][build] mode=%s top=%s output=%s\n' '$(SIM_MODE)' '$(SIM_TOP)' '$(NPC_BIN)'
	@printf '[npc][build] rtl_inputs=%s c_units=%s cxx_units=%s\n' '$(words $(SIM_RTL))' '$(words $(C_UNITS))' '$(words $(CPP_UNITS))'
	@rm -f $(abspath $(NPC_BIN))
	+@$(VERILATOR) $(VL_FLAGS) $(VL_DEFS) $(INCLUDE_FLAGS) \
		--top-module $(SIM_TOP) $(SIM_RTL) $(CPP_UNITS) $(C_OBJECTS) $(SOC_INPUTS) \
		$(addprefix -CFLAGS ,$(CFLAGS)) $(addprefix -LDFLAGS ,$(LDFLAGS)) \
		--Mdir $(OBJECT_DIR)/verilator --exe -o $(abspath $(NPC_BIN))
	@touch $(abspath $(NPC_BIN))
	@printf '[npc][build] ready binary=%s\n' '$(NPC_BIN)'

clean:
	@printf '[npc][clean] removing artifact_root=%s\n' '$(ARTIFACT_ROOT)'
	@rm -rf $(ARTIFACT_ROOT)
	@printf '[npc][clean] complete\n'

.PHONY: app build clean rtl-bundle
