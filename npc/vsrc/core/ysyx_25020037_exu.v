`include "ysyx_25020037_config.vh"

module ysyx_25020037_exu (
    output wire         sim_end,
    input  wire         clk,
    input  wire         rst,
    input  wire         idu_valid,
    input  wire         lsu_ready,
    output reg          exu_valid,
    output wire         exu_ready,
    output wire [`RS_DATA-1: 0] rs_data,
    input  wire [31: 0] rdata_processed,
`ifdef VERILATOR
    output reg  [31: 0] diff_pc_o,
`endif
    input  wire [`WU_TO_EU_BUS_WD -1:0] wu_to_eu_bus,
    input  wire [`DU_TO_EU_BUS_WD -1:0] du_to_eu_bus,
    output reg  [`EU_TO_LU_BUS_WD -1:0] eu_to_lu_bus,
    output reg  [`EU_TO_IC_BUS_WD -1:0] eu_to_ic_bus,
    input  wire         pc_updata,
    output reg          exu_dnpc_valid,
    output reg  [31: 0] exu_dnpc
);
`ifdef VERILATOR
    import "DPI-C" function void hit(input int inst_not_realize);
`endif

    localparam BYPASS_DEPTH = 2;
    reg [ 3:0] bypass_rd[     BYPASS_DEPTH-1:0];
    reg [31:0] bypass_data[   BYPASS_DEPTH-1:0];
    reg        bypass_is_load[BYPASS_DEPTH-1:0];

    wire [31: 0] src1_r;
    wire [31: 0] src2_r;
    wire [31: 0] csr_data;
    assign {src1_r,
            src2_r,
            csr_data
           } = wu_to_eu_bus;

    wire [31: 0] src1;
    wire [31: 0] src2;
    wire [`DU_TO_LU_BUS_WD -1:0] du_to_lu_bus;
    wire [31: 0] pc;
    wire [ 1: 0] lw_lh_lb;
    wire [ 1: 0] sw_sh_sb;
    wire         is_fence_i;
    wire [31: 0] imm;
    wire [ 3: 0] rd;
    wire [ 3: 0] rs1;
    wire [ 3: 0] rs2;
    wire         is_write;
    wire         is_read;
    wire         gpr_we;
    wire [16: 0] alu_op;
    wire         src1_is_pc;
    wire         src2_is_imm;
    wire         is_pc_jump;
    wire         ecall_en;
    wire         mret_en;
    wire         csrrs_op;
    wire         csrrw_op;
    wire         ebreak;
    assign {du_to_lu_bus,
            pc,
            lw_lh_lb,
            sw_sh_sb,
            is_fence_i,
            imm,
            rd,
            rs1,
            rs2,
            is_write,
            is_read,
            gpr_we,
            alu_op,
            src1_is_pc,
            src2_is_imm,
            is_pc_jump,
            ecall_en,
            mret_en,
            csrrs_op,
            csrrw_op,
            ebreak
           } = du_to_eu_bus;

    wire   c_mtvec     = (imm[11:0] == `MTVEC || ecall_en);
    wire   c_mepc      = (imm[11:0] == `MEPC  || mret_en );
    wire   c_mstatus   = (imm[11:0] == `MSTATUS          );
    wire   c_mcause    = (imm[11:0] == `MCAUSE           );
    wire   c_mvendorid = (imm[11:0] == `MVENDORID        );
    wire   c_marchid   = (imm[11:0] == `MARCHID          );
    assign rs_data     = {c_mtvec, c_mepc, c_mstatus, c_mcause, c_mvendorid, c_marchid, rs1, rs2};

    wire   csr_w_gpr_we;
    wire   csrs_mtvec_wen;
    wire   csrs_mepc_wen;
    wire   csrs_mcause_wen;
    wire   csrs_mstatus_wen;
    assign csr_w_gpr_we     = csrrs_op | csrrw_op;
    assign csrs_mtvec_wen   = ( imm[11:0] == `MTVEC  ) & csr_w_gpr_we;
    assign csrs_mepc_wen    = ((imm[11:0] == `MEPC   ) & csr_w_gpr_we) | ecall_en;
    assign csrs_mcause_wen  = ((imm[11:0] == `MCAUSE ) & csr_w_gpr_we) | ecall_en;
    assign csrs_mstatus_wen = ((imm[11:0] == `MSTATUS) & csr_w_gpr_we) | mret_en;

    wire [`EU_TO_WU_BUS_WD -1:0] eu_to_wu_bus;
    assign eu_to_wu_bus = {
        ecall_en,
        mret_en,
        csrs_mtvec_wen,
        csrs_mepc_wen,
        csrs_mcause_wen,
        csrs_mstatus_wen
    };
    reg [31:0] bypass_src1;
    reg [31:0] bypass_src2;
    always @(*) begin
        bypass_src1 = src1_r;
        if ((bypass_rd[0] == rs1) && (rs1 != 4'd0)) begin
            bypass_src1 = bypass_is_load[0] ? rdata_processed : bypass_data[0];
        end
        else if ((bypass_rd[1] == rs1) && (rs1 != 4'd0)) begin
            bypass_src1 = bypass_is_load[1] ? rdata_processed : bypass_data[1];
        end
     end

    always @(*) begin
        bypass_src2 = src2_r;
        if ((bypass_rd[0] == rs2) && (rs2 != 4'd0)) begin
            bypass_src2 = bypass_is_load[0] ? rdata_processed : bypass_data[0];
        end
        else if ((bypass_rd[1] == rs2) && (rs2 != 4'd0)) begin
            bypass_src2 = bypass_is_load[1] ? rdata_processed : bypass_data[1];
        end
    end

    assign src1 = bypass_src1;
    assign src2 = bypass_src2;
    assign exu_ready = lsu_ready;

    wire [31: 0] snpc;
    wire [31: 0] dnpc_r;
    wire [31: 0] result;
    wire [31: 0] alu_src1;
    wire [31: 0] alu_src2;
    wire [31: 0] alu_src3;
    wire [31: 0] alu_src4;
    wire [31: 0] alu_result1;
    wire         alu_result2;
    wire [31: 0] csr_wcsr_data;
    wire [31: 0] data_channel;

    assign snpc     = pc + 32'h4;
    assign alu_src1 = src1_is_pc  ? pc  : src1;
    assign alu_src2 = src2_is_imm ? imm : src2;
    assign alu_src3 = src1;
    assign alu_src4 = src2;

    ysyx_25020037_alu alu_cpu(
        .alu_op         (alu_op     ),
        .alu_src1       (alu_src1   ),
        .alu_src2       (alu_src2   ),
        .alu_src3       (alu_src3   ),
        .alu_src4       (alu_src4   ),
        .alu_result1    (alu_result1),
        .alu_result2    (alu_result2)
        );

    assign csr_wcsr_data  = ({32{csrrw_op}} & src1)
                          | ({32{csrrs_op}} & (src1 | csr_data))
                          | ({32{ecall_en}} & pc);
    assign dnpc_r         = ({32{ecall_en   | mret_en    }} & csr_data) 
                          | ({32{is_pc_jump | alu_result2}} & alu_result1) 
                          | ({32{is_fence_i              }} & snpc);

    assign result    = is_pc_jump   ? snpc     :
                       csr_w_gpr_we ? csr_data :
                       alu_result1;

    assign data_channel = is_write ? src2 : csr_wcsr_data;

    always @(posedge clk) begin
        if (lsu_ready) begin
            if(bypass_is_load[1]) begin
                bypass_data[1]    = rdata_processed;
                bypass_is_load[1] = 1'b0;
            end else if (bypass_is_load[0])begin
                bypass_data[0]    = rdata_processed;
                bypass_is_load[0] = 1'b0;
            end
        end
        if (exu_ready && idu_valid && !exu_dnpc_valid) begin
            bypass_rd[1]       = bypass_rd[0];
            bypass_data[1]     = bypass_data[0];
            bypass_is_load[1]  = bypass_is_load[0];

            bypass_rd[0]       = gpr_we ? rd      : bypass_rd[0];
            bypass_data[0]     = gpr_we ? result  : bypass_data[0];
            bypass_is_load[0]  = gpr_we ? is_read : bypass_is_load[0];
        end
    end

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            exu_dnpc_valid <=1'b0;
            eu_to_lu_bus <= 'b0;
        end else begin
`ifdef VERILATOR
            diff_pc_o <= idu_valid ? pc : diff_pc_o;
`endif
            if(exu_ready) begin
                if(dnpc_r != 32'b0 && ~exu_dnpc_valid) begin
                    exu_dnpc_valid <= idu_valid;
                    exu_dnpc <= dnpc_r;
                end else if (pc_updata) begin
                    exu_dnpc_valid <=1'b0;
                end
                if (idu_valid) begin
                    exu_valid <= ~exu_dnpc_valid;
                    eu_to_lu_bus <= {
                        rd,
                        eu_to_wu_bus,
                        lw_lh_lb,
                        sw_sh_sb,
                        is_write,
                        is_read,
                        du_to_lu_bus,
                        gpr_we,
                        data_channel,
                        result
                    };
                    eu_to_ic_bus <= is_fence_i;
                end else begin
                    exu_valid <= 1'b0;
                    eu_to_ic_bus <= 'b0;
                    eu_to_lu_bus <= 'b0;
                end
            end
        end
    end

    assign sim_end = ~exu_dnpc_valid & idu_valid & ebreak;
`ifdef VERILATOR
    always @(*) begin
       if(~exu_dnpc_valid & idu_valid & ebreak) begin hit(32'b0); end
    end
`endif
endmodule
