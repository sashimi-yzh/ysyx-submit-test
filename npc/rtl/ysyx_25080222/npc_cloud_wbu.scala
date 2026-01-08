package npc_cloud

import chisel3._
import chisel3.util._
//WBU(Write Back Unit)：写回单元(寄存器)
class npc_cloud_wbu(ADDR_WIDTH: Int = 5, DATA_WIDTH: Int = 32) extends Module {
    val io = IO(new Bundle {
        val in = Flipped(DecoupledIO(new LSU_TO_WBU_Bundle)) 
        val out = DecoupledIO(UInt(1.W))
       
        val rs1_data = Output(UInt(DATA_WIDTH.W))
        val rs1_addr = Input(UInt(ADDR_WIDTH.W))
        val rs2_data = Output(UInt(DATA_WIDTH.W))
        val rs2_addr = Input(UInt(ADDR_WIDTH.W))
        val csr_rdata = Output(UInt(DATA_WIDTH.W))
        val csr_raddr = Input(UInt(ADDR_WIDTH.W))

        val forward = Output(Bool())
    } )

    //wbu状态机
    io.in.ready := true.B      // WBU只是简单写回，没有延迟
    io.out.valid := io.in.valid
    io.out.bits := io.in.bits.ebreak

    val rf = RegInit(VecInit(Seq.fill(32)(0.U(DATA_WIDTH.W)) ) )
    
    // 使用四位数组管理CSR寄存器
    val csr = RegInit(VecInit(Seq(
        0.U(DATA_WIDTH.W),                    // 0: MCAUSE
        0.U(DATA_WIDTH.W),                    // 1: MSTATUS
        0.U(DATA_WIDTH.W),                    // 2: MEPC
        "ha0000000".U(DATA_WIDTH.W),           // 3: MTVEC - 设置为初始地址
        "h79737978".U(DATA_WIDTH.W),           // 4: mvendorid - ysyx的ASCII码, 即0x79737978
        0x25080222.U(DATA_WIDTH.W)              // 5: marchid - 学号数字部分
    ) ) )

    io.rs1_data := Mux(io.rs1_addr === 0.U, 0.U, rf(io.rs1_addr) )
    io.rs2_data := Mux(io.rs2_addr === 0.U, 0.U, rf(io.rs2_addr) )
    io.csr_rdata := Mux(io.csr_raddr < 6.U, csr(io.csr_raddr(2,0)), 0.U)
    io.forward := io.in.valid && io.in.bits.wen_rd

    rf( io.in.bits.rd) := Mux( (io.in.valid && io.in.bits.wen_rd &&  io.in.bits.rd =/= 0.U),
                                io.in.bits.rd_wdata, rf( io.in.bits.rd) ) 

    rf(0) := 0.U      //$0寄存器恒为0
    
    csr( io.in.bits.csr_waddr(2,0)) := Mux( (io.in.valid && io.in.bits.wen_csr &&  io.in.bits.csr_waddr < 4.U),
                               io.in.bits.csr_wdata, csr( io.in.bits.csr_waddr(2,0)) )  

    csr(0.U) := Mux( (io.in.valid && io.in.bits.wen_csr && io.in.bits.ecall),
                               11.U, csr(0.U) )   //ecall指令修改 MCAUSE  储存异常原因
    
   // when(io.out.valid){
        // printf("[WBU]in.ready=%d in.valid=%d out.ready=%d out.valid=%d ", 
        //     io.in.ready, io.in.valid, io.out.ready, io.out.valid)
        // printf("pc=0x%x rd=%d wdata=0x%x out.bits(ebreak)=%d\n",  
        //     io.in.bits.pc, io.in.bits.rd, io.in.bits.rd_wdata, io.out.bits)
    //}


    val reg_trace = Module(new npc_cloud_reg_trace())
    reg_trace.io.clk := clock     
    reg_trace.io.valid := !reset.asBool && io.out.valid
    reg_trace.io.wen := io.in.bits.wen_rd & !reset.asBool
    reg_trace.io.waddr :=  io.in.bits.rd      
    reg_trace.io.wdata := io.in.bits.rd_wdata  





}
