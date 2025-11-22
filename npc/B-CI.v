`define __ICARUS__ 0

// Included from ./pipeline-soc-vsrc/ysyx_25010030_define.vh
//译码模块(指令)
`define INST_TYPE_LUI     5'b01101//U
`define INST_TYPE_AUIPC   5'b00101//U
`define INST_TYPE_JAL     5'b11011
`define INST_TYPE_JALR    5'b11001
`define INST_TYPE_S       5'b01000
`define INST_TYPE_B       5'b11000
`define INST_TYPE_R       5'b01100
`define INST_TYPE_L       5'b00000
`define INST_TYPE_I       5'b00100
`define INST_TYPE_E       5'b11100
`define INST_TYPE_CSR     5'b10011

`define INST_LUI       7'b01101_11
`define INST_AUIPC     7'b00101_11
`define INST_JAL       7'b11011_11
`define INST_JALR      7'b11001_11
`define INST_LW        7'b00000_11
`define INST_CSR       7'b11100_11

`define INST_B         7'b11000_11
`define INST_R         7'b01100_11
`define INST_I         7'b00100_11

`define INST_ECALL        32'h00000073 
`define INST_MRET         32'h30200073
//ebreak
`define INST_EBREAK       32'h00100073
`define HIT_TRAP          1
`define ABORT             2

//funct3值定义
`define F3_ADDI    3'b000
`define F3_SLTI    3'b010
`define F3_SLTU    3'b011
`define F3_ANDI    3'b111
`define F3_ORI     3'b110
`define F3_BEQ     3'b000
`define F3_BNE     3'b001
`define F3_BLT     3'b100
`define F3_BLTU    3'b110
`define F3_BGE     3'b101

`define F3_RSH   3'b101
`define F3_LSH   3'b001
`define F3_XORI  3'b100
`define F3_SLT   3'b010
`define F3_LW    3'b010
`define F3_LH    3'b001
`define F3_LBU   3'b100
`define F3_LB    3'b000
`define F3_SW    3'b010
`define F3_SH    3'b001
`define F3_SB    3'b000
`define F3_LHU   3'b101
`define F3_BGEU  3'b111

`define F3_CSRRW  3'b001
`define F3_CSRRS  3'b010
// `define F3_CSRRC  3'b011
`define F3_CSRRWI 3'b101
`define F3_CSRRSI 3'b110
// `define F3_CSRRCI 3'b111
`define F3_ECALL  3'b000

// ALU 操作码
`define ALU_ADD    4'b0000
`define ALU_SUB    4'b0001
`define ALU_AND    4'b0010
`define ALU_OR     4'b0011
`define ALU_XOR    4'b0100//xor,xori
`define ALU_SLL    4'b0101//sll,slli
`define ALU_SLTU   4'b0110//sltiu,sltu
`define ALU_SLT    4'b0111
`define ALU_SRA    4'b1000//sra,srai
`define ALU_SRL    4'b1001//srl,srli

//Mem字节选取
// `define Mem_Word   3'b010
// `define Mem_Half   3'b001
// `define Mem_UHalf  3'b011
// `define Mem_UBit   3'b000
// `define Mem_Bit    3'b100

`define Mem_Word   5'b11111
`define Mem_Half   5'b10011
`define Mem_UHalf  5'b00011
`define Mem_UBit   5'b00001
`define Mem_Bit    5'b10001


//CSR操作码
`define CSR_CSRRW 2'b01
`define CSR_CSRRS 2'b10
`define CSR_CSRRC 2'b11
`define CSR_NONE  2'b00

`define MSTATUS 12'h300
`define MTVEC   12'h305
`define MEPC    12'h341
`define MCAUSE  12'h342

`define OKAY    2'b00
`define SLVERR  2'b10
`define DECERR  2'b11

`define RESET_PC       32'h8000_0000
`define RESET_MROM_PC  32'h2000_0000
`define RESET_FLASH_PC 32'h3000_0000

// Included from ./pipeline-soc-vsrc/ysyx_25010030_AXI_ARB.v

module ysyx_25010030_AXI_ARB (
    input  wire         clk,
    input  wire         reset,

    output reg          ifu_arready,
    input  wire         ifu_arvalid,
    input  wire [31: 0] ifu_araddr,
    input  wire [ 3: 0] ifu_arid,
    input  wire [ 7: 0] ifu_arlen,
    input  wire [ 2: 0] ifu_arsize,
    input  wire [ 1: 0] ifu_arburst,
    input  wire         ifu_rready,
    output reg          ifu_rvalid,
    output reg  [ 1: 0] ifu_rresp,
    output reg  [31: 0] ifu_rdata,
    output reg          ifu_rlast,
    output reg  [ 3: 0] ifu_rid,

    output reg          lsu_awready,
    input  wire         lsu_awvalid,
    input  wire [31: 0] lsu_awaddr,
    input  wire [ 3: 0] lsu_awid,
    input  wire [ 7: 0] lsu_awlen,
    input  wire [ 2: 0] lsu_awsize,
    input  wire [ 1: 0] lsu_awburst,
    output reg          lsu_wready,
    input  wire         lsu_wvalid,
    input  wire [31: 0] lsu_wdata,
    input  wire [ 3: 0] lsu_wstrb,
    input  wire         lsu_wlast,
    input  wire         lsu_bready,
    output reg          lsu_bvalid,
    output reg  [ 1: 0] lsu_bresp,
    output reg  [ 3: 0] lsu_bid,
    output reg          lsu_arready,
    input  wire         lsu_arvalid,
    input  wire [31: 0] lsu_araddr,
    input  wire [ 3: 0] lsu_arid,
    input  wire [ 7: 0] lsu_arlen,
    input  wire [ 2: 0] lsu_arsize,
    input  wire [ 1: 0] lsu_arburst,
    input  wire         lsu_rready,
    output reg          lsu_rvalid,
    output reg  [ 1: 0] lsu_rresp,
    output reg  [31: 0] lsu_rdata,
    output reg          lsu_rlast,
    output reg  [ 3: 0] lsu_rid,

    input  wire         io_master_awready,
    output reg          io_master_awvalid,
    output reg  [31: 0] io_master_awaddr,
    output reg  [ 3: 0] io_master_awid,
    output reg  [ 7: 0] io_master_awlen,
    output reg  [ 2: 0] io_master_awsize,
    output reg  [ 1: 0] io_master_awburst,
    input  wire         io_master_wready,
    output reg          io_master_wvalid,
    output reg  [31: 0] io_master_wdata,
    output reg  [ 3: 0] io_master_wstrb,
    output reg          io_master_wlast,
    output reg          io_master_bready,
    input  wire         io_master_bvalid,
    input  wire [ 1: 0] io_master_bresp,
    input  wire [ 3: 0] io_master_bid,
    input  wire         io_master_arready,
    output reg          io_master_arvalid,
    output reg [31: 0]  io_master_araddr,
    output reg [ 3: 0]  io_master_arid,
    output reg [ 7: 0]  io_master_arlen,
    output reg [ 2: 0]  io_master_arsize,
    output reg [ 1: 0]  io_master_arburst,
    output reg          io_master_rready,
    input  wire         io_master_rvalid,
    input  wire [ 1: 0] io_master_rresp,
    input  wire [31: 0] io_master_rdata,
    input  wire         io_master_rlast,
    input  wire [ 3: 0] io_master_rid,

    input  wire         clint_arready,
    output reg          clint_arvalid,
    output reg  [31: 0] clint_araddr,
    // output reg  [ 3: 0] clint_arid,
    // output reg  [ 7: 0] clint_arlen,
    // output reg  [ 2: 0] clint_arsize,
    // output reg  [ 1: 0] clint_arburst,
    output reg          clint_rready,
    input  wire         clint_rvalid,
    input  wire [ 1: 0] clint_rresp,
    input  wire [31: 0] clint_rdata,
    input  wire         clint_rlast
    // input  wire [ 3: 0] clint_rid
);

localparam CLINT_BASE      = 16'h0200; // 0200_0000-0200_ffff
// `ifdef YSYXSOC
localparam CLINT_BASE_START= 32'h02000000;
localparam CLINT_BASE_END  = 32'h0200ffff;
// `else
// localparam CLINT_BASE_START= 32'ha0002000;
// localparam CLINT_BASE_END  = 32'ha0002007;
// `endif

localparam IDLE        = 2'b00;
localparam IFU_ACCESS  = 2'b01;
localparam LSU_R_ACCESS  = 2'b10;
localparam LSU_W_ACCESS  = 2'b11;

reg       is_clint_addr;
reg [1:0] current_master, next_master;

always @(posedge clk or posedge reset) begin
    if (reset) begin
        current_master <= IDLE;
    end else begin
        // current_master <= next_master;
        case(next_master)
            IDLE        : current_master <= next_master;
            IFU_ACCESS  : current_master <= next_master;
            LSU_R_ACCESS: current_master <= next_master;
            LSU_W_ACCESS: current_master <= next_master;
            default     : current_master <= current_master;
        endcase
        case (current_master)
            IDLE: begin
                is_clint_addr <= (lsu_arvalid & ((lsu_araddr >= CLINT_BASE_START) && (lsu_araddr <= CLINT_BASE_END)));
            end
            default: begin is_clint_addr <= is_clint_addr; end
        endcase
    end
end

always @(*) begin
    case (current_master)
        IDLE         : next_master = (lsu_arvalid) ? LSU_R_ACCESS  :
                                     (lsu_awvalid) ? LSU_W_ACCESS  :
                                     (ifu_arvalid) ? IFU_ACCESS    : IDLE;
        IFU_ACCESS   : next_master = (ifu_rvalid && ifu_rready && ifu_rlast) ? IDLE : IFU_ACCESS;
        LSU_R_ACCESS : next_master = ((lsu_rvalid && lsu_rready && lsu_rlast) | (clint_rvalid & clint_rready)) ? IDLE : LSU_R_ACCESS;
        LSU_W_ACCESS : next_master = (io_master_bvalid & io_master_bready) ? IDLE : LSU_W_ACCESS;
        default      : next_master = IDLE;
    endcase
end

always @(*) begin
    ifu_arready = 1'b0;
    ifu_rvalid  = 1'b0;
    ifu_rresp   = 2'b00;
    ifu_rdata   = 32'b0;
    ifu_rlast   = 1'b0;
    ifu_rid     = 4'b0;

    lsu_arready = 1'b0;
    lsu_awready = 1'b0;
    lsu_wready  = 1'b0;
    lsu_bvalid  = 1'b0;
    lsu_bresp   = 2'b00;
    lsu_bid     = 4'b0;
    lsu_rvalid  = 1'b0;
    lsu_rresp   = 2'b00;
    lsu_rdata   = 32'b0;
    lsu_rlast   = 1'b0;
    lsu_rid     = 4'b0;
    
    io_master_arvalid = 1'b0;
    io_master_araddr  = 32'b0;
    io_master_arid    = 4'b0;
    io_master_arlen   = 8'b0;
    io_master_arsize  = 3'b0;
    io_master_arburst = 2'b0;
    io_master_rready  = 1'b0;

    io_master_awvalid = 1'b0;
    io_master_awaddr  = 32'b0;
    io_master_awid    = 4'b0;
    io_master_awlen   = 8'b0;
    io_master_awsize  = 3'b0;
    io_master_awburst = 2'b0;
    io_master_wvalid  = 1'b0;
    io_master_wdata   = 32'b0;
    io_master_wstrb   = 4'b0;
    io_master_wlast   = 1'b0;
    io_master_bready  = 1'b0;
    
    clint_arvalid = 1'b0;
    clint_araddr  = 32'b0;
    // clint_arid    = 4'b0;
    // clint_arlen   = 8'b0;
    // clint_arsize  = 3'b0;
    // clint_arburst = 2'b0;
    clint_rready  = 1'b0;
    
    case (current_master)
        IFU_ACCESS: begin
            io_master_arvalid = ifu_arvalid;
            io_master_araddr  = ifu_araddr;
            io_master_arid    = ifu_arid;
            io_master_arlen   = ifu_arlen;
            io_master_arsize  = ifu_arsize;
            io_master_arburst = ifu_arburst;
            io_master_rready  = ifu_rready;
            
            ifu_arready     = io_master_arready;
            ifu_rdata       = io_master_rdata;
            ifu_rresp       = io_master_rresp;
            ifu_rlast       = io_master_rlast;
            ifu_rvalid      = io_master_rvalid;
            ifu_rid         = io_master_rid;
        end
        LSU_R_ACCESS: begin
            if (is_clint_addr) begin
                clint_arvalid   = lsu_arvalid;
                clint_araddr    = lsu_araddr;
                // clint_arid      = lsu_arid;
                // clint_arlen     = lsu_arlen;
                // clint_arsize    = lsu_arsize;
                // clint_arburst   = lsu_arburst;
                clint_rready    = lsu_rready;
                
                lsu_arready     = clint_arready;
                lsu_rdata       = clint_rdata;
                lsu_rresp       = clint_rresp;
                lsu_rlast       = clint_rlast;
                lsu_rvalid      = clint_rvalid;
                // lsu_rid         = clint_rid;
            end else begin
                io_master_arvalid = lsu_arvalid;
                io_master_araddr  = lsu_araddr;
                io_master_arid    = lsu_arid;
                io_master_arlen   = lsu_arlen;
                io_master_arsize  = lsu_arsize;
                io_master_arburst = lsu_arburst;
                io_master_rready  = lsu_rready;
                
                lsu_arready     = io_master_arready;
                lsu_rdata       = io_master_rdata;
                lsu_rresp       = io_master_rresp;
                lsu_rlast       = io_master_rlast;
                lsu_rvalid      = io_master_rvalid;
                lsu_rid         = io_master_rid;
            end
        end
        LSU_W_ACCESS: begin
                io_master_awvalid = lsu_awvalid;
                io_master_awaddr  = lsu_awaddr;
                io_master_awid    = lsu_awid;
                io_master_awlen   = lsu_awlen;
                io_master_awsize  = lsu_awsize;
                io_master_awburst = lsu_awburst;
                io_master_wvalid  = lsu_wvalid;
                io_master_wdata   = lsu_wdata;
                io_master_wstrb   = lsu_wstrb;
                io_master_wlast   = lsu_wlast;
                io_master_bready  = lsu_bready;
                
                lsu_awready     = io_master_awready;
                lsu_wready      = io_master_wready;
                lsu_bvalid      = io_master_bvalid;
                lsu_bresp       = io_master_bresp;
                lsu_bid         = io_master_bid;
        end
        default: begin end
    endcase
end

endmodule
// Included from ./pipeline-soc-vsrc/ysyx_25010030_CLINT.v

module ysyx_25010030_CLINT(
    input  wire         clk,
    input  wire         reset,

    output reg          arready,
    input  wire         arvalid,
    input  wire [31: 0] araddr,
    // input  wire [ 3: 0] arid,
    // input  wire [ 7: 0] arlen,
    // input  wire [ 2: 0] arsize,
    // input  wire [ 1: 0] arburst,
    input  wire         rready,
    output reg          rvalid,
    output reg  [ 1: 0] rresp,
    output reg  [31: 0] rdata,
    output reg          rlast
    // output reg  [ 3: 0] rid
);

    reg  [31: 0] mtimel, mtimeh;
    wire [ 3: 0] clint_offset;
    assign  clint_offset = araddr[3:0];

    localparam IDLE         = 1'b0;
    localparam BUSY         = 1'b1;
    reg          state, next_state;

    always @(posedge clk) begin
        if (reset) begin
            state <= IDLE;   
            arready <= 1'b1;
            rvalid <= 1'b0;
            mtimel <= 32'h0;
            mtimeh <= 32'h0;
        end else begin
            state <= next_state;
            if (mtimel == 32'hFFFFFFFF) begin
                mtimel <= 32'h0;
                mtimeh <= mtimeh + 1;
            end else begin
                mtimel <= mtimel + 1;
            end
            case (state)
                IDLE: begin
                    rvalid <= 1'b0;
                    rlast <= 1'b0;
                    if (arvalid & arready) begin
                        arready <= 1'b0;
                    end
                end
                
                BUSY: begin
                    arready <= 1'b1;
                    rdata <= (clint_offset == 4'h0) ? mtimel :
                             (clint_offset == 4'h4) ? mtimeh :
                             32'b0;
                    rvalid <= 1'b1;
                    rlast <= 1'b1;
                    rresp <= 2'b00;
                end
            endcase
        end
    end

    always @(*) begin
        case (state)
            IDLE: next_state = (arvalid) ? BUSY : IDLE;      
            BUSY: next_state = (rready & rlast) ? IDLE : BUSY; 
            default: next_state = IDLE;
        endcase
    end

endmodule

// Included from ./pipeline-soc-vsrc/ysyx_25010030_EX.v

module ysyx_25010030_EX (
    input             clk,
    input             reset,
    // input             id_ready,        // ID -> IF
    input             id_valid,
    output reg        ex_ready,
    input             lsu_ready,
    output reg        ex_lsu_valid,

    input      [ 3:0] id_wb_rs1,
    input      [ 3:0] id_wb_rs2,
    input      [ 3:0] lsu_ex_forward_rd,
    input             lsu_ex_forward_RegWrite,
    input             lsu_ex_forward_MemRead,
    input      [31:0] lsu_wb_wdata,
    input      [ 3:0] lsu_wb_rd,
    input             lsu_wb_RegWrite,
    input             lsu_wb_valid,
    output reg        ex_lsu_forward_las,

    // input      [31:0] id_ex_inst,
    input      [31:0] id_ex_pc,
    input      [31:0] id_ex_imm,
    input      [ 4:0] id_ex_zimm,
    input      [ 5:0] id_ex_shamt,
    input      [31:0] wb_ex_src1,
    input      [31:0] wb_ex_src2,
    input             id_ex_RegWrite,
    input      [ 3:0] id_ex_rd,
    input      [ 6:0] id_ex_opcode,
    input      [ 2:0] id_ex_func3,
    input      [ 3:0] id_ex_alu_op,

    input             id_ex_jal,
    input             id_ex_jalr,
    input             id_ex_fencei,
    input             id_ex_MemRead,
    input             id_ex_MemWrite,
    input      [ 4:0] id_ex_MemLen,

    input      [31:0] wb_ex_csr_num1,
    input      [31:0] wb_ex_csr_num2,
     
    // input             id_ex_csr,
    input             id_ex_csr_wen1,
    // input             id_ex_csr_wen2,
    input      [11:0] id_ex_csr_wr_addr1,
    // input      [11:0] id_ex_csr_wr_addr2,
    input             id_ex_csr_ecall,
    input             id_ex_csr_mret,
    input      [ 1:0] id_ex_csr_op,

    output reg        ex_flush,
    output reg [31:0] ex_flush_pc,
    output reg        ex_fencei,

    // output reg [31:0] ex_lsu_inst,
    // output reg [31:0] ex_lsu_pc,
    output reg [31:0] ex_lsu_src2,
    output reg        ex_lsu_RegWrite,
    output reg [ 3:0] ex_lsu_rd,
    output reg        ex_lsu_MemRead,
    output reg        ex_lsu_MemWrite,
    output reg [ 4:0] ex_lsu_MemLen,

    output reg        ex_lsu_csr,
    output reg        ex_lsu_csr_wen1,
    // output reg        ex_lsu_csr_wen2,
    output reg [11:0] ex_lsu_csr_wr_addr1,
    // output reg [11:0] ex_lsu_csr_wr_addr2,
    output reg [31:0] ex_lsu_csr_wr_data1,
    output reg [31:0] ex_lsu_csr_wr_data2,
    output reg [31:0] ex_lsu_csr_rdata,

    output reg        ex_lsu_csr_ecall,
    output reg        ex_lsu_csr_mret,

    output reg [31:0] ex_lsu_process_result

);
// `ifdef VERILATOR
    // import "DPI-C" function void ebreak(input int station, input int inst);
    // import "DPI-C" function void counter(input int inst_type, input int ifu_inc, input int lsu_inc, input int exu_inc);
// `endif
    
    // EXU 活跃周期计数
    // always @(posedge clk) begin
    //     if (reset) begin
    //         exu_active_cycles <= 0;
    //     end else if (id_valid && ex_ready) begin
    //         exu_active_cycles <= exu_active_cycles + 1;
    //     end
    // end

    // 前递后的源寄存器值
    // wire [31:0] src1 = (forward_rs1[1] ? ex_lsu_process_result : 
    //                    (forward_rs1[0] | load_use_flag[1]) ? lsu_wb_wdata : 
    //                    wb_ex_src1);
    // wire [31:0] src2 = (forward_rs2[1] ? ex_lsu_process_result : 
    //                    (forward_rs2[0] | load_use_flag[0]) ? lsu_wb_wdata : 
    //                    wb_ex_src2);
    // 前递信号定义
    wire [1:0] forward_rs1;
    wire [1:0] forward_rs2;
    wire       forward_las;
    wire [3:0] load_use_flag;
    
    wire [31:0] src1 = (forward_rs1[1])   ? ex_lsu_process_result : 
                       (forward_rs1[0])   ? lsu_wb_wdata : 
                       (load_use_flag[3]) ? lsu_wb_wdata : wb_ex_src1;

    wire [31:0] src2 = (forward_rs2[1])   ? ex_lsu_process_result : 
                       (forward_rs2[0])   ? lsu_wb_wdata : 
                       (load_use_flag[2]) ? lsu_wb_wdata : wb_ex_src2;

    // ALU 操作中间变量
    reg [31:0] ex_num1;
    reg [31:0] ex_num2;
    reg [31:0] process_result;

    // ALU 输入选择
    always @(*) begin
        ex_num1 = src1;
        if (id_ex_MemRead | id_ex_MemWrite) begin
            ex_num2 = id_ex_imm;
        end
        else if (id_ex_jal | id_ex_jalr) begin
            ex_num1 = id_ex_pc;
            ex_num2 = 32'd4;
        end
        else if(id_ex_opcode == `INST_LUI) begin
            ex_num1 = id_ex_imm;
            ex_num2 = 32'd0;
        end
        else if(id_ex_opcode == `INST_AUIPC) begin
            ex_num1 = id_ex_pc;
            ex_num2 = id_ex_imm;
        end
        else if(id_ex_alu_op == `ALU_SLL || id_ex_alu_op == `ALU_SRL || id_ex_alu_op == `ALU_SRA) begin
            ex_num2 = (id_ex_opcode[6:2] == `INST_TYPE_I && !id_ex_shamt[5]) ? {27'd0, id_ex_shamt[4:0]} :
                      (id_ex_opcode[6:2] == `INST_TYPE_R)                    ? {27'd0, src2[4:0]}        : 32'd0;
        end
        else begin
            ex_num2 = (id_ex_opcode[6:2] == `INST_TYPE_R || id_ex_opcode[6:2] == `INST_TYPE_B) ? src2 : id_ex_imm;
        end
    end

    // ALU 操作
    reg        alu_zero;
    reg        alu_less;

    reg sign1, sign2;
    reg [31:0] sub_result;

    always @(*) begin
        sign1 = ex_num1[31];
        sign2 = ex_num2[31];
        sub_result = ex_num1 - ex_num2;
        case (id_ex_alu_op)
            `ALU_ADD:  process_result = ex_num1 + ex_num2;
            `ALU_SUB:  process_result = sub_result;
            `ALU_AND:  process_result = ex_num1 & ex_num2;
            `ALU_OR:   process_result = ex_num1 | ex_num2;
            `ALU_XOR:  process_result = ex_num1 ^ ex_num2;
            `ALU_SLTU: process_result = (ex_num1 < ex_num2) ? {31'b0, 1'b1} : 32'b0;
            // `ALU_SLT:  process_result = ($signed(ex_num1) < $signed(ex_num2)) ? {31'b0, 1'b1} : 32'b0;
            `ALU_SLT: begin
                if(sign1 != sign2) begin
                    process_result = sign1 ? {31'b0, 1'b1} : 32'b0;
                end
                else begin
                    process_result = sub_result[31] ? {31'b0, 1'b1} : 32'b0;
                end
            end
            `ALU_SRA:  process_result = $signed(ex_num1) >>> ex_num2[4:0];
            `ALU_SLL:  process_result = ex_num1 << ex_num2[4:0];
            `ALU_SRL:  process_result = ex_num1 >> ex_num2[4:0];
            default:   begin 
                process_result = 32'b0; 
            // `ifdef VERILATOR
            //     $display("Unkonw alu_op"); 
            // `endif
            end
        endcase
        alu_zero = (process_result == 32'b0);
        // alu_less = (id_ex_alu_op == `ALU_SLT)  ? ($signed(ex_num1) < $signed(ex_num2)) :
        //            (id_ex_alu_op == `ALU_SLTU) ? (ex_num1 < ex_num2) : 1'b0;
        alu_less = process_result[0];
    end

    // 分支和跳转逻辑
    // reg [31:0] jal_target;
    reg [31:0] fencei_target;
    reg [31:0] jalr_target;
    reg        take_branch;
    reg        ex_flush_condition;

    // wire [31:0] jalr_target = (src1 + id_ex_imm) & ~32'h1;
    // wire        take_branch = (id_ex_opcode == `INST_B) && (
    //                     (id_ex_func3 == `F3_BNE  && !alu_zero) ||  
    //                     (id_ex_func3 == `F3_BEQ  &&  alu_zero) ||  
    //                     (id_ex_func3 == `F3_BLT  &&  alu_less) || 
    //                     (id_ex_func3 == `F3_BGE  && !alu_less) ||  
    //                     (id_ex_func3 == `F3_BLTU &&  alu_less) ||  
    //                     (id_ex_func3 == `F3_BGEU && !alu_less));

    always @(*) begin
        // jal_target  = id_ex_pc + id_ex_imm;
        ex_flush    = (reset) ? 1'b0 : (ex_flush_condition & (~|load_use_flag));
        ex_fencei   = id_ex_fencei;
        fencei_target = id_ex_pc + 32'h4;
        jalr_target = (src1 + id_ex_imm) & 32'hfffffffe;
        take_branch = (id_ex_opcode == `INST_B) && (
                    (id_ex_func3 == `F3_BNE  && !alu_zero) ||  // bne
                    (id_ex_func3 == `F3_BEQ  &&  alu_zero) ||  // beq
                    ( alu_less && (id_ex_func3 == `F3_BLT || id_ex_func3 == `F3_BLTU)) || // blt/bltu
                    (!alu_less && (id_ex_func3 == `F3_BGE || id_ex_func3 == `F3_BGEU))    // bge/bgeu 
        );
        case(1'b1)
            // id_ex_jal: begin
            //     // ex_flush    = 1'b1 & ex_flush_condition & (~(|load_use_flag));
            //     // ex_flush_pc = jal_target;
            //     ex_flush = 1'b0;
            //     ex_flush_pc = 32'h0;
            // end
            id_ex_fencei: begin
                ex_flush_pc = fencei_target;
            end
            id_ex_jalr: begin
                ex_flush_pc = jalr_target;
            end
            id_ex_csr_ecall : begin
                ex_flush_pc = wb_ex_csr_num1;
            end
            id_ex_csr_mret: begin
                ex_flush_pc = wb_ex_csr_num2;
            end
            take_branch: begin
                ex_flush_pc = id_ex_pc + id_ex_imm;   
            end
            default: begin
                ex_flush    = 1'b0; // 非分支指令不需要冲刷
                ex_flush_pc = 32'h0;
            end
        endcase
    end
    
    always @(posedge clk)begin
        if(reset)begin
            ex_flush_condition <= 1'b1;
        end
        else if(ex_flush)begin
            ex_flush_condition <= 1'b0;
        end
        else if(id_valid)begin
            ex_flush_condition <= 1'b1;
        end
    end

    // reg [31:0] csr_write_ecall;
    // always @(*) begin
    //     if (id_ex_csr_ecall) begin
    //         csr_write_ecall = id_ex_pc;
    //     end
    //     else begin
    //         csr_write_ecall = 32'b0;
    //     end
    // end

    // wire [31:0] mstatus;
    wire [31:0] mpie;
    wire [31:0] zimm;
    assign mpie = (wb_ex_csr_num1 >> 7) & 32'h1;
    // assign mstatus = (((wb_ex_csr_num1 & ~(32'h3 << 11)) & ~(32'h1 << 3)) | (mpie << 3)) | (32'h1 << 7);
    assign zimm = {27'b0, id_ex_zimm};

    reg [31:0] csr_write_data;
    always @(*) begin
        case(1'b1)
            (id_ex_csr_op == `CSR_CSRRW && id_ex_func3 == `F3_CSRRW) : csr_write_data = src1;
            // (id_ex_csr_op == `CSR_CSRRC && id_ex_func3 == `F3_CSRRC): csr_write_data = (wb_ex_csr_num1 & ~src1);
            (id_ex_csr_op == `CSR_CSRRS && id_ex_func3 == `F3_CSRRS) : csr_write_data = (wb_ex_csr_num1 | src1);
            (id_ex_csr_op == `CSR_CSRRW && id_ex_func3 == `F3_CSRRWI): csr_write_data = zimm;
            // (id_ex_csr_op == `CSR_CSRRC && id_ex_func3 == `F3_CSRRCI):csr_write_data = wb_ex_csr_num1 & ~zimm;
            (id_ex_csr_op == `CSR_CSRRS && id_ex_func3 == `F3_CSRRSI): csr_write_data = wb_ex_csr_num1 | zimm;
            (                                        id_ex_csr_ecall): csr_write_data = 32'd11;
            // (                                         id_ex_csr_mret): csr_write_data = mstatus;
            default:                                                   csr_write_data = 32'b0;
        endcase
    end

    // wire [31:0] csr_write_data = (id_ex_csr_op == `CSR_CSRRW && id_ex_func3 == `F3_CSRRW) ? src1                                   :
    //                              (id_ex_csr_op == `CSR_CSRRC && id_ex_func3 == `F3_CSRRC) ? (wb_ex_csr_num1 & ~src1)               :
    //                              (id_ex_csr_op == `CSR_CSRRS && id_ex_func3 == `F3_CSRRS) ? (wb_ex_csr_num1 | src1)                :
    //                              (id_ex_csr_op == `CSR_CSRRW && id_ex_func3 == `F3_CSRRWI)? zimm                                   :
    //                              (id_ex_csr_op == `CSR_CSRRC && id_ex_func3 == `F3_CSRRCI)? wb_ex_csr_num1 & ~zimm                 :
    //                              (id_ex_csr_op == `CSR_CSRRS && id_ex_func3 == `F3_CSRRSI)? wb_ex_csr_num1 | zimm                  :
    //                              (                                        id_ex_csr_ecall)? 32'd11                                 :
    //                              (                                         id_ex_csr_mret)? mstatus                                :
    //                                                                                         32'b0;

    wire forward_flag1 = ex_lsu_RegWrite & (|ex_lsu_rd) & ex_lsu_valid;
    wire forward_flag2 = lsu_wb_RegWrite & (|lsu_wb_rd) & lsu_wb_valid;
    wire use_flag1 = lsu_ex_forward_MemRead & lsu_ex_forward_RegWrite & (|lsu_ex_forward_rd);
    wire use_flag2 = ex_lsu_MemRead & ex_lsu_RegWrite & (|ex_lsu_rd) & ex_lsu_valid;


    assign forward_rs1[1] = forward_flag1 & (ex_lsu_rd == id_wb_rs1);
    assign forward_rs1[0] = forward_flag2 & (lsu_wb_rd == id_wb_rs1);
    assign forward_rs2[1] = forward_flag1 & (ex_lsu_rd == id_wb_rs2);
    assign forward_rs2[0] = forward_flag2 & (lsu_wb_rd == id_wb_rs2);

    assign forward_las = id_ex_MemWrite & ex_lsu_MemRead & ex_lsu_RegWrite & ex_lsu_valid &
                         (|ex_lsu_rd) & (ex_lsu_rd != id_wb_rs1) & (ex_lsu_rd == id_wb_rs2);

    assign load_use_flag[3] = use_flag1 & (lsu_ex_forward_rd == id_wb_rs1);
    assign load_use_flag[2] = use_flag1 & (lsu_ex_forward_rd == id_wb_rs2);
    assign load_use_flag[1] = use_flag2 & (ex_lsu_rd == id_wb_rs1);
    assign load_use_flag[0] = use_flag2 & (ex_lsu_rd == id_wb_rs2);

    // 流水线控制
    always @(*) begin
        if(reset) begin
            ex_ready = 1'b0;
        end
        else begin
            ex_ready = (lsu_ready || ~ex_lsu_valid) && (load_use_flag == 4'b0);
        end
    end

    always @(posedge clk) begin
        if (reset) begin
            ex_lsu_valid <= 1'b0;
        end
        else if ((id_valid && ex_ready) && (lsu_ready || ~ex_lsu_valid)) begin
            ex_lsu_valid <= 1'b1;
        end
        else if (~(id_valid && ex_ready) && lsu_ready) begin
            ex_lsu_valid <= 1'b0;
        end
    end

    // 输出信号赋值
    always @(posedge clk) begin
        if (reset) begin
            ex_lsu_src2           <= 32'h0;
            ex_lsu_RegWrite       <= 1'b0;
            ex_lsu_rd             <= 4'b0;
            ex_lsu_MemRead        <= 1'b0;
            ex_lsu_MemWrite       <= 1'b0;
            ex_lsu_MemLen         <= 5'b0;
            ex_lsu_process_result <= 32'h0;
            ex_lsu_forward_las    <= 1'b0;
            ex_lsu_csr            <= 1'b0;
            ex_lsu_csr_wen1       <= 1'b0;
            ex_lsu_csr_wr_addr1   <= 12'b0;
            ex_lsu_csr_wr_data1   <= 32'h0;
            ex_lsu_csr_wr_data2   <= 32'h0;
            ex_lsu_csr_rdata      <= 32'h0;
            ex_lsu_csr_ecall      <= 1'b0;
            ex_lsu_csr_mret       <= 1'b0;
        end
        else if (id_valid && ex_ready) begin
            ex_lsu_src2           <= src2;
            ex_lsu_RegWrite       <= id_ex_RegWrite;
            ex_lsu_rd             <= id_ex_rd;
            ex_lsu_MemRead        <= id_ex_MemRead;
            ex_lsu_MemWrite       <= id_ex_MemWrite;
            ex_lsu_MemLen         <= id_ex_MemLen;
            ex_lsu_process_result <= process_result;
            ex_lsu_forward_las    <= forward_las;
            ex_lsu_csr            <= (id_ex_csr_wen1 | id_ex_csr_ecall | id_ex_csr_mret);
            ex_lsu_csr_wen1       <= id_ex_csr_wen1;
            ex_lsu_csr_wr_addr1   <= id_ex_csr_wr_addr1;
            ex_lsu_csr_wr_data1   <= csr_write_data;
            ex_lsu_csr_wr_data2   <= (id_ex_csr_ecall) ? id_ex_pc : 32'b0;
            ex_lsu_csr_rdata      <= wb_ex_csr_num1;
            ex_lsu_csr_ecall      <= id_ex_csr_ecall;
            ex_lsu_csr_mret       <= id_ex_csr_mret;
        end
    end
endmodule

// Included from ./pipeline-soc-vsrc/ysyx_25010030_iCache.v

module ysyx_25010030_iCache #(
    parameter CACHE_SIZE = 32,   
    parameter BLOCK_SIZE = 16    
)(
    input wire        clk,       
    input wire        reset,     
    input wire        is_fencei,  
    input wire [31:0] addr,      
    output reg [31:0] inst,      
    output reg        valid,     

    // AXI接口信号（支持突发传输）
    output reg  [31:0] axi_araddr,  
    output reg         axi_arvalid, 
    input  wire        axi_arready, 
    output wire [ 3:0] axi_arid,
    output wire [ 7:0] axi_arlen,   
    output wire [ 2:0] axi_arsize,  
    output wire [ 1:0] axi_arburst, 
    input  wire        axi_rvalid,  
    output reg         axi_rready,  
    input  wire [31:0] axi_rdata,   
    input  wire [ 1:0] axi_rresp,   
    input  wire [ 3:0] axi_rid,
    input  wire        axi_rlast    
);
`ifdef VERILATOR
    // import "DPI-C" function void cache_counter(input bit ihit);
`endif

    // 地址划分 - 直接映射结构（块大小16字节）
    // 31           标签         直接映射索引    块内偏移(4位)  0
    // +-------------+-----------+------------+
    // |     tag     |  index    |  offset    |
    // +-------------+-----------+------------+
    localparam NUM_BLOCKS         = CACHE_SIZE / BLOCK_SIZE;  // 总块数
    localparam BLOCK_OFFSET_WIDTH = $clog2(BLOCK_SIZE);       // 块内偏移宽度（4位 for 16字节）
    localparam INDEX_WIDTH        = $clog2(NUM_BLOCKS);       // 直接映射索引宽度
    localparam TAG_WIDTH          = 32 - INDEX_WIDTH - BLOCK_OFFSET_WIDTH; // 标签宽度
    localparam BEATS_PER_BLOCK    = BLOCK_SIZE / 4;           // 每块的32位数据数（16/4=4）

    // 存储器定义 
    reg [TAG_WIDTH-1:0] tag_ram   [0:NUM_BLOCKS-1];          // 标签存储器
    reg [         31:0] data_ram  [0:NUM_BLOCKS-1][0:BEATS_PER_BLOCK-1]; // 数据存储器
    reg                 valid_ram [0:NUM_BLOCKS-1];          // 有效位       

    // 地址分解
    wire [         TAG_WIDTH-1:0] req_tag    = addr[31 : 32 - TAG_WIDTH];
    wire [       INDEX_WIDTH-1:0] req_index  = addr[INDEX_WIDTH + BLOCK_OFFSET_WIDTH - 1 : BLOCK_OFFSET_WIDTH];
    wire [                   1:0] beat_idx   = addr[3:2];  // 块内32位数据索引

    // reg hit;   

    // 保存当前请求信息
    reg [         TAG_WIDTH-1:0] saved_tag;      // 保存标签
    reg [       INDEX_WIDTH-1:0] saved_index;    // 保存索引
    reg [                   1:0] saved_beat_idx; // 保存块内数据索引

    // 状态机定义
    localparam IDLE = 2'b00;
    // localparam MISS = 2'b01;
    localparam READ = 2'b11;  // 接收突发传输数据
    localparam FILL = 2'b10;  // 填充缓存块

    reg [1:0] state, next_state;

    reg [ 1:0] beat_cnt;  // 已接收的突发beat数（0-3）
    reg [31:0] block_data [0:BEATS_PER_BLOCK-1];  // 存储块内所有32位数据
    reg        ar_done;

    localparam SDRAM_BASE        = 32'hA0000000;  
    localparam SDRAM_END         = 32'hBFFFFFFF;
`ifdef YSYXSOC
    wire in_sdram = (addr >= SDRAM_BASE) && (addr <= SDRAM_END);
`else
    wire in_sdram = 0;
`endif

    // 状态寄存器
    always @(posedge clk) begin
        if (reset) begin
            state <= IDLE;
        end else begin
            state <= next_state;
        end
    end

    // 状态转换逻辑
    wire hit;
    always @(*) begin
        case (state)
            IDLE: next_state = hit ? IDLE : READ;
        `ifdef YSYXSOC
            READ: next_state = (axi_rvalid && axi_rready && axi_rlast) ? FILL : READ;
        `else
            READ: next_state = (axi_rvalid && axi_rready && axi_rlast) ? IDLE : READ;
        `endif
            FILL: next_state = IDLE; 
            default: next_state = IDLE;
        endcase
    end

    assign hit = valid_ram[req_index] && (tag_ram[req_index] == req_tag) && !is_fencei && in_sdram;

    // AXI突发传输配置与控制
    assign axi_arid    = 4'h0;    // 固定ID
    assign axi_arlen   = in_sdram ? 8'h3   : 8'b0;    // 突发长度4拍（16字节块）
    assign axi_arburst = in_sdram ? 2'b01 : 2'b00;   // 递增突发
    assign axi_arsize  = 3'b010;  // 4字节
    
    // FENCE.I指令处理：清空所有缓存块的有效位
    integer idx;
    // always @(posedge clk) begin
    //     if(is_fencei || reset) begin
    //         for (idx = 0; idx < NUM_BLOCKS; idx = idx + 1) begin
    //             valid_ram[idx] <= 1'b0;
    //         end
    //     end
    // end
    
    // 缓存初始化、命中处理、填充处理（无LRU逻辑）
    integer b;
    always @(posedge clk) begin
        if (reset) begin
            // 初始化缓存：所有块无效
            for (idx = 0; idx < NUM_BLOCKS; idx = idx + 1) begin
                valid_ram[idx] <= 1'b0;
            end
            inst  <= 32'h0;
            valid <= 1'b0;

            axi_rready <= 1'b0;
            axi_arvalid <= 1'b0;
        end else begin
            if (is_fencei) begin
                for (idx = 0; idx < NUM_BLOCKS; idx = idx + 1) begin
                    valid_ram[idx] <= 1'b0;
                end
            end
            case (state)
                IDLE: begin
                    axi_rready <= 1'b0;
                    beat_cnt   <= 2'h0;
                    ar_done    <= 1'b0;

                    saved_tag      <= req_tag;
                    saved_index    <= req_index;
                    saved_beat_idx <= beat_idx; 
                    
                    if (hit) begin
                        inst  <= data_ram[req_index][beat_idx];
                        valid <= 1'b1;
                    end 
                    else begin
                        valid <= 1'b0;
                    end
                end

                READ: begin
                    valid <= 1'b0;
                    axi_rready <= 1'b1;
                    if(!axi_arvalid && !ar_done) begin 
                        axi_arvalid <= 1'b1;
                        axi_araddr  <= in_sdram ? {addr[31:BLOCK_OFFSET_WIDTH], {BLOCK_OFFSET_WIDTH{1'b0}}} : addr;
                    end
                    else if(axi_arready) begin
                        axi_arvalid <= 1'b0;
                        ar_done <= 1'b1;
                    end
                    if (axi_rvalid) begin
                    `ifdef YSYXSOC
                        block_data[beat_cnt] <= axi_rdata;
                        beat_cnt <= in_sdram ? beat_cnt + 1'b1 : 2'b0;
                    `else
                        inst <= axi_rdata;
                        valid <= 1'b1;
                    `endif
                    end
                end

                FILL: begin
                    axi_rready <= 1'b0;
                    valid_ram[saved_index] <= 1'b1;
                    tag_ram[saved_index]   <= saved_tag;
                    for (b = 0; b < BEATS_PER_BLOCK; b = b + 1) begin
                        data_ram[saved_index][b] <= block_data[b];
                    end
                    inst  <= in_sdram ? block_data[saved_beat_idx] : block_data[2'b0];
                    valid <= 1'b1;
                end
                default: begin end
            endcase
        end
    end

endmodule

// Included from ./pipeline-soc-vsrc/ysyx_25010030_ID.v

module ysyx_25010030_ID (
    input             clk,                  
    input             reset,                
    input      [31:0] if_id_pc,              
    input      [31:0] if_id_inst,            
    input             ex_flush,             

    // 握手信号
    input             if_valid,               
    output reg        id_ready,               
    input             ex_ready,               
    output reg        id_valid,  

    output reg        sim_end,             

    output reg [31:0] id_ex_pc,             
    // output reg [31:0] id_ex_inst,         
    output reg        id_ex_RegWrite,       
    output reg [ 3:0] id_ex_rd,             
    output reg [ 3:0] id_wb_rs1,            
    output reg [ 3:0] id_wb_rs2,            
    output reg [ 4:0] id_ex_zimm,            
    output reg [31:0] id_ex_imm,            
    output reg [ 5:0] id_ex_shamt,         

    output reg [ 3:0] id_ex_alu_op,
    output reg [ 4:0] id_ex_MemLen,
    output reg        id_ex_MemWrite,
    output reg        id_ex_MemRead,
    output reg [ 6:0] id_ex_opcode,
    output reg [ 2:0] id_ex_func3,

    output reg        id_ex_jal,              
    output reg        id_ex_jalr,
    output reg        id_ex_fencei,             

    // output reg        id_ex_csr,             
    output reg        id_ex_csr_wen1,         
    // output reg        id_ex_csr_wen2,        
    output reg        id_ex_csr_ecall,        
    output reg        id_ex_csr_mret,        
    output reg [ 1:0] id_ex_csr_op,

    output reg [11:0] id_ex_csr_wr_addr1,     
    // output reg [11:0] id_ex_csr_wr_addr2,    
    output reg [11:0] id_wb_csr_addr1,        
    output reg [11:0] id_wb_csr_addr2         
);
`ifdef VERILATOR
    // import "DPI-C" function void counter(input int inst_type, input int ifu_inc, input int lsu_inc, input int exu_inc);
`endif
    // 指令字段提取
    localparam FENCEI = 32'h0000100f;
    wire [6:0] opcode = if_id_inst[ 6: 0];
    wire [3:0] rs1    = if_id_inst[18:15];
    wire [3:0] rs2    = if_id_inst[23:20];
    wire [3:0] rd     = if_id_inst[10: 7];
    wire [2:0] func3  = if_id_inst[14:12];
    // wire [6:0] func7  = if_id_inst[31:25];
    wire       func7_5 = if_id_inst[30];
    wire [5:0] shamt  = if_id_inst[25:20];
    wire [4:0] zimm   = if_id_inst[19:15];
    wire [4:0] get_opcode = opcode[ 6: 2];

    // 立即数生成
    wire [31:0] immI   = {{20{if_id_inst[31]}}, if_id_inst[31:20]};
    wire [31:0] immU   = {if_id_inst[31:12], 12'b0};
    wire [31:0] immS   = {{20{if_id_inst[31]}}, if_id_inst[31:25], if_id_inst[11:7]};
    wire [31:0] immB   = {{20{if_id_inst[31]}}, if_id_inst[7], if_id_inst[30:25], if_id_inst[11:8], 1'b0};
    wire [31:0] immJ   = {{12{if_id_inst[31]}}, if_id_inst[19:12], if_id_inst[20], if_id_inst[30:21], 1'b0};
    wire [31:0] immR   = 32'b0;
    wire [31:0] immCSR = {27'b0, if_id_inst[19:15]};

    // reg [31:0] inst_type;

    // 握手逻辑
    always @(*) begin
        if(reset) begin
            id_ready = 1'b0;
        end
        else begin
            id_ready = (ex_ready || ~id_valid) && ~ex_flush;
        end
    end

    always @(posedge clk) begin
        if (reset) begin
            id_valid <= 1'b0;
        end
        else if ((if_valid && id_ready) && (ex_ready || ~id_valid)) begin
            id_valid <= 1'b1;
        end
        else if ((~(if_valid && id_ready)) && ex_ready) begin
            id_valid <= 1'b0;
        end
    end

    // 译码逻辑和输出信号赋值
    always @(posedge clk) begin
        if (reset) begin
            // inst_type <= 7;
            sim_end         <= 1'b0;

            id_ex_RegWrite  <= 1'b0;
            id_ex_MemWrite  <= 1'b0;
            id_ex_MemRead   <= 1'b0;
            id_ex_jal       <= 1'b0;
            id_ex_jalr      <= 1'b0;
            id_ex_fencei    <= 1'b0;
            // id_ex_csr       <= 1'b0;
            id_ex_csr_wen1  <= 1'b0;
            // id_ex_csr_wen2  <= 1'b0;
            id_ex_csr_ecall <= 1'b0;
            id_ex_csr_mret  <= 1'b0;
            
            id_ex_rd    <= 4'b0;
            id_wb_rs1   <= 4'b0;
            id_wb_rs2   <= 4'b0;
            id_ex_zimm  <= 5'b0;
            id_ex_imm   <= 32'b0;
            id_ex_shamt <= 6'b0;
            
            id_ex_pc   <= 32'b0;
            // id_ex_inst <= 32'b0;
            
            id_ex_alu_op <= `ALU_ADD;
            id_ex_MemLen <= `Mem_Word;
            id_ex_opcode <= 7'b0;
            id_ex_func3  <= 3'b0;
            id_ex_csr_op <= `CSR_NONE;
            
            id_ex_csr_wr_addr1 <= 12'b0;
            // id_ex_csr_wr_addr2 <= 12'b0;
            id_wb_csr_addr1    <= 12'b0;
            id_wb_csr_addr2    <= 12'b0;
        end
        else if (if_valid && id_ready) begin
            sim_end <= (if_id_inst == 32'h00100073);
            // 传递基本信号
            id_ex_pc     <= if_id_pc;
            // id_ex_inst   <= if_id_inst;
            id_ex_rd     <= rd;
            id_wb_rs1    <= rs1;
            id_wb_rs2    <= rs2;
            id_ex_zimm   <= zimm;  
            id_ex_shamt  <= shamt;
            id_ex_opcode <= opcode;
            id_ex_func3  <= func3;

            // 初始化默认值
            id_ex_imm       <= 32'b0;
            id_ex_RegWrite  <= 1'b0;
            id_ex_MemWrite  <= 1'b0;
            id_ex_MemRead   <= 1'b0;
            id_ex_alu_op    <= `ALU_ADD;
            id_ex_MemLen    <= `Mem_Word;
            id_ex_csr_op    <= `CSR_NONE;
            id_ex_csr_wen1  <= 1'b0;
            // id_ex_csr_wen2  <= 1'b0;
            id_ex_csr_ecall <= 1'b0;
            id_ex_csr_mret  <= 1'b0;
            id_ex_jal       <= 1'b0;
            id_ex_jalr      <= 1'b0;
            id_ex_fencei    <= (if_id_inst == FENCEI);

            id_ex_csr_wr_addr1 <= 12'b0;
            // id_ex_csr_wr_addr2 <= 12'b0;
            id_wb_csr_addr1    <= 12'b0;
            id_wb_csr_addr2    <= 12'b0;

            // 译码逻辑
            case (get_opcode)
                `INST_TYPE_LUI: begin
                    id_ex_imm      <= immU;
                    id_ex_RegWrite <= 1'b1;
                    // inst_type      <= 1;
                end
                `INST_TYPE_AUIPC: begin
                    id_ex_imm      <= immU;
                    id_ex_RegWrite <= 1'b1;
                    id_ex_alu_op   <= `ALU_ADD;  // PC + imm
                    // inst_type      <= 1;
                end
                `INST_TYPE_JAL: begin
                    id_ex_imm      <= immJ;
                    id_ex_RegWrite <= 1'b1;
                    id_ex_jal      <= 1'b1;
                    // inst_type      <= 2;
                end
                `INST_TYPE_JALR: begin
                    if (func3 == 3'b000) begin
                        id_ex_imm      <= immI;
                        id_ex_RegWrite <= 1'b1;
                        id_ex_jalr     <= 1'b1;
                        // inst_type      <= 2;
                    end
                end
                `INST_TYPE_S: begin
                    id_ex_imm      <= immS;
                    id_ex_MemWrite <= 1'b1;
                    case (func3)
                        `F3_SW: id_ex_MemLen <= `Mem_Word;
                        `F3_SH: id_ex_MemLen <= `Mem_Half;
                        `F3_SB: id_ex_MemLen <= `Mem_Bit;
                        default: begin end
                    endcase
                    // inst_type <= 5;
                end
                `INST_TYPE_L: begin
                    id_ex_imm      <= immI;
                    id_ex_RegWrite <= 1'b1;
                    id_ex_MemRead  <= 1'b1;
                    id_ex_alu_op   <= `ALU_ADD;
                    case (func3)
                        `F3_LW:  id_ex_MemLen <= `Mem_Word;
                        `F3_LH:  id_ex_MemLen <= `Mem_Half;
                        `F3_LB:  id_ex_MemLen <= `Mem_Bit;
                        `F3_LHU: id_ex_MemLen <= `Mem_UHalf;
                        `F3_LBU: id_ex_MemLen <= `Mem_UBit;
                        default: begin end
                    endcase
                    // inst_type <= 3;
                end
                `INST_TYPE_R: begin
                    id_ex_imm      <= immR;
                    id_ex_RegWrite <= 1'b1;
                    case (func3)
                        3'b000:   id_ex_alu_op <= (func7_5) ? `ALU_SUB : `ALU_ADD;
                        `F3_ANDI: id_ex_alu_op <= `ALU_AND;
                        `F3_ORI:  id_ex_alu_op <= `ALU_OR;
                        `F3_XORI: id_ex_alu_op <= `ALU_XOR;
                        `F3_SLTU: id_ex_alu_op <= `ALU_SLTU;
                        `F3_SLT:  id_ex_alu_op <= `ALU_SLT;
                        `F3_RSH:  id_ex_alu_op <= (func7_5) ? `ALU_SRA : `ALU_SRL;
                        `F3_LSH:  id_ex_alu_op <= `ALU_SLL;
                        default: begin end
                    endcase
                    // inst_type <= 0;/
                end
                `INST_TYPE_I: begin
                    id_ex_imm <= immI;
                    id_ex_RegWrite <= 1'b1;
                    case (func3)
                        `F3_ADDI: id_ex_alu_op <= `ALU_ADD;
                        `F3_ANDI: id_ex_alu_op <= `ALU_AND;
                        `F3_ORI:  id_ex_alu_op <= `ALU_OR;
                        `F3_SLTU: id_ex_alu_op <= `ALU_SLTU;
                        `F3_SLTI: id_ex_alu_op <= `ALU_SLT;
                        `F3_XORI: id_ex_alu_op <= `ALU_XOR;
                        `F3_RSH:  id_ex_alu_op <= (func7_5) ? `ALU_SRA : `ALU_SRL;
                        `F3_LSH:  id_ex_alu_op <= `ALU_SLL;
                        default: begin end
                    endcase
                    // inst_type <=1;
                end
                `INST_TYPE_B: begin
                    id_ex_imm <= immB;
                    case (func3)
                        `F3_BEQ, `F3_BNE:   id_ex_alu_op <= `ALU_SUB;
                        `F3_BLT, `F3_BGE:   id_ex_alu_op <= `ALU_SLT;
                        `F3_BLTU, `F3_BGEU: id_ex_alu_op <= `ALU_SLTU;
                        default: begin end
                    endcase
                    // inst_type <= 4;
                end
                `INST_TYPE_E: begin
                    if (opcode == `INST_CSR) begin
                        // id_ex_csr      <= 1'b1;
                        id_ex_csr_wen1 <= 1'b1;
                        case (func3)
                            `F3_CSRRW: begin
                                id_ex_RegWrite <= 1'b1;
                                id_ex_csr_op   <= `CSR_CSRRW;
                            end
                            `F3_CSRRS: begin
                                id_ex_RegWrite <= 1'b1;
                                id_ex_csr_op   <= `CSR_CSRRS;
                            end
                            // `F3_CSRRC: begin
                            //     id_ex_RegWrite <= 1'b1;
                            //     id_ex_csr_op   <= `CSR_CSRRC;
                            // end
                            `F3_CSRRWI: begin
                                id_ex_RegWrite <= 1'b1;
                                id_ex_csr_op   <= `CSR_CSRRW;
                                id_ex_imm      <= immCSR;
                            end
                            `F3_CSRRSI: begin
                                id_ex_RegWrite <= 1'b1;
                                id_ex_csr_op   <= `CSR_CSRRS;
                                id_ex_imm      <= immCSR;
                            end
                            // `F3_CSRRCI: begin
                            //     id_ex_RegWrite <= 1'b1;
                            //     id_ex_csr_op   <= `CSR_CSRRC;
                            //     id_ex_imm      <= immCSR;
                            // end
                            `F3_ECALL: begin
                                if (if_id_inst == `INST_ECALL) begin
                                    id_ex_csr_ecall <= 1'b1;
                                    // id_ex_csr_wen2  <= 1'b1;
                                    id_ex_imm       <= 32'h0;
                                end
                                else if (if_id_inst == `INST_MRET) begin
                                    id_ex_csr_mret <= 1'b1;
                                    id_ex_imm      <= 32'h0;
                                end
                            end
                            default: begin end
                        endcase
                        // id_ex_csr_wr_addr1 <= (if_id_inst == `INST_ECALL) ? `MCAUSE : ((if_id_inst == `INST_MRET) ? `MSTATUS : if_id_inst[31:20]);
                        id_ex_csr_wr_addr1 <= if_id_inst[31:20];
                        // id_ex_csr_wr_addr2 <= (if_id_inst == `INST_ECALL) ? `MEPC : 12'b0;
                        id_wb_csr_addr1    <= (if_id_inst == `INST_MRET) ? `MSTATUS : ((if_id_inst == `INST_ECALL) ? `MTVEC : if_id_inst[31:20]);
                        id_wb_csr_addr2    <= (if_id_inst == `INST_MRET) ? `MEPC : 12'b0;
                        // inst_type <= 6;
                    end
                end
                default: begin
                    // inst_type <= 7;
                end
            endcase
        // `ifdef VERILATOR
        //     if(inst_type != 7) begin
        //         counter(inst_type, 0, 0, 0);
        //     end
        // `endif
        end
    end
endmodule

// Included from ./pipeline-soc-vsrc/ysyx_25010030_IF_AXI.v
// `include "./ysyx_25010030_iCache.v"

module ysyx_25010030_IF_AXI (
    input             clk,
    input             reset,

    input             EX_flush,
    input      [31:0] EX_flush_pc,
    // input             ex_fencei,

    input             ID_ready,
    output reg        IF_valid,

    output reg [31:0] IF_ID_pc,
    output reg [31:0] IF_ID_inst,

    // AXI4-Lite 接口信号（与 SRAM 连接）
    output reg        if_axi_arvalid,       // 读地址有效
    // input             axi_if_arready,       // 读地址就绪
    output reg [31:0] if_axi_araddr,        // 读地址
    output reg [ 3:0] if_axi_arid,
    output reg [ 7:0] if_axi_arlen,
    output reg [ 2:0] if_axi_arsize,
    output reg [ 1:0] if_axi_arburst,
    // input      [31:0] axi_if_rdata,         // 读数据
    // input             axi_if_rvalid,        // 读数据有效
    output reg        if_axi_rready,        // 读数据就绪
    // input      [ 1:0] axi_if_rresp,         // 读响应
    // input      [ 3:0] axi_if_rid,
    // input             axi_if_rlast
    output reg [31:0] next_pc,
    input      [31:0] cache_inst,
    input             cache_valid,
    input      [31:0] cache_araddr,
    input             cache_arvalid,
    input      [ 3:0] cache_arid,
    input      [ 7:0] cache_arlen,
    input      [ 2:0] cache_arsize,
    input      [ 1:0] cache_arburst,
    input             cache_rready
    // output reg [31:0] ifu_active_cycles
);
// `ifdef VERILATOR
    // import "DPI-C" function void counter(input int inst_type, input int ifu_inc, input int lsu_inc, input int exu_inc);
// `endif

    // 状态机定义
    reg [1:0] ifu_state;
    localparam IDLE       = 2'b00;
    localparam WAIT_FLUSH = 2'b01;
    localparam WAIT_CACHE = 2'b11;  // 等待缓存响应

    // localparam FENCEI = 32'h0000100f;
    localparam JAL_OPCODE = 7'b1101111;

    // 内部信号
    // reg [31:0] next_pc;
    // reg cache_req;
    reg flush_once;
    reg once;
    
    // cache接口信号
    // wire [31:0] cache_inst;
    // wire        cache_valid;

    // wire [31:0] cache_araddr;
    // wire        cache_arvalid;
    // wire [ 3:0] cache_arid;
    // wire [ 7:0] cache_arlen;
    // wire [ 2:0] cache_arsize;
    // wire [ 1:0] cache_arburst;
    // wire        cache_rready;

    // wire        is_fencei = (IF_ID_inst == FENCEI);
    wire        is_jal    = (cache_inst[6:0] == JAL_OPCODE);
    wire [31:0] immJ      = {{12{cache_inst[31]}}, cache_inst[19:12], cache_inst[20], cache_inst[30:21], 1'b0};
    wire [31:0] jal_target = (flush_once ? IF_ID_pc : next_pc) + immJ;
    
    // 实例化iCache模块
    // ysyx_25010030_iCache u_icache (
    //     .clk            (clk           ),
    //     .reset          (reset         ),
    //     .is_fencei      (ex_fencei     ),
    //     .addr           (next_pc       ),
    //     .inst           (cache_inst    ),
    //     .valid          (cache_valid   ),
    //     .axi_araddr     (cache_araddr  ),
    //     .axi_arvalid    (cache_arvalid ),
    //     .axi_arready    (axi_if_arready),
    //     .axi_arid       (cache_arid    ),  
    //     .axi_arlen      (cache_arlen   ),  
    //     .axi_arsize     (cache_arsize  ),  
    //     .axi_arburst    (cache_arburst ),  
    //     .axi_rvalid     (axi_if_rvalid ),
    //     .axi_rready     (cache_rready  ),
    //     .axi_rdata      (axi_if_rdata  ),
    //     .axi_rresp      (axi_if_rresp  ),
    //     .axi_rid        (axi_if_rid    ),  
    //     .axi_rlast      (axi_if_rlast  )   
    // );

    // 统计活跃周期
    // always @(posedge clk) begin
    //     if (reset) begin
    //         ifu_active_cycles <= 0;
    //     end else if (ifu_state != IDLE || cache_arvalid) begin
    //         ifu_active_cycles <= ifu_active_cycles + 1;
    //     end
    // end

    // AXI信号转发（缓存 -> 外部总线）
    always @(*) begin
        // if (cache_arvalid || cache_rready) begin
            if_axi_arvalid = cache_arvalid;
            if_axi_araddr  = cache_araddr;
            if_axi_rready  = cache_rready;
            if_axi_arid    = cache_arid;
            if_axi_arlen   = cache_arlen;
            if_axi_arsize  = cache_arsize;
            if_axi_arburst = cache_arburst;
        // end else begin
        //     if_axi_arvalid = 0;
        //     if_axi_araddr  = 0;
        //     if_axi_rready  = 0;
        //     if_axi_arid    = 0;
        //     if_axi_arlen   = 0;
        //     if_axi_arsize  = 0;
        //     if_axi_arburst = 0;
        // end
    end

    // 主控制逻辑
    always @(posedge clk) begin
        if (reset) begin
        `ifdef NPC
            IF_ID_pc   <= `RESET_PC;
            next_pc    <= `RESET_PC;
        `else
            IF_ID_pc   <= `RESET_FLASH_PC;
            next_pc    <= `RESET_FLASH_PC;
        `endif
            IF_ID_inst <= 0;
            IF_valid   <= 0;
            ifu_state  <= IDLE;
            // cache_req  <= 0;
            flush_once <= 0;
            once       <= 1;
        end
        else begin
            // 处理冲刷信号
            if (EX_flush) begin
                IF_valid   <= 0;
                next_pc    <= EX_flush_pc;
                flush_once <= 1;
                ifu_state  <= WAIT_CACHE;
            end
            else begin
                case (ifu_state)
                    IDLE: begin
                        // 准备新的取指请求
                        if ((IF_valid && ID_ready) || flush_once || once) begin
                            once       <= 0;
                            flush_once <= 0;
                            // cache_req  <= 1;
                            IF_valid   <= 0;
                            ifu_state  <= WAIT_FLUSH;
                        end
                    end
                    WAIT_FLUSH: begin
                        ifu_state <= WAIT_CACHE;
                    end
                    WAIT_CACHE: begin
                        // cache_req <= 0;
                        
                        // 缓存命中
                        if (cache_valid) begin
                            IF_ID_inst <= cache_inst;
                            IF_ID_pc   <= (flush_once) ? IF_ID_pc : next_pc;
                            IF_valid   <= (flush_once) ? 0 : 1;
                            next_pc    <= (flush_once) ? next_pc : (is_jal) ? jal_target : next_pc + 4;
                            ifu_state  <= IDLE;
                        // `ifdef VERILATOR
                        //     // 统计指令
                        //     counter(7, 1, 0, 0);
                        // `endif
                        end
                        
                    end

                    default: ifu_state <= IDLE;
                endcase
            end
        end
    end

endmodule

// Included from ./pipeline-soc-vsrc/ysyx_25010030_LSU_AXI.v


module ysyx_25010030_LSU_AXI (
    input         clk,
    input         rst,

    // 流水线握手信号
    input         ex_lsu_valid,       
    output reg    lsu_ex_ready,       
    input         wb_lsu_ready,       
    output reg    lsu_wb_valid,       

    // EX 阶段输入信号
    input         ex_lsu_forward_las,
    input         ex_lsu_RegWrite,    
    input  [ 3:0] ex_lsu_rd,          
    input         ex_lsu_MemRead,     
    input         ex_lsu_MemWrite,    
    input  [ 4:0] ex_lsu_MemLen,          
    input  [31:0] addr,               
    input  [31:0] data_in,              

    // CSR 相关信号
    input         ex_lsu_csr,
    input         ex_lsu_csr_wen1,
    // input         ex_lsu_csr_wen2,
    input  [31:0] ex_lsu_csr_wr_data1,
    input  [31:0] ex_lsu_csr_wr_data2,
    input  [11:0] ex_lsu_csr_wr_addr1,
    // input  [11:0] ex_lsu_csr_wr_addr2,
    input  [31:0] ex_lsu_csr_rdata,
    input         ex_lsu_csr_ecall,
    input         ex_lsu_csr_mret,
    input  [31:0] ex_lsu_process_result,

    // 前递信号
    output [ 3:0] lsu_ex_forward_rd,         
    output        lsu_ex_forward_RegWrite,   
    output        lsu_ex_forward_MemRead,    

    // 传递到 WB 阶段的信号
    output reg [31:0] lsu_wb_csr_wr_data1,
    output reg [31:0] lsu_wb_csr_wr_data2,
    output reg [11:0] lsu_wb_csr_wr_addr1,
    // output reg [11:0] lsu_wb_csr_wr_addr2,
    output reg        lsu_wb_csr_wen1,
    output reg        lsu_wb_csr_ecall,
    output reg        lsu_wb_RegWrite,        
    output reg [ 3:0] lsu_wb_rd,              
    output reg [31:0] lsu_wb_write_rd_data,   

    // AXI4-Lite 接口信号
    output reg        lsu_axi_arvalid,      
    input             axi_lsu_arready,      
    output wire [31:0] lsu_axi_araddr,
    output wire [ 3:0] lsu_axi_arid,
    output wire [ 7:0] lsu_axi_arlen,
    output reg  [ 2:0] lsu_axi_arsize,
    output wire [ 1:0] lsu_axi_arburst,        
    input      [31:0] axi_lsu_rdata,         
    input             axi_lsu_rvalid,       
    output reg        lsu_axi_rready,       
    input      [ 1:0] axi_lsu_rresp,
    input      [ 3:0] axi_lsu_rid,
    input             axi_lsu_rlast,         

    output wire [31:0] lsu_axi_awaddr,        
    output reg        lsu_axi_awvalid,      
    input             axi_lsu_awready, 
    output wire [ 3:0] lsu_axi_awid,
    output wire [ 7:0] lsu_axi_awlen,
    output reg  [ 2:0] lsu_axi_awsize,
    output wire [ 1:0] lsu_axi_awburst,     
    output wire [31:0] lsu_axi_wdata,         
    output wire [ 3:0] lsu_axi_wstrb,         
    output reg        lsu_axi_wvalid,       
    input             axi_lsu_wready,
    output reg        lsu_axi_wlast,       
    input      [ 1:0] axi_lsu_bresp,         
    input             axi_lsu_bvalid,       
    output wire       lsu_axi_bready,
    input      [ 3:0] axi_lsu_bid     

    // output reg [31:0] lsu_active_cycles
);
`ifdef VERILATOR
    // import "DPI-C" function void ebreak(input int station, input int inst);
    // import "DPI-C" function void counter(input int inst_type, input int ifu_inc, input int lsu_inc, input int exu_inc);
`endif 

    // parameter OKAY = 2'b00;

    localparam SDRAM_BASE        = 32'hA0000000;  
    localparam SDRAM_END         = 32'hBFFFFFFF;  
    localparam AXI_BURST_FIXED   = 2'b00;       
    localparam AXI_BURST_INCR    = 2'b01;   
    localparam AXI_SIZE_BYTE     = 3'h0;         
    localparam AXI_SIZE_HALF     = 3'h1;  
    localparam AXI_SIZE_WORD     = 3'h2;
    localparam AXI_ID            = 4'h0;  
    localparam BURST_LEN         = 4; 
    localparam BLOCK_SIZE        = 16;
`ifdef YSYXSOC
    wire in_sdram = (saved_addr >= SDRAM_BASE) && (saved_addr <= SDRAM_END);
`else
    wire in_sdram = 0;
`endif

    localparam BLOCK_OFFSET_WIDTH = 4; 
    // wire [BLOCK_OFFSET_WIDTH-1:0] req_offset  = addr[BLOCK_OFFSET_WIDTH - 1 : 0];  // 块内偏移（0-15）
    // wire [                   1:0] word_offset = req_offset[3:2]; 
    wire [                      1:0] word_offset = addr[3:2];

    reg [                   1:0] saved_word_offset;
    reg [                  31:0] saved_wdata;  
    reg [                   3:0] saved_wstrb; 
    reg [                   3:0] burst_cnt; 

    // reg  [31:0] cache_addr;
    reg  [ 1:0] addr_off;   
    reg  [31:0] rdata;  
    reg         valid;   
    reg  [31:0] saved_addr; 

    localparam IDLE = 2'b00; 
    localparam RD   = 2'b10; 
    localparam WR   = 2'b01; 
    reg [1:0] lsu_state, lsu_next_state;

    reg        aw_done;  
    reg        w_done;   
    reg        b_done;   
    reg        ar_done;

    wire we = (ex_lsu_valid & lsu_ex_ready & ex_lsu_MemWrite);
    wire req_valid = ((ex_lsu_valid & lsu_ex_ready) & (ex_lsu_MemRead | ex_lsu_MemWrite));

    always @(posedge clk) begin
        // if (rst) begin
        //     saved_word_offset <= 0;
        //     saved_wdata       <= 0;
        //     saved_wstrb       <= 0;
        // end
        if (lsu_state == IDLE & req_valid) begin
            addr_off <= addr[1:0];
            saved_addr <= addr; 
            saved_word_offset <= word_offset;
            // saved_wdata       <= align_write_data(ex_lsu_MemLen, addr[1:0], data_in);
            saved_wdata       <= (ex_lsu_MemLen[3:0] == 4'b0001) ? ({24'b0, data_in[7:0]} << (addr[1:0] * 8)) :
                                 (ex_lsu_MemLen[3:0] == 4'b0011) ? (addr[1:0] == 2'b00 ? {16'b0, data_in[15:0]} :
                                                                    addr[1:0] == 2'b10 ? {data_in[15:0], 16'b0} :
                                                                    data_in) : data_in;
            // saved_wdata       <= data_in << addr[1:0]*8;
            saved_wstrb       <= ex_lsu_MemLen[3:0] << addr[1:0];
        end
    end

    always @(posedge clk) begin
        if (rst) begin
            lsu_state <= IDLE;
        end else begin
            lsu_state <= lsu_next_state;
        end
    end

    always @(*) begin
        case (lsu_state)
            IDLE: lsu_next_state = req_valid ? (we ? WR : RD) : IDLE;
            RD:   lsu_next_state = (axi_lsu_rvalid && lsu_axi_rready && axi_lsu_rlast) ? IDLE : RD;
            WR:   lsu_next_state = (aw_done && w_done && b_done) ? IDLE : WR;
            default: lsu_next_state = IDLE;
        endcase
    end
    
    always @(posedge clk) begin
        if(lsu_state == IDLE) begin
            aw_done <= 0;
            w_done  <= 0;
            b_done  <= 0;
            burst_cnt <= 0;
        end
        else begin
            if(axi_lsu_rvalid && lsu_axi_rready) begin
                burst_cnt <= burst_cnt + 1;
            end
            if (lsu_axi_awvalid && axi_lsu_awready) aw_done <= 1'b1;
            if (lsu_axi_wvalid && axi_lsu_wready && lsu_axi_wlast) w_done <= 1'b1;
            if (axi_lsu_bvalid && lsu_axi_bready) b_done <= 1'b1;
        end
    end

    reg [BLOCK_SIZE*8-1:0] block_data;
    reg [4:0]  l_MemLen;

    assign lsu_axi_arid    = AXI_ID;
    assign lsu_axi_araddr  = in_sdram ? {saved_addr[31:BLOCK_OFFSET_WIDTH], {BLOCK_OFFSET_WIDTH{1'b0}}} : saved_addr;
    assign lsu_axi_arburst = in_sdram ? AXI_BURST_INCR : AXI_BURST_FIXED;
    assign lsu_axi_arlen   = in_sdram ? BURST_LEN - 1 : 8'h0;
    // assign lsu_axi_arsize  = (ex_lsu_MemLen[3:0] == 4'b0001 ) ? AXI_SIZE_BYTE : 
    //                          (ex_lsu_MemLen[3:0] == 4'b0011 ) ? AXI_SIZE_HALF : 
    //                          AXI_SIZE_WORD;
    
    assign lsu_axi_awburst = AXI_BURST_FIXED;
    assign lsu_axi_awid    = AXI_ID;
    assign lsu_axi_awlen   = 8'h0;
    // assign lsu_axi_awsize  = (saved_wstrb == 4'b0001 || saved_wstrb == 4'b0010 || 
    //                           saved_wstrb == 4'b0100 || saved_wstrb == 4'b1000) ? AXI_SIZE_BYTE :
    //                          (saved_wstrb == 4'b0011 || saved_wstrb == 4'b1100) ? AXI_SIZE_HALF : 
    //                          AXI_SIZE_WORD;
    // assign lsu_axi_awsize  = (l_MemLen[3:0] == 4'b0001 ) ? AXI_SIZE_BYTE : 
    //                          (l_MemLen[3:0] == 4'b0011 ) ? AXI_SIZE_HALF : 
    //                          AXI_SIZE_WORD;
    assign lsu_axi_awaddr  = saved_addr;
    assign lsu_axi_wstrb   = saved_wstrb;
    assign lsu_axi_wdata   = saved_wdata;
    assign lsu_axi_bready  = 1'b1;

    always @(*) begin
        case(l_MemLen[3:0])
            4'b0001: lsu_axi_awsize = AXI_SIZE_BYTE;
            4'b0011: lsu_axi_awsize = AXI_SIZE_HALF;
            default: lsu_axi_awsize = AXI_SIZE_WORD; 
        endcase
        case(l_MemLen[3:0])
            4'b0001: lsu_axi_arsize = AXI_SIZE_BYTE;
            4'b0011: lsu_axi_arsize = AXI_SIZE_HALF;
            default: lsu_axi_arsize = AXI_SIZE_WORD; 
        endcase
    end

    always @(posedge clk) begin
        if (rst) begin
            lsu_axi_awvalid <= 1'b0;
            lsu_axi_wvalid  <= 1'b0;
            lsu_axi_arvalid <= 1'b0;
        end 
        if (lsu_state == RD) begin
            if (!ar_done && !lsu_axi_arvalid) begin
                // lsu_axi_araddr  <= in_sdram ?  {saved_addr[31:BLOCK_OFFSET_WIDTH], {BLOCK_OFFSET_WIDTH{1'b0}}} : saved_addr;
                lsu_axi_arvalid <= 1'b1;
            end else if (axi_lsu_arready) begin
                lsu_axi_arvalid <= 1'b0;  
                ar_done         <= 1'b1;
            end
            lsu_axi_rready <= 1'b1;
            if(axi_lsu_rvalid && in_sdram) begin
                block_data[burst_cnt*32 +: 32] = axi_lsu_rdata;
            end
        end 
        else begin
            lsu_axi_arvalid <= 1'b0; 
            ar_done         <= 1'b0;
        end

        if (lsu_state == WR) begin
            if (!lsu_axi_awvalid && !aw_done) begin
                // lsu_axi_awaddr  <= saved_addr;  
                lsu_axi_awvalid <= 1'b1;
            end else if (axi_lsu_awready) begin
                lsu_axi_awvalid <= 1'b0;  // 地址握手完成后清零
            end

            if (!lsu_axi_wvalid && !w_done) begin
                // lsu_axi_wdata  <= saved_wdata;  
                // lsu_axi_wstrb  <= saved_wstrb;  
                lsu_axi_wvalid <= 1'b1;
                lsu_axi_wlast  <= 1'b1; 
            end else if (axi_lsu_wready) begin
                lsu_axi_wvalid <= 1'b0;
                lsu_axi_wlast  <= 1'b0;
            end
        end
    end

    always @(posedge clk) begin
        if (rst) begin
            rdata  <= 32'h0;
            valid  <= 1'b0;
        end else begin  
            valid <= 1'b0;
            if (axi_lsu_rvalid && lsu_axi_rready && axi_lsu_rlast) begin
                rdata <= in_sdram ? block_data[saved_word_offset*32 +: 32] : axi_lsu_rdata;
                valid <= 1'b1;
            end
            if(aw_done && w_done && b_done) begin
                valid <= 1'b1;
            end
            // case (lsu_state)
            //     // IDLE: begin end
            //     RD: begin
            //         if (axi_lsu_rvalid && lsu_axi_rready && axi_lsu_rlast) begin
            //             rdata <= in_sdram ? block_data[saved_word_offset*32 +: 32] : axi_lsu_rdata;
            //             valid <= 1'b1;
            //         end
            //     end
            //     WR: begin
            //         if(aw_done && w_done && b_done) begin
            //             valid <= 1'b1;
            //         end
            //     end
            //     default: begin end
            // endcase
        end
    end

    reg        l_load;            
    reg        l_rd_en;           
    reg [3:0]  l_rd_addr;                  

    // 前递信号赋值
    assign lsu_ex_forward_rd        = l_rd_addr;
    assign lsu_ex_forward_RegWrite  = l_rd_en;
    assign lsu_ex_forward_MemRead   = l_load;

    // 寄存器更新逻辑
    always @(posedge clk) begin
        if (rst) begin
            l_load    <= 0;
            l_rd_en   <= 0;
            l_rd_addr <= 0;
            l_MemLen  <= 0;
        end 
        else if (req_valid) begin
            l_load    <= ex_lsu_MemRead;
            l_rd_en   <= ex_lsu_RegWrite;
            l_rd_addr <= ex_lsu_rd;
            l_MemLen  <= ex_lsu_MemLen;
        end 
        else if (lsu_wb_valid & wb_lsu_ready) begin
            l_load    <= 0;
            l_rd_en   <= ex_lsu_RegWrite;
            l_rd_addr <= ex_lsu_rd;
            l_MemLen  <= ex_lsu_MemLen;
        end 
        else if (ex_lsu_valid & lsu_ex_ready & ~(ex_lsu_MemRead | ex_lsu_MemWrite)) begin // 非访存指令
            l_load    <= 0;
            l_rd_en   <= ex_lsu_RegWrite;
            l_rd_addr <= ex_lsu_rd;
            l_MemLen  <= ex_lsu_MemLen;
        end 
    end

    wire [31:0] byte_data1 = (rdata >> (addr_off*8));
    wire [ 7:0] byte_data = byte_data1[7:0];
    wire [15:0] half_data = (addr_off == 2'b10) ? (rdata[31:16]) : rdata[15:0];
    wire [31:0] read_lsu_data = (l_MemLen == `Mem_Bit  ) ? {{24{byte_data[7]}}, byte_data} :
                                (l_MemLen == `Mem_UBit ) ? {24'b0, byte_data} :
                                (l_MemLen == `Mem_Half ) ? {{16{half_data[15]}}, half_data} :
                                (l_MemLen == `Mem_UHalf) ? {16'b0, half_data} :
                                rdata;
                                
    // 写回数据选择
    reg [31:0] rd_data;
    always @(*) begin
        if (l_load) begin
            rd_data = read_lsu_data;
        end 
        else if (ex_lsu_forward_las) begin
            rd_data = data_in;
        end 
        else if (ex_lsu_MemWrite) begin
            rd_data = 32'h0;
        end 
        else if (ex_lsu_csr & !ex_lsu_csr_ecall & !ex_lsu_csr_mret) begin
            rd_data = ex_lsu_csr_rdata;
        end 
        else begin
            rd_data = ex_lsu_process_result;
        end
    end

    // 流水线握手逻辑
    always @(posedge clk) begin
        if (rst) begin
            lsu_ex_ready <= 1;
        end 
        else if (req_valid) begin
            lsu_ex_ready <= 0;
        end 
        else if (lsu_wb_valid & wb_lsu_ready) begin
            lsu_ex_ready <= 1;
        end 
    end

    always @(posedge clk) begin
        if (rst) begin
            lsu_wb_valid <= 0;
        end 
        else if (ex_lsu_valid & lsu_ex_ready) begin
            lsu_wb_valid <= ~(ex_lsu_MemRead | ex_lsu_MemWrite);
        end 
        else if (valid) begin
            lsu_wb_valid <= 1;
        end 
        // else if (req_valid) begin
        //     lsu_wb_valid <= 0;
        // end 
        else if ((~(ex_lsu_valid && lsu_ex_ready)) && lsu_wb_valid) begin
            lsu_wb_valid <= 0;
        end
    end

    // 输出到 WB 阶段
    always @(posedge clk) begin
        // if (rst) begin
        //     lsu_wb_RegWrite      <= 0;
        //     lsu_wb_rd            <= 0;
        //     lsu_wb_write_rd_data <= 0;
        //     lsu_wb_csr_wen1      <= 0;
        //     lsu_wb_csr_wen2      <= 0;
        //     lsu_wb_csr_wr_addr1  <= 0;
        //     lsu_wb_csr_wr_addr2  <= 0;
        //     lsu_wb_csr_wr_data1  <= 0;
        //     lsu_wb_csr_wr_data2  <= 0;
        // end else 
        if (valid) begin
            lsu_wb_RegWrite      <= l_rd_en;
            lsu_wb_rd            <= l_rd_addr;
            lsu_wb_csr_wen1      <= ex_lsu_csr_wen1;
            lsu_wb_csr_ecall     <= ex_lsu_csr_ecall;
            lsu_wb_csr_wr_addr1  <= ex_lsu_csr_wr_addr1;
            // lsu_wb_csr_wr_addr2  <= ex_lsu_csr_wr_addr2;
            lsu_wb_csr_wr_data1  <= ex_lsu_csr_wr_data1;
            lsu_wb_csr_wr_data2  <= ex_lsu_csr_wr_data2;
            lsu_wb_write_rd_data <= rd_data;
        end else if (ex_lsu_valid & lsu_ex_ready & ~(ex_lsu_MemRead | ex_lsu_MemWrite)) begin
            lsu_wb_RegWrite      <= ex_lsu_RegWrite; // 非内存访问指令
            lsu_wb_rd            <= ex_lsu_rd;
            lsu_wb_csr_wen1      <= ex_lsu_csr_wen1;
            lsu_wb_csr_ecall     <= ex_lsu_csr_ecall;
            lsu_wb_csr_wr_addr1  <= ex_lsu_csr_wr_addr1;
            // lsu_wb_csr_wr_addr2  <= ex_lsu_csr_wr_addr2;
            lsu_wb_csr_wr_data1  <= ex_lsu_csr_wr_data1;
            lsu_wb_csr_wr_data2  <= ex_lsu_csr_wr_data2;
            lsu_wb_write_rd_data <= rd_data;
        end
    end


endmodule

// Included from ./pipeline-soc-vsrc/ysyx_25010030.v

module ysyx_25010030 (
    input         clock,
    input         reset,
    input         io_interrupt,
// `ifdef __ICARUS__
//     output reg   sim_end,
// `endif

    //====== AXI Master ======//
    input         io_master_awready,
    output        io_master_awvalid,
    output [31:0] io_master_awaddr,
    output [ 3:0] io_master_awid,
    output [ 7:0] io_master_awlen,
    output [ 2:0] io_master_awsize,
    output [ 1:0] io_master_awburst,

    input         io_master_wready,
    output        io_master_wvalid,
    output [31:0] io_master_wdata,
    output [ 3:0] io_master_wstrb,
    output        io_master_wlast,

    output        io_master_bready,
    input         io_master_bvalid,
    input  [ 1:0] io_master_bresp,
    input  [ 3:0] io_master_bid,

    input         io_master_arready,
    output        io_master_arvalid,
    output [31:0] io_master_araddr,
    output [ 3:0] io_master_arid,
    output [ 7:0] io_master_arlen,
    output [ 2:0] io_master_arsize,
    output [ 1:0] io_master_arburst,

    output        io_master_rready,
    input         io_master_rvalid,
    input  [ 1:0] io_master_rresp,
    input  [31:0] io_master_rdata,
    input         io_master_rlast,
    input  [3:0]  io_master_rid,

    //====== AXI Slave ======//
    output        io_slave_awready,
    input         io_slave_awvalid,
    input  [31:0] io_slave_awaddr,
    input  [ 3:0] io_slave_awid,
    input  [ 7:0] io_slave_awlen,
    input  [ 2:0] io_slave_awsize,
    input  [ 1:0] io_slave_awburst,

    output        io_slave_wready,
    input         io_slave_wvalid,
    input  [31:0] io_slave_wdata,
    input  [ 3:0] io_slave_wstrb,
    input         io_slave_wlast,

    input         io_slave_bready,
    output        io_slave_bvalid,
    output [ 1:0] io_slave_bresp,
    output [ 3:0] io_slave_bid,

    output        io_slave_arready,
    input         io_slave_arvalid,
    input  [31:0] io_slave_araddr,
    input  [ 3:0] io_slave_arid,
    input  [ 7:0] io_slave_arlen,
    input  [ 2:0] io_slave_arsize,
    input  [ 1:0] io_slave_arburst,

    input         io_slave_rready,
    output        io_slave_rvalid,
    output [ 1:0] io_slave_rresp,
    output [31:0] io_slave_rdata,
    output        io_slave_rlast,
    output [ 3:0] io_slave_rid
);

    assign io_slave_awready = 1'b0;
    assign io_slave_wready  = 1'b0;
    assign io_slave_bvalid  = 1'b0;
    assign io_slave_bresp   = 2'b0;
    assign io_slave_bid     = 4'b0;
    assign io_slave_arready = 1'b0;
    assign io_slave_rvalid  = 1'b0;
    assign io_slave_rresp   = 2'b0;
    assign io_slave_rdata   = 32'b0;
    assign io_slave_rlast   = 1'b0;
    assign io_slave_rid     = 4'b0;

`ifdef VERILATOR
    // import "DPI-C" function void ebreak(input int station, input int inst);
    // import "DPI-C" function void occupancy(input int ifu_active_cycles, input int exu_active_cycles, input int lsu_active_cycles, input int total_cycles);
`endif
    // 顶层信号声明
    wire [31:0] IF_ID_pc;      
    wire [31:0] IF_ID_inst;       
    wire        IF_valid;         
    wire        id_ready;         

    wire [31:0] id_ex_pc;      
    // wire [31:0] id_ex_inst;    
    wire        id_valid;         
    wire        ex_ready;         
    wire        id_ex_RegWrite;
    wire [ 3:0] id_ex_rd;      
    wire [ 3:0] id_wb_rs1;      
    wire [ 3:0] id_wb_rs2;      
    wire [ 4:0] id_ex_zimm;      
    wire [31:0] id_ex_imm;        
    wire [ 5:0] id_ex_shamt;      
    wire [ 3:0] id_ex_alu_op;     
    wire [ 4:0] id_ex_MemLen;  
    wire        id_ex_MemWrite;
    wire        id_ex_MemRead; 
    wire [ 6:0] id_ex_opcode;     
    wire [ 2:0] id_ex_func3;      
    wire        id_ex_jal;        
    wire        id_ex_jalr;
    wire        id_ex_fencei;      
    // wire        id_ex_csr;      
    wire        id_ex_csr_wen1;  
    // wire        id_ex_csr_wen2; 
    wire        id_ex_csr_ecall;  
    wire        id_ex_csr_mret;  
    wire [ 1:0] id_ex_csr_op;
    wire [11:0] id_ex_csr_wr_addr1;
    // wire [11:0] id_ex_csr_wr_addr2;
    wire [11:0] id_wb_csr_addr1; 
    wire [11:0] id_wb_csr_addr2;  

    // wire [31:0] ex_lsu_pc;     
    // wire [31:0] ex_lsu_inst;  
    wire        sim_end;
    wire        ex_fencei; 
    wire        ex_lsu_valid;     
    wire        lsu_ex_ready;     
    wire [31:0] ex_lsu_src2;      
    wire        ex_lsu_RegWrite;  
    wire [ 3:0] ex_lsu_rd;        
    wire        ex_lsu_MemRead;   
    wire        ex_lsu_MemWrite;  
    wire [ 4:0] ex_lsu_MemLen;    
    wire [31:0] ex_lsu_process_result; 
    wire        ex_flush;        
    wire [31:0] ex_flush_pc;     
    wire        ex_lsu_csr;      
    wire        ex_lsu_csr_wen1; 
    // wire        ex_lsu_csr_wen2; 
    wire [11:0] ex_lsu_csr_wr_addr1;
    // wire [11:0] ex_lsu_csr_wr_addr2; 
    wire [31:0] ex_lsu_csr_wr_data1; 
    wire [31:0] ex_lsu_csr_wr_data2; 
    wire [31:0] ex_lsu_csr_rdata; 
    wire        ex_lsu_csr_ecall; 
    wire        ex_lsu_csr_mret;  

    wire        lsu_wb_valid;     
    wire        wb_lsu_ready;     
    wire        lsu_wb_RegWrite;  
    wire [ 3:0] lsu_wb_rd;        
    wire [31:0] lsu_wb_write_rd_data;  
    wire [31:0] lsu_wb_csr_wr_data1;   
    wire [31:0] lsu_wb_csr_wr_data2;   
    wire [11:0] lsu_wb_csr_wr_addr1;   
    // wire [11:0] lsu_wb_csr_wr_addr2;  
    wire        lsu_wb_csr_wen1;      
    wire        lsu_wb_csr_ecall;    
    // wire        wb_valid;         

    wire [31:0] wb_ex_src1;      
    wire [31:0] wb_ex_src2;      
    wire [31:0] wb_ex_csr_num1;   
    wire [31:0] wb_ex_csr_num2;   

    // 前递信号
    wire [ 3:0] lsu_ex_forward_rd;        
    wire        lsu_ex_forward_RegWrite;  
    wire        lsu_ex_forward_MemRead;   
    wire        ex_lsu_forward_las;       

    // LSU - ARB 的 AXI4-Lite 接口信号
    wire        lsu_axi_arvalid;
    wire        axi_lsu_arready;
    wire [31:0] lsu_axi_araddr;
    wire [ 3:0] lsu_axi_arid;
    wire [ 7:0] lsu_axi_arlen;
    wire [ 2:0] lsu_axi_arsize;
    wire [ 1:0] lsu_axi_arburst;
    wire [31:0] axi_lsu_rdata;
    wire        axi_lsu_rvalid;
    wire [ 3:0] axi_lsu_rid;
    wire        axi_lsu_rlast;
    wire        lsu_axi_rready;
    wire [ 1:0] axi_lsu_rresp;
    wire [31:0] lsu_axi_awaddr;
    wire [ 3:0] lsu_axi_awid;
    wire [ 7:0] lsu_axi_awlen;
    wire [ 2:0] lsu_axi_awsize;
    wire [ 1:0] lsu_axi_awburst;
    wire        lsu_axi_awvalid;
    wire        axi_lsu_awready;
    wire [31:0] lsu_axi_wdata;
    wire [ 3:0] lsu_axi_wstrb;
    wire        lsu_axi_wvalid;
    wire        lsu_axi_wlast;
    wire        axi_lsu_wready;
    wire [ 1:0] axi_lsu_bresp;
    wire [ 3:0] axi_lsu_bid;
    wire        axi_lsu_bvalid;
    wire        lsu_axi_bready;

    // IF - ARB 的 AXI4-Lite 接口信号
    wire        if_axi_arvalid;    
    wire        axi_if_arready;      
    wire [31:0] if_axi_araddr;      
    wire [ 3:0] if_axi_arid;
    wire [ 7:0] if_axi_arlen;
    wire [ 2:0] if_axi_arsize;
    wire [ 1:0] if_axi_arburst;
    wire [31:0] axi_if_rdata;        
    wire        axi_if_rvalid;      
    wire [ 3:0] axi_if_rid;
    wire        axi_if_rlast;
    wire        if_axi_rready;      
    wire [ 1:0] axi_if_rresp;    

     //====== CLINT =======//
    //AR channel
    wire [31:0] clint_araddr;
    wire        clint_arvalid;
    // wire [ 3:0] clint_arid;
    // wire [ 7:0] clint_arlen;
    // wire [ 2:0] clint_arsize;
    // wire [ 1:0] clint_arburst;
    wire        clint_arready;
    //R channel
    wire [ 1:0] clint_rresp;
    wire [31:0] clint_rdata;
    wire        clint_rvalid;
    // wire [ 3:0] clint_rid;
    wire        clint_rlast;
    wire        clint_rready;
    //AW channel
    // wire [31:0] clint_awaddr;
    // wire        clint_awvalid;
    // wire [ 3:0] clint_awid;
    // wire [ 7:0] clint_awlen;
    // wire [ 2:0] clint_awsize;
    // wire [ 1:0] clint_awburst;
    // wire        clint_awready;
    //W channel
    // wire [31:0] clint_wdata;
    // wire [ 3:0] clint_wstrb;
    // wire        clint_wvalid;
    // wire        clint_wlast;
    // wire        clint_wready;
    //B channel
    // wire [ 1:0] clint_bresp;
    // wire [ 3:0] clint_bid;
    // wire        clint_bvalid;
    // wire        clint_bready;

    // wire [31:0] ifu_active_cycles;
    // wire [31:0] exu_active_cycles;
    // wire [31:0] lsu_active_cycles;
    wire [31:0] next_pc;
    wire [31:0] cache_inst;
    wire        cache_valid;
    wire [31:0] cache_araddr;
    wire        cache_arvalid;
    wire [ 3:0] cache_arid;
    wire [ 7:0] cache_arlen;
    wire [ 2:0] cache_arsize;
    wire [ 1:0] cache_arburst;
    wire        cache_rready;

    ysyx_25010030_CLINT clint (
        .clk    (clock        ),
        .reset  (reset        ),
        .arvalid(clint_arvalid),
        .araddr (clint_araddr ),
        .arready(clint_arready),
        .rready (clint_rready ),
        .rvalid (clint_rvalid ),
        .rlast  (clint_rlast  ),
        .rresp  (clint_rresp  ),
        .rdata  (clint_rdata  )
    );


    ysyx_25010030_AXI_ARB axi_arb (
        .clk              (clock            ),
        .reset            (reset            ),

        // IFU master 接口（读通道）
        .ifu_arready      (axi_if_arready   ),
        .ifu_arvalid      (if_axi_arvalid   ),
        .ifu_araddr       (if_axi_araddr    ),
        .ifu_arid         (if_axi_arid      ),
        .ifu_arlen        (if_axi_arlen     ),
        .ifu_arsize       (if_axi_arsize    ),
        .ifu_arburst      (if_axi_arburst   ),
        .ifu_rready       (if_axi_rready    ),
        .ifu_rvalid       (axi_if_rvalid    ),
        .ifu_rresp        (axi_if_rresp     ),
        .ifu_rdata        (axi_if_rdata     ),
        .ifu_rlast        (axi_if_rlast     ),
        .ifu_rid          (axi_if_rid       ),

        // LSU master 接口（写通道）
        .lsu_awready      (axi_lsu_awready  ),
        .lsu_awvalid      (lsu_axi_awvalid  ),
        .lsu_awaddr       (lsu_axi_awaddr   ),
        .lsu_awid         (lsu_axi_awid     ),
        .lsu_awlen        (lsu_axi_awlen    ),
        .lsu_awsize       (lsu_axi_awsize   ),
        .lsu_awburst      (lsu_axi_awburst  ),
        .lsu_wready       (axi_lsu_wready   ),
        .lsu_wvalid       (lsu_axi_wvalid   ),
        .lsu_wdata        (lsu_axi_wdata    ),
        .lsu_wstrb        (lsu_axi_wstrb    ),
        .lsu_wlast        (lsu_axi_wlast    ),
        .lsu_bready       (lsu_axi_bready   ),
        .lsu_bvalid       (axi_lsu_bvalid   ),
        .lsu_bresp        (axi_lsu_bresp    ),
        .lsu_bid          (axi_lsu_bid      ),

        // LSU master 接口（读通道）
        .lsu_arready      (axi_lsu_arready  ),
        .lsu_arvalid      (lsu_axi_arvalid  ),
        .lsu_araddr       (lsu_axi_araddr   ),
        .lsu_arid         (lsu_axi_arid     ),
        .lsu_arlen        (lsu_axi_arlen    ),
        .lsu_arsize       (lsu_axi_arsize   ),
        .lsu_arburst      (lsu_axi_arburst  ),
        .lsu_rready       (lsu_axi_rready   ),
        .lsu_rvalid       (axi_lsu_rvalid   ),
        .lsu_rresp        (axi_lsu_rresp    ),
        .lsu_rdata        (axi_lsu_rdata    ),
        .lsu_rlast        (axi_lsu_rlast    ),
        .lsu_rid          (axi_lsu_rid      ),

        // IO master 接口（写通道）
        .io_master_awready(io_master_awready),
        .io_master_awvalid(io_master_awvalid),
        .io_master_awaddr (io_master_awaddr ),
        .io_master_awid   (io_master_awid   ),
        .io_master_awlen  (io_master_awlen  ),
        .io_master_awsize (io_master_awsize ),
        .io_master_awburst(io_master_awburst),
        .io_master_wready (io_master_wready ),
        .io_master_wvalid (io_master_wvalid ),
        .io_master_wdata  (io_master_wdata  ),
        .io_master_wstrb  (io_master_wstrb  ),
        .io_master_wlast  (io_master_wlast  ),
        .io_master_bready (io_master_bready ),
        .io_master_bvalid (io_master_bvalid ),
        .io_master_bresp  (io_master_bresp  ),
        .io_master_bid    (io_master_bid    ),

        // IO master 接口（读通道）
        .io_master_arready(io_master_arready),
        .io_master_arvalid(io_master_arvalid),
        .io_master_araddr (io_master_araddr ),
        .io_master_arid   (io_master_arid   ),
        .io_master_arlen  (io_master_arlen  ),
        .io_master_arsize (io_master_arsize ),
        .io_master_arburst(io_master_arburst),
        .io_master_rready (io_master_rready ),
        .io_master_rvalid (io_master_rvalid ),
        .io_master_rresp  (io_master_rresp  ),
        .io_master_rdata  (io_master_rdata  ),
        .io_master_rlast  (io_master_rlast  ),
        .io_master_rid    (io_master_rid    ),

        // CLINT从设备接口（读通道）
        .clint_araddr     (clint_araddr     ),
        .clint_arvalid    (clint_arvalid    ),
        .clint_arready    (clint_arready    ),
        // .clint_arid       (clint_arid       ),
        // .clint_arlen      (clint_arlen      ),
        // .clint_arsize     (clint_arsize     ),
        // .clint_arburst    (clint_arburst    ),
        .clint_rready     (clint_rready     ),
        .clint_rvalid     (clint_rvalid     ),
        .clint_rresp      (clint_rresp      ),
        .clint_rdata      (clint_rdata      ),
        .clint_rlast      (clint_rlast      )
        // .clint_rid        (clint_rid        )

        // CLINT从设备接口（写通道，始终无效）
        // .clint_awaddr(clint_awaddr),
        // .clint_awvalid(clint_awvalid),
        // .clint_awready(clint_awready),
        // .clint_awid(clint_awid),
        // .clint_awlen(clint_awlen),
        // .clint_awsize(clint_awsize),
        // .clint_awburst(clint_awburst),
        // .clint_wdata(clint_wdata),
        // .clint_wstrb(clint_wstrb),
        // .clint_wvalid(clint_wvalid),
        // .clint_wlast(clint_wlast),
        // .clint_wready(clint_wready),
        // .clint_bready(clint_bready),
        // .clint_bvalid(clint_bvalid),
        // .clint_bresp(clint_bresp),
        // .clint_bid(clint_bid)
    );

    ysyx_25010030_iCache u_icache (
        .clk            (clock         ),
        .reset          (reset         ),
        .is_fencei      (ex_fencei     ),
        .addr           (next_pc       ),
        .inst           (cache_inst    ),
        .valid          (cache_valid   ),
        .axi_araddr     (cache_araddr  ),
        .axi_arvalid    (cache_arvalid ),
        .axi_arready    (axi_if_arready),
        .axi_arid       (cache_arid    ),  
        .axi_arlen      (cache_arlen   ),  
        .axi_arsize     (cache_arsize  ),  
        .axi_arburst    (cache_arburst ),  
        .axi_rvalid     (axi_if_rvalid ),
        .axi_rready     (cache_rready  ),
        .axi_rdata      (axi_if_rdata  ),
        .axi_rresp      (axi_if_rresp  ),
        .axi_rid        (axi_if_rid    ),  
        .axi_rlast      (axi_if_rlast  )   
    );

    // IF（指令获取）模块
    ysyx_25010030_IF_AXI ifu (
        .clk           (clock         ),
        .reset         (reset         ),
        .EX_flush      (ex_flush      ),
        .EX_flush_pc   (ex_flush_pc   ),
        // .ex_fencei     (ex_fencei     ),
        .ID_ready      (id_ready      ),
        .IF_valid      (IF_valid      ),
        .IF_ID_pc      (IF_ID_pc      ),
        .IF_ID_inst    (IF_ID_inst    ),
        .if_axi_arvalid(if_axi_arvalid),
        // .axi_if_arready(axi_if_arready),
        .if_axi_araddr (if_axi_araddr ),
        .if_axi_arid   (if_axi_arid   ),
        .if_axi_arlen  (if_axi_arlen  ),
        .if_axi_arsize (if_axi_arsize ),
        .if_axi_arburst(if_axi_arburst),
        // .axi_if_rdata  (axi_if_rdata  ),
        // .axi_if_rvalid (axi_if_rvalid ),
        .if_axi_rready (if_axi_rready ),
        // .axi_if_rresp  (axi_if_rresp  ),
        // .axi_if_rid    (axi_if_rid    ),
        // .axi_if_rlast  (axi_if_rlast  )
        .next_pc       (next_pc       ),
        .cache_inst    (cache_inst    ),
        .cache_valid   (cache_valid   ),
        .cache_araddr  (cache_araddr  ),
        .cache_arvalid (cache_arvalid ),
        .cache_arid    (cache_arid    ),
        .cache_arlen   (cache_arlen   ),
        .cache_arsize  (cache_arsize  ),
        .cache_arburst (cache_arburst ),
        .cache_rready  (cache_rready  )
    );

    // ID（指令解码）模块
    ysyx_25010030_ID idu (
        .clk               (clock             ),
        .reset             (reset             ),
        .if_id_pc          (IF_ID_pc          ),
        .if_id_inst        (IF_ID_inst        ),
        .ex_flush          (ex_flush          ),
        .if_valid          (IF_valid          ),
        .id_ready          (id_ready          ),
        .ex_ready          (ex_ready          ),
        .id_valid          (id_valid          ),
        .id_ex_pc          (id_ex_pc          ),
        .sim_end           (sim_end          ),
        // .id_ex_inst(id_ex_inst),
        .id_ex_RegWrite    (id_ex_RegWrite    ),
        .id_ex_rd          (id_ex_rd          ),
        .id_wb_rs1         (id_wb_rs1         ),
        .id_wb_rs2         (id_wb_rs2         ),
        .id_ex_zimm        (id_ex_zimm        ),
        .id_ex_imm         (id_ex_imm         ),
        .id_ex_shamt       (id_ex_shamt       ),
        .id_ex_alu_op      (id_ex_alu_op      ),
        .id_ex_MemLen      (id_ex_MemLen      ),
        .id_ex_MemWrite    (id_ex_MemWrite    ),
        .id_ex_MemRead     (id_ex_MemRead     ),
        .id_ex_opcode      (id_ex_opcode      ),
        .id_ex_func3       (id_ex_func3       ),
        .id_ex_jal         (id_ex_jal         ),
        .id_ex_jalr        (id_ex_jalr        ),
        .id_ex_fencei      (id_ex_fencei      ),
        // .id_ex_csr(id_ex_csr),
        .id_ex_csr_wen1    (id_ex_csr_wen1    ),
        // .id_ex_csr_wen2(id_ex_csr_wen2),
        .id_ex_csr_ecall   (id_ex_csr_ecall   ),
        .id_ex_csr_mret    (id_ex_csr_mret    ),
        .id_ex_csr_op      (id_ex_csr_op      ),
        .id_ex_csr_wr_addr1(id_ex_csr_wr_addr1),
        // .id_ex_csr_wr_addr2(id_ex_csr_wr_addr2),
        .id_wb_csr_addr1   (id_wb_csr_addr1   ),
        .id_wb_csr_addr2   (id_wb_csr_addr2   )
    );

    // EX（执行）模块
    ysyx_25010030_EX exu (
        .clk                    (clock                  ),
        .reset                  (reset                  ),
        // .id_ready               (id_ready               ),
        .id_valid               (id_valid               ),
        .ex_ready               (ex_ready               ),
        .lsu_ready              (lsu_ex_ready           ),
        .ex_lsu_valid           (ex_lsu_valid           ),
        .id_wb_rs1              (id_wb_rs1              ),
        .id_wb_rs2              (id_wb_rs2              ),
        .lsu_ex_forward_rd      (lsu_ex_forward_rd      ),
        .lsu_ex_forward_RegWrite(lsu_ex_forward_RegWrite),
        .lsu_ex_forward_MemRead (lsu_ex_forward_MemRead ),
        .lsu_wb_wdata           (lsu_wb_write_rd_data   ),
        .lsu_wb_rd              (lsu_wb_rd              ),
        .lsu_wb_RegWrite        (lsu_wb_RegWrite        ),
        .lsu_wb_valid           (lsu_wb_valid           ),
        .ex_lsu_forward_las     (ex_lsu_forward_las     ),
        // .id_ex_inst(id_ex_inst),
        .id_ex_pc               (id_ex_pc               ),
        .id_ex_imm              (id_ex_imm              ),
        .id_ex_zimm             (id_ex_zimm             ),
        .id_ex_shamt            (id_ex_shamt            ),
        .wb_ex_src1             (wb_ex_src1             ),
        .wb_ex_src2             (wb_ex_src2             ),
        .id_ex_RegWrite         (id_ex_RegWrite         ),
        .id_ex_rd               (id_ex_rd               ),
        .id_ex_opcode           (id_ex_opcode           ),
        .id_ex_func3            (id_ex_func3            ),
        .id_ex_alu_op           (id_ex_alu_op           ),
        .id_ex_jal              (id_ex_jal              ),
        .id_ex_jalr             (id_ex_jalr             ),
        .id_ex_fencei           (id_ex_fencei           ),
        .ex_fencei              (ex_fencei              ),
        .id_ex_MemRead          (id_ex_MemRead          ),
        .id_ex_MemWrite         (id_ex_MemWrite         ),
        .id_ex_MemLen           (id_ex_MemLen           ),
        .wb_ex_csr_num1         (wb_ex_csr_num1         ),
        .wb_ex_csr_num2         (wb_ex_csr_num2         ),
        // .id_ex_csr(id_ex_csr),
        .id_ex_csr_wen1         (id_ex_csr_wen1         ),
        // .id_ex_csr_wen2(id_ex_csr_wen2),
        .id_ex_csr_wr_addr1     (id_ex_csr_wr_addr1     ),
        // .id_ex_csr_wr_addr2(id_ex_csr_wr_addr2),
        .id_ex_csr_ecall        (id_ex_csr_ecall        ),
        .id_ex_csr_mret         (id_ex_csr_mret         ),
        .id_ex_csr_op           (id_ex_csr_op           ),
        .ex_flush               (ex_flush               ),
        .ex_flush_pc            (ex_flush_pc            ),
        // .ex_lsu_inst(ex_lsu_inst),
        // .ex_lsu_pc(ex_lsu_pc),
        .ex_lsu_src2            (ex_lsu_src2            ),
        .ex_lsu_RegWrite        (ex_lsu_RegWrite        ),
        .ex_lsu_rd              (ex_lsu_rd              ),
        .ex_lsu_MemRead         (ex_lsu_MemRead         ),
        .ex_lsu_MemWrite        (ex_lsu_MemWrite        ),
        .ex_lsu_MemLen          (ex_lsu_MemLen          ),
        .ex_lsu_csr             (ex_lsu_csr             ),
        .ex_lsu_csr_wen1        (ex_lsu_csr_wen1        ),
        // .ex_lsu_csr_wen2(ex_lsu_csr_wen2),
        .ex_lsu_csr_wr_addr1    (ex_lsu_csr_wr_addr1    ),
        // .ex_lsu_csr_wr_addr2(ex_lsu_csr_wr_addr2),
        .ex_lsu_csr_wr_data1    (ex_lsu_csr_wr_data1    ),
        .ex_lsu_csr_wr_data2    (ex_lsu_csr_wr_data2    ),
        .ex_lsu_csr_rdata       (ex_lsu_csr_rdata       ),
        .ex_lsu_csr_ecall       (ex_lsu_csr_ecall       ),
        .ex_lsu_csr_mret        (ex_lsu_csr_mret        ),
        // .exu_active_cycles(exu_active_cycles),
        .ex_lsu_process_result  (ex_lsu_process_result  )
    );

    // MEM（内存访问）模块
    ysyx_25010030_LSU_AXI lsu (
        .clk                    (clock                  ),
        .rst                    (reset                  ),
        .ex_lsu_valid           (ex_lsu_valid           ),
        .lsu_ex_ready           (lsu_ex_ready           ),
        .wb_lsu_ready           (wb_lsu_ready           ),
        .lsu_wb_valid           (lsu_wb_valid           ),
        .ex_lsu_forward_las     (ex_lsu_forward_las     ),
        .ex_lsu_RegWrite        (ex_lsu_RegWrite        ),
        .ex_lsu_rd              (ex_lsu_rd              ),
        .ex_lsu_MemRead         (ex_lsu_MemRead         ),
        .ex_lsu_MemWrite        (ex_lsu_MemWrite        ),
        .ex_lsu_MemLen          (ex_lsu_MemLen          ),
        .addr                   (ex_lsu_process_result  ), // 从 EX 传入的内存地址
        .data_in                (ex_lsu_src2            ), // 从 EX 传入的写数据
        .lsu_ex_forward_rd      (lsu_ex_forward_rd      ),
        .lsu_ex_forward_RegWrite(lsu_ex_forward_RegWrite),
        .lsu_ex_forward_MemRead (lsu_ex_forward_MemRead ),
        .ex_lsu_csr             (ex_lsu_csr             ),
        .ex_lsu_csr_wen1        (ex_lsu_csr_wen1        ),
        // .ex_lsu_csr_wen2(ex_lsu_csr_wen2),
        .ex_lsu_csr_wr_data1    (ex_lsu_csr_wr_data1    ),
        .ex_lsu_csr_wr_data2    (ex_lsu_csr_wr_data2    ),
        .ex_lsu_csr_wr_addr1    (ex_lsu_csr_wr_addr1    ),
        // .ex_lsu_csr_wr_addr2(ex_lsu_csr_wr_addr2),
        .ex_lsu_csr_rdata       (ex_lsu_csr_rdata       ),
        .ex_lsu_csr_ecall       (ex_lsu_csr_ecall       ),
        .ex_lsu_csr_mret        (ex_lsu_csr_mret        ),
        .ex_lsu_process_result  (ex_lsu_process_result  ),
        .lsu_wb_csr_wr_data1    (lsu_wb_csr_wr_data1    ),
        .lsu_wb_csr_wr_data2    (lsu_wb_csr_wr_data2    ),
        .lsu_wb_csr_wr_addr1    (lsu_wb_csr_wr_addr1    ),
        // .lsu_wb_csr_wr_addr2(lsu_wb_csr_wr_addr2),
        .lsu_wb_csr_wen1        (lsu_wb_csr_wen1        ),
        .lsu_wb_csr_ecall       (lsu_wb_csr_ecall       ),
        .lsu_wb_RegWrite        (lsu_wb_RegWrite        ),
        .lsu_wb_rd              (lsu_wb_rd              ),
        .lsu_axi_arvalid        (lsu_axi_arvalid        ),
        .axi_lsu_arready        (axi_lsu_arready        ),
        .lsu_axi_araddr         (lsu_axi_araddr         ),
        .lsu_axi_arid           (lsu_axi_arid           ),
        .lsu_axi_arlen          (lsu_axi_arlen          ),
        .lsu_axi_arsize         (lsu_axi_arsize         ),
        .lsu_axi_arburst        (lsu_axi_arburst        ),
        .axi_lsu_rdata          (axi_lsu_rdata          ),
        .axi_lsu_rvalid         (axi_lsu_rvalid         ),
        .lsu_axi_rready         (lsu_axi_rready         ),
        .axi_lsu_rresp          (axi_lsu_rresp          ),
        .axi_lsu_rid            (axi_lsu_rid            ),
        .axi_lsu_rlast          (axi_lsu_rlast          ),
        .lsu_axi_awaddr         (lsu_axi_awaddr         ),
        .lsu_axi_awvalid        (lsu_axi_awvalid        ),
        .axi_lsu_awready        (axi_lsu_awready        ),
        .lsu_axi_awid           (lsu_axi_awid           ),
        .lsu_axi_awlen          (lsu_axi_awlen          ),
        .lsu_axi_awsize         (lsu_axi_awsize         ),
        .lsu_axi_awburst        (lsu_axi_awburst        ),
        .lsu_axi_wdata          (lsu_axi_wdata          ),
        .lsu_axi_wstrb          (lsu_axi_wstrb          ),
        .lsu_axi_wvalid         (lsu_axi_wvalid         ),
        .lsu_axi_wlast          (lsu_axi_wlast          ),
        .axi_lsu_wready         (axi_lsu_wready         ),
        .axi_lsu_bresp          (axi_lsu_bresp          ),
        .axi_lsu_bvalid         (axi_lsu_bvalid         ),
        .lsu_axi_bready         (lsu_axi_bready         ),
        .axi_lsu_bid            (axi_lsu_bid            ),
        // .lsu_active_cycles(lsu_active_cycles),
        .lsu_wb_write_rd_data   (lsu_wb_write_rd_data   )
    );

    // WBU（写回）模块
    ysyx_25010030_WB wbu (
        .clk         (clock               ),
        .rst         (reset               ),
        .wen         (lsu_wb_RegWrite     ),
        .lsu_wb_valid(lsu_wb_valid        ),
        .wb_lsu_ready(wb_lsu_ready        ),
        .wdata       (lsu_wb_write_rd_data),
        .waddr       (lsu_wb_rd           ),
        .rs1         (id_wb_rs1           ),
        .rs2         (id_wb_rs2           ),
        .src1        (wb_ex_src1          ),
        .src2        (wb_ex_src2          ),
        .raddr_csr1  (id_wb_csr_addr1     ),
        .raddr_csr2  (id_wb_csr_addr2     ),
        .wen_csr1    (lsu_wb_csr_wen1     ),
        .is_ecall    (lsu_wb_csr_ecall    ),
        .wdata_csr1  (lsu_wb_csr_wr_data1 ),
        .wdata_csr2  (lsu_wb_csr_wr_data2 ),
        .waddr_csr1  (lsu_wb_csr_wr_addr1 ),
        // .waddr_csr2(lsu_wb_csr_wr_addr2),
        .rdata_csr1  (wb_ex_csr_num1      ),
        .rdata_csr2  (wb_ex_csr_num2      )
    );

    // reg [31:0] inst_cnt;
    // reg [31:0] cycle_cnt;

    // always @(posedge clock) begin
    //     if(reset) begin
    //         inst_cnt <= 0;
    //         cycle_cnt <= 0;
    //     end
    //     else begin
    //         cycle_cnt <= cycle_cnt + 1;
    //         if(wb_valid) begin
    //             inst_cnt <= inst_cnt + 1;
    //         end
    //     end
    // end
    // EBREAK 处理
// `ifdef VERILATOR
//     always @(posedge clock) begin
//         if (IF_ID_inst == 32'h00100073) begin
//             // occupancy(ifu_active_cycles, exu_active_cycles, lsu_active_cycles, cycle_cnt);
//             ebreak(`HIT_TRAP, IF_ID_inst);
//         end
//     end
// `endif

// `ifdef __ICARUS__
    // reg sim_end;
    // always @(posedge clock) begin
    //     if (reset) begin
    //         sim_end <= 1'b0;
    //     end
    //     if (IF_ID_inst == 32'h00100073) begin
    //         sim_end <= 1;
    //     end
    // end
// `endif
endmodule

// Included from ./pipeline-soc-vsrc/ysyx_25010030_WB.v

module ysyx_25010030_WB #(
  parameter ADDR_WIDTH = 4,
  parameter DATA_WIDTH = 32)(
  input 		  clk,
  input 		  rst,
  input			  wen,
  input           lsu_wb_valid,
  output          wb_lsu_ready,

  input  [DATA_WIDTH-1:0] wdata,
  input  [ADDR_WIDTH-1:0] waddr,
  input  [ADDR_WIDTH-1:0] rs1,      
  input  [ADDR_WIDTH-1:0] rs2,      
  output [DATA_WIDTH-1:0] src1,     
  output [DATA_WIDTH-1:0] src2,     


  input  [11:0]           raddr_csr1,   
  input  [11:0]           raddr_csr2,   
  input                   wen_csr1,     
//   input                   wen_csr2, 
  input                   is_ecall,    
  input  [31:0]           wdata_csr1,
  input  [31:0]           wdata_csr2,
  input  [11:0]           waddr_csr1,
//   input  [11:0]           waddr_csr2,
  output [31:0]           rdata_csr1,
  output [31:0]           rdata_csr2     
);
// reg [31:0] CSR[2**12-1:0];
// reg [31:0] mstatus;
reg [31:0] mtvec;
reg [31:0] mepc;
// reg [31:0] mcause;
wire [31:0] mcause = 32'hb;
wire [31:0] mstatus = 32'h1800;
// wire [31:0] mvendorid = 32'h79737978;
// wire [31:0] marchid = 32'h17d9f6e;

localparam MSTATUS = 12'h300;
localparam MTVEC   = 12'h305;
localparam MEPC    = 12'h341;
localparam MCAUSE  = 12'h342;
// localparam MVENDORID = 12'hf11;
// localparam MARCHID   = 12'hf12;

reg [DATA_WIDTH-1:0] regs [2**ADDR_WIDTH-1:0];

assign wb_lsu_ready = 1;

integer i;
always @(posedge clk) begin
    if(rst)begin
        for(i = 0; i < 16; i = i + 1)begin
            regs[i] <= 32'b0;
        end
    end
    else if (lsu_wb_valid & wen & (waddr != 4'b0)) begin
        regs[waddr] <= wdata;
    end
end

assign src1 = (rs1 == 4'b0) ? 32'b0 : regs[rs1];
assign src2 = (rs2 == 4'b0) ? 32'b0 : regs[rs2];

always @(posedge clk) begin
    if (rst) begin
        // mvendorid <= 32'h79737978;
        // marchid   <= 32'h17d9f6e;

        // mstatus <= 32'h1800;
        mtvec   <= 32'h0;
        mepc    <= 32'h0;
        // mcause  <= 32'h0;
    end
    else if (lsu_wb_valid) begin
        if (wen_csr1) begin
            case(waddr_csr1)
                // MSTATUS: mstatus <= wdata_csr1;
                MTVEC:   mtvec   <= wdata_csr1;
                MEPC:    mepc    <= wdata_csr1;
                // MCAUSE:  mcause  <= wdata_csr1;
                default: ;
            endcase
        end
        if (is_ecall) begin
            // case(waddr_csr2)
            //     MSTATUS: mstatus <= wdata_csr2;
            //     MTVEC:   mtvec   <= wdata_csr2;
            //     MEPC:    mepc    <= wdata_csr2;
            //     // MCAUSE:  mcause  <= wdata_csr2;
            //     default: ;
            // endcase
            mepc <= wdata_csr2;
        end
    end
end

// assign rdata_csr1 = (raddr_csr1 == MSTATUS) ? mstatus :
//                     // (raddr_csr1 == MVENDORID) ? mvendorid :
//                     // (raddr_csr1 == MARCHID)   ? marchid   :
//                     (raddr_csr1 == MTVEC)   ? mtvec   :
//                     (raddr_csr1 == MEPC)    ? mepc    :
//                     (raddr_csr1 == MCAUSE)  ? mcause  : 32'h0;

// assign rdata_csr2 = (raddr_csr2 == MSTATUS) ? mstatus :
//                     // (raddr_csr1 == MVENDORID) ? mvendorid :
//                     // (raddr_csr1 == MARCHID)   ? marchid   :
//                     (raddr_csr2 == MTVEC)   ? mtvec   :
//                     (raddr_csr2 == MEPC)    ? mepc    :
//                     (raddr_csr2 == MCAUSE)  ? mcause  : 32'h0;
function [31:0] csr_read;
    input [11:0] addr;
    begin
    case (addr)
        MSTATUS: csr_read = mstatus;
        MTVEC:   csr_read = mtvec;
        MEPC:    csr_read = mepc;
        MCAUSE:  csr_read = mcause;
        default: csr_read = 32'h0;
    endcase
    end
endfunction

assign rdata_csr1 = csr_read(raddr_csr1);
assign rdata_csr2 = csr_read(raddr_csr2);

endmodule


