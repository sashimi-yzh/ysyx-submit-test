# instAnaly

指令统计分析


## 使用方法：
1. 编译

```
make 
```
2. 获取需要用的文件

需要PC trace文件和程序的elf文件
PC trace文件由NEMU或者npc仿真框架生成，目前只支持读取二进制的压缩文件
elf文件需要由`disasm.sh`将其反汇编:
```
bash disasm.sh xxxx.elf
```

3. 运行程序

```
./instAnaly logfilename.gz elfname.disasm > out.csv
```

程序在读取log文件时，每读取10W次从标准错误上打印一行信息，表示程序正在运行中。






