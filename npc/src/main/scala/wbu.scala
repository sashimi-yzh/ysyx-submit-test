package  cpu


import chisel3._
import chisel3.util._

import wb_sel._




class ysyx_23060246_WBU(config: NPCConfig) extends Module {
    val io = IO(new Bundle {
        val in = Flipped(Decoupled(new SigIO_LSU_WBU(config.XLEN)))
        val out = Decoupled(new SigIO_WBU_IFU(config.XLEN))
        val reg_write = Flipped(new RegfileWriteIO(config))
        val wb_valid = Output(Bool())
        val rd_addr = Output(UInt(5.W))
        val inst_type = Output(UInt(4.W))
        val forward_wbu = Output(UInt(config.XLEN.W))
    })

    // val in_reg = Reg(Output(chiselTypeOf(io.in)))
    // when( io.in.valid && io.in.ready){
    //     in_reg := io.in
    // }
    // val pc = in_reg.bits.pc
    // val ctrlsig = in_reg.bits.wbu
    // val src1 = in_reg.bits.src1
    // val alu_out = in_reg.bits.alu_out
    // val ld_data = in_reg.bits.ld_data
    // val rd_addr = in_reg.bits.rd_addr
    // val npc = in_reg.bits.npc
    // val csr_out = in_reg.bits.csr_out

    val pc = io.in.bits.pc
    val ctrlsig = io.in.bits.wbu
    val src1 = io.in.bits.src1
    val alu_out = io.in.bits.alu_out
    val ld_data = io.in.bits.ld_data
    val rd_addr = io.in.bits.rd_addr
    val npc = io.in.bits.npc
    val csr_out = io.in.bits.csr_out

    val s_idle :: s_wait_ready :: Nil = Enum(2)

    val state = RegInit(s_idle)         
    state := MuxLookup(state, s_idle)(Seq(
        s_idle -> Mux(io.in.valid, s_wait_ready, s_idle),
        s_wait_ready -> Mux(io.out.ready, s_idle, s_wait_ready)
    ))


    io.out.valid := state === s_wait_ready
    io.in.ready := state === s_idle

    
    io.rd_addr := Mux(state === s_idle, 0.U, rd_addr)

    val valid_old = RegNext(io.out.valid)
    io.wb_valid := (!valid_old && io.out.valid)
    val wbu_valid = RegNext(!valid_old && io.out.valid)
    dontTouch(wbu_valid) // Used for simulation
    dontTouch(pc)
    dontTouch(npc)
    dontTouch(io.in.bits.inst)

    io.reg_write.addr := rd_addr
    io.reg_write.en := ctrlsig.wb_sel =/= WB_XX //&& io.out.valid; 
        
    val wb_data = MuxLookup(ctrlsig.wb_sel, 0.U(config.XLEN.W))(Seq(
        WB_ALU -> alu_out,
        WB_MEM -> ld_data,
        WB_PC4  -> (pc + 4.U),
        WB_CSR -> csr_out,
        )
    )
    io.reg_write.data := wb_data
    io.forward_wbu := wb_data

    io.out.bits.rd_addr := io.in.bits.rd_addr
    io.out.bits.npc := npc
    dontTouch(io.in.bits.pc)
    io.inst_type := ctrlsig.inst_type
    
    val ebreak_ = Module(new ysyx_23060246_Ebreak)
    val isebreak = RegInit(false.B)
    when(io.in.bits.inst === insts.ebreak){
        isebreak := true.B
    }.otherwise{
        isebreak := false.B
    }
    ebreak_.io.isebreak := isebreak
    ebreak_.io.clock := clock
    ebreak_.io.reset := reset

    if(config.PERF_CNT){
        val inst_cnt = RegInit(0.U(64.W))
        val cycle_cnt = RegInit(0.U(64.W))
        when(wbu_valid){
            inst_cnt := inst_cnt + 1.U
        }
        cycle_cnt := cycle_cnt + 1.U
        dontTouch(inst_cnt)
        dontTouch(cycle_cnt)
    }

}
