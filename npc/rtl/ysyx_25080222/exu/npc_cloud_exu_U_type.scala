package npc_cloud

import chisel3._
import chisel3.util._


//U-type
class npc_cloud_exu_auipc extends Module{
    val io = IO(new Bundle{
        val is = Input(Bool())
        val rd = Output(UInt(32.W))
        val pc =Input(UInt(32.W))
        val imm =Input(UInt(32.W))
    } )
    


    io.rd := Mux(io.is & !reset.asBool, (io.pc + io.imm), 0.U) 
}


class npc_cloud_exu_lui extends Module{
    val io = IO(new Bundle{
        val is = Input(Bool())
        val rd = Output(UInt(32.W))
        val pc =Input(UInt(32.W))
        val imm =Input(UInt(32.W))
    } )

    io.rd := Mux(io.is & !reset.asBool, io.imm, 0.U) 
}