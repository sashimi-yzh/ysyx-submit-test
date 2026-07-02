CONTRACT_ID = platform-ysyxsoc-flash-sram-suite
CONTRACT_GROUP = platform-layout
CONTRACT_ARCHS = riscv32e-ysyxsoc
CONTRACT_POINTS = ysyxsoc-layout-flash-sram
CONTRACT_ROOT = ../..
SRCS = src/start.S src/main.c
include $(CONTRACT_ROOT)/contract.mk

AM_SRCS := $(filter-out riscv/ysyxsoc/start.S,$(AM_SRCS))
LDSCRIPTS := linker-flash-sram.ld
LDFLAGS := -z noexecstack -melf32lriscv --defsym=_pmem_start=0x30000000 --defsym=_entry_offset=0x0 --gc-sections -e _start $(addprefix -T,$(LDSCRIPTS))
