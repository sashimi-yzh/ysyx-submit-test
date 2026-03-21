//------------------------------------------------------------------------
// VERILOG MACRO
//------------------------------------------------------------------------

// `define ysyx_25110270_SOC //no verilog macro define here, define it in Makefile

`ifdef ysyx_25110270_SOC 

`define ysyx_25110270_DPIC
`define ysyx_25110270_PERF
// `define ysyx_25110270_DEBUG

`endif

`ifdef ysyx_25110270_NPC 

`define ysyx_25110270_DPIC
`define ysyx_25110270_PERF
// `define ysyx_25110270_DEBUG

`endif

// `define ysyx_25110270_NETSIM

//------------------------------------------------------------------------
// rv32i load type inst
//------------------------------------------------------------------------
`define ysyx_25110270_RV32I_OP_TYPE_IL 7'b0000011
`define ysyx_25110270_RV32I_F3_LB      3'b000
`define ysyx_25110270_RV32I_F3_LH      3'b001
`define ysyx_25110270_RV32I_F3_LW      3'b010
`define ysyx_25110270_RV32I_F3_LBU     3'b100
`define ysyx_25110270_RV32I_F3_LHU     3'b101

//------------------------------------------------------------------------
// rv32i I type inst
//------------------------------------------------------------------------
`define ysyx_25110270_RV32I_OP_TYPE_I 7'b0010011
`define ysyx_25110270_RV32I_F3_ADDI   3'b000
`define ysyx_25110270_RV32I_F3_SLLI   3'b001
`define ysyx_25110270_RV32I_F3_SLTI   3'b010
`define ysyx_25110270_RV32I_F3_SLTIU  3'b011
`define ysyx_25110270_RV32I_F3_XORI   3'b100
`define ysyx_25110270_RV32I_F3_SRI    3'b101
`define ysyx_25110270_RV32I_F3_ORI    3'b110
`define ysyx_25110270_RV32I_F3_ANDI   3'b111

//------------------------------------------------------------------------
// rv32i U type inst
//------------------------------------------------------------------------
`define ysyx_25110270_RV32I_OP_AUIPC  7'b0010111
`define ysyx_25110270_RV32I_OP_LUI    7'b0110111

//------------------------------------------------------------------------
// rv32i S type inst
//------------------------------------------------------------------------
`define ysyx_25110270_RV32I_OP_TYPE_S 7'b0100011
`define ysyx_25110270_RV32I_F3_SB     3'b000
`define ysyx_25110270_RV32I_F3_SH     3'b001
`define ysyx_25110270_RV32I_F3_SW     3'b010

// rv32i/rv32m R/M type inst
`define ysyx_25110270_RV32IM_OP_TYPE_R 7'b0110011

`define ysyx_25110270_RV32I_F3_ADD_SUB 3'b000
`define ysyx_25110270_RV32I_F3_SLL     3'b001
`define ysyx_25110270_RV32I_F3_SLT     3'b010
`define ysyx_25110270_RV32I_F3_SLTU    3'b011
`define ysyx_25110270_RV32I_F3_XOR     3'b100
`define ysyx_25110270_RV32I_F3_SR      3'b101
`define ysyx_25110270_RV32I_F3_OR      3'b110
`define ysyx_25110270_RV32I_F3_AND     3'b111

`define ysyx_25110270_RV32I_F7_R1    7'b0000000
`define ysyx_25110270_RV32I_F7_R2    7'b0100000

//------------------------------------------------------------------------
// rv32i B type inst
//------------------------------------------------------------------------
`define ysyx_25110270_RV32I_OP_TYPE_B 7'b1100011
`define ysyx_25110270_RV32I_F3_BEQ    3'b000
`define ysyx_25110270_RV32I_F3_BNE    3'b001
`define ysyx_25110270_RV32I_F3_BLT    3'b100
`define ysyx_25110270_RV32I_F3_BGE    3'b101
`define ysyx_25110270_RV32I_F3_BLTU   3'b110
`define ysyx_25110270_RV32I_F3_BGEU   3'b111

//------------------------------------------------------------------------
// rv32i J type inst
//------------------------------------------------------------------------
`define ysyx_25110270_RV32I_OP_JALR   7'b1100111
`define ysyx_25110270_RV32I_OP_JAL    7'b1101111

//------------------------------------------------------------------------
// rv32 Except type inst
//------------------------------------------------------------------------
`define ysyx_25110270_RV_MRET       32'h30200073
`define ysyx_25110270_RV_ECALL      32'h00000073
`define ysyx_25110270_RV_EBREAK     32'h00100073

`define ysyx_25110270_RV_FENCE_I    32'h0000100F

//------------------------------------------------------------------------
// rv32zicsr CSR type inst
//------------------------------------------------------------------------
`define ysyx_25110270_RV_OP_CSR    7'b1110011
`define ysyx_25110270_RV_F3_CSRRW  3'b001
`define ysyx_25110270_RV_F3_CSRRS  3'b010
`define ysyx_25110270_RV_F3_CSRRC  3'b011
`define ysyx_25110270_RV_F3_CSRRWI 3'b101
`define ysyx_25110270_RV_F3_CSRRSI 3'b110
`define ysyx_25110270_RV_F3_CSRRCI 3'b111

//------------------------------------------------------------------------
// GENERAL PURPOSE REGISTER DEFINITIONS
//------------------------------------------------------------------------
`define ysyx_25110270_RegNum 16        // reg num
`define ysyx_25110270_RegAddrWidth $clog2(`ysyx_25110270_RegNum)
`define ysyx_25110270_RegAddrBus `ysyx_25110270_RegAddrWidth-1:0

//------------------------------------------------------------------------
// CSR REGISTER DEFINITIONS
//------------------------------------------------------------------------
`define ysyx_25110270_CsrNum 8
`define ysyx_25110270_CsrMapWidth $clog2(`ysyx_25110270_CsrNum)
`define ysyx_25110270_CsrMapBus `ysyx_25110270_CsrMapWidth-1:0

`define ysyx_25110270_CSR_MSTATUS           12'h300     // Machine Status Register
`define ysyx_25110270_CSR_MTVEC             12'h305     // Machine Trap-Vector Base-Address Register
`define ysyx_25110270_CSR_MEPC              12'h341     // Machine Exception Program Counter
`define ysyx_25110270_CSR_MCAUSE            12'h342     // Machine Cause Register
`define ysyx_25110270_CSR_CYCLE             12'hc00     // Lower 32 bits of Cycle counter
`define ysyx_25110270_CSR_CYCLEH            12'hc80     // Upper 32 bits of Cycle counter
`define ysyx_25110270_CSR_MVENDORID         12'hf11     // Vendor ID
`define ysyx_25110270_CSR_MARCHID           12'hf12     // Architecture ID

`define ysyx_25110270_CSR_MAP_MSTATUS       0
`define ysyx_25110270_CSR_MAP_MCAUSE        1
`define ysyx_25110270_CSR_MAP_MTVEC         2
`define ysyx_25110270_CSR_MAP_MEPC          3
`define ysyx_25110270_CSR_MAP_CYCLE         4
`define ysyx_25110270_CSR_MAP_CYCLEH        5
`define ysyx_25110270_CSR_MAP_MVENDORID     6
`define ysyx_25110270_CSR_MAP_MARCHID       7

//------------------------------------------------------------------------
// ALU SOURCE SELECTION DEFINITIONS
//------------------------------------------------------------------------
`define ysyx_25110270_ALUSRCA_RS1     2'b01
`define ysyx_25110270_ALUSRCA_PC      2'b10
`define ysyx_25110270_ALUSRCA_0       2'b11

//------------------------------------------------------------------------
// ALU SOURCE SELECTION DEFINITIONS
//------------------------------------------------------------------------
`define ysyx_25110270_ALUSRCB_RS2     2'b01
`define ysyx_25110270_ALUSRCB_IMM     2'b10
`define ysyx_25110270_ALUSRCB_4       2'b11

//------------------------------------------------------------------------
// AGU SOURCE SELECTION DEFINITIONS
//------------------------------------------------------------------------
`define ysyx_25110270_AGUSRC_RS1      2'b01
`define ysyx_25110270_AGUSRC_PC       2'b10
`define ysyx_25110270_AGUSRC_0        2'b11

//------------------------------------------------------------------------
// CSR SOURCE SELECTION DEFINITIONS
//------------------------------------------------------------------------
`define ysyx_25110270_CSRSRC_RS1      1'b0
`define ysyx_25110270_CSRSRC_IMM      1'b1

//------------------------------------------------------------------------
// FWD SOURCE SELECTION DEFINITIONS
//------------------------------------------------------------------------
`define ysyx_25110270_FWDSRC_NFW      1'b0
`define ysyx_25110270_FWDSRC_EX       1'b1

//------------------------------------------------------------------------
// EXCEPTION TYPE DEFINITIONS
//------------------------------------------------------------------------
`define ysyx_25110270_ExceptWidth     2
`define ysyx_25110270_ExceptBus       `ysyx_25110270_ExceptWidth-1:0

`define ysyx_25110270_EXCPT_ECALL     0
`define ysyx_25110270_EXCPT_MRET      1

//------------------------------------------------------------------------
// MEMORY DEFINITIONS
//------------------------------------------------------------------------
`define ysyx_25110270_CLINT_BASE    32'h0200_0000
`define ysyx_25110270_CLINT_SIZE    32'h0001_0000
`define ysyx_25110270_SERIAL_BASE   32'h1000_0000
`define ysyx_25110270_SERIAL_SIZE   32'h0000_1000
`define ysyx_25110270_SPI_BASE      32'h1000_1000
`define ysyx_25110270_SPI_SIZE      32'h0000_1000
`define ysyx_25110270_GPIO_BASE     32'h1000_2000
`define ysyx_25110270_GPIO_SIZE     32'h0000_0010
`define ysyx_25110270_PS2_BASE      32'h1001_1000
`define ysyx_25110270_PS2_SIZE      32'h0000_0008
`define ysyx_25110270_VGA_BASE      32'h2100_0000
`define ysyx_25110270_VGA_SIZE      32'h0020_0000
`define ysyx_25110270_CHIPL_BASE    32'hc000_0000
`define ysyx_25110270_CHIPL_SIZE    32'h4000_0000

`define ysyx_25110270_MromAddrBase  32'h2000_0000
`define ysyx_25110270_MromSize      32'h0001_0000
`define ysyx_25110270_SramAddrBase  32'h0f00_0000
`define ysyx_25110270_SramSize      32'h0100_0000
`define ysyx_25110270_FlashAddrBase 32'h3000_0000
`define ysyx_25110270_FlashSize     32'h1000_0000
`define ysyx_25110270_PsramAddrBase 32'h8000_0000
`define ysyx_25110270_PsramSize     32'h2000_0000
`define ysyx_25110270_SdramAddrBase 32'ha000_0000
`define ysyx_25110270_SdramSize     32'h2000_0000

`ifndef __ICARUS__

`ifdef ysyx_25110270_NPC
    `define ysyx_25110270_RESET_VECTOR  32'h8000_0000
`else
    `ifdef ysyx_25110270_NOBOOTLOADER
        `define ysyx_25110270_RESET_VECTOR  `ysyx_25110270_SdramAddrBase
    `else
        `define ysyx_25110270_RESET_VECTOR  `ysyx_25110270_FlashAddrBase
    `endif
`endif

`else
    `define ysyx_25110270_RESET_VECTOR  32'h8000_0000
`endif


// `ifdef ysyx_25110270_SOC
//     `ifdef ysyx_25110270_NOBOOTLOADER
//         `define ysyx_25110270_RESET_VECTOR  `ysyx_25110270_SdramAddrBase
//     `else
//         `define ysyx_25110270_RESET_VECTOR  `ysyx_25110270_FlashAddrBase
//     `endif
// `else
//     `define ysyx_25110270_RESET_VECTOR  32'h8000_0000
// `endif

//------------------------------------------------------------------------
// 取指单元
//------------------------------------------------------------------------

module ysyx_25110270_ifetch
(
    input   wire                        clk,
    input   wire                        rst,

    input   wire                        I_bru_taken,        //跳转指令
    input   wire    [31:0]              I_bru_target,

    input   wire                        I_ready,
    output  wire                        O_valid,

    input   wire                        I_flush,            // 指令冲刷
    input   wire    [31:0]              I_flush_addr,       // 冲刷跳转地址


    output  wire    [31:0]              O_inst,
    output  wire    [31:0]              O_inst_addr,

    //to bus
    output  wire                        ibus_awvalid,
    input   wire                        ibus_awready,
    output  wire    [31:0]              ibus_awaddr,
    output  wire    [3:0]               ibus_awid,
    output  wire    [7:0]               ibus_awlen,
    output  wire    [2:0]               ibus_awsize,
    output  wire    [1:0]               ibus_awburst,
    output  wire                        ibus_wvalid,
    input   wire                        ibus_wready,
    output  wire    [31:0]              ibus_wdata,
    output  wire    [3:0]               ibus_wstrb,
    output  wire                        ibus_wlast,
    input   wire                        ibus_bvalid,
    output  wire                        ibus_bready,
    input   wire    [1:0]               ibus_bresp,
    input   wire    [3:0]               ibus_bid,
    output  wire                        ibus_arvalid,
    input   wire                        ibus_arready,
    output  wire    [31:0]              ibus_araddr,
    output  wire    [3:0]               ibus_arid,
    output  wire    [7:0]               ibus_arlen,
    output  wire    [2:0]               ibus_arsize,
    output  wire    [1:0]               ibus_arburst,
    input   wire                        ibus_rvalid,
    output  wire                        ibus_rready,
    input   wire    [31:0]              ibus_rdata,
    input   wire    [1:0]               ibus_rresp,
    input   wire                        ibus_rlast,
    input   wire    [3:0]               ibus_rid
);

    //------------------------------------------------------------------------
    // 变量定义
    //------------------------------------------------------------------------

    wire resp_valid;
    wire valid;

    reg  [31:0] pc;
    wire [31:0] inst;
    wire [31:0] pc_plus4;

    wire icache_clear = (inst == `ysyx_25110270_RV_FENCE_I) & valid;

    assign valid = I_ready & resp_valid;

    ysyx_25110270_icache 
    #(
        .ADDR_WIDTH             (32                         ),
        .DATA_WIDTH             (32                         ),
        .SET_NUM                (8                          ),
        .N_WAYS                 (1                          ),
        .BLOCK_SIZE             (8                          )
    ) icache
    (
        .clk                    (clk                        ),
        .rst                    (rst                        ),

        .I_valid                (I_ready                    ),
        .O_valid                (resp_valid                 ),

        .I_addr                 (pc                         ),
        .O_data                 (inst                       ),

        .I_clear                (icache_clear               ),

        .O_arvalid              (ibus_arvalid               ),
        .I_arready              (ibus_arready               ),
        .O_araddr               (ibus_araddr                ),
        .O_arlen                (ibus_arlen                 ),
        .O_arsize               (ibus_arsize                ),
        .O_arburst              (ibus_arburst               ),
        .I_rvalid               (ibus_rvalid                ),
        .O_rready               (ibus_rready                ),
        .I_rdata                (ibus_rdata                 ),
        .I_rlast                (ibus_rlast                 ),
        .I_rresp                (ibus_rresp                 )
    );

    always @(posedge clk) begin
        if(rst) begin
            pc <= `ysyx_25110270_RESET_VECTOR;
        end else if(valid) begin     // WAIT
            if(I_flush) begin
                pc <= I_flush_addr;
            end else if(I_bru_taken) begin
                pc <= I_bru_target;
            end else begin
                pc <= pc_plus4;
            end
        end
    end

    assign pc_plus4 = pc + 32'h4;

    assign O_inst = inst;
    assign O_inst_addr = pc;
    assign O_valid = valid;
    
    assign ibus_awvalid = 1'b0;
    assign ibus_awaddr  = 0;
    assign ibus_awid    = 0;
    assign ibus_awlen   = 0;
    assign ibus_awsize  = 0;
    assign ibus_awburst = 2'b00;

    assign ibus_wvalid = 1'b0;
    assign ibus_wdata  = 0;
    assign ibus_wstrb  = 0;
    assign ibus_wlast  = 1'b0;

    assign ibus_bready = 1'b0;

    assign ibus_arid = 0;

`ifdef ysyx_25110270_PERF
    import "DPI-C" function void iamat_cal(input int begin_flag, input int end_flag);

    reg begin_flag_r;
    wire begin_flag = ibus_arvalid;
    wire end_flag   = ibus_rvalid && ibus_rlast;

    always @(posedge clk) begin
        if(rst) begin
            begin_flag_r <= 1'b0;
        end else begin
            begin_flag_r <= begin_flag;
        end
    end


    always @(posedge clk) begin
        if(begin_flag && !begin_flag_r) begin
            iamat_cal(1, 0);
        end else if(end_flag) begin
            iamat_cal(0, 1);
        end
    end

`endif


endmodule

//------------------------------------------------------------------------
// icache
//------------------------------------------------------------------------

module ysyx_25110270_icache
#(
    parameter DATA_WIDTH  = 32,
    parameter ADDR_WIDTH  = 32,
    parameter SET_NUM     = 8,     // direct mapped cache sets
    parameter N_WAYS      = 1,      // number of ways, 1, 2, 4, 8
    parameter BLOCK_SIZE  = 8       // in bytes
)
(
    input                           clk,
    input                           rst,
    input                           I_valid,
    output                          O_valid,
    input       [ADDR_WIDTH-1:0]    I_addr,
    output      [DATA_WIDTH-1:0]    O_data,
    input                           I_clear,

    output                          O_arvalid,
    input                           I_arready,
    output      [ADDR_WIDTH-1:0]    O_araddr,
    output      [7:0]               O_arlen,
    output      [2:0]               O_arsize,
    output      [1:0]               O_arburst,
    input                           I_rvalid,
    output                          O_rready,
    input       [DATA_WIDTH-1:0]    I_rdata,
    input                           I_rlast,
    input       [1:0]               I_rresp

);

    parameter WORD_BYTES        = DATA_WIDTH/8;             
    parameter WORDS_PER_BLOCK   = BLOCK_SIZE / WORD_BYTES;      // 每个block包含的字数
    parameter BLOCK_WIDTH       = $clog2(WORDS_PER_BLOCK);      // 块内字偏移宽度
    parameter SET_WIDTH         = $clog2(SET_NUM);              // 组索引宽度
    parameter TAG_WIDTH         = ADDR_WIDTH - SET_WIDTH - BLOCK_WIDTH - 2; // 标签宽度

    parameter IDLE   = 2'b00;
    parameter REQ    = 2'b01;
    parameter REFILL = 2'b10;

    // 存储器定义
    reg [TAG_WIDTH-1:0] tag_mem [0:SET_NUM*N_WAYS-1];
    reg [DATA_WIDTH-1:0] data_mem [0:SET_NUM*N_WAYS-1][0:WORDS_PER_BLOCK-1];
    reg valid_mem [0:SET_NUM*N_WAYS-1];

    wire [TAG_WIDTH-1:0]               tag;      // 标签位
    wire [SET_WIDTH-1:0]               index;    // 组索引
    wire [BLOCK_WIDTH-1:0]             offset;   // 块内字偏移

    assign tag     = I_addr[ADDR_WIDTH-1 : SET_WIDTH + BLOCK_WIDTH + 2];
    assign index   = I_addr[SET_WIDTH + BLOCK_WIDTH + 1 : BLOCK_WIDTH + 2];
    assign offset  = I_addr[BLOCK_WIDTH + 1 : 2];


    reg [1:0] state;

    wire hit;
    generate
        if(N_WAYS == 1) begin : DIRECT_MAPPED
            assign hit = (tag_mem[index] == tag) & valid_mem[index];
        end else begin : SET_ASSOCIATIVE
            // 多路情况，暂不实现
        end
    endgenerate


    always @(posedge clk) begin
        if(rst) begin
            state <= IDLE;
        end else begin
            case(state)
                IDLE:    state <= I_valid ? (hit ? IDLE : REQ) : IDLE;
                REQ:     state <= I_arready ? REFILL : REQ;
                REFILL:  state <= (I_rvalid && I_rlast) ? IDLE : REFILL;
                default: state <= IDLE;
            endcase
        end
    end

    integer i, j;
    always @(posedge clk) begin
        if(rst || I_clear) begin
            for(i = 0; i < SET_NUM*N_WAYS; i = i + 1) begin
                valid_mem[i] <= 0;
            end
        end else begin
            if(state[1] && I_rvalid) begin
                data_mem[index][I_rlast] <= I_rdata;
                tag_mem[index] <= tag;
                valid_mem[index] <= I_rlast;
            end
        end
    end

    reg [DATA_WIDTH-1:0] odata_r;
    reg ovalid_r;

    always @(posedge clk) begin
        if(rst) begin
            ovalid_r <= 1'b0;
        end else if(I_valid & hit & !ovalid_r) begin
            ovalid_r <= 1'b1;
            odata_r <= data_mem[index][offset];
        end else begin
            ovalid_r <= 1'b0;
        end
    end

    assign O_data  = odata_r;
    assign O_valid = ovalid_r;

    assign O_arvalid = state[0]; // REQ state
    assign O_araddr  = {I_addr[ADDR_WIDTH-1:3], 3'b000};
    assign O_arlen   = WORDS_PER_BLOCK[7:0] - 8'b1;
    assign O_arsize  = 3'b010; // 4 bytes
    assign O_arburst = 2'b01; // INCR
    // assign O_arburst = 2'b10; // WRAP
    assign O_rready  = 1'b0;

endmodule
//------------------------------------------------------------------------
// 分支预测模块
//------------------------------------------------------------------------

module ysyx_25110270_branch_predictor
#(
    parameter SRC_WIDTH = 32
)(
    input   wire                        clk,
    input   wire                        rst,

    input   wire                        update,              // 来自EX阶段的分支预测更新信号
    input   wire    [SRC_WIDTH-1:0]     update_src,          // 来自EX阶段的指令地址
    input   wire    [31:0]              update_dst,          // 来自EX阶段的分支目标地址

    input   wire    [31:0]              inst,
    input   wire    [SRC_WIDTH-1:0]     pc,           // 来自IF阶段的指令地址
    output  wire                        taken,        // 输出到IF阶段的分支是否被预测为采取
    output  wire    [31:0]              target        // 输出到IF阶段的分支目标地址
);

    wire valid;
    wire [31:0] branch_target;

    assign taken = (((inst[6:0] == 7'h63) & inst[31]) | (inst[6:0] == 7'h6f)) & valid;
    assign target = branch_target;

    ysyx_25110270_branch_target_buffer 
    #(
        .SRC_WIDTH              (SRC_WIDTH                  )
    ) btb 
    (
        .clk                    (clk                        ),
        .rst                    (rst                        ),
        .update                 (update                     ),
        .update_src             (update_src                 ),
        .update_dst             (update_dst                 ),
        .source                 (pc                         ),
        .valid                  (valid                      ),
        .target                 (branch_target              )
    );

endmodule

module ysyx_25110270_branch_target_buffer
#(
    parameter SRC_WIDTH = 32
)(
    input   wire                        clk,
    input   wire                        rst,

    input   wire                        update,
    input   wire    [SRC_WIDTH-1:0]     update_src,
    input   wire    [31:0]              update_dst,

    input   wire    [SRC_WIDTH-1:0]     source,
    output  wire                        valid,
    output  wire    [31:0]              target
);

    reg [31:0] btb [0:(1<<SRC_WIDTH)-1];
    reg btb_valid [0:(1<<SRC_WIDTH)-1];

    integer i;
    always @(posedge clk) begin
        if(rst) begin
            for(i = 0; i < (1<<SRC_WIDTH); i = i + 1) begin
                btb_valid[i] <= 0;
            end
        end else if(update) begin
            btb[update_src] <= update_dst;
            btb_valid[update_src] <= 1;
        end
    end

    assign valid = btb_valid[source];
    assign target = btb[source];

endmodule

//------------------------------------------------------------------------
// 译码单元
//------------------------------------------------------------------------

module ysyx_25110270_decoder 
(
    input   wire                                    clk,
    input   wire                                    rst,

    input   wire    [31:0                       ]   I_inst,
    input   wire    [31:0                       ]   I_inst_addr,
    
    input   wire                                    I_ready,
    output  wire                                    O_ready,
    output  wire                                    O_valid,

    output  wire    [`ysyx_25110270_RegAddrBus  ]   O_rs1_raddr,        //regfiles读通用寄存器1地址
    output  wire    [`ysyx_25110270_RegAddrBus  ]   O_rs2_raddr,        //regfiles读通用寄存器2地址       
    output  wire    [`ysyx_25110270_CsrMapBus   ]   O_csr_addr,         //CSR寄存器地址

`ifdef ysyx_25110270_DPIC
    output  wire    [31:0                       ]   O_inst,             //指令内容
`endif

`ifdef __ICARUS__
    output  wire    [31:0                       ]   O_inst,             //指令内容
`endif

    output  wire    [31:0                       ]   O_inst_addr,        //指令地址

    output  wire    [31:0                       ]   O_imm,              //立即数
    output  wire                                    O_rd_we,            //写通用寄存器标志
    output  wire    [`ysyx_25110270_RegAddrBus  ]   O_rd_waddr,         //写通用寄存器地址
    output  wire    [2:0                        ]   O_op,

    output  wire    [1:0                        ]   O_alu_srca_sel,
    output  wire    [1:0                        ]   O_alu_srcb_sel,
    output  wire    [1:0                        ]   O_agu_src_sel,
    output  wire                                    O_csr_src_sel,
    
    output  wire                                    O_ld_valid,         //访存有效标志
    output  wire                                    O_st_valid,         //访存有效标志
    output  wire                                    O_br_valid,         //跳转有效标志
    output  wire                                    O_csr_valid,        //CSR指令有效标志
    output  wire                                    O_f7b5_en,          //funct7[5]使能，针对srai, sub, sra指令
    output  wire                                    O_sign,             //有符号位
    output  wire    [`ysyx_25110270_ExceptBus   ]   O_except,

    //forward
    output  wire                                    O_rs1_re,
    output  wire                                    O_rs2_re
);
    
    //------------------------------------------------------------------------
    // 指令解码
    //------------------------------------------------------------------------
    wire [6:0]  opcode;
    wire [2:0]  funct3;
    wire [6:0]  funct7;
    wire [3:0]  rd;
    wire [3:0]  rs1;
    wire [3:0]  rs2;

    ysyx_25110270_RV32_Inst_Unpack inst_unpack
    (
        .I_inst                 (I_inst                     ),
        .opcode                 (opcode                     ),
        .funct3                 (funct3                     ),
        .funct7                 (funct7                     ),
        .rd                     (rd                         ),
        .rs1                    (rs1                        ),
        .rs2                    (rs2                        )
    );

    //------------------------------------------------------------------------
    // 立即数生成
    //------------------------------------------------------------------------
    wire [31:0] rv32i_i_type_imm = {{20{I_inst[31]}}, I_inst[31:20]};
    wire [31:0] rv32i_s_type_imm = {{20{I_inst[31]}}, I_inst[31:25], I_inst[11:7]};
    wire [31:0] rv32i_u_type_imm = {I_inst[31:12], 12'b0};
    wire [31:0] rv32i_b_type_imm = {{20{I_inst[31]}}, I_inst[7], I_inst[30:25], I_inst[11:8], 1'b0};
    wire [31:0] rv32i_j_type_imm = {{12{I_inst[31]}}, I_inst[19:12], I_inst[20], I_inst[30:21], 1'b0};
    wire [31:0] rv_csr_type_imm  = {27'h0, I_inst[19:15]};

    reg [31:0] imm;
    always @(*) begin
        case(opcode)
            `ysyx_25110270_RV32I_OP_TYPE_IL,
            `ysyx_25110270_RV32I_OP_TYPE_I,
            `ysyx_25110270_RV32I_OP_JALR:       imm = rv32i_i_type_imm;

            `ysyx_25110270_RV32I_OP_TYPE_S:     imm = rv32i_s_type_imm;

            `ysyx_25110270_RV32I_OP_AUIPC,
            `ysyx_25110270_RV32I_OP_LUI:        imm = rv32i_u_type_imm;

            `ysyx_25110270_RV32I_OP_TYPE_B:     imm = rv32i_b_type_imm;
            `ysyx_25110270_RV32I_OP_JAL:        imm = rv32i_j_type_imm;
            `ysyx_25110270_RV_OP_CSR:           imm = rv_csr_type_imm;
            default:                            imm = 0;
        endcase
    end

    //------------------------------------------------------------------------
    // 控制信号生成
    //------------------------------------------------------------------------

    /*=======================================================================
        [18:16]:    op
        [15   ]:    csr_src_sel
        [14:13]:    agu_src_sel  
        [12:11]:    alu_srcb_sel
        [10:9 ]:    alu_srca_sel
        [8    ]:    f7b5_en    ---> srai, sub, sra
        [7    ]:    csr_valid
        [6    ]:    br_valid
        [5    ]:    st_valid
        [4    ]:    ld_valid
        [3    ]:    sign
        [2    ]:    rs2_re
        [1    ]:    rs1_re
        [0    ]:    rd_we
    ========================================================================*/
    
    localparam bit_rd_we     = 0;
    localparam bit_rs1_re    = 1;
    localparam bit_rs2_re    = 2;
    localparam bit_sign      = 3;
    localparam bit_ld_valid  = 4;
    localparam bit_st_valid  = 5;
    localparam bit_br_valid  = 6;
    localparam bit_csr_valid = 7;
    localparam bit_f7b5_en   = 8;
    localparam bit_alu_srca  = 9;
    localparam bit_alu_srcb  = 11;
    localparam bit_agu_src   = 13;
    localparam bit_csr_src   = 15;
    localparam bit_op        = 16;

    reg [18:0] basic_ctrl;

    always @(*) begin
        basic_ctrl = 0;
        case(opcode)
            `ysyx_25110270_RV32I_OP_TYPE_IL: begin
                basic_ctrl[bit_rd_we        ] = 1'b1;
                basic_ctrl[bit_rs1_re       ] = 1'b1;
                basic_ctrl[bit_ld_valid     ] = 1'b1;
                basic_ctrl[bit_agu_src +: 2 ] = `ysyx_25110270_AGUSRC_RS1;
                basic_ctrl[bit_op +: 3      ] = funct3;
            end
            `ysyx_25110270_RV32I_OP_TYPE_I: begin
                basic_ctrl[bit_rd_we        ] = 1'b1;
                basic_ctrl[bit_rs1_re       ] = 1'b1;
                basic_ctrl[bit_sign         ] = (funct3 != `ysyx_25110270_RV32I_F3_SLTIU);  // no sltiu
                basic_ctrl[bit_f7b5_en      ] = I_inst[30] & (funct3 == `ysyx_25110270_RV32I_F3_SRI);  // only srai has funct7[5] = 1
                basic_ctrl[bit_alu_srca +: 2] = `ysyx_25110270_ALUSRCA_RS1;
                basic_ctrl[bit_alu_srcb +: 2] = `ysyx_25110270_ALUSRCB_IMM;
                basic_ctrl[bit_op +: 3      ] = funct3;
            end
            `ysyx_25110270_RV32I_OP_AUIPC: begin
                basic_ctrl[bit_rd_we        ] = 1'b1;
                basic_ctrl[bit_sign         ] = 1'b1;
                basic_ctrl[bit_alu_srca +: 2] = `ysyx_25110270_ALUSRCA_PC;
                basic_ctrl[bit_alu_srcb +: 2] = `ysyx_25110270_ALUSRCB_IMM;
                basic_ctrl[bit_op +: 3      ] = `ysyx_25110270_RV32I_F3_ADD_SUB;
            end
            `ysyx_25110270_RV32I_OP_LUI: begin
                basic_ctrl[bit_rd_we        ] = 1'b1;
                basic_ctrl[bit_sign         ] = 1'b1;
                basic_ctrl[bit_alu_srca +: 2] = `ysyx_25110270_ALUSRCA_0;
                basic_ctrl[bit_alu_srcb +: 2] = `ysyx_25110270_ALUSRCB_IMM;
                basic_ctrl[bit_op +: 3      ] = `ysyx_25110270_RV32I_F3_ADD_SUB;
            end
            `ysyx_25110270_RV32I_OP_TYPE_S: begin
                basic_ctrl[bit_rs1_re       ] = 1'b1;
                basic_ctrl[bit_rs2_re       ] = 1'b1;
                basic_ctrl[bit_st_valid     ] = 1'b1;
                basic_ctrl[bit_agu_src +: 2 ] = `ysyx_25110270_AGUSRC_RS1;
                basic_ctrl[bit_op +: 3      ] = funct3;
            end
            `ysyx_25110270_RV32IM_OP_TYPE_R: begin
                basic_ctrl[bit_rd_we        ] = 1'b1;
                basic_ctrl[bit_rs1_re       ] = 1'b1;
                basic_ctrl[bit_rs2_re       ] = 1'b1;
                basic_ctrl[bit_sign         ] = (funct3 != `ysyx_25110270_RV32I_F3_SLTU);  // no sltu
                basic_ctrl[bit_f7b5_en      ] = I_inst[30];
                basic_ctrl[bit_alu_srca +: 2] = `ysyx_25110270_ALUSRCA_RS1;
                basic_ctrl[bit_alu_srcb +: 2] = `ysyx_25110270_ALUSRCB_RS2;
                basic_ctrl[bit_op +: 3      ] = funct3;
            end
            `ysyx_25110270_RV32I_OP_TYPE_B: begin
                basic_ctrl[bit_rs1_re       ] = 1'b1;
                basic_ctrl[bit_rs2_re       ] = 1'b1;
                basic_ctrl[bit_sign         ] = ~(funct3[2] & funct3[1]);   // no bltu, bgeu
                basic_ctrl[bit_br_valid     ] = 1'b1;
                basic_ctrl[bit_alu_srca +: 2] = `ysyx_25110270_ALUSRCA_RS1;
                basic_ctrl[bit_alu_srcb +: 2] = `ysyx_25110270_ALUSRCB_RS2;
                basic_ctrl[bit_agu_src +: 2 ] = `ysyx_25110270_AGUSRC_PC;
                basic_ctrl[bit_op +: 3      ] = funct3;
            end
            `ysyx_25110270_RV32I_OP_JALR: begin
                basic_ctrl[bit_rd_we        ] = 1'b1;
                basic_ctrl[bit_rs1_re       ] = 1'b1;
                basic_ctrl[bit_sign         ] = 1'b1;
                basic_ctrl[bit_br_valid     ] = 1'b1;
                basic_ctrl[bit_alu_srca +: 2] = `ysyx_25110270_ALUSRCA_PC;
                basic_ctrl[bit_alu_srcb +: 2] = `ysyx_25110270_ALUSRCB_4;
                basic_ctrl[bit_agu_src +: 2 ] = `ysyx_25110270_AGUSRC_RS1;
                basic_ctrl[bit_op +: 3      ] = 3'b011;                      // for jalr, jal, remap funct3 to 3'b011 to simplify control logic
            end
            `ysyx_25110270_RV32I_OP_JAL: begin
                basic_ctrl[bit_rd_we        ] = 1'b1;
                basic_ctrl[bit_rs1_re       ] = 1'b1;
                basic_ctrl[bit_sign         ] = 1'b1;
                basic_ctrl[bit_br_valid     ] = 1'b1;                        // br_valid + funct3 == 011 ---->  alu_add
                basic_ctrl[bit_alu_srca +: 2] = `ysyx_25110270_ALUSRCA_PC;
                basic_ctrl[bit_alu_srcb +: 2] = `ysyx_25110270_ALUSRCB_4;
                basic_ctrl[bit_agu_src +: 2 ] = `ysyx_25110270_AGUSRC_PC;
                basic_ctrl[bit_op +: 3      ] = 3'b011;                      // for jalr, jal, remap funct3 to 3'b011 to simplify control logic
            end
            `ysyx_25110270_RV_OP_CSR: begin
                basic_ctrl[bit_rd_we        ] = funct3 != 0;
                basic_ctrl[bit_rs1_re       ] = ~funct3[2];  // no csrrwi, csrrsi, csrrci
                basic_ctrl[bit_csr_valid    ] = funct3 != 0;
                basic_ctrl[bit_csr_src      ] = funct3[2];   // 1 for imm, 0 for rs1
                basic_ctrl[bit_op +: 3      ] = funct3;
            end
            default: begin end
        endcase
    end

    //------------------------------------------------------------------------
    // 异常解码
    //------------------------------------------------------------------------
    wire [`ysyx_25110270_ExceptBus ] except;
    ysyx_25110270_dec_except dec_except
    (
        .I_inst                 (I_inst                     ),
        .O_except               (except                     )
    );

    assign O_except = except;

    //------------------------------------------------------------------------
    // csr重映射
    //------------------------------------------------------------------------
    wire [`ysyx_25110270_CsrMapBus ] csr_map;
    ysyx_25110270_csr_mapout csr_mapout
    (
        .I_csr_addr             (I_inst[31:20]              ),
        .O_csr_map              (csr_map                    )
    );

    assign O_csr_addr = csr_map;

    //------------------------------------------------------------------------
    // 输出
    //------------------------------------------------------------------------
`ifdef ysyx_25110270_DPIC
    assign O_inst = I_inst;
`endif
`ifdef __ICARUS__
    assign O_inst = I_inst;
`endif
    assign O_inst_addr = I_inst_addr;
    
    assign O_ready = I_ready;
    assign O_valid = O_ready;

    assign O_rs1_raddr = rs1;
    assign O_rs2_raddr = rs2;
    assign O_rd_waddr = rd;

    assign O_imm = imm;
    assign O_rd_we = basic_ctrl[bit_rd_we];

    assign O_op = basic_ctrl[bit_op +: 3];

    assign O_ld_valid = basic_ctrl[bit_ld_valid];
    assign O_st_valid = basic_ctrl[bit_st_valid];
    assign O_csr_valid = basic_ctrl[bit_csr_valid];
    assign O_br_valid = basic_ctrl[bit_br_valid];
    assign O_f7b5_en = basic_ctrl[bit_f7b5_en];
    assign O_sign = basic_ctrl[bit_sign];

    assign O_rs1_re = basic_ctrl[bit_rs1_re];
    assign O_rs2_re = basic_ctrl[bit_rs2_re];

    assign O_alu_srca_sel = basic_ctrl[bit_alu_srca +: 2];
    assign O_alu_srcb_sel = basic_ctrl[bit_alu_srcb +: 2];
    assign O_agu_src_sel  = basic_ctrl[bit_agu_src +: 2];
    assign O_csr_src_sel  = basic_ctrl[bit_csr_src];

endmodule

//------------------------------------------------------------------------
// 指令解包模块
//------------------------------------------------------------------------

module ysyx_25110270_RV32_Inst_Unpack
(
    input   wire    [31:0]  I_inst,
    output  wire    [6:0 ]  opcode,
    output  wire    [2:0 ]  funct3,
    output  wire    [6:0 ]  funct7,
    output  wire    [3:0 ]  rd,
    output  wire    [3:0 ]  rs1,
    output  wire    [3:0 ]  rs2
);

    assign opcode = I_inst[6:0];
    assign rd     = I_inst[10:7];
    assign funct3 = I_inst[14:12];
    assign rs1    = I_inst[18:15];
    assign rs2    = I_inst[23:20];
    assign funct7 = I_inst[31:25];

endmodule

//------------------------------------------------------------------------
// CSR寄存器重映射
//------------------------------------------------------------------------
module ysyx_25110270_csr_mapout
(
    input   wire    [11:0                       ]   I_csr_addr,
    output  wire    [`ysyx_25110270_CsrMapBus   ]   O_csr_map
);

    reg [`ysyx_25110270_CsrMapBus] csr_map;
    always @(*) begin
        case(I_csr_addr)
            `ysyx_25110270_CSR_MSTATUS      : csr_map =  `ysyx_25110270_CSR_MAP_MSTATUS;
            `ysyx_25110270_CSR_MCAUSE       : csr_map =  `ysyx_25110270_CSR_MAP_MCAUSE;
            `ysyx_25110270_CSR_MTVEC        : csr_map =  `ysyx_25110270_CSR_MAP_MTVEC;
            `ysyx_25110270_CSR_MEPC         : csr_map =  `ysyx_25110270_CSR_MAP_MEPC;
            `ysyx_25110270_CSR_CYCLE        : csr_map =  `ysyx_25110270_CSR_MAP_CYCLE;
            `ysyx_25110270_CSR_CYCLEH       : csr_map =  `ysyx_25110270_CSR_MAP_CYCLEH;
            `ysyx_25110270_CSR_MVENDORID    : csr_map =  `ysyx_25110270_CSR_MAP_MVENDORID;
            `ysyx_25110270_CSR_MARCHID      : csr_map =  `ysyx_25110270_CSR_MAP_MARCHID;
            default                         : csr_map =  0;
        endcase
    end

    assign O_csr_map = csr_map;

endmodule

//------------------------------------------------------------------------
// 异常指令译码单元
//------------------------------------------------------------------------
module ysyx_25110270_dec_except
(
    input   wire    [31:0                       ]   I_inst,
    output  wire    [`ysyx_25110270_ExceptBus   ]   O_except
);

    // 异常指令
    assign O_except[`ysyx_25110270_EXCPT_ECALL  ] = (I_inst == `ysyx_25110270_RV_ECALL  );
    assign O_except[`ysyx_25110270_EXCPT_MRET   ] = (I_inst == `ysyx_25110270_RV_MRET   );

endmodule
//------------------------------------------------------------------------
// hazard unit
//------------------------------------------------------------------------

module ysyx_25110270_hazard_unit
(
    input   wire                                    I_rs1_re,
    input   wire                                    I_rs2_re,

    input   wire    [`ysyx_25110270_RegAddrBus  ]   I_rs1_raddr,      //读寄存器1地址
    input   wire    [`ysyx_25110270_RegAddrBus  ]   I_rs2_raddr,

    input   wire                                    I_ex_rd_we,
    input   wire    [`ysyx_25110270_RegAddrBus  ]   I_ex_rd_waddr,

    input   wire                                    I_csr_valid,
    input   wire    [`ysyx_25110270_CsrMapBus   ]   I_csr_raddr,

    input   wire                                    I_ex_csr_valid,
    input   wire    [`ysyx_25110270_CsrMapBus   ]   I_ex_csr_waddr,

    output  wire                                    O_fwd_ctrl_rs1,
    output  wire                                    O_fwd_ctrl_rs2,
    output  wire                                    O_fwd_ctrl_csr
);

    wire ex_same_addr_rs1 = I_ex_rd_waddr == I_rs1_raddr;
    wire ex_same_addr_rs2 = I_ex_rd_waddr == I_rs2_raddr;
    wire ex_same_addr_csr = I_ex_csr_waddr == I_csr_raddr;

    wire use_ex_data_rs1 = I_ex_rd_we & ex_same_addr_rs1;
    wire use_ex_data_rs2 = I_ex_rd_we & ex_same_addr_rs2;
    wire use_ex_data_csr = I_ex_csr_valid & ex_same_addr_csr;


    wire fwd_ctrl_rs1 = (I_rs1_re & I_rs1_raddr != 0 & use_ex_data_rs1) ? 
                        `ysyx_25110270_FWDSRC_EX : `ysyx_25110270_FWDSRC_NFW;

    wire fwd_ctrl_rs2 = (I_rs2_re & I_rs2_raddr != 0 & use_ex_data_rs2) ? 
                        `ysyx_25110270_FWDSRC_EX : `ysyx_25110270_FWDSRC_NFW;

    wire fwd_ctrl_csr = (I_csr_valid & use_ex_data_csr) ? 
                        `ysyx_25110270_FWDSRC_EX : `ysyx_25110270_FWDSRC_NFW;

    assign O_fwd_ctrl_rs1 = fwd_ctrl_rs1;
    assign O_fwd_ctrl_rs2 = fwd_ctrl_rs2;
    assign O_fwd_ctrl_csr = fwd_ctrl_csr;

endmodule

//------------------------------------------------------------------------
// 执行模块
//------------------------------------------------------------------------

module ysyx_25110270_exec
(
    input   wire                                    clk,
    input   wire                                    rst,

`ifdef ysyx_25110270_DPIC
    input   wire    [31:0                       ]   I_inst,
`endif
`ifdef __ICARUS__
    input   wire    [31:0                       ]   I_inst,
`endif

    input   wire    [31:0                       ]   I_inst_addr,

    input   wire                                    I_valid,
    output  wire                                    O_ready,
    output  wire                                    O_valid,

    input   wire                                    I_rd_we,
    input   wire    [`ysyx_25110270_RegAddrBus  ]   I_rd_waddr,
    input   wire    [31:0                       ]   I_imm,
    input   wire    [1:0                        ]   I_alu_srca_sel,
    input   wire    [1:0                        ]   I_alu_srcb_sel,
    input   wire    [1:0                        ]   I_agu_src_sel,
    input   wire                                    I_csr_src_sel,

    input   wire                                    I_ld_valid,         //访存有效标志
    input   wire                                    I_st_valid,         //访存有效标志
    input   wire                                    I_br_valid,         //跳转指令标志
    input   wire                                    I_csr_valid,        //CSR指令标志
    input   wire                                    I_f7b5_en,          //指令funct7=0x7b或0x5时有效
    input   wire                                    I_sign,             //有符号位
    input   wire    [2:0                        ]   I_op,
    input   wire    [`ysyx_25110270_CsrMapBus   ]   I_csr_addr,
    input   wire    [`ysyx_25110270_ExceptBus   ]   I_except,             //异常

    input   wire                                    I_fwd_ctrl_rs1,
    input   wire                                    I_fwd_ctrl_rs2,
    input   wire                                    I_fwd_ctrl_csr,

    input   wire    [31:0                       ]   I_rs1_rdata,
    input   wire    [31:0                       ]   I_rs2_rdata,
    input   wire    [31:0                       ]   I_csr_rdata,

    input   wire    [31:0                       ]   I_fwd_old_rs_data,      //转发的旧数据
    input   wire    [31:0                       ]   I_fwd_old_csr_data,     //转发的旧数据

`ifdef ysyx_25110270_DPIC
    output  wire    [31:0                       ]   O_inst,
    output  wire                                    O_device_skip,
`endif

`ifdef __ICARUS__
    output  wire    [31:0                       ]   O_inst,
`endif

    output  wire    [31:0                       ]   O_inst_addr,

    output  wire                                    O_rd_we,
    output  wire    [`ysyx_25110270_RegAddrBus  ]   O_rd_waddr,
    output  wire    [31:0                       ]   O_rd_wdata,

    output  wire                                    O_csr_valid,
    output  wire    [`ysyx_25110270_CsrMapBus   ]   O_csr_addr,
    output  wire    [31:0                       ]   O_csr_wdata,

    output  wire    [`ysyx_25110270_ExceptBus   ]   O_except,

    //bru
    output  wire                                    O_bru_taken,
    output  wire    [31:0                       ]   O_bru_target,

    //to bus
    output  wire                                    dbus_awvalid,
    input   wire                                    dbus_awready,
    output  wire    [31:0]                          dbus_awaddr,
    output  wire    [3:0 ]                          dbus_awid,
    output  wire    [7:0 ]                          dbus_awlen,
    output  wire    [2:0 ]                          dbus_awsize,
    output  wire    [1:0 ]                          dbus_awburst,
    output  wire                                    dbus_wvalid,
    input   wire                                    dbus_wready,
    output  wire    [31:0]                          dbus_wdata,
    output  wire    [3:0 ]                          dbus_wstrb,
    output  wire                                    dbus_wlast,
    input   wire                                    dbus_bvalid,
    output  wire                                    dbus_bready,
    input   wire    [1:0 ]                          dbus_bresp,
    input   wire    [3:0 ]                          dbus_bid,
    output  wire                                    dbus_arvalid,
    input   wire                                    dbus_arready,
    output  wire    [31:0]                          dbus_araddr,
    output  wire    [3:0 ]                          dbus_arid,
    output  wire    [7:0 ]                          dbus_arlen,
    output  wire    [2:0 ]                          dbus_arsize,
    output  wire    [1:0 ]                          dbus_arburst,
    input   wire                                    dbus_rvalid,
    output  wire                                    dbus_rready,
    input   wire    [31:0]                          dbus_rdata,
    input   wire    [1:0 ]                          dbus_rresp,
    input   wire                                    dbus_rlast,
    input   wire    [3:0 ]                          dbus_rid

);
    //------------------------------------------------------------------------
    // fwd选择
    //------------------------------------------------------------------------
    wire [31:0] final_rs1_rdata = I_fwd_ctrl_rs1 ? I_fwd_old_rs_data : I_rs1_rdata;
    wire [31:0] final_rs2_rdata = I_fwd_ctrl_rs2 ? I_fwd_old_rs_data : I_rs2_rdata;
    wire [31:0] final_csr_rdata = I_fwd_ctrl_csr ? I_fwd_old_csr_data : I_csr_rdata;

    //------------------------------------------------------------------------
    // src选择
    //------------------------------------------------------------------------
    reg [31:0] alu_srca;
    reg [31:0] alu_srcb;
    reg [31:0] agu_src;

    always @(*) begin
        case(I_alu_srca_sel)
            `ysyx_25110270_ALUSRCA_RS1: alu_srca = final_rs1_rdata;
            `ysyx_25110270_ALUSRCA_PC:  alu_srca = I_inst_addr;
            default:                    alu_srca = 0;
        endcase
    end

    always @(*) begin
        case(I_alu_srcb_sel)
            `ysyx_25110270_ALUSRCB_RS2: alu_srcb = final_rs2_rdata;
            `ysyx_25110270_ALUSRCB_IMM: alu_srcb = I_imm;
            `ysyx_25110270_ALUSRCB_4:   alu_srcb = 4;
            default:                    alu_srcb = 0;
        endcase
    end

    always @(*) begin
        case(I_agu_src_sel)
            `ysyx_25110270_AGUSRC_RS1:  agu_src = final_rs1_rdata;
            `ysyx_25110270_AGUSRC_PC:   agu_src = I_inst_addr;
            default:                    agu_src = 0;
        endcase
    end

    wire [31:0] csr_src = I_csr_src_sel ? I_imm : final_rs1_rdata;

    //------------------------------------------------------------------------
    // alu运算
    //------------------------------------------------------------------------
    wire src_eq, src_lt;
    wire [31:0] alu_result;

    wire [2:0] alu_op = (I_op == 3'b011 & I_br_valid) ? `ysyx_25110270_RV32I_F3_ADD_SUB : I_op;  // jal, jalr指令需要加法运算

    ysyx_25110270_alu alu
    (
        .I_alu_srca                 (alu_srca               ),
        .I_alu_srcb                 (alu_srcb               ),
        .I_sign                     (I_sign                 ),
        .I_f7b5_en                  (I_f7b5_en              ),
        .I_alu_ctrl                 (alu_op                 ),
        .O_alu_result               (alu_result             ),
        .O_eq                       (src_eq                 ),
        .O_lt                       (src_lt                 )
    );

    //------------------------------------------------------------------------
    // agu运算
    //------------------------------------------------------------------------
    wire [31:0] agu_result;
    assign agu_result = agu_src + I_imm;

    //------------------------------------------------------------------------
    // bru运算
    //------------------------------------------------------------------------
    wire bru_taken;
    ysyx_25110270_bru bru
    (
        .I_src_eq                   (src_eq                 ),
        .I_src_lt                   (src_lt                 ),
        .I_bru_ctrl                 (I_op                   ),
        .O_bru_taken                (bru_taken              )
    );


    //------------------------------------------------------------------------
    // csr运算
    //------------------------------------------------------------------------
    wire [31:0] csr_wdata;
    ysyx_25110270_csr_exe csr_exe
    (
        .I_csr_src                  (csr_src                ),
        .I_csr_rdata                (I_csr_rdata            ),
        .I_csr_ctrl                 (I_op[1:0]              ),
        .O_csr_wdata                (csr_wdata              )
    );

    //------------------------------------------------------------------------
    // ex2 pipeline
    //------------------------------------------------------------------------
    reg [31:0] agu_result_r;

    reg [31:0] store_data;
    reg [2:0] ls_ctrl;

    wire [31:0] rd_wdata;

    always @(posedge clk) begin
        if(rst) begin
            ls_ctrl <= 0;
        end else begin
            agu_result_r <= agu_result;
            store_data <= final_rs2_rdata;
            ls_ctrl <= (I_ld_valid | I_st_valid) ? I_op : 3'b111;
        end
    end

    wire stallreq_ls;

    wire stallreq = stallreq_ls;

`ifdef ysyx_25110270_DPIC
    wire device_skip;
`endif

    ysyx_25110270_lsu lsu
    (
        .clk                        (clk                    ),
        .rst                        (rst                    ),

`ifdef ysyx_25110270_DEBUG
        .I_inst_addr                (I_inst_addr            ),
`endif

        .I_valid                    (I_valid                ),

        .I_alu_result               (alu_result             ),
        .I_csr_valid                (I_csr_valid            ),
        .I_csr_rdata                (final_csr_rdata        ),

        .I_ld_valid                 (I_ld_valid             ),
        .I_st_valid                 (I_st_valid             ),
        .I_ls_ctrl                  (ls_ctrl                ),
        .I_memory_addr              (agu_result_r           ),
        .I_store_data               (store_data             ),

        .O_rd_wdata                 (rd_wdata               ),
        .O_stallreq                 (stallreq_ls            ),

`ifdef ysyx_25110270_DPIC
        .O_device_skip              (device_skip            ),
`endif

        .dbus_awvalid               (dbus_awvalid           ),
        .dbus_awready               (dbus_awready           ),
        .dbus_awaddr                (dbus_awaddr            ),
        .dbus_awid                  (dbus_awid              ),
        .dbus_awlen                 (dbus_awlen             ),
        .dbus_awsize                (dbus_awsize            ),
        .dbus_awburst               (dbus_awburst           ),
        .dbus_wvalid                (dbus_wvalid            ),
        .dbus_wready                (dbus_wready            ),
        .dbus_wdata                 (dbus_wdata             ),
        .dbus_wstrb                 (dbus_wstrb             ),
        .dbus_wlast                 (dbus_wlast             ),
        .dbus_bvalid                (dbus_bvalid            ),
        .dbus_bready                (dbus_bready            ),
        .dbus_bresp                 (dbus_bresp             ),
        .dbus_bid                   (dbus_bid               ),
        .dbus_arvalid               (dbus_arvalid           ),
        .dbus_arready               (dbus_arready           ),
        .dbus_araddr                (dbus_araddr            ),
        .dbus_arid                  (dbus_arid              ),
        .dbus_arlen                 (dbus_arlen             ),
        .dbus_arsize                (dbus_arsize            ),
        .dbus_arburst               (dbus_arburst           ),
        .dbus_rvalid                (dbus_rvalid            ),
        .dbus_rready                (dbus_rready            ),
        .dbus_rdata                 (dbus_rdata             ),
        .dbus_rresp                 (dbus_rresp             ),
        .dbus_rlast                 (dbus_rlast             ),
        .dbus_rid                   (dbus_rid               )
    );


    //------------------------------------------------------------------------
    // 输出
    //------------------------------------------------------------------------
`ifdef ysyx_25110270_DPIC
    assign O_inst = I_inst;
`endif

`ifdef __ICARUS__
    assign O_inst = I_inst;
`endif

    assign O_inst_addr = I_inst_addr;

    assign O_ready = ~stallreq;
    assign O_valid = O_ready;

    assign O_rd_we = I_rd_we;
    assign O_rd_waddr = I_rd_waddr;
    assign O_rd_wdata = rd_wdata;

    assign O_csr_valid = I_csr_valid;
    assign O_csr_addr = I_csr_addr;
    assign O_csr_wdata = csr_wdata;

    assign O_bru_taken = bru_taken & I_br_valid;
    assign O_bru_target = agu_result;

    assign O_except = I_except;



`ifdef ysyx_25110270_DPIC
    import "DPI-C" function void ftrace_exec(input int pc, input int dnpc, input int rs1, input int rd, input int imm, input int op); //op=1 jal, op=2 jalr

    assign O_device_skip = device_skip;
    wire [3:0] rs1 = I_inst[18:15];

    always @(*) begin
        if(I_br_valid & (I_op == 3'b011) & I_agu_src_sel == `ysyx_25110270_AGUSRC_PC) begin
            ftrace_exec(I_inst_addr, O_bru_target, rs1, O_rd_waddr, I_imm, 1);
        end else if(I_br_valid & (I_op == 3'b011) & I_agu_src_sel == `ysyx_25110270_AGUSRC_RS1) begin
            ftrace_exec(I_inst_addr, O_bru_target, rs1, O_rd_waddr, I_imm, 2);
        end
    end

`endif


endmodule //exu

//------------------------------------------------------------------------
// ALU模块
//------------------------------------------------------------------------

module ysyx_25110270_alu
(
    input   wire    [31:0                       ]   I_alu_srca,
    input   wire    [31:0                       ]   I_alu_srcb,
    input   wire                                    I_sign,             // 有符号位
    input   wire                                    I_f7b5_en,          // 指令funct7[5] = 1
    input   wire    [2:0                        ]   I_alu_ctrl,
    output  wire    [31:0                       ]   O_alu_result,

    output  wire                                    O_eq,
    output  wire                                    O_lt
);

    wire adder_sign = I_sign;
    wire adder_sub = I_f7b5_en | (I_alu_ctrl != `ysyx_25110270_RV32I_F3_ADD_SUB); // no add

    wire [32:0] adder_s1 = {adder_sign & I_alu_srca[31], I_alu_srca};
    wire [32:0] adder_s2 = {adder_sign & I_alu_srcb[31], I_alu_srcb} ^ {{33{adder_sub}}};

    wire [31:0] rv32i_add_res;
    wire adder_cout;

    assign {adder_cout, rv32i_add_res} = adder_s1 + adder_s2 + {{32{1'b0}}, adder_sub};

    wire [31:0] rv32i_shift_res;
    wire [31:0] rv32i_xor_res     = I_alu_srca ^ I_alu_srcb;
    wire [31:0] rv32i_or_res      = I_alu_srca | I_alu_srcb;
    wire [31:0] rv32i_and_res     = I_alu_srca & I_alu_srcb;

    reg [31:0] res; 
    always @(*) begin
        case(I_alu_ctrl)
            `ysyx_25110270_RV32I_F3_ADD_SUB:
                res = rv32i_add_res;
            `ysyx_25110270_RV32I_F3_SLL, `ysyx_25110270_RV32I_F3_SR:
                res = rv32i_shift_res;
            `ysyx_25110270_RV32I_F3_SLT, `ysyx_25110270_RV32I_F3_SLTU:
                res = {31'b0, adder_cout};
            `ysyx_25110270_RV32I_F3_XOR:
                res = rv32i_xor_res;
            `ysyx_25110270_RV32I_F3_OR: 
                res = rv32i_or_res;
            `ysyx_25110270_RV32I_F3_AND:
                res = rv32i_and_res;
            default:
                res = 0;
        endcase
    end

    ysyx_25110270_barrel_shift
    #(
        .WIDTH                  (32                                         )
    ) barrel_shift
    (
        .I_shift_src            (I_alu_srca                                 ),
        .I_shift_amt            (I_alu_srcb[4:0]                            ),
        .I_shift_right          (I_alu_ctrl[2]                              ),  // srl, srli指令右移
        .I_shift_arith          (I_f7b5_en                                  ),

        .O_shift_result         (rv32i_shift_res                            )
    );

    assign O_alu_result = res;
    assign O_eq = (I_alu_srca == I_alu_srcb);
    assign O_lt = adder_cout;
    
endmodule
    
//------------------------------------------------------------------------
// 分支判断模块
//------------------------------------------------------------------------

module ysyx_25110270_bru
(
    input   wire                                    I_src_eq,
    input   wire                                    I_src_lt,
    input   wire    [2:0]                           I_bru_ctrl,
    
    output  wire                                    O_bru_taken
);
    reg bru_taken;

    wire eq = I_src_eq;
    wire neq = ~I_src_eq;
    wire lt = I_src_lt;
    wire ge = ~I_src_lt;

    always @(*) begin
        case(I_bru_ctrl)
            `ysyx_25110270_RV32I_F3_BEQ:  bru_taken = eq;
            `ysyx_25110270_RV32I_F3_BNE:  bru_taken = neq;
            3'b011                     :  bru_taken = 1'b1;         // jal, jalr指令无条件跳转
            `ysyx_25110270_RV32I_F3_BLT:  bru_taken = lt;
            `ysyx_25110270_RV32I_F3_BLTU: bru_taken = lt;
            `ysyx_25110270_RV32I_F3_BGE:  bru_taken = ge;
            `ysyx_25110270_RV32I_F3_BGEU: bru_taken = ge;
            default:                      bru_taken = 1'b0;
        endcase
    end

    assign O_bru_taken = bru_taken;


endmodule

//------------------------------------------------------------------------
// 桶式移位模块
//------------------------------------------------------------------------
module ysyx_25110270_barrel_shift 
#(
    parameter WIDTH = 32
)(
    input   wire    [WIDTH-1:0      ]   I_shift_src,
    input   wire    [4:0            ]   I_shift_amt,
    input   wire                        I_shift_right,     // 1: right shift   0: left shift
    input   wire                        I_shift_arith,     // 1: arithmetic    0: logical

    output  wire    [WIDTH-1:0      ]   O_shift_result
);

    wire [WIDTH-1:0] stage0, stage1, stage2, stage3, stage4;
    wire [WIDTH-1:0] data_reversed;

    genvar i;
    generate
        for (i = 0; i < WIDTH; i = i + 1) begin: reverse_gen
            assign data_reversed[i] = I_shift_src[WIDTH-1-i];
        end
    endgenerate

    wire [WIDTH-1:0] shift_src = I_shift_right ? I_shift_src : data_reversed;
    wire fill_bit = I_shift_arith ? I_shift_src[WIDTH-1] : 1'b0;

    assign stage0 = I_shift_amt[0] ? {fill_bit, shift_src[WIDTH-1:1]}     : shift_src;
    assign stage1 = I_shift_amt[1] ? {{2{fill_bit}}, stage0[WIDTH-1:2]}   : stage0;
    assign stage2 = I_shift_amt[2] ? {{4{fill_bit}}, stage1[WIDTH-1:4]}   : stage1;
    assign stage3 = I_shift_amt[3] ? {{8{fill_bit}}, stage2[WIDTH-1:8]}   : stage2;
    assign stage4 = I_shift_amt[4] ? {{16{fill_bit}}, stage3[WIDTH-1:16]} : stage3;

    wire [WIDTH-1:0] shift_result = stage4;
    generate
        for (i = 0; i < WIDTH; i = i + 1) begin: output_gen
            assign O_shift_result[i] = I_shift_right ? shift_result[i] : shift_result[WIDTH-1-i];
        end
    endgenerate


    // wire [WIDTH-1:0] lstage0, lstage1, lstage2, lstage3, lstage4;
    // wire [WIDTH-1:0] rstage0, rstage1, rstage2, rstage3, rstage4;

    // assign lstage0 = I_shift_amt[0] ? {I_shift_src[WIDTH-2:0], 1'b0} : I_shift_src;
    // assign lstage1 = I_shift_amt[1] ? {lstage0[WIDTH-3:0], 2'b0}     : lstage0;
    // assign lstage2 = I_shift_amt[2] ? {lstage1[WIDTH-5:0], 4'b0}     : lstage1;
    // assign lstage3 = I_shift_amt[3] ? {lstage2[WIDTH-9:0], 8'b0}     : lstage2;
    // assign lstage4 = I_shift_amt[4] ? {lstage3[WIDTH-17:0], 16'b0}   : lstage3;

    
    // wire fill_bit = I_shift_arith ? I_shift_src[WIDTH-1] : 1'b0;
    
    // assign rstage0 = I_shift_amt[0] ? {fill_bit, I_shift_src[WIDTH-1:1]}    : I_shift_src;
    // assign rstage1 = I_shift_amt[1] ? {{2{fill_bit}}, rstage0[WIDTH-1:2]}   : rstage0;
    // assign rstage2 = I_shift_amt[2] ? {{4{fill_bit}}, rstage1[WIDTH-1:4]}   : rstage1;
    // assign rstage3 = I_shift_amt[3] ? {{8{fill_bit}}, rstage2[WIDTH-1:8]}   : rstage2;
    // assign rstage4 = I_shift_amt[4] ? {{16{fill_bit}}, rstage3[WIDTH-1:16]} : rstage3;
    
    // assign O_shift_result  = I_shift_right ? rstage4 : lstage4;

endmodule

//------------------------------------------------------------------------
// 执行CSR模块
//------------------------------------------------------------------------

module ysyx_25110270_csr_exe
(
    input   wire    [31:0                           ]   I_csr_src,
    input   wire    [31:0                           ]   I_csr_rdata,
    input   wire    [1:0                            ]   I_csr_ctrl,

    output  wire    [31:0                           ]   O_csr_wdata
);
    wire [31:0] rv_csrrw_res = I_csr_src;
    wire [31:0] rv_csrrs_res = I_csr_rdata | I_csr_src;
    wire [31:0] rv_csrrc_res = I_csr_rdata & (~I_csr_src);

    reg [31:0] csr_wdata;
    always @(*) begin
        case(I_csr_ctrl)
            2'b01:      csr_wdata = rv_csrrw_res;   // rw, rwi
            2'b10:      csr_wdata = rv_csrrs_res;   // rs, rsi
            2'b11:      csr_wdata = rv_csrrc_res;   // rc, rci
            default:    csr_wdata = 0;
        endcase
    end

    assign O_csr_wdata = csr_wdata;

endmodule

//------------------------------------------------------------------------
// 访存单元
//------------------------------------------------------------------------

module ysyx_25110270_lsu
(
    input   wire                                    clk,
    input   wire                                    rst,

`ifdef ysyx_25110270_DEBUG
    input   wire    [31:0                       ]   I_inst_addr,
`endif

    input   wire                                    I_valid,

    input   wire    [31:0                       ]   I_alu_result,
    input   wire                                    I_csr_valid,
    input   wire    [31:0                       ]   I_csr_rdata,

    input   wire                                    I_ld_valid,
    input   wire                                    I_st_valid,
    input   wire    [2:0                        ]   I_ls_ctrl,
    input   wire    [31:0                       ]   I_memory_addr,
    input   wire    [31:0                       ]   I_store_data,

    output  wire    [31:0                       ]   O_rd_wdata,
    output  wire                                    O_stallreq,

`ifdef ysyx_25110270_DPIC
    output  wire                                    O_device_skip,
`endif

    //to bus
    output  wire                                    dbus_awvalid,
    input   wire                                    dbus_awready,
    output  wire    [31:0]                          dbus_awaddr,
    output  wire    [3:0 ]                          dbus_awid,
    output  wire    [7:0 ]                          dbus_awlen,
    output  wire    [2:0 ]                          dbus_awsize,
    output  wire    [1:0 ]                          dbus_awburst,
    output  wire                                    dbus_wvalid,
    input   wire                                    dbus_wready,
    output  wire    [31:0]                          dbus_wdata,
    output  wire    [3:0 ]                          dbus_wstrb,
    output  wire                                    dbus_wlast,
    input   wire                                    dbus_bvalid,
    output  wire                                    dbus_bready,
    input   wire    [1:0 ]                          dbus_bresp,
    input   wire    [3:0 ]                          dbus_bid,
    output  wire                                    dbus_arvalid,
    input   wire                                    dbus_arready,
    output  wire    [31:0]                          dbus_araddr,
    output  wire    [3:0 ]                          dbus_arid,
    output  wire    [7:0 ]                          dbus_arlen,
    output  wire    [2:0 ]                          dbus_arsize,
    output  wire    [1:0 ]                          dbus_arburst,
    input   wire                                    dbus_rvalid,
    output  wire                                    dbus_rready,
    input   wire    [31:0]                          dbus_rdata,
    input   wire    [1:0 ]                          dbus_rresp,
    input   wire                                    dbus_rlast,
    input   wire    [3:0 ]                          dbus_rid
);

    //------------------------------------------------------------------------
    // 存取结果
    //------------------------------------------------------------------------
    reg [31:0] rdata;
    always @(posedge clk) begin
        if(rst) begin
            rdata <= 0;
        end else if(dbus_rvalid) begin
            rdata <= dbus_rdata;
        end
    end

    wire [31:0] lb_00_res = {{24{rdata[7]}},  rdata[7:0]};
    wire [31:0] lb_01_res = {{24{rdata[15]}}, rdata[15:8]};
    wire [31:0] lb_10_res = {{24{rdata[23]}}, rdata[23:16]};
    wire [31:0] lb_11_res = {{24{rdata[31]}}, rdata[31:24]};

    wire [31:0] lh_00_res = {{16{rdata[15]}}, rdata[15:0]};
    wire [31:0] lh_10_res = {{16{rdata[31]}}, rdata[31:16]};

    wire [31:0] lw_res = rdata;

    wire [31:0] lbu_00_res = {{24{1'b0}}, rdata[7:0]};
    wire [31:0] lbu_01_res = {{24{1'b0}}, rdata[15:8]};
    wire [31:0] lbu_10_res = {{24{1'b0}}, rdata[23:16]};
    wire [31:0] lbu_11_res = {{24{1'b0}}, rdata[31:24]};

    wire [31:0] lhu_00_res = {{16{1'b0}}, rdata[15:0]};
    wire [31:0] lhu_10_res = {{16{1'b0}}, rdata[31:16]};

    wire [31:0] sb_00_res = {24'b0, I_store_data[7:0]};
    wire [31:0] sb_01_res = {16'b0, I_store_data[7:0], 8'b0};
    wire [31:0] sb_10_res = {8'b0, I_store_data[7:0], 16'b0};
    wire [31:0] sb_11_res = {I_store_data[7:0], 24'b0};

    wire [31:0] sh_00_res = {16'b0, I_store_data[15:0]};
    wire [31:0] sh_10_res = {I_store_data[15:0], 16'b0};

    wire [31:0] sw_res = I_store_data;


    // 地址明辨
    wire [1:0] offset = I_memory_addr[1:0];

    //------------------------------------------------------------------------
    // 访存逻辑
    //------------------------------------------------------------------------

    reg [31:0] rd_data;
    always @(*) begin
        rd_data = I_csr_valid ? I_csr_rdata : I_alu_result;
        case({I_ls_ctrl, offset})
            {`ysyx_25110270_RV32I_F3_LB,  2'b00}: rd_data = lb_00_res;
            {`ysyx_25110270_RV32I_F3_LB,  2'b01}: rd_data = lb_01_res;
            {`ysyx_25110270_RV32I_F3_LB,  2'b10}: rd_data = lb_10_res;
            {`ysyx_25110270_RV32I_F3_LB,  2'b11}: rd_data = lb_11_res;

            {`ysyx_25110270_RV32I_F3_LH,  2'b00}: rd_data = lh_00_res;
            {`ysyx_25110270_RV32I_F3_LH,  2'b10}: rd_data = lh_10_res;

            {`ysyx_25110270_RV32I_F3_LW,  2'b00}: rd_data = lw_res;

            {`ysyx_25110270_RV32I_F3_LBU, 2'b00}: rd_data = lbu_00_res;
            {`ysyx_25110270_RV32I_F3_LBU, 2'b01}: rd_data = lbu_01_res;
            {`ysyx_25110270_RV32I_F3_LBU, 2'b10}: rd_data = lbu_10_res;
            {`ysyx_25110270_RV32I_F3_LBU, 2'b11}: rd_data = lbu_11_res;

            {`ysyx_25110270_RV32I_F3_LHU, 2'b00}: rd_data = lhu_00_res;
            {`ysyx_25110270_RV32I_F3_LHU, 2'b10}: rd_data = lhu_10_res;

            default: begin end
        endcase
    end

    //------------------------------------------------------------------------
    // 存储逻辑
    //------------------------------------------------------------------------

    reg [31:0] wdata;
    reg [3:0] data_mask;
    always @(*) begin
        case({I_ls_ctrl[1:0], offset})  // 00 sb, 01 sh, 10 sw
            {2'b00, 2'b00}: begin
                wdata     = sb_00_res;
                data_mask = 4'b0001;
            end
            {2'b00, 2'b01}: begin
                wdata     = sb_01_res;
                data_mask = 4'b0010;
            end
            {2'b00, 2'b10}: begin
                wdata     = sb_10_res;
                data_mask = 4'b0100;
            end
            {2'b00, 2'b11}: begin
                wdata     = sb_11_res;
                data_mask = 4'b1000;
            end
            {2'b01, 2'b00}: begin
                wdata     = sh_00_res;
                data_mask = 4'b0011;
            end
            {2'b01, 2'b10}: begin
                wdata     = sh_10_res;
                data_mask = 4'b1100;
            end
            {2'b10, 2'b00}: begin
                wdata     = sw_res;
                data_mask = 4'b1111;
            end
            default: begin
                wdata     = 0;
                data_mask = 0;
            end
        endcase
    end
    
    // reg [2:0] data_axsize;
    // always @(*) begin
    //     case(I_ls_ctrl[1:0])  // 00 sb/lb/lbu, 01 sh/lh/lhu, 10 sw/lw
    //         2'b00:   data_axsize = 3'b000;
    //         2'b01:   data_axsize = 3'b001;
    //         2'b10:   data_axsize = 3'b010;
    //         default: data_axsize = 3'b000;
    //     endcase
    // end

    wire [2:0] data_axsize = {1'b0, I_ls_ctrl[1:0]};

    wire is_ld_st = I_ld_valid | I_st_valid;
    wire ls_addr_resp = dbus_awready | dbus_arready;
    wire ls_data_resp = dbus_bvalid | dbus_rvalid;

    reg req_valid;
    always @(posedge clk) begin
        if(rst) begin
            req_valid <= 1'b0;
        end else if(I_valid) begin
            req_valid <= 1'b1;
        end else if(ls_data_resp)begin
            req_valid <= 1'b0;
        end
    end

    reg addr_resp_valid;
    always @(posedge clk) begin
        if(rst) begin
            addr_resp_valid <= 1'b1;
        end else if(ls_addr_resp) begin
            addr_resp_valid <= 1'b0;
        end else if(I_valid) begin
            addr_resp_valid <= 1'b1;
        end
    end

    wire stallreq = (is_ld_st & req_valid) & ~ls_data_resp;

    //------------------------------------------------------------------------
    // 输出
    //------------------------------------------------------------------------
    assign O_rd_wdata = rd_data;

    assign O_stallreq = stallreq;

`ifdef ysyx_25110270_DPIC
    assign O_device_skip = (I_ld_valid | I_st_valid) & 
    (
        (I_memory_addr >= `ysyx_25110270_SERIAL_BASE & I_memory_addr < (`ysyx_25110270_SERIAL_BASE + `ysyx_25110270_SERIAL_SIZE)) |
        (I_memory_addr >= `ysyx_25110270_CLINT_BASE  & I_memory_addr < (`ysyx_25110270_CLINT_BASE  + `ysyx_25110270_CLINT_SIZE )) |
        (I_memory_addr >= `ysyx_25110270_SPI_BASE    & I_memory_addr < (`ysyx_25110270_SPI_BASE    + `ysyx_25110270_SPI_SIZE   )) |
        (I_memory_addr >= `ysyx_25110270_GPIO_BASE   & I_memory_addr < (`ysyx_25110270_GPIO_BASE   + `ysyx_25110270_GPIO_SIZE  )) |
        (I_memory_addr >= `ysyx_25110270_PS2_BASE    & I_memory_addr < (`ysyx_25110270_PS2_BASE    + `ysyx_25110270_PS2_SIZE   )) |
        (I_memory_addr >= `ysyx_25110270_VGA_BASE    & I_memory_addr < (`ysyx_25110270_VGA_BASE    + `ysyx_25110270_VGA_SIZE   )) |
        (I_memory_addr >= `ysyx_25110270_CHIPL_BASE  /*& I_memory_addr < (`ysyx_25110270_CHIPL_BASE  + `ysyx_25110270_CHIPL_SIZE )*/)
    );

`endif


    assign dbus_awvalid = addr_resp_valid & I_st_valid;
    assign dbus_wvalid = 0; // arbiter 中已赋值
    assign dbus_arvalid = addr_resp_valid & I_ld_valid;

    assign dbus_awaddr = I_memory_addr;
    assign dbus_awid = 4'b0000;
    assign dbus_awlen = 8'b0000_0000;
    assign dbus_awsize = data_axsize;
    assign dbus_awburst = 2'b01;

    assign dbus_wdata = wdata;
    assign dbus_wstrb = data_mask;
    assign dbus_wlast = 1'b1;

    assign dbus_bready = 1'b0;   // xbar中已经将bready固定为1'b1了

    assign dbus_araddr = I_memory_addr;
    assign dbus_arid = 4'b0000;
    assign dbus_arlen = 8'b0000_0000;
    assign dbus_arsize = data_axsize;
    assign dbus_arburst = 2'b01;

    assign dbus_rready = 1'b0;   // xbar中已经将rready固定为1'b1了

`ifdef ysyx_25110270_DEBUG

    reg valid, valid_r;
    always @(posedge clk) begin
        if(rst) begin
            valid <= 1'b0;
            valid_r <= 1'b0;
        end else begin
            valid <= I_valid;
            valid_r <= valid;
        end
    end

    wire not_in_mrom   = (I_memory_addr < `ysyx_25110270_MromAddrBase ) | (I_memory_addr >= (`ysyx_25110270_MromAddrBase  + `ysyx_25110270_MromSize   ));
    wire not_in_sram   = (I_memory_addr < `ysyx_25110270_SramAddrBase ) | (I_memory_addr >= (`ysyx_25110270_SramAddrBase  + `ysyx_25110270_SramSize   ));
    wire not_in_flash  = (I_memory_addr < `ysyx_25110270_FlashAddrBase) | (I_memory_addr >= (`ysyx_25110270_FlashAddrBase + `ysyx_25110270_FlashSize  ));
    wire not_in_psram  = (I_memory_addr < `ysyx_25110270_PsramAddrBase) | (I_memory_addr >= (`ysyx_25110270_PsramAddrBase + `ysyx_25110270_PsramSize  ));
    wire not_in_sdram  = (I_memory_addr < `ysyx_25110270_SdramAddrBase) | (I_memory_addr >= (`ysyx_25110270_SdramAddrBase + `ysyx_25110270_SdramSize  ));
    wire not_in_clint  = (I_memory_addr < `ysyx_25110270_CLINT_BASE   ) | (I_memory_addr >= (`ysyx_25110270_CLINT_BASE    + `ysyx_25110270_CLINT_SIZE ));
    wire not_in_serial = (I_memory_addr < `ysyx_25110270_SERIAL_BASE  ) | (I_memory_addr >= (`ysyx_25110270_SERIAL_BASE   + `ysyx_25110270_SERIAL_SIZE));
    wire not_in_spi    = (I_memory_addr < `ysyx_25110270_SPI_BASE     ) | (I_memory_addr >= (`ysyx_25110270_SPI_BASE      + `ysyx_25110270_SPI_SIZE   ));
    wire not_in_gpio   = (I_memory_addr < `ysyx_25110270_GPIO_BASE    ) | (I_memory_addr >= (`ysyx_25110270_GPIO_BASE     + `ysyx_25110270_GPIO_SIZE  ));
    wire not_in_ps2    = (I_memory_addr < `ysyx_25110270_PS2_BASE     ) | (I_memory_addr >= (`ysyx_25110270_PS2_BASE      + `ysyx_25110270_PS2_SIZE   ));
    wire not_in_vga    = (I_memory_addr < `ysyx_25110270_VGA_BASE     ) | (I_memory_addr >= (`ysyx_25110270_VGA_BASE      + `ysyx_25110270_VGA_SIZE   ));
    wire not_in_chipl  = (I_memory_addr < `ysyx_25110270_CHIPL_BASE   )/* | (I_memory_addr >= (`ysyx_25110270_CHIPL_BASE    + `ysyx_25110270_CHIPL_SIZE ))*/;

    wire not_in_device =  not_in_mrom & not_in_sram & not_in_flash & 
                          not_in_psram & not_in_sdram & not_in_clint & 
                          not_in_serial & not_in_spi & not_in_gpio & 
                          not_in_ps2 & not_in_vga & not_in_chipl;

    always @(posedge clk) begin
        if((dbus_arvalid || dbus_awvalid) && not_in_device && valid_r) begin
            $error("LSU: Data read address out of range at pc 0x%08x, access addr 0x%08x!", I_inst_addr, I_memory_addr);
        end
        if(dbus_bvalid && dbus_bresp != 2'b00) begin
            $error("LSU: DBUS write error at pc 0x%08x!", I_inst_addr);
        end
        if(dbus_rvalid && dbus_rresp != 2'b00) begin
            $error("LSU: DBUS read error at pc 0x%08x!", I_inst_addr);
        end
    end
`endif

`ifdef ysyx_25110270_PERF
    
    import "DPI-C" function void ls_delay_cal(input int begin_flag, input int end_flag);

    reg begin_flag_r;
    wire begin_flag = dbus_arvalid | dbus_awvalid;
    wire end_flag   = dbus_bvalid  | dbus_rvalid;

    always @(posedge clk) begin
        if(rst) begin
            begin_flag_r <= 1'b0;
        end else begin
            begin_flag_r <= begin_flag;
        end
    end

    always @(posedge clk) begin
        if(begin_flag & ~begin_flag_r) begin
            ls_delay_cal(1, 0);
        end else if(end_flag) begin
            ls_delay_cal(0, 1);
        end
    end

`endif

endmodule
//------------------------------------------------------------------------
// 写回单元
//------------------------------------------------------------------------

module ysyx_25110270_wbu
(
    input   wire                                    clk,
    input   wire                                    rst,

`ifdef ysyx_25110270_DPIC
    input   wire    [31:0                       ]   I_inst,
    input   wire    [31:0                       ]   I_inst_addr,
`endif

`ifdef __ICARUS__
    input   wire    [31:0                       ]   I_inst,
    input   wire    [31:0                       ]   I_inst_addr,
`endif
    
    input   wire                                    I_valid,

    input   wire    [`ysyx_25110270_RegAddrBus  ]   I_rs1_raddr,
    input   wire    [`ysyx_25110270_RegAddrBus  ]   I_rs2_raddr,
    output  wire    [31:0                       ]   O_rs1_rdata,
    output  wire    [31:0                       ]   O_rs2_rdata,
    input   wire    [`ysyx_25110270_CsrMapBus   ]   I_csr_raddr,
    output  wire    [31:0                       ]   O_csr_rdata,

    input   wire                                    I_rd_we,
    input   wire    [`ysyx_25110270_RegAddrBus  ]   I_rd_waddr,
    input   wire    [31:0                       ]   I_rd_wdata,

    input   wire                                    I_csr_valid,
    input   wire    [`ysyx_25110270_CsrMapBus   ]   I_csr_waddr,
    input   wire    [31:0                       ]   I_csr_wdata,

    output  wire    [63:0                       ]   O_mtime,

    input   wire    [`ysyx_25110270_ExceptBus   ]   I_except,
    input   wire    [31:0                       ]   I_except_addr,

`ifdef ysyx_25110270_DPIC
    input   wire    [31:0                       ]   I_if_addr,
    input   wire    [31:0                       ]   I_dec_addr,
    input   wire    [31:0                       ]   I_ex_addr,

    input   wire                                    I_device_skip,
`endif
    output  wire                                    O_flush,
    output  wire    [31:0                       ]   O_flush_addr
);

`ifdef ysyx_25110270_DPIC
    // registers for DPI
    wire [31:0] gpr0, gpr1, gpr2, gpr3, gpr4, gpr5, gpr6, gpr7, gpr8, gpr9, gpr10, gpr11, gpr12, gpr13, gpr14, gpr15, gpr16, gpr17, gpr18, gpr19, gpr20, gpr21, gpr22, gpr23, gpr24, gpr25, gpr26, gpr27, gpr28, gpr29, gpr30, gpr31;   //寄存器组

    // csr reg output for dpi
    wire [31:0] csr_mtvec;
    wire [31:0] csr_mepc;
    wire [31:0] csr_mstatus;
    wire [31:0] csr_mcause;
    wire [31:0] csr_mcyclel;
    wire [31:0] csr_mcycleh;
    wire [31:0] csr_mvendorid;
    wire [31:0] csr_marchid;
`endif

`ifdef __ICARUS__
    // icarus仿真时输出gpr10的值，方便调试
    wire [31:0] gpr10;
`endif

    reg valid_r;
    always @(posedge clk) begin
        if(rst) begin
            valid_r <= 1'b0;
        end else begin
            valid_r <= I_valid;
        end
    end

    ysyx_25110270_regfile u_regfile
    (
        .clk                    (clk                        ),
        .rst                    (rst                        ),

        .I_rs1_raddr            (I_rs1_raddr                ),
        .I_rs2_raddr            (I_rs2_raddr                ),

        .O_rs1_rdata            (O_rs1_rdata                ),
        .O_rs2_rdata            (O_rs2_rdata                ),

`ifdef ysyx_25110270_DPIC
        .O_gpr0                 (gpr0                       ),
        .O_gpr1                 (gpr1                       ),
        .O_gpr2                 (gpr2                       ),
        .O_gpr3                 (gpr3                       ),
        .O_gpr4                 (gpr4                       ),
        .O_gpr5                 (gpr5                       ),
        .O_gpr6                 (gpr6                       ),
        .O_gpr7                 (gpr7                       ),
        .O_gpr8                 (gpr8                       ),
        .O_gpr9                 (gpr9                       ),
        .O_gpr10                (gpr10                      ),
        .O_gpr11                (gpr11                      ),
        .O_gpr12                (gpr12                      ),
        .O_gpr13                (gpr13                      ),
        .O_gpr14                (gpr14                      ),
        .O_gpr15                (gpr15                      ),
`endif

`ifdef __ICARUS__
        .gpr10                  (gpr10                      ), 
`endif

        .I_rd_we                (I_rd_we                    ),
        .I_rd_waddr             (I_rd_waddr                 ),
        .I_rd_wdata             (I_rd_wdata                 )
    );

    ysyx_25110270_csr u_csr
    (
        .clk                    (clk                        ),
        .rst                    (rst                        ),

        .I_raddr                (I_csr_raddr                ),
        .O_rdata                (O_csr_rdata                ),

        .I_we                   (I_csr_valid                ),
        .I_waddr                (I_csr_waddr                ),
        .I_wdata                (I_csr_wdata                ),

        .I_valid                (valid_r                    ),  
        .I_except               (I_except                   ),
        .I_except_addr          (I_except_addr              ),


        .O_flush                (O_flush                    ),
        .O_flush_addr           (O_flush_addr               ),

`ifdef ysyx_25110270_DPIC
        .O_csr_mtvec            (csr_mtvec                  ), //mtvec寄存器
        .O_csr_mepc             (csr_mepc                   ), //mepc寄存器
        .O_csr_mstatus          (csr_mstatus                ), //mstatus寄存器
        .O_csr_mcause           (csr_mcause                 ), //mcause寄存器
        .O_csr_mcyclel          (csr_mcyclel                ), //mcycle寄存器
        .O_csr_mcycleh          (csr_mcycleh                ), //mcycle寄存器
        .O_csr_mvendorid        (csr_mvendorid              ), //mvendorid寄存器
        .O_csr_marchid          (csr_marchid                ), //marchid寄存器
`endif

        .O_mtime                (O_mtime                    )
    );

`ifdef __ICARUS__
    initial begin
        $display("VERILOG enabled ICARUS! Reset vector: 0x%h", `ysyx_25110270_RESET_VECTOR);
    end
`endif

`ifdef ysyx_25110270_DPIC
    ////////////////////// DPI-C //////////////////////


    `ifdef ysyx_25110270_SOC
        initial begin
            $display("VERILOG enabled SOC! Reset vector: 0x%h", `ysyx_25110270_RESET_VECTOR);
        end
    `else 
        initial begin
            $display("VERILOG enabled NPC! Reset vector: 0x%h", `ysyx_25110270_RESET_VECTOR);
        end
    `endif

    import "DPI-C" function void trap(input int reg_data, input int halt_pc);

    import "DPI-C" function void cpu_value(input int diff_skip, input int valid, input int inst, input int inst_addr, input int pc, 
        input int gpr0, input int gpr1, input int gpr2, input int gpr3, 
        input int gpr4, input int gpr5, input int gpr6, input int gpr7, 
        input int gpr8, input int gpr9, input int gpr10, input int gpr11, 
        input int gpr12, input int gpr13, input int gpr14, input int gpr15,

        input int mepc, input int mtvec, input int mstatus,
        input int mcause, input int mcyclel, input int mcycleh, 
        input int mvendorid, input int marchid
    );

    reg [31:0] inst_r1;
    reg [31:0] inst_addr_r1;
    reg [31:0] pc;
    reg skip_r;
    always @(posedge clk) begin
        if(rst) begin
            inst_r1         <= 0;
            inst_addr_r1    <= 0;
            pc              <= 0;
            skip_r          <= 1'b0;
        end else begin
            inst_r1         <= I_inst;
            inst_addr_r1    <= I_inst_addr;
            pc              <= O_flush ? O_flush_addr :
                               (I_ex_addr == 0 ? 
                               (I_dec_addr == 0 ? I_if_addr : I_dec_addr) 
                               : I_ex_addr);
            skip_r          <= I_device_skip;
        end
    end

    always @(posedge clk) begin
        if(valid_r && (|inst_r1) && (|inst_addr_r1)) begin
            cpu_value
            (
                skip_r, 1, inst_r1, inst_addr_r1, pc, 
                gpr0, gpr1, gpr2, gpr3, gpr4, gpr5, gpr6, gpr7,
                gpr8, gpr9, gpr10, gpr11, gpr12, gpr13, gpr14, gpr15,

                csr_mepc, csr_mtvec, csr_mstatus,
                csr_mcause, csr_mcyclel, csr_mcycleh,
                csr_mvendorid, csr_marchid
            );
        end

        if(inst_r1 == `ysyx_25110270_RV_EBREAK) begin
            trap(gpr10, inst_addr_r1); // a0
        end

    end
`endif

`ifdef __ICARUS__

    reg [31:0] inst_r1, inst_addr_r1;
    always @(posedge clk) begin
        if(rst) begin
            inst_r1 <= 0;
            inst_addr_r1 <= 0;
        end else begin
            inst_r1 <= I_inst;
            inst_addr_r1 <= I_inst_addr;
        end
    end

    wire is_ebreak = inst_r1 == `ysyx_25110270_RV_EBREAK;

    always @(posedge clk) begin
        if(is_ebreak) begin
            if(gpr10 == 0) begin
                $display("~~~~~~~~~~~~~~~~~~~ TEST_PASS ~~~~~~~~~~~~~~~~~~~");
                $display("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
                $display("~~~~~~~~~ #####     ##     ####    #### ~~~~~~~~~");
                $display("~~~~~~~~~ #    #   #  #   #       #     ~~~~~~~~~");
                $display("~~~~~~~~~ #    #  #    #   ####    #### ~~~~~~~~~");
                $display("~~~~~~~~~ #####   ######       #       #~~~~~~~~~");
                $display("~~~~~~~~~ #       #    #  #    #  #    #~~~~~~~~~");
                $display("~~~~~~~~~ #       #    #   ####    #### ~~~~~~~~~");
                $display("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
                $display("Finish at PC = 0x%08x", inst_addr_r1);
            end else begin
                $display("~~~~~~~~~~~~~~~~~~~ TEST_FAIL ~~~~~~~~~~~~~~~~~~~~");
                $display("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
                $display("~~~~~~~~~~######    ##       #    #     ~~~~~~~~~~");
                $display("~~~~~~~~~~#        #  #      #    #     ~~~~~~~~~~");
                $display("~~~~~~~~~~#####   #    #     #    #     ~~~~~~~~~~");
                $display("~~~~~~~~~~#       ######     #    #     ~~~~~~~~~~");
                $display("~~~~~~~~~~#       #    #     #    #     ~~~~~~~~~~");
                $display("~~~~~~~~~~#       #    #     #    ######~~~~~~~~~~");
                $display("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
                $display("Finish at PC = 0x%08x", inst_addr_r1);
            end
            $finish;
        end
    end
`endif

`ifdef ysyx_25110270_DEBUG
    always @(posedge clk) begin
        if(valid_r & inst_r1 == 0 && inst_addr_r1 != 0) begin
            $error("Error: inst is 0 at addr %h!", inst_addr_r1);
            $finish;
        end
    end
`endif

`ifdef ysyx_25110270_PERF

    import "DPI-C" function void wb_inst_cycle_cal(input int pc, input int inst);

    always @(posedge clk) begin
        if(valid_r && (|inst_r1) && (|inst_addr_r1)) begin
            wb_inst_cycle_cal(inst_addr_r1, inst_r1);
        end
    end

`endif

endmodule
//------------------------------------------------------------------------
// 通用寄存器
//------------------------------------------------------------------------

module ysyx_25110270_regfile
(
    input   wire                                    clk,
    input   wire                                    rst,

    input   wire    [`ysyx_25110270_RegAddrBus  ]   I_rs1_raddr,      //读寄存器1地址
    input   wire    [`ysyx_25110270_RegAddrBus  ]   I_rs2_raddr,      //读寄存器2地址

    output  wire    [31:0                       ]   O_rs1_rdata,     //输出寄存器1数据
    output  wire    [31:0                       ]   O_rs2_rdata,     //输出寄存器2数据

`ifdef ysyx_25110270_DPIC
    output  wire    [31:0                       ]   O_gpr0,           // for dpi
    output  wire    [31:0                       ]   O_gpr1,
    output  wire    [31:0                       ]   O_gpr2,
    output  wire    [31:0                       ]   O_gpr3,
    output  wire    [31:0                       ]   O_gpr4,
    output  wire    [31:0                       ]   O_gpr5,
    output  wire    [31:0                       ]   O_gpr6,
    output  wire    [31:0                       ]   O_gpr7,
    output  wire    [31:0                       ]   O_gpr8,
    output  wire    [31:0                       ]   O_gpr9,
    output  wire    [31:0                       ]   O_gpr10,
    output  wire    [31:0                       ]   O_gpr11,
    output  wire    [31:0                       ]   O_gpr12,
    output  wire    [31:0                       ]   O_gpr13,
    output  wire    [31:0                       ]   O_gpr14,
    output  wire    [31:0                       ]   O_gpr15,

`endif

`ifdef __ICARUS__
    output  wire    [31:0                       ]   gpr10,            // for
`endif

    input   wire                                    I_rd_we,         //写寄存器标志
    input   wire    [`ysyx_25110270_RegAddrBus  ]   I_rd_waddr,      //写寄存器地址
    input   wire    [31:0                       ]   I_rd_wdata      //写寄存器数据
);


    reg [31:0] regs[1:`ysyx_25110270_RegNum-1];   //寄存器组

    // integer i;
    //写寄存器
    always @(posedge clk) begin
        // if(rst) begin
        //     for(i = 1; i < `ysyx_25110270_RegNum; i = i + 1) begin
        //         regs[i] <= 0;
        //     end
        // end else begin
        if(I_rd_we && (I_rd_waddr != 0)) begin
            regs[I_rd_waddr] <= I_rd_wdata;
        end
        // end
    end

    reg [31:0] rs1_rdata, rs2_rdata;
    always @(*) begin
        if(I_rs1_raddr == 0) begin
            rs1_rdata = 0;
        end else if(I_rd_we && I_rd_waddr == I_rs1_raddr) begin
            rs1_rdata = I_rd_wdata;
        end else begin
            rs1_rdata = regs[I_rs1_raddr];
        end
    end

    always @(*) begin
        if(I_rs2_raddr == 0) begin
            rs2_rdata = 0;
        end else if(I_rd_we && I_rd_waddr == I_rs2_raddr) begin
            rs2_rdata = I_rd_wdata;
        end else begin
            rs2_rdata = regs[I_rs2_raddr];
        end
    end

    //读寄存器
    assign O_rs1_rdata = rs1_rdata;
    assign O_rs2_rdata = rs2_rdata;

`ifdef ysyx_25110270_DPIC
    assign O_gpr0  = 0;
    assign O_gpr1  = regs[1];
    assign O_gpr2  = regs[2];
    assign O_gpr3  = regs[3];
    assign O_gpr4  = regs[4];
    assign O_gpr5  = regs[5];
    assign O_gpr6  = regs[6];
    assign O_gpr7  = regs[7];
    assign O_gpr8  = regs[8];
    assign O_gpr9  = regs[9];
    assign O_gpr10 = regs[10];
    assign O_gpr11 = regs[11];
    assign O_gpr12 = regs[12];
    assign O_gpr13 = regs[13];
    assign O_gpr14 = regs[14];
    assign O_gpr15 = regs[15];

    wire [31:0] gpr1_ra = regs[1];
    wire [31:0] gpr_sp = regs[2];
    wire [31:0] gpr_gp = regs[3];
    wire [31:0] gpr_tp = regs[4];
    wire [31:0] gpr_t0 = regs[5];
    wire [31:0] gpr_t1 = regs[6];
    wire [31:0] gpr_t2 = regs[7];
    wire [31:0] gpr_s0 = regs[8];
    wire [31:0] gpr_s1 = regs[9];
    wire [31:0] gpr_a0 = regs[10];
    wire [31:0] gpr_a1 = regs[11];
    wire [31:0] gpr_a2 = regs[12];
    wire [31:0] gpr_a3 = regs[13];
    wire [31:0] gpr_a4 = regs[14];
    wire [31:0] gpr_a5 = regs[15];

`endif

`ifdef __ICARUS__

    wire [31:0] gpr1_ra = regs[1];
    wire [31:0] gpr_sp = regs[2];
    wire [31:0] gpr_gp = regs[3];
    wire [31:0] gpr_tp = regs[4];
    wire [31:0] gpr_t0 = regs[5];
    wire [31:0] gpr_t1 = regs[6];
    wire [31:0] gpr_t2 = regs[7];
    wire [31:0] gpr_s0 = regs[8];
    wire [31:0] gpr_s1 = regs[9];
    wire [31:0] gpr_a0 = regs[10];
    wire [31:0] gpr_a1 = regs[11];
    wire [31:0] gpr_a2 = regs[12];
    wire [31:0] gpr_a3 = regs[13];
    wire [31:0] gpr_a4 = regs[14];
    wire [31:0] gpr_a5 = regs[15];

    assign gpr10 = regs[10];
`endif

endmodule //regfile

//------------------------------------------------------------------------
// CSR寄存器
//------------------------------------------------------------------------

module ysyx_25110270_csr
(
    input   wire                                    clk,
    input   wire                                    rst,

    input   wire    [`ysyx_25110270_CsrMapBus   ]   I_raddr,
    output  wire    [31:0                       ]   O_rdata,

    input   wire                                    I_we,
    input   wire    [`ysyx_25110270_CsrMapBus   ]   I_waddr,
    input   wire    [31:0                       ]   I_wdata,

    input   wire                                    I_valid,            //指令有效信号
    input   wire    [`ysyx_25110270_ExceptBus   ]   I_except,
    input   wire    [31:0                       ]   I_except_addr,

    output  wire    [63:0                       ]   O_mtime,            //mtime寄存器

`ifdef ysyx_25110270_DPIC
    output  wire    [31:0                       ]   O_csr_mtvec,        //mtvec寄存器
    output  wire    [31:0                       ]   O_csr_mepc,         //mepc寄存器
    output  wire    [31:0                       ]   O_csr_mstatus,      //mstatus寄存器
    output  wire    [31:0                       ]   O_csr_mcause,       //mcause寄存器
    output  wire    [31:0                       ]   O_csr_mcyclel,      //mcycle寄存器
    output  wire    [31:0                       ]   O_csr_mcycleh,      //mcycle寄存器
    output  wire    [31:0                       ]   O_csr_mvendorid,    //mvendorid寄存器
    output  wire    [31:0                       ]   O_csr_marchid,      //marchid寄存器
`endif

    output  wire                                    O_flush,
    output  wire    [31:0                       ]   O_flush_addr
);

    reg [17:0] mstatus;
    reg [3:0] mcause;
    reg [31:0] mtvec;
    reg [31:0] mepc;

    reg [39:0] cycle;

    wire is_ecall  = I_except[`ysyx_25110270_EXCPT_ECALL];
    wire is_mret   = I_except[`ysyx_25110270_EXCPT_MRET];

    wire except_sync = is_ecall; // for ysyx
    wire except_call = except_sync;
    wire except_mret = is_mret;
    
    wire [31:0] mvendorid;
    wire [31:0] marchid;

    parameter YSYX_LOGO      = 32'h79737978; //ysyx的logo
    parameter YSYX_STU_NUM   = 32'h25110270; //我的学号-25110270

    assign mvendorid = YSYX_LOGO;
    assign marchid = YSYX_STU_NUM;

    //cycle counter
    //复位撤销后就一直计数
    always @(posedge clk) begin
        if(rst) begin
            cycle <= 0;
        end else begin
            cycle <= cycle + 1;
        end
    end

    //write reg
    //写寄存器操作
    always @(posedge clk) begin
        if(rst) begin
            mstatus <= 0;
            mcause <= 0;
        end else if(I_valid) begin
            if(except_sync) begin
                mepc <= I_except_addr;
                mcause <= 4'd11;
                mstatus <= {mstatus[17:8], mstatus[3], mstatus[6:4], 1'b0, mstatus[2:0]} | 18'h1800; //MPIE->MIE, MIE清0
            end else if(except_mret) begin
                mstatus <= {mstatus[17:8], 1'b1, mstatus[6:4], mstatus[7], mstatus[2:0]} & ~18'h1800; //MIE<-MPIE
            end else if(I_we) begin
                case(I_waddr[1:0])
                    `ysyx_25110270_CSR_MAP_MSTATUS:  mstatus     <= I_wdata[17:0];
                    `ysyx_25110270_CSR_MAP_MCAUSE:   mcause      <= I_wdata[3:0];
                    `ysyx_25110270_CSR_MAP_MTVEC:    mtvec       <= I_wdata;
                    `ysyx_25110270_CSR_MAP_MEPC:     mepc        <= I_wdata;
                    default: begin end
                endcase
            end
        end
    end


    //read reg
    //idu模块读CSR寄存器
    reg [31:0] rdata;
    always @(*) begin
        if(I_we && I_raddr == I_waddr) begin
            rdata = I_wdata;
        end else begin
            case(I_raddr)
                `ysyx_25110270_CSR_MAP_MSTATUS:   rdata = {14'b0, mstatus};
                `ysyx_25110270_CSR_MAP_MTVEC:     rdata = mtvec;
                `ysyx_25110270_CSR_MAP_MEPC:      rdata = mepc;
                `ysyx_25110270_CSR_MAP_MCAUSE:    rdata = {28'b0, mcause};
                `ysyx_25110270_CSR_MAP_CYCLE:     rdata = cycle[31:0];
                `ysyx_25110270_CSR_MAP_CYCLEH:    rdata = {24'd0, cycle[39:32]};
                `ysyx_25110270_CSR_MAP_MVENDORID: rdata = mvendorid;
                `ysyx_25110270_CSR_MAP_MARCHID:   rdata = marchid;
                default:                          rdata = 0;
            endcase
        end
    end


    //------------------------------------------------------------------------
    // 输出
    //------------------------------------------------------------------------
    assign O_rdata = rdata;

    assign O_flush = except_call | except_mret;
    assign O_flush_addr = except_call ? mtvec : mepc;

    assign O_mtime = {24'd0, cycle};

`ifdef ysyx_25110270_DPIC
    assign O_csr_mstatus = mstatus;
    assign O_csr_mcause = mcause;
    assign O_csr_mtvec = mtvec;
    assign O_csr_mepc = mepc;
    assign O_csr_mcyclel = cycle[31:0];
    assign O_csr_mcycleh = {24'd0, cycle[39:32]};
    assign O_csr_mvendorid = mvendorid;
    assign O_csr_marchid = marchid;
`endif

endmodule

//------------------------------------------------------------------------
// 取指译码流水线单元
//------------------------------------------------------------------------

module ysyx_25110270_pipeline_if_dec
(
    input   wire                        clk,
    input   wire                        rst,

    input   wire    [31:0           ]   I_inst,             // 指令内容
    input   wire    [31:0           ]   I_inst_addr,        // 指令地址

    output  reg     [31:0           ]   O_inst,             // 指令内容
    output  reg     [31:0           ]   O_inst_addr,        // 指令地址

    input   wire                        I_enable,
    input   wire                        I_flush

);
    always @(posedge clk) begin
        if(rst | I_flush) begin
            O_inst          <= 0                        ;
`ifdef ysyx_25110270_DPIC
            O_inst_addr     <= 0                        ;
`endif
`ifdef __ICARUS__
            O_inst_addr     <= 0                        ;
`endif
        end else if(I_enable) begin
            O_inst          <= I_inst                   ;
            O_inst_addr     <= I_inst_addr              ;
        end
    end

endmodule



//------------------------------------------------------------------------
// 译码执行流水线单元
//------------------------------------------------------------------------

module ysyx_25110270_pipeline_dec_ex
(
    input   wire                                    clk,
    input   wire                                    rst,

`ifdef ysyx_25110270_DPIC
    input   wire    [31:0                       ]   I_inst,             // 指令内容
`endif
`ifdef __ICARUS__
    input   wire    [31:0                       ]   I_inst,             // 指令内容
`endif
    input   wire    [31:0                       ]   I_inst_addr,        // 指令地址
    input   wire    [31:0                       ]   I_rs1_rdata,        // 通用寄存器1读数据
    input   wire    [31:0                       ]   I_rs2_rdata,        // 通用寄存器2读数据
    input   wire    [31:0                       ]   I_csr_rdata,        // CSR寄存器读数据
    input   wire    [31:0                       ]   I_imm,              // 立即数
    input   wire                                    I_rd_we,            // 写通用寄存器标志
    input   wire    [`ysyx_25110270_RegAddrBus  ]   I_rd_waddr,         // 写通用寄存器地址
    input   wire    [2:0                        ]   I_op,               // 指令类型
    input   wire    [1:0                        ]   I_alu_srca_sel,
    input   wire    [1:0                        ]   I_alu_srcb_sel,
    input   wire    [1:0                        ]   I_agu_src_sel,
    input   wire                                    I_csr_src_sel,
    input   wire                                    I_ld_valid,         // 访存有效标志
    input   wire                                    I_st_valid,         // 访存有效标志
    input   wire                                    I_br_valid,         // 分支有效标志
    input   wire                                    I_csr_valid,        // 写CSR寄存器标志
    input   wire    [`ysyx_25110270_CsrMapBus   ]   I_csr_addr,         // 写CSR寄存器地址
    input   wire                                    I_f7b5_en,          // 指令funct7[5]有效标志
    input   wire                                    I_sign,             // 有符号位
    input   wire    [`ysyx_25110270_ExceptBus   ]   I_except,           // 异常

    input   wire                                    I_fwd_ctrl_rs1,
    input   wire                                    I_fwd_ctrl_rs2,
    input   wire                                    I_fwd_ctrl_csr,

`ifdef ysyx_25110270_DPIC
    output  reg     [31:0                       ]   O_inst,             // 指令内容
`endif
`ifdef __ICARUS__
    output  reg     [31:0                       ]   O_inst,             // 指令内容
`endif
    output  reg     [31:0                       ]   O_inst_addr,        // 指令地址
    output  reg     [31:0                       ]   O_rs1_rdata,        // 通用寄存器1读数据
    output  reg     [31:0                       ]   O_rs2_rdata,        // 通用寄存器2读数据
    output  reg     [31:0                       ]   O_csr_rdata,        // CSR寄存器读数据
    output  reg     [31:0                       ]   O_imm,              // 立即数
    output  reg                                     O_rd_we,            // 写通用寄存器标志
    output  reg     [`ysyx_25110270_RegAddrBus  ]   O_rd_waddr,         // 写通用寄存器地址
    output  reg     [2:0                        ]   O_op,               // 指令类型
    output  reg     [1:0                        ]   O_alu_srca_sel,
    output  reg     [1:0                        ]   O_alu_srcb_sel,
    output  reg     [1:0                        ]   O_agu_src_sel,
    output  reg                                     O_csr_src_sel,
    output  reg                                     O_ld_valid,         // 访存有效标志
    output  reg                                     O_st_valid,         // 访存有效标志
    output  reg                                     O_br_valid,         // 分支有效标志
    output  reg                                     O_csr_valid,        // 写CSR寄存器标志
    output  reg     [`ysyx_25110270_CsrMapBus   ]   O_csr_addr,         // 写CSR寄存器地址
    output  reg                                     O_f7b5_en,          // 指令funct7[5]有效标志
    output  reg                                     O_sign,             // 有符号位
    output  reg     [`ysyx_25110270_ExceptBus   ]   O_except,           // 异常

    output  reg                                     O_fwd_ctrl_rs1,
    output  reg                                     O_fwd_ctrl_rs2,
    output  reg                                     O_fwd_ctrl_csr,

    input   wire                                    I_enable,
    input   wire                                    I_flush
);
    always @(posedge clk) begin
        if(rst | I_flush) begin
            O_rd_we         <= 0                        ;
            O_ld_valid      <= 0                        ;
            O_st_valid      <= 0                        ;
            O_br_valid      <= 0                        ;
            O_csr_valid     <= 0                        ;
            O_except        <= 0                        ;
`ifdef ysyx_25110270_DPIC
            O_inst          <= 0                        ;
            O_inst_addr     <= 0                        ;
`endif
`ifdef __ICARUS__
            O_inst          <= 0                        ;
            O_inst_addr     <= 0                        ;
`endif
        end else if(I_enable) begin
`ifdef ysyx_25110270_DPIC
            O_inst          <= I_inst                   ;
`endif
`ifdef __ICARUS__
            O_inst          <= I_inst                   ;
`endif
            O_inst_addr     <= I_inst_addr              ;
            O_rs1_rdata     <= I_rs1_rdata              ;
            O_rs2_rdata     <= I_rs2_rdata              ;
            O_csr_rdata     <= I_csr_rdata              ;
            O_imm           <= I_imm                    ;
            O_rd_we         <= I_rd_we                  ;
            O_rd_waddr      <= I_rd_waddr               ;
            O_op            <= I_op                     ;
            O_alu_srca_sel  <= I_alu_srca_sel           ;
            O_alu_srcb_sel  <= I_alu_srcb_sel           ;
            O_agu_src_sel   <= I_agu_src_sel            ;
            O_csr_src_sel   <= I_csr_src_sel            ;
            O_ld_valid      <= I_ld_valid               ;
            O_st_valid      <= I_st_valid               ;
            O_br_valid      <= I_br_valid               ;
            O_csr_valid     <= I_csr_valid              ;
            O_csr_addr      <= I_csr_addr               ;
            O_f7b5_en       <= I_f7b5_en                ;
            O_sign          <= I_sign                   ;
            O_except        <= I_except                 ;
            O_fwd_ctrl_rs1  <= I_fwd_ctrl_rs1           ;   
            O_fwd_ctrl_rs2  <= I_fwd_ctrl_rs2           ;   
            O_fwd_ctrl_csr  <= I_fwd_ctrl_csr           ;   
        end
    end

endmodule


//------------------------------------------------------------------------
// 访存写回流水线单元
//------------------------------------------------------------------------

module ysyx_25110270_pipeline_ex_wb
(
    input   wire                                    clk,
    input   wire                                    rst,

`ifdef ysyx_25110270_DPIC
    input   wire    [31:0                       ]   I_inst,             // 指令内容
    input   wire                                    I_device_skip,
`endif
`ifdef __ICARUS__
    input   wire    [31:0                       ]   I_inst,             // 指令
`endif
    input   wire    [31:0                       ]   I_inst_addr,        // 指令地址
    input   wire                                    I_rd_we,
    input   wire    [`ysyx_25110270_RegAddrBus  ]   I_rd_waddr,
    input   wire    [31:0                       ]   I_rd_wdata,
    input   wire                                    I_csr_valid,        // 写CSR寄存器标志
    input   wire    [`ysyx_25110270_CsrMapBus   ]   I_csr_addr,         // 写CSR寄存器地址
    input   wire    [31:0                       ]   I_csr_wdata,        // 写CSR寄存器数据
    input   wire    [`ysyx_25110270_ExceptBus   ]   I_except,           // 异常

`ifdef ysyx_25110270_DPIC
    output  reg     [31:0                       ]   O_inst,             // 指令内容
    output  reg                                     O_device_skip,
`endif
`ifdef __ICARUS__
    output  reg     [31:0                       ]   O_inst,             // 指令
`endif
    output  reg     [31:0                       ]   O_inst_addr,        // 指令地址
    output  reg                                     O_rd_we,
    output  reg     [`ysyx_25110270_RegAddrBus  ]   O_rd_waddr,
    output  reg     [31:0                       ]   O_rd_wdata,
    output  reg                                     O_csr_valid,        // 写CSR寄存器标志
    output  reg     [`ysyx_25110270_CsrMapBus   ]   O_csr_addr,         // 写CSR寄存器地址
    output  reg     [31:0                       ]   O_csr_wdata,        // 写CSR寄存器数据
    output  reg     [`ysyx_25110270_ExceptBus   ]   O_except,           // 异常

    input   wire                                    I_enable,
    input   wire                                    I_flush
);

    always @(posedge clk) begin
        if(rst | I_flush) begin
            O_rd_we         <= 0                        ;
            O_csr_valid     <= 0                        ;
            O_except        <= 0                        ;
`ifdef ysyx_25110270_DPIC
            O_inst          <= 0                        ;
            O_inst_addr     <= 0                        ;
            O_device_skip   <= 0                        ;
`endif
`ifdef __ICARUS__
            O_inst          <= 0                        ;
            O_inst_addr     <= 0                        ;
`endif
        end else if(I_enable) begin
`ifdef ysyx_25110270_DPIC
            O_inst          <= I_inst                   ;
            O_device_skip   <= I_device_skip            ;
`endif
`ifdef __ICARUS__            
            O_inst          <= I_inst                   ;
`endif
            O_inst_addr     <= I_inst_addr              ;
            O_rd_we         <= I_rd_we                  ;
            O_rd_waddr      <= I_rd_waddr               ;
            O_rd_wdata      <= I_rd_wdata               ;
            O_csr_valid     <= I_csr_valid              ;
            O_csr_addr      <= I_csr_addr               ;
            O_csr_wdata     <= I_csr_wdata              ;
            O_except        <= I_except                 ;
        end
    end

endmodule
//------------------------------------------------------------------------
// AXI仲裁器模块
//------------------------------------------------------------------------

module ysyx_25110270_arbiter
(
    input   wire                        clk,
    input   wire                        rst,

    input   wire                        M0_awvalid,
    output  wire                        M0_awready,
    input   wire    [31:0]              M0_awaddr,
    input   wire    [3:0]               M0_awid,
    input   wire    [7:0]               M0_awlen,
    input   wire    [2:0]               M0_awsize,
    input   wire    [1:0]               M0_awburst,
    input   wire                        M0_wvalid,
    output  wire                        M0_wready,
    input   wire    [31:0]              M0_wdata,
    input   wire    [3:0]               M0_wstrb,
    input   wire                        M0_wlast,
    output  wire                        M0_bvalid,
    input   wire                        M0_bready,
    output  wire    [1:0]               M0_bresp,
    output  wire    [3:0]               M0_bid,
    input   wire                        M0_arvalid,
    output  wire                        M0_arready,
    input   wire    [31:0]              M0_araddr,
    input   wire    [3:0]               M0_arid,
    input   wire    [7:0]               M0_arlen,
    input   wire    [2:0]               M0_arsize,
    input   wire    [1:0]               M0_arburst,
    output  wire                        M0_rvalid,
    input   wire                        M0_rready,
    output  wire    [31:0]              M0_rdata,
    output  wire    [1:0]               M0_rresp,
    output  wire                        M0_rlast,
    output  wire    [3:0]               M0_rid,

    input   wire                        M1_awvalid,
    output  wire                        M1_awready,
    input   wire    [31:0]              M1_awaddr,
    input   wire    [3:0]               M1_awid,
    input   wire    [7:0]               M1_awlen,
    input   wire    [2:0]               M1_awsize,
    input   wire    [1:0]               M1_awburst,
    input   wire                        M1_wvalid,
    output  wire                        M1_wready,
    input   wire    [31:0]              M1_wdata,
    input   wire    [3:0]               M1_wstrb,
    input   wire                        M1_wlast,
    output  wire                        M1_bvalid,
    input   wire                        M1_bready,
    output  wire    [1:0]               M1_bresp,
    output  wire    [3:0]               M1_bid,
    input   wire                        M1_arvalid,
    output  wire                        M1_arready,
    input   wire    [31:0]              M1_araddr,
    input   wire    [3:0]               M1_arid,
    input   wire    [7:0]               M1_arlen,
    input   wire    [2:0]               M1_arsize,
    input   wire    [1:0]               M1_arburst,
    output  wire                        M1_rvalid,
    input   wire                        M1_rready,
    output  wire    [31:0]              M1_rdata,
    output  wire    [1:0]               M1_rresp,
    output  wire                        M1_rlast,
    output  wire    [3:0]               M1_rid,

    output  wire                        M_awvalid,
    input   wire                        M_awready,
    output  wire    [31:0]              M_awaddr,
    output  wire    [3:0]               M_awid,
    output  wire    [7:0]               M_awlen,
    output  wire    [2:0]               M_awsize,
    output  wire    [1:0]               M_awburst,
    output  wire                        M_wvalid,
    input   wire                        M_wready,
    output  wire    [31:0]              M_wdata,
    output  wire    [3:0]               M_wstrb,
    output  wire                        M_wlast,
    input   wire                        M_bvalid,
    output  wire                        M_bready,
    input   wire    [1:0]               M_bresp,
    input   wire    [3:0]               M_bid,
    output  wire                        M_arvalid,
    input   wire                        M_arready,
    output  wire    [31:0]              M_araddr,
    output  wire    [3:0]               M_arid,
    output  wire    [7:0]               M_arlen,
    output  wire    [2:0]               M_arsize,
    output  wire    [1:0]               M_arburst,
    input   wire                        M_rvalid,
    output  wire                        M_rready,
    input   wire    [31:0]              M_rdata,
    input   wire    [1:0]               M_rresp,
    input   wire                        M_rlast,
    input   wire    [3:0]               M_rid
);

    parameter IDLE = 2'b00;
    parameter M0   = 2'b01;
    parameter M1   = 2'b10;

    wire m0_req = M0_awvalid | M0_arvalid;
    wire m1_req = M1_awvalid | M1_arvalid;

    wire m0_resp = M0_bvalid | (M0_rvalid & M0_rlast);
    wire m1_resp = M1_bvalid | (M1_rvalid & M1_rlast);

    reg [1:0] state;

    always @(posedge clk) begin
        if(rst) begin
            state <= IDLE;
        end else begin
            case(state)
                IDLE: begin
                    if(m1_req) state <= M1;
                    else if(m0_req) state <= M0;
                end
                M0: begin
                    if(m0_resp) state <= (m1_req) ? M1 : IDLE;
                end
                M1: begin
                    if(m1_resp) state <= (m0_req) ? M0 : IDLE;
                end
                default: state <= IDLE;
            endcase
        end
    end

    wire state_m0 = state[0];
    wire state_m1 = state[1];


    // AXI信号连接
    assign M_awvalid  = state_m1 ? M1_awvalid : 0;
    assign M_wvalid   = M_awvalid;
    assign M_arvalid  = state_m0 ? M0_arvalid :
                        state_m1 ? M1_arvalid : 0;

    assign M_awaddr   = state_m0 ? M0_awaddr  : M1_awaddr;
    assign M_awid     = M1_awid;
    assign M_awlen    = M1_awlen;
    assign M_awsize   = M1_awsize;
    assign M_awburst  = M1_awburst;
    assign M_wdata    = M1_wdata;
    assign M_wstrb    = M1_wstrb;
    assign M_wlast    = M1_wlast;
    assign M_bready   = 1'b0; // xbar中已经将bready固定为1'b1了
    assign M_araddr   = state_m0 ? M0_araddr  : M1_araddr;
    assign M_arid     = state_m0 ? M0_arid    : M1_arid;
    assign M_arlen    = state_m0 ? M0_arlen   : M1_arlen;
    assign M_arsize   = state_m0 ? M0_arsize  : M1_arsize;
    assign M_arburst  = state_m0 ? M0_arburst : M1_arburst;
    assign M_rready   = 1'b0; // xbar中已经将rready固定为1'b1了

    assign M0_awready = 0; // 只读
    assign M0_wready  = 0; // 只读
    assign M0_bvalid  = 0; // 只读
    assign M0_bresp   = 0; // 只读
    assign M0_bid     = 0; // 只读
    assign M0_arready = state_m0 ? M_arready  : 0;
    assign M0_rvalid  = state_m0 ? M_rvalid   : 0;
    assign M0_rdata   = M_rdata;
    assign M0_rresp   = M_rresp;
    assign M0_rlast   = M_rlast;
    assign M0_rid     = M_rid;

    assign M1_awready = state_m1 ? M_awready  : 0;
    assign M1_wready  = state_m1 ? M_wready   : 0;
    assign M1_bvalid  = state_m1 ? M_bvalid   : 0;
    assign M1_bresp   = M_bresp;
    assign M1_bid     = M_bid;
    assign M1_arready = state_m1 ? M_arready  : 0;
    assign M1_rvalid  = state_m1 ? M_rvalid   : 0;
    assign M1_rdata   = M_rdata;
    assign M1_rresp   = M_rresp;
    assign M1_rlast   = M_rlast;
    assign M1_rid     = M_rid;


endmodule
//------------------------------------------------------------------------
// cpu core
//------------------------------------------------------------------------

module ysyx_25110270_cpu_core
(
    input   wire                        clk,
    input   wire                        rst,

    output  wire    [63:0]              mtime,

    input   wire                        io_interrupt,

    output  wire                        io_master_awvalid,
    input   wire                        io_master_awready,
    output  wire    [31:0]              io_master_awaddr,
    output  wire    [3:0]               io_master_awid,
    output  wire    [7:0]               io_master_awlen,
    output  wire    [2:0]               io_master_awsize,
    output  wire    [1:0]               io_master_awburst,
    output  wire                        io_master_wvalid,
    input   wire                        io_master_wready,
    output  wire    [31:0]              io_master_wdata,
    output  wire    [3:0]               io_master_wstrb,
    output  wire                        io_master_wlast,
    input   wire                        io_master_bvalid,
    output  wire                        io_master_bready,
    input   wire    [1:0]               io_master_bresp,
    input   wire    [3:0]               io_master_bid,
    output  wire                        io_master_arvalid,
    input   wire                        io_master_arready,
    output  wire    [31:0]              io_master_araddr,
    output  wire    [3:0]               io_master_arid,
    output  wire    [7:0]               io_master_arlen,
    output  wire    [2:0]               io_master_arsize,
    output  wire    [1:0]               io_master_arburst,
    input   wire                        io_master_rvalid,
    output  wire                        io_master_rready,
    input   wire    [31:0]              io_master_rdata,
    input   wire    [1:0]               io_master_rresp,
    input   wire                        io_master_rlast,
    input   wire    [3:0]               io_master_rid
);

    //-------------------------------------------------------------
    // ifetch
    //-------------------------------------------------------------
    wire [31:0                      ]   O_if_inst;
    wire [31:0                      ]   O_if_inst_addr;
    wire                                O_if_valid;

    //-------------------------------------------------------------
    // pipeline_if_dec
    //-------------------------------------------------------------
    wire [31:0                      ]   I_dec_inst;
    wire [31:0                      ]   I_dec_inst_addr;

    //-------------------------------------------------------------
    // decoder
    //-------------------------------------------------------------
    wire [`ysyx_25110270_RegAddrBus ]   O_rs1_raddr;
    wire [`ysyx_25110270_RegAddrBus ]   O_rs2_raddr;
    wire [`ysyx_25110270_CsrMapBus  ]   O_csr_addr;
    wire [31:0                      ]   I_rs1_rdata;
    wire [31:0                      ]   I_rs2_rdata;
    wire [31:0                      ]   I_csr_rdata;

`ifdef ysyx_25110270_DPIC
    wire [31:0                      ]   O_dec_inst;
`endif
`ifdef __ICARUS__
    wire [31:0                      ]   O_dec_inst;
`endif

    wire [31:0                      ]   O_dec_inst_addr;
    wire                                O_dec_valid;
    wire                                O_dec_ready;
    wire [31:0                      ]   O_dec_imm;
    wire                                O_dec_rd_we;
    wire [`ysyx_25110270_RegAddrBus ]   O_dec_rd_waddr;
    wire [2:0                       ]   O_dec_op;
    wire [1:0                       ]   O_dec_alu_srca_sel;
    wire [1:0                       ]   O_dec_alu_srcb_sel;
    wire [1:0                       ]   O_dec_agu_src_sel;
    wire                                O_dec_csr_src_sel;
    wire                                O_dec_ld_valid;
    wire                                O_dec_st_valid;
    wire                                O_dec_br_valid;
    wire                                O_dec_csr_valid;
    wire                                O_dec_f7b5_en;
    wire                                O_dec_sign;
    wire [`ysyx_25110270_ExceptBus  ]   O_dec_except;

    //-------------------------------------------------------------
    // pipeline_dec_ex
    //-------------------------------------------------------------
`ifdef ysyx_25110270_DPIC
    wire [31:0                      ]   I_ex_inst;
`endif
`ifdef __ICARUS__
    wire [31:0                      ]   I_ex_inst;
`endif

    wire [31:0                      ]   I_ex_inst_addr;

    wire [31:0                      ]   I_ex_rs1_rdata;
    wire [31:0                      ]   I_ex_rs2_rdata;
    wire [31:0                      ]   I_ex_csr_rdata;

    wire [31:0                      ]   I_ex_imm;
    wire                                I_ex_rd_we;
    wire [`ysyx_25110270_RegAddrBus ]   I_ex_rd_waddr;
    wire [1:0                       ]   I_ex_alu_srca_sel;
    wire [1:0                       ]   I_ex_alu_srcb_sel;
    wire [1:0                       ]   I_ex_agu_src_sel;
    wire                                I_ex_csr_src_sel;
    wire                                I_ex_ld_valid;
    wire                                I_ex_st_valid;
    wire                                I_ex_br_valid;
    wire                                I_ex_csr_valid;
    wire                                I_ex_f7b5_en;
    wire                                I_ex_sign;
    wire [2:0                       ]   I_ex_op;

    wire [`ysyx_25110270_CsrMapBus  ]   I_ex_csr_addr;

    wire [`ysyx_25110270_ExceptBus  ]   I_ex_except;

    //-------------------------------------------------------------
    // hazard_unit
    //-------------------------------------------------------------
    wire                                O_dec_rs1_re;
    wire                                O_dec_rs2_re;

    wire                                dec_fwd_ctrl_rs1;
    wire                                dec_fwd_ctrl_rs2;
    wire                                dec_fwd_ctrl_csr;

    wire                                ex_fwd_ctrl_rs1;
    wire                                ex_fwd_ctrl_rs2;
    wire                                ex_fwd_ctrl_csr;

    //-------------------------------------------------------------
    // exec
    //-------------------------------------------------------------
    wire                                O_ex_bru_taken;
    wire [31:0                      ]   O_ex_bru_target;

`ifdef ysyx_25110270_DPIC
    wire [31:0                      ]   O_ex_inst;
`endif
`ifdef __ICARUS__
    wire [31:0                      ]   O_ex_inst;
`endif

    wire [31:0                      ]   O_ex_inst_addr;
    wire                                O_ex_valid;
    wire                                O_ex_ready;

    wire                                O_ex_rd_we;
    wire [`ysyx_25110270_RegAddrBus ]   O_ex_rd_waddr;
    wire [31:0                      ]   O_ex_rd_wdata;
    wire                                O_ex_csr_valid;
    wire [`ysyx_25110270_CsrMapBus  ]   O_ex_csr_addr;
    wire [31:0                      ]   O_ex_csr_wdata;
    wire [`ysyx_25110270_ExceptBus  ]   O_ex_except;

    //-------------------------------------------------------------
    // pipeline_ex_wb
    //-------------------------------------------------------------
`ifdef ysyx_25110270_DPIC
    wire [31:0                      ]   I_wb_inst;
`endif

`ifdef __ICARUS__
    wire [31:0                      ]   I_wb_inst;
`endif

    wire [31:0                      ]   I_wb_inst_addr;
    wire                                I_wb_rd_we;
    wire [`ysyx_25110270_RegAddrBus ]   I_wb_rd_waddr;
    wire [31:0                      ]   I_wb_rd_wdata;
    wire                                I_wb_csr_valid;
    wire [`ysyx_25110270_CsrMapBus  ]   I_wb_csr_addr;
    wire [31:0                      ]   I_wb_csr_wdata;
    wire [`ysyx_25110270_ExceptBus  ]   I_wb_except;

    //-------------------------------------------------------------
    // wb
    //-------------------------------------------------------------
    wire                                O_flush;
    wire [31:0                      ]   O_flush_addr;

    //-------------------------------------------------------------
    // instantiate modules
    //-------------------------------------------------------------
`ifdef ysyx_25110270_DPIC
    wire ex_device_skip;
    wire wb_device_skip;
`endif

    wire cpu_execute;
    wire if_enable, dec_enable, ex_enable;
    wire if_flush, dec_flush, ex_flush;

    //ibus
    wire                                ibus_awvalid;
    wire                                ibus_awready;
    wire [31:0]                         ibus_awaddr;
    wire [3:0 ]                         ibus_awid;
    wire [7:0 ]                         ibus_awlen;
    wire [2:0 ]                         ibus_awsize;
    wire [1:0 ]                         ibus_awburst;
    wire                                ibus_wvalid;
    wire                                ibus_wready;
    wire [31:0]                         ibus_wdata;
    wire [3:0 ]                         ibus_wstrb;
    wire                                ibus_wlast;
    wire                                ibus_bvalid;
    wire                                ibus_bready;
    wire [1:0]                          ibus_bresp;
    wire [3:0 ]                         ibus_bid;
    wire                                ibus_arvalid;
    wire                                ibus_arready;
    wire [31:0]                         ibus_araddr;
    wire [3:0 ]                         ibus_arid;
    wire [7:0 ]                         ibus_arlen;
    wire [2:0 ]                         ibus_arsize;
    wire [1:0 ]                         ibus_arburst;
    wire                                ibus_rvalid;
    wire                                ibus_rready;
    wire [31:0]                         ibus_rdata;
    wire [1:0]                          ibus_rresp;
    wire                                ibus_rlast;
    wire [3:0 ]                         ibus_rid;

    //dbus
    wire                                dbus_awvalid;
    wire                                dbus_awready;
    wire [31:0]                         dbus_awaddr;
    wire [3:0 ]                         dbus_awid;
    wire [7:0 ]                         dbus_awlen;
    wire [2:0 ]                         dbus_awsize;
    wire [1:0 ]                         dbus_awburst;
    wire                                dbus_wvalid;
    wire                                dbus_wready;
    wire [31:0]                         dbus_wdata;
    wire [3:0 ]                         dbus_wstrb;
    wire                                dbus_wlast;
    wire                                dbus_bvalid;
    wire                                dbus_bready;
    wire [1:0]                          dbus_bresp;
    wire [3:0 ]                         dbus_bid;
    wire                                dbus_arvalid;
    wire                                dbus_arready;
    wire [31:0]                         dbus_araddr;
    wire [3:0 ]                         dbus_arid;
    wire [7:0 ]                         dbus_arlen;
    wire [2:0 ]                         dbus_arsize;
    wire [1:0 ]                         dbus_arburst;
    wire                                dbus_rvalid;
    wire                                dbus_rready;
    wire [31:0]                         dbus_rdata;
    wire [1:0]                          dbus_rresp;
    wire                                dbus_rlast;
    wire [3:0 ]                         dbus_rid;

    ysyx_25110270_ifetch u_ifetch
    (
        .clk                    (clk                        ),
        .rst                    (rst                        ),

        .I_bru_taken            (O_ex_bru_taken             ),
        .I_bru_target           (O_ex_bru_target            ),

        .I_ready                (O_dec_ready                ),
        .O_valid                (O_if_valid                 ),

        .I_flush                (O_flush                    ),
        .I_flush_addr           (O_flush_addr               ),

        .O_inst                 (O_if_inst                  ),
        .O_inst_addr            (O_if_inst_addr             ),
        
        //to bus
        .ibus_awvalid           (ibus_awvalid               ),
        .ibus_awready           (ibus_awready               ),
        .ibus_awaddr            (ibus_awaddr                ),
        .ibus_awid              (ibus_awid                  ),
        .ibus_awlen             (ibus_awlen                 ),
        .ibus_awsize            (ibus_awsize                ),
        .ibus_awburst           (ibus_awburst               ),
        .ibus_wvalid            (ibus_wvalid                ),
        .ibus_wready            (ibus_wready                ),
        .ibus_wdata             (ibus_wdata                 ),
        .ibus_wstrb             (ibus_wstrb                 ),
        .ibus_wlast             (ibus_wlast                 ),
        .ibus_bvalid            (ibus_bvalid                ),
        .ibus_bready            (ibus_bready                ),
        .ibus_bresp             (ibus_bresp                 ),
        .ibus_bid               (ibus_bid                   ),
        .ibus_arvalid           (ibus_arvalid               ),
        .ibus_arready           (ibus_arready               ),
        .ibus_araddr            (ibus_araddr                ),
        .ibus_arid              (ibus_arid                  ),
        .ibus_arlen             (ibus_arlen                 ),
        .ibus_arsize            (ibus_arsize                ),
        .ibus_arburst           (ibus_arburst               ),
        .ibus_rvalid            (ibus_rvalid                ),
        .ibus_rready            (ibus_rready                ),
        .ibus_rdata             (ibus_rdata                 ),
        .ibus_rresp             (ibus_rresp                 ),
        .ibus_rlast             (ibus_rlast                 ),
        .ibus_rid               (ibus_rid                   )
    );

    ysyx_25110270_decoder u_decoder
    (
        .clk                    (clk                        ),
        .rst                    (rst                        ),

        .I_inst                 (I_dec_inst                 ),
        .I_inst_addr            (I_dec_inst_addr            ),

        .I_ready                (O_ex_ready                 ),
        .O_ready                (O_dec_ready                ),
        .O_valid                (O_dec_valid                ),

        .O_rs1_raddr            (O_rs1_raddr                ),
        .O_rs2_raddr            (O_rs2_raddr                ),
        .O_csr_addr             (O_csr_addr                 ),

`ifdef ysyx_25110270_DPIC
        .O_inst                 (O_dec_inst                 ),
`endif
`ifdef __ICARUS__
        .O_inst                 (O_dec_inst                 ),
`endif

        .O_inst_addr            (O_dec_inst_addr            ),

        .O_imm                  (O_dec_imm                  ),
        .O_rd_we                (O_dec_rd_we                ),
        .O_rd_waddr             (O_dec_rd_waddr             ),
        .O_op                   (O_dec_op                   ),
        .O_alu_srca_sel         (O_dec_alu_srca_sel         ),
        .O_alu_srcb_sel         (O_dec_alu_srcb_sel         ),
        .O_agu_src_sel          (O_dec_agu_src_sel          ),
        .O_csr_src_sel          (O_dec_csr_src_sel          ),
        .O_ld_valid             (O_dec_ld_valid             ),
        .O_st_valid             (O_dec_st_valid             ),
        .O_br_valid             (O_dec_br_valid             ),
        .O_csr_valid            (O_dec_csr_valid            ),
        .O_f7b5_en              (O_dec_f7b5_en              ),
        .O_sign                 (O_dec_sign                 ),
        .O_except               (O_dec_except               ), 

        .O_rs1_re               (O_dec_rs1_re               ),
        .O_rs2_re               (O_dec_rs2_re               )
    );

    ysyx_25110270_hazard_unit u_hazard_unit
    (
        .I_rs1_re               (O_dec_rs1_re               ),
        .I_rs2_re               (O_dec_rs2_re               ),

        .I_rs1_raddr            (O_rs1_raddr                ),
        .I_rs2_raddr            (O_rs2_raddr                ),

        .I_ex_rd_we             (I_ex_rd_we                 ),
        .I_ex_rd_waddr          (I_ex_rd_waddr              ),

        .I_csr_valid            (O_dec_csr_valid            ),
        .I_csr_raddr            (O_csr_addr                 ),

        .I_ex_csr_valid         (I_ex_csr_valid             ),
        .I_ex_csr_waddr         (I_ex_csr_addr              ),

        .O_fwd_ctrl_rs1         (dec_fwd_ctrl_rs1           ),
        .O_fwd_ctrl_rs2         (dec_fwd_ctrl_rs2           ),
        .O_fwd_ctrl_csr         (dec_fwd_ctrl_csr           )
    );

    ysyx_25110270_exec u_exec
    (
        .clk                    (clk                        ),
        .rst                    (rst                        ),

`ifdef ysyx_25110270_DPIC
        .I_inst                 (I_ex_inst                  ),
`endif
`ifdef __ICARUS__
        .I_inst                 (I_ex_inst                  ),
`endif

        .I_inst_addr            (I_ex_inst_addr             ),

        .I_valid                (dec_enable                 ),
        .O_ready                (O_ex_ready                 ),
        .O_valid                (O_ex_valid                 ),

        .I_rd_we                (I_ex_rd_we                 ),
        .I_rd_waddr             (I_ex_rd_waddr              ),
        .I_imm                  (I_ex_imm                   ),
        .I_alu_srca_sel         (I_ex_alu_srca_sel          ),
        .I_alu_srcb_sel         (I_ex_alu_srcb_sel          ),
        .I_agu_src_sel          (I_ex_agu_src_sel           ),
        .I_csr_src_sel          (I_ex_csr_src_sel           ),

        .I_ld_valid             (I_ex_ld_valid              ),
        .I_st_valid             (I_ex_st_valid              ),
        .I_br_valid             (I_ex_br_valid              ),
        .I_csr_valid            (I_ex_csr_valid             ),
        .I_f7b5_en              (I_ex_f7b5_en               ),
        .I_sign                 (I_ex_sign                  ),
        .I_op                   (I_ex_op                    ),
        .I_csr_addr             (I_ex_csr_addr              ),
        .I_except               (I_ex_except                ),

        .I_fwd_ctrl_rs1         (ex_fwd_ctrl_rs1            ),
        .I_fwd_ctrl_rs2         (ex_fwd_ctrl_rs2            ),
        .I_fwd_ctrl_csr         (ex_fwd_ctrl_csr            ),

        .I_rs1_rdata            (I_ex_rs1_rdata             ),
        .I_rs2_rdata            (I_ex_rs2_rdata             ),
        .I_csr_rdata            (I_ex_csr_rdata             ),

        .I_fwd_old_rs_data      (I_wb_rd_wdata              ),
        .I_fwd_old_csr_data     (I_wb_csr_wdata             ),

`ifdef ysyx_25110270_DPIC
        .O_inst                 (O_ex_inst                  ),
        .O_device_skip          (ex_device_skip             ),
`endif

`ifdef __ICARUS__
        .O_inst                 (O_ex_inst                  ),
`endif

        .O_inst_addr            (O_ex_inst_addr             ),

        .O_rd_we                (O_ex_rd_we                 ),
        .O_rd_waddr             (O_ex_rd_waddr              ),
        .O_rd_wdata             (O_ex_rd_wdata              ),
        .O_csr_valid            (O_ex_csr_valid             ),
        .O_csr_addr             (O_ex_csr_addr              ),
        .O_csr_wdata            (O_ex_csr_wdata             ),
        .O_except               (O_ex_except                ),

        .O_bru_taken            (O_ex_bru_taken             ),
        .O_bru_target           (O_ex_bru_target            ),

        //to bus
        .dbus_awvalid           (dbus_awvalid               ),
        .dbus_awready           (dbus_awready               ),
        .dbus_awaddr            (dbus_awaddr                ),
        .dbus_awid              (dbus_awid                  ),
        .dbus_awlen             (dbus_awlen                 ),
        .dbus_awsize            (dbus_awsize                ),
        .dbus_awburst           (dbus_awburst               ),
        .dbus_wvalid            (dbus_wvalid                ),
        .dbus_wready            (dbus_wready                ),
        .dbus_wdata             (dbus_wdata                 ),
        .dbus_wstrb             (dbus_wstrb                 ),
        .dbus_wlast             (dbus_wlast                 ),
        .dbus_bvalid            (dbus_bvalid                ),
        .dbus_bready            (dbus_bready                ),
        .dbus_bresp             (dbus_bresp                 ),
        .dbus_bid               (dbus_bid                   ),
        .dbus_arvalid           (dbus_arvalid               ),
        .dbus_arready           (dbus_arready               ),
        .dbus_araddr            (dbus_araddr                ),
        .dbus_arid              (dbus_arid                  ),
        .dbus_arlen             (dbus_arlen                 ),
        .dbus_arsize            (dbus_arsize                ),
        .dbus_arburst           (dbus_arburst               ),
        .dbus_rvalid            (dbus_rvalid                ),
        .dbus_rready            (dbus_rready                ),
        .dbus_rdata             (dbus_rdata                 ),
        .dbus_rresp             (dbus_rresp                 ),
        .dbus_rlast             (dbus_rlast                 ),
        .dbus_rid               (dbus_rid                   )
    );

    ysyx_25110270_wbu u_wbu
    (
        .clk                    (clk                        ),
        .rst                    (rst                        ),

`ifdef ysyx_25110270_DPIC
        .I_inst                 (I_wb_inst                  ),
        .I_inst_addr            (I_wb_inst_addr             ),
`endif
`ifdef __ICARUS__
        .I_inst                 (I_wb_inst                  ),
        .I_inst_addr            (I_wb_inst_addr             ),
`endif

        .I_valid                (ex_enable                  ),

        .I_rs1_raddr            (O_rs1_raddr                ),
        .I_rs2_raddr            (O_rs2_raddr                ),
        .O_rs1_rdata            (I_rs1_rdata                ),
        .O_rs2_rdata            (I_rs2_rdata                ),
        .I_csr_raddr            (O_csr_addr                 ),
        .O_csr_rdata            (I_csr_rdata                ),

        .I_rd_we                (I_wb_rd_we                 ),
        .I_rd_waddr             (I_wb_rd_waddr              ),
        .I_rd_wdata             (I_wb_rd_wdata              ),

        .I_csr_valid            (I_wb_csr_valid             ),
        .I_csr_waddr            (I_wb_csr_addr              ),
        .I_csr_wdata            (I_wb_csr_wdata             ),

        .I_except               (I_wb_except                ),
        .I_except_addr          (I_wb_inst_addr             ),

        .O_mtime                (mtime                      ),

`ifdef ysyx_25110270_DPIC
        .I_if_addr              (O_if_inst_addr             ),
        .I_dec_addr             (O_dec_inst_addr            ),
        .I_ex_addr              (O_ex_inst_addr             ),

        .I_device_skip          (wb_device_skip             ),
`endif
        .O_flush                (O_flush                    ),
        .O_flush_addr           (O_flush_addr               )
    );

    ysyx_25110270_arbiter arbiter_inst 
    (
        .clk                    (clk                        ),
        .rst                    (rst                        ),

        .M0_awvalid             (ibus_awvalid               ),
        .M0_awready             (ibus_awready               ),
        .M0_awaddr              (ibus_awaddr                ),
        .M0_awid                (ibus_awid                  ),
        .M0_awlen               (ibus_awlen                 ),
        .M0_awsize              (ibus_awsize                ),
        .M0_awburst             (ibus_awburst               ),
        .M0_wvalid              (ibus_wvalid                ),
        .M0_wready              (ibus_wready                ),
        .M0_wdata               (ibus_wdata                 ),
        .M0_wstrb               (ibus_wstrb                 ),
        .M0_wlast               (ibus_wlast                 ),
        .M0_bvalid              (ibus_bvalid                ),
        .M0_bready              (ibus_bready                ),
        .M0_bresp               (ibus_bresp                 ),
        .M0_bid                 (ibus_bid                   ),
        .M0_arvalid             (ibus_arvalid               ),
        .M0_arready             (ibus_arready               ),
        .M0_araddr              (ibus_araddr                ),
        .M0_arid                (ibus_arid                  ),
        .M0_arlen               (ibus_arlen                 ),
        .M0_arsize              (ibus_arsize                ),
        .M0_arburst             (ibus_arburst               ),
        .M0_rvalid              (ibus_rvalid                ),
        .M0_rready              (ibus_rready                ),
        .M0_rdata               (ibus_rdata                 ),
        .M0_rresp               (ibus_rresp                 ),
        .M0_rlast               (ibus_rlast                 ),
        .M0_rid                 (ibus_rid                   ),

        .M1_awvalid             (dbus_awvalid               ),
        .M1_awready             (dbus_awready               ),
        .M1_awaddr              (dbus_awaddr                ),
        .M1_awid                (dbus_awid                  ),
        .M1_awlen               (dbus_awlen                 ),
        .M1_awsize              (dbus_awsize                ),
        .M1_awburst             (dbus_awburst               ),
        .M1_wvalid              (dbus_wvalid                ),
        .M1_wready              (dbus_wready                ),
        .M1_wdata               (dbus_wdata                 ),
        .M1_wstrb               (dbus_wstrb                 ),
        .M1_wlast               (dbus_wlast                 ),
        .M1_bvalid              (dbus_bvalid                ),
        .M1_bready              (dbus_bready                ),
        .M1_bresp               (dbus_bresp                 ),
        .M1_bid                 (dbus_bid                   ),
        .M1_arvalid             (dbus_arvalid               ),
        .M1_arready             (dbus_arready               ),
        .M1_araddr              (dbus_araddr                ),
        .M1_arid                (dbus_arid                  ),
        .M1_arlen               (dbus_arlen                 ),
        .M1_arsize              (dbus_arsize                ),
        .M1_arburst             (dbus_arburst               ),
        .M1_rvalid              (dbus_rvalid                ),
        .M1_rready              (dbus_rready                ),
        .M1_rdata               (dbus_rdata                 ),
        .M1_rresp               (dbus_rresp                 ),
        .M1_rlast               (dbus_rlast                 ),
        .M1_rid                 (dbus_rid                   ),

        .M_awvalid              (io_master_awvalid          ),
        .M_awready              (io_master_awready          ),
        .M_awaddr               (io_master_awaddr           ),
        .M_awid                 (io_master_awid             ),
        .M_awlen                (io_master_awlen            ),
        .M_awsize               (io_master_awsize           ),
        .M_awburst              (io_master_awburst          ),
        .M_wvalid               (io_master_wvalid           ),
        .M_wready               (io_master_wready           ),
        .M_wdata                (io_master_wdata            ),
        .M_wstrb                (io_master_wstrb            ),
        .M_wlast                (io_master_wlast            ),
        .M_bvalid               (io_master_bvalid           ),
        .M_bready               (io_master_bready           ),
        .M_bresp                (io_master_bresp            ),
        .M_bid                  (io_master_bid              ),
        .M_arvalid              (io_master_arvalid          ),
        .M_arready              (io_master_arready          ),
        .M_araddr               (io_master_araddr           ),
        .M_arid                 (io_master_arid             ),
        .M_arlen                (io_master_arlen            ),
        .M_arsize               (io_master_arsize           ),
        .M_arburst              (io_master_arburst          ),
        .M_rvalid               (io_master_rvalid           ),
        .M_rready               (io_master_rready           ),
        .M_rdata                (io_master_rdata            ),
        .M_rresp                (io_master_rresp            ),
        .M_rlast                (io_master_rlast            ),
        .M_rid                  (io_master_rid              )
    );


    //------------------------------------------------------------------------
    // PIPELINE
    //------------------------------------------------------------------------

    assign cpu_execute = O_if_valid;

    assign if_enable = O_if_valid;
    assign if_flush = (O_flush | (O_ex_bru_taken & O_ex_ready)) & cpu_execute;

    ysyx_25110270_pipeline_if_dec u_pipeline_if_dec
    (
        .clk                    (clk                        ),
        .rst                    (rst                        ),

        .I_inst                 (O_if_inst                  ),
        .I_inst_addr            (O_if_inst_addr             ),

        .O_inst                 (I_dec_inst                 ),
        .O_inst_addr            (I_dec_inst_addr            ),

        .I_enable               (if_enable                  ),
        .I_flush                (if_flush                   )
    );

    assign dec_enable = O_dec_valid & cpu_execute;
    assign dec_flush = if_flush;

    ysyx_25110270_pipeline_dec_ex u_pipeline_dec_ex
    (
        .clk                    (clk                        ),
        .rst                    (rst                        ),

`ifdef ysyx_25110270_DPIC
        .I_inst                 (O_dec_inst                 ),
`endif
`ifdef __ICARUS__
        .I_inst                 (O_dec_inst                 ),
`endif
        .I_inst_addr            (O_dec_inst_addr            ),
        .I_rs1_rdata            (I_rs1_rdata                ),
        .I_rs2_rdata            (I_rs2_rdata                ),
        .I_csr_rdata            (I_csr_rdata                ),
        .I_imm                  (O_dec_imm                  ),
        .I_rd_we                (O_dec_rd_we                ),
        .I_rd_waddr             (O_dec_rd_waddr             ),
        .I_op                   (O_dec_op                   ),
        .I_alu_srca_sel         (O_dec_alu_srca_sel         ),
        .I_alu_srcb_sel         (O_dec_alu_srcb_sel         ),
        .I_agu_src_sel          (O_dec_agu_src_sel          ),
        .I_csr_src_sel          (O_dec_csr_src_sel          ),
        .I_ld_valid             (O_dec_ld_valid             ),
        .I_st_valid             (O_dec_st_valid             ),
        .I_br_valid             (O_dec_br_valid             ),
        .I_csr_valid            (O_dec_csr_valid            ),
        .I_csr_addr             (O_csr_addr                 ),
        .I_f7b5_en              (O_dec_f7b5_en              ),
        .I_sign                 (O_dec_sign                 ),
        .I_except               (O_dec_except               ),
        .I_fwd_ctrl_rs1         (dec_fwd_ctrl_rs1           ),
        .I_fwd_ctrl_rs2         (dec_fwd_ctrl_rs2           ),
        .I_fwd_ctrl_csr         (dec_fwd_ctrl_csr           ),

`ifdef ysyx_25110270_DPIC
        .O_inst                 (I_ex_inst                  ),
`endif
`ifdef __ICARUS__
        .O_inst                 (O_ex_inst                  ),
`endif

        .O_inst_addr            (I_ex_inst_addr             ),
        .O_rs1_rdata            (I_ex_rs1_rdata             ),
        .O_rs2_rdata            (I_ex_rs2_rdata             ),
        .O_csr_rdata            (I_ex_csr_rdata             ),
        .O_imm                  (I_ex_imm                   ),
        .O_rd_we                (I_ex_rd_we                 ),
        .O_rd_waddr             (I_ex_rd_waddr              ),
        .O_op                   (I_ex_op                    ),
        .O_alu_srca_sel         (I_ex_alu_srca_sel          ),
        .O_alu_srcb_sel         (I_ex_alu_srcb_sel          ),
        .O_agu_src_sel          (I_ex_agu_src_sel           ),
        .O_csr_src_sel          (I_ex_csr_src_sel           ),
        .O_ld_valid             (I_ex_ld_valid              ),
        .O_st_valid             (I_ex_st_valid              ),
        .O_br_valid             (I_ex_br_valid              ),
        .O_csr_valid            (I_ex_csr_valid             ),
        .O_csr_addr             (I_ex_csr_addr              ),
        .O_f7b5_en              (I_ex_f7b5_en               ),
        .O_sign                 (I_ex_sign                  ),
        .O_except               (I_ex_except                ),
        .O_fwd_ctrl_rs1         (ex_fwd_ctrl_rs1            ),
        .O_fwd_ctrl_rs2         (ex_fwd_ctrl_rs2            ),
        .O_fwd_ctrl_csr         (ex_fwd_ctrl_csr            ),

        .I_enable               (dec_enable                  ),
        .I_flush                (dec_flush                   )
    );

    assign ex_enable = O_ex_valid & cpu_execute;
    assign ex_flush = O_flush & cpu_execute;

    ysyx_25110270_pipeline_ex_wb u_pipeline_ex_wb
    (
        .clk                    (clk                        ),
        .rst                    (rst                        ),

`ifdef ysyx_25110270_DPIC
        .I_inst                 (O_ex_inst                  ),
        .I_device_skip          (ex_device_skip             ),
`endif
`ifdef __ICARUS__
        .I_inst                 (O_ex_inst                  ),
`endif

        .I_inst_addr            (O_ex_inst_addr             ),
        .I_rd_we                (O_ex_rd_we                 ),
        .I_rd_waddr             (O_ex_rd_waddr              ),
        .I_rd_wdata             (O_ex_rd_wdata              ),
        .I_csr_valid            (O_ex_csr_valid             ),
        .I_csr_addr             (O_ex_csr_addr              ),
        .I_csr_wdata            (O_ex_csr_wdata             ),
        .I_except               (O_ex_except                ),

`ifdef ysyx_25110270_DPIC
        .O_inst                 (I_wb_inst                  ),
`endif
`ifdef __ICARUS__
        .O_inst                 (I_wb_inst                  ),
`endif
        .O_inst_addr            (I_wb_inst_addr             ),
        .O_rd_we                (I_wb_rd_we                 ),
        .O_rd_waddr             (I_wb_rd_waddr              ),
        .O_rd_wdata             (I_wb_rd_wdata              ),
        .O_csr_valid            (I_wb_csr_valid             ),
        .O_csr_addr             (I_wb_csr_addr              ),
        .O_csr_wdata            (I_wb_csr_wdata             ),
        .O_except               (I_wb_except                ),

`ifdef ysyx_25110270_DPIC
        .O_device_skip          (wb_device_skip             ),
`endif

        .I_enable               (ex_enable                  ),
        .I_flush                (ex_flush                   )
    );


endmodule //ysyx_25110270

//------------------------------------------------------------------------
// AXI xbar模块
//------------------------------------------------------------------------

module ysyx_25110270_xbar
#(
    parameter S0_BASE = 32'h0200_0000,
    parameter S0_SIZE = 32'h0001_0000
)(
    input   wire                        clk,
    input   wire                        rst,

    input   wire                        S_awvalid,
    output  wire                        S_awready,
    input   wire    [31:0]              S_awaddr,
    input   wire    [3:0]               S_awid,
    input   wire    [7:0]               S_awlen,
    input   wire    [2:0]               S_awsize,
    input   wire    [1:0]               S_awburst,
    input   wire                        S_wvalid,
    output  wire                        S_wready,
    input   wire    [31:0]              S_wdata,
    input   wire    [3:0]               S_wstrb,
    input   wire                        S_wlast,
    output  wire                        S_bvalid,
    input   wire                        S_bready,
    output  wire    [1:0]               S_bresp,
    output  wire    [3:0]               S_bid,
    input   wire                        S_arvalid,
    output  wire                        S_arready,
    input   wire    [31:0]              S_araddr,
    input   wire    [3:0]               S_arid,
    input   wire    [7:0]               S_arlen,
    input   wire    [2:0]               S_arsize,
    input   wire    [1:0]               S_arburst,
    output  wire                        S_rvalid,
    input   wire                        S_rready,
    output  wire    [31:0]              S_rdata,
    output  wire    [1:0]               S_rresp,
    output  wire                        S_rlast,
    output  wire    [3:0]               S_rid,

    // slave0
    output  wire                        M0_awvalid,
    input   wire                        M0_awready,
    output  wire    [31:0]              M0_awaddr,
    output  wire    [3:0]               M0_awid,
    output  wire    [7:0]               M0_awlen,
    output  wire    [2:0]               M0_awsize,
    output  wire    [1:0]               M0_awburst,
    output  wire                        M0_wvalid,
    input   wire                        M0_wready,
    output  wire    [31:0]              M0_wdata,
    output  wire    [3:0]               M0_wstrb,
    output  wire                        M0_wlast,
    input   wire                        M0_bvalid,
    output  wire                        M0_bready,
    input   wire    [1:0]               M0_bresp,
    input   wire    [3:0]               M0_bid,
    output  wire                        M0_arvalid,
    input   wire                        M0_arready,
    output  wire    [31:0]              M0_araddr,
    output  wire    [3:0]               M0_arid,
    output  wire    [7:0]               M0_arlen,
    output  wire    [2:0]               M0_arsize,
    output  wire    [1:0]               M0_arburst,
    input   wire                        M0_rvalid,
    output  wire                        M0_rready,
    input   wire    [31:0]              M0_rdata,
    input   wire    [1:0]               M0_rresp,
    input   wire                        M0_rlast,
    input   wire    [3:0]               M0_rid,

    // slave1
    output  wire                        M1_awvalid,
    input   wire                        M1_awready,
    output  wire    [31:0]              M1_awaddr,
    output  wire    [3:0]               M1_awid,
    output  wire    [7:0]               M1_awlen,
    output  wire    [2:0]               M1_awsize,
    output  wire    [1:0]               M1_awburst,
    output  wire                        M1_wvalid,
    input   wire                        M1_wready,
    output  wire    [31:0]              M1_wdata,
    output  wire    [3:0]               M1_wstrb,
    output  wire                        M1_wlast,
    input   wire                        M1_bvalid,
    output  wire                        M1_bready,
    input   wire    [1:0]               M1_bresp,
    input   wire    [3:0]               M1_bid,
    output  wire                        M1_arvalid,
    input   wire                        M1_arready,
    output  wire    [31:0]              M1_araddr,
    output  wire    [3:0]               M1_arid,
    output  wire    [7:0]               M1_arlen,
    output  wire    [2:0]               M1_arsize,
    output  wire    [1:0]               M1_arburst,
    input   wire                        M1_rvalid,
    output  wire                        M1_rready,
    input   wire    [31:0]              M1_rdata,
    input   wire    [1:0]               M1_rresp,
    input   wire                        M1_rlast,
    input   wire    [3:0]               M1_rid
);

`ifdef __ICARUS__
    wire sel_slave0   = (S0_BASE <= S_araddr && S_araddr < S0_BASE + S0_SIZE) ||
                        (S0_BASE <= S_awaddr && S_awaddr < S0_BASE + S0_SIZE);

    assign M0_awvalid = sel_slave0 ? S_awvalid  : 0 ;
    assign M0_awaddr  = sel_slave0 ? S_awaddr   : 0 ;
    assign M0_awid    = sel_slave0 ? S_awid     : 0 ;
    assign M0_awlen   = sel_slave0 ? S_awlen    : 0 ;
    assign M0_awsize  = sel_slave0 ? S_awsize   : 0 ;
    assign M0_awburst = sel_slave0 ? S_awburst  : 0 ;
    assign M0_wvalid  = sel_slave0 ? S_wvalid   : 0 ;
    assign M0_wdata   = sel_slave0 ? S_wdata    : 0 ;
    assign M0_wstrb   = sel_slave0 ? S_wstrb    : 0 ;
    assign M0_wlast   = sel_slave0 ? S_wlast    : 0 ;
    assign M0_bready  = sel_slave0 ? S_bready   : 0 ;
`else
    
`ifdef ysyx_25110270_NPC
    wire sel_slave0   = (S0_BASE <= S_araddr && S_araddr < S0_BASE + S0_SIZE) ||
                        (S0_BASE <= S_awaddr && S_awaddr < S0_BASE + S0_SIZE);

    assign M0_awvalid = sel_slave0 ? S_awvalid  : 0 ;
    assign M0_awaddr  = sel_slave0 ? S_awaddr   : 0 ;
    assign M0_awid    = sel_slave0 ? S_awid     : 0 ;
    assign M0_awlen   = sel_slave0 ? S_awlen    : 0 ;
    assign M0_awsize  = sel_slave0 ? S_awsize   : 0 ;
    assign M0_awburst = sel_slave0 ? S_awburst  : 0 ;
    assign M0_wvalid  = sel_slave0 ? S_wvalid   : 0 ;
    assign M0_wdata   = sel_slave0 ? S_wdata    : 0 ;
    assign M0_wstrb   = sel_slave0 ? S_wstrb    : 0 ;
    assign M0_wlast   = sel_slave0 ? S_wlast    : 0 ;
    assign M0_bready  = sel_slave0 ? S_bready   : 0 ;
`else
    wire sel_slave0   = (S0_BASE <= S_araddr && S_araddr < S0_BASE + S0_SIZE);

    assign M0_awvalid = 0;  //只读
    assign M0_awaddr  = 0;
    assign M0_awid    = 0;
    assign M0_awlen   = 0;
    assign M0_awsize  = 0;
    assign M0_awburst = 0;
    assign M0_wvalid  = 0;
    assign M0_wdata   = 0;
    assign M0_wstrb   = 0;
    assign M0_wlast   = 0;
    assign M0_bready  = 0;
`endif

`endif

    assign M0_arvalid = sel_slave0 ? S_arvalid  : 0 ;
    assign M0_araddr  = S_araddr;
    assign M0_arid    = S_arid;
    assign M0_arlen   = S_arlen;
    assign M0_arsize  = S_arsize;
    assign M0_arburst = S_arburst;
    assign M0_rready  = 1'b1;

    assign M1_awvalid = sel_slave0 ? 0 : S_awvalid  ;
    assign M1_awaddr  = S_awaddr;
    assign M1_awid    = S_awid;
    assign M1_awlen   = S_awlen;
    assign M1_awsize  = S_awsize;
    assign M1_awburst = S_awburst;
    assign M1_wvalid  = sel_slave0 ? 0 : S_wvalid   ;
    assign M1_wdata   = S_wdata;
    assign M1_wstrb   = S_wstrb;
    assign M1_wlast   = S_wlast;
    assign M1_bready  = 1'b1;
    assign M1_arvalid = sel_slave0 ? 0 : S_arvalid  ;
    assign M1_araddr  = S_araddr;
    assign M1_arid    = S_arid;
    assign M1_arlen   = S_arlen;
    assign M1_arsize  = S_arsize;
    assign M1_arburst = S_arburst;
    assign M1_rready  = 1'b1;

    assign S_awready  = sel_slave0 ? M0_awready : M1_awready ;
    assign S_wready   = sel_slave0 ? M0_wready  : M1_wready  ;
    assign S_bvalid   = sel_slave0 ? M0_bvalid  : M1_bvalid  ;
    assign S_bresp    = sel_slave0 ? M0_bresp   : M1_bresp   ;
    assign S_bid      = sel_slave0 ? M0_bid     : M1_bid     ;
    assign S_arready  = sel_slave0 ? M0_arready : M1_arready ;
    assign S_rvalid   = sel_slave0 ? M0_rvalid  : M1_rvalid  ;
    assign S_rdata    = sel_slave0 ? M0_rdata   : M1_rdata   ;
    assign S_rresp    = sel_slave0 ? M0_rresp   : M1_rresp   ;
    assign S_rlast    = sel_slave0 ? M0_rlast   : M1_rlast   ;
    assign S_rid      = sel_slave0 ? M0_rid     : M1_rid     ;

endmodule

//------------------------------------------------------------------------
// clint模块
//------------------------------------------------------------------------

module ysyx_25110270_clint
(
    input   wire                        clk,        //时钟输入
    input   wire                        rst,        //复位输入

    input   wire    [63:0]              time_i,     //mtime寄存器输入

    // AXI接口
    input   wire                        awvalid_i,
    output  wire                        awready_o,
    input   wire    [31:0]              awaddr_i,
    input   wire    [3:0 ]              awid_i,
    input   wire    [7:0 ]              awlen_i,
    input   wire    [2:0 ]              awsize_i,
    input   wire    [1:0 ]              awburst_i,
    input   wire                        wvalid_i,
    output  wire                        wready_o,
    input   wire    [31:0]              wdata_i,
    input   wire    [3:0]               wstrb_i,
    input   wire                        wlast_i,
    output  wire                        bvalid_o,
    input   wire                        bready_i,
    output  wire    [1:0 ]              bresp_o,
    output  wire    [3:0 ]              bid_o,
    input   wire                        arvalid_i,
    output  wire                        arready_o,
    input   wire    [31:0]              araddr_i,
    input   wire    [3:0 ]              arid_i,
    input   wire    [7:0 ]              arlen_i,
    input   wire    [2:0 ]              arsize_i,
    input   wire    [1:0 ]              arburst_i,
    output  wire                        rvalid_o,
    input   wire                        rready_i,
    output  wire    [31:0]              rdata_o,
    output  wire    [1:0 ]              rresp_o,
    output  wire                        rlast_o,
    output  wire    [3:0 ]              rid_o
);

    reg rdata_valid;
    always @(posedge clk) begin
        if(rst) begin
            rdata_valid <= 1'b0;
        end else begin
            if(rvalid_o && rready_i) begin
                rdata_valid <= 1'b0;
            end else if(arvalid_i) begin
                rdata_valid <= 1'b1;
            end
        end
    end

    assign awready_o = 1'b0;
    assign wready_o  = 1'b0;
    assign bvalid_o  = 1'b0;
    assign bresp_o   = 2'b00;
    assign bid_o     = 4'b0000;
    assign arready_o = 1'b1;
    assign rvalid_o  = rdata_valid;
    assign rdata_o   = araddr_i[2] ? time_i[63:32] : time_i[31:0];
    assign rresp_o   = 2'b00;
    assign rlast_o   = 1'b1;
    assign rid_o     = 4'b0000;

endmodule

`ifndef ysyx_25110270_NETSIM

//------------------------------------------------------------------------
// ysyx_25110270
//------------------------------------------------------------------------

module ysyx_25110270
(
    input   wire                        clock,
    input   wire                        reset,

    input   wire                        io_interrupt,

    output  wire                        io_master_awvalid,
    input   wire                        io_master_awready,
    output  wire    [31:0]              io_master_awaddr,
    output  wire    [3:0]               io_master_awid,
    output  wire    [7:0]               io_master_awlen,
    output  wire    [2:0]               io_master_awsize,
    output  wire    [1:0]               io_master_awburst,
    output  wire                        io_master_wvalid,
    input   wire                        io_master_wready,
    output  wire    [31:0]              io_master_wdata,
    output  wire    [3:0]               io_master_wstrb,
    output  wire                        io_master_wlast,
    input   wire                        io_master_bvalid,
    output  wire                        io_master_bready,
    input   wire    [1:0]               io_master_bresp,
    input   wire    [3:0]               io_master_bid,
    output  wire                        io_master_arvalid,
    input   wire                        io_master_arready,
    output  wire    [31:0]              io_master_araddr,
    output  wire    [3:0]               io_master_arid,
    output  wire    [7:0]               io_master_arlen,
    output  wire    [2:0]               io_master_arsize,
    output  wire    [1:0]               io_master_arburst,
    input   wire                        io_master_rvalid,
    output  wire                        io_master_rready,
    input   wire    [31:0]              io_master_rdata,
    input   wire    [1:0]               io_master_rresp,
    input   wire                        io_master_rlast,
    input   wire    [3:0]               io_master_rid,

    input   wire                        io_slave_awvalid,
    output  wire                        io_slave_awready,
    input   wire    [31:0]              io_slave_awaddr,
    input   wire    [3:0]               io_slave_awid,
    input   wire    [7:0]               io_slave_awlen,
    input   wire    [2:0]               io_slave_awsize,
    input   wire    [1:0]               io_slave_awburst,
    input   wire                        io_slave_wvalid,
    output  wire                        io_slave_wready,
    input   wire    [31:0]              io_slave_wdata,
    input   wire    [3:0]               io_slave_wstrb,
    input   wire                        io_slave_wlast,
    output  wire                        io_slave_bvalid,
    input   wire                        io_slave_bready,
    output  wire    [1:0]               io_slave_bresp,
    output  wire    [3:0]               io_slave_bid,
    input   wire                        io_slave_arvalid,
    output  wire                        io_slave_arready,
    input   wire    [31:0]              io_slave_araddr,
    input   wire    [3:0]               io_slave_arid,
    input   wire    [7:0]               io_slave_arlen,
    input   wire    [2:0]               io_slave_arsize,
    input   wire    [1:0]               io_slave_arburst,
    output  wire                        io_slave_rvalid,
    input   wire                        io_slave_rready,
    output  wire    [31:0]              io_slave_rdata,
    output  wire    [1:0]               io_slave_rresp,
    output  wire                        io_slave_rlast,
    output  wire    [3:0]               io_slave_rid
);

    wire clk = clock;
    wire rst = reset;

    //cpu core
    wire        cpu_awvalid;
    wire        cpu_awready;
    wire [31:0] cpu_awaddr;
    wire [3:0 ] cpu_awid;
    wire [7:0 ] cpu_awlen;
    wire [2:0 ] cpu_awsize;
    wire [1:0 ] cpu_awburst;
    wire        cpu_wvalid;
    wire        cpu_wready;
    wire [31:0] cpu_wdata;
    wire [3:0 ] cpu_wstrb;
    wire        cpu_wlast;
    wire        cpu_bvalid;
    wire        cpu_bready;
    wire [1:0]  cpu_bresp;
    wire [3:0 ] cpu_bid;
    wire        cpu_arvalid;
    wire        cpu_arready;
    wire [31:0] cpu_araddr;
    wire [3:0 ] cpu_arid;
    wire [7:0 ] cpu_arlen;
    wire [2:0 ] cpu_arsize;
    wire [1:0 ] cpu_arburst;
    wire        cpu_rvalid;
    wire        cpu_rready;
    wire [31:0] cpu_rdata;
    wire [1:0]  cpu_rresp;
    wire        cpu_rlast;
    wire [3:0 ] cpu_rid;

    //clint
    wire        clint_awvalid;
    wire        clint_awready;
    wire [31:0] clint_awaddr;
    wire [3:0 ] clint_awid;
    wire [7:0 ] clint_awlen;
    wire [2:0 ] clint_awsize;
    wire [1:0 ] clint_awburst;
    wire        clint_wvalid;
    wire        clint_wready;
    wire [31:0] clint_wdata;
    wire [3:0 ] clint_wstrb;
    wire        clint_wlast;
    wire        clint_bvalid;
    wire        clint_bready;
    wire [1:0]  clint_bresp;
    wire [3:0 ] clint_bid;
    wire        clint_arvalid;
    wire        clint_arready;
    wire [31:0] clint_araddr;
    wire [3:0 ] clint_arid;
    wire [7:0 ] clint_arlen;
    wire [2:0 ] clint_arsize;
    wire [1:0 ] clint_arburst;
    wire        clint_rvalid;
    wire        clint_rready;
    wire [31:0] clint_rdata;
    wire [1:0]  clint_rresp;
    wire        clint_rlast;
    wire [3:0 ] clint_rid;

    wire [63:0] mtime;

    ysyx_25110270_cpu_core cpu_core
    (
        .clk                    (clk                        ),
        .rst                    (rst                        ),

        .mtime                  (mtime                      ),

        .io_interrupt           (io_interrupt               ),

        .io_master_awvalid      (cpu_awvalid                ),
        .io_master_awready      (cpu_awready                ),
        .io_master_awaddr       (cpu_awaddr                 ),
        .io_master_awid         (cpu_awid                   ),
        .io_master_awlen        (cpu_awlen                  ),
        .io_master_awsize       (cpu_awsize                 ),
        .io_master_awburst      (cpu_awburst                ),
        .io_master_wvalid       (cpu_wvalid                 ),
        .io_master_wready       (cpu_wready                 ),
        .io_master_wdata        (cpu_wdata                  ),
        .io_master_wstrb        (cpu_wstrb                  ),
        .io_master_wlast        (cpu_wlast                  ),
        .io_master_bvalid       (cpu_bvalid                 ),
        .io_master_bready       (cpu_bready                 ),
        .io_master_bresp        (cpu_bresp                  ),
        .io_master_bid          (cpu_bid                    ),
        .io_master_arvalid      (cpu_arvalid                ),
        .io_master_arready      (cpu_arready                ),
        .io_master_araddr       (cpu_araddr                 ),
        .io_master_arid         (cpu_arid                   ),
        .io_master_arlen        (cpu_arlen                  ),
        .io_master_arsize       (cpu_arsize                 ),
        .io_master_arburst      (cpu_arburst                ),
        .io_master_rvalid       (cpu_rvalid                 ),
        .io_master_rready       (cpu_rready                 ),
        .io_master_rdata        (cpu_rdata                  ),
        .io_master_rresp        (cpu_rresp                  ),
        .io_master_rlast        (cpu_rlast                  ),
        .io_master_rid          (cpu_rid                    )

    );

    ysyx_25110270_xbar xbar 
    (
        .clk                    (clk                        ),
        .rst                    (rst                        ),

        .S_awvalid              (cpu_awvalid                ),
        .S_awready              (cpu_awready                ),
        .S_awaddr               (cpu_awaddr                 ),
        .S_awid                 (cpu_awid                   ),
        .S_awlen                (cpu_awlen                  ),
        .S_awsize               (cpu_awsize                 ),
        .S_awburst              (cpu_awburst                ),
        .S_wvalid               (cpu_wvalid                 ),
        .S_wready               (cpu_wready                 ),
        .S_wdata                (cpu_wdata                  ),
        .S_wstrb                (cpu_wstrb                  ),
        .S_wlast                (cpu_wlast                  ),
        .S_bvalid               (cpu_bvalid                 ),
        .S_bready               (cpu_bready                 ),
        .S_bresp                (cpu_bresp                  ),
        .S_bid                  (cpu_bid                    ),
        .S_arvalid              (cpu_arvalid                ),
        .S_arready              (cpu_arready                ),
        .S_araddr               (cpu_araddr                 ),
        .S_arid                 (cpu_arid                   ),
        .S_arlen                (cpu_arlen                  ),
        .S_arsize               (cpu_arsize                 ),
        .S_arburst              (cpu_arburst                ),
        .S_rvalid               (cpu_rvalid                 ),
        .S_rready               (cpu_rready                 ),
        .S_rdata                (cpu_rdata                  ),
        .S_rresp                (cpu_rresp                  ),
        .S_rlast                (cpu_rlast                  ),
        .S_rid                  (cpu_rid                    ),

        .M0_awvalid             (clint_awvalid              ),
        .M0_awready             (clint_awready              ),
        .M0_awaddr              (clint_awaddr               ),
        .M0_awid                (clint_awid                 ),
        .M0_awlen               (clint_awlen                ),
        .M0_awsize              (clint_awsize               ),
        .M0_awburst             (clint_awburst              ),
        .M0_wvalid              (clint_wvalid               ),
        .M0_wready              (clint_wready               ),
        .M0_wdata               (clint_wdata                ),
        .M0_wstrb               (clint_wstrb                ),
        .M0_wlast               (clint_wlast                ),
        .M0_bvalid              (clint_bvalid               ),
        .M0_bready              (clint_bready               ),
        .M0_bresp               (clint_bresp                ),
        .M0_bid                 (clint_bid                  ),
        .M0_arvalid             (clint_arvalid              ),
        .M0_arready             (clint_arready              ),
        .M0_araddr              (clint_araddr               ),
        .M0_arid                (clint_arid                 ),
        .M0_arlen               (clint_arlen                ),
        .M0_arsize              (clint_arsize               ),
        .M0_arburst             (clint_arburst              ),
        .M0_rvalid              (clint_rvalid               ),
        .M0_rready              (clint_rready               ),
        .M0_rdata               (clint_rdata                ),
        .M0_rresp               (clint_rresp                ),
        .M0_rlast               (clint_rlast                ),
        .M0_rid                 (clint_rid                  ),

        .M1_awvalid             (io_master_awvalid          ),
        .M1_awready             (io_master_awready          ),
        .M1_awaddr              (io_master_awaddr           ),
        .M1_awid                (io_master_awid             ),
        .M1_awlen               (io_master_awlen            ),
        .M1_awsize              (io_master_awsize           ),
        .M1_awburst             (io_master_awburst          ),
        .M1_wvalid              (io_master_wvalid           ),
        .M1_wready              (io_master_wready           ),
        .M1_wdata               (io_master_wdata            ),
        .M1_wstrb               (io_master_wstrb            ),
        .M1_wlast               (io_master_wlast            ),
        .M1_bvalid              (io_master_bvalid           ),
        .M1_bready              (io_master_bready           ),
        .M1_bresp               (io_master_bresp            ),
        .M1_bid                 (io_master_bid              ),
        .M1_arvalid             (io_master_arvalid          ),
        .M1_arready             (io_master_arready          ),
        .M1_araddr              (io_master_araddr           ),
        .M1_arid                (io_master_arid             ),
        .M1_arlen               (io_master_arlen            ),
        .M1_arsize              (io_master_arsize           ),
        .M1_arburst             (io_master_arburst          ),
        .M1_rvalid              (io_master_rvalid           ),
        .M1_rready              (io_master_rready           ),
        .M1_rdata               (io_master_rdata            ),
        .M1_rresp               (io_master_rresp            ),
        .M1_rlast               (io_master_rlast            ),
        .M1_rid                 (io_master_rid              )
    );

    ysyx_25110270_clint clint
    (
        .clk                    (clk                        ),
        .rst                    (rst                        ),

        .time_i                 (mtime                      ),

        .awvalid_i              (clint_awvalid              ),
        .awready_o              (clint_awready              ),
        .awaddr_i               (clint_awaddr               ),
        .awid_i                 (clint_awid                 ),
        .awlen_i                (clint_awlen                ),
        .awsize_i               (clint_awsize               ),
        .awburst_i              (clint_awburst              ),
        .wvalid_i               (clint_wvalid               ),
        .wready_o               (clint_wready               ),
        .wdata_i                (clint_wdata                ),
        .wstrb_i                (clint_wstrb                ),
        .wlast_i                (clint_wlast                ),
        .bvalid_o               (clint_bvalid               ),
        .bready_i               (clint_bready               ),
        .bresp_o                (clint_bresp                ),
        .bid_o                  (clint_bid                  ),
        .arvalid_i              (clint_arvalid              ),
        .arready_o              (clint_arready              ),
        .araddr_i               (clint_araddr               ),
        .arid_i                 (clint_arid                 ),
        .arlen_i                (clint_arlen                ),
        .arsize_i               (clint_arsize               ),
        .arburst_i              (clint_arburst              ),
        .rvalid_o               (clint_rvalid               ),
        .rready_i               (clint_rready               ),
        .rdata_o                (clint_rdata                ),
        .rresp_o                (clint_rresp                ),
        .rlast_o                (clint_rlast                ),
        .rid_o                  (clint_rid                  )
    );

    assign io_slave_awready = 1'b0;
    assign io_slave_wready  = 1'b0;
    assign io_slave_bvalid  = 1'b0;
    assign io_slave_bresp   = 2'b00;
    assign io_slave_bid     = 4'b0;
    assign io_slave_arready = 1'b0;
    assign io_slave_rvalid  = 1'b0;
    assign io_slave_rdata   = 32'b0;
    assign io_slave_rresp   = 2'b00;
    assign io_slave_rlast   = 1'b0;
    assign io_slave_rid     = 4'b0;


endmodule //ysyx_25110270

`endif


module ysyx_25110270_mem 
#(
    parameter MEM_DEPTH  = 32'h01000000                //MEM深度
)(
    input   wire                        clk,        //时钟输入
    input   wire                        rst,      //复位输入

    input   wire                        awvalid_i,
    output  wire                        awready_o,
    input   wire    [31:0]              awaddr_i,
    input   wire    [3:0 ]              awid_i,
    input   wire    [7:0 ]              awlen_i,
    input   wire    [2:0 ]              awsize_i,
    input   wire    [1:0 ]              awburst_i,
    input   wire                        wvalid_i,
    output  wire                        wready_o,
    input   wire    [31:0]              wdata_i,
    input   wire    [3:0]               wstrb_i,
    input   wire                        wlast_i,
    output  wire                        bvalid_o,
    input   wire                        bready_i,
    output  wire    [1:0 ]              bresp_o,
    output  wire    [3:0 ]              bid_o,
    input   wire                        arvalid_i,
    output  wire                        arready_o,
    input   wire    [31:0]              araddr_i,
    input   wire    [3:0 ]              arid_i,
    input   wire    [7:0 ]              arlen_i,
    input   wire    [2:0 ]              arsize_i,
    input   wire    [1:0 ]              arburst_i,
    output  wire                        rvalid_o,
    input   wire                        rready_i,
    output  wire    [31:0]              rdata_o,
    output  wire    [1:0 ]              rresp_o,
    output  wire                        rlast_o,
    output  wire    [3:0 ]              rid_o
);

    reg [31:0] rdata;
    reg rvalid;
    reg rlast;
    reg flag;
    reg [7:0] cnt;

    reg bvalid;

`ifdef __ICARUS__

    reg [7:0] mem_array0 [0 : 32'h0200_0000-1];
    reg [7:0] mem_array1 [0 : 32'h0200_0000-1];
    reg [7:0] mem_array2 [0 : 32'h0200_0000-1];
    reg [7:0] mem_array3 [0 : 32'h0200_0000-1];

    initial begin
        // $readmemh("/home/hhh/Public/ysyx/ysyx-workbench/npc/build/test.data", mem_array0);
        $readmemh("build/test.data", mem_array0);
    end
    wire [31:0] araddr_align = {araddr_i[31:2], 2'b00};

    always @(posedge clk) begin
        if(rst) begin
            rvalid <= 1'b0;
            rlast <= 1'b0;
            cnt <= 0;
            flag <= 1'b0;
        end else begin
            if(rvalid_o && rready_i) begin
                rvalid <= 1'b0;
                rlast <= 1'b0;
            end else if(arvalid_i || flag) begin
                case(araddr_align[26:25])
                    2'b00: rdata <= {mem_array0[araddr_align[24:0]+3+4*cnt], mem_array0[araddr_align[24:0]+2+4*cnt], mem_array0[araddr_align[24:0]+1+4*cnt], mem_array0[araddr_align[24:0]+0+4*cnt]};
                    2'b01: rdata <= {mem_array1[araddr_align[24:0]+3+4*cnt], mem_array1[araddr_align[24:0]+2+4*cnt], mem_array1[araddr_align[24:0]+1+4*cnt], mem_array1[araddr_align[24:0]+0+4*cnt]};
                    2'b10: rdata <= {mem_array2[araddr_align[24:0]+3+4*cnt], mem_array2[araddr_align[24:0]+2+4*cnt], mem_array2[araddr_align[24:0]+1+4*cnt], mem_array2[araddr_align[24:0]+0+4*cnt]};
                    2'b11: rdata <= {mem_array3[araddr_align[24:0]+3+4*cnt], mem_array3[araddr_align[24:0]+2+4*cnt], mem_array3[araddr_align[24:0]+1+4*cnt], mem_array3[araddr_align[24:0]+0+4*cnt]};
                endcase
                rvalid <= 1'b1;
                if(cnt == arlen_i) begin
                    rlast <= 1'b1;
                    cnt <= 0;
                    flag <= 1'b0;
                end else begin
                    rlast <= 1'b0;
                    cnt <= cnt + 1;
                    flag <= 1'b1;
                end
            end
        end
    end

    wire [31:0] awaddr_align = {awaddr_i[31:2], 2'b00};

    always @(posedge clk) begin
        if(rst) begin
            bvalid <= 1'b0;
        end else begin
            if(bvalid_o && bready_i) begin
                bvalid <= 1'b0;
            end else if(wvalid_i) begin
                case(awaddr_align[26:25])
                    2'b00: begin
                        if(wstrb_i[3]) mem_array0[awaddr_align[24:0]+3] <= wdata_i[31:24];
                        if(wstrb_i[2]) mem_array0[awaddr_align[24:0]+2] <= wdata_i[24:16];
                        if(wstrb_i[1]) mem_array0[awaddr_align[24:0]+1] <= wdata_i[15:8];
                        if(wstrb_i[0]) mem_array0[awaddr_align[24:0]+0] <= wdata_i[7:0];
                    end
                    2'b01: begin
                        if(wstrb_i[3]) mem_array1[awaddr_align[24:0]+3] <= wdata_i[31:24];
                        if(wstrb_i[2]) mem_array1[awaddr_align[24:0]+2] <= wdata_i[24:16];
                        if(wstrb_i[1]) mem_array1[awaddr_align[24:0]+1] <= wdata_i[15:8];
                        if(wstrb_i[0]) mem_array1[awaddr_align[24:0]+0] <= wdata_i[7:0];
                    end
                    2'b10: begin
                        if(wstrb_i[3]) mem_array2[awaddr_align[24:0]+3] <= wdata_i[31:24];
                        if(wstrb_i[2]) mem_array2[awaddr_align[24:0]+2] <= wdata_i[24:16];
                        if(wstrb_i[1]) mem_array2[awaddr_align[24:0]+1] <= wdata_i[15:8];
                        if(wstrb_i[0]) mem_array2[awaddr_align[24:0]+0] <= wdata_i[7:0];
                    end
                    2'b11: begin
                        if(wstrb_i[3]) mem_array3[awaddr_align[24:0]+3] <= wdata_i[31:24];
                        if(wstrb_i[2]) mem_array3[awaddr_align[24:0]+2] <= wdata_i[24:16];
                        if(wstrb_i[1]) mem_array3[awaddr_align[24:0]+1] <= wdata_i[15:8];
                        if(wstrb_i[0]) mem_array3[awaddr_align[24:0]+0] <= wdata_i[7:0];
                    end
                endcase
                bvalid <= 1'b1;
            end
        end
    end
`endif
   
`ifdef ysyx_25110270_DPIC
    import "DPI-C" function int paddr_read(input int raddr);
    import "DPI-C" function void paddr_write(input int waddr, input int wdata, input int wmask);

    always @(posedge clk) begin
        if(rst) begin
            rvalid <= 1'b0;
            rlast <= 1'b0;
            cnt <= 0;
            flag <= 1'b0;
        end else begin
            if(rvalid_o && rready_i) begin
                rvalid <= 1'b0;
                rlast <= 1'b0;
            end else if(arvalid_i || flag) begin
                rdata <= paddr_read(araddr_i + 4*cnt);
                rvalid <= 1'b1;
                if(cnt == arlen_i) begin
                    rlast <= 1'b1;
                    cnt <= 0;
                    flag <= 1'b0;
                end else begin
                    rlast <= 1'b0;
                    cnt <= cnt + 1;
                    flag <= 1'b1;
                end
            end
        end
    end

    always @(posedge clk) begin
        if(rst) begin
            bvalid <= 1'b0;
        end else begin
            if(bvalid_o && bready_i) begin
                bvalid <= 1'b0;
            end else if(wvalid_i) begin
                paddr_write(awaddr_i, wdata_i, wstrb_i);
                bvalid <= 1'b1;
            end
        end
    end

`endif

    assign awready_o = 1'b1;
    assign wready_o  = 1'b1;
    assign bvalid_o  = bvalid;
    assign bresp_o   = 2'b00;
    assign arready_o = 1'b1;
    assign rvalid_o  = rvalid;
    assign rdata_o   = rdata;
    assign rresp_o   = 2'b00;
    assign rlast_o   = rlast;


endmodule

module ysyx_25110270_uart
(
    input   wire                        clk,        //时钟输入
    input   wire                        rst,      //复位输入

    input   wire                        awvalid_i,
    output  wire                        awready_o,
    input   wire    [31:0]              awaddr_i,
    input   wire    [3:0 ]              awid_i,
    input   wire    [7:0 ]              awlen_i,
    input   wire    [2:0 ]              awsize_i,
    input   wire    [1:0 ]              awburst_i,
    input   wire                        wvalid_i,
    output  wire                        wready_o,
    input   wire    [31:0]              wdata_i,
    input   wire    [3:0]               wstrb_i,
    input   wire                        wlast_i,
    output  wire                        bvalid_o,
    input   wire                        bready_i,
    output  wire    [1:0 ]              bresp_o,
    output  wire    [3:0 ]              bid_o,
    input   wire                        arvalid_i,
    output  wire                        arready_o,
    input   wire    [31:0]              araddr_i,
    input   wire    [3:0 ]              arid_i,
    input   wire    [7:0 ]              arlen_i,
    input   wire    [2:0 ]              arsize_i,
    input   wire    [1:0 ]              arburst_i,
    output  wire                        rvalid_o,
    input   wire                        rready_i,
    output  wire    [31:0]              rdata_o,
    output  wire    [1:0 ]              rresp_o,
    output  wire                        rlast_o,
    output  wire    [3:0 ]              rid_o
);


    reg bvalid;
    always @(posedge clk) begin
        if(rst) begin
            bvalid <= 1'b0;
        end else begin
            if(bvalid_o && bready_i) begin
                bvalid <= 1'b0;
            end else if(wvalid_i && wready_o) begin
                bvalid <= 1'b1;
            end
        end
    end

`ifdef __ICARUS__
    reg last_write;

    always @(posedge clk) begin
        if(rst) begin
            last_write <= 1'b0;
        end else begin
            last_write <= wvalid_i;

            if((wvalid_i) & !last_write) begin
                $write("%c", wdata_i[7:0]);
                $fflush();
            end
        end
    end

`endif
`ifdef ysyx_25110270_DPIC
    always @(*) begin
        if(wvalid_i && wready_o) begin
            $write("%c", wdata_i[7:0]);
            $fflush();
        end
    end
`endif
    assign awready_o = 1'b1;
    assign wready_o  = 1'b1;
    assign bvalid_o  = bvalid;
    assign bresp_o   = 2'b00;
    assign arready_o = 1'b1;
    assign rvalid_o  = 1'b0;
    assign rdata_o   = 0;
    assign rresp_o   = 2'b00;
    assign rlast_o   = 1'b1;

endmodule
module ysyx_25110270_top
(
    input         clock,
    input         reset
);

    //cpu core
    wire        cpu_awvalid;
    wire        cpu_awready;
    wire [31:0] cpu_awaddr;
    wire [3:0 ] cpu_awid;
    wire [7:0 ] cpu_awlen;
    wire [2:0 ] cpu_awsize;
    wire [1:0 ] cpu_awburst;
    wire        cpu_wvalid;
    wire        cpu_wready;
    wire [31:0] cpu_wdata;
    wire [3:0 ] cpu_wstrb;
    wire        cpu_wlast;
    wire        cpu_bvalid;
    wire        cpu_bready;
    wire [1:0]  cpu_bresp;
    wire [3:0 ] cpu_bid;
    wire        cpu_arvalid;
    wire        cpu_arready;
    wire [31:0] cpu_araddr;
    wire [3:0 ] cpu_arid;
    wire [7:0 ] cpu_arlen;
    wire [2:0 ] cpu_arsize;
    wire [1:0 ] cpu_arburst;
    wire        cpu_rvalid;
    wire        cpu_rready;
    wire [31:0] cpu_rdata;
    wire [1:0]  cpu_rresp;
    wire        cpu_rlast;
    wire [3:0 ] cpu_rid;

    wire        s0_awvalid;
    wire        s0_awready;
    wire [31:0] s0_awaddr;
    wire [3:0 ] s0_awid;
    wire [7:0 ] s0_awlen;
    wire [2:0 ] s0_awsize;
    wire [1:0 ] s0_awburst;
    wire        s0_wvalid;
    wire        s0_wready;
    wire [31:0] s0_wdata;
    wire [3:0 ] s0_wstrb;
    wire        s0_wlast;
    wire        s0_bvalid;
    wire        s0_bready;
    wire [1:0]  s0_bresp;
    wire [3:0 ] s0_bid;
    wire        s0_arvalid;
    wire        s0_arready;
    wire [31:0] s0_araddr;
    wire [3:0 ] s0_arid;
    wire [7:0 ] s0_arlen;
    wire [2:0 ] s0_arsize;
    wire [1:0 ] s0_arburst;
    wire        s0_rvalid;
    wire        s0_rready;
    wire [31:0] s0_rdata;
    wire [1:0]  s0_rresp;
    wire        s0_rlast;
    wire [3:0 ] s0_rid;

    wire        s1_awvalid;
    wire        s1_awready;
    wire [31:0] s1_awaddr;
    wire [3:0 ] s1_awid;
    wire [7:0 ] s1_awlen;
    wire [2:0 ] s1_awsize;
    wire [1:0 ] s1_awburst;
    wire        s1_wvalid;
    wire        s1_wready;
    wire [31:0] s1_wdata;
    wire [3:0 ] s1_wstrb;
    wire        s1_wlast;
    wire        s1_bvalid;
    wire        s1_bready;
    wire [1:0]  s1_bresp;
    wire [3:0 ] s1_bid;
    wire        s1_arvalid;
    wire        s1_arready;
    wire [31:0] s1_araddr;
    wire [3:0 ] s1_arid;
    wire [7:0 ] s1_arlen;
    wire [2:0 ] s1_arsize;
    wire [1:0 ] s1_arburst;
    wire        s1_rvalid;
    wire        s1_rready;
    wire [31:0] s1_rdata;
    wire [1:0]  s1_rresp;
    wire        s1_rlast;
    wire [3:0 ] s1_rid;

    ysyx_25110270 ysyx_25110270(
        .clock(clock),
        .reset(reset),
        .io_interrupt(1'b0),
        .io_master_awvalid(cpu_awvalid),
        .io_master_awready(cpu_awready),
        .io_master_awid(cpu_awid),
        .io_master_awaddr(cpu_awaddr),
        .io_master_awlen(cpu_awlen),
        .io_master_awsize(cpu_awsize),
        .io_master_awburst(cpu_awburst),
        .io_master_wvalid(cpu_wvalid),
        .io_master_wready(cpu_wready),
        .io_master_wdata(cpu_wdata),
        .io_master_wstrb(cpu_wstrb),
        .io_master_wlast(cpu_wlast),
        .io_master_bvalid(cpu_bvalid),
        .io_master_bready(cpu_bready),
        .io_master_bid(cpu_bid),
        .io_master_bresp(cpu_bresp),
        .io_master_arvalid(cpu_arvalid),
        .io_master_arready(cpu_arready),
        .io_master_arid(cpu_arid),
        .io_master_araddr(cpu_araddr),
        .io_master_arlen(cpu_arlen),
        .io_master_arsize(cpu_arsize),
        .io_master_arburst(cpu_arburst),
        .io_master_rvalid(cpu_rvalid),
        .io_master_rready(cpu_rready),
        .io_master_rid(cpu_rid),
        .io_master_rdata(cpu_rdata),
        .io_master_rresp(cpu_rresp),
        .io_master_rlast(cpu_rlast),

        .io_slave_awvalid(1'b0),
        .io_slave_awready(),
        .io_slave_awaddr(32'b0),
        .io_slave_awid(4'b0),
        .io_slave_awlen(8'b0),
        .io_slave_awsize(3'b0),
        .io_slave_awburst(2'b0),
        .io_slave_wvalid(1'b0),
        .io_slave_wready(),
        .io_slave_wdata(32'b0),
        .io_slave_wstrb(4'b0),
        .io_slave_wlast(1'b0),
        .io_slave_bvalid(),
        .io_slave_bready(1'b0),
        .io_slave_bresp(),
        .io_slave_bid(),
        .io_slave_arvalid(1'b0),
        .io_slave_arready(),
        .io_slave_araddr(32'b0),
        .io_slave_arid(4'b0),
        .io_slave_arlen(8'b0),
        .io_slave_arsize(3'b0),
        .io_slave_arburst(2'b0),
        .io_slave_rvalid(),
        .io_slave_rready(1'b0),
        .io_slave_rid(),
        .io_slave_rdata(),
        .io_slave_rresp(),
        .io_slave_rlast()
    );


    ysyx_25110270_mem mem_test
    (
        .clk(clock),
        .rst(reset),
        .awvalid_i(s1_awvalid),
        .awready_o(s1_awready),
        .awaddr_i(s1_awaddr),
        .awid_i(s1_awid),
        .awlen_i(s1_awlen),
        .awsize_i(s1_awsize),
        .awburst_i(s1_awburst),
        .wvalid_i(s1_wvalid),
        .wready_o(s1_wready),
        .wdata_i(s1_wdata),
        .wstrb_i(s1_wstrb),
        .wlast_i(s1_wlast),
        .bvalid_o(s1_bvalid),
        .bready_i(s1_bready),
        .bresp_o(s1_bresp),
        .bid_o(s1_bid),
        .arvalid_i(s1_arvalid),
        .arready_o(s1_arready),
        .araddr_i(s1_araddr),
        .arid_i(s1_arid),
        .arlen_i(s1_arlen),
        .arsize_i(s1_arsize),
        .arburst_i(s1_arburst),
        .rvalid_o(s1_rvalid),
        .rready_i(s1_rready),
        .rdata_o(s1_rdata),
        .rresp_o(s1_rresp),
        .rlast_o(s1_rlast),
        .rid_o(s1_rid)
    );


    ysyx_25110270_uart uart_test
    (
        .clk(clock),
        .rst(reset),
        .awvalid_i(s0_awvalid),
        .awready_o(s0_awready),
        .awaddr_i(s0_awaddr),
        .awid_i(s0_awid),
        .awlen_i(s0_awlen),
        .awsize_i(s0_awsize),
        .awburst_i(s0_awburst),
        .wvalid_i(s0_wvalid),
        .wready_o(s0_wready),
        .wdata_i(s0_wdata),
        .wstrb_i(s0_wstrb),
        .wlast_i(s0_wlast),
        .bvalid_o(s0_bvalid),
        .bready_i(s0_bready),
        .bresp_o(s0_bresp),
        .bid_o(s0_bid),
        .arvalid_i(s0_arvalid),
        .arready_o(s0_arready),
        .araddr_i(s0_araddr),
        .arid_i(s0_arid),
        .arlen_i(s0_arlen),
        .arsize_i(s0_arsize),
        .arburst_i(s0_arburst),
        .rvalid_o(s0_rvalid),
        .rready_i(s0_rready),
        .rdata_o(s0_rdata),
        .rresp_o(s0_rresp),
        .rlast_o(s0_rlast),
        .rid_o(s0_rid)
    );


    ysyx_25110270_xbar
    #(
        .S0_BASE(32'h1000_0000),
        .S0_SIZE(32'h0000_1000)
    ) xbar_test
    (
        .clk(clock),
        .rst(reset),

        .S_arvalid(cpu_arvalid),
        .S_arready(cpu_arready),
        .S_arid(cpu_arid),
        .S_araddr(cpu_araddr),
        .S_arlen(cpu_arlen),
        .S_arsize(cpu_arsize),
        .S_arburst(cpu_arburst),
        .S_rready(cpu_rready),
        .S_rvalid(cpu_rvalid),
        .S_rid(cpu_rid),
        .S_rdata(cpu_rdata),
        .S_rresp(cpu_rresp),
        .S_rlast(cpu_rlast),
        .S_awvalid(cpu_awvalid),
        .S_awready(cpu_awready),
        .S_awid(cpu_awid),
        .S_awaddr(cpu_awaddr),
        .S_awlen(cpu_awlen),
        .S_awsize(cpu_awsize),
        .S_awburst(cpu_awburst),
        .S_wvalid(cpu_wvalid),
        .S_wready(cpu_wready),
        .S_wdata(cpu_wdata),
        .S_wstrb(cpu_wstrb),
        .S_wlast(cpu_wlast),
        .S_bready(cpu_bready),
        .S_bvalid(cpu_bvalid),
        .S_bid(cpu_bid),
        .S_bresp(cpu_bresp),

        .M0_awvalid(s0_awvalid),
        .M0_awready(s0_awready),
        .M0_awid(s0_awid),
        .M0_awaddr(s0_awaddr),
        .M0_awlen(s0_awlen),
        .M0_awsize(s0_awsize),
        .M0_awburst(s0_awburst),
        .M0_wvalid(s0_wvalid),
        .M0_wready(s0_wready),
        .M0_wdata(s0_wdata),
        .M0_wstrb(s0_wstrb),
        .M0_wlast(s0_wlast),
        .M0_bvalid(s0_bvalid),
        .M0_bready(s0_bready),
        .M0_bresp(s0_bresp),
        .M0_bid(s0_bid),
        .M0_arvalid(s0_arvalid),
        .M0_arready(s0_arready),
        .M0_arid(s0_arid),
        .M0_araddr(s0_araddr),
        .M0_arlen(s0_arlen),
        .M0_arsize(s0_arsize),
        .M0_arburst(s0_arburst),
        .M0_rvalid(s0_rvalid),
        .M0_rready(s0_rready),
        .M0_rid(s0_rid),
        .M0_rdata(s0_rdata),
        .M0_rresp(s0_rresp),
        .M0_rlast(s0_rlast),

        .M1_awvalid(s1_awvalid),
        .M1_awready(s1_awready),
        .M1_awid(s1_awid),
        .M1_awaddr(s1_awaddr),
        .M1_awlen(s1_awlen),
        .M1_awsize(s1_awsize),
        .M1_awburst(s1_awburst),
        .M1_wvalid(s1_wvalid),
        .M1_wready(s1_wready),
        .M1_wdata(s1_wdata),
        .M1_wstrb(s1_wstrb),
        .M1_wlast(s1_wlast),
        .M1_bvalid(s1_bvalid),
        .M1_bready(s1_bready),
        .M1_bresp(s1_bresp),
        .M1_bid(s1_bid),
        .M1_arvalid(s1_arvalid),
        .M1_arready(s1_arready),
        .M1_arid(s1_arid),
        .M1_araddr(s1_araddr),
        .M1_arlen(s1_arlen),
        .M1_arsize(s1_arsize),
        .M1_arburst(s1_arburst),
        .M1_rvalid(s1_rvalid),
        .M1_rready(s1_rready),
        .M1_rid(s1_rid),
        .M1_rdata(s1_rdata),
        .M1_rresp(s1_rresp),
        .M1_rlast(s1_rlast)
    );

endmodule

`ifdef __ICARUS__

`timescale 1ns / 1ps
module ysyx_25110270_top_tb;
    
    reg clock;
    reg reset;

    initial begin
        clock = 0;
        forever #1 clock = ~clock;
    end

    initial begin
        reset = 1;
        #20 reset = 0;
    end

    ysyx_25110270_top top(
        .clock(clock),
        .reset(reset)
    );

`ifdef ysyx_25110270_WAVE
    initial begin
        $dumpfile("build/waveform.vcd");
        $dumpvars(0,ysyx_25110270_top_tb);
    end
`endif

    initial begin
        // #1000 $finish;
    end

endmodule

`endif
