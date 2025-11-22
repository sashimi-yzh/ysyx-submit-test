#!/bin/bash

ECHO_RED="\033[31m"
ECHO_GREEN="\033[32m"
ECHO_YELLOW="\033[33m"
ECHO_NONE="\033[0m"

NPC_HOME=$(pwd)
CPU_TEST_HOME=${NPC_HOME}/../am-kernels/tests/cpu-tests
AM_TEST_HOME=${NPC_HOME}/../am-kernels/tests/am-tests
MICROBENCH_HOME=${NPC_HOME}/../am-kernels/benchmarks/microbench
RISCV_TEST_HOME=${NPC_HOME}/../am-kernels/tests/riscv-tests-am-master

CPU_TIMEOUT_SEC=120
PASS_CNT=0
FAIL_CNT=0

NVBOARD_ENABLE=0
DCACHE_ENABLE=0

test_catcher() {
    while IFS= read -r line; do
        if [[ -z "${CURRENT_TEST}" && $line =~ ${TEST_NAME_PATTERN} ]]; then
            CURRENT_TEST="${BASH_REMATCH[1]}"
            printf "TEST: [%'-15s] " "${CURRENT_TEST}"
        fi
        if [[ $line =~ ${TRAP_PATTERN} ]]; then
            TRAP_TYPE="${BASH_REMATCH[1]}"
            if [ "${TRAP_TYPE}" = "GOOD" ]; then
                echo -e "${ECHO_GREEN} PASS ${ECHO_NONE}"
                ((PASS_CNT++))
            else
                echo -e "${ECHO_RED} **FAIL** ${ECHO_NONE}"
                ((FAIL_CNT++))
            fi
            CURRENT_TEST="" # 重置当前测试名，支持多测试程序连续运行
        fi
    done
}

if [ $# -eq 0 ]; then
    echo -e "${ECHO_RED}❌ Warning! No parameters set. Enter 'help' for help${ECHO_NONE}"
    exit 1
fi

#检查架构（后续加入单周期，nemu等）
ARCH="$1"
case "$ARCH" in
    riscv32e-ysyxsoc)
        echo -e "Running Arch ${ECHO_GREEN}[$ARCH]${ECHO_NONE} For test ..."
        # echo -e "Default [nvboard] ${ECHO_RED}close${ECHO_NONE} and [dcache] ${ECHO_RED}close${ECHO_NONE}" #后续修改，可以根据传入参数进行变动（help
        shift 1 #移除第一个参数arch
        for arg in "$@"; do
            case "$arg" in
                nvboard)
                    NVBOARD_ENABLE=1
                    ;;
                dcache)
                    DCACHE_ENABLE=1
                    ;;
                *)
                    echo -e "${ECHO_YELLOW}Warning! Unknown argument: [$arg]. Ignore.${ECHO_NONE}"
                    ;;
            esac
        done
        echo -e "Set [nvboard] to ${NVBOARD_ENABLE}, [dcache] to ${DCACHE_ENABLE}"
        ;;
    riscv32e-npc)
        echo -e "Running Arch ${ECHO_GREEN}[$ARCH]${ECHO_NONE} For test ..."
        ;;
    help)
        echo -e "\n============== AUTO TEST RUN =============="
        echo -e "It can be tested automatically with one click, and then"
        echo -e "collect relevant error information to improve the testing efficiency."
        echo -e "\nFor example, enter './run_test.sh riscv32e-ysyxsoc nvboard dcache'(function nvboard and dcache only for ysyxsoc). "
        echo -e "This means enabling the 'nvboard' and 'dcache' args on arch 'riscv32e-ysyxsoc'"
        echo -e "Otherwise, it will be set to default and off."
        echo -e "===========================================\n"
        exit 1
        ;;
    *)
        echo -e "Currently do not supported ARCH: ${ECHO_RED}[$ARCH]${ECHO_NONE} "
        echo "Supported ARCH: riscv32e-npc, riscv32e-ysyxsoc ..."
        exit 1
        ;;
esac
ARGS="nvboard=${NVBOARD_ENABLE} dcache=${DCACHE_ENABLE}"

#进入cpu-test运行
cd ${CPU_TEST_HOME} || {
            echo -e "${ECHO_RED}❌ Failed to switch directories CPU_TEST_HOME! The directory does not exist: ${CPU_TEST_HOME}${ECHO_NONE}"
            exit 1
        }

TEST_NAME_PATTERN="^# Building ([a-zA-Z0-9_-]+)-run "
TRAP_PATTERN="HIT (GOOD|BAD) TRAP"

echo -e "\n${ECHO_YELLOW}Running CPU-TEST (only show the result)...${ECHO_NONE}"
echo -e "${ECHO_YELLOW}Timeout: ${CPU_TIMEOUT_SEC}s (no output will interrupt test)${ECHO_NONE}" #TIMEOUT退出机制TODO
echo -e "${ECHO_YELLOW}--------------------------------------------------${ECHO_NONE}"

#一键回归性测试
make ARCH=${ARCH} -C ${CPU_TEST_HOME} run  ${ARGS}2>&1 | \
test_catcher

echo -e "${ECHO_YELLOW}--------------------------------------------------${ECHO_NONE}"
if [ ${FAIL_CNT} -eq 0 ]; then
    echo "All the cpu-test pass successfully!"
else
    # echo -e "${FAIL_CNT} tests Failed, check your code!"
    echo -e "Arch: ${ARCH}"
    echo -e "Args: ${ARGS}"
    echo -e "Pass: ${ECHO_GREEN}${PASS_CNT}${ECHO_NONE}"
    echo -e "Fail: ${ECHO_RED}${FAIL_CNT}${ECHO_NONE}. Check your code!"
    exit 1
fi

#进入riscv-test运行
cd ${RISCV_TEST_HOME} || {
            echo -e "${ECHO_RED}❌ Failed to switch directories RISCV_TEST_HOME! The directory does not exist: ${RISCV_TEST_HOME}${ECHO_NONE}"
            echo -e "Try to clone riscv-tests-am-master into am-kernels/tests/"
            cd ${NPC_HOME}/am-kernels/tests/
            git clone https://github.com/NJU-ProjectN/riscv-tests-am
            cd ${RISCV_TEST_HOME} || exit 1
        }
echo -e "\n${ECHO_YELLOW}Running RISCV-TEST (only show the result)...${ECHO_NONE}"
echo -e "${ECHO_YELLOW}Timeout: ${CPU_TIMEOUT_SEC}s (no output will interrupt test)${ECHO_NONE}" #TIMEOUT退出机制TODO
echo -e "${ECHO_YELLOW}--------------------------------------------------${ECHO_NONE}"

#一键回归性测试
make ARCH=${ARCH} -C ${RISCV_TEST_HOME} run  ${ARGS}2>&1 | \
test_catcher

echo -e "${ECHO_YELLOW}--------------------------------------------------${ECHO_NONE}"
if [ ${FAIL_CNT} -eq 0 ]; then
    echo "All the riscv-test pass successfully!"
else
    echo -e "Arch: ${ARCH}"
    echo -e "Args: ${ARGS}"
    echo -e "Pass: ${ECHO_GREEN}${PASS_CNT}${ECHO_NONE}"
    echo -e "Fail: ${ECHO_RED}${FAIL_CNT}${ECHO_NONE}"
fi
