package npc

import chisel3._
import chisel3.util._
import npc.EXUs._
import npc.PMU._

class InstDecode extends Bundle{
    val inst = UInt(32.W)
    def opcode = inst(6,0)
    def rs1 = inst(19,15)
    def rs2 = inst(24,20)
    def rd = inst(11,7)
    def funct3 = inst(14,12)
    def funct7 = inst(31,25)
    def immI = Cat(Fill(20,inst(31)),inst(31,20))
    def immIU = Cat(Fill(20,0.U),inst(31,20))
    def immB = Cat(Fill(19, inst(31)), inst(31), inst(7), inst(30,25), inst(11,8), 0.U(1.W))
    def immU = Cat(inst(31,12),0.U(12.W))
    def immS = Cat(Fill(20,inst(31)),inst(31,25),inst(11,7))
    def immJ = Cat(Fill(11, inst(31)), inst(31), inst(19,12), inst(20), inst(30,21), 0.U(1.W))
    
}

 
class ysyx_26030092_EbreakBlackBox extends ExtModule{
    val io = FlatIO(new Bundle{
        val ebreak_trap = Input(Bool())
    })
    addResource("/EbreakBlackBox.v")
}
class ysyx_26030092_InvalidInstructionBlackBox extends ExtModule{
    val io = FlatIO(new Bundle{
        val pc = Input(UInt(32.W))
        val inst = Input(UInt(32.W))
        val invalid = Input(Bool())
    })
    addResource("/InvalidInstructionBlackBox.v")
}

class DecodeBundle extends Bundle{
        val inst = Output(UInt(32.W))
        val rd = Output(UInt(5.W))
        val imm = Output(UInt(32.W))
        val pc = Output(UInt(32.W))
}

class IDUBundle extends Bundle{
    val decode = new DecodeBundle
    val exu_ctl = new EXUCTLBundle
    val rs1_data = UInt(32.W)
    val rs2_data = UInt(32.W)
    val csr_rdata = UInt(32.W)
    val excp_code = UInt(32.W)
    val is_excp = Bool()
    val pc_valid = Bool()

    def to_branch = {
        val b = Wire(new branchBundle)
        b.rs1       := rs1_data
        b.rs2       := rs2_data
        b.csr_rdata := csr_rdata
        b.branch_op := exu_ctl.branch_op
        b.jump_op   := exu_ctl.jump_op
        b.sys_op    := exu_ctl.sys_op
        b.is_excp   := is_excp
        b
    }

}

class StageWriteInfoBundle extends Bundle{
    val wen   = Output(Bool()) 
    val rd    = Output(UInt(5.W)) 
    val value = Output(UInt(32.W))
    val valid = Output(Bool())
}

class CSRWriteInfoBundle extends Bundle{
    val wen   = Output(Bool())
    val addr  = Output(UInt(12.W))
    val value = Output(UInt(32.W))
    val valid = Output(Bool())
}

class ysyx_26030092_IDU extends Module{
    val in = IO(Flipped(Decoupled(new Bundle {
        val pc = Input(UInt(32.W))
        val inst = Input(UInt(32.W))
        val excp_code = Input(UInt(32.W))
        val is_excp = Input(Bool())
    })))

    val flush = IO(Input(Bool()))
    val out = IO(Decoupled(new IDUBundle))

    val wb_info  = IO(Flipped(new StageWriteInfoBundle))
    val csr_info = IO(Flipped(new CSRWriteInfoBundle))

    val RFS_ReadPort = IO(new Bundle {
        val RegReadPort = new ReadRegPortBundle
        val CSRReadPort = new CSRReadPortBundle
    })

    val out_comb = Wire(new IDUBundle)



    val inst = in.bits.inst.asTypeOf(new InstDecode)
    dontTouch(inst)

    // RAW 冒险
    def conflict(rs: UInt, info: StageWriteInfoBundle): Bool =
        info.wen && rs =/= 0.U && rs === info.rd

    val csr_read_addr = MuxCase(0.U(12.W), Seq(
        (out_comb.exu_ctl.sys_op === SysOp.mret)          -> "h341".U,
        (out_comb.exu_ctl.csr_op =/= CSROp.none)          -> out_comb.decode.imm(11,0)
    ))
    val in_rs1_hit = conflict(inst.rs1, wb_info)
    val in_rs2_hit = conflict(inst.rs2, wb_info)
    val in_csr_hit = csr_info.wen && csr_read_addr === csr_info.addr

    out_comb.decode.inst := in.bits.inst
    out_comb.pc_valid := true.B
    RFS_ReadPort.RegReadPort.raddr1 := inst.rs1
    RFS_ReadPort.RegReadPort.raddr2 := inst.rs2
    RFS_ReadPort.CSRReadPort.CSRRAddr := csr_read_addr

    out_comb.rs1_data := Mux(in_rs1_hit && wb_info.valid, wb_info.value, RFS_ReadPort.RegReadPort.rdata1)
    out_comb.rs2_data := Mux(in_rs2_hit && wb_info.valid, wb_info.value, RFS_ReadPort.RegReadPort.rdata2)
    out_comb.csr_rdata := Mux(in_csr_hit && csr_info.valid, csr_info.value, RFS_ReadPort.CSRReadPort.CSRRData)

    val slot       = Reg(new IDUBundle)
    val slot_valid = RegInit(false.B)

    val slot_csr_addr = MuxCase(0.U(12.W), Seq(
        (slot.exu_ctl.sys_op === SysOp.mret) -> "h341".U,
        (slot.exu_ctl.csr_op =/= CSROp.none) -> slot.decode.imm(11,0)
    ))
    val slot_inst    = slot.decode.inst.asTypeOf(new InstDecode)
    val slot_rs1_hit = conflict(slot_inst.rs1, wb_info)
    val slot_rs2_hit = conflict(slot_inst.rs2, wb_info)
    val slot_csr_hit = csr_info.wen && slot_csr_addr === csr_info.addr
    val slot_stall   = ((slot_rs1_hit || slot_rs2_hit) && !wb_info.valid) ||
                       (slot_csr_hit && !csr_info.valid)

    in.ready   := !flush && (!slot_valid || out.fire)
    out.valid  := slot_valid & !slot_stall
    out.bits   := slot
    out.bits.pc_valid := slot_valid
    out.bits.rs1_data  := Mux(slot_rs1_hit && wb_info.valid, wb_info.value, slot.rs1_data)
    out.bits.rs2_data  := Mux(slot_rs2_hit && wb_info.valid, wb_info.value, slot.rs2_data)
    out.bits.csr_rdata := Mux(slot_csr_hit && csr_info.valid, csr_info.value, slot.csr_rdata)

    when(flush){
        slot_valid := false.B
    }.otherwise{
        when(in.fire){
            slot       := out_comb
            slot_valid := true.B
        }.elsewhen(out.fire){
            slot_valid := false.B
        }
    }

    PerfCounter("IDU_pipe_idle") := !in.valid

    val invalid = WireDefault(true.B)

    out_comb.excp_code := DontCare
    out_comb.is_excp := false.B

    out_comb.decode.rd := inst.rd
    out_comb.decode.pc := in.bits.pc
    out_comb.decode.imm := DontCare

    out_comb.exu_ctl.ALU_Src1    := ALUSrc1.rs1
    out_comb.exu_ctl.ALU_Src2    := ALUSrc2.imm
    out_comb.exu_ctl.ALU_Control := ALUOp.add
    out_comb.exu_ctl.reg_write   := false.B
    out_comb.exu_ctl.wb_src      := WBSrc.none
    out_comb.exu_ctl.mem_op      := MemOp.none
    out_comb.exu_ctl.mem_size    := MemSize.word
    out_comb.exu_ctl.mem_signed  := false.B
    out_comb.exu_ctl.branch_op   := BranchOp.none
    out_comb.exu_ctl.jump_op     := JumpOp.none
    out_comb.exu_ctl.csr_op      := CSROp.none
    out_comb.exu_ctl.sys_op      := SysOp.none
    out_comb.exu_ctl.fence_i     := false.B
    out_comb.exu_ctl.wfi         := false.B

    when(invalid && !in.bits.is_excp){
        out_comb.excp_code := 2.U
        out_comb.is_excp := true.B
    }


    switch(inst.opcode){
        is("b0010011".U){
            out_comb.decode.imm := inst.immI
            out_comb.exu_ctl.ALU_Src1 := ALUSrc1.rs1
            out_comb.exu_ctl.ALU_Src2 := ALUSrc2.imm
            out_comb.exu_ctl.reg_write := true.B
            out_comb.exu_ctl.wb_src := WBSrc.alu
            when(inst.funct3 === "b000".U){// addi
                out_comb.exu_ctl.ALU_Control := ALUOp.add
                invalid := false.B
            }
            when(inst.funct3 === "b011".U){// sltiu
                out_comb.exu_ctl.ALU_Control := ALUOp.sltu
                invalid := false.B
            }
            when(inst.funct3 === "b010".U){// slti
                out_comb.exu_ctl.ALU_Control := ALUOp.slt
                invalid := false.B
            }
            when(inst.funct3 === "b001".U && inst.immI(11,5) === "b0".U ){// slli
                out_comb.exu_ctl.ALU_Control := ALUOp.sll
                out_comb.exu_ctl.ALU_Src2 := ALUSrc2.shamt
                invalid := false.B
            }
            when(inst.funct3 === "b101".U && inst.immI(11,5) === "b0".U){//srli
                out_comb.exu_ctl.ALU_Control := ALUOp.srl
                out_comb.exu_ctl.ALU_Src2 := ALUSrc2.shamt
                invalid := false.B   
            }
            when(inst.funct3 === "b101".U && inst.immI(11,5) === "b0100000".U){//srai
                out_comb.exu_ctl.ALU_Control := ALUOp.sra
                out_comb.exu_ctl.ALU_Src2 := ALUSrc2.shamt
                invalid := false.B   
            }

            when(inst.funct3 === "b111".U){// andi
                out_comb.exu_ctl.ALU_Control := ALUOp.and
                invalid := false.B
            }
            when(inst.funct3 === "b100".U){// xori
                out_comb.exu_ctl.ALU_Control := ALUOp.xor
                invalid := false.B
            }
            when(inst.funct3 === "b110".U){// ori
                out_comb.exu_ctl.ALU_Control := ALUOp.or
                invalid := false.B
            }
        }
        is("b1100111".U){
            out_comb.decode.imm := inst.immI
            out_comb.exu_ctl.ALU_Src1 := ALUSrc1.rs1
            out_comb.exu_ctl.ALU_Src2 := ALUSrc2.imm
            when(inst.funct3 === "b000".U){//jalr
                out_comb.exu_ctl.jump_op := JumpOp.jump
                out_comb.exu_ctl.ALU_Control := ALUOp.add
                out_comb.exu_ctl.reg_write := true.B
                out_comb.exu_ctl.wb_src := WBSrc.pc_plus4
                invalid := false.B
            }
        }
        is("b1110011".U){
            when(inst.funct3 === "b000".U && inst.immI === 1.U && 
                        inst.rs1 === 0.U && inst.rd === 0.U){//ebreak
                    invalid := false.B
                    when(!in.bits.is_excp){
                        out_comb.excp_code := 3.U
                        out_comb.is_excp := true.B
                    }
                
            }.elsewhen(inst.funct3 === "b010".U){// csrrs
                out_comb.decode.rd := inst.rd
                out_comb.decode.imm := inst.immI
                out_comb.exu_ctl.ALU_Src1 := ALUSrc1.rs1
                out_comb.exu_ctl.ALU_Src2 := ALUSrc2.csr
                out_comb.exu_ctl.ALU_Control := ALUOp.or
                out_comb.exu_ctl.csr_op := CSROp.csrrs
                out_comb.exu_ctl.reg_write := true.B
                out_comb.exu_ctl.wb_src := WBSrc.csr
                invalid := false.B
            }.elsewhen(inst.funct3 === "b001".U){// csrws
                out_comb.decode.rd := inst.rd
                out_comb.decode.imm := inst.immI
                out_comb.exu_ctl.csr_op := CSROp.csrrw
                out_comb.exu_ctl.reg_write := true.B
                out_comb.exu_ctl.wb_src := WBSrc.csr
                invalid := false.B
            }.elsewhen(inst.funct3 === "b000".U && inst.immI === "h105".U &&
                        inst.rs1 === 0.U && inst.rd === 0.U){// wfi
                    out_comb.exu_ctl.wfi := true.B
                    invalid := false.B
            }.elsewhen(inst.funct3 === 0.U && inst.rd === 0.U && 
                    inst.rs1 === 0.U && inst.immI === "b001100000010".U){// mret
                    out_comb.exu_ctl.sys_op := SysOp.mret
                    invalid := false.B
            }.elsewhen(inst.funct3 === "b000".U && inst.immI === 0.U && 
                        inst.rs1 === 0.U && inst.rd === 0.U){ // ecall
                when(!in.bits.is_excp){
                    out_comb.excp_code := 11.U
                    out_comb.is_excp := true.B
                }
                out_comb.decode.pc := in.bits.pc
                invalid := false.B
            }
        }
        is("b0110011".U){
            out_comb.exu_ctl.ALU_Src1 := ALUSrc1.rs1
            out_comb.exu_ctl.ALU_Src2 := ALUSrc2.rs2
            out_comb.exu_ctl.reg_write := true.B
            out_comb.exu_ctl.wb_src := WBSrc.alu
            when(inst.funct3 === "b000".U && inst.funct7 === "b0000000".U){// add
                out_comb.exu_ctl.ALU_Control := ALUOp.add
                invalid := false.B
            }
            when(inst.funct3 === "b000".U && inst.funct7 === "b0100000".U){// sub
                out_comb.exu_ctl.ALU_Control := ALUOp.sub
                invalid := false.B
            }
            when(inst.funct3 === "b111".U && inst.funct7 === "b0000000".U){// and
                out_comb.exu_ctl.ALU_Control := ALUOp.and
                invalid := false.B
            }
            when(inst.funct3 === "b100".U && inst.funct7 === "b0000000".U){// xor
                out_comb.exu_ctl.ALU_Control := ALUOp.xor
                invalid := false.B
            }
            when(inst.funct3 === "b110".U && inst.funct7 === "b0000000".U){// or
                out_comb.exu_ctl.ALU_Control := ALUOp.or
                invalid := false.B
            }
            when(inst.funct3 === "b011".U && inst.funct7 === "b0000000".U){// sltu
                out_comb.exu_ctl.ALU_Control := ALUOp.sltu
                invalid := false.B
            }

            when(inst.funct3 === "b001".U && inst.funct7 === "b0000000".U){// sll
                out_comb.exu_ctl.ALU_Control := ALUOp.sll
                invalid := false.B
            }
            when(inst.funct3 === "b101".U && inst.funct7 === "b0000000".U){// srl
                out_comb.exu_ctl.ALU_Control := ALUOp.srl
                invalid := false.B
            }
            when(inst.funct3 === "b101".U && inst.funct7 === "b0100000".U){// sra
                out_comb.exu_ctl.ALU_Control := ALUOp.sra
                invalid := false.B
            }
            when(inst.funct3 === "b010".U && inst.funct7 === "b0000000".U){// slt
                out_comb.exu_ctl.ALU_Control := ALUOp.slt
                invalid := false.B
            }
            when(inst.funct3 === "b011".U && inst.funct7 === "b0000000".U){// sltu
                out_comb.exu_ctl.ALU_Control := ALUOp.sltu
                invalid := false.B
            }


        }
        is("b0110111".U){// lui
            out_comb.decode.imm := inst.immU
            out_comb.exu_ctl.ALU_Src2 := ALUSrc2.imm
            out_comb.exu_ctl.ALU_Control := ALUOp.lui
            out_comb.exu_ctl.reg_write := true.B
            out_comb.exu_ctl.wb_src := WBSrc.alu
            invalid := false.B
        }
        is("b0010111".U){// auipc
            out_comb.decode.imm := inst.immU
            out_comb.exu_ctl.ALU_Src1 := ALUSrc1.pc
            out_comb.exu_ctl.ALU_Src2 := ALUSrc2.imm
            out_comb.exu_ctl.ALU_Control := ALUOp.add
            out_comb.exu_ctl.reg_write := true.B
            out_comb.exu_ctl.wb_src := WBSrc.alu
            invalid := false.B
        }
        is("b0000011".U){
            out_comb.exu_ctl.ALU_Src1 := ALUSrc1.rs1
            out_comb.exu_ctl.ALU_Src2 := ALUSrc2.imm
            out_comb.decode.imm := inst.immI
            out_comb.exu_ctl.ALU_Control := ALUOp.add
            out_comb.exu_ctl.mem_op := MemOp.load
            out_comb.exu_ctl.reg_write := true.B
            out_comb.exu_ctl.wb_src := WBSrc.mem
            when(inst.funct3 === "b010".U){//lw
                out_comb.exu_ctl.mem_size := MemSize.word
                invalid := false.B
            }.elsewhen(inst.funct3 === "b100".U){//lbu
                out_comb.exu_ctl.mem_size := MemSize.byte
                invalid := false.B
            }.elsewhen(inst.funct3 === "b101".U){//lhu
                out_comb.exu_ctl.mem_size := MemSize.half
                invalid := false.B                
            }.elsewhen(inst.funct3 === "b000".U){// lb
                out_comb.exu_ctl.mem_size := MemSize.byte
                out_comb.exu_ctl.mem_signed := true.B
                invalid := false.B    
            }.elsewhen(inst.funct3 === "b001".U){// lh
                out_comb.exu_ctl.mem_size := MemSize.half
                out_comb.exu_ctl.mem_signed := true.B
                invalid := false.B
            }
        }
        is("b0100011".U){
            out_comb.exu_ctl.ALU_Src1 := ALUSrc1.rs1
            out_comb.exu_ctl.ALU_Src2 := ALUSrc2.imm
            out_comb.decode.imm := inst.immS
            out_comb.exu_ctl.ALU_Control := ALUOp.add
            out_comb.exu_ctl.mem_op := MemOp.store
            when(inst.funct3 === "b010".U){// sw
                out_comb.exu_ctl.mem_size := MemSize.word
                invalid := false.B
                
            }.elsewhen(inst.funct3 === "b000".U){// sb
                out_comb.exu_ctl.mem_size := MemSize.byte
                invalid := false.B
            }.elsewhen(inst.funct3 === "b001".U){
                out_comb.exu_ctl.mem_size := MemSize.half
                invalid := false.B
            }
        }
        is("b1101111".U){// jal
            out_comb.exu_ctl.ALU_Src1 := ALUSrc1.pc
            out_comb.exu_ctl.ALU_Src2 := ALUSrc2.imm
            out_comb.decode.imm := inst.immJ
            out_comb.exu_ctl.ALU_Control := ALUOp.add
            out_comb.exu_ctl.jump_op := JumpOp.jump
            out_comb.exu_ctl.reg_write := true.B
            out_comb.exu_ctl.wb_src := WBSrc.pc_plus4
            invalid := false.B
        }

        is("b1100011".U){// branch
            out_comb.exu_ctl.ALU_Src1 := ALUSrc1.pc
            out_comb.exu_ctl.ALU_Src2 := ALUSrc2.imm
            out_comb.decode.imm := inst.immB
            out_comb.exu_ctl.ALU_Control := ALUOp.add
            switch(inst.funct3){
                is("b000".U){
                    out_comb.exu_ctl.branch_op := BranchOp.beq
                    invalid := false.B
                }
                is("b001".U){
                    out_comb.exu_ctl.branch_op := BranchOp.bne
                    invalid := false.B
                }
                is("b100".U){
                    out_comb.exu_ctl.branch_op := BranchOp.blt
                    invalid := false.B                    
                }
                is("b101".U){
                    out_comb.exu_ctl.branch_op := BranchOp.bge
                    invalid := false.B                    
                }
                is("b110".U){
                    out_comb.exu_ctl.branch_op := BranchOp.bltu
                    invalid := false.B                    
                }
                is("b111".U){
                    out_comb.exu_ctl.branch_op := BranchOp.bgeu
                    invalid := false.B
                }
            }
        }
        is("b0001111".U){ //fence.i
            when(inst.funct3 === "b001".U){
                out_comb.exu_ctl.fence_i := true.B
                invalid := false.B
            }
        }
    }

    when(in.bits.is_excp){
        out_comb.is_excp := true.B
        out_comb.excp_code := in.bits.excp_code
    }

    val fired_inst = slot.decode.inst.asTypeOf(new InstDecode)
    PerfCounter("IDU_calc") := (fired_inst.opcode === "b0010011".U || fired_inst.opcode === "b0110011".U) && out.fire
    PerfCounter("IDU_jump") := (fired_inst.opcode === "b1100111".U || fired_inst.opcode === "b1101111".U) && out.fire
    PerfCounter("IDU_csr") := (fired_inst.opcode === "b1110011".U) && out.fire
    PerfCounter("IDU_load") := (fired_inst.opcode === "b0000011".U) && out.fire
    PerfCounter("IDU_store") := (fired_inst.opcode === "b0100011".U) && out.fire
    PerfCounter("IDU_branch") := (fired_inst.opcode === "b1100011".U) && out.fire
    PerfCounter("IDU_slot_stall_cycles") := slot_valid && slot_stall
    PerfCounter("IDU_idle_cycle") := !slot_valid & !in.valid
    PerfCounter("IDU_stall_by_EXU_cycle") := slot_valid & !out.ready
    val idu_internal_stall = in.valid && !in.ready && !out.fire
    PerfCounter("IDU_internal_stall_cycles") := idu_internal_stall
    PerfCounter("IDU_flush_discard") := flush && slot_valid
}