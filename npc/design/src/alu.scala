package cpu.alu

import chisel3._
import chisel3.util._
import common_def._
import busfsm._

class ALUInput extends Bundle {
  val is_imm = Bool()
  val func3t = UInt(3.W)
  val func7t = UInt(7.W)
  val src1   = Types.UWord
  val src2   = Types.UWord
}

class ALU_Trival extends Module {
  val io = IO(new Bundle {
    val in  = Flipped(Decoupled(new ALUInput))
    val out = Decoupled(Types.UWord)
  })

  val fsm = InnerBusCtrl(io.in, io.out, alwaysComb = true)

  val addRes = io.in.bits.src1 + io.in.bits.src2
  val subRes = io.in.bits.src1 - io.in.bits.src2
  val andRes = io.in.bits.src1 & io.in.bits.src2
  val orRes  = io.in.bits.src1 | io.in.bits.src2
  val xorRes = io.in.bits.src1 ^ io.in.bits.src2

  val shamt  = io.in.bits.src2(4, 0)
  val srlRes = io.in.bits.src1 >> shamt
  val sraRes = (io.in.bits.src1.asSInt >> shamt).asUInt
  val sllRes = (io.in.bits.src1 << shamt)(31, 0)

  val sltRes  = (io.in.bits.src1.asSInt < io.in.bits.src2.asSInt).asUInt
  val sltuRes = (io.in.bits.src1 < io.in.bits.src2).asUInt

  val isOpAlt = io.in.bits.func7t(5)
  val isAdd   = ((~isOpAlt) || io.in.bits.is_imm) && (~io.in.bits.func3t(1))

  val addSubRes = Mux(isAdd, addRes, subRes)

  val rshiftRes = Mux(isOpAlt, sraRes, srlRes)

  val results = VecInit(
    addSubRes, // 000: add/sub/addi
    sllRes,    // 001: sll/slli
    sltRes,    // 010: slt/slti
    sltuRes,   // 011: sltu/sltiu
    xorRes,    // 100: xor/xori
    rshiftRes, // 101: srl/srli/sra/srai
    orRes,     // 110: or/ori
    andRes     // 111: and/andi
  )

  val key = io.in.bits.func3t

  io.out.bits := results(key)

}

class ALU extends Module {
  val io = IO(new Bundle {
    val in  = Flipped(new ALUInput)
    val out = Output(Types.UWord)
    val isBranch = Input(Bool())
    val addSubRes = Output(Types.UWord)
    val sltRes = Output(Bool())
    val sltuRes = Output(Bool())
  })

  // alias
  val inbits = io.in
  val src1   = inbits.src1
  val src2   = inbits.src2

  val func3t = inbits.func3t

  val s_src1 = src1.asSInt
  val s_src2 = src2.asSInt

  val shamt = src2(4, 0)

  val isOpAlt = inbits.func7t(5)

  // when func3[1] == 1, less than need sub result
  // val isAdd = ((~isOpAlt) || inbits.is_imm) && (~inbits.func3t(1))
  val isAdd = ((~isOpAlt) || inbits.is_imm) && (~io.isBranch) && (~func3t(1))

  val add_sub_res = Wire(Types.UWord)
  io.addSubRes := add_sub_res

  val op2_inv = src2 ^ Fill(32, ~isAdd)

  val cin = !isAdd
  // add_sub_res := src1 + op2_inv + cin
  // add_sub_res := Mux(isAdd, src1 + src2, src1 - src2)

  val full_add_res = src1 +& op2_inv + cin
  add_sub_res := full_add_res(31, 0)
  val carry_out = full_add_res(32)

  // By using carry out to determine slt/sltu
  // Optimize 23504 -> 23445

  // For unsigned less than a + (-b) sign bit is carry out
  val sltu_res = !carry_out

  val sign_src1 = src1(31)
  val sign_src2 = src2(31)
  val sign_res  = add_sub_res(31)

  // only meaningful when sub mode (~isAdd)
  val overflow = (sign_src1 =/= sign_src2) && (sign_src1 =/= sign_res)

  // when overflow:
  //   result sign positive -> (a:-...) - (b: +...) overflow -> slt should be true
  // when no overflow:
  //   result sign negative -> less than -> slt should be true
  val slt_res = sign_res ^ overflow

  io.sltRes := slt_res
  io.sltuRes := sltu_res

  val rShiftResult = Wire(Types.UWord)
  val lShiftResult = Wire(Types.UWord)

  // rShiftResult := Mux(isOpAlt, (s_src1 >> shamt).asUInt, src1 >> shamt)

  // wired optimize make 64b shift has smaller area than 32b shift + mux
  // make EXU and ALU smaller, but whole CPU bigger little bit ???
  rShiftResult := Cat(Fill(32, isOpAlt && sign_src1), src1) >> shamt
  lShiftResult := src1 << shamt

  val defaultRes = Wire(Types.UWord)
  defaultRes := DontCare

  // left shift here
  // expilcitly tell chisel that width is 32
  // to avoid use 64-bit as result leads to big case
  //
  // can make alu alone module area smaller
  // but when considering whole cpu module
  // seems no difference ???
  // val leftShiftRes = Wire(Types.UWord)
  // leftShiftRes := src1 << shamt

  val logic_and = src1 & src2
  val logic_xor = src1 ^ src2
  // Optimize or to use and/xor result
  // 23445 -> 23282
  val logic_or  = logic_and | logic_xor

  // val func3t2HighResult = Mux(
  //   func3t(0),
//   Mux(func3t(1), rShiftResult, sltu_res),
  //   Mux(func3t(1), logic_or, logic_xor)
  // )
  //
  // val func3t2LowResult = Mux(
  //   func3t(1),
  //   Mux(func3t(0), sltu_res, slt_res),
  //   Mux(func3t(0), Reverse(rShiftResult), add_sub_res)
  // )
  //
  // io.out.bits := Mux(func3t(2), func3t2HighResult, func3t2LowResult)

  val results = VecInit(
    add_sub_res,        // 000: add/sub/addi
    lShiftResult,       // 001: sll/slli
    slt_res,            // 010: slt/slti
    sltu_res,           // 011: sltu/sltiu
    logic_xor,          // 100: xor/xori
    rShiftResult,       // 101: srl/srli/sra/srai
    logic_or,           // 110: or/ori
    logic_and           // 111: and/andi
  )

  io.out := results(func3t)
}
