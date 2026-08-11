# Host-side source manifest.  Directory entries are expanded by the top-level
# makefile so platform-specific files stay out of the opposite simulator.

SOURCE_FILES += csrc/npc-main.c
SOURCE_FILES += csrc/platform/sim.cpp
SOURCE_FILES += csrc/platform/trace.cpp
SOURCE_FILES += $(if $(USE_NPC),csrc/platform/npc.cpp,)
SOURCE_FILES += $(if $(USE_SOC),csrc/platform/ysyxsoc.cpp,)

SOURCE_DIRS += csrc/cpu
SOURCE_DIRS += csrc/dpi
SOURCE_DIRS += csrc/engine/interpreter
SOURCE_DIRS += csrc/isa/$(ISA_FAMILY)
SOURCE_DIRS += csrc/memory
SOURCE_DIRS += csrc/monitor
SOURCE_DIRS += csrc/runtime
SOURCE_DIRS += csrc/trace

HOST_INCLUDES += $(NPC_DIR)/csrc/engine/interpreter
HOST_INCLUDES += $(NPC_DIR)/csrc/isa/$(ISA_FAMILY)/include

# Disassembly needs Capstone, so do not compile it when instruction tracing is off.
ifneq ($(CONFIG_ITRACE),y)
EXCLUDE_FILES += csrc/trace/disasm.c
endif
