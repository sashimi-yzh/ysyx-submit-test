package sirius

import chisel3._
import chisel3.util._

class Iqueue(
  entries32: Int
)(
  implicit private val cfg: CoreConfig)
    extends Module {
  require(entries32 >= 2 && BigInt(entries32).bitCount == 1)
  require((cfg.pcInit & 3) == 0)
  val entries16 = entries32 * 2

  val io = IO(new Bundle {
    val enq = Flipped(DecoupledIO(UInt(32.W)))
    val deq = DecoupledIO(new Bundle {
      val inst = UInt(32.W)
      val isC = Bool()
    })
    val flush = Input(Bool())
    val targetUnalign = Input(Bool())
  })

  val hiReg32 = Reg(Vec(entries32, UInt(16.W)))
  val loReg32 = Reg(Vec(entries32, UInt(16.W)))

  val wPtrReg32 = RegInit(0.U(log2Ceil(entries32).W))
  val rPtrReg16 = RegInit(0.U(log2Ceil(entries16).W))

  val counter16 = RegInit(0.U(log2Ceil(entries16 + 1).W))
  assert(counter16 <= entries16.U)

  val isC = io.deq.bits.inst(1, 0) =/= "b11".U
  val full = counter16 > (entries16 - 2).U
  val empty = (counter16 === 0.U) || ((counter16 === 1.U) && !isC)

  io.enq.ready := !full
  io.deq.valid := !empty

  val rPtr32 = rPtrReg16(rPtrReg16.getWidth - 1, 1)
  val rPtrUnalign = rPtrReg16(0)
  val rPtrHi32 = rPtr32
  val rPtrLo32 = Mux(rPtrUnalign, rPtr32 + 1.U, rPtr32)
  val rHi = hiReg32(rPtrHi32)
  val rLo = loReg32(rPtrLo32)
  val outHi = Mux(rPtrUnalign, rLo, rHi)
  val outLo = Mux(rPtrUnalign, rHi, rLo)
  io.deq.bits.inst := outHi ## outLo
  io.deq.bits.isC := isC

  val targetUnalignReg = RegInit(false.B)

  when(io.enq.fire) {
    hiReg32(wPtrReg32) := io.enq.bits(31, 16)
    loReg32(wPtrReg32) := io.enq.bits(15, 0)
    wPtrReg32 := wPtrReg32 + 1.U
    targetUnalignReg := false.B
  }
  when(io.deq.fire) {
    rPtrReg16 := rPtrReg16 + Mux(isC, 1.U, 2.U)
  }
  when(io.enq.fire || io.deq.fire) {
    counter16 := counter16 +
      Mux(io.enq.fire, Mux(targetUnalignReg, 1.U, 2.U), 0.U) -
      Mux(io.deq.fire, Mux(isC, 1.U, 2.U), 0.U)
  }
  when(io.flush) {
    wPtrReg32 := 0.U
    rPtrReg16 := Mux(io.targetUnalign, 1.U, 0.U)
    counter16 := 0.U
    targetUnalignReg := io.targetUnalign
  }
}
