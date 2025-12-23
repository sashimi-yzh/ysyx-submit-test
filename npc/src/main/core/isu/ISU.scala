package npc.core.isu

import chisel3._
import chisel3.util._
import npc.common.Config._
import npc.common._
import npc.common.Instructions._
import npc.core.idu._
import npc.core.exu._
import npc.core.wbu._
import npc.core.difftest._
/*
              ___ _____ _   _ _____ ____  ____ ___ ____
             / _ \_   _| | | | ____|  _ \/ ___|_ _/ ___|
            | | | || | | |_| |  _| | |_) \___ \| | |  _
            | |_| || | |  _  | |___|  _ < ___) | | |_| |
             \___/ |_| |_| |_|_____|_| \_\____/___\____|
*/
class ISUIO extends Bundle{
    val gpr_we = Input(Bool())
    val gpr_wdata = Input(UInt(WORD_LEN.W))
    val gpr_waddr = Input(UInt(ADDR_LEN.W))
}
class FLUSHIO extends Bundle{
    val flush_flg = Input(Bool())
}
/*
             ____ ___ ____  _____ ____ ___ ____
            |  _ \_ _|  _ \| ____/ ___|_ _/ ___|
            | |_) | || |_) |  _| \___ \| | |  _
            |  __/| ||  __/| |___ ___) | | |_| |
            |_|  |___|_|   |_____|____/___\____|
*/
class ISUIO_pipe_out extends Bundle{
    val is2exe_processunit = Output(UInt(ProcessUnit.ProcessUnit_Width.W))
    val is2exe_processtpe = Output(UInt(ProcessTpe.ProcessTpe_Width.W))
    val is2exe_bjtpe = Output(UInt(BJTpe.BJTpe_Width.W))
    val is2exe_rfwe = Output(UInt(RFwe.RFwe_Width.W))
    val is2exe_rd_addr = Output(UInt(ADDR_LEN.W))
    val is2exe_ch1 = Output(UInt(WORD_LEN.W))
    val is2exe_ch2 = Output(UInt(WORD_LEN.W))
    val is2exe_ch3 = Output(UInt(WORD_LEN.W))
    val diff = if(DIFFTEST) Some(new DIFFIO) else None
}
class ISUIO_pipe extends Bundle {
    val in = Flipped(Decoupled(new IDUIO_pipe_out))
    val out = Decoupled(new ISUIO_pipe_out)
}
/*
             ___ ____  _   _
            |_ _/ ___|| | | |
             | |\___ \| | | |
             | | ___) | |_| |
            |___|____/ \___/
*/
class ISU extends Module{
    val io_pipe = IO(new ISUIO_pipe)
    val io = IO(new ISUIO)
    val io_for_ex = IO(Flipped(new EXUIO_FOR))
    val io_for_wb = IO(Flipped(new WBUIO_FOR))
    val io_flush = IO(new FLUSHIO)
/*
              ____ ____  ____
             / ___|  _ \|  _ \
            | |  _| |_) | |_) |
            | |_| |  __/|  _ <
             \____|_|   |_| \_\
*/
    val gpr = new GPR
    val rs1_addr = io_pipe.in.bits.id2is_rs1_addr
    val rs2_addr = io_pipe.in.bits.id2is_rs2_addr
    val rs1_data = gpr.read(rs1_addr)
    val rs2_data = gpr.read(rs2_addr)
    dontTouch(rs1_data)
    dontTouch(rs2_data)
    when(io.gpr_we === RFwe.RFwe_y && io.gpr_waddr =/= 0.U){
        gpr.write(io.gpr_waddr, io.gpr_wdata)
    }
/*
             ____    _  _____  _
            |  _ \  / \|_   _|/ \
            | | | |/ _ \ | | / _ \
            | |_| / ___ \| |/ ___ \
            |____/_/__ \_\_/_/   \_\  ___    ____  ____ ___ _   _  ____
            |  ___/ _ \|  _ \ \      / / \  |  _ \|  _ \_ _| \ | |/ ___|
            | |_ | | | | |_) \ \ /\ / / _ \ | |_) | | | | ||  \| | |  _
            |  _|| |_| |  _ < \ V  V / ___ \|  _ <| |_| | || |\  | |_| |
            |_|   \___/|_| \_\ \_/\_/_/   \_\_| \_\____/___|_| \_|\____|
*/
    def isDepend(addr: UInt, rd_addr: UInt, rfwe: Bool): Bool = (addr =/= 0.U) && (addr === rd_addr) && rfwe
    val validForEX = io_for_ex.valid && (io_for_ex.gpr_we === RFwe.RFwe_y)
    val dontForEX = io_for_ex.processunit === ProcessUnit.CSR
    val rs1DependEX = isDepend(rs1_addr, io_for_ex.gpr_waddr, validForEX)
    val rs2DependEX = isDepend(rs2_addr, io_for_ex.gpr_waddr, validForEX)

    val validForWB = io_for_wb.gpr_we === RFwe.RFwe_y
    val rs1DependWB = isDepend(rs1_addr, io_for_wb.gpr_waddr, validForWB)
    val rs2DependWB = isDepend(rs2_addr, io_for_wb.gpr_waddr, validForWB)

    val rs1ForEX = rs1DependEX && ~dontForEX
    val rs2ForEX = rs2DependEX && ~dontForEX
    val rs1ForWB = rs1DependWB && Mux(dontForEX, ~rs1DependEX, true.B)
    val rs2ForWB = rs2DependWB && Mux(dontForEX, ~rs2DependEX, true.B)

    val sb = new ScoreBoard
    val ch1Ready = ~sb.isBusy(rs1_addr) || rs1ForEX || rs1ForWB || io_pipe.in.bits.id2is_ch1tpe =/= CH1Tpe.CH1Tpe_RS1
    val ch2Ready = ~sb.isBusy(rs2_addr) || rs2ForEX || rs2ForWB || io_pipe.in.bits.id2is_ch2tpe =/= CH2Tpe.CH2Tpe_RS2
    val useCh3 = io_pipe.in.bits.id2is_bjtpe.orR || io_pipe.in.bits.id2is_processunit === ProcessUnit.LSU
    val ch3Ready = ~useCh3 || io_pipe.in.bits.id2is_bjtpe.orR || (~sb.isBusy(rs1_addr) || rs1ForEX || rs1ForWB)

    val isudone = ch1Ready || ch2Ready || ch3Ready
    dontTouch(isudone)

    val wbClearMask = Mux(io_for_wb.gpr_we === RFwe.RFwe_y && !isDepend(io_for_wb.gpr_waddr, io_for_ex.gpr_waddr, io_for_ex.gpr_we === RFwe.RFwe_y), sb.mask(io_for_wb.gpr_waddr), 0.U(GPR_NUM.W))
    val isuFireSetMask = Mux(io_pipe.out.fire, sb.mask(io_pipe.in.bits.id2is_rd_addr), 0.U)
    dontTouch(wbClearMask)
    dontTouch(isuFireSetMask)
    when (io_flush.flush_flg) { sb.update(0.U, Fill(GPR_NUM, 1.U(1.W))) }
    .otherwise { sb.update(isuFireSetMask, wbClearMask) }








    val ch1 = Mux1H(Seq(
        (io_pipe.in.bits.id2is_ch1tpe === CH1Tpe.CH1Tpe_PC) -> io_pipe.in.bits.id2is_reg_pc,
        (io_pipe.in.bits.id2is_ch1tpe === CH1Tpe.CH1Tpe_RS1 && rs1ForEX) -> io_for_ex.gpr_wdata,
        (io_pipe.in.bits.id2is_ch1tpe === CH1Tpe.CH1Tpe_RS1 && rs1ForWB) -> io_for_wb.gpr_wdata,
        (io_pipe.in.bits.id2is_ch1tpe === CH1Tpe.CH1Tpe_RS1 && ~(rs1ForEX || rs1ForWB)) -> rs1_data
    ))
    val ch2 = Mux1H(Seq(
        (io_pipe.in.bits.id2is_ch2tpe === CH2Tpe.CH2Tpe_IMM) -> io_pipe.in.bits.id2is_imm,
        (io_pipe.in.bits.id2is_ch2tpe === CH2Tpe.CH2Tpe_CSR_ADDR) -> io_pipe.in.bits.id2is_csr_addr,
        (io_pipe.in.bits.id2is_ch2tpe === CH2Tpe.CH2Tpe_RS2 && rs2ForEX) -> io_for_ex.gpr_wdata,
        (io_pipe.in.bits.id2is_ch2tpe === CH2Tpe.CH2Tpe_RS2 && rs2ForWB) -> io_for_wb.gpr_wdata,
        (io_pipe.in.bits.id2is_ch2tpe === CH2Tpe.CH2Tpe_RS2 && ~(rs2ForEX || rs2ForWB)) -> rs2_data,
        (io_pipe.in.bits.id2is_ch2tpe === CH2Tpe.CH2Tpe_4) -> 4.U,
    ))
    val ch3_rs1 = Mux1H(Seq(
        (rs1ForEX) -> io_for_ex.gpr_wdata,
        (rs1ForWB) -> io_for_wb.gpr_wdata,
        (~(rs1ForEX || rs1ForWB)) -> rs1_data
    ))
    val ch3 = Mux(io_pipe.in.bits.id2is_bjtpe.orR && io_pipe.in.bits.id2is_bjtpe =/= BJTpe.BJ_JR, io_pipe.in.bits.id2is_reg_pc, ch3_rs1) +& io_pipe.in.bits.id2is_imm

    io_pipe.out.bits.is2exe_processunit := io_pipe.in.bits.id2is_processunit
    io_pipe.out.bits.is2exe_processtpe := io_pipe.in.bits.id2is_processtpe
    io_pipe.out.bits.is2exe_bjtpe := io_pipe.in.bits.id2is_bjtpe
    io_pipe.out.bits.is2exe_rfwe := io_pipe.in.bits.id2is_rfwe
    io_pipe.out.bits.is2exe_rd_addr := io_pipe.in.bits.id2is_rd_addr
    io_pipe.out.bits.is2exe_ch1 := ch1
    io_pipe.out.bits.is2exe_ch2 := ch2
    io_pipe.out.bits.is2exe_ch3 := ch3







/*
             _   _    _    _   _ ____  ____  _   _    _    _  _______
            | | | |  / \  | \ | |  _ \/ ___|| | | |  / \  | |/ / ____|
            | |_| | / _ \ |  \| | | | \___ \| |_| | / _ \ | ' /|  _|
            |  _  |/ ___ \| |\  | |_| |___) |  _  |/ ___ \| . \| |___
            |_| |_/_/   \_\_| \_|____/|____/|_| |_/_/   \_\_|\_\_____|
*/
    //handshake between modules
    val in_ready = RegInit(false.B)
    val out_valid = RegInit(false.B)
    io_pipe.in.ready := in_ready
    io_pipe.out.valid := out_valid && ~io_flush.flush_flg

    val s_BeforePreFire :: s_AfterPreFire :: Nil = Enum(2)
    val c_state = RegInit(s_BeforePreFire)
    val n_state = WireDefault(c_state)
    dontTouch(n_state)

    c_state := n_state//first phase

    when(io_flush.flush_flg){
        n_state := s_BeforePreFire
    }.otherwise{
        n_state := MuxLookup(c_state, s_BeforePreFire)(Seq(//second phase
            s_BeforePreFire  ->  Mux(io_pipe.in.fire, s_AfterPreFire, s_BeforePreFire),
            s_AfterPreFire   ->  Mux(io_pipe.out.fire, s_BeforePreFire, s_AfterPreFire)
        ))
    }

    switch(n_state){//third phase
        is(s_BeforePreFire){
            in_ready := true.B
            out_valid := false.B
        }
        is(s_AfterPreFire){
            in_ready := false.B
            out_valid := true.B && isudone && ~io_flush.flush_flg
        }
    }


    if(DIFFTEST){
        io_pipe.out.bits.diff.get.pc := io_pipe.in.bits.diff.get.pc
        io_pipe.out.bits.diff.get.inst := io_pipe.in.bits.diff.get.inst
    }

}

