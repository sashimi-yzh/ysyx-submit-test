package empty
import chisel3._
import chisel3.util._
import chisel3.layer.block

class __sim_bus() extends Module {
  val fetch_port = IO(Flipped(new AXI))
  val io = IO(new Bundle {
    val raddr = Output(UInt(32.W))
    val waddr = Output(UInt(32.W))
    val wdata = Output(UInt(32.W))
    val wmask = Output(UInt(4.W))
    val valid = Output(Bool())
    val wen = Output(Bool())
    val rdata = Input(UInt(32.W))
  })
  val fire = GenerateFireSignal(fetch_port)

  val has_ar = RegInit(false.B)
  val has_aw = RegInit(false.B)
  val has_w = RegInit(false.B)

  has_ar := MuxCase(
    has_ar,
    Seq(
      fire.ar_fire -> true.B,
      fire.r_burst_last -> false.B
    )
  )
  has_aw := MuxCase(
    has_aw,
    Seq(
      fire.aw_fire -> true.B,
      fire.b_fire -> false.B
    )
  )
  has_w := MuxCase(
    has_w,
    Seq(
      fire.w_burst_last -> true.B,
      fire.b_fire -> false.B
    )
  )

  val burst_read_cnt = Reg(UInt(32.W))
  val rid_r = RegEnable(fetch_port.ar.id, fire.ar_fire)
  val raddr_r = Reg(UInt(32.W))
  raddr_r := MuxCase(
    raddr_r,
    Seq(
      fire.ar_fire -> (fetch_port.ar.addr + 4.U),
      fire.r_fire -> (raddr_r + 4.U)
    )
  )
  burst_read_cnt := MuxCase(
    burst_read_cnt,
    Seq(
      fire.ar_fire -> (fetch_port.ar.len),
      fire.r_fire -> (burst_read_cnt - 1.U)
    )
  )

  fetch_port.r.last := (burst_read_cnt === 0.U) && (has_ar)
  fetch_port.r.id := rid_r
  fetch_port.r.data := io.rdata
  fetch_port.r.resp := "b00".U
  fetch_port.ar.ready := !has_ar
  fetch_port.r.valid := has_ar

  io.raddr := Mux(fire.ar_fire, fetch_port.ar.addr, raddr_r)

  val wid_r = RegEnable(fetch_port.aw.id, fire.aw_fire)
  val waddr_r = Reg(UInt(32.W))
  waddr_r := MuxCase(
    waddr_r,
    Seq(
      fire.aw_fire -> (fetch_port.aw.addr),
      fire.w_fire -> (waddr_r + 4.U)
    )
  )

  fetch_port.aw.ready := !has_aw
  fetch_port.w.ready := has_aw
  io.wen := fire.w_fire
  io.wdata := fetch_port.w.data
  io.wmask := fetch_port.w.strb
  io.waddr := waddr_r

  fetch_port.b.valid := has_w
  fetch_port.b.resp := "b00".U
  fetch_port.b.id := wid_r

  io.valid := fire.ar_fire || (has_ar && !fire.r_burst_last && fire.r_fire)

  block(AXIAssertLayer) {
    when(fire.ar_fire) {
      assert(
        fetch_port.ar.len === 0.U || fetch_port.ar.size === "b010".U,
        "Only arsize = b010 is supported when burst"
      )
      assert(fetch_port.ar.burst === "b01".U, "Only arburst = b01 is supported")
    }
    when(fire.aw_fire) {
      assert(
        fetch_port.aw.len === 0.U || fetch_port.aw.size === "b010".U,
        "Only awsize = b010 is supported when burst"
      )
      assert(fetch_port.aw.burst === "b01".U, "Only awburst = b01 is supported")

    }

  }
}
