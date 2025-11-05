package cpu

import chisel3._
import chisel3.util._

class BPU(config:NPCConfig) extends Module{
    val io = IO(new Bundle{
        val pc = Input(UInt(config.XLEN.W))
        val update = Input(Bool())
        val exu_npc = Flipped(Valid(UInt(config.XLEN.W)))
        val exu_pc = Input(UInt(config.XLEN.W))
        val idu_pc = Input(UInt(config.XLEN.W))
        val npc = Output(UInt(config.XLEN.W))

    })
    val params = config.bpuparameters
    val entrySize = params.nEntries
    val tagWidth = log2Ceil(entrySize)
    val pcWidth = params.pcWidth
    val npcWidth = params.npcWidth
    val cntWidth = params.cntWidth
    
    val initCounterValue = (1 << (cntWidth - 1)).U(cntWidth.W)

    val btb = new Bundle {
        val pc = RegInit(VecInit(Seq.fill(entrySize)(0.U(pcWidth.W))))
        val npc = RegInit(VecInit(Seq.fill(entrySize)(0.U(npcWidth.W))))
        val counter = RegInit(VecInit(Seq.fill(entrySize)(initCounterValue))) // 2-bit saturating counter
    }
    

    val tag = RegInit(0.U(tagWidth.W))


    val npc = Wire(UInt(config.XLEN.W))



    npc := io.pc + 4.U
    for (i <- 0 until entrySize) {
        when(btb.pc(i) === io.pc(pcWidth-1,0)) {
            when(btb.counter(i)(cntWidth-1)){
                npc := Cat(io.pc(config.XLEN-1, npcWidth), btb.npc(i))
            }.otherwise{
                npc := io.pc + 4.U
            }
        tag := (i).U 
        }
    }

    val tag_plus_1 = tag + 1.U
    val replace_idx = WireDefault(entrySize.U)
    for (i <- 0 until entrySize) {
        when(btb.pc(i) === io.exu_pc(pcWidth-1,0)) {
            replace_idx := i.U
        }
    }
    when(io.update) {
        when(replace_idx === entrySize.U) {
            btb.pc(tag_plus_1) := io.exu_pc
            btb.npc(tag_plus_1) := io.exu_npc.bits
            btb.counter(tag_plus_1) := initCounterValue
            tag := tag_plus_1
        }.otherwise {
            btb.pc(replace_idx) := io.exu_pc
            btb.npc(replace_idx) := io.exu_npc.bits
            tag := replace_idx
        }
    }

    // val branch_taken = io.exu_npc.bits(pcWidth-1,0) === io.idu_pc(pcWidth-1,0)
    // dontTouch(branch_taken)
    // val isBranch = (io.exu_pc(pcWidth-1,0) + 4.U) =/= io.exu_npc.bits(pcWidth-1,0) 
    // dontTouch(isBranch)




    val update_cnt_idx = WireDefault(entrySize.U)
    for (i <- 0 until entrySize) {
        when(btb.pc(i) === io.exu_pc(pcWidth-1,0)) {
            update_cnt_idx := i.U
        }
    }
    dontTouch(update_cnt_idx)
    val branch_taken = Mux(update_cnt_idx < entrySize.U, btb.npc(update_cnt_idx) === io.exu_npc.bits(npcWidth-1, 0), false.B)
    dontTouch(branch_taken)
    val isBranch = (io.exu_pc(pcWidth-1,0) + 4.U) =/= io.exu_npc.bits(pcWidth-1,0) 
    dontTouch(isBranch)
    val counterMaxValue = ((1 << cntWidth) - 1).U(cntWidth.W)

    when(io.exu_npc.valid && isBranch){
        when(branch_taken) {
            btb.counter(update_cnt_idx) := Mux(btb.counter(update_cnt_idx) === counterMaxValue, counterMaxValue, 
                                btb.counter(update_cnt_idx) + 1.U)
        }.otherwise {
            btb.counter(update_cnt_idx) := Mux(btb.counter(update_cnt_idx) === 0.U, 0.U, 
                                btb.counter(update_cnt_idx) - 1.U)
        }
    }

    io.npc := npc
}