`include "npc_config.vh"

module ysyx_25040102_EXU_ysyx(
    input               clk,
    input               reset,

    input   [31:0]      snpc,
    input   [31:0]      dnpc,
    input   [31:0]      pc,

    // input   [31:0]      rs1,
    input   [31:0]      rs2,

    input   [31:0]      result,
    input               less,
    input               is_compare,

    input               mpcWr,
    // input   [31:0]      mretPc,
    input   [3:0]       mcause,
    output  [3:0]       mcause_out,

    input               mcause_wr,
    output              mcause_wr_out,

    // input               ebreak,
    // output              ebreak_out,

    input               decode_valid,
    output              decode_ready,

    input               lsu_ready,
    output              lsu_valid,

    input               pc_ready,
    output              pc_valid,
    // output  reg [31:0]  Next_pc_ifu,

    // lsu ctrl
    // output  [31:0]      lsu_addr, // 内存操作地址
    output  [31:0]      lsu_data, // 写内存数据
    output  [1:0]       lsu_mode, // 00不访存，01 load，11 store，10 mdata
    output  [2:0]       lsu_op,   // memop,指示字节

    output  [31:0]      Next_pc,  // next_pc
    output  [31:0]      pc_out,
    
    // reg ctrl
    output  [3:0]       Rw_out,
    output  [31:0]      result_out,
    output              regwr_out,

    input               RegWr,  
    input   [2:0]       branch,
    input               MemtoReg, // load
    input               MemWr,
    input   [2:0]       MemOp,

    input   [3:0]       Rw,       // to reg
    input               flush_finish // to mreg
);

    reg     [31:0]      rs2_r;

    reg                 RegWr_r;  // 写通用寄存器使能
    reg     [2:0]       branch_r;
    reg                 MemtoReg_r; // load
    reg                 MemWr_r; // store
    reg     [2:0]       MemOp_r;

    reg     [31:0]      snpc_r;
    reg     [31:0]      dnpc_r;
    reg     [3:0]       Rw_r;
    reg     [31:0]      Next_pc_r;
    reg     [31:0]      result_r;
    reg                 less_r;
    reg                 is_compare_r;
    reg                 mpcWr_r;
    // reg                 ebreak_r;
    reg     [31:0]      pc_r;
    reg     [3:0]       mcause_r;
    reg                 mcause_wr_r;

    reg     [1:0]       current_state;
    reg     [1:0]       next_state;

    localparam WAIT_DEVALID     = 0;
    localparam WAIT_LSUREADY    = 1;
    localparam WAIT_PCREADY     = 2;
    localparam WAIT_DNPC        = 3;

    always @(posedge clk) begin
        if(reset == 1'b1) begin
            current_state       <= WAIT_DEVALID;
        end
        else begin
            current_state       <= next_state;
        end
    end

    wire    [1:0]   mux;

    always @(*) begin
        
        case(current_state)

            WAIT_DEVALID: begin // 阻塞
                if(decode_valid == 1'b1) begin
                    next_state = WAIT_LSUREADY;
                end
                else begin
                    next_state = WAIT_DEVALID;
                end
            end

            WAIT_LSUREADY: begin
                if(lsu_ready == 1'b1) begin
                    if(mux == 2'b01) begin // snpc
                        next_state = WAIT_DEVALID;
                    end
                    else begin // flush
                        next_state = WAIT_PCREADY;
                    end
                end
                else begin
                    next_state = WAIT_LSUREADY;
                end
            end

            WAIT_PCREADY: begin
                if(pc_ready == 1'b1) begin
                    next_state  = WAIT_DNPC;
                end
                else begin
                    next_state  = WAIT_PCREADY;
                end
            end

            WAIT_DNPC: begin
                if(decode_valid == 1'b1 && flush_finish == 1'b1) begin
                    next_state = WAIT_LSUREADY;
                end
                else begin
                    next_state  = WAIT_DNPC;
                end
            end

        endcase
    end

    assign  decode_ready    = (current_state == WAIT_DEVALID || current_state == WAIT_DNPC);
    assign  lsu_valid       = (current_state == WAIT_LSUREADY);
    assign  pc_valid        = (current_state == WAIT_PCREADY);

    assign  lsu_data        = rs2_r;
    assign  lsu_mode        = (MemWr_r) ? 2'b11 : {1'b0, MemtoReg_r};
    assign  lsu_op          = MemOp_r;

    wire    [31:0]  result_com;

    assign  result_com = ((is_compare_r == 1'b1) ? {31'b0, less_r} : result_r);

    // assign  
    assign  Rw_out          = (current_state == WAIT_LSUREADY) ? Rw_r : 4'h0;
    assign  result_out      = (mux == 2'b00) ? snpc_r : result_com;
    assign  regwr_out       = (current_state == WAIT_LSUREADY) ? RegWr_r: 1'b0;
    // assign  ebreak_out      = ebreak_r;

    assign  pc_out          = pc_r;
    assign  mcause_out      = mcause_r;
    assign  mcause_wr_out   = mcause_wr_r;


    always @(posedge clk) begin
        if(decode_valid == 1'b1 && decode_ready == 1'b1) begin
            mpcWr_r         <= mpcWr;
            rs2_r           <= rs2;
            RegWr_r         <= RegWr;
            branch_r        <= branch;
            MemtoReg_r      <= MemtoReg;
            MemWr_r         <= MemWr;
            MemOp_r         <= MemOp;
            less_r          <= less;
            is_compare_r    <= is_compare;
            snpc_r          <= snpc;
            dnpc_r          <= dnpc;
            Rw_r            <= Rw;
            result_r        <= result;
            // ebreak_r        <= ebreak;
            pc_r            <= pc;
            mcause_r        <= mcause;
            mcause_wr_r     <= mcause_wr;
        end
    end


    wire zero_r     = (result_r == 0);
    
    ysyx_25040102_Branch_Cond u_Branch_Cond(
        .mpcWr      (mpcWr_r    ),
        .branch 	(branch_r ),
        .less   	(less_r   ),
        .zero   	(zero_r   ),
        .mux        (mux      )
    );

    always @(*) begin // 2'b00 result; 2'b01 snpc; 2'b11 dnpc; 2'b10 mpc
        case(mux)
            2'b00: Next_pc_r = result_com;
            2'b01: Next_pc_r = snpc_r;
            2'b10: Next_pc_r = snpc_r;
            2'b11: Next_pc_r = dnpc_r;
        endcase
    end

    assign  Next_pc     = Next_pc_r;


`ifdef ysyx_25040102_SIM
    always @(posedge clk) begin
        if(current_state == WAIT_PCREADY && pc_ready == 1'b1) begin
            time_add(6);
        end
    end

    always @(posedge clk) begin
        if(current_state == WAIT_DNPC) begin
            cycle_add(6);
        end
    end

`endif 


endmodule
