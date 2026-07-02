#***************************************************************************************
# Copyright (c) 2014-2024 Zihao Yu, Nanjing University
#
# NEMU is licensed under Mulan PSL v2.
# You can use this software according to the terms and conditions of the Mulan PSL v2.
# You may obtain a copy of Mulan PSL v2 at:
#          http://license.coscl.org.cn/MulanPSL2
#
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
# EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
# MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
#
# See the Mulan PSL v2 for more details.
#**************************************************************************************/

NAME = gen-expr
SRCS = gen-expr.c
include $(NEMU_HOME)/scripts/build.mk

.PHONY: test gen clean

# Compile and run test
test: $(BINARY)
	$(call git_commit, "generate expr test cases")
	$(BINARY) 100 > input
	gcc -o test_expr test_expr.c -I$(NEMU_HOME)/include -DCONFIG_ISA32=1
	./test_expr input

clean:
	rm -rf .code.c .expr test_expr input 
