package cpu

import chisel3._
import chisel3.util._

import chisel3.experimental.dataview._

import common_def._
import busfsm._
import regfile._

import cpu.WriteBackInfo

class InstInfoDecoder extends Module {
  val io = IO(new Bundle {
    val opcode = Input(UInt(7.W))
    val valid  = Output(Bool())
    val out    = Output(new InstMetaInfo())
  })

  // opcode[1:0] should always be 11 for 32bit
  io.valid := io.opcode(1, 0).andR
  val opcu = io.opcode(6, 2)

  val lut = Seq(
    "b00000".U -> (InstFmt.imm, InstType.load),
    "b00100".U -> (InstFmt.imm, InstType.arithmetic),
    "b11001".U -> (InstFmt.imm, InstType.jalr),
    "b11100".U -> (InstFmt.imm, InstType.system),
    "b01100".U -> (InstFmt.reg, InstType.arithmetic),
    "b01000".U -> (InstFmt.store, InstType.store),
    "b01101".U -> (InstFmt.upper, InstType.lui),
    "b00101".U -> (InstFmt.upper, InstType.auipc),
    "b11011".U -> (InstFmt.jump, InstType.jal),
    "b11000".U -> (InstFmt.branch, InstType.branch),
    "b00011".U -> (InstFmt.imm, InstType.fencei)
  ).map { case (key, (fmt, typ)) =>
    key -> {
      val info = Wire(new InstMetaInfo)
      info.fmt := fmt
      info.typ := typ
      info
    }
  }

  val dontcare = Wire(new InstMetaInfo)
  dontcare := DontCare
  io.out   := MuxLookup(opcu, dontcare)(lut)
}

class WrBackForwardInfo(
  implicit p: CPUParameters)
    extends Bundle {
  val addr      = p.GPRAddr
  val enWr      = Bool()
  val dataVaild = Bool()
  val data      = Types.UWord
}

object WrBackForwardInfo {
  def apply(
    infoValid:  Bool,
    dinstInfo:  DecodedInst,
    dataVaild:  Bool,
    data:       UInt
  )(
    implicit p: CPUParameters
  ): WrBackForwardInfo = {
    val res = Wire(new WrBackForwardInfo)
    res.addr      := dinstInfo.rd
    res.enWr      := dinstInfo.info.rdWrEn && infoValid
    res.dataVaild := dataVaild
    res.data      := data
    res
  }
  def apply(
    dinst:      DecoupledIO[DecodedInst],
    dataVaild:  Bool,
    data:       UInt
  )(
    implicit p: CPUParameters
  ): WrBackForwardInfo = {
    apply(dinst.valid, dinst.bits, dataVaild, data)
  }
  def apply(
    dinst:      DecoupledIO[DecodedInst]
  )(
    implicit p: CPUParameters
  ): WrBackForwardInfo = {
    val foo = Wire(Types.UWord)
    foo := DontCare
    apply(dinst, false.B, foo)
  }
}

class WrBackInfoGroup(
  implicit p: CPUParameters)
    extends Bundle {
  // val exus1 = new WrBackForwardInfo
  // val exus2 = new WrBackForwardInfo

  val exu = new WrBackForwardInfo

  val lsu   = new WrBackForwardInfo
  val wbu   = new WrBackForwardInfo
}

class ByPassMux(
  implicit p: CPUParameters)
    extends Module {
  val io = IO(new Bundle {
    val rs1      = Input(p.GPRAddr)
    val rs2      = Input(p.GPRAddr)
    val regData1 = Input(Types.UWord)
    val regData2 = Input(Types.UWord)

    val wrBackInfo = Input(new WrBackInfoGroup)
    val needStall  = Output(Bool())

    val outData1 = Output(Types.UWord)
    val outData2 = Output(Types.UWord)
  })

  def conflict(rs: UInt, rd: UInt, en: Bool): Bool = (rs === rd) && (rd =/= 0.U) && en

  def conflict(rs: UInt, wrBack: WrBackForwardInfo): Bool = conflict(rs, wrBack.addr, wrBack.enWr)

  def oneConflictWithWrBack(wrBack: WrBackForwardInfo): Bool = {
    conflict(io.rs1, wrBack) || conflict(io.rs2, wrBack)
  }

  /*
  val isConflictWithEXUS1 = Wire(Bool())
  // exu stage 1 always prepare the data, no valid bypass data
  // just check conflict
  isConflictWithEXUS1 := oneConflictWithWrBack(io.wrBackInfo.exus1)

  val isConflictWithEXUS2 = Wire(Bool())
  val isRs1ConflictEXUS2  = conflict(io.rs1, io.wrBackInfo.exus2)
  val isRs2ConflictEXUS2  = conflict(io.rs2, io.wrBackInfo.exus2)

  isConflictWithEXUS2 := (isRs1ConflictEXUS2 || isRs2ConflictEXUS2)

  val isConflictWithEXU = WireDefault(isConflictWithEXUS1 || isConflictWithEXUS2)

  val exus2WrBackDataVaild = io.wrBackInfo.exus2.dataVaild
  val exus2WrBackData = io.wrBackInfo.exus2.data
  */

  val isConflictWithEXU = oneConflictWithWrBack(io.wrBackInfo.exu)
  val isRs1ConflictEXUS2 = conflict(io.rs1, io.wrBackInfo.exu)
  val isRs2ConflictEXUS2 = conflict(io.rs2, io.wrBackInfo.exu)

  val isConflictWithEXUS1 = false.B

  val exus2WrBackDataVaild = io.wrBackInfo.exu.dataVaild
  val exus2WrBackData = io.wrBackInfo.exu.data

  // -----------

  val isConflictWithLSU = Wire(Bool())
  // lsu may have valid bypass data, but it immediately forward the data
  // to wbu after the memory access, for now, dont use it, just check conflict
  isConflictWithLSU := oneConflictWithWrBack(io.wrBackInfo.lsu)

  val isConflictWithWBU    = Wire(Bool())
  val isRs1ConflictWithWBU = conflict(io.rs1, io.wrBackInfo.wbu)
  val isRs2ConflictWithWBU = conflict(io.rs2, io.wrBackInfo.wbu)

  isConflictWithWBU := (isRs1ConflictWithWBU || isRs2ConflictWithWBU)

  dontTouch(isConflictWithEXU)
  dontTouch(isConflictWithLSU)
  dontTouch(isConflictWithWBU)

  val isRdAfterWr = Wire(Bool())
  isRdAfterWr := isConflictWithEXU || isConflictWithLSU || isConflictWithWBU
  dontTouch(isRdAfterWr)


  val canRs1Bypass =
    Mux(isRs1ConflictEXUS2, exus2WrBackDataVaild, isRs1ConflictWithWBU)
  val canRs2Bypass =
    Mux(isRs2ConflictEXUS2, exus2WrBackDataVaild, isRs2ConflictWithWBU)

  val needStallForRs1 = (isRs1ConflictEXUS2 || isRs1ConflictWithWBU) && (!canRs1Bypass)
  val needStallForRs2 = (isRs2ConflictEXUS2 || isRs2ConflictWithWBU) && (!canRs2Bypass)

  val needStall = needStallForRs1 || needStallForRs2 || isConflictWithLSU || isConflictWithEXUS1

  val isStall = WireDefault(needStall)
  dontTouch(isStall)

  val r1UseBypass = canRs1Bypass
  val r2UseBypass = canRs2Bypass

  val r1BypassData = Mux(isRs1ConflictEXUS2, exus2WrBackData, io.wrBackInfo.wbu.data)
  val r2BypassData = Mux(isRs2ConflictEXUS2, exus2WrBackData, io.wrBackInfo.wbu.data)

  io.outData1 := Mux(r1UseBypass, r1BypassData, io.regData1)
  io.outData2 := Mux(r2UseBypass, r2BypassData, io.regData2)

  io.needStall := needStall
}

class IDU(
  implicit p: CPUParameters)
    extends Module {
  val io = IO(new Bundle {
    val in   = Flipped(Decoupled(new Inst))
    val rvec = GPRegReqIO.ReadVecTX(2)

    val flush = Input(Bool())

    val wrBackInfo = Input(new WrBackInfoGroup)

    val out = Decoupled(new DecodedInst)
  })

  dontTouch(io)

  // TODO: handle invalid instruction

  // val fsm = InnerBusCtrl(io.in, io.out, alwaysComb = true)

  io.out.bits.viewAsSupertype(new Inst) := io.in.bits

  // alias
  val res  = io.out.bits.info
  def inst = io.in.bits.code.get

  val iinfo_dec = Module(new InstInfoDecoder())
  iinfo_dec.io.opcode                   := inst(6, 0)
  res.viewAsSupertype(new InstMetaInfo) := iinfo_dec.io.out

  // res.rd  := inst(11, 7)
  // res.rs1 := inst(19, 15)
  // res.rs2 := inst(24, 20)

  val rs1 = inst(19, 15)
  val rs2 = inst(24, 20)

  val isTypStore     = InstType.hasSame(res.typ, InstType.store)
  val isTypBranch    = InstType.hasSame(res.typ, InstType.branch)
  val isTypFencei    = InstType.hasSame(res.typ, InstType.fencei)
  // for now, system inst, ecall and mret has rd == 0
  // TODO: handle rd != 0 case
  val isNoWrBackType = isTypStore || isTypBranch || isTypFencei
  res.rdWrEn := ~isNoWrBackType

  // io.rvec.en      := true.B
  io.rvec.addr(0) := rs1
  io.rvec.addr(1) := rs2

  // fetch IMM
  val immI = Cat(Fill(21, inst(31)), inst(30, 20))
  val immS = Cat(immI(31, 5), inst(11, 8), inst(7))
  val immB = Cat(immI(31, 12), inst(7), immS(10, 1), 0.U(1.W))
  val immU = Cat(inst(31, 12), 0.U(12.W))
  val immJ = Cat(immI(31, 20), inst(19, 12), inst(20), inst(30, 21), 0.U(1.W))

  val dontcareImm = Wire(Types.UWord)
  dontcareImm := DontCare

  res.imm := MuxLookup(iinfo_dec.io.out.fmt, dontcareImm)(
    Seq(
      InstFmt.imm    -> immI,
      InstFmt.jump   -> immJ,
      InstFmt.store  -> immS,
      InstFmt.branch -> immB,
      InstFmt.upper  -> immU
    )
  )

  // res.snpc := io.in.bits.pc + 4.U

  val bypassMux = Module(new ByPassMux())
  bypassMux.io.rs1        := rs1
  bypassMux.io.rs2        := rs2
  bypassMux.io.regData1   := io.rvec.data(0)
  bypassMux.io.regData2   := io.rvec.data(1)
  bypassMux.io.wrBackInfo := io.wrBackInfo
  res.reg1                := bypassMux.io.outData1
  res.reg2                := bypassMux.io.outData2

  val needStall = bypassMux.io.needStall

  io.in.ready  := (io.out.ready && !needStall) || io.flush
  io.out.valid := io.in.valid && !needStall && !io.flush

  val dbgOutInst = WireDefault(io.in.bits.code.get)
  dontTouch(dbgOutInst)
}
