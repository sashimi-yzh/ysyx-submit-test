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
(* keep *)wire                                 ebreak                         ;
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
wire                                 IFU_AXI4_rready                ;
wire                                 ICACHE_IFU_stall               ;
wire                                 flush                          ;
wire                                 BTB_pred_valid                 ;
wire                                 ICACHE_AXI4_arvalid            ;
wire                                 ICACHE_AXI4_arready            ;
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
    //.BTB_pred_pc                    (BTB_pred_pc        ),
    //.BTB_pred_valid                 (BTB_pred_valid     ),
    .IFU_IDU_INSTR                  (instr              ),
    //.instr_in                     (instr_in           ),
    //.BTB_pre_DNPC                   (BTB_pre_DNPC       ),

    .ifu_count                      (ifu_count          ),

    .IFU_ICACHE_araddr                (IFU_AXI4_araddr    ),
    .IFU_ICACHE_arvalid               (IFU_AXI4_arvalid   ),
    //.IFU_AXI4_arready               (IFU_AXI4_arready   ),
    .ICACHE_IFU_rdata                 (IFU_AXI4_rdata     ),
    .ICACHE_IFU_rvalid              (IFU_AXI4_rvalid    ),
    .IFU_ICACHE_rready                (IFU_AXI4_rready    ),
    .ICACHE_IFU_raddr               (ICACHE_IFU_raddr   ),
    .ICACHE_IFU_stall               (ICACHE_IFU_stall   )
    
);


ysyx_24070003_icache  my_icache(
    .clock                          (clock              ),
    .reset                          (reset              ),
    .fence_i                        (fence_i            ),
    .flush                          (flush              ),
    .IFU_ICACHE_araddr                (IFU_AXI4_araddr    ),
    .IFU_ICACHE_arvalid               (IFU_AXI4_arvalid   ),
   // .IFU_AXI4_rdata               (IFU_AXI4_rdata     ),
    //.IFU_AXI4_rvalid              (IFU_AXI4_rvalid    ),
    .IFU_ICACHE_rready                (IFU_AXI4_rready    ),

    //.BTB_pre_DNPC                   (BTB_pre_DNPC       ),
    .IDU_IFU_STALL                  (stall              ),
    .LSU_IFU_stall                  (LSU_IFU_stall      ),


    .ICACHE_IFU_rdata               (IFU_AXI4_rdata     ),
    .ICACHE_IFU_raddr               (ICACHE_IFU_raddr   ),
    //.ICACHE_IFU_pre_dnpc            (ICACHE_IFU_pre_dnpc),
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


// ysyx_24070003_btb my_btb(
//     .clock                          (clock              ),
//     .reset                          (reset              ),
//     .cur_pc                         (ifu_current_pc     ),
//     .update_pc                      (IDU_EXU_PC         ),
//     .target_pc                      (EXU_BTB_PC         ),
//     .update_valid                   (EXU_BTB_updata_valid),

//     .pred_pc                        (BTB_pred_pc        ),
//     .pred_valid                     (BTB_pred_valid     )
// );


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
    //.IFU_IDU_pre_dnpc               (ICACHE_IFU_pre_dnpc),
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
    //.IDU_EXU_pre_dnpc               (IDU_EXU_pre_dnpc   ),

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
    //.IDU_EXU_pre_dnpc               (IDU_EXU_pre_dnpc   ),
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
    .EXU_IDU_REN                    (EXU_IDU_REN        )
   // .EXU_BTB_PC                     (EXU_BTB_PC         ),
    //.EXU_BTB_updata_valid           (EXU_BTB_updata_valid)
);

assign LSU_RDATA = (LSU_AXI4_ARADDR >= 32'h02000000 && LSU_AXI4_ARADDR <= 32'h0200ffff) ? AXI4_CLINT_RDATA : LSU_AXI4_RDATA;
assign LSU_RVALID = (LSU_AXI4_ARADDR >= 32'h02000000 && LSU_AXI4_ARADDR <= 32'h0200ffff) ? AXI4_CLINT_RVALID : LSU_AXI4_RVALID;
assign LSU_ARREADY = (LSU_AXI4_ARADDR >= 32'h02000000 && LSU_AXI4_ARADDR <= 32'h0200ffff) ? AXI4_CLINT_ARREADY : LSU_AXI4_ARREADY;
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
// assign dpi_monitor_data[0] = {31'b0,difftest_valid};
// assign dpi_monitor_data[1] = TO_top_pc;
// assign dpi_monitor_data[2] = TO_top_dnpc;
// assign dpi_monitor_data[3] = instr;
// assign dpi_monitor_data[4] = {31'b0,ebreak};
// assign dpi_monitor_data[5] = {31'b0,ref_skip};



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














