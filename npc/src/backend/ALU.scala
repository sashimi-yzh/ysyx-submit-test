package npc.EXUs

import chisel3._
import chisel3.util._

object ALUSrc1 extends ChiselEnum{
    val rs1,
    pc = Value
}

object ALUSrc2 extends ChiselEnum{
    val rs2,
    imm,
    shamt,
    csr = Value
}

object ALUOp extends ChiselEnum{
    val add,
    sub,
    and,
    or,
    xor,
    lui,
    sll,srl,sra, //左移右移
    slt,sltu //小于
    = Value
}

class ysyx_26030092_ALU extends Module{

    val in = IO(Input(new Bundle {
        val ctl = ALUOp()
        val src1 = UInt(32.W)
        val src2 = UInt(32.W)
    }))
    val out = IO(Output(UInt(32.W)))

    val is_sub = (in.ctl === ALUOp.sub) || (in.ctl === ALUOp.slt) || (in.ctl === ALUOp.sltu)
    val op2    = Mux(is_sub, ~in.src2, in.src2)
    val diff   = in.src1 +& op2 + is_sub.asUInt   // 33 位，bit32 是进位/借位
    dontTouch(is_sub)
    dontTouch(op2)
    dontTouch(diff)

    out := DontCare
    switch(in.ctl){
        is(ALUOp.add) { out := diff(31,0) }
        is(ALUOp.sub) { out := diff(31,0) }
        is(ALUOp.sltu){ out := (!diff(32)).asUInt }   // 借位=1 表示 src1 < src2
        is(ALUOp.slt) { out := Mux(in.src1(31) =/= in.src2(31), in.src1(31), diff(31)).asUInt }
        is(ALUOp.and){ out := in.src1 & in.src2 }
        is(ALUOp.xor){ out := in.src1 ^ in.src2 }
        is(ALUOp.or) { out := in.src1 | in.src2 }
        is(ALUOp.lui){ out := in.src2 }
        is(ALUOp.sll){ out := in.src1 << in.src2(4,0) }
        is(ALUOp.srl){ out := in.src1 >> in.src2(4,0) }
        is(ALUOp.sra){ out := (in.src1.asSInt >> in.src2(4,0)).asUInt }
    }
}

