ifeq ($(CONFIG_NVBOARD),y)
include $(NPC_HOME)/scripts/nvboard.mk
endif

VERILATOR = verilator
GTKWAVE = gtkwave

OBJ_DIR = $(BUILD_DIR)/$(ARCH)-obj_dir
WAVE_DIR = $(BUILD_DIR)/wave
WAVE = $(WAVE_DIR)/sim.fst
$(shell mkdir -p $(OBJ_DIR))
$(shell mkdir -p $(WAVE_DIR))

YSYXSOC_DIR = $(NPC_HOME)/../ysyxSoC
YSYXSOC_LIBDIR = $(YSYXSOC_DIR)/perip/uart16550/rtl \
								 $(YSYXSOC_DIR)/perip/spi/rtl

VLT_FILE = $(BUILD_DIR)/../profile/profile.vlt
ifneq ($(wildcard $(VLT_FILE)),)
VLT_ARGS = $(VLT_FILE)
$(info Found profile.vlt, enabling PGO)
else
$(info profile.vlt not found, skipping PGO)
endif

VSRCS += $(shell find $(abspath $(VSRC_DIR)) -name "*.sv" -o -name "*.v")
VERILATOR_BUILDFLAGS += -MMD --cc --build -j 16 --autoflush \
				-O3 --x-assign fast --x-initial fast --noassert --threads 1

# VERILATOR_CFLAGS += -MMD --cc --build -j 16 \
# 				-O3 --x-assign fast --x-initial fast --noassert --threads 4 \
# 				--threads-max-mtasks 128 --threads-dpi all --prof-pgo --prof-exec $(VLT_ARGS)
ifeq ($(CONFIG_NPC_WAVE),y)
$(info WAVE is enable)
VERILATOR_BUILDFLAGS += --trace-fst
endif

CSRCS += $(shell find $(abspath $(NPC_HOME)/csrc) -name "*.c" -or -name "*.cc" -or -name "*.cpp")
ARCHIVES += $(OBJ_DIR)/libV$(TOPNAME).a $(OBJ_DIR)/libverilated.a $(OBJ_DIR)/V$(TOPNAME)__ALL.a
ifeq ($(CONFIG_NVBOARD),y)
ARCHIVES += $(NVBOARD_ARCHIVE)
endif

# Menuconfig
GUEST_ISA ?= $(call remove_quote,$(CONFIG_ISA))
ENGINE ?= $(call remove_quote,$(CONFIG_ENGINE))
NAME = $(GUEST_ISA)-nemu-$(ENGINE)

# FILELIST_MK = $(shell find -L $(NEMU_HOME)/src/isa -name "filelist.mk")
# include $(FILELIST_MK)

ifneq ($(CONFIG_CC),)
CC = $(call remove_quote,$(CONFIG_CC))
endif


CFLAGS_BUILD += -Wall -Werror 
CFLAGS_BUILD += -Wno-error=stringop-overread -Wno-nonnull-compare -Wno-error=stringop-overflow
CFLAGS_BUILD += $(call remove_quote,$(CONFIG_CC_OPT))
CFLAGS_BUILD += $(if $(CONFIG_CC_LTO),-flto,)
CFLAGS_BUILD += $(if $(CONFIG_CC_DEBUG),-O0 -ggdb3,)
CFLAGS_BUILD += $(if $(CONFIG_CC_DEBUG_ONLY_G),-g,)
CFLAGS_BUILD += $(if $(CONFIG_CC_ASAN),-fsanitize=address,)
CFLAGS_BUILD += $(if $(CONFIG_CC_UBSAN),-fsanitize=undefined,)
CFLAGS_BUILD += $(if $(CONFIG_CC_LKSAN),-fsanitize=leak,)

CFLAGS_TRACE += -DITRACE_COND=$(if $(CONFIG_ITRACE_COND),$(call remove_quote,$(CONFIG_ITRACE_COND)),true)
CFLAGS_TRACE += -DDTRACE_COND=$(if $(CONFIG_DTRACE_COND),$(call remove_quote,$(CONFIG_DTRACE_COND)),true)
CFLAGS_TRACE += -DMTRACE_COND=$(if $(CONFIG_MTRACE_COND),$(call remove_quote,$(CONFIG_MTRACE_COND)),true)
CFLAGS_TRACE += -DFTRACE_COND=$(if $(CONFIG_FTRACE_COND),$(call remove_quote,$(CONFIG_FTRACE_COND)),true)
CXXFLAGS += $(CFLAGS_BUILD) $(CFLAGS_TRACE) -D__GUEST_ISA__=$(GUEST_ISA)

# NVBOARD
ifeq ($(CONFIG_NVBOARD),y)
CXXFLAGS += -Wno-error=unused-variable -Wno-error=delete-non-virtual-dtor -Wno-error=sign-compare
endif

INC_PATH := $(NPC_HOME)/csrc/$(GUEST_ISA)/include \
						$(CFG_DIR)/include $(NEMU_HOME)/include \
						$(NEMU_HOME)/tools/mini-gdbstub/include \
						$(INC_PATH)
export ADD_INC_PATH := $(INC_PATH)
INCFLAGS = $(addprefix -I, $(INC_PATH))
CXXFLAGS += $(INCFLAGS) \
						-D__TOP_NAME__=$(TOPNAME) \
						-D__VTOP_NAME__=V$(TOPNAME) \
						-D__TOP_NAME_INCLUDE__=V$(TOPNAME).h \
						-D__TOP_NAME_SYMS_INCLUDE__=V$(TOPNAME)__Syms.h \
						-D__WAVE__=$(WAVE) \
						-D__NPC_VERILATOR_GPR__=$(CONFIG_NPC_VERILATOR_GPR)

NEMU_MAKE_FLAGS += CFG_DIR="$(CFG_DIR)" \
									 ADD_ARCHIVES="$(ARCHIVES)" \
									 ADD_LIBS=" \
									   -lz \
									   $(if $(CONFIG_NPC_WAVE),-llz4,) \
									   $(if $(CONFIG_NVBOARD),$(shell pkg-config --libs sdl2 SDL2_image SDL2_ttf),)"

make_ysyxsoc:
ifneq ($(findstring ysyxsoc,$(ARCH)),) # ysyxsoc
	-$(MAKE) -C $(YSYXSOC_DIR) verilog
endif

lint:
	-$(VERILATOR) $(VERILATOR_FLAGS) -Wall --lint-only --top-module $(TOPNAME) $(VSRCS)

build_ar: verilog make_ysyxsoc $(CSRCS) $(NVBOARD_ARCHIVE)
	# Build archives
	$(VERILATOR) $(VERILATOR_BUILDFLAGS) $(VERILATOR_FLAGS) \
		--top-module $(TOPNAME) $(VSRCS) $(CSRCS) $(NVBOARD_ARCHIVE) \
		$(addprefix -CFLAGS , $(CXXFLAGS)) \
		--Mdir $(OBJ_DIR)

wave:
	$(GTKWAVE) $(WAVE)



.PHONY: lint build_ar run gdb wave make_ysyxsoc
