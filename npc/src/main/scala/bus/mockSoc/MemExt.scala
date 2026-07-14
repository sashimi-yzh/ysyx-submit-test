package top
import chisel3._
import chisel3.util._


class MemExt extends Module {
  val io = IO(new Bundle {
    val axi = Flipped(new AXI4IO)
  })
  DriveZeroSinks(io.axi)

  val mem = Module(new MemHelper())
  mem.io.clock := clock
  mem.io.reset := reset
  mem.io.wen   := false.B
  mem.io.ren   := false.B

  object State extends ChiselEnum {
    val sIdle, sWait, sDone = Value
  }
  val waddrReg = RegInit(0.U(32.W))
  val wdataReg = RegInit(0.U(32.W))
  val wmaskReg = RegInit(0.U(4.W))

  val wstate = RegInit(State.sIdle)
  val bstate = RegInit(State.sIdle)

  switch(wstate) {
    is(State.sIdle) {
      io.axi.w.ready := true.B
      when(io.axi.w.valid) {
        wstate   := State.sDone
        wdataReg := io.axi.w.data
        wmaskReg := io.axi.w.strb
      }
    }
    is(State.sDone) {
      io.axi.w.ready := false.B
      when(io.axi.b.ready && io.axi.b.valid) {
        wstate := State.sIdle
      }
    }
  }

  switch(bstate) {
    is(State.sIdle) {
      io.axi.aw.ready := true.B
      when(io.axi.aw.valid) {
        bstate   := State.sWait
        waddrReg := io.axi.aw.addr
      }
    }
    is(State.sWait) {
      when(wstate === State.sDone) {
        mem.io.wen := true.B
        bstate := State.sDone
      }
    }
    is(State.sDone) {
      io.axi.b.valid := true.B
      when(io.axi.b.ready) {
        bstate := State.sIdle
      }
    }
  }

  object Rstate extends ChiselEnum {
    val sIdle, sRead, sOut = Value
  }
  val rstate = RegInit(Rstate.sIdle)
  val raddrReg   = RegInit(0.U(32.W))
  val arburstReg = RegInit(0.U(2.W))
  val arlenReg   = RegInit(0.U(8.W))
  val rdataReg   = RegInit(0.U(32.W))
  val burstCnt   = RegInit(0.U(8.W))
  switch(rstate) {
    is(Rstate.sIdle) {
      io.axi.ar.ready := true.B
      when(io.axi.ar.valid) {
        rstate     := Rstate.sRead
        raddrReg   := io.axi.ar.addr
        arburstReg := io.axi.ar.burst
        arlenReg   := io.axi.ar.len
      }
    }
    is(Rstate.sRead) {
      mem.io.ren := true.B
      rstate     := Rstate.sOut
      
      // 拦截 CPU 对 0x30000000 的复位取指，注入跳转到 0x80000000 的指令
      when(raddrReg === "h30000000".U) {
        rdataReg := "h800002b7".U // 指令: lui t0, 0x80000
      }.elsewhen(raddrReg === "h30000004".U) {
        rdataReg := "h00028067".U // 指令: jalr x0, 0(t0) (即 jr t0)
      }.otherwise {
        rdataReg := mem.io.rdata  // 其他地址正常读取 MemHelper
      }

      raddrReg   := raddrReg + 4.U
      burstCnt   := burstCnt + 1.U
    }
    is(Rstate.sOut) {
      io.axi.r.valid := true.B
      io.axi.r.data  := rdataReg
      when(io.axi.r.ready) {
        when(burstCnt === arlenReg + 1.U) {
          rstate := Rstate.sIdle
          io.axi.r.last := true.B
          burstCnt := 0.U
        }.otherwise {
          rstate := Rstate.sRead
        }
      }
    }
  }

  mem.io.waddr := waddrReg
  mem.io.wdata := wdataReg
  mem.io.wstrb := wmaskReg
  mem.io.raddr := raddrReg
}

class MemHelper extends ExtModule {
  val io = IO(new Bundle {
    val clock = Input(Clock())
    val reset = Input(Bool())
    val raddr = Input(UInt(32.W))
    val waddr = Input(UInt(32.W))
    val ren   = Input(Bool())
    val rdata = Output(UInt(32.W))
    val wdata = Input(UInt(32.W))
    val wen   = Input(Bool())
    val wstrb = Input(UInt(4.W))
  })

  setInline(
    "MemHelper.v",
    """
    module MemHelper(
      input         io_clock,
      input         io_reset,
      input  [31:0] io_raddr,
      input  [31:0] io_waddr,
      input         io_ren,
      output reg [31:0] io_rdata,
      input  [31:0] io_wdata,
      input         io_wen,
      input  [3:0]  io_wstrb
    );

`ifdef __ICARUS__
      
      reg [31:0] ram [0:32767];

      initial begin
        $readmemh("image.hex", ram);
      end

      wire [31:0] r_idx = (io_raddr - 32'h8000_0000) >> 2;
      wire [31:0] w_idx = (io_waddr - 32'h8000_0000) >> 2;

      wire r_out_of_bounds = (r_idx > 32'd32767);
      wire w_out_of_bounds = (w_idx > 32'd32767);

      wire [31:0] old_data = w_out_of_bounds ? 32'h0 : ram[w_idx];
      
      wire [31:0] new_data;
      assign new_data[7:0]   = io_wstrb[0] ? io_wdata[7:0]   : old_data[7:0];
      assign new_data[15:8]  = io_wstrb[1] ? io_wdata[15:8]  : old_data[15:8];
      assign new_data[23:16] = io_wstrb[2] ? io_wdata[23:16] : old_data[23:16];
      assign new_data[31:24] = io_wstrb[3] ? io_wdata[31:24] : old_data[31:24];

      always @(posedge io_clock) begin
        if (io_wen && !w_out_of_bounds) begin
          ram[w_idx] <= new_data;
        end
      end

      always @(*) begin
        if (io_ren) begin
          if (r_out_of_bounds)
            io_rdata = 32'hdeadbeef;
          else
            io_rdata = ram[r_idx];
        end else begin
          io_rdata = 32'h0;
        end
      end
`else
      import "DPI-C" function int mem_read(input int addr);
      import "DPI-C" function void mem_write(input int addr, input int data, input byte wmask);

      always @(posedge io_clock) begin
        if(io_wen)
          mem_write(io_waddr, io_wdata, {4'b0, io_wstrb});
      end

      always @(*) begin
        if(io_ren)
          io_rdata = mem_read(io_raddr);
        else
          io_rdata = 32'h0;
      end
`endif

    endmodule
    """.stripMargin
  )
}