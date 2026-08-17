# 1.程序是个状态机
画出计算1+2+...+100的程序的状态机

$$
状态为(PC,R_{result},R_i)\\
初始状态(PC,R_{result},R_i)_0=(0,0,0)\\
(PC,R_{result},R_i)_{k+1}=
\begin{cases}
(1,R_{result},R_i+1)_k &若 PC=0\\
(2,R_{result}+R_i,R_i)_k &若 PC=1\\
(0,R_{result}+R_i,R_i)_k &若 PC=2且R_i\neq100\\
结束&若 PC=2且R_i=100
\end{cases}
$$

# 2.理解基础设施
我们通过一些简单的计算来体会简易调试器的作用. 首先作以下假设
+ 假设你需要编译500次NEMU才能完成PA.
+ 假设这500次编译当中, 有90%的次数是用于调试.
+ 假设你没有实现简易调试器, 只能通过GDB对运行在NEMU上的客户程序进行调试. 在每一次调试中, 由于GDB不能直接观测客户程序, 你需要花费30秒的时间来从GDB中获取并分析一个信息.
+ 假设你需要获取并分析20个信息才能排除一个bug.

那么这个学期下来, 你将会在调试上花费多少时间?

$500\times 0.9 \times 30\mathrm s \times 20 = 75\mathrm h$

# 3.RTFM
### riscv32有哪几种指令格式?
6种：RISBUJ

来源：The RISC-V Instruction Set Manual Volume I: Unprivileged ISA：p16-20

 Figure 2.3: RISC-V base instruction formats showing immediate variants.

 ### LUI指令的行为是什么?
 U-Type指令，指令中除opcode外含有20bit立即数`imm`和目标寄存器地址`rd`。
 
 行为:将`imm`填充到`rd`高20位，`rd`的低12位置零
```verilog
rd = {imm[19:0], 12'b0}
```
来源：Volume I: RISC-V Unprivileged ISA p19
```
LUI (load upper immediate) is used to build 32-bit constants and uses the U-type format. LUI
places the U-immediate value in the top 20 bits of the destination register rd, filling in the lowest
12 bits with zeros.
```
### mstatus寄存器的结构是怎么样的?
`mstatus`(Machine Status Registers)，见文档中图

来源：Volume II: RISC-V Privileged Architectures p20

3.1.6 Machine Status Registers (mstatus and mstatush)

# 5.shell命令
完成PA1的内容之后, `nemu/`目录下的所有.c和.h和文件总共有多少行代码? 你是使用什么命令得到这个结果的? 和框架代码相比, 你在PA1中编写了多少行代码? (Hint: 目前`pa0`分支中记录的正好是做PA1之前的状态, 思考一下应该如何回到"过去"?) 你可以把这条命令写入Makefile中, 随着实验进度的推进, 你可以很方便地统计工程的代码行数, 例如敲入`make count`就会自动运行统计代码行数的命令. 再来个难一点的, 除去空行之外, `nemu/`目录下的所有.c和.h文件总共有多少行代码?

```shell
#!/usr/bin/env bash

files_pa0=$(git ls-tree -r --name-only pa0 src | grep '\.[ch]$')
lines1=0
for file in $files_pa0;
do
    file_lines1=$(git show pa0:nemu/$file | tr -s '\n' | wc -l)
    lines1=$((file_lines1+lines1))
done
lines2=$(find ./src -name "*.[ch]" | xargs cat | tr -s '\n' | wc -l)

echo "相比pa0多了$((lines2-lines1))行"
```

# 4.RTFM
打开`nemu/scripters/build.mk`文件, 你会在`CFLAGS`变量中看到gcc的一些编译选项. 请解释gcc中的`-Wall`和`-Werror`有什么作用? 为什么要使用`-Wall`和`-Werror`?

`-Wall`作用：开启大部分常用的警告，比如未使用变量、类型不匹配等。可以提前发现代码中的潜在 bug，提高代码质量。

`-Werror`作用：把所有警告当作错误处理。可以防止带有警告的代码进入最终成品。

