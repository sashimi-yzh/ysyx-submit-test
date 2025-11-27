`include "HDR/ysyx_25040111_inc.vh"
`include "HDR/ysyx_25040111_dpic.vh"
`include "ALU/ysyx_25040111_alu.v"

module ysyx_25040111_exu(
    input                   clock,
    input                   reset,
    
    input                   exe_valid,
    output                  exe_ready,
    input  [`OPT_HIGH:0]    opt,
    input  [4:0]            ard_in,
    input  [4:0]            ar1_in,
    input  [4:0]            ar2_in,
    input  [11:0]           acsrd_in,
    input  [31:0]           pc,
    input  [31:0]           imm,
    
    input  [31:0]           csri,
    input  [31:0]           rs1,
    input  [31:0]           rs2,

    output                  abt_valid,
    input                   abt_ready,
    output                  abt_men,

    output [4:0]            abt_ard,
    output [31:0]           abt_rd,
    output                  abt_gen,

    output [11:0]           abt_acsr,
    output [31:0]           abt_csr,
    output                  abt_sen,

    output                  abt_write,
    output [31:0]           abt_wdata,
    output [31:0]           abt_addr,
    output [1:0]            abt_mask, 
    output                  abt_rsign,
    
    output [31:0]           jump_pc,
    output                  jpc_ready,

    input                   abt_finish,
    input  [4:0]            abt_frd,
    output [31:0]           abt_pc,

    input                   erri,
    input  [3:0]            errtpi,
    output                  erro,
    output [3:0]            errtpo,

    output                  fencei
);

//-----------------------------------------------------------------
// Register / Wire
//-----------------------------------------------------------------

    // exu input data
    reg  [31:0]         ers2,   ecsr;
    reg  [31:0]         epc; 
    reg  [`OPT_HIGH:0]  eopt;
    reg  [4:0]          ard;
    reg  [11:0]         acsrd;
    reg  [3:0]          errtp;
    reg                 error;

    // output data
    reg  [31:0]         rdo;

    // pipeline ctrl
    reg  [15:0]         rlock;
    reg                 exe_start;
    reg                 exe_end;
    reg                 jmpc_ok;

    // alu paramter
    reg  [31:0]         alu_p1, alu_p2;
    reg  [6:0]          alu_ctrl;
    wire [31:0]         rd;
    
    // read after write lock paramter
    wire lock = |(rlock & ((16'h1 << ard_in[3:0]) |
                           (16'h1 << ar1_in[3:0]) |
                           (16'h1 << ar2_in[3:0])));

    wire load = opt[12] & |opt[11:10] & ~opt[15];

    wire [15:0] ard_mask  = 16'h1 << ard_in[3:0];
    wire [15:0] frd_mask  = 16'h1 << abt_frd[3:0];

    // jump pc process
    wire jmp  = (~(opt[9:8] == 2'b01) & |opt[2:0]) | (opt[12] & opt[15]);
    wire mtp  = opt[12] & opt[15];
    
    wire [15:0] rlock_set = exe_ready & exe_valid & load ? rlock | ard_mask : rlock;
    wire [15:0] rlock_nxt = abt_finish ? rlock_set & ~frd_mask : rlock_set;

    // other ctrl
    wire mwt  = eopt[15] & eopt[10];
    wire mrd  = opt[15]  & opt[11];

//-----------------------------------------------------------------
// External Interface
//-----------------------------------------------------------------
    
    assign exe_ready = ~exe_start & ~lock;

    assign abt_valid = exe_end;
    assign abt_men   = |eopt[11:10] & ~eopt[15] & ~error;
    
    assign abt_ard   = ard;
    assign abt_rd    = mwt ? ecsr : rdo;
    assign abt_gen   = eopt[0] & ~error;

    assign abt_acsr  = error ? `MEPC : acsrd;
    assign abt_csr   = error ? epc   : rdo;
    assign abt_sen   = mwt | error;

    assign abt_rsign = eopt[14];
    assign abt_write = ~eopt[12];
    assign abt_addr  = rdo;
    assign abt_wdata = ers2;
    assign abt_mask  = eopt[11:10];

    assign abt_pc    = epc;
    
    assign jpc_ready = jmpc_ok | (abt_valid & abt_ready & fencei);
    assign jump_pc   = rd; 

    assign erro      = error;
    assign errtpo    = errtp;
    
    assign fencei = ~eopt[0] & ~eopt[15] & (eopt[12:10] == 3'b100);

//-----------------------------------------------------------------
// State Machine
//-----------------------------------------------------------------

    // input data
    always @(posedge clock) begin
        if (exe_start & ~exe_end) begin
            ers2 <= rs2; ecsr <= csri;
            epc  <= pc; eopt <= opt;
            ard <= ard_in; acsrd <= acsrd_in;
            error <= erri; errtp <= errtpi;
        end
    end

    // exe start
    always @(posedge clock) begin
        if (reset)
            exe_start <= 1'b0;
        else if (exe_ready & exe_valid)
            exe_start <= 1'b1;
        else if (exe_start & abt_valid & abt_ready)
            exe_start <= 1'b0;
    end

    // exe end
    always @(posedge clock) begin
        if (reset)
            exe_end <= 1'b0;
        else if (exe_start & ~exe_end)
            exe_end <= 1'b1;
        else if (abt_valid & abt_ready)
            exe_end <= 1'b0;
    end

    // executing
    always @(posedge clock) begin
        if (exe_ready & exe_valid) begin
            case (opt[4:3])
                2'b00: begin alu_p1 <= imm; alu_p2 <= 0;    end
                2'b01: begin                    
                    alu_p1 <= rs1; 
                    alu_p2 <= mrd ? csri : rs2;    
                end
                2'b10: begin alu_p1 <= pc;  alu_p2 <= imm;  end
                2'b11: begin alu_p1 <= rs1; alu_p2 <= imm;  end
            endcase
            
            alu_ctrl <= {opt[7:5], (opt[12:10]==3'b100), opt[15:13]};
        end
        else if (exe_start & ~exe_end) begin
            case (opt[9:8])
                2'b00: begin 
                    alu_p1 <= mtp ? csri  : pc;  
                    alu_p2 <= mtp ? 32'd0 : rd[0] ? imm : 32'd4;  
                end
                2'b01: begin alu_p1 <= pc;  alu_p2 <= 32'd4; end
                2'b10: begin alu_p1 <= pc;  alu_p2 <= imm;   end
                2'b11: begin alu_p1 <= rs1; alu_p2 <= imm;   end
            endcase

            alu_ctrl <= {`ADD, 1'b0, `EMPTY};
        end
    end

    // rdo
    always @(posedge clock) begin
        if (reset)
            rdo <= 0;
        else if (exe_start & ~exe_end)
            rdo <= rd;
    end

    // jmpc_ok
    always @(posedge clock) begin
        if (reset)
            jmpc_ok <= 1'b0;
        else if (exe_start & ~exe_end & jmp)
            jmpc_ok <= 1'b1;
        else if (jmpc_ok)
            jmpc_ok <= 1'b0;
    end

    // read after write process
    always @(posedge clock) begin
        if (reset) rlock <= 16'b0;
        else rlock <= rlock_nxt;
    end

//-----------------------------------------------------------------
// MODULE INSTANCES
//-----------------------------------------------------------------

    // ALU
    ysyx_25040111_alu u_alu(
        .var1 	(alu_p1         ),
        .var2 	(alu_p2         ),
        .opt  	(alu_ctrl[6:4]  ),
        .snpc   (alu_ctrl[3]    ),
        .ext    (alu_ctrl[0]    ),
        .sign   (alu_ctrl[1]    ),
        .negate (alu_ctrl[2]    ),
        .res  	(rd             )
    );

//-----------------------------------------------------------------
// Combinational Logic
//-----------------------------------------------------------------

`ifndef YOSYS_STA
    // EBREADK
    wire [31:0] eret;
    assign eret = opt[15] ? rs1 : 32'd9;
    always @(*) begin
        if (opt == `EBREAK_INST)
        `ifdef __ICARUS__
            $finish();
        `else
            ebreak(eret);            
        `endif
    end
`endif // YOSYS_STA

endmodule
