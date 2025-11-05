package AXI4

import chisel3._
import chisel3.util._

import freechips.rocketchip.amba.axi4._

class ysyx_23060246_AXIXbar(val OutNum: Int, val AddressMap: Array[(Long, Long)], param : AXI4BundleParameters ) extends Module {
  val io = IO(new Bundle {
    // single input 
    val in = Flipped(new AXI4Bundle(param))
    // multiple output
    val out = Vec(OutNum, (new AXI4Bundle(param)))
  })

  
  val state_r = RegInit(OutNum.U(log2Ceil(OutNum+1).W)) 
  val state_w = RegInit(OutNum.U(log2Ceil(OutNum+1).W)) 

  val state_r_idle = OutNum.U
  val state_w_idle = OutNum.U

  // read state 
  state_r := MuxLookup(state_r, OutNum.U)(
    (0 until OutNum).map(i => {
      i.U(log2Ceil(OutNum+1).W) -> Mux(io.in.r.ready && io.out(i).r.valid && io.out(i).r.bits.last, state_r_idle, i.U(log2Ceil(OutNum+1).W))
    }) :+ (state_r_idle -> Mux(io.in.ar.valid, RangeLookup(io.in.ar.bits.addr, state_r_idle,
      AddressMap.map { case (start, end) =>
        (start.U(param.addrBits.W), end.U(param.addrBits.W), AddressMap.indexOf((start, end)).U)
      }.toIndexedSeq
    ), state_r_idle)))

  // write state 
  state_w := MuxLookup(state_w, OutNum.U)(
    (0 until OutNum).map(i => {
      i.U(log2Ceil(OutNum+1).W) -> Mux(io.in.b.ready && io.out(i).b.valid && io.out(i).w.bits.last , state_w_idle, i.U(log2Ceil(OutNum+1).W))
    }) :+ (state_w_idle -> Mux(io.in.aw.valid, RangeLookup(io.in.aw.bits.addr, state_w_idle,
      AddressMap.map { case (start, end) =>
        (start.U(param.addrBits.W), end.U(param.addrBits.W), AddressMap.indexOf((start, end)).U)
      }.toIndexedSeq
    ), state_w_idle)))


  for (i <- 0 until OutNum) {
    io.out(i).ar.valid := state_r === i.U(log2Ceil(OutNum+1).W) && io.in.ar.valid
    io.out(i).ar.bits := io.in.ar.bits
    
    
    io.out(i).aw.valid := state_w === i.U(log2Ceil(OutNum+1).W) && io.in.aw.valid
    io.out(i).aw.bits := io.in.aw.bits

    io.out(i).w.valid := state_w === i.U(log2Ceil(OutNum+1).W) && io.in.w.valid
    io.out(i).w.bits := io.in.w.bits

    io.out(i).r.ready := state_r === i.U(log2Ceil(OutNum+1).W) && io.in.r.ready
    io.out(i).b.ready := state_w === i.U(log2Ceil(OutNum+1).W) && io.in.b.ready
  }

  // slave to master
  io.in.ar.ready := Mux(state_r === state_r_idle, false.B, io.out(state_r).ar.ready)
  io.in.r.bits.data := Mux(state_r === state_r_idle, 0.U, io.out(state_r).r.bits.data)
  io.in.r.bits.resp := Mux(state_r === state_r_idle, 0.U, io.out(state_r).r.bits.resp)
  io.in.r.bits.id   := Mux(state_r === state_r_idle, 0.U, io.out(state_r).r.bits.id)
  io.in.r.bits.last   := Mux(state_r === state_r_idle, 0.U, io.out(state_r).r.bits.last)
  io.in.r.valid := Mux(state_r === state_r_idle, false.B, io.out(state_r).r.valid)

  io.in.aw.ready := Mux(state_w === state_w_idle, false.B, io.out(state_w).aw.ready)
  io.in.w.ready := Mux(state_w === state_w_idle, false.B, io.out(state_w).w.ready)
  io.in.b.bits.resp := Mux(state_w === state_w_idle, 0.U, io.out(state_w).b.bits.resp)
  io.in.b.bits.id   := Mux(state_w === state_w_idle, 0.U, io.out(state_w).b.bits.id)
  io.in.b.valid := Mux(state_w === state_w_idle, false.B, io.out(state_w).b.valid)
}

// object RangeLookup {
//   def apply[S <: UInt, T <: Data](key: S, default: T, mapping: Seq[(S, S, T)]): T = {
//     mapping.foldLeft(default) { case (d, (ks, ke, v)) =>
//       Mux(key >= ks && key <= ke, v, d)
//     }
//   }
// }
