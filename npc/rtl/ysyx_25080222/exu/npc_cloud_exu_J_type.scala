package npc_cloud

import chisel3._
import chisel3.util._
//import chisel3.experimental._ //BlackBox 机制
//import chisel3.experimental.{IntParam, BaseModule}
//EXU(EXecution Unit): 负责根据控制信号对数据进行执行操作, 并将执行结果写回寄存器或存储器
//J-type


class npc_cloud_exu_jal extends Module{
    val io = IO(new Bundle{
        val is = Input(Bool())
        val rd = Output(UInt(32.W))
        val pc = Input(UInt(32.W))
        val dnpc = Output(UInt(32.W))
        val imm =Input(UInt(32.W))
    } )
    

    io.rd := Mux(io.is & !reset.asBool, (io.pc + 4.U), 0.U) 
    io.dnpc := Mux(io.is & !reset.asBool, (io.pc + io.imm), io.pc) 
}