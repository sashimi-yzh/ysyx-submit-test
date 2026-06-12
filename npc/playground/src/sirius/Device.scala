package sirius

import chisel3._
import chisel3.util._

class UartDevice extends Module {
  val in = IO(Flipped(new Axi4IO))

  0.U.asTypeOf(chiselTypeOf(in.ar)) :>= in.ar
  in.r :<= 0.U.asTypeOf(chiselTypeOf(in.r))
  assert(!in.ar.valid && !in.r.valid)

  val sIdle :: sWaitResp :: Nil = Enum(2)
  val state = RegInit(sIdle)
  state := MuxLookup(state, sIdle)(
    Seq(
      sIdle -> Mux(in.aw.valid && in.w.valid, sWaitResp, sIdle),
      sWaitResp -> Mux(in.b.ready, sIdle, sWaitResp)
    )
  )
  val inputValid = state === sIdle && in.aw.valid && in.w.valid
  in.aw.ready := inputValid
  in.w.ready := inputValid
  in.b.valid := state === sWaitResp
  in.b.bits.resp := 0.U

  when(inputValid) {
    printf("%c", in.w.bits.data(7, 0))
  }
}

class ClintDevice extends Module {
  val in = IO(Flipped(new Axi4IO))

  assert(!in.aw.valid && !in.w.valid)
  when(in.ar.valid) {
    assert(in.ar.bits.len === 0.U)
  }

  0.U.asTypeOf(chiselTypeOf(in)) :>= in
  in.r.bits.last := true.B
  val idReg = RegEnable(in.ar.bits.id, in.ar.fire)
  in.r.bits.id := idReg

  val sIdle :: sMtimeLo :: sMtimeHi :: Nil = Enum(3)
  val state = RegInit(sIdle)
  val nextState = MuxLookup(state, sIdle)(
    Seq(
      sIdle -> Mux(
        in.ar.fire,
        Mux(in.ar.bits.addr(2), sMtimeHi, sMtimeLo),
        sIdle
      ),
      sMtimeLo -> Mux(in.r.fire, sIdle, sMtimeLo),
      sMtimeHi -> Mux(in.r.fire, sIdle, sMtimeHi)
    )
  )
  state := nextState

  in.ar.ready := state === sIdle
  in.r.valid := state =/= sIdle

  // val mtimeReg = RegInit(0.U(64.W))
  // mtimeReg := mtimeReg + 1.U
  // val mtimeLo = mtimeReg(31, 0)
  // val mtimeHi = mtimeReg(63, 32)

  val addResult = Wire(UInt(32.W))
  val switcher = RegInit(false.B)
  switcher := !switcher
  val mtimeLo = RegEnable(addResult, 0.U(32.W), !switcher)
  val mtimeHi = RegEnable(addResult, 0.U(32.W), switcher && mtimeLo.andR)
  addResult := 1.U + Mux(switcher, mtimeHi, mtimeLo)

  in.r.bits.data := MuxLookup(state, mtimeLo)(
    Seq(
      sMtimeLo -> mtimeLo,
      sMtimeHi -> mtimeHi
    )
  )
}
