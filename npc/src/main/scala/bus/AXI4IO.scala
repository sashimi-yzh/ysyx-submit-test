package top
import chisel3._
import chisel3.util._

class AXI4IO_AW extends Bundle {
  val ready = Input(Bool())
  val valid = Output(Bool())
  val addr  = Output(UInt(32.W))
  val id    = Output(UInt(4.W))
  val len   = Output(UInt(8.W))
  val size  = Output(UInt(3.W))
  val burst = Output(UInt(2.W))
}
class AXI4IO_W extends Bundle {
  val ready  = Input(Bool())
  val valid  = Output(Bool())
  val data   = Output(UInt(32.W))
  val strb   = Output(UInt(4.W))
  val last   = Output(Bool())
}
class AXI4IO_B extends Bundle {
  val ready  = Output(Bool())
  val valid  = Input(Bool())
  val resp   = Input(UInt(2.W))
  val id     = Input(UInt(4.W))
}
class AXI4IO_AR extends Bundle {
  val ready = Input(Bool())
  val valid = Output(Bool())
  val addr  = Output(UInt(32.W))
  val id    = Output(UInt(4.W))
  val len   = Output(UInt(8.W))
  val size  = Output(UInt(3.W))
  val burst = Output(UInt(2.W))
}
class AXI4IO_R extends Bundle {   
  val ready  = Output(Bool())
  val valid  = Input(Bool())
  val resp   = Input(UInt(2.W))
  val data   = Input(UInt(32.W))
  val last   = Input(Bool())
  val id     = Input(UInt(4.W))
}

class AXI4IO extends Bundle {
  val aw = new AXI4IO_AW
  val w  = new AXI4IO_W
  val b  = new AXI4IO_B
  val ar = new AXI4IO_AR
  val r  = new AXI4IO_R
}



class AXI4IOFlat extends Bundle {
  // AW (Write Address) Channel
  val awready = Input(Bool())
  val awvalid = Output(Bool())
  val awaddr  = Output(UInt(32.W))
  val awid    = Output(UInt(4.W))
  val awlen   = Output(UInt(8.W))
  val awsize  = Output(UInt(3.W))
  val awburst = Output(UInt(2.W))

  // W (Write Data) Channel
  val wready  = Input(Bool())
  val wvalid  = Output(Bool())
  val wdata   = Output(UInt(32.W))
  val wstrb   = Output(UInt(4.W))
  val wlast   = Output(Bool())

  // B (Write Response) Channel
  val bready  = Output(Bool())
  val bvalid  = Input(Bool())
  val bresp   = Input(UInt(2.W))
  val bid     = Input(UInt(4.W))

  // AR (Read Address) Channel
  val arready = Input(Bool())
  val arvalid = Output(Bool())
  val araddr  = Output(UInt(32.W))
  val arid    = Output(UInt(4.W))
  val arlen   = Output(UInt(8.W))
  val arsize  = Output(UInt(3.W))
  val arburst = Output(UInt(2.W))

  // R (Read Data) Channel
  val rready  = Output(Bool())
  val rvalid  = Input(Bool())
  val rresp   = Input(UInt(2.W))
  val rdata   = Input(UInt(32.W))
  val rlast   = Input(Bool())
  val rid     = Input(UInt(4.W))
}

object AXI4Bridge {

  def connect(master: AXI4IO, slave: AXI4IOFlat): Unit = {
    // AW (Write Address) Channel
    slave.awvalid   := master.aw.valid
    slave.awaddr    := master.aw.addr
    slave.awid      := master.aw.id
    slave.awlen     := master.aw.len
    slave.awsize    := master.aw.size
    slave.awburst   := master.aw.burst
    master.aw.ready := slave.awready

    // W (Write Data) Channel
    slave.wvalid    := master.w.valid
    slave.wdata     := master.w.data
    slave.wstrb     := master.w.strb
    slave.wlast     := master.w.last
    master.w.ready  := slave.wready

    // B (Write Response) Channel
    master.b.valid  := slave.bvalid
    master.b.resp   := slave.bresp
    master.b.id     := slave.bid
    slave.bready    := master.b.ready

    // AR (Read Address) Channel
    slave.arvalid   := master.ar.valid
    slave.araddr    := master.ar.addr
    slave.arid      := master.ar.id
    slave.arlen     := master.ar.len
    slave.arsize    := master.ar.size
    slave.arburst   := master.ar.burst
    master.ar.ready := slave.arready

    // R (Read Data) Channel
    master.r.valid  := slave.rvalid
    master.r.resp   := slave.rresp
    master.r.data   := slave.rdata
    master.r.last   := slave.rlast
    master.r.id     := slave.rid
    slave.rready    := master.r.ready
  }


  def connect(master: AXI4IOFlat, slave: AXI4IO): Unit = {
    // AW (Write Address) Channel
    slave.aw.valid := master.awvalid
    slave.aw.addr  := master.awaddr
    slave.aw.id    := master.awid
    slave.aw.len   := master.awlen
    slave.aw.size  := master.awsize
    slave.aw.burst := master.awburst
    master.awready := slave.aw.ready

    // W (Write Data) Channel
    slave.w.valid  := master.wvalid
    slave.w.data   := master.wdata
    slave.w.strb   := master.wstrb
    slave.w.last   := master.wlast
    master.wready  := slave.w.ready

    // B (Write Response) Channel
    master.bvalid  := slave.b.valid
    master.bresp   := slave.b.resp
    master.bid     := slave.b.id
    slave.b.ready  := master.bready

    // AR (Read Address) Channel
    slave.ar.valid := master.arvalid
    slave.ar.addr  := master.araddr
    slave.ar.id    := master.arid
    slave.ar.len   := master.arlen
    slave.ar.size  := master.arsize
    slave.ar.burst := master.arburst
    master.arready := slave.ar.ready

    // R (Read Data) Channel
    master.rvalid  := slave.r.valid
    master.rresp   := slave.r.resp
    master.rdata   := slave.r.data
    master.rlast   := slave.r.last
    master.rid     := slave.r.id
    slave.r.ready  := master.rready
  }
}