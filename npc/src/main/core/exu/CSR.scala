package npc.core.exu

import chisel3._
import chisel3.util._
import npc.common.Config._
import npc.common._
import npc.common.Instructions._

class CSRIO_in extends Bundle{
    val op1 = Output(UInt(WORD_LEN.W))
    val op2 = Output(UInt(WORD_LEN.W))
    val processtpe = Output(UInt(ProcessTpe.ProcessTpe_Width.W))
}
class CSRIO_out extends Bundle{
    val csr_rdata = Output(UInt(WORD_LEN.W))
}

class CSRIO extends Bundle {
    val in = Flipped(Decoupled(new CSRIO_in))
    val out = Decoupled(new CSRIO_out)
}

class CSR extends Module {
    val io = IO(new CSRIO)
    val io_bj = IO(new EXU_BJIO)

    val (processtpe, op1, addr) = (io.in.bits.processtpe, io.in.bits.op1, io.in.bits.op2(11, 0))

    val mstatus   = RegInit(0x1800.U(WORD_LEN.W))
    val mtvec     = Reg(UInt(WORD_LEN.W))
    val mepc      = Reg(UInt(WORD_LEN.W))
    val mcause    = Reg(UInt(WORD_LEN.W))
    val mvendorid = "h79737978".U(WORD_LEN.W)
    val marchid   = 24080032.U(WORD_LEN.W)

    val rdata = WireDefault(0.U(WORD_LEN.W))
    switch(addr){
        is("h300".U) { rdata := mstatus }
        is("h305".U) { rdata := mtvec }
        is("h341".U) { rdata := mepc }
        is("h342".U) { rdata := mcause }
        is("hf11".U) { rdata := mvendorid }
        is("hf12".U) { rdata := marchid }
    }
    io.out.bits.csr_rdata := rdata

    val wdata = Mux(processtpe(0), rdata | op1, op1)
    when(io.in.valid && ~processtpe(1)){
        switch(addr) {
            is("h305".U) { mtvec := wdata }
            is("h341".U) { mepc  := wdata }
            is("h342".U) { mcause := wdata }
            is("h300".U) { mstatus := wdata }
        }
    }

    when(processtpe === ProcessTpe.CSR.CSR_ECALL && io.in.valid){
        mepc := op1
        mcause := 11.U
    }

    //handshake
    io.in.ready := true.B
    io.out.valid := io.in.valid

    //ecall and mret
    io_bj.valid := processtpe(1) && io.in.valid
    io_bj.target := Mux(processtpe(0), mtvec, mepc)
}
