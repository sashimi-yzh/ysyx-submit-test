module ysyx_26040125(
        input  clock,
        input  reset,

        /*verilator lint_off UNUSED*/
        input io_interrupt,
        /*verilator lint_on UNUSED*/

        // AXI4 Master port
        input         io_master_awready,
        output        io_master_awvalid,
        output [31:0] io_master_awaddr,
        output [3:0]  io_master_awid,
        output [7:0]  io_master_awlen,
        output [2:0]  io_master_awsize,
        output [1:0]  io_master_awburst,
        input         io_master_wready,
        output        io_master_wvalid,
        output [31:0] io_master_wdata,
        output [3:0]  io_master_wstrb,
        output        io_master_wlast,
        output        io_master_bready,
        input         io_master_bvalid,
        input  [1:0]  io_master_bresp,
        input  [3:0]  io_master_bid,
        input         io_master_arready,
        output        io_master_arvalid,
        output [31:0] io_master_araddr,
        output [3:0]  io_master_arid,
        output [7:0]  io_master_arlen,
        output [2:0]  io_master_arsize,
        output [1:0]  io_master_arburst,
        output        io_master_rready,
        input         io_master_rvalid,
        input  [1:0]  io_master_rresp,
        input  [31:0] io_master_rdata,
        input         io_master_rlast,
        input  [3:0]  io_master_rid,

        // AXI4 Slave port
        /*verilator lint_off UNUSED */
        output        io_slave_awready,
        input         io_slave_awvalid,
        input  [31:0] io_slave_awaddr,
        input  [3:0]  io_slave_awid,
        input  [7:0]  io_slave_awlen,
        input  [2:0]  io_slave_awsize,
        input  [1:0]  io_slave_awburst,
        output        io_slave_wready,
        input         io_slave_wvalid,
        input  [31:0] io_slave_wdata,
        input  [3:0]  io_slave_wstrb,
        input         io_slave_wlast,
        input         io_slave_bready,
        output        io_slave_bvalid,
        output [1:0]  io_slave_bresp,
        output [3:0]  io_slave_bid,
        output        io_slave_arready,
        input         io_slave_arvalid,
        input  [31:0] io_slave_araddr,
        input  [3:0]  io_slave_arid,
        input  [7:0]  io_slave_arlen,
        input  [2:0]  io_slave_arsize,
        input  [1:0]  io_slave_arburst,
        input         io_slave_rready,
        output        io_slave_rvalid,
        output [1:0]  io_slave_rresp,
        output [31:0] io_slave_rdata,
        output        io_slave_rlast,
        output [3:0]  io_slave_rid
        /*verilator lint_on UNUSED */
    );

    // Slave port: outputs = 0, inputs left unconnected
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

    // PCR outputs
    wire [31:0] PCR_PC;
    wire [1:0]  PCR_meta_data_BTB_o;
    wire        PCR_hit_BTB_o;

    // IFU outputs
    wire [31:0] IFU_m_Inst;
    wire [31:0] IFU_m_PC;
    wire        IFU_m_valid;
    wire [31:0] IFU_m_axi_araddr;
    wire        IFU_m_axi_arvalid;
    wire [3:0]  IFU_m_axi_arid;
    wire [7:0]  IFU_m_axi_arlen;
    wire [2:0]  IFU_m_axi_arsize;
    wire [1:0]  IFU_m_axi_arburst;
    wire        IFU_m_axi_rready;
    wire [31:0] IFU_m_axi_awaddr;
    wire        IFU_m_axi_awvalid;
    wire [3:0]  IFU_m_axi_awid;
    wire [7:0]  IFU_m_axi_awlen;
    wire [2:0]  IFU_m_axi_awsize;
    wire [1:0]  IFU_m_axi_awburst;
    wire [31:0] IFU_m_axi_wdata;
    wire [3:0]  IFU_m_axi_wstrb;
    wire        IFU_m_axi_wvalid;
    wire        IFU_m_axi_wlast;
    wire        IFU_m_axi_bready;
    wire        IFU_pc_en;
    wire        IFU_m_has_exception;
    wire [3:0]  IFU_m_exception_code;
    wire [1:0]  IFU_m_meta_data_BTB;
    wire        IFU_m_hit_BTB;

    // GPR outputs
    wire [31:0] GPR_rdata1;
    wire [31:0] GPR_rdata2;

    // IDU outputs
    wire        IDU_s_ready;
    wire [4:0]  IDU_m_rd;
    wire [31:0] IDU_m_srcR1;
    wire [31:0] IDU_m_srcR2;
    wire [31:0] IDU_m_imm;
    wire [3:0]  IDU_m_alu_op;
    wire [1:0]  IDU_m_alu_sel0;
    wire [1:0]  IDU_m_alu_sel1;
    wire        IDU_m_wb_en;
    wire        IDU_m_mem_en;
    wire        IDU_m_mem_write_en;
    wire [1:0]  IDU_m_op_width;
    wire [2:0]  IDU_m_wb_sel;
    wire [2:0]  IDU_m_brju;
    wire        IDU_m_mem_signext;
    wire [11:0] IDU_m_csr_addr;
    wire [11:0] IDU_csr_addr;
    wire [31:0] IDU_m_csr_data;
    wire        IDU_m_csr_wr_sel;
    wire        IDU_m_csr_wen;
    wire [31:0] IDU_m_PC;
    wire        IDU_m_valid;
    wire        IDU_m_fencei;
    wire        IDU_m_has_exception;
    wire [3:0]  IDU_m_exception_code;
    wire [1:0]  IDU_m_meta_data_BTB;
    wire        IDU_m_hit_BTB;

    /*verilator lint_off UNUSED */
    wire [4:0]  IDU_rs1;
    wire [4:0]  IDU_rs2;
    /*verilator lint_on UNUSED */

    // EXU outputs
    wire        EXU_s_ready;
    wire [4:0]  EXU_m_rd;
    wire        EXU_m_wb_en;
    wire        EXU_m_mem_en;
    wire        EXU_m_mem_write_en;
    wire [1:0]  EXU_m_op_width;
    wire [2:0]  EXU_m_wb_sel;
    wire        EXU_m_mem_signext;
    wire [11:0] EXU_m_csr_addr;
    wire [31:0] EXU_m_csr_data;
    wire        EXU_m_csr_wr_sel;
    wire        EXU_m_csr_wen;
    wire [31:0] EXU_m_srcR1;
    wire [31:0] EXU_m_srcR2;
    wire [31:0] EXU_m_result;
    wire [31:0] EXU_m_PC;
    wire [31:0] EXU_m_imm;
    wire        EXU_m_valid;
    wire        EXU_cache_flush;
    wire        EXU_m_has_exception;
    wire [3:0]  EXU_m_exception_code;
    wire [4:0]  EXU_rd_exu;
    wire [11:0] EXU_csr_exu;
    wire        EXU_rd_valid_exu;
    wire        EXU_csr_valid_exu;
    wire [31:0] EXU_pcr_exu_result;
    wire [31:0] EXU_pcr_imm;
    wire [2:0]  EXU_pcr_behavior;
    wire        EXU_flush;
    wire [31:0] EXU_pcr_pc_now;
    wire [31:0] EXU_forward_data_exu;
    wire        EXU_forward_ready_exu;
    wire [31:0] EXU_csr_forward_data_exu;
    wire        EXU_csr_forward_ready_exu;
    wire [31:0] EXU_PC_w;
    wire [31:0] EXU_target;
    wire [1:0]  EXU_meta_data;
    wire        EXU_write_en;


    // LSU outputs
    wire        LSU_s_ready;
    wire [4:0]  LSU_m_rd;
    wire        LSU_m_wb_en;
    wire [2:0]  LSU_m_wb_sel;
    wire [11:0] LSU_m_csr_addr;
    wire [31:0] LSU_m_csr_data;
    wire        LSU_m_csr_wr_sel;
    wire        LSU_m_csr_wen;
    wire [31:0] LSU_m_srcR1;
    wire [31:0] LSU_m_result;
    wire [31:0] LSU_m_rdata;
    wire [31:0] LSU_m_PC;
    wire [31:0] LSU_m_imm;
    wire        LSU_m_valid;
    wire [31:0] LSU_m_axi_araddr;
    wire        LSU_m_axi_arvalid;
    wire [3:0]  LSU_m_axi_arid;
    wire [7:0]  LSU_m_axi_arlen;
    wire [2:0]  LSU_m_axi_arsize;
    wire [1:0]  LSU_m_axi_arburst;
    wire        LSU_m_axi_rready;
    wire [31:0] LSU_m_axi_awaddr;
    wire        LSU_m_axi_awvalid;
    wire [3:0]  LSU_m_axi_awid;
    wire [7:0]  LSU_m_axi_awlen;
    wire [2:0]  LSU_m_axi_awsize;
    wire [1:0]  LSU_m_axi_awburst;
    wire [31:0] LSU_m_axi_wdata;
    wire [3:0]  LSU_m_axi_wstrb;
    wire        LSU_m_axi_wvalid;
    wire        LSU_m_axi_wlast;
    wire        LSU_m_axi_bready;
    wire [4:0]  LSU_rd_lsu;
    wire [11:0] LSU_csr_lsu;
    wire        LSU_rd_valid_lsu;
    wire        LSU_csr_valid_lsu;
    wire        LSU_m_has_exception;
    wire [3:0]  LSU_m_exception_code;
    wire [31:0] LSU_forward_data_lsu;
    wire        LSU_forward_ready_lsu;
    wire [31:0] LSU_csr_forward_data_lsu;
    wire        LSU_csr_forward_ready_lsu;
    

    // WBU outputs
    wire        WBU_s_ready;
    wire        WBU_wen;
    wire [31:0] WBU_wdata;
    /*verilator lint_off UNUSED */
    wire [4:0]  WBU_waddr;
    /*verilator lint_on UNUSED */
    wire [11:0] WBU_csr_addr_;
    wire [31:0] WBU_csr_srcR1_;
    wire [31:0] WBU_csr_alu_res_;
    wire        WBU_csr_wr_sel_;
    wire        WBU_csr_wen_;
    wire [31:0] WBU_csr_epc_;
    wire [31:0] WBU_csr_cause_;
    wire [4:0]  WBU_rd_wbu;
    wire [11:0] WBU_csr_wbu;
    wire        WBU_rd_valid_wbu;
    wire        WBU_csr_valid_wbu;
    wire        WBU_csr_exception;
    wire        WBU_exception_flush;
    wire [31:0] WBU_forward_data_wbu;
    wire        WBU_forward_ready_wbu;
    wire [31:0] WBU_csr_forward_data_wbu;
    wire        WBU_csr_forward_ready_wbu;

    // CSR outputs
    wire [31:0] CSR_rdata;
    wire [31:0] CSR_mtvec_out;
    wire [31:0] CSR_mepc_out;

    // ARB outputs (slave side, responses back to IFU/LSU)
    wire        ARB_s_axi_arready_A;
    wire [31:0] ARB_s_axi_rdata_A;
    wire [1:0]  ARB_s_axi_rresp_A;
    wire        ARB_s_axi_rvalid_A;
    wire [3:0]  ARB_s_axi_rid_A;
    wire        ARB_s_axi_rlast_A;
    wire        ARB_s_axi_awready_A;
    wire        ARB_s_axi_wready_A;
    wire [1:0]  ARB_s_axi_bresp_A;
    wire        ARB_s_axi_bvalid_A;
    wire [3:0]  ARB_s_axi_bid_A;
    wire        ARB_s_axi_arready_B;
    wire [31:0] ARB_s_axi_rdata_B;
    wire [1:0]  ARB_s_axi_rresp_B;
    wire        ARB_s_axi_rvalid_B;
    wire [3:0]  ARB_s_axi_rid_B;
    wire        ARB_s_axi_rlast_B;
    wire        ARB_s_axi_awready_B;
    wire        ARB_s_axi_wready_B;
    wire [1:0]  ARB_s_axi_bresp_B;
    wire        ARB_s_axi_bvalid_B;
    wire [3:0]  ARB_s_axi_bid_B;
    // ARB outputs (master side, to XBAR slave)
    wire [31:0] ARB_m_axi_araddr;
    wire        ARB_m_axi_arvalid;
    wire [3:0]  ARB_m_axi_arid;
    wire [7:0]  ARB_m_axi_arlen;
    wire [2:0]  ARB_m_axi_arsize;
    wire [1:0]  ARB_m_axi_arburst;
    wire        ARB_m_axi_rready;
    wire [31:0] ARB_m_axi_awaddr;
    wire        ARB_m_axi_awvalid;
    wire [3:0]  ARB_m_axi_awid;
    wire [7:0]  ARB_m_axi_awlen;
    wire [2:0]  ARB_m_axi_awsize;
    wire [1:0]  ARB_m_axi_awburst;
    wire [31:0] ARB_m_axi_wdata;
    wire [3:0]  ARB_m_axi_wstrb;
    wire        ARB_m_axi_wvalid;
    wire        ARB_m_axi_wlast;
    wire        ARB_m_axi_bready;

    // XBAR outputs (slave side, responses back to ARB)
    wire        XBAR_s_axi_arready;
    wire [31:0] XBAR_s_axi_rdata;
    wire [1:0]  XBAR_s_axi_rresp;
    wire        XBAR_s_axi_rvalid;
    wire [3:0]  XBAR_s_axi_rid;
    wire        XBAR_s_axi_rlast;
    wire        XBAR_s_axi_awready;
    wire        XBAR_s_axi_wready;
    wire [1:0]  XBAR_s_axi_bresp;
    wire        XBAR_s_axi_bvalid;
    wire [3:0]  XBAR_s_axi_bid;
    // XBAR outputs (master A, to MTIME)
    wire [3:0]  XBAR_m_axi_arid_A;
    wire [31:0] XBAR_m_axi_araddr_A;
    wire [7:0]  XBAR_m_axi_arlen_A;
    wire [2:0]  XBAR_m_axi_arsize_A;
    wire [1:0]  XBAR_m_axi_arburst_A;
    wire        XBAR_m_axi_arvalid_A;
    wire        XBAR_m_axi_rready_A;
    wire [3:0]  XBAR_m_axi_awid_A;
    wire [31:0] XBAR_m_axi_awaddr_A;
    wire [7:0]  XBAR_m_axi_awlen_A;
    wire [2:0]  XBAR_m_axi_awsize_A;
    wire [1:0]  XBAR_m_axi_awburst_A;
    wire        XBAR_m_axi_awvalid_A;
    wire [31:0] XBAR_m_axi_wdata_A;
    wire [3:0]  XBAR_m_axi_wstrb_A;
    wire        XBAR_m_axi_wlast_A;
    wire        XBAR_m_axi_wvalid_A;
    wire        XBAR_m_axi_bready_A;
    // XBAR outputs (master B, to external io_master)
    wire [3:0]  XBAR_m_axi_arid_B;
    wire [31:0] XBAR_m_axi_araddr_B;
    wire [7:0]  XBAR_m_axi_arlen_B;
    wire [2:0]  XBAR_m_axi_arsize_B;
    wire [1:0]  XBAR_m_axi_arburst_B;
    wire        XBAR_m_axi_arvalid_B;
    wire        XBAR_m_axi_rready_B;
    wire [3:0]  XBAR_m_axi_awid_B;
    wire [31:0] XBAR_m_axi_awaddr_B;
    wire [7:0]  XBAR_m_axi_awlen_B;
    wire [2:0]  XBAR_m_axi_awsize_B;
    wire [1:0]  XBAR_m_axi_awburst_B;
    wire        XBAR_m_axi_awvalid_B;
    wire [31:0] XBAR_m_axi_wdata_B;
    wire [3:0]  XBAR_m_axi_wstrb_B;
    wire        XBAR_m_axi_wlast_B;
    wire        XBAR_m_axi_wvalid_B;
    wire        XBAR_m_axi_bready_B;

    // MTIME outputs
    wire        MTIME_s_axi_arready;
    wire [3:0]  MTIME_s_axi_rid;
    wire [31:0] MTIME_s_axi_rdata;
    wire [1:0]  MTIME_s_axi_rresp;
    wire        MTIME_s_axi_rlast;
    wire        MTIME_s_axi_rvalid;
    wire        MTIME_s_axi_awready;
    wire        MTIME_s_axi_wready;
    wire [3:0]  MTIME_s_axi_bid;
    wire [1:0]  MTIME_s_axi_bresp;
    wire        MTIME_s_axi_bvalid;

    // BTB outputs
    wire [31:0] BTB_target_BTB;
    wire [1:0]  BTB_meta_data_BTB;
    wire        BTB_hit_BTB;

    // Connect io_master to XBAR master B
    assign io_master_arvalid  = XBAR_m_axi_arvalid_B;
    assign io_master_araddr   = XBAR_m_axi_araddr_B;
    assign io_master_arid     = XBAR_m_axi_arid_B;
    assign io_master_arlen    = XBAR_m_axi_arlen_B;
    assign io_master_arsize   = XBAR_m_axi_arsize_B;
    assign io_master_arburst  = XBAR_m_axi_arburst_B;
    assign io_master_rready   = XBAR_m_axi_rready_B;
    assign io_master_awvalid  = XBAR_m_axi_awvalid_B;
    assign io_master_awaddr   = XBAR_m_axi_awaddr_B;
    assign io_master_awid     = XBAR_m_axi_awid_B;
    assign io_master_awlen    = XBAR_m_axi_awlen_B;
    assign io_master_awsize   = XBAR_m_axi_awsize_B;
    assign io_master_awburst  = XBAR_m_axi_awburst_B;
    assign io_master_wvalid   = XBAR_m_axi_wvalid_B;
    assign io_master_wdata    = XBAR_m_axi_wdata_B;
    assign io_master_wstrb    = XBAR_m_axi_wstrb_B;
    assign io_master_wlast    = XBAR_m_axi_wlast_B;
    assign io_master_bready   = XBAR_m_axi_bready_B;


    PCR ysyx_26040125_PCR(
            .clk             (clock),
            .reset           (reset),
            .exu_result      (EXU_pcr_exu_result),
            .imm             (EXU_pcr_imm),
            .mtvec           (CSR_mtvec_out),
            .mepc            (CSR_mepc_out),
            .behavior        (EXU_pcr_behavior),
            .pc_en           (IFU_pc_en),
            .PC              (PCR_PC),
            .pc_now          (EXU_pcr_pc_now),
            .flush           (EXU_flush),
            .exception       (WBU_exception_flush),
            .meta_data_BTB_o (PCR_meta_data_BTB_o),
            .hit_BTB_o       (PCR_hit_BTB_o),
            .target_BTB      (BTB_target_BTB),
            .meta_data_BTB   (BTB_meta_data_BTB),
            .hit_BTB         (BTB_hit_BTB)
        );

    IFU ysyx_26040125_IFU(
            .clk            (clock),
            .reset          (reset),
            .m_Inst            (IFU_m_Inst),
            .m_PC              (IFU_m_PC),
            .m_meta_data_BTB   (IFU_m_meta_data_BTB),
            .m_hit_BTB         (IFU_m_hit_BTB),
            .m_has_exception   (IFU_m_has_exception),
            .m_exception_code  (IFU_m_exception_code),
            .m_valid           (IFU_m_valid),
            .m_ready           (IDU_s_ready),
            .PC                (PCR_PC),
            .meta_data_BTB     (PCR_meta_data_BTB_o),
            .hit_BTB           (PCR_hit_BTB_o),
            .cache_flush       (EXU_cache_flush),
            .exception_flush   (WBU_exception_flush),
            .m_axi_araddr   (IFU_m_axi_araddr),
            .m_axi_arvalid  (IFU_m_axi_arvalid),
            .m_axi_arready  (ARB_s_axi_arready_A),
            .m_axi_arid     (IFU_m_axi_arid),
            .m_axi_arlen    (IFU_m_axi_arlen),
            .m_axi_arsize   (IFU_m_axi_arsize),
            .m_axi_arburst  (IFU_m_axi_arburst),
            .m_axi_rdata    (ARB_s_axi_rdata_A),
            .m_axi_rresp    (ARB_s_axi_rresp_A),
            .m_axi_rid      (ARB_s_axi_rid_A),
            .m_axi_rlast    (ARB_s_axi_rlast_A),
            .m_axi_rvalid   (ARB_s_axi_rvalid_A),
            .m_axi_rready   (IFU_m_axi_rready),
            .m_axi_awaddr   (IFU_m_axi_awaddr),
            .m_axi_awvalid  (IFU_m_axi_awvalid),
            .m_axi_awready  (ARB_s_axi_awready_A),
            .m_axi_awid     (IFU_m_axi_awid),
            .m_axi_awlen    (IFU_m_axi_awlen),
            .m_axi_awsize   (IFU_m_axi_awsize),
            .m_axi_awburst  (IFU_m_axi_awburst),
            .m_axi_wdata    (IFU_m_axi_wdata),
            .m_axi_wstrb    (IFU_m_axi_wstrb),
            .m_axi_wvalid   (IFU_m_axi_wvalid),
            .m_axi_wlast    (IFU_m_axi_wlast),
            .m_axi_wready   (ARB_s_axi_wready_A),
            .m_axi_bresp    (ARB_s_axi_bresp_A),
            .m_axi_bvalid   (ARB_s_axi_bvalid_A),
            .m_axi_bid      (ARB_s_axi_bid_A),
            .m_axi_bready   (IFU_m_axi_bready),
            .flush          (EXU_flush),
            .pc_en          (IFU_pc_en)
        );

    GPR ysyx_26040125_GPR(
            .clk    (clock),
            .reset  (reset),
            .wdata  (WBU_wdata),
            .waddr  (WBU_waddr[3:0]),
            .wen    (WBU_wen),
            .raddr1 (IDU_rs1[3:0]),
            .rdata1 (GPR_rdata1),
            .raddr2 (IDU_rs2[3:0]),
            .rdata2 (GPR_rdata2)
        );

    IDU ysyx_26040125_IDU(
            .clk            (clock),
            .reset          (reset),
            .s_Inst              (IFU_m_Inst),
            .s_PC                (IFU_m_PC),
            .s_meta_data_BTB     (IFU_m_meta_data_BTB),
            .s_hit_BTB           (IFU_m_hit_BTB),
            .s_has_exception     (IFU_m_has_exception),
            .s_exception_code    (IFU_m_exception_code),
            .s_valid             (IFU_m_valid),
            .s_ready             (IDU_s_ready),
            .m_meta_data_BTB     (IDU_m_meta_data_BTB),
            .m_hit_BTB           (IDU_m_hit_BTB),
            .m_rd                (IDU_m_rd),
            .m_srcR1        (IDU_m_srcR1),
            .m_srcR2        (IDU_m_srcR2),
            .m_imm          (IDU_m_imm),
            .m_alu_op       (IDU_m_alu_op),
            .m_alu_sel0     (IDU_m_alu_sel0),
            .m_alu_sel1     (IDU_m_alu_sel1),
            .m_wb_en        (IDU_m_wb_en),
            .m_mem_en       (IDU_m_mem_en),
            .m_mem_write_en (IDU_m_mem_write_en),
            .m_op_width     (IDU_m_op_width),
            .m_wb_sel       (IDU_m_wb_sel),
            .m_brju         (IDU_m_brju),
            .m_mem_signext  (IDU_m_mem_signext),
            .m_csr_addr     (IDU_m_csr_addr),
            .m_csr_data     (IDU_m_csr_data),
            .m_csr_wr_sel   (IDU_m_csr_wr_sel),
            .m_csr_wen      (IDU_m_csr_wen),
            .m_PC           (IDU_m_PC),
            .m_fencei       (IDU_m_fencei),
            .m_has_exception (IDU_m_has_exception),
            .m_exception_code (IDU_m_exception_code),
            .m_valid        (IDU_m_valid),
            .m_ready        (EXU_s_ready),
            .rs1            (IDU_rs1),
            .rs2            (IDU_rs2),
            .srcR1_in       (GPR_rdata1),
            .srcR2_in       (GPR_rdata2),
            .csr_data       (CSR_rdata),
            .csr_addr       (IDU_csr_addr),
            .rd_exu         (EXU_rd_exu),
            .csr_exu        (EXU_csr_exu),
            .rd_valid_exu   (EXU_rd_valid_exu),
            .csr_valid_exu  (EXU_csr_valid_exu),
            .rd_lsu         (LSU_rd_lsu),
            .csr_lsu        (LSU_csr_lsu),
            .rd_valid_lsu   (LSU_rd_valid_lsu),
            .csr_valid_lsu  (LSU_csr_valid_lsu),
            .rd_wbu         (WBU_rd_wbu),
            .csr_wbu        (WBU_csr_wbu),
            .rd_valid_wbu   (WBU_rd_valid_wbu),
            .csr_valid_wbu  (WBU_csr_valid_wbu),
            .flush          (EXU_flush),
            .exception_flush  (WBU_exception_flush),

            .forward_data_exu (EXU_forward_data_exu),
            .forward_ready_exu (EXU_forward_ready_exu),
            .csr_forward_data_exu (EXU_csr_forward_data_exu),
            .csr_forward_ready_exu (EXU_csr_forward_ready_exu),
            .forward_data_lsu (LSU_forward_data_lsu),
            .forward_ready_lsu (LSU_forward_ready_lsu),
            .csr_forward_data_lsu (LSU_csr_forward_data_lsu),
            .csr_forward_ready_lsu (LSU_csr_forward_ready_lsu),
            .forward_data_wbu (WBU_forward_data_wbu),
            .forward_ready_wbu (WBU_forward_ready_wbu),
            .csr_forward_data_wbu (WBU_csr_forward_data_wbu),
            .csr_forward_ready_wbu (WBU_csr_forward_ready_wbu)
        );

    EXU ysyx_26040125_EXU(
            .clk            (clock),
            .reset          (reset),
            .s_rd           (IDU_m_rd),
            .s_srcR1        (IDU_m_srcR1),
            .s_srcR2        (IDU_m_srcR2),
            .s_imm          (IDU_m_imm),
            .s_alu_op       (IDU_m_alu_op),
            .s_alu_sel0     (IDU_m_alu_sel0),
            .s_alu_sel1     (IDU_m_alu_sel1),
            .s_wb_en        (IDU_m_wb_en),
            .s_mem_en       (IDU_m_mem_en),
            .s_mem_write_en (IDU_m_mem_write_en),
            .s_op_width     (IDU_m_op_width),
            .s_wb_sel       (IDU_m_wb_sel),
            .s_brju         (IDU_m_brju),
            .s_mem_signext  (IDU_m_mem_signext),
            .s_csr_addr     (IDU_m_csr_addr),
            .s_csr_data     (IDU_m_csr_data),
            .s_csr_wr_sel   (IDU_m_csr_wr_sel),
            .s_csr_wen      (IDU_m_csr_wen),
            .s_PC           (IDU_m_PC),
            .s_fencei       (IDU_m_fencei),
            .s_has_exception(IDU_m_has_exception),
            .s_exception_code(IDU_m_exception_code),
            .s_meta_data_BTB (IDU_m_meta_data_BTB),
            .s_hit_BTB       (IDU_m_hit_BTB),
            .s_valid        (IDU_m_valid),
            .s_ready        (EXU_s_ready),
            .m_rd           (EXU_m_rd),
            .m_wb_en        (EXU_m_wb_en),
            .m_mem_en       (EXU_m_mem_en),
            .m_mem_write_en (EXU_m_mem_write_en),
            .m_op_width     (EXU_m_op_width),
            .m_wb_sel       (EXU_m_wb_sel),
            .m_mem_signext  (EXU_m_mem_signext),
            .m_csr_addr     (EXU_m_csr_addr),
            .m_csr_data     (EXU_m_csr_data),
            .m_csr_wr_sel   (EXU_m_csr_wr_sel),
            .m_csr_wen      (EXU_m_csr_wen),
            .m_srcR1        (EXU_m_srcR1),
            .m_srcR2        (EXU_m_srcR2),
            .m_result       (EXU_m_result),
            .m_PC           (EXU_m_PC),
            .m_imm          (EXU_m_imm),
            .m_valid        (EXU_m_valid),
            .m_ready        (LSU_s_ready),
            .m_has_exception (EXU_m_has_exception),
            .m_exception_code (EXU_m_exception_code),
            .rd_exu         (EXU_rd_exu),
            .csr_exu        (EXU_csr_exu),
            .rd_valid_exu   (EXU_rd_valid_exu),
            .csr_valid_exu  (EXU_csr_valid_exu),
            .pcr_exu_result (EXU_pcr_exu_result),
            .pcr_imm        (EXU_pcr_imm       ),
            .pcr_behavior   (EXU_pcr_behavior  ),
            .pcr_pc_now     (EXU_pcr_pc_now    ),
            .flush          (EXU_flush         ),
            .cache_flush      (EXU_cache_flush   ),
            .exception_flush  (WBU_exception_flush),
            .forward_data_exu (EXU_forward_data_exu),
            .forward_ready_exu (EXU_forward_ready_exu),
            .csr_forward_data_exu (EXU_csr_forward_data_exu),
            .csr_forward_ready_exu (EXU_csr_forward_ready_exu),
            .PC_w            (EXU_PC_w),
            .target          (EXU_target),
            .meta_data       (EXU_meta_data),
            .write_en        (EXU_write_en)
        );

    LSU ysyx_26040125_LSU(
            .clk            (clock),
            .reset          (reset),
            .s_rd           (EXU_m_rd),
            .s_wb_en        (EXU_m_wb_en),
            .s_mem_en       (EXU_m_mem_en),
            .s_mem_write_en (EXU_m_mem_write_en),
            .s_op_width     (EXU_m_op_width),
            .s_wb_sel       (EXU_m_wb_sel),
            .s_mem_signext  (EXU_m_mem_signext),
            .s_csr_addr     (EXU_m_csr_addr),
            .s_csr_data     (EXU_m_csr_data),
            .s_csr_wr_sel   (EXU_m_csr_wr_sel),
            .s_csr_wen      (EXU_m_csr_wen),
            .s_srcR1        (EXU_m_srcR1),
            .s_srcR2        (EXU_m_srcR2),
            .s_result       (EXU_m_result),
            .s_PC           (EXU_m_PC),
            .s_imm          (EXU_m_imm),
            .s_has_exception (EXU_m_has_exception),
            .s_exception_code (EXU_m_exception_code),
            .s_valid        (EXU_m_valid),
            .s_ready        (LSU_s_ready),
            .m_rd           (LSU_m_rd),
            .m_wb_en        (LSU_m_wb_en),
            .m_wb_sel       (LSU_m_wb_sel),
            .m_csr_addr     (LSU_m_csr_addr),
            .m_csr_data     (LSU_m_csr_data),
            .m_csr_wr_sel   (LSU_m_csr_wr_sel),
            .m_csr_wen      (LSU_m_csr_wen),
            .m_srcR1        (LSU_m_srcR1),
            .m_result       (LSU_m_result),
            .m_rdata        (LSU_m_rdata),
            .m_PC           (LSU_m_PC),
            .m_imm          (LSU_m_imm),
            .m_has_exception (LSU_m_has_exception),
            .m_exception_code (LSU_m_exception_code),
            .m_valid        (LSU_m_valid),
            .m_ready        (WBU_s_ready),
            .m_axi_araddr   (LSU_m_axi_araddr),
            .m_axi_arvalid  (LSU_m_axi_arvalid),
            .m_axi_arready  (ARB_s_axi_arready_B),
            .m_axi_arid     (LSU_m_axi_arid),
            .m_axi_arlen    (LSU_m_axi_arlen),
            .m_axi_arsize   (LSU_m_axi_arsize),
            .m_axi_arburst  (LSU_m_axi_arburst),
            .m_axi_rdata    (ARB_s_axi_rdata_B),
            .m_axi_rresp    (ARB_s_axi_rresp_B),
            .m_axi_rid      (ARB_s_axi_rid_B),
            .m_axi_rlast    (ARB_s_axi_rlast_B),
            .m_axi_rvalid   (ARB_s_axi_rvalid_B),
            .m_axi_rready   (LSU_m_axi_rready),
            .m_axi_awaddr   (LSU_m_axi_awaddr),
            .m_axi_awvalid  (LSU_m_axi_awvalid),
            .m_axi_awready  (ARB_s_axi_awready_B),
            .m_axi_awid     (LSU_m_axi_awid),
            .m_axi_awlen    (LSU_m_axi_awlen),
            .m_axi_awsize   (LSU_m_axi_awsize),
            .m_axi_awburst  (LSU_m_axi_awburst),
            .m_axi_wdata    (LSU_m_axi_wdata),
            .m_axi_wstrb    (LSU_m_axi_wstrb),
            .m_axi_wvalid   (LSU_m_axi_wvalid),
            .m_axi_wlast    (LSU_m_axi_wlast),
            .m_axi_wready   (ARB_s_axi_wready_B),
            .m_axi_bresp    (ARB_s_axi_bresp_B),
            .m_axi_bvalid   (ARB_s_axi_bvalid_B),
            .m_axi_bid      (ARB_s_axi_bid_B),
            .m_axi_bready   (LSU_m_axi_bready),
            .rd_lsu         (LSU_rd_lsu),
            .csr_lsu        (LSU_csr_lsu),
            .rd_valid_lsu   (LSU_rd_valid_lsu),
            .csr_valid_lsu  (LSU_csr_valid_lsu),
            .exception_flush  (WBU_exception_flush),
            .forward_data_lsu (LSU_forward_data_lsu),
            .forward_ready_lsu (LSU_forward_ready_lsu),
            .csr_forward_data_lsu (LSU_csr_forward_data_lsu),
            .csr_forward_ready_lsu (LSU_csr_forward_ready_lsu)
        );

    WBU ysyx_26040125_WBU(
            .clk            (clock),
            .reset          (reset),
            .s_rd           (LSU_m_rd),
            .s_wb_en        (LSU_m_wb_en),
            .s_wb_sel       (LSU_m_wb_sel),
            .s_csr_addr     (LSU_m_csr_addr),
            .s_csr_data     (LSU_m_csr_data),
            .s_csr_wr_sel   (LSU_m_csr_wr_sel),
            .s_csr_wen      (LSU_m_csr_wen),
            .s_srcR1        (LSU_m_srcR1),
            .s_result       (LSU_m_result),
            .s_rdata        (LSU_m_rdata),
            .s_PC           (LSU_m_PC),
            .s_imm          (LSU_m_imm),
            .s_has_exception (LSU_m_has_exception),
            .s_exception_code (LSU_m_exception_code),
            .s_valid        (LSU_m_valid),
            .s_ready        (WBU_s_ready),
            .wen            (WBU_wen),
            .wdata          (WBU_wdata),
            .waddr          (WBU_waddr),
            .csr_addr_      (WBU_csr_addr_),
            .csr_srcR1_     (WBU_csr_srcR1_),
            .csr_alu_res_   (WBU_csr_alu_res_),
            .csr_wr_sel_    (WBU_csr_wr_sel_),
            .csr_wen_       (WBU_csr_wen_),
            .csr_exception   (WBU_csr_exception),
            .csr_epc_       (WBU_csr_epc_),
            .csr_cause_     (WBU_csr_cause_),
            .rd_wbu         (WBU_rd_wbu),
            .csr_wbu        (WBU_csr_wbu),
            .rd_valid_wbu   (WBU_rd_valid_wbu),
            .csr_valid_wbu  (WBU_csr_valid_wbu),
            .exception_flush  (WBU_exception_flush),
            .forward_data_wbu (WBU_forward_data_wbu),
            .forward_ready_wbu (WBU_forward_ready_wbu),
            .csr_forward_data_wbu (WBU_csr_forward_data_wbu),
            .csr_forward_ready_wbu (WBU_csr_forward_ready_wbu)
        );

    CSR ysyx_26040125_CSR(
            .clk     (clock),
            .reset   (reset),
            .waddr    (WBU_csr_addr_),
            .raddr    (IDU_csr_addr),
            .srcR1   (WBU_csr_srcR1_),
            .alu_res (WBU_csr_alu_res_),
            .wr_sel  (WBU_csr_wr_sel_),
            .wen     (WBU_csr_wen_),
            .exception (WBU_csr_exception),
            .w_epc   (WBU_csr_epc_),
            .w_cause (WBU_csr_cause_),
            .rdata   (CSR_rdata),
            .mtvec_out (CSR_mtvec_out),
            .mepc_out (CSR_mepc_out)
        );



    ARB ysyx_26040125_ARB(
            .clk               ( clock                ),
            .reset             ( reset                ),
            .s_axi_araddr_A    ( IFU_m_axi_araddr     ),
            .s_axi_arvalid_A   ( IFU_m_axi_arvalid    ),
            .s_axi_arready_A   ( ARB_s_axi_arready_A  ),
            .s_axi_arid_A      ( IFU_m_axi_arid       ),
            .s_axi_arlen_A     ( IFU_m_axi_arlen      ),
            .s_axi_arsize_A    ( IFU_m_axi_arsize     ),
            .s_axi_arburst_A   ( IFU_m_axi_arburst    ),
            .s_axi_rdata_A     ( ARB_s_axi_rdata_A    ),
            .s_axi_rresp_A     ( ARB_s_axi_rresp_A    ),
            .s_axi_rvalid_A    ( ARB_s_axi_rvalid_A   ),
            .s_axi_rready_A    ( IFU_m_axi_rready     ),
            .s_axi_rid_A       ( ARB_s_axi_rid_A      ),
            .s_axi_rlast_A     ( ARB_s_axi_rlast_A    ),
            .s_axi_awaddr_A    ( IFU_m_axi_awaddr     ),
            .s_axi_awvalid_A   ( IFU_m_axi_awvalid    ),
            .s_axi_awready_A   ( ARB_s_axi_awready_A  ),
            .s_axi_awid_A      ( IFU_m_axi_awid       ),
            .s_axi_awlen_A     ( IFU_m_axi_awlen      ),
            .s_axi_awsize_A    ( IFU_m_axi_awsize     ),
            .s_axi_awburst_A   ( IFU_m_axi_awburst    ),
            .s_axi_wdata_A     ( IFU_m_axi_wdata      ),
            .s_axi_wstrb_A     ( IFU_m_axi_wstrb      ),
            .s_axi_wvalid_A    ( IFU_m_axi_wvalid     ),
            .s_axi_wready_A    ( ARB_s_axi_wready_A   ),
            .s_axi_wlast_A     ( IFU_m_axi_wlast      ),
            .s_axi_bresp_A     ( ARB_s_axi_bresp_A    ),
            .s_axi_bvalid_A    ( ARB_s_axi_bvalid_A   ),
            .s_axi_bready_A    ( IFU_m_axi_bready     ),
            .s_axi_bid_A       ( ARB_s_axi_bid_A      ),

            .s_axi_araddr_B    ( LSU_m_axi_araddr     ),
            .s_axi_arvalid_B   ( LSU_m_axi_arvalid    ),
            .s_axi_arready_B   ( ARB_s_axi_arready_B  ),
            .s_axi_arid_B      ( LSU_m_axi_arid       ),
            .s_axi_arlen_B     ( LSU_m_axi_arlen      ),
            .s_axi_arsize_B    ( LSU_m_axi_arsize     ),
            .s_axi_arburst_B   ( LSU_m_axi_arburst    ),
            .s_axi_rdata_B     ( ARB_s_axi_rdata_B    ),
            .s_axi_rresp_B     ( ARB_s_axi_rresp_B    ),
            .s_axi_rvalid_B    ( ARB_s_axi_rvalid_B   ),
            .s_axi_rready_B    ( LSU_m_axi_rready     ),
            .s_axi_rid_B       ( ARB_s_axi_rid_B      ),
            .s_axi_rlast_B     ( ARB_s_axi_rlast_B    ),
            .s_axi_awaddr_B    ( LSU_m_axi_awaddr     ),
            .s_axi_awvalid_B   ( LSU_m_axi_awvalid    ),
            .s_axi_awready_B   ( ARB_s_axi_awready_B  ),
            .s_axi_awid_B      ( LSU_m_axi_awid       ),
            .s_axi_awlen_B     ( LSU_m_axi_awlen      ),
            .s_axi_awsize_B    ( LSU_m_axi_awsize     ),
            .s_axi_awburst_B   ( LSU_m_axi_awburst    ),
            .s_axi_wdata_B     ( LSU_m_axi_wdata      ),
            .s_axi_wstrb_B     ( LSU_m_axi_wstrb      ),
            .s_axi_wvalid_B    ( LSU_m_axi_wvalid     ),
            .s_axi_wready_B    ( ARB_s_axi_wready_B   ),
            .s_axi_wlast_B     ( LSU_m_axi_wlast      ),
            .s_axi_bresp_B     ( ARB_s_axi_bresp_B    ),
            .s_axi_bvalid_B    ( ARB_s_axi_bvalid_B   ),
            .s_axi_bready_B    ( LSU_m_axi_bready     ),
            .s_axi_bid_B       ( ARB_s_axi_bid_B      ),

            .m_axi_araddr      ( ARB_m_axi_araddr     ),
            .m_axi_arvalid     ( ARB_m_axi_arvalid    ),
            .m_axi_arready     ( XBAR_s_axi_arready   ),
            .m_axi_arid        ( ARB_m_axi_arid       ),
            .m_axi_arlen       ( ARB_m_axi_arlen      ),
            .m_axi_arsize      ( ARB_m_axi_arsize     ),
            .m_axi_arburst     ( ARB_m_axi_arburst    ),
            .m_axi_rdata       ( XBAR_s_axi_rdata     ),
            .m_axi_rresp       ( XBAR_s_axi_rresp     ),
            .m_axi_rid         ( XBAR_s_axi_rid       ),
            .m_axi_rlast       ( XBAR_s_axi_rlast     ),
            .m_axi_rvalid      ( XBAR_s_axi_rvalid    ),
            .m_axi_rready      ( ARB_m_axi_rready     ),
            .m_axi_awaddr      ( ARB_m_axi_awaddr     ),
            .m_axi_awvalid     ( ARB_m_axi_awvalid    ),
            .m_axi_awready     ( XBAR_s_axi_awready   ),
            .m_axi_awid        ( ARB_m_axi_awid       ),
            .m_axi_awlen       ( ARB_m_axi_awlen      ),
            .m_axi_awsize      ( ARB_m_axi_awsize     ),
            .m_axi_awburst     ( ARB_m_axi_awburst    ),
            .m_axi_wdata       ( ARB_m_axi_wdata      ),
            .m_axi_wstrb       ( ARB_m_axi_wstrb      ),
            .m_axi_wvalid      ( ARB_m_axi_wvalid     ),
            .m_axi_wlast       ( ARB_m_axi_wlast      ),
            .m_axi_wready      ( XBAR_s_axi_wready    ),
            .m_axi_bresp       ( XBAR_s_axi_bresp     ),
            .m_axi_bvalid      ( XBAR_s_axi_bvalid    ),
            .m_axi_bid         ( XBAR_s_axi_bid       ),
            .m_axi_bready      ( ARB_m_axi_bready     )
        );

    XBAR ysyx_26040125_XBAR(
            .clk               (clock),
            .reset             (reset),

            .s_axi_arid        (ARB_m_axi_arid),
            .s_axi_araddr      (ARB_m_axi_araddr),
            .s_axi_arlen       (ARB_m_axi_arlen),
            .s_axi_arsize      (ARB_m_axi_arsize),
            .s_axi_arburst     (ARB_m_axi_arburst),
            .s_axi_arvalid     (ARB_m_axi_arvalid),
            .s_axi_arready     (XBAR_s_axi_arready),
            .s_axi_rid         (XBAR_s_axi_rid),
            .s_axi_rdata       (XBAR_s_axi_rdata),
            .s_axi_rresp       (XBAR_s_axi_rresp),
            .s_axi_rlast       (XBAR_s_axi_rlast),
            .s_axi_rvalid      (XBAR_s_axi_rvalid),
            .s_axi_rready      (ARB_m_axi_rready),
            .s_axi_awid        (ARB_m_axi_awid),
            .s_axi_awaddr      (ARB_m_axi_awaddr),
            .s_axi_awlen       (ARB_m_axi_awlen),
            .s_axi_awsize      (ARB_m_axi_awsize),
            .s_axi_awburst     (ARB_m_axi_awburst),
            .s_axi_awvalid     (ARB_m_axi_awvalid),
            .s_axi_awready     (XBAR_s_axi_awready),
            .s_axi_wdata       (ARB_m_axi_wdata),
            .s_axi_wstrb       (ARB_m_axi_wstrb),
            .s_axi_wlast       (ARB_m_axi_wlast),
            .s_axi_wvalid      (ARB_m_axi_wvalid),
            .s_axi_wready      (XBAR_s_axi_wready),
            .s_axi_bid         (XBAR_s_axi_bid),
            .s_axi_bresp       (XBAR_s_axi_bresp),
            .s_axi_bvalid      (XBAR_s_axi_bvalid),
            .s_axi_bready      (ARB_m_axi_bready),

            // Master A -> MTIME
            .m_axi_arid_A      (XBAR_m_axi_arid_A),
            .m_axi_araddr_A    (XBAR_m_axi_araddr_A),
            .m_axi_arlen_A     (XBAR_m_axi_arlen_A),
            .m_axi_arsize_A    (XBAR_m_axi_arsize_A),
            .m_axi_arburst_A   (XBAR_m_axi_arburst_A),
            .m_axi_arvalid_A   (XBAR_m_axi_arvalid_A),
            .m_axi_arready_A   (MTIME_s_axi_arready),
            .m_axi_rid_A       (MTIME_s_axi_rid),
            .m_axi_rdata_A     (MTIME_s_axi_rdata),
            .m_axi_rresp_A     (MTIME_s_axi_rresp),
            .m_axi_rlast_A     (MTIME_s_axi_rlast),
            .m_axi_rvalid_A    (MTIME_s_axi_rvalid),
            .m_axi_rready_A    (XBAR_m_axi_rready_A),
            .m_axi_awid_A      (XBAR_m_axi_awid_A),
            .m_axi_awaddr_A    (XBAR_m_axi_awaddr_A),
            .m_axi_awlen_A     (XBAR_m_axi_awlen_A),
            .m_axi_awsize_A    (XBAR_m_axi_awsize_A),
            .m_axi_awburst_A   (XBAR_m_axi_awburst_A),
            .m_axi_awvalid_A   (XBAR_m_axi_awvalid_A),
            .m_axi_awready_A   (MTIME_s_axi_awready),
            .m_axi_wdata_A     (XBAR_m_axi_wdata_A),
            .m_axi_wstrb_A     (XBAR_m_axi_wstrb_A),
            .m_axi_wlast_A     (XBAR_m_axi_wlast_A),
            .m_axi_wvalid_A    (XBAR_m_axi_wvalid_A),
            .m_axi_wready_A    (MTIME_s_axi_wready),
            .m_axi_bid_A       (MTIME_s_axi_bid),
            .m_axi_bresp_A     (MTIME_s_axi_bresp),
            .m_axi_bvalid_A    (MTIME_s_axi_bvalid),
            .m_axi_bready_A    (XBAR_m_axi_bready_A),

            // Master B -> external io_master
            .m_axi_arid_B      (XBAR_m_axi_arid_B),
            .m_axi_araddr_B    (XBAR_m_axi_araddr_B),
            .m_axi_arlen_B     (XBAR_m_axi_arlen_B),
            .m_axi_arsize_B    (XBAR_m_axi_arsize_B),
            .m_axi_arburst_B   (XBAR_m_axi_arburst_B),
            .m_axi_arvalid_B   (XBAR_m_axi_arvalid_B),
            .m_axi_arready_B   (io_master_arready),
            .m_axi_rid_B       (io_master_rid),
            .m_axi_rdata_B     (io_master_rdata),
            .m_axi_rresp_B     (io_master_rresp),
            .m_axi_rlast_B     (io_master_rlast),
            .m_axi_rvalid_B    (io_master_rvalid),
            .m_axi_rready_B    (XBAR_m_axi_rready_B),
            .m_axi_awid_B      (XBAR_m_axi_awid_B),
            .m_axi_awaddr_B    (XBAR_m_axi_awaddr_B),
            .m_axi_awlen_B     (XBAR_m_axi_awlen_B),
            .m_axi_awsize_B    (XBAR_m_axi_awsize_B),
            .m_axi_awburst_B   (XBAR_m_axi_awburst_B),
            .m_axi_awvalid_B   (XBAR_m_axi_awvalid_B),
            .m_axi_awready_B   (io_master_awready),
            .m_axi_wdata_B     (XBAR_m_axi_wdata_B),
            .m_axi_wstrb_B     (XBAR_m_axi_wstrb_B),
            .m_axi_wlast_B     (XBAR_m_axi_wlast_B),
            .m_axi_wvalid_B    (XBAR_m_axi_wvalid_B),
            .m_axi_wready_B    (io_master_wready),
            .m_axi_bid_B       (io_master_bid),
            .m_axi_bresp_B     (io_master_bresp),
            .m_axi_bvalid_B    (io_master_bvalid),
            .m_axi_bready_B    (XBAR_m_axi_bready_B)
        );

    MTIME ysyx_26040125_MTIME(
            .clk           ( clock                  ),
            .reset         ( reset                  ),
            .s_axi_arid    ( XBAR_m_axi_arid_A      ),
            .s_axi_araddr  ( XBAR_m_axi_araddr_A    ),
            .s_axi_arlen   ( XBAR_m_axi_arlen_A     ),
            .s_axi_arsize  ( XBAR_m_axi_arsize_A    ),
            .s_axi_arburst ( XBAR_m_axi_arburst_A   ),
            .s_axi_arvalid ( XBAR_m_axi_arvalid_A   ),
            .s_axi_arready ( MTIME_s_axi_arready     ),
            .s_axi_rid     ( MTIME_s_axi_rid         ),
            .s_axi_rdata   ( MTIME_s_axi_rdata       ),
            .s_axi_rresp   ( MTIME_s_axi_rresp       ),
            .s_axi_rlast   ( MTIME_s_axi_rlast       ),
            .s_axi_rvalid  ( MTIME_s_axi_rvalid      ),
            .s_axi_rready  ( XBAR_m_axi_rready_A    ),
            .s_axi_awid    ( XBAR_m_axi_awid_A      ),
            .s_axi_awaddr  ( XBAR_m_axi_awaddr_A    ),
            .s_axi_awlen   ( XBAR_m_axi_awlen_A     ),
            .s_axi_awsize  ( XBAR_m_axi_awsize_A    ),
            .s_axi_awburst ( XBAR_m_axi_awburst_A   ),
            .s_axi_awvalid ( XBAR_m_axi_awvalid_A   ),
            .s_axi_awready ( MTIME_s_axi_awready     ),
            .s_axi_wdata   ( XBAR_m_axi_wdata_A     ),
            .s_axi_wstrb   ( XBAR_m_axi_wstrb_A     ),
            .s_axi_wlast   ( XBAR_m_axi_wlast_A     ),
            .s_axi_wvalid  ( XBAR_m_axi_wvalid_A    ),
            .s_axi_wready  ( MTIME_s_axi_wready      ),
            .s_axi_bid     ( MTIME_s_axi_bid         ),
            .s_axi_bresp   ( MTIME_s_axi_bresp       ),
            .s_axi_bvalid  ( MTIME_s_axi_bvalid      ),
            .s_axi_bready  ( XBAR_m_axi_bready_A    )
        );

    BTB#(
        .ENTRY_NUM(8)
    )ysyx_26040125_BTB(
            .clk         (clock),
            .reset       (reset),
            .PC_r        (PCR_PC),
            .PC_w        (EXU_PC_w),
            .target      (EXU_target),
            .meta_data   (EXU_meta_data),
            .write_en    (EXU_write_en),
            .target_BTB    (BTB_target_BTB),
            .meta_data_BTB (BTB_meta_data_BTB),
            .hit_BTB       (BTB_hit_BTB)
        );

endmodule
