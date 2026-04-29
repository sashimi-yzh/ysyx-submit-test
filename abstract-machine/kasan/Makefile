NAME = kasan
KASAN_DIR ?= baremetal_kasan

SRC_FILENAMES = kasan.c heap.c rt_utils.c

foo.mk:
	git clone --depth=1 https://github.com/androidoffsec/baremetal_kasan.git
	touch foo.mk

include foo.mk

# fuck am compile order
# $(shell mkdir -p ./build)
# $(shell cp $(KASAN_DIR)/common.h ./build/mem.h)

SRCS = $(addprefix $(KASAN_DIR)/,$(SRC_FILENAMES))
CFLAGS += -I$(KASAN_DIR) -I$(abspath .)

SRCS += $(shell find . -name '*.c')

IS_BUILDKASAN = 1

include $(AM_HOME)/Makefile
