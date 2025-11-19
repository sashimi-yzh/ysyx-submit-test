package npc.core

import chisel3._
import chisel3.util._
import npc.common.Config._
import npc.common._
import npc.common.Instructions._

import npc.core._
import npc.core.ifu._
import npc.core.idu._
import npc.core.isu._
import npc.core.exu._
import npc.core.wbu._
import npc.perip._
import npc.bus.axi._
import npc.core.icache._

class CoreIO extends Bundle {
    val imem = Flipped(new AXI4WithoutClk)
    val dmem = Flipped(new AXI4WithoutClk)
}

class Core extends Module {
    val io = IO(new CoreIO)

    val ifu = Module(new IFU)
    val idu = Module(new IDU)
    val isu = Module(new ISU)
    val exu = Module(new EXU)
    val wbu = Module(new WBU)

/*
             ____ ___ ____  _____ _     ___ _   _ _____
            |  _ \_ _|  _ \| ____| |   |_ _| \ | | ____|
            | |_) | || |_) |  _| | |    | ||  \| |  _|
            |  __/| ||  __/| |___| |___ | || |\  | |___
            |_|  |___|_|   |_____|_____|___|_| \_|_____|
*/
    wbu.io_pipe.out.ready := true.B
    val ready_r = RegNext(ifu.io_pipe.in.ready)

    ifu.io_pipe.in.valid := RegEnable(true.B, false.B, ifu.io_pipe.in.ready & ready_r)

    pipelineConnect(ifu.io_pipe.out, idu.io_pipe.in)
    pipelineConnect(idu.io_pipe.out, isu.io_pipe.in)
    pipelineConnect(isu.io_pipe.out, exu.io_pipe.in)
    pipelineConnect(exu.io_pipe.out, wbu.io_pipe.in)

/*
             ___ __  __ _____ __  __    ___     ___ ____    _    ____ _   _ _____
            |_ _|  \/  | ____|  \/  |  ( _ )   |_ _/ ___|  / \  / ___| | | | ____|
             | || |\/| |  _| | |\/| |  / _ \/\  | | |     / _ \| |   | |_| |  _|
             | || |  | | |___| |  | | | (_>  <  | | |___ / ___ \ |___|  _  | |___
            |___|_|  |_|_____|_|  |_|  \___/\/ |___\____/_/   \_\____|_| |_|_____|
*/
    val icache = Module(new iCache(4, 4, 1))
    /*due to the area limit, icache dosen't realise plru, only support random.
    final icache is 4, 4, 1, so replace policy dosen't matter*/
    io.imem <> icache.io.out
    icache.io.in <> ifu.io.imem
/*
             ____  __  __ _____ __  __
            |  _ \|  \/  | ____|  \/  |
            | | | | |\/| |  _| | |\/| |
            | |_| | |  | | |___| |  | |
            |____/|_|  |_|_____|_|  |_|
*/
    io.dmem <> exu.io.dmem
/*
              ___ _____ _   _ _____ ____
             / _ \_   _| | | | ____|  _ \
            | | | || | | |_| |  _| | |_) |
            | |_| || | |  _  | |___|  _ <
             \___/ |_| |_| |_|_____|_| \_\
*/
    isu.io.gpr_we := wbu.io.gpr_we
    isu.io.gpr_waddr := wbu.io.gpr_waddr
    isu.io.gpr_wdata := wbu.io.gpr_wdata

    ifu.io_bj <> exu.io_bj
    ifu.io_fencei_flush_exu <> exu.io_fencei_flush_exu
    ifu.io_fencei_flush_icache <> icache.io_fencei_flush_icache

    isu.io_for_ex <> exu.io_for
    isu.io_for_wb <> wbu.io_for

    idu.io_flush.flush_flg := ifu.io_flush.flush_flg
    isu.io_flush.flush_flg := ifu.io_flush.flush_flg

    icache.io_fencei <> exu.io_fencei













    def pipelineConnect[T <: Data, T2 <: Data](prevOut: DecoupledIO[T], thisIn: DecoupledIO[T]) = {
        prevOut.ready := thisIn.ready
        thisIn.bits := RegEnable(prevOut.bits, prevOut.valid && thisIn.ready)
        thisIn.valid := RegEnable(prevOut.valid, false.B, thisIn.ready);
    }


}
