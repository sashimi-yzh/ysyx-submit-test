package empty

import chisel3._
import chisel3.util._

class FireSignal extends Bundle {
  val ar_fire = Bool()
  val r_fire = Bool()
  val r_burst_last = Bool()
  val aw_fire = Bool()
  val w_fire = Bool()
  val w_burst_last = Bool()
  val b_fire = Bool()
}

object GenerateFireSignal {
  def apply(axi: AXI): FireSignal = {
    val ret = Wire(new FireSignal)
    ret.ar_fire := axi.ar.valid && axi.ar.ready
    ret.r_fire := axi.r.ready && axi.r.valid
    ret.r_burst_last := axi.r.last && ret.r_fire
    ret.aw_fire := axi.aw.valid && axi.aw.ready
    ret.w_fire := axi.w.valid && axi.w.ready
    ret.w_burst_last := axi.w.last && ret.w_fire
    ret.b_fire := axi.b.ready && axi.b.valid
    return ret
  }
}

class Arbiter_2Master() extends PrefixedModule {
  val IFU_AXI = IO(Flipped(new AXI))
  val LSU_AXI = IO(Flipped(new AXI))
  val OUT_AXI = IO(new AXI)

  set_flipped_AXIfull_zero(IFU_AXI)
  set_flipped_AXIfull_zero(LSU_AXI)
  set_AXIfull_zero(OUT_AXI)

  val out_fire = GenerateFireSignal(OUT_AXI)

  val sIDLE :: sIFU :: sLSU :: Nil = Enum(3)

  val out_ar = RegInit(false.B)
  val out_aw = RegInit(false.B)
  val out_w = RegInit(false.B)

  val ar_owner = RegInit(sIDLE)
  val aw_w_owner = RegInit(sIDLE)

  val bind_to_IFU_ar = ar_owner === sIFU && !out_ar
  val bind_to_LSU_ar = ar_owner === sLSU && !out_ar

  val bind_to_IFU_r = ar_owner === sIFU
  val bind_to_LSU_r = ar_owner === sLSU

  val bind_to_LSU_aw_w = aw_w_owner === sLSU
  val bind_to_LSU_b = aw_w_owner === sLSU

  when(bind_to_IFU_ar) {
    IFU_AXI.ar <> OUT_AXI.ar
  }.elsewhen(bind_to_LSU_ar) {
    LSU_AXI.ar <> OUT_AXI.ar
  }

  when(bind_to_IFU_r) {
    IFU_AXI.r <> OUT_AXI.r
  }.elsewhen(bind_to_LSU_r) {
    LSU_AXI.r <> OUT_AXI.r
  }

  when(bind_to_LSU_aw_w) {
    when(!out_w) {
      LSU_AXI.w <> OUT_AXI.w
    }
    when(!out_aw) {
      LSU_AXI.aw <> OUT_AXI.aw
    }
  }

  when(bind_to_LSU_b) {
    LSU_AXI.b <> OUT_AXI.b
  }

  val read_req_owner = Mux(
    LSU_AXI.ar.valid,
    sLSU,
    Mux(IFU_AXI.ar.valid, sIFU, sIDLE)
  )

  val read_done = out_fire.r_burst_last

  val read_cancel =
    !out_ar &&
      ((ar_owner === sIFU && !IFU_AXI.ar.valid) ||
        (ar_owner === sLSU && !LSU_AXI.ar.valid))

  ar_owner := MuxLookup(ar_owner, sIDLE)(
    Seq(
      sIDLE -> read_req_owner,
      sIFU -> Mux(read_done || read_cancel, sIDLE, sIFU),
      sLSU -> Mux(read_done || read_cancel, sIDLE, sLSU)
    )
  )

  out_ar := MuxCase(
    out_ar,
    Seq(
      read_done -> false.B,
      read_cancel -> false.B,
      out_fire.ar_fire -> true.B
    )
  )

  val write_req = LSU_AXI.aw.valid || LSU_AXI.w.valid
  val write_done = out_fire.b_fire

  val write_cancel =
    aw_w_owner === sLSU &&
      !out_aw &&
      !out_w &&
      !LSU_AXI.aw.valid &&
      !LSU_AXI.w.valid

  aw_w_owner := MuxLookup(aw_w_owner, sIDLE)(
    Seq(
      sIDLE -> Mux(write_req, sLSU, sIDLE),
      sLSU -> Mux(write_done || write_cancel, sIDLE, sLSU)
    )
  )

  out_aw := MuxCase(
    out_aw,
    Seq(
      write_done -> false.B,
      write_cancel -> false.B,
      out_fire.aw_fire -> true.B
    )
  )

  out_w := MuxCase(
    out_w,
    Seq(
      write_done -> false.B,
      write_cancel -> false.B,
      out_fire.w_burst_last -> true.B
    )
  )
}
