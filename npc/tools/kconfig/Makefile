NAME = conf
NPC_HOME ?= $(abspath ../..)
obj := build
SRCS += confdata.c expr.c preprocess.c symbol.c util.c
SRCS += $(obj)/lexer.lex.c $(obj)/parser.tab.c
CC = gcc
CFLAGS += -DYYDEBUG
TOOL_INCLUDE += .
DISTRO = $(shell cat /etc/os-release | grep PRETTY_NAME | sed 's/PRETTY_NAME=//')

ifeq ($(DISTRO),"Gentoo Linux")
LIBS += -ltinfo
endif

ifeq ($(NAME),conf)
SRCS += conf.c
else ifeq ($(NAME),mconf)
SRCS += mconf.c $(shell find lxdialog/ -name "*.c")
LIBS += -lncurses
else
$(error bad target=$(NAME))
endif

include $(NPC_HOME)/scripts/toolchain.mk

$(obj)/lexer.lex.o: $(obj)/parser.tab.h
$(obj)/lexer.lex.c: lexer.l $(obj)/parser.tab.h
	@printf '[tool] lex %s\n' '$@'
	@flex -o $@ $<

$(obj)/parser.tab.c $(obj)/parser.tab.h: parser.y
	@printf '[tool] yacc %s\n' '$@'
	@bison -v $< --defines=$(obj)/parser.tab.h -o $(obj)/parser.tab.c

conf:
	@$(MAKE) -s

mconf:
	@$(MAKE) -s NAME=mconf

.PHONY: conf mconf
