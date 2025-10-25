#pragma once
#include <dlfcn.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

struct Difftest
{
	void init_difftest(long img_size);
	void (*ref_difftest_memcpy)(uint32_t addr, void *buf, size_t n, bool direction) = NULL;
	void (*ref_difftest_regcpy)(void *dut, bool direction) = NULL;
	void (*ref_difftest_exec)(uint64_t n) = NULL;
	char ref_so_file[256] = "/home/pglzjz/ysyx-workbench/nemu/build/riscv32-nemu-interpreter-so";
	int port = 0;
};