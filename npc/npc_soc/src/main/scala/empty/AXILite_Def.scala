package empty

import chisel3._
import chisel3.util._
import chisel3.layer._

object AXIAssertLayer extends Layer(LayerConfig.Inline)

class ReadAddressChannel extends Bundle {
  val araddr = Output(UInt(32.W))
  val arvalid = Output(Bool())
  val arready = Input(Bool())
}
class ReadDataChannel extends Bundle {
  val rdata = Input(UInt(32.W))
  val rresp = Input(UInt(2.W))
  val rvalid = Input(Bool())
  val rready = Output(Bool())
}
class WriteDataChannel extends Bundle {
  val wdata = Output(UInt(32.W))
  val wstrb = Output(UInt(4.W))
  val wvalid = Output(Bool())
  val wready = Input(Bool())
}
class WriteAddressChannel extends Bundle {
  val awaddr = Output(UInt(32.W))
  val awvalid = Output(Bool())
  val awready = Input(Bool())
}
class RespChannel extends Bundle {
  val bresp = Input(UInt(2.W))
  val bvalid = Input(Bool())
  val bready = Output(Bool())
}

class AXI_Lite extends Bundle {
  val ar = new ReadAddressChannel
  val r = new ReadDataChannel
  val aw = new WriteAddressChannel
  val w = new WriteDataChannel
  val b = new RespChannel
}

object set_AXI_zero {
  def apply(axi: AXI_Lite) = {
    axi.ar.araddr := 0.U
    axi.ar.arvalid := 0.U

    axi.r.rready := 0.U

    axi.aw.awaddr := 0.U
    axi.aw.awvalid := 0.U

    axi.w.wdata := 0.U
    axi.w.wvalid := 0.U
    axi.w.wstrb := 0.U

    axi.b.bready := 0.U
  }
}

object set_flipped_AXI_zero {
  def apply(axi: AXI_Lite) = {
    axi.ar.arready := 0.U

    axi.r.rdata := 0.U
    axi.r.rresp := 0.U
    axi.r.rvalid := 0.U

    axi.aw.awready := 0.U

    axi.w.wready := 0.U

    axi.b.bresp := 0.U
    axi.b.bvalid := 0.U
  }
}
