package npc


import chisel3._
import chisel3.util._
import npc.common._
import npc.Constants._
import npc.devices.{CLINT}

class ysyx_24100012 extends Module { 
  implicit val conf = Config()
  val io = IO(new CoreIo())

  dontTouch(io)
  val core = Module(new Core())
  chisel3.experimental.annotate(
    new chisel3.experimental.ChiselAnnotation {
      override def toFirrtl = sifive.enterprise.firrtl
        .NestedPrefixModulesAnnotation(core.toTarget, "ysyx_24100012_", true)
    }
  )
  core.io.core <> io
  val halt = RegInit(false.B)
  halt := core.io.ebreak
  dontTouch(halt)

}

class CoreIo(implicit val conf: Config) extends Bundle 
{
  val interrupt = Input(Bool())
  val master = new AXI4LiteIo()
  val slave = Flipped(new AXI4LiteIo())
}

class Core(implicit val conf: Config)extends Module
{
  def pipelineConnect[T <: Data, T2 <: Data](prevOut: DecoupledIO[T],
    thisIn: DecoupledIO[T]) = {
      prevOut.ready := thisIn.ready
      thisIn.bits := RegEnable(prevOut.bits,0.U.asTypeOf(chiselTypeOf(prevOut.bits)),prevOut.valid && thisIn.ready )
      thisIn.valid := prevOut.valid && thisIn.ready
  }
  val io = IO(new Bundle {
    val ebreak = Output(Bool())
    val core =  new CoreIo()
  })
  val inst_fetch  = Module(new InstFetch())
  val arbiter     = Module(new AXI4LiteRRArbiter(2))
  val decoder     = Module(new Decoder())
  val reg_file    = Module(new RegFile())
  val exu         = Module(new EXU())
  val lsu         = Module(new LSU())
  val wbu         = Module(new WBU())
  val clint       = Module(new CLINT())


  clint.io.clock := clock
  clint.io.reset := reset
  clint.io.in <> lsu.io.clintIO  

  arbiter.io.axi_port <> io.core.master
  arbiter.io.ports(DPORT) <> lsu.io.port  
  arbiter.io.ports(IPORT) <> inst_fetch.io.port 

  inst_fetch.io.ctl <> decoder.io.ctl_sign
  inst_fetch.io.exception_target := lsu.io.exception_target
  inst_fetch.io.exu_in <>  exu.io.ifu_out
  
  decoder.io.reg_in <> reg_file.io.out
  decoder.io.dec_reg <> reg_file.io.dec

  exu.io.ctl <> decoder.io.ctl_sign
  exu.io.to_ctl <> decoder.io.exe_ctl 

  lsu.io.to_ctl <> decoder.io.lsu_ctl

  wbu.io.reg <> reg_file.io.wb
  wbu.io.to_ctl <> decoder.io.wb_ctl
  io.ebreak := wbu.io.ebreak
  dontTouch(io.ebreak)

  pipelineConnect(inst_fetch.io.ifu_dec, decoder.io.ifu_dec)
  pipelineConnect(decoder.io.dec_exe, exu.io.dec_exe)
  pipelineConnect(exu.io.exe_mem, lsu.io.exe_mem)
  pipelineConnect(lsu.io.mem_wb, wbu.io.mem_wb)

  // io.halt :=  exu.io.ebreak would lead to conflicts in same cycle
  val halt = Mux(wbu.io.ebreak, true.B, false.B)
  io.core.slave.ar.ready := false.B
  io.core.slave.r.data := 0.U
  io.core.slave.r.resp := 0.U
  io.core.slave.r.valid := false.B
  io.core.slave.r.last := false.B
  io.core.slave.r.id := 0.U
  io.core.slave.aw.ready := false.B
  io.core.slave.w.ready := false.B
  io.core.slave.b.valid := false.B
  io.core.slave.b.resp := 0.U
  io.core.slave.b.id := 0.U
  io.core.master.ar.id := 0.U

  // ///// debug port
  if (conf.ENABLE_DEBUG) {
    val debug = Module(new DebugPort())
    val perfEvent = Module(new PerfEventPort())
    debug.io.clock := clock
    debug.io.reset := reset
    debug.io.halt := halt
    debug.io.pc := inst_fetch.io.ifu_dec.bits.pc
    debug.io.mem_pc := lsu.io.mem_wb.bits.pc
    debug.io.wb_pc := wbu.io.wb_pc 
    debug.io.inst := inst_fetch.io.ifu_dec.bits.inst
    debug.io.wb_valid := wbu.io.mem_wb.bits.mem_resp_valid
    debug.io.lsu_port := wbu.io.mem_wb.bits.debug
    debug.io.wb_inst := 0.U
    
    perfEvent.io.clock      := clock
    perfEvent.io.reset      := reset
    perfEvent.io.ifu_port   := inst_fetch.io.debug
    perfEvent.io.ctl_port   := decoder.io.debug
    perfEvent.io.lsu_port   := lsu.io.debug
    perfEvent.io.wbu_port   := wbu.io.debug
  }
}


