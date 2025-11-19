package npc.core.exu

import chisel3._
import chisel3.util._
import npc.common.Config._
import npc.common._
import npc.common.Instructions._

class ALUIO_in extends Bundle{
    val op1 = Output(UInt(WORD_LEN.W))
    val op2 = Output(UInt(WORD_LEN.W))
    val processtpe = Output(UInt(ProcessTpe.ProcessTpe_Width.W))
    val bjtpe = Output(UInt(BJTpe.BJTpe_Width.W))
}
class ALUIO_out extends Bundle{
    val alu_out = Output(UInt(WORD_LEN.W))
}

class ALUIO extends Bundle {
    val in = Flipped(Decoupled(new ALUIO_in))
    val out = Decoupled(new ALUIO_out)
}


class ALU extends Module{
    val io = IO(new ALUIO)
    val io_bj = IO(new EXU_BJIO)

    val (op1_data, op2_data, processtpe, bjtpe) = (io.in.bits.op1, io.in.bits.op2, io.in.bits.processtpe, io.in.bits.bjtpe)
    val shamt = op2_data(4, 0).asUInt

    //Adder
    val is_sub = processtpe(0)
    val add_sub_out = op1_data +& (op2_data ^ Fill(WORD_LEN, is_sub)) + is_sub
    //others
    val and_out = op1_data & op2_data
    val or_out = op1_data | op2_data
    val xor_out = op1_data ^ op2_data
    val sra_out = (op1_data.asSInt >> shamt).asUInt
    val srl_out = op1_data >> shamt
    val sll_out = op1_data << shamt
    val others_out = MuxLookup(processtpe(2, 0), and_out)(Seq(
        ProcessTpe.ALU.ALU_OR(2, 0) -> or_out,
        ProcessTpe.ALU.ALU_XOR(2, 0) -> xor_out,
        ProcessTpe.ALU.ALU_SLL(2, 0) -> sll_out,
        ProcessTpe.ALU.ALU_SRL(2, 0) -> srl_out,
        ProcessTpe.ALU.ALU_SRA(2, 0) -> sra_out
    ))
    //Comp
    val compu_out = !add_sub_out(WORD_LEN.U)
    val comps_out = xor_out((WORD_LEN - 1).U) ^ compu_out
    //alu_out
    io.out.bits.alu_out := Mux(
        processtpe(3), add_sub_out, Mux(
        processtpe === ProcessTpe.ALU.ALU_COMPU, compu_out, Mux(
        processtpe === ProcessTpe.ALU.ALU_COMPS, comps_out, others_out
        ))
    )

    //bj
    val cmp = io.out.bits.alu_out(0)
    val eq = io.out.bits.alu_out === 0.U
    io_bj.valid := io.in.valid && (
        (bjtpe === BJTpe.BJ_BEQ && eq) ||
        (bjtpe === BJTpe.BJ_BNE && !eq) ||
        (bjtpe === BJTpe.BJ_BLT && cmp) ||
        (bjtpe === BJTpe.BJ_BLTU && cmp) ||
        (bjtpe === BJTpe.BJ_BGE && !cmp) ||
        (bjtpe === BJTpe.BJ_BGEU && !cmp) ||
        (bjtpe(3))
    )
    io_bj.target := DontCare

    //handshake
    io.in.ready := io.out.ready
    io.out.valid := io.in.valid


    dontTouch(cmp)
    dontTouch(eq)
    dontTouch(eq)
    dontTouch(and_out)
    dontTouch(or_out)
    dontTouch(xor_out)
    dontTouch(sra_out)
    dontTouch(srl_out)
    dontTouch(sll_out)
    dontTouch(add_sub_out)
}