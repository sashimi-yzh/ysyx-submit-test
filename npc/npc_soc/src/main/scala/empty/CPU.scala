package empty

import chisel3._
import chisel3.util._
import chisel3.layer._
import chisel3.layers.Verification

object PerformanceCounterLayer extends Layer(LayerConfig.Inline)

object StageConnect {
  def apply[T <: Data](left: DecoupledIO[T], right: DecoupledIO[T]) = {
    val arch = "pipeline"
    if (arch == "single") {
      right.bits := left.bits
    } else if (arch == "multi") {
      right <> left
    } else if (arch == "pipeline") {
      left.ready := right.ready
      right.bits := RegEnable(left.bits, left.fire)
      right.valid := left.valid
    }
  }
}

class MemAccessBus extends Bundle {
  val raddr = Output(UInt(32.W))
  val wen = Output(Bool())
  val waddr = Output(UInt(32.W))
  val wdata = Output(UInt(32.W))
  val wmask = Output(UInt(4.W))
  val rdata = Input(UInt(32.W))
  val reqValid = Output(Bool())
  val reqReady = Input(Bool())
  val respValid = Input(Bool())
  val respReady = Output(Bool())
}

class PerformanceCounter extends ExtModule {
  val clock = IO(Input(Clock()))
  val reset = IO(Input(Reset()))
  val pc = IO(Input(UInt(32.W)))
  val ifu_arready = IO(Input(Bool()))
  val ifu_arvalid = IO(Input(Bool()))
  val ifu_rready = IO(Input(Bool()))
  val ifu_rvalid = IO(Input(Bool()))
  val lsu_arready = IO(Input(Bool()))
  val lsu_arvalid = IO(Input(Bool()))
  val lsu_rready = IO(Input(Bool()))
  val lsu_rvalid = IO(Input(Bool()))
  val exu_ready = IO(Input(Bool()))
  val exu_valid = IO(Input(Bool()))
  val idu_ready = IO(Input(Bool()))
  val idu_valid = IO(Input(Bool()))
  val wbu_valid = IO(Input(Bool()))
  val inst_type = IO(Input(new InstType))
  val stalled = IO(Input(Bool()))
  val flushed = IO(Input(Bool()))
}

class CPU_Core(init_pc: UInt, performance_counter: Boolean) extends PrefixedModule {
  val io = IO(new Bundle {
    val pc = Output(UInt(32.W))
    val ebreak = Output(Bool())
    val axi_bus = new AXI
    val ok_to_step = Output(Bool())
    val retire_pc = Output(UInt(32.W))
    val retire_inst = Output(UInt(32.W))
  })

  val ifu = Module(new IFU(init_pc = init_pc))
  val idu = Module(new IDU)
  val exu = Module(new EXU)
  val lsu = Module(new LSU)
  val wbu = Module(new WBU)

  val pc = RegEnable(Cat(wbu.out.dnpc(31, 1), 0.U(1.W)), init_pc, wbu.out.ok_to_step)
  io.pc := pc

  val gpr = Module(new GPR(CNT = 16, BITWIDTH = 32))
  val csrBank = Module(new CSR)
  val arbiter = Module(new Arbiter_2Master)
  val xbar = Module(new XBar_CLINT)
  val clint = Module(new Clint)

  io.axi_bus <> xbar.OUT_AXI
  xbar.IN_AXI <> arbiter.OUT_AXI
  xbar.CLINT_AXI <> clint.in
  clint.mtime := csrBank.io.mcycle

  io.retire_pc := wbu.out.retire_pc
  io.retire_inst := wbu.out.retire_inst

  ifu.in.exu_dnpc := Mux(lsu.out_pc.flush_valid, lsu.out_pc.dnpc, exu.out_pc.dnpc)
  ifu.in.fencei := lsu.out_pc.fencei
  ifu.in.flush_valid := exu.out_pc.flush_valid || lsu.out_pc.flush_valid
  idu.flush.valid := exu.out_pc.flush_valid || lsu.out_pc.flush_valid
  exu.flush.valid := lsu.out_pc.flush_valid

  ifu.fetch_port <> arbiter.IFU_AXI

  StageConnect(ifu.out, idu.in)
  StageConnect(idu.out, exu.in)
  StageConnect(exu.out, lsu.in)
  StageConnect(lsu.out, wbu.in)

  def check_conflict(rs_info: ConflictInfoRS, rd_info: ConflictInfoRD): (Bool, Bool, Bool, Bool, Bool, UInt) = {
    val conf1 = rs_info.rs1_valid && rd_info.rd_valid && (rs_info.rs1_id === rd_info.rd_id) && (rd_info.rd_id =/= 0.U(5.W))
    val conf2 = rs_info.rs2_valid && rd_info.rd_valid && (rs_info.rs2_id === rd_info.rd_id) && (rd_info.rd_id =/= 0.U(5.W))
    val conf_csr = rd_info.csr_dest_valid
    val forward1 = conf1 && rd_info.ok_to_forward_rd
    val forward2 = conf2 && rd_info.ok_to_forward_rd
    (conf1, forward1, conf2, forward2, conf_csr, rd_info.rd_data)
  }

  val (conf1_exu, fwd1_exu, conf2_exu, fwd2_exu, conf_csr_exu, data_exu) = check_conflict(idu.conf, exu.conf)
  val (conf1_lsu, fwd1_lsu, conf2_lsu, fwd2_lsu, conf_csr_lsu, data_lsu) = check_conflict(idu.conf, lsu.conf)
  val (conf1_wbu, fwd1_wbu, conf2_wbu, fwd2_wbu, conf_csr_wbu, data_wbu) = check_conflict(idu.conf, wbu.conf)

  val stall_src1 = MuxCase(
    false.B,
    Seq(
      conf1_exu -> !fwd1_exu,
      conf1_lsu -> !fwd1_lsu,
      conf1_wbu -> !fwd1_wbu
    )
  )
  val stall_src2 = MuxCase(
    false.B,
    Seq(
      conf2_exu -> !fwd2_exu,
      conf2_lsu -> !fwd2_lsu,
      conf2_wbu -> !fwd2_wbu
    )
  )
  val stall_csr = conf_csr_exu || conf_csr_lsu || conf_csr_wbu || wbu.out.csr_interruption
  idu.conf.stall := stall_src1 || stall_src2 || stall_csr

  idu.conf.do_forward_src1 := MuxCase(
    false.B,
    Seq(
      conf1_exu -> fwd1_exu,
      conf1_lsu -> fwd1_lsu,
      conf1_wbu -> fwd1_wbu
    )
  )
  idu.conf.do_forward_src2 := MuxCase(
    false.B,
    Seq(
      conf2_exu -> fwd2_exu,
      conf2_lsu -> fwd2_lsu,
      conf2_wbu -> fwd2_wbu
    )
  )
  idu.conf.forward_data_src1 := MuxCase(
    data_wbu,
    Seq(
      conf1_exu -> data_exu,
      conf1_lsu -> data_lsu
    )
  )
  idu.conf.forward_data_src2 := MuxCase(
    data_wbu,
    Seq(
      conf2_exu -> data_exu,
      conf2_lsu -> data_lsu
    )
  )

  io.ok_to_step := wbu.out.ok_to_step
  csrBank.io.ok_to_step := wbu.out.ok_to_step
  idu.fetch_port_in.csr_rdata := csrBank.io.rdata
  idu.fetch_port_in.csr_mepc := csrBank.io.mepc
  idu.fetch_port_in.csr_mtvec := csrBank.io.mtvec
  idu.fetch_port_in.gpr_rdata1 := gpr.io.rdata1
  idu.fetch_port_in.gpr_rdata2 := gpr.io.rdata2

  lsu.fetch_port <> arbiter.LSU_AXI

  gpr.io.raddr1 := idu.fetch_port_out.gpr_raddr1
  gpr.io.raddr2 := idu.fetch_port_out.gpr_raddr2
  gpr.io.waddr := wbu.out.gpr_waddr
  gpr.io.wdata := wbu.out.gpr_wdata
  gpr.io.wen := wbu.out.gpr_wen

  csrBank.io.csr_w := wbu.out.csr_waddr
  csrBank.io.csr_r := idu.fetch_port_out.csr_raddr
  csrBank.io.cur_pc := wbu.out.csr_cur_pc
  csrBank.io.interruption := wbu.out.csr_interruption
  csrBank.io.wdata := wbu.out.csr_wdata
  csrBank.io.wen := wbu.out.csr_wen

  io.ebreak := wbu.out.ebreak

  block(PerformanceCounterLayer) {
    val m_performance_counter = Module(new PerformanceCounter)
    m_performance_counter.clock := clock
    m_performance_counter.reset := reset
    m_performance_counter.pc := pc
    m_performance_counter.exu_ready := exu.out.ready
    m_performance_counter.exu_valid := exu.out.valid
    m_performance_counter.idu_ready := idu.out.ready
    m_performance_counter.idu_valid := idu.out.valid
    m_performance_counter.wbu_valid := wbu.out.ok_to_step
    m_performance_counter.inst_type := decodeInstType(wbu.out.retire_inst)
    m_performance_counter.ifu_arready := ifu.fetch_port.ar.ready
    m_performance_counter.ifu_arvalid := ifu.fetch_port.ar.valid
    m_performance_counter.ifu_rready := ifu.fetch_port.r.ready
    m_performance_counter.ifu_rvalid := ifu.fetch_port.r.valid
    m_performance_counter.lsu_arready := lsu.fetch_port.ar.ready
    m_performance_counter.lsu_arvalid := lsu.fetch_port.ar.valid
    m_performance_counter.lsu_rready := lsu.fetch_port.r.ready
    m_performance_counter.lsu_rvalid := lsu.fetch_port.r.valid
    m_performance_counter.stalled := idu.perf_cnt.stalled
    m_performance_counter.flushed := idu.perf_cnt.flushed
  }
}
