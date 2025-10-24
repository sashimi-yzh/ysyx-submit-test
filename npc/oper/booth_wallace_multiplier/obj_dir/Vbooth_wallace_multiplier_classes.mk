# Verilated -*- Makefile -*-
# DESCRIPTION: Verilator output: Make include file with class lists
#
# This file lists generated Verilated files, for including in higher level makefiles.
# See Vbooth_wallace_multiplier.mk for the caller.

### Switches...
# C11 constructs required?  0/1 (always on now)
VM_C11 = 1
# Timing enabled?  0/1
VM_TIMING = 0
# Coverage output mode?  0/1 (from --coverage)
VM_COVERAGE = 0
# Parallel builds?  0/1 (from --output-split)
VM_PARALLEL_BUILDS = 1
# Tracing output mode?  0/1 (from --trace/--trace-fst)
VM_TRACE = 1
# Tracing output mode in VCD format?  0/1 (from --trace)
VM_TRACE_VCD = 1
# Tracing output mode in FST format?  0/1 (from --trace-fst)
VM_TRACE_FST = 0

### Object file lists...
# Generated module classes, fast-path, compile with highest optimization
VM_CLASSES_FAST += \
	Vbooth_wallace_multiplier \
	Vbooth_wallace_multiplier___024root__DepSet_he1b26b9d__0 \
	Vbooth_wallace_multiplier___024root__DepSet_ha6307e34__0 \
	Vbooth_wallace_multiplier___024root__DepSet_ha6307e34__1 \
	Vbooth_wallace_multiplier_walloc_17bits__DepSet_h372db835__0 \
	Vbooth_wallace_multiplier_walloc_17bits__DepSet_h372db835__1 \
	Vbooth_wallace_multiplier_walloc_17bits__DepSet_h372db835__2 \

# Generated module classes, non-fast-path, compile with low/medium optimization
VM_CLASSES_SLOW += \
	Vbooth_wallace_multiplier___024root__Slow \
	Vbooth_wallace_multiplier___024root__DepSet_he1b26b9d__0__Slow \
	Vbooth_wallace_multiplier___024root__DepSet_ha6307e34__0__Slow \
	Vbooth_wallace_multiplier_walloc_17bits__Slow \
	Vbooth_wallace_multiplier_walloc_17bits__DepSet_hf7cd2c8c__0__Slow \

# Generated support classes, fast-path, compile with highest optimization
VM_SUPPORT_FAST += \
	Vbooth_wallace_multiplier__Trace__0 \
	Vbooth_wallace_multiplier__Trace__1 \
	Vbooth_wallace_multiplier__Trace__2 \

# Generated support classes, non-fast-path, compile with low/medium optimization
VM_SUPPORT_SLOW += \
	Vbooth_wallace_multiplier__Syms \
	Vbooth_wallace_multiplier__Trace__0__Slow \
	Vbooth_wallace_multiplier__Trace__1__Slow \
	Vbooth_wallace_multiplier__Trace__2__Slow \

# Global classes, need linked once per executable, fast-path, compile with highest optimization
VM_GLOBAL_FAST += \
	verilated \
	verilated_vcd_c \
	verilated_threads \

# Global classes, need linked once per executable, non-fast-path, compile with low/medium optimization
VM_GLOBAL_SLOW += \


# Verilated -*- Makefile -*-
