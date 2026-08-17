package empty

import chisel3._
import chisel3.util._
import chisel3.layer._

object ALUOp {
  def ADD = 0.U(4.W)
  def SUB = 1.U(4.W)
  def SLT = 2.U(4.W)
  def SLTU = 3.U(4.W)
  def SLL = 4.U(4.W)
  def SRL = 5.U(4.W)
  def SRA = 6.U(4.W)
  def AND = 7.U(4.W)
  def OR = 8.U(4.W)
  def XOR = 9.U(4.W)
}

object GprWdataSel {
  def ALU = 0.U(2.W)
  def RAM = 1.U(2.W)
  def SNPC = 2.U(2.W)
  def CSR = 3.U(2.W)
}

object RamSize {
  def BYTE = 0.U(2.W)
  def HALF = 1.U(2.W)
  def WORD = 2.U(2.W)
}

class InstFields extends Bundle {
  val rs1 = UInt(5.W)
  val rs2 = UInt(5.W)
  val rd = UInt(5.W)
  val funct3 = UInt(3.W)
  val funct7 = UInt(7.W)
  val imm = UInt(32.W)
  val csr = UInt(12.W)
}

class InstType extends Bundle {
  val is_arithmetic_imm = Bool()
  val is_arithmetic_reg = Bool()
  val is_store = Bool()
  val is_load = Bool()
  val is_branch = Bool()
  val is_jal = Bool()
  val is_jalr = Bool()
  val is_lui = Bool()
  val is_auipc = Bool()
  val is_ebreak = Bool()
  val is_ecall = Bool()
  val is_mret = Bool()
  val is_csrop = Bool()
  val is_fence = Bool()
}

class ImmType extends Bundle {
  val is_I = Bool()
  val is_R = Bool()
  val is_S = Bool()
  val is_B = Bool()
  val is_J = Bool()
  val is_U = Bool()
}

class ALUControl extends Bundle {
  val op = UInt(4.W)
}

class ControlSignals extends Bundle {
  val is_csr_visit = Bool()
  val alu_controls = new ALUControl
  val gpr_wdata_sel = UInt(2.W)
  val is_gpr_wen = Bool()
  val ram_size = UInt(2.W)
  val is_load_unsigned = Bool()
  val is_ram_valid = Bool()
  val is_ram_wen = Bool()
  val is_csr_masked = Bool()
  val rd = UInt(5.W)
  val csrd = UInt(12.W)
  val bra_funct3 = UInt(3.W)
  val is_branch = Bool()
  val is_dnpc_jal_or_jalr = Bool()
  val is_dnpc_csr_jump = Bool()
  val is_ebreak = Bool()
}

class ExuInstFlags extends Bundle {
  val is_arithmetic_reg = Bool()
  val is_store = Bool()
  val is_branch = Bool()
  val is_jal = Bool()
  val is_jalr = Bool()
  val is_lui = Bool()
  val is_auipc = Bool()
  val is_mret = Bool()
  val is_csrop = Bool()
  val is_fence = Bool()
}

object decodeInstType {
  private def apply(inst: UInt, funct3: UInt): InstType = {
    val ret = WireInit(0.U.asTypeOf(new InstType))
    val opcode = inst(6, 2)
    switch(opcode) {
      is("b00100".U) { ret.is_arithmetic_imm := true.B }
      is("b01100".U) { ret.is_arithmetic_reg := true.B }
      is("b01000".U) { ret.is_store := true.B }
      is("b00000".U) { ret.is_load := true.B }
      is("b11000".U) { ret.is_branch := true.B }
      is("b11011".U) { ret.is_jal := true.B }
      is("b11001".U) { ret.is_jalr := true.B }
      is("b01101".U) { ret.is_lui := true.B }
      is("b00101".U) { ret.is_auipc := true.B }
      is("b11100".U) { ret.is_csrop := true.B }
      is("b00011".U) { ret.is_fence := true.B }
    }
    val is_funct3_zero = funct3 === "b000".U(3.W)
    ret.is_ebreak := ret.is_csrop && is_funct3_zero && !inst(21) && inst(20)
    ret.is_ecall := ret.is_csrop && is_funct3_zero && !inst(21) && !inst(20)
    ret.is_mret := ret.is_csrop && is_funct3_zero && inst(21)
    ret
  }

  def apply(inst: UInt, fields: InstFields): InstType = apply(inst, fields.funct3)

  def apply(inst: UInt): InstType = apply(inst, inst(14, 12))
}

object decodeImmType {
  def apply(inst: UInt, it: InstType): ImmType = {
    val ret = Wire(new ImmType)
    ret.is_I := it.is_arithmetic_imm || it.is_ebreak || it.is_load || it.is_jalr
    ret.is_R := it.is_arithmetic_reg
    ret.is_S := it.is_store
    ret.is_B := it.is_branch
    ret.is_J := it.is_jal
    ret.is_U := it.is_auipc || it.is_lui
    ret
  }
}

object decodeInstFields {
  def apply(inst: UInt, immType: ImmType): InstFields = {
    val ret = Wire(new InstFields)
    ret.rs1 := inst(19, 15)
    ret.rs2 := inst(24, 20)
    ret.rd := inst(11, 7)
    ret.funct3 := inst(14, 12)
    ret.funct7 := inst(31, 25)
    ret.csr := inst(31, 20)

    val imm_B = Cat(Fill(20, inst(31)), inst(7), inst(30, 25), inst(11, 8), 0.U(1.W))
    val imm_S = Cat(Fill(20, inst(31)), inst(31, 25), inst(11, 7))
    val imm_J = Cat(Fill(12, inst(31)), inst(19, 12), inst(20), inst(30, 21), 0.U(1.W))
    val imm_U = Cat(inst(31, 12), 0.U(12.W))
    val imm_I = Cat(Fill(20, inst(31)), inst(31, 20))

    ret.imm := Mux1H(
      Seq(
        immType.is_B -> imm_B,
        immType.is_S -> imm_S,
        immType.is_J -> imm_J,
        immType.is_U -> imm_U,
        immType.is_I -> imm_I
      )
    )
    ret
  }
}

object decodeInstControlSignal {
  def apply(inst: UInt, it: InstType, fields: InstFields, imm_type: ImmType): ControlSignals = {
    val ret = Wire(new ControlSignals)
    val is_funct3_zero = fields.funct3 === "b000".U(3.W)
    val is_alu_sub_sra = fields.funct7(5) && !(it.is_arithmetic_imm && is_funct3_zero)
    val is_alu_force_add = it.is_mret || it.is_store || it.is_load || it.is_branch || it.is_auipc || it.is_jal || it.is_jalr || it.is_lui
    val alu_op = WireDefault(ALUOp.ADD)
    when(!is_alu_force_add) {
      switch(fields.funct3) {
        is("b000".U) { alu_op := Mux(is_alu_sub_sra, ALUOp.SUB, ALUOp.ADD) }
        is("b001".U) { alu_op := ALUOp.SLL }
        is("b010".U) { alu_op := ALUOp.SLT }
        is("b011".U) { alu_op := ALUOp.SLTU }
        is("b100".U) { alu_op := ALUOp.XOR }
        is("b101".U) { alu_op := Mux(is_alu_sub_sra, ALUOp.SRA, ALUOp.SRL) }
        is("b110".U) { alu_op := ALUOp.OR }
        is("b111".U) { alu_op := ALUOp.AND }
      }
    }

    val csr_visit = it.is_csrop && !is_funct3_zero
    ret.is_csr_visit := csr_visit
    ret.alu_controls.op := alu_op
    ret.gpr_wdata_sel := MuxCase(
      GprWdataSel.ALU,
      Seq(
        it.is_load -> GprWdataSel.RAM,
        (it.is_jal || it.is_jalr) -> GprWdataSel.SNPC,
        csr_visit -> GprWdataSel.CSR
      )
    )
    ret.is_gpr_wen := csr_visit || imm_type.is_U || it.is_load || imm_type.is_R || it.is_arithmetic_imm || it.is_jal || it.is_jalr
    ret.ram_size := fields.funct3(1, 0)
    ret.is_load_unsigned := fields.funct3(2)
    ret.is_ram_valid := it.is_load || it.is_store
    ret.is_ram_wen := it.is_store
    ret.is_csr_masked := fields.funct3(1)
    ret.bra_funct3 := fields.funct3
    ret.rd := fields.rd
    ret.csrd := fields.csr
    ret.is_branch := it.is_branch
    ret.is_dnpc_jal_or_jalr := it.is_jal || it.is_jalr
    ret.is_dnpc_csr_jump := it.is_mret
    ret.is_ebreak := it.is_ebreak
    ret
  }
}

class Operands extends Bundle {
  val mtvec = UInt(32.W)
  val src1 = UInt(32.W)
  val src2_or_csr = UInt(32.W)
}

class MessageIDU2EXU extends Bundle {
  val pc = UInt(32.W)
  val inst = UInt(32.W)
  val in_cache = Bool()
  val controls = new ControlSignals
  val flags = new ExuInstFlags
  val sources = new Operands
  val exception = Bool()
}

class ConflictInfoRS extends Bundle {
  val rs1_valid = Output(Bool())
  val rs2_valid = Output(Bool())
  val csr_src_valid = Output(Bool())
  val rs1_id = Output(UInt(5.W))
  val rs2_id = Output(UInt(5.W))
  val csr_src_id = Output(UInt(12.W))
  val stall = Input(Bool())
  val do_forward_src1 = Input(Bool())
  val do_forward_src2 = Input(Bool())
  val forward_data_src1 = Input(UInt(32.W))
  val forward_data_src2 = Input(UInt(32.W))
}

class IDU() extends PrefixedModule {
  val in = IO(Flipped(DecoupledIO(new MessageIFU2IDU)))
  val perf_cnt = IO(new Bundle {
    val stalled = Output(Bool())
    val flushed = Output(Bool())
  })
  val out = IO(DecoupledIO(new MessageIDU2EXU))
  val conf = IO(new ConflictInfoRS)
  val flush = IO(new Bundle { val valid = Input(Bool()) })
  val fetch_port_out = IO(new Bundle {
    val gpr_raddr1 = Output(UInt(5.W))
    val gpr_raddr2 = Output(UInt(5.W))
    val csr_raddr = Output(UInt(12.W))
  })
  val fetch_port_in = IO(new Bundle {
    val gpr_rdata1 = Input(UInt(32.W))
    val gpr_rdata2 = Input(UInt(32.W))
    val csr_rdata = Input(UInt(32.W))
    val csr_mtvec = Input(UInt(32.W))
    val csr_mepc = Input(UInt(32.W))
  })

  val has_inst_r = RegInit(false.B)
  has_inst_r := MuxCase(
    has_inst_r,
    Seq(
      (in.fire && !flush.valid) -> true.B,
      (out.fire || flush.valid) -> false.B
    )
  )
  val has_inst = has_inst_r && !flush.valid

  val imm_type = Wire(new ImmType)
  val fields = Wire(new InstFields)
  val inst_type = Wire(new InstType)
  val control_signals = Wire(new ControlSignals)

  imm_type := decodeImmType(in.bits.inst, inst_type)
  fields := decodeInstFields(in.bits.inst, imm_type)
  inst_type := decodeInstType(in.bits.inst, fields)
  control_signals := decodeInstControlSignal(in.bits.inst, inst_type, fields, imm_type)

  fetch_port_out.csr_raddr := fields.csr
  fetch_port_out.gpr_raddr1 := fields.rs1
  fetch_port_out.gpr_raddr2 := fields.rs2

  val gpr_rdata1 = Mux(conf.do_forward_src1, conf.forward_data_src1, fetch_port_in.gpr_rdata1)
  val gpr_rdata2 = Mux(conf.do_forward_src2, conf.forward_data_src2, fetch_port_in.gpr_rdata2)

  out.bits.pc := in.bits.pc
  out.bits.inst := in.bits.inst
  out.bits.in_cache := in.bits.in_cache
  out.bits.controls := control_signals
  out.bits.sources.src1 := gpr_rdata1
  out.bits.sources.src2_or_csr := MuxCase(
    gpr_rdata2,
    Seq(
      (control_signals.gpr_wdata_sel === GprWdataSel.CSR) -> fetch_port_in.csr_rdata,
      inst_type.is_mret -> fetch_port_in.csr_mepc
    )
  )
  out.bits.sources.mtvec := fetch_port_in.csr_mtvec
  out.bits.exception := inst_type.is_ecall

  out.bits.flags.is_arithmetic_reg := inst_type.is_arithmetic_reg
  out.bits.flags.is_store := inst_type.is_store
  out.bits.flags.is_branch := inst_type.is_branch
  out.bits.flags.is_jal := inst_type.is_jal
  out.bits.flags.is_jalr := inst_type.is_jalr
  out.bits.flags.is_lui := inst_type.is_lui
  out.bits.flags.is_auipc := inst_type.is_auipc
  out.bits.flags.is_mret := inst_type.is_mret
  out.bits.flags.is_csrop := inst_type.is_csrop
  out.bits.flags.is_fence := inst_type.is_fence

  conf.rs1_id := fields.rs1
  conf.rs2_id := fields.rs2
  conf.csr_src_id := control_signals.csrd
  conf.rs1_valid := has_inst && (imm_type.is_R || imm_type.is_I || imm_type.is_S || imm_type.is_B || inst_type.is_csrop)
  conf.rs2_valid := has_inst && (imm_type.is_R || imm_type.is_S || imm_type.is_B)
  conf.csr_src_valid := has_inst && inst_type.is_csrop

  out.valid := has_inst && !conf.stall
  in.ready := (out.fire || !has_inst) && !conf.stall

  perf_cnt.stalled := has_inst && conf.stall
  perf_cnt.flushed := has_inst_r && flush.valid
}
