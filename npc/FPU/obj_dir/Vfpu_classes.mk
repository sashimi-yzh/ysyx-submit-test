# Verilated -*- Makefile -*-
# DESCRIPTION: Verilator output: Make include file with class lists
#
# This file lists generated Verilated files, for including in higher level makefiles.
# See Vfpu.mk for the caller.

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
	Vfpu \
	Vfpu___024root__DepSet_hbe86dc64__0 \
	Vfpu___024root__DepSet_hf745f77d__0 \
	Vfpu___024root__DepSet_hf745f77d__1 \
	Vfpu___024root__DepSet_hf745f77d__2 \
	Vfpu_walloc_17bits__DepSet_hf6031a0a__0 \
	Vfpu_walloc_17bits__DepSet_hf6031a0a__1 \
	Vfpu_walloc_17bits__DepSet_hf6031a0a__2 \

# Generated module classes, non-fast-path, compile with low/medium optimization
VM_CLASSES_SLOW += \
	Vfpu___024root__Slow \
	Vfpu___024root__DepSet_hbe86dc64__0__Slow \
	Vfpu___024root__DepSet_hf745f77d__0__Slow \
	Vfpu_walloc_17bits__Slow \
	Vfpu_walloc_17bits__DepSet_hafcabd8f__0__Slow \

# Generated support classes, fast-path, compile with highest optimization
VM_SUPPORT_FAST += \
	Vfpu__Trace__0 \
	Vfpu__Trace__1 \
	Vfpu__Trace__2 \

# Generated support classes, non-fast-path, compile with low/medium optimization
VM_SUPPORT_SLOW += \
	Vfpu__Syms \
	Vfpu__Trace__0__Slow \
	Vfpu__Trace__1__Slow \
	Vfpu__Trace__2__Slow \

# Global classes, need linked once per executable, fast-path, compile with highest optimization
VM_GLOBAL_FAST += \
	verilated \
	verilated_vcd_c \
	verilated_threads \

# Global classes, need linked once per executable, non-fast-path, compile with low/medium optimization
VM_GLOBAL_SLOW += \


# Verilated -*- Makefile -*-
