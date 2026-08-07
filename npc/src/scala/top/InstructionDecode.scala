package top
import chisel3._
import dto._
import enums._
import chisel3.util._
import table._
import chisel3.experimental.inlinetest.TestChoice.All
import chisel3.util.experimental.decode.decoder
import org.chipsalliance.cde.config.Parameters
import config.Configs
import chisel3.util.experimental.decode._

class InstructionDecode(
  implicit p: Parameters)
    extends Module {
  val io                                                               = IO(new Bundle {
    val ifu           = Flipped(Decoupled(new If2Id))
    val toEXU         = Decoupled(new Id2Ex)
    // to Regfile
    val regReadAddr1  = Output(UInt(4.W))
    val regReadData1  = Input(UInt(32.W))
    val regReadAddr2  = Output(UInt(4.W))
    val regReadData2  = Input(UInt(32.W))
    // to CsrReg
    val csrTube       = new CsrRegOperator
    val exuForwarding = Input(new RegForward)
    val mauFowarding  = Input(new RegForward)
    val wbuForwarding = Input(new RegForward)
    val flush         = Input(Bool())
    // regForward
    val csrMepc       = if (p(Configs.DebugMode)) Input(UInt(32.W)) else null
    val csrMtvec      = if (p(Configs.DebugMode)) Input(UInt(32.W)) else null
  })
  val sPause :: sWaitIfu :: sPrepareData :: sDecode :: sSendExu :: Nil = Enum(5)
  val state                                                            = RegInit(sWaitIfu)
  val immI                                                             = Wire(UInt(32.W))
  val immS                                                             = Wire(UInt(32.W))
  val immB                                                             = Wire(UInt(32.W))
  val immU                                                             = Wire(UInt(32.W))
  val immJ                                                             = Wire(UInt(32.W))
  val rs1                                                              = Wire(UInt(5.W))
  val rs2                                                              = Wire(UInt(5.W))
  val rd                                                               = Wire(UInt(5.W))
  val funct3                                                           = Wire(UInt(3.W))
  val funct7                                                           = Wire(UInt(7.W))
  val opcode                                                           = Wire(UInt(7.W))
  val decodeResult                                                     = Reg(new Id2Ex)
  val rs1Data                                                          = decodeResult.rs1Data
  val rs2Data                                                          = decodeResult.rs2Data
  val rs1DataReady                                                     = Reg(Bool())
  val rs2DataReady                                                     = Reg(Bool())
  val csr                                                              = Wire(UInt(12.W))
  val csrData                                                          = Wire(UInt(32.W))
  val isCsrInstruction                                                 = Wire(Bool())
  val instReg                                                          = decodeResult.imm

  rs1                     := instReg(19, 15)
  rs2                     := instReg(24, 20)
  rd                      := instReg(11, 7)
  opcode                  := instReg(6, 0)
  funct3                  := instReg(14, 12)
  funct7                  := instReg(31, 25)
  state                   := MuxLookup(state, sWaitIfu)(
    Seq(
      sPause       -> Mux(io.flush, sWaitIfu, sWaitIfu),
      sWaitIfu     -> Mux(
        io.flush,
        sWaitIfu,
        Mux(io.ifu.fire, Mux(io.ifu.bits.exception, sSendExu, sPrepareData), sWaitIfu)
      ),
      sPrepareData -> Mux(io.flush, sWaitIfu, Mux(rs1DataReady & rs2DataReady, sDecode, sPrepareData)),
      sDecode      -> Mux(io.flush, sWaitIfu, sSendExu),
      sSendExu     -> Mux(io.flush, sWaitIfu, Mux(io.toEXU.fire, Mux(isCsrInstruction || decodeResult.exception, sPause, sWaitIfu), sSendExu))
    )
  )
  io.ifu.ready            := state === sWaitIfu
  io.toEXU.valid          := state === sSendExu
  io.toEXU.bits           := decodeResult
  immI                    := Cat(Fill(20, instReg(31)), instReg(31, 20))
  immS                    := Cat(Fill(20, instReg(31)), instReg(31, 25), instReg(11, 7))
  immB                    := Cat(
    Fill(20, instReg(31)),
    instReg(7),
    instReg(30, 25),
    instReg(11, 8),
    0.U(1.W)
  )
  immU                    := Cat(instReg(31, 12), Fill(12, 0.U(1.W)))
  immJ                    := Cat(
    Fill(12, instReg(31)),
    instReg(19, 12),
    instReg(20),
    instReg(30, 21),
    0.U(1.W)
  )
  isCsrInstruction        := opcode === "b1110011".U
  io.regReadAddr1         := rs1
  io.regReadAddr2         := rs2
  csr                     := immI
  io.csrTube.regWriteEn   := false.B
  io.csrTube.regWriteData := 0.U
  io.csrTube.regAddr      := csr
  csrData                 := io.csrTube.regReadData
  switch(state) {
    is(sWaitIfu) {
      when(io.ifu.fire) {
        decodeResult.imm          := io.ifu.bits.inst
        decodeResult.pc           := io.ifu.bits.pc
        decodeResult.exception    := io.ifu.bits.exception
        decodeResult.exceptionNum := io.ifu.bits.exceptionNum
        decodeResult.npc          := io.ifu.bits.npc
        rs1DataReady              := false.B
        rs2DataReady              := false.B
      }
    }
    is(sPrepareData) {
      val wbuMatchRs1 = io.wbuForwarding.valid && io.wbuForwarding.rd === rs1
      val wbuMatchRs2 = io.wbuForwarding.valid && io.wbuForwarding.rd === rs2
      val mauMatchRs1 = io.mauFowarding.valid && io.mauFowarding.rd === rs1
      val mauMatchRs2 = io.mauFowarding.valid && io.mauFowarding.rd === rs2
      val exuMatchRs1 = io.exuForwarding.valid && io.exuForwarding.rd === rs1
      val exuMatchRs2 = io.exuForwarding.valid && io.exuForwarding.rd === rs2

      val exuSelRs1 = exuMatchRs1
      val mauSelRs1 = mauMatchRs1 && !exuMatchRs1
      val wbuSelRs1 = wbuMatchRs1 && !exuMatchRs1 && !mauMatchRs1
      val regSelRs1 = !(exuMatchRs1 || mauMatchRs1 || wbuMatchRs1)

      rs1Data := Mux1H(
        Seq(
          regSelRs1 -> io.regReadData1,
          exuSelRs1 -> io.exuForwarding.rdData,
          mauSelRs1 -> io.mauFowarding.rdData,
          wbuSelRs1 -> io.wbuForwarding.rdData
        )
      )

      rs1DataReady := PriorityMux(
        Seq(
          exuMatchRs1 -> io.exuForwarding.dataValid,
          mauMatchRs1 -> io.mauFowarding.dataValid,
          wbuMatchRs1 -> io.wbuForwarding.dataValid,
          true.B      -> true.B
        )
      )

      val exuSelRs2 = exuMatchRs2
      val mauSelRs2 = mauMatchRs2 && !exuMatchRs2
      val wbuSelRs2 = wbuMatchRs2 && !exuMatchRs2 && !mauMatchRs2
      val regSelRs2 = !(exuMatchRs2 || mauMatchRs2 || wbuMatchRs2)

      rs2Data := Mux1H(
        Seq(
          regSelRs2 -> io.regReadData2,
          exuSelRs2 -> io.exuForwarding.rdData,
          mauSelRs2 -> io.mauFowarding.rdData,
          wbuSelRs2 -> io.wbuForwarding.rdData
        )
      )

      rs2DataReady := PriorityMux(
        Seq(
          exuMatchRs2 -> io.exuForwarding.dataValid,
          mauMatchRs2 -> io.mauFowarding.dataValid,
          wbuMatchRs2 -> io.wbuForwarding.dataValid,
          true.B      -> true.B
        )
      )
    }
    is(sDecode) {
      val decodeTable = new DecodeTable(
        AllInstructions.all,
        Seq(
          decodeException,
          decodeAluOperator,
          decodeExceptionNum,
          decodeMemSize,
          decodeMemSignEx,
          decodeCsrWriteEn,
          // decodeCsrOp,
          decodeRs1Src,
          decodeRegWriteEn,
          decodeRs2Src,
          decodeNeedMA,
          decodeMemWriteEn,
          decodeIsBranch,
          decodeFenceI,
          decodeIsJal,
          decodeIsJalr,
          decodeIsMret,
          decodeIsEcall,
          decodeImmFmt,
          decodeCsrrw
        )
      )
      val result      = decodeTable.decode(instReg)
      decodeResult.exception    := result(decodeException)
      decodeResult.exceptionNum := result(decodeExceptionNum)
      decodeResult.mret         := result(decodeIsMret)
      decodeResult.rd           := rd
      decodeResult.regWriteEn   := result(decodeRegWriteEn)
      decodeResult.rs1Data      := MuxLookup(result(decodeRs1Src), rs1Data)(
        Seq(
          Rs1Src.reg  -> rs1Data,
          Rs1Src.pc   -> decodeResult.pc,
          Rs1Src.zero -> 0.U
        )
      )
      decodeResult.rs2Data      := MuxLookup(result(decodeRs2Src), rs2Data)(
        Seq(
          Rs2Src.reg  -> rs2Data,
          Rs2Src.immI -> immI,
          Rs2Src.immU -> immU,
          Rs2Src.csr  -> csrData
        )
      )
      decodeResult.fence_i      := result(decodeFenceI)
      decodeResult.needMA       := result(decodeNeedMA)
      decodeResult.memSize      := result(decodeMemSize)
      decodeResult.memSignEx    := result(decodeMemSignEx)
      decodeResult.aluOperator  := result(decodeAluOperator)
      decodeResult.isBranch     := result(decodeIsBranch)
      decodeResult.isJal        := result(decodeIsJal)
      decodeResult.isJalr       := result(decodeIsJalr)
      decodeResult.csrrw        := result(decodeCsrrw)
      decodeResult.branchFunct3 := funct3
      decodeResult.imm          := MuxLookup(result(decodeImmFmt), immI)(
        Seq(
          ImmFmt.immS -> immS,
          ImmFmt.immB -> immB,
          ImmFmt.immU -> immU,
          ImmFmt.immJ -> immJ
        )
      )
      decodeResult.csrWriteEn   := result(decodeCsrWriteEn)
      // decodeResult.csrOp        := result(decodeCsrOp)
      if (p(Configs.DebugMode)) {
        decodeResult.instruction := instReg
        when(result(decodeIsEcall)) {
          decodeResult.npc := io.csrMtvec
        }
        when(result(decodeIsMret)) {
          decodeResult.npc := io.csrMepc
        }
      }
    }
  }
}
