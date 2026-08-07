import chisel3._
import chisel3.util._
import dto._
import top._
import xbar._
import reg._
import enums._
import axi4._
import diplomatic._
import config.Configs
import org.chipsalliance.cde.config.Parameters
import org.chipsalliance.diplomacy.lazymodule.{LazyModule, LazyModuleImp}

class Top(
  implicit p: Parameters)
    extends LazyModule {
  val xbar     = LazyModule(new XbarArbiter)
  val ifuWrap  = LazyModule(new AXI4MasterWrapper())
  val mauWrap  = LazyModule(new AXI4MasterWrapper())
  val clint    = LazyModule(new Clint)
  val extSlave = new AXI4SlaveNode(
    AXI4SlaveNodeParameters(
      AddressSet.misaligned(0, BigInt(1) << 32)
    )
  )

  val csrRegFile       = LazyModule(new CsrRegFile)
  val iduCsrWrapper    = LazyModule(new CsrRegMasterWrapper)
  val wbuCsrReqWrapper = LazyModule(new CsrRegMasterWrapper)

  xbar.node  := ifuWrap.node
  xbar.node  := mauWrap.node
  clint.node := xbar.node
  extSlave   := xbar.node

  csrRegFile.node := iduCsrWrapper.node
  csrRegFile.node := wbuCsrReqWrapper.node

  lazy val module = new LazyModuleImp(this) {
    val io                                      = IO(new Bundle {
      val interrupt = Input(Bool())
      val master    = new AXI4FlatBundle(new AXI4Parameters)
      val slave     = Flipped(new AXI4FlatBundle(new AXI4Parameters))
    })
    override def desiredName: String = wrapper.p(Configs.STUID)
    override def localModulePrefix              = Some(wrapper.p(Configs.STUID))
    override def localModulePrefixAppliesToSelf = false
    val icache                                  = Module(new InstructionCache)
    val branchPredictor                         = Module(new BranchPredictor)
    val ifu                                     = Module(new InstructionFetch)
    val idu                                     = Module(new InstructionDecode)
    val exu                                     = Module(new InstructionExecute)
    val mau                                     = Module(new MemoryAccess)
    val wbu                                     = Module(new WriteBack)
    val regFile                                 = Module(new RegFileRV32E)

    icache.io.axi <> ifuWrap.module.axi
    icache.io.req <> ifu.io.icacheReq
    icache.io.resp <> ifu.io.icacheResp
    branchPredictor.io.predict <> ifu.io.predict
    branchPredictor.io.update <> exu.io.updateBranchPredictor
    mau.io.axi <> mauWrap.module.axi

    io.master :#= extSlave.in.head._1

    val ioSlaverUnFlat = Wire(new AXI4Bundle(new AXI4Parameters))
    io.slave.fromBundleAsSlave(ioSlaverUnFlat)
    ioSlaverUnFlat.ar.ready := 0.U.asTypeOf(ioSlaverUnFlat.ar.ready)
    ioSlaverUnFlat.r.valid  := 0.U.asTypeOf(ioSlaverUnFlat.r.valid)
    ioSlaverUnFlat.r.bits   := 0.U.asTypeOf(ioSlaverUnFlat.r.bits)
    ioSlaverUnFlat.aw.ready := 0.U.asTypeOf(ioSlaverUnFlat.aw.ready)
    ioSlaverUnFlat.w.ready  := 0.U.asTypeOf(ioSlaverUnFlat.w.ready)
    ioSlaverUnFlat.b.valid  := 0.U.asTypeOf(ioSlaverUnFlat.b.valid)
    ioSlaverUnFlat.b.bits   := 0.U.asTypeOf(ioSlaverUnFlat.b.bits)

    ifu.io.idu <> idu.io.ifu
    idu.io.toEXU <> exu.io.idu
    idu.io.exuForwarding <> exu.io.forward
    idu.io.mauFowarding <> mau.io.forward
    idu.io.wbuForwarding <> wbu.io.forward
    csrRegFile.module.exception    := wbu.io.exception
    csrRegFile.module.exceptionNum := wbu.io.exceptionNum
    csrRegFile.module.mret         := wbu.io.mret
    csrRegFile.module.pc           := wbu.io.pc
    regFile.io.regReadAddr1        := idu.io.regReadAddr1
    idu.io.regReadData1            := regFile.io.regReadData1
    regFile.io.regReadAddr2        := idu.io.regReadAddr2
    idu.io.regReadData2            := regFile.io.regReadData2
    idu.io.csrTube <> iduCsrWrapper.module.csrRegOperator
    icache.io.flush                := mau.io.fence_i.valid
    ifu.io.flush                   := Mux(csrRegFile.module.pcRedirect.valid, csrRegFile.module.pcRedirect, Mux(mau.io.fence_i.valid, mau.io.fence_i, exu.io.pcRedirect))
    idu.io.flush                   := csrRegFile.module.pcRedirect.valid || exu.io.pcRedirect.valid || mau.io.fence_i.valid
    exu.io.flush                   := csrRegFile.module.pcRedirect.valid || mau.io.fence_i.valid
    exu.io.mau <> mau.io.exu
    mau.io.wbu <> wbu.io.mau
    regFile.io.wbReq <> wbu.io.RegFileReq
    wbuCsrReqWrapper.module.csrRegOperator <> wbu.io.CsrFileReq
    if (p(Configs.DebugMode)) {
      idu.io.csrMepc  := csrRegFile.module.mepc
      idu.io.csrMtvec := csrRegFile.module.mtvec
      dontTouch(wbu.io.npc)
      dontTouch(wbu.io.instruction)
    }
  }
}
