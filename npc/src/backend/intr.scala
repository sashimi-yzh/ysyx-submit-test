package backend
import chisel3._

class intr2RFS extends Bundle{
    val timer_intr = Input(Bool())// from and to RFS
    val timer_armed = Input(Bool())// RFS：计时器还在计数
    val timer_intr_taken = Output(Bool())
    val intr_pc = Output(UInt(32.W))
    val intr_en = Input(Bool())
}
class intr2EXU extends Bundle{
    val intr = Output(Bool()) // from and to EXU
    val intr_taken = Input(Bool())
    val excp_taken = Input(Bool())
    val intr_pc = Input(UInt(32.W))
    val sleep = Output(Bool())
    val wfi = Input(Bool())
}

class ysyx_26030092_intrUnit extends Module{
    val to_RFS = IO(new intr2RFS)

    val to_EXU = IO(new intr2EXU)
    to_RFS.intr_pc := to_EXU.intr_pc

    val intr_flag = RegInit(false.B)
    to_EXU.intr := intr_flag & to_RFS.intr_en
    to_RFS.timer_intr_taken := false.B
    when(to_RFS.timer_intr){
        intr_flag := true.B
    }
    when(to_EXU.intr_taken & intr_flag){
        intr_flag := false.B
        to_RFS.timer_intr_taken := true.B
    }

    val wfi_flag = RegInit(false.B)

    when(to_EXU.wfi && to_RFS.timer_armed) { wfi_flag := true.B }
    when(to_RFS.timer_intr) { wfi_flag := false.B }
    when(!to_RFS.timer_armed) { wfi_flag := false.B }

    to_EXU.sleep := wfi_flag 
}