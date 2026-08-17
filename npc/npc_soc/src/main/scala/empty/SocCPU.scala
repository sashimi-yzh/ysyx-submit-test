package empty
import chisel3._
import chisel3.util._
import chisel3.layer._

class AXI_Flatten extends Bundle {
  val awready = Input(Bool())
  val awvalid = Output(Bool())
  val awaddr = Output(UInt(32.W))
  val awid = Output(UInt(4.W))
  val awlen = Output(UInt(8.W))
  val awsize = Output(UInt(3.W))
  val awburst = Output(UInt(2.W))

  val wready = Input(Bool())
  val wvalid = Output(Bool())
  val wdata = Output(UInt(32.W))
  val wstrb = Output(UInt(4.W))
  val wlast = Output(Bool())

  val bready = Output(Bool())
  val bvalid = Input(Bool())
  val bresp = Input(UInt(2.W))
  val bid = Input(UInt(4.W))

  val arready = Input(Bool())
  val arvalid = Output(Bool())
  val araddr = Output(UInt(32.W))
  val arid = Output(UInt(4.W))
  val arlen = Output(UInt(8.W))
  val arsize = Output(UInt(3.W))
  val arburst = Output(UInt(2.W))

  val rready = Output(Bool())
  val rvalid = Input(Bool())
  val rresp = Input(UInt(2.W))
  val rdata = Input(UInt(32.W))
  val rlast = Input(Bool())
  val rid = Input(UInt(4.W))

}

class Ebreaker extends ExtModule {
  val clock = IO(Input(Clock()))
  val reset = IO(Input(Reset()))
  val ebreak = IO(Input(Bool()))
}
class AXI_Checker extends ExtModule {
  val clock = IO(Input(Clock()))
  val reset = IO(Input(Reset()))
  val bready = IO(Input(Bool()))
  val bvalid = IO(Input(Bool()))
  val bresp = IO(Input(UInt(2.W)))
  val rready = IO(Input(Bool()))
  val rvalid = IO(Input(Bool()))
  val rresp = IO(Input(UInt(2.W)))
}

class mtracer_soc extends ExtModule {
  val clock = IO(Input(Clock()))
  val reset = IO(Input(Reset()))
  val arvalid = IO(Input(Bool()))
  val arready = IO(Input(Bool()))
  val arid = IO(Input(UInt(4.W)))
  val araddr = IO(Input(UInt(32.W)))
  val arlen = IO(Input(UInt(8.W)))
  val arsize = IO(Input(UInt(3.W)))
  val awvalid = IO(Input(Bool()))
  val awready = IO(Input(Bool()))
  val awid = IO(Input(UInt(4.W)))
  val awaddr = IO(Input(UInt(32.W)))
  val awlen = IO(Input(UInt(8.W)))
  val awsize = IO(Input(UInt(3.W)))
}

class Inst_Retire extends ExtModule {
  val clock = IO(Input(Clock()))
  val reset = IO(Input(Reset()))
  val retire = IO(Input(Bool()))
  val inst = IO(Input(UInt(32.W)))
  val pc = IO(Input(UInt(32.W)))
}

object Verifying extends Layer(LayerConfig.Inline)

class ysyx_25080216(
    performance_counter: Boolean,
    axiasset: Boolean,
    verifying: Boolean,
    init_pc: Long
) extends Module {
  val io = IO(new Bundle {
    val interrupt = Input(Bool())
    val master = new AXI_Flatten
    val slave = Flipped(new AXI_Flatten)
  })
  if (performance_counter) enable(PerformanceCounterLayer)
  if (axiasset) enable(AXIAssertLayer)
  if (verifying) enable(Verifying)
  val cpu = Module(
    new CPU_Core(
      init_pc = init_pc.U(32.W),
      performance_counter = performance_counter
    )
  )

  block(Verifying) {
    val ebreaker = Module(new Ebreaker)
    val axi_checker = Module(new AXI_Checker)
    val inst_retire = Module(new Inst_Retire)
    val mtracer = Module(new mtracer_soc)

    mtracer.clock := clock
    mtracer.reset := reset
    mtracer.arvalid := io.master.arvalid
    mtracer.arready := io.master.arready
    mtracer.arid := io.master.arid
    mtracer.araddr := io.master.araddr
    mtracer.arlen := io.master.arlen
    mtracer.arsize := io.master.arsize
    mtracer.awvalid := io.master.awvalid
    mtracer.awready := io.master.awready
    mtracer.awid := io.master.awid
    mtracer.awaddr := io.master.awaddr
    mtracer.awlen := io.master.awlen
    mtracer.awsize := io.master.awsize

    inst_retire.clock := clock
    inst_retire.reset := reset
    inst_retire.pc := cpu.io.pc
    inst_retire.retire := cpu.io.ok_to_step
    inst_retire.inst := cpu.io.retire_inst

    axi_checker.clock := clock
    axi_checker.reset := reset
    axi_checker.bvalid := io.master.bvalid
    axi_checker.bready := io.master.bready
    axi_checker.bresp := io.master.bresp
    axi_checker.rvalid := io.master.rvalid
    axi_checker.rready := io.master.rready
    axi_checker.rresp := io.master.rresp

    ebreaker.clock := clock
    ebreaker.reset := reset
    ebreaker.ebreak := cpu.io.ebreak
  }

  io.master.awvalid := cpu.io.axi_bus.aw.valid
  io.master.awaddr := cpu.io.axi_bus.aw.addr
  io.master.awid := cpu.io.axi_bus.aw.id
  io.master.awlen := cpu.io.axi_bus.aw.len
  io.master.awsize := cpu.io.axi_bus.aw.size
  io.master.awburst := cpu.io.axi_bus.aw.burst
  cpu.io.axi_bus.aw.ready := io.master.awready

  io.master.wvalid := cpu.io.axi_bus.w.valid
  io.master.wdata := cpu.io.axi_bus.w.data
  io.master.wstrb := cpu.io.axi_bus.w.strb
  io.master.wlast := cpu.io.axi_bus.w.last
  cpu.io.axi_bus.w.ready := io.master.wready

  io.master.bready := cpu.io.axi_bus.b.ready
  cpu.io.axi_bus.b.valid := io.master.bvalid
  cpu.io.axi_bus.b.resp := io.master.bresp
  cpu.io.axi_bus.b.id := io.master.bid

  cpu.io.axi_bus.ar.ready := io.master.arready
  io.master.arvalid := cpu.io.axi_bus.ar.valid
  io.master.araddr := cpu.io.axi_bus.ar.addr
  io.master.arid := cpu.io.axi_bus.ar.id
  io.master.arlen := cpu.io.axi_bus.ar.len
  io.master.arsize := cpu.io.axi_bus.ar.size
  io.master.arburst := cpu.io.axi_bus.ar.burst

  io.master.rready := cpu.io.axi_bus.r.ready
  cpu.io.axi_bus.r.valid := io.master.rvalid
  cpu.io.axi_bus.r.resp := io.master.rresp
  cpu.io.axi_bus.r.data := io.master.rdata
  cpu.io.axi_bus.r.last := io.master.rlast
  cpu.io.axi_bus.r.id := io.master.rid

  io.slave.awready := false.B
  io.slave.wready := false.B
  io.slave.bvalid := false.B
  io.slave.bresp := 0.U(2.W)
  io.slave.bid := 0.U(4.W)

  io.slave.arready := false.B
  io.slave.rvalid := false.B
  io.slave.rresp := 0.U(2.W)
  io.slave.rdata := 0.U(32.W)
  io.slave.rlast := false.B
  io.slave.rid := 0.U(4.W)

}
