06.22
IPC： 0.078267
06.23
STA：仅对核心分析，最大频率为453Mhz
06.25
实现简易icache，
|容量|ipc|if耗时|lsu读耗时|lsu写耗时|if占比|lsu读占比|lsu写占比
|---|---|---|---|---|---|---|---|
|无|0.032|24.36|33.84|17.50|79.38%|12.27%|5.65%|
|8×4B|0.04524|15.66|33.63|15.31|72.16%|17.22%|6.97%|
|16×4B|0.05227|12.92|31.91|14.88|68.77%|19.06%|7.79%|
|32×4B|0.06994|8.43|30.50|14.00|59.98%|24.38%|9.81%|
|64×4B|0.095|4.9|28|13.7|47%|31%|12%|
|128×4B|0.11719|3.08|26.82|13.07|36.64%|37.15%|15.04%|

| 字段 | 06.23 |06.28|
|---|---|---|---|
| Commit | 9f7beb67b960fe3ccea0320d0384dabfa03f93d9 |65d8caa30df45beb68622bddfd36f31ca2c3211e|e2dd12380945af19311a98f75c6d42de5050d651|
| 说明 | 多周期，优化前；延迟校准取r=4.5 |多周期，加入icache；这次换成了nangate45；icache规格：总容量128B，block大小16B，每组2相联|实现初级流水线；这次使用-flatten综合|
| 仿真周期数 | 32111897 |20246528|
| 指令数 | 605646 |619149|
| IPC | 0.02 |0.0699|0.0351|
| 综合频率 | 439.21Mhz |526.9Mhz|1066Mhz|
| 综合面积 | - |20917um^2|20883um^2|
| IF延迟 | 23.13 |8.45(命中4，没命中50.5)|
| LSU读延迟 | 33.84 |19.09|
| LSU写延迟 | 17.50 |9.90|
|等待周期占比|-|if:59.96%;lsuR:15.53%;lsuW:6.82%|
|mi耗时|-|-|11.824 ms|





>>> pc= 0x300001b0  总周期=3752591593  总指令=195612913    ipc=0.0521

=================================================================================================================
                                         Performance Latency Analysis
                                         [Mode: EXCLUDING (>100 cycles) Flash Data]
=================================================================================================================

--- Bus Transaction Latency ---
Instruction Fetch (IF) :  15.09 cycles/req (Total Count: 195612851)
  -> IF Cache Hit Rate :  62.25% (Hit: 121775702, Miss: 73837149)
  -> Avg Hit Latency   :   4.00 cycles/req
  -> Avg Miss Latency  :  33.39 cycles/req
LSU Read Latency       :  20.00 cycles/req (Total Count: 15834799)
LSU Write Latency      :  10.00 cycles/req (Total Count: 7268362)

--- Cycles to Next Fetch by Inst ---          ||  --- Overall Cycle Breakdown (Total = 100%) ---
R-Type    :  20.47 cycles (Count: 26218941)   ||  Category             | Cycles & Percentage           
I-Type    :  11.86 cycles (Count: 87848409)   ||  ---------------------|-----------------------------------
Load      :  66.98 cycles (Count: 15404822)   ||  Total Target Cycles  | 3678086071 cycles
Store     :  52.99 cycles (Count: 7143740)    ||  Active Cycles (Work) |   9.13% (335968026 cycles)
U-Type    :  42.83 cycles (Count: 1843737)    ||  Wait for IF   (Read) |  80.28% (2952760977 cycles)
B-Type    :   9.02 cycles (Count: 52509809)   ||  Wait for LSU  (Read) |   8.61% (316680395 cycles)
J-Type    :  33.52 cycles (Count: 4079418)    ||  Wait for LSU (Write) |   1.98% (72676673 cycles)
CSR       :  30.21 cycles (Count:     68)     ||  ---------------------|-----------------------------------
                                              ||  Sum of Percentages   | 100.00%
                                              ||  IPC (Insts/Cycle)    | 0.05303

=================================================================================================================


多周期，527Mhz 表第二列
>>> pc= 0x300001b0  总周期=2112491720  总指令=195607500    ipc=0.0926
MicroBench PASS
Scored time: 3377.486 ms
Total  time: 3988.928 ms
=================================================================================================================
                                         Performance Latency Analysis
                                         [Mode: EXCLUDING (>100 cycles) Flash Data]
=================================================================================================================

--- Bus Transaction Latency ---
Instruction Fetch (IF) :   6.62 cycles/req (Total Count: 195607479)
  -> IF Cache Hit Rate :  94.80% (Hit: 185429814, Miss: 10177665)
  -> Avg Hit Latency   :   4.00 cycles/req
  -> Avg Miss Latency  :  54.31 cycles/req
LSU Read Latency       :  23.00 cycles/req (Total Count: 15837965)
LSU Write Latency      :  11.87 cycles/req (Total Count: 7268103)

--- Cycles to Next Fetch by Inst ---          ||  --- Overall Cycle Breakdown (Total = 100%) ---
R-Type    :   7.72 cycles (Count: 26214141)   ||  Category             | Cycles & Percentage           
I-Type    :   5.92 cycles (Count: 87845416)   ||  ---------------------|-----------------------------------
Load      :  48.99 cycles (Count: 15837965)   ||  Total Target Cycles  | 2099008659 cycles
Store     :  32.53 cycles (Count: 7268101)    ||  Active Cycles (Work) |  16.87% (354036492 cycles)
U-Type    :  22.73 cycles (Count: 1843751)    ||  Wait for IF   (Read) |  61.67% (1294464093 cycles)
B-Type    :   4.98 cycles (Count: 52509499)   ||  Wait for LSU  (Read) |  17.35% (364228620 cycles)
J-Type    :  14.86 cycles (Count: 4079205)    ||  Wait for LSU (Write) |   4.11% (86279454 cycles)
CSR       :  19.54 cycles (Count:     70)     ||  ---------------------|-----------------------------------
                                              ||  Sum of Percentages   | 100.00%
                                              ||  IPC (Insts/Cycle)    | 0.09319

=================================================================================================================



多周期，990Mhz
MicroBench PASS
Scored time: 3310.088 ms
Total  time: 3912.931 ms
Total  cycles: 0
>>> HIT GOOD TRAP!
>>> pc= 0x300001b0  总周期=3880984357  总指令=195598709    ipc=0.0504

=================================================================================================================
                                         Performance Latency Analysis
                                         [Mode: EXCLUDING (>100 cycles) Flash Data]
=================================================================================================================

--- Bus Transaction Latency ---
Instruction Fetch (IF) :   9.10 cycles/req (Total Count: 195598688)
  -> IF Cache Hit Rate :  94.80% (Hit: 185421053, Miss: 10177635)
  -> Avg Hit Latency   :   4.00 cycles/req
  -> Avg Miss Latency  : 102.05 cycles/req
LSU Read Latency       :  41.15 cycles/req (Total Count: 15835071)
LSU Write Latency      :  20.72 cycles/req (Total Count: 7268095)

--- Cycles to Next Fetch by Inst ---          ||  --- Overall Cycle Breakdown (Total = 100%) ---
R-Type    :  14.30 cycles (Count: 26214156)   ||  Category             | Cycles & Percentage           
I-Type    :  10.74 cycles (Count: 87842454)   ||  ---------------------|-----------------------------------
Load      :  90.56 cycles (Count: 15828424)   ||  Total Target Cycles  | 3853491255 cycles
Store     :  60.36 cycles (Count: 7267838)    ||  Active Cycles (Work) |  32.98% (1270948222 cycles)
U-Type    :  42.75 cycles (Count: 1843751)    ||  Wait for IF   (Read) |  46.20% (1780298204 cycles)
B-Type    :   8.96 cycles (Count: 52506567)   ||  Wait for LSU  (Read) |  16.91% (651622587 cycles)
J-Type    :  27.90 cycles (Count: 4079195)    ||  Wait for LSU (Write) |   3.91% (150622242 cycles)
CSR       :  39.00 cycles (Count:     70)     ||  ---------------------|-----------------------------------
                                              ||  Sum of Percentages   | 100.00%
                                              ||  IPC (Insts/Cycle)    | 0.05075

=================================================================================================================


流水线，1.066Ghz 表第三列  20883um^2
MicroBench PASS
Scored time: 2749.227 ms
Total  time: 3336.144 ms
Total  cycles: 0
>>> HIT GOOD TRAP!
>>> pc= 0x300001b0  总周期=3362843597  总指令=195602934    ipc=0.0582

==========================================================================================
                                CPU PERFORMANCE DASHBOARD                               
==========================================================================================
[ Global Metrics ]                 [ Pipeline Flush ]                 [ Stall Ratios ]
Active Cycles    : 3336727259      Pre-pipe Flushes : 54857589        IFU Stall %      : 42.09%
Total Commits    : 195546615       Pipeline Flushes : 41480607        LSU Stall %      : 61.88%
Avg IPC          : 0.0586          Total Flushes    : 96338196        RAW Stall %      : 13.80%
Commit Active %  : 5.86%           Total Flush Rate : 33.01%          
------------------------------------------------------------------------------------------
[ Instruction Fetch (IF) ]                      [ Load/Store Unit (LSU) ]
Fetch Attempts   : 291884811                    LSU Read Avg     : 40.99 cyc
Fetch Miss %     : 4.43%                        LSU Write Avg    : 20.00 cyc
Fetch Hit %      : 95.57%                       
Avg Bus Latency  : 67.88 cyc                    
IF Bus Total Cycles: 877506780                  LSU Read Bus Cycles: 649209647
IF Bus Requests  : 12927217                     LSU Read Requests: 15836679
                                                LSU Write Bus Cycles: 145166480
                                                LSU Write Requests: 7258688
------------------------------------------------------------------------------------------
[ Instruction Distribution ]
Type                Count                    Ratio (%)
R-Type              26213950                 13.41
I-Type              87815687                 44.91
L-Type              15836679                 8.10
S-Type              7258688                  3.71
U-Type              1843732                  0.94
B-Type              52498631                 26.85
J-Type              4079178                  2.09
CSR                 70                       0.00
==========================================================================================



流水线，加入raw转发，1.08Ghz, 21602 um^2
MicroBench PASS
Scored time: 2577.432 ms
Total  time: 3146.257 ms
Total  cycles: 0
>>> HIT GOOD TRAP!
>>> pc= 0x300001b0  总周期=3172927046  总指令=195603616    ipc=0.0616

==========================================================================================
                                CPU PERFORMANCE DASHBOARD                               
==========================================================================================
[ Global Metrics ]                 [ Pipeline Flush ]                 [ Stall Ratios ]
Active Cycles    : 3146822813      Pre-pipe Flushes : 55615289        IFU Stall %      : 44.58%
Total Commits    : 195547297       Pipeline Flushes : 41503501        LSU Stall %      : 65.39%
Avg IPC          : 0.0621          Total Flushes    : 97118790        RAW Stall %      : 0.00%
Commit Active %  : 6.21%           Total Flush Rate : 33.18%          
------------------------------------------------------------------------------------------
[ Instruction Fetch (IF) ]                      [ Load/Store Unit (LSU) ]
Fetch Attempts   : 292666087                    LSU Read Avg     : 40.99 cyc
Fetch Miss %     : 4.42%                        LSU Write Avg    : 20.00 cyc
Fetch Hit %      : 95.58%                       
Avg Bus Latency  : 67.87 cyc                    
IF Bus Total Cycles: 877386835                  LSU Read Bus Cycles: 649212845
IF Bus Requests  : 12927217                     LSU Read Requests: 15836925
                                                LSU Write Bus Cycles: 145166480
                                                LSU Write Requests: 7258688
------------------------------------------------------------------------------------------
[ Instruction Distribution ]
Type                Count                    Ratio (%)
R-Type              26213862                 13.41
I-Type              87815949                 44.91
L-Type              15836925                 8.10
S-Type              7258688                  3.71
U-Type              1843732                  0.94
B-Type              52498893                 26.85
J-Type              4079178                  2.09
CSR                 70                       0.00
==========================================================================================

if变为两级
MicroBench PASS
Scored time: 2615.334 ms
Total  time: 3187.272 ms
Total  cycles: 0
>>> HIT GOOD TRAP!
>>> pc= 0x300001b0  总周期=3213957696  总指令=195603847    ipc=0.0609
branchtrace_write_close success

==========================================================================================
                                CPU PERFORMANCE DASHBOARD                               
==========================================================================================
[ Global Metrics ]                 [ Pipeline Flush ]                 [ Stall Ratios ]
Active Cycles    : 3187841489      Pre-pipe Flushes : 0               IFU Stall %      : 2.56%
Total Commits    : 195547529       Pipeline Flushes : 83946403        LSU Stall %      : 64.82%
Avg IPC          : 0.0613          Total Flushes    : 83946403        RAW Stall %      : 1.82%
Commit Active %  : 6.13%           Total Flush Rate : 30.04%          
------------------------------------------------------------------------------------------
[ Instruction Fetch (IF) ]                      [ Load/Store Unit (LSU) ]
Fetch Attempts   : 279493932                    LSU Read Avg     : 40.99 cyc
Fetch Miss %     : 0.00%                        LSU Write Avg    : 20.00 cyc
Fetch Hit %      : 100.00%                      
Avg Bus Latency  : 67.85 cyc                    
IF Bus Total Cycles: 876172982                  LSU Read Bus Cycles: 649212962
IF Bus Requests  : 12913807                     LSU Read Requests: 15836934
                                                LSU Write Bus Cycles: 145166480
                                                LSU Write Requests: 7258688
------------------------------------------------------------------------------------------
[ Instruction Distribution ]
Type                Count                    Ratio (%)
R-Type              26214002                 13.41
I-Type              87815990                 44.91
L-Type              15836934                 8.10
S-Type              7258688                  3.71
U-Type              1843732                  0.94
B-Type              52498934                 26.85
J-Type              4079179                  2.09
CSR                 70                       0.00
==========================================================================================

加入分支预测，btfn
MicroBench PASS
Scored time: 2362.421 ms
Total  time: 2874.936 ms
Total  cycles: 0
>>> HIT GOOD TRAP!
>>> pc= 0x300001b0  总周期=2901583798  总指令=195605975    ipc=0.0674

==========================================================================================
                                CPU PERFORMANCE DASHBOARD                               
==========================================================================================
[ Global Metrics ]                 [ Pipeline Flush ]                 [ Stall Ratios ]
Active Cycles    : 2875503457      Pre-pipe Flushes : 0               IFU Stall %      : 1.90%
Total Commits    : 195549657       Pipeline Flushes : 39968661        LSU Stall %      : 69.31%
Avg IPC          : 0.0680          Total Flushes    : 39968661        RAW Stall %      : 1.93%
Commit Active %  : 6.80%           Total Flush Rate : 16.97%          
------------------------------------------------------------------------------------------
[ Instruction Fetch (IF) ]                      [ Load/Store Unit (LSU) ]
Fetch Attempts   : 235518318                    LSU Read Avg     : 40.99 cyc
Fetch Miss %     : 4.62%                        LSU Write Avg    : 20.00 cyc
Fetch Hit %      : 95.38%                       
Avg Bus Latency  : 67.86 cyc                    
IF Bus Total Cycles: 738071840                  LSU Read Bus Cycles: 649222214
IF Bus Requests  : 10875654                     LSU Read Requests: 15837650
                                                LSU Write Bus Cycles: 145166480
                                                LSU Write Requests: 7258688
------------------------------------------------------------------------------------------
[ Instruction Distribution ]
Type                Count                    Ratio (%)
R-Type              26213908                 13.41
I-Type              87816732                 44.91
L-Type              15837650                 8.10
S-Type              7258688                  3.71
U-Type              1843732                  0.94
B-Type              52499698                 26.85
J-Type              4079179                  2.09
CSR                 70                       0.00
==========================================================================================


2bit，不往btb存j，1160Mhz
MicroBench PASS
Scored time: 2348.149 ms
Total  time: 2838.155 ms
Total  cycles: 0
>>> HIT GOOD TRAP!
>>> pc= 0x300001b0  总周期=2864806601  总指令=195605754    ipc=0.0683

==========================================================================================
                                CPU PERFORMANCE DASHBOARD                               
==========================================================================================
[ Global Metrics ]                 [ Pipeline Flush ]                 [ Stall Ratios ]
Active Cycles    : 2838726260      Pre-pipe Flushes : 0               IFU Stall %      : 1.58%
Total Commits    : 195549436       Pipeline Flushes : 29411655        LSU Stall %      : 69.28%
Avg IPC          : 0.0689          Total Flushes    : 29411655        RAW Stall %      : 1.98%
Commit Active %  : 6.89%           Total Flush Rate : 13.07%          
------------------------------------------------------------------------------------------
[ Instruction Fetch (IF) ]                      [ Load/Store Unit (LSU) ]
Fetch Attempts   : 224961091                    LSU Read Avg     : 40.99 cyc
Fetch Miss %     : 4.86%                        LSU Write Avg    : 20.00 cyc
Fetch Hit %      : 95.14%                       
Avg Bus Latency  : 67.89 cyc                    
IF Bus Total Cycles: 742444443                  LSU Read Bus Cycles: 649221811
IF Bus Requests  : 10935579                     LSU Read Requests: 15837619
                                                LSU Write Bus Cycles: 145166480
                                                LSU Write Requests: 7258688
------------------------------------------------------------------------------------------
[ Instruction Distribution ]
Type                Count                    Ratio (%)
R-Type              26213924                 13.41
I-Type              87816629                 44.91
L-Type              15837619                 8.10
S-Type              7258688                  3.71
U-Type              1843732                  0.94
B-Type              52499595                 26.85
J-Type              4079179                  2.09
CSR                 70                       0.00

[ Branch Prediction ]
Branch Total        52499595                 
Branch Correct      41592611                 
Accuracy (%)        79.22                    
==========================================================================================
make[1]: Leaving directory '/home/hy5un/ysyx-workbench/npc'

2bit ，存j， 1130Mhz
MicroBench PASS
Scored time: 2332.650 ms
Total  time: 2843.296 ms
Total  cycles: 0

[FREQ] time=4420.01s  cycles=2869938025  inst_cnt=195606119  avg_freq=649305.77 Hz
>>> HIT GOOD TRAP!
>>> pc= 0x300001b0  总周期=2869944316  总指令=195606119    ipc=0.0682

==========================================================================================
                                CPU PERFORMANCE DASHBOARD                               
==========================================================================================
[ Global Metrics ]                 [ Pipeline Flush ]                 [ Stall Ratios ]
Active Cycles    : 2843863975      Pre-pipe Flushes : 0               IFU Stall %      : 1.41%
Total Commits    : 195549801       Pipeline Flushes : 26943209        LSU Stall %      : 70.70%
Avg IPC          : 0.0688          Total Flushes    : 26943209        RAW Stall %      : 1.97%
Commit Active %  : 6.88%           Total Flush Rate : 12.11%          
------------------------------------------------------------------------------------------
[ Instruction Fetch (IF) ]                      [ Load/Store Unit (LSU) ]
Fetch Attempts   : 222493010                    LSU Read Avg     : 40.99 cyc
Fetch Miss %     : 4.85%                        LSU Write Avg    : 20.00 cyc
Fetch Hit %      : 95.15%                       
Avg Bus Latency  : 67.87 cyc                    
IF Bus Total Cycles: 732138895                  LSU Read Bus Cycles: 649222425
IF Bus Requests  : 10787764                     LSU Read Requests: 15837649
                                                LSU Write Bus Cycles: 145166640
                                                LSU Write Requests: 7258696
------------------------------------------------------------------------------------------
[ Instruction Distribution ]
Type                Count                    Ratio (%)
R-Type              26213932                 13.41
I-Type              87816798                 44.91
L-Type              15837649                 8.10
S-Type              7258696                  3.71
U-Type              1843732                  0.94
B-Type              52499735                 26.85
J-Type              4079189                  2.09
CSR                 70                       0.00

[ Branch Prediction ]
Branch Total        52499735                 
Branch Correct      42881348                 
Accuracy (%)        81.68                    
==========================================================================================