DIRS-BLACKLIST += src/isa/x86/device
ifdef CONFIG_PERF_OPT
SRCS-BLACKLIST += src/isa/x86/inst.c
else
SRCS-BLACKLIST += src/isa/x86/inst/decode.c
endif
