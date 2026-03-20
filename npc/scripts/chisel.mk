# Chisel

ifdef GITHUB_ACTIONS
$(info Detected CI environment, emit mill version file to make CI test mill version happy)
$(shell echo '0.12.4' > ../../../.mill-version)
endif

CHISEL2V_DEST_ISA_EMIT_DIR := $(CHISEL2V_EMIT_ROOT)/$(ARCH_ISA)
$(shell mkdir -p $(CHISEL2V_DEST_ISA_EMIT_DIR))
$(shell touch $(CHISEL2V_DEST_ISA_EMIT_DIR)/filelist.f)

define rd_filelist_indir 
$(addprefix $(1)/, $(shell cat $(1)/filelist.f))
endef

CHISEL_UNSYNTH_KEYWORDS = DPICLayer|DifftestLayer|verification
define rd_synth_filelist_indir
$(addprefix $(1)/, $(shell grep -vE "$(CHISEL_UNSYNTH_KEYWORDS)" $(1)/filelist.f))
endef

MILL ?= 

GLOBAL_MILL_EXISTS := $(shell command -v mill 2> /dev/null)
LOCAL_MILL_EXISTS := $(shell test -f ./mill && echo y)
ifeq ($(MILL),)
ifneq ($(GLOBAL_MILL_EXISTS),)
  $(info Using global Mill: $(shell which mill))
  MILL = mill
else ifeq ($(LOCAL_MILL_EXISTS), y)
  $(info Using local Mill: $(abspath ./mill))
  MILL = ./mill
else
  $(info Mill build tool not found. Please install Mill or place a local copy in the project directory.)
endif
else
  $(info Using specified Mill: $(MILL))
endif

CHISEL2V_DONE = $(BUILD_DIR)/verilog.done

CHISEL_DESIGN = design
CHISEL_SRCS = $(shell find $(abspath $(CHISEL_DESIGN)) -name "*.scala")
CHISEL_SRCS += build.mill

VERILATOR_INCDIRS += $(shell find $(abspath $(CHISEL2V_DEST_ISA_EMIT_DIR)) -type d)

# Core design verilog and some verification/dpic layer impl
CHISEL_EMITED_VSRCS = $(call rd_filelist_indir, $(CHISEL2V_DEST_ISA_EMIT_DIR))

# Core design verilog only, remove layer impl
CHISEL_EMITED_VSRCS_SYNTH = $(call rd_synth_filelist_indir, $(CHISEL2V_DEST_ISA_EMIT_DIR))

# un synithesizable sources
#
# Layer : Verification code for assert/assume/cover... and printf ...
# 				Chisel generates these code into separate files with name like `layers-*` to
# 				make core logic synthesizable and clean
#
CHISEL_EMITED_VSRCS_LAYER = $(shell find $(abspath $(CHISEL2V_DEST_ISA_EMIT_DIR)) -name "layers-*")

$(CHISEL2V_DONE): $(CHISEL_SRCS)
ifndef IN_LOCK
	@+flock $(CHISEL2V_DONE).lock $(MAKE) $(CHISEL2V_DONE) IN_LOCK=1
else
	$(call git_commit, "generate verilog")
	@echo "# Removing old emitted verilog"
	# @rm -rf $(CHISEL2V_EMIT_ROOT)
	@find "$(CHISEL2V_EMIT_ROOT)" -type f -delete
	@echo "# Emitting verilog with Mill"
	$(MILL) -i $(CHISEL_DESIGN).runMain Elaborate --target-dir $(CHISEL2V_EMIT_ROOT)
	@touch $(CHISEL2V_DONE)
endif

#
# use file xxx.done as a dependency to avoid repeated insertion
# since the sed command modifies the source files
# the real modification only needs when CHISEL2V_DONE is updated
#

# # Insert verilog public modifier for VPI
# #   see https://verilator.org/guide/latest/extensions.html#cmdoption-verilator-public_-flat-flat_rd-flat_rw-_on
# # to enable VPI work (make signal accessible from C++ side)
# VPI_DONE := $(BUILD_DIR)/vpi.done
# $(VPI_DONE): $(CHISEL2V_DONE)
# ifeq ($(ENABLE_VPI), 1)
# 	$(info # Inserting verilator public modifier)
# 	@$(foreach src,$(MY_SIM_VSRCS),\
# 	sed -i '1i /*verilator public_on*/' $(src); \
# 	sed -i -e '$$a /*verilator public_off*/' $(src);)
# 	@touch $@
# endif


# Chisel generates macro like `layer$xxx` to control inline layer
# renaming them to `$(CPU_DESIGN_NAME)_xxx` to avoid conflict and
# make them more standard as macro names (convinient to pass to verilator)

# RENAME_LAYER_MACRO := $(BUILD_DIR)/rename_layer_macro.done
# $(RENAME_LAYER_MACRO): $(CHISEL2V_DONE)
# 	$(info # Renaming unstandard layer$$ style macro)
# 	@$(foreach src,$(MY_SIM_VSRCS), sed -i 's/layer\$$\(\w\+\)/$(CPU_DESIGN_NAME)_\1/g' $(src);)
# 	@touch $@

