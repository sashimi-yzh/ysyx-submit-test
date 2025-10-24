package npc.core.wbu

import chisel3._
import chisel3.util._
import npc.common.Config._
import npc.common._
import npc.common.Instructions._
import npc.core.exu._
/*
              ___ _____ _   _ _____ ____  ____ ___ ____
             / _ \_   _| | | | ____|  _ \/ ___|_ _/ ___|
            | | | || | | |_| |  _| | |_) \___ \| | |  _
            | |_| || | |  _  | |___|  _ < ___) | | |_| |
             \___/ |_| |_| |_|_____|_| \_\____/___\____|
*/
class WBUIO extends Bundle {
    val gpr_we = Output(Bool())
    val gpr_waddr = Output(UInt(ADDR_LEN.W))
    val gpr_wdata = Output(UInt(WORD_LEN.W))
}
class WBUIO_FOR extends Bundle {
    val gpr_we = Output(Bool())
    val gpr_wdata = Output(UInt(WORD_LEN.W))
    val gpr_waddr = Output(UInt(ADDR_LEN.W))
}
/*
             ____ ___ ____  _____ ____ ___ ____
            |  _ \_ _|  _ \| ____/ ___|_ _/ ___|
            | |_) | || |_) |  _| \___ \| | |  _
            |  __/| ||  __/| |___ ___) | | |_| |
            |_|  |___|_|   |_____|____/___\____|
*/
class WBUIO_pipe_out extends Bundle{
}
class WBUIO_pipe extends Bundle {
    val in = Flipped(Decoupled(new EXUIO_pipe_out))
    val out = Decoupled(new WBUIO_pipe_out)
}
/*
            __        ______  _   _
            \ \      / / __ )| | | |
             \ \ /\ / /|  _ \| | | |
              \ V  V / | |_) | |_| |
               \_/\_/  |____/ \___/
*/
class WBU extends Module {
    val io = IO(new WBUIO)
    val io_pipe = IO(new WBUIO_pipe)
    val io_for = IO(new WBUIO_FOR)

    dontTouch(io_pipe)

    io_pipe.in.ready := true.B
    io_pipe.out.valid := true.B
    io.gpr_we := io_pipe.in.bits.exe2wb_gpr_we
    io.gpr_waddr := io_pipe.in.bits.exe2wb_gpr_waddr
    io.gpr_wdata := io_pipe.in.bits.exe2wb_gpr_wdata

    io_for.gpr_we := io_pipe.in.bits.exe2wb_gpr_we
    io_for.gpr_waddr := io_pipe.in.bits.exe2wb_gpr_waddr
    io_for.gpr_wdata := io_pipe.in.bits.exe2wb_gpr_wdata


    if(DIFFTEST){
        val diffvalid = RegNext(io_pipe.in.valid)
        dontTouch(diffvalid)
    }
}

