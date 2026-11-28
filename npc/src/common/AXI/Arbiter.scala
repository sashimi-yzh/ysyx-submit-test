package npc.AXI
import chisel3._
import chisel3.util._
import npc.AXI.AXI4Bundle
import npc.PMU._
import chisel3.{UIntIntf => readBusy}

class ysyx_26030092_AXI4Arbiter(n_in : Int) extends Module{
    val master = IO(Vec(n_in, Flipped(new AXI4Bundle)))
    val slave = IO(new AXI4Bundle)

    for(i <- 0 until n_in){
        master(i).initSlave()
    }
    slave.initMaster()

    when(master(0).arvalid){
        slave.connectARFrom(master(0), true.B)
        slave.arid := 0.U
    }.elsewhen(master(1).arvalid){
        slave.connectARFrom(master(1), true.B)
        slave.arid := 1.U
    }

    for(i <- 0 until n_in){
        master(i).rvalid := slave.rvalid && (slave.rid === i.U)
        master(i).rid    := slave.rid
        master(i).rdata  := slave.rdata
        master(i).rresp  := slave.rresp
        master(i).rlast  := slave.rlast
        dontTouch(master(i).rready)
    }
    slave.rready := master(slave.rid).rready

    slave.connectAWFrom(master(1), true.B)
    slave.connectWFrom(master(1), true.B)
    slave.connectBFrom(master(1), true.B)
}
