package cpu
import chisel3._
import chisel3.util._
import common_def._
import busfsm._

import regfile._
import cpu.alu._
import axi4._

import config._

/*
class EXUStageCalcOut(
  implicit p: CPUParameters)
    extends Bundle {
  val aluOut = Types.UWord

  val isTypSys = Bool()
  val isECALL  = Bool()
  val isMRET   = Bool()
  // val isEBREAK = Bool()

  val csrRdata = Types.UWord
  val csrWr    = CSRegReqIO.TX.Write

  val dinst = new DecodedInst

  val reg1AddImm = Types.UWord

  val pcAddImm = Types.UWord

  val takeBranch = Bool()

  val gprWeEn = Bool()
}
/**/
class EXUStageCalc(
  implicit p: CPUParameters)
    extends Module {
  val io = IO(new Bundle {
    val in       = Flipped(Decoupled(new DecodedInst))
    val csr_rvec = CSRegReqIO.TX.SingleRead
    val fwd      = Output(new WrBackForwardInfo)
    val flush    = Input(Bool())
    val out      = Decoupled(new EXUStageCalcOut)
  })

  val GARBAGE_UNINIT_VALUE = Wire(Types.UWord)
  GARBAGE_UNINIT_VALUE := DontCare

  io.fwd := WrBackForwardInfo(io.in)

  val alu = Module(new ALU)

  alu.io.out.ready := io.out.ready
  alu.io.in.valid  := io.in.valid

  val alu_in = alu.io.in.bits
  val dinst  = io.in.bits
  val func3t = dinst.code(14, 12)
  val func7t = dinst.code(31, 25)

  val isFmtI   = InstFmt.hasSame(dinst.info.fmt, InstFmt.imm)
  val isTypSys = InstType.hasSame(dinst.info.typ, InstType.system)

  io.out.bits.gprWeEn := dinst.info.rdWrEn

  io.in.ready  := io.out.ready || io.flush
  io.out.valid := io.in.valid && !io.flush

  val instIMM = dinst.imm

  io.out.bits.pcAddImm := dinst.pc.get + instIMM
  io.out.bits.dinst    := dinst

  // reg

  val reg_v1 = dinst.info.reg1
  val reg_v2 = dinst.info.reg2

  alu_in.src1 := reg_v1
  alu_in.src2 := Mux(isFmtI, instIMM, reg_v2)

  alu_in.is_imm := isFmtI
  alu_in.func3t := func3t
  alu_in.func7t := func7t

  io.out.bits.aluOut     := alu.io.out.bits
  io.out.bits.reg1AddImm := reg_v1 + instIMM

  // csr

  val is_mret  = dinst.code === "h30200073".U
  val is_ecall = dinst.code === "h73".U
  // val is_ebreak = dinst.code === "h00100073".U

  val outInfo = io.out.bits

  outInfo.isTypSys := isTypSys
  outInfo.isECALL  := is_ecall
  outInfo.isMRET   := is_mret
  // outInfo.isEBREAK := is_ebreak

  val csrren    = io.csr_rvec.en
  val csr_raddr = io.csr_rvec.addr
  val csr_rdata = io.csr_rvec.data

  io.out.bits.csrRdata := csr_rdata

  val csrwen    = io.out.bits.csrWr.en
  val csr_waddr = io.out.bits.csrWr.addr
  val csr_wdata = io.out.bits.csrWr.data

  object CSROp {
    val csrrw = 1.U
    val csrrs = 2.U
  }

  val isCSRRW = (func3t === CSROp.csrrw) && isTypSys
  val isCSRRS = (func3t === CSROp.csrrs) && isTypSys

  // csrren := isCSRRS || (isCSRRW && (dinst.rd =/= 0.U)) || is_ecall || is_mret
  // csrwen := isCSRRW || (isCSRRS && (reg_v1 =/= 0.U))

  csrren := isCSRRS || isCSRRW || is_ecall || is_mret
  csrwen := isCSRRW || isCSRRS

  when(isTypSys) {
    when(is_ecall) {
      // csrren    := true.B
      // csrwen    := false.B
      csr_waddr := CSRAddr.mepc
      csr_raddr := CSRAddr.mtvec

      // ecall: set mepc to pc
      // !!!note:
      // although wen = falase
      // is_ecall flag make csr to write wdata to mepc
      csr_wdata := dinst.pc.get
    }.elsewhen(is_mret) {
      csr_raddr := CSRAddr.mepc
      csr_waddr := DontCare
      csr_wdata := DontCare
    }.otherwise {
      csr_raddr := dinst.code(31, 20)
      csr_waddr := csr_raddr
      csr_wdata := Mux(
        isCSRRW,
        reg_v1,
        (csr_rdata | reg_v1)
      )
    }
  }.otherwise {
    csr_raddr := DontCare
    csr_waddr := DontCare
    csr_wdata := DontCare
  }

  // blt/bge 10x
  // bltu/bgeu 11x
  //
  // only when func3t[2] == 0 -> eq/ne
  val isLessThanU = reg_v1 < reg_v2
  val isLessThanS = (reg_v1.asSInt < reg_v2.asSInt)
  val isLessThan  = Mux(func3t(1), isLessThanU, isLessThanS)
  val branchCalc  = Mux(func3t(2), isLessThan, (reg_v1 === reg_v2))
  io.out.bits.takeBranch := Mux(func3t(0), ~branchCalc, branchCalc)
}

class EXUStageChooseNxt(
  implicit p: CPUParameters)
    extends Module {
  val io = IO(new Bundle {
    val in        = Flipped(Decoupled(new EXUStageCalcOut))
    val jmpHappen = Output(Bool())
    val isJAL     = Output(Bool())
    val predWrong = Output(Bool())
    val nxtPC     = Output(Types.UWord)
    val pc        = Output(Types.UWord)

    val fencei = Output(Bool())

    val fwd = Output(new WrBackForwardInfo)
    val out = Decoupled(new LSUInput)
  })

  io.in.ready  := io.out.ready
  io.out.valid := io.in.valid

  val dinst = io.in.bits.dinst

  val isTypLoad       = InstType.hasSame(dinst.info.typ, InstType.load)
  val isTypStore      = InstType.hasSame(dinst.info.typ, InstType.store)
  val isTypAUIPC      = InstType.hasSame(dinst.info.typ, InstType.auipc)
  val isTypJAL        = InstType.hasSame(dinst.info.typ, InstType.jal)
  val isTypJALR       = InstType.hasSame(dinst.info.typ, InstType.jalr)
  val isTypBranch     = InstType.hasSame(dinst.info.typ, InstType.branch)
  val isTypArithmetic = InstType.hasSame(dinst.info.typ, InstType.arithmetic)
  val isTypLUI        = InstType.hasSame(dinst.info.typ, InstType.lui)
  val isFenceI        = InstType.hasSame(dinst.info.typ, InstType.fencei)

  val isFmtB = InstFmt.hasSame(dinst.info.fmt, InstFmt.branch)

  val lsuInfo = io.out.bits
  lsuInfo.destAddr  := io.in.bits.reg1AddImm
  lsuInfo.isLoad    := isTypLoad
  lsuInfo.isStore   := isTypStore
  lsuInfo.func3t    := io.in.bits.dinst.code(14, 12)
  lsuInfo.storeData := io.in.bits.dinst.info.reg2
  val writeBackInfo = lsuInfo.exuWriteBack
  // writeBackInfo.csr <> io.in.bits.csrWr
  // writeBackInfo.is_ebreak     := io.in.bits.isEBREAK

  writeBackInfo.csr.en   := io.in.bits.csrWr.en
  writeBackInfo.csr.addr := io.in.bits.csrWr.addr
  writeBackInfo.csr.data30b := io.in.bits.csrWr.data(31, 2)

  writeBackInfo.csr_ecallflag := io.in.bits.isECALL

  // No consider exception
  val normalNxtPC = Wire(Types.UWord)
  val nxtPC       = Wire(Types.UWord)

  // need pc+imm:
  // auipc, jal(r), branch
  val pcAddImm = io.in.bits.pcAddImm
  val snpc     = io.in.bits.dinst.pc.get + 4.U

  writeBackInfo.gpr.en   := io.in.bits.gprWeEn
  writeBackInfo.gpr.addr := dinst.rd
  val sysInstWrBackData = io.in.bits.csrRdata

  writeBackInfo.gpr.data := Mux1H(
    Seq(
      isTypArithmetic         -> io.in.bits.aluOut,
      isTypLUI                -> dinst.imm,
      isTypAUIPC              -> pcAddImm,
      (isTypJALR || isTypJAL) -> snpc,
      io.in.bits.isTypSys     -> sysInstWrBackData
    )
  )

  val isMemOP = isTypLoad || isTypStore

  io.fwd := WrBackForwardInfo(io.in.valid, io.in.bits.dinst, ~isMemOP, writeBackInfo.gpr.data)

  writeBackInfo.iid := dinst.iid

  val isJmpCsr   = io.in.bits.isECALL || io.in.bits.isMRET
  val takeBranch = WireDefault(false.B)
  takeBranch := io.in.bits.takeBranch
  val willJmp = (isTypBranch && takeBranch) || isTypJALR || isTypJAL || isJmpCsr

  io.jmpHappen := willJmp
  io.isJAL     := isTypJAL
  // when fence.i, also treat it as jump
  // to make flush to refetch the inst nxt fence.i
  if (Config.useBTBAndBP) {
    io.predWrong := (normalNxtPC =/= dinst.predictedNextPC) || isJmpCsr || isFenceI
  } else {
    // io.predWrong := (normalNxtPC =/= snpc) || isJmpCsr || isFenceI
    io.predWrong := isJmpCsr || isFenceI || isTypJALR || isTypJAL || (isFmtB && takeBranch)
  }

  io.fencei := isFenceI && io.in.valid

  val r1AddImm = io.in.bits.reg1AddImm

  normalNxtPC := Mux(
    isTypJALR,
    (r1AddImm(31, 1) ## 0.U(1.W)),
    Mux(
      isTypJAL || (isFmtB && takeBranch),
      pcAddImm,
      snpc
    )
  )
  nxtPC       := Mux(isJmpCsr, io.in.bits.csrRdata, normalNxtPC)
  io.nxtPC    := nxtPC
  io.pc       := io.in.bits.dinst.pc.get

  val dbgIsBranch = WireDefault(isTypBranch)
  val dbgIsJALR   = WireDefault(isTypJALR)
  val dbgIsJAL    = WireDefault(isTypJAL)
  val dbgIsCSRJmp = WireDefault(isJmpCsr)
  dontTouch(dbgIsBranch)
  dontTouch(dbgIsJALR)
  dontTouch(dbgIsJAL)
  dontTouch(dbgIsCSRJmp)
}

class EXU(
  implicit p: CPUParameters)
    extends Module {
  val io = IO(new Bundle {
    val in        = Flipped(Decoupled(new DecodedInst))
    val csr_rvec  = CSRegReqIO.TX.SingleRead
    val jmpHappen = Output(Bool())
    val isJAL     = Output(Bool())

    val predWrong = Output(Bool())
    val pc        = Output(Types.UWord)
    val nxtPC     = Output(Types.UWord)

    val flush1 = Input(Bool())

    val fencei = Output(Bool())

    val fwd = Output(new WrBackForwardInfo)
    // val fwd1 = Output(new WrBackForwardInfo)
    // val fwd2 = Output(new WrBackForwardInfo)

    val out = Decoupled(new LSUInput)
  })

  def dontTouchValidReady[T <: Data](x: DecoupledIO[T]): Unit = {
    dontTouch(x.valid)
    dontTouch(x.ready)
  }

  val stageCalc      = Module(new EXUStageCalc)
  val stageChooseNxt = Module(new EXUStageChooseNxt)

  // io.fwd1 := stageCalc.io.fwd
  // io.fwd2 := stageChooseNxt.io.fwd
  //
  // dontTouchValidReady(stageCalc.io.in)
  // dontTouchValidReady(stageCalc.io.out)
  // dontTouchValidReady(stageChooseNxt.io.in)
  // dontTouchValidReady(stageChooseNxt.io.out)
  //
  // io.in <> stageCalc.io.in
  // io.out <> stageChooseNxt.io.out
  //
  // stageCalc.io.csr_rvec <> io.csr_rvec
  // io.jmpHappen := stageChooseNxt.io.jmpHappen
  // io.isJAL     := stageChooseNxt.io.isJAL
  // io.predWrong := stageChooseNxt.io.predWrong
  // io.nxtPC     := stageChooseNxt.io.nxtPC
  // io.pc        := stageChooseNxt.io.pc
  // io.fencei    := stageChooseNxt.io.fencei
  //
  // stageCalc.io.flush := io.flush1
  //
  // pipelineConnect(stageCalc.io.out, stageChooseNxt.io.in, stageChooseNxt.io.out)

  stageCalc.io.in <> io.in
  stageCalc.io.csr_rvec <> io.csr_rvec
  stageCalc.io.flush := false.B // for one stage EXU, no need to flush stageCalc

  stageChooseNxt.io.in <> stageCalc.io.out
  io.jmpHappen := stageChooseNxt.io.jmpHappen
  io.isJAL     := stageChooseNxt.io.isJAL
  io.predWrong := stageChooseNxt.io.predWrong
  io.nxtPC     := stageChooseNxt.io.nxtPC
  io.pc        := stageChooseNxt.io.pc
  io.fencei    := stageChooseNxt.io.fencei

  io.fwd := stageChooseNxt.io.fwd

  io.out <> stageChooseNxt.io.out
}*/

class EXU(
  implicit p: CPUParameters)
    extends Module {
  val io = IO(new Bundle {
    val in        = Flipped(Decoupled(new DecodedInst))
    val csr_rvec  = CSRegReqIO.TX.SingleRead
    val jmpHappen = Output(Bool())
    val isJAL     = Output(Bool())

    val predWrong = Output(Bool())
    val pc        = Output(Types.UWord)
    val nxtPC     = Output(Types.UWord)

    val flush1 = Input(Bool())

    val fencei = Output(Bool())
    val fwd    = Output(new WrBackForwardInfo)
    val out    = Decoupled(new LSUInput)
  })

  val dinst  = io.in.bits
  val func3t = dinst.code.func3t
  val func7t = dinst.code.func7t
  val imm    = dinst.imm
  val pc     = dinst.pc.get

  val isFmtI   = InstFmt.hasSame(dinst.info.fmt, InstFmt.imm)
  val isFmtB   = InstFmt.hasSame(dinst.info.fmt, InstFmt.branch)
  val isTypSys = InstType.hasSame(dinst.info.typ, InstType.system)

  val isTypLoad       = InstType.hasSame(dinst.info.typ, InstType.load)
  val isTypStore      = InstType.hasSame(dinst.info.typ, InstType.store)
  val isTypAUIPC      = InstType.hasSame(dinst.info.typ, InstType.auipc)
  val isTypJAL        = InstType.hasSame(dinst.info.typ, InstType.jal)
  val isTypJALR       = InstType.hasSame(dinst.info.typ, InstType.jalr)
  val isTypBranch     = InstType.hasSame(dinst.info.typ, InstType.branch)
  val isTypArithmetic = InstType.hasSame(dinst.info.typ, InstType.arithmetic)
  val isTypLUI        = InstType.hasSame(dinst.info.typ, InstType.lui)
  val isFenceI        = InstType.hasSame(dinst.info.typ, InstType.fencei)

  val reg_v1 = dinst.info.reg1
  val reg_v2 = dinst.info.reg2

  val alu = Module(new ALU)

  alu.io.in.src1   := reg_v1
  alu.io.in.src2   := Mux(isFmtI, imm, reg_v2)
  alu.io.in.is_imm := isFmtI
  alu.io.in.func3t := func3t
  alu.io.in.func7t := func7t

  val aluOut = alu.io.out

  alu.io.isBranch := isTypBranch

  def calcBranchByALU = {
    val isLessThanU = alu.io.sltuRes
    val isLessThanS = alu.io.sltRes
    val isLessThan  = Mux(func3t(1), isLessThanU, isLessThanS)
    val branchCalc  = Mux(func3t(2), isLessThan, reg_v1 === reg_v2)
    Mux(func3t(0), ~branchCalc, branchCalc)
  }

  def calcBranchBySub = {
    val W   = reg_v1.getWidth
    val sub = reg_v1 - reg_v2

    val isEqual = sub === 0.U

    val v1_msb  = reg_v1(W - 1)
    val v2_msb  = reg_v2(W - 1)
    val res_msb = sub(W - 1)

    val lessThan   = Mux(v1_msb === v2_msb, res_msb, Mux(func3t(1), v2_msb, v1_msb))
    val branchCalc = Mux(func3t(2), lessThan, isEqual)
    Mux(func3t(0), ~branchCalc, branchCalc)
  }

  def calcBranchByCompare = {
    val isLessThanU = reg_v1 < reg_v2
    val isLessThanS = (reg_v1.asSInt < reg_v2.asSInt)
    val isLessThan  = Mux(func3t(1), isLessThanU, isLessThanS)
    val branchCalc  = Mux(func3t(2), isLessThan, (reg_v1 === reg_v2))
    Mux(func3t(0), ~branchCalc, branchCalc)
  }

  val takeBranch = calcBranchByCompare

  val is_mret  = dinst.code.eq("h30200073".U)
  val is_ecall = dinst.code.eq("h73".U)

  object CSROp {
    val csrrw = 1.U
    val csrrs = 2.U
  }
  val isCSRRW = (func3t === CSROp.csrrw) && isTypSys
  val isCSRRS = (func3t === CSROp.csrrs) && isTypSys

  val csr_rdata = io.csr_rvec.data
  io.csr_rvec.en := true.B // (isCSRRS || isCSRRW || is_ecall || is_mret) && io.in.valid

  val csrWr = io.out.bits.exuWriteBack.csr

  val csrWrData = Wire(Types.UWord)

  io.out.bits.exuWriteBack.csr_ecallflag := is_ecall

  when(isTypSys) {
    when(is_ecall) {
      io.csr_rvec.addr := CSRAddr.mtvec
      csrWr.en         := true.B
      csrWr.addr       := CSRAddr.mepc
      csrWrData        := dinst.pc.get
    }.elsewhen(is_mret) {
      io.csr_rvec.addr := CSRAddr.mepc
      csrWr.en         := false.B
      csrWr.addr       := DontCare
      csrWrData        := DontCare
    }.otherwise {
      val csrAddr = dinst.code.get(31, 20)
      io.csr_rvec.addr := csrAddr
      // csrWr.en         := (isCSRRW || (isCSRRS && (reg_v1 =/= 0.U)))
      csrWr.en         := isCSRRW || isCSRRS
      csrWr.addr       := csrAddr
      csrWrData        := Mux(isCSRRW, reg_v1, (csr_rdata | reg_v1))
    }
  }.otherwise {
    io.csr_rvec.addr := DontCare
    csrWr.en         := false.B
    csrWr.addr       := DontCare
    csrWrData        := DontCare
  }

  csrWr.data30b := csrWrData(31, 2)

  val snpc       = pc + 4.U
  val pcAddImm   = pc + imm
  val reg1AddImm = reg_v1 + imm

  val normalNxtPC = Mux(
    isTypJALR,
    (reg1AddImm(31, 1) ## 0.U(1.W)),
    Mux(
      isTypJAL || (isTypBranch && takeBranch),
      pcAddImm,
      snpc
    )
  )

  val isJmpCsr   = (is_ecall || is_mret) && isTypSys
  val finalNxtPC = Mux(isJmpCsr, csr_rdata, normalNxtPC)

  val willJmp = ((isTypBranch && takeBranch) || isTypJALR || isTypJAL || isJmpCsr) && io.in.valid

  io.jmpHappen := willJmp
  io.isJAL     := isTypJAL
  io.pc        := pc
  io.nxtPC     := finalNxtPC
  io.fencei    := isFenceI && io.in.valid

  if (Config.useBTBAndBP) {
    io.predWrong := (normalNxtPC =/= dinst.predictedNextPC) || isJmpCsr || isFenceI
  } else {
    io.predWrong := isJmpCsr || isFenceI || isTypJALR || isTypJAL || (isTypBranch && takeBranch)
  }

  val gprWrData = Mux1H(
    Seq(
      isTypArithmetic         -> aluOut,
      isTypLUI                -> imm,
      isTypAUIPC              -> pcAddImm,
      (isTypJALR || isTypJAL) -> snpc,
      isTypSys                -> csr_rdata
    )
  )

  io.out.valid := io.in.valid  // && !io.flush1
  io.in.ready  := io.out.ready // || io.flush1

  val lsuInfo = io.out.bits
  lsuInfo.destAddr  := reg1AddImm
  lsuInfo.isLoad    := isTypLoad
  lsuInfo.isStore   := isTypStore
  lsuInfo.func3t    := func3t
  lsuInfo.storeData := reg_v2

  val writeBackInfo = lsuInfo.exuWriteBack
  writeBackInfo.iid      := dinst.iid
  writeBackInfo.gpr.en   := dinst.info.rdWrEn && io.in.valid
  writeBackInfo.gpr.addr := dinst.rd
  writeBackInfo.gpr.data := gprWrData

  val isMemOP = isTypLoad || isTypStore
  io.fwd := WrBackForwardInfo(io.in.valid, dinst, !isMemOP, gprWrData)

  val dbgIsBranch = WireDefault(isTypBranch)
  val dbgIsJALR   = WireDefault(isTypJALR)
  val dbgIsJAL    = WireDefault(isTypJAL)
  val dbgIsCSRJmp = WireDefault(isJmpCsr)
  dontTouch(dbgIsBranch)
  dontTouch(dbgIsJALR)
  dontTouch(dbgIsJAL)
  dontTouch(dbgIsCSRJmp)
}

class EXUForDifftest(
  implicit p: CPUParameters)
    extends Module {
  val io = IO(new Bundle {
    val in     = Flipped(Decoupled(new DecodedInst))
    val actual = new Bundle {
      val inReady  = Input(Bool())
      val pc       = Input(Types.UWord)
      val nxtPC    = Input(Types.UWord)
      val memAddr  = Input(Types.UWord)
      val outValid = Input(Bool())
    }
    val out    = Decoupled(new LSUInputForDifftest)
  })
  io.in.ready := io.actual.inReady
  io.out.valid := io.actual.outValid

  val outInfo = io.out.bits
  outInfo.isLoad   := InstType.hasSame(io.in.bits.info.typ, InstType.load)
  outInfo.isStore  := InstType.hasSame(io.in.bits.info.typ, InstType.store)
  outInfo.pc       := io.actual.pc
  outInfo.nxtPC    := io.actual.nxtPC
  outInfo.isEBreak := io.in.bits.code.eq("h00100073".U)
  outInfo.destAddr := io.actual.memAddr
}
