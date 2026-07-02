ifeq ($(strip $(CONTRACT_ID)),)
$(error CONTRACT_ID is not set)
endif

ifeq ($(strip $(CONTRACT_ARCHS)),)
$(error CONTRACT_ARCHS is not set for $(CONTRACT_ID))
endif

ifeq ($(strip $(CONTRACT_GROUP)),)
$(error CONTRACT_GROUP is not set for $(CONTRACT_ID))
endif

ifeq ($(strip $(CONTRACT_POINTS)),)
$(error CONTRACT_POINTS is not set for $(CONTRACT_ID))
endif

ARCH ?= riscv32e-ysyxsoc

ifeq ($(filter $(ARCH),$(CONTRACT_ARCHS)),)
$(error contract $(CONTRACT_ID) does not support ARCH=$(ARCH); supported: $(CONTRACT_ARCHS))
endif

NAME = $(CONTRACT_ID)
SRCS ?= src/main.c
INC_PATH += $(CONTRACT_ROOT)/include
CFLAGS += -DCONTRACT_SUITE=\"$(CONTRACT_ID)\"
CFLAGS += -DCONTRACT_GROUP=\"$(CONTRACT_GROUP)\"

include $(AM_HOME)/Makefile
