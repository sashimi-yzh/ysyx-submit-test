`include "ysyx_25020037_config.vh"

module ysyx_25020037 (
    input   wire         clock,
    input   wire         reset,
    input   wire         io_interrupt,

    input   wire         io_master_awready,
    output  wire         io_master_awvalid,
    output  wire [31: 0] io_master_awaddr,
    output  wire [ 3: 0] io_master_awid, 
    output  wire [ 7: 0] io_master_awlen,  
    output  wire [ 2: 0] io_master_awsize,
    output  wire [ 1: 0] io_master_awburst,
    input   wire         io_master_wready,
    output  wire         io_master_wvalid, 
    output  wire [31: 0] io_master_wdata, 
    output  wire [ 3: 0] io_master_wstrb,  
    output  wire         io_master_wlast,  
    output  wire         io_master_bready, 
    input   wire         io_master_bvalid, 
    input   wire [ 1: 0] io_master_bresp, 
    input   wire [ 3: 0] io_master_bid,  
    input   wire         io_master_arready,
    output  wire         io_master_arvalid,
    output  wire [31: 0] io_master_araddr,
    output  wire [ 3: 0] io_master_arid, 
    output  wire [ 7: 0] io_master_arlen,  
    output  wire [ 2: 0] io_master_arsize, 
    output  wire [ 1: 0] io_master_arburst,
    output  wire         io_master_rready,
    input   wire         io_master_rvalid, 
    input   wire [ 1: 0] io_master_rresp, 
    input   wire [31: 0] io_master_rdata,  
    input   wire         io_master_rlast,  
    input   wire [ 3: 0] io_master_rid,

    output  wire         io_slave_awready,
    input   wire         io_slave_awvalid,
    input   wire [31: 0] io_slave_awaddr,
    input   wire [ 3: 0] io_slave_awid, 
    input   wire [ 7: 0] io_slave_awlen,  
    input   wire [ 2: 0] io_slave_awsize, 
    input   wire [ 1: 0] io_slave_awburst,
    output  wire         io_slave_wready,
    input   wire         io_slave_wvalid, 
    input   wire [31: 0] io_slave_wdata, 
    input   wire [ 3: 0] io_slave_wstrb,  
    input   wire         io_slave_wlast,  
    input   wire         io_slave_bready, 
    output  wire         io_slave_bvalid, 
    output  wire [ 1: 0] io_slave_bresp, 
    output  wire [ 3: 0] io_slave_bid,  
    output  wire         io_slave_arready,
    input   wire         io_slave_arvalid,
    input   wire [31: 0] io_slave_araddr,
    input   wire [ 3: 0] io_slave_arid, 
    input   wire [ 7: 0] io_slave_arlen,  
    input   wire [ 2: 0] io_slave_arsize, 
    input   wire [ 1: 0] io_slave_arburst,
    input   wire         io_slave_rready,
    output  wire         io_slave_rvalid, 
    output  wire [ 1: 0] io_slave_rresp, 
    output  wire [31: 0] io_slave_rdata,  
    output  wire         io_slave_rlast,  
    output  wire [ 3: 0] io_slave_rid  
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

    parameter BLOCK_SIZE   = 32'd16;
    parameter CACHE_BLOCKS = 32'd2;

    wire [`DU_TO_EU_BUS_WD -1:0] du_to_eu_bus;
    wire [`EU_TO_LU_BUS_WD -1:0] eu_to_lu_bus;
    wire [`LU_TO_WU_BUS_WD -1:0] lu_to_wu_bus;
    wire [`WU_TO_EU_BUS_WD -1:0] wu_to_eu_bus;
    wire [`EU_TO_IC_BUS_WD -1:0] eu_to_ic_bus;

    wire [`RS_DATA-1: 0] rs_data;
    wire [31: 0] exu_dnpc;
    wire         exu_dnpc_valid;
    wire         pc_updata;
    wire [31:0]  rdata_processed;

    wire         ifu_valid;
    wire         idu_valid;
    wire         idu_ready;
    wire         exu_valid;
    wire         exu_ready;
    wire         lsu_ready;
    wire         lsu_valid;
    wire         diff;
    wire [31:0]  diff_pc_o_exu;
    wire [31:0]  diff_pc_o_lsu;
    wire [31:0]  diff_pc;

    wire         ifu_arready;
    wire         ifu_arvalid;
    wire [31:0]  ifu_araddr;
    wire [3:0]   ifu_arid;
    wire [7:0]   ifu_arlen;
    wire [2:0]   ifu_arsize;
    wire [1:0]   ifu_arburst;
    wire         ifu_rready;
    wire         ifu_rvalid;
    wire [1:0]   ifu_rresp;
    wire [31:0]  ifu_rdata;
    wire         ifu_rlast;
    wire [3:0]   ifu_rid;

    wire         lsu_awready;
    wire         lsu_awvalid;
    wire [31:0]  lsu_awaddr;
    wire [3:0]   lsu_awid;
    wire [7:0]   lsu_awlen;
    wire [2:0]   lsu_awsize;
    wire [1:0]   lsu_awburst;
    wire         lsu_wready;
    wire         lsu_wvalid;
    wire [31:0]  lsu_wdata;
    wire [3:0]   lsu_wstrb;
    wire         lsu_wlast;
    wire         lsu_bready;
    wire         lsu_bvalid;
    wire [1:0]   lsu_bresp;
    wire [3:0]   lsu_bid;
    wire         lsu_arready;
    wire         lsu_arvalid;
    wire [31:0]  lsu_araddr;
    wire [3:0]   lsu_arid;
    wire [7:0]   lsu_arlen;
    wire [2:0]   lsu_arsize;
    wire [1:0]   lsu_arburst;
    wire         lsu_rready;
    wire         lsu_rvalid;
    wire [1:0]   lsu_rresp;
    wire [31:0]  lsu_rdata;
    wire         lsu_rlast;
    wire [3:0]   lsu_rid;

    wire         clint_arready;
    wire         clint_arvalid;
    wire [31:0]  clint_araddr;
    wire [3:0]   clint_arid;
    wire [7:0]   clint_arlen;
    wire [2:0]   clint_arsize;
    wire [1:0]   clint_arburst;
    wire         clint_rready;
    wire         clint_rvalid;
    wire [1:0]   clint_rresp;
    wire [31:0]  clint_rdata;
    wire         clint_rlast;
    wire [3:0]   clint_rid;

    wire [31: 0] icache_addr;
    wire         icache_valid;
    wire [31: 0] pc;
    wire [31: 0] inst;
    wire         icache_hit;
      
    ysyx_25020037_ifu #(
        .BLOCK_SIZE    (BLOCK_SIZE)
    ) ifu_cpu(
        .clk           (clock            ),
        .rst           (reset            ),
        .exu_dnpc_valid(exu_dnpc_valid   ),
        .exu_dnpc      (exu_dnpc         ),
        .pc_updata     (pc_updata        ),
        .idu_ready     (idu_ready        ),
        .ifu_valid     (ifu_valid        ),
        .pc            (pc               ),
        .icache_addr   (icache_addr      ),
        .icache_valid  (icache_valid     ),
        .icache_hit    (icache_hit       )
        );

    ysyx_25020037_icache #(
        .ADDR_WIDTH    (32),
        .DATA_WIDTH    (32),
        .CACHE_BLOCKS  (CACHE_BLOCKS),
        .BLOCK_SIZE    (BLOCK_SIZE)
    ) u_icache (
        .clk           (clock            ),
        .rst           (reset            ),
        .arready       (ifu_arready      ),
        .arvalid       (ifu_arvalid      ),
        .araddr        (ifu_araddr       ),
        .arid          (ifu_arid         ),
        .arlen         (ifu_arlen        ),
        .arsize        (ifu_arsize       ),
        .arburst       (ifu_arburst      ),
        .rready        (ifu_rready       ),
        .rvalid        (ifu_rvalid       ),
        .rresp         (ifu_rresp        ),
        .rdata         (ifu_rdata        ),
        .rlast         (ifu_rlast        ),
        .rid           (ifu_rid          ),
        .eu_to_ic_bus  (eu_to_ic_bus     ),
        .cpu_addr      (icache_addr      ),
        .cpu_valid     (icache_valid     ),
        .inst          (inst             ),
        .cpu_hit       (icache_hit       )
    );

    ysyx_25020037_idu idu_cpu(
        .clk            (clock          ),
        .rst            (reset          ),
        .ifu_valid      (ifu_valid      ),
        .exu_ready      (exu_ready      ),
        .idu_valid      (idu_valid      ),
        .idu_ready      (idu_ready      ),
        .exu_dnpc_valid (exu_dnpc_valid ),
        .pc             (pc             ),
        .inst           (inst           ),
        .du_to_eu_bus   (du_to_eu_bus   )
        );
    wire    sim_end;
    ysyx_25020037_exu exu_cpu(
        .sim_end        (sim_end        ),
        .clk            (clock          ),
        .rst            (reset          ),
        .idu_valid      (idu_valid      ),
        .lsu_ready      (lsu_ready      ),
        .exu_ready      (exu_ready      ),
        .exu_valid      (exu_valid      ),
        .rs_data        (rs_data        ),
        .rdata_processed(rdata_processed),
`ifdef VERILATOR
        .diff_pc_o      (diff_pc_o_exu  ),
`endif
        .wu_to_eu_bus   (wu_to_eu_bus   ),
        .du_to_eu_bus   (du_to_eu_bus   ),
        .eu_to_lu_bus   (eu_to_lu_bus   ),
        .eu_to_ic_bus   (eu_to_ic_bus   ),
        .pc_updata      (pc_updata      ),
        .exu_dnpc_valid (exu_dnpc_valid ),
        .exu_dnpc       (exu_dnpc       )
    );

    ysyx_25020037_lsu lsu_cpu(
        .clk            (clock           ),
        .rst            (reset           ),
        .exu_valid      (exu_valid       ),
        .lsu_ready      (lsu_ready       ),
        .lsu_valid      (lsu_valid       ),
        .exu_dnpc_valid (exu_dnpc_valid  ),
        .rdata_processed(rdata_processed ),
`ifdef VERILATOR
        .diff_pc_i      (diff_pc_o_exu   ),
        .diff_pc_o      (diff_pc_o_lsu   ),
`endif
        .eu_to_lu_bus   (eu_to_lu_bus    ),
        .lu_to_wu_bus   (lu_to_wu_bus    ),
        .awready        (lsu_awready     ),
        .awvalid        (lsu_awvalid     ),
        .awaddr         (lsu_awaddr      ),
        .awid           (lsu_awid        ),
        .awlen          (lsu_awlen       ),
        .awsize         (lsu_awsize      ),
        .awburst        (lsu_awburst     ),
        .wready         (lsu_wready      ),
        .wvalid         (lsu_wvalid      ),
        .wdata          (lsu_wdata       ),
        .wstrb          (lsu_wstrb       ),
        .wlast          (lsu_wlast       ),
        .bready         (lsu_bready      ),
        .bvalid         (lsu_bvalid      ),
        .bresp          (lsu_bresp       ),
        .bid            (lsu_bid         ),
        .arready        (lsu_arready     ),
        .arvalid        (lsu_arvalid     ),
        .araddr         (lsu_araddr      ),
        .arid           (lsu_arid        ),
        .arlen          (lsu_arlen       ),
        .arsize         (lsu_arsize      ),
        .arburst        (lsu_arburst     ),
        .rready         (lsu_rready      ),
        .rvalid         (lsu_rvalid      ),
        .rresp          (lsu_rresp       ),
        .rdata          (lsu_rdata       ),
        .rlast          (lsu_rlast       ),
        .rid            (lsu_rid         )
    );

ysyx_25020037_arbiter u_arbiter(
        .clk                    (clock            ),
        .rst                    (reset            ),
        .ifu_arready            (ifu_arready      ),
        .ifu_arvalid            (ifu_arvalid      ),
        .ifu_araddr             (ifu_araddr       ),
        .ifu_arid               (ifu_arid         ),
        .ifu_arlen              (ifu_arlen        ),
        .ifu_arsize             (ifu_arsize       ),
        .ifu_arburst            (ifu_arburst      ),
        .ifu_rready             (ifu_rready       ),
        .ifu_rvalid             (ifu_rvalid       ),
        .ifu_rresp              (ifu_rresp        ),
        .ifu_rdata              (ifu_rdata        ),
        .ifu_rlast              (ifu_rlast        ),
        .ifu_rid                (ifu_rid          ),
        .lsu_awready            (lsu_awready      ),
        .lsu_awvalid            (lsu_awvalid      ),
        .lsu_awaddr             (lsu_awaddr       ),
        .lsu_awid               (lsu_awid         ),
        .lsu_awlen              (lsu_awlen        ),
        .lsu_awsize             (lsu_awsize       ),
        .lsu_awburst            (lsu_awburst      ),
        .lsu_wready             (lsu_wready       ),
        .lsu_wvalid             (lsu_wvalid       ),
        .lsu_wdata              (lsu_wdata        ),
        .lsu_wstrb              (lsu_wstrb        ),
        .lsu_wlast              (lsu_wlast        ),
        .lsu_bready             (lsu_bready       ),
        .lsu_bvalid             (lsu_bvalid       ),
        .lsu_bresp              (lsu_bresp        ),
        .lsu_bid                (lsu_bid          ),
        .lsu_arready            (lsu_arready      ),
        .lsu_arvalid            (lsu_arvalid      ),
        .lsu_araddr             (lsu_araddr       ),
        .lsu_arid               (lsu_arid         ),
        .lsu_arlen              (lsu_arlen        ),
        .lsu_arsize             (lsu_arsize       ),
        .lsu_arburst            (lsu_arburst      ),
        .lsu_rready             (lsu_rready       ),
        .lsu_rvalid             (lsu_rvalid       ),
        .lsu_rresp              (lsu_rresp        ),
        .lsu_rdata              (lsu_rdata        ),
        .lsu_rlast              (lsu_rlast        ),
        .lsu_rid                (lsu_rid          ),
        .io_master_awready      (io_master_awready),
        .io_master_awvalid      (io_master_awvalid),
        .io_master_awaddr       (io_master_awaddr ),
        .io_master_awid         (io_master_awid   ),
        .io_master_awlen        (io_master_awlen  ),
        .io_master_awsize       (io_master_awsize ),
        .io_master_awburst      (io_master_awburst),
        .io_master_wready       (io_master_wready ),
        .io_master_wvalid       (io_master_wvalid ),
        .io_master_wdata        (io_master_wdata  ),
        .io_master_wstrb        (io_master_wstrb  ),
        .io_master_wlast        (io_master_wlast  ),
        .io_master_bready       (io_master_bready ),
        .io_master_bvalid       (io_master_bvalid ),
        .io_master_bresp        (io_master_bresp  ),
        .io_master_bid          (io_master_bid    ),
        .io_master_arready      (io_master_arready),
        .io_master_arvalid      (io_master_arvalid),
        .io_master_araddr       (io_master_araddr ),
        .io_master_arid         (io_master_arid   ),
        .io_master_arlen        (io_master_arlen  ),
        .io_master_arsize       (io_master_arsize ),
        .io_master_arburst      (io_master_arburst),
        .io_master_rready       (io_master_rready ),
        .io_master_rvalid       (io_master_rvalid ),
        .io_master_rresp        (io_master_rresp  ),
        .io_master_rdata        (io_master_rdata  ),
        .io_master_rlast        (io_master_rlast  ),
        .io_master_rid          (io_master_rid    ),
        .clint_arready          (clint_arready    ),
        .clint_arvalid          (clint_arvalid    ),
        .clint_araddr           (clint_araddr     ),
        .clint_arid             (clint_arid       ),
        .clint_arlen            (clint_arlen      ),
        .clint_arsize           (clint_arsize     ),
        .clint_arburst          (clint_arburst    ),
        .clint_rready           (clint_rready     ),
        .clint_rvalid           (clint_rvalid     ),
        .clint_rresp            (clint_rresp      ),
        .clint_rdata            (clint_rdata      ),
        .clint_rlast            (clint_rlast      ),
        .clint_rid              (clint_rid        )
);

ysyx_25020037_clint u_clint (
        .clk        (clock        ),
        .rst        (reset        ),
        .arready    (clint_arready),
        .arvalid    (clint_arvalid),
        .araddr     (clint_araddr ),
        .arid       (clint_arid   ),
        .arlen      (clint_arlen  ),
        .arsize     (clint_arsize ),
        .arburst    (clint_arburst),
        .rready     (clint_rready ),
        .rvalid     (clint_rvalid ),
        .rresp      (clint_rresp  ),
        .rdata      (clint_rdata  ),
        .rlast      (clint_rlast  ),
        .rid        (clint_rid    )
);

    ysyx_25020037_wbu wbu_cpu(
        .clk          (clock        ),
        .rst          (reset        ),
        .lsu_valid    (lsu_valid    ),
`ifdef VERILATOR
        .diff         (diff         ),
        .diff_pc_i    (diff_pc_o_lsu),
        .diff_pc      (diff_pc      ),
`endif
        .rs_data      (rs_data      ),
        .lu_to_wu_bus (lu_to_wu_bus ),
        .wu_to_eu_bus (wu_to_eu_bus )
        );

endmodule
