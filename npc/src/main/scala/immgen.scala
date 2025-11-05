package cpu


import chisel3._
import chisel3.util._




class ImmGenIO(xlen: Int) extends Bundle {
    val inst = Input(UInt(xlen.W))
    val sel = Input(UInt(3.W))
    val out = Output(UInt(xlen.W))
}


class ysyx_23060246_ImmGen(xlen: Int) extends Module{
    val io = IO(new ImmGenIO(xlen))


    val immI = io.inst(31, 20).asSInt
    val immU = Cat(io.inst(31, 12), 0.U(12.W)).asSInt
    val immS = Cat(io.inst(31, 25), io.inst(11, 7)).asSInt
    val immJ = Cat(io.inst(31), io.inst(19, 12), io.inst(20), io.inst(30, 25), io.inst(24, 21), 0.U(1.W)).asSInt
    val immB = Cat(io.inst(31), io.inst(7), io.inst(30, 25), io.inst(11, 8), 0.U(1.W)).asSInt
    import imm_sel._
    io.out := MuxLookup(io.sel, 0.S)(Seq(
            IMM_I -> immI,
            IMM_U -> immU,
            IMM_S -> immS,
            IMM_J -> immJ,
            IMM_B -> immB
        )
    ).asUInt

}
