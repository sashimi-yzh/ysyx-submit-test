# 常用工具链（mill 提供）
#
#   make test / help / reformat / checkformat / bsp / idea

test:
	mill -i playground.test

help:
	mill -i playground.runMain Elaborate --help

reformat:
	mill -i __.reformat

checkformat:
	mill -i __.checkFormat

bsp:
	mill -i mill.bsp.BSP/install

idea:
	mill -i mill.idea.GenIdea/idea
