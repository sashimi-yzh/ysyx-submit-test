package top
import chisel3._
import chisel3.util._

class ysyx_26010036 extends Module {
  val io = IO(new Bundle {
    val interrupt = Input(Bool())
    val master    = new AXI4IOFlat
    val slave     = Flipped(new AXI4IOFlat)
  })

  override def localModulePrefix              = Some("ysyx_26010036")
  override def localModulePrefixAppliesToSelf = false
  dontTouch(io)

  DriveZeroSinks(io)

  val ifu = Module(new IFU())
  val ica = Module(new ICache(cacheSizeB = 32, blockSizeB = 16, assoc = 1))
  val idu = Module(new IDU())
  val exu = Module(new EXU())
  val lsu = Module(new LSU())
  val wbu = Module(new WBU())

  val exuFlush, wbuFlush = WireInit(false.B)
  val numStages          = 4
  val stallReqs          = WireDefault(VecInit(Seq.fill(numStages)(false.B)))
  val stallEns           = WireDefault(VecInit(Seq.fill(numStages)(false.B)))
  for (i <- 0 until numStages) {
    stallEns(i) := stallReqs.asUInt(numStages - 1, i).orR
  }

  // StageConnect(ifu.io.out, ica.io.in, exuFlush, stallReqs(numStages - 5), stallEns(numStages - 5))
  ica.io.in <> ifu.io.out
  StageConnect(ica.io.out, idu.io.in, exuFlush, stallReqs(numStages - 4), stallEns(numStages - 4))
  StageConnect(idu.io.out, exu.io.in, wbuFlush, stallReqs(numStages - 3), stallEns(numStages - 3))
  StageConnect(exu.io.out, lsu.io.in, wbuFlush, stallReqs(numStages - 2), stallEns(numStages - 2))
  StageConnect(lsu.io.out, wbu.io.in, false.B, stallReqs(numStages - 1), stallEns(numStages - 1))

  val gpr = Module(new RegFile())

  // gpr
  gpr.io.raddr1 := idu.io.rs1 // idu阶段读取
  gpr.io.raddr2 := idu.io.rs2
  idu.io.rdata1 := gpr.io.rdata1
  idu.io.rdata2 := gpr.io.rdata2
  gpr.io.wen    := wbu.io.wen // wbu阶段写回
  gpr.io.waddr  := wbu.io.rd
  gpr.io.wdata  := wbu.io.wdata

  val csr = Module(new CSRFile())

  // CSR
  csr.io.raddr         := idu.io.out.bits.imm // idu阶段读取
  idu.io.csrRdata      := csr.io.rdata
  csr.io.waddr         := wbu.io.in.bits.imm
  csr.io.mret          := wbu.io.mret
  csr.io.wdata         := wbu.io.csrWdata
  csr.io.wen           := wbu.io.csrWen
  wbu.io.wbuRedirectPc := csr.io.wbuRedirectPc
  csr.io.excValid      := wbu.io.excValid
  csr.io.excType       := wbu.io.excType
  csr.io.excPc         := wbu.io.in.bits.pc

  // RAW冒险处理
  val rs1Stall  = WireDefault(false.B)
  val rawExuRs1 = exu.io.out.valid && (exu.io.out.bits.rd === idu.io.rs1) && exu.io.out.bits.ctrl.regWen
  val rawLsuRs1 = lsu.io.out.valid && (lsu.io.out.bits.rd === idu.io.rs1) && lsu.io.out.bits.ctrl.regWen
  val rawWbuRs1 = wbu.io.wen && (wbu.io.rd === idu.io.rs1)
  when(idu.io.raw.rs1R) {
    when(rawExuRs1) {
      idu.io.rdata1 := exu.io.out.bits.gprWdata
      rs1Stall      := exu.io.out.bits.ctrl.rdSel === RdSel.MEM
    }
      .elsewhen(rawLsuRs1) { idu.io.rdata1 := lsu.io.out.bits.gprWdata }
      .elsewhen(rawWbuRs1) { idu.io.rdata1 := wbu.io.wdata }
  }

  val rs2Stall  = WireDefault(false.B)
  val rawExuRs2 = exu.io.out.valid && (exu.io.out.bits.rd === idu.io.rs2) && exu.io.out.bits.ctrl.regWen
  val rawLsuRs2 = lsu.io.out.valid && (lsu.io.out.bits.rd === idu.io.rs2) && lsu.io.out.bits.ctrl.regWen
  val rawWbuRs2 = wbu.io.wen && (wbu.io.rd === idu.io.rs2)
  when(idu.io.raw.rs2R) {
    when(rawExuRs2) {
      idu.io.rdata2 := exu.io.out.bits.gprWdata
      rs2Stall      := exu.io.out.bits.ctrl.rdSel === RdSel.MEM
    }.elsewhen(rawLsuRs2) { idu.io.rdata2 := lsu.io.out.bits.gprWdata }
      .elsewhen(rawWbuRs2) { idu.io.rdata2 := wbu.io.wdata }
  }

  val csrStall  = WireInit(false.B)
  val rawExuCsr = exu.io.out.valid && (exu.io.out.bits.ctrl.csrWen || exu.io.out.bits.ctrl.excValid)
  val rawLsuCsr = lsu.io.out.valid && (lsu.io.out.bits.ctrl.csrWen || lsu.io.out.bits.ctrl.excValid)
  val rawWbuCsr = wbu.io.csrWen || wbu.io.excValid
  when(idu.io.raw.csrR) {
    when(rawExuCsr || rawLsuCsr || rawWbuCsr) {
      csrStall := true.B
    }
  }
  idu.io.raw.stall := rs1Stall || rs2Stall || csrStall

  // 流水线冲刷处理
  exuFlush          := wbu.io.redirectEn || exu.io.redirectEn
  wbuFlush          := wbu.io.redirectEn
  ifu.io.redirectEn := exuFlush
  ifu.io.redirectPc := Mux(wbu.io.redirectEn, wbu.io.redirectPc, exu.io.redirectPc)


  // AXI4总线连接
  val arb   = Module(new AXI4Arbiter())
  val clint = Module(new CLINT())

  ica.io.axi <> arb.io.sIFU
  // lsu.io.axi <> arb.io.sLSU
  lsu.io.axi <> clint.io.lsu
  clint.io.out <> arb.io.sLSU
  AXI4Bridge.connect(arb.io.m, io.master)

  // fencei
  ica.io.fenceiValid := exu.io.fenceiValid

  // dpic
  val enableDpic = sys.env.getOrElse("ENABLE_DPIC", "1") == "1"
  if (enableDpic) {
    val dpic = Module(new ysyx_26010036_DPICModule())
    dpic.io.ebreak := wbu.io.excValid && wbu.io.excType === ExceptionType.Breakpoint
    dpic.io.clk    := clock.asBool

    // difftest
    dpic.io.difftest_step := RegNext(wbu.io.in.valid)
    dpic.io.nextPC        := RegEnable(Mux(wbu.io.redirectEn, wbu.io.redirectPc, wbu.io.in.bits.dpic_npc), wbu.io.in.valid)
    dpic.io.pc            := RegEnable(wbu.io.dpic_pc, wbu.io.in.valid)
    dpic.io.inst          := RegEnable(wbu.io.dpic_inst, wbu.io.in.valid)
    dpic.io.gpr           := gpr.io.regs
    dpic.io.csr           := csr.io.dpic
    dpic.io.memAddr       := RegEnable(wbu.io.dpic_memAddr, wbu.io.in.valid)
    dpic.io.memRdata      := RegEnable(wbu.io.dpic_memRdata, wbu.io.in.valid)
    dpic.io.memWdata      := RegEnable(wbu.io.dpic_memWdata, wbu.io.in.valid)
    dpic.io.memRValid     := RegEnable(wbu.io.dpic_memRValid, wbu.io.in.valid)
    dpic.io.memWValid     := RegEnable(wbu.io.dpic_memWValid, wbu.io.in.valid)
    dpic.io.tag           := RegEnable(wbu.io.dpic_tag, wbu.io.in.valid)

    // performance counter
    // dpic.io.pfm_begin    := ifu.io.out.bits.pc >= "h80000000".U && ifu.io.out.valid
    dpic.io.pfm_begin     := ifu.io.out.bits.pc >= "ha0000000".U && ifu.io.out.valid
    dpic.io.if_miss       := ica.io.dpic_miss
    dpic.io.if_finish     := ifu.io.out.fire
    dpic.io.ifu_i_flushed := false.B // todo
    dpic.io.ifu_nvalid    := !ifu.io.out.valid
    dpic.io.if_bus_req    := ica.io.axi.ar.valid && ica.io.axi.ar.ready
    dpic.io.if_bus_resp   := ica.io.axi.r.valid && ica.io.axi.r.ready && ica.io.axi.r.last
    dpic.io.ifu_tag       := ifu.io.out.bits.dpic_tag

    dpic.io.idu_raw := idu.io.raw.stall

    dpic.io.branch_correct := exu.io.out.fire && exu.io.dpic_branchCorrect

    dpic.io.lsu_r_begin  := lsu.io.axi.ar.valid && lsu.io.axi.ar.ready
    dpic.io.lsu_r_finish := lsu.io.axi.r.valid && lsu.io.axi.r.ready && lsu.io.axi.r.last
    dpic.io.lsu_w_begin  := lsu.io.axi.aw.valid && lsu.io.axi.aw.ready
    dpic.io.lsu_w_finish := lsu.io.axi.b.valid && lsu.io.axi.b.ready
    dpic.io.lsu_nvalid   := !lsu.io.in.ready

    dpic.io.wbu_valid := wbu.io.in.valid
    dpic.io.wbu_tag   := wbu.io.dpic_tag

    dpic.io.inst_r   := wbu.io.in.bits.ctrl.pcit === PfmCntInstType.R && wbu.io.in.valid
    dpic.io.inst_i   := wbu.io.in.bits.ctrl.pcit === PfmCntInstType.I && wbu.io.in.valid
    dpic.io.inst_l   := wbu.io.in.bits.ctrl.pcit === PfmCntInstType.L && wbu.io.in.valid
    dpic.io.inst_s   := wbu.io.in.bits.ctrl.pcit === PfmCntInstType.S && wbu.io.in.valid
    dpic.io.inst_b   := wbu.io.in.bits.ctrl.pcit === PfmCntInstType.B && wbu.io.in.valid
    dpic.io.inst_u   := wbu.io.in.bits.ctrl.pcit === PfmCntInstType.U && wbu.io.in.valid
    dpic.io.inst_j   := wbu.io.in.bits.ctrl.pcit === PfmCntInstType.J && wbu.io.in.valid
    dpic.io.inst_csr := wbu.io.in.bits.ctrl.pcit === PfmCntInstType.CSR && wbu.io.in.valid
    dpic.io.inst_sys := wbu.io.in.bits.ctrl.pcit === PfmCntInstType.SYS && wbu.io.in.valid
  }
}

object StageConnect {
  def apply[T <: Data](
    left:     DecoupledIO[T],
    right:    DecoupledIO[T],
    flush:    Bool = false.B,
    stallReq: Bool,
    stallEn:  Bool = false.B
  ) = {
    val arch = "pipeline"
    if (arch == "single") { right := left }
    else if (arch == "multi") { right <> left }
    else if (arch == "pipeline") {
      stallReq   := !right.ready
      left.ready := !stallEn
      right.bits := RegEnable(left.bits, !stallEn)
      val validReg = RegInit(false.B)
      right.valid := validReg

      when(flush) {
        validReg    := false.B
        right.valid := false.B
      }.elsewhen(!stallEn) {
        validReg := left.valid
      }
    }
    // else if (arch == "ooo") { right <> Queue(left, 16) }
  }
}
