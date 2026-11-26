module IFU(
  input clk,
  input rst,
  input commit,
  input [31:0] pc_next,

  output ifu_arvalid,
  input  ifu_arready,
  output [31:0] ifu_araddr,

  input  ifu_rvalid,
  output ifu_rready,
  input  [31:0] ifu_rdata,

  output reg [31:0] pc,
  output [31:0] inst,
  output ifu_valid
);

  localparam IDLE = 1'b0, WAIT = 1'b1;

  reg state;
  reg [31:0] inst_reg;
  reg inst_valid;

  assign ifu_arvalid = !rst && (state == IDLE);
  assign ifu_araddr = pc;

  assign ifu_rready = !rst && (state == WAIT) && !inst_valid;
  assign inst = (ifu_rvalid && ifu_rready) ? ifu_rdata : inst_reg;
  assign ifu_valid = !rst && (inst_valid || (ifu_rvalid && ifu_rready));

  always @(posedge clk) begin
    if (rst) begin
      state <= IDLE;
`ifdef SOC_MODE
      pc <= 32'h30000000;
`else
      pc <= 32'h80000000;
`endif
      inst_reg <= 32'h00000013;
      inst_valid <= 1'b0;
    end else begin
      case (state)
        IDLE: begin
          if (ifu_arvalid && ifu_arready) begin
            state <= WAIT;
          end
        end
        WAIT: begin
          if (ifu_rvalid && ifu_rready) begin
            inst_reg <= ifu_rdata;
            inst_valid <= 1'b1;
          end
          if (commit) begin
            pc <= pc_next;
            state <= IDLE;
            inst_valid <= 1'b0;
          end
        end
        default: state <= IDLE;
      endcase
    end
  end

endmodule
