package cpu 

import chisel3._
import chisel3.util._

import A_sel._
import B_sel._
import pc_sel._
import aluop._
import imm_sel._
import br_sel._
import csr_cmd._




class ysyx_23060246_EXU(config: NPCConfig) extends Module{
    var io = IO(new Bundle{
        val in = Flipped(Decoupled(new SigIO_IDU_EXU(config.XLEN)))
        val out = (Decoupled(new SigIO_EXU_LSU(config.XLEN)))

        val pc_sig = (Valid(new SigIO_EXU_IFU(config.XLEN)))

        val rd_addr = Output(UInt(5.W))
    })
    val xlen = config.XLEN
    //val alu = Module(new ysyx_23060246_ALU(xlen))
    val alu = Module(new ysyx_23060246_ALU_AREA(xlen))
    val immGen = Module(new ysyx_23060246_ImmGen(xlen))


    val pc = io.in.bits.pc
    val inst = io.in.bits.inst
    val ctrlsig = io.in.bits.exu
    val sig_csr_cmd = io.in.bits.wbu.csr_cmd
    val wb_sel = io.in.bits.wbu.wb_sel



    val s_idle :: s_exe :: s_wait_ready :: Nil = Enum(3)

    val state = RegInit(s_idle)         
    state := MuxLookup(state, s_idle)(Seq(
        s_idle -> Mux(io.in.valid, s_exe, s_idle),
        s_exe  -> s_wait_ready, // Reserve more time for EXU
        s_wait_ready -> Mux(io.out.ready, s_idle, s_wait_ready)
    ))


    io.out.valid := state === s_wait_ready
    io.in.ready := state === s_idle


 

    // regfile
    val rd_addr = inst(11, 7)
    // val rs1_addr = inst(19, 15)
    // val rs2_addr = inst(24, 20)
    io.rd_addr := Mux(state === s_idle && RegNext(state) === s_idle, 0.U, rd_addr)

    

    val src1_reg = RegInit(0.U(xlen.W))
    val src2_reg = RegInit(0.U(xlen.W))

    
    val src1 = ctrlsig.src1
    val src2 = ctrlsig.src2
    src1_reg := src1
    src2_reg := src2

    immGen.io.inst := inst 
    immGen.io.sel := ctrlsig.imm_sel

    //val imm_out_reg = RegInit(0.U(32.W))
    //imm_out_reg := immGen.io.out 
    val alu_A_reg = RegInit(0.U(xlen.W))
    alu_A_reg := MuxLookup(ctrlsig.A_sel, 0.U(xlen.W))(Seq(
        A_RS1 -> src1,
        A_PC  -> pc
        )
    )
    alu.io.A := alu_A_reg

    val alu_B_reg = RegInit(0.U(xlen.W))
    alu_B_reg := MuxLookup(ctrlsig.B_sel, 0.U(xlen.W))(Seq(
        B_RS2 -> src2,
        B_IMM -> immGen.io.out 
        )
    )
    alu.io.B := alu_B_reg

    alu.io.aluop := ctrlsig.alu_op




    val csr = Module(new ysyx_23060246_CSR(config))
    csr.io.inst := inst
    csr.io.pc := pc
    csr.io.cmd := sig_csr_cmd
    csr.io.in := src1_reg  //目前还未用到立即数  WARNING
    csr.io.update_enable := RegNext(io.out.valid)
    dontTouch(csr.io)  //任何时候都不优化

    val branch = Module(new ysyx_23060246_Branch(xlen))
    branch.io.br_sel := ctrlsig.br_sel
    branch.io.src1 := src1
    branch.io.src2 := src2

    val branch_taken = RegInit(false.B)
    branch_taken := branch.io.taken

    val npc = MuxCase(
        pc + 4.U,  
        IndexedSeq(
        ((ctrlsig.pc_sel === PC_ALU) || (branch_taken)) -> (alu.io.out >> 1.U << 1.U),  //对齐
        (ctrlsig.pc_sel === PC_0) -> pc, 
        (ctrlsig.pc_sel === PC_CSR) -> csr.io.target_pc
        )
    )
    io.out.bits.npc := npc
    // io.npc.bits := npc 
    // io.npc.valid := state === s_exe
    io.pc_sig.bits.pc := pc
    io.pc_sig.bits.npc := npc
    io.pc_sig.valid := state === s_exe


    // // Forwarding
    // io.forward.bits := alu.io.out // TODO: csrrw
    // io.forward.valid := state === s_exe && ctrlsig.ld_sel =/= LD_XX && ctrlsig.wb_sel =/= WB_XX


    io.out.bits.csr_out  := csr.io.out
    io.out.bits.rd_addr := rd_addr
    io.out.bits.src1 := src1_reg
    io.out.bits.src2 := src2_reg 
    io.out.bits.alu_out := alu.io.out
    io.out.bits.pc := pc
    io.out.bits.inst := inst
/*
    io.out.bits.wbu <> in_reg.bits.wbu
    io.out.bits.lsu <> in_reg.bits.lsu
*/
    io.out.bits.wbu <> io.in.bits.wbu
    io.out.bits.lsu <> io.in.bits.lsu

    if(config.PERF_CNT){
        val alu_arith_cnt = RegInit(0.U(32.W))
        val alu_logic_cnt = RegInit(0.U(32.W))
        val alu_shift_cnt = RegInit(0.U(32.W))
        val alu_cmp_cnt = RegInit(0.U(32.W))
        val alu_copy_cnt = RegInit(0.U(32.W))
        val aluop = alu.io.aluop 
        when(io.out.valid && io.out.ready){
            alu_arith_cnt := alu_arith_cnt + (aluop === ALU_ADD || aluop === ALU_SUB)
            alu_logic_cnt := alu_logic_cnt + (aluop === ALU_AND || aluop === ALU_OR ||
                                            aluop === ALU_XOR)
            alu_shift_cnt := alu_shift_cnt + (aluop === ALU_SLL || aluop === ALU_SRL ||
                                            aluop === ALU_SRA)
            alu_cmp_cnt := alu_cmp_cnt + (aluop === ALU_SLT || aluop === ALU_SLTU)
            alu_copy_cnt := alu_copy_cnt + (aluop === ALU_COPY_A || aluop === ALU_COPY_B)
        }
        dontTouch(alu_arith_cnt)
        dontTouch(alu_logic_cnt)
        dontTouch(alu_shift_cnt)
        dontTouch(alu_cmp_cnt)
        dontTouch(alu_copy_cnt)
    }
}