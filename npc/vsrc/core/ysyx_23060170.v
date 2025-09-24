module ysyx_23060170 (
  input            clock ,
  input            reset ,
  input            io_interrupt ,
  input            io_master_awready ,
  output           io_master_awvalid ,
  output  [3  :0]  io_master_awid ,
  output  [31 :0]  io_master_awaddr ,
  output  [7  :0]  io_master_awlen ,
  output  [2  :0]  io_master_awsize ,
  output  [1  :0]  io_master_awburst ,
  input            io_master_wready ,
  output           io_master_wvalid ,
  output  [31 :0]  io_master_wdata ,
  output  [3  :0]  io_master_wstrb ,
  output           io_master_wlast ,
  output           io_master_bready ,
  input            io_master_bvalid ,
  input   [3  :0]  io_master_bid ,
  input   [1  :0]  io_master_bresp ,
  input            io_master_arready ,
  output           io_master_arvalid ,
  output  [3  :0]  io_master_arid ,
  output  [31 :0]  io_master_araddr ,
  output  [7  :0]  io_master_arlen ,
  output  [2  :0]  io_master_arsize ,
  output  [1  :0]  io_master_arburst ,
  output           io_master_rready ,
  input            io_master_rvalid ,
  input   [31 :0]  io_master_rdata ,
  input   [3  :0]  io_master_rid ,
  input   [1  :0]  io_master_rresp ,
  input            io_master_rlast ,
  // unused signal
  output           io_slave_awready ,
  input            io_slave_awvalid ,
  input   [3  :0]  io_slave_awid ,
  input   [31 :0]  io_slave_awaddr ,
  input   [7  :0]  io_slave_awlen ,
  input   [2  :0]  io_slave_awsize ,
  input   [1  :0]  io_slave_awburst ,
  output           io_slave_wready ,
  input            io_slave_wvalid ,
  input   [31 :0]  io_slave_wdata ,
  input   [3  :0]  io_slave_wstrb ,
  input            io_slave_wlast ,
  input            io_slave_bready ,
  output           io_slave_bvalid ,
  output  [3  :0]  io_slave_bid ,
  output  [1  :0]  io_slave_bresp ,
  output           io_slave_arready ,
  input            io_slave_arvalid ,
  input   [3  :0]  io_slave_arid ,
  input   [31 :0]  io_slave_araddr ,
  input   [7  :0]  io_slave_arlen ,
  input   [2  :0]  io_slave_arsize ,
  input   [1  :0]  io_slave_arburst ,
  input            io_slave_rready ,
  output           io_slave_rvalid ,
  output   [3  :0] io_slave_rid ,
  output   [31 :0] io_slave_rdata ,
  output   [1  :0] io_slave_rresp ,
  output           io_slave_rlast 
);

`ifdef ysyx_23060170_SIM_INFO
wire    [31 :0]  idu_exu_inst ;
wire    [31 :0]  idu_exu_tpc ;
wire    [31 :0]  exu_lsu_tpc ;
wire    [31 :0]  exu_lsu_inst ;
wire             lsu_valid ;
wire             lsu_ebreak ;
wire    [31 :0]  lsu_wbu_pc ;
wire    [31 :0]  lsu_wbu_npc ;
wire    [31 :0]  lsu_wbu_inst ;
`endif

// IF
wire             ifu_valid ;
wire             ifu_idu_excp ;
wire    [3  :0]  ifu_idu_excp_code ;
wire    [31 :0]  ifu_idu_pc ;
wire    [31 :0]  ifu_idu_tpc ;
wire    [31 :0]  ifu_idu_inst ;
wire             ifu_icache_valid ;
wire    [31 :0]  ifu_icache_pc ;
wire             icache_ifu_ready ;
wire    [31 :0]  icache_ifu_data ;
wire             icache_ifu_acc_fault ;
wire             ifu_icache_flush  ;
wire             ifu_icache_rls  ;
// ID
wire             idu_valid ;
wire             idu_ready ;
wire    [4  :0]  idu_gpr_raddr1 ;
wire    [4  :0]  idu_gpr_raddr2 ;
wire    [1  :0]  idu_csr_raddr ;
wire             idu_exu_excp ;
wire    [3  :0]  idu_exu_excp_code ;
wire    [7  :0]  idu_exu_exu_sel_signal ;
wire    [31 :0]  idu_exu_out ;
wire    [31 :0]  idu_exu_gpr_rdata1 ;
wire    [31 :0]  idu_exu_gpr_rdata2 ;
wire    [31 :0]  idu_exu_pc ;
wire    [31 :0]  idu_exu_tpc_or_csr_wdata ;
wire    [2  :0]  idu_exu_branch_code ;
wire    [9  :0]  idu_exu_alu_op ;
wire             idu_exu_gpr_wen ;
wire    [4  :0]  idu_exu_gpr_waddr ;
wire             idu_exu_csr_wen ;
wire    [1  :0]  idu_exu_csr_waddr ;
wire             idu_exu_mem_ren ;
wire             idu_exu_mem_wen ;
// EX
wire             exu_valid ;
wire             exu_ready ;
wire    [31 :0]  exu_lsu_out ;
wire    [2  :0]  exu_lsu_mem_func3 ;
wire    [4  :0]  exu_lsu_gpr_waddr ;
wire    [1  :0]  exu_lsu_csr_waddr ;
wire    [31 :0]  exu_lsu_csr_or_mem_wdata ;
wire             exu_lsu_mem_ren ;
wire             exu_lsu_mem_wen ;
wire             exu_lsu_gpr_wen ;
wire             exu_lsu_csr_wen ;
wire             exu_lsu_excp ;
wire    [3  :0]  exu_lsu_excp_code ;
wire             exu_lsu_is_fencei ;
wire             exu_lsu_br_mispred ;
wire    [31 :0]  exu_lsu_pc ;
wire    [31 :0]  exu_lsu_npc ;
wire    [3  :0]  exu_idu_gpr_waddr ;
// LSU
wire             lsu_ready ;
wire    [31 :0]  lsu_out ;
wire             lsu_gpr_wen ;
wire    [4  :0]  lsu_gpr_waddr ;
wire             lsu_csr_wen ;
wire    [1  :0]  lsu_csr_waddr ;
wire    [31 :0]  lsu_csr_wdata ;
wire             lsu_csr_excp ;
wire    [3  :0]  lsu_csr_mcause ;
wire    [31 :0]  csr_lsu_rdata ;
wire    [3  :0]  lsu_idu_gpr_waddr ;
wire             lsu_flush ;
wire    [31 :0]  lsu_flush_pc ;
wire             lsu_ifu_fencei ;
// regfile
wire    [31 :0]  gpr_idu_rdata1 ;
wire    [31 :0]  gpr_idu_rdata2 ;
// csr
wire    [31 :0]  csr_idu_rdata ;
// Xbar
wire             icache_Xbar_ar_valid ;
wire    [31 :0]  icache_Xbar_ar_addr ;
wire    [3  :0]  icache_Xbar_ar_id ;
wire    [7  :0]  icache_Xbar_ar_len ;
wire    [2  :0]  icache_Xbar_ar_size ;
wire    [1  :0]  icache_Xbar_ar_burst ;
wire             icache_Xbar_r_ready ;
wire             icache_Xbar_aw_valid ;
wire    [31 :0]  icache_Xbar_aw_addr ;
wire    [3  :0]  icache_Xbar_aw_id ;
wire    [7  :0]  icache_Xbar_aw_len ;
wire    [2  :0]  icache_Xbar_aw_size ;
wire    [1  :0]  icache_Xbar_aw_burst ;
wire             icache_Xbar_w_valid ;
wire    [31 :0]  icache_Xbar_w_data ;
wire    [3  :0]  icache_Xbar_w_strb ;
wire             icache_Xbar_w_last ;
wire             icache_Xbar_b_ready ;
wire             lsu_Xbar_ar_valid ;
wire    [31 :0]  lsu_Xbar_ar_addr ;
wire    [3  :0]  lsu_Xbar_ar_id ;
wire    [7  :0]  lsu_Xbar_ar_len ;
wire    [2  :0]  lsu_Xbar_ar_size ;
wire    [1  :0]  lsu_Xbar_ar_burst ;
wire             lsu_Xbar_r_ready ;
wire             lsu_Xbar_aw_valid ;
wire    [31 :0]  lsu_Xbar_aw_addr ;
wire    [3  :0]  lsu_Xbar_aw_id ;
wire    [7  :0]  lsu_Xbar_aw_len ;
wire    [2  :0]  lsu_Xbar_aw_size ;
wire    [1  :0]  lsu_Xbar_aw_burst ;
wire             lsu_Xbar_w_valid ;
wire    [31 :0]  lsu_Xbar_w_data ;
wire    [3  :0]  lsu_Xbar_w_strb ;
wire             lsu_Xbar_w_last ;
wire             lsu_Xbar_b_ready ;
wire             Xbar_icache_ar_ready ;
wire             Xbar_icache_r_valid ;
wire    [31 :0]  Xbar_icache_r_data ;
wire    [1  :0]  Xbar_icache_r_resp ;
wire             Xbar_icache_r_last ;
wire    [3  :0]  Xbar_icache_r_id ;
wire             Xbar_icache_aw_ready ;
wire             Xbar_icache_w_ready ;
wire             Xbar_icache_b_valid ;
wire    [1  :0]  Xbar_icache_b_resp ;
wire    [3  :0]  Xbar_icache_b_id ;
wire             Xbar_lsu_ar_ready ;
wire             Xbar_lsu_r_valid ;
wire    [31 :0]  Xbar_lsu_r_data ;
wire    [1  :0]  Xbar_lsu_r_resp ;
wire             Xbar_lsu_r_last ;
wire    [3  :0]  Xbar_lsu_r_id ;
wire             Xbar_lsu_aw_ready ;
wire             Xbar_lsu_w_ready ;
wire             Xbar_lsu_b_valid ;
wire    [1  :0]  Xbar_lsu_b_resp ;
wire    [3  :0]  Xbar_lsu_b_id ;

//======================================================
//                   unuse signal
//======================================================
assign io_slave_awready =  1'd0;
assign io_slave_wready  =  1'd0;
assign io_slave_bvalid  =  1'd0;
assign io_slave_bid     =  4'd0;
assign io_slave_bresp   =  2'd0;
assign io_slave_arready =  1'd0;
assign io_slave_rvalid  =  1'd0;
assign io_slave_rid     =  4'd0;
assign io_slave_rdata   = 32'd0;
assign io_slave_rresp   =  2'd0;
assign io_slave_rlast   =  1'd0;

ysyx_23060170_IFU ifu (
    // input
    .clock                       (clock                         ),
    .reset                       (reset                         ),
    .idu_ready                   (idu_ready                     ),
    .lsu_ifu_flush               (lsu_flush                     ),
    .lsu_ifu_flush_pc            (lsu_flush_pc                  ),
    .lsu_ifu_fencei              (lsu_ifu_fencei                ),
    .icache_ifu_ready            (icache_ifu_ready              ),
    .icache_ifu_data             (icache_ifu_data               ),
    .icache_ifu_acc_fault        (icache_ifu_acc_fault          ),
    // output
    .ifu_valid                   (ifu_valid                     ),
    .ifu_idu_excp                (ifu_idu_excp                  ),
    .ifu_idu_excp_code           (ifu_idu_excp_code             ),
    .ifu_idu_pc                  (ifu_idu_pc                    ),
    .ifu_idu_tpc                 (ifu_idu_tpc                   ),
    .ifu_idu_inst                (ifu_idu_inst                  ),
    .ifu_icache_flush            (ifu_icache_flush              ),
    .ifu_icache_rls              (ifu_icache_rls                ),
    .ifu_icache_valid            (ifu_icache_valid              ),
    .ifu_icache_pc               (ifu_icache_pc                 )
);

ysyx_23060170_IDU idu (
    // input
    .clock                       (clock                         ),
    .reset                       (reset                         ),
    .ifu_valid                   (ifu_valid                     ),
    .exu_ready                   (exu_ready                     ),
    .lsu_idu_flush               (lsu_flush                     ),
    .ifu_idu_excp                (ifu_idu_excp                  ),
    .ifu_idu_excp_code           (ifu_idu_excp_code             ),
    .ifu_idu_pc                  (ifu_idu_pc                    ),
    .ifu_idu_tpc                 (ifu_idu_tpc                   ),
    .ifu_idu_inst                (ifu_idu_inst                  ),
    .gpr_idu_rdata1              (gpr_idu_rdata1                ),
    .gpr_idu_rdata2              (gpr_idu_rdata2                ),
    .csr_idu_rdata               (csr_idu_rdata                 ),
    .exu_idu_gpr_waddr           (exu_idu_gpr_waddr             ),
    .lsu_idu_gpr_waddr           (lsu_idu_gpr_waddr             ),
`ifdef ysyx_23060170_SIM_INFO
    .idu_exu_inst                (idu_exu_inst                  ),
    .idu_exu_tpc                 (idu_exu_tpc                   ),
`endif
    // output
    .idu_valid                   (idu_valid                     ),
    .idu_ready                   (idu_ready                     ),
    .idu_gpr_raddr1              (idu_gpr_raddr1                ),
    .idu_gpr_raddr2              (idu_gpr_raddr2                ),
    .idu_csr_raddr               (idu_csr_raddr                 ),
    .idu_exu_excp                (idu_exu_excp                  ),
    .idu_exu_excp_code           (idu_exu_excp_code             ),
    .idu_exu_exu_sel_signal      (idu_exu_exu_sel_signal        ),
    .idu_exu_out                 (idu_exu_out                   ),
    .idu_exu_gpr_rdata1          (idu_exu_gpr_rdata1            ),
    .idu_exu_gpr_rdata2          (idu_exu_gpr_rdata2            ),
    .idu_exu_pc                  (idu_exu_pc                    ),
    .idu_exu_tpc_or_csr_wdata    (idu_exu_tpc_or_csr_wdata      ),
    .idu_exu_branch_code         (idu_exu_branch_code           ),
    .idu_exu_alu_op              (idu_exu_alu_op                ),
    .idu_exu_gpr_wen             (idu_exu_gpr_wen               ),
    .idu_exu_gpr_waddr           (idu_exu_gpr_waddr             ),
    .idu_exu_csr_wen             (idu_exu_csr_wen               ),
    .idu_exu_csr_waddr           (idu_exu_csr_waddr             ),
    .idu_exu_mem_ren             (idu_exu_mem_ren               ),
    .idu_exu_mem_wen             (idu_exu_mem_wen               )
);

ysyx_23060170_EXU exu (
    // input
    .clock                       (clock                         ),
    .reset                       (reset                         ),
    .idu_valid                   (idu_valid                     ),
    .lsu_ready                   (lsu_ready                     ),
    .lsu_exu_flush               (lsu_flush                     ),
    .idu_exu_excp                (idu_exu_excp                  ),
    .idu_exu_excp_code           (idu_exu_excp_code             ),
    .idu_exu_exu_sel_signal      (idu_exu_exu_sel_signal        ),
    .idu_exu_out                 (idu_exu_out                   ),
    .idu_exu_gpr_rdata1          (idu_exu_gpr_rdata1            ),
    .idu_exu_gpr_rdata2          (idu_exu_gpr_rdata2            ),
    .idu_exu_pc                  (idu_exu_pc                    ),
    .idu_exu_tpc_or_csr_wdata    (idu_exu_tpc_or_csr_wdata      ),
    .idu_exu_branch_code         (idu_exu_branch_code           ),
    .idu_exu_alu_op              (idu_exu_alu_op                ),
    .idu_exu_gpr_wen             (idu_exu_gpr_wen               ),
    .idu_exu_gpr_waddr           (idu_exu_gpr_waddr             ),
    .idu_exu_csr_wen             (idu_exu_csr_wen               ),
    .idu_exu_csr_waddr           (idu_exu_csr_waddr             ),
    .idu_exu_mem_ren             (idu_exu_mem_ren               ),
    .idu_exu_mem_wen             (idu_exu_mem_wen               ),
`ifdef ysyx_23060170_SIM_INFO
    .idu_exu_tpc                 (idu_exu_tpc                   ),
    .idu_exu_inst                (idu_exu_inst                  ),
    .exu_lsu_tpc                 (exu_lsu_tpc                   ),
    .exu_lsu_inst                (exu_lsu_inst                  ),
`endif
    // output
    .exu_valid                   (exu_valid                     ),
    .exu_ready                   (exu_ready                     ),
    .exu_lsu_out                 (exu_lsu_out                   ),
    .exu_lsu_mem_func3           (exu_lsu_mem_func3             ),
    .exu_lsu_gpr_waddr           (exu_lsu_gpr_waddr             ),
    .exu_lsu_csr_waddr           (exu_lsu_csr_waddr             ),
    .exu_lsu_csr_or_mem_wdata    (exu_lsu_csr_or_mem_wdata      ),
    .exu_lsu_mem_ren             (exu_lsu_mem_ren               ),
    .exu_lsu_mem_wen             (exu_lsu_mem_wen               ),
    .exu_lsu_gpr_wen             (exu_lsu_gpr_wen               ),
    .exu_lsu_csr_wen             (exu_lsu_csr_wen               ),
    .exu_lsu_excp                (exu_lsu_excp                  ),
    .exu_lsu_excp_code           (exu_lsu_excp_code             ),
    .exu_lsu_is_fencei           (exu_lsu_is_fencei             ),
    .exu_lsu_br_mispred          (exu_lsu_br_mispred            ),
    .exu_lsu_pc                  (exu_lsu_pc                    ),
    .exu_lsu_npc                 (exu_lsu_npc                   ),
    .exu_idu_gpr_waddr           (exu_idu_gpr_waddr             )
);

ysyx_23060170_LSU lsu (
    // input
    .clock                       (clock                         ),
    .reset                       (reset                         ),
    .exu_valid                   (exu_valid                     ),
    .exu_lsu_excp                (exu_lsu_excp                  ),
    .exu_lsu_excp_code           (exu_lsu_excp_code             ),
    .exu_lsu_is_fencei           (exu_lsu_is_fencei             ),
    .exu_lsu_br_mispred          (exu_lsu_br_mispred            ),
    .exu_lsu_pc                  (exu_lsu_pc                    ),
    .exu_lsu_npc                 (exu_lsu_npc                   ),
    .exu_lsu_out                 (exu_lsu_out                   ),
    .exu_lsu_mem_func3           (exu_lsu_mem_func3             ),
    .exu_lsu_mem_ren             (exu_lsu_mem_ren               ),
    .exu_lsu_mem_wen             (exu_lsu_mem_wen               ),
    .exu_lsu_gpr_waddr           (exu_lsu_gpr_waddr             ),
    .exu_lsu_gpr_wen             (exu_lsu_gpr_wen               ),
    .exu_lsu_csr_waddr           (exu_lsu_csr_waddr             ),
    .exu_lsu_csr_or_mem_wdata    (exu_lsu_csr_or_mem_wdata      ),
    .exu_lsu_csr_wen             (exu_lsu_csr_wen               ),
    .csr_lsu_rdata               (csr_lsu_rdata                 ),
    .Xbar_lsu_ar_ready           (Xbar_lsu_ar_ready             ),
    .Xbar_lsu_r_valid            (Xbar_lsu_r_valid              ),
    .Xbar_lsu_r_data             (Xbar_lsu_r_data               ),
    .Xbar_lsu_r_resp             (Xbar_lsu_r_resp               ),
    .Xbar_lsu_r_last             (Xbar_lsu_r_last               ),
    .Xbar_lsu_r_id               (Xbar_lsu_r_id                 ),
    .Xbar_lsu_aw_ready           (Xbar_lsu_aw_ready             ),
    .Xbar_lsu_w_ready            (Xbar_lsu_w_ready              ),
    .Xbar_lsu_b_valid            (Xbar_lsu_b_valid              ),
    .Xbar_lsu_b_resp             (Xbar_lsu_b_resp               ),
    .Xbar_lsu_b_id               (Xbar_lsu_b_id                 ),
`ifdef ysyx_23060170_SIM_INFO
    .exu_lsu_tpc                 (exu_lsu_tpc                   ),
    .exu_lsu_inst                (exu_lsu_inst                  ),
    .lsu_valid                   (lsu_valid                     ),
    .lsu_ebreak                  (lsu_ebreak                    ),
    .lsu_wbu_pc                  (lsu_wbu_pc                    ),
    .lsu_wbu_npc                 (lsu_wbu_npc                   ),
    .lsu_wbu_inst                (lsu_wbu_inst                  ),
`endif
    // output
    .lsu_ready                   (lsu_ready                     ),
    .lsu_flush                   (lsu_flush                     ),
    .lsu_flush_pc                (lsu_flush_pc                  ),
    .lsu_ifu_fencei              (lsu_ifu_fencei                ),
    .lsu_out                     (lsu_out                       ),
    .lsu_gpr_waddr               (lsu_gpr_waddr                 ),
    .lsu_gpr_wen                 (lsu_gpr_wen                   ),
    .lsu_csr_wen                 (lsu_csr_wen                   ),
    .lsu_csr_waddr               (lsu_csr_waddr                 ),
    .lsu_csr_wdata               (lsu_csr_wdata                 ),
    .lsu_csr_excp                (lsu_csr_excp                  ),
    .lsu_csr_mcause              (lsu_csr_mcause                ),
    .lsu_Xbar_ar_valid           (lsu_Xbar_ar_valid             ),
    .lsu_Xbar_ar_addr            (lsu_Xbar_ar_addr              ),
    .lsu_Xbar_ar_id              (lsu_Xbar_ar_id                ),
    .lsu_Xbar_ar_len             (lsu_Xbar_ar_len               ),
    .lsu_Xbar_ar_size            (lsu_Xbar_ar_size              ),
    .lsu_Xbar_ar_burst           (lsu_Xbar_ar_burst             ),
    .lsu_Xbar_r_ready            (lsu_Xbar_r_ready              ),
    .lsu_Xbar_aw_valid           (lsu_Xbar_aw_valid             ),
    .lsu_Xbar_aw_addr            (lsu_Xbar_aw_addr              ),
    .lsu_Xbar_aw_id              (lsu_Xbar_aw_id                ),
    .lsu_Xbar_aw_len             (lsu_Xbar_aw_len               ),
    .lsu_Xbar_aw_size            (lsu_Xbar_aw_size              ),
    .lsu_Xbar_aw_burst           (lsu_Xbar_aw_burst             ),
    .lsu_Xbar_w_valid            (lsu_Xbar_w_valid              ),
    .lsu_Xbar_w_data             (lsu_Xbar_w_data               ),
    .lsu_Xbar_w_strb             (lsu_Xbar_w_strb               ),
    .lsu_Xbar_w_last             (lsu_Xbar_w_last               ),
    .lsu_Xbar_b_ready            (lsu_Xbar_b_ready              ),
    .lsu_idu_gpr_waddr           (lsu_idu_gpr_waddr             )
);

ysyx_23060170_icache_nx1 #(
    .SET_NUM(4)
) icache (
    // input
    .clock                       (clock                         ),
    .reset                       (reset                         ),
    .ifu_icache_flush            (ifu_icache_flush              ),
    .ifu_icache_rls              (ifu_icache_rls                ),
    .ifu_icache_valid            (ifu_icache_valid              ),
    .ifu_icache_pc               (ifu_icache_pc                 ),
    .Xbar_icache_ar_ready        (Xbar_icache_ar_ready          ),
    .Xbar_icache_r_valid         (Xbar_icache_r_valid           ),
    .Xbar_icache_r_data          (Xbar_icache_r_data            ),
    .Xbar_icache_r_resp          (Xbar_icache_r_resp            ),
    .Xbar_icache_r_last          (Xbar_icache_r_last            ),
    .Xbar_icache_r_id            (Xbar_icache_r_id              ),
    .Xbar_icache_aw_ready        (Xbar_icache_aw_ready          ),
    .Xbar_icache_w_ready         (Xbar_icache_w_ready           ),
    .Xbar_icache_b_valid         (Xbar_icache_b_valid           ),
    .Xbar_icache_b_resp          (Xbar_icache_b_resp            ),
    .Xbar_icache_b_id            (Xbar_icache_b_id              ),
    // output
    .icache_ifu_ready            (icache_ifu_ready              ),
    .icache_ifu_data             (icache_ifu_data               ),
    .icache_ifu_acc_fault        (icache_ifu_acc_fault          ),
    .icache_Xbar_ar_valid        (icache_Xbar_ar_valid          ),
    .icache_Xbar_ar_addr         (icache_Xbar_ar_addr           ),
    .icache_Xbar_ar_id           (icache_Xbar_ar_id             ),
    .icache_Xbar_ar_len          (icache_Xbar_ar_len            ),
    .icache_Xbar_ar_size         (icache_Xbar_ar_size           ),
    .icache_Xbar_ar_burst        (icache_Xbar_ar_burst          ),
    .icache_Xbar_r_ready         (icache_Xbar_r_ready           ),
    .icache_Xbar_aw_valid        (icache_Xbar_aw_valid          ),
    .icache_Xbar_aw_addr         (icache_Xbar_aw_addr           ),
    .icache_Xbar_aw_id           (icache_Xbar_aw_id             ),
    .icache_Xbar_aw_len          (icache_Xbar_aw_len            ),
    .icache_Xbar_aw_size         (icache_Xbar_aw_size           ),
    .icache_Xbar_aw_burst        (icache_Xbar_aw_burst          ),
    .icache_Xbar_w_valid         (icache_Xbar_w_valid           ),
    .icache_Xbar_w_data          (icache_Xbar_w_data            ),
    .icache_Xbar_w_strb          (icache_Xbar_w_strb            ),
    .icache_Xbar_w_last          (icache_Xbar_w_last            ),
    .icache_Xbar_b_ready         (icache_Xbar_b_ready           )
);

ysyx_23060170_gpr #(
    .ADDR_WIDTH(4),
    .DATA_WIDTH(32)
) gpr (
    // input
    .clock                       (clock                         ),
    .raddr1                      (idu_gpr_raddr1[3:0]           ),
    .raddr2                      (idu_gpr_raddr2[3:0]           ),
    .wen                         (lsu_gpr_wen                   ),
    .waddr                       (lsu_gpr_waddr[3:0]            ),
    .wdata                       (lsu_out                       ),
    // output
    .rdata1                      (gpr_idu_rdata1                ),
    .rdata2                      (gpr_idu_rdata2                )
);

ysyx_23060170_csr csr (
    // input
    .clock                       (clock                         ),
    .idu_csr_raddr               (idu_csr_raddr                 ),
    .lsu_csr_wen                 (lsu_csr_wen                   ),
    .lsu_csr_waddr               (lsu_csr_waddr                 ),
    .lsu_csr_wdata               (lsu_csr_wdata                 ),
    .lsu_csr_excp                (lsu_csr_excp                  ),
    .lsu_csr_mcause              (lsu_csr_mcause                ),
    // output
    .csr_idu_rdata               (csr_idu_rdata                 ),
    .csr_lsu_rdata               (csr_lsu_rdata                 )
);

ysyx_23060170_Xbar Xbar (
    // input
    .clock                       (clock                         ),
    .reset                       (reset                         ),
    .icache_Xbar_ar_valid        (icache_Xbar_ar_valid          ),
    .icache_Xbar_ar_addr         (icache_Xbar_ar_addr           ),
    .icache_Xbar_ar_id           (icache_Xbar_ar_id             ),
    .icache_Xbar_ar_len          (icache_Xbar_ar_len            ),
    .icache_Xbar_ar_size         (icache_Xbar_ar_size           ),
    .icache_Xbar_ar_burst        (icache_Xbar_ar_burst          ),
    .icache_Xbar_r_ready         (icache_Xbar_r_ready           ),
    .icache_Xbar_aw_valid        (icache_Xbar_aw_valid          ),
    .icache_Xbar_aw_addr         (icache_Xbar_aw_addr           ),
    .icache_Xbar_aw_id           (icache_Xbar_aw_id             ),
    .icache_Xbar_aw_len          (icache_Xbar_aw_len            ),
    .icache_Xbar_aw_size         (icache_Xbar_aw_size           ),
    .icache_Xbar_aw_burst        (icache_Xbar_aw_burst          ),
    .icache_Xbar_w_valid         (icache_Xbar_w_valid           ),
    .icache_Xbar_w_data          (icache_Xbar_w_data            ),
    .icache_Xbar_w_strb          (icache_Xbar_w_strb            ),
    .icache_Xbar_w_last          (icache_Xbar_w_last            ),
    .icache_Xbar_b_ready         (icache_Xbar_b_ready           ),
    .lsu_Xbar_ar_valid           (lsu_Xbar_ar_valid             ),
    .lsu_Xbar_ar_addr            (lsu_Xbar_ar_addr              ),
    .lsu_Xbar_ar_id              (lsu_Xbar_ar_id                ),
    .lsu_Xbar_ar_len             (lsu_Xbar_ar_len               ),
    .lsu_Xbar_ar_size            (lsu_Xbar_ar_size              ),
    .lsu_Xbar_ar_burst           (lsu_Xbar_ar_burst             ),
    .lsu_Xbar_r_ready            (lsu_Xbar_r_ready              ),
    .lsu_Xbar_aw_valid           (lsu_Xbar_aw_valid             ),
    .lsu_Xbar_aw_addr            (lsu_Xbar_aw_addr              ),
    .lsu_Xbar_aw_id              (lsu_Xbar_aw_id                ),
    .lsu_Xbar_aw_len             (lsu_Xbar_aw_len               ),
    .lsu_Xbar_aw_size            (lsu_Xbar_aw_size              ),
    .lsu_Xbar_aw_burst           (lsu_Xbar_aw_burst             ),
    .lsu_Xbar_w_valid            (lsu_Xbar_w_valid              ),
    .lsu_Xbar_w_data             (lsu_Xbar_w_data               ),
    .lsu_Xbar_w_strb             (lsu_Xbar_w_strb               ),
    .lsu_Xbar_w_last             (lsu_Xbar_w_last               ),
    .lsu_Xbar_b_ready            (lsu_Xbar_b_ready              ),
    .io_master_awready           (io_master_awready             ),
    .io_master_wready            (io_master_wready              ),
    .io_master_bvalid            (io_master_bvalid              ),
    .io_master_bid               (io_master_bid                 ),
    .io_master_bresp             (io_master_bresp               ),
    .io_master_arready           (io_master_arready             ),
    .io_master_rvalid            (io_master_rvalid              ),
    .io_master_rdata             (io_master_rdata               ),
    .io_master_rid               (io_master_rid                 ),
    .io_master_rresp             (io_master_rresp               ),
    .io_master_rlast             (io_master_rlast               ),
    // output
    .Xbar_icache_ar_ready        (Xbar_icache_ar_ready          ),
    .Xbar_icache_r_valid         (Xbar_icache_r_valid           ),
    .Xbar_icache_r_data          (Xbar_icache_r_data            ),
    .Xbar_icache_r_resp          (Xbar_icache_r_resp            ),
    .Xbar_icache_r_last          (Xbar_icache_r_last            ),
    .Xbar_icache_r_id            (Xbar_icache_r_id              ),
    .Xbar_icache_aw_ready        (Xbar_icache_aw_ready          ),
    .Xbar_icache_w_ready         (Xbar_icache_w_ready           ),
    .Xbar_icache_b_valid         (Xbar_icache_b_valid           ),
    .Xbar_icache_b_resp          (Xbar_icache_b_resp            ),
    .Xbar_icache_b_id            (Xbar_icache_b_id              ),
    .Xbar_lsu_ar_ready           (Xbar_lsu_ar_ready             ),
    .Xbar_lsu_r_valid            (Xbar_lsu_r_valid              ),
    .Xbar_lsu_r_data             (Xbar_lsu_r_data               ),
    .Xbar_lsu_r_resp             (Xbar_lsu_r_resp               ),
    .Xbar_lsu_r_last             (Xbar_lsu_r_last               ),
    .Xbar_lsu_r_id               (Xbar_lsu_r_id                 ),
    .Xbar_lsu_aw_ready           (Xbar_lsu_aw_ready             ),
    .Xbar_lsu_w_ready            (Xbar_lsu_w_ready              ),
    .Xbar_lsu_b_valid            (Xbar_lsu_b_valid              ),
    .Xbar_lsu_b_resp             (Xbar_lsu_b_resp               ),
    .Xbar_lsu_b_id               (Xbar_lsu_b_id                 ),
    .io_master_awvalid           (io_master_awvalid             ),
    .io_master_awid              (io_master_awid                ),
    .io_master_awaddr            (io_master_awaddr              ),
    .io_master_awlen             (io_master_awlen               ),
    .io_master_awsize            (io_master_awsize              ),
    .io_master_awburst           (io_master_awburst             ),
    .io_master_wvalid            (io_master_wvalid              ),
    .io_master_wdata             (io_master_wdata               ),
    .io_master_wstrb             (io_master_wstrb               ),
    .io_master_wlast             (io_master_wlast               ),
    .io_master_bready            (io_master_bready              ),
    .io_master_arvalid           (io_master_arvalid             ),
    .io_master_arid              (io_master_arid                ),
    .io_master_araddr            (io_master_araddr              ),
    .io_master_arlen             (io_master_arlen               ),
    .io_master_arsize            (io_master_arsize              ),
    .io_master_arburst           (io_master_arburst             ),
    .io_master_rready            (io_master_rready              )
);

endmodule
