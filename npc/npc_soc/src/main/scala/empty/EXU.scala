package empty

import chisel3._
import chisel3.util._
import chisel3.layer.block

class WriteInfo extends Bundle {
  val mem_word_or_csr_wdata = UInt(32.W)
  val gpr_wdata = UInt(32.W)
  val dnpc = UInt(32.W)
  val mtvec = UInt(32.W)
  val alu_out = UInt(32.W)
}

class WriteInfoWBU extends Bundle {
  val mem_word_or_csr_wdata = UInt(32.W)
  val gpr_wdata = UInt(32.W)
  val dnpc = UInt(32.W)
}

class PerformanceCounter_ICache extends ExtModule {
  val clock = IO(Input(Clock()))
  val reset = IO(Input(Reset()))
  val icache_hit = IO(Input(Bool()))
}

class ControlSignalsEXU extends Bundle {
  val is_csr_visit = Bool()
  val is_gpr_wen = Bool()
  val gpr_wdata_sel = UInt(2.W)
  val ram_size = UInt(2.W)
  val is_load_unsigned = Bool()
  val is_ram_valid = Bool()
  val is_ram_wen = Bool()
  val rd = UInt(5.W)
  val csrd = UInt(12.W)
  val is_ebreak = Bool()
}

class MessageEXU2LSU extends Bundle {
  val pc = UInt(32.W)
  val inst = UInt(32.W)
  val controls = new ControlSignalsEXU
  val write_info = new WriteInfo
  val fence = Bool()
  val exeption = Bool()
  val csr_jump = Bool()
}

class ConflictInfoRD extends Bundle {
  val rd_valid = Output(Bool())
  val csr_dest_valid = Output(Bool())
  val rd_id = Output(UInt(5.W))
  val csr_id = Output(UInt(12.W))
  val ok_to_forward_rd = Output(Bool())
  val rd_data = Output(UInt(32.W))
}

class EXU() extends PrefixedModule {
  val in = IO(Flipped(DecoupledIO(new MessageIDU2EXU)))
  val out = IO(DecoupledIO(new MessageEXU2LSU))
  val conf = IO(new ConflictInfoRD)
  val out_pc = IO(new Bundle {
    val dnpc = Output(UInt(32.W))
    val flush_valid = Output(Bool())
  })
  val flush = IO(new Bundle { val valid = Input(Bool()) })

  val has_signal_r = RegInit(false.B)
  has_signal_r := MuxCase(
    has_signal_r,
    Seq(
      (in.fire && !flush.valid) -> true.B,
      (out.fire || flush.valid) -> false.B
    )
  )
  val has_signal = has_signal_r && !flush.valid

  out.bits.pc := in.bits.pc
  out.bits.inst := in.bits.inst
  out.bits.controls := in.bits.controls

  val alu = Module(new ALU(32))
  val branch = Module(new Branch(32))

  val imm_I = Cat(Fill(20, in.bits.inst(31)), in.bits.inst(31, 20))
  val imm_S = Cat(Fill(20, in.bits.inst(31)), in.bits.inst(31, 25), in.bits.inst(11, 7))
  val imm_B = Cat(Fill(20, in.bits.inst(31)), in.bits.inst(7), in.bits.inst(30, 25), in.bits.inst(11, 8), 0.U(1.W))
  val imm_U = Cat(in.bits.inst(31, 12), 0.U(12.W))
  val imm_J = Cat(Fill(12, in.bits.inst(31)), in.bits.inst(19, 12), in.bits.inst(20), in.bits.inst(30, 21), 0.U(1.W))
  val alu_imm = MuxCase(
    imm_I,
    Seq(
      in.bits.flags.is_branch -> imm_B,
      in.bits.flags.is_store -> imm_S,
      in.bits.flags.is_jal -> imm_J,
      (in.bits.flags.is_auipc || in.bits.flags.is_lui) -> imm_U
    )
  )
  val alu_a = MuxCase(
    in.bits.sources.src1,
    Seq(
      (in.bits.flags.is_lui || in.bits.flags.is_mret) -> 0.U(32.W),
      (in.bits.flags.is_branch || in.bits.flags.is_jal || in.bits.flags.is_auipc) -> in.bits.pc
    )
  )
  val alu_b = Mux(in.bits.flags.is_mret || in.bits.flags.is_arithmetic_reg, in.bits.sources.src2_or_csr, alu_imm)

  alu.io.A := alu_a
  alu.io.B := alu_b
  alu.io.controls := in.bits.controls.alu_controls
  out.bits.write_info.alu_out := alu.io.out

  branch.io.A := in.bits.sources.src1
  branch.io.B := in.bits.sources.src2_or_csr
  branch.io.funct3 := in.bits.controls.bra_funct3

  val snpc = in.bits.pc + 4.U(32.W)
  val jalr_target = Cat(alu.io.out(31, 1), 0.U(1.W))
  val branch_or_jal_target = alu.io.out
  val taken_target = Mux(in.bits.flags.is_jalr, jalr_target, branch_or_jal_target)
  val should_branch = in.bits.controls.is_branch && branch.io.jump
  val should_redirect = should_branch || in.bits.flags.is_jal || in.bits.flags.is_jalr || in.bits.flags.is_mret
  val actual_dnpc = Mux(should_redirect, taken_target, snpc)
  val should_flush = should_redirect && actual_dnpc =/= snpc

  out.bits.write_info.gpr_wdata := MuxLookup(
    in.bits.controls.gpr_wdata_sel,
    alu.io.out
  )(
    Seq(
      GprWdataSel.SNPC -> snpc,
      GprWdataSel.CSR -> in.bits.sources.src2_or_csr,
      GprWdataSel.ALU -> alu.io.out
    )
  )
  out.bits.write_info.mem_word_or_csr_wdata := Mux(
    in.bits.flags.is_store,
    in.bits.sources.src2_or_csr,
    Mux(in.bits.controls.is_csr_masked, in.bits.sources.src1 | in.bits.sources.src2_or_csr, in.bits.sources.src1)
  )

  conf.rd_id := in.bits.controls.rd
  conf.rd_valid := has_signal && in.bits.controls.is_gpr_wen
  conf.csr_dest_valid := has_signal && in.bits.controls.is_csr_visit
  conf.csr_id := in.bits.controls.csrd
  conf.ok_to_forward_rd := in.bits.controls.gpr_wdata_sel =/= GprWdataSel.RAM
  conf.rd_data := out.bits.write_info.gpr_wdata

  out.valid := has_signal
  val is_first_cycle = RegNext(in.fire, false.B)

  out.bits.write_info.mtvec := in.bits.sources.mtvec
  out.bits.write_info.dnpc := actual_dnpc
  out.bits.exeption := in.bits.exception
  out.bits.csr_jump := in.bits.controls.is_dnpc_csr_jump
  out.bits.fence := in.bits.flags.is_fence

  out_pc.dnpc := actual_dnpc
  out_pc.flush_valid := has_signal && is_first_cycle && should_flush
  in.ready := out.fire || !has_signal

  block(PerformanceCounterLayer) {
    val performancecounter_icache = Module(new PerformanceCounter_ICache)
    performancecounter_icache.clock := clock
    performancecounter_icache.reset := reset
    performancecounter_icache.icache_hit := out.fire && in.bits.in_cache
  }
}
