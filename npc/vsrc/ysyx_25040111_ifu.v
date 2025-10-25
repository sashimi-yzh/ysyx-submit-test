`ifdef STA_SOC
`define PC_RESET 32'h30000000   
`else
`define PC_RESET 32'h80000000
`endif

module ysyx_25040111_ifu (
    input           clock,
    input           reset,
    
    input           ifu_ready,
    output          ifu_valid,
    output  [31:0]  ifu_addr,
    input   [31:0]  ifu_inst,

    input           idu_valid,
    output          idu_ready,
    input           jump,
    output  [31:0]  idu_inst,
    output  [31:0]  idu_pc,

    input   [31:0]  jump_pc,
    input           jpc_ready,

    input           err,
    input   [31:0]  errpc
);

//-----------------------------------------------------------------
// Register / Wire
//-----------------------------------------------------------------

    wire [31:0] next_pc;

    reg  [31:0] pc;
    reg         jpc_ok;
    reg  [31:0] inst;
    reg         inst_ok;

//-----------------------------------------------------------------
// External Interface
//-----------------------------------------------------------------

    assign idu_inst     = inst;
    assign idu_ready    = inst_ok;
    assign ifu_valid    = jump ? jpc_ok : ~inst_ok;
    assign ifu_addr     = pc;
    assign idu_pc       = pc;

//-----------------------------------------------------------------
// COMBINATIONAL LOGIC
//-----------------------------------------------------------------



//-----------------------------------------------------------------
// State Machine
//-----------------------------------------------------------------
    
    // inst  inst_ok
    always @(posedge clock) begin
        if (reset | err) begin
            inst_ok <= 1'b0;            
        end
        else if (ifu_ready & ifu_valid) begin
            inst <= ifu_inst;
            inst_ok <= 1'b1;
            `ifndef YOSYS_STA
            `ifdef __ICARUS__
                if ($isunknown(ifu_inst)) $stop;
                else if ($isunknown(pc)) $stop;
            `endif
            `endif
        end
        else if (idu_ready & idu_valid)
            inst_ok <= 1'b0;
    end

    // pc
    always @(posedge clock) begin
        if (reset)
            pc <= `PC_RESET;
        else if (err)
            pc <= errpc;
        else if (idu_ready & idu_valid)
            pc <= pc + 32'd4;
        else if (jpc_ready & jump)
            pc <= jump_pc;
    end

    // jpc ok
    always @(posedge clock) begin
        if (reset | err) begin
            jpc_ok <= 1'b0;
        end
        else if (jpc_ready & jump)
            jpc_ok <= 1'b1;
        else if (ifu_ready & ifu_valid) begin
            jpc_ok <= 1'b0;
        end
    end


endmodule
