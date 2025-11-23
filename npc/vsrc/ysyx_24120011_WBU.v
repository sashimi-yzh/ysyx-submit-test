module ysyx_24120011_WBU(
    //input clk,
    //input rst,
    //数据
    //input  [31:0] i_r_mem_data,
    //input  [2:0]  i_rd_ctrl,
    //input  [2:0]  i_csr_ctrl,
    //input  [31:0] i_pc,
    //input  [31:0] i_src1,
    //input  [31:0] i_r_csr_data,
    //input  [31:0] i_imm,
    input  [3:0]  i_rd,
    input  [11:0] i_w_csr_addr,
    //input  [31:0] i_ALU_result,

    input [31:0] i_rd_data,
    input        i_rd_data_en,
    input [31:0] i_w_csr_data,
    input i_w_csr_en,
    input i_w_csr_ecall,
    //写GPR
    output [3:0]   o_rd,
    output [31:0]  o_rd_data,
    output         o_rd_en,
    //写CSR
    output [11:0]  o_w_csr_addr,
    output [31:0]  o_w_csr_data,
    output         o_w_csr_en,
    output         o_w_csr_ecall,
    //握手
    input  i_MEM_valid,
    output o_WBU_ready

    //output [2:0] o_rd_ctrl
);

// reg [31:0]  rd_data;
// reg [31:0]  w_csr_data;

// assign o_rd = i_rd;
// assign o_rd_data = rd_data;
// assign o_rd_en = i_MEM_valid ? (i_rd_ctrl == 3'd4 ? 1'b0 : 1'b1) : 1'b0;
// assign o_w_csr_addr = i_w_csr_addr;
// assign o_w_csr_data = w_csr_data;
// assign o_w_csr_en = i_MEM_valid ? (i_csr_ctrl[1:0] == 2'd0 ? 1'b0 : 1'b1) : 1'b0;
// assign o_w_csr_ecall = i_MEM_valid ? (i_csr_ctrl[2] == 1'd0 ? 1'b0 : 1'b1) : 1'b0;


assign o_rd = i_rd;
assign o_rd_data = i_rd_data;
assign o_rd_en = i_rd_data_en;
assign o_w_csr_addr = i_w_csr_addr;
assign o_w_csr_data = i_w_csr_data;
assign o_w_csr_en = i_w_csr_en;
assign o_w_csr_ecall = i_w_csr_ecall;

assign o_WBU_ready = 1'b1;
//assign o_rd_ctrl   = i_rd_ctrl;

// always@(*)begin
//     case(i_rd_ctrl)
//         3'd0: rd_data = i_pc + 32'd4;
//         3'd1: rd_data = i_pc + i_imm;
//         3'd2: rd_data = i_ALU_result;
//         3'd3: rd_data = i_imm;
//         3'd4: rd_data = 32'h0000_0000;
//         3'd5: rd_data = i_r_mem_data;
//         3'd6: rd_data = i_r_csr_data;
//         default: rd_data = 32'h0000_0000;
//     endcase
// end
// always@(*)begin
//     case(i_csr_ctrl[1:0])
//         //2'd0:    w_csr_data = 32'b0;
//         2'd1:    w_csr_data = i_src1;
//         2'd2:    w_csr_data = i_ALU_result;
//         2'd3:    w_csr_data = i_pc;
//         default: w_csr_data = 32'b0;
//     endcase
// end


// parameter ysyx_24120011_WBU_IDLE      = 1'b0;
// parameter ysyx_24120011_WBU_WORKING   = 1'b1;

// reg  [31:0] r_mem_data;
// reg  [2:0]  rd_ctrl;
// reg  [2:0]  csr_ctrl;
// reg  [31:0] pc;
// reg  [31:0] src1;
// reg  [31:0] r_csr_data;
// reg  [31:0] imm;
// reg  [3:0]  rd;
// reg  [11:0] w_csr_addr;
// reg  [31:0] ALU_result;

// reg state;
// reg next_state;

// assign o_WBU_ready  = (state == ysyx_24120011_WBU_IDLE) ? 1'b1 : 1'b0;

// //指令锁存
// always @(posedge clk) begin
//     if(rst) begin
//         r_mem_data <= 'd0;
//         rd_ctrl    <= 'd0;
//         csr_ctrl   <= 'd0;
//         pc         <= 'd0;
//         src1       <= 'd0;
//         r_csr_data <= 'd0;
//         imm        <= 'd0;
//         rd         <= 'd0;
//         w_csr_addr <= 'd0;
//         ALU_result <= 'd0;
//     end
//     else begin
//         //输入握手
//         if(i_MEM_valid && o_WBU_ready) begin
//             r_mem_data <= i_r_mem_data;
//             rd_ctrl    <= i_rd_ctrl;
//             csr_ctrl   <= i_csr_ctrl;
//             pc         <= i_pc;
//             src1       <= i_src1;
//             r_csr_data <= i_r_csr_data;
//             imm        <= i_imm;
//             rd         <= i_rd;
//             w_csr_addr <= i_w_csr_addr;
//             ALU_result <= i_ALU_result;
//         end
//     end
// end

// // always @(*) begin
// //             r_mem_data = i_r_mem_data;
// //             rd_ctrl    = i_rd_ctrl;
// //             csr_ctrl   = i_csr_ctrl;
// //             pc         = i_pc;
// //             src1       = i_src1;
// //             r_csr_data = i_r_csr_data;
// //             imm        = i_imm;
// //             rd         = i_rd;
// //             w_csr_addr = i_w_csr_addr;
// //             ALU_result = i_ALU_result;
// // end

// //状态机跳转
// always@(*)begin
//     case(state)
//         ysyx_24120011_WBU_IDLE:    next_state = (i_MEM_valid && o_WBU_ready) ? ysyx_24120011_WBU_WORKING : ysyx_24120011_WBU_IDLE;
//         ysyx_24120011_WBU_WORKING: next_state = ysyx_24120011_WBU_IDLE;
//         default : next_state = ysyx_24120011_WBU_IDLE;
//     endcase
// end
// always@(posedge clk)begin
//     if(rst) begin
//         state <= ysyx_24120011_WBU_IDLE;
//     end
//     else begin
//         state <= next_state;
//     end
// end

// reg [31:0]  rd_data;
// reg         rd_en;
// reg [31:0]  w_csr_data;
// reg         w_csr_en;
// reg         w_csr_ecall;

// assign o_rd          = rd         ;
// assign o_rd_data     = rd_data    ;
// assign o_rd_en       = rd_en      ;
// assign o_w_csr_addr  = w_csr_addr ;
// assign o_w_csr_data  = w_csr_data ;
// assign o_w_csr_en    = w_csr_en   ;
// assign o_w_csr_ecall = w_csr_ecall;
// assign o_rd_ctrl     = rd_ctrl    ;
// //GPR\CSR写入逻辑
// always @(posedge clk) begin
//     if (rst) begin
//         rd_en       <= 'd0;
//         w_csr_en    <= 'd0;
//         w_csr_ecall <= 'd0;
//     end else begin
//         if (state == ysyx_24120011_WBU_IDLE) begin
//             rd_en       <= 'd0       ;
//             w_csr_en    <= 'd0       ;
//             w_csr_ecall <= 'd0       ;
//         end else begin
//             if (rd_ctrl == 3'd4) begin
//                 rd_en      <= 'd0;
//             end else begin
//                 rd_en      <= 'd1;
//             end
//             if (csr_ctrl[1:0] == 2'd0) begin
//                 w_csr_en      <= 'd0;
//             end else begin
//                 w_csr_en      <= 'd1;
//             end
//             if (csr_ctrl[2] == 1'd0) begin
//                 w_csr_ecall   <= 'd0;
//             end else begin
//                 w_csr_ecall   <= 'd1;
//             end
//         end
//     end
// end
// always@(*)begin
//     case(rd_ctrl)
//         3'd0: rd_data = pc + 32'd4;
//         3'd1: rd_data = pc + imm;
//         3'd2: rd_data = ALU_result;
//         3'd3: rd_data = imm;
//         3'd4: rd_data = 32'h0000_0000;
//         3'd5: rd_data = r_mem_data;
//         3'd6: rd_data = r_csr_data;
//         default: rd_data = 32'h0000_0000;
//     endcase
// end
// always@(*)begin
//     case(csr_ctrl[1:0])
//         2'd0:    w_csr_data = 32'b0;
//         2'd1:    w_csr_data = src1;
//         2'd2:    w_csr_data = ALU_result;
//         2'd3:    w_csr_data = pc;
//         default: w_csr_data = 32'b0;
//     endcase
// end
endmodule