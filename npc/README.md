# 1. Trace 工具如何打开；
打开[NPC_cloud_SoC/include/npc.h]，集中在10~25行：
波形记录：取消注释：`#define WAVE 1`，不记录波形则注释该代码
连接NVBoard：取消注释：`#define NVBOARD 1`，否则注释该代码

表达式生成器测试用例：`#define TEST_EXPR 0`，修改宏定义为1，否则修改宏定义为0
打开监视点：`#define SCAN_WATCHPOINT 0`，修改宏定义为1，否则修改宏定义为0

打开指令执行的踪迹：取消注释:`#define NPC_ITRACE 0`，否则注释该代码
打开寄存器的踪迹：`#define NPC_RTRACE 0`，修改宏定义为1，否则修改宏定义为0
打开函数调用的踪迹：`#define NPC_FTRACE 0`，修改宏定义为1，否则修改宏定义为0
打开内存访问的踪迹：`#define NPC_MTRACE 0`修改宏定义为1，，否则修改宏定义为0

打开差分测试：`#define NPC_DIFFTEST 0`，修改宏定义为1，否则修改宏定义为0

NEMU中各个Trace 工具在，make menuconfig里，testing and debugging中

# 2. RT-Thread 运行
运行 `make ARCH=riscv32e-ysyxSoC run`
连接NVBoard
然后在 [~/Templates/rt-thread-am/bsp/abstract-machine] 终端里运行`make ARCH=riscv32e-ysyxSoC run`
运行到有内容打印大概需要20min（去掉校准后快一些），勉强能玩贪吃蛇，打字游戏和超级玛丽太卡了，能运行但玩不了

如果运行`make ARCH=riscv32-nemu run` 或者 `make ARCH=riscv32e-npc run`：
在 [~/Templates/rt-thread-am/bsp/abstract-machine] 终端里
运行`make ARCH=riscv32-nemu run` 或者 `make ARCH=riscv32e-npc run`

# 3. 运行项目工程，除了讲义提及的要求之外，还需要额外完成哪些配置。
为了CI测试注释掉`/home/cloud/ysyx-workbench/ysyxSoC/perip/uart16550/rtl/uart_tfifo.v`里打印语句
需要终端打印的话要取消注释

ysyxSoC环境下差分测试:
注释掉[ysyx-workbench/abstract-machine/am/src/riscv/ysyxsoc/trm.c]里的158行`CSR_init();`
在make menuconfig里，testing and debugging中打开Enable ysyxsoc-difftest 
再make clean 后修改Build target，然后make，才能测试

运行  `make ARCH=riscv32e-npc run`前：
npc环境下差分测试:
需要在make menuconfig里，testing and debugging中关闭Enable ysyxsoc-difftest 
再make clean 后make，才能测试

运行  `make ARCH=riscv32-nemu run`前：
需要在make menuconfig里，testing and debugging中关闭Enable ysyxsoc-difftest 
再make clean 后make，才能测试

如果运行iverilog，需要考虑ebreak退出，取消[NPC_cloud_SoC/rtl/npc_cloud_cpu.scala]里47行的注释
   io.slave.bid := wbu.io.out.bits.asBool //ebreak
