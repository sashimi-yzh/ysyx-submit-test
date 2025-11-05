package cpu 

import chisel3._ 
import chisel3.util._  


// 控制相关  冲刷IFU、IDU 
class ysyx_23060246_ControlHazard(config: NPCConfig) extends Module{
    val io = IO(new Bundle{
        val ifu_pc = Flipped(Valid(UInt(config.XLEN.W)))
        val idu_pc = Flipped(Valid(UInt(config.XLEN.W)))
        val exu_npc = Flipped(Valid(UInt(config.XLEN.W)))
        val flush = Output(Bool())
    })

    val ifu_flush = io.ifu_pc.valid && (io.exu_npc.bits =/= io.ifu_pc.bits)
    val idu_flush = io.idu_pc.valid && (io.exu_npc.bits =/= io.idu_pc.bits)
    dontTouch(idu_flush)
    dontTouch(ifu_flush)
    io.flush := (ifu_flush || idu_flush) && io.exu_npc.valid

}

// class DataHazards(config: NPCConfig) extends Module{
//     val io = IO(new Bundle{
//         val exu = Flipped(Decoupled(new SigIO_IDU_EXU(config.XLEN)))
//         val idu = Flipped(Decoupled(new SigIO_IFU_IDU(config.XLEN)))
//         val flush = Input(Bool())
//     })

//     val exu_inst = io.exu.bits.inst
//     val idu_inst = io.idu.bits.inst

//     val exu_rd = exu_inst(11,7)
//     val idu_rs1 = idu_inst(19,15)
//     val idu_rs2 = idu_inst(24,20)

//     val rs1_hazard = exu_rd =/= 0.U && exu_rd === idu_rs1
//     val rs2_hazard = exu_rd =/= 0.U && exu_rd === idu_rs2

//     io.exu.ready := ~rs1_hazard && ~rs2_hazard && ~io.flush
//     io.idu.ready := ~rs1_hazard && ~rs2_hazard && ~io.flush

// }