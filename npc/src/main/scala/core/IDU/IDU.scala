package top

import chisel3._
import chisel3.util._

import RV32EInstr._
class IDU2EXU extends ICA2IDU {
  val rd       = UInt(5.W)
  val imm      = UInt(32.W)
  // val pc4 = UInt(32.W)
  val gprWdata = UInt(32.W)

  val ctrl   = new CtrlBundle
  val rdata1 = UInt(32.W)
  val rdata2 = UInt(32.W)
  val op1    = UInt(32.W)
  val op2    = UInt(32.W)

}
class IDU extends Module {
  val io = IO(new Bundle {
    val in       = Flipped(Decoupled(new ICA2IDU))
    val out      = Decoupled(new IDU2EXU)
    val rs1      = Output(UInt(5.W))
    val rs2      = Output(UInt(5.W))
    val rdata1   = Input(UInt(32.W))
    val rdata2   = Input(UInt(32.W))
    val csrRdata = Input(UInt(32.W))

    val raw = new RAWIO
  })
  BundleConnect(io.in.bits, io.out.bits)

  val inst = io.in.bits.inst

  val rd  = inst(11, 7)
  val rs1 = inst(19, 15)
  val rs2 = inst(24, 20)

  val immI = inst(31, 20).asSInt.pad(32).asUInt
  val immS = Cat(inst(31, 25), inst(11, 7)).asSInt.pad(32).asUInt
  val immB = Cat(inst(31), inst(7), inst(30, 25), inst(11, 8), 0.U(1.W)).asSInt.pad(32).asUInt
  val immU = Cat(inst(31, 12), 0.U(12.W)).asSInt.pad(32).asUInt
  val immJ = Cat(inst(31), inst(19, 12), inst(20), inst(30, 21), 0.U(1.W)).asSInt.pad(32).asUInt

  val baseR      = Ctrl(op1Sel = Op1Sel.RS1, op2Sel = Op2Sel.RS2, rdSel = RdSel.ALU, regWen = true.B, pcit = PfmCntInstType.R)
  val baseI      = Ctrl(immSel = ImmSel.I, op1Sel = Op1Sel.RS1, op2Sel = Op2Sel.IMM, rdSel = RdSel.ALU, regWen = true.B, pcit = PfmCntInstType.I)
  val baseLoad   = Ctrl(immSel = ImmSel.I, op1Sel = Op1Sel.RS1, op2Sel = Op2Sel.IMM, rdSel = RdSel.MEM, regWen = true.B, memR = true.B, aluOp = AluOp.ADD, pcit = PfmCntInstType.L)
  val baseStore  = Ctrl(immSel = ImmSel.S, op1Sel = Op1Sel.RS1, op2Sel = Op2Sel.IMM, memWen = true.B, aluOp = AluOp.ADD, pcit = PfmCntInstType.S)
  val baseBranch = Ctrl(immSel = ImmSel.B, pcSel = PcSel.BRANCH, pcit = PfmCntInstType.B)

  val decodeTable = Array(
    // R-type
    ADD  -> baseR.copy(aluOp = AluOp.ADD).toList,
    SUB  -> baseR.copy(aluOp = AluOp.SUB).toList,
    XOR  -> baseR.copy(aluOp = AluOp.XOR).toList,
    OR   -> baseR.copy(aluOp = AluOp.OR).toList,
    AND  -> baseR.copy(aluOp = AluOp.AND).toList,
    SLL  -> baseR.copy(aluOp = AluOp.LL).toList,
    SRL  -> baseR.copy(aluOp = AluOp.RL).toList,
    SRA  -> baseR.copy(aluOp = AluOp.RA).toList,
    SLT  -> baseR.copy(aluOp = AluOp.LT).toList,
    SLTU -> baseR.copy(aluOp = AluOp.LTU).toList,

    // I-type
    ADDI  -> baseI.copy(aluOp = AluOp.ADD).toList,
    ANDI  -> baseI.copy(aluOp = AluOp.AND).toList,
    ORI   -> baseI.copy(aluOp = AluOp.OR).toList,
    XORI  -> baseI.copy(aluOp = AluOp.XOR).toList,
    SLLI  -> baseI.copy(aluOp = AluOp.LL).toList,
    SRLI  -> baseI.copy(aluOp = AluOp.RL).toList,
    SRAI  -> baseI.copy(aluOp = AluOp.RA).toList,
    SLTI  -> baseI.copy(aluOp = AluOp.LT).toList,
    SLTIU -> baseI.copy(aluOp = AluOp.LTU).toList,

    // Loads
    LB  -> baseLoad.copy(memLen = MemLen.BYTE, memSext = true.B).toList,
    LH  -> baseLoad.copy(memLen = MemLen.HALF, memSext = true.B).toList,
    LW  -> baseLoad.copy(memLen = MemLen.WORD).toList,
    LBU -> baseLoad.copy(memLen = MemLen.BYTE).toList,
    LHU -> baseLoad.copy(memLen = MemLen.HALF).toList,

    // Stores
    SB -> baseStore.copy(memLen = MemLen.BYTE).toList,
    SH -> baseStore.copy(memLen = MemLen.HALF).toList,
    SW -> baseStore.copy(memLen = MemLen.WORD).toList,

    // Branches
    BEQ  -> baseBranch.copy(brOp = BranchOp.EQ).toList,
    BNE  -> baseBranch.copy(brOp = BranchOp.NEQ).toList,
    BLT  -> baseBranch.copy(brOp = BranchOp.LT).toList,
    BGE  -> baseBranch.copy(brOp = BranchOp.GE).toList,
    BLTU -> baseBranch.copy(brOp = BranchOp.LTU).toList,
    BGEU -> baseBranch.copy(brOp = BranchOp.GEU).toList,

    // U-type
    LUI   -> Ctrl(immSel = ImmSel.U, rdSel = RdSel.IMM, regWen = true.B, pcit = PfmCntInstType.U).toList,
    AUIPC -> Ctrl(immSel = ImmSel.U, op1Sel = Op1Sel.PC, op2Sel = Op2Sel.IMM, rdSel = RdSel.ALU, regWen = true.B, aluOp = AluOp.ADD, pcit = PfmCntInstType.U).toList,

    // Jumps
    JAL  -> Ctrl(immSel = ImmSel.J, regWen = true.B, rdSel = RdSel.PC4, pcSel = PcSel.IMM, pcit = PfmCntInstType.J).toList,
    JALR -> Ctrl(immSel = ImmSel.I, rdSel = RdSel.PC4, regWen = true.B, pcSel = PcSel.RS1, pcit = PfmCntInstType.J).toList,

    // CSR
    CSRRW -> Ctrl(immSel = ImmSel.I, csrWen = true.B, rdSel = RdSel.CSR, regWen = true.B, csrSel = CsrSel.RS1, pcit = PfmCntInstType.CSR).toList,
    CSRRS -> Ctrl(
      immSel = ImmSel.I,
      csrWen = true.B,
      rdSel = RdSel.CSR,
      regWen = true.B,
      csrSel = CsrSel.ALU,
      aluOp = AluOp.OR,
      op1Sel = Op1Sel.RS1,
      op2Sel = Op2Sel.CSR,
      pcit = PfmCntInstType.CSR
    ).toList,

    // SYSTEM
    EBREAK -> Ctrl(excValid = true.B, excType = ExceptionType.Breakpoint, pcit = PfmCntInstType.SYS).toList,
    ECALL  -> Ctrl(excValid = true.B, excType = ExceptionType.EcallM, pcit = PfmCntInstType.SYS).toList,
    MRET   -> Ctrl(mret = true.B, pcit = PfmCntInstType.SYS).toList,
    FENCEI -> Ctrl(fencei = true.B, pcSel = PcSel.NEXT).toList
  )

  val defaultCtrl = Ctrl(excValid = true.B, excType = ExceptionType.IllegalInstruction).toList
  val ctrlSignals = ListLookup(inst, defaultCtrl, decodeTable)

  val ctrl = Wire(new CtrlBundle)
  (ctrl.getElements.zip(ctrlSignals.reverse)).foreach { case (port, sig) =>
    port := sig.asTypeOf(port)
  }
  io.out.bits.ctrl := ctrl
  // imm
  io.out.bits.imm := DontCare
  switch(ctrl.immSel) {
    is(ImmSel.I) { io.out.bits.imm := immI }
    is(ImmSel.S) { io.out.bits.imm := immS }
    is(ImmSel.B) { io.out.bits.imm := immB }
    is(ImmSel.U) { io.out.bits.imm := immU }
    is(ImmSel.J) { io.out.bits.imm := immJ }
  }

  // op
  io.out.bits.op1 := DontCare
  switch(ctrl.op1Sel) {
    is(Op1Sel.RS1) { io.out.bits.op1 := io.rdata1 }
    is(Op1Sel.PC) { io.out.bits.op1 := io.in.bits.pc }
  }
  io.out.bits.op2 := DontCare
  switch(ctrl.op2Sel) {
    is(Op2Sel.RS2) { io.out.bits.op2 := io.rdata2 }
    is(Op2Sel.IMM) { io.out.bits.op2 := io.out.bits.imm }
    is(Op2Sel.CSR) { io.out.bits.op2 := io.csrRdata }
  }

  io.out.bits.gprWdata := DontCare
  switch(ctrl.rdSel) {

    is(RdSel.IMM) { io.out.bits.gprWdata := immU }
    is(RdSel.CSR) { io.out.bits.gprWdata := io.csrRdata }
  }

  io.rs1             := rs1
  io.rs2             := rs2
  io.out.bits.rd     := rd
  io.out.bits.pc     := io.in.bits.pc
  io.out.bits.rdata1 := io.rdata1
  io.out.bits.rdata2 := io.rdata2

  // RAW处理
  io.raw.rs1R := rs1 =/= 0.U && (
    ctrl.op1Sel === Op1Sel.RS1 ||
      ctrl.csrSel === CsrSel.RS1 ||
      ctrl.pcSel === PcSel.BRANCH ||
      ctrl.pcSel === PcSel.RS1
  )
  io.raw.rs2R := rs2 =/= 0.U && (
    ctrl.op2Sel === Op2Sel.RS2 ||
      ctrl.memWen ||
      ctrl.pcSel === PcSel.BRANCH
  )
  io.raw.csrR := ctrl.op2Sel === Op2Sel.CSR || ctrl.rdSel === RdSel.CSR

  io.out.valid := io.in.valid && !io.raw.stall
  io.in.ready  := !io.raw.stall

  when(io.in.bits.excValid) {
    io.out.bits.ctrl.excType  := io.in.bits.excType
    io.out.bits.ctrl.excValid := true.B
  }
}

class RAWIO extends Bundle {
  val rs1R = Output(Bool())
  val rs2R = Output(Bool())
  val csrR = Output(Bool())

  val stall = Input(Bool())

}
