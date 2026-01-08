package npc_cloud

import chisel3._
import chisel3.util._
import chisel3.experimental._ //BlackBox 机制
import chisel3.experimental.{IntParam, BaseModule}
//EXU(EXecution Unit): 负责根据控制信号对数据进行执行操作, 并将执行结果写回寄存器或存储器
class npc_cloud_exu extends Module {
    val io = IO(new Bundle {
        val in = Flipped(DecoupledIO(new IDU_TO_EXU_Bundle) ) 
        val out = DecoupledIO(new EXU_TO_LSU_Bundle)  // 输出到LSU
        
        val dnpc = Output(UInt(32.W))
        val forward = Output(Bool())
    } )

  


    //exu状态机
    val s_idle :: s_wait_ready :: Nil = Enum(2)
    val state = RegInit(s_idle)
        state := MuxLookup(state, s_idle, List(
        s_idle       -> Mux( (io.out.valid && !io.out.ready), s_wait_ready, s_idle),  //指令全部结束，更新pc时候(初始)有效
        s_wait_ready -> Mux(io.out.ready, s_idle, s_wait_ready)
    ))

    io.in.ready := io.out.ready && (state === s_idle)      
    io.out.valid := io.in.valid || (state === s_wait_ready)

    io.out.bits.pc := io.in.bits.pc

    io.out.bits.lw := io.in.bits.lw
    io.out.bits.lh := io.in.bits.lh
    io.out.bits.lb := io.in.bits.lb
    io.out.bits.lhu := io.in.bits.lhu
    io.out.bits.lbu := io.in.bits.lbu
    io.out.bits.sw := io.in.bits.sw
    io.out.bits.sh := io.in.bits.sh
    io.out.bits.sb := io.in.bits.sb

    val ren = io.in.bits.lw || io.in.bits.lb || io.in.bits.lbu || io.in.bits.lh || io.in.bits.lhu
    val wen = io.in.bits.sw || io.in.bits.sh || io.in.bits.sb  
    io.out.bits.ren := ren
    io.out.bits.wen := wen
    io.out.bits.addr := io.in.bits.rs1_data + io.in.bits.imm //访存地址恒为：rs1_data + imm
    io.out.bits.wdata := (io.in.bits.rs2_data << (io.out.bits.addr(1, 0) << 3.U) )(31,0)//根据地址的低2位对数据进行左移

    //译码出各种类别的指令
    val instruction_count = Module(new npc_cloud_instruction_count())
    instruction_count.io.clk := clock  
    instruction_count.io.alu_valid := io.out.valid && io.out.ready && ( (io.in.bits.en_riscv && !wen && !ren && !io.out.bits.wen_csr) || io.in.bits.ecall )
    instruction_count.io.csr_valid := io.out.valid && io.out.bits.wen_csr && !io.in.bits.ecall 

    //when(io.out.valid || io.in.valid){
        // printf("[EXU]in.ready=%d in.valid=%d out.ready=%d out.valid=%d state=%d ", 
        //     io.in.ready, io.in.valid, io.out.ready, io.out.valid, state)
        // printf("pc=0x%x rs1_data=0x%x rs2_data=0x%x rd_wdata=0x%x en_dnpc=%d dnpc=0x%x rd=%d\n", 
        //     io.in.bits.pc, io.in.bits.rs1_data, io.in.bits.rs2_data, io.out.bits.rd_wdata, io.in.bits.en_dnpc, io.dnpc, io.in.bits.rd)
    //}


    //指令执行模块调用
    //I-type
    val ecall = Module(new npc_cloud_exu_ecall())
    ecall.io.is := io.in.bits.ecall  //连接模块输入信号
    ecall.io.pc := io.in.bits.pc 
    ecall.io.csr_rdata := io.in.bits.csr_rdata 

    val csrrw = Module(new npc_cloud_exu_csrrw())
    csrrw.io.is := io.in.bits.csrrw  //连接模块输入信号
    csrrw.io.rs1_data := io.in.bits.rs1_data 
    csrrw.io.csr_rdata := io.in.bits.csr_rdata 

    val csrrs = Module(new npc_cloud_exu_csrrs())
    csrrs.io.is := io.in.bits.csrrs  //连接模块输入信号
    csrrs.io.rs1_data := io.in.bits.rs1_data 
    csrrs.io.csr_rdata := io.in.bits.csr_rdata 

    val addi = Module(new npc_cloud_exu_addi())
    addi.io.is := io.in.bits.addi  //连接模块输入信号
    addi.io.rs1_data := io.in.bits.rs1_data 
    addi.io.imm := io.in.bits.imm

    val jalr = Module(new npc_cloud_exu_jalr())
    jalr.io.is := io.in.bits.jalr //连接模块输入信号
    jalr.io.pc :=io.in.bits.pc  
    jalr.io.rs1_data := io.in.bits.rs1_data  
    jalr.io.imm := io.in.bits.imm

    val slti = Module(new npc_cloud_exu_slti())
    slti.io.is := io.in.bits.slti //连接模块输入信号
    slti.io.rs1_data := io.in.bits.rs1_data  
    slti.io.imm := io.in.bits.imm

    val sltiu = Module(new npc_cloud_exu_sltiu())
    sltiu.io.is := io.in.bits.sltiu //连接模块输入信号
    sltiu.io.rs1_data := io.in.bits.rs1_data  
    sltiu.io.imm := io.in.bits.imm

    val xori = Module(new npc_cloud_exu_xori())
    xori.io.is := io.in.bits.xori  //连接模块输入信号
    xori.io.rs1_data := io.in.bits.rs1_data 
    xori.io.imm := io.in.bits.imm

    val andi = Module(new npc_cloud_exu_andi())
    andi.io.is := io.in.bits.andi  //连接模块输入信号
    andi.io.rs1_data := io.in.bits.rs1_data 
    andi.io.imm := io.in.bits.imm

    val srai = Module(new npc_cloud_exu_srai())
    srai.io.is := io.in.bits.srai  //连接模块输入信号
    srai.io.rs1_data := io.in.bits.rs1_data 
    srai.io.shamt := io.in.bits.shamt

    val srli = Module(new npc_cloud_exu_srli())
    srli.io.is := io.in.bits.srli  //连接模块输入信号
    srli.io.rs1_data := io.in.bits.rs1_data 
    srli.io.shamt := io.in.bits.shamt

    val slli = Module(new npc_cloud_exu_slli())
    slli.io.is := io.in.bits.slli  //连接模块输入信号
    slli.io.rs1_data := io.in.bits.rs1_data 
    slli.io.shamt := io.in.bits.shamt

    val ori = Module(new npc_cloud_exu_ori())
    ori.io.is := io.in.bits.ori  //连接模块输入信号
    ori.io.rs1_data := io.in.bits.rs1_data 
    ori.io.imm := io.in.bits.imm

    //J-type
    val jal = Module(new npc_cloud_exu_jal())
    jal.io.is := io.in.bits.jal //连接模块输入信号
    jal.io.pc :=io.in.bits.pc  
    jal.io.imm := io.in.bits.imm


    //B-type
    val beq = Module(new npc_cloud_exu_beq())
    beq.io.is := io.in.bits.beq //连接模块输入信号
    beq.io.rs1_data := io.in.bits.rs1_data
    beq.io.rs2_data := io.in.bits.rs2_data
    beq.io.pc :=io.in.bits.pc
    beq.io.imm := io.in.bits.imm

    val bne = Module(new npc_cloud_exu_bne())
    bne.io.is := io.in.bits.bne //连接模块输入信号
    bne.io.rs1_data := io.in.bits.rs1_data
    bne.io.rs2_data := io.in.bits.rs2_data
    bne.io.pc :=io.in.bits.pc
    bne.io.imm := io.in.bits.imm

    val bge = Module(new npc_cloud_exu_bge())
    bge.io.is := io.in.bits.bge //连接模块输入信号
    bge.io.rs1_data := io.in.bits.rs1_data
    bge.io.rs2_data := io.in.bits.rs2_data
    bge.io.pc :=io.in.bits.pc
    bge.io.imm := io.in.bits.imm

    val bgeu = Module(new npc_cloud_exu_bgeu())
    bgeu.io.is := io.in.bits.bgeu //连接模块输入信号
    bgeu.io.rs1_data := io.in.bits.rs1_data
    bgeu.io.rs2_data := io.in.bits.rs2_data
    bgeu.io.pc :=io.in.bits.pc
    bgeu.io.imm := io.in.bits.imm

    val blt = Module(new npc_cloud_exu_blt())
    blt.io.is := io.in.bits.blt //连接模块输入信号
    blt.io.rs1_data := io.in.bits.rs1_data
    blt.io.rs2_data := io.in.bits.rs2_data
    blt.io.pc :=io.in.bits.pc
    blt.io.imm := io.in.bits.imm

    val bltu = Module(new npc_cloud_exu_bltu())
    bltu.io.is := io.in.bits.bltu //连接模块输入信号
    bltu.io.rs1_data := io.in.bits.rs1_data
    bltu.io.rs2_data := io.in.bits.rs2_data
    bltu.io.pc :=io.in.bits.pc
    bltu.io.imm := io.in.bits.imm


    //R-type
    val mret = Module(new npc_cloud_exu_mret())
    mret.io.is := io.in.bits.mret //连接模块输入信号
    mret.io.csr_rdata := io.in.bits.csr_rdata
    mret.io.pc :=io.in.bits.pc  

    val add = Module(new npc_cloud_exu_add())
    add.io.is := io.in.bits.add //连接模块输入信号
    add.io.rs1_data := io.in.bits.rs1_data
    add.io.rs2_data := io.in.bits.rs2_data

    val sltu = Module(new npc_cloud_exu_sltu())
    sltu.io.is := io.in.bits.sltu //连接模块输入信号
    sltu.io.rs1_data := io.in.bits.rs1_data
    sltu.io.rs2_data := io.in.bits.rs2_data

    val slt = Module(new npc_cloud_exu_slt())
    slt.io.is := io.in.bits.slt //连接模块输入信号
    slt.io.rs1_data := io.in.bits.rs1_data
    slt.io.rs2_data := io.in.bits.rs2_data

    val xor = Module(new npc_cloud_exu_xor())
    xor.io.is := io.in.bits.xor //连接模块输入信号
    xor.io.rs1_data := io.in.bits.rs1_data
    xor.io.rs2_data := io.in.bits.rs2_data

    val and = Module(new npc_cloud_exu_and())
    and.io.is := io.in.bits.and //连接模块输入信号
    and.io.rs1_data := io.in.bits.rs1_data
    and.io.rs2_data := io.in.bits.rs2_data

    val sra = Module(new npc_cloud_exu_sra())
    sra.io.is := io.in.bits.sra //连接模块输入信号
    sra.io.rs1_data := io.in.bits.rs1_data
    sra.io.rs2_data := io.in.bits.rs2_data(4,0)

    val or = Module(new npc_cloud_exu_or())
    or.io.is := io.in.bits.or //连接模块输入信号
    or.io.rs1_data := io.in.bits.rs1_data
    or.io.rs2_data := io.in.bits.rs2_data

    val srl = Module(new npc_cloud_exu_srl())
    srl.io.is := io.in.bits.srl //连接模块输入信号
    srl.io.rs1_data := io.in.bits.rs1_data
    srl.io.rs2_data := io.in.bits.rs2_data(4,0)

    val sll = Module(new npc_cloud_exu_sll())
    sll.io.is := io.in.bits.sll //连接模块输入信号
    sll.io.rs1_data := io.in.bits.rs1_data
    sll.io.rs2_data := io.in.bits.rs2_data(4,0)

    val sub = Module(new npc_cloud_exu_sub())
    sub.io.is := io.in.bits.sub //连接模块输入信号
    sub.io.rs1_data := io.in.bits.rs1_data
    sub.io.rs2_data := io.in.bits.rs2_data



    //U-type
    val auipc = Module(new npc_cloud_exu_auipc())
    auipc.io.is := io.in.bits.auipc //连接模块输入信号
    auipc.io.imm := io.in.bits.imm
    auipc.io.pc :=io.in.bits.pc  
    
    val lui = Module(new npc_cloud_exu_lui())
    lui.io.is := io.in.bits.lui //连接模块输入信号
    lui.io.imm := io.in.bits.imm
    lui.io.pc :=io.in.bits.pc  

    io.out.bits.wen_rd := io.in.bits.wen_rd
    io.out.bits.rd := io.in.bits.rd
    io.out.bits.wen_csr := io.in.bits.wen_csr
    io.out.bits.csr_waddr := io.in.bits.csr_waddr
    io.out.bits.ebreak := io.in.bits.ebreak
    io.out.bits.ecall := io.in.bits.ecall

                                        

    io.out.bits.rd_wdata :=  MuxCase(0.U, Seq(
                io.in.bits.csrrw    ->  csrrw.io.rd ,   // I-type
                io.in.bits.csrrs    ->  csrrs.io.rd ,
                io.in.bits.addi     ->  addi.io.rd  ,   
                io.in.bits.slti     ->  slti.io.rd  ,  
                io.in.bits.sltiu    ->  sltiu.io.rd ,      
                io.in.bits.xori     ->  xori.io.rd  ,  
                io.in.bits.andi     ->  andi.io.rd  ,
                io.in.bits.srai     ->  srai.io.rd  ,
                io.in.bits.ori      ->  ori.io.rd   , 
                io.in.bits.srli     ->  srli.io.rd  ,
                io.in.bits.slli     ->  slli.io.rd  ,
                ren                 ->  0.U      ,    //读取内存指令(I-type: lw,lb,lbu,lh,lhu)
                io.in.bits.jalr     ->  jalr.io.rd  ,   
                io.in.bits.jal      ->  jal.io.rd   ,    // J-type
                io.in.bits.add      ->  add.io.rd   ,    // R-type
                io.in.bits.sltu     ->  sltu.io.rd  , 
                io.in.bits.slt      ->  slt.io.rd   , 
                io.in.bits.sll      ->  sll.io.rd   ,
                io.in.bits.xor      ->  xor.io.rd   , 
                io.in.bits.and      ->  and.io.rd   ,
                io.in.bits.sra      ->  sra.io.rd   ,
                io.in.bits.or       ->  or.io.rd    ,
                io.in.bits.srl      ->  srl.io.rd   , 
                io.in.bits.sub      ->  sub.io.rd   , 
                io.in.bits.auipc    ->  auipc.io.rd ,    // U-type
                io.in.bits.lui      ->  lui.io.rd   ) )  

    io.out.bits.csr_wdata :=  MuxCase(0.U, Seq(
                io.in.bits.ecall    ->  ecall.io.csr_wdata  ,      //I-type
                io.in.bits.csrrw    ->  csrrw.io.csr_wdata  , 
                io.in.bits.csrrs    ->  csrrs.io.csr_wdata  ) )  

    val snpc =io.in.bits.pc + 4.U

    io.dnpc :=  MuxCase(0.U, Seq(
                io.in.bits.jalr      ->  jalr.io.dnpc ,            //I-type
                io.in.bits.ecall     ->  ecall.io.dnpc,
                io.in.bits.jal       ->  jal.io.dnpc  ,            //J-type
                io.in.bits.beq       ->  beq.io.dnpc  ,            //B-type
                io.in.bits.bne       ->  bne.io.dnpc  , 
                io.in.bits.bge       ->  bge.io.dnpc  , 
                io.in.bits.bgeu      ->  bgeu.io.dnpc , 
                io.in.bits.blt       ->  blt.io.dnpc  , 
                io.in.bits.bltu      ->  bltu.io.dnpc , 
                io.in.bits.mret      ->  mret.io.dnpc , 
                !io.in.bits.en_dnpc ->  snpc         ) )         // 默认值静态pc    
    
    io.forward := io.in.bits.wen_rd && !ren


}


class EXU_TO_LSU_Bundle extends Bundle {
    val pc = Output(UInt(32.W))

    val rd = Output(UInt(5.W))
    val wen_rd = Output(Bool()) 
    val rd_wdata = Output(UInt(32.W))
    val csr_waddr = Output(UInt(5.W))
    val wen_csr = Output(Bool()) 
    val csr_wdata = Output(UInt(32.W))

    val ren = Output(Bool())      
    val wen = Output(Bool())      
    val addr = Output(UInt(32.W))
    val wdata = Output(UInt(32.W))
    
    val ebreak = Output(Bool()) 
    val ecall = Output(Bool())   

    val lw = Output(Bool())      //load指令
    val lb = Output(Bool())
    val lbu = Output(Bool())
    val lh = Output(Bool())
    val lhu = Output(Bool())

    val sw = Output(Bool())       //store指令
    val sh = Output(Bool())
    val sb = Output(Bool())

}


