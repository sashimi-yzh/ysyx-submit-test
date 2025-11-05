package AXI4 
import chisel3._
import chisel3.util._

class AXIBundle(addrWidthBits: Int, dataWidthBits: Int) extends Bundle{
  val awaddr = Output(UInt(addrWidthBits.W))
  val awvalid = Output(Bool())
  val awready = Input(Bool())
  val awid = Output(UInt(4.W))
  val awlen = Output(UInt(8.W))
  val awsize = Output(UInt(3.W))
  val awburst = Output(UInt(2.W))
  // val awlock = Output(Bool())
  // val awcache = Output(UInt(4.W))
  // val awprot = Output(UInt(3.W))
  // val awqos = Output(UInt(4.W))

  val wready = Input(Bool())
  val wvalid = Output(Bool())
  val wdata = Output(UInt(dataWidthBits.W))
  val wstrb = Output(UInt(4.W))
  val wlast = Output(Bool())

  val bready = Output(Bool())
  val bvalid = Input(Bool())
  val bresp = Input(UInt(2.W))
  val bid =  Input(UInt(4.W))

  val arready = Input(Bool())
  val arvalid = Output(Bool())
  val araddr = Output(UInt(addrWidthBits.W))
  val arid = Output(UInt(4.W))
  val arlen = Output(UInt(8.W))
  val arsize = Output(UInt(3.W))
  val arburst = Output(UInt(2.W))
  // val arlock = Output(Bool())
  // val arcache = Output(UInt(4.W))
  // val arprot = Output(UInt(3.W))
  // val arqos = Output(UInt(4.W))

  val rready = Output(Bool())
  val rvalid = Input(Bool())
  val rresp = Input(UInt(2.W))
  val rdata = Input(UInt(dataWidthBits.W))
  val rlast = Input(Bool())
  val rid = Input(UInt(4.W))
}