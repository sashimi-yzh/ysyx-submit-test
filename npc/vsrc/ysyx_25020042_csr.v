
module ysyx_25020042_csr (
    input clock,
    // input reset,
    input i_Exception_valid,
    input [31:0] i_csr_wdata,
    input [11:0] i_csr_addr,
    input [11:0] i_wbu_csr_addr,
    // input [31:0] i_mstatus_wdata,
    // input [31:0] i_mtvec_wdata,
    input [31:0] i_mepc_wdata,
    input [3:0] i_mcause_wdata,
    input wbu_valid,
    output [31:0] o_mstatus,
    output [31:0] o_mtvec,
    output [31:0] o_mepc,
    output reg [31:0] o_csr_rdata
);

// reg [31:0] mstatus;  
reg [31:0] mtvec;    
reg [31:0] mepc;     
reg [3:0] mcause;   
// reg [31:0] mcause;   
// reg [31:0] mcycle;   
// reg [31:0] mcycleh;  
// reg [31:0] mvendorid;
// reg [31:0] marchid;  

// reg [5:0] wen;
reg [3:1] wen;
// wire [31:0] mstatus_wdata;
wire [31:0] mtvec_wdata;
wire [31:0] mepc_wdata;
/* verilator lint_off UNUSEDSIGNAL */
wire [3:0] mcause_wdata;
/* verilator lint_on UNUSEDSIGNAL */
// wire [31:0] mcycle_val;
// wire [31:0] mcycleh_val;
wire [31:0] mvendorid_val;
wire [31:0] marchid_val;
// wire [31:0] mcycle_wdata;
// wire [31:0] mcycleh_wdata;

// assign mstatus_wdata = (i_Exception_valid == 1'b1) ? i_mstatus_wdata : i_csr_wdata;
assign mtvec_wdata   = (i_Exception_valid == 1'b1) ? 32'b0   : i_csr_wdata;
// assign mtvec_wdata   = (i_Exception_valid == 1'b1) ? i_mtvec_wdata   : i_csr_wdata;
assign mepc_wdata    = (i_Exception_valid == 1'b1) ? i_mepc_wdata    : i_csr_wdata;
assign mcause_wdata  = (i_Exception_valid == 1'b1) ? i_mcause_wdata  : i_csr_wdata[3:0];
// assign mcycle_wdata  = (wen[4] == 1'b1) ? i_csr_wdata    : mcycle_val + 1;
// assign mcycleh_wdata = (wen[5] == 1'b1) ? i_csr_wdata    : mcycle_val == 32'hffffffff ? mcycleh_val + 1 : mcycleh_val;


always @(*) begin
    wen = 3'b0;
    o_csr_rdata = 32'b0;
    if (wbu_valid) begin
        if(i_Exception_valid == 1'b1 ) begin
            wen = 3'b110;
        // end else if(i_wbu_csr_addr == 12'h300) begin
        //     wen[0] = 1'b1;
        end else if(i_wbu_csr_addr == 12'h305) begin
            wen[1] = 1'b1;
        end else if(i_wbu_csr_addr == 12'h341) begin
            wen[2] = 1'b1;
        end else if(i_wbu_csr_addr == 12'h342) begin
            wen[3] = 1'b1;
        // end else if(i_wbu_csr_addr == 12'hB00) begin
        //     wen[4] = 1'b1;
        // end else if(i_wbu_csr_addr == 12'hB80) begin
        //     wen[5] = 1'b1;
        end else begin
            wen = 3'b0;
        end
    end else begin  wen = 3'b0; end

    if(i_csr_addr == 12'h300) begin
        o_csr_rdata = o_mstatus;
    end else if(i_csr_addr == 12'h305) begin
        o_csr_rdata = o_mtvec;
    end else if(i_csr_addr == 12'h341) begin
        o_csr_rdata = o_mepc;
    end else if(i_csr_addr == 12'h342) begin
        o_csr_rdata = {28'b0, mcause};
    // end else if(i_csr_addr == 12'hB00) begin
    //     o_csr_rdata = mcycle_val;
    // end else if(i_csr_addr == 12'hB80) begin
    //     o_csr_rdata = mcycleh_val;
    end else if(i_csr_addr == 12'hF11) begin
        o_csr_rdata = mvendorid_val;
    end else if(i_csr_addr == 12'hF12) begin
        o_csr_rdata = marchid_val;
    end else begin
        o_csr_rdata = 32'b0;
    end
    
end


assign o_mstatus = 32'h1800;
assign o_mtvec   = mtvec;
assign o_mepc    = mepc;
// assign mcycle_val = mcycle;
// assign mcycleh_val = mcycleh;
assign mvendorid_val = 32'h79737978;
assign marchid_val = 32'h017DC68A;
always @(posedge clock) begin
    // if(reset) begin
    //     // mstatus   <= 32'h1800;
    //     mtvec     <= 32'h0;
    //     // mepc      <= 32'h0;
    //     mcause    <= 32'h0;
    //     // mcycle    <= 32'h0;
    //     // mcycleh   <= 32'h0;
    //     // mvendorid <= 32'h79737978;
    //     // marchid   <= 32'h017DC68A;
    // end
    // else begin
        // if(wen[0]) begin
        //     mstatus   <= mstatus_wdata;
        // end
        if(wen[1]) begin
            mtvec     <= mtvec_wdata;
        end
        if(wen[2]) begin
            mepc      <= mepc_wdata;
        end
        if(wen[3]) begin
            mcause    <= mcause_wdata[3:0];
        end
        // mcycle    <= mcycle_wdata;
        // mcycleh   <= mcycleh_wdata;
    // end
end

endmodule
