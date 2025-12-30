package npc_cloud

import chisel3._
import chisel3.util._
//import chisel3.experimental._ //BlackBox 机制
//import chisel3.experimental.{IntParam, BaseModule}
//EXU(EXecution Unit): 负责根据控制信号对数据进行执行操作, 并将执行结果写回寄存器或存储器
//J-type

class npc_cloud_exu_mret extends Module{
    val io = IO(new Bundle{
        val is = Input(Bool())
        val csr_rdata =Input(UInt(32.W))
        val dnpc = Output(UInt(32.W))
        val pc =Input(UInt(32.W))
    } )


    io.dnpc := Mux(io.is & !reset.asBool, (io.csr_rdata + 4.U), io.pc) 
}

class npc_cloud_exu_add extends Module{
    val io = IO(new Bundle{
        val is = Input(Bool())
        val rd = Output(UInt(32.W))
        val rs1_data = Input(UInt(32.W))
        val rs2_data = Input(UInt(32.W))
    } )
    
    io.rd := Mux(io.is & !reset.asBool, (io.rs1_data + io.rs2_data), 0.U) 
}

class npc_cloud_exu_sltu extends Module{
    val io = IO(new Bundle{
        val is = Input(Bool())
        val rd = Output(UInt(32.W))
        val rs1_data =Input(UInt(32.W))
        val rs2_data =Input(UInt(32.W))
    } )
    
    io.rd := Mux(io.is & !reset.asBool, (io.rs1_data < io.rs2_data).asUInt, 0.U) 
}

class npc_cloud_exu_slt extends Module{
    val io = IO(new Bundle{
        val is = Input(Bool())
        val rd = Output(UInt(32.W))
        val rs1_data =Input(UInt(32.W))
        val rs2_data =Input(UInt(32.W))
    } )

    io.rd := Mux(io.is & !reset.asBool, (io.rs1_data.asSInt < io.rs2_data.asSInt).asUInt, 0.U) 
        //补码（相反数）：取反加一
    //A-B的最高位^溢出为1 A<B
    //溢出判断原理：两个参加加法运算的变量符号相同，而运算结果的符号与其不相同，则运算结果不准确，产生溢出
}

class npc_cloud_exu_xor extends Module{
    val io = IO(new Bundle{
        val is = Input(Bool())
        val rd = Output(UInt(32.W))
        val rs1_data =Input(UInt(32.W))
        val rs2_data =Input(UInt(32.W))
    } )
    

    io.rd := Mux(io.is & !reset.asBool , (io.rs1_data ^ io.rs2_data), 0.U)
}

class npc_cloud_exu_and extends Module{
    val io = IO(new Bundle{
        val is = Input(Bool())
        val rd = Output(UInt(32.W))
        val rs1_data =Input(UInt(32.W))
        val rs2_data =Input(UInt(32.W))
    } )
    
    io.rd := Mux(io.is & !reset.asBool , (io.rs1_data & io.rs2_data), 0.U)
}

class npc_cloud_exu_sra extends Module{
    val io = IO(new Bundle{
        val is = Input(Bool())
        val rd = Output(UInt(32.W))
        val rs1_data =Input(UInt(32.W))
        val rs2_data =Input(UInt(5.W))
    } )

    io.rd := Mux(io.is & !reset.asBool, ((io.rs1_data.asSInt >> io.rs2_data).asUInt), 0.U) 
}

class npc_cloud_exu_or extends Module{
    val io = IO(new Bundle{
        val is = Input(Bool())
        val rd = Output(UInt(32.W))
        val rs1_data =Input(UInt(32.W))
        val rs2_data =Input(UInt(32.W))
    } )
    
    io.rd := Mux(io.is & !reset.asBool, (io.rs1_data | io.rs2_data), 0.U) 
}

class npc_cloud_exu_srl extends Module{
    val io = IO(new Bundle{
        val is = Input(Bool())
        val rd = Output(UInt(32.W))
        val rs1_data =Input(UInt(32.W))
        val rs2_data =Input(UInt(5.W))
    } )
    

    io.rd := Mux(io.is & !reset.asBool, (io.rs1_data >> io.rs2_data), 0.U) 
}

class npc_cloud_exu_sll extends Module{
    val io = IO(new Bundle{
        val is = Input(Bool())
        val rd = Output(UInt(32.W))
        val rs1_data =Input(UInt(32.W))
        val rs2_data =Input(UInt(5.W))
    } )

    io.rd := Mux(io.is & !reset.asBool, (io.rs1_data << io.rs2_data)(31, 0) , 0.U) 
}

class npc_cloud_exu_sub extends Module{
    val io = IO(new Bundle{
        val is = Input(Bool())
        val rd = Output(UInt(32.W))
        val rs1_data =Input(UInt(32.W))
        val rs2_data =Input(UInt(32.W))
    } )
    

    io.rd := Mux(io.is & !reset.asBool, io.rs1_data - io.rs2_data, 0.U) 
}
