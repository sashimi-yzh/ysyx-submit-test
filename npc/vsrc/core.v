module  ysyx_25050136_NPCCORE
(
    input                                     clk  ,
    input                                   reset  ,
    // 指令相关
    output                        inst_flush_o     ,
    output                        inst_req_valid_o ,
    output   [31:0]               inst_req_addr_o  ,
    input                         inst_ret_valid_i ,
    input                         inst_ret_last_i  ,
    input    [31:0]               inst_ret_data_i  ,
    // 数据相关
    input    [31:0]               mem_ret_rdata_i,
    input                         mem_ret_ready_i,
    output   [31:0]               mem_req_addr_o ,
    output                        mem_req_valid_o,
    output                        mem_req_ren_o  ,
    output                        mem_req_wen_o  ,
    output   [3:0]                mem_req_mask_o ,
    output   [2:0]                mem_req_size_o ,
    output                        mem_req_use_o  ,
    output   [31:0]               mem_req_wdata_o
);
//========================================
// 顶层信号定义
//========================================
localparam ADDR_WIDTH = 4;
// === 清洗流水线 ===
// 引发清洗的信号
wire id_branch_flush;
wire id_fencei_flush;
wire ex_branch_flush;
// 各级流水线接受的清洗信号
wire if_flush = id_branch_flush | id_fencei_flush | ex_branch_flush;
wire ic_flush = if_flush;
wire ic_fencei = id_fencei_flush;
wire id_flush = ex_branch_flush;
// === 跳转 ===
wire [31:0] id_branch_npc;
wire [31:0] ex_branch_npc;
wire [31:0] branch_npc = ex_branch_flush ? ex_branch_npc : id_branch_npc;
wire [31:0] id_pht_pc;
wire        id_pht_taken;
wire        id_pht_update;
wire        ex_btb_update;
wire [31:0] ex_btb_pc;
wire [31:0] ex_btb_target;
// === 取操作数 ===
wire [ADDR_WIDTH-1:0]   raddr1;
wire [ADDR_WIDTH-1:0]   raddr2;
wire [31:0]             rdata1;
wire [31:0]             rdata2;
// === DBG ===
`ifdef YSYXSOC
wire [31:0]                      id_dbg_inst/* verilator public_flat */;
wire [5:0]                     id_dbg_optype/* verilator public_flat */;
wire [31:0]                        ex_dbg_pc/* verilator public_flat */;
wire [31:0]                      ex_dbg_inst/* verilator public_flat */;
wire [5:0]                     ex_dbg_optype/* verilator public_flat */;
wire [31:0]                       mem_dbg_pc/* verilator public_flat */;
wire [31:0]                     mem_dbg_inst/* verilator public_flat */;
wire                       mem_dbg_is_device/* verilator public_flat */;
wire [5:0]                    mem_dbg_optype/* verilator public_flat */;
wire [31:0]                     mem_dbg_addr/* verilator public_flat */;
wire [31:0]                     mem_dbg_data/* verilator public_flat */;
wire [2:0]                       mem_dbg_len/* verilator public_flat */;
wire [1:0]                      mem_dbg_type/* verilator public_flat */;
`endif
// === 数据冒险 ===
wire [ADDR_WIDTH-1:0]   ex_waddr;
wire [31:0]            ex_wdata;
wire                   ex_wvalid;
wire                    ex_wen;
wire [ADDR_WIDTH-1:0]   mem_waddr;
wire [31:0]           mem_wdata;
wire                  mem_wvalid;
wire                   mem_wen;
// === IF和ICACHE ===
wire                    if_ic_ready;
wire [31:0]             if_ic_pc;
wire [31:0]             if_ic_prepc;
wire                    if_ic_taken;
wire                    if_ic_btb_hit;
wire                    if_ic_valid;
// === ICACHE和ID ===
wire                    ic_id_ready;
wire [31:0]             ic_id_inst;
wire [31:0]             ic_id_pc;
wire [31:0]             ic_id_prepc;
wire                    ic_id_taken;
wire                    ic_id_btb_hit;
wire                    ic_id_valid;
// === ID和EX ===
wire                    id_ex_ready;
wire                    id_ex_ebreak;
wire [31:0]             id_ex_dbg_inst;
wire [31:0]             id_ex_rdata1;
wire [ADDR_WIDTH-1:0]   id_ex_raddr1;
wire [31:0]             id_ex_rdata2;
wire [ADDR_WIDTH-1:0]   id_ex_raddr2;
wire [31:0]             id_ex_pc;
wire [31:0]             id_ex_npc;
wire [31:0]             id_ex_prepc;
wire                    id_ex_btb_hit;
wire [31:0]             id_ex_imm;
wire [3:0]              id_ex_alu_op;
wire [`ysyx_25050136_CSRU_OP_NUM-1:0] id_ex_csru_op;
wire                    id_ex_alu_op1_use_pc;
wire                    id_ex_alu_op2_use_imm;
wire                    id_ex_jump;
wire                    id_ex_mispredict;
wire                    id_ex_jalr;
wire                    id_ex_lsu_ren;
wire                    id_ex_lsu_wen;
wire [3:0]              id_ex_lsu_mask;
wire                    id_ex_lsu_signed;
wire [11:0]             id_ex_csr_addr;
wire                    id_ex_csr_ren;
wire                    id_ex_csr_wen;
wire                    id_ex_csr_wdata_use_rs1;
wire [4:0]              id_ex_rs1;
wire                    id_ex_rd_npc;
wire [ADDR_WIDTH-1:0]   id_ex_rd;
wire                    id_ex_rd_en;
wire                    id_ex_valid;
// === EX和MEM ===
wire                    ex_mem_ready;
wire                    ex_mem_ebreak;
wire [ADDR_WIDTH-1:0]   ex_mem_rd;
wire                    ex_mem_rd_en;
wire [31:0]             ex_mem_gpr_wdata;
wire                    ex_mem_lsu_ren;
wire                    ex_mem_lsu_wen;
wire [3:0]              ex_mem_lsu_mask;
wire                    ex_mem_lsu_signed;
wire [31:0]             ex_mem_lsu_addr;
wire [31:0]             ex_mem_lsu_wdata;
wire                    ex_mem_valid;
// === MEM和WB ===
wire                    mem_wb_ready;
wire                    mem_wb_ebreak;
wire [ADDR_WIDTH-1:0]   mem_wb_rd;
wire                    mem_wb_rd_en;
wire [31:0]             mem_wb_gpr_wdata;
wire                    mem_wb_valid;

assign inst_flush_o = ic_flush;
//========================================
// 子模块
//========================================

ysyx_25050136_IF u_ysyx_25050136_IF(
    .clk            (clk            ),
    .reset          (reset          ),
    .flush          (if_flush       ),
    .branch_npc_i   (branch_npc     ),
    .pht_pc_i       (id_pht_pc      ),
    .pht_update_i   (id_pht_update  ),
    .pht_taken_i    (id_pht_taken   ),
    .btb_pc_i       (ex_btb_pc      ),
    .btb_update_i   (ex_btb_update  ),
    .btb_target_i   (ex_btb_target  ),
    .out_ready_i    (if_ic_ready    ),
    .out_pc_o       (if_ic_pc       ),
    .out_prepc_o    (if_ic_prepc    ),
    .out_taken_o    (if_ic_taken    ),
    .out_btb_hit_o  (if_ic_btb_hit  ),
    .out_valid_o    (if_ic_valid    )
);

ysyx_25050136_ICACHE 
#(
    .OFFSET_WIDTH 	(4             ),
    .NUM_WAY      	(1             ),
    .INDEX_WIDTH  	(2             )
)u_ysyx_25050136_ICACHE(  
    .clk            	(clk               ),
    .reset          	(reset             ),
    .flush          	(ic_flush          ),
    .fencei         	(ic_fencei         ),
    .in_valid_i     	(if_ic_valid       ),
    .in_pc_i        	(if_ic_pc          ),
    .in_prepc_i     	(if_ic_prepc       ),
    .in_taken_i     	(if_ic_taken       ),
    .in_btb_hit_i   	(if_ic_btb_hit     ),
    .in_ready_o     	(if_ic_ready       ),
    .out_ready_i    	(ic_id_ready       ),
    .out_inst_o     	(ic_id_inst        ),
    .out_pc_o       	(ic_id_pc          ),
    .out_prepc_o    	(ic_id_prepc       ),
    .out_taken_o    	(ic_id_taken       ),
    .out_btb_hit_o  	(ic_id_btb_hit     ),
    .out_valid_o    	(ic_id_valid       ),
    .req_valid_o     	(inst_req_valid_o  ),
    .ret_valid_i     	(inst_ret_valid_i  ),
    .ret_last_i      	(inst_ret_last_i   ),
    .ret_data_i      	(inst_ret_data_i   )
);
assign inst_req_addr_o = ic_id_pc;
ysyx_25050136_ID #(
    .ADDR_WIDTH     (ADDR_WIDTH)
) u_ysyx_25050136_ID (
    .clk                      (clk                       ),
    .reset                    (reset                     ),
    .flush                    (id_flush                  ),
    .in_valid_i               (ic_id_valid               ),
    .in_inst_i                (ic_id_inst                ),
    .in_pc_i                  (ic_id_pc                  ),
    .in_prepc_i               (ic_id_prepc               ),
    .in_taken_i               (ic_id_taken               ),
    .in_btb_hit_i             (ic_id_btb_hit             ),
    .in_ready_o               (ic_id_ready               ),
    .out_ready_i              (id_ex_ready               ),
`ifdef YSYXSOC
    .out_dbg_inst_o           (id_dbg_inst               ),
    .out_dbg_optype_o         (id_dbg_optype             ),
`endif
    .out_pc_o                 (id_ex_pc                  ),
    .out_npc_o                (id_ex_npc                 ),
    .out_ebreak_o             (id_ex_ebreak              ),
    .out_prepc_o              (id_ex_prepc               ),
    .out_btb_hit_o            (id_ex_btb_hit             ),
    .out_rdata1_o             (id_ex_rdata1              ),
    .out_rdata2_o             (id_ex_rdata2              ),
    .out_imm_o                (id_ex_imm                 ),
    .out_alu_op_o             (id_ex_alu_op              ),
    .out_csru_op_o            (id_ex_csru_op             ),
    .out_alu_op1_use_pc_o     (id_ex_alu_op1_use_pc      ),
    .out_alu_op2_use_imm_o    (id_ex_alu_op2_use_imm     ),
    .out_jump_o               (id_ex_jump                ),
    .out_mispredict_o         (id_ex_mispredict          ),
    .out_jalr_o               (id_ex_jalr                ),
    .out_lsu_ren_o            (id_ex_lsu_ren             ),
    .out_lsu_wen_o            (id_ex_lsu_wen             ),
    .out_lsu_mask_o           (id_ex_lsu_mask            ),
    .out_lsu_signed_o         (id_ex_lsu_signed          ),
    .out_csr_addr_o           (id_ex_csr_addr            ),
    .out_csr_ren_o            (id_ex_csr_ren             ),
    .out_csr_wen_o            (id_ex_csr_wen             ),
    .out_csr_wdata_use_rs1_o  (id_ex_csr_wdata_use_rs1   ),
    .out_rs1_o                (id_ex_rs1                 ),
    .out_rd_npc_o             (id_ex_rd_npc              ),
    .out_rd_o                 (id_ex_rd                  ),
    .out_rd_en_o              (id_ex_rd_en               ),
    .out_valid_o              (id_ex_valid               ),
    .ex_wen_i                 (ex_wen                    ),
    .ex_wvalid_i              (ex_wvalid                 ),
    .ex_waddr_i               (ex_waddr                  ),
    .ex_wdata_i               (ex_wdata                  ),
    .mem_wen_i                (mem_wen                   ),
    .mem_wvalid_i             (mem_wvalid                ),
    .mem_waddr_i              (mem_waddr                 ),
    .mem_wdata_i              (mem_wdata                 ),
    .out_rdata1_i             (rdata1                    ),
    .out_raddr1_o             (raddr1                    ),
    .out_rdata2_i             (rdata2                    ),
    .out_raddr2_o             (raddr2                    ),
    .branch_flush_o           (id_branch_flush           ),
    .branch_npc_o             (id_branch_npc             ),
    .pht_update_o             (id_pht_update             ),
    .pht_pc_o                 (id_pht_pc                 ),
    .pht_taken_o              (id_pht_taken              ),
    .fencei_flush_o           (id_fencei_flush           )
);

ysyx_25050136_EX #(
    .ADDR_WIDTH     (ADDR_WIDTH)
) u_ysyx_25050136_EX (
    .clk                      (clk                      ),
    .reset                    (reset                    ),
    .flush                    (1'b0                     ), // EX stage does not receive external flush
    .in_valid_i               (id_ex_valid              ),
    .in_pc_i                  (id_ex_pc                 ),
    .in_npc_i                 (id_ex_npc                ),
    .in_ebreak_i              (id_ex_ebreak             ),
    .in_prepc_i               (id_ex_prepc              ),
    .in_btb_hit_i             (id_ex_btb_hit            ),
    .in_rdata1_i              (id_ex_rdata1             ),
    .in_rdata2_i              (id_ex_rdata2             ),
    .in_imm_i                 (id_ex_imm                ),
    .in_alu_op_i              (id_ex_alu_op             ),
    .in_csru_op_i             (id_ex_csru_op            ),
    .in_alu_op1_use_pc_i      (id_ex_alu_op1_use_pc     ),
    .in_alu_op2_use_imm_i     (id_ex_alu_op2_use_imm    ),
    .in_jump_i                (id_ex_jump               ),
    .in_mispredict_i          (id_ex_mispredict         ),
    .in_jalr_i                (id_ex_jalr               ),
    .in_lsu_ren_i             (id_ex_lsu_ren            ),
    .in_lsu_wen_i             (id_ex_lsu_wen            ),
    .in_lsu_mask_i            (id_ex_lsu_mask           ),
    .in_lsu_signed_i          (id_ex_lsu_signed         ),
    .in_csr_addr_i            (id_ex_csr_addr           ),
    .in_csr_ren_i             (id_ex_csr_ren            ),
    .in_csr_wen_i             (id_ex_csr_wen            ),
    .in_csr_wdata_use_rs1_i   (id_ex_csr_wdata_use_rs1  ),
    .in_rs1_i                 (id_ex_rs1                ),
    .in_rd_npc_i              (id_ex_rd_npc             ),
    .in_rd_i                  (id_ex_rd                 ),
    .in_rd_en_i               (id_ex_rd_en              ),
    .in_ready_o               (id_ex_ready              ),
`ifdef YSYXSOC
    .in_dbg_inst_i            (id_dbg_inst              ),
    .in_dbg_optype_i          (id_dbg_optype            ),
    .out_dbg_pc_o             (ex_dbg_pc                ),
    .out_dbg_inst_o           (ex_dbg_inst              ),
    .out_dbg_optype_o         (ex_dbg_optype            ),
`endif
    .out_ready_i              (ex_mem_ready             ),
    .out_ebreak_o             (ex_mem_ebreak            ),
    .out_rd_o                 (ex_mem_rd                ),
    .out_rd_en_o              (ex_mem_rd_en             ),
    .out_gpr_wdata_o          (ex_mem_gpr_wdata         ),
    .out_lsu_ren_o            (ex_mem_lsu_ren           ),
    .out_lsu_wen_o            (ex_mem_lsu_wen           ),
    .out_lsu_mask_o           (ex_mem_lsu_mask          ),
    .out_lsu_signed_o         (ex_mem_lsu_signed        ),
    .out_lsu_addr_o           (ex_mem_lsu_addr          ),
    .out_lsu_wdata_o          (ex_mem_lsu_wdata         ),
    .out_valid_o              (ex_mem_valid             ),
    .btb_update_o             (ex_btb_update            ),
    .btb_pc_o                 (ex_btb_pc                ),
    .btb_target_o             (ex_btb_target            ),
    .branch_flush_o           (ex_branch_flush          ),
    .branch_npc_o             (ex_branch_npc            ),
    .wen_o                    (ex_wen                   ),
    .waddr_o                  (ex_waddr                 ),
    .wdata_o                  (ex_wdata                 ),
    .wvalid_o                 (ex_wvalid                )
);


ysyx_25050136_MEM #(
    .ADDR_WIDTH 	(ADDR_WIDTH)
) u_ysyx_25050136_MEM (
    .clk             	(clk                ),
    .reset           	(reset              ),
    .flush           	(1'b0              ),
    .in_valid_i      	(ex_mem_valid       ),
    .in_ebreak_i    	(ex_mem_ebreak      ),
    .in_rd_i         	(ex_mem_rd          ),
    .in_rd_en_i      	(ex_mem_rd_en       ),
    .in_gpr_wdata_i  	(ex_mem_gpr_wdata   ),
    .in_req_ren_i    	(ex_mem_lsu_ren     ),
    .in_req_wen_i    	(ex_mem_lsu_wen     ),
    .in_req_mask_i   	(ex_mem_lsu_mask    ),
    .in_lsu_signed_i 	(ex_mem_lsu_signed  ),
    .in_req_addr_i   	(ex_mem_lsu_addr    ),
    .in_lsu_wdata_i  	(ex_mem_lsu_wdata   ),
    .in_ready_o      	(ex_mem_ready       ),
`ifdef YSYXSOC
    .in_dbg_pc_i     	(ex_dbg_pc          ),
    .in_dbg_inst_i   	(ex_dbg_inst        ),
    .in_dbg_optype_i  	(ex_dbg_optype      ),
    .out_dbg_pc_o    	(mem_dbg_pc         ),
    .out_dbg_inst_o  	(mem_dbg_inst       ),
    .out_dbg_is_device_o(mem_dbg_is_device  ),
    .out_dbg_optype_o	(mem_dbg_optype     ),
    .out_dbg_addr_o     (mem_dbg_addr),
    .out_dbg_data_o     (mem_dbg_data),
    .out_dbg_len_o      (mem_dbg_len),
    .out_dbg_type_o     (mem_dbg_type),
`endif
    .out_ready_i     	(mem_wb_ready       ),
    .out_rd_o        	(mem_wb_rd          ),
    .out_ebreak_o     	(mem_wb_ebreak      ),
    .out_rd_en_o     	(mem_wb_rd_en       ),
    .out_gpr_wdata_o 	(mem_wb_gpr_wdata   ),
    .out_valid_o     	(mem_wb_valid       ),
    .wen_o           	(mem_wen            ),
    .waddr_o         	(mem_waddr          ),
    .wdata_o         	(mem_wdata          ),
    .wvalid_o        	(mem_wvalid         ),
    .ret_rdata_i     	(mem_ret_rdata_i    ),
    .ret_ready_i     	(mem_ret_ready_i    ),
    .req_addr_o      	(mem_req_addr_o     ),
    .req_valid_o     	(mem_req_valid_o    ),
    .req_ren_o       	(mem_req_ren_o      ),
    .req_wen_o       	(mem_req_wen_o      ),
    .req_mask_o      	(mem_req_mask_o     ),
    .req_size_o      	(mem_req_size_o     ),
    .req_use_o       	(mem_req_use_o      ),
    .req_wdata_o     	(mem_req_wdata_o    )
);

ysyx_25050136_WB #(
    .ADDR_WIDTH 	(4  )
) u_ysyx_25050136_WB (
    .clk             	(clk              ),
    .reset           	(reset            ),
    .in_valid_i      	(mem_wb_valid     ),
    .in_rd_i         	(mem_wb_rd        ),
    .in_rd_en_i      	(mem_wb_rd_en     ),
    .in_gpr_wdata_i  	(mem_wb_gpr_wdata ),
    .in_ready_o      	(mem_wb_ready     ),
`ifdef YSYXSOC
    .in_dbg_addr_i     (mem_dbg_addr),
    .in_dbg_data_i     (mem_dbg_data),
    .in_dbg_len_i      (mem_dbg_len),
    .in_dbg_type_i     (mem_dbg_type),
    .in_dbg_pc_i     	(mem_dbg_pc       ),
    .in_dbg_inst_i   	(mem_dbg_inst     ),
    .in_dbg_is_device_i (mem_dbg_is_device),
    .in_dbg_optype_i  	(mem_dbg_optype   ),
`endif
    .raddr1_i  	        (raddr1           ),
    .raddr2_i     	    (raddr2           ),
    .rdata1_o           (rdata1           ),
    .rdata2_o     	    (rdata2           )
);

endmodule
