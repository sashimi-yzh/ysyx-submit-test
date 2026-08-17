package empty
import chisel3._
import chisel3.util._
import chisel3.layer._

class Mem_operator extends ExtModule {
  val clock = IO(Input(Clock()))
  val reset = IO(Input(Reset()))
  val raddr = IO(Input(UInt(32.W)))
  val waddr = IO(Input(UInt(32.W)))
  val wdata = IO(Input(UInt(32.W)))
  val wmask = IO(Input(UInt(4.W)))
  val valid = IO(Input(Bool()))
  val wen = IO(Input(Bool()))
  val rdata = IO(Output(UInt(32.W)))
}

class npc_top(init_pc: Long, performance_counter: Boolean) extends Module {
  val io = IO(new Bundle {
    val pc = Output(UInt(32.W))
    val ebreak = Output(Bool())
    val ok_to_step = Output(Bool())

    // val ifu_inst = Input(UInt(32.W))
    // val ifu_addr = Output(UInt(32.W))
    // val ifu_valid = Output(Bool())

    // val lsu_raddr = Output(UInt(32.W))
    // val lsu_waddr = Output(UInt(32.W))
    // val lsu_wdata = Output(UInt(32.W))
    // val lsu_wmask = Output(UInt(4.W))
    // val lsu_valid = Output(Bool())
    // val lsu_wen = Output(Bool())
    // val lsu_rdata = Input(UInt(32.W))

  })

  if (performance_counter) enable(PerformanceCounterLayer)

  val cpu = Module(
    new CPU_Core(
      init_pc = init_pc.U(32.W),
      performance_counter = performance_counter
    )
  )
  // val __inst_fetch = Module(new __inst_fetch_bus)
  val fetcher = Module(new __sim_bus())
  block(Verifying) {
    val ebreaker = Module(new Ebreaker)
    val axi_checker = Module(new AXI_Checker)
    val inst_retire = Module(new Inst_Retire)
    inst_retire.clock := clock
    inst_retire.reset := reset
    inst_retire.pc := cpu.io.retire_pc
    inst_retire.retire := cpu.io.ok_to_step
    inst_retire.inst := cpu.io.retire_inst

    axi_checker.clock := clock
    axi_checker.reset := reset
    axi_checker.bvalid := cpu.io.axi_bus.b.valid
    axi_checker.bready := cpu.io.axi_bus.b.ready
    axi_checker.bresp := cpu.io.axi_bus.b.resp
    axi_checker.rvalid := cpu.io.axi_bus.r.valid
    axi_checker.rready := cpu.io.axi_bus.r.ready
    axi_checker.rresp := cpu.io.axi_bus.r.resp

    ebreaker.clock := clock
    ebreaker.reset := reset
    ebreaker.ebreak := cpu.io.ebreak
  }

  val mem_operator = Module(new Mem_operator())
  mem_operator.clock := clock
  mem_operator.reset := reset
  mem_operator.raddr := fetcher.io.raddr
  mem_operator.valid := fetcher.io.valid
  mem_operator.waddr := fetcher.io.waddr
  mem_operator.wdata := fetcher.io.wdata
  mem_operator.wen := fetcher.io.wen
  mem_operator.wmask := fetcher.io.wmask
  fetcher.io.rdata := mem_operator.rdata

  // val serial = Module(new UART)
  // val clint = Module(new CLINT)
  // val crossbar = Module(new Xbar)
  // cpu.io.inst_bus_axi <> __inst_fetch.fetch_port
  cpu.io.axi_bus <> fetcher.fetch_port
  // cpu.io.axi_bus <> crossbar.IN_AXI
  // crossbar.MEM_AXI <> __lsu_fetch.fetch_port
  // crossbar.UART_AXI <> serial.fetch_port
  // crossbar.CLINT_AXI <> clint.fetch_port

  io.pc := cpu.io.pc
  io.ebreak := cpu.io.ebreak
  io.ok_to_step := cpu.io.ok_to_step

  // io.ifu_addr := __inst_fetch.io.addr
  // io.ifu_valid := __inst_fetch.io.valid
  // __inst_fetch.io.instr := io.ifu_inst

}
