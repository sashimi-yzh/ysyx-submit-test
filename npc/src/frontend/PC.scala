package npc

import chisel3._
import chisel3.util._

class ysyx_26030092_PCBlackBox extends ExtModule{
    val io = FlatIO(new Bundle {
        val clock = Input(Clock())
        val reset = Input(Reset())
        val pc_next = Input(UInt(32.W))
        val pc_we = Input(Bool())
        val pc_4 = Input(Bool())
        val pc = Output(UInt(32.W))
    })
    addResource("/PCBlackBox.v")
}

class ysyx_26030092_PCReg extends Module{
    val next_pc = IO(Input(UInt(32.W)))
    val jump    = IO(Input(Bool()))
    val adv     = IO(Input(Bool()))
    val pc      = IO(Output(UInt(32.W)))

    val u = Module(new ysyx_26030092_PCBlackBox)
    u.io.clock   := clock
    u.io.reset   := reset
    u.io.pc_next := next_pc
    u.io.pc_we   := jump
    u.io.pc_4    := adv
    pc := u.io.pc
}
