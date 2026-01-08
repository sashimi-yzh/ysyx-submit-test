package npc_cloud

import chisel3._
import chisel3.util._
//LSU(访存单元):收到读写请求后, 出访存请求, load指令则延迟1周期返回读出的数据
class npc_cloud_LSU extends Module { //AXI4-Lite手册禁止：valid不能等对应的ready
    val io = IO(new Bundle {
        val in = Flipped(DecoupledIO(new EXU_TO_LSU_Bundle) )  // 方向反转：从设备
        val out = DecoupledIO(new LSU_TO_WBU_Bundle)  // 输出到WBU
        val axi = new AXI4_Bundle()  // 默认方向：主设备,连接到仲裁器

        val forward = Output(Bool())
    } )

    val lsu_end = RegNext(io.axi.rvalid || io.axi.bvalid, false.B)
    //lsu状态机
    val s_idle :: s_store_ready :: s_load_ready :: s_wait_mem :: Nil = Enum(4)
    val state = RegInit(s_idle)
        state := MuxLookup(state, s_idle, List(
        //s_idle       -> Mux( (io.in.valid && (io.in.bits.wen || io.in.bits.ren)), s_wait_mem, s_idle),  //有访存指令
        s_idle       -> MuxCase( s_idle, Seq(
            (io.in.valid && io.in.bits.wen && !(io.axi.awready && io.axi.wready)) -> s_store_ready,
                               (io.in.valid && io.in.bits.ren && !io.axi.arready) -> s_load_ready,
                              (io.in.valid && (io.in.bits.wen || io.in.bits.ren)) -> s_wait_mem   //有访存指令
                                )    ) ,             
        s_store_ready   -> Mux((io.axi.awready && io.axi.wready), s_wait_mem, s_store_ready),                                                  
        s_load_ready    -> Mux(io.axi.arready, s_wait_mem, s_load_ready),
        s_wait_mem      -> Mux(lsu_end, s_idle, s_wait_mem)
    ))
    
    io.in.ready := (state === s_idle) && !(io.in.valid && (io.in.bits.wen || io.in.bits.ren))
    io.out.valid := MuxCase( false.B, Seq(
        ( (state ===  s_idle) && (io.in.valid && !(io.in.bits.wen || io.in.bits.ren)) ) -> true.B,
        ( (state ===  s_wait_mem) && (io.axi.rvalid || io.axi.bvalid) ) -> true.B
                    )    )

    //when(io.in.valid || io.out.valid){
        // printf("[LSU]in.ready=%d in.valid=%d out.ready=%d out.valid=%d state=%d ", 
        //     io.in.ready, io.in.valid, io.out.ready, io.out.valid, state)
        // printf("pc=0x%x rd=%d\n", 
        //     io.in.bits.pc, io.in.bits.rd )
    //}

    //LSU(访存单元)接口信号
    //读取内存指令(I-type: lw,lb,lbu,lh,lhu)
    io.axi.arvalid := (io.in.bits.ren && io.in.valid) || (state === s_load_ready)
    //io.axi.araddr := Cat(io.in.bits.addr(31,2) , Fill(2, 0.U))  
    io.axi.araddr := ((io.in.bits.addr ) )
    io.axi.arid := 0.U
    io.axi.arsize := MuxCase(0.U, Seq(
                        io.in.bits.lw  -> 2.U,  // 4字节
                        io.in.bits.lh  -> 1.U,  // 2字节
                        io.in.bits.lhu -> 1.U,  // 2字节
                        io.in.bits.lb  -> 0.U,  // 1字节
                        io.in.bits.lbu -> 0.U   // 1字节
    ))
    io.axi.arburst :="b01".U  // 回环地址（用于cache）
    io.axi.arlen := 0.U   // 突发长度为1 
    io.axi.rready :=  (state ===  s_wait_mem)  

    val rdata =   ( io.axi.rdata >> (io.in.bits.addr(1, 0) * 8.U) )
 
    // val rdata =   MuxCase( ( io.axi.rdata >> (io.axi.araddr(1, 0) * 8.U) ) , Seq(  //psram sdram根据地址的低2位对数据进行右移    
    //                 ( (io.axi.araddr >= 0x0f000000.U) && (io.axi.araddr < 0x0f002000.U) )  
    //                 -> ( io.axi.rdata >> (io.axi.araddr(1, 0) * 8.U) ),  //SoC(SRAM)无法访问非对齐地址，会自动调整到低位的最近对齐地址
    //                 ( (io.axi.araddr >= 0x20000000.U) && (io.axi.araddr < 0x20001000.U) )
    //                   -> io.axi.rdata,  //MROM支持非对齐访存
    //                 ( (io.axi.araddr >= 0x30000000.U) && (io.axi.araddr < 0x3fffffff.U) )
    //                   -> io.axi.rdata,  //flash支持非对齐访存
    //                 ) )

    val lsu_rd = Mux1H ( Seq(
            io.in.bits.lw  -> rdata,     //lw读取4字节
            io.in.bits.lb  -> Cat(Fill(24, rdata(7)), rdata(7, 0)), //lb读取1字节并符号扩展
            io.in.bits.lbu -> Cat(0.U(24.W), rdata(7, 0)), //lbu读取1字节并0扩展   
            io.in.bits.lh  -> Cat(Fill(16, rdata(15)), rdata(15, 0)), //lh读取2字节并符号扩展
            io.in.bits.lhu -> Cat(0.U(16.W), rdata(15, 0)),  //lhu读取2字节并0扩展
            !io.in.bits.ren    -> 0.U       // 默认值0   
    ) )  


    //S-type 写入内存指令(sw，sh，sb，都是将rs2_data写入地址rs1_data + imm)
    io.axi.awvalid := (io.in.valid && io.in.bits.wen) || (state === s_store_ready)
    io.axi.awaddr :=  io.in.bits.addr
    io.axi.wvalid := (io.in.valid && io.in.bits.wen) || (state === s_store_ready)
    
    val wmask = Mux1H ( Seq(
                    io.in.bits.sw    ->  "b1111".U,  //sw写入4字节         
                    io.in.bits.sh    ->  "b0011".U,  //sh最低2字节
                    io.in.bits.sb    ->  "b0001".U,  //sb最低字节          
                    !io.in.bits.wen             ->  0.U      ) ) // 默认值0   
    //SoC无法访问非对齐地址，会自动调整到低位的最近对齐地址
    io.axi.wstrb := (wmask << io.axi.awaddr(1, 0))(3,0)//根据地址的低2位对基础wmask进行左移
    io.axi.wdata := io.in.bits.wdata
    io.axi.awsize := Mux1H(Seq(
                    io.in.bits.sw -> 2.U,  // 4字节传输, 2^2 = 4
                    io.in.bits.sh -> 1.U,  // 2字节传输, 2^1 = 2  
                    io.in.bits.sb -> 0.U,  // 1字节传输, 2^0 = 1
                    !io.in.bits.wen          -> 0.U    ))
    io.axi.awid := 0.U
    io.axi.awlen := 0.U
    io.axi.awburst := "b01".U
    io.axi.wlast := true.B
    io.axi.bready :=  (state ===  s_wait_mem)

    //LSU向WBU的输出
    io.out.bits.pc := io.in.bits.pc

    io.out.bits.rd_wdata :=  Mux1H ( Seq(
                io.in.bits.ren                 ->  lsu_rd      ,    //读取内存指令(I-type: lw,lb,lbu,lh,lhu)
                !io.in.bits.ren                ->  io.in.bits.rd_wdata
                ) )  
    io.out.bits.wen_rd := io.in.bits.wen_rd
    io.out.bits.rd := io.in.bits.rd

    io.out.bits.csr_wdata :=  io.in.bits.csr_wdata
    io.out.bits.wen_csr := io.in.bits.wen_csr
    io.out.bits.csr_waddr := io.in.bits.csr_waddr

    io.out.bits.ebreak := io.in.bits.ebreak
    io.out.bits.ecall := io.in.bits.ecall

    io.forward := ( (state ===  s_wait_mem) && (io.axi.rvalid) ) || ( (state ===  s_idle) && (io.in.valid && !io.in.bits.ren) && io.in.bits.wen_rd)



    val lsu_count = Module(new npc_cloud_lsu_count())
    lsu_count.io.clk := clock  
    lsu_count.io.rvalid := io.axi.rvalid && io.axi.rready && (io.axi.rresp === 0.U)
    lsu_count.io.ren := io.axi.arvalid && (state === s_idle)
    lsu_count.io.bvalid := io.axi.bvalid && io.axi.bready && (io.axi.bresp === 0.U)
    lsu_count.io.wen := io.axi.awvalid && io.axi.wvalid && (state === s_idle)


}

class LSU_TO_WBU_Bundle extends Bundle {
    val pc = Output(UInt(32.W))

    val wen_rd = Output(Bool()) 
    val rd = Output(UInt(5.W))
    val rd_wdata = Output(UInt(32.W))
    val wen_csr = Output(Bool()) 
    val csr_waddr = Output(UInt(5.W))
    val csr_wdata = Output(UInt(32.W))
    val ebreak = Output(Bool()) 
    val ecall = Output(Bool()) 
}


