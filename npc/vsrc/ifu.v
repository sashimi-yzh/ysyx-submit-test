//`define LFSR_SIM

module ysyx_24110012_ifu(
    input wire clk,
    input wire reset,
    input wire cycle_done,


    output reg [31:0] ifu_idu_pc,
    output reg [31:0] ifu_idu_inst,
    output reg ifu_idu_cycle_done,

    output wire ifu_idu_valid,
    input wire idu_ifu_ready,

    input wire [31:0] wbu_ifu_npc,
    input wire wbu_redirect,
    input wire flush,

    // AR
    output reg [31:0] araddr,
    output reg arvalid,
    output reg [2:0] arsize,
    input wire arready,
    // R
    input wire [31:0] rdata,
    input wire rvalid,
    output reg rready,

    // AW
    output reg [31:0] awaddr,
    output reg awvalid,
    output reg [2:0] awsize,
    input wire awready,

    // W
    output reg [31:0] wdata,
    output reg [3:0] wstrb,
    output reg wvalid,
    input wire wready,

    // B
    input wire [1:0] bresp,
    input wire bvalid,
    output wire bready
);

parameter RESET_PC_MROM = 32'h20000000;
parameter RESET_PC_FLASH = 32'h30000000;
parameter RESET_BASE = 32'h80000000;
`ifdef NPC
parameter RESET_PC = RESET_BASE; // Initial PC value
`else
parameter RESET_PC = RESET_PC_FLASH; // Initial PC value
`endif
reg inst_fetch;
reg [31:0] req_pc;

assign awaddr = 32'b0;
assign awvalid = 1'b0;
assign wdata = 32'b0;
assign wstrb = 4'b0;
assign wvalid = 1'b0;
assign bready = 1'b0;
assign awsize = 3'b010;
assign arsize = 3'b010;

reg flush_inflight;
reg [31:0] inflight_pc;

`ifndef SYNTHESIS
assert property (@(posedge clk) awready == 1'b0) else
  $error("AWR should be 0 in PC update module");
`endif

`ifndef LFSR_SIM

always @(posedge clk) begin
  if (reset) begin
    ifu_idu_inst <= 32'b0;
    ifu_idu_valid <= 1'b0;
    arvalid <= 1'b0;
    rready <= 1'b0;
  end else begin
    if (wbu_redirect && !arvalid && !rready && !flush_inflight) begin
        ifu_idu_valid <= 1'b0;
        ifu_idu_pc    <= 32'b0;
        ifu_idu_inst  <= 32'b0;
        araddr        <= wbu_ifu_npc;
        arvalid       <= 1'b1;
    end else if (flush && !arvalid && !rready && !flush_inflight) begin
        ifu_idu_valid <= 1'b0;
        ifu_idu_pc    <= 32'b0;
        ifu_idu_inst  <= 32'b0;
        araddr        <= req_pc;
        arvalid       <= 1'b1;
    end else if (inst_fetch && !arvalid && !rready) begin
       araddr <= req_pc;
       arvalid <= 1'b1;
    end
    if (arvalid && arready) begin
        inflight_pc <= araddr;
        rready      <= 1'b1;
        arvalid     <= 1'b0;
    end
    if (rvalid && rready) begin
      araddr <= 32'b0;
      rready <= 1'b0;
      if (flush_inflight || wbu_redirect || flush) begin
          flush_inflight <= 1'b0;
          ifu_idu_valid  <= 1'b0;
          ifu_idu_pc     <= 32'b0;
          ifu_idu_inst   <= 32'b0;
          araddr         <= wbu_redirect ? wbu_ifu_npc : req_pc;
          arvalid        <= 1'b1;
      end else begin
          ifu_idu_valid <= 1'b1;
          ifu_idu_pc <= inflight_pc;
          ifu_idu_inst <= rdata;
      end
    end
    if (idu_ifu_ready && ifu_idu_valid) begin
        ifu_idu_valid <= 1'b0;
    end
  end
end

`else
reg [4:0] arvalid_lfsr = 5'b00101;
reg [4:0] arvalid_delay_cnt;
reg arvalid_start;

always @(posedge clk) begin
    ifu_idu_inst <= 32'b0;
    ifu_idu_valid <= 1'b0;
    if (inst_fetch) begin
       araddr <= ifu_idu_pc;
       if (arvalid_start == 1'b0) begin
       arvalid_lfsr <= {arvalid_lfsr[3:0], arvalid_lfsr[2] ^ arvalid_lfsr[0]};
       end
       arvalid_start <= 1'b1;
       arvalid_delay_cnt <= 5'b0;
    end
    if (arvalid_start) begin
      arvalid_delay_cnt <= arvalid_delay_cnt + 1'b1;
      if (arvalid_delay_cnt == arvalid_lfsr) begin
        arvalid <= 1'b1;
        arvalid_start <= 1'b0;
        arvalid_delay_cnt <= 5'b0;
      end
    end
    if (arvalid && arready) begin
        rready <= 1'b1;
        arvalid <= 1'b0;
    end
    if (rvalid && rready) begin
        araddr <= 32'b0;
        ifu_idu_valid <= 1'b1;
        ifu_idu_inst <= rdata;
        rready <= 1'b0;
    end
end
`endif

  always @(posedge clk) begin
    if (reset) begin
      req_pc     <= RESET_PC;
      ifu_idu_pc <= RESET_PC;
      inst_fetch <= 1'b1;
    end else begin
      if (wbu_redirect) begin
        req_pc <= wbu_ifu_npc;
        inst_fetch <= 1'b1;
        if (arvalid || rready) begin
          flush_inflight <= 1'b1;
        end else begin
          flush_inflight <= 1'b0;
        end
      end else if (flush) begin
        inst_fetch <= 1'b1;
        if (arvalid || rready) begin
          flush_inflight <= 1'b1;
        end else begin
          flush_inflight <= 1'b0;
        end
      end else if (ifu_idu_valid && idu_ifu_ready) begin
        req_pc     <= ifu_idu_pc + 4;
        inst_fetch <= 1'b1;
      end else begin
        inst_fetch <= 1'b0;
      end
    end
  end

`ifndef SYNTHESIS
// Function to get PC value from C++
export "DPI-C" function get_pc_npc;
function int get_pc_npc();
    return ifu_idu_pc;
endfunction
`endif

endmodule
