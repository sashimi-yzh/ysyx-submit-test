package npc.AXI

import chisel3._
import chisel3.util._

class AXI4Bundle extends Bundle {

        val awready = Input(Bool())
        val awvalid = Output(Bool())
        val awaddr  = Output(UInt(32.W))
        val awid    = Output(UInt(4.W))
        val awlen   = Output(UInt(8.W))
        val awsize  = Output(UInt(3.W))
        val awburst = Output(UInt(2.W))

    val wready = Input(Bool())
    val wvalid = Output(Bool())
    val wdata  = Output(UInt(32.W))
    val wstrb  = Output(UInt(4.W))
    val wlast  = Output(Bool())

    val bready = Output(Bool())
    val bvalid = Input(Bool())
    val bresp  = Input(UInt(2.W))
    val bid    = Input(UInt(4.W))

    val arready = Input(Bool())
    val arvalid = Output(Bool())
    val araddr  = Output(UInt(32.W))
    val arid    = Output(UInt(4.W))
    val arlen   = Output(UInt(8.W))
    val arsize  = Output(UInt(3.W))
    val arburst = Output(UInt(2.W))

    val rready = Output(Bool())
    val rvalid = Input(Bool())
    val rresp  = Input(UInt(2.W))
    val rdata  = Input(UInt(32.W))
    val rid    = Input(UInt(4.W))
    val rlast  = Input(Bool())

    def initMaster(): Unit = {

        awvalid := false.B
        awaddr  := 0.U
        awid    := 0.U
        awlen   := 0.U
        awsize  := 0.U
        awburst := 0.U
        wvalid  := false.B
        wdata   := 0.U
        wstrb   := 0.U
        wlast   := false.B
        bready  := false.B
        arvalid := false.B
        araddr  := 0.U
        arid    := 0.U
        arlen   := 0.U
        arsize  := 0.U
        arburst := 0.U
        rready  := false.B
    }
    def initSlave(): Unit = {
        awready := false.B

        wready  := false.B
        bvalid  := false.B
        bresp   := 0.U
        bid     := 0.U

        arready := false.B

        rvalid  := false.B
        rresp   := 0.U
        rdata   := 0.U
        rid     := 0.U
        rlast   := false.B
    }

    def connectARFrom(master: AXI4Bundle, en: Bool): Unit = {
        this.arvalid := master.arvalid && en
        master.arready := this.arready && en
        this.araddr  := Mux(en, master.araddr, 0.U)
        this.arid    := Mux(en, master.arid, 0.U)
        this.arlen   := Mux(en, master.arlen, 0.U)
        this.arsize  := Mux(en, master.arsize, 0.U)
        this.arburst := Mux(en, master.arburst, 0.U)
    }

    def connectAWFrom(master: AXI4Bundle, en: Bool): Unit = {
        this.awvalid := master.awvalid && en
        master.awready := en && this.awready
        this.awaddr  := Mux(en, master.awaddr, 0.U)
        this.awid    := Mux(en, master.awid, 0.U)
        this.awlen   := Mux(en, master.awlen, 0.U)
        this.awsize  := Mux(en, master.awsize, 0.U)
        this.awburst := Mux(en, master.awburst, 0.U)
    }

  def connectWFrom(master: AXI4Bundle, en: Bool): Unit = {
    this.wvalid := master.wvalid && en
    master.wready := en && this.wready
    this.wdata  := Mux(en, master.wdata, 0.U)
    this.wstrb  := Mux(en, master.wstrb, 0.U)
    this.wlast  := Mux(en, master.wlast, false.B)
  }

  def connectBFrom(master: AXI4Bundle, en: Bool): Unit = {
    master.bvalid := this.bvalid && en
    this.bready := en && master.bready
    master.bresp := Mux(en, this.bresp, 0.U)
    master.bid   := Mux(en, this.bid, 0.U)
  }

  def connectRFrom(master: AXI4Bundle, en: Bool): Unit = {
    master.rvalid := this.rvalid && en
    this.rready := en && master.rready
    master.rdata := Mux(en, this.rdata, 0.U)
    master.rresp := Mux(en, this.rresp, 0.U)
    master.rid   := Mux(en, this.rid, 0.U)
    master.rlast := Mux(en, this.rlast, false.B)
  }
}
