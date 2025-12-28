module ysyx_24070003(
    /*
    input clk,
    input rstn,
    //input [31:0] instr1,
    output [31:0] instr,
    //output reg[31:0] pc,
    output [31:0] dnpc,
    output [31:0] pc,
    output ebreak,
    output reg difftest_valid
    */
    `ifdef __ICARUS__
    output  wire        ebreak ,
    output  wire [31:0]  a0,
    `endif
    input   wire        clock,
    input   wire        reset,
    input   wire        io_interrupt,
    input   wire        io_master_awready,
    output  wire        io_master_awvalid, 
    output  wire [31:0] io_master_awaddr,  
    output  wire [3:0]  io_master_awid,   
    output  wire [7:0]  io_master_awlen, 
    output  wire [2:0]  io_master_awsize,
    output  wire [1:0]  io_master_awburst, 
    input   wire        io_master_wready,
    output  wire        io_master_wvalid,  
    output  wire [31:0]  io_master_wdata,   
    output  wire [3:0]    io_master_wstrb,   
    output  wire        io_master_wlast ,  
    output  wire        io_master_bready , 
    input   wire        io_master_bvalid  ,
    input   wire [1:0]     io_master_bresp   ,
    input   wire [3:0]     io_master_bid     ,
    input   wire        io_master_arready ,
    output  wire        io_master_arvalid,
    output  wire [31:0]   io_master_araddr  ,
    output  wire [3:0]    io_master_arid    ,
    output  wire [7:0]    io_master_arlen   ,
    output  wire [2:0]    io_master_arsize  ,
    output  wire [1:0]    io_master_arburst ,
    output  wire        io_master_rready  ,
    input   wire        io_master_rvalid  ,
    input   wire [1:0]     io_master_rresp   ,
    input   wire [31:0]    io_master_rdata   ,
    input   wire        io_master_rlast   ,
    input   wire [3:0]     io_master_rid   ,
    output  wire            io_slave_awready,
    input   wire           io_slave_awvalid,
    input   wire     [31:0] io_slave_awaddr ,
    input   wire     [3:0] io_slave_awid   ,
    input   wire     [7:0] io_slave_awlen ,
    input   wire     [2:0] io_slave_awsize ,
    input   wire     [1:0] io_slave_awburst,
    output  wire              io_slave_wready ,
    input   wire             io_slave_wvalid,
    input   wire    [31:0] io_slave_wdata,
    input   wire    [3:0] io_slave_wstrb,
    input   wire     io_slave_wlast  ,
    input   wire     io_slave_bready ,
    output  wire     io_slave_bvalid ,
    output  wire        [1:0] io_slave_bresp ,
    output  wire    [3:0] io_slave_bid   ,
    output  wire     io_slave_arready,
    input   wire     io_slave_arvalid,
    input   wire    [31:0] io_slave_araddr,
    input   wire    [3:0] io_slave_arid,    
    input   wire    [7:0] io_slave_arlen,
    input   wire    [2:0] io_slave_arsize,
    input   wire    [1:0] io_slave_arburst,
    input   wire     io_slave_rready,
    output  wire     io_slave_rvalid,
    output  wire        [1:0] io_slave_rresp,   
    output  wire            [31:0] io_slave_rdata ,
    output  wire      io_slave_rlast ,
    output  wire        [3:0] io_slave_rid   
);

reg [63:0]                           lsu_count                      ;
reg [63:0]                           ifu_count                      ;
reg [63:0]                           calcu_type_count               ;
reg [63:0]                           Jump_type_count                ;
reg [63:0]                           BJump_type_count               ;
reg [63:0]                           LOAD_type_count                ;
reg [63:0]                           STORE_type_count               ;
reg [63:0]                           C_type_count                   ;
reg [63:0]                           lsu_during_count               ;
reg [63:0]                           ifu_during_count               ;
reg [63:0]                           lsu_load_count                 ;
reg [63:0]                           lsu_store_count                ;
reg [63:0]                           total_count                    ;
reg [63:0]                           ICACHE_hit_count               ;
reg [63:0]                           ICACHE_miss_count              ;
reg [63:0]                           total_access                   ;
reg [63:0]                           access_time                    ;
reg [63:0]                           miss_penalty                   ;

wire [31:0]                          instr                          ;
wire [31:0]                          IFU_IDU_PC                     ;
// wire [31:0]                          IFU_IDU_dnpc                   ;
wire [31:0]                          AXI4_MASTER_ARADDR             ;
wire [31:0]                          AXI4_MASTER_RDATA              ;
wire [31:0]                          AXI4_MASTER_AWADDR             ;
wire [31:0]                          AXI4_MASTER_WDATA              ;
wire [31:0]                          IFU_AXI4_rdata                 ;
wire [31:0]                          ICACHE_IFU_raddr               ;
wire [31:0]                          BTB_pre_DNPC                   ;
wire [31:0]                          ifu_current_pc                 ;
wire [31:0]                          imm                            ;
wire [31:0]                          rs1_data                       ;
wire [31:0]                          rs2_data                       ;   
wire [31:0]                          alu_out                        ;
wire [31:0]                          ICACHE_AXI4_rdata              ;
wire [31:0]                          ICACHE_AXI4_araddr             ;
//wire [31:0]                          AXI4_SRAM_ARADDR               ;
//wire [31:0]                          AXI4_SRAM_RDATA                ;
wire [31:0]                          IFU_AXI4_araddr                ;
wire [31:0]                          BTB_pred_pc                    ;
wire [31:0]                          ICACHE_IFU_pre_dnpc            ;
//wire [31:0]                          AXI4_SRAM_AWADDR               ;
//wire [31:0]                          AXI4_SRAM_WDATA                ;
//wire [31:0]                          AXI4_UART_ARADDR               ;
//wire [31:0]                          AXI4_UART_RDATA                ;
//wire [31:0]                          AXI4_UART_AWADDR               ;
//wire [31:0]                          AXI4_UART_WDATA                ;
//wire [31:0]                          AXI4_CLINT_ARADDR              ;
wire [31:0]                          AXI4_CLINT_RDATA               ;
//wire [31:0]                          AXI4_CLINT_AWADDR              ;
//wire [31:0]                          AXI4_CLINT_WDATA               ;  
wire [31:0]                          IDU_EXU_PC                     ;
wire [31:0]                          IDU_EXU_pre_dnpc               ;
wire [31:0]                          EXU_LSU_PC                     ;
wire [31:0]                          LSU_WBU_PC                     ;
wire [31:0]                          PC_DATA                        ;
wire [31:0]                          DNPC_DATA                      ;   
wire [31:0]                          EXU_LSU_dnpc                   ;
wire [31:0]                          LSU_WBU_dnpc                   ;
//wire [31:0]                          IDU_EXU_dnpc                   ;
wire [31:0]                          LSU_WBU_DATA                   ;
//wire [31:0]                          LSU_WBU_csr_data               ;
wire [31:0]                          LSU_WBU_csr_in                 ;
wire [31:0]                          WBU_CSR_DATA                   ;
wire [31:0]                          EXU_IFU_pc                     ;
wire [31:0]                          EXU_LSU_RS2DATA                ;
//wire [31:0]                          EXU_LSU_IMM                    ;
wire [31:0]                          LSU_forward_data               ;
wire [31:0]                          EXU_BTB_PC                     ;
wire [31:0]                          LSU_AXI4_RDATA                 ;
wire [31:0]                          LSU_AXI4_AWADDR                ;
wire [31:0]                          LSU_AXI4_WDATA                 ;
wire [31:0]                          LSU_AXI4_ARADDR                ;
wire [31:0]                          EXU_LSU_csr_data               ;
wire [31:0]                          EXU_LSU_csr_in                 ;
wire [31:0]                          wbu_data                       ;
reg  [31:0]                          TO_top_pc                      ;
reg  [31:0]                          TO_top_dnpc                    ;
reg  [31:0]                          csr_data                       ;
wire [31:0]                          LSU_RDATA                      ;

wire                                 u_alu_type                     ;
wire                                 mul_high                       ;
wire [1:0]                                alu_src1                       ;
wire [1:0]                                alu_src2                       ;
wire                                 U_type_1                       ;  
wire                                 J_type_1                       ;
wire                                 ebreak                         ;
reg                                  difftest_valid                 ;
wire                                 IFU_IDU_valid                  ;
wire                                 IDU_EXU_valid                  ;
wire                                 EXU_IDU_ready                  ;
wire                                 IDU_IFU_ready                  ;
//wire                                 WBU_IFU_ready                  ;
//wire                                 WBU_IFU_valid                  ;
wire                                 LSU_WBU_ready                  ;
wire                                 LSU_WBU_valid                  ;
wire                                 LSU_EXU_ready                  ;
wire                                 EXU_LSU_valid                  ;
wire                                 IFU_AXI4_arvalid               ;
// wire                                 IFU_AXI4_arready               ;
wire                                 IFU_AXI4_rvalid                ;
(* keep *)wire                                 IFU_AXI4_rready                ;
wire                                 ICACHE_IFU_stall               ;
wire                                 flush                          ;
wire                                 BTB_pred_valid                 ;
wire                                 ICACHE_AXI4_arvalid            ;
(* keep *)wire                                 ICACHE_AXI4_arready            ;
wire                                 ICACHE_AXI4_rvalid             ;
wire                                 ICACHE_AXI4_rready             ;
wire                                 LSU_IFU_stall                  ;
//wire                                 AXI4_SRAM_ARVALID              ;
//wire                                 AXI4_SRAM_ARREADY              ;
//wire                                 AXI4_SRAM_RVALID               ;
//wire                                 AXI4_SRAM_RREADY               ;
//wire                                 AXI4_SRAM_AWVALID              ;
//wire                                 AXI4_SRAM_AWREADY              ;
// wire                                 AXI4_SRAM_WVALID               ;
// wire                                 AXI4_SRAM_WREADY               ;
// wire                                 AXI4_SRAM_BVALID               ;
// wire                                 AXI4_SRAM_BREADY               ;
// wire                                 AXI4_UART_ARVALID              ;
// wire                                 AXI4_UART_ARREADY              ;
// wire                                 AXI4_UART_RVALID               ;
// wire                                 AXI4_UART_RREADY               ;
// wire                                 AXI4_UART_AWVALID              ;
// wire                                 AXI4_UART_AWREADY              ;
// wire                                 AXI4_UART_WVALID               ;
// wire                                 AXI4_UART_WREADY               ;
// wire                                 AXI4_UART_BVALID               ;
// wire                                 AXI4_UART_BREADY               ;   
// wire                                 AXI4_CLINT_ARVALID             ;
wire                                 AXI4_CLINT_ARREADY             ;
wire                                 AXI4_CLINT_RVALID              ;
wire                                 AXI4_CLINT_RREADY              ;
// wire                                 AXI4_CLINT_AWVALID             ;
// wire                                 AXI4_CLINT_AWREADY             ;
// wire                                 AXI4_CLINT_WVALID              ;
// wire                                 AXI4_CLINT_WREADY              ;     
// wire                                 AXI4_CLINT_BVALID              ;
// wire                                 AXI4_CLINT_BREADY              ;
wire                                 IDU_EXU_lw                     ;
wire                                 IDU_EXU_lh                     ;
wire                                 IDU_EXU_lb                     ;
wire                                 IDU_EXU_lbu                    ;
wire                                 IDU_EXU_lhu                    ;
wire                                 IDU_EXU_sw                     ;
wire                                 IDU_EXU_sb                     ;
wire                                 IDU_EXU_sh                     ;
wire                                 IDU_EXU_csw                    ;
wire                                 IDU_EXU_csc                    ;
wire                                 IDU_EXU_css                    ;   
wire                                 IDU_EXU_ecall                  ;
wire                                 IDU_EXU_mret                   ;
wire                                 IDU_EXU_jal                    ;
wire                                 IDU_EXU_jalr                   ;
wire                                 IDU_EXU_C_type                 ;
wire                                 IDU_EXU_B_type                 ;
wire                                 fence_i                        ;
wire                                 stall                          ;
wire                                 IDU_EXU_exu_raw_rs1            ;
wire                                 IDU_EXU_exu_raw_rs2            ;
wire                                 IDU_EXU_lsu_raw_rs1            ;
wire                                 IDU_EXU_lsu_raw_rs2            ;
wire                                 EXU_LSU_ren                    ;
wire                                 EXU_LSU_reg                    ;
wire                                 LSU_WBU_reg                    ;
wire                                 EXU_LSU_ebreak                 ;
wire                                 IDU_EXU_ebreak                 ;
wire                                 EXU_LSU_wen                    ;
wire                                 EXU_IDU_REG_WEN                ;
wire                                 LSU_IDU_REG_WEN                ;
wire                                 LSU_IDU_REN                    ;
wire                                 EXU_IDU_REN                    ;
wire                                 EXU_LSU_lw                     ;
wire                                 EXU_LSU_lh                     ;
wire                                 EXU_LSU_lb                     ;
wire                                 EXU_LSU_lbu                    ;
wire                                 EXU_LSU_lhu                    ;
wire                                 EXU_LSU_sw                     ;
wire                                 EXU_LSU_sb                     ;
wire                                 EXU_LSU_sh                     ;
wire                                 EXU_LSU_ecall                  ;
wire                                 EXU_LSU_mret                   ;
wire                                 EXU_LSU_C_type                 ;
//wire                                 EXU_IFU_JUMP                   ;
wire                                 EXU_BTB_updata_valid           ;
wire                                 LSU_WBU_ecall                  ;
wire                                 LSU_WBU_mret                   ;
wire                                 LSU_WBU_C_type                 ;
wire                                 LSU_AXI4_RVALID                ;
wire                                 LSU_AXI4_RREADY                ;
wire                                 LSU_AXI4_AWVALID               ;
wire                                 LSU_AXI4_AWREADY               ;
wire                                 LSU_AXI4_WVALID                ;
wire                                 LSU_AXI4_WREADY                ;
wire                                 LSU_AXI4_BVALID                ;
wire                                 LSU_AXI4_BREADY                ;
wire                                 LSU_AXI4_ARVALID               ;
wire                                 LSU_AXI4_ARREADY               ;
wire                                 LSU_RVALID                     ;
wire                                 LSU_AXI_wlast                  ;
wire                                 WBU_wen                        ;
wire                                 WBU_CSR_WEN                    ;
wire                                 WBU_ECALL                      ;
wire                                 WBU_TOP_skip                   ;
//wire                                 WBU_IDU_REG_wen                ;
wire                                 LSU_WBU_skip                   ;
wire                                 LSU_ARREADY                    ;
wire                                 branch                         ;
wire                                 mem_read                       ;
wire                                 mem_write                      ;   
wire                                 reg_write                      ;
wire                                 AXI4_MASTER_ARVALID            ;
wire                                 AXI4_MASTER_ARREADY            ;
wire                                 AXI4_MASTER_RVALID             ;
wire                                 AXI4_MASTER_RREADY             ;
wire                                 AXI4_MASTER_AWVALID            ;
wire                                 AXI4_MASTER_AWREADY            ;
wire                                 AXI4_MASTER_WVALID             ;
wire                                 AXI4_MASTER_WREADY             ;
wire                                 AXI4_MASTER_BVALID             ;            
wire                                 AXI4_MASTER_BREADY             ;
//reg                                  WBU_IFU_valid_cache            ;
reg                                  ref_skip                       ;

//wire [3:0]                           AXI4_SRAM_WSTRB                ;
//wire [3:0]                           AXI4_UART_WSTRB                ;
//wire [3:0]                           AXI4_CLINT_WSTRB               ;
wire [3:0]                           LSU_AXI4_WSTRB                 ;
wire [3:0]                           alu_op                         ;
wire [3:0]                           AXI4_MASTER_WSTRB              ;

wire [4:0]                           rd                             ;
wire [4:0]                           rs1                            ;
wire [4:0]                           rs2                            ;   
wire [4:0]                           EXU_LSU_rd                     ;
wire [4:0]                           LSU_WBU_rd                     ;
wire [4:0]                           EXU_IDU_REG_ADDR               ;
wire [4:0]                           LSU_IDU_REG_ADDR               ;
wire [4:0]                           wbu_addr                       ;
//wire [4:0]                           WBU_IDU_REG_ADDR               ;


//wire [2:0]                           funct3                         ;   
wire [2:0]                           LSU_AXI4_ARSIZE                ;
wire [2:0]                           AXI4_MASTER_ARSIZE             ;
wire [2:0]                           IDU_EXU_csr_rst                ;
wire [2:0]                           EXU_LSU_csr_rst                ;
wire [2:0]                           WBU_CSR_ADDR                   ;
wire [2:0]                           LSU_WBU_csr_rst                ;
wire [2:0]                           WBU_CSR_RADDR                  ;
wire [2:0]                           LSU_AXI4_wsize                 ;   

//wire [5:0]                           funct7                         ;
wire [1:0]                           resp                           ;
wire [7:0]                           ICACHE_AXI4_arlen              ;
wire [7:0]                           AXI4_MASTER_ARLEN              ;




assign io_master_awvalid        =       AXI4_MASTER_AWVALID;
assign io_master_awaddr         =       AXI4_MASTER_AWADDR;
assign io_master_rready         =       AXI4_MASTER_RREADY;
assign io_master_awid           =       'd0;//AXI4_MASTER_AWID;
assign io_master_awlen          =       8'd0;//AXI4_MASTER_AWLEN;
assign io_master_awsize         =       LSU_AXI4_wsize;//AXI4_MASTER_AWSIZE;
assign io_master_awburst        =       2'd01;//AXI4_MASTER_AWBURST;
assign io_master_wvalid         =       AXI4_MASTER_WVALID;
assign io_master_wdata          =       AXI4_MASTER_WDATA;
assign io_master_wstrb          =       AXI4_MASTER_WSTRB;
assign io_master_wlast          =       LSU_AXI_wlast;//AXI4_MASTER_WLAST;
assign io_master_bready         =       AXI4_MASTER_BREADY;
assign io_master_arvalid        =       AXI4_MASTER_ARVALID;
assign io_master_araddr         =       AXI4_MASTER_ARADDR;
assign io_master_arid           =       'd0;//AXI4_MASTER_ARID;
assign io_master_arlen          =       AXI4_MASTER_ARLEN;//AXI4_MASTER_ARLEN;
assign io_master_arsize         =       AXI4_MASTER_ARSIZE;//AXI4_MASTER_ARSIZE;
assign io_master_arburst        =       2'd01;//AXI4_MASTER_ARBURST;

assign AXI4_MASTER_AWREADY      =       io_master_awready;
assign AXI4_MASTER_WREADY       =       io_master_wready;
assign AXI4_MASTER_BVALID       =       io_master_bvalid;
assign AXI4_MASTER_RDATA        =       io_master_rdata;
assign AXI4_MASTER_ARREADY      =       io_master_arready;
assign AXI4_MASTER_RVALID       =       io_master_rvalid;


assign io_slave_awready         =       'd0;
assign io_slave_wready          =       'd0;
assign io_slave_bvalid          =       'd0;
assign io_slave_bresp           =       'd0;
assign io_slave_bid             =       'd0;
assign io_slave_arready         =       'd0;
assign io_slave_rvalid          =       'd0;
assign io_slave_rresp           =       'd0;
assign io_slave_rdata           =       'd0;
assign io_slave_rlast           =       'd0;
assign io_slave_rid             =       'd0;


assign resp = io_master_rresp | io_master_bresp;



ysyx_24070003_ifu my_ifu(
    //.WBU_IFU_JUMP                   (EXU_IFU_JUMP       ),
    .IFU_IDU_valid                  (IFU_IDU_valid      ), 
    .IDU_IFU_ready                  (IDU_IFU_ready      ),
    .resp                           (resp               ),
    .clock                            (clock              ),
    .rstn                           (reset              ),
    .fence_i                        (fence_i            ),
    .stall                          (stall  ||  LSU_IFU_stall           ),
   //.pcsrc                         (pcsrc              ),
    .EXU_IFU_pc                     (EXU_IFU_pc         ),
    .EXU_IFU_flush                  (flush              ),
    //.EXU_LSU_valid                  (EXU_LSU_valid      ),
    //.EXU_IFU_STALL_done           (EXU_IFU_STALL_done),
    //.imm                          (imm                ),
    //.rs1_data                     (rs1_data           ),
    //.alu_out                      (alu_out            ),
    //.zero                         (EXU_IFU_zero       ),
    //.jal                          (EXU_IFU_jal        ),
    //.jalr                         (EXU_IFU_jalr       ),
    //.ecall                        (LSU_WBU_ecall      ),
    //.mret                         (LSU_WBU_mret       ),
    //.csr_data                     (csr_data           ),
    //.stall                        (IFU_IDU_STALL      ),
   // .inst_addr_o                  (inst_addr_o        ),
    .IFU_IDU_PC                     (IFU_IDU_PC         ),
    .cur_pc                         (ifu_current_pc     ),
    .BTB_pred_pc                    (BTB_pred_pc        ),
    .BTB_pred_valid                 (BTB_pred_valid     ),
    .IFU_IDU_INSTR                  (instr              ),
    //.instr_in                     (instr_in           ),
    .BTB_pre_DNPC                   (BTB_pre_DNPC       ),

    .ifu_count                      (ifu_count          ),

    .IFU_AXI4_araddr                (IFU_AXI4_araddr    ),
    .IFU_AXI4_arvalid               (IFU_AXI4_arvalid   ),
    //.IFU_AXI4_arready               (IFU_AXI4_arready   ),
    .IFU_AXI4_rdata                 (IFU_AXI4_rdata     ),
    .ICACHE_IFU_rvalid              (IFU_AXI4_rvalid    ),
    .IFU_AXI4_rready                (IFU_AXI4_rready    ),
    .ICACHE_IFU_raddr               (ICACHE_IFU_raddr   ),
    .ICACHE_IFU_stall               (ICACHE_IFU_stall   )
    
);


ysyx_24070003_icache  my_icache(
    .clock                          (clock              ),
    .reset                          (reset              ),
    .fence_i                        (fence_i            ),
    .flush                          (flush              ),
    .IFU_AXI4_araddr                (IFU_AXI4_araddr    ),
    .IFU_AXI4_arvalid               (IFU_AXI4_arvalid   ),
   // .IFU_AXI4_rdata               (IFU_AXI4_rdata     ),
    //.IFU_AXI4_rvalid              (IFU_AXI4_rvalid    ),
    .IFU_AXI4_rready                (IFU_AXI4_rready    ),

    .BTB_pre_DNPC                   (BTB_pre_DNPC       ),
    .IDU_IFU_STALL                  (stall              ),
    .LSU_IFU_stall                  (LSU_IFU_stall      ),


    .ICACHE_IFU_rdata               (IFU_AXI4_rdata     ),
    .ICACHE_IFU_raddr               (ICACHE_IFU_raddr   ),
    .ICACHE_IFU_pre_dnpc            (ICACHE_IFU_pre_dnpc),
    .ICACHE_IFU_valid               (IFU_AXI4_rvalid    ),
    .ICACHE_IFU_stall               (ICACHE_IFU_stall   ),

    .ICACHE_AXI4_araddr             (ICACHE_AXI4_araddr ),
    .ICACHE_AXI4_arvalid            (ICACHE_AXI4_arvalid),
    .ICACHE_AXI4_arready            (ICACHE_AXI4_arready),
    .ICACHE_AXI4_rdata              (ICACHE_AXI4_rdata  ),
    .ICACHE_AXI4_rvalid             (ICACHE_AXI4_rvalid ),
    .ICACHE_AXI4_rready             (ICACHE_AXI4_rready ),
    .ICACHE_AXI4_rlast              (io_master_rlast    ),
    // .ICACHE_hit_count               (ICACHE_hit_count   ),
    // .ICACHE_miss_count              (ICACHE_miss_count  ),
    // .total_access                   (total_access       ),
    // .access_time                    (access_time        ),
    // .miss_penalty                   (miss_penalty       ),
    // .ifu_during_count               (ifu_during_count   ),
    .ICACHE_AXI4_arlen              (ICACHE_AXI4_arlen  )
);


ysyx_24070003_btb my_btb(
    .clock                          (clock              ),
    .reset                          (reset              ),
    .cur_pc                         (ifu_current_pc     ),
    .update_pc                      (IDU_EXU_PC         ),
    .target_pc                      (EXU_BTB_PC         ),
    .update_valid                   (EXU_BTB_updata_valid),

    .pred_pc                        (BTB_pred_pc        ),
    .pred_valid                     (BTB_pred_valid     )
);


ysyx_24070003_axi_arbiter my_axi_arbiter(
    .clock                            (clock              ),
    .rstn                           (reset              ),   
    
    // IFU 接口 (指令获取)
    .ifu_araddr                     (ICACHE_AXI4_araddr ),
    .ifu_arvalid                    (ICACHE_AXI4_arvalid),
    .ifu_arready                    (ICACHE_AXI4_arready),
    
    .ifu_rdata                      (ICACHE_AXI4_rdata  ),            
    .ifu_rvalid                     (ICACHE_AXI4_rvalid ),
    .ifu_rready                     (ICACHE_AXI4_rready ),
    
    // LSU 接口 (加载/存储)
    .lsu_araddr                     (LSU_AXI4_ARADDR    )   ,
    .lsu_arvalid                    (LSU_AXI4_ARVALID   ),
    .lsu_arready                    (LSU_AXI4_ARREADY   ),
    
    .lsu_rdata                      (LSU_AXI4_RDATA     ),
    .lsu_rvalid                     (LSU_AXI4_RVALID    ),
    .lsu_rready                     (LSU_AXI4_RREADY    ),
    
    .lsu_awaddr                     (LSU_AXI4_AWADDR    ),
    .lsu_awvalid                    (LSU_AXI4_AWVALID   ),
    .lsu_awready                    (LSU_AXI4_AWREADY   ),
    
    .lsu_wdata                      (LSU_AXI4_WDATA     ),
    .lsu_wstrb                      (LSU_AXI4_WSTRB     ),
    .lsu_wvalid                     (LSU_AXI4_WVALID    ),
    .lsu_wready                     (LSU_AXI4_WREADY    ),    
    
   // .lsu_bresp               (),
    .lsu_bvalid                     (LSU_AXI4_BVALID    ),
    .lsu_bready                     (LSU_AXI4_BREADY    ),
    .lsu_arsize                     (LSU_AXI4_ARSIZE    ),
    
    .master_araddr                  (AXI4_MASTER_ARADDR ),
    .master_arvalid                 (AXI4_MASTER_ARVALID),
    .master_arready                 (AXI4_MASTER_ARREADY),
    
    .master_rdata                   (AXI4_MASTER_RDATA  ),
    .master_rvalid                  (AXI4_MASTER_RVALID ),
    .master_rready                  (AXI4_MASTER_RREADY ),
    
    .master_awaddr                  (AXI4_MASTER_AWADDR ),
    .master_awvalid                 (AXI4_MASTER_AWVALID),
    .master_awready                 (AXI4_MASTER_AWREADY),
    
    .master_wdata                   (AXI4_MASTER_WDATA  ),
    .master_wstrb                   (AXI4_MASTER_WSTRB  ),
    .master_wvalid                  (AXI4_MASTER_WVALID ),       
    .master_wready                  (AXI4_MASTER_WREADY ),
    
    //.sram_bresp                   (),
    .master_bvalid                  (AXI4_MASTER_BVALID ),
    .master_bready                  (AXI4_MASTER_BREADY ),
    .ICACHE_AXI4_arlen              (ICACHE_AXI4_arlen  ),
    .master_arlen                   (AXI4_MASTER_ARLEN  ),
    .master_rlast                   (io_master_rlast    ),
    .master_arsize                  (AXI4_MASTER_ARSIZE )
);


ysyx_24070003_clint my_clint(
    .clock                            (clock              )  ,
    .rstn                           (reset              ),    


    // AXI-Lite4 Read Address Channel
    .AXI4_CLINT_ARADDR              (LSU_AXI4_ARADDR    ),
    .AXI4_CLINT_ARREADY             (AXI4_CLINT_ARREADY ),
    
    // AXI-Lite4 Read Data Channel
    .AXI4_CLINT_RDATA               (AXI4_CLINT_RDATA   ),
    .AXI4_CLINT_RVALID              (AXI4_CLINT_RVALID  )
);


wire [8:0] IDU_EXU_RW_sign,EXU_LSU_RW_sign;
wire [2:0]                           csr_op                         ;
ysyx_24070003_idu my_idu(
   // .EXU_IFU_flush                (EXU_IFU_flush      ),
    .clock                            (clock              ),
    .IFU_IDU_PC                     (IFU_IDU_PC         ),
    .rst_n                          (reset              ),
    .flush                          (flush              ),
    .fence_i                        (fence_i            ),
    .IFU_IDU_pre_dnpc               (ICACHE_IFU_pre_dnpc),
   // .IFU_IDU_STALL                (IFU_IDU_STALL      ),
    .IFU_IDU_valid                  (IFU_IDU_valid      ),
    .IDU_IFU_ready                  (IDU_IFU_ready      ),
    .EXU_IDU_ready                  (EXU_IDU_ready      ), 
    .IDU_EXU_valid                  (IDU_EXU_valid      ),
    .INSTR                          (instr              ),
   // .IDU_EXU_opcode               (opcode             ),
    .IDU_EXU_rd                     (rd                 ),
    .IDU_EXU_rs1                    (rs1                ),
    .IDU_EXU_rs2                    (rs2                ),
    .IDU_EXU_csr_rst                (IDU_EXU_csr_rst    ),
    .IDU_EXU_imm                    (imm                ),
    .IDU_EXU_alu_op                 (alu_op             ),
    .IDU_EXU_u_alu_type             (u_alu_type         ),
    //.IDU_EXU_mul_high               (mul_high           ),
    .IDU_EXU_alu_src1               (alu_src1           ),
    .IDU_EXU_alu_src2               (alu_src2           ),
    .IDU_EXU_branch                 (branch             ),
   // .IDU_EXU_mem_to_reg           (mem_to_reg         ),
    .IDU_EXU_mem_read               (mem_read           ),
    //.IDU_EXU_mem_write              (mem_write          ),    
    .IDU_EXU_reg_write              (reg_write          ),
    .IDU_EXU_jal                    (IDU_EXU_jal        ),
    .IDU_EXU_jalr                   (IDU_EXU_jalr       ),
    // .IDU_EXU_lw                     (IDU_EXU_lw         ),
    // .IDU_EXU_lh                     (IDU_EXU_lh         ),  
    // .IDU_EXU_lb                     (IDU_EXU_lb         ),
    // .IDU_EXU_lbu                    (IDU_EXU_lbu        ),
    // .IDU_EXU_lhu                    (IDU_EXU_lhu        ),
    // .IDU_EXU_sw                     (IDU_EXU_sw         ),
    // .IDU_EXU_sb                     (IDU_EXU_sb         ),
    // .IDU_EXU_sh                     (IDU_EXU_sh         ),
    .IDU_EXU_RW_sign                (IDU_EXU_RW_sign),
    .IDU_EXU_csr_op                 (csr_op             ),
    .IDU_EXU_ebreak                 (IDU_EXU_ebreak     ),
    .IDU_EXU_ecall                  (IDU_EXU_ecall      ),
    .IDU_EXU_mret                   (IDU_EXU_mret       ),
    //.IDU_EXU_U_type_1               (U_type_1           ),
    //.IDU_EXU_J_type_1               (J_type_1           ),
   // .IDU_EXU_pcsrc                (pcsrc              ),
    .IDU_EXU_C_type                 (IDU_EXU_C_type     ),
    .IDU_EXU_B_type                 (IDU_EXU_B_type     ),
    //.IDU_EXU_STALL                (IDU_EXU_STALL      ),
    .IDU_EXU_PC                     (IDU_EXU_PC         ),
    .IDU_EXU_pre_dnpc               (IDU_EXU_pre_dnpc   ),

    .IDU_EXU_exu_raw_rs1            (IDU_EXU_exu_raw_rs1),
    .IDU_EXU_exu_raw_rs2            (IDU_EXU_exu_raw_rs2),
    .IDU_EXU_lsu_raw_rs1            (IDU_EXU_lsu_raw_rs1),
    .IDU_EXU_lsu_raw_rs2            (IDU_EXU_lsu_raw_rs2),

    // .calcu_type_count               (calcu_type_count   ),
    // .Jump_type_count                (Jump_type_count    ),
    // .BJump_type_count               (BJump_type_count   ),
    // .LOAD_type_count                (LOAD_type_count    ),
    // .STORE_type_count               (STORE_type_count   ),
    // .C_type_count                   (C_type_count       ),


    .exu_reg_write_en               (EXU_IDU_REG_WEN    ),
    .exu_rd_addr                    (EXU_IDU_REG_ADDR   ),
    .exu_ren                        (EXU_IDU_REN        ),

    // 来自级()
    .lsu_reg_write_en               (LSU_IDU_REG_WEN    ),          
    .lsu_rd_addr                    (LSU_IDU_REG_ADDR   ),
    //.lsu_ren                        (LSU_IDU_REN        ),


    .stall                          (stall              )
);  



ysyx_24070003_exu my_exu(
    .IDU_EXU_rd                     (rd                 ),
    .clock                            (clock              ),
    .rstn                           (reset              ),
    .IDU_EXU_exu_raw_rs1            (IDU_EXU_exu_raw_rs1),
    .IDU_EXU_exu_raw_rs2            (IDU_EXU_exu_raw_rs2),
    .IDU_EXU_lsu_raw_rs1            (IDU_EXU_lsu_raw_rs1),
    .IDU_EXU_lsu_raw_rs2            (IDU_EXU_lsu_raw_rs2),
    .LSU_forward_data               (LSU_forward_data   ),
    .IDU_EXU_pre_dnpc               (IDU_EXU_pre_dnpc   ),
    //.IDU_EXU_STALL                (IDU_EXU_STALL      ),
    .IDU_EXU_ebreak                 (IDU_EXU_ebreak     ),
    .IDU_EXU_csr_rst                (IDU_EXU_csr_rst    ),
    .IDU_EXU_ren                    (mem_read           ),
    //.IDU_EXU_wen                    (mem_write          ),
    .IDU_EXU_reg                    (reg_write          ),
    .IDU_EXU_jal                    (IDU_EXU_jal        ),
    .IDU_EXU_jalr                   (IDU_EXU_jalr       ),
    .IDU_EXU_RW_sign                 (IDU_EXU_RW_sign),
    // .IDU_EXU_lw                     (IDU_EXU_lw         ),
    // .IDU_EXU_lh                     (IDU_EXU_lh         ),
    // .IDU_EXU_lb                     (IDU_EXU_lb         ),
    // .IDU_EXU_lbu                    (IDU_EXU_lbu        ),
    // .IDU_EXU_lhu                    (IDU_EXU_lhu        ),
    // .IDU_EXU_sw                     (IDU_EXU_sw         ),
    // .IDU_EXU_sb                     (IDU_EXU_sb         ),
    // .IDU_EXU_sh                     (IDU_EXU_sh         ),
    .csr_op                         (csr_op             ),
    .csr_data                       (csr_data           ),
    .IDU_EXU_ecall                  (IDU_EXU_ecall      ),
    .IDU_EXU_mret                   (IDU_EXU_mret       ),
    .IDU_EXU_C_type                 (IDU_EXU_C_type     ),
    .IDU_EXU_B_type                 (IDU_EXU_B_type     ),
    .EXU_IDU_ready                  (EXU_IDU_ready      ),
    .IDU_EXU_valid                  (IDU_EXU_valid      ),
    .LSU_EXU_ready                  (LSU_EXU_ready      ),
    .EXU_LSU_valid                  (EXU_LSU_valid      ),
    .rs1_data                       (rs1_data           ),
    .rs2_data                       (rs2_data           ),
    .imm_data                       (imm                ),
    .pc_data                        (IDU_EXU_PC         ),
    .alu_src1                       (alu_src1           ),
    .alu_src2                       (alu_src2           ),
    .branch                         (branch             ),   
    //.J_type_1                       (J_type_1           ),
    .u_alu_type                     (u_alu_type         ),
    //.mul_high                       (mul_high           ),
    //.U_type_1                       (U_type_1           ),
    
    .EXU_LSU_alu_out                (alu_out            ),
    //.EXU_IFU_zero                 (EXU_IFU_zero       ),
    .alu_op                         (alu_op             ),
    .EXU_LSU_rd                     (EXU_LSU_rd         ),   
    .EXU_LSU_ren                    (EXU_LSU_ren        ),
    //.EXU_LSU_wen                    (EXU_LSU_wen        ),
    .EXU_LSU_reg                    (EXU_LSU_reg        ),
    .EXU_LSU_ebreak                 (EXU_LSU_ebreak     ),
    //.EXU_IFU_jal                  (EXU_IFU_jal        ),
    //.EXU_IFU_jalr                 (EXU_IFU_jalr       ),
    // .EXU_LSU_lw                     (EXU_LSU_lw         ),
    // .EXU_LSU_lh                     (EXU_LSU_lh         ),
    // .EXU_LSU_lb                     (EXU_LSU_lb         ),
    // .EXU_LSU_lbu                    (EXU_LSU_lbu        ),
    // .EXU_LSU_lhu                    (EXU_LSU_lhu        ),
    // .EXU_LSU_sw                     (EXU_LSU_sw         ),
    // .EXU_LSU_sb                     (EXU_LSU_sb         ),
    // .EXU_LSU_sh                     (EXU_LSU_sh         ),
    .EXU_LSU_RW_sign                (EXU_LSU_RW_sign),
    .EXU_LSU_csr_data               (EXU_LSU_csr_data   ),
    .EXU_LSU_ecall                  (EXU_LSU_ecall      ),
    .EXU_LSU_mret                   (EXU_LSU_mret       ),
    .EXU_LSU_csr_rst                (EXU_LSU_csr_rst    ),
    .EXU_LSU_C_type                 (EXU_LSU_C_type     ),
    .EXU_LSU_csr_in                 (EXU_LSU_csr_in     ),
    .EXU_IFU_pc                     (EXU_IFU_pc         ),
    //.EXU_IFU_STALL_done           (EXU_IFU_STALL_done ),
    .EXU_flush                      (flush              ),
    .EXU_LSU_RS2DATA                (EXU_LSU_RS2DATA    ),
    .EXU_LSU_PC                     (EXU_LSU_PC         ),
    .EXU_LSU_dnpc                   (EXU_LSU_dnpc       ),
    //.EXU_LSU_IMM                    (EXU_LSU_IMM        ),

    .EXU_IDU_REG_ADDR               (EXU_IDU_REG_ADDR   )     ,
    .EXU_IDU_REG_WEN                (EXU_IDU_REG_WEN    ),
    .EXU_IDU_REN                    (EXU_IDU_REN        ),
    .EXU_BTB_PC                     (EXU_BTB_PC         ),
    .EXU_BTB_updata_valid           (EXU_BTB_updata_valid)
);

assign LSU_RDATA = (LSU_AXI4_ARADDR >= 32'h02000000 && LSU_AXI4_ARADDR <= 32'h02000004) ? AXI4_CLINT_RDATA : LSU_AXI4_RDATA;
assign LSU_RVALID = (LSU_AXI4_ARADDR >= 32'h02000000 && LSU_AXI4_ARADDR <= 32'h02000004) ? AXI4_CLINT_RVALID : LSU_AXI4_RVALID;
assign LSU_ARREADY = (LSU_AXI4_ARADDR >= 32'h02000000 && LSU_AXI4_ARADDR <= 32'h02000004) ? AXI4_CLINT_ARREADY : LSU_AXI4_ARREADY;
ysyx_24070003_lsu my_lsu(
    //.EXU_IFU_pc                   (EXU_IFU_pc         ),
    //.LSU_WBU_pc                   (LSU_WBU_pc         ),
    //.EXU_LSU_JUMP                 (EXU_IFU_JUMP       )  ,
    //.LSU_WBU_JUMP                 (LSU_WBU_JUMP       ),
    .EXU_LSU_dnpc                   (EXU_LSU_dnpc       ),
    .EXU_LSU_PC                     (EXU_LSU_PC         ),
    .EXU_LSU_RW_sign                (EXU_LSU_RW_sign),
    // .EXU_LSU_lw                     (EXU_LSU_lw         ),
    // .EXU_LSU_lh                     (EXU_LSU_lh         ),
    // .EXU_LSU_lb                     (EXU_LSU_lb         ),
    // .EXU_LSU_lbu                    (EXU_LSU_lbu        ),
    // .EXU_LSU_lhu                    (EXU_LSU_lhu        ),
    // .EXU_LSU_sw                     (EXU_LSU_sw         ),
    // .EXU_LSU_sb                     (EXU_LSU_sb         ),
    // .EXU_LSU_sh                     (EXU_LSU_sh         ),
    .EXU_LSU_csr_data               (EXU_LSU_csr_data   ),
    .EXU_LSU_csr_in                 (EXU_LSU_csr_in     ),
    .EXU_LSU_ecall                  (EXU_LSU_ecall      ),
    .EXU_LSU_mret                   (EXU_LSU_mret       ),
    .EXU_LSU_C_type                 (EXU_LSU_C_type     ),
    .EXU_LSU_csr_rst                (EXU_LSU_csr_rst    ),
    .EXU_LSU_ren                    (EXU_LSU_ren        ),
    //.EXU_LSU_wen                    (EXU_LSU_wen        ),
    //.IDU_EXU_ren                  (mem_read           ),
    //.IDU_EXU_wen                  (mem_write          ),
    .EXU_LSU_reg                    (EXU_LSU_reg        ),
    .EXU_LSU_ebreak                 (EXU_LSU_ebreak     ),
    .EXU_LSU_rd                     (EXU_LSU_rd         ),
    .EXU_LSU_result                 (alu_out            ),
    .LSU_EXU_ready                  (LSU_EXU_ready      ),
    .EXU_LSU_valid                  (EXU_LSU_valid      ),
    .LSU_WBU_valid                  (LSU_WBU_valid      ),
    .LSU_WBU_ready                  (LSU_WBU_ready      ),
    .clock                          (clock              ),
    .rst_n                          (reset              ),
    .LSU_WBU_PC                     (LSU_WBU_PC         ),
    //.alu_result                   (alu_out            ),
    .rs2_data                       (EXU_LSU_RS2DATA    ),
   // .rdata                        (rdata              ),
    //.LSU_WBU_csr_data               (LSU_WBU_csr_data   ),
    .LSU_WBU_ecall                  (LSU_WBU_ecall      ),
    .LSU_WBU_mret                   (LSU_WBU_mret       ),
    .LSU_WBU_C_type                 (LSU_WBU_C_type     ),
    .LSU_WBU_DATA                   (LSU_WBU_DATA       ),
    .LSU_WBU_reg                    (LSU_WBU_reg        ),
    .LSU_WBU_rd                     (LSU_WBU_rd         ),
    .LSU_WBU_ebreak                 (ebreak             ),
    .LSU_WBU_csr_rst                (LSU_WBU_csr_rst    ),
    .LSU_WBU_csr_in                 (LSU_WBU_csr_in     ),
    .LSU_WBU_dnpc                   (LSU_WBU_dnpc       ),
    .LSU_WBU_skip                   (LSU_WBU_skip       ),

    .LSU_IFU_stall                  (LSU_IFU_stall      ),
    //.LSU_WLEN                     (LSU_WLEN           ),
    //.LSU_WDATA                    (LSU_WDATA          ),
    //.LSU_RDATA                    (LSU_RDATA          )
    .LSU_AXI4_ARADDR                (LSU_AXI4_ARADDR    ),
    .LSU_AXI4_ARVALID               (LSU_AXI4_ARVALID   ),
    .LSU_AXI4_ARREADY               (LSU_ARREADY        ),
    .LSU_AXI4_RDATA                 (LSU_RDATA          ),
    .LSU_AXI4_RVALID                (LSU_RVALID         ),
    .LSU_AXI4_RREADY                (LSU_AXI4_RREADY    ),
    .LSU_AXI4_AWADDR                (LSU_AXI4_AWADDR    ),
    .LSU_AXI4_AWVALID               (LSU_AXI4_AWVALID   ),
    .LSU_AXI4_AWREADY               (LSU_AXI4_AWREADY   ),
    .LSU_AXI4_WDATA                 (LSU_AXI4_WDATA     ),
    .LSU_AXI4_WSTRB                 (LSU_AXI4_WSTRB     ),
    .LSU_AXI4_WVALID                (LSU_AXI4_WVALID    ),
    .LSU_AXI4_WREADY                (LSU_AXI4_WREADY    ),
    .LSU_AXI4_BVALID                (LSU_AXI4_BVALID    ),
    .LSU_AXI4_BREADY                (LSU_AXI4_BREADY    ),
    .LSU_AXI_wlast                  (LSU_AXI_wlast      ),
    .LSU_AXI4_wsize                 (LSU_AXI4_wsize     ),
    .LSU_AXI4_ARSIZE                (LSU_AXI4_ARSIZE    ),
    // .lsu_count                      (lsu_count          ),
    // .lsu_during_count               (lsu_during_count   ),
    // .lsu_load_count                 (lsu_load_count     ),
    // .lsu_store_count                (lsu_store_count    ),

    .LSU_forward_data               (LSU_forward_data   ),
    .LSU_IDU_REG_ADDR               (LSU_IDU_REG_ADDR   ),
    .LSU_IDU_REG_WEN                (LSU_IDU_REG_WEN    )
    //.LSU_IDU_REN                    (LSU_IDU_REN        )
);




ysyx_24070003_wbu my_wbu(
    .clock                            (clock              ),
    .LSU_WBU_dnpc                   (LSU_WBU_dnpc       ),
    .LSU_WBU_skip                   (LSU_WBU_skip       ),
    //.LSU_WBU_pc                   (LSU_WBU_pc         ),
    //.WBU_IFU_pc                   (WBU_IFU_pc         ),
    //.LSU_WBU_JUMP                 (LSU_WBU_JUMP       ),
    //.WBU_IFU_JUMP                 (WBU_IFU_JUMP       ),
    .LSU_WBU_PC                     (LSU_WBU_PC         ),
    .LSU_WBU_reg                    (LSU_WBU_reg        ),
    .LSU_WBU_result                 (LSU_WBU_DATA       ),
    //.LSU_WBU_csr_data               (LSU_WBU_csr_data   ),
    .LSU_WBU_csr_in                 (LSU_WBU_csr_in     ),
    .LSU_WBU_ecall                  (LSU_WBU_ecall      ),
    .LSU_WBU_mret                   (LSU_WBU_mret       ),
    .LSU_WBU_C_type                 (LSU_WBU_C_type     ),
   // .LSU_WBU_jal                  (LSU_WBU_jal        ),
    //.LSU_WBU_jalr                 (LSU_WBU_jalr       ),
    .LSU_WBU_csr_rst                (LSU_WBU_csr_rst    ),
    .rst_n                          (reset              ),
   // .wbu_en                       (                   ),
    .LSU_WBU_valid                  (LSU_WBU_valid      ),
    .LSU_WBU_ready                  (LSU_WBU_ready      ),
    //.data_in                      (rdata              ),
    .addr                           (LSU_WBU_rd         ),
    .WBU_REG_DATA                   (wbu_data           ),
    .WBU_REG_ADDR                   (wbu_addr           ),
    .WBU_wen                        (WBU_wen            ),
    .WBU_CSR_DATA                   (WBU_CSR_DATA       ),
    .WBU_CSR_ADDR                   (WBU_CSR_ADDR       ),
    .WBU_CSR_WEN                    (WBU_CSR_WEN        ),
    .WBU_ECALL                      (WBU_ECALL          ),
    .PC_DATA                        (PC_DATA            ),
    .DNPC_DATA                      (DNPC_DATA          ),
    .WBU_TOP_skip                   (WBU_TOP_skip       )
);
    
wire [31:0] a0;
ysyx_24070003_RegisterFile #(.ADDR_WIDTH(4), .DATA_WIDTH(32)) rf1(
        .clock                        (clock              ),
        .reset                        (reset              ),
    `ifdef __ICARUS__
        .a0                          (a0              ),
    `endif
        .wdata                      (wbu_data           ),
        .waddr                      (wbu_addr[3:0]      ),
        .wen                        (WBU_wen            ),
        .rdata1                     (rs1_data           ),
        .raddr1                     (rs1[3:0]           ),
        .rdata2                     (rs2_data           ),
        .raddr2                     (rs2[3:0]           )
    );
assign WBU_CSR_RADDR = (IDU_EXU_ecall) ? 'd3 : (IDU_EXU_mret) ? 'd0 :IDU_EXU_csr_rst;
ysyx_24070003_csr_reg #(.ADDR_WIDTH(3), .DATA_WIDTH(32)) csr1(
        .clock                        (clock              ),
        .wdata                      (WBU_CSR_DATA       ),
        .ecall                      (WBU_ECALL          ),
        .pc                         (PC_DATA            ),
        .waddr                      (WBU_CSR_ADDR       ),
        .wen                        (WBU_CSR_WEN        ),
        .rdata1                     (csr_data           ),
        .raddr1                     (WBU_CSR_RADDR      )
    );

///////////////////difftest/////////////////


always @(posedge clock ) begin
    if(reset) begin
        difftest_valid <= 1'b0;
        //WBU_IFU_valid_cache <= 1'b0;
        TO_top_pc <= 32'h00000000;
        TO_top_dnpc <= 32'h00000000;
        ref_skip <= 1'b0;
    end else begin
        //WBU_IFU_valid_cache <= (LSU_WBU_valid);
        difftest_valid <= LSU_WBU_valid;
        TO_top_pc <= PC_DATA;
        TO_top_dnpc <= DNPC_DATA;
        ref_skip <= WBU_TOP_skip;
    end
end

always @(posedge clock ) begin
    if(reset) begin
        total_count <= 0;
    end else begin
        total_count <= total_count + 1;
    end
end
// always @(posedge clock ) begin
//     if(EXU_LSU_ebreak) begin
//         $display("total_count               = %040d\n",total_count);
//         $display("total_instr               = %040d\n",calcu_type_count + Jump_type_count + LOAD_type_count + STORE_type_count + C_type_count);
//         $display("lsu_count                 = %040d\n",lsu_count);
//         $display("ifu_count                 = %040d\n",ifu_count);
//         $display("calcu_type_count          = %040d\n",calcu_type_count);
//         $display("Jump_type_count           = %040d\n",Jump_type_count);
//         $display("BJump_type_count          = %040d\n",BJump_type_count);
//         $display("LOAD_type_count           = %040d\n",LOAD_type_count);
//         $display("STORE_type_count          = %040d\n",STORE_type_count);
//         $display("C_type_count              = %040d\n",C_type_count);
//         $display("lsu_average_count         = %040d\n",lsu_during_count/lsu_count);
//         $display("ifu_average_count         = %040d\n",ifu_during_count/ifu_count);
//         $display("load_instr_average_count  = %040d\n",lsu_load_count/LOAD_type_count);
//         $display("store_instr_average_count = %040d\n",lsu_store_count/STORE_type_count);
//         $display("ICACHE hit_count          = %040d\n",ICACHE_hit_count);
//         $display("ICACHE miss_count         = %040d\n",ICACHE_miss_count);
//         $display("total_access              = %040d\n",total_access);
//         $display("access_time               = %040d\n",access_time);
//         $display("miss_penalty              = %040d\n",miss_penalty);
//     end
// end
// import "DPI-C" function void set_monitor_ptr(input logic [31:0] data []);
// reg [31:0] dpi_monitor_data[0:5];
// // 初始化时绑定指针
// initial set_monitor_ptr(dpi_monitor_data);
assign dpi_monitor_data[0] = {31'b0,difftest_valid};
assign dpi_monitor_data[1] = TO_top_pc;
assign dpi_monitor_data[2] = TO_top_dnpc;
assign dpi_monitor_data[3] = instr;
assign dpi_monitor_data[4] = {31'b0,ebreak};
assign dpi_monitor_data[5] = {31'b0,ref_skip};



/*
axi_xbar my_axi_xbar(
    //.clk                     (clk),
    //.rstn                    (rstn),    
    
    // 主设备接口 (从IFU和LSU来)
    .m_araddr                (AXI4_MASTER_ARADDR),
    .m_arvalid                (AXI4_MASTER_ARVALID),
    .m_arready               (AXI4_MASTER_ARREADY),
    
    .m_rdata                 (AXI4_MASTER_RDATA),
    .m_rvalid                (AXI4_MASTER_RVALID),
    .m_rready                (AXI4_MASTER_RREADY),
    
    .m_awaddr                (AXI4_MASTER_AWADDR),
    .m_awvalid               (AXI4_MASTER_AWVALID),
    .m_awready               (AXI4_MASTER_AWREADY),
    
    .m_wdata                 (AXI4_MASTER_WDATA),
    .m_wstrb                 (AXI4_MASTER_WSTRB),
    .m_wvalid                (AXI4_MASTER_WVALID),
    .m_wready                (AXI4_MASTER_WREADY),
    
    //.m_bresp                 (),
    .m_bvalid                (AXI4_MASTER_BVALID),
    .m_bready                (AXI4_MASTER_BREADY),
    
    // 从设备接口 (到UART、SRAM等设备去)
    .s_araddr                ({AXI4_SRAM_ARADDR,AXI4_UART_ARADDR,AXI4_CLINT_ARADDR}),
    .s_arvalid               ({AXI4_SRAM_ARVALID,AXI4_UART_ARVALID,AXI4_CLINT_ARVALID}),
    .s_arready               ({AXI4_SRAM_ARREADY,AXI4_UART_ARREADY,AXI4_CLINT_ARREADY}),
    
    .s_rdata                 ({AXI4_SRAM_RDATA,AXI4_UART_RDATA,AXI4_CLINT_RDATA}),
    .s_rvalid                ({AXI4_SRAM_RVALID,AXI4_UART_RVALID,AXI4_CLINT_RVALID}),
    .s_rready                ({AXI4_SRAM_RREADY,AXI4_UART_RREADY,AXI4_CLINT_RREADY}),
    
    .s_awaddr                ({AXI4_SRAM_AWADDR,AXI4_UART_AWADDR,AXI4_CLINT_AWADDR}),
    .s_awvalid               ({AXI4_SRAM_AWVALID,AXI4_UART_AWVALID,AXI4_CLINT_AWVALID}),
    .s_awready               ({AXI4_SRAM_AWREADY,AXI4_UART_AWREADY,AXI4_CLINT_AWREADY}),
    
    .s_wdata                 ({AXI4_SRAM_WDATA,AXI4_UART_WDATA,AXI4_CLINT_WDATA}),
    .s_wstrb                 ({AXI4_SRAM_WSTRB,AXI4_UART_WSTRB,AXI4_CLINT_WSTRB}),
    .s_wvalid                ({AXI4_SRAM_WVALID,AXI4_UART_WVALID,AXI4_CLINT_WVALID}),
    .s_wready                ({AXI4_SRAM_WREADY,AXI4_UART_WREADY,AXI4_CLINT_WREADY}),
    
    //.s_bresp,
    .s_bvalid                ({AXI4_SRAM_BVALID,AXI4_UART_BVALID,AXI4_CLINT_BVALID}),
    .s_bready                ({AXI4_SRAM_BREADY,AXI4_UART_BREADY,AXI4_CLINT_BREADY})
);  

sram my_sram(
    .CLK                          (clk),
    .rstn                               (rstn),

    // AXI-Lite4 Read Address Channel
    .AXI4_SRAM_ARADDR           (AXI4_SRAM_ARADDR),
    .AXI4_SRAM_ARVALID          (AXI4_SRAM_ARVALID),
    .AXI4_SRAM_ARREADY          (AXI4_SRAM_ARREADY),
    
    // AXI-Lite4 Read Data Channel
    .AXI4_SRAM_RDATA           (AXI4_SRAM_RDATA),
    .AXI4_SRAM_RVALID                   (AXI4_SRAM_RVALID),
    .AXI4_SRAM_RREADY           (AXI4_SRAM_RREADY),

    // AXI-Lite4 Write Address Channel
    .AXI4_SRAM_AWADDR              (AXI4_SRAM_AWADDR) ,
    .AXI4_SRAM_AWVALID             (AXI4_SRAM_AWVALID),
    .AXI4_SRAM_AWREADY              (AXI4_SRAM_AWREADY),
   
    // AXI-Lite4 Write Data Channel
    .AXI4_SRAM_WDATA            (AXI4_SRAM_WDATA),
    .AXI4_SRAM_WSTRB            (AXI4_SRAM_WSTRB),  
    .AXI4_SRAM_WVALID           (AXI4_SRAM_WVALID),
    .AXI4_SRAM_WREADY           (AXI4_SRAM_WREADY),
   
    // AXI-Lite4 Write Response Channel
    .AXI4_SRAM_BVALID           (AXI4_SRAM_BVALID),
    .AXI4_SRAM_BREADY                (AXI4_SRAM_BREADY)
    //output reg [1:0]       AXI4_SRAM_BRESP 
);

uart my_uart(
    .CLK                                 (clk),
    .rstn                               (rstn),


    // AXI-Lite4 Read Address Channel
    .AXI4_UART_ARADDR                       (AXI4_UART_ARADDR),
    .AXI4_UART_ARVALID                       (AXI4_UART_ARVALID),
    .AXI4_UART_ARREADY                       (AXI4_UART_ARREADY),   
    
    // AXI-Lite4 Read Data Channel
    .AXI4_UART_RDATA                       (AXI4_UART_RDATA),
    .AXI4_UART_RVALID                       (AXI4_UART_RVALID), 
    .AXI4_UART_RREADY                       (AXI4_UART_RREADY),

    // AXI-Lite4 Write Address Channel
    .AXI4_UART_AWADDR                       (AXI4_UART_AWADDR),
    .AXI4_UART_AWVALID                       (AXI4_UART_AWVALID),
    .AXI4_UART_AWREADY                       (AXI4_UART_AWREADY),
   
    // AXI-Lite4 Write Data Channel
    .AXI4_UART_WDATA                       (AXI4_UART_WDATA),
    .AXI4_UART_WSTRB                       (AXI4_UART_WSTRB),  
    .AXI4_UART_WVALID                       (AXI4_UART_WVALID),
    .AXI4_UART_WREADY                       (AXI4_UART_WREADY),
   
    // AXI-Lite4 Write Response Channel
    .AXI4_UART_BVALID                       (AXI4_UART_BVALID),
    .AXI4_UART_BREADY                       (AXI4_UART_BREADY)
    //output reg [1:0]       AXI4_UART_BRESP 
);
*/

 
/*
sram_inst inst_sram(
    .CLK(clk),
    .rstn(rstn),
    .IFU_AXI4_ARADDR(IFU_AXI4_araddr),
    .IFU_AXI4_ARVALID(IFU_AXI4_arvalid),
    .IFU_AXI4_ARREADY(IFU_AXI4_arready),
    .IFU_AXI4_RDATA(IFU_AXI4_rdata),
    .IFU_AXI4_RVALID(IFU_AXI4_rvalid),
    .IFU_AXI4_RREADY(IFU_AXI4_rready)
);

*/
/*
sram_data data_sram(
    .CLK(clk),
    .rstn(rstn),
    //.wen(EXU_LSU_wen),
    //.ren(EXU_LSU_ren),
    //.wlen(LSU_WLEN),
    //.addr(alu_out),
    //.data(LSU_WDATA),
    //.Q(LSU_RDATA)
    // AXI-Lite4 Read Address Channel
    .LSU_AXI4_ARADDR         (LSU_AXI4_ARADDR),
    .LSU_AXI4_ARVALID            (LSU_AXI4_ARVALID),
    .LSU_AXI4_ARREADY            (LSU_AXI4_ARREADY),
    
    // AXI-Lite4 Read Data Channel
    .LSU_AXI4_RDATA            (LSU_AXI4_RDATA),
    .LSU_AXI4_RVALID            (LSU_AXI4_RVALID),
    .LSU_AXI4_RREADY            (LSU_AXI4_RREADY),

    // AXI-Lite4 Write Address Channel
    .LSU_AXI4_AWADDR         (LSU_AXI4_AWADDR),
    .LSU_AXI4_AWVALID            (LSU_AXI4_AWVALID),
    .LSU_AXI4_AWREADY            (LSU_AXI4_AWREADY),
   
    // AXI-Lite4 Write Data Channel
    .LSU_AXI4_WDATA         (LSU_AXI4_WDATA),
    .LSU_AXI4_WSTRB         (LSU_AXI4_WSTRB),  
    .LSU_AXI4_WVALID            (LSU_AXI4_WVALID),
    .LSU_AXI4_WREADY            (LSU_AXI4_WREADY),
   
    // AXI-Lite4 Write Response Channel
    .LSU_AXI4_BVALID            (LSU_AXI4_BVALID),
    .LSU_AXI4_BREADY            (LSU_AXI4_BREADY)
    //output reg [1:0]       LSU_AXI4_BRESP 
);
*/

endmodule

module ysyx_24070003_ifu(
    input clock,
    input rstn,
    //input WBU_IFU_JUMP,
     //IDU是否准备好接收IFU的指令
    output reg IFU_IDU_valid, //IFU传递给IDU的指令是否有效
    input  IDU_IFU_ready, //IDU是否准备好接收IFU的指令
    input [31:0]EXU_IFU_pc,
    input       EXU_IFU_flush,
    input [31:0] BTB_pred_pc,
    input       BTB_pred_valid,
    input [1:0] resp,
    //output [31:0] inst_addr_o,
    output [31:0]IFU_IDU_INSTR,
    //input  [31:0] instr_in,
    output  [31:0] IFU_IDU_PC,
    output  [31:0] cur_pc,


    //input  EXU_LSU_valid,

    input  fence_i,
    input  stall,
    output [31:0]     BTB_pre_DNPC,

    output reg [63:0] ifu_count,

    // AXI-Lite4 Interface
    output reg [31:0] IFU_AXI4_araddr,
    output            IFU_AXI4_arvalid,
    // input             IFU_AXI4_arready,
    input  [31:0]     IFU_AXI4_rdata,
    input             ICACHE_IFU_rvalid,
    output reg        IFU_AXI4_rready,
    input  [31:0]     ICACHE_IFU_raddr,
    input             ICACHE_IFU_stall
    
);
(* keep *)reg [31:0] pc;



assign cur_pc = pc;
assign BTB_pre_DNPC = BTB_pred_pc;
always@(posedge clock)
begin 
   if(rstn | (resp != 2'b00))begin
    `ifdef __ICARUS__
    pc<=32'h80000000 ;
    `else
    pc<=32'h30000000 ;
    `endif
    end
    else if(EXU_IFU_flush)begin 
    pc <= EXU_IFU_pc;
    end
    else if(stall) begin
    pc <= pc;
    end
    else if(BTB_pred_valid && IDU_IFU_ready && (~ICACHE_IFU_stall)) begin
    pc <= BTB_pred_pc;
    end
    else if(IDU_IFU_ready && (~ICACHE_IFU_stall))begin
    pc <= pc + 32'h4;
    end
    
end



assign IFU_IDU_valid = ICACHE_IFU_rvalid;

assign IFU_AXI4_araddr = pc;

assign IFU_AXI4_arvalid = (~stall && !EXU_IFU_flush && !fence_i);


assign IFU_IDU_INSTR = IFU_AXI4_rdata;
assign IFU_IDU_PC   = ICACHE_IFU_raddr;   // 早就发出的地址


assign IFU_AXI4_rready = IDU_IFU_ready;

always @(posedge clock) begin
    if (rstn) begin
        ifu_count <= 64'h0;
    end
    else if(IDU_IFU_ready && IFU_IDU_valid)begin
        ifu_count <= ifu_count + 1'b1;
    end
end


/*
sram_inst inst_sram(
    .CLK(clk),
    .wen(1'b0),
    .addr(inst_addr),
    .Q(instr)
);*/
endmodule

module ysyx_24070003_icache(
    input clock,
    input reset,
    input fence_i,
    input flush,
    input  [31:0]  IFU_AXI4_araddr,
    input          IFU_AXI4_arvalid,
    // output reg        IFU_AXI4_rvalid,
    input             IFU_AXI4_rready,
    input  [31:0]     BTB_pre_DNPC,
    input             IDU_IFU_STALL,
    input             LSU_IFU_stall,

    output    [31:0]  ICACHE_IFU_rdata,
    output    [31:0]  ICACHE_IFU_raddr,
    output    [31:0]  ICACHE_IFU_pre_dnpc,
    output            ICACHE_IFU_valid,

    // output reg [63:0] ICACHE_hit_count,
    // output reg [63:0] ICACHE_miss_count,
    // output reg [63:0] total_access,
    // output reg [63:0] access_time,
    // output reg [63:0] miss_penalty,
    // output reg [63:0] ifu_during_count,

    output reg [31:0] ICACHE_AXI4_araddr,
    output reg        ICACHE_AXI4_arvalid,
    input             ICACHE_AXI4_arready,
    input  [31:0]     ICACHE_AXI4_rdata,
    input             ICACHE_AXI4_rvalid,
    input             ICACHE_AXI4_rlast,
    output            ICACHE_IFU_stall,
    output            ICACHE_AXI4_rready,
    output reg [7:0]  ICACHE_AXI4_arlen
    
);

parameter SDRAM_BLOCK_SIZE = 16;     
parameter SDRAM_NUM_BLOCKS = 4;    
parameter SDRAM_OFFSET_BITS = 4;    
parameter SDRAM_INDEX_BITS = 2;     
parameter SDRAM_TAG_BITS = 26;       


reg [SDRAM_TAG_BITS-1:0] tags [0:SDRAM_NUM_BLOCKS-1];  // 标签存储
reg [SDRAM_BLOCK_SIZE * 8-1:0] data [0:SDRAM_NUM_BLOCKS-1];           // 数据存储
reg [SDRAM_NUM_BLOCKS-1:0]valid ;                // 有效位

              // 有效位
parameter  IDLE = 0,
            AXI_WAIT = 1,
            AXI_READ = 2;
reg [1:0] state;
// typedef enum logic [2:0] {
//     IDLE,        // 空闲状态
//     AXI_WAIT,
//     AXI_READ    // 
// } state_t;


// state_t state;

reg [1:0] burst_count;
integer i;

//reg hit_reg1;
(* keep *)reg [31:0]  pc_reg1;
reg reg1_valid;
(* keep *)reg [31:0] reg1_pre_dnpc;

(* keep *)wire hit_reg1;


(* keep *)reg [31:0] addr_reg3;
reg [31:0] data_reg3;
reg [31:0] per_pc_reg3;
reg data_valid;

reg flush_r;



wire [SDRAM_TAG_BITS-1:0] tag_reg1 = pc_reg1[31:SDRAM_OFFSET_BITS+SDRAM_INDEX_BITS];
wire [SDRAM_INDEX_BITS-1:0] index_reg1 = pc_reg1[SDRAM_OFFSET_BITS+SDRAM_INDEX_BITS-1:SDRAM_OFFSET_BITS];


wire icache_stall = LSU_IFU_stall || IDU_IFU_STALL;

assign hit_reg1 = (valid[index_reg1] && (tags[index_reg1] == tag_reg1));
reg first_req;
reg reset_r;
(* keep *)wire negedeg_reset;
always @(posedge clock) begin
    reset_r <= reset;
end
assign negedeg_reset = reset_r & ~reset;
always @(posedge clock) begin
    if (reset | flush | flush_r)                    first_req <= 1'b1;
    else if (reg1_valid && hit_reg1)
                                  first_req <= 1'b0;  // 只要曾经命中过，就退出首次
end

// 更新条件
wire allow_update;
assign allow_update = (!icache_stall && IFU_AXI4_rready && !fence_i &&
                      (state == IDLE) &&
                      (first_req & (~reg1_valid) || hit_reg1)) | (!icache_stall && state == AXI_READ && ICACHE_AXI4_rlast & ~(flush | flush_r)); 

always @(posedge clock) begin
    if(reset) begin
        pc_reg1 <= 0;
        reg1_pre_dnpc <= 0;
    end
    else if(allow_update) begin
        pc_reg1 <= IFU_AXI4_araddr;
        reg1_pre_dnpc <= BTB_pre_DNPC;
    end
end

always @(posedge clock) begin
    if(reset) begin
        reg1_valid  <= 0;
    end
    else if(flush) begin
        reg1_valid <= 0;
    end
    else if(!icache_stall && IFU_AXI4_rready && !fence_i) begin
        reg1_valid <= 1'b1;
    end
end

always @(posedge clock) begin
    if(!icache_stall && IFU_AXI4_rready && reg1_valid && hit_reg1 && state == IDLE) begin
            case (pc_reg1[3:2])
                2'b00: data_reg3 <= data[index_reg1][31:0];
                2'b01: data_reg3 <= data[index_reg1][63:32];
                2'b10: data_reg3 <= data[index_reg1][95:64];
                2'b11: data_reg3 <= data[index_reg1][127:96];
            endcase
            addr_reg3 <= pc_reg1;
            per_pc_reg3 <= reg1_pre_dnpc;
       
    end
    else if(!icache_stall && state == AXI_READ && ICACHE_AXI4_rlast)begin
        case (pc_reg1[3:2])
            2'b00: data_reg3 <= data[index_reg1][31:0];
            2'b01: data_reg3 <= data[index_reg1][63:32];
            2'b10: data_reg3 <= data[index_reg1][95:64];
            2'b11: data_reg3 <= ICACHE_AXI4_rdata;
        endcase
        addr_reg3 <= pc_reg1;
        per_pc_reg3 <= reg1_pre_dnpc;
    end
end

assign ICACHE_IFU_rdata = data_reg3;
assign ICACHE_IFU_raddr = addr_reg3;
assign ICACHE_IFU_pre_dnpc  = per_pc_reg3;
assign ICACHE_IFU_valid = data_valid & (~flush);

assign ICACHE_IFU_stall = ~allow_update;


always @(posedge clock) begin
    if(reset)begin
        data_valid <= 0;
    end
    else if(flush || flush_r || fence_i) begin
        data_valid <= 0;
    end
    else if((!icache_stall && state == IDLE && reg1_valid && hit_reg1 && (~flush)) || (!icache_stall && state == AXI_READ && ICACHE_AXI4_rlast)) begin
        data_valid <= 1'b1;
    end
    else if(ICACHE_IFU_valid && IFU_AXI4_rready)begin
        data_valid <= 1'b0;
    end
end

always @(posedge clock) begin
    if(reset) begin
        flush_r <= 0;
    end
    else if(state != IDLE && flush) begin
        flush_r <= flush;
    end
    else if(state == IDLE) begin
        flush_r <= 0;
    end
end

always @(posedge clock) begin
    if(reset) begin
        state <= IDLE;
    end
    else begin
        case (state)
        IDLE: begin
            if(reg1_valid && (!(LSU_IFU_stall || IDU_IFU_STALL)) && IFU_AXI4_rready) begin
                if(hit_reg1)begin
                    state <= IDLE;
                end
                else if(!flush)begin
                    state <= AXI_WAIT;
                end
            end
        end
        AXI_WAIT: begin
            if(ICACHE_AXI4_arready && ICACHE_AXI4_arvalid) begin
                state <= AXI_READ;
            end
            else begin
                state <= AXI_WAIT;
            end
        end
        AXI_READ: begin
            if(ICACHE_AXI4_rvalid && ICACHE_AXI4_rlast) begin
                state <= IDLE; 
            end
            else begin
                state <= AXI_READ;
            end
        end
        default: begin
            state <= IDLE;
        end
        endcase
    end
end

// always @(posedge clock) begin
//     if(reset) begin
//         ICACHE_hit_count <= 0;
//     end
//     else if(hit_reg2 && reg2_valid && (!stall) && IFU_AXI4_rready)begin
//         ICACHE_hit_count <= ICACHE_hit_count + 1;
//     end
// end

// always @(posedge clock) begin
//     if(reset) begin
//         ICACHE_miss_count <= 0;
//     end
//     else if(ICACHE_AXI4_arready && ICACHE_AXI4_arvalid && state == AXI_WAIT)begin
//         ICACHE_miss_count <= ICACHE_miss_count + 1;
//     end
// end

// always @(posedge clock) begin
//     if(reset) begin
//         access_time <= 0;
//     end
//     else if(state == IDLE && IFU_AXI4_arvalid) begin
//         access_time <= access_time + 1'b1;
//     end
// end

// always @(posedge clock) begin
//     if(reset) begin
//         total_access <= 0;
//     end
//     else if(reg2_valid && (!stall) && IFU_AXI4_rready) begin
//         total_access <= total_access + 1'b1;
//     end
// end

// always @(posedge clock) begin
//     if(reset) begin
//         miss_penalty <= 0;
//     end
//     else if(((!hit_reg2) && reg2_valid && (!stall) && IFU_AXI4_rready && state == IDLE) || state == AXI_READ || state == AXI_WAIT) begin
//         miss_penalty <= miss_penalty + 1'b1;
//     end
// end

// always @(posedge clock) begin
//     if(reset) begin
//         ifu_during_count <= 0;
//     end
//     else if((reg2_valid && (!stall) && IFU_AXI4_rready) || state == AXI_READ || state == AXI_WAIT || state == UPDATED_CACHE ) begin
//         ifu_during_count <= ifu_during_count + 1;
//     end
// end




assign ICACHE_AXI4_rready = 1'b1;
assign ICACHE_AXI4_arlen = 8'b11;  // 一次读取4个数据
//assign ICACHE_AXI4_araddr = (is_sdram_reg2) ? {pc_reg2[31:4], 4'b0} : {pc_reg2[31:2], 2'b0};  // 地址对齐到16字节边界

always @(posedge clock)begin
    if(state == AXI_READ && ICACHE_AXI4_rvalid) begin
        case (burst_count)
            2'b00: data[index_reg1][31:0] <= ICACHE_AXI4_rdata;
            2'b01: data[index_reg1][63:32] <= ICACHE_AXI4_rdata;
            2'b10: data[index_reg1][95:64] <= ICACHE_AXI4_rdata;
            2'b11: data[index_reg1][127:96] <= ICACHE_AXI4_rdata;
        endcase
        
    end
end

always @(posedge clock)begin
    if(reset) begin
        burst_count <= 0;
    end 
    else if(state == AXI_READ && ICACHE_AXI4_rvalid) begin
        burst_count <= burst_count + 1;
    end
end



always @(posedge clock) begin
    if(fence_i | reset) begin
        valid <= 0;  // 复位时所有块无效
    end
    else if(state == AXI_READ) begin
        valid[index_reg1] <= 1'b1;
        tags[index_reg1] <= tag_reg1;
    end
end

always @(posedge clock) begin
    if(reset) begin
        ICACHE_AXI4_arvalid <= 0;
    end
    else if((ICACHE_AXI4_arready && ICACHE_AXI4_arvalid))begin
        ICACHE_AXI4_arvalid <= 1'b0;
    end
    else if(state == IDLE && (!hit_reg1) && reg1_valid && (!flush) && IFU_AXI4_rready)begin
        ICACHE_AXI4_arvalid <= 1'b1;
    end
end
always @(posedge clock) begin
    if(reset)begin
        ICACHE_AXI4_araddr <= 32'b0;
    end
    else  if(state == IDLE && (!hit_reg1) && reg1_valid && (!flush) && IFU_AXI4_rready)begin
        ICACHE_AXI4_araddr <= {pc_reg1[31:4], 4'b0} ; 
    end
    
end



endmodule

module ysyx_24070003_btb(
    input clock,
    input reset,
    input [31:0] cur_pc,
    input [31:0] update_pc,
    input [31:0] target_pc,
    input        update_valid,

    output [31:0] pred_pc,
    output        pred_valid
);


localparam WAY_NUM = 2;
localparam INDEX_WIDTH = 2;
localparam ADDR_WIDTH = 32;
localparam OFFSET_WITH = 2;
localparam TAG_WIDTH = ADDR_WIDTH - OFFSET_WITH - INDEX_WIDTH;

wire [INDEX_WIDTH-1:0] cur_index;
wire [TAG_WIDTH-1:0] cur_tag;
wire [INDEX_WIDTH-1:0] update_index;
wire [TAG_WIDTH-1:0] update_tag;
wire [WAY_NUM-1:0] hit;
wire [WAY_NUM-1:0] update_hit;
//wire cur_hit;
wire upd_hit;

reg [TAG_WIDTH-1:0] btb_tag [2 ** INDEX_WIDTH -1:0][WAY_NUM-1:0];     // 标签存储
reg [29:0] btb_target [2 ** INDEX_WIDTH -1:0][WAY_NUM-1:0];  // 目标地址存储
reg btb_valid [2 ** INDEX_WIDTH -1:0][WAY_NUM-1:0];          // 有效位

reg [3:0] hit_valid;
reg [3:0] hit_valid1;

assign cur_index = cur_pc[INDEX_WIDTH+OFFSET_WITH-1:OFFSET_WITH];
assign cur_tag = cur_pc[ADDR_WIDTH-1:INDEX_WIDTH+OFFSET_WITH];
assign update_index = update_pc[INDEX_WIDTH+OFFSET_WITH-1:OFFSET_WITH];
assign update_tag = update_pc[ADDR_WIDTH-1:INDEX_WIDTH+OFFSET_WITH];

assign hit[0] = btb_valid[cur_index][0] && (btb_tag[cur_index][0] == cur_tag);
assign hit[1] = btb_valid[cur_index][1] && (btb_tag[cur_index][1] == cur_tag);

assign pred_valid = (hit_valid[cur_index]) ? hit[0] : (hit_valid1[update_index]) ? hit[1] : 0;

assign update_hit[0] = ~btb_valid[update_index][0] ;
assign update_hit[1] = ~btb_valid[update_index][1] ;



assign pred_pc = (pred_valid) ? {btb_target[cur_index][hit[1]],2'b00} : cur_pc;

reg update_way;
always @(posedge clock) begin
    if(reset)begin 
        update_way <= 0;
    end
    else if(update_valid)begin
        update_way <= ~update_way;
    end
end

integer i,j;
always @(posedge clock) begin
    if(reset)begin
        hit_valid <= 4'b0000;
        hit_valid1 <= 4'b0000;
    end
    else if(update_valid)begin
        if(update_hit[0]) begin
            hit_valid[update_index] <= 1;
            btb_tag[update_index][0] <= update_tag;
            btb_target[update_index][0] <= target_pc[31:2];
            btb_valid[update_index][0] <= 1;
        end
        else if(update_hit[1]) begin
            hit_valid1[update_index] <= 1;
            btb_tag[update_index][1] <= update_tag;
            btb_target[update_index][1] <= target_pc[31:2];
            btb_valid[update_index][1] <= 1;
        end
        else begin
            btb_tag[update_index][update_way] <= update_tag;
            btb_target[update_index][update_way] <= target_pc[31:2];
            btb_valid[update_index][update_way] <= 1;
        end
    end
end

endmodule

module ysyx_24070003_idu(
    input wire [31:0] INSTR,
    input wire [31:0] IFU_IDU_PC,
    input [31:0]IFU_IDU_pre_dnpc,
    input       flush,
    //input wire EXU_IFU_flush,
    input clock,
    input rst_n,
    output fence_i,
    //input               IFU_IDU_STALL,
    input               IFU_IDU_valid,          // 从IFU到IDU的有效信号
    output           IDU_IFU_ready,          // IDU到IFU的就绪信号
    input               EXU_IDU_ready,          // 从执行单元(EXU)到IDU的就绪信号
    output reg          IDU_EXU_valid,          // IDU到EXU的有效信号
    //output reg[6:0] IDU_EXU_opcode,
    output reg[4:0] IDU_EXU_rd,
    output reg[4:0] IDU_EXU_rs1,
    output reg[4:0] IDU_EXU_rs2,
    output reg[2:0] IDU_EXU_csr_rst,
    output reg[31:0]IDU_EXU_imm,
    output reg [3:0]IDU_EXU_alu_op ,       
    output reg IDU_EXU_u_alu_type    ,
    //output reg IDU_EXU_mul_high      ,
    output reg [1:0] IDU_EXU_alu_src1      ,
    output reg [1:0] IDU_EXU_alu_src2      ,
    output reg IDU_EXU_branch        ,
   // output reg IDU_EXU_mem_to_reg    ,
    output reg IDU_EXU_mem_read      ,
    //output reg IDU_EXU_mem_write     ,
    output reg IDU_EXU_reg_write     ,
    output reg IDU_EXU_jal           ,
    output reg IDU_EXU_jalr          ,
    // output reg IDU_EXU_lw            ,
    // output reg IDU_EXU_lh            ,
    // output reg IDU_EXU_lb            ,
    // output reg IDU_EXU_lbu           ,
    // output reg IDU_EXU_lhu           ,
    // output reg IDU_EXU_sw            ,
    // output reg IDU_EXU_sb            ,
    // output reg IDU_EXU_sh            ,
    output reg [8:0] IDU_EXU_RW_sign,
    output reg [2:0]IDU_EXU_csr_op,
    output reg IDU_EXU_ebreak        ,
    output reg IDU_EXU_ecall         ,
    output reg IDU_EXU_mret          ,
    //output reg IDU_EXU_U_type_1      ,
    //output reg IDU_EXU_J_type_1      ,
    output reg IDU_EXU_B_type      ,
    //output reg IDU_EXU_pcsrc         ,
    output reg IDU_EXU_C_type        ,
    //output reg IDU_EXU_STALL         ,
    output reg [31:0] IDU_EXU_PC  ,
    output reg [31:0] IDU_EXU_pre_dnpc,

    output reg IDU_EXU_exu_raw_rs1,
    output reg IDU_EXU_exu_raw_rs2,
    output reg IDU_EXU_lsu_raw_rs1,
    output reg IDU_EXU_lsu_raw_rs2,

    // output reg [63:0] calcu_type_count,
    // output reg [63:0] Jump_type_count,
    // output reg [63:0] BJump_type_count,
    // output reg [63:0] LOAD_type_count,
    // output reg [63:0] STORE_type_count,
    // output reg [63:0] C_type_count,

    input         exu_reg_write_en,
    input  [4:0]  exu_rd_addr,
    input         exu_ren,

    // 来自级
    input         lsu_reg_write_en,
    input  [4:0]  lsu_rd_addr,


    output        stall

);
// reg [63:0] calcu_type_count;
// reg [63:0] Jump_type_count;
// reg [63:0] LOAD_type_count;
// reg [63:0] STORE_type_count;
// reg [63:0] C_type_count;

// reg [31:0]instr;
wire    [31:0]    immI_num ;
wire    [31:0]    immS_num ;
wire    [31:0]    immB_num ;
wire    [31:0]    immU_num ;
wire    [31:0]    immJ_num ;
wire    [2:0]     immC_num ;
wire    [6:0]     opcode   ;
wire    [2:0]     funct3   ; 
wire    [6:0]     funct7   ; 
wire    [4:0]     rd       ;     
wire    [4:0]     rs1      ; 
wire    [4:0]     rs2      ; 
wire    [2:0]     csr_rst  ; 
wire    [31:0]    imm      ; 
wire U_type;
wire J_type;
wire I_type;
wire S_type;
wire R_type;
wire B_type;
wire C_type;
wire I_type_1 = (opcode == 7'b0010011);

assign funct3 = (R_type || I_type || S_type || B_type|| C_type) ? INSTR[14:12] : 3'b0;
assign funct7 = (R_type || I_type_1) ? INSTR[31:25] : 7'b0;
assign opcode = INSTR[6:0];
assign I_type = (opcode == 7'b0010011 || opcode == 7'b1100111 || opcode == 7'b0000011 || opcode == 7'b1010011);
assign R_type = (opcode == 7'b0110011);
assign S_type = (opcode == 7'b0100011);
assign U_type = (opcode == 7'b0110111 || opcode == 7'B0010111);
assign B_type = (opcode == 7'b1100011);
assign J_type = (opcode == 7'b1101111 || opcode == 7'b1011111);
assign C_type = (opcode == 7'b1110011);

assign  immI_num = { {21{INSTR[31]}}, INSTR[30:20] };
assign  immS_num = { {21{INSTR[31]}}, INSTR[30:25], INSTR[11:7] };
assign  immB_num = { {20{INSTR[31]}}, INSTR[7], INSTR[30:25], INSTR[11:8], 1'b0 };
assign  immU_num = { INSTR[31], INSTR[30:12], 12'b0 };
assign  immJ_num = { {12{INSTR[31]}}, INSTR[19:12], INSTR[20], INSTR[30:21], 1'b0 };
assign  immC_num =   (INSTR[31:20] == 'h341) ? 3'd0 :
                    (INSTR[31:20] == 'h300) ? 3'd1 :
                    (INSTR[31:20] == 'h342) ? 3'd2 :
                    (INSTR[31:20] == 'h305) ? 3'd3 : 
                    (INSTR[31:20] == 'hf11) ? 3'd4 :
                    (INSTR[31:20] == 'hf12) ? 3'd5 :3'd0;
assign rs2 = (R_type || S_type || B_type) ? INSTR[24:20] :5'b0;
assign csr_rst = (C_type) ? immC_num : 3'd0;
assign rs1 = (R_type || S_type || B_type || I_type || C_type) ? INSTR[19:15] : 5'b0;

assign rd = (R_type || I_type || U_type || J_type || C_type) ? INSTR[11:7] : 5'b0;



assign imm = ( {32{I_type}} & immI_num ) |
                     ( {32{S_type}} & immS_num ) |
                     ( {32{B_type}} & immB_num ) |
                     ( {32{U_type}} & immU_num ) |
                     ( {32{J_type}} & immJ_num ) ;

wire J_type_1;
wire [1:0] alu_op;
wire I_type_2 = (opcode == 7'b1100111);
assign J_type_1 = (opcode == 7'b1101111) || I_type_2; 
assign C_type = (opcode == 7'b1110011);

wire I_type_3 = (opcode == 7'b0000011);
wire I_type_4 = (opcode == 7'b1010011);
wire jalr = (opcode == 7'b1100111);
wire jal  = (opcode == 7'b1101111);
wire U_type_1 = (opcode == 7'b0110111);

wire csw = ( C_type && funct3 == 3'b001 );
wire csc = ( C_type && funct3 == 3'b011 );
wire css = ( C_type && funct3 == 3'b010 );

wire lh   = (I_type_3 && funct3 == 3'b001);
wire lw   = (I_type_3 && funct3 == 3'b010);
wire lb   = (I_type_3 && funct3 == 3'b000);
wire lbu  = (I_type_3 && funct3 == 3'b100);
wire lhu  = (I_type_3 && funct3 == 3'b101);

wire sw   = (S_type && funct3 == 3'b010);
wire sb   = (S_type && funct3 == 3'b000);
wire sh   = (S_type && funct3 == 3'b001);

wire [8:0] rw_sign;

// wire remu = (R_type && funct7 == 7'b0000001 && funct3 == 3'b111);
// wire mulh = (R_type && funct7 == 7'b0000001 && funct3 == 3'b001);
// wire mulhu= (R_type && funct7 == 7'b0000001 && funct3 == 3'b011);
// wire divu = (R_type && funct7 == 7'b0000001 && funct3 == 3'b101);
wire sltu = (R_type && funct7 == 7'b0000000 && funct3 == 3'b011);
// wire mul  = (R_type && funct7 == 7'b0000001 && funct3 == 3'b000);
wire sltiu= (I_type_1 && funct3 == 3'b011);
wire bltu = (B_type && funct3 == 3'b110);
wire bgeu = (B_type && funct3 == 3'b111);

wire u_alu_type = (sltu | sltiu | bltu | bgeu | lbu | lhu );
//wire mul_high = mulh | mulhu;
//wire jump = J_type | I_type_2;
wire mem_read = I_type_3;
wire mem_write = S_type;
wire  ebreak = ( INSTR == 32'b00000000000100000000000001110011 ) ;
wire ecall  = ( INSTR == 32'b00000000000000000000000001110011)  ;
wire mret   = ( INSTR == 32'b00110000001000000000000001110011 ) ;
wire reg_write = !(B_type || S_type);
wire alu_src1 = R_type | I_type_1 | I_type_3 | I_type_4 | S_type | B_type;
wire alu_src2 = R_type | B_type;

wire idu_rs1_valid = R_type | I_type | S_type | B_type | C_type;
wire idu_rs2_valid = R_type | S_type | B_type;
//wire mem_to_reg = (mem_read|mem_write);
wire branch = B_type;
assign alu_op = (R_type) ? 2'b10 :
                (B_type) ? 2'b01 :
                (S_type | U_type | I_type_3 | J_type) ? 2'b00 :
                2'b11;
wire [3:0] aluop;
ysyx_24070003_exuop_ctrl my_exuop_crtl(
    .funct3         (funct3),
    .funct7         (funct7[5:0]),
    .alu_op         (alu_op),
    .aluOp          (aluop)
);
assign rw_sign = {mem_write,lh,lw,lb,lbu,lhu,sw,sb,sh};

///////////////////////////

//////////////////////////

wire rs1_raw_exu;
wire rs2_raw_exu;
wire rs1_raw_lsu;
wire rs2_raw_lsu;

ysyx_24070003_raw raw_detect(
    // 来自译码的源寄存器
    .idu_rs1_addr               (rs1),
    .idu_rs2_addr               (rs2),
    .idu_rs1_valid              (idu_rs1_valid),   // 为 1 表示本指令真正读 rs1
    .idu_rs2_valid              (idu_rs2_valid),   // 为 1 表示本指令真正读 rs2

    // 来自
    .exu_reg_write_en           (exu_reg_write_en),
    .exu_rd_addr                (exu_rd_addr),
    .exu_ren                    (exu_ren),

    // 来自级
    .lsu_reg_write_en           (lsu_reg_write_en),
    .lsu_rd_addr                (lsu_rd_addr),

    .rs1_raw_exu                 (rs1_raw_exu),
    .rs2_raw_exu                 (rs2_raw_exu),
    .rs1_raw_lsu                 (rs1_raw_lsu),
    .rs2_raw_lsu                 (rs2_raw_lsu),

    // 输出有一个冲突就阻塞
    .stall                      (stall)
);
////////////0x0000100F//////////////0000000 00000 00000 001 00000 0001111/////////////
assign fence_i = (INSTR == 32'h0000100F) && IFU_IDU_valid && IDU_IFU_ready;
//wire pcsrc = (branch /*& zero*/) | jump | ecall | mret;


wire [2:0] csr_op = {csw, csc, css};

assign IDU_IFU_ready = EXU_IDU_ready  && (~stall);    // 设置IDU到IFU的就绪信号

reg idu_exu_valid;
always @(posedge clock) begin
    if(rst_n) begin
        idu_exu_valid <= 1'b0;
    end else if(stall) begin
        idu_exu_valid <= 1'b0;
    end else if(IFU_IDU_valid && IDU_IFU_ready ) begin
        idu_exu_valid <= 1'b1;
    end else if(EXU_IDU_ready && IDU_EXU_valid) begin
        idu_exu_valid <= 1'b0;
    end
end

assign IDU_EXU_valid = idu_exu_valid ;

always@(posedge clock)
begin 
   if((rst_n ))begin
   // IDU_EXU_opcode        <=        7'b0;     
    IDU_EXU_rd            <=        5'b0;
    IDU_EXU_rs1           <=        5'b0;  
    IDU_EXU_rs2           <=        5'b0;
    IDU_EXU_csr_rst       <=        3'b0;    
    IDU_EXU_imm           <=        32'b0;

    IDU_EXU_alu_op              <=        4'b0;     
    IDU_EXU_u_alu_type          <=        1'b0;   
    //IDU_EXU_mul_high            <=        1'b0;
    IDU_EXU_alu_src1            <=        2'b0;
    IDU_EXU_alu_src2            <=        2'b0;  
    IDU_EXU_branch              <=        1'b0;
 //   IDU_EXU_mem_to_reg          <=        1'b0;    
    IDU_EXU_mem_read            <=        1'b0;
    //IDU_EXU_mem_write           <=        1'b0;     
    IDU_EXU_reg_write           <=        1'b0;   
    IDU_EXU_jal                 <=        1'b0;
    IDU_EXU_jalr                <=        1'b0;
    IDU_EXU_RW_sign             <=        8'b0;
    // IDU_EXU_lw                  <=        1'b0;  
    // IDU_EXU_lh                  <=        1'b0;
    // IDU_EXU_lb                  <=        1'b0;    
    // IDU_EXU_lbu                 <=        1'b0;
    // IDU_EXU_lhu                 <=        1'b0;     
    // IDU_EXU_sw                  <=        1'b0;   
    // IDU_EXU_sb                  <=        1'b0;
    // IDU_EXU_sh                  <=        1'b0;
    IDU_EXU_csr_op              <=        3'b0;  
    IDU_EXU_ebreak              <=        1'b0;
    IDU_EXU_ecall               <=        1'b0;     
    IDU_EXU_mret                <=        1'b0;   
    //IDU_EXU_U_type_1            <=        1'b0;
    //IDU_EXU_J_type_1            <=        1'b0;
    //IDU_EXU_pcsrc               <=        1'b0;  
    IDU_EXU_C_type              <=        1'b0;
    IDU_EXU_B_type              <=        1'b0;
    IDU_EXU_exu_raw_rs1           <=        1'b0;
    IDU_EXU_exu_raw_rs2           <=        1'b0;
    IDU_EXU_lsu_raw_rs1           <=        1'b0;
    IDU_EXU_lsu_raw_rs2           <=        1'b0;

    //IDU_EXU_STALL               <=        1'b0;
    IDU_EXU_PC                  <=        32'b0;
    IDU_EXU_pre_dnpc                <=        32'b0;
    // calcu_type_count               <=        64'b0;
    // Jump_type_count               <=        64'b0;
    // BJump_type_count               <=        64'b0;
    // C_type_count               <=        64'b0;
    // LOAD_type_count               <=        64'b0;
    // STORE_type_count               <=        64'b0;
    end
    else if(stall || flush)begin
   // IDU_EXU_opcode        <=        opcode   ;     
    IDU_EXU_rd            <=        5'b0;
    IDU_EXU_rs1           <=        5'b0;  
    IDU_EXU_rs2           <=        5'b0;
    IDU_EXU_csr_rst       <=        3'b0;    
    IDU_EXU_imm           <=        32'b0;

    IDU_EXU_alu_op              <=        4'b0;     
    IDU_EXU_u_alu_type          <=        1'b0;   
    //IDU_EXU_mul_high            <=        1'b0;
    IDU_EXU_alu_src1            <=       2'b0;
    IDU_EXU_alu_src2            <=        2'b0;  
    IDU_EXU_branch              <=        1'b0;
 //   IDU_EXU_mem_to_reg          <=        1'b0;    
    IDU_EXU_mem_read            <=        1'b0;
    //IDU_EXU_mem_write           <=        1'b0;     
    IDU_EXU_reg_write           <=        1'b0;   
    IDU_EXU_jal                 <=        1'b0;
    IDU_EXU_jalr                <=        1'b0;
    // IDU_EXU_lw                  <=        1'b0;  
    // IDU_EXU_lh                  <=        1'b0;
    // IDU_EXU_lb                  <=        1'b0;    
    // IDU_EXU_lbu                 <=        1'b0;
    // IDU_EXU_lhu                 <=        1'b0;     
    // IDU_EXU_sw                  <=        1'b0;   
    // IDU_EXU_sb                  <=        1'b0;
    // IDU_EXU_sh                  <=        1'b0;
    IDU_EXU_RW_sign             <=        8'b0;
    IDU_EXU_csr_op              <=        3'b0;     
    IDU_EXU_ebreak              <=        1'b0;
    IDU_EXU_ecall               <=        1'b0;     
    IDU_EXU_mret                <=        1'b0;   
    //IDU_EXU_U_type_1            <=        1'b0;
    //IDU_EXU_J_type_1            <=        1'b0;
    //IDU_EXU_pcsrc               <=        1'b0;  
    IDU_EXU_C_type              <=        1'b0;
    IDU_EXU_B_type              <=        1'b0;
    //IDU_EXU_STALL               <=        1'b0;
    IDU_EXU_PC                  <=        32'b0;
    IDU_EXU_pre_dnpc                <=        32'b0;

    IDU_EXU_exu_raw_rs1           <=        1'b0;
    IDU_EXU_exu_raw_rs2           <=        1'b0;
    IDU_EXU_lsu_raw_rs1           <=        1'b0;
    IDU_EXU_lsu_raw_rs2           <=        1'b0;
    end
    else if(IFU_IDU_valid && IDU_IFU_ready)begin
        // if(U_type|R_type|I_type_1|I_type_4) begin calcu_type_count <= calcu_type_count + 1'b1; end
        // else if(J_type) begin Jump_type_count <= Jump_type_count + 1'b1; end
        // else if(B_type) begin BJump_type_count <= BJump_type_count + 1'b1; end
        // else if(C_type) begin C_type_count <= C_type_count + 1'b1; end
        // else if(I_type_3) begin LOAD_type_count <= LOAD_type_count + 1'b1; end
        // else if(S_type) begin STORE_type_count <= STORE_type_count + 1'b1; end
   // IDU_EXU_opcode        <=        opcode   ;     
    IDU_EXU_rd            <=        rd       ;
    IDU_EXU_rs1           <=        rs1      ;  
    IDU_EXU_rs2           <=        rs2      ;
    IDU_EXU_csr_rst       <=        csr_rst  ;    
    IDU_EXU_imm           <=        imm      ;
    IDU_EXU_alu_op              <=        aluop;     
    IDU_EXU_u_alu_type          <=        u_alu_type;   
    //IDU_EXU_mul_high            <=        mul_high     ;
    IDU_EXU_alu_src1            <=        {alu_src1, U_type_1}    ;
    IDU_EXU_alu_src2            <=        {alu_src2, J_type_1}    ;  
    IDU_EXU_branch              <=        branch       ;
   // IDU_EXU_mem_to_reg          <=        mem_to_reg   ;    
    IDU_EXU_mem_read            <=        mem_read     ;
    //IDU_EXU_mem_write           <=        mem_write    ;     
    IDU_EXU_reg_write           <=        reg_write    ;   
    IDU_EXU_jal                 <=        jal          ;
    IDU_EXU_jalr                <=        jalr   ;
    IDU_EXU_RW_sign             <=        rw_sign;
    // IDU_EXU_lw                  <=        lw     ;  
    // IDU_EXU_lh                  <=        lh     ;
    // IDU_EXU_lb                  <=        lb     ;    
    // IDU_EXU_lbu                 <=        lbu    ;
    // IDU_EXU_lhu                 <=        lhu    ;     
    // IDU_EXU_sw                  <=        sw     ;   
    // IDU_EXU_sb                  <=        sb     ;
    // IDU_EXU_sh                  <=        sh     ;
    IDU_EXU_csr_op              <=        csr_op;     
    IDU_EXU_ebreak              <=        ebreak    ;
    IDU_EXU_ecall               <=        ecall     ;     
    IDU_EXU_mret                <=        mret      ;   
    // IDU_EXU_U_type_1            <=        U_type_1  ;
    // IDU_EXU_J_type_1            <=        J_type_1  ;
    //IDU_EXU_pcsrc               <=        pcsrc     ;  
    IDU_EXU_C_type              <=        C_type    ;
    IDU_EXU_B_type              <=        B_type    ;
    //IDU_EXU_STALL               <=        IFU_IDU_STALL;
    IDU_EXU_PC                  <=        IFU_IDU_PC;
    IDU_EXU_pre_dnpc                <=        IFU_IDU_pre_dnpc;

    IDU_EXU_exu_raw_rs1           <=        rs1_raw_exu;
    IDU_EXU_exu_raw_rs2           <=        rs2_raw_exu;
    IDU_EXU_lsu_raw_rs1           <=        rs1_raw_lsu;
    IDU_EXU_lsu_raw_rs2           <=        rs2_raw_lsu;
    end
    else begin
    
   // IDU_EXU_opcode        <=        opcode   ;     
    IDU_EXU_rd            <=        IDU_EXU_rd           ;
    IDU_EXU_rs1           <=        IDU_EXU_rs1         ;
    IDU_EXU_rs2           <=        IDU_EXU_rs2         ;
    IDU_EXU_csr_rst       <=        IDU_EXU_csr_rst     ;
    IDU_EXU_imm           <=        IDU_EXU_imm         ;
    IDU_EXU_alu_op              <=  IDU_EXU_alu_op      ;
    IDU_EXU_u_alu_type          <=  IDU_EXU_u_alu_type  ;
    //IDU_EXU_mul_high            <=  IDU_EXU_mul_high    ;
    IDU_EXU_alu_src1            <=  IDU_EXU_alu_src1    ;
    IDU_EXU_alu_src2            <=  IDU_EXU_alu_src2    ;
    IDU_EXU_branch              <=  IDU_EXU_branch      ;
   // IDU_EXU_mem_to_reg          <=/ IDU_EXU_mem_to_reg    
    IDU_EXU_mem_read            <=  IDU_EXU_mem_read    ;
    //IDU_EXU_mem_write           <=  IDU_EXU_mem_write      ;
    IDU_EXU_reg_write           <=  IDU_EXU_reg_write    ;
    IDU_EXU_jal                 <=  IDU_EXU_jal         ;
    IDU_EXU_jalr                <=  IDU_EXU_jalr        ;
    IDU_EXU_RW_sign             <=  IDU_EXU_RW_sign;
    // IDU_EXU_lw                  <=  IDU_EXU_lw          ;
    // IDU_EXU_lh                  <=  IDU_EXU_lh          ;
    // IDU_EXU_lb                  <=  IDU_EXU_lb          ;
    // IDU_EXU_lbu                 <=  IDU_EXU_lbu         ;
    // IDU_EXU_lhu                 <=  IDU_EXU_lhu         ;
    // IDU_EXU_sw                  <=  IDU_EXU_sw          ;
    // IDU_EXU_sb                  <=  IDU_EXU_sb          ;
    // IDU_EXU_sh                  <=  IDU_EXU_sh        ;  
    IDU_EXU_csr_op              <=        IDU_EXU_csr_op;  
    IDU_EXU_ebreak              <=  IDU_EXU_ebreak    ;  
    IDU_EXU_ecall               <=  IDU_EXU_ecall     ;  
    IDU_EXU_mret                <=  IDU_EXU_mret      ;  
    //IDU_EXU_U_type_1            <=  IDU_EXU_U_type_1  ;  
    //IDU_EXU_J_type_1            <=  IDU_EXU_J_type_1  ;  
    //IDU_EXU_pcsrc               <=//IDU_EXU_pcsrc   ;  
    IDU_EXU_C_type              <=  IDU_EXU_C_type    ;  
    IDU_EXU_B_type              <=  IDU_EXU_B_type    ;
    //IDU_EXU_STALL               <=//IDU_EXU_STALL   ;  
    IDU_EXU_PC                  <=  IDU_EXU_PC        ;  
    IDU_EXU_pre_dnpc                <=  IDU_EXU_pre_dnpc      ;  

    IDU_EXU_exu_raw_rs1           <=        IDU_EXU_exu_raw_rs1;
    IDU_EXU_exu_raw_rs2           <=        IDU_EXU_exu_raw_rs2;
    IDU_EXU_lsu_raw_rs1           <=        IDU_EXU_lsu_raw_rs1;
    IDU_EXU_lsu_raw_rs2           <=        IDU_EXU_lsu_raw_rs2;
    end
end


endmodule

module ysyx_24070003_raw (
    // 来自译码的源寄存器
    input  [4:0] idu_rs1_addr,
    input  [4:0] idu_rs2_addr,
    input         idu_rs1_valid,   // 为 1 表示本指令真正读 rs1
    input         idu_rs2_valid,

    // 来自
    input         exu_reg_write_en,
    input  [4:0]  exu_rd_addr,
    input         exu_ren,

    // 来自级
    input         lsu_reg_write_en,
    input  [4:0]  lsu_rd_addr,

    output       rs1_raw_exu,
    output       rs2_raw_exu,
    output       rs1_raw_lsu,
    output       rs2_raw_lsu,
    // 输出有一个冲突就阻塞
    output        stall
);
    function  conflict;
        input [4:0] src;
        input       src_valid;
        input [4:0] dst;
        input       dst_valid;
        begin
        conflict = src_valid & dst_valid & (src == dst) & (dst != 5'b0);
        end
    endfunction

    assign rs1_raw_lsu = conflict(idu_rs1_addr, idu_rs1_valid, lsu_rd_addr, lsu_reg_write_en);
    assign rs2_raw_lsu = conflict(idu_rs2_addr, idu_rs2_valid, lsu_rd_addr, lsu_reg_write_en);

    wire rs1_raw_exu1 = conflict(idu_rs1_addr, idu_rs1_valid, exu_rd_addr, exu_reg_write_en);
    wire rs2_raw_exu1 = conflict(idu_rs2_addr, idu_rs2_valid, exu_rd_addr, exu_reg_write_en);

    assign rs1_raw_exu = rs1_raw_exu1 && (~exu_ren);
    assign rs2_raw_exu = rs2_raw_exu1 && (~exu_ren);

    

    assign stall         = (rs1_raw_exu1 | rs2_raw_exu1) && exu_ren ;
                            //rs1_raw_wbu | rs2_raw_wbu ;
    
endmodule

module ysyx_24070003_exuop_ctrl(
    input [2:0]  funct3,
    input [5:0]  funct7,
    input [1:0]  alu_op,
    output reg [3:0] aluOp
);
`define ysyx_24070003_OP_ADD         4'b0001 // +
`define ysyx_24070003_OP_SUB         4'b0011 // -

`define ysyx_24070003_OP_AND         4'b0100 // &
`define ysyx_24070003_OP_OR          4'b0101 // |
`define ysyx_24070003_OP_XOR         4'b0110 // ^

`define ysyx_24070003_OP_SLL         4'b1100 // <<
`define ysyx_24070003_OP_SRL         4'b1101 // >>
`define ysyx_24070003_OP_SRA         4'b1110 // >>>

`define ysyx_24070003_OP_BLT         4'b1000 // <
`define ysyx_24070003_OP_BGE         4'b1001 // >=
`define ysyx_24070003_OP_BNE         4'b1010 // !=
`define ysyx_24070003_OP_BEQ         4'b1011 // ==

`define ysyx_24070003_BEQ_FUNCT3         3'b000
`define ysyx_24070003_BNE_FUNCT3         3'b001
`define ysyx_24070003_BLT_FUNCT3         3'b100
`define ysyx_24070003_BGE_FUNCT3         3'b101
`define ysyx_24070003_BLTU_FUNCT3        3'b110
`define ysyx_24070003_BGEU_FUNCT3        3'b111

`define ysyx_24070003_ADDI_FUNCT3         3'b000
`define ysyx_24070003_SLLI_FUNCT3         3'b001
`define ysyx_24070003_SLTI_FUNCT3         3'b010
`define ysyx_24070003_SLTIU_FUNCT3        3'b011
`define ysyx_24070003_XORI_FUNCT3         3'b100
`define ysyx_24070003_SRLI_SRAI_FUNCT3    3'b101
`define ysyx_24070003_ORI_FUNCT3          3'b110
`define ysyx_24070003_ANDI_FUNCT3         3'b111

`define ysyx_24070003_SUB_ADD_MUL_FUNCT3         3'b000
`define ysyx_24070003_SLL_MULH_FUNCT3            3'b001
`define ysyx_24070003_SLT_FUNCT3                 3'b010
`define ysyx_24070003_SLTU_MULHU_FUNCT3          3'b011
`define ysyx_24070003_XOR_DIV_FUNCT3             3'b100
`define ysyx_24070003_SRL_SRA_DIVU_FUNCT3        3'b101
`define ysyx_24070003_OR_REM_FUNCT3              3'b110
`define ysyx_24070003_AND_REMU_FUNCT3            3'b111
    always @(*) begin
      case(alu_op)
        2'b00:  aluOp = `ysyx_24070003_OP_ADD;       //load/store    
        2'b10:  begin //R
          case(funct3)                   
            `ysyx_24070003_SUB_ADD_MUL_FUNCT3: begin
                  if(funct7[5]) //sub
                    aluOp = `ysyx_24070003_OP_SUB;
                  else //add
                    aluOp = `ysyx_24070003_OP_ADD;
              end
            `ysyx_24070003_SLL_MULH_FUNCT3: begin
                  aluOp = `ysyx_24070003_OP_SLL;
              end
            `ysyx_24070003_SLT_FUNCT3: begin
                  aluOp = `ysyx_24070003_OP_BLT;
              end
            `ysyx_24070003_SLTU_MULHU_FUNCT3: begin
                  aluOp = `ysyx_24070003_OP_BLT;
              end
            `ysyx_24070003_XOR_DIV_FUNCT3: begin
                  aluOp = `ysyx_24070003_OP_XOR;
              end
            `ysyx_24070003_SRL_SRA_DIVU_FUNCT3: begin
                  if(funct7[5]) //sra
                    aluOp = `ysyx_24070003_OP_SRA;
                  else //srl
                    aluOp = `ysyx_24070003_OP_SRL;
              end
            `ysyx_24070003_OR_REM_FUNCT3: begin
                  aluOp = `ysyx_24070003_OP_OR;
              end
            `ysyx_24070003_AND_REMU_FUNCT3: begin
                  aluOp = `ysyx_24070003_OP_AND;
              end
            default : aluOp = `ysyx_24070003_OP_ADD;
        endcase
        end
        2'b01:  begin //B
          case(funct3)                   
            `ysyx_24070003_BEQ_FUNCT3:  aluOp = `ysyx_24070003_OP_BEQ;
            `ysyx_24070003_BNE_FUNCT3:  aluOp = `ysyx_24070003_OP_BNE;
            `ysyx_24070003_BLT_FUNCT3:  aluOp = `ysyx_24070003_OP_BLT;
            `ysyx_24070003_BGE_FUNCT3:  aluOp = `ysyx_24070003_OP_BGE;
            `ysyx_24070003_BLTU_FUNCT3: aluOp = `ysyx_24070003_OP_BLT;
            `ysyx_24070003_BGEU_FUNCT3: aluOp = `ysyx_24070003_OP_BGE;
            default:      aluOp = `ysyx_24070003_OP_ADD;
          endcase
          end
        2'b11:  begin //I
        case(funct3)                   
            `ysyx_24070003_ADDI_FUNCT3: aluOp = `ysyx_24070003_OP_ADD;
            `ysyx_24070003_SLLI_FUNCT3: aluOp = `ysyx_24070003_OP_SLL;
            `ysyx_24070003_SLTI_FUNCT3: aluOp = `ysyx_24070003_OP_BLT;
            `ysyx_24070003_SLTIU_FUNCT3: aluOp = `ysyx_24070003_OP_BLT;
            `ysyx_24070003_XORI_FUNCT3: aluOp = `ysyx_24070003_OP_XOR;
            `ysyx_24070003_SRLI_SRAI_FUNCT3: begin if(funct7[5]) aluOp = `ysyx_24070003_OP_SRA;else aluOp = `ysyx_24070003_OP_SRL; end
            `ysyx_24070003_ORI_FUNCT3: aluOp = `ysyx_24070003_OP_OR;
            `ysyx_24070003_ANDI_FUNCT3: aluOp = `ysyx_24070003_OP_AND;
            default: aluOp = funct7[4:1];
        endcase
        end
        default: aluOp = `ysyx_24070003_OP_ADD;
      endcase
    end
    /*
    always @(*) begin
    $display("Value of signal alu_op is %02b", alu_op);
    $display("Value of signal funct3 is %03b", funct3);
    $display("Value of signal funct7 is %07b", funct7);
    $display("Value of signal aluOp is %07b", aluOp);
    end
    */
endmodule

module ysyx_24070003_exu(
    input clock,
    input rstn,
    //input IDU_EXU_STALL,
    output      reg       EXU_IDU_ready,          // 从执行单元(EXU)到IDU的就绪信号
    input               IDU_EXU_valid,          // IDU到EXU的有效信号
    input       LSU_EXU_ready,
    output      reg EXU_LSU_valid,
    input IDU_EXU_ren,
    //input IDU_EXU_wen,
    input IDU_EXU_reg,
    input IDU_EXU_ebreak,
    input IDU_EXU_jal,
    input IDU_EXU_jalr,
    // input IDU_EXU_lw,
    // input IDU_EXU_lh,
    // input IDU_EXU_lb,
    // input IDU_EXU_lbu,
    // input IDU_EXU_lhu,
    // input IDU_EXU_sw,
    // input IDU_EXU_sb,
    // input IDU_EXU_sh,
    input [8:0] IDU_EXU_RW_sign,
    input [2:0] csr_op,
    input [31:0] csr_data,
    input [31:0] IDU_EXU_pre_dnpc,

    input IDU_EXU_exu_raw_rs1,
    input IDU_EXU_exu_raw_rs2,
    input IDU_EXU_lsu_raw_rs1,
    input IDU_EXU_lsu_raw_rs2,
    input [31:0] LSU_forward_data,

    input IDU_EXU_ecall,
    input IDU_EXU_mret,
    input IDU_EXU_C_type,
    input IDU_EXU_B_type,
    input [2:0] IDU_EXU_csr_rst,
    
    input [31:0] rs1_data,
    input [31:0] rs2_data,
    input [31:0] imm_data,
    input [31:0] pc_data,
    input [1:0] alu_src1,
    input [1:0] alu_src2,
    input branch,
    input u_alu_type,
    //input mul_high,
    //input U_type_1,
    //input J_type_1,
    
    output  reg[31:0] EXU_LSU_alu_out,
    //output  EXU_IFU_zero,
    input [3:0]  alu_op,
    input [4:0] IDU_EXU_rd,
    output reg [4:0] EXU_LSU_rd,
    output reg EXU_LSU_ren,
    //output reg EXU_LSU_wen,
    output reg EXU_LSU_reg,
    output reg EXU_LSU_ebreak,
    //output reg EXU_IFU_jal,
    //output reg EXU_IFU_jalr,
    // output reg EXU_LSU_lw,
    // output reg EXU_LSU_lh,
    // output reg EXU_LSU_lb,
    // output reg EXU_LSU_lbu,
    // output reg EXU_LSU_lhu,
    // output reg EXU_LSU_sw,
    // output reg EXU_LSU_sb,
    // output reg EXU_LSU_sh,
    output reg [8:0]  EXU_LSU_RW_sign,
    output reg [31:0] EXU_LSU_csr_data,
    output reg [31:0] EXU_LSU_csr_in,
    output     [31:0] EXU_IFU_pc,
    output reg EXU_LSU_ecall,
    output reg EXU_LSU_mret,
    output reg EXU_LSU_C_type,
    output reg [2:0] EXU_LSU_csr_rst,
   // output reg EXU_IFU_STALL_done,
    output     EXU_flush,
    output reg [31:0] EXU_LSU_RS2DATA,
    output reg [31:0] EXU_LSU_PC,
    output reg [31:0] EXU_LSU_dnpc,
    //output reg [31:0] EXU_LSU_IMM,

    output [4:0]  EXU_IDU_REG_ADDR,
    output        EXU_IDU_REG_WEN,
    output        EXU_IDU_REN,

    output [31:0] EXU_BTB_PC,
    output        EXU_BTB_updata_valid
    
);
wire [31:0] RS1_data;
wire [31:0] RS2_data;
assign EXU_IDU_REG_ADDR = IDU_EXU_rd;
assign EXU_IDU_REG_WEN = IDU_EXU_reg && IDU_EXU_valid && EXU_IDU_ready;
assign EXU_IDU_REN = IDU_EXU_ren && IDU_EXU_valid && EXU_IDU_ready;
//wire [3:0]aluop;
wire zero;
wire [31:0] alu_out;
wire [31:0] csr_in;

//assign RS1_data = (IDU_EXU_exu_raw_rs1) ? EXU_LSU_alu_out : (IDU_EXU_lsu_raw_rs1) ? LSU_forward_data : rs1_data;
ysyx_24070003_mux4_32bit my(
    .sel            ({IDU_EXU_exu_raw_rs1,IDU_EXU_lsu_raw_rs1}),
    .a              (rs1_data), 
    .b              (LSU_forward_data),
    .c              (EXU_LSU_alu_out),
    .d              (EXU_LSU_alu_out),
    .out            (RS1_data)
);
//MuxKeyInternal #(2, 2, 32, 1) i0 (RS1_data, {IDU_EXU_exu_raw_rs1,IDU_EXU_lsu_raw_rs1}, EXU_LSU_alu_out, {2'b00,rs1_data,2'b01,LSU_forward_data});
//assign RS2_data = (IDU_EXU_exu_raw_rs2) ? EXU_LSU_alu_out : (IDU_EXU_lsu_raw_rs2) ? LSU_forward_data : rs2_data;
ysyx_24070003_mux4_32bit my1(
    .sel            ({IDU_EXU_exu_raw_rs2,IDU_EXU_lsu_raw_rs2}),
    .a              (rs2_data), 
    .b              (LSU_forward_data),
    .c              (EXU_LSU_alu_out),
    .d              (EXU_LSU_alu_out),
    .out            (RS2_data)
);
// assign csr_in = ( {32{IDU_EXU_csw}} & (RS1_data)) |
//                 ( {32{IDU_EXU_csc}} & (RS1_data &csr_data)) |
//                 ( {32{IDU_EXU_css}} & (csr_data | RS1_data)) ;

//wire [2:0] csr_op = {IDU_EXU_csw, IDU_EXU_csc, IDU_EXU_css};

assign  csr_in =     (csr_op == 3'b100) ? RS1_data        :
                     (csr_op == 3'b010) ? RS1_data & csr_data :
                     (csr_op == 3'b001) ? RS1_data | csr_data :
                                        32'h0;   // 无效，理论上不会出现
wire [31:0] opdata1;
wire [31:0] opdata2;
//assign opdata1 = (alu_src1 == 2'b10)? RS1_data : (alu_src1 == 2'b01) ? 32'h00000000 : pc_data;
ysyx_24070003_mux4_32bit my3(
    .sel            (alu_src1),
    .a              (pc_data), 
    .b              (32'h00000000),
    .c              (RS1_data),
    .d              (pc_data),
    .out            (opdata1)
);
//assign opdata2 = (alu_src2 == 2'b10)? RS2_data : (alu_src2 == 2'b01) ? 32'h00000004 : imm_data;
ysyx_24070003_mux4_32bit my4(
    .sel            (alu_src2),
    .a              (imm_data), 
    .b              (32'h00000004),
    .c              (RS2_data),
    .d              (imm_data),
    .out            (opdata2)
);

ysyx_24070003_alu my_alu(
    .clock          (clock      ),
    .opdata1        (opdata1   ),
    .opdata2        (opdata2   ),
    .branch         (branch     ), 
    .u_alu_type     (u_alu_type ),
    .alu_crtl       (alu_op      ),
    .alu_out        (alu_out    ),
    .zero           (zero       )
);
wire [3:0] pc_sel = {IDU_EXU_jal || IDU_EXU_B_type, IDU_EXU_ecall || IDU_EXU_mret, IDU_EXU_jal || zero, IDU_EXU_jalr};
wire [31:0] pc_opdata1;
wire [31:0] pc_opdata2;

assign pc_opdata1 = (pc_sel[1] || pc_sel[3]) ? pc_data : RS1_data;
assign pc_opdata2 = imm_data;
wire [31:0] next_pc = pc_opdata1 + pc_opdata2;
wire btb_pre_error = (IDU_EXU_pre_dnpc != EXU_IFU_pc) && (IDU_EXU_jal || IDU_EXU_B_type);
assign EXU_flush = (IDU_EXU_ecall || IDU_EXU_mret || IDU_EXU_jalr || btb_pre_error) && (IDU_EXU_valid && EXU_IDU_ready);

assign EXU_IDU_ready = LSU_EXU_ready;  

///assign EXU_BTB_PC = (pc_sel[3]) ? next_pc_jal : next_pc_jalr;
assign EXU_BTB_PC = next_pc;
assign EXU_BTB_updata_valid = (IDU_EXU_jal || IDU_EXU_B_type) && (IDU_EXU_valid && EXU_IDU_ready);

always @(posedge clock) begin 
    if(rstn) begin
        EXU_LSU_valid <= 1'b0;
    end
    else if(EXU_IDU_ready & IDU_EXU_valid) begin
        EXU_LSU_valid <= 1'b1;
    end
    else if(LSU_EXU_ready && EXU_LSU_valid)begin
        EXU_LSU_valid <= 1'b0;
    end
end

// wire [31:0] next_pc_jal = pc_data + imm_data;
// wire [31:0] next_pc_jalr = RS1_data + imm_data;


assign EXU_IFU_pc =
            (pc_sel[2]) ? csr_data      :
            (pc_sel[1] || pc_sel[0]) ? next_pc   :
                                  pc_data + 32'd4;



always@(posedge clock)
begin 
   if(rstn)begin
    //EXU_IFU_zero              <=        1'b0;
    EXU_LSU_alu_out           <=        32'b0;
    EXU_LSU_rd                <=        5'b0;
    EXU_LSU_ren               <=        1'b0;
    //EXU_LSU_wen               <=        1'b0;
    //EXU_LSU_reg               <=        1'b0;
    EXU_LSU_ebreak               <=        1'b0;
    //EXU_IFU_jal               <=        1'b0;
    //EXU_IFU_jalr               <=        1'b0;
    // EXU_LSU_lw               <=        1'b0;
    // EXU_LSU_lh               <=        1'b0;
    // EXU_LSU_lb               <=        1'b0;
    // EXU_LSU_lbu               <=        1'b0;
    // EXU_LSU_lhu               <=        1'b0;
    // EXU_LSU_sw               <=        1'b0;
    // EXU_LSU_sb               <=        1'b0;
    // EXU_LSU_sh               <=        1'b0;
    EXU_LSU_RW_sign            <=        8'b0;
    EXU_LSU_csr_data           <=        32'b0;
    EXU_LSU_ecall               <=        1'b0;
    EXU_LSU_mret               <=        1'b0;
    EXU_LSU_C_type               <=        1'b0;
    EXU_LSU_csr_rst               <=        3'b0;
    EXU_LSU_csr_in               <=        32'b0;
    //EXU_IFU_pc               <=        32'b0;
    EXU_LSU_RS2DATA           <=        32'b0;
    EXU_LSU_PC               <=        32'b0;
    EXU_LSU_dnpc               <=        32'b0;
    //EXU_LSU_IMM              <=          32'b0;
    end
    else if(IDU_EXU_valid & EXU_IDU_ready)begin
    EXU_LSU_alu_out           <=        alu_out;
    //EXU_IFU_zero              <=        zero;
    EXU_LSU_rd                <=        IDU_EXU_rd;
    EXU_LSU_ren               <=        IDU_EXU_ren;
    //EXU_LSU_wen               <=        IDU_EXU_wen;
    EXU_LSU_reg               <=        IDU_EXU_reg;
    EXU_LSU_ebreak               <=        IDU_EXU_ebreak;
    EXU_LSU_RW_sign             <=      IDU_EXU_RW_sign;
    //EXU_IFU_jal               <=        IDU_EXU_jal;
    //EXU_IFU_jalr               <=        IDU_EXU_jalr;
    // EXU_LSU_lw               <=        IDU_EXU_lw;
    // EXU_LSU_lh               <=        IDU_EXU_lh;
    // EXU_LSU_lb               <=        IDU_EXU_lb;
    // EXU_LSU_lbu               <=        IDU_EXU_lbu;
    // EXU_LSU_lhu               <=        IDU_EXU_lhu;
    // EXU_LSU_sw               <=        IDU_EXU_sw;
    // EXU_LSU_sb               <=        IDU_EXU_sb;
    // EXU_LSU_sh               <=        IDU_EXU_sh;
    EXU_LSU_csr_data           <=        csr_data;
    EXU_LSU_ecall               <=        IDU_EXU_ecall;
    EXU_LSU_mret               <=        IDU_EXU_mret;
    EXU_LSU_C_type               <=        IDU_EXU_C_type;
    EXU_LSU_csr_rst               <=        IDU_EXU_csr_rst;
    EXU_LSU_csr_in               <=        csr_in;
    //EXU_IFU_pc               <=        pc_jump;
    EXU_LSU_RS2DATA           <=        RS2_data;
    EXU_LSU_PC               <=        pc_data;
    EXU_LSU_dnpc               <=        EXU_IFU_pc;
    //EXU_LSU_IMM                <=      imm_data;
    end
    else begin
    //EXU_IFU_zero              <=        1'b0;
    EXU_LSU_alu_out           <=        EXU_LSU_alu_out;
    EXU_LSU_rd                <=        EXU_LSU_rd;
    EXU_LSU_ren               <=        EXU_LSU_ren;
    //EXU_LSU_wen               <=        EXU_LSU_wen;
    //EXU_LSU_reg               <=        1'b0;
    EXU_LSU_ebreak               <=        EXU_LSU_ebreak;
    //EXU_IFU_jal               <=        1'b0;
    //EXU_IFU_jalr               <=        1'b0;
    // EXU_LSU_lw               <=        EXU_LSU_lw;
    // EXU_LSU_lh               <=        EXU_LSU_lh;
    // EXU_LSU_lb               <=        EXU_LSU_lb;
    // EXU_LSU_lbu               <=        EXU_LSU_lbu;
    // EXU_LSU_lhu               <=        EXU_LSU_lhu;
    // EXU_LSU_sw               <=        EXU_LSU_sw;
    // EXU_LSU_sb               <=        EXU_LSU_sb;
    // EXU_LSU_sh               <=        EXU_LSU_sh;
    EXU_LSU_RW_sign            <=       EXU_LSU_RW_sign;
    EXU_LSU_csr_data           <=        EXU_LSU_csr_data;
    EXU_LSU_ecall               <=        EXU_LSU_ecall;
    EXU_LSU_mret               <=        EXU_LSU_mret;
    EXU_LSU_C_type               <=        EXU_LSU_C_type;
    EXU_LSU_csr_rst               <=        EXU_LSU_csr_rst;
    EXU_LSU_csr_in               <=        EXU_LSU_csr_in;
    //EXU_IFU_pc               <=        32'b0;
    EXU_LSU_RS2DATA           <=        EXU_LSU_RS2DATA;
    EXU_LSU_PC               <=        EXU_LSU_PC;
    EXU_LSU_dnpc               <=        EXU_LSU_dnpc;
    //EXU_LSU_IMM              <=         EXU_LSU_IMM;
end
end
endmodule

module ysyx_24070003_alu(
    input clock,
    input [31:0] opdata1,
    input [31:0] opdata2,
    input branch,
    input u_alu_type,
    input [3:0] alu_crtl,
    output reg [31:0] alu_out,
    output  zero
);


wire [1:0] logic_ctl;
wire [1:0] shift_ctl;
wire       sub_ctl;
wire [1:0] data_choice;

wire ADD_zero;

assign logic_ctl = alu_crtl[1:0];
assign shift_ctl = alu_crtl[1:0];
assign data_choice = alu_crtl[3:2];
assign sub_ctl = (~ alu_crtl[3]  & ~alu_crtl[2]  & alu_crtl[1]) | ( alu_crtl[3]  & ~alu_crtl[2]);
//*********************logic op***************************
reg [31:0] logic_result;

always@(*) begin
    case(logic_ctl)
	2'b00:logic_result = opdata1 & opdata2;
	2'b01:logic_result = opdata1 | opdata2;
	2'b10:logic_result = opdata1 ^ opdata2;
    2'b11:logic_result = opdata1 | opdata2;
	endcase
end 
//************************shift op************************
wire [5:0]     ALU_SHIFT;
wire [31:0] shift_result;
assign ALU_SHIFT=opdata2[5:0];

ysyx_24070003_Shifter myShifter(.ALU_DA(opdata1),
                .ALU_SHIFT(ALU_SHIFT),
				.Shiftctr(shift_ctl),
				.shift_result(shift_result));

//************************add sub op**********************
wire [31:0] BIT_M,XOR_M;
wire ADD_carry,ADD_OverFlow;
wire [31:0] ADD_result;

assign BIT_M={32{sub_ctl}};
assign XOR_M=BIT_M^opdata2;

ysyx_24070003_Adder Adder(.A(opdata1),
            .B(XOR_M),
			.Cin(sub_ctl),
			.ALU_CTL(alu_crtl),
			.ADD_carry(ADD_carry),
			//.ADD_OverFlow(ADD_OverFlow),
			.ADD_zero(ADD_zero),
			.ADD_result(ADD_result));



//********************************************************
//**************************slt op************************
wire [31:0] SLT_result;
wire LESS_M1,LESS_M2,LESS_S,SLT_M;
wire BLT,BGE,BNE,BEQ;
//assign ADD_OverFlow = (opdata1[31] & ~opdata2[31]) | ((opdata1[31] ~^ opdata2[31]) & ADD_result[31]); 
assign BLT = (alu_crtl[3]  & ~alu_crtl[2]  &  ~alu_crtl[1]  & ~alu_crtl[0]);
assign BGE = (alu_crtl[3]  & ~alu_crtl[2]  &  ~alu_crtl[1]  &  alu_crtl[0]);
assign BNE = (alu_crtl[3]  & ~alu_crtl[2]  &   alu_crtl[1]  & ~alu_crtl[0]);
assign BEQ = (alu_crtl[3]  & ~alu_crtl[2]  &   alu_crtl[1]  &  alu_crtl[0]);
assign zero = (BLT &  branch  &  LESS_S)   |
              (BGE & ~LESS_S)   |
              (BNE & ~ADD_zero) |
              (BEQ &  ADD_zero) ;

assign LESS_M1 = ADD_carry ^ sub_ctl;
assign LESS_M2 = (opdata1[31] & ~opdata2[31]) | ((opdata1[31] ~^ opdata2[31]) & ADD_result[31]);
assign LESS_S = (u_alu_type)?LESS_M1:LESS_M2;
assign SLT_result = (LESS_S)?32'h00000001:32'h00000000;
//708,687,567
always @(*) 
begin
  case(data_choice)
     2'b00:alu_out=ADD_result;
     2'b01:alu_out=logic_result;
     2'b10:alu_out=SLT_result;
     2'b11:alu_out=shift_result; 
  endcase
end

endmodule

module ysyx_24070003_Shifter(input [31:0] ALU_DA,
               input [5:0] ALU_SHIFT,
			   input [1:0] Shiftctr,
			   output reg [31:0] shift_result);
			
     wire [63:0] tmp_res;
     always@(*) begin
	   case(Shiftctr)
	   2'b00:shift_result = ALU_DA << ALU_SHIFT[4:0];
	   2'b01:shift_result = ALU_DA >> ALU_SHIFT[4:0];
	   2'b10:shift_result = tmp_res[31:0];
	   default:shift_result = ALU_DA;
	   endcase
	 end
assign tmp_res = {{{32{ALU_DA[31]}}, ALU_DA} >> ALU_SHIFT};

endmodule

//*************************************************************
//***********************************adder*********************


module ysyx_24070003_Adder(input [31:0] A,
             input [31:0] B,
			 input Cin,
			 input [3:0] ALU_CTL,
			 output ADD_carry,
			 //output ADD_OverFlow,
			 output ADD_zero,
			 output [31:0] ADD_result);


    assign {ADD_carry,ADD_result}=A+B+Cin;


   assign ADD_zero = ~(|ADD_result);
//    assign ADD_OverFlow=((~Cin) & ~A[31] & ~B[31] & ADD_result[31]) 
//                       | ((~Cin) & A[31] & B[31] & ~ADD_result[31])
//                       | ((Cin) & A[31] & ~B[31] & ~ADD_result[31]) 
// 					  | ((Cin) & ~A[31] & B[31] & ADD_result[31]);
     
endmodule

module ysyx_24070003_lsu(
    input           clock,
    input           rst_n,
   // input           EXU_LSU_JUMP,
    //output        reg  LSU_WBU_JUMP,
    //input  [31:0]   EXU_IFU_pc,
    //output reg [31:0]   LSU_WBU_pc,

    input           EXU_LSU_valid,
    output           LSU_EXU_ready,
    output     reg      LSU_WBU_valid,
    input           LSU_WBU_ready,
    input       [8:0] EXU_LSU_RW_sign,
    // input           EXU_LSU_lw,
    // input           EXU_LSU_lh,
    // input           EXU_LSU_lb,
    // input           EXU_LSU_lbu,
    // input           EXU_LSU_lhu,
    // input           EXU_LSU_sw,
    // input           EXU_LSU_sb,
    // input           EXU_LSU_sh,
    input      [31:0] EXU_LSU_PC,
    input      [31:0] EXU_LSU_dnpc,
    input      [31:0] EXU_LSU_csr_data,
    input      [31:0] EXU_LSU_csr_in,
    input           EXU_LSU_ecall,
    input           EXU_LSU_mret,
    input           EXU_LSU_C_type,
    input      [2:0] EXU_LSU_csr_rst,

    input           EXU_LSU_ren,
    //input           EXU_LSU_wen,
//input           IDU_EXU_ren,
    //input           IDU_EXU_wen,
    
    input           EXU_LSU_reg,
    input           EXU_LSU_ebreak,
    input      [31:0] EXU_LSU_result,
    output      [31:0] LSU_WBU_DATA,
    output   reg[31:0] LSU_WBU_PC,
    input    [4:0]  EXU_LSU_rd,
    //input    [31:0] alu_result,
    input    [31:0] rs2_data,
    output   reg    LSU_WBU_reg,
    output   reg    LSU_WBU_ebreak,
    //output   [31:0] rdata,
    output   reg [4:0]  LSU_WBU_rd,
    //output   reg [31:0] LSU_WBU_csr_data,
    output   reg [31:0] LSU_WBU_csr_in,
    output   reg    LSU_WBU_ecall,
    output   reg    LSU_WBU_mret,
    output   reg    LSU_WBU_C_type,
    output   reg [2:0] LSU_WBU_csr_rst,
    output   reg [31:0] LSU_WBU_dnpc,
    output   reg LSU_WBU_skip,
    //output   [3:0]  LSU_WLEN,
   // output    [31:0] LSU_WDATA,
    //input    [31:0] LSU_RDATA,

    output      LSU_IFU_stall,

    output reg [32-1:0] LSU_AXI4_ARADDR,
    output reg                  LSU_AXI4_ARVALID,
    input                       LSU_AXI4_ARREADY,
    
    // 读数据通道
    input  [32-1:0]     LSU_AXI4_RDATA,
    input                       LSU_AXI4_RVALID,
    output reg                  LSU_AXI4_RREADY,
    
    // 写地址通道
    output reg [32-1:0] LSU_AXI4_AWADDR,
    output reg                  LSU_AXI4_AWVALID,
    input                       LSU_AXI4_AWREADY,
    
    // 写数据通道
    output reg [32-1:0] LSU_AXI4_WDATA,
    output reg [3:0]            LSU_AXI4_WSTRB,
    output reg                  LSU_AXI4_WVALID,
    input                       LSU_AXI4_WREADY,
    
    // 写响应通道
    input                       LSU_AXI4_BVALID,
    output reg                  LSU_AXI4_BREADY,
    output reg                  LSU_AXI_wlast,
    output reg [2:0]            LSU_AXI4_wsize,
    // output reg [63:0]           lsu_count,
    // output reg [63:0]           lsu_during_count,
    // output reg [63:0]           lsu_load_count,
    // output reg [63:0]           lsu_store_count,
    output reg [2:0]            LSU_AXI4_ARSIZE,


    output     [31:0]           LSU_forward_data,
    output [4:0]            LSU_IDU_REG_ADDR,
    output                  LSU_IDU_REG_WEN
    //output                  LSU_IDU_REN
      //input  [1:0]                LSU_AXI4_BRESP
);

assign LSU_IDU_REG_ADDR = EXU_LSU_rd;
assign LSU_IDU_REG_WEN = EXU_LSU_reg && LSU_EXU_ready && EXU_LSU_valid;
//assign LSU_IDU_REN   = EXU_LSU_ren && LSU_EXU_ready && EXU_LSU_valid;
assign LSU_forward_data = LSU_WBU_DATA;
wire EXU_LSU_wen,EXU_LSU_lh,EXU_LSU_lw,EXU_LSU_lb,EXU_LSU_lbu,EXU_LSU_lhu,EXU_LSU_sw,EXU_LSU_sb,EXU_LSU_sh;
assign {EXU_LSU_wen,EXU_LSU_lh,EXU_LSU_lw,EXU_LSU_lb,EXU_LSU_lbu,EXU_LSU_lhu,EXU_LSU_sw,EXU_LSU_sb,EXU_LSU_sh} = EXU_LSU_RW_sign;
parameter  IDLE = 0,
            START = 1,
            READ_START = 2,
            WRITE_WIRE_1 = 3,
            WRITE_WIRE_2 = 4,
            WRITE_DATA = 5;
reg [2:0] state;

    //reg [63:0] lsu_count;
    reg LSU_REN;
    //wire [3:0]  wlen;
    //wire [31:0] addr;
    //wire [31:0] wdata;
    //reg  [31:0]rdata_in,rdata;
    wire [3:0] LSU_WLEN;
    wire [31:0] rdata;
    reg [31:0] LSU_RDATA,LSU_WDATA;
    wire [3:0] lsu_wstrb;
    wire [31:0] lsu_wdata;
    wire [31:0] lsu_rdata;
    wire [2:0] lsu_arsize;
    reg skip;
    wire skip1 = (((EXU_LSU_result >= 32'h10000000) && (EXU_LSU_result < 32'h30000000)) && (EXU_LSU_ren || EXU_LSU_wen)) ? 1'b1 : 1'b0;
    wire skip2 = (((EXU_LSU_result >= 32'h02000000) && (EXU_LSU_result < 32'h0200ffff)) && (EXU_LSU_ren || EXU_LSU_wen)) ? 1'b1 : 1'b0;
    wire EXU_skip = skip1 | skip2;
    assign LSU_WDATA = ( {32{EXU_LSU_sb}} & {24'b0,rs2_data[7:0]}) |
                   ( {32{EXU_LSU_sh}} & {16'b0,rs2_data[15:0]}) |
                   ( {32{EXU_LSU_sw}} & rs2_data);

    // assign lsu_rdata = (LSU_AXI4_ARADDR[1:0]  == 2'b00) ? (LSU_RDATA >> 32'd0) :
    //                    (LSU_AXI4_ARADDR[1:0]  == 2'b01) ? (LSU_RDATA >> 32'd8) :
    //                    (LSU_AXI4_ARADDR[1:0]  == 2'b10) ? (LSU_RDATA >> 32'd16) :
    //                    (LSU_AXI4_ARADDR[1:0]  == 2'b11) ? (LSU_RDATA >> 32'd24) : (LSU_RDATA >> 32'd0);

 ysyx_24070003_mux4_32bit my6(
    .sel            (LSU_AXI4_ARADDR[1:0]),
    .a              (LSU_RDATA >> 32'd0), 
    .b              (LSU_RDATA >> 32'd8),
    .c              (LSU_RDATA >> 32'd16),
    .d              (LSU_RDATA >> 32'd24),
    .out            (lsu_rdata)
);

    //assign lsu_rdata = (LSU_RDATA >> (LSU_AXI4_ARADDR[1:0] << 3));

    reg LSU_WBU_lb,LSU_WBU_lh,LSU_WBU_lw,LSU_WBU_lbu,LSU_WBU_lhu;
always @(posedge clock) begin
    if(rst_n)begin
        LSU_WBU_lb <= 1'b0;
        LSU_WBU_lh <= 1'b0;
        LSU_WBU_lw <= 1'b0;
        LSU_WBU_lbu <= 1'b0;
        LSU_WBU_lhu <= 1'b0;
    end else if((LSU_EXU_ready && EXU_LSU_valid) ) begin
        LSU_WBU_lb <= EXU_LSU_lb;
        LSU_WBU_lh <= EXU_LSU_lh;
        LSU_WBU_lw <= EXU_LSU_lw;
        LSU_WBU_lbu <= EXU_LSU_lbu;
        LSU_WBU_lhu <= EXU_LSU_lhu;

    end 
end

    assign rdata = ( {32{LSU_WBU_lb}} & {{24{lsu_rdata[7]}},lsu_rdata[7:0]}) |
                   ( {32{LSU_WBU_lh}} & {{16{lsu_rdata[15]}}, (lsu_rdata[15:0])}) |
                   ( {32{LSU_WBU_lw}} & lsu_rdata) |
                   ( {32{LSU_WBU_lbu}} & {24'b0,lsu_rdata[7:0]}) |
                   ( {32{LSU_WBU_lhu}} & {16'b0,lsu_rdata[15:0]});

    assign  LSU_WLEN = ( {4{EXU_LSU_sb}} & 4'b1 )  |
                   ( {4{EXU_LSU_sh}} & 4'b11 )  |
                   ( {4{EXU_LSU_sw}} & 4'b1111 ) ;
    wire [2:0] awsize;

    assign  awsize = ( {3{EXU_LSU_sb}} & 3'b0 )  |
                   ( {3{EXU_LSU_sh}} & 3'b01 )  |
                   ( {3{EXU_LSU_sw}} & 3'b10 ) ;
    
    
    assign lsu_arsize = ( {3{LSU_WBU_lb}} & 3'b0) |
                   ( {3{LSU_WBU_lh}} & 3'b01) |
                   ( {3{LSU_WBU_lw}} & 3'b10) |
                   ( {3{LSU_WBU_lbu}} & 3'b0) |
                   ( {3{LSU_WBU_lhu}} & 3'b01);
                   
    // wire is_sdram = ((LSU_AXI4_ARADDR >= 32'ha0000000) && (LSU_AXI4_ARADDR < 32'hc0000000));
    // assign lsu_arsize = (is_sdram) ? arsize : 3'b00;
    // always @(posedge clk) begin
    //     if(EXU_LSU_wen) begin
    //     $write("lsu_wstrb = %04b,EXU_LSU_result = %08x\n",lsu_wstrb,EXU_LSU_result);
    //     end
    // end
    // assign lsu_wstrb = (EXU_LSU_result[1:0]  == 2'b00) ? (LSU_WLEN << 2'd0) :
    //                    (EXU_LSU_result[1:0]  == 2'b01) ? (LSU_WLEN << 2'd1) :
    //                    (EXU_LSU_result[1:0]  == 2'b10) ? (LSU_WLEN << 2'd2) :
    //                    (EXU_LSU_result[1:0]  == 2'b11) ? (LSU_WLEN << 2'd3) : (LSU_WLEN << 2'd0);

ysyx_24070003_mux4_32bit my7(
    .sel            (EXU_LSU_result[1:0]),
    .a              (LSU_WLEN << 32'd0), 
    .b              (LSU_WLEN << 32'd1),
    .c              (LSU_WLEN << 32'd2),
    .d              (LSU_WLEN << 32'd3),
    .out            (lsu_wstrb)
);

    //assign lsu_wstrb = (LSU_WLEN << EXU_LSU_result[1:0] );
    // assign lsu_wdata = (EXU_LSU_result[1:0]  == 2'b00) ? (LSU_WDATA << 32'd0) :
    //                    (EXU_LSU_result[1:0]  == 2'b01) ? (LSU_WDATA << 32'd8) :
    //                    (EXU_LSU_result[1:0]  == 2'b10) ? (LSU_WDATA << 32'd16) :
    //                    (EXU_LSU_result[1:0]  == 2'b11) ? (LSU_WDATA << 32'd24) : (LSU_WDATA << 32'd0);

ysyx_24070003_mux4_32bit my8(
    .sel            (EXU_LSU_result[1:0]),
    .a              (LSU_WDATA << 32'd0), 
    .b              (LSU_WDATA << 32'd8),
    .c              (LSU_WDATA << 32'd16),
    .d              (LSU_WDATA << 32'd24),
    .out            (lsu_wdata)
);

    //assign lsu_wdata = (LSU_WDATA << (EXU_LSU_result[1:0] << 3));
    //wire [31:0] LSU_WBU_DATA;
    reg [31:0] LSU_WBU_result;
    assign LSU_WBU_DATA = (LSU_REN) ? rdata : LSU_WBU_result;


    //assign addr = alu_result;


assign LSU_IFU_stall = (state != IDLE);



always @(posedge clock) begin
    if (rst_n) begin
        state <= IDLE;
        
        // AXI 信号复位
        LSU_AXI4_ARVALID <= 1'b0;
        LSU_AXI4_RREADY <= 1'b0;
        LSU_AXI4_AWVALID <= 1'b0;
        LSU_AXI4_WVALID <= 1'b0;
        LSU_AXI4_BREADY <= 1'b0;

        LSU_WBU_valid <= 1'b0;

        LSU_AXI_wlast <= 1'b0;
        // lsu_count <=  64'd0;
        // lsu_during_count <= 64'd0;
        // lsu_load_count <= 64'd0;
        // lsu_store_count <= 64'd0;
        LSU_AXI4_ARSIZE <= 3'b0;
    end
    else begin
        case (state)
            IDLE: begin
                LSU_AXI_wlast <= 1'b0;
                
                if((!(EXU_LSU_ren || EXU_LSU_wen))) begin
                    state <= IDLE;
                end else if (EXU_LSU_wen && LSU_EXU_ready && EXU_LSU_valid ) begin
                    LSU_AXI4_AWADDR <= EXU_LSU_result;
                    LSU_AXI4_WDATA <= lsu_wdata;
                    LSU_AXI4_WSTRB <= lsu_wstrb;
                    LSU_AXI4_AWVALID <= 1'b1;
                    LSU_AXI4_WVALID <= 1'b1;
                    LSU_AXI_wlast <= 1'b1; 
                    LSU_AXI4_wsize <= awsize;
                    state <= START;
                end else if ((EXU_LSU_ren && LSU_EXU_ready && EXU_LSU_valid)) begin
                    LSU_AXI4_ARADDR <= EXU_LSU_result;
                    LSU_AXI4_ARSIZE <= lsu_arsize;
                    LSU_AXI4_ARVALID <= 1'b1;
                    state <= START;
                end
            end
                    
            
            START: begin
                if(LSU_AXI4_AWVALID && LSU_AXI4_AWREADY && LSU_AXI4_WVALID && LSU_AXI4_WREADY) begin
                            // lsu_during_count <= lsu_during_count + 1'b1;
                            // lsu_store_count <= lsu_store_count + 1'b1;
                            // lsu_count <= lsu_count + 1'b1;
                            LSU_AXI_wlast <= 1'b1;
                            LSU_AXI4_BREADY <= 1'b1;
                            state <= WRITE_DATA;
                            LSU_AXI4_AWVALID <= 1'b0;
                            LSU_AXI4_WVALID <= 1'b0;
                end else if(LSU_AXI4_AWVALID && LSU_AXI4_AWREADY ) begin
                            LSU_AXI_wlast <= 1'b1;
                            state <= WRITE_WIRE_1;
                            LSU_AXI4_AWVALID <= 1'b0;
                end else if(LSU_AXI4_WVALID && LSU_AXI4_WREADY ) begin
                            LSU_AXI_wlast <= 1'b1;
                            state <= WRITE_WIRE_2;
                            LSU_AXI4_WVALID <= 1'b0;
                end else if(LSU_AXI4_ARVALID && LSU_AXI4_ARREADY) begin
                            // lsu_load_count <= lsu_load_count + 1'b1;
                            // lsu_during_count <= lsu_during_count + 1'b1;
                            LSU_AXI4_RREADY <= 1'b1;
                            state <= READ_START;
                            LSU_AXI4_ARVALID <= 1'b0;
                end else 
                    state <= START;
            end
            
            // 读操作 ------------------------------------------------------
            READ_START: begin
                // 发送读地址
                
                if (LSU_AXI4_RREADY && LSU_AXI4_RVALID) begin
                    //lsu_count <= lsu_count + 1'b1;
                    LSU_AXI4_RREADY <= 1'b0;
                    LSU_RDATA <= LSU_AXI4_RDATA;
                    state <= IDLE;
                end
                else begin
                    //lsu_during_count <= lsu_during_count + 1'b1;
                    //lsu_load_count <= lsu_load_count + 1'b1;
                    state <= READ_START;
                end
            end
            
            // 写操作 ------------------------------------------------------
            WRITE_WIRE_1: begin
                // 发送写地址
                
                if(LSU_AXI4_WVALID && LSU_AXI4_WREADY ) begin
                    //lsu_count <= lsu_count + 1'b1;
                    LSU_AXI_wlast <= 1'b1;
                    state <= WRITE_WIRE_2;
                    LSU_AXI4_WVALID <= 1'b0;
                    LSU_AXI4_BREADY <= 1'b1;
                    state <= WRITE_DATA;
                end else begin
                    
                    state <= WRITE_WIRE_1;
                end
            end
            
            WRITE_WIRE_2: begin
                // 等待另一个握手完成
                if(LSU_AXI4_AWVALID && LSU_AXI4_AWREADY ) begin
                    state <= WRITE_WIRE_1;
                    LSU_AXI4_AWVALID <= 1'b0;
                    LSU_AXI4_BREADY <= 1'b1;
                    state <= WRITE_DATA;
                end else begin
                    state <= WRITE_WIRE_2;
                end
            end
            
            WRITE_DATA: begin   
                
                LSU_AXI_wlast <= 1'b0;
                if(LSU_AXI4_BVALID && LSU_AXI4_BREADY) begin
                    LSU_AXI4_BREADY <= 1'b0;
                    state <= IDLE;  
                end
                else begin
                    state <= WRITE_DATA;
                    //lsu_during_count <= lsu_during_count + 1'b1;
                    //lsu_store_count <= lsu_store_count + 1'b1;
                end
            end
            
            default: state <= IDLE;
        endcase
    end
end

always @(posedge clock) begin
    if(rst_n) begin
        LSU_WBU_valid <= 1'b0;
    end
    else if((LSU_AXI4_RREADY && LSU_AXI4_RVALID) || (LSU_AXI4_BVALID && LSU_AXI4_BREADY)) begin
        LSU_WBU_valid <= 1'b1;
    end
    else if((LSU_EXU_ready && EXU_LSU_valid) && (~(EXU_LSU_ren || EXU_LSU_wen))) begin
        LSU_WBU_valid <= 1'b1;
    end
    else begin
        LSU_WBU_valid <= 1'b0;
    end
end

//import "DPI-C" function void vpmem_read(input int raddr,input byte ren,output int rdata);
//import "DPI-C" function void vpmem_write(input int waddr, input byte wmask,input int wdata,input byte wen);
//reg [31:0] RDATAIN,WDATA;

always @(posedge clock) begin
    if(rst_n)begin
        //RDATAIN <= 32'b0;
        //WDATA   <= 32'b0;
        LSU_WBU_rd <= 5'b0;
        LSU_WBU_result <= 32'b0;
        LSU_WBU_reg <= 1'b0;
        LSU_WBU_ebreak <= 1'b0;
        //LSU_WBU_csr_data <= 32'b0;
        LSU_WBU_ecall <= 1'b0;
        LSU_WBU_mret <= 1'b0;
        LSU_WBU_C_type <= 1'b0;
        LSU_WBU_csr_rst <= 3'b0;
        LSU_WBU_csr_in <= 32'b0;
        //LSU_WBU_JUMP <= 1'b0;
        //LSU_WBU_pc <= 32'b0;
        LSU_REN      <= 1'b0;
        LSU_WBU_skip <= 1'b0;
        LSU_WBU_PC <= 32'b0;
        LSU_WBU_dnpc <= 32'b0;
    end else if((LSU_EXU_ready && EXU_LSU_valid) ) begin
        //RDATAIN <= rdata_in;
        //WDATA   <= wdata;
        LSU_WBU_result <= (EXU_LSU_C_type) ? EXU_LSU_csr_data : EXU_LSU_result;
        LSU_REN      <= EXU_LSU_ren;
        LSU_WBU_rd <= EXU_LSU_rd;
        LSU_WBU_reg<= EXU_LSU_reg;
        LSU_WBU_ebreak<= EXU_LSU_ebreak;
        //LSU_WBU_csr_data <= EXU_LSU_csr_data;
        LSU_WBU_ecall <= EXU_LSU_ecall;
        LSU_WBU_mret <= EXU_LSU_mret;
        LSU_WBU_C_type <= EXU_LSU_C_type;
        LSU_WBU_csr_rst <= EXU_LSU_csr_rst;
        LSU_WBU_csr_in <= EXU_LSU_csr_in;
        //LSU_WBU_JUMP <= EXU_LSU_JUMP;
        //LSU_WBU_pc <= EXU_IFU_pc;
        LSU_WBU_PC <= EXU_LSU_PC;
        LSU_WBU_dnpc <= EXU_LSU_dnpc;
        LSU_WBU_skip <= EXU_skip ;

    end 
end


assign LSU_EXU_ready = ((state == IDLE) && LSU_WBU_ready);
/*
sram_data data_sram(
    .CLK(clk),
    .wen(EXU_LSU_wen),
    .ren(EXU_LSU_ren),
    .wlen(wlen),
    .addr(addr),
    .data(wdata),
    .Q(rdata_in)
);
*/

endmodule

module ysyx_24070003_wbu(
    input clock,
    input rst_n,
    //input LSU_WBU_JUMP,
    //output reg WBU_IFU_JUMP,
    input [31:0] LSU_WBU_PC,
    input [31:0] LSU_WBU_dnpc,
    input        LSU_WBU_skip,
   // output reg [31:0] WBU_IFU_pc,

    input LSU_WBU_valid,
    output LSU_WBU_ready,
    input LSU_WBU_reg,
    //input [31:0] LSU_WBU_csr_data,
    input [31:0] LSU_WBU_csr_in,
    input [2:0]  LSU_WBU_csr_rst,
    input LSU_WBU_ecall,
    input LSU_WBU_mret,
    input LSU_WBU_C_type,
 //   input LSU_WBU_jal,
   // input LSU_WBU_jalr,
    //input [31:0]data_in,
    input [31:0] LSU_WBU_result,
    input [4:0] addr,
    output  [31:0]WBU_REG_DATA,
    output  [4:0]WBU_REG_ADDR,
    output  [31:0]WBU_CSR_DATA,
    output  [2:0]WBU_CSR_ADDR,
    output  WBU_wen,
    output  WBU_CSR_WEN,
    output  WBU_ECALL,
    output  [31:0] PC_DATA,
    output  [31:0] DNPC_DATA,
    output  WBU_TOP_skip
);

//wire [4:0] csr_addr;
wire csr_en;

//assign csr_addr = (LSU_WBU_ecall) ? 'd3 : (LSU_WBU_mret) ? 'd0 :LSU_WBU_csr_rst;



assign WBU_wen = LSU_WBU_reg;
assign WBU_REG_DATA = LSU_WBU_result;
assign WBU_REG_ADDR = addr;
assign WBU_CSR_DATA = LSU_WBU_csr_in;
assign WBU_CSR_ADDR = LSU_WBU_csr_rst;
assign WBU_CSR_WEN    = LSU_WBU_C_type&(~LSU_WBU_mret)&(~LSU_WBU_ecall);
assign WBU_ECALL      = LSU_WBU_ecall;
assign PC_DATA        = LSU_WBU_PC;
assign DNPC_DATA      = LSU_WBU_dnpc;
assign WBU_TOP_skip   = LSU_WBU_skip;

assign LSU_WBU_ready = 1'b1;


endmodule

module ysyx_24070003_RegisterFile #(
    parameter ADDR_WIDTH = 4,  
    parameter DATA_WIDTH = 32
) (
    input clock,
    input reset,
    `ifdef __ICARUS__
    output [DATA_WIDTH-1:0] a0,
    `endif
    input [DATA_WIDTH-1:0] wdata,
    input [ADDR_WIDTH-1:0] waddr,
    input wen,
    
    output [DATA_WIDTH-1:0] rdata1,
    
    input [ADDR_WIDTH-1:0] raddr1,
    
    output [DATA_WIDTH-1:0] rdata2,
    
    input [ADDR_WIDTH-1:0] raddr2
);

    reg [DATA_WIDTH-1:0] rf[15:0];
    // import "DPI-C" function void set_gpr_ptr(input logic [31:0] a []);
    // initial set_gpr_ptr(rf); 

    
    always @(posedge clock) begin
        if(reset) rf[0] <= 32'h0;
        if (wen & waddr != 0) rf[waddr] <= wdata; 
    end
    `ifdef __ICARUS__
    assign a0  = rf[10];
    `endif
    assign rdata1 = rf[raddr1];
    assign rdata2 = rf[raddr2];
   
endmodule

module ysyx_24070003_csr_reg #(
    parameter ADDR_WIDTH = 5,  
    parameter DATA_WIDTH = 32
) (
    input clock,
    input [DATA_WIDTH-1:0] wdata,
    input ecall,
    input [31:0] pc,
    input [ADDR_WIDTH-1:0] waddr,
    input wen,
    
    output [DATA_WIDTH-1:0] rdata1,
    
    input [ADDR_WIDTH-1:0] raddr1
);

    reg [DATA_WIDTH-1:0] csr[5:0];
    
    initial begin
        csr[4] = 32'h79737978; // zero register
        csr[5] = 32'h016e38bf; // zero register
    end
    //  import "DPI-C" function void set_csr_ptr(input logic [31:0] a []);
    //  initial set_csr_ptr(csr); // set the pointer to the CSR array
    initial csr[1] = 'h1800;
    always @(posedge clock) begin
        if (ecall) begin 
            csr[2] <= 'd11; 
            csr[0] <= pc; 
        end // ECALL: set PC and cause to 11 (Environment Call)
        if (wen) csr[waddr] <= wdata; // write to CSR
    end
    
    assign rdata1 = csr[raddr1];

    

endmodule

module ysyx_24070003_mux4_32bit(
    input [1:0] sel,
    input [31:0] a, 
    input [31:0] b,
    input [31:0] c,
    input [31:0] d,
    output reg [31:0] out
);
    always @(*) begin
        case(sel)
            2'b00: out = a;
            2'b01: out = b;
            2'b10: out = c;
            2'b11: out = d;
        endcase
    end
endmodule

module ysyx_24070003_axi_arbiter #(
    parameter ADDR_WIDTH = 32,
    parameter DATA_WIDTH = 32
)(
    input clock,
    input rstn,
    
    // IFU 接口 (指令获取)
    input  [ADDR_WIDTH-1:0] ifu_araddr,
    input                   ifu_arvalid,
    output                  ifu_arready,
    
    output [DATA_WIDTH-1:0] ifu_rdata,
    output                  ifu_rvalid,
    input                   ifu_rready,
    
    // LSU 接口 (加载/存储)
    input  [ADDR_WIDTH-1:0] lsu_araddr,
    input                   lsu_arvalid,
    output                  lsu_arready,
    
    output [DATA_WIDTH-1:0] lsu_rdata,
    output                  lsu_rvalid,
    input                   lsu_rready,
    
    input  [ADDR_WIDTH-1:0] lsu_awaddr,
    input                   lsu_awvalid,
    output                  lsu_awready,
    
    input  [DATA_WIDTH-1:0] lsu_wdata,
    input  [3:0]            lsu_wstrb,
    input                   lsu_wvalid,
    output                  lsu_wready,
    
    //output [1:0]            lsu_bresp,
    output                  lsu_bvalid,
    input                   lsu_bready,
    input   [2:0]          lsu_arsize,
    
    // SRAM 从设备接口
    output [ADDR_WIDTH-1:0] master_araddr,
    output                  master_arvalid,
    input                   master_arready,
    
    input  [DATA_WIDTH-1:0] master_rdata,
    input                   master_rvalid,
    output                  master_rready,
    
    output [ADDR_WIDTH-1:0] master_awaddr,
    output                  master_awvalid,
    input                   master_awready,
    
    output [DATA_WIDTH-1:0] master_wdata,
    output [3:0]            master_wstrb,
    output                  master_wvalid,
    input                   master_wready,
    
    //input  [1:0]            sram_bresp,
    input                   master_bvalid,
    output                  master_bready,

    input   [7:0]           ICACHE_AXI4_arlen,
    output  [7:0]           master_arlen,
    input                   master_rlast,
    output  [2:0]           master_arsize
);

// 仲裁状态定义
// typedef enum logic [2:0] {
//     IDLE,
//     IFU_READ_START,
//     IFU_READ_WAIT,
//     LSU_READ_START,
//     LSU_READ_WAIT,
//     LSU_WRITE_START,
//     LSU_WRITE_DATA,
//     LSU_WRITE_RESP
// } arb_state_t;

// arb_state_t state;

parameter  IDLE = 0,
            IFU_READ_START = 1,
            IFU_READ_WAIT = 2,
            LSU_READ_START = 3,
            LSU_READ_WAIT = 4,
            LSU_WRITE_START = 5,
            LSU_WRITE_DATA = 6,
            LSU_WRITE_RESP = 7;
reg [2:0] state;
// 仲裁优先级参数

// 内部信号
reg [ADDR_WIDTH-1:0] saved_araddr;
//reg [ADDR_WIDTH-1:0] saved_awaddr;
//reg [DATA_WIDTH-1:0] saved_wdata;
//reg [3:0]            saved_wstrb;

wire clint = (lsu_araddr >= 32'h02000000 && lsu_araddr <= 32'h02000004);
// 状态机
always @(posedge clock ) begin
    if (rstn) begin
        state <= IDLE;
        saved_araddr <= '0;
        //saved_awaddr <= '0;
        //saved_wdata <= '0;
        //saved_wstrb <= '0;
    end else begin
        case (state)
            IDLE: begin
                // 优先级处理：IFU读请求优先
                if (lsu_arvalid && !clint) begin
                    saved_araddr <= lsu_araddr;
                    state <= LSU_READ_START;
                end
                else if (ifu_arvalid) begin
                    saved_araddr <= ifu_araddr;
                    state <= IFU_READ_START;
                end
                // LSU写请求
                else if (lsu_awvalid && lsu_wvalid) begin
                    //saved_awaddr <= lsu_awaddr;
                    //saved_wdata <= lsu_wdata;
                    //saved_wstrb <= lsu_wstrb;
                    state <= LSU_WRITE_START;
                end
            end
            
            // IFU读操作
            IFU_READ_START: begin
                if (master_arready) begin
                    state <= IFU_READ_WAIT;
                end
            end
            
            IFU_READ_WAIT: begin
                if (master_rvalid && master_rready && master_rlast) begin
                    state <= IDLE;
                end
            end
            
            // LSU读操作
            LSU_READ_START: begin
                if (master_arready) begin
                    state <= LSU_READ_WAIT;
                end
            end
            
            LSU_READ_WAIT: begin
                if (master_rvalid && master_rready) begin
                    state <= IDLE;
                end
            end
            
            // LSU写操作
            LSU_WRITE_START: begin
                if (master_awready && master_wready) begin
                    state <= LSU_WRITE_RESP;
                end
                else if (master_awready) begin
                    state <= LSU_WRITE_DATA;
                end
                else if (master_bvalid && master_bready) begin
                    state <= IDLE;
                end
            end
            
            LSU_WRITE_DATA: begin
                
                if (master_wready) begin
                    state <= LSU_WRITE_RESP;
                end
                else if (master_bvalid && master_bready) begin
                    state <= IDLE;
                end
            end
            
            LSU_WRITE_RESP: begin
                if (master_bvalid && master_bready) begin
                    state <= IDLE;
                end
            end
            
            default: state <= IDLE;
        endcase
    end
end

// 读地址通道仲裁
assign master_araddr = saved_araddr;/*(state == IFU_READ_START || state == IFU_READ_WAIT) ? saved_araddr :
                     (state == LSU_READ_START || state == LSU_READ_WAIT) ? saved_araddr : '0;*/
assign master_arlen = (state == IFU_READ_START || state == IFU_READ_WAIT) ? ICACHE_AXI4_arlen : 8'b0;
assign master_arvalid = (state == IFU_READ_START || state == LSU_READ_START) ? 1'b1 : 1'b0;
assign master_arsize = (state == LSU_READ_START || state == LSU_READ_WAIT) ? lsu_arsize : 3'b10;

assign ifu_arready = (state == IFU_READ_START) ? master_arready : 1'b0;
assign lsu_arready = (state == LSU_READ_START) ? master_arready : 1'b0;

// 读数据通道仲裁
assign ifu_rdata = master_rdata;
assign lsu_rdata = master_rdata;

assign ifu_rvalid = (state == IFU_READ_WAIT || state == IFU_READ_WAIT) ? master_rvalid : 1'b0;
assign lsu_rvalid = (state == LSU_READ_WAIT) ? master_rvalid : 1'b0;

assign master_rready = (state == IFU_READ_WAIT) ? ifu_rready :
                     (state == LSU_READ_WAIT) ? lsu_rready : 1'b0;

// 写地址通道仲裁 (仅LSU)
assign master_awaddr = lsu_awaddr;
assign master_awvalid = lsu_awvalid;
assign lsu_awready = master_awready;

// 写数据通道仲裁 (仅LSU)
assign master_wdata = lsu_wdata;
assign master_wstrb = lsu_wstrb;
assign master_wvalid = lsu_wvalid;
assign lsu_wready =  master_wready ;

// 写响应通道仲裁 (仅LSU)
//assign lsu_bresp = sram_bresp;
assign lsu_bvalid =master_bvalid ;
assign master_bready = lsu_bready ;

endmodule

module ysyx_24070003_clint #(
    parameter ADDR_WIDTH = 32,
    parameter DATA_WIDTH = 32
)(
    input clock,
    input rstn,


    // AXI-Lite4 Read Address Channel
    input [ADDR_WIDTH-1:0] AXI4_CLINT_ARADDR,
    output              AXI4_CLINT_ARREADY,
    
    // AXI-Lite4 Read Data Channel
    output  [DATA_WIDTH-1:0] AXI4_CLINT_RDATA,
    output                   AXI4_CLINT_RVALID
    //output reg [1:0]       AXI4_SRAM_BRESP 
);
    //reg [DATA_WIDTH-1:0] mem [0:2**ADDR_WIDTH-1];


//import "DPI-C" function void vpmem_read(input int raddr,input byte ren,output int rdata);
//import "DPI-C" function void vpmem_write(input int waddr, input byte wmask,input int wdata,input byte wen);


reg [31:0] mtime_low;
reg [31:0] mtime_high;
always @(posedge clock) begin
    if (rstn) begin
        mtime_low <= 32'b0;
    end else if(mtime_low == 32'hffffffff) begin
        mtime_low <= 32'b0;
    end else begin
        mtime_low <= mtime_low + 32'b1;
    end
end
always @(posedge clock) begin
    if (rstn) begin
        mtime_high <= 32'b0;
    end else if (mtime_low == 32'hffffffff)begin
            mtime_high <= mtime_high + 32'b1;
    end else begin
        mtime_high <= mtime_high;
    end
end

// wire [31:0] rdata;
assign AXI4_CLINT_RDATA = (AXI4_CLINT_ARADDR == 32'h02000000) ? mtime_low : (AXI4_CLINT_ARADDR == 32'h02000004) ? mtime_high : 32'b0;

assign AXI4_CLINT_RVALID = 1'b1;
assign AXI4_CLINT_ARREADY = 1'b1;



// // DPI-C interface for instruction read
// //import "DPI-C" function void vpmem_read(input int raddr, output int rdata);

// // State machine
// always @(posedge clock) begin
//     if (rstn) begin
//         state_read <= RIDLE;
//         AXI4_CLINT_ARREADY <= 1'b0;
//         AXI4_CLINT_RVALID <= 1'b0;
        
//         read_addr_reg <= 'b0;
//     end
//     else begin
//         case (state_read)
//             RIDLE: begin
//                 AXI4_CLINT_ARREADY <= 1'b1;
//                 if (AXI4_CLINT_ARVALID) begin
//                     // Latch read address
//                     read_addr_reg <= AXI4_CLINT_ARADDR;
//                     AXI4_CLINT_ARREADY <= 1'b0;
//                     state_read <= READ_DATA;
//                 end
//             end
            
//             READ_DATA: begin
//                 // Perform read operation using DPI-C
//                 //vpmem_read(read_addr_reg, {7'b0, 1'b1}, AXI4_CLINT_RDATA);
//                 AXI4_CLINT_RDATA <= rdata;
//                 AXI4_CLINT_RVALID <= 1'b1;
//                 state_read <= READ_WAIT;
//             end
            
//             READ_WAIT: begin
//                 if (AXI4_CLINT_RREADY) begin
//                     AXI4_CLINT_RVALID <= 1'b0;
//                     state_read <= RIDLE;
//                 end
//             end
            
//             default: state_read <= RIDLE;
//         endcase
//     end
// end


endmodule







