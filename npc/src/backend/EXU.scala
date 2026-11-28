package npc

import chisel3._
import chisel3.util._
import npc.EXUs._
import npc.PMU._
import backend.intr2EXU

object JumpOp extends ChiselEnum{
    val none, jump = Value
}

object MemOp extends ChiselEnum{
    val none, load, store = Value
}

object MemSize extends ChiselEnum{
    val byte, half, word = Value
}

object WBSrc extends ChiselEnum{
    val none, alu, mem, pc_plus4, csr = Value
}

object BranchOp extends ChiselEnum{
    val none, beq, bne, blt, bge, bltu, bgeu = Value
}

object CSROp extends ChiselEnum{
    val none, csrrw, csrrs = Value
}

object SysOp extends ChiselEnum{
    val none, mret = Value
}

class EXUCTLBundle extends Bundle{
    val ALU_Src1    = Output(ALUSrc1())
    val ALU_Src2    = Output(ALUSrc2())
    val ALU_Control = Output(ALUOp())
    val reg_write   = Output(Bool())
    val wb_src      = Output(WBSrc())
    val mem_op      = Output(MemOp())
    val mem_size    = Output(MemSize())
    val mem_signed  = Output(Bool())
    val branch_op   = Output(BranchOp())
    val jump_op     = Output(JumpOp())
    val csr_op      = Output(CSROp())
    val sys_op      = Output(SysOp())
    val fence_i     = Output(Bool())
    val wfi         = Output(Bool())
}

class ysyx_26030092_EXU extends Module{

    val idu_out = IO(Flipped(Decoupled(new IDUBundle)))

    // ALU
    val src1 = WireDefault(0.U(32.W))
    switch(idu_out.bits.exu_ctl.ALU_Src1){
        is(ALUSrc1.rs1){ src1 := idu_out.bits.rs1_data }
        is(ALUSrc1.pc) { src1 := idu_out.bits.decode.pc }
    }
    val src2 = WireDefault(0.U(32.W))
    switch(idu_out.bits.exu_ctl.ALU_Src2){
        is(ALUSrc2.rs2)   { src2 := idu_out.bits.rs2_data }
        is(ALUSrc2.imm)   { src2 := idu_out.bits.decode.imm }
        is(ALUSrc2.shamt) { src2 := Cat(0.U(27.W), idu_out.bits.decode.imm(4,0)) }
        is(ALUSrc2.csr)   { src2 := idu_out.bits.csr_rdata }
    }
    val ALU_u = Module(new ysyx_26030092_ALU)
    ALU_u.in.ctl := idu_out.bits.exu_ctl.ALU_Control
    ALU_u.in.src1 := src1
    ALU_u.in.src2 := src2
    val AluResult = ALU_u.out
    dontTouch(AluResult)

    // lsu接线
    val lsu_out = IO(Flipped(Decoupled(new LSUOutBundle)))
    lsu_out.ready := false.B

    val is_mem = idu_out.valid && idu_out.bits.exu_ctl.mem_op =/= MemOp.none
    val lsu_in = IO(Decoupled(new LSUBundle))

    lsu_in.bits := 0.U.asTypeOf(new LSUBundle)
    lsu_in.bits.addr := AluResult
    lsu_in.bits.wdata := idu_out.bits.rs2_data
    lsu_in.bits.mem_op := idu_out.bits.exu_ctl.mem_op
    lsu_in.bits.mem_size := idu_out.bits.exu_ctl.mem_size
    lsu_in.bits.mem_signed := idu_out.bits.exu_ctl.mem_signed
    lsu_in.bits.pc := idu_out.bits.decode.pc
    lsu_in.valid  := idu_out.fire && is_mem

    // branch
    val redirectPC = IO(Output(UInt(32.W)))
    val mtvec = IO(Input(UInt(32.W)))
    val mret_out = IO(Output(Bool()))
    val bpu_train = IO(Output(new BPUTrainBundle))
    val branch_u = Module(new ysyx_26030092_BranchUnit)
    val pc_u = Module(new ysyx_26030092_PCReg)
    branch_u.pc        := pc_u.pc
    branch_u.alu       := AluResult
    branch_u.idu_in    := idu_out.bits.to_branch
    branch_u.fire      := idu_out.fire
    branch_u.idu_in.is_excp := idu_out.bits.is_excp
    bpu_train          := branch_u.bpu_train
    pc_u.adv     := branch_u.adv
    pc_u.jump     := branch_u.jump
    pc_u.next_pc  := branch_u.next_pc
    dontTouch(pc_u.jump)


    // flush
    val flush = IO(Output(Bool()))
    val fencei = IO(Output(Bool()))
    val pc_valid_not_hit = (idu_out.bits.pc_valid && idu_out.bits.decode.pc =/= pc_u.pc)
    fencei := RegNext(idu_out.fire && idu_out.bits.exu_ctl.fence_i, false.B)
    flush  := pc_valid_not_hit | fencei
    redirectPC := pc_u.pc

    // 构建wb wire
    val wb_data = Wire(new WriteBackPortBundle)
    wb_data := 0.U.asTypeOf(new WriteBackPortBundle)
    wb_data.RegWaddr := idu_out.bits.decode.rd
    wb_data.RegWrite := idu_out.bits.exu_ctl.reg_write
    wb_data.PC := idu_out.bits.decode.pc
    switch(idu_out.bits.exu_ctl.wb_src){
        is(WBSrc.alu)      { wb_data.RegWdata := AluResult }
        is(WBSrc.pc_plus4) { wb_data.RegWdata := idu_out.bits.decode.pc + 4.U }
        is(WBSrc.csr)      { wb_data.RegWdata := idu_out.bits.csr_rdata }
    }
    when(idu_out.bits.exu_ctl.csr_op =/= CSROp.none){
        wb_data.CSRAddr := idu_out.bits.decode.imm(11,0)
        wb_data.CSRWrite := true.B
        wb_data.CSRData := Mux(idu_out.bits.exu_ctl.csr_op === CSROp.csrrw,
                               idu_out.bits.rs1_data, AluResult)
    }
    wb_data.Exception_Code := idu_out.bits.excp_code
    wb_data.isTrap := idu_out.bits.is_excp

    // commit debug
    val commit_info = IO(Output(new CommitInfoBundle))
    val commit_info_comb = Wire(new CommitInfoBundle)
    val wb_slot_commit = Reg(new CommitInfoBundle)
    commit_info   := wb_slot_commit
    commit_info_comb.mem := is_mem
    commit_info_comb.mem_addr := AluResult
    commit_info_comb.pc := idu_out.bits.decode.pc
    commit_info_comb.inst := idu_out.bits.decode.inst
    commit_info_comb.next_pc := Mux(idu_out.bits.is_excp, mtvec, branch_u.dnpc)

    // 非访存指令流水 & FSM
    val wbu_in = IO(Decoupled(new WriteBackPortBundle))
    val wb_slot        = Reg(new WriteBackPortBundle)
    val wb_slot_valid  = RegInit(false.B)
    val lsu_busy       = RegInit(false.B)
    idu_out.ready := !lsu_busy && !flush// can accept
    wbu_in.valid  := wb_slot_valid
    wbu_in.bits   := wb_slot

    wb_slot_valid := false.B
    when(lsu_busy){ 
        lsu_out.ready := true.B
        when(lsu_out.fire){
            wb_slot.RegWdata := lsu_out.bits.rdata
            wb_slot_valid    := true.B
            lsu_busy         := false.B
            when(lsu_out.bits.is_excp){
                wb_slot.isTrap         := true.B
                wb_slot.Exception_Code := lsu_out.bits.excp_code
                wb_slot.RegWrite       := false.B
                wb_slot.CSRWrite       := false.B
            }
        }
    }.elsewhen(idu_out.fire){
        wb_slot        := wb_data
        wb_slot_commit := commit_info_comb
        when(is_mem && !idu_out.bits.is_excp){ lsu_busy := true.B }.otherwise{ wb_slot_valid := true.B }
    }

    // forwarding
    val wb_info  = IO(Output(new StageWriteInfoBundle))
    val csr_info = IO(Output(new CSRWriteInfoBundle))
    wb_info.wen   := (wb_slot_valid || lsu_busy) && wb_slot.RegWrite
    wb_info.rd    := wb_slot.RegWaddr
    wb_info.value := wb_slot.RegWdata
    wb_info.valid := wb_slot_valid && wb_slot.RegWrite

    csr_info.wen   := (wb_slot_valid || lsu_busy) && wb_slot.CSRWrite
    csr_info.addr  := wb_slot.CSRAddr
    csr_info.value := wb_slot.CSRData
    csr_info.valid := wb_slot_valid && wb_slot.CSRWrite


    // excp
    val wb_trap = wb_slot_valid && wb_slot.isTrap
    when(wb_trap){
        idu_out.ready := false.B
        pc_u.jump     := true.B
        pc_u.next_pc  := mtvec
    }
    // 异常指令提交时，报告的下一跳是 mtvec
    when(wb_trap){
        commit_info.next_pc := mtvec
    }

    mret_out := idu_out.fire && idu_out.bits.exu_ctl.sys_op === SysOp.mret

    // intr
    val intr = IO(Flipped(new intr2EXU))
    intr.intr_pc := DontCare
    intr.wfi := idu_out.bits.exu_ctl.wfi && idu_out.fire
    intr.intr_taken := false.B
    intr.excp_taken := wb_slot_valid && wb_slot.isTrap
    val exu_not_busy = !lsu_busy && !wb_slot_valid
    when(intr.intr){
        idu_out.ready := false.B
        when(exu_not_busy){
            intr.intr_taken := true.B
            pc_u.jump := true.B
            pc_u.next_pc := mtvec
            intr.intr_pc := pc_u.pc
        }
    }
    when(intr.sleep) { idu_out.ready := false.B }


    PerfCounter("EXU_flush_count")         := flush
    PerfCounter("EXU_stall_cycles")        := idu_out.valid && !idu_out.ready
    PerfCounter("EXU_lsu_wait")            := lsu_busy
    PerfCounter("EXU_stall_by_lsu_reject") := idu_out.valid && is_mem && !lsu_in.ready
    PerfCounter("EXU_idle_cycles")         := !idu_out.valid && !wb_slot_valid && !lsu_busy
}
