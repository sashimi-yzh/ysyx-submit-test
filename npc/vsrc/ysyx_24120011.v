import "DPI-C" function void ebreak ();
import "DPI-C" function void npc_trap(input int pc, input int ret);
import "DPI-C" function void Performance_Counters(input int Performancetype);
module ysyx_24120011 (
    input clock,
    input reset,
    input           io_interrupt        ,
    input		    io_master_awready	,
    output		    io_master_awvalid	,
    output	[31:0]	io_master_awaddr	,
    output	[3:0]	io_master_awid	    ,
    output	[7:0]	io_master_awlen	    ,
    output	[2:0]	io_master_awsize	,
    output	[1:0]	io_master_awburst	,
    input		    io_master_wready	,
    output		    io_master_wvalid	,
    output	[31:0]	io_master_wdata	    ,
    output	[3:0]	io_master_wstrb	    ,
    output		    io_master_wlast	    ,
    output		    io_master_bready	,
    input		    io_master_bvalid	,
    input	[1:0]	io_master_bresp	    ,
    input	[3:0]	io_master_bid	    ,
    input		    io_master_arready	,
    output		    io_master_arvalid	,
    output	[31:0]	io_master_araddr	,
    output	[3:0]	io_master_arid	    ,
    output	[7:0]	io_master_arlen	    ,
    output	[2:0]	io_master_arsize	,
    output	[1:0]	io_master_arburst	,
    output		    io_master_rready	,
    input		    io_master_rvalid	,
    input	[1:0]	io_master_rresp	    ,
    input	[31:0]	io_master_rdata	    ,
    input		    io_master_rlast	    ,
    input	[3:0]	io_master_rid	    ,


    output		    io_slave_awready    ,
    input		    io_slave_awvalid    ,
    input	[31:0]	io_slave_awaddr     ,
    input	[3:0]	io_slave_awid       ,
    input	[7:0]	io_slave_awlen      ,
    input	[2:0]	io_slave_awsize     ,
    input	[1:0]	io_slave_awburst    ,
    output		    io_slave_wready     ,
    input		    io_slave_wvalid     ,
    input	[31:0]	io_slave_wdata      ,
    input	[3:0]	io_slave_wstrb      ,
    input		    io_slave_wlast      ,
    input		    io_slave_bready     ,
    output		    io_slave_bvalid     ,
    output	[1:0]	io_slave_bresp      ,
    output	[3:0]	io_slave_bid        ,
    output		    io_slave_arready    ,
    input		    io_slave_arvalid    ,
    input	[31:0]	io_slave_araddr     ,
    input	[3:0]	io_slave_arid       ,
    input	[7:0]	io_slave_arlen      ,
    input	[2:0]	io_slave_arsize     ,
    input	[1:0]	io_slave_arburst    ,
    input		    io_slave_rready     ,
    output		    io_slave_rvalid     ,
    output	[1:0]	io_slave_rresp      ,
    output	[31:0]	io_slave_rdata      ,
    output		    io_slave_rlast      ,
    output	[3:0]	io_slave_rid
);
// //======================finish========================//
// always@(posedge clock) begin
//     if (IFU_IDU_inst == 32'b00000000000100000000000001110011) begin
//         $write("npc execute ebreak at pc = 0x%08x\n", IFU_IDU_pc);
//         if (a0 == 0) begin
//             $write("\033[1;32mHIT GOOD TRAP!\033[0m\n"); // 绿色
//         end
//         else begin
//             $write("\033[1;31mHIT BAD TRAP!\033[0m\n");  // 红色
//         end
//         $finish;
//     end
// end
// //======================finish========================//
//============M0=============//        
//AR-axi4lite
wire  [31:0]     M0_araddr;
wire             M0_arvalid;
wire              M0_arready;
//AR-axi4
wire  [3:0]      M0_arid;
wire  [7:0]      M0_arlen;
wire  [2:0]      M0_arsize;
wire  [1:0]      M0_arburst;
//R-axi4lite            
wire   [31:0]     M0_rdata;
wire   [1:0]      M0_rresp;
wire              M0_rvalid;
wire             M0_rready;
//R-axi4
wire              M0_rlast;
wire   [3:0]      M0_rid;
//AW-axi4lite
wire  [31:0]     M0_awaddr;
wire             M0_awvalid;
wire              M0_awready;
//AW-axi4
wire  [3:0]      M0_awid;
wire  [7:0]      M0_awlen;
wire  [2:0]      M0_awsize;
wire  [1:0]      M0_awburst;
//W-axi4lite
wire  [31:0]     M0_wdata;
wire  [3:0]      M0_wstrb;
wire             M0_wvalid;
wire              M0_wready;
//W-axi4
wire             M0_wlast;
//B-axi4lite
wire   [1:0]      M0_bresp;
wire              M0_bvalid;
wire             M0_bready;
//B-axi4
wire	[3:0]	   M0_bid;
//============M1=============//        
//AR-axi4lite
wire  [31:0]     M1_araddr;
wire             M1_arvalid;
wire              M1_arready;
//AR-axi4
wire  [3:0]      M1_arid;
wire  [7:0]      M1_arlen;
wire  [2:0]      M1_arsize;
wire  [1:0]      M1_arburst;
//R-axi4lite            
wire   [31:0]     M1_rdata;
wire   [1:0]      M1_rresp;
wire              M1_rvalid;
wire             M1_rready;
//R-axi4
wire              M1_rlast;
wire   [3:0]      M1_rid;
//AW-axi4lite
wire  [31:0]     M1_awaddr;
wire             M1_awvalid;
wire              M1_awready;
//AW-axi4
wire  [3:0]      M1_awid;
wire  [7:0]      M1_awlen;
wire  [2:0]      M1_awsize;
wire  [1:0]      M1_awburst;
//W-axi4lite
wire  [31:0]     M1_wdata;
wire  [3:0]      M1_wstrb;
wire             M1_wvalid;
wire              M1_wready;
//W-axi4
wire             M1_wlast;
//B-axi4lite
wire   [1:0]      M1_bresp;
wire              M1_bvalid;
wire             M1_bready;
//B-axi4
wire	[3:0]	   M1_bid;
//============S0=============// 
//AR-axi4lite
wire  [31:0]     S0_araddr;
wire             S0_arvalid;
wire            S0_arready;
//AR-axi4
wire  [3:0]      S0_arid;
wire  [7:0]      S0_arlen;
wire  [2:0]      S0_arsize;
wire  [1:0]      S0_arburst;
//R-axi4lite              
wire [31:0]     S0_rdata;
wire [1:0]      S0_rresp;
wire            S0_rvalid;
wire             S0_rready;
//R-axi4
wire            S0_rlast;
wire [3:0]      S0_rid;
//AW-axi4lite
wire  [31:0]     S0_awaddr;
wire             S0_awvalid;
wire            S0_awready;
//AW-axi4
wire  [3:0]      S0_awid;
wire  [7:0]      S0_awlen;
wire  [2:0]      S0_awsize;
wire  [1:0]      S0_awburst;
//W-axi4lite
wire  [31:0]     S0_wdata;
wire  [3:0]      S0_wstrb;
wire             S0_wvalid;
wire            S0_wready;
//W-axi4
wire             S0_wlast;
//B-axi4lite
wire [1:0]      S0_bresp;
wire            S0_bvalid;
wire             S0_bready;
//B-axi4
wire [3:0]	  S0_bid;
//============clint=============// 
//AR-axi4lite
wire  [31:0]     clint_araddr;
wire             clint_arvalid;
wire            clint_arready;
//AR-axi4
wire  [3:0]      clint_arid;
wire  [7:0]      clint_arlen;
wire  [2:0]      clint_arsize;
wire  [1:0]      clint_arburst;
//R-axi4lite              
wire [31:0]     clint_rdata;
wire [1:0]      clint_rresp;
wire            clint_rvalid;
wire             clint_rready;
//R-axi4
wire            clint_rlast;
wire [3:0]      clint_rid;
//AW-axi4lite
wire  [31:0]     clint_awaddr;
wire             clint_awvalid;
wire            clint_awready;
//AW-axi4
wire  [3:0]      clint_awid;
wire  [7:0]      clint_awlen;
wire  [2:0]      clint_awsize;
wire  [1:0]      clint_awburst;
//W-axi4lite
wire  [31:0]     clint_wdata;
wire  [3:0]      clint_wstrb;
wire             clint_wvalid;
wire            clint_wready;
//W-axi4
wire             clint_wlast;
//B-axi4lite
wire [1:0]      clint_bresp;
wire            clint_bvalid;
wire             clint_bready;
//B-axi4
wire [3:0]	  clint_bid;

//======================dpic========================//
always@(posedge clock)begin
    if (IFU_IDU_inst == 32'b00000000000100000000000001110011)begin
        npc_trap(IFU_IDU_pc,a0);
        ebreak();
    end
end

reg IFU_valid_delay;
reg IFU_valid_rising_edge;
reg LSU_rready_delay;
reg LSU_rready_rising_edge;
reg EXU_valid_delay;
reg EXU_valid_rising_edge;
always@(posedge clock) begin
    IFU_valid_delay <= IFU_valid;
    IFU_valid_rising_edge <= IFU_valid & ~IFU_valid_delay;
    LSU_rready_delay <= M1_rready;
    LSU_rready_rising_edge <= M1_rready & ~LSU_rready_delay;
    EXU_valid_delay <= EXU_ready;
    EXU_valid_rising_edge <= EXU_ready & ~EXU_valid_delay;
end
always@(posedge clock) begin
    if(IFU_valid_rising_edge) begin
        Performance_Counters(32'd1);
    end
    if(LSU_rready_rising_edge) begin
        Performance_Counters(32'd2);
    end
    if(EXU_valid_rising_edge) begin
        Performance_Counters(32'd3);
    end
end
//======================dpic========================//
wire [31:0] EXU_IFU_npc;
wire [31:0] PC_IFU_pc;
wire EXU_valid;
wire PC_ready;
wire IFU_ready;
wire PC_valid;
// ysyx_24120011_PC u_ysyx_24120011_PC(
//     .clk         ( clock         ),
//     .rst         ( reset         ),
//     .i_npc       ( EXU_PC_npc       ),
//     .o_pc        ( PC_IFU_pc        ),
//     .i_EXU_valid ( EXU_valid ),
//     .o_PC_ready  ( PC_ready  ),
//     .i_IFU_ready ( IFU_ready ),
//     .o_PC_valid  ( PC_valid  )
// );
wire [31:0] IFU_IDU_pc;
wire [31:0] IFU_IDU_inst;
wire IFID_ready;
wire IFU_valid;
wire flush;

ysyx_24120011_IFU u_ysyx_24120011_IFU(
    .clk          ( clock          ),
    .rst          ( reset          ),
    .i_pc         ( EXU_IFU_npc         ),
    .o_pc         ( IFU_IDU_pc         ),
    .o_inst       ( IFU_IDU_inst       ),
    .i_EXU_valid  ( EXU_valid   ),
    .o_IFU_ready  ( IFU_ready  ),
    .i_IDU_ready  ( IDU_ready ),
    .o_IFU_valid  ( IFU_valid  ),
    .M0_araddr    ( M0_araddr    ),
    .M0_arvalid   ( M0_arvalid   ),
    .M0_arready   ( M0_arready   ),
    .M0_arid      ( M0_arid      ),
    .M0_arlen     ( M0_arlen     ),
    .M0_arsize    ( M0_arsize    ),
    .M0_arburst   ( M0_arburst   ),
    .M0_rdata     ( M0_rdata     ),
    .M0_rresp     ( M0_rresp     ),
    .M0_rvalid    ( M0_rvalid    ),
    .M0_rready    ( M0_rready    ),
    .M0_rlast     ( M0_rlast     ),
    .M0_rid       ( M0_rid       ),
    .M0_awaddr    ( M0_awaddr    ),
    .M0_awvalid   ( M0_awvalid   ),
    .M0_awready   ( M0_awready   ),
    .M0_awid      ( M0_awid      ),
    .M0_awlen     ( M0_awlen     ),
    .M0_awsize    ( M0_awsize    ),
    .M0_awburst   ( M0_awburst   ),
    .M0_wdata     ( M0_wdata     ),
    .M0_wstrb     ( M0_wstrb     ),
    .M0_wvalid    ( M0_wvalid    ),
    .M0_wready    ( M0_wready    ),
    .M0_wlast     ( M0_wlast     ),
    .M0_bresp     ( M0_bresp     ),
    .M0_bvalid    ( M0_bvalid    ),
    .M0_bready    ( M0_bready    ),
    .M0_bid       ( M0_bid       ),
    .i_flush      ( flush        )
);
wire [31:0] IFID_IDU_pc;
wire [31:0] IFID_IDU_inst;
wire IDU_ready;
wire IFID_valid;
// ysyx_24120011_IFID u_ysyx_24120011_IFID(
//     .clk          ( clock          ),
//     .rst          ( reset          ),
//     .i_pc         ( IFU_IFID_pc         ),
//     .i_inst       ( IFU_IFID_inst       ),
//     .o_pc         ( IFID_IDU_pc         ),
//     .o_inst       ( IFID_IDU_inst       ),
//     .i_IFU_valid  ( IFU_valid  ),
//     .o_IFID_ready ( IFID_ready ),
//     .i_IDU_ready  ( IDU_ready  ),
//     .o_IFID_valid  ( IFID_valid  )
// );

wire [2:0]  IDU_EXU_pc_ctrl;
wire [2:0]  IDU_EXU_rd_ctrl;
wire [5:0]  IDU_EXU_ALU_ctrl;
wire [6:0] IDU_EXU_mem_ctrl;
wire [2:0]  IDU_EXU_csr_ctrl;
wire [31:0] IDU_EXU_pc;
wire [31:0] IDU_EXU_src1;
wire [31:0] IDU_EXU_src2;
wire [31:0] IDU_EXU_r_csr_data;
wire [31:0] IDU_EXU_imm;
wire [3:0]  IDU_EXU_rd;
wire [11:0] IDU_EXU_w_csr_addr;
wire IDEX_ready;
wire IDU_valid;
wire [3:0]  IDU_GPR_rs1;
wire [3:0]  IDU_GPR_rs2;
wire [31:0] IDU_GPR_src1;
wire [31:0] IDU_GPR_src2;
wire [11:0] IDU_CSR_r_csr_addr;
wire [31:0] IDU_CSR_r_csr_data;
//======================dpic========================//
wire [31:0] IDU_EXU_inst;
//======================dpic========================//
ysyx_24120011_IDU u_ysyx_24120011_IDU(
    .clk          ( clock          ),
    .rst          ( reset          ),
    .i_pc         ( IFU_IDU_pc         ),
    .i_inst       ( IFU_IDU_inst       ),
    .o_pc_ctrl    ( IDU_EXU_pc_ctrl    ),
    .o_rd_ctrl    ( IDU_EXU_rd_ctrl    ),
    .o_ALU_ctrl   ( IDU_EXU_ALU_ctrl   ),
    .o_mem_ctrl   ( IDU_EXU_mem_ctrl   ),
    .o_csr_ctrl   ( IDU_EXU_csr_ctrl   ),
    .o_pc         ( IDU_EXU_pc         ),
    .o_src1       ( IDU_EXU_src1       ),
    .o_src2       ( IDU_EXU_src2       ),
    .o_r_csr_data ( IDU_EXU_r_csr_data ),
    .o_imm        ( IDU_EXU_imm        ),
    .o_rd         ( IDU_EXU_rd         ),
    .o_w_csr_addr ( IDU_EXU_w_csr_addr ),
    .i_IFU_valid  ( IFU_valid ),
    .o_IDU_ready  ( IDU_ready  ),
    .i_EXU_ready  ( EXU_ready ),
    .o_IDU_valid  ( IDU_valid  ),
    .o_rs1        ( IDU_GPR_rs1        ),
    .o_rs2        ( IDU_GPR_rs2        ),
    .i_src1       ( IDU_GPR_src1       ),
    .i_src2       ( IDU_GPR_src2       ),
    .o_r_csr_addr ( IDU_CSR_r_csr_addr ),
    .i_r_csr_data ( IDU_CSR_r_csr_data  ),
    .i_stop_pipe  ( DATAHAZARD_stop_pipe           ),
    .i_rd_data    ( DATAHAZARD_IDU_r_ddata),
    .i_rs1_or_rs2 ( DATAHAZARD_IDU_rs1_or_rs2),
    .i_bypass     ( DATAHAZARD_IDU_bypass),
    //======================dpic========================//
    .o_inst       ( IDU_EXU_inst),
    //======================dpic========================//
    .i_flush      ( flush )
);
wire [2:0]  IDEX_EXU_pc_ctrl;
wire [2:0]  IDEX_EXU_rd_ctrl;
wire [5:0]  IDEX_EXU_ALU_ctrl;
wire [18:0] IDEX_EXU_mem_ctrl;
wire [4:0]  IDEX_EXU_csr_ctrl;
wire [31:0] IDEX_EXU_pc;
wire [31:0] IDEX_EXU_src1;
wire [31:0] IDEX_EXU_src2;
wire [31:0] IDEX_EXU_r_csr_data;
wire [31:0] IDEX_EXU_imm;
wire [4:0]  IDEX_EXU_rd;
wire [11:0] IDEX_EXU_w_csr_addr;
wire EXU_ready ;
wire IDEX_valid;
// ysyx_24120011_IDEX u_ysyx_24120011_IDEX(
//     .clk          ( clock          ),
//     .rst          ( reset          ),
//     .i_pc_ctrl    ( IDU_IDEX_pc_ctrl    ),
//     .i_rd_ctrl    ( IDU_IDEX_rd_ctrl    ),
//     .i_ALU_ctrl   ( IDU_IDEX_ALU_ctrl   ),
//     .i_mem_ctrl   ( IDU_IDEX_mem_ctrl   ),
//     .i_csr_ctrl   ( IDU_IDEX_csr_ctrl   ),
//     .i_pc         ( IDU_IDEX_pc         ),
//     .i_src1       ( IDU_IDEX_src1       ),
//     .i_src2       ( IDU_IDEX_src2       ),
//     .i_r_csr_data ( IDU_IDEX_r_csr_data ),
//     .i_imm        ( IDU_IDEX_imm        ),
//     .i_rd         ( IDU_IDEX_rd         ),
//     .i_w_csr_addr ( IDU_IDEX_w_csr_addr ),
//     .o_pc_ctrl    ( IDEX_EXU_pc_ctrl    ),
//     .o_rd_ctrl    ( IDEX_EXU_rd_ctrl    ),
//     .o_ALU_ctrl   ( IDEX_EXU_ALU_ctrl   ),
//     .o_mem_ctrl   ( IDEX_EXU_mem_ctrl   ),
//     .o_csr_ctrl   ( IDEX_EXU_csr_ctrl   ),
//     .o_pc         ( IDEX_EXU_pc         ),
//     .o_src1       ( IDEX_EXU_src1       ),
//     .o_src2       ( IDEX_EXU_src2       ),
//     .o_r_csr_data ( IDEX_EXU_r_csr_data ),
//     .o_imm        ( IDEX_EXU_imm        ),
//     .o_rd         ( IDEX_EXU_rd         ),
//     .o_w_csr_addr ( IDEX_EXU_w_csr_addr ),
//     .i_IDU_valid  ( IDU_valid  ),
//     .o_IDEX_ready ( IDEX_ready ),
//     .i_EXU_ready  ( EXU_ready  ),
//     .o_IDEX_valid  ( IDEX_valid  )
// );
wire [2:0]  EXU_MEM_rd_ctrl;
wire [6:0] EXU_MEM_mem_ctrl;
wire [2:0]  EXU_MEM_csr_ctrl;
wire [31:0] EXU_MEM_pc;
wire [31:0] EXU_MEM_src1;
wire [31:0] EXU_MEM_src2;
wire [31:0] EXU_MEM_r_csr_data;
wire [31:0] EXU_MEM_imm;
wire [3:0]  EXU_MEM_rd;
wire [11:0] EXU_MEM_w_csr_addr;
wire [31:0] EXU_MEM_ALU_result;

wire [31:0] EXU_MEM_rd_data   ;  
wire [1:0]  EXU_MEM_rd_data_type;
wire [31:0] EXU_MEM_w_csr_data  ;
wire        EXU_MEM_w_csr_en    ;
wire        EXU_MEM_w_csr_ecall ;
wire        EXMEM_ready;
ysyx_24120011_EXU u_ysyx_24120011_EXU(
    .clk           ( clock           ),
    .rst           ( reset           ),
    .i_pc_ctrl     ( IDU_EXU_pc_ctrl     ),
    .i_rd_ctrl     ( IDU_EXU_rd_ctrl     ),
    .i_ALU_ctrl    ( IDU_EXU_ALU_ctrl    ),
    .i_mem_ctrl    ( IDU_EXU_mem_ctrl    ),
    .i_csr_ctrl    ( IDU_EXU_csr_ctrl    ),
    .i_pc          ( IDU_EXU_pc          ),
    .i_src1        ( IDU_EXU_src1        ),
    .i_src2        ( IDU_EXU_src2        ),
    .i_r_csr_data  ( IDU_EXU_r_csr_data  ),
    .i_imm         ( IDU_EXU_imm         ),
    .i_rd          ( IDU_EXU_rd          ),
    .i_w_csr_addr  ( IDU_EXU_w_csr_addr  ),
    //.o_rd_ctrl     ( EXU_MEM_rd_ctrl     ),
    .o_mem_ctrl    ( EXU_MEM_mem_ctrl    ),
    //.o_csr_ctrl    ( EXU_MEM_csr_ctrl    ),
    //.o_pc          ( EXU_MEM_pc          ),
    //.o_src1        ( EXU_MEM_src1        ),
    .o_src2        ( EXU_MEM_src2        ),
    //.o_r_csr_data  ( EXU_MEM_r_csr_data  ),
    //.o_imm         ( EXU_MEM_imm         ),
    .o_rd          ( EXU_MEM_rd          ),
    .o_w_csr_addr  ( EXU_MEM_w_csr_addr  ),
    .o_ALU_result  ( EXU_MEM_ALU_result  ),
    .o_rd_data     (EXU_MEM_rd_data      ),
    .o_rd_data_type(EXU_MEM_rd_data_type ),
    .o_w_csr_data  (EXU_MEM_w_csr_data   ),
    .o_w_csr_en    (EXU_MEM_w_csr_en     ),
    .o_w_csr_ecall (EXU_MEM_w_csr_ecall  ),
    .o_npc         ( EXU_IFU_npc         ),
    .i_IDU_valid   ( IDU_valid  ),
    .o_EXU_ready   ( EXU_ready   ),
    .i_MEM_ready   ( MEM_ready ),
    .o_EXU_valid   ( EXU_valid   ),
    .o_flush       ( flush ),
    .i_IDU_empty   ( IDU_ready ),
    //======================dpic========================//
    .i_inst        ( IDU_EXU_inst),
    //======================dpic========================//
    .i_IFU_pc      ( IFU_IDU_pc)
);
wire [2:0]  EXMEM_MEM_rd_ctrl;
wire [18:0] EXMEM_MEM_mem_ctrl;
wire [4:0]  EXMEM_MEM_csr_ctrl;
wire [31:0] EXMEM_MEM_pc;
wire [31:0] EXMEM_MEM_src1;
wire [31:0] EXMEM_MEM_src2;
wire [31:0] EXMEM_MEM_r_csr_data;
wire [31:0] EXMEM_MEM_imm;
wire [4:0]  EXMEM_MEM_rd;
wire [11:0] EXMEM_MEM_w_csr_addr;
wire [31:0] EXMEM_MEM_ALU_result;
wire MEM_ready;
wire EXMEM_valid;
// ysyx_24120011_EXMEM u_ysyx_24120011_EXMEM(
//     .clk           ( clock           ),
//     .rst           ( reset           ),
//     .i_rd_ctrl     ( EXU_EXMEM_rd_ctrl     ),
//     .i_mem_ctrl    ( EXU_EXMEM_mem_ctrl    ),
//     .i_csr_ctrl    ( EXU_EXMEM_csr_ctrl    ),
//     .i_pc          ( EXU_EXMEM_pc          ),
//     .i_src1        ( EXU_EXMEM_src1        ),
//     .i_src2        ( EXU_EXMEM_src2        ),
//     .i_r_csr_data  ( EXU_EXMEM_r_csr_data  ),
//     .i_imm         ( EXU_EXMEM_imm         ),
//     .i_rd          ( EXU_EXMEM_rd          ),
//     .i_w_csr_addr  ( EXU_EXMEM_w_csr_addr  ),
//     .i_ALU_result  ( EXU_EXMEM_ALU_result  ),
//     .o_rd_ctrl     ( EXMEM_MEM_rd_ctrl     ),
//     .o_mem_ctrl    ( EXMEM_MEM_mem_ctrl    ),
//     .o_csr_ctrl    ( EXMEM_MEM_csr_ctrl    ),
//     .o_pc          ( EXMEM_MEM_pc          ),
//     .o_src1        ( EXMEM_MEM_src1        ),
//     .o_src2        ( EXMEM_MEM_src2        ),
//     .o_r_csr_data  ( EXMEM_MEM_r_csr_data  ),
//     .o_imm         ( EXMEM_MEM_imm         ),
//     .o_rd          ( EXMEM_MEM_rd          ),
//     .o_w_csr_addr  ( EXMEM_MEM_w_csr_addr  ),
//     .o_ALU_result  ( EXMEM_MEM_ALU_result  ),
//     .i_EXU_valid   ( EXU_valid   ),
//     .o_EXMEM_ready ( EXMEM_ready ),
//     .i_MEM_ready   ( MEM_ready   ),
//     .o_EXMEM_valid  ( EXMEM_valid  )
// );
wire [31:0] MEM_WBU_r_mem_data;
wire [2:0]  MEM_WBU_rd_ctrl;
wire [2:0]  MEM_WBU_csr_ctrl;
wire [31:0] MEM_WBU_pc;
wire [31:0] MEM_WBU_src1;
wire [31:0] MEM_WBU_r_csr_data;
wire [31:0] MEM_WBU_imm;
wire [3:0]  MEM_WBU_rd;
wire [11:0] MEM_WBU_w_csr_addr;
wire [31:0] MEM_WBU_ALU_result;

wire [31:0] MEM_WBU_rd_data   ;  
wire        MEM_WBU_rd_data_en;
wire [31:0] MEM_WBU_w_csr_data  ;
wire        MEM_WBU_w_csr_en    ;
wire        MEM_WBU_w_csr_ecall ;
wire MEMWB_ready;
wire MEM_valid;
wire [1:0] MEM_DATAHAZARD_rd_data_type;
ysyx_24120011_MEM u_ysyx_24120011_MEM(
    .clk           ( clock           ),
    .rst           ( reset           ),
    //.i_rd_ctrl     ( EXU_MEM_rd_ctrl     ),
    .i_mem_ctrl    ( EXU_MEM_mem_ctrl    ),
    //.i_csr_ctrl    ( EXU_MEM_csr_ctrl    ),
    //.i_pc          ( EXU_MEM_pc          ),
    //.i_src1        ( EXU_MEM_src1        ),
    .i_src2        ( EXU_MEM_src2        ),
    //.i_r_csr_data  ( EXU_MEM_r_csr_data  ),
    //.i_imm         ( EXU_MEM_imm         ),
    .i_rd          ( EXU_MEM_rd          ),
    .i_w_csr_addr  ( EXU_MEM_w_csr_addr  ),
    .i_ALU_result  ( EXU_MEM_ALU_result  ),

    .i_rd_data     (EXU_MEM_rd_data      ),
    .i_rd_data_type(EXU_MEM_rd_data_type ),
    .i_w_csr_data  (EXU_MEM_w_csr_data   ),
    .i_w_csr_en    (EXU_MEM_w_csr_en     ),
    .i_w_csr_ecall (EXU_MEM_w_csr_ecall  ),

    //.o_r_mem_data  ( MEM_WBU_r_mem_data  ),
    //.o_rd_ctrl     ( MEM_WBU_rd_ctrl     ),
    //.o_csr_ctrl    ( MEM_WBU_csr_ctrl    ),
    //.o_pc          ( MEM_WBU_pc          ),
    //.o_src1        ( MEM_WBU_src1        ),
    //.o_r_csr_data  ( MEM_WBU_r_csr_data  ),
    //.o_imm         ( MEM_WBU_imm         ),
    .o_rd          ( MEM_WBU_rd          ),
    .o_w_csr_addr  ( MEM_WBU_w_csr_addr  ),
    //.o_ALU_result  ( MEM_WBU_ALU_result  ),
    .o_rd_data     (MEM_WBU_rd_data      ),
    .o_rd_data_en  (MEM_WBU_rd_data_en ),
    .o_w_csr_data  (MEM_WBU_w_csr_data   ),
    .o_w_csr_en    (MEM_WBU_w_csr_en     ),
    .o_w_csr_ecall (MEM_WBU_w_csr_ecall  ),
    .o_rd_data_type(MEM_DATAHAZARD_rd_data_type),
    .i_EXU_valid   ( EXU_valid ),
    .o_MEM_ready   ( MEM_ready   ),
    .i_WBU_ready   ( WBU_ready ),
    .o_MEM_valid   ( MEM_valid   ),
    .M1_araddr     ( M1_araddr     ),
    .M1_arvalid    ( M1_arvalid    ),
    .M1_arready    ( M1_arready    ),
    .M1_arid       ( M1_arid       ),
    .M1_arlen      ( M1_arlen      ),
    .M1_arsize     ( M1_arsize     ),
    .M1_arburst    ( M1_arburst    ),
    .M1_rdata      ( M1_rdata      ),
    .M1_rresp      ( M1_rresp      ),
    .M1_rvalid     ( M1_rvalid     ),
    .M1_rready     ( M1_rready     ),
    .M1_rlast      ( M1_rlast      ),
    .M1_rid        ( M1_rid        ),
    .M1_awaddr     ( M1_awaddr     ),
    .M1_awvalid    ( M1_awvalid    ),
    .M1_awready    ( M1_awready    ),
    .M1_awid       ( M1_awid       ),
    .M1_awlen      ( M1_awlen      ),
    .M1_awsize     ( M1_awsize     ),
    .M1_awburst    ( M1_awburst    ),
    .M1_wdata      ( M1_wdata      ),
    .M1_wstrb      ( M1_wstrb      ),
    .M1_wvalid     ( M1_wvalid     ),
    .M1_wready     ( M1_wready     ),
    .M1_wlast      ( M1_wlast      ),
    .M1_bresp      ( M1_bresp      ),
    .M1_bvalid     ( M1_bvalid     ),
    .M1_bready     ( M1_bready     ),
    .M1_bid        ( M1_bid        )
);
wire [31:0] MEMWB_WBU_r_mem_data;
wire [2:0]  MEMWB_WBU_rd_ctrl;
wire [4:0]  MEMWB_WBU_csr_ctrl;
wire [31:0] MEMWB_WBU_pc;
wire [31:0] MEMWB_WBU_src1;
wire [31:0] MEMWB_WBU_r_csr_data;
wire [31:0] MEMWB_WBU_imm;
wire [4:0]  MEMWB_WBU_rd;
wire [11:0] MEMWB_WBU_w_csr_addr;
wire [31:0] MEMWB_WBU_ALU_result;
wire WBU_ready;   
wire MEMWB_valid; 
// ysyx_24120011_MEMWB u_ysyx_24120011_MEMWB(
//     .clk           ( clock           ),
//     .rst           ( reset           ),
//     .i_r_mem_data  ( MEM_MEMWB_r_mem_data  ),
//     .i_rd_ctrl     ( MEM_MEMWB_rd_ctrl     ),
//     .i_csr_ctrl    ( MEM_MEMWB_csr_ctrl    ),
//     .i_pc          ( MEM_MEMWB_pc          ),
//     .i_src1        ( MEM_MEMWB_src1        ),
//     .i_r_csr_data  ( MEM_MEMWB_r_csr_data  ),
//     .i_imm         ( MEM_MEMWB_imm         ),
//     .i_rd          ( MEM_MEMWB_rd          ),
//     .i_w_csr_addr  ( MEM_MEMWB_w_csr_addr  ),
//     .i_ALU_result  ( MEM_MEMWB_ALU_result  ),
//     .o_r_mem_data  ( MEMWB_WBU_r_mem_data  ),
//     .o_rd_ctrl     ( MEMWB_WBU_rd_ctrl     ),
//     .o_csr_ctrl    ( MEMWB_WBU_csr_ctrl    ),
//     .o_pc          ( MEMWB_WBU_pc          ),
//     .o_src1        ( MEMWB_WBU_src1        ),
//     .o_r_csr_data  ( MEMWB_WBU_r_csr_data  ),
//     .o_imm         ( MEMWB_WBU_imm         ),
//     .o_rd          ( MEMWB_WBU_rd          ),
//     .o_w_csr_addr  ( MEMWB_WBU_w_csr_addr  ),
//     .o_ALU_result  ( MEMWB_WBU_ALU_result  ),
//     .i_MEM_valid   ( MEM_valid   ),
//     .o_MEMWB_ready ( MEMWB_ready ),
//     .i_WBU_ready   ( WBU_ready   ),
//     .o_MEMWB_valid ( MEMWB_valid  )
// );
wire [3:0]   WBU_GPR_rd;
wire [31:0]  WBU_GPR_rd_data;
wire         WBU_GPR_rd_en;
wire [11:0]  WBU_CSR_w_csr_addr;
wire [31:0]  WBU_CSR_w_csr_data;
wire         WBU_CSR_w_csr_en;
wire         WBU_CSR_w_csr_ecall;
wire [2:0]   WBU_rd_ctrl;
ysyx_24120011_WBU u_ysyx_24120011_WBU(
    //.clk           ( clock           ),
    //.rst           ( reset           ),
    //.i_r_mem_data  ( MEM_WBU_r_mem_data  ),
    //.i_rd_ctrl     ( MEM_WBU_rd_ctrl     ),
    //.i_csr_ctrl    ( MEM_WBU_csr_ctrl    ),
    //.i_pc          ( MEM_WBU_pc          ),
    //.i_src1        ( MEM_WBU_src1        ),
    //.i_r_csr_data  ( MEM_WBU_r_csr_data  ),
    //.i_imm         ( MEM_WBU_imm         ),
    .i_rd          ( MEM_WBU_rd          ),
    .i_w_csr_addr  ( MEM_WBU_w_csr_addr  ),
    //.i_ALU_result  ( MEM_WBU_ALU_result  ),
    .i_rd_data     (MEM_WBU_rd_data      ),
    .i_rd_data_en  (MEM_WBU_rd_data_en ),
    .i_w_csr_data  (MEM_WBU_w_csr_data   ),
    .i_w_csr_en    (MEM_WBU_w_csr_en     ),
    .i_w_csr_ecall (MEM_WBU_w_csr_ecall  ),
    .o_rd          ( WBU_GPR_rd          ),
    .o_rd_data     ( WBU_GPR_rd_data     ),
    .o_rd_en       ( WBU_GPR_rd_en       ),
    .o_w_csr_addr  ( WBU_CSR_w_csr_addr  ),
    .o_w_csr_data  ( WBU_CSR_w_csr_data  ),
    .o_w_csr_en    ( WBU_CSR_w_csr_en    ),
    .o_w_csr_ecall ( WBU_CSR_w_csr_ecall ),
    .i_MEM_valid   ( MEM_valid ),
    .o_WBU_ready   ( WBU_ready   )
    //.o_rd_ctrl     ( WBU_rd_ctrl   )
);

wire [31:0] a0;
ysyx_24120011_GPR u_ysyx_24120011_GPR(
    .clk       ( clock       ),
    .rst       ( reset       ),
    .i_rs1     ( IDU_GPR_rs1     ),
    .i_rs2     ( IDU_GPR_rs2     ),
    .o_src1    ( IDU_GPR_src1    ),
    .o_src2    ( IDU_GPR_src2    ),
    .i_rd      ( WBU_GPR_rd      ),
    .i_rd_data ( WBU_GPR_rd_data ),
    .i_rd_en   ( WBU_GPR_rd_en   ),
    .a0        ( a0              )
);

ysyx_24120011_CSR u_ysyx_24120011_CSR(
    .clk          ( clock          ),
    .rst          ( reset          ),
    .i_r_csr_addr ( IDU_CSR_r_csr_addr ),
    .o_r_csr_data ( IDU_CSR_r_csr_data ),
    .i_w_csr_addr ( WBU_CSR_w_csr_addr ),
    .i_w_csr_data ( WBU_CSR_w_csr_data ),
    .i_w_csr_en   ( WBU_CSR_w_csr_en   ),
    .i_w_csr_ecall  ( WBU_CSR_w_csr_ecall  )
);
wire DATAHAZARD_stop_pipe;
wire [31:0] DATAHAZARD_IDU_r_ddata;
wire DATAHAZARD_IDU_rs1_or_rs2;
wire DATAHAZARD_IDU_bypass;

ysyx_24120011_data_hazard_detection u_ysyx_24120011_data_hazard_detection(
    .i_IDU_rs1     ( IDU_GPR_rs1     ),
    .i_IDU_rs2     ( IDU_GPR_rs2     ),
    .i_EXU_rd      ( EXU_MEM_rd      ),
    .i_EXU_rd_data_type ( EXU_MEM_rd_data_type),
    .i_EXU_rd_data ( EXU_MEM_rd_data),
    .i_MEM_rd      ( MEM_WBU_rd      ),
    .i_MEM_rd_data_type ( MEM_DATAHAZARD_rd_data_type),
    .i_MEM_rd_data ( MEM_WBU_rd_data),
    .i_EXU_ready   ( EXU_ready   ),
    .i_MEM_ready   ( MEM_ready   ),
    .o_stop_pipe   ( DATAHAZARD_stop_pipe   ),
    .o_rd_data     ( DATAHAZARD_IDU_r_ddata),
    .o_rs1_or_rs2  ( DATAHAZARD_IDU_rs1_or_rs2),
    .o_bypass      ( DATAHAZARD_IDU_bypass)
);

ysyx_24120011_Arbiter u_ysyx_24120011_Arbiter(
    .clk        ( clock        ),
    .rst        ( reset        ),
    .M0_araddr  ( M0_araddr  ),
    .M0_arvalid ( M0_arvalid ),
    .M0_arready ( M0_arready ),
    .M0_arid    ( M0_arid    ),
    .M0_arlen   ( M0_arlen   ),
    .M0_arsize  ( M0_arsize  ),
    .M0_arburst ( M0_arburst ),
    .M0_rdata   ( M0_rdata   ),
    .M0_rresp   ( M0_rresp   ),
    .M0_rvalid  ( M0_rvalid  ),
    .M0_rready  ( M0_rready  ),
    .M0_rlast   ( M0_rlast   ),
    .M0_rid     ( M0_rid     ),
    .M0_awaddr  ( M0_awaddr  ),
    .M0_awvalid ( M0_awvalid ),
    .M0_awready ( M0_awready ),
    .M0_awid    ( M0_awid    ),
    .M0_awlen   ( M0_awlen   ),
    .M0_awsize  ( M0_awsize  ),
    .M0_awburst ( M0_awburst ),
    .M0_wdata   ( M0_wdata   ),
    .M0_wstrb   ( M0_wstrb   ),
    .M0_wvalid  ( M0_wvalid  ),
    .M0_wready  ( M0_wready  ),
    .M0_wlast   ( M0_wlast   ),
    .M0_bresp   ( M0_bresp   ),
    .M0_bvalid  ( M0_bvalid  ),
    .M0_bready  ( M0_bready  ),
    .M0_bid     ( M0_bid     ),
    .M1_araddr  ( M1_araddr  ),
    .M1_arvalid ( M1_arvalid ),
    .M1_arready ( M1_arready ),
    .M1_arid    ( M1_arid    ),
    .M1_arlen   ( M1_arlen   ),
    .M1_arsize  ( M1_arsize  ),
    .M1_arburst ( M1_arburst ),
    .M1_rdata   ( M1_rdata   ),
    .M1_rresp   ( M1_rresp   ),
    .M1_rvalid  ( M1_rvalid  ),
    .M1_rready  ( M1_rready  ),
    .M1_rlast   ( M1_rlast   ),
    .M1_rid     ( M1_rid     ),
    .M1_awaddr  ( M1_awaddr  ),
    .M1_awvalid ( M1_awvalid ),
    .M1_awready ( M1_awready ),
    .M1_awid    ( M1_awid    ),
    .M1_awlen   ( M1_awlen   ),
    .M1_awsize  ( M1_awsize  ),
    .M1_awburst ( M1_awburst ),
    .M1_wdata   ( M1_wdata   ),
    .M1_wstrb   ( M1_wstrb   ),
    .M1_wvalid  ( M1_wvalid  ),
    .M1_wready  ( M1_wready  ),
    .M1_wlast   ( M1_wlast   ),
    .M1_bresp   ( M1_bresp   ),
    .M1_bvalid  ( M1_bvalid  ),
    .M1_bready  ( M1_bready  ),
    .M1_bid     ( M1_bid     ),
    .S0_araddr  ( S0_araddr  ),
    .S0_arvalid ( S0_arvalid ),
    .S0_arready ( S0_arready ),
    .S0_arid    ( S0_arid    ),
    .S0_arlen   ( S0_arlen   ),
    .S0_arsize  ( S0_arsize  ),
    .S0_arburst ( S0_arburst ),
    .S0_rdata   ( S0_rdata   ),
    .S0_rresp   ( S0_rresp   ),
    .S0_rvalid  ( S0_rvalid  ),
    .S0_rready  ( S0_rready  ),
    .S0_rlast   ( S0_rlast   ),
    .S0_rid     ( S0_rid     ),
    .S0_awaddr  ( S0_awaddr  ),
    .S0_awvalid ( S0_awvalid ),
    .S0_awready ( S0_awready ),
    .S0_awid    ( S0_awid    ),
    .S0_awlen   ( S0_awlen   ),
    .S0_awsize  ( S0_awsize  ),
    .S0_awburst ( S0_awburst ),
    .S0_wdata   ( S0_wdata   ),
    .S0_wstrb   ( S0_wstrb   ),
    .S0_wvalid  ( S0_wvalid  ),
    .S0_wready  ( S0_wready  ),
    .S0_wlast   ( S0_wlast   ),
    .S0_bresp   ( S0_bresp   ),
    .S0_bvalid  ( S0_bvalid  ),
    .S0_bready  ( S0_bready  ),
    .S0_bid     ( S0_bid     )
);

ysyx_24120011_Clint u_ysyx_24120011_Clint(
    .clk     ( clock     ),
    .rst     ( reset     ),
    .araddr  ( clint_araddr  ),
    .arvalid ( clint_arvalid ),
    .arready ( clint_arready ),
    .arid    ( clint_arid    ),
    .arlen   ( clint_arlen   ),
    .arsize  ( clint_arsize  ),
    .arburst ( clint_arburst ),
    .rdata   ( clint_rdata   ),
    .rresp   ( clint_rresp   ),
    .rvalid  ( clint_rvalid  ),
    .rready  ( clint_rready  ),
    .rlast   ( clint_rlast   ),
    .rid     ( clint_rid     ),
    .awaddr  ( clint_awaddr  ),
    .awvalid ( clint_awvalid ),
    .awready ( clint_awready ),
    .awid    ( clint_awid    ),
    .awlen   ( clint_awlen   ),
    .awsize  ( clint_awsize  ),
    .awburst ( clint_awburst ),
    .wdata   ( clint_wdata   ),
    .wstrb   ( clint_wstrb   ),
    .wvalid  ( clint_wvalid  ),
    .wready  ( clint_wready  ),
    .wlast   ( clint_wlast   ),
    .bresp   ( clint_bresp   ),
    .bvalid  ( clint_bvalid  ),
    .bready  ( clint_bready  ),
    .bid     ( clint_bid     )
);

ysyx_24120011_Xbar u_ysyx_24120011_Xbar(
    .clk             ( clock             ),
    .rst             ( reset             ),
    .Xbar_araddr     ( S0_araddr     ),
    .Xbar_arvalid    ( S0_arvalid    ),
    .Xbar_arready    ( S0_arready    ),
    .Xbar_arid       ( S0_arid       ),
    .Xbar_arlen      ( S0_arlen      ),
    .Xbar_arsize     ( S0_arsize     ),
    .Xbar_arburst    ( S0_arburst    ),
    .Xbar_rdata      ( S0_rdata      ),
    .Xbar_rresp      ( S0_rresp      ),
    .Xbar_rvalid     ( S0_rvalid     ),
    .Xbar_rready     ( S0_rready     ),
    .Xbar_rlast      ( S0_rlast      ),
    .Xbar_rid        ( S0_rid        ),
    .Xbar_awaddr     ( S0_awaddr     ),
    .Xbar_awvalid    ( S0_awvalid    ),
    .Xbar_awready    ( S0_awready    ),
    .Xbar_awid       ( S0_awid       ),
    .Xbar_awlen      ( S0_awlen      ),
    .Xbar_awsize     ( S0_awsize     ),
    .Xbar_awburst    ( S0_awburst    ),
    .Xbar_wdata      ( S0_wdata      ),
    .Xbar_wstrb      ( S0_wstrb      ),
    .Xbar_wvalid     ( S0_wvalid     ),
    .Xbar_wready     ( S0_wready     ),
    .Xbar_wlast      ( S0_wlast      ),
    .Xbar_bresp      ( S0_bresp      ),
    .Xbar_bvalid     ( S0_bvalid     ),
    .Xbar_bready     ( S0_bready     ),
    .Xbar_bid        ( S0_bid        ),
    .Xbar_S0_araddr  ( io_master_araddr  ),
    .Xbar_S0_arvalid ( io_master_arvalid ),
    .Xbar_S0_arready ( io_master_arready ),
    .Xbar_S0_arid    ( io_master_arid    ),
    .Xbar_S0_arlen   ( io_master_arlen   ),
    .Xbar_S0_arsize  ( io_master_arsize  ),
    .Xbar_S0_arburst ( io_master_arburst ),
    .Xbar_S0_rdata   ( io_master_rdata   ),
    .Xbar_S0_rresp   ( io_master_rresp   ),
    .Xbar_S0_rvalid  ( io_master_rvalid  ),
    .Xbar_S0_rready  ( io_master_rready  ),
    .Xbar_S0_rlast   ( io_master_rlast   ),
    .Xbar_S0_rid     ( io_master_rid     ),
    .Xbar_S0_awaddr  ( io_master_awaddr  ),
    .Xbar_S0_awvalid ( io_master_awvalid ),
    .Xbar_S0_awready ( io_master_awready ),
    .Xbar_S0_awid    ( io_master_awid    ),
    .Xbar_S0_awlen   ( io_master_awlen   ),
    .Xbar_S0_awsize  ( io_master_awsize  ),
    .Xbar_S0_awburst ( io_master_awburst ),
    .Xbar_S0_wdata   ( io_master_wdata   ),
    .Xbar_S0_wstrb   ( io_master_wstrb   ),
    .Xbar_S0_wvalid  ( io_master_wvalid  ),
    .Xbar_S0_wready  ( io_master_wready  ),
    .Xbar_S0_wlast   ( io_master_wlast   ),
    .Xbar_S0_bresp   ( io_master_bresp   ),
    .Xbar_S0_bvalid  ( io_master_bvalid  ),
    .Xbar_S0_bready  ( io_master_bready  ),
    .Xbar_S0_bid     ( io_master_bid     ),
    .Xbar_S1_araddr  ( clint_araddr      ),
    .Xbar_S1_arvalid ( clint_arvalid     ),
    .Xbar_S1_arready ( clint_arready     ),
    .Xbar_S1_arid    ( clint_arid        ),
    .Xbar_S1_arlen   ( clint_arlen       ),
    .Xbar_S1_arsize  ( clint_arsize      ),
    .Xbar_S1_arburst ( clint_arburst     ),
    .Xbar_S1_rdata   ( clint_rdata       ),
    .Xbar_S1_rresp   ( clint_rresp       ),
    .Xbar_S1_rvalid  ( clint_rvalid      ),
    .Xbar_S1_rready  ( clint_rready      ),
    .Xbar_S1_rlast   ( clint_rlast       ),
    .Xbar_S1_rid     ( clint_rid         ),
    .Xbar_S1_awaddr  ( clint_awaddr      ),
    .Xbar_S1_awvalid ( clint_awvalid     ),
    .Xbar_S1_awready ( clint_awready     ),
    .Xbar_S1_awid    ( clint_awid        ),
    .Xbar_S1_awlen   ( clint_awlen       ),
    .Xbar_S1_awsize  ( clint_awsize      ),
    .Xbar_S1_awburst ( clint_awburst     ),
    .Xbar_S1_wdata   ( clint_wdata       ),
    .Xbar_S1_wstrb   ( clint_wstrb       ),
    .Xbar_S1_wvalid  ( clint_wvalid      ),
    .Xbar_S1_wready  ( clint_wready      ),
    .Xbar_S1_wlast   ( clint_wlast       ),
    .Xbar_S1_bresp   ( clint_bresp       ),
    .Xbar_S1_bvalid  ( clint_bvalid      ),
    .Xbar_S1_bready  ( clint_bready      ),
    .Xbar_S1_bid     ( clint_bid         )

    // .Xbar_S2_araddr  (  ),
    // .Xbar_S2_arvalid (  ),
    // .Xbar_S2_arready (  ),
    // .Xbar_S2_arid    (  ),
    // .Xbar_S2_arlen   (  ),
    // .Xbar_S2_arsize  (  ),
    // .Xbar_S2_arburst (  ),
    // .Xbar_S2_rdata   (  ),
    // .Xbar_S2_rresp   (  ),
    // .Xbar_S2_rvalid  (  ),
    // .Xbar_S2_rready  (  ),
    // .Xbar_S2_rlast   (  ),
    // .Xbar_S2_rid     (  ),
    // .Xbar_S2_awaddr  (  ),
    // .Xbar_S2_awvalid (  ),
    // .Xbar_S2_awready (  ),
    // .Xbar_S2_awid    (  ),
    // .Xbar_S2_awlen   (  ),
    // .Xbar_S2_awsize  (  ),
    // .Xbar_S2_awburst (  ),
    // .Xbar_S2_wdata   (  ),
    // .Xbar_S2_wstrb   (  ),
    // .Xbar_S2_wvalid  (  ),
    // .Xbar_S2_wready  (  ),
    // .Xbar_S2_wlast   (  ),
    // .Xbar_S2_bresp   (  ),
    // .Xbar_S2_bvalid  (  ),
    // .Xbar_S2_bready  (  ),
    // .Xbar_S2_bid     (  )
);

endmodule