package npc_cloud

import chisel3._
import chisel3.util._
//import chisel3.experimental._ //BlackBox 机制
//import chisel3.experimental.{IntParam, BaseModule}
//EXU(EXecution Unit): 负责根据控制信号对数据进行执行操作, 并将执行结果写回寄存器或存储器
//J-type


class npc_cloud_exu_beq extends Module{
    val io = IO(new Bundle{
        val is = Input(Bool())
        val rs1_data = Input(UInt(32.W))
        val rs2_data = Input(UInt(32.W))
        val pc = Input(UInt(32.W))
        val dnpc = Output(UInt(32.W))
        val imm =Input(UInt(32.W))
    } )
    

    io.dnpc := Mux(io.is & !reset.asBool & (io.rs1_data === io.rs2_data), (io.pc + io.imm), (io.pc + 4.U)) 
}


class npc_cloud_exu_bne extends Module{
    val io = IO(new Bundle{
        val is = Input(Bool())
        val rs1_data = Input(UInt(32.W))
        val rs2_data = Input(UInt(32.W))
        val pc = Input(UInt(32.W))
        val dnpc = Output(UInt(32.W))
        val imm =Input(UInt(32.W))
    } )
    
    io.dnpc := Mux(io.is & !reset.asBool & (io.rs1_data =/= io.rs2_data), (io.pc + io.imm), (io.pc + 4.U)) 
}



class npc_cloud_exu_bge extends Module{
    val io = IO(new Bundle{
        val is = Input(Bool())
        val rs1_data =Input(UInt(32.W))
        val rs2_data =Input(UInt(32.W))
        val pc = Input(UInt(32.W))
        val dnpc = Output(UInt(32.W))
        val imm =Input(UInt(32.W))
    } )


    //A-B的最高位^溢出为1 A<B
    io.dnpc := Mux(io.is & !reset.asBool & (io.rs1_data.asSInt >= io.rs2_data.asSInt), 
                                (io.pc + io.imm), (io.pc + 4.U)) 
}

class npc_cloud_exu_bgeu extends Module{
    val io = IO(new Bundle{
        val is = Input(Bool())
        val rs1_data =Input(UInt(32.W))
        val rs2_data =Input(UInt(32.W))
        val pc = Input(UInt(32.W))
        val dnpc = Output(UInt(32.W))
        val imm =Input(UInt(32.W))
    } )
    
    //n位无符号数计算:(0,A)+((0,~B)+1) 借位(结果的n+1位)为1 则A>=B  借位为0则A<B  (也可以当做n+1位有符号正数计算)

    io.dnpc := Mux(io.is & !reset.asBool & (io.rs1_data >= io.rs2_data), (io.pc + io.imm), (io.pc + 4.U)) 
}


class npc_cloud_exu_blt extends Module{
    val io = IO(new Bundle{
        val is = Input(Bool())
        val rs1_data =Input(UInt(32.W))
        val rs2_data =Input(UInt(32.W))
        val pc = Input(UInt(32.W))
        val dnpc = Output(UInt(32.W))
        val imm =Input(UInt(32.W))
    } )

    //A-B的最高位^溢出为1 A<B
    io.dnpc := Mux(io.is & !reset.asBool & (io.rs1_data.asSInt < io.rs2_data.asSInt), 
                            (io.pc + io.imm), (io.pc + 4.U)) 
}

class npc_cloud_exu_bltu extends Module{
    val io = IO(new Bundle{
        val is = Input(Bool())
        val rs1_data =Input(UInt(32.W))
        val rs2_data =Input(UInt(32.W))
        val pc = Input(UInt(32.W))
        val dnpc = Output(UInt(32.W))
        val imm =Input(UInt(32.W))
    } )
    

    io.dnpc := Mux(io.is & !reset.asBool & (io.rs1_data < io.rs2_data), 
                                (io.pc + io.imm), (io.pc + 4.U)) 
}