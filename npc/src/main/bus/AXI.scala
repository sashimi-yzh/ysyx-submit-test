package npc.bus.axi

import chisel3._
import chisel3.util._
import npc.common.Config._

class AXI4 extends Bundle{
  //slave
  //clk and rst
  val clk = Input(Clock())
  val rst = Input(Reset())
  //AR
  val araddr = Input(UInt(WORD_LEN.W))
  val arvalid = Input(Bool())
  val arready = Output(Bool())
    val arid = Input(UInt(4.W))
    val arlen = Input(UInt(8.W))
    val arsize = Input(UInt(3.W))
    val arburst = Input(UInt(2.W))
  //R
  val rdata = Output(UInt(WORD_LEN.W))
  val rresp = Output(UInt(2.W))
  val rvalid = Output(Bool())
  val rready = Input(Bool())
    val rlast = Output(Bool())
    val rid = Output(UInt(4.W))
  //AW
  val awaddr = Input(UInt(WORD_LEN.W))
  val awvalid = Input(Bool())
  val awready = Output(Bool())
    val awid = Input(UInt(4.W))
    val awlen = Input(UInt(8.W))
    val awsize = Input(UInt(3.W))
    val awburst = Input(UInt(2.W))
  //W
  val wdata = Input(UInt(WORD_LEN.W))
  val wstrb = Input(UInt(4.W))
  val wvalid = Input(Bool())
  val wready = Output(Bool())
    val wlast = Input(Bool())
  //B
  val bresp = Output(UInt(2.W))
  val bvalid = Output(Bool())
  val bready = Input(Bool())
    val bid = Output(UInt(4.W))
}


class AXI4WithoutClk extends Bundle{
  //slave
  //AR
  val araddr = Input(UInt(WORD_LEN.W))
  val arvalid = Input(Bool())
  val arready = Output(Bool())
    val arid = Input(UInt(4.W))
    val arlen = Input(UInt(8.W))
    val arsize = Input(UInt(3.W))
    val arburst = Input(UInt(2.W))
  //R
  val rdata = Output(UInt(WORD_LEN.W))
  val rresp = Output(UInt(2.W))
  val rvalid = Output(Bool())
  val rready = Input(Bool())
    val rlast = Output(Bool())
    val rid = Output(UInt(4.W))
  //AW
  val awaddr = Input(UInt(WORD_LEN.W))
  val awvalid = Input(Bool())
  val awready = Output(Bool())
    val awid = Input(UInt(4.W))
    val awlen = Input(UInt(8.W))
    val awsize = Input(UInt(3.W))
    val awburst = Input(UInt(2.W))
  //W
  val wdata = Input(UInt(WORD_LEN.W))
  val wstrb = Input(UInt(4.W))
  val wvalid = Input(Bool())
  val wready = Output(Bool())
    val wlast = Input(Bool())
  //B
  val bresp = Output(UInt(2.W))
  val bvalid = Output(Bool())
  val bready = Input(Bool())
    val bid = Output(UInt(4.W))
}


object AXI4Connector {
    def connectAR(slave: AXI4WithoutClk, master: AXI4WithoutClk): Unit = {
        master.araddr   := slave.araddr
        master.arvalid  := slave.arvalid
        master.arid     := slave.arid
        master.arlen    := slave.arlen
        master.arsize   := slave.arsize
        master.arburst  := slave.arburst
        slave.arready   := master.arready
    }
    // Connect Read Data Channel (R)
    def connectR(slave: AXI4WithoutClk, master: AXI4WithoutClk): Unit = {
        slave.rdata    := master.rdata
        slave.rresp    := master.rresp
        slave.rvalid   := master.rvalid
        slave.rlast    := master.rlast
        slave.rid      := master.rid
        master.rready  := slave.rready
    }
    // Connect Write Address Channel (AW)
    def connectAW(slave: AXI4WithoutClk, master: AXI4WithoutClk): Unit = {
        master.awaddr   := slave.awaddr
        master.awvalid  := slave.awvalid
        master.awid     := slave.awid
        master.awlen    := slave.awlen
        master.awsize   := slave.awsize
        master.awburst  := slave.awburst
        slave.awready   := master.awready
    }
    // Connect Write Data Channel (W)
    def connectW(slave: AXI4WithoutClk, master: AXI4WithoutClk): Unit = {
        master.wdata    := slave.wdata
        master.wstrb    := slave.wstrb
        master.wvalid   := slave.wvalid
        master.wlast    := slave.wlast
        slave.wready    := master.wready
    }
    // Connect Write Response Channel (B)
    def connectB(slave: AXI4WithoutClk, master: AXI4WithoutClk): Unit = {
        slave.bresp    := master.bresp
        slave.bvalid   := master.bvalid
        slave.bid      := master.bid
        master.bready  := slave.bready
    }
    // Connect All Channels
    def connectAll(slave: AXI4WithoutClk, master: AXI4WithoutClk): Unit = {
        connectAR(slave, master)
        connectR(slave, master)
        connectAW(slave, master)
        connectW(slave, master)
        connectB(slave, master)
    }
}