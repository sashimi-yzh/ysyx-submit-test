package top
import chisel3._
import chisel3.util._
import chisel3.util.random.LFSR


class RandomDelay(maxBits: Int = 4) extends Module {
  val io = IO(new Bundle {
    val trigger = Input(Bool())
    val ready   = Output(Bool())
  })

  val triggerPrev = RegNext(io.trigger, false.B)
  val risingEdge  = io.trigger && !triggerPrev

  val lfsr     = LFSR(8, risingEdge)        // 仅上升沿时采样新随机值
  val cnt      = RegInit(0.U(maxBits.W))
  val active   = RegInit(false.B)
  val readyReg = RegInit(false.B)
  readyReg := false.B

  when(risingEdge && !active) { //仅在trigger上升沿激活
    cnt    := lfsr(maxBits - 1, 0)
    active := true.B
  }

  when(active) {
    when(cnt === 0.U) {
      readyReg := true.B
      active   := false.B
    }.otherwise {
      cnt := cnt - 1.U
    }
  }

  io.ready := readyReg
}