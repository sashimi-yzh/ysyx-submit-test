package cpu 


import chisel3._
import chisel3.util._




class Sig_EXU(xlen:Int) extends Bundle{
    val A_sel = Input(UInt(1.W))
    val B_sel = Input(UInt(1.W))
    val src1 = Input(UInt(xlen.W))
    val src2 = Input(UInt(xlen.W))
    val alu_op = Input(UInt(4.W))
    val imm_sel = Input(UInt(3.W))
   // val csr_cmd = Input(UInt(3.W))
    var br_sel = Input(UInt(3.W))
    val pc_sel = Input(UInt(2.W))
}

class Sig_LSU(xlen:Int) extends  Bundle{
    val ld_sel = Input(UInt(3.W))
    val st_sel = Input(UInt(2.W))
    //val csr_cmd = Input(UInt(3.W))

}

class Sig_WBU(xlen:Int) extends Bundle{
    val wb_sel = Input(UInt(3.W))
    val csr_cmd = Input(UInt(3.W)) 
    val inst_type = Input(UInt(4.W))
}

class Sig_CSR extends Bundle{
    val csr_cmd = Input(UInt(3.W))
}

class SigIO_IFU_IDU(xlen: Int) extends Bundle{
    val inst = Input(UInt(32.W))
    val pc = Input(UInt(xlen.W))
}

class SigIO_IDU_EXU(xlen: Int) extends Bundle{
    val exu = new Sig_EXU(xlen)
    val lsu = new Sig_LSU(xlen)
    val wbu = new Sig_WBU(xlen)
    val inst = Input(UInt(32.W))
    val pc = Input(UInt(xlen.W))
}

class SigIO_EXU_LSU(xlen: Int) extends Bundle{
    val lsu = new Sig_LSU(xlen)
    val wbu = new Sig_WBU(xlen)
    val inst = Input(UInt(32.W))
    val pc = Input(UInt(xlen.W))
    val alu_out = Input(UInt(xlen.W))
    val src1 = Input(UInt(xlen.W))
    val src2 = Input(UInt(xlen.W))
    var rd_addr = Input(UInt(5.W))
    val npc = Input(UInt(xlen.W))
    val csr_out = Input(UInt(xlen.W))
}

class SigIO_LSU_WBU(xlen: Int) extends Bundle{
    val wbu = new Sig_WBU(xlen)
    val inst = Input(UInt(32.W))
    val pc = Input(UInt(xlen.W))
    val alu_out = Input(UInt(xlen.W))
    val ld_data = Input(UInt(xlen.W))
    val rd_addr = Input(UInt(5.W))
    val src1 = Input(UInt(xlen.W))
    val npc = Input(UInt(xlen.W))
    val csr_out = Input(UInt(xlen.W))
}

class SigIO_WBU_IFU(xlen: Int) extends Bundle{
    val npc = Input(UInt(xlen.W))
    val rd_addr = Input(UInt(5.W))
    
}


class SigIO_FORWARD(xlen: Int) extends Bundle{
    val rs1 = Output(UInt(5.W))
    val rs2 = Output(UInt(5.W))
    val rd = Output(UInt(5.W))
    val src1 = Output(UInt(xlen.W))
    val src2 = Output(UInt(xlen.W))
}

// for bpu 
class SigIO_EXU_IFU(xlen: Int) extends Bundle{
    val npc = Input(UInt(xlen.W))
    val pc = Input(UInt(xlen.W))
}