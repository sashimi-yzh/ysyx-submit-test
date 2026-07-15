module CSR(
    input clk,
    input reset,
    input [11:0] waddr, //write addr
    input [11:0] raddr, //read addr
    input [31:0] srcR1,
    input [31:0] alu_res,
    input wr_sel, //0: write srcR1, 1: write alu_res
    input wen,

    input exception,

    input [31:0] w_epc,
    input [31:0] w_cause,

    output reg [31:0] rdata,
    output [31:0] mtvec_out,
    output [31:0] mepc_out
);

    reg [31:0] mcycle;
    reg [31:0] mcycleh;
    reg [31:0] mvendorid;
    reg [31:0] marchid;
    reg [31:0] mtvec;
    reg [31:0] mepc;
    reg [31:0] mcause;

    //a combinational logic to read CSR, only take the mycle(h) into account
    always @(*) begin
        if(raddr == 12'hc00) rdata = mcycle; //mcycle
        else if(raddr == 12'hc80) rdata = mcycleh; //mcycleh
        else if(raddr == 12'hf11) rdata = mvendorid; //mvendorid
        else if(raddr == 12'hf12) rdata = marchid; //marchid
        else if(raddr == 12'h305) rdata = mtvec; //mtvec
        else if(raddr == 12'h341) rdata = mepc; //mepc
        else if(raddr == 12'h342) rdata = mcause; //mcause
        else rdata = 32'b0;
    end

    always @(posedge clk) begin
        if(reset) mtvec <= 32'b0;
        else if(wen && waddr == 12'h305) mtvec <= (wr_sel) ? alu_res : srcR1; //mtvec
    end

    always @(posedge clk) begin
        if(reset) mepc <= 32'b0;
        else if(exception) mepc <= w_epc; //write mepc with the current PC when exception happens
        else if(wen && waddr == 12'h341) mepc <= (wr_sel) ? alu_res : srcR1; //mepc
    end

    always @(posedge clk) begin
        if(reset) mcause <= 32'b0;
        else if(exception) mcause <= w_cause; //write mcause with the current cause when exception happens
        else if(wen && waddr == 12'h342) mcause <= (wr_sel) ? alu_res : srcR1; //mcause
    end

    always @(posedge clk) begin
        if(reset) mcycle <= 32'b0;
        else mcycle <= mcycle + 1;
    end
    
    always @(posedge clk) begin
        if(reset) mcycleh <= 32'b0;
        else if(mcycle == 32'hffff_ffff) mcycleh <= mcycleh + 1;
    end

    always @(posedge clk) begin
        if(reset) mvendorid <= 32'b0;
        else mvendorid <= 32'h79737978; //just a random value
    end

    always @(posedge clk) begin
        if(reset) marchid <= 32'b0;
        else marchid <= 32'h018D573D; //26040125 in hex
    end

    assign mtvec_out = mtvec;
    assign mepc_out = mepc;

endmodule
