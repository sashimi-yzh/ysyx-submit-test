package busfsm
import chisel3._
import chisel3.util._

class OneMasterOneSlaveFSM_Old extends Module {
  val io = IO(new Bundle {
    val master_valid = Input(Bool())
    val master_ready = Output(Bool())

    val self_finished = Input(Bool())

    val slave_valid = Output(Bool())
    val slave_ready = Input(Bool())

    val _state = Output(UInt(2.W))
  })

  val s_idle :: s_busy :: s_wait_slave :: Nil = Enum(3)
  val state                                   = RegInit(s_idle)

  io._state := state

  state := MuxLookup(state, s_idle)(
    Seq(
      s_idle       -> Mux(io.master_valid, s_busy, s_idle),
      s_busy       -> Mux(io.self_finished, s_wait_slave, s_busy),
      s_wait_slave -> Mux(io.slave_ready, s_idle, s_wait_slave)
    )
  )

  io.master_ready := (state === s_wait_slave) && (io.self_finished) && (io.slave_ready)
  io.slave_valid  := (state === s_wait_slave)

  def connectMaster[T <: Data](master: DecoupledIO[T]): Unit = {
    master.ready    := io.master_ready
    io.master_valid := master.valid
  }
  def connectSlave[T <: Data](slave: DecoupledIO[T]):   Unit = {
    slave.valid    := io.slave_valid
    io.slave_ready := slave.ready
  }

}
class OneMasterOneSlaveFSM extends Module {
  val io = IO(new Bundle {
    val master_valid = Input(Bool())
    val master_ready = Output(Bool())

    val self_finished = Input(Bool())

    val slave_valid = Output(Bool())
    val slave_ready = Input(Bool())
  })

  val full = RegInit(false.B)

  val state = Wire(UInt(2.W))
  when(!full) {
    state := 0.U
  }.elsewhen(full && !io.self_finished) {
    state := 1.U
  }.otherwise {
    state := 2.U
  }
  dontTouch(state)

  val selfFinished = io.self_finished && (!reset.asBool)

  val slave_picked = io.slave_ready && selfFinished

  val ready = !full && (!reset.asBool)
  io.master_ready := ready || (full && slave_picked)

  io.slave_valid := full && selfFinished

  when(ready) {
    full := io.master_valid && selfFinished
  }.elsewhen(slave_picked) {
    full := io.master_valid && selfFinished
  }
}

object InnerBusCtrl {
  def apply(master: DecoupledIO[Data], slave: DecoupledIO[Data]): OneMasterOneSlaveFSM = {
    val fsm = Module(new OneMasterOneSlaveFSM)
    fsm.io.master_valid := master.valid
    fsm.io.slave_ready  := slave.ready
    master.ready        := fsm.io.master_ready
    slave.valid         := fsm.io.slave_valid
    fsm
  }

  def apply(master: DecoupledIO[Data], slave: DecoupledIO[Data], self_finished: Bool): OneMasterOneSlaveFSM = {
    val fsm = apply(master, slave)
    fsm.io.self_finished := self_finished
    fsm
  }

  def apply(master: DecoupledIO[Data], slave: DecoupledIO[Data], alwaysComb: Boolean) = {
    slave.valid  := master.valid
    master.ready := slave.ready

    // apply(master, slave, alwaysComb.B)
  }
}
