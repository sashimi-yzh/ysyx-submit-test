package npc

import chisel3._
import npc.AXI._
// import npc.Xbar.{Arbiter,Xbar}
import npc.device._
import npc.PMU._
import backend._

class ysyx_26030092 extends Module{

    val area = Seq((0X2000000L, 0X200BFFFL),
                    (0x80000000L, 0x8fffffffL))

    val io = IO(new Bundle{
        val interrupt = Input(Bool())
        val master = new AXI4Bundle()
        val slave = Flipped(new AXI4Bundle())
    })
    val IFU_u = Module(new ysyx_26030092_IFU())
    val RFS_u = Module(new ysyx_26030092_RFS())
    val LSU_u = Module(new ysyx_26030092_LSU())
    val IDU_u = Module(new ysyx_26030092_IDU())
    val EXU_u = Module(new ysyx_26030092_EXU())
    val WBU_u = Module(new ysyx_26030092_WBU())

    WBU_u.commit_info := EXU_u.commit_info


    val CLINT_u = Module(new ysyx_26030092_CLINT())
    val CLINT_AXI4Router_u = Module(new ysyx_26030092_CLINT_AXI4Router())
    val AXI4Arbiter_u = Module(new ysyx_26030092_AXI4Arbiter(2))
    io.slave.initSlave()
    


    IFU_u.flush_icache := EXU_u.fencei
    IFU_u.flush := EXU_u.flush
    IFU_u.RedirectPC :=EXU_u.redirectPC
    IFU_u.bpu_train := EXU_u.bpu_train

    IDU_u.in <> IFU_u.out
    IDU_u.RFS_ReadPort <> RFS_u.RFS_ReadPort
    IDU_u.flush := EXU_u.flush

    IDU_u.wb_info  <> EXU_u.wb_info
    IDU_u.csr_info <> EXU_u.csr_info

    EXU_u.idu_out <> IDU_u.out

    EXU_u.lsu_in <> LSU_u.in
    EXU_u.lsu_out <> LSU_u.out

    EXU_u.wbu_in <> WBU_u.in
    EXU_u.mtvec := RFS_u.mtvec_out

    CLINT_u.mtime := RFS_u.mtime_out

    RFS_u.WriteRegPort := WBU_u.WriteRegPort
    RFS_u.CSRWritePort := WBU_u.CSRWritePort
    RFS_u.ExceptionPort := WBU_u.ExceptionPort
    IFU_u.AXI4_port <> AXI4Arbiter_u.master(0)
    LSU_u.AXI4_port <> CLINT_AXI4Router_u.in
    CLINT_AXI4Router_u.toSoC <> AXI4Arbiter_u.master(1)
    CLINT_AXI4Router_u.toCLINT <> CLINT_u.AXI4_port

    io.master <> AXI4Arbiter_u.slave

    RFS_u.mret_in := EXU_u.mret_out

    val intr_u = Module(new ysyx_26030092_intrUnit)
    intr_u.to_EXU <> EXU_u.intr
    intr_u.to_RFS <> RFS_u.intr

    PerfCounter("total_cycles") := true.B
}
