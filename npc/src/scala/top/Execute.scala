package top

import chisel3._
import dto._
import chisel3.util._
import enums._
import org.chipsalliance.cde.config.Parameters
import config.Configs
class ALU(
  implicit p: Parameters)
    extends Module {
  val io          = IO(new Bundle {
    val src1         = Input(UInt(32.W))
    val src2         = Input(UInt(32.W))
    val cin          = Input(Bool())
    val res          = Output(UInt(32.W))
    val signedLess   = Output(Bool())
    val signedGe     = Output(Bool())
    val unsignedLess = Output(Bool())
    val unsignedGe   = Output(Bool())
    val equal        = Output(Bool())
  })
  val src2_xor    = Mux(io.cin, ~io.src2, io.src2)
  val result      = Cat(0.U(1.W), io.src1) + Cat(0.U(1.W), src2_xor) + io.cin
  val src1_sign   = io.src1(31)
  val src2_sign   = io.src2(31)
  val result_sign = result(31)
  io.res          := result(31, 0)
  io.signedLess   := Mux(src1_sign =/= src2_sign, src1_sign, result_sign)
  io.signedGe     := !io.signedLess
  io.unsignedLess := ~result(32)
  io.unsignedGe   := result(32)
  io.equal        := result(31, 0) === 0.U
}
class InstructionExecute(
  implicit p: Parameters)
    extends Module {
  val io                                                         = IO(
    new Bundle {
      val idu                   = Flipped(Decoupled(new Id2Ex))
      val mau                   = Decoupled(new Ex2Ma)
      val pcRedirect            = Output(new PcRedirect)
      val flush                 = Input(Bool())
      val updateBranchPredictor = Flipped(new UpdateIO)
      val forward               = Output(new RegForward)
    }
  )
  val s_wait_idu :: s_calc_address :: s_calc :: s_send_ma :: Nil = Enum(4)
  val state                                                      = RegInit(s_wait_idu)
  val decodeInfo                                                 = Reg(new Id2Ex)
  val address1                                                   = decodeInfo.imm
  val result2                                                    = decodeInfo.rs2Data
  val branchTaken                                                = Wire(Bool())
  val forcus                                                     = Mux(state === s_wait_idu, io.idu.bits, decodeInfo)
  val isControlTransfer                                          = forcus.isJal || forcus.isJalr || forcus.isBranch

  io.forward.rd        := decodeInfo.rd
  io.forward.rdData    := result2
  io.forward.valid     := state =/= s_wait_idu && decodeInfo.regWriteEn && decodeInfo.rd =/= 0.U
  io.forward.dataValid := state === s_send_ma && !(decodeInfo.needMA && decodeInfo.regWriteEn)

  state := MuxLookup(state, s_wait_idu)(
    Seq(
      s_wait_idu     -> Mux(io.flush || !io.idu.fire, s_wait_idu, Mux(io.idu.bits.exception, s_send_ma, Mux(isControlTransfer || io.idu.bits.needMA, s_calc_address, s_calc))),
      s_calc_address -> Mux(io.flush, s_wait_idu, s_calc),
      s_calc         -> Mux(io.flush, s_wait_idu, s_send_ma),
      s_send_ma      -> Mux(io.mau.fire || io.flush, s_wait_idu, s_send_ma)
    )
  )

  val isJalOrJalr = decodeInfo.isJal || decodeInfo.isJalr
  val alu         = Module(new ALU())
  val shiftAmount = decodeInfo.rs2Data(4, 0)
  val shiftLeft   = (decodeInfo.rs1Data << shiftAmount)(31, 0)
  val shiftRight  = decodeInfo.rs1Data >> shiftAmount
  val shiftArith  = (decodeInfo.rs1Data.asSInt >> shiftAmount).asUInt

  val pcPlus4 = decodeInfo.pc + 4.U

  branchTaken := MuxLookup(decodeInfo.branchFunct3, false.B)(
    Seq(
      "b000".U -> alu.io.equal,
      "b001".U -> ~alu.io.equal,
      "b100".U -> alu.io.signedLess,
      "b101".U -> alu.io.signedGe,
      "b110".U -> alu.io.unsignedLess,
      "b111".U -> alu.io.unsignedGe
    )
  )

  val redirectTarget = Mux((decodeInfo.isBranch && branchTaken) || decodeInfo.isJal || decodeInfo.isJalr, address1, pcPlus4)
  val predictFail    = isControlTransfer && redirectTarget =/= decodeInfo.npc
  alu.io.src1                     := 0.U
  alu.io.src2                     := 0.U
  alu.io.cin                      := 0.U
  io.updateBranchPredictor.valid  := state === s_calc && isControlTransfer
  io.updateBranchPredictor.target := redirectTarget
  io.updateBranchPredictor.pc     := decodeInfo.pc
  io.pcRedirect.valid             := state === s_calc && predictFail
  io.pcRedirect.npc               := redirectTarget

  io.idu.ready := state === s_wait_idu
  io.mau.valid := state === s_send_ma

  io.mau.bits.fence_i      := decodeInfo.fence_i
  io.mau.bits.rd           := decodeInfo.rd
  io.mau.bits.rdData       := Mux(decodeInfo.csrWriteEn || decodeInfo.needMA, decodeInfo.rs2Data, result2)
  io.mau.bits.rdWriteEn    := decodeInfo.regWriteEn
  io.mau.bits.needMA       := decodeInfo.needMA
  io.mau.bits.memAddr      := address1
  io.mau.bits.memSize      := decodeInfo.memSize
  io.mau.bits.memSignEx    := decodeInfo.memSignEx
  io.mau.bits.mret         := decodeInfo.mret
  io.mau.bits.pc           := decodeInfo.pc
  if (p(Configs.DebugMode)) {
    io.mau.bits.npc         := decodeInfo.npc
    io.mau.bits.instruction := decodeInfo.instruction
  }
  io.mau.bits.csrWriteEn   := decodeInfo.csrWriteEn
  io.mau.bits.csrWriteAddr := decodeInfo.imm
  io.mau.bits.csrWriteData := decodeInfo.rs1Data | Mux(decodeInfo.csrrw, 0.U, decodeInfo.rs2Data)
  io.mau.bits.exception    := decodeInfo.exception
  io.mau.bits.exceptionNum := decodeInfo.exceptionNum
  if (p(Configs.DebugMode)) {
    when(state === s_calc && predictFail) {
      decodeInfo.npc := redirectTarget
    }
  }
  switch(state) {
    is(s_wait_idu) {
      when(io.idu.fire) { decodeInfo := io.idu.bits }
    }
    is(s_calc_address) {
      alu.io.src1    := Mux(decodeInfo.isBranch || decodeInfo.isJal, decodeInfo.pc, decodeInfo.rs1Data)
      alu.io.src2    := decodeInfo.imm
      alu.io.cin     := false.B
      decodeInfo.imm := alu.io.res
    }
    is(s_calc) {
      alu.io.src1        := decodeInfo.rs1Data
      alu.io.src2        := decodeInfo.rs2Data
      alu.io.cin         := decodeInfo.aluOperator.isOneOf(
        AluOperator.sub,
        AluOperator.signedLess,
        AluOperator.unsignedLess
      ) || decodeInfo.isBranch
      decodeInfo.rs2Data := Mux(
        isJalOrJalr,
        pcPlus4,
        MuxLookup(decodeInfo.aluOperator, decodeInfo.rs2Data)(
          Seq(
            AluOperator.add                  -> alu.io.res,
            AluOperator.sub                  -> alu.io.res,
            AluOperator.and                  -> (decodeInfo.rs1Data & decodeInfo.rs2Data),
            AluOperator.arithmeticRightShift -> shiftArith,
            AluOperator.logicalLeftShift     -> shiftLeft,
            AluOperator.logicalRightShift    -> shiftRight,
            AluOperator.or                   -> (decodeInfo.rs1Data | decodeInfo.rs2Data),
            AluOperator.signedLess           -> alu.io.signedLess,
            AluOperator.unsignedLess         -> alu.io.unsignedLess,
            AluOperator.xor                  -> (decodeInfo.rs1Data ^ decodeInfo.rs2Data)
          )
        )
      )
    }
    is(s_send_ma) {}
  }
  if (p(Configs.DebugMode)) {
    dontTouch(branchTaken)
  }
}
