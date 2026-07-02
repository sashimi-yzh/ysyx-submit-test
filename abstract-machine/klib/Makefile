NAME = klib
SRCS = $(shell find src/ -name "*.c")
ifeq ($(PICOLIBC),1)
SRCS = src/picolibc.c src/cpp.c
else
SRCS := $(filter-out src/picolibc.c,$(SRCS))
endif
include $(AM_HOME)/Makefile
