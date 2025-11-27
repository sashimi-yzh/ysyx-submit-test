module ysyx_25040111_reg (
    input         clock,
    input         wen,
    input  [1:0]  ren,
    input  [31:0] wdata,
    input  [3:0]  waddr,
    input  [3:0]  ars1, 
    input  [3:0]  ars2,
    output [31:0] rs1, 
    output [31:0] rs2
);

    reg  [31:0] rf [15:0];

    // 读口（显式 forwarding 临时信号）
    wire forward1 = (wen && (ars1 == waddr));
    wire forward2 = (wen && (ars2 == waddr));

    wire [31:0] rf_rs1 = rf[ars1];
    wire [31:0] rf_rs2 = rf[ars2];
    
    always @(posedge clock) begin
        if (wen && (waddr != 4'd0)) begin
            rf[waddr] <= wdata;       
        end
        rf[0] <= 0;
    end

    assign rs1 = ren[0] ? (forward1 ? wdata : rf_rs1) : 32'd0;
    assign rs2 = ren[1] ? (forward2 ? wdata : rf_rs2) : 32'd0;

endmodule
