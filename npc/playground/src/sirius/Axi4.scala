package sirius

import chisel3._
import chisel3.util._
import chisel3.experimental.dataview._

object Axi4Resp {
  val okay: BigInt = 0b00
  val exokay: BigInt = 0b01
  val slverr: BigInt = 0b10
  val decerr: BigInt = 0b11
}

object Axi4Burst {
  val fixed: BigInt = 0b00
  val incr: BigInt = 0b01
  val warp: BigInt = 0b10
}

// class VerilogAxi4LiteIO(val busWidth: Int = 32) extends Bundle {
//   val AWVALID = Output(Bool())
//   val AWREADY = Input(Bool())
//   val AWADDR = Output(UInt(busWidth.W))
//   // val AWPROT
//
//   val WVALID = Output(Bool())
//   val WREADY = Input(Bool())
//   val WDATA = Output(UInt(busWidth.W))
//   val WSTRB = Output(UInt((busWidth >> 3).W))
//
//   val BVALID = Input(Bool())
//   val BREADY = Output(Bool())
//   val BRESP = Input(UInt(2.W))
//
//   val ARVALID = Output(Bool())
//   val ARREADY = Input(Bool())
//   val ARADDR = Output(UInt(busWidth.W))
//   // val ARPROT
//
//   val RVALID = Input(Bool())
//   val RREADY = Output(Bool())
//   val RDATA = Input(UInt(busWidth.W))
//   val RRESP = Input(UInt(2.W))
// }
// object VerilogAxi4LiteIO {
//   implicit val view: DataView[Axi4LiteIO, VerilogAxi4LiteIO] = 
//     Axi4LiteIO.view.invert(axi4LiteIO => new VerilogAxi4LiteIO(axi4LiteIO.busWidth))
// }
//
// class Axi4LiteIO(val busWidth: Int = 32) extends Bundle {
//   val aw = Decoupled(new Bundle {
//     val addr = Output(UInt(busWidth.W))
//     // val prot
//   })
//
//   val w = Decoupled(new Bundle {
//     val data = Output(UInt(busWidth.W))
//     val strb = Output(UInt((busWidth >> 3).W))
//   })
//
//   val b = Flipped(Decoupled(Flipped(new Bundle {
//     val resp = Input(UInt(2.W))
//   })))
//
//   val ar = Decoupled(new Bundle {
//     val addr = Output(UInt(busWidth.W))
//     // val prot
//   })
//
//   val r = Flipped(Decoupled(Flipped(new Bundle {
//     val data = Input(UInt(busWidth.W))
//     val resp = Input(UInt(2.W))
//   })))
// }
// object Axi4LiteIO {
//   implicit val view: DataView[VerilogAxi4LiteIO, Axi4LiteIO] = DataView(
//     verilogAxi4LiteIO => new Axi4LiteIO(verilogAxi4LiteIO.busWidth),
//     _.AWVALID -> _.aw.valid,
//     _.AWREADY -> _.aw.ready,
//     _.AWADDR -> _.aw.bits.addr,
//     // _.AWPROT -> aw.bits.port,
//
//     _.WVALID -> _.w.valid,
//     _.WREADY -> _.w.ready,
//     _.WDATA -> _.w.bits.data,
//     _.WSTRB -> _.w.bits.strb,
//
//     _.BVALID -> _.b.valid,
//     _.BREADY -> _.b.ready,
//     _.BRESP -> _.b.bits.resp,
//
//     _.ARVALID -> _.ar.valid,
//     _.ARREADY -> _.ar.ready,
//     _.ARADDR -> _.ar.bits.addr,
//     // _.ARPROT -> _.ar.bits.prot,
//
//     _.RVALID -> _.r.valid,
//     _.RREADY -> _.r.ready,
//     _.RDATA -> _.r.bits.data,
//     _.RRESP -> _.r.bits.resp
//   )
// }

class Axi4FlatIO(val busWidth: Int = 32) extends Bundle {
  val awready = Input(Bool())
  val awvalid = Output(Bool())
  val awaddr = Output(UInt(busWidth.W))
  val awid = Output(UInt(4.W))
  val awlen = Output(UInt(8.W))
  val awsize = Output(UInt(3.W))
  val awburst = Output(UInt(2.W))
  // val awprot

  val wready = Input(Bool())
  val wvalid = Output(Bool())
  val wdata = Output(UInt(busWidth.W))
  val wstrb = Output(UInt((busWidth >> 3).W))
  val wlast = Output(Bool())

  val bready = Output(Bool())
  val bvalid = Input(Bool())
  val bresp = Input(UInt(2.W))
  val bid = Input(UInt(4.W))

  val arready = Input(Bool())
  val arvalid = Output(Bool())
  val araddr = Output(UInt(busWidth.W))
  val arid = Output(UInt(4.W))
  val arlen = Output(UInt(8.W))
  val arsize = Output(UInt(3.W))
  val arburst = Output(UInt(2.W))
  // val arprot

  val rready = Output(Bool())
  val rvalid = Input(Bool())
  val rresp = Input(UInt(2.W))
  val rdata = Input(UInt(busWidth.W))
  val rlast = Input(Bool())
  val rid = Input(UInt(4.W))
}
object Axi4FlatIO {
  implicit val view: DataView[Axi4IO, Axi4FlatIO] = 
    Axi4IO.view.invert(axi4IO => new Axi4FlatIO(axi4IO.busWidth))
}

class Axi4IO(val busWidth: Int = 32) extends Bundle {
  val aw = Decoupled(new Bundle {
    val addr = Output(UInt(busWidth.W))
    val id = Output(UInt(4.W))
    val len = Output(UInt(8.W))
    val size = Output(UInt(3.W))
    val burst = Output(UInt(2.W))
  // val prot
  })

  val w = Decoupled(new Bundle {
    val data = Output(UInt(busWidth.W))
    val strb = Output(UInt((busWidth >> 3).W))
    val last = Output(Bool())
  })

  val b = Flipped(Decoupled(Flipped(new Bundle {
    val resp = Input(UInt(2.W))
    val id = Input(UInt(4.W))
  })))

  val ar = Decoupled(new Bundle {
    val addr = Output(UInt(busWidth.W))
    val id = Output(UInt(4.W))
    val len = Output(UInt(8.W))
    val size = Output(UInt(3.W))
    val burst = Output(UInt(2.W))
    // val prot
  })

  val r = Flipped(Decoupled(Flipped(new Bundle {
    val resp = Input(UInt(2.W))
    val data = Input(UInt(busWidth.W))
    val last = Input(Bool())
    val id = Input(UInt(4.W))
  })))
}
object Axi4IO {
  implicit val view: DataView[Axi4FlatIO, Axi4IO] = DataView(
    axi4FlatIO => new Axi4IO(axi4FlatIO.busWidth),
    _.awready -> _.aw.ready,
    _.awvalid -> _.aw.valid,
    _.awaddr -> _.aw.bits.addr,
    _.awid -> _.aw.bits.id,
    _.awlen -> _.aw.bits.len,
    _.awsize -> _.aw.bits.size,
    _.awburst -> _.aw.bits.burst,
    // _.awprot -> aw.bits.port,

    _.wready -> _.w.ready,
    _.wvalid -> _.w.valid,
    _.wdata -> _.w.bits.data,
    _.wstrb -> _.w.bits.strb,
    _.wlast -> _.w.bits.last,

    _.bready -> _.b.ready,
    _.bvalid -> _.b.valid,
    _.bresp -> _.b.bits.resp,
    _.bid -> _.b.bits.id,

    _.arready -> _.ar.ready,
    _.arvalid -> _.ar.valid,
    _.araddr -> _.ar.bits.addr,
    _.arid -> _.ar.bits.id,
    _.arlen -> _.ar.bits.len,
    _.arsize -> _.ar.bits.size,
    _.arburst -> _.ar.bits.burst,
    // _.arprot -> _.ar.bits.prot,

    _.rready -> _.r.ready,
    _.rvalid -> _.r.valid,
    _.rresp -> _.r.bits.resp,
    _.rdata -> _.r.bits.data,
    _.rlast -> _.r.bits.last,
    _.rid -> _.r.bits.id
  )
}

