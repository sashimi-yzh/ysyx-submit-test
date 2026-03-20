# testsoc

SOC_HOME = $(CHISEL2V_EMIT_ROOT)/testsoc/$(ARCH_PLATFORM)
$(shell mkdir -p $(SOC_HOME))
$(shell touch $(SOC_HOME)/filelist.f)

SOC_LAYER_VSRCS = $(shell find $(abspath $(SOC_HOME)) -name "layers-*")
SOC_SYNTH_VSRCS = $(call rd_synth_filelist_indir, $(SOC_HOME))
SOC_VSRCS = $(call rd_filelist_indir, $(SOC_HOME))

MY_SIM_VSRCS += $(SOC_VSRCS)
MY_SIM_VSRCS += $(SOC_LAYER_VSRCS)

VERILATOR_INCDIRS += $(shell find $(abspath $(SOC_HOME)) -type d)
RESET_PC = 80000000
