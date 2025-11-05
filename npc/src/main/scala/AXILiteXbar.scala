package AXI4

import chisel3._
import chisel3.util._

class AXILiteXbar(val OutNum: Int, val AddressMap: Array[(Long, Long)], addrWidthBits: Int, dataWidthBits: Int) extends Module {
  val io = IO(new Bundle {
    // 一个 AXI Lite 主设备接口
    val in = new AXILiteSlaveIF(addrWidthBits, dataWidthBits)
    // 多个 AXI Lite 从设备接口
    val out = Vec(OutNum, (new AXILiteMasterIF(addrWidthBits, dataWidthBits)))
  })

  // 状态寄存器，用于控制 AR 和 AW 请求的路由
  val state_r = RegInit(OutNum.U(log2Ceil(OutNum+1).W)) // 读取请求状态
  val state_w = RegInit(OutNum.U(log2Ceil(OutNum+1).W)) // 写入请求状态

  // 空闲状态
  val state_r_idle = OutNum.U
  val state_w_idle = OutNum.U

  // 读取请求的状态转换
  state_r := MuxLookup(state_r, OutNum.U)(
    (0 until OutNum).map(i => {
      i.U(log2Ceil(OutNum+1).W) -> Mux(io.in.r.ready && io.out(i).r.valid, state_r_idle, i.U(log2Ceil(OutNum+1).W))
    }) :+ (state_r_idle -> Mux(io.in.ar.valid, RangeLookup(io.in.ar.bits.addr, state_r_idle,
      AddressMap.map { case (start, end) =>
        (start.U(addrWidthBits.W), end.U(addrWidthBits.W), AddressMap.indexOf((start, end)).U)
      }.toIndexedSeq
    ), state_r_idle)))

  // 写入请求的状态转换
  state_w := MuxLookup(state_w, OutNum.U)(
    (0 until OutNum).map(i => {
      i.U(log2Ceil(OutNum+1).W) -> Mux(io.in.b.ready && io.out(i).b.valid, state_w_idle, i.U(log2Ceil(OutNum+1).W))
    }) :+ (state_w_idle -> Mux(io.in.aw.valid, RangeLookup(io.in.aw.bits.addr, state_w_idle,
      AddressMap.map { case (start, end) =>
        (start.U(addrWidthBits.W), end.U(addrWidthBits.W), AddressMap.indexOf((start, end)).U)
      }.toIndexedSeq
    ), state_w_idle)))

  // 路由 AR 和 AW 信号到对应的从设备
  for (i <- 0 until OutNum) {
    io.out(i).ar.bits.addr := io.in.ar.bits.addr
    io.out(i).ar.valid := state_r === i.U(log2Ceil(OutNum+1).W) && io.in.ar.valid
    io.out(i).ar.bits.prot := io.in.ar.bits.prot

    io.out(i).aw.bits.addr := io.in.aw.bits.addr
    io.out(i).aw.valid := state_w === i.U(log2Ceil(OutNum+1).W) && io.in.aw.valid
    io.out(i).aw.bits.prot := io.in.aw.bits.prot

    io.out(i).w.bits.data := io.in.w.bits.data
    io.out(i).w.valid := state_w === i.U(log2Ceil(OutNum+1).W) && io.in.w.valid
    io.out(i).w.bits.strb := io.in.w.bits.strb

    // 从设备的响应
    io.out(i).r.ready := state_r === i.U(log2Ceil(OutNum+1).W) && io.in.r.ready
    io.out(i).b.ready := state_w === i.U(log2Ceil(OutNum+1).W) && io.in.b.ready
  }

  // 将从设备的响应返回给主设备
  io.in.ar.ready := Mux(state_r === state_r_idle, false.B, io.out(state_r).ar.ready)
  io.in.r.bits.data := Mux(state_r === state_r_idle, 0.U, io.out(state_r).r.bits.data)
  io.in.r.bits.resp := Mux(state_r === state_r_idle, 0.U, io.out(state_r).r.bits.resp)
  io.in.r.valid := Mux(state_r === state_r_idle, false.B, io.out(state_r).r.valid)

  io.in.aw.ready := Mux(state_w === state_w_idle, false.B, io.out(state_w).aw.ready)
  io.in.w.ready := Mux(state_w === state_w_idle, false.B, io.out(state_w).w.ready)
  io.in.b.bits := Mux(state_w === state_w_idle, 0.U, io.out(state_w).b.bits)
  io.in.b.valid := Mux(state_w === state_w_idle, false.B, io.out(state_w).b.valid)
}

object RangeLookup {
  def apply[S <: UInt, T <: Data](key: S, default: T, mapping: Seq[(S, S, T)]): T = {
    mapping.foldLeft(default) { case (d, (ks, ke, v)) =>
      Mux(key >= ks && key <= ke, v, d)
    }
  }
}
