package npc_cloud

import chisel3._
import chisel3.util._
// IFU(Instruction Fetch Unit): 负责从存储器中取指, 生成下一条指令地址, 并将指令传递给译码单元

class ysyx_25080222_pc extends BlackBox with HasBlackBoxInline {
  val io = IO(new Bundle {
    val pc_init = Output(UInt(32.W))
  })
  
    setInline("ysyx_25080222_pc.v",
        s"""
        |module ysyx_25080222_pc(
        |  output reg [31:0] pc_init
        |);
        |`ifdef PC_INIT
        |  initial pc_init = `PC_INIT;
        |`else
        |  initial pc_init = 32'h30000000;
        |`endif
        |endmodule
        |""".stripMargin)
}

//class npc_cloud_ifu(pc_init: String = "h80000000")  extends Module {
class npc_cloud_ifu extends Module {
    val io = IO(new Bundle {
        //val out = DecoupledIO(UInt(32.W))
        val out = DecoupledIO(new IFU_TO_IDU_Bundle)  // 输出到IDU

        //val pc = Output(UInt(32.W))
        val exu_dnpc = Input(UInt(32.W))
        val exu_en_dnpc = Input(Bool())
        val idu_en_dnpc = Input(Bool())
        val exu_fence_i = Input(Bool())
        val idu_fence_i = Input(Bool())
        val ebreak = Input(Bool())
        
        val valid = Input(Bool())
        val axi = new AXI4_Bundle()  // 默认方向：主设备
    })

    val start = RegInit(2.U(2.W))
    start := Mux(start =/= 0.U, start - 1.U, start)
    dontTouch(start)

    val PCInit = Module(new ysyx_25080222_pc)
    val pc = RegInit(PCInit.io.pc_init) // pc寄存器初始化定义
    //pc := Mux(io.valid, io.exu_dnpc , pc)
    pc := MuxCase(pc, Seq(
        (io.out.valid && io.out.ready && io.exu_en_dnpc) -> (io.exu_dnpc + 4.U),
        (io.out.valid && io.out.ready && !io.exu_en_dnpc) -> (pc + 4.U),
         io.exu_en_dnpc -> io.exu_dnpc
            ) )
    io.out.bits.pc := Mux(!io.exu_en_dnpc, pc, io.exu_dnpc)
    //io.out.bits.pc := Mux(start =/= 0.U, pc, Mux(!io.exu_en_dnpc, pc, io.exu_dnpc) ) 

    //ifu状态机
    val s_idle :: s_wait_mem_ready :: s_wait_mem :: s_wait_ready :: Nil = Enum(4)
    val state = RegInit(s_idle)
        state := MuxLookup(state, s_idle, List(
        s_idle              -> MuxCase(s_idle, Seq(
                            (io.axi.arvalid && !io.axi.rvalid) -> s_wait_mem ,
                          (io.axi.arvalid && io.axi.rvalid && !io.out.ready)   -> s_wait_ready
                            ) ),
        s_wait_mem          -> Mux(io.out.valid && io.out.ready, s_idle, Mux(io.out.valid, s_wait_ready, s_wait_mem)),
        s_wait_ready        -> Mux(io.out.ready, s_idle, s_wait_ready)
    ))
    io.out.valid := io.axi.rvalid || (state === s_wait_ready) //读取有效指令后传输数据
    //io.out.valid := io.axi.rvalid
    val inst = RegInit(0.U(32.W))
    inst := Mux(io.axi.rvalid, io.axi.rdata, inst) 
    io.out.bits.inst := Mux(io.axi.rvalid, io.axi.rdata, inst) 

    //IFU访问接口用AXI4进行封装
    //val ren =  (state === s_idle) && (io.exu_en_dnpc || (RegNext(io.out.valid && io.out.ready, true.B) && (!io.ebreak && !io.idu_en_dnpc))  )
    /*跳转指令和fence.i指令在译码阶段不取指，到执行阶段再取指*/
    //val ren = WireInit(true.B)
    val ren =  (state === s_idle) && ((io.exu_en_dnpc || io.exu_fence_i) || (RegNext(io.out.valid && io.out.ready, true.B) && (!io.ebreak && !io.idu_en_dnpc && !io.idu_fence_i))  )



    io.axi.arvalid := Mux(start =/= 0.U, start(0), ren) && !reset.asBool
    //io.axi.arvalid := Mux(RegNext(reset.asBool), RegNext(true.B,false.B), ren)
    //io.axi.araddr := io.out.bits.pc
    io.axi.araddr := Mux(start =/= 0.U, pc, io.out.bits.pc)
    io.axi.rready := true.B 
    io.axi.arid := 0.U
    io.axi.arsize := "b010".U  // 4字节传输 (2^2 = 4)
    io.axi.arburst :="b01".U  // INCR模式   
    io.axi.arlen := 0.U   // 突发长度为1,单次传输
    io.axi.awvalid := false.B   //IFU不使用的写通道设定默认值
    io.axi.awaddr := 0.U
    io.axi.wvalid := false.B
    io.axi.wdata := 0.U
    io.axi.wstrb := 0.U
    io.axi.bready := false.B
    io.axi.awid := 0.U
    io.axi.awsize := 0.U
    io.axi.awlen := 0.U
    io.axi.awburst := "b00".U
    io.axi.wlast := false.B
    io.axi.bready := false.B
    

    val itrace = Module(new npc_cloud_itrace())
    itrace.io.clk := clock 
    itrace.io.rst := reset.asBool    
    itrace.io.arvalid := io.axi.arvalid
    itrace.io.rvalid := io.axi.rvalid
    itrace.io.valid := io.valid
    itrace.io.pc :=  io.out.bits.pc
    itrace.io.inst := io.out.bits.inst   


    
    //when(io.axi.arvalid || io.out.valid){
        // printf("[IFU]in.valid=%d  ren=%d      out.ready=%d out.valid=%d pc=0x%x state=%d inst=0x%x ", 
        //         io.valid, ren,  io.out.ready, io.out.valid, io.out.bits.pc, state, io.out.bits.inst)
        // printf("idu_en_dnpc=%d exu_en_dnpc=%d dnpc=0x%x\n", 
        //         io.idu_en_dnpc, io.exu_en_dnpc,  io.exu_dnpc)
    //}
}


class IFU_TO_IDU_Bundle extends Bundle {
    val pc = Output(UInt(32.W))
    val inst = Output(UInt(32.W))
}



class npc_cloud_icache extends Module {
    val io = IO(new Bundle {
        val in = Flipped(new AXI4_Bundle())  // 方向反转：从设备(ifu到icache)
        val out = new AXI4_Bundle()  // 默认方向：主设备(icache到Arbiter)
        val fence_i  = Input(Bool()) 
    })

    //SRAM的访问延迟本身就只有1周期, 因此也无需缓存, 将缓存块留给其他的地址空间
    val access_sram = ((io.in.araddr >= 0x0f000000.U) && (io.in.araddr <= 0x0f002000.U)).asBool

     // 计算组索引和标签
    val SETS = 2
    val WAYS = 1
    val CACHE_LINE_SIZE = 4   // 每个cache line存放4条指令
    val LINE_SIZE = 2   // log2(CACHE_LINE_SIZE)
    val INDEX_BITS = 1  // log2(SETS)

    val offset_buf = RegInit(0.U(2.W))
    offset_buf := MuxCase(offset_buf, Seq(
                             // (io.in.arvalid && !access_sram)  -> io.in.araddr ,
                            (io.out.rvalid && !io.out.rlast) -> (offset_buf + 1.U),
                            (io.out.rvalid && io.out.rlast)  -> 0.U
                            ) )

    val set = ( io.in.araddr(LINE_SIZE + 2) )

    val tag = io.in.araddr(31, 2 + LINE_SIZE + INDEX_BITS)
    val offset = ( io.in.araddr >> 2 )(LINE_SIZE-1,0)
    
    val icache_reg= RegInit(VecInit(Seq.fill(SETS)(
                            VecInit(Seq.fill(CACHE_LINE_SIZE)(0.U(32.W)))
                            )) )
    val tag_reg = RegInit(VecInit(Seq.fill(SETS)(
                            0.U( (32 - 2 - LINE_SIZE -INDEX_BITS).W))))
    val valid_reg = RegInit(VecInit(Seq.fill(SETS)(
                            false.B)))
    
    //判断set对应cache块的tag与请求地址的tag是否相同, 并检查该cache块是否有效
    val hit = ( valid_reg(set) && (tag_reg(set) === tag) ) && io.in.arvalid

    //cache状态机
    val s_idle :: s_check :: s_wait_ready :: s_wait_mem :: Nil = Enum(4)
    val state = RegInit(s_idle)
    state := MuxLookup(state, s_idle, List(
        s_idle          ->  MuxCase(s_idle, Seq(
                                    //(io.in.arvalid && !access_sram) -> s_check,   //LSU有请求(IFU有请求)：切换
                 (io.in.arvalid && ( access_sram || !hit ) && !io.out.arready)  -> s_wait_ready,
                  (io.in.arvalid && ( access_sram || !hit ) && io.out.arready)  -> s_wait_mem
                            ) ),
        //s_check         ->  Mux(hit, s_idle,  Mux(io.out.arready, s_wait_mem, s_wait_ready)),   
        s_wait_ready    ->  Mux(io.out.arready, s_wait_mem, s_wait_ready), 
        s_wait_mem      ->  Mux( (io.out.rvalid && io.out.rlast), s_idle, s_wait_mem) 
    )   )


    icache_reg(set)(offset_buf) := Mux( (io.out.rvalid && (state === s_wait_mem) && !access_sram), io.out.rdata, icache_reg(set)(offset_buf)  )
    
    tag_reg(set) := Mux( (io.out.rvalid && io.out.rlast && (state === s_wait_mem) && !access_sram), tag, tag_reg(set) )
    
    // valid_reg(set) := MuxCase(valid_reg(set), Seq(
    //                                  io.fence_i ->   (false.B) ,//fence.i指令所有缓存无效
    //     (io.out.rvalid && io.out.rlast && (state === s_wait_mem) && !access_sram) -> true.B
    //                         ) )
    // valid_reg(!set) := Mux( io.fence_i, false.B, valid_reg(!set) )
    valid_reg(set) := Mux( (io.out.rvalid && io.out.rlast && (state === s_wait_mem) && !access_sram), true.B ,valid_reg(set) )
    when(io.fence_i){
        valid_reg(0) := false.B
        valid_reg(1) := false.B
    }

    //输出到仲裁器，在内存中读出请求所在的数据块
    io.out.araddr := MuxCase(Cat(io.in.araddr(31,4), 0.U(4.W)), Seq(
                                     (access_sram) -> io.in.araddr
                            ) )
    io.out.arvalid :=  MuxCase(false.B, Seq(
            ( (state === s_idle) && hit  )  -> false.B,
                   (state === s_wait_ready) -> true.B,
                              (access_sram) -> io.in.arvalid,
                         (state === s_idle) -> io.in.arvalid
                            ) )
    io.out.rready := io.in.rready
    io.out.arid := io.in.arid
    io.out.arsize := io.in.arsize
    io.out.arburst := io.in.arburst 
    io.out.arlen := Mux((access_sram), io.in.arlen , 3.U  )
    //ifu读通道返回
    io.in.rdata := MuxCase(0.U, Seq(
            (io.out.rvalid && io.out.rlast && access_sram ) -> io.out.rdata, //直接访问SRAM
                           ( (state === s_idle) && hit)  -> icache_reg(set)(offset), //命中缓存
    (io.out.rvalid && io.out.rlast && (state === s_wait_mem) &&  (offset === 3.U) ) -> io.out.rdata, 
    (io.out.rvalid && io.out.rlast && (state === s_wait_mem) &&  (offset =/= 3.U) ) -> icache_reg(set)(offset) 
                                ) )
    io.in.rvalid :=  MuxCase(false.B, Seq(
            (io.out.rvalid && io.out.rlast) -> true.B,
             ( (state === s_idle) && hit  )  -> true.B
                                ) )
    io.in.rresp := MuxCase(0.U, Seq(
            (io.out.rvalid && io.out.rlast) -> io.out.rresp,
             ( (state === s_idle) && hit)  -> 0.U
                                ) )
    io.in.arready := true.B
    io.in.rlast := Mux( ( (state === s_idle) && hit), true.B, io.out.rlast)
    io.in.rid := MuxCase(0.U, Seq(
            (io.out.rvalid && io.out.rlast) -> io.out.rid,
             ( (state === s_idle) && hit)  -> 0.U
                                ) )  
    
    io.out.awvalid := io.in.awvalid   //icache不使用的写通道设定默认值,输出到仲裁器
    io.out.awaddr := io.in.awaddr
    io.out.wvalid := io.in.wvalid
    io.out.wdata := io.in.wdata
    io.out.wstrb := io.in.wstrb
    io.out.bready := io.in.bready
    io.out.awid := io.in.awid
    io.out.awsize := io.in.awsize
    io.out.awlen := io.in.awlen
    io.out.awburst := io.in.awburst
    io.out.wlast :=  io.in.wlast
    io.out.bready :=  io.in.bready
    io.in.awready := false.B   //icache不使用的写通道设定默认响应，返回到ifu
    io.in.wready := false.B
    io.in.bvalid := false.B
    io.in.bresp := 0.U
    io.in.bid := 0.U

    val icache_count = Module(new npc_cloud_icache_count())
    icache_count.io.clk := clock  
    icache_count.io.arvalid := io.in.arvalid && !access_sram
    icache_count.io.addr := io.in.araddr
    icache_count.io.check := ( (state === s_idle) && hit)
    icache_count.io.sdram := ( (state === s_wait_mem) && io.out.rvalid && io.out.rlast)

}
