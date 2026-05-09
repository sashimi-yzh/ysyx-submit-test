`include "npc_config.vh"

module ysyx_25040102(
    input               clock,
    input               reset,

    input               io_interrupt,

    // output  [31:0]      Next_pc,
    // output  [31:0]      pc,

    input               io_master_awready,
    output              io_master_awvalid, 
    output  [31:0]      io_master_awaddr,  
    output  [3:0]       io_master_awid,    
    output  [7:0]       io_master_awlen,   
    output  [2:0]       io_master_awsize,  
    output  [1:0]       io_master_awburst, 
    input               io_master_wready,  
    output              io_master_wvalid,  
    output  [31:0]      io_master_wdata,   
    output  [3:0]       io_master_wstrb,   
    output              io_master_wlast,   
    output              io_master_bready,  
    input               io_master_bvalid,  
    input   [1:0]       io_master_bresp,   
    input   [3:0]       io_master_bid,     
    input               io_master_arready, 
    output              io_master_arvalid, 
    output  [31:0]      io_master_araddr,  
    output  [3:0]       io_master_arid,    
    output  [7:0]       io_master_arlen,   
    output  [2:0]       io_master_arsize,  
    output  [1:0]       io_master_arburst, 
    output              io_master_rready,  
    input               io_master_rvalid,  
    input   [1:0]       io_master_rresp,   
    input   [31:0]      io_master_rdata,   
    input               io_master_rlast,   
    input   [3:0]       io_master_rid,

    output              io_slave_awready, 
    input               io_slave_awvalid, 
    input   [31:0]      io_slave_awaddr,  
    input   [3:0]       io_slave_awid,    
    input   [7:0]       io_slave_awlen,   
    input   [2:0]       io_slave_awsize,  
    input   [1:0]       io_slave_awburst, 
    output              io_slave_wready,  
    input               io_slave_wvalid,  
    input   [31:0]      io_slave_wdata,   
    input   [3:0]       io_slave_wstrb,   
    input               io_slave_wlast,   
    input               io_slave_bready,  
    output              io_slave_bvalid,  
    output  [1:0]       io_slave_bresp,   
    output  [3:0]       io_slave_bid,     
    output              io_slave_arready, 
    input               io_slave_arvalid, 
    input   [31:0]      io_slave_araddr,  
    input   [3:0]       io_slave_arid,    
    input   [7:0]       io_slave_arlen,   
    input   [2:0]       io_slave_arsize,  
    input   [1:0]       io_slave_arburst, 
    input               io_slave_rready,  
    output              io_slave_rvalid,  
    output  [1:0]       io_slave_rresp,   
    output  [31:0]      io_slave_rdata,   
    output              io_slave_rlast,   
    output  [3:0]       io_slave_rid    

);

    assign  io_slave_awready    = 0;
    assign  io_slave_wready     = 0;
    assign  io_slave_bvalid     = 0;
    assign  io_slave_bresp      = 0;
    assign  io_slave_bid        = 0;
    assign  io_slave_arready    = 0;
    assign  io_slave_rvalid     = 0;   
    assign  io_slave_rresp      = 0;  
    assign  io_slave_rdata      = 0;  
    assign  io_slave_rlast      = 0;  
    assign  io_slave_rid        = 0;


    wire    [3:0]       Ra;
    wire    [3:0]       Rb;
    wire    [3:0]       Rw;


    // output declaration of module IFU_ysyx
    // wire    [31:0]      inst;
    // wire                inst_valid;
    wire                inst_ready;
   
    wire                ifu_arready; 
    wire                ifu_arvalid;
    wire    [31:0]      ifu_araddr;  
    wire    [3:0]       ifu_arid;    
    wire    [7:0]       ifu_arlen;   
    wire    [2:0]       ifu_arsize;  
    wire    [1:0]       ifu_arburst; 
    wire                ifu_rready;  
    wire                ifu_rvalid;  
    wire    [1:0]       ifu_rresp;   
    wire    [31:0]      ifu_rdata;   
    wire                ifu_rlast;   
    wire    [3:0]       ifu_rid;

    // wire    [31:0]      pc_wb_if;

    wire                pc_ready;

    wire                pc_valid;

    wire    [31:0]      ifu_paddr;
    wire                ifu_psel;
    // wire                ifu_penable;
    wire                ifu_pready;
    wire    [31:0]      ifu_prdata;
    wire                ifu_pslverr;
    wire    [31:0]      snpc;
    wire                flush;

    wire [31:0] pc_if_id;

    // output declaration of module IDU_ysyx
    // wire inst_ready;
    wire        decode_valid;
    wire [31:0] imm;
    wire        RegWr;
    wire [2:0]  Branch;
    wire        MemtoReg;
    wire        MemWr;
    wire [2:0]  MemOp;
    wire        ALUAsrc;
    wire        ALUBsrc;
    wire [3:0]  ALUctr;
    wire [1:0]  mRegWr;
    // wire [3:0] csr_mode;
    // wire        ebreak_id_ex;
    wire [31:0] snpc_id;

    wire [3:0]    mcause_id;
    wire          mcause_wr_id;
    wire          mret;

    // output declaration of module EXU_ysyx
    wire decode_ready;
    wire lsu_valid;

    wire [31:0] lsu_data;
    wire [1:0] lsu_mode;
    wire [2:0] lsu_op;

    wire    [3:0]   mcause;
    wire            mcause_wr;
    wire    [31:0]  pc_mreg;

    wire    [31:0]      Next_pc_ls_wb;
    wire    [3:0]       Rw_ls_wb;
    wire    [31:0]      result_ls_wb;
    wire                regwr_ls_wb;
    wire    [1:0]       lsu_mode_out;
    wire    [31:0]      pc_ls;
    wire                mcause_wr_ls;
    wire    [3:0]       mcause_ls;

    assign  mcause_wr   = mcause_wr_ls;
    assign  mcause      = mcause_ls;
    assign  pc_mreg     = pc_ls;

    wire [31:0] Next_pc;
    wire [3:0] Rw_ex_ls;
    wire [31:0] result_ex_ls;
    wire regwr_ex_ls;

    wire        lsu_ready;
    wire        flush_id_ex;
    wire [31:0] pc_ex_ls;

    wire [3:0]  mcause_ex;
    wire        mcause_wr_ex;

    wire    [7:0]   imm_mreg    = imm[7:0];
    wire    [31:0]  mreg_data;
    wire    csr_wr  = (decode_ready && decode_valid) ? mRegWr[0] : 1'b0;
    reg     [31:0]  wrData;
    wire    [31:0]  dnpc_r;
    wire    mpcWr;
    wire    [31:0]  mretPc;

    wire    [31:0]  pc_id_ex;
    wire    [31:0]  rs1;
    wire    [31:0]  rs2;

    wire    [31:0]  dataA;
    wire    [31:0]  dataB;
    reg     [31:0]  rs1_forward;
    reg     [31:0]  rs2_forward;

    
    ysyx_25040102_IFU_ysyx u_IFU_ysyx(
        .clk        	    (clock          ),
        .reset      	    (reset          ),
        // .inst       	    (inst           ),
        .pc_out             (pc_if_id       ),
        .pc_exu      	    (Next_pc        ),
        .pc_valid   	    (pc_valid       ), // WBU
        .pc_ready   	    (pc_ready       ), // WBU
        .flush              (flush              ),
        // .flush_finish       (flush_finish       ),
        .snpc               (snpc               ),
        .in_paddr           (ifu_paddr          ),
        .in_psel            (ifu_psel           ),
        .in_pready          (ifu_pready         )
    );
    
    ysyx_25040102_iCache #(
        .N(`ysyx_25040102_ICACHE_N), // 16块
        .M(`ysyx_25040102_ICACHE_M) //  每块8byte
    )u_iCache(
        .clock          	(clock           ),
        .reset          	(reset           ),
        .in_paddr       	(ifu_paddr       ),
        .in_psel        	(ifu_psel        ),
        .in_penable     	(inst_ready      ), // IDU_ready
        .in_pready      	(ifu_pready      ),
        .in_prdata      	(ifu_prdata      ),
        .in_pslverr     	(ifu_pslverr     ),
        // 
        .master_arready 	(ifu_arready     ),
        .master_arvalid 	(ifu_arvalid     ),
        .master_araddr  	(ifu_araddr      ),
        .master_arid    	(ifu_arid        ),
        .master_arlen   	(ifu_arlen       ),
        .master_arsize  	(ifu_arsize      ),
        .master_arburst 	(ifu_arburst     ),
        .master_rready  	(ifu_rready      ),
        .master_rvalid  	(ifu_rvalid      ),
        .master_rresp   	(ifu_rresp       ),
        .master_rdata   	(ifu_rdata       ),
        .master_rlast   	(ifu_rlast       ),
        .master_rid     	(ifu_rid         )
    );
    
    ysyx_25040102_IDU_ysyx u_IDU_ysyx(
        .clk          	    (clock         ),
        .reset        	    (reset         ),
        
        .pc           	    (pc_if_id      ),
        .snpc               (snpc          ),
        .pc_out             (pc_id_ex      ),
        .snpc_out       	(snpc_id       ),

        .inst_valid   	    (ifu_pready    ), // icache返回指令
        .inst_ready   	    (inst_ready    ),
        .inst         	    (ifu_prdata    ),
        .in_pslverr         (ifu_pslverr),
        .flush_finish       (flush          ),
        .flush_finish_out   (flush_id_ex    ),
        .pc_valid           (pc_valid       ),

        .Rw_exu             (Rw_ex_ls       ),
        .load_exu           (lsu_mode       ),
        .Rw_lsu             (Rw_ls_wb       ),
        .load_lsu           (lsu_mode_out   ),

        .decode_ready 	    (decode_ready  ),
        .decode_valid 	    (decode_valid  ),

        .imm          	    (imm           ),
        .RegWr        	    (RegWr         ),
        .Branch       	    (Branch        ),
        .MemtoReg     	    (MemtoReg      ),
        .MemWr        	    (MemWr         ),
        .MemOp        	    (MemOp         ),
        .ALUAsrc      	    (ALUAsrc       ),
        .ALUBsrc      	    (ALUBsrc       ),
        .ALUctr       	    (ALUctr        ),
        .mRegWr       	    (mRegWr        ),
        .mcause             (mcause_id   ),
        .mcause_wr          (mcause_wr_id),
        .mret               (mret     ),

        .Ra           	    (Ra            ),
        .Rb           	    (Rb            ),
        .Rw           	    (Rw            )
    );

    always @(*) begin
        if(mRegWr == 2'b01) begin
            wrData      = rs1_forward;
        end
        else if(mRegWr == 2'b11) begin
            wrData      = mreg_data | rs1_forward;
        end
        else begin
            wrData      = 32'h0;
        end
    end

    ysyx_25040102_mReg u_mReg(
        .clk        (clock      ),
        .mcause     (mcause     ),
        .mcause_wr  (mcause_wr  ),
        .mret       (mret       ),
        .imm        (imm_mreg   ),
        .mpcWr      (mpcWr      ), // to PC_ysyx
        .mRegData   (mreg_data  ), // to reg
        .mRegwr     (csr_wr     ), // write en
        .mretPc 	(mretPc     ), // to PC_ysyx
        .mcause_pc  (mcause_wr_id),
        .pc         (pc_mreg    ), // pc
        .wrData     (wrData     )  // write data
    );

    // dnpc for branch
    assign  dnpc_r  = pc_id_ex + imm;

    always @(*) begin
        if(Rw_ex_ls == Ra && Rw_ex_ls != 0 && regwr_ex_ls == 1'b1 && lsu_mode != 2'b01) begin
            rs1_forward     = result_ex_ls;
        end
        else if(Rw_ls_wb == Ra && Rw_ls_wb != 0 && regwr_ls_wb == 1'b1 && lsu_mode != 2'b01) begin
            rs1_forward     = result_ls_wb;
        end
        else begin
            rs1_forward     = rs1;
        end
    end

    always @(*) begin
        if(Rw_ex_ls == Rb && Rw_ex_ls != 0 && regwr_ex_ls == 1'b1 && lsu_mode != 2'b01) begin
            rs2_forward     = result_ex_ls;
        end
        else if(Rw_ls_wb == Rb && Rw_ls_wb != 0 && regwr_ls_wb == 1'b1 && lsu_mode != 2'b01) begin
            rs2_forward     = result_ls_wb;
        end
        else begin
            rs2_forward     = rs2;
        end
    end

    ysyx_25040102_MuxKey #(2, 1, 32) u_mux1(
        dataA,
        ALUAsrc,
        {
            1'b1, pc_id_ex,
            1'b0, rs1_forward
        }
    );

    ysyx_25040102_MuxKey #(2, 1, 32) u_mux2(
        dataB,
        ALUBsrc,
        {
            1'b0, rs2_forward,
            1'b1, imm
        }
    );

    ysyx_25040102_RegisterFile #(4, 32) u_register
    (
        .clk                (clock          ),
        .busW               (result_ls_wb     ),
        .Ra                 (Ra             ),
        .Rb                 (Rb             ),
        .Rw                 (Rw_ls_wb         ),
        .Regwr              (regwr_ls_wb      ),
        .busA               (rs1            ),
        .busB               (rs2            )
    );

    // output declaration of module ALU_ysyx
    wire less;
    wire is_compare;
    wire [31:0] result;
    
    ysyx_25040102_ALU_ysyx u_ALU_ysyx(
        .dataA      (dataA         ),
        .dataB      (dataB         ),
        .ALUctr  	(ALUctr     ),
        .less    	(less       ),
        .is_compare (is_compare       ),
        .result  	(result     )
    );

    wire    [31:0]  snpc_id_ex;
    assign  snpc_id_ex  = (mpcWr == 1'b1) ? mretPc : snpc_id;

    wire    [31:0]  result_ex;
    assign  result_ex   = (mRegWr == 2'b11) ? mreg_data : result; 
    

    
    ysyx_25040102_EXU_ysyx u_EXU_ysyx(
        .clk          	    (clock         ),
        .reset        	    (reset         ),
        .rs2          	    (rs2_forward   ),

        .decode_valid 	    (decode_valid  ),
        .decode_ready 	    (decode_ready  ),
        .lsu_ready    	    (lsu_ready     ),
        .lsu_valid    	    (lsu_valid     ),
        .flush_finish       (flush_id_ex   ),
        .mpcWr              (mpcWr         ),
        .pc                 (pc_id_ex),

        .mcause             (mcause_id),
        .mcause_out         (mcause_ex),
        .mcause_wr          (mcause_wr_id),
        .mcause_wr_out      (mcause_wr_ex),


        .result             (result_ex),
        .less               (less),
        .is_compare         (is_compare),

        // lsu ctrl
        .lsu_data     	    (lsu_data      ),
        .lsu_mode     	    (lsu_mode      ),
        .lsu_op       	    (lsu_op        ),

        // reg ctrl
        .dnpc               (dnpc_r        ),
        .snpc               (snpc_id_ex    ),
        .pc_ready           (pc_ready      ),
        .pc_valid           (pc_valid      ),

        .Rw_out       	    (Rw_ex_ls      ),
        .result_out   	    (result_ex_ls  ),
        .regwr_out    	    (regwr_ex_ls   ),
        .pc_out             (pc_ex_ls),

        .RegWr        	    (RegWr         ),
        .branch       	    (Branch        ),
        .MemtoReg     	    (MemtoReg      ),
        .MemWr        	    (MemWr         ),
        .MemOp        	    (MemOp         ),
        .Next_pc            (Next_pc       ),
        .Rw           	    (Rw            )
    );

    // lsu AXI4
    // Address Read
    wire                lsu_awready;
    wire                lsu_awvalid; 
    wire    [31:0]      lsu_awaddr;  
    wire    [3:0]       lsu_awid;    
    wire    [7:0]       lsu_awlen;   
    wire    [2:0]       lsu_awsize;  
    wire    [1:0]       lsu_awburst; 
    wire                lsu_wready;  
    wire                lsu_wvalid;  
    wire    [31:0]      lsu_wdata;   
    wire    [3:0]       lsu_wstrb;   
    wire                lsu_wlast;   
    wire                lsu_bready;  
    wire                lsu_bvalid;  
    wire    [1:0]       lsu_bresp;   
    wire    [3:0]       lsu_bid;     
    wire                lsu_arready; 
    wire                lsu_arvalid;
    wire    [31:0]      lsu_araddr;  
    wire    [3:0]       lsu_arid;    
    wire    [7:0]       lsu_arlen;   
    wire    [2:0]       lsu_arsize;  
    wire    [1:0]       lsu_arburst; 
    wire                lsu_rready;  
    wire                lsu_rvalid;  
    wire    [1:0]       lsu_rresp;   
    wire    [31:0]      lsu_rdata;   
    wire                lsu_rlast;   
    wire    [3:0]       lsu_rid;

    // wire                ebreak_ls_wb;
    ysyx_25040102_LSU_ysyx u_LSU_ysyx(
        .clk         	    (clock          ),
        .reset       	    (reset          ),
        // lsu ctrl
        .lsu_data    	    (lsu_data       ),
        .lsu_mode    	    (lsu_mode       ),
        .lsu_op      	    (lsu_op         ),
        .pc                 (pc_ex_ls),
        .pc_out             (pc_ls),

        .mcause             (mcause_ex),
        .mcause_wr          (mcause_wr_ex),
        .mcause_out         (mcause_ls  ),
        .mcause_wr_out      (mcause_wr_ls),

        .Rw          	    (Rw_ex_ls       ),
        .result      	    (result_ex_ls   ),
        .regwr       	    (regwr_ex_ls    ),
        .Next_pc            (Next_pc        ),
        .Next_pc_out 	    (Next_pc_ls_wb  ),
        .Rw_out      	    (Rw_ls_wb       ),
        .result_out  	    (result_ls_wb   ),
        .regwr_out   	    (regwr_ls_wb    ),

        .lsu_valid   	    (lsu_valid      ),
        .lsu_ready   	    (lsu_ready      ),
        .lsu_mode_out       (lsu_mode_out   ),

        .master_awready     (lsu_awready    ),     
        .master_awvalid     (lsu_awvalid    ),     
        .master_awaddr      (lsu_awaddr     ),    
        .master_awid        (lsu_awid       ),  
        .master_awlen       (lsu_awlen      ),   
        .master_awsize      (lsu_awsize     ),    
        .master_awburst     (lsu_awburst    ),     
        .master_wready      (lsu_wready     ),    
        .master_wvalid      (lsu_wvalid     ),    
        .master_wdata       (lsu_wdata      ),   
        .master_wstrb       (lsu_wstrb      ),   
        .master_wlast       (lsu_wlast      ),   
        .master_bready      (lsu_bready     ),    
        .master_bvalid      (lsu_bvalid     ),    
        .master_bresp       (lsu_bresp      ),   
        .master_bid         (lsu_bid        ), 
        .master_arready     (lsu_arready    ),    
        .master_arvalid     (lsu_arvalid    ),    
        .master_araddr      (lsu_araddr     ),   
        .master_arid        (lsu_arid       ), 
        .master_arlen       (lsu_arlen      ),  
        .master_arsize      (lsu_arsize     ),   
        .master_arburst     (lsu_arburst    ),    
        .master_rready      (lsu_rready     ),   
        .master_rvalid      (lsu_rvalid     ),   
        .master_rresp       (lsu_rresp      ),  
        .master_rdata       (lsu_rdata      ),  
        .master_rlast       (lsu_rlast      ),  
        .master_rid         (lsu_rid        )
    );

    // output declaration of module xBar

    wire                clint_slave_awready;
    wire                clint_slave_awvalid; 
    wire    [31:0]      clint_slave_awaddr;  
    wire    [3:0]       clint_slave_awid;    
    wire    [7:0]       clint_slave_awlen;   
    wire    [2:0]       clint_slave_awsize;  
    wire    [1:0]       clint_slave_awburst; 
    wire                clint_slave_wready;  
    wire                clint_slave_wvalid;  
    wire    [31:0]      clint_slave_wdata;   
    wire    [3:0]       clint_slave_wstrb;   
    wire                clint_slave_wlast;
    wire                clint_slave_bready;  
    wire                clint_slave_bvalid;  
    wire    [1:0]       clint_slave_bresp;   
    wire    [3:0]       clint_slave_bid;  
    wire                clint_slave_arready; 
    wire                clint_slave_arvalid; 
    wire    [31:0]      clint_slave_araddr;  
    wire    [3:0]       clint_slave_arid;    
    wire    [7:0]       clint_slave_arlen;   
    wire    [2:0]       clint_slave_arsize;  
    wire    [1:0]       clint_slave_arburst; 
    wire                clint_slave_rready;  
    wire                clint_slave_rvalid;  
    wire    [1:0]       clint_slave_rresp;   
    wire    [31:0]      clint_slave_rdata;   
    wire                clint_slave_rlast;   
    wire    [3:0]       clint_slave_rid;    


    ysyx_25040102_xBar u_xBar(
        .clk               	(clock              ),
        .reset             	(reset              ),
        .ifu_arready       	(ifu_arready        ),
        .ifu_arvalid       	(ifu_arvalid        ),
        .ifu_araddr        	(ifu_araddr         ),
        .ifu_arid          	(ifu_arid           ),
        .ifu_arlen         	(ifu_arlen          ),
        .ifu_arsize        	(ifu_arsize         ),
        .ifu_arburst       	(ifu_arburst        ),
        .ifu_rready        	(ifu_rready         ),
        .ifu_rvalid        	(ifu_rvalid         ),
        .ifu_rresp         	(ifu_rresp          ),
        .ifu_rdata         	(ifu_rdata          ),
        .ifu_rlast         	(ifu_rlast          ),
        .ifu_rid           	(ifu_rid            ),
        .lsu_awready       	(lsu_awready        ),
        .lsu_awvalid       	(lsu_awvalid        ),
        .lsu_awaddr        	(lsu_awaddr         ),
        .lsu_awid          	(lsu_awid           ),
        .lsu_awlen         	(lsu_awlen          ),
        .lsu_awsize        	(lsu_awsize         ),
        .lsu_awburst       	(lsu_awburst        ),
        .lsu_wready        	(lsu_wready         ),
        .lsu_wvalid        	(lsu_wvalid         ),
        .lsu_wdata         	(lsu_wdata          ),
        .lsu_wstrb         	(lsu_wstrb          ),
        .lsu_wlast         	(lsu_wlast          ),
        .lsu_bready        	(lsu_bready         ),
        .lsu_bvalid        	(lsu_bvalid         ),
        .lsu_bresp         	(lsu_bresp          ),
        .lsu_bid           	(lsu_bid            ),
        .lsu_arready       	(lsu_arready        ),
        .lsu_arvalid       	(lsu_arvalid        ),
        .lsu_araddr        	(lsu_araddr         ),
        .lsu_arid          	(lsu_arid           ),
        .lsu_arlen         	(lsu_arlen          ),
        .lsu_arsize        	(lsu_arsize         ),
        .lsu_arburst       	(lsu_arburst        ),
        .lsu_rready        	(lsu_rready         ),
        .lsu_rvalid        	(lsu_rvalid         ),
        .lsu_rresp         	(lsu_rresp          ),
        .lsu_rdata         	(lsu_rdata          ),
        .lsu_rlast         	(lsu_rlast          ),
        .lsu_rid           	(lsu_rid            ),
        .io_master_awready 	(io_master_awready  ),
        .io_master_awvalid 	(io_master_awvalid  ),
        .io_master_awaddr  	(io_master_awaddr   ),
        .io_master_awid    	(io_master_awid     ),
        .io_master_awlen   	(io_master_awlen    ),
        .io_master_awsize  	(io_master_awsize   ),
        .io_master_awburst 	(io_master_awburst  ),
        .io_master_wready  	(io_master_wready   ),
        .io_master_wvalid  	(io_master_wvalid   ),
        .io_master_wdata   	(io_master_wdata    ),
        .io_master_wstrb   	(io_master_wstrb    ),
        .io_master_wlast   	(io_master_wlast    ),
        .io_master_bready  	(io_master_bready   ),
        .io_master_bvalid  	(io_master_bvalid   ),
        .io_master_bresp   	(io_master_bresp    ),
        .io_master_bid     	(io_master_bid      ),
        .io_master_arready 	(io_master_arready  ),
        .io_master_arvalid 	(io_master_arvalid  ),
        .io_master_araddr  	(io_master_araddr   ),
        .io_master_arid    	(io_master_arid     ),
        .io_master_arlen   	(io_master_arlen    ),
        .io_master_arsize  	(io_master_arsize   ),
        .io_master_arburst 	(io_master_arburst  ),
        .io_master_rready  	(io_master_rready   ),
        .io_master_rvalid  	(io_master_rvalid   ),
        .io_master_rresp   	(io_master_rresp    ),
        .io_master_rdata   	(io_master_rdata    ),
        .io_master_rlast   	(io_master_rlast    ),
        .io_master_rid     	(io_master_rid      ),
        .clint_master_awready    (clint_slave_awready),
        .clint_master_awvalid    (clint_slave_awvalid), 
        .clint_master_awaddr     (clint_slave_awaddr),  
        .clint_master_awid       (clint_slave_awid),    
        .clint_master_awlen      (clint_slave_awlen),   
        .clint_master_awsize     (clint_slave_awsize),  
        .clint_master_awburst    (clint_slave_awburst), 
        .clint_master_wready     (clint_slave_wready),  
        .clint_master_wvalid     (clint_slave_wvalid),  
        .clint_master_wdata      (clint_slave_wdata),   
        .clint_master_wstrb      (clint_slave_wstrb),   
        .clint_master_wlast      (clint_slave_wlast),
        .clint_master_bready     (clint_slave_bready),  
        .clint_master_bvalid     (clint_slave_bvalid),  
        .clint_master_bresp      (clint_slave_bresp),   
        .clint_master_bid        (clint_slave_bid),  
        .clint_master_arready    (clint_slave_arready), 
        .clint_master_arvalid    (clint_slave_arvalid), 
        .clint_master_araddr     (clint_slave_araddr),  
        .clint_master_arid       (clint_slave_arid),    
        .clint_master_arlen      (clint_slave_arlen),   
        .clint_master_arsize     (clint_slave_arsize),  
        .clint_master_arburst    (clint_slave_arburst), 
        .clint_master_rready     (clint_slave_rready),  
        .clint_master_rvalid     (clint_slave_rvalid),  
        .clint_master_rresp      (clint_slave_rresp),   
        .clint_master_rdata      (clint_slave_rdata),   
        .clint_master_rlast      (clint_slave_rlast),   
        .clint_master_rid        (clint_slave_rid)

    );

    ysyx_25040102_clint u_clint(
        .clk                    (   clock),
        .reset                  (   reset),
        .clint_slave_awready    (clint_slave_awready),
        .clint_slave_awvalid    (clint_slave_awvalid), 
        .clint_slave_awaddr     (clint_slave_awaddr),  
        .clint_slave_awid       (clint_slave_awid),    
        .clint_slave_awlen      (clint_slave_awlen),   
        .clint_slave_awsize     (clint_slave_awsize),  
        .clint_slave_awburst    (clint_slave_awburst), 
        .clint_slave_wready     (clint_slave_wready),  
        .clint_slave_wvalid     (clint_slave_wvalid),  
        .clint_slave_wdata      (clint_slave_wdata),   
        .clint_slave_wstrb      (clint_slave_wstrb),   
        .clint_slave_wlast      (clint_slave_wlast),
        .clint_slave_bready     (clint_slave_bready),  
        .clint_slave_bvalid     (clint_slave_bvalid),  
        .clint_slave_bresp      (clint_slave_bresp),   
        .clint_slave_bid        (clint_slave_bid),  
        .clint_slave_arready    (clint_slave_arready), 
        .clint_slave_arvalid    (clint_slave_arvalid), 
        .clint_slave_araddr     (clint_slave_araddr),  
        .clint_slave_arid       (clint_slave_arid),    
        .clint_slave_arlen      (clint_slave_arlen),   
        .clint_slave_arsize     (clint_slave_arsize),  
        .clint_slave_arburst    (clint_slave_arburst), 
        .clint_slave_rready     (clint_slave_rready),  
        .clint_slave_rvalid     (clint_slave_rvalid),  
        .clint_slave_rresp      (clint_slave_rresp),   
        .clint_slave_rdata      (clint_slave_rdata),   
        .clint_slave_rlast      (clint_slave_rlast),   
        .clint_slave_rid        (clint_slave_rid)
);

endmodule
