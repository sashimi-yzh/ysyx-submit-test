package cpu 


import chisel3._
import chisel3.util._

import csr_addr._
import csr_cmd._
//import defines._

class CSRIO(xlen:Int) extends Bundle{
  val cmd = Input(UInt(3.W))

  val in = Input(UInt(xlen.W))
  val out = Output(UInt(xlen.W))
  
  val inst = Input(UInt(32.W))
  val pc = Input(UInt(xlen.W))
  val target_pc = Output(UInt(xlen.W))

  val update_enable = Input(Bool()) 
}

class ysyx_23060246_CSR(config: NPCConfig) extends Module{
  val io = IO(new CSRIO(config.XLEN))

  val xlen = config.XLEN 

  val mepc = RegInit(0.U(xlen.W))
  val mcause = RegInit(0.U(xlen.W))
  //val mtvec = RegInit(Mux((xlen.U === 32.U), 0x100.U(32.W), 0x80000000L.U(64.W)))
  //val mstatus = RegInit(Mux((xlen.U === 32.U), 0x1800.U(32.W), 0xa00001800L.U(64.W)))
  val mtvec = RegInit(config.MTVEC_INIT.U(xlen.W))
  val mstatus = RegInit(config.MSTATUS_INIT.U(xlen.W))

  var csr_regs = Seq(
    BitPat(CSR_MEPC) -> mepc,
    BitPat(CSR_MCAUSE) -> mcause,
    BitPat(CSR_MTVEC) -> mtvec,
    BitPat(CSR_MSTATUS) -> mstatus,
    BitPat(CSR_VENDORID) -> 0x79737978.U,
    BitPat(CSR_MARCHID) -> 23060246.U
  )
  
  val addr = io.inst(31, 20)
 
// lookup 更适用于查找表结构（如 ROM、RAM 或其他数据存储结构），尤其是表项较少的情况。
// muxlookup 更适用于需要选择不同值的情况，特别是在较高效的硬件实现中，它能利用 MUX 逻辑来减少资源消耗。
  //io.out := Lookup(addr, 0.U, csr_regs).asUInt

  io.out := MuxLookup(addr, 0.U(xlen.W))(Seq(
    CSR_MSTATUS -> mstatus,
    CSR_MTVEC -> mtvec,
    CSR_MEPC -> mepc,
    CSR_MCAUSE -> mcause,
    CSR_VENDORID -> 0x79737978.U,
    CSR_MARCHID -> 23060246.U
))

  // ebreak 在 control.scal 由dpi-c实现
  //val is_ecall = io.inst === insts.ecall  // INFO 这里还可以优化很多地方
  val is_ecall = io.cmd === CSR_P && io.inst(21,20) === 0x0.U && io.inst(29,27) === "b000".U
  //val is_mret = io.inst === insts.mret
  val is_mret = io.cmd === CSR_P && io.inst(21,20) === 0x2.U && io.inst(29,27) === "b110".U

  val rs1_addr = io.inst(19, 15)

  //If rd=x0, then the instruction shall not read the CSR and 
  //shall not cause any of the side effects that might occur on a CSR read.
  val we = io.cmd === CSR_W || io.cmd === CSR_S || io.cmd === CSR_C && rs1_addr.orR 

  val wdata = MuxLookup(io.cmd, 0.U)(Seq(
    CSR_W -> io.in,
    //CSR_C -> (io.in & ~Lookup(addr, 0.U, csr_regs)),
    CSR_C -> (io.in & ~io.out),
    //CSR_S -> (io.in | Lookup(addr, 0.U, csr_regs)),
    CSR_S -> (io.in | io.out),  
  ))
  dontTouch(wdata)
  when(RegNext(we)){
  when(addr === CSR_MEPC) { mepc := wdata }
  .elsewhen(addr === CSR_MCAUSE) { mcause := wdata }
  .elsewhen(addr === CSR_MTVEC) { mtvec := wdata }
  .elsewhen(addr === CSR_MSTATUS) { mstatus := wdata }
  }

  //防止一条指令内变化多次
  val mstatus_tmp = RegInit(config.MSTATUS_INIT.U(32.W))
  when(io.update_enable && is_mret){
    mstatus := mstatus_tmp
  }

  when(is_ecall){
    mepc := io.pc >> 2 << 2
    //mcause := 0x8000000000000000.U
    mstatus := 0x1800.U
    mcause := 0xb.U // ECall from M-mode
    io.target_pc := mtvec
  }.elsewhen(is_mret){
      mstatus_tmp := Cat(mstatus(31, 13), 
                 0.U(2.W),            
                 mstatus(10, 8),  
                 1.U(1.W),      // MPIE
                 mstatus(6, 4),   
                 mstatus(7),        // MIE
                 mstatus(2, 0))   
    io.target_pc := mepc
  }.otherwise{
    io.target_pc := 0.U
  }

}