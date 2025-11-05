#/usr/bin/bash

# Usage ./perf.sh $NPC_TOPNAME $CLK_FREQ_MHZ

if [ $# -eq 2 ]; then
    NPC_TOPNAME=$1;
    CLK_FREQ_MHZ=$2;
else
    echo -e "\e[1;31mERROR:\e[0m";
    echo "Usage ./perf.sh \$NPC_TOPNAME \$CLK_FREQ_MHZ";
    exit;
fi


echo
echo -e "\e[1;34m Performance Counter: \e[0m"
cat ${NPC_HOME}/build/perf_statistic.txt
echo
echo -e "\e[1;34m Area Report: \e[0m"
area=$(cat ${YOSYSSTA_PATH}/result/${NPC_TOPNAME}-${CLK_FREQ_MHZ}MHz/yosys.log | grep "Chip area for top module")
if [ -z "$area" ]; then
area=$(cat ${YOSYSSTA_PATH}/result/${NPC_TOPNAME}-${CLK_FREQ_MHZ}MHz/yosys.log | grep -F "Chip area for module '\\${NPC_TOPNAME}'")
fi
echo $area
echo
echo -e "\e[1;34m Timing Report(Max Freq): \e[0m "
cat ${YOSYSSTA_PATH}/result/${NPC_TOPNAME}-${CLK_FREQ_MHZ}MHz/${NPC_TOPNAME}.rpt | grep "Freq(MHz)" -A2 -B1
