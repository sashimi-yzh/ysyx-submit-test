`include "../include/ysyx_23060299_npc_defines.v"

module ysyx_23060299 (
    input   wire            clock               ,
    input   wire            reset               ,

`ifdef __ICARUS__
`ifndef NETLIST
	output  reg             sim_end             ,
	output          [31:0]  return_value        ,
`endif
`endif

// `ifdef ysyx_23060299_verilator_env
    input   wire            io_interrupt        ,
// `endif
   
    input   wire            io_master_awready   ,
    output  wire            io_master_awvalid   ,
    output  wire    [31:0]  io_master_awaddr    ,
    output  wire    [3:0]   io_master_awid      ,
    output  wire    [7:0]   io_master_awlen     ,
    output  wire    [2:0]   io_master_awsize    ,
    output  wire    [1:0]   io_master_awburst   ,
    input   wire            io_master_wready    ,
    output  wire            io_master_wvalid    ,
    output  wire    [31:0]  io_master_wdata     ,
    output  wire    [3:0]   io_master_wstrb     ,
    output  wire            io_master_wlast     ,
    output  wire            io_master_bready    ,
    input   wire            io_master_bvalid    ,
    input   wire    [1:0]   io_master_bresp     ,
    input   wire    [3:0]   io_master_bid       ,
    input   wire            io_master_arready   ,
    output  wire            io_master_arvalid   ,
    output  wire    [31:0]  io_master_araddr    ,
    output  wire    [3:0]   io_master_arid      ,
    output  wire    [7:0]   io_master_arlen     ,
    output  wire    [2:0]   io_master_arsize    ,
    output  wire    [1:0]   io_master_arburst   ,
    output  wire            io_master_rready    ,
    input   wire            io_master_rvalid    ,
    input   wire    [1:0]   io_master_rresp     ,
    input   wire    [31:0]  io_master_rdata     ,
    input   wire            io_master_rlast     ,
    input   wire    [3:0]   io_master_rid       ,

    output  wire            io_slave_awready    ,

// `ifdef ysyx_23060299_verilator_env
    input   wire            io_slave_awvalid    ,
    input   wire    [31:0]  io_slave_awaddr     ,
    input   wire    [3:0]   io_slave_awid       ,
    input   wire    [7:0]   io_slave_awlen      ,
    input   wire    [2:0]   io_slave_awsize     ,
    input   wire    [1:0]   io_slave_awburst    ,
// `endif

    output  wire            io_slave_wready     ,

// `ifdef ysyx_23060299_verilator_env
    input   wire            io_slave_wvalid     ,
    input   wire    [31:0]  io_slave_wdata      ,  
    input   wire    [3:0]   io_slave_wstrb      ,  
    input   wire            io_slave_wlast      ,  
    input   wire            io_slave_bready     ,
// `endif

    output  wire            io_slave_bvalid     ,
    output  wire    [1:0]   io_slave_bresp      , 
    output  wire    [3:0]   io_slave_bid        ,  
    output  wire            io_slave_arready    , 

// `ifdef ysyx_23060299_verilator_env
    input   wire            io_slave_arvalid    ,    
    input   wire    [31:0]  io_slave_araddr     , 
    input   wire    [3:0]   io_slave_arid       ,  
    input   wire    [7:0]   io_slave_arlen      , 
    input   wire    [2:0]   io_slave_arsize     ,
    input   wire    [1:0]   io_slave_arburst    ,    
    input   wire            io_slave_rready     ,
// `endif

    output  wire            io_slave_rvalid     ,
    output  wire    [1:0]   io_slave_rresp      ,  
    output  wire    [31:0]  io_slave_rdata      ,  
    output  wire            io_slave_rlast      ,  
    output  wire    [3:0]   io_slave_rid         
);

// unused
assign  io_slave_awready    =   'd0 ;
assign  io_slave_wready     =   'd0 ;
assign  io_slave_bvalid     =   'd0 ;
assign  io_slave_bresp      =   'd0 ;
assign  io_slave_bid        =   'd0 ;
assign  io_slave_arready    =   'd0 ;
assign  io_slave_rvalid     =   'd0 ;
assign  io_slave_rresp      =   'd0 ;
assign  io_slave_rdata      =   'd0 ;
assign  io_slave_rlast      =   'd0 ;
assign  io_slave_rid        =   'd0 ;

// IFU --- ICACHE
wire    [31:0]  cpu_cache_addr  ;
wire            cpu_cache_valid ;
`ifdef ysyx_23060299_NPC
reg     [31:0]  cache_cpu_data  ;
wire            cache_cpu_ready ;
reg             cache_cpu_valid ;
`else
wire    [31:0]  cache_cpu_data  ;
wire            cache_cpu_ready ;
wire            cache_cpu_valid ;
`endif
wire            cache_mask      ;
wire            fence_i         ;
    
// ICACHE --- SDRAM
wire    [31:0]  araddr_m0   ;
wire            arvalid_m0  ;
wire            arready_m0  ;   
wire    [7:0]   arlen_m0    ;     
wire    [2:0]   arsize_m0   ;     
wire    [1:0]   arburst_m0  ;     
wire    [31:0]  rdata_m0    ;
wire    [1:0]   rresp_m0    ;
wire            rvalid_m0   ;
wire            rready_m0   ;
wire            rlast_m0    ;

// IFU --- IDEXU
wire    [31:0]  pc_IDEXU        ;
wire    [31:0]  inst_idu        ;
wire            ifu_valid       ;
wire            idexu_ready     ;
wire            need_jump_ifu   ;
wire            branch_inst_ifu ;
wire    [31:0]  pc_jump         ;
wire            jump_inst       ;

// IDEXU --- REG
wire    [`ysyx_23060299_REG_ADDR_WIDTH - 1:0] rs1_idx     ;
wire    [`ysyx_23060299_REG_ADDR_WIDTH - 1:0] rs2_idx     ;
wire                            rs1_ren     ;
wire                            rs2_ren     ;
wire    [31:0]                  rs1_IDEXU   ;
wire    [31:0]                  rs2_IDEXU   ;

//  IDEXU --- CSR
wire    [11:0]  csr_raddr       ;
wire            csr_ren         ;
wire    [31:0]  csr_wdata       ;
wire    [11:0]  csr_waddr       ;
wire            csr_wen         ;
wire    [31:0]  csr_rdata       ;
wire    [31:0]  pc_csr          ;
wire            ecall_csr       ;
wire            mret_csr        ;

//  IDEXU --- LSU
wire                            wr_en_lsu           ;
wire    [`ysyx_23060299_REG_ADDR_WIDTH - 1:0] rd_idx_lsu          ;
wire                            lw_lsu              ;
wire                            lbu_lsu             ;
wire                            lb_lsu              ;
wire                            lh_lsu              ;
wire                            lhu_lsu             ;
wire                            sw_lsu              ;
wire                            sh_lsu              ;
wire                            sb_lsu              ;
wire    [31:0]                  exu_result_lsu      ;
wire    [31:0]                  rs2_lsu             ;
wire                            idexu_valid         ;
wire                            lsu_ready           ;
wire                            lsu_rhandshake_d1   ;

// LSU --- WBU
wire    [`ysyx_23060299_REG_ADDR_WIDTH - 1:0] rd_idx_wbu      ;
wire                            wr_en_wbu       ;
wire    [31:0]                  load_result     ;
wire                            load_inst_wbu   /* verilator public_flat_rd */;
wire    [31:0]                  exu_result_wbu  ;
wire                            lsu_valid       ;
wire                            wbu_ready       ;

// LSU --- LSU_RAM
wire            awvalid_m1      ;
wire            awready_m1      ;
wire    [31:0]  awaddr_m1       ;
wire    [2:0]   awsize_m1       ;
wire            wvalid_m1       ;
wire            wready_m1       ;
wire    [31:0]  wdata_m1        ;
wire    [3:0]   wstrb_m1        ;
wire    [1:0]   bresp_m1        ;
wire            bvalid_m1       ;
wire            bready_m1       ;
wire    [31:0]  araddr_m1       ;
wire    [2:0]   arsize_m1       ;
wire            arvalid_m1      ;
wire            arready_m1      ;
`ifdef ysyx_23060299_NPC
reg     [31:0]  rdata_m1        ;
wire    [1:0]   rresp_m1        ;
reg             rvalid_m1       ;
wire            rready_m1       ;
`else
wire    [31:0]  rdata_m1        ;
wire    [1:0]   rresp_m1        ;
wire            rvalid_m1       ;
wire            rready_m1       ;
`endif

// WBU --- REG
wire    [31:0]                  wbu_result      ;
wire    [`ysyx_23060299_REG_ADDR_WIDTH - 1:0] rd_idx          ;
wire                            reg_wren        ;

// signal to debug, can be removed
wire    [31:0]  pc_LSU  ;
wire    [31:0]  pc_WBU  ;

// AXI-BUS --- RAM
wire            awvalid_s0      ;
wire            awready_s0      ;
wire    [31:0]  awaddr_s0       ;
wire            wvalid_s0       ;
wire            wready_s0       ;
wire    [31:0]  wdata_s0        ;
wire    [3:0]   wstrb_s0        ;
wire    [1:0]   bresp_s0        ;
wire            bvalid_s0       ;
wire            bready_s0       ;
wire            arvalid_s0      ;
wire            arready_s0      ;
wire    [31:0]  araddr_s0       ;
wire    [31:0]  rdata_s0        ;
wire    [1:0]   rresp_s0        ;
wire            rvalid_s0       ;
wire            rready_s0       ;

// clint
wire            clint_awvalid   ;
wire            clint_awready   ;
wire    [31:0]  clint_awaddr    ;
wire    [2:0]   clint_awsize    ;
wire            clint_wvalid    ;
wire            clint_wready    ;
wire    [31:0]  clint_wdata     ;
wire    [3:0]   clint_wstrb     ;
wire    [1:0]   clint_bresp     ;
wire            clint_bvalid    ;
wire            clint_bready    ;
wire    [31:0]  clint_araddr    ;
wire            clint_arvalid   ;
wire            clint_arready   ;
wire    [2:0]   clint_arsize    ;
wire    [31:0]  clint_rdata     ;
wire    [1:0]   clint_rresp     ;
wire            clint_rvalid    ;
wire            clint_rready    ;

`ifdef ysyx_23060299_NPC
    import "DPI-C" function void      store_word(int waddr, int wdata);
    import "DPI-C" function void      store_half(int waddr, int wdata);
    import "DPI-C" function void      store_byte(int waddr, int wdata);
    import "DPI-C" function int       load_word(int raddr);
    import "DPI-C" function shortint  load_half(int raddr);
    import "DPI-C" function byte      load_byte(int raddr);

assign  cache_cpu_ready =   1'b1    ;

always @(posedge clock ) begin
    if(reset)
        cache_cpu_valid <=  1'b0    ;
    else if(cpu_cache_valid)
        cache_cpu_valid <=  1'b1    ;
    else
        cache_cpu_valid <=  1'b0    ;
end

always @(posedge clock ) begin
    if(reset)
        cache_cpu_data  <=  'd0 ;
    else if(cpu_cache_valid)
        cache_cpu_data  <=  load_word(cpu_cache_addr);
    else
        cache_cpu_data  <=  'd0 ;
end

assign  awready_m1  =   1'b1    ;
assign  wready_m1   =   1'b1    ;
assign  bresp_m1    =   2'b0    ;
assign  bvalid_m1   =   1'b1    ;
assign  arready_m1  =   1'b1    ;
assign  rresp_m1    =   2'b0    ;

always @(posedge clock ) begin
    if(reset)
        rvalid_m1   <=  1'b0    ;
    else if(arvalid_m1)
        rvalid_m1   <=  1'b1    ;
    else if(rvalid_m1 && rready_m1)
        rvalid_m1   <=  1'b0    ;
end

always @(posedge clock ) begin
    if(arvalid_m1) begin
        if(arsize_m1 == 3'b010)
            rdata_m1   <=  load_word(araddr_m1);
        else if(arsize_m1 == 3'b001) begin
            if(araddr_m1[1:0] == 2'b10)
                rdata_m1   <=  {load_half(araddr_m1), 16'd0};
            else if(araddr_m1[1:0] == 2'b00)
                rdata_m1   <=  {16'd0, load_half(araddr_m1)};
        end
        else if(arsize_m1 == 3'b000) begin
            if(araddr_m1[1:0] == 2'b11)
                rdata_m1   <=  {load_byte(araddr_m1), 24'd0};
            else if(araddr_m1[1:0] == 2'b01)
                rdata_m1   <=  {16'd0, load_byte(araddr_m1), 8'd0};
            else if(araddr_m1[1:0] == 2'b10)
                rdata_m1   <=  {8'd0, load_byte(araddr_m1), 16'd0};
            else if(araddr_m1[1:0] == 2'b00)
                rdata_m1   <=  {24'd0, load_byte(araddr_m1)};
        end 
    end
end

always @(posedge clock ) begin
    if(awvalid_m1 && wvalid_m1) begin
        if(wstrb_m1 == 4'b1111)
            store_word(awaddr_m1, wdata_m1);
        else if(wstrb_m1 == 4'b0011)
            store_half(awaddr_m1, {16'd0,wdata_m1[15:0]});
        else if(wstrb_m1 == 4'b1100)
            store_half(awaddr_m1, {16'd0,wdata_m1[31:16]});
        else if(wstrb_m1 == 4'b1000)
            store_byte(awaddr_m1, {24'd0,wdata_m1[31:24]});
        else if(wstrb_m1 == 4'b0100)
            store_byte(awaddr_m1, {24'd0,wdata_m1[23:16]});
        else if(wstrb_m1 == 4'b0010)
            store_byte(awaddr_m1, {24'd0,wdata_m1[15:8]});
        else if(wstrb_m1 == 4'b0001)
            store_byte(awaddr_m1, {24'd0,wdata_m1[7:0]});
    end
end

`endif

ysyx_23060299_ICACHE #
(
    .WAY        (1)     ,   //  2 way
    .INDEX      (1)     ,   //  2**4 set 
    .OFFSET     (4)         //  32 bit
) 
ICACHE (
    // common
    .clock              (clock      ),
    .reset              (reset      ),

    // from ifu
    .cpu_cache_addr     (cpu_cache_addr     ),
    .cpu_cache_valid    (cpu_cache_valid    ),

    `ifdef ysyx_23060299_NPC
    .cache_cpu_data     (                   ),
    .cache_cpu_ready    (                   ),
    .cache_cpu_valid    (                   ),
    `else
    .cache_cpu_data     (cache_cpu_data     ),
    .cache_cpu_ready    (cache_cpu_ready    ),
    .cache_cpu_valid    (cache_cpu_valid    ),
    `endif


    .cache_mask         (cache_mask         ),
    .fence_i            (fence_i            ),

    // from axi lite BUS
    .axi_araddr         (araddr_m0  ),
    .axi_arvalid        (arvalid_m0 ),
    .axi_arready        (arready_m0 ),
    .axi_arlen          (arlen_m0   ),
    .axi_arsize         (arsize_m0  ),
    .axi_arburst        (arburst_m0 ),
    .axi_rdata          (rdata_m0   ),
    .axi_rresp          (rresp_m0   ),
    .axi_rvalid         (rvalid_m0  ),
    .axi_rready         (rready_m0  ),
    .axi_rlast          (rlast_m0   )
);

ysyx_23060299_IFU IFU (
    .clock              (clock      ),
    .reset              (reset      ),

    // IFU_RAM
    .cpu_cache_addr     (cpu_cache_addr     ),
    .cpu_cache_valid    (cpu_cache_valid    ),
    .cache_cpu_data     (cache_cpu_data     ),
    .cache_cpu_ready    (cache_cpu_ready    ),
    .cache_cpu_valid    (cache_cpu_valid    ),
    .cache_mask         (cache_mask         ),
    .fence_i            (fence_i            ),

    // from IDU 
    .need_jump_ifu      (need_jump_ifu      ),
    .branch_inst_ifu    (branch_inst_ifu    ),
    .pc_jump            (pc_jump            ),
    .jump_inst          (jump_inst          ),

    // to IDU
    .inst_idu           (inst_idu           ),
    .pc_IDEXU           (pc_IDEXU           ),
    .ifu_valid          (ifu_valid          ),
    .idexu_ready        (idexu_ready        )
);

ysyx_23060299_IDEXU IDEXU (
    .clock              (clock  ),
    .reset              (reset  ),
    
    .inst_idu           (inst_idu   ),
    .pc_IDEXU           (pc_IDEXU   ),
    .ifu_valid          (ifu_valid  ),
    
    .idexu_ready        (idexu_ready        ),
    .need_jump_ifu      (need_jump_ifu      ),
    .branch_inst_ifu    (branch_inst_ifu    ),
    .pc_jump            (pc_jump            ),
    .jump_inst          (jump_inst          ),
    
    .rs1_idx            (rs1_idx    ),
    .rs2_idx            (rs2_idx    ),
    .rs1_ren            (rs1_ren    ),
    .rs2_ren            (rs2_ren    ),
    .rs1_IDEXU          (rs1_IDEXU  ),
    .rs2_IDEXU          (rs2_IDEXU  ),
    
    .wr_en_lsu          (wr_en_lsu      ),
    .rd_idx_lsu         (rd_idx_lsu     ),
    .lw_lsu             (lw_lsu         ),
    .lbu_lsu            (lbu_lsu        ),
    .lb_lsu             (lb_lsu         ),
    .lh_lsu             (lh_lsu         ),
    .lhu_lsu            (lhu_lsu        ),
    .sw_lsu             (sw_lsu         ),
    .sh_lsu             (sh_lsu         ),
    .sb_lsu             (sb_lsu         ),
    .exu_result_lsu     (exu_result_lsu ),
    .rs2_lsu            (rs2_lsu        ),
    .idexu_valid        (idexu_valid    ),
    .lsu_ready          (lsu_ready      ),
    
    .lsu_rhandshake_d1  (lsu_rhandshake_d1  ),
    
    .wr_en_wbu          (wr_en_wbu      ),
    .rd_idx_wbu         (rd_idx_wbu     ),
    .wbu_result         (wbu_result     ),
    .load_inst_wbu      (load_inst_wbu  ),
    
`ifdef ysyx_23060299_verilator_env 
    .pc_LSU             (pc_LSU         ),
`endif
    
    // to CSR Reg
    .csr_wdata          (csr_wdata      ),
    .csr_waddr          (csr_waddr      ),
    .csr_wen            (csr_wen        ),
    .csr_rdata          (csr_rdata      ),
    .csr_raddr          (csr_raddr      ),
    .csr_ren            (csr_ren        ),
    .pc_csr             (pc_csr         ),
    .ecall_csr          (ecall_csr      ),
    .mret_csr           (mret_csr       )
);

ysyx_23060299_LSU LSU (
    .clock              (clock      ),
    .reset              (reset      ),

    // from EXU
    .wr_en_lsu          (wr_en_lsu      ),
    .rd_idx_lsu         (rd_idx_lsu     ),
    .lw_lsu             (lw_lsu         ),
    .lbu_lsu            (lbu_lsu        ),
    .lb_lsu             (lb_lsu         ),
    .lh_lsu             (lh_lsu         ),
    .lhu_lsu            (lhu_lsu        ),
    .sw_lsu             (sw_lsu         ),
    .sh_lsu             (sh_lsu         ),
    .sb_lsu             (sb_lsu         ),
    .exu_result         (exu_result_lsu ),
    .rs2_lsu            (rs2_lsu        ),
    .idexu_valid        (idexu_valid    ),
    .lsu_ready          (lsu_ready      ),

    // to LSU-RAM
    .lsu_awvalid        (awvalid_m1     ),
    .lsu_awready        (awready_m1     ),
    .lsu_awaddr         (awaddr_m1      ),
    .lsu_awsize         (awsize_m1      ),
    .lsu_wvalid         (wvalid_m1      ),
    .lsu_wready         (wready_m1      ),
    .lsu_wdata          (wdata_m1       ),
    .lsu_wstrb          (wstrb_m1       ),
    .lsu_bresp          (bresp_m1       ),
    .lsu_bvalid         (bvalid_m1      ),
    .lsu_bready         (bready_m1      ),
    .lsu_araddr         (araddr_m1      ),
    .lsu_arvalid        (arvalid_m1     ),
    .lsu_arready        (arready_m1     ),
    .lsu_arsize         (arsize_m1      ),
    .lsu_rdata          (rdata_m1       ),
    .lsu_rresp          (rresp_m1       ),
    .lsu_rvalid         (rvalid_m1      ),
    .lsu_rready         (rready_m1      ),

    // to WBU
    .rd_idx_wbu         (rd_idx_wbu         ),
    .wr_en_wbu          (wr_en_wbu          ),
    .load_result        (load_result        ),
    .load_inst_wbu      (load_inst_wbu      ),
    .exu_result_wbu     (exu_result_wbu     ),
    .lsu_valid          (lsu_valid          ),
    .wbu_ready          (wbu_ready          ),
    .lsu_rhandshake_d1  (lsu_rhandshake_d1  )

`ifdef ysyx_23060299_verilator_env 
    ,.pc_LSU             (pc_LSU             )
    ,.pc_WBU             (pc_WBU             )
`endif

);

ysyx_23060299_WBU WBU (
    .clock          (clock          ),
    .reset          (reset          ),

    // from LSU
    .wr_en_wbu      (wr_en_wbu      ),
    .rd_idx_wbu     (rd_idx_wbu     ),
    .load_result    (load_result    ),
    .load_inst      (load_inst_wbu  ),
    .exu_result_r   (exu_result_wbu ),
    .lsu_valid      (lsu_valid      ),
    .wbu_ready      (wbu_ready      ),

`ifdef ysyx_23060299_verilator_env 
    .pc_WBU         (pc_WBU         ),
`endif

    // to REG
    .wbu_result     (wbu_result     ),
    .rd_idx         (rd_idx         ),
    .reg_wren       (reg_wren       )
);

ysyx_23060299_RegisterFile #(
    .ADDR_WIDTH (`ysyx_23060299_REG_ADDR_WIDTH),
    .DATA_WIDTH (32)
) RegisterFile (
    .clock          (clock      ), 

`ifdef __ICARUS__
	.return_value   (return_value),
`endif

    .wdata          (wbu_result ), 
    .waddr          (rd_idx     ), 
    .wen            (reg_wren   ), 
    .rs1_raddr      (rs1_idx    ), 
    .rs1_rdata      (rs1_IDEXU  ), 
    .rs1_ren        (rs1_ren    ), 
    .rs2_raddr      (rs2_idx    ), 
    .rs2_rdata      (rs2_IDEXU  ), 
    .rs2_ren        (rs2_ren    ) 
);

ysyx_23060299_CSR_Reg CSR_Reg (
    .clock      (clock          ), 
    .csr_wdata  (csr_wdata      ), 
    .csr_waddr  (csr_waddr      ), 
    .csr_wen    (csr_wen        ),
    .csr_rdata  (csr_rdata      ), 
    .csr_raddr  (csr_raddr      ), 
    .csr_ren    (csr_ren        ),

    // from IDU
    .pc         (pc_csr         ),
    .ecall      (ecall_csr      ),
    .mret       (mret_csr       )
);

ysyx_23060299_axi_lite_interconnect   ysyx_23060299_axi_lite_interconnect(
    .clock              (clock),
    .reset              (reset),  

    // IFU AXI signals
    .ifu_araddr         (araddr_m0      ),
    .ifu_arvalid        (arvalid_m0     ),
    .ifu_arready        (arready_m0     ),
    .ifu_arlen          (arlen_m0       ),
    .ifu_arsize         (arsize_m0      ),
    .ifu_arburst        (arburst_m0     ),
    .ifu_rdata          (rdata_m0       ),
    .ifu_rresp          (rresp_m0       ),
    .ifu_rvalid         (rvalid_m0      ),
    .ifu_rready         (rready_m0      ),
    .ifu_rlast          (rlast_m0       ),

    `ifdef ysyx_23060299_NPC
        // LSU AXI signals
    .lsu_awvalid        (awvalid_m1     ),
    .lsu_awready        (     ),
    .lsu_awaddr         (awaddr_m1      ),
    .lsu_awsize         (awsize_m1      ),
    .lsu_wvalid         (wvalid_m1      ),
    .lsu_wready         (      ),
    .lsu_wdata          (wdata_m1       ),
    .lsu_wstrb          (wstrb_m1       ),
    .lsu_bresp          (       ),
    .lsu_bvalid         (      ),
    .lsu_bready         (bready_m1      ),
    .lsu_araddr         (araddr_m1      ),
    .lsu_arvalid        (arvalid_m1     ),
    .lsu_arready        (     ),
    .lsu_arsize         (arsize_m1      ),
    .lsu_rdata          (       ),
    .lsu_rresp          (       ),
    .lsu_rvalid         (      ),
    .lsu_rready         (rready_m1      ),
    `else
        // LSU AXI signals
    .lsu_awvalid        (awvalid_m1     ),
    .lsu_awready        (awready_m1     ),
    .lsu_awaddr         (awaddr_m1      ),
    .lsu_awsize         (awsize_m1      ),
    .lsu_wvalid         (wvalid_m1      ),
    .lsu_wready         (wready_m1      ),
    .lsu_wdata          (wdata_m1       ),
    .lsu_wstrb          (wstrb_m1       ),
    .lsu_bresp          (bresp_m1       ),
    .lsu_bvalid         (bvalid_m1      ),
    .lsu_bready         (bready_m1      ),
    .lsu_araddr         (araddr_m1      ),
    .lsu_arvalid        (arvalid_m1     ),
    .lsu_arready        (arready_m1     ),
    .lsu_arsize         (arsize_m1      ),
    .lsu_rdata          (rdata_m1       ),
    .lsu_rresp          (rresp_m1       ),
    .lsu_rvalid         (rvalid_m1      ),
    .lsu_rready         (rready_m1      ),
    `endif

    //ysyxsoc
    .io_master_awready   (io_master_awready  ),
    .io_master_awvalid   (io_master_awvalid  ),
    .io_master_awaddr    (io_master_awaddr   ),
    .io_master_awid      (io_master_awid     ),
    .io_master_awlen     (io_master_awlen    ),
    .io_master_awsize    (io_master_awsize   ),
    .io_master_awburst   (io_master_awburst  ),
    .io_master_wready    (io_master_wready   ),
    .io_master_wvalid    (io_master_wvalid   ),
    .io_master_wdata     (io_master_wdata    ),
    .io_master_wstrb     (io_master_wstrb    ),
    .io_master_wlast     (io_master_wlast    ),
    .io_master_bready    (io_master_bready   ),
    .io_master_bvalid    (io_master_bvalid   ),
    .io_master_bresp     (io_master_bresp    ),
    .io_master_bid       (io_master_bid      ),
    .io_master_arready   (io_master_arready  ),
    .io_master_arvalid   (io_master_arvalid  ),
    .io_master_araddr    (io_master_araddr   ),
    .io_master_arid      (io_master_arid     ),
    .io_master_arlen     (io_master_arlen    ),
    .io_master_arsize    (io_master_arsize   ),
    .io_master_arburst   (io_master_arburst  ),
    .io_master_rready    (io_master_rready   ),
    .io_master_rvalid    (io_master_rvalid   ),
    .io_master_rresp     (io_master_rresp    ),
    .io_master_rdata     (io_master_rdata    ),
    .io_master_rlast     (io_master_rlast    ),
    .io_master_rid       (io_master_rid      ),

    // CLINT
    .clint_awvalid      (clint_awvalid  ),
    .clint_awready      (clint_awready  ),
    .clint_awaddr       (clint_awaddr   ),
    .clint_awsize       (clint_awsize   ),
    .clint_wvalid       (clint_wvalid   ),
    .clint_wready       (clint_wready   ),
    .clint_wdata        (clint_wdata    ),
    .clint_wstrb        (clint_wstrb    ),
    .clint_bresp        (clint_bresp    ),
    .clint_bvalid       (clint_bvalid   ),
    .clint_bready       (clint_bready   ),
    .clint_araddr       (clint_araddr   ),
    .clint_arvalid      (clint_arvalid  ),
    .clint_arready      (clint_arready  ),
    .clint_arsize       (clint_arsize   ),
    .clint_rdata        (clint_rdata    ),
    .clint_rresp        (clint_rresp    ),
    .clint_rvalid       (clint_rvalid   ),
    .clint_rready       (clint_rready   )
);

ysyx_23060299_CLINT   CLINT(
    .clock              (clock  ),
    .reset              (reset  ),

    .clint_awvalid      (clint_awvalid  ),
    .clint_awready      (clint_awready  ),
    .clint_awaddr       (clint_awaddr   ),
    .clint_awsize       (clint_awsize   ),
    .clint_wvalid       (clint_wvalid   ),
    .clint_wready       (clint_wready   ),
    .clint_wdata        (clint_wdata    ),
    .clint_wstrb        (clint_wstrb    ),
    .clint_bresp        (clint_bresp    ),
    .clint_bvalid       (clint_bvalid   ),
    .clint_bready       (clint_bready   ),
    .clint_araddr       (clint_araddr   ),
    .clint_arvalid      (clint_arvalid  ),
    .clint_arready      (clint_arready  ),
    .clint_arsize       (clint_arsize   ),
    .clint_rdata        (clint_rdata    ),
    .clint_rresp        (clint_rresp    ),
    .clint_rvalid       (clint_rvalid   ),
    .clint_rready       (clint_rready   )
);


`ifdef ysyx_23060299_verilator_env

// yosys-sta need to mask
import "DPI-C" function void check_access_fault(input bit [1:0] resp, input int pc);

always @(*) begin
    if(io_master_rready &&  io_master_rvalid)
        check_access_fault(io_master_rresp, pc_IDEXU);
end

`endif


`ifdef __ICARUS__
`ifndef NETLIST
	reg [2:0] prog_end; //1:id, 2:ex, 3:wb
	always @(posedge clock) begin
		if (reset) begin
			prog_end <= 0;
			sim_end <= 0;
		end
		else if ((inst_idu == 32'h00100073) & (ifu_valid & idexu_ready)) prog_end <= 1;
		else if ((prog_end == 1) & (idexu_valid & lsu_ready)) prog_end <= 2;
		else if ((prog_end == 2) & lsu_valid & wbu_ready) sim_end <= 1;
	end
`endif
`endif
    
endmodule
