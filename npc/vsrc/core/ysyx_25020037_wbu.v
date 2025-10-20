`include "ysyx_25020037_config.vh"

module ysyx_25020037_wbu (
    input  wire         clk,
    input  wire         rst,
    input  wire         lsu_valid,
`ifdef VERILATOR
    output reg          diff,
    input  wire [31: 0] diff_pc_i,
    output reg  [31: 0] diff_pc,
`endif
    input  wire [`RS_DATA-1: 0] rs_data,
    output wire [`WU_TO_EU_BUS_WD -1:0] wu_to_eu_bus,
    input  wire [`LU_TO_WU_BUS_WD -1:0] lu_to_wu_bus
);
    wire [ 3: 0] rd;
    wire [`EU_TO_WU_BUS_WD -1:0] eu_to_wu_bus;
    wire         gpr_we;
    wire [31: 0] csr_wcsr_data;  
    wire [31: 0] gpr_wdata;
    assign {rd,
            eu_to_wu_bus,
            gpr_we,
            csr_wcsr_data,
            gpr_wdata
           } = lu_to_wu_bus;
    reg  [31: 0] regs [15:0];
    reg  [31: 0] mtvec;
    reg  [31: 0] mepc;
    reg  [31: 0] mstatus;
    reg  [31: 0] mcause;
    wire [31: 0] mvendorid = 32'h79737978;
    wire [31: 0] marchid   = 32'h017DC685;

    wire   c_mtvec;
    wire   c_mepc;
    wire   c_mstatus;
    wire   c_mcause;
    wire   c_mvendorid;
    wire   c_marchid;
    wire [ 3: 0] rs1;
    wire [ 3: 0] rs2;
    assign {c_mtvec, c_mepc, c_mstatus, c_mcause, c_mvendorid, c_marchid, rs1, rs2} = rs_data;

    wire         ecall_en;
    wire         mret_en;
    wire         csrs_mtvec_wen;
    wire         csrs_mepc_wen;
    wire         csrs_mcause_wen;
    wire         csrs_mstatus_wen;
    assign {ecall_en,
            mret_en,
            csrs_mtvec_wen,
            csrs_mepc_wen,
            csrs_mcause_wen,
            csrs_mstatus_wen
           } = eu_to_wu_bus;
    wire [31: 0] src1;
    wire [31: 0] src2;
    wire [31: 0] csr_data; 
    assign csr_data = ({32{c_mtvec    }} & mtvec)
                    | ({32{c_mepc     }} & mepc)
                    | ({32{c_mstatus  }} & mstatus)
                    | ({32{c_mcause   }} & mcause)
                    | ({32{c_mvendorid}} & mvendorid)
                    | ({32{c_marchid  }} & marchid);

    wire [31: 0] mcause_data;
    wire [31: 0] mstatus_data;
    assign mcause_data  = ecall_en ? 32'hb    : csr_wcsr_data;
    assign mstatus_data = ecall_en ? 32'h1800 :
                          mret_en  ? ((mstatus & ~(32'h1 << 3))
                        | (((mstatus & (32'h1 << 7)) >> 4))
                        | (32'h1 << 7))
                        & ~((32'h1 << 11) | (32'h1 << 12)) :
                        csr_wcsr_data;
    always @(posedge clk or posedge rst) begin
      if(rst) begin
        regs[0] <= 32'b0;
        mstatus <= 32'h1800;
      end else begin
        if ((rd != 4'b0) && gpr_we) begin
          regs[rd] <= gpr_wdata;
        end
        if (csrs_mtvec_wen) begin
          mtvec <= csr_wcsr_data;
        end
        if (csrs_mepc_wen) begin
          mepc <= csr_wcsr_data;
        end
        if (csrs_mcause_wen) begin
          mcause <= mcause_data;
        end
        if (csrs_mstatus_wen) begin
          mstatus <= mstatus_data;
        end
`ifdef VERILATOR
        diff_pc <= diff_pc_i;
        if (lsu_valid) begin
          diff <= 1'b1;
        end else begin
          diff <= 1'b0;
        end
`endif
      end
    end
    
    assign src1 = regs[rs1];
    assign src2 = regs[rs2];
    assign wu_to_eu_bus = {           
             src1,
             src2,
             csr_data
           };

endmodule
