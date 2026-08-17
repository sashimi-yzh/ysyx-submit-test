package empty

import chisel3._
import chisel3.util._
import chisel3.layer._

class XBar_CLINT() extends PrefixedModule {
  val IN_AXI = IO(Flipped(new AXI))
  val OUT_AXI = IO(new AXI)
  val CLINT_AXI = IO(new AXI)

  set_flipped_AXIfull_zero(IN_AXI)
  set_AXIfull_zero(OUT_AXI)
  set_AXIfull_zero(CLINT_AXI)

  val IN_fire = GenerateFireSignal(IN_AXI)
  val OUT_fire = GenerateFireSignal(OUT_AXI)
  val CLINT_fire = GenerateFireSignal(CLINT_AXI)

  val sel_clint_ar = IN_AXI.ar.addr(31, 16) === 0x0200.U(16.W)

  when(sel_clint_ar) {
    CLINT_AXI.ar <> IN_AXI.ar
  }.otherwise {
    OUT_AXI.ar <> IN_AXI.ar
  }

  val sel_clint_aw = IN_AXI.aw.addr(31, 16) === 0x0200.U(16.W)
  val write_pending = RegInit(false.B)
  val write_to_clint = RegInit(false.B)

  when(!write_pending) {
    when(sel_clint_aw) {
      CLINT_AXI.aw <> IN_AXI.aw
      CLINT_AXI.w <> IN_AXI.w
    }.otherwise {
      OUT_AXI.aw <> IN_AXI.aw
      OUT_AXI.w <> IN_AXI.w
    }
  }.otherwise {
    when(write_to_clint) {
      CLINT_AXI.w <> IN_AXI.w
      CLINT_AXI.b <> IN_AXI.b
    }.otherwise {
      OUT_AXI.w <> IN_AXI.w
      OUT_AXI.b <> IN_AXI.b
    }
  }

  when(IN_fire.aw_fire) {
    write_pending := true.B
    write_to_clint := sel_clint_aw
  }.elsewhen(IN_fire.b_fire) {
    write_pending := false.B
  }

  val sOUT :: sCLINT :: Nil = Enum(2)
  val r_state = RegInit(sOUT)

  r_state := MuxLookup(r_state, sOUT)(
    Seq(
      sOUT -> Mux(CLINT_AXI.r.valid && !OUT_AXI.r.valid, sCLINT, sOUT),
      sCLINT -> Mux(CLINT_fire.r_burst_last, sOUT, sCLINT)
    )
  )

  val should_bind_to_OUT_r = r_state === sOUT

  when(should_bind_to_OUT_r) {
    OUT_AXI.r <> IN_AXI.r
  }.otherwise {
    CLINT_AXI.r <> IN_AXI.r
  }

  val ext_ar_addr_hold = RegInit(0.U(32.W))
  val ext_ar_id_hold = RegInit(0.U(4.W))
  val ext_ar_len_hold = RegInit(0.U(8.W))
  val ext_ar_size_hold = RegInit(0.U(3.W))
  val ext_ar_burst_hold = RegInit(0.U(2.W))
  val ext_ar_pending = RegInit(false.B)

  when(OUT_fire.ar_fire) {
    ext_ar_addr_hold := OUT_AXI.ar.addr
    ext_ar_id_hold := OUT_AXI.ar.id
    ext_ar_len_hold := OUT_AXI.ar.len
    ext_ar_size_hold := OUT_AXI.ar.size
    ext_ar_burst_hold := OUT_AXI.ar.burst
    ext_ar_pending := true.B
  }.elsewhen(OUT_fire.r_burst_last) {
    ext_ar_pending := false.B
  }

  when(ext_ar_pending && !OUT_AXI.ar.valid) {
    OUT_AXI.ar.addr := ext_ar_addr_hold
    OUT_AXI.ar.id := ext_ar_id_hold
    OUT_AXI.ar.len := ext_ar_len_hold
    OUT_AXI.ar.size := ext_ar_size_hold
    OUT_AXI.ar.burst := ext_ar_burst_hold
  }

  val ext_aw_addr_hold = RegInit(0.U(32.W))
  val ext_aw_id_hold = RegInit(0.U(4.W))
  val ext_aw_len_hold = RegInit(0.U(8.W))
  val ext_aw_size_hold = RegInit(0.U(3.W))
  val ext_aw_burst_hold = RegInit(0.U(2.W))
  val ext_aw_pending = RegInit(false.B)

  when(OUT_fire.aw_fire) {
    ext_aw_addr_hold := OUT_AXI.aw.addr
    ext_aw_id_hold := OUT_AXI.aw.id
    ext_aw_len_hold := OUT_AXI.aw.len
    ext_aw_size_hold := OUT_AXI.aw.size
    ext_aw_burst_hold := OUT_AXI.aw.burst
    ext_aw_pending := true.B
  }.elsewhen(OUT_fire.b_fire) {
    ext_aw_pending := false.B
  }

  when(ext_aw_pending && !OUT_AXI.aw.valid) {
    OUT_AXI.aw.addr := ext_aw_addr_hold
    OUT_AXI.aw.id := ext_aw_id_hold
    OUT_AXI.aw.len := ext_aw_len_hold
    OUT_AXI.aw.size := ext_aw_size_hold
    OUT_AXI.aw.burst := ext_aw_burst_hold
  }
}

class Clint extends PrefixedModule {
  val in = IO(Flipped(new AXI))
  val mtime = IO(Input(UInt(64.W)))

  set_flipped_AXIfull_zero(in)

  val fire = GenerateFireSignal(in)

  val has_ar = RegInit(false.B)
  val low_or_high = RegEnable(in.ar.addr(2), fire.ar_fire)

  has_ar := MuxCase(
    has_ar,
    Seq(
      fire.ar_fire -> true.B,
      fire.r_burst_last -> false.B
    )
  )

  in.ar.ready := !has_ar
  in.r.valid := has_ar
  in.r.data := Mux(low_or_high, mtime(63, 32), mtime(31, 0))
  in.r.last := true.B
  in.r.id := "b1000".U(4.W)

  val wIDLE :: wAW :: wW :: wRESP :: Nil = Enum(4)
  val w_state = RegInit(wIDLE)

  in.aw.ready := w_state === wIDLE || w_state === wW
  in.w.ready := w_state === wIDLE || w_state === wAW
  in.b.valid := w_state === wRESP
  in.b.resp := 0.U(2.W)
  in.b.id := "b1000".U(4.W)

  w_state := MuxLookup(w_state, wIDLE)(
    Seq(
      wIDLE -> Mux(
        fire.aw_fire && fire.w_burst_last,
        wRESP,
        Mux(
          fire.aw_fire,
          wAW,
          Mux(fire.w_burst_last, wW, wIDLE)
        )
      ),
      wAW -> Mux(fire.w_burst_last, wRESP, wAW),
      wW -> Mux(fire.aw_fire, wRESP, wW),
      wRESP -> Mux(fire.b_fire, wIDLE, wRESP)
    )
  )

  block(Verifying) {
    when(fire.ar_fire) {
      assert(in.ar.id === "b1000".U(4.W), "CLINT can only be accessed by LSU")
      assert(in.ar.len === 0.U, "Burst length can only be 1")
    }

    when(fire.aw_fire) {
      assert(in.aw.id === "b1000".U(4.W), "CLINT can only be accessed by LSU")
      assert(in.aw.len === 0.U, "Burst length can only be 1")
    }
  }
}
