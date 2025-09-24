module ysyx_23060170_sram (
  // input
  clock,
  reset,
  Xbar_sram_ar_valid,
  Xbar_sram_ar_addr,
  Xbar_sram_ar_id,
  Xbar_sram_ar_len,
  Xbar_sram_ar_size,
  Xbar_sram_ar_burst,
  Xbar_sram_r_ready,
  Xbar_sram_aw_valid,
  Xbar_sram_aw_addr,
  Xbar_sram_aw_id,
  Xbar_sram_aw_len,
  Xbar_sram_aw_size,
  Xbar_sram_aw_burst,
  Xbar_sram_w_valid,
  Xbar_sram_w_data,
  Xbar_sram_w_strb,
  Xbar_sram_w_last,
  Xbar_sram_b_ready,
  // output
  sram_Xbar_ar_ready,
  sram_Xbar_r_valid,
  sram_Xbar_r_data,
  sram_Xbar_r_resp,
  sram_Xbar_r_last,
  sram_Xbar_r_id,
  sram_Xbar_aw_ready,
  sram_Xbar_w_ready,
  sram_Xbar_b_valid,
  sram_Xbar_b_resp,
  sram_Xbar_b_id
);

input            clock;
input            reset;
input            Xbar_sram_ar_valid;
input   [31 :0]  Xbar_sram_ar_addr;
input   [3  :0]  Xbar_sram_ar_id;
input   [7  :0]  Xbar_sram_ar_len;
input   [2  :0]  Xbar_sram_ar_size;
input   [1  :0]  Xbar_sram_ar_burst;
input            Xbar_sram_r_ready;
input            Xbar_sram_aw_valid;
input   [31 :0]  Xbar_sram_aw_addr;
input   [3  :0]  Xbar_sram_aw_id;
input   [7  :0]  Xbar_sram_aw_len;
input   [2  :0]  Xbar_sram_aw_size;
input   [1  :0]  Xbar_sram_aw_burst;
input            Xbar_sram_w_valid;
input   [31 :0]  Xbar_sram_w_data;
input   [3  :0]  Xbar_sram_w_strb;
input            Xbar_sram_w_last;
input            Xbar_sram_b_ready;
output           sram_Xbar_ar_ready;
output           sram_Xbar_r_valid;
output  [31 :0]  sram_Xbar_r_data;
output  [1  :0]  sram_Xbar_r_resp;
output           sram_Xbar_r_last;
output  [3  :0]  sram_Xbar_r_id;
output           sram_Xbar_aw_ready;
output           sram_Xbar_w_ready;
output           sram_Xbar_b_valid;
output  [1  :0]  sram_Xbar_b_resp;
output  [3  :0]  sram_Xbar_b_id;

reg              sram_Xbar_ar_ready ;
reg              sram_Xbar_r_valid ;
reg     [31 :0]  sram_Xbar_r_data ;
reg              sram_Xbar_aw_ready ;
reg              sram_Xbar_w_ready ;
reg              sram_Xbar_b_valid ;
reg              sram_aw_valid ;
reg              sram_w_valid ;
reg     [7  :0]  sram_burst_num ;
reg     [7  :0]  sram_burst_cnt ;

wire             Xbar_sram_ar_handshake ;
wire             sram_Xbar_r_handshake ;
wire             Xbar_sram_aw_handshake ;
wire             Xbar_sram_w_handshake ;
wire             sram_Xbar_b_handshake ;
wire    [31 :0]  pmem_read_addr ;

//======================================================
//                   unuse signal
//======================================================

assign sram_Xbar_r_resp = 2'd0;
assign sram_Xbar_r_last = (sram_burst_cnt == (sram_burst_num - 8'd1) ? 1'd1 : 1'd0) && sram_Xbar_r_valid;
assign sram_Xbar_r_id   = 4'd0;
assign sram_Xbar_b_resp = 2'd0;
assign sram_Xbar_b_id   = 4'd0;

//======================================================
//           ram interface of sys bus
//======================================================

// =============== AR CHANNEL ==========================
assign Xbar_sram_ar_handshake = Xbar_sram_ar_valid && sram_Xbar_ar_ready;

// --------------- control part ------------------------

always @(posedge clock) begin

  if (reset) begin
    sram_Xbar_ar_ready <= 1'd1;
  end
  else if (Xbar_sram_ar_handshake) begin
    sram_Xbar_ar_ready <= 1'd0;
  end
  else if (sram_Xbar_r_handshake) begin
    sram_Xbar_ar_ready <= 1'd1;
  end
  else begin
    sram_Xbar_ar_ready <= sram_Xbar_ar_ready;
  end

end

always @(posedge clock) begin

  if (reset) begin
    sram_burst_num <= 8'd0;
    sram_burst_cnt <= 8'd0;
  end
  else if (Xbar_sram_ar_handshake) begin
    sram_burst_num <= Xbar_sram_ar_len + 8'd1;
    sram_burst_cnt <= 8'd0;
  end
  else if (sram_Xbar_r_handshake) begin
    sram_burst_cnt <= sram_burst_cnt + 8'd1;
  end
  else begin
    sram_burst_cnt <= sram_burst_cnt;
  end

end

// =============== R CHANNEL ==========================
assign sram_Xbar_r_handshake = sram_Xbar_r_valid && Xbar_sram_r_ready;

// --------------- control part ------------------------

// =============== AW CHANNEL ==========================
assign Xbar_sram_aw_handshake = Xbar_sram_aw_valid && sram_Xbar_aw_ready;

// --------------- control part ------------------------

always @(posedge clock) begin

  if (reset) begin
    sram_Xbar_aw_ready <= 1'd1;
    sram_aw_valid     <= 1'd0;
  end
  else if (Xbar_sram_aw_handshake) begin
    sram_Xbar_aw_ready <= 1'd0;
    sram_aw_valid     <= 1'd1;
  end
  else if (sram_Xbar_b_handshake) begin
    sram_Xbar_aw_ready <= 1'd1;
    sram_aw_valid     <= 1'd0;
  end
  else begin
    sram_Xbar_aw_ready <= sram_Xbar_aw_ready;
    sram_aw_valid     <= sram_aw_valid;
  end

end

// =============== W CHANNEL ===========================
assign Xbar_sram_w_handshake = Xbar_sram_w_valid && sram_Xbar_w_ready;

// --------------- control part ------------------------

always @(posedge clock) begin

  if (reset) begin
    sram_Xbar_w_ready <= 1'd1;
    sram_w_valid     <= 1'd0;
  end
  else if (Xbar_sram_w_handshake) begin
    sram_Xbar_w_ready <= 1'd0;
    sram_w_valid     <= 1'd1;
  end
  else if (sram_Xbar_b_handshake) begin
    sram_Xbar_w_ready <= 1'd1;
    sram_w_valid     <= 1'd0;
  end
  else begin
    sram_Xbar_w_ready <= sram_Xbar_w_ready;
    sram_w_valid     <= sram_w_valid;
  end

end

// =============== B CHANNEL ===========================
assign sram_Xbar_b_handshake = sram_Xbar_b_valid && Xbar_sram_b_ready;


//-----------------------------------------------------------------
// iverilog/verilator
//-----------------------------------------------------------------
`ifdef __ICARUS__

parameter SRAM_SIZE = 2**28;
reg [7:0] ram [0:SRAM_SIZE-1];

initial begin
  `ifdef MEM_FILE
    $readmemh(`MEM_FILE, ram);
  `else
    $display("Error: No memory file path provided!");
    $finish;
  `endif
end

wire [31:0] ar_addr  ;
assign ar_addr = Xbar_sram_ar_addr == 32'h30000000 || Xbar_sram_ar_addr == 32'h30000004
                 ? Xbar_sram_ar_addr : Xbar_sram_ar_addr - 32'h80000000;
assign pmem_read_addr = Xbar_sram_ar_handshake ? {ar_addr[31:2], 2'b0} : {ar_addr[31:2], 2'b0} + {24'd0, sram_burst_cnt << 2};

function [31:0] pmem_read;
  input [31:0] raddr;
  begin
    pmem_read = {ram[raddr+3], ram[raddr+2], ram[raddr+1], ram[raddr]};
  end
endfunction

task pmem_write;
  input [31:0] waddr;
  input [7:0]  wmask;
  input [31:0] wdata;
  integer i;
  begin
    for (i=0; i<4; i=i+1) begin
      if (wmask[i]) begin
        ram[waddr-32'h80000000+i] <= wdata[i*8 +: 8];
      end
    end
  end
endtask

`endif
`ifdef ysyx_23060170_VERILATOR

assign pmem_read_addr = Xbar_sram_ar_handshake ? {Xbar_sram_ar_addr[31:2], 2'b0} : 
                                                 {Xbar_sram_ar_addr[31:2], 2'b0} + {24'd0, sram_burst_cnt << 2};

import "DPI-C" function int pmem_read(
  input  int  raddr
);

import "DPI-C" function void pmem_write(
  input int  waddr,
  input byte wmask,
  input int  wdata
);

`endif

//-----------------------------------------------------------------
// Read/Write
//-----------------------------------------------------------------
// read
always @(posedge clock) begin
  if (reset) begin
    sram_Xbar_r_data  <= 32'd0;
    sram_Xbar_r_valid <=  1'd0;
  end
  else if (sram_Xbar_r_handshake) begin
    sram_Xbar_r_valid <=  1'd0;
  end
  else if (Xbar_sram_ar_handshake || sram_burst_cnt != sram_burst_num) begin
    `ifdef __ICARUS__
    if (pmem_read_addr == 32'h30000000) begin
      sram_Xbar_r_data  <= 32'h800002B7;
    end
    else if (pmem_read_addr == 32'h30000004) begin
      sram_Xbar_r_data  <= 32'h000280E7;
    end else begin
      sram_Xbar_r_data  <= pmem_read(pmem_read_addr);
    end
    `else
    sram_Xbar_r_data  <= pmem_read(pmem_read_addr);
    `endif
    sram_Xbar_r_valid <=  1'd1;
  end
  else begin
    sram_Xbar_r_data  <= sram_Xbar_r_data;
    sram_Xbar_r_valid <= sram_Xbar_r_valid;
  end
end

// write
always @(posedge clock) begin
  if (reset) begin
    sram_Xbar_b_valid <= 1'd0;
  end
  else if (sram_Xbar_b_handshake) begin
    sram_Xbar_b_valid <= 1'd0;
  end
  else if ( (Xbar_sram_aw_handshake && Xbar_sram_w_handshake)
             || (sram_aw_valid && sram_w_valid) ) begin
    pmem_write({Xbar_sram_aw_addr[31:2], 2'b0}, { 4'd0, Xbar_sram_w_strb }, Xbar_sram_w_data);
    sram_Xbar_b_valid <= 1'd1;
  end
  else begin
    sram_Xbar_b_valid <= sram_Xbar_b_valid;
  end
end

endmodule
