package sirius

import chisel3._
import chisel3.util._
import chisel3.experimental.dataview._

// Trap
class TrapIO(implicit private val cfg: CoreConfig) extends Bundle {
  val isTrap = Output(Bool())
  // val cause = Output(UInt(cfg.mxlen.W))
  val cause = Output(UInt(5.W))
}

// 数据载荷
class IfuPayload(implicit private val cfg: CoreConfig) extends Bundle {
  val trap = new TrapIO
  val ifu = new Bundle {
    val pcLo = UInt(cfg.predTargetWidth.W)
    val debugPc = UInt(cfg.xlen.W)
    val inst = UInt(cfg.xlen.W)
    // val staticNextPc = UInt(cfg.xlen.W)
    val predTaken = Bool()
    // val predTarget = UInt(cfg.xlen.W)
    val predTarget = UInt(cfg.predTargetWidth.W)
    val isC = Bool()
  }
}

class IduPayload(implicit private val cfg: CoreConfig) extends IfuPayload {
  val idu = new Bundle {
    val rs1Data = UInt(cfg.xlen.W)
    val rs2Data = UInt(cfg.xlen.W)
    val wAddr = UInt(cfg.registerAddrWidth.W)
    val imm = UInt(cfg.xlen.W)
    val csrAddr = CsrEnum()
    val immNotZero = Bool()
  }
}

class ExuPayload(implicit private val cfg: CoreConfig) extends IduPayload {
  val exu = new Bundle {
    val aluOut  = UInt(cfg.xlen.W)
    // val csrData = UInt(cfg.mxlen.W)
    val jumpTarget = UInt(cfg.xlen.W)
    val predTargetMayErr = Bool()
  }
}

class LsuPayload(implicit private val cfg: CoreConfig) extends ExuPayload {
  val lsu = new Bundle {
    // val loadData = UInt(cfg.xlen.W)
    val regWData = UInt(cfg.xlen.W)
    val formal = Option.when(cfg.formal)(new rvspeccore.core.MemIO()(cfg.xlen))
  }
}

// 控制信号
class WbuCtrl(implicit private val cfg: CoreConfig) extends Bundle {
  val wbuCtrl = new CtrlSignals().wb
  // val debugCtrl = Option.when(cfg.isDebug)(new CtrlSignals().debug)
}

class LsuCtrl(implicit private val cfg: CoreConfig) extends WbuCtrl {
  val lsuCtrl = new CtrlSignals().ls
}

class ExuCtrl(implicit private val cfg: CoreConfig) extends LsuCtrl {
  val exuCtrl = new CtrlSignals().ex
}

class GlobalCtrl(implicit private val cfg: CoreConfig) extends Bundle {
  val globalCtrl = new CtrlSignals().global
}

// IO
class IfuToIduIO(implicit private val cfg: CoreConfig) extends Bundle {
  val ifuPayload = Output(new IfuPayload)
}

class IduToExuIO(implicit private val cfg: CoreConfig) extends Bundle {
  val iduPayload = Output(new IduPayload)
  val ctrl = Output(new ExuCtrl)
}

class ExuToLsuIO(implicit private val cfg: CoreConfig) extends Bundle {
  val exuPayload = Output(new ExuPayload)
  val ctrl = Output(new LsuCtrl)
}

class LsuToWbuIO(implicit private val cfg: CoreConfig) extends Bundle {
  val lsuPayload = Output(new LsuPayload)
  val ctrl = Output(new WbuCtrl)
  val debug = Option.when(cfg.isDebug)(Output(new Bundle {
    val isJump = Bool()
    val jumpTarget = UInt(cfg.xlen.W)
  }))
}

// 访问外部
class IfuToMemIO(implicit private val cfg: CoreConfig) extends Bundle {
  val reqValid = Output(Bool())
  val reqReady = Input(Bool())
  val respValid = Input(Bool())
  val respReady = Output(Bool())
  val rAddr = Output(UInt(cfg.xlen.W))
  val rData = Input(UInt(cfg.xlen.W))
}

class IfuToBpuIO(implicit private val cfg: CoreConfig) extends Bundle {
  val pc = Output(UInt(cfg.xlen.W))
  val taken = Input(Bool())
  val target = Input(UInt(cfg.xlen.W))
}

class IduToRegFileIO(implicit private val cfg: CoreConfig) extends Bundle {
  val rAddr = Output(Vec(2, UInt(cfg.registerAddrWidth.W)))
  val rData = Input(Vec(2, UInt(cfg.xlen.W)))
}

class ExuToCsrIO(implicit private val cfg: CoreConfig) extends Bundle {
  val rAddr = Output(CsrEnum()) 
  val rData = Input(UInt(cfg.mxlen.W))
}

class LsuToMemIO(implicit private val cfg: CoreConfig) extends Bundle {
  val reqValid = Output(Bool())
  val reqReady = Input(Bool())
  val respValid = Input(Bool())
  val respReady = Output(Bool())
  val addr = Output(UInt(cfg.xlen.W))
  val rData = Input(UInt(cfg.xlen.W))
  val wData = Output(UInt(cfg.xlen.W))
  val wMask = Output(UInt((cfg.xlen >> 3).W))
  val wEn   = Output(Bool())
}

class WbuToRegFileIO(implicit private val cfg: CoreConfig) extends Bundle {
  val wEn   = Output(Bool())
  val wAddr = Output(UInt(cfg.registerAddrWidth.W))
  val wData = Output(UInt(cfg.xlen.W))
}

class LsuToBpuIO(implicit private val cfg: CoreConfig) extends Bundle {
  val update = Output(Bool())
  val isCtrlInst = Output(Bool())
  val realTaken = Output(Bool())
  val predTaken = Output(Bool())
  val pc = Output(UInt(cfg.xlen.W))
  val target = Output(UInt(cfg.xlen.W))
}

class WbuToCsrIO(implicit private val cfg: CoreConfig) extends Bundle {
  val rAddr = Output(CsrEnum()) 
  val rData = Input(UInt(cfg.mxlen.W))

  val wEn = Output(Bool())
  val wAddr = Output(CsrEnum()) 
  val wData = Output(UInt(cfg.mxlen.W))
  val pc = Output(UInt(cfg.xlen.W))
  val isTrap = Output(Bool())
  val causeNum = Output(UInt(cfg.mxlen.W))
  val mtvec = Input(UInt(cfg.mxlen.W))
  val mepc = Input(UInt(cfg.mxlen.W))
}

class PipelineCtrlIO(implicit private val cfg: CoreConfig) extends Bundle {
  val isJump = Output(Bool())
  val target = Output(UInt(cfg.xlen.W))
}
