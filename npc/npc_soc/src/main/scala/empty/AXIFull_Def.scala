package empty

import chisel3._
import chisel3.util._
import chisel3.layer._

class AXI_AW extends Bundle {
  val ready = Input(Bool())
  val valid = Output(Bool())
  val addr = Output(UInt(32.W))
  val id = Output(UInt(4.W))
  val len = Output(UInt(8.W))
  val size = Output(UInt(3.W))
  val burst = Output(UInt(2.W))
}

class AXI_W extends Bundle {
  val ready = Input(Bool())
  val valid = Output(Bool())
  val data = Output(UInt(32.W))
  val strb = Output(UInt(4.W))
  val last = Output(Bool())
}

class AXI_B extends Bundle {
  val ready = Output(Bool())
  val valid = Input(Bool())
  val resp = Input(UInt(2.W))
  val id = Input(UInt(4.W))
}

class AXI_AR extends Bundle {
  val ready = Input(Bool())
  val valid = Output(Bool())
  val addr = Output(UInt(32.W))
  val id = Output(UInt(4.W))
  val len = Output(UInt(8.W))
  val size = Output(UInt(3.W))
  val burst = Output(UInt(2.W))
}

class AXI_R extends Bundle {
  val ready = Output(Bool())
  val valid = Input(Bool())
  val resp = Input(UInt(2.W))
  val data = Input(UInt(32.W))
  val last = Input(Bool())
  val id = Input(UInt(4.W))
}

class AXI extends Bundle {
  val aw = new AXI_AW
  val w = new AXI_W
  val b = new AXI_B
  val ar = new AXI_AR
  val r = new AXI_R
}

object set_AXIfull_zero {
  def apply(axi: AXI) = {
    axi.aw.addr := 0.U
    axi.aw.valid := 0.U
    axi.aw.id := 0.U
    axi.aw.len := 0.U
    axi.aw.size := "b010".U
    axi.aw.burst := "b01".U

    axi.w.data := 0.U
    axi.w.valid := 0.U
    axi.w.strb := 0.U
    axi.w.last := 0.U

    axi.ar.addr := 0.U
    axi.ar.valid := 0.U
    axi.ar.id := 0.U
    axi.ar.len := 0.U
    axi.ar.size := "b010".U
    axi.ar.burst := "b01".U

    axi.r.ready := 0.U

    axi.b.ready := 0.U
  }
}

object set_flipped_AXIfull_zero {
  def apply(axi: AXI) = {
    axi.ar.ready := 0.U

    axi.r.valid := 0.U
    axi.r.resp := 0.U
    axi.r.data := 0.U
    axi.r.last := 0.U
    axi.r.id := 0.U

    axi.aw.ready := 0.U

    axi.w.ready := 0.U

    axi.b.resp := 0.U
    axi.b.valid := 0.U
    axi.b.id := 0.U
  }
}

object check_signal_stable {
  def apply(ready: Bool, valid: Bool, signals: UInt, module_name: String) = {
    val sIDLE :: sVALID :: Nil = Enum(2)
    val state = RegInit(sIDLE)
    val latched = RegEnable(signals, 0.U, state === sIDLE && valid)
    state := MuxLookup(state, sIDLE)(
      Seq(
        sIDLE -> Mux(valid && !ready, sVALID, sIDLE),
        sVALID -> Mux(ready, sIDLE, sVALID)
      )
    )
    when(state === sVALID) {
      assert(valid, "In " + module_name + " valid dropped before fire")
      assert(
        latched === signals,
        "In " + module_name + " signals changed before fire"
      )
    }
  }
}
