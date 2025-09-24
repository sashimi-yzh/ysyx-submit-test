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

WORK_DIR = $(NEMU_HOME)/tools/gen-expr
BUILD_DIR = $(WORK_DIR)/build

all:
	@mkdir -p $(BUILD_DIR)
	@gcc -o $(BUILD_DIR)/gen-expr $(WORK_DIR)/gen-expr.c

run:all
	@$(BUILD_DIR)/gen-expr $(LU) 100 > /tmp/expr_result.txt

clean:
	@rm -rf build

.PHONY: all clean