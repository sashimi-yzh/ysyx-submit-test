package npc

import chisel3._
import chisel3.util._
import npc.PMU._

// 提交指令信息：PC / 是否访存 / 访存地址（沿流水线 EXU → WBU）
class CommitInfoBundle extends Bundle {
  val pc = Output(UInt(32.W))
  val inst = Output(UInt(32.W))
  val next_pc = Output(UInt(32.W))
  val mem = Output(Bool())
  val mem_addr = Output(UInt(32.W))
}

class WriteBackPortBundle extends Bundle{
    val RegWaddr = Output(UInt(5.W))
    val RegWdata = Output(UInt(32.W))
    val RegWrite = Output(Bool())

    val CSRAddr = Output(UInt(12.W))
    val CSRData = Output(UInt(32.W))
    val CSRWrite = Output(Bool())
    val isTrap = Output(Bool())
    val PC = Output(UInt(32.W))
    val Exception_Code = Output(UInt(32.W))

}

// WBU → IFU 的 PC 更新端口：commit 脉冲 + 跳转/trap 事件
class RedirectBundle extends Bundle {
  val is_trap = Output(Bool())
  val pc_next = Output(UInt(32.W))
}

class ysyx_26030092_Commit extends ExtModule{
    val clock = FlatIO(Input(Clock()))
    val reset = FlatIO(Input(Bool()))
    val pc = FlatIO(Input(UInt(32.W)))
    val inst = FlatIO(Input(UInt(32.W)))
    val dnpc = FlatIO(Input(UInt(32.W)))
    val valid = FlatIO(Input(Bool()))
    val mem_commit = FlatIO(Input(Bool()))
    val mem_addr = FlatIO(Input(UInt(32.W)))
    addResource("/Commit.v")
}

class ysyx_26030092_WBU extends Module{
    val in = IO(Flipped(Decoupled(new WriteBackPortBundle)))

    val WriteRegPort = IO(Output(new WriteRegPortBundle))
    val CSRWritePort = IO(Output(new CSRWritePortBundle))
    val ExceptionPort = IO(Output(new ExceptionInfoBundle))

    val commit_info = IO(Input(new CommitInfoBundle))

    in.ready := true.B

    WriteRegPort := 0.U.asTypeOf(new WriteRegPortBundle)
    CSRWritePort := 0.U.asTypeOf(new CSRWritePortBundle)
    ExceptionPort := 0.U.asTypeOf(new ExceptionInfoBundle)

    when(in.fire){
        WriteRegPort.waddr := in.bits.RegWaddr
        WriteRegPort.wdata := in.bits.RegWdata
        WriteRegPort.wen := in.bits.RegWrite

        CSRWritePort.CSRWAddr := in.bits.CSRAddr
        CSRWritePort.CSRWData := in.bits.CSRData
        CSRWritePort.CSRWrite := in.bits.CSRWrite

        ExceptionPort.isTrap := in.bits.isTrap
        ExceptionPort.PC := in.bits.PC
        ExceptionPort.Exception_Code := in.bits.Exception_Code

    }

    PerfCounter("WBU_commit") := in.fire
    PerfCounter("WBU_stall_cycle") := !in.valid

    // commit 通知：fire 锁存，下一拍触发 DPI-C（供 difftest/trace 消费）
    val commit_u = Module(new ysyx_26030092_Commit)
    commit_u.clock := clock
    commit_u.reset := reset
    commit_u.valid := false.B
    commit_u.pc := commit_info.pc
    commit_u.inst := commit_info.inst
    commit_u.dnpc := commit_info.next_pc
    commit_u.mem_commit := commit_info.mem
    commit_u.mem_addr := commit_info.mem_addr

    when(in.fire){
        commit_u.valid := true.B
    }

    val invalid_instruction = Module(new ysyx_26030092_InvalidInstructionBlackBox())
    invalid_instruction.io.pc := ExceptionPort.PC
    invalid_instruction.io.inst := commit_info.inst
    invalid_instruction.io.invalid := false.B

    // 访存错误 / ebreak 指令：仿真终止（BAD TRAP）
    val ebreak = Module(new ysyx_26030092_EbreakBlackBox())
    ebreak.io.ebreak_trap := false.B

    when(ExceptionPort.isTrap && in.fire){
        when(ExceptionPort.Exception_Code === 0.U || ExceptionPort.Exception_Code === 3.U){
            ebreak.io.ebreak_trap := true.B
        }.elsewhen(ExceptionPort.Exception_Code === 2.U){
            invalid_instruction.io.invalid := true.B
        }
    }
}
