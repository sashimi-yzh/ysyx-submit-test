package npc_cloud

import chisel3._
import chisel3.util._

//处理器基本架构
//class ysyx_25080222(pc_init: String = "h30000000") extends Module {
class ysyx_25080222 extends Module {

    val io = IO(new Bundle {
        //val valid = Output(Bool())
        val interrupt = Input(Bool())
        val master = new AXI4_Bundle()  // 方向：主设备
        val slave = Flipped(new AXI4_Bundle())   // 方向：从设备
    } )

    //对于不使用的顶层输出端口, 需要将其赋值为常数0
    io.slave.awready := true.B // 写地址通道 
    io.slave.wready := true.B
    io.slave.bvalid := io.slave.awvalid && io.slave.wvalid // 写响应通道
    io.slave.bresp := 0.U
    io.slave.bid := 0.U
    io.slave.arready := true.B // 读地址通道 
    io.slave.rvalid := false.B // 读数据通道 

    io.slave.rresp := 0.U
    io.slave.rdata := 0.U
    io.slave.rlast := true.B
    io.slave.rid := 0.U

    //val ifu = Module(new npc_cloud_ifu(pc_init))  //取址模块实例化
    val ifu = Module(new npc_cloud_ifu)  //取址模块实例化
    //val ifu = withModulePrefix("ysyx_25080222") { Module(new npc_cloud_ifu(pc_init)) }
    val idu = Module(new npc_cloud_idu)  //译码模块实例化
    val exu = Module(new npc_cloud_exu)  //指令执行模块实例化
    val lsu = Module(new npc_cloud_LSU)   //lsu(访存单元)模块连线
    val wbu = Module(new npc_cloud_wbu)  //写回单元(寄存器)模块实例化

    def pipelineConnect[T <: Data, T2 <: Data](prevOut: DecoupledIO[T],
                            thisIn: DecoupledIO[T], thisOut: DecoupledIO[T2]) = {
        prevOut.ready := thisIn.ready
        thisIn.bits := RegEnable(prevOut.bits, prevOut.valid && thisIn.ready)
        //thisIn.valid := ???
        thisIn.valid := RegNext(prevOut.valid && thisIn.ready, false.B)
    }

    pipelineConnect(ifu.io.out, idu.io.in, idu.io.out)
    pipelineConnect(idu.io.out, exu.io.in, exu.io.out)
    pipelineConnect(exu.io.out, lsu.io.in, lsu.io.out)
    pipelineConnect(lsu.io.out, wbu.io.in, wbu.io.out)
      
    // StageConnect(ifu.io.out, idu.io.in)
    // StageConnect(idu.io.out, exu.io.in)
    // StageConnect(exu.io.out, wbu.io.in)
    
    def conflict(rs: UInt, rd: UInt) = (rs === rd)
    def conflictWithRd(rs1: UInt, rs2: UInt, rd: UInt) = {
        ( conflict(rs1, rd) || conflict(rs2, rd) ) && (rd =/= 0.U)
    }
    // val isRAW = (conflictWithRd(idu.io.rs1, idu.io.rs2, exu.io.in.bits.rd) && exu.io.in.valid && (idu.io.in.bits.pc =/= exu.io.in.bits.pc)) ||
    //             (conflictWithRd(idu.io.rs1, idu.io.rs2, lsu.io.in.bits.rd) && lsu.io.in.valid && (idu.io.in.bits.pc =/= lsu.io.in.bits.pc)) 
    //             (conflictWithRd(idu.io.rs1, idu.io.rs2, wbu.io.in.bits.rd) && wbu.io.in.valid && (idu.io.in.bits.pc =/= wbu.io.in.bits.pc))
    /*实现转发技术后，load指令在LS阶段也需要在总线的R通道握手后才能得到返回的数据,所以load指令在EXU阶段和LSU数据读取之前 RAW堵塞*/
    val isRAW_exu = (conflictWithRd(idu.io.rs1, idu.io.rs2, exu.io.in.bits.rd) && exu.io.in.valid && (idu.io.in.bits.pc =/= exu.io.in.bits.pc) && exu.io.out.bits.ren)
    //val isRAW_lsu = (conflictWithRd(idu.io.rs1, idu.io.rs2, lsu.io.in.bits.rd) && lsu.io.in.valid && (idu.io.in.bits.pc =/= lsu.io.in.bits.pc) && lsu.io.in.bits.ren && !lsu.io.out.valid) 
    val isRAW_lsu = (conflictWithRd(idu.io.rs1, idu.io.rs2, lsu.io.in.bits.rd) && lsu.io.in.valid && (idu.io.in.bits.pc =/= lsu.io.in.bits.pc) && lsu.io.in.bits.ren && !lsu.io.out.valid) 

    val isRAW = isRAW_exu || isRAW_lsu
    


    val icache = Module(new npc_cloud_icache())   //instruction cache
    icache.io.in <> ifu.io.axi                    //ifu模块连线
    icache.io.fence_i := idu.io.out.bits.fencei && idu.io.in.valid   //fence.i指令，更新缓存

    /*arbiter(仲裁器)从IFU和LSU中选择一个请求转发给下游Xbar(连接到cpu外部的SoC)*/
    val arbiter = Module(new AXI4_Arbiter())  //AXI4-Lite仲裁器
    //arbiter.io.ifu <> ifu.io.axi             //ifu模块连线
    arbiter.io.ifu <> icache.io.out             //ifu(icache)模块连线
    arbiter.io.lsu <> lsu.io.axi             //lsu模块连线

    io.master <> arbiter.io.axi

     /*各个模块额外的信号连接*/

    /*取值模块连接(输入信号)*/
    ifu.io.idu_en_dnpc := idu.io.out.bits.en_dnpc
    ifu.io.exu_en_dnpc := exu.io.in.bits.en_dnpc && (idu.io.in.bits.pc === exu.io.in.bits.pc) && exu.io.in.valid
    ifu.io.exu_dnpc := exu.io.dnpc 
    ifu.io.idu_fence_i := idu.io.out.bits.fencei
    ifu.io.exu_fence_i := exu.io.in.bits.fencei && (idu.io.in.bits.pc === exu.io.in.bits.pc) && exu.io.in.valid
    ifu.io.valid := wbu.io.out.valid
    ifu.io.ebreak := idu.io.out.bits.ebreak  

    //IDU读取寄存器数据
    idu.io.rs1_data := wbu.io.rs1_data   //读取寄存器数据     
    idu.io.rs2_data := wbu.io.rs2_data
    idu.io.raw := isRAW
    idu.io.csr_rdata := wbu.io.csr_rdata
    idu.io.forward_rs1 := (exu.io.forward && ( conflict(idu.io.rs1, exu.io.in.bits.rd) && (exu.io.in.bits.rd =/= 0.U) )  && (idu.io.in.bits.pc =/= exu.io.in.bits.pc) ) || 
                            (lsu.io.forward && ( conflict(idu.io.rs1, lsu.io.in.bits.rd) && (lsu.io.in.bits.rd =/= 0.U) ) && lsu.io.out.valid && (idu.io.in.bits.pc =/= lsu.io.in.bits.pc) ) ||
                            (wbu.io.forward && ( conflict(idu.io.rs1, wbu.io.in.bits.rd) && (wbu.io.in.bits.rd =/= 0.U) ) && wbu.io.in.valid && (idu.io.in.bits.pc =/= wbu.io.in.bits.pc) )

    idu.io.forward_rs2 := (exu.io.forward && ( conflict(idu.io.rs2, exu.io.in.bits.rd) && (exu.io.in.bits.rd =/= 0.U) ) && (idu.io.in.bits.pc =/= exu.io.in.bits.pc) ) || 
                            (lsu.io.forward && ( conflict(idu.io.rs2, lsu.io.in.bits.rd) && (lsu.io.in.bits.rd =/= 0.U) ) && lsu.io.out.valid && (idu.io.in.bits.pc =/= lsu.io.in.bits.pc) ) ||
                            (wbu.io.forward && ( conflict(idu.io.rs2, wbu.io.in.bits.rd) && (wbu.io.in.bits.rd =/= 0.U) ) && wbu.io.in.valid && (idu.io.in.bits.pc =/= wbu.io.in.bits.pc) )
    idu.io.forward_rs1_data := MuxCase(0.U, Seq(
            (exu.io.forward && ( conflict(idu.io.rs1, exu.io.in.bits.rd) && (exu.io.in.bits.rd =/= 0.U) )  && (idu.io.in.bits.pc =/= exu.io.in.bits.pc) ) -> exu.io.out.bits.rd_wdata,
            (lsu.io.forward && ( conflict(idu.io.rs1, lsu.io.in.bits.rd) && (lsu.io.in.bits.rd =/= 0.U) ) && lsu.io.out.valid && (idu.io.in.bits.pc =/= lsu.io.in.bits.pc) )  -> lsu.io.out.bits.rd_wdata,
            (wbu.io.forward && ( conflict(idu.io.rs1, wbu.io.in.bits.rd) && (wbu.io.in.bits.rd =/= 0.U) ) && wbu.io.in.valid && (idu.io.in.bits.pc =/= wbu.io.in.bits.pc) ) -> wbu.io.in.bits.rd_wdata
    ))
    idu.io.forward_rs2_data := MuxCase(0.U, Seq(
            (exu.io.forward && ( conflict(idu.io.rs2, exu.io.in.bits.rd) && (exu.io.in.bits.rd =/= 0.U) )  && (idu.io.in.bits.pc =/= exu.io.in.bits.pc) ) -> exu.io.out.bits.rd_wdata,
            (lsu.io.forward && ( conflict(idu.io.rs2, lsu.io.in.bits.rd) && (lsu.io.in.bits.rd =/= 0.U) ) && lsu.io.out.valid && (idu.io.in.bits.pc =/= lsu.io.in.bits.pc) )  -> lsu.io.out.bits.rd_wdata,
            (wbu.io.forward && ( conflict(idu.io.rs2, wbu.io.in.bits.rd) && (wbu.io.in.bits.rd =/= 0.U) ) && wbu.io.in.valid && (idu.io.in.bits.pc =/= wbu.io.in.bits.pc) ) -> wbu.io.in.bits.rd_wdata
    ))
    //wbu.io.rd_waddr := idu.io.rd         //写回单元(寄存器)模块(输入信号)，读取寄存器地址                                                                                    
    wbu.io.rs1_addr := idu.io.rs1
    wbu.io.rs2_addr := idu.io.rs2
    wbu.io.csr_raddr := idu.io.csr_raddr
    wbu.io.out.ready := true.B 

    val ebreak = Module(new npc_cloud_exu_ebreak())
    ebreak.io.clk := clock 
    ebreak.io.is := wbu.io.out.bits.asBool  //译码识别为ebreak指令

}


// object StageConnect {
//     def apply[T <: Data](left: DecoupledIO[T], right: DecoupledIO[T]) = {
//         val arch = "multi"
//         // 为展示抽象的思想, 此处代码省略了若干细节
//         if      (arch == "single")   { right.bits := left.bits  }
//         else if (arch == "multi")    { right <> left }
//         else if (arch == "pipeline") { right <> RegEnable(left, left.fire) }
//         else if (arch == "ooo")      { right <> Queue(left, 16) }
//     }
// }


//AXI4仲裁器:用于从IFU和LSU中选择一个请求转发给下游（实际上包括Xbar,访问CLINK的时候不通过SoC直接访问CLINK）
class AXI4_Arbiter extends Module {    
    val io = IO(new Bundle {
        val ifu = Flipped(new AXI4_Bundle())  // 方向反转：从设备
        val lsu = Flipped(new AXI4_Bundle())  // 方向反转：从设备
        val axi = new AXI4_Bundle()  // 方向：主设备连接到cpu外部的SoC
    })

    //io.lsu <> io.axi  //写入通道直接跟lsu连接
    val clink = Module(new npc_cloud_CLINT())

    val ifu_end = RegNext(io.axi.rvalid && io.axi.rlast, false.B)
    val lsu_end = RegNext(io.lsu.rvalid || io.lsu.bvalid, false.B)
    //AXI4仲裁器状态机
    val s_idle :: s_lsu_mem :: s_ifu_mem :: Nil = Enum(3)
    val state = RegInit(s_idle)
    state := MuxLookup(state, s_idle, List(
        s_idle -> MuxCase(s_idle, Seq(
                                (io.lsu.arvalid || (io.lsu.wvalid && io.lsu.awvalid)) -> s_lsu_mem ,
                                (io.ifu.arvalid) -> s_ifu_mem) ),              // LSU优先
        s_lsu_mem -> Mux( lsu_end , s_idle, s_lsu_mem),  // LSU读取完数据：切换 
        s_ifu_mem -> Mux( ifu_end , s_idle, s_ifu_mem)                    // IFU读取完数据：切换 
    ))



    val is_clink = ( (io.lsu.araddr >= "h02000000".U(32.W)) &&  //判断是否为时钟的地址空间
                   (io.lsu.araddr < "h02010000".U(32.W)) )

    clink.io.axi.araddr :=  Mux(((state === s_idle) && io.lsu.arvalid && is_clink), io.lsu.araddr, 0.U)
    clink.io.axi.arvalid :=  Mux(((state === s_idle) && io.lsu.arvalid && is_clink), io.lsu.arvalid, 0.U)
    clink.io.axi.rready := Mux( (state === s_idle), io.ifu.rready, false.B)
    clink.io.axi.arid := io.lsu.arid
    clink.io.axi.arlen := io.lsu.arlen
    clink.io.axi.arsize := io.lsu.arsize
    clink.io.axi.arburst := io.lsu.arburst
    //clink不使用的写通道设定默认响应
    clink.io.axi.awvalid := false.B 
    clink.io.axi.awaddr := 0.U
    clink.io.axi.awid := 0.U
    clink.io.axi.awlen := 0.U
    clink.io.axi.awsize := 0.U
    clink.io.axi.awburst := 0.U
    clink.io.axi.wvalid := false.B
    clink.io.axi.wdata := 0.U
    clink.io.axi.wstrb := 0.U
    clink.io.axi.wlast := false.B
    clink.io.axi.bready := false.B   
    //用于从IFU和LSU中选择一个请求转发给下游Xbar
    io.axi.arvalid :=  MuxCase(false.B, Seq(
                                ((state === s_idle) && io.lsu.arvalid && !is_clink) -> io.lsu.arvalid,
                                ((state === s_idle) && io.ifu.arvalid && !(io.lsu.arvalid || (io.lsu.wvalid && io.lsu.awvalid))) -> io.ifu.arvalid) )    
    io.axi.araddr := MuxCase(0.U, Seq(
             ((state === s_lsu_mem) || ( (state === s_idle) && io.lsu.arvalid && !is_clink) ) -> io.lsu.araddr ,
       ((state === s_ifu_mem) || ( (state === s_idle) && io.ifu.arvalid && !io.lsu.arvalid) ) -> io.ifu.araddr) )
    io.axi.rready := MuxCase(false.B, Seq(    
             ((state === s_lsu_mem) || ( (state === s_idle) && io.lsu.arvalid && !is_clink) ) -> io.lsu.rready,
       ((state === s_ifu_mem) || ( (state === s_idle) && io.ifu.arvalid && !io.lsu.arvalid) ) -> io.ifu.rready  ) )
    io.axi.arid := MuxCase(0.U, Seq(
             ((state === s_lsu_mem) || ( (state === s_idle) && io.lsu.arvalid && !is_clink) ) -> io.lsu.arid ,
       ((state === s_ifu_mem) || ( (state === s_idle) && io.ifu.arvalid && !io.lsu.arvalid) ) -> io.ifu.arid) )
    io.axi.arsize := MuxCase(0.U, Seq(
             ((state === s_lsu_mem) || ( (state === s_idle) && io.lsu.arvalid && !is_clink) ) -> io.lsu.arsize ,
       ((state === s_ifu_mem) || ( (state === s_idle) && io.ifu.arvalid && !io.lsu.arvalid) ) -> io.ifu.arsize) )
    io.axi.arburst := MuxCase(0.U, Seq(
             ((state === s_lsu_mem) || ( (state === s_idle) && io.lsu.arvalid && !is_clink) ) -> io.lsu.arburst ,
       ((state === s_ifu_mem) || ( (state === s_idle) && io.ifu.arvalid && !io.lsu.arvalid) ) -> io.ifu.arburst) )  
    io.axi.arlen := MuxCase(0.U, Seq(
             ((state === s_lsu_mem) || ( (state === s_idle) && io.lsu.arvalid && !is_clink) ) -> io.lsu.arlen ,
       ((state === s_ifu_mem) || ( (state === s_idle) && io.ifu.arvalid && !io.lsu.arvalid) ) -> io.ifu.arlen ) )
    //ifu读通道输出
    io.ifu.arready := Mux( ( (state === s_idle) && !(io.lsu.arvalid || (io.lsu.wvalid && io.lsu.awvalid)) ), io.axi.arready, false.B)
    io.ifu.rdata := Mux( (state === s_ifu_mem), io.axi.rdata, false.B) 
    io.ifu.rvalid :=  Mux( (state === s_ifu_mem), io.axi.rvalid, false.B)
    io.ifu.rresp := Mux( (state === s_ifu_mem), io.axi.rresp, 0.U)
    io.ifu.rlast := Mux( (state === s_ifu_mem), io.axi.rlast, false.B)
    io.ifu.rid := Mux((state === s_ifu_mem), io.axi.rid, 0.U)     
    //IFU不使用的写通道设定默认响应
    io.ifu.awready := false.B   
    io.ifu.wready := false.B
    io.ifu.bvalid := false.B
    io.ifu.bresp := 0.U
    io.ifu.bid := 0.U    
    //lsu读通道输出
    io.lsu.arready := MuxCase(false.B, Seq(
        ( (state === s_idle) && is_clink) -> clink.io.axi.arready,     // 时钟读取优先级最高
        (state === s_idle) -> io.axi.arready ))     // 然后是内存读取
    io.lsu.rdata := MuxCase(false.B, Seq(
        ( (state === s_lsu_mem) && is_clink) -> clink.io.axi.rdata,       // 时钟数据
        (state === s_lsu_mem) -> io.axi.rdata))         // 内存数据
    io.lsu.rvalid := MuxCase(false.B, Seq(
        ( (state === s_lsu_mem) && is_clink) -> clink.io.axi.rvalid,      // 时钟有效
        (state === s_lsu_mem) -> io.axi.rvalid  ))       // 内存有效
    io.lsu.rresp := MuxCase(0.U, Seq(      
        ( (state === s_lsu_mem) && is_clink) -> clink.io.axi.rresp,       // 时钟响应
       (state === s_lsu_mem) -> io.axi.rresp    ))      // 内存响应
    io.lsu.rid := MuxCase(0.U, Seq(      
        ( (state === s_lsu_mem) && is_clink) -> clink.io.axi.rid,       // 时钟响应
       (state === s_lsu_mem) -> io.axi.rid    ))      // 内存响应
    io.lsu.rlast := MuxCase(0.U, Seq(      
        ( (state === s_lsu_mem) && is_clink) -> clink.io.axi.rlast,       // 时钟响应
       (state === s_lsu_mem) -> io.axi.rlast    ))      // 内存响应
    //写入通道直接跟lsu连接
    io.axi.awvalid :=  Mux( ( (state === s_idle) && !is_clink) , io.lsu.awvalid, 0.U)  
    io.axi.wvalid :=  Mux( ( (state === s_idle) && !is_clink) , io.lsu.wvalid, 0.U)

    io.axi.awaddr :=  io.lsu.awaddr  
    io.axi.awid :=  io.lsu.awid 
    io.axi.awlen :=  io.lsu.awlen  
    io.axi.awsize :=  io.lsu.awsize  
    io.axi.awburst :=  io.lsu.awburst    

    io.axi.wdata :=  io.lsu.wdata 
    io.axi.wstrb :=  io.lsu.wstrb  
    io.axi.wlast :=  io.lsu.wlast  

    io.axi.bready :=  io.lsu.bready 


    io.lsu.awready :=  Mux( (state === s_idle) , Mux( (!is_clink) , io.axi.awready, true.B), 0.U)  
    io.lsu.wready :=  Mux( (state === s_idle) , Mux( (!is_clink) , io.axi.wready, true.B), 0.U) 

    io.lsu.bvalid :=  Mux( (state === s_lsu_mem) , io.axi.bvalid, 0.U)  
    io.lsu.bresp :=  io.axi.bresp 
    io.lsu.bid :=  io.axi.bid
  
                        
    when(io.axi.rvalid && io.axi.rresp =/= 0.U){ //判断指示读操作是否成功
            //printf("[AXI4_Arbiter]rvalid=%d rresp=%d\n",io.axi.rvalid, io.axi.rresp)
            assert(false.B, "[AXI4_Arbiter]Invalid read address access.\n")
    }

    when(io.axi.bvalid && io.axi.bresp =/= 0.U){   //判断指示写操作是否成功
        //printf("[AXI4_Arbiter]bvalid=%d bresp=%d\n",io.axi.bvalid, io.axi.bresp)
        assert(false.B, "[AXI4_Arbiter]Invalid write address access.\n")
    }

}



//CLINT(Core Local INTerrupt controller,核心本地中断控制器)
class npc_cloud_CLINT extends Module { //AXI4-Lite手册禁止：valid不能等对应的ready
    val io = IO(new Bundle {
        val axi = Flipped(new AXI4_Bundle())  // 方向反转：从设备
    } )

    val mtime = RegInit(0.U(64.W))
    mtime := mtime + 1.U

    //CLINT读通道设定
    io.axi.arready := !io.axi.rvalid 
    io.axi.rresp := 0.U
                        // RegNext( Mux((io.axi.araddr === "h02000000".U(32.W)) ||
                        //  (io.axi.araddr === "h02000004".U(32.W)), 0.U, "b11".U) )
    io.axi.rvalid :=  RegNext(  io.axi.arvalid )   
    // io.axi.rdata := RegNext( MuxCase(0.U, Seq(
    //         !io.axi.arvalid                         -> 0.U,           // 保护条件：地址无效时返回0
    //         (io.axi.araddr === "h02000000".U(32.W)) -> mtime(31, 0),  // mtime低32位
    //         (io.axi.araddr === "h02000004".U(32.W)) -> mtime(63, 32)   // mtime高32位
    // ) ) )
        io.axi.rdata := RegNext( MuxCase(0.U, Seq(
            !io.axi.arvalid                         -> 0.U,           // 保护条件：地址无效时返回0
            (io.axi.araddr(2) === 0.U) -> mtime(31, 0),  // mtime低32位
            (io.axi.araddr(2) === 1.U) -> mtime(63, 32)   // mtime高32位
    ) ) )

    //when (io.axi.arvalid){printf("[CLINK]io.axi.araddr =0x%x ", io.axi.araddr)}
    //when (io.axi.rvalid){printf("[CLINK]io.axi.rdata =0x%x\n", io.axi.rdata)}

    io.axi.rid := 0.U
    io.axi.rlast := io.axi.rvalid
    //CLINT不使用的写通道设定默认响应
    io.axi.awready := false.B 
    io.axi.wready := false.B
    io.axi.bvalid := false.B
    io.axi.bresp := 0.U
    io.axi.bid := 0.U
     
}

class AXI4_Bundle (val addrWidth: Int = 32, val dataWidth: Int = 32) extends Bundle {
  // 写地址通道  
  val awready  = Input(Bool())
  val awvalid  = Output(Bool())
  val awaddr   = Output(UInt(addrWidth.W))
  val awid     = Output(UInt(4.W))
  val awlen    = Output(UInt(8.W))
  val awsize   = Output(UInt(3.W))
  val awburst  = Output(UInt(2.W))
  
  // 写数据通道  
  val wready   = Input(Bool())
  val wvalid   = Output(Bool())
  val wdata    = Output(UInt(dataWidth.W))
  val wstrb    = Output(UInt(4.W)) 
  val wlast    = Output(Bool())
  
  // 写响应通道 
  val bready   = Output(Bool())
  val bvalid   = Input(Bool())
  val bresp    = Input(UInt(2.W))
  val bid      = Input(UInt(4.W))
  
  // 读地址通道  
  val arready  = Input(Bool())
  val arvalid  = Output(Bool())
  val araddr   = Output(UInt(addrWidth.W))
  val arid     = Output(UInt(4.W))
  val arlen    = Output(UInt(8.W))
  val arsize   = Output(UInt(3.W))
  val arburst  = Output(UInt(2.W))
  
  // 读数据通道  
  val rready   = Output(Bool())
  val rvalid   = Input(Bool())
  val rresp    = Input(UInt(2.W))
  val rdata    = Input(UInt(dataWidth.W))
  val rlast    = Input(Bool())
  val rid      = Input(UInt(4.W))
}


//itrace && IFU取到指令的性能计数器
class npc_cloud_itrace extends BlackBox with HasBlackBoxResource {
    val io = IO(new Bundle{
        val clk = Input(Clock())  
        val rst = Input(Bool())  
        val rvalid = Input(Bool())
        val arvalid = Input(Bool())  
        val valid = Input(Bool())     
        val pc = Input(UInt(32.W))  
        val inst = Input(UInt(32.W))  
    } )
    
    addResource("/npc_cloud_DPI_C.v")
    override def desiredName = "ysyx_25080222_itrace"
}

//访问寄存器trace
class npc_cloud_reg_trace (ADDR_WIDTH: Int = 5, DATA_WIDTH: Int = 32) extends BlackBox with HasBlackBoxResource {
    val io = IO(new Bundle{
        val clk = Input(Clock())  
        //val rst = Input(Bool())   
        val valid = Input(Bool())
        val wen = Input(Bool())   
        val wdata = Input(UInt(DATA_WIDTH.W))
        val waddr = Input(UInt(ADDR_WIDTH.W))
    } )
    
    addResource("/npc_cloud_DPI_C.v")
    override def desiredName = "ysyx_25080222_reg_trace"
}

//IFU取到指令的性能计数器
// class npc_cloud_ifu_count extends BlackBox with HasBlackBoxResource {
//     val io = IO(new Bundle{
//         val clk = Input(Clock())  
//         val valid = Input(Bool())
//         val ar = Input(Bool())
//         val addr = Input(UInt(32.W))
//     } )
    
//     addResource("/npc_cloud_DPI_C.v")
//     override def desiredName = "ysyx_25080222_ifu_count"
// }

//icache的性能计数器
class npc_cloud_icache_count extends BlackBox with HasBlackBoxResource {
    val io = IO(new Bundle{
        val clk = Input(Clock())  
        val arvalid = Input(Bool())
        val addr = Input(UInt(32.W)) 
        val check = Input(Bool())
        val sdram = Input(Bool())
    } )
    
    addResource("/npc_cloud_DPI_C.v")
    override def desiredName = "ysyx_25080222_icache_count"
}

//LSU取到指令的性能计数器
class npc_cloud_lsu_count extends BlackBox with HasBlackBoxResource {
    val io = IO(new Bundle{
        val clk = Input(Clock())  
        val rvalid = Input(Bool())
        val ren = Input(Bool())
        val bvalid = Input(Bool())
        val wen = Input(Bool())
    } )
    
    addResource("/npc_cloud_DPI_C.v")
    override def desiredName = "ysyx_25080222_lsu_count"
}

//EXU取到指令的性能计数器
class npc_cloud_instruction_count extends BlackBox with HasBlackBoxResource {
    val io = IO(new Bundle{
        val clk = Input(Clock())  
        val alu_valid = Input(Bool())
        val csr_valid = Input(Bool())

    } )
    
    addResource("/npc_cloud_DPI_C.v")
    override def desiredName = "ysyx_25080222_instruction_count"
}

