package npc_cloud

import chisel3._
import chisel3.util._
//IDU(Instruction Decode Unit): 负责对当前指令进行译码, 准备执行阶段需要使用的数据和控制信号
class npc_cloud_idu extends Module {
    val io = IO(new Bundle {
        //val in = Flipped(DecoupledIO(UInt(32.W)))
        val in = Flipped(DecoupledIO(new IFU_TO_IDU_Bundle) )
        val out = DecoupledIO(new IDU_TO_EXU_Bundle)  // 输出到EXU
        //val valid = Input(Bool()) //指令运行结束
        //译码结果
        val rs2 = Output(UInt(5.W))
        val rs2_data = Input(UInt(32.W))
        val rs1 = Output(UInt(5.W))
        val rs1_data = Input(UInt(32.W))
        val raw = Input(Bool())  //写后读(Read After Write, RAW)冒险
        val forward_rs1 = Input(Bool())
        val forward_rs2 = Input(Bool())
        val forward_rs1_data = Input(UInt(32.W))
        val forward_rs2_data = Input(UInt(32.W))

        val csr_raddr = Output(UInt(5.W))
        val csr_rdata = Input(UInt(32.W))
    } )

    //idu状态机
    val s_idle :: s_wait_ready :: Nil = Enum(2)
    val state = RegInit(s_idle)
        state := MuxLookup(state, s_idle, List(
        s_idle       -> Mux( (io.out.valid && !io.out.ready), s_wait_ready, s_idle),  //指令全部结束，更新pc时候(初始)有效
        s_wait_ready -> Mux(io.out.ready, s_idle, s_wait_ready)
    ))

    //idu接口信号
    io.in.ready := io.out.ready && (state === s_idle) && !(io.raw)
    io.out.valid := (io.in.valid ||  (state === s_wait_ready) ) && !(io.raw) || (RegNext(io.raw)  && !(io.raw) )

    //val inst =  io.in.bits.inst
   
    //io.inst := inst       //提取正在执行的指令

    val rs_reg = RegInit(true.B)
    rs_reg := Mux(io.in.valid, false.B, rs_reg)
    val rs = Mux(io.in.valid, false.B, rs_reg)


    val inst = Mux( (rs), 0x00000000.U, io.in.bits.inst )
    io.out.bits.pc := io.in.bits.pc
    io.out.bits.rs1_data := Mux( (rs_reg), io.rs1_data, Mux(io.forward_rs1, io.forward_rs1_data, io.rs1_data))
    io.out.bits.rs2_data := Mux(io.forward_rs2, io.forward_rs2_data, io.rs2_data)
    io.out.bits.csr_rdata := io.csr_rdata



    // 内部使用的指令字段
    val funct7 = inst(31, 25)
    val funct3 = inst(14, 12)
    val opcode = inst(6, 0)

    io.rs2    := inst(24, 20)
    io.rs1    := inst(19, 15)
    io.out.bits.rd     := inst(11, 7)
    io.out.bits.shamt  := inst(25, 20)

    io.out.bits.inst  := inst
    //指令判断
    //I-type
    io.out.bits.fencei:= (inst === "b00000000000000000001000000001111".U)
    io.out.bits.ebreak:= (inst === "b00000000000100000000000001110011".U)
    io.out.bits.ecall := (inst === "b00000000000000000000000001110011".U)
    io.out.bits.csrrw :=                              (funct3 === "b001".U) && (opcode === "b1110011".U)
    io.out.bits.csrrs :=                              (funct3 === "b010".U) && (opcode === "b1110011".U)
    io.out.bits.addi  :=                              (funct3 === "b000".U) && (opcode === "b0010011".U)
    io.out.bits.slti  :=                              (funct3 === "b010".U) && (opcode === "b0010011".U)
    io.out.bits.sltiu :=                              (funct3 === "b011".U) && (opcode === "b0010011".U)
    io.out.bits.jalr  :=                              (funct3 === "b000".U) && (opcode === "b1100111".U)
    io.out.bits.srai  := (inst(31,26)==="b010000".U)&&(funct3 === "b101".U) && (opcode === "b0010011".U)
    io.out.bits.andi  :=                              (funct3 === "b111".U) && (opcode === "b0010011".U)
    io.out.bits.lw    :=                              (funct3 === "b010".U) && (opcode === "b0000011".U)
    io.out.bits.lb    :=                              (funct3 === "b000".U) && (opcode === "b0000011".U)
    io.out.bits.lbu   :=                              (funct3 === "b100".U) && (opcode === "b0000011".U)
    io.out.bits.lh    :=                              (funct3 === "b001".U) && (opcode === "b0000011".U)
    io.out.bits.lhu   :=                              (funct3 === "b101".U) && (opcode === "b0000011".U)
    io.out.bits.xori  :=                              (funct3 === "b100".U) && (opcode === "b0010011".U)
    io.out.bits.srli  := (funct7 === "b0000000".U) && (funct3 === "b101".U) && (opcode === "b0010011".U)
    io.out.bits.slli  := (funct7 === "b0000000".U) && (funct3 === "b001".U) && (opcode === "b0010011".U)
    io.out.bits.ori   :=                              (funct3 === "b110".U) && (opcode === "b0010011".U)
    //J-type
    io.out.bits.jal   :=                                                       (opcode === "b1101111".U)
    //S-type
    io.out.bits.sw    :=                              (funct3 === "b010".U) && (opcode === "b0100011".U)
    io.out.bits.sh    :=                              (funct3 === "b001".U) && (opcode === "b0100011".U)
    io.out.bits.sb    :=                              (funct3 === "b000".U) && (opcode === "b0100011".U)
    //B-type
    io.out.bits.beq   :=                              (funct3 === "b000".U) && (opcode === "b1100011".U)
    io.out.bits.bne   :=                              (funct3 === "b001".U) && (opcode === "b1100011".U)
    io.out.bits.bge   :=                              (funct3 === "b101".U) && (opcode === "b1100011".U)
    io.out.bits.bgeu  :=                              (funct3 === "b111".U) && (opcode === "b1100011".U)
    io.out.bits.blt   :=                              (funct3 === "b100".U) && (opcode === "b1100011".U)
    io.out.bits.bltu  :=                              (funct3 === "b110".U) && (opcode === "b1100011".U)
    //R-type
    io.out.bits.mret  := (inst === "b00110000001000000000000001110011".U)
    io.out.bits.add   := (funct7 === "b0000000".U) && (funct3 === "b000".U) && (opcode === "b0110011".U)
    io.out.bits.sltu  := (funct7 === "b0000000".U) && (funct3 === "b011".U) && (opcode === "b0110011".U)
    io.out.bits.slt   := (funct7 === "b0000000".U) && (funct3 === "b010".U) && (opcode === "b0110011".U)
    io.out.bits.xor   := (funct7 === "b0000000".U) && (funct3 === "b100".U) && (opcode === "b0110011".U)
    io.out.bits.or    := (funct7 === "b0000000".U) && (funct3 === "b110".U) && (opcode === "b0110011".U)
    io.out.bits.sub   := (funct7 === "b0100000".U) && (funct3 === "b000".U) && (opcode === "b0110011".U)
    io.out.bits.subw  := (funct7 === "b0100000".U) && (funct3 === "b000".U) && (opcode === "b0111011".U)
    io.out.bits.and   := (funct7 === "b0000000".U) && (funct3 === "b111".U) && (opcode === "b0110011".U)
    io.out.bits.sll   := (funct7 === "b0000000".U) && (funct3 === "b001".U) && (opcode === "b0110011".U)
    io.out.bits.sra   := (funct7 === "b0100000".U) && (funct3 === "b101".U) && (opcode === "b0110011".U)
    io.out.bits.srl   := (funct7 === "b0000000".U) && (funct3 === "b101".U) && (opcode === "b0110011".U)
    //U-type
    io.out.bits.auipc :=                                                       (opcode === "b0010111".U)
    io.out.bits.lui   :=                                                       (opcode === "b0110111".U)

    // 立即数选择
    val immI = Cat(Fill(20, inst(31)), inst(31, 20))
    val immJ = Cat(Fill(12, inst(31)), inst(19, 12), inst(20), inst(30, 21), 0.U(1.W))
    val immS = Cat(Fill(20, inst(31)), inst(31, 25), inst(11, 7))
    val immB = Cat(Fill(19, inst(31)), inst(31), inst(7), inst(30, 25), inst(11, 8), 0.U(1.W))
    val immU = Cat(inst(31, 12), 0.U(12.W))
    io.out.bits.imm := MuxCase(0.U, Seq(
                (io.out.bits.csrrw | io.out.bits.csrrs | io.out.bits.addi | io.out.bits.jalr |
                 io.out.bits.sltiu | io.out.bits.slti  | io.out.bits.andi | io.out.bits.ori  |
                 io.out.bits.xori  | io.out.bits.srli  | io.out.bits.srai | io.out.bits.lw   |
                 io.out.bits.lb    | io.out.bits.lbu   | io.out.bits.lh   | io.out.bits.lhu) -> immI,
                (io.out.bits.sw | io.out.bits.sh | io.out.bits.sb)                           -> immS,
                (io.out.bits.beq | io.out.bits.bne | io.out.bits.bge | io.out.bits.bgeu |
                 io.out.bits.blt | io.out.bits.bltu)                                         -> immB,
                (io.out.bits.auipc | io.out.bits.lui)                                        -> immU,
                io.out.bits.jal                                                          -> immJ ) )

    //译码结果
    io.out.bits.wen_rd :=   io.out.bits.addi   | io.out.bits.slti | io.out.bits.slli |    //I-type
            io.out.bits.srli   | io.out.bits.ori  |io.out.bits.sltiu | io.out.bits.srai |
            io.out.bits.andi   | io.out.bits.xori |io.out.bits.jalr  | io.out.bits.lw   |
            io.out.bits.lb     | io.out.bits.lbu  | io.out.bits.lh   | io.out.bits.lhu  |
            io.out.bits.ebreak |io.out.bits.csrrw |io.out.bits.csrrs |
            io.out.bits.jal  |                                                            //J-type
            io.out.bits.add  | io.out.bits.sltu | io.out.bits.xor  | io.out.bits.or    |  //R-type
            io.out.bits.sub  | io.out.bits.and  | io.out.bits.sll  | io.out.bits.sra   |
            io.out.bits.srl  | io.out.bits.slt  |
            io.out.bits.auipc| io.out.bits.lui                                            //U-type

    io.out.bits.en_dnpc :=  io.out.bits.jalr |io.out.bits.ecall|                         //I-type
                    io.out.bits.jal  |                                                    //J-type
                    io.out.bits.beq  | io.out.bits.bne | io.out.bits.bge  |               //B-type
                    io.out.bits.bgeu | io.out.bits.blt | io.out.bits.bltu |
                    io.out.bits.mret                                                      //R-type

    io.out.bits.wen_csr :=  io.out.bits.ecall | io.out.bits.csrrw | io.out.bits.csrrs     //I-type

    io.out.bits.en_riscv :=  io.out.bits.wen_rd | io.out.bits.en_dnpc | io.out.bits.wen_csr |
                     io.out.bits.sw     | io.out.bits.sh   | io.out.bits.sb |              //S-type
                     io.out.bits.fencei

    io.csr_raddr := Mux1H ( Seq(
                                               io.out.bits.ecall   -> 3.U  ,
                                               io.out.bits.mret    -> 2.U  ,
        ( io.out.bits.wen_csr && ( io.out.bits.imm === 0x342.U ) ) -> 0.U  ,      // MCAUSE  0x342   异常原因
        ( io.out.bits.wen_csr && ( io.out.bits.imm === 0x300.U ) ) -> 1.U  ,      // MSTATUS 0x300   机器状态寄存器
        ( io.out.bits.wen_csr && ( io.out.bits.imm === 0x341.U ) ) -> 2.U  ,      // MEPC    0x341   异常程序计数器
        ( io.out.bits.wen_csr && ( io.out.bits.imm === 0x305.U ) ) -> 3.U  ,       // MTVEC   0x305   异常向量基地址
        ( io.out.bits.wen_csr && ( io.out.bits.imm(11, 0) === 0xF11.U ) ) -> 4.U  ,   // 4: mvendorid - ysyx的ASCII码, 即0x79737978
        ( io.out.bits.wen_csr && ( io.out.bits.imm(11, 0) === 0xF12.U ) ) -> 5.U      // 5: marchid - 学号数字部分
        ) )

    io.out.bits.csr_waddr := Mux1H ( Seq(
                                               io.out.bits.ecall   -> 2.U  ,
        ( io.out.bits.wen_csr && ( io.out.bits.imm === 0x342.U ) ) -> 0.U  ,      // MCAUSE  0x342   异常原因
        ( io.out.bits.wen_csr && ( io.out.bits.imm === 0x300.U ) ) -> 1.U  ,      // MSTATUS 0x300   机器状态寄存器
        ( io.out.bits.wen_csr && ( io.out.bits.imm === 0x341.U ) ) -> 2.U  ,      // MEPC    0x341   异常程序计数器
        ( io.out.bits.wen_csr && ( io.out.bits.imm === 0x305.U ) ) -> 3.U        // MTVEC   0x305   异常向量基地址
        ) )

    //when(io.out.valid || io.in.valid) {
        // printf("[IDU]in.ready=%d in.valid=%d out.ready=%d out.valid=%d state=%d ",
        //         io.in.ready, io.in.valid,   io.out.ready, io.out.valid, state)
        // printf("pc=0x%x inst=0x%x rs1:gpr[%d]=0x%x rs2:gpr[%d]=0x%x rd=%d raw=%d forward_rs1=%d, forward_rs2=%d\n",
        //         io.in.bits.pc, inst, inst(19, 15), io.out.bits.rs1_data, inst(24, 20), io.out.bits.rs2_data, io.out.bits.rd, io.raw, io.forward_rs1, io.forward_rs2)
    //}

}


class IDU_TO_EXU_Bundle extends Bundle {
     // 译码结果
    val pc = Output(UInt(32.W))
    val imm = Output(UInt(32.W))
    val shamt = Output(UInt(6.W))
    val rd = Output(UInt(5.W))
    val wen_rd = Output(Bool())
    val csr_waddr = Output(UInt(5.W))
    val wen_csr = Output(Bool())
    val en_dnpc = Output(Bool())
    val en_riscv = Output(Bool())
    val inst = Output(UInt(32.W))
    val rs1_data = Output(UInt(32.W))
    val rs2_data = Output(UInt(32.W))
    val csr_rdata = Output(UInt(32.W))

    //指令判断信号
    val fencei = Output(Bool())
    val ebreak = Output(Bool())  //I-type
    val ecall = Output(Bool())
    val csrrw = Output(Bool())
    val csrrs = Output(Bool())
    val addi = Output(Bool())
    val slti = Output(Bool())
    val sltiu = Output(Bool())
    val jalr = Output(Bool())
    val srai = Output(Bool())
    val andi = Output(Bool())
    val lw = Output(Bool())
    val lb = Output(Bool())
    val lbu = Output(Bool())
    val lh = Output(Bool())
    val lhu = Output(Bool())
    val xori = Output(Bool())
    val srli = Output(Bool())
    val slli = Output(Bool())
    val jal = Output(Bool())      //J-type
    val sw = Output(Bool())       //S-type
    val sh = Output(Bool())
    val sb = Output(Bool())
    val beq = Output(Bool())      //B-type
    val bne = Output(Bool())
    val bge = Output(Bool())
    val bgeu = Output(Bool())
    val blt = Output(Bool())
    val bltu = Output(Bool())
    val mret = Output(Bool())  //R-type
    val add = Output(Bool())
    val sltu = Output(Bool())
    val slt = Output(Bool())
    val xor = Output(Bool())
    val or = Output(Bool())
    val ori = Output(Bool())
    val sub = Output(Bool())
    val subw = Output(Bool())
    val and = Output(Bool())
    val sll = Output(Bool())
    val sra = Output(Bool())
    val srl = Output(Bool())
    val auipc = Output(Bool())     //U-type
    val lui = Output(Bool())
}