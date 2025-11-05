#!/bin/env bash

TOPNAME=$1
FREQ=$2

REMOTE_DIR="${GZIC_SERVER_USER}@${GZIC_SERVER_IP}:${GZIC_SERVER_USER_HOME}/PROJECT/npc"

rsync -av ./* "$REMOTE_DIR"\
    --exclude='build' --exclude='wave*' --exclude='target' --exclude='rocket-chip' \
    --exclude='test_run_dir' --exclude='out'
scp ./build/verilog/*.sv "$REMOTE_DIR/build/verilog"
scp ../ysyxSoC/build/*.v "$REMOTE_DIR/build/verilog"
rsync -av ../ysyxSoC/perip  "$REMOTE_DIR/build/perip"


rsync -av "$YOSYSSTA_PATH/nangate45/sim/cells.v" "$REMOTE_DIR/build/nangate45/"
rsync -av "$YOSYSSTA_PATH/result/${TOPNAME}-${FREQ}MHz" "$REMOTE_DIR/build/netlist/"
