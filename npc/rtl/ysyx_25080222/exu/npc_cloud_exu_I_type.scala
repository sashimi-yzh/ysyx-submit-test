package npc_cloud

import chisel3._
import chisel3.util._
//EXU(EXecution Unit): 负责根据控制信号对数据进行执行操作, 并将执行结果写回寄存器或存储器
//I-type

//ebreak指令:利用DPI-C机制, 使得在NPC在执行的时候通知仿真环境结束仿真. 
class npc_cloud_exu_ebreak extends BlackBox with HasBlackBoxResource {
    val io = IO(new Bundle{
        val clk = Input(Clock())  
        val is = Input(Bool())
    } )
    
    addResource("/npc_cloud_DPI_C.v")
    override def desiredName = "ysyx_25080222_exu_ebreak"
}

class npc_cloud_exu_ecall extends Module{
    val io = IO(new Bundle{
        val is = Input(Bool())
        val csr_wdata = Output(UInt(32.W))
        val csr_rdata =Input(UInt(32.W))
        val pc =Input(UInt(32.W))
        val dnpc = Output(UInt(32.W))
    } )
    
    io.csr_wdata := Mux(io.is & !reset.asBool, io.pc, 0.U) 
    io.dnpc := Mux(io.is & !reset.asBool, io.csr_rdata, 0.U) 
}

class npc_cloud_exu_csrrw extends Module{
    val io = IO(new Bundle{
        val is = Input(Bool())
        val rd = Output(UInt(32.W))
        val csr_wdata = Output(UInt(32.W))
        val rs1_data =Input(UInt(32.W))
        val csr_rdata =Input(UInt(32.W))
    } )
    
    io.rd := Mux(io.is & !reset.asBool, io.csr_rdata, 0.U) 
    io.csr_wdata := Mux(io.is & !reset.asBool, io.rs1_data, 0.U) 
}

class npc_cloud_exu_csrrs extends Module{
    val io = IO(new Bundle{
        val is = Input(Bool())
        val rd = Output(UInt(32.W))
        val csr_wdata = Output(UInt(32.W))
        val rs1_data =Input(UInt(32.W))
        val csr_rdata =Input(UInt(32.W))
    } )

    
    io.rd := Mux(io.is & !reset.asBool, io.csr_rdata, 0.U) 
    io.csr_wdata := Mux(io.is & !reset.asBool, (io.csr_rdata | io.rs1_data), 0.U) 
}

class npc_cloud_exu_addi extends Module{
    val io = IO(new Bundle{
        val is = Input(Bool())
        val rd = Output(UInt(32.W))
        val rs1_data =Input(UInt(32.W))
        val imm =Input(UInt(32.W))
    } )


    io.rd := Mux(io.is & !reset.asBool, (io.rs1_data + io.imm), 0.U) 
}

class npc_cloud_exu_sltiu extends Module{
    val io = IO(new Bundle{
        val is = Input(Bool())
        val rd = Output(UInt(32.W))
        val rs1_data =Input(UInt(32.W))
        val imm =Input(UInt(32.W))
    } )
    
     //n位无符号数计算:(0,A)+((0,~B)+1) 借位(结果的n+1位)为1 则A>=B  借位为0则A<B  (也可以当做n+1位有符号正数计算)
    io.rd := Mux(io.is & !reset.asBool, (io.rs1_data < io.imm).asUInt, 0.U) 
}

class npc_cloud_exu_slti extends Module{
    val io = IO(new Bundle{
        val is = Input(Bool())
        val rd = Output(UInt(32.W))
        val rs1_data =Input(UInt(32.W))
        val imm =Input(UInt(32.W))
    } )
    

    io.rd := Mux(io.is & !reset.asBool , (io.rs1_data.asSInt < io.imm.asSInt).asUInt, 0.U)
    //补码（相反数）：取反加一
    //A-B的最高位^溢出为1 A<B
    //溢出判断原理：两个参加加法运算的变量符号相同，而运算结果的符号与其不相同，则运算结果不准确，产生溢出
}

class npc_cloud_exu_xori extends Module{
    val io = IO(new Bundle{
        val is = Input(Bool())
        val rd = Output(UInt(32.W))
        val rs1_data =Input(UInt(32.W))
        val imm =Input(UInt(32.W))
    } )

    io.rd := Mux(io.is & !reset.asBool , (io.rs1_data ^ io.imm), 0.U)
}

class npc_cloud_exu_andi extends Module{
    val io = IO(new Bundle{
        val is = Input(Bool())
        val rd = Output(UInt(32.W))
        val rs1_data =Input(UInt(32.W))
        val imm =Input(UInt(32.W))
    } )
    
    io.rd := Mux(io.is & !reset.asBool , (io.rs1_data & io.imm), 0.U)
}

class npc_cloud_exu_srai extends Module{
    val io = IO(new Bundle{
        val is = Input(Bool())
        val rd = Output(UInt(32.W))
        val rs1_data =Input(UInt(32.W))
        val shamt =Input(UInt(6.W))
    } )

    io.rd := Mux(io.is & !reset.asBool & !io.shamt(5), (io.rs1_data.asSInt >> io.shamt(4,0)).asUInt, 0.U) 
}

class npc_cloud_exu_ori extends Module{
    val io = IO(new Bundle{
        val is = Input(Bool())
        val rd = Output(UInt(32.W))
        val rs1_data =Input(UInt(32.W))
        val imm =Input(UInt(32.W))
    } )
    
    io.rd := Mux(io.is & !reset.asBool, (io.rs1_data | io.imm), 0.U) 
}

class npc_cloud_exu_srli extends Module{
    val io = IO(new Bundle{
        val is = Input(Bool())
        val rd = Output(UInt(32.W))
        val rs1_data =Input(UInt(32.W))
        val shamt =Input(UInt(6.W))
    } )
    
    io.rd := Mux(io.is & !reset.asBool & !io.shamt(5), (io.rs1_data >> io.shamt(4,0)), 0.U) 
}

class npc_cloud_exu_slli extends Module{
    val io = IO(new Bundle{
        val is = Input(Bool())
        val rd = Output(UInt(32.W))
        val rs1_data =Input(UInt(32.W))
        val shamt =Input(UInt(6.W))
    } )

    io.rd := Mux(io.is & !reset.asBool & !io.shamt(5), (io.rs1_data << io.shamt(4,0))(31,0), 0.U) 
    
}

class npc_cloud_exu_jalr extends Module{
    val io = IO(new Bundle{
        val is = Input(Bool())
        val rd = Output(UInt(32.W))
        val dnpc = Output(UInt(32.W))
        val pc =Input(UInt(32.W))
        val rs1_data =Input(UInt(32.W))
        val imm =Input(UInt(32.W))
    } )
    

    io.rd := Mux(io.is & !reset.asBool, (io.pc + 4.U), 0.U) 
    io.dnpc := Mux(io.is & !reset.asBool, (io.rs1_data + io.imm), io.pc) 

}

