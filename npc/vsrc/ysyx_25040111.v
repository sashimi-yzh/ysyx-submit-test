`include "HDR/ysyx_25040111_inc.vh"
`include "IDU/ysyx_25040111_idu.v"

module ysyx_25040111(
    input clock,
    input reset

`ifdef STA_SOC
    ,input          io_interrupt,

    input           io_master_awready,
    output          io_master_awvalid,
    output [31:0]   io_master_awaddr,
    output [3:0]    io_master_awid,
    output [7:0]    io_master_awlen,
    output [2:0]    io_master_awsize,
    output [1:0]    io_master_awburst,

    input           io_master_wready,
    output          io_master_wvalid,
    output [31:0]   io_master_wdata,
    output [3:0]    io_master_wstrb,
    output          io_master_wlast,

    output          io_master_bready,
    input           io_master_bvalid,
    input  [1:0]    io_master_bresp,
    input  [3:0]    io_master_bid,

    input           io_master_arready,
    output          io_master_arvalid,
    output [31:0]   io_master_araddr,
    output [3:0]    io_master_arid,
    output [7:0]    io_master_arlen,
    output [2:0]    io_master_arsize,
    output [1:0]    io_master_arburst,

    output          io_master_rready,
    input           io_master_rvalid,
    input  [1:0]    io_master_rresp,
    input  [31:0]   io_master_rdata,
    input           io_master_rlast,
    input  [3:0]    io_master_rid,

    output          io_slave_awready,
    input           io_slave_awvalid,
    input  [31:0]   io_slave_awaddr,
    input  [3:0]    io_slave_awid,
    input  [7:0]    io_slave_awlen,
    input  [2:0]    io_slave_awsize,
    input  [1:0]    io_slave_awburst,

    output          io_slave_wready,
    input           io_slave_wvalid,
    input  [31:0]   io_slave_wdata,
    input  [3:0]    io_slave_wstrb,
    input           io_slave_wlast,

    input           io_slave_bready,
    output          io_slave_bvalid,
    output [1:0]    io_slave_bresp,
    output [3:0]    io_slave_bid,

    output          io_slave_arready,
    input           io_slave_arvalid,
    input  [31:0]   io_slave_araddr,
    input  [3:0]    io_slave_arid,
    input  [7:0]    io_slave_arlen,
    input  [2:0]    io_slave_arsize,
    input  [1:0]    io_slave_arburst,

    input           io_slave_rready,
    output          io_slave_rvalid,
    output [1:0]    io_slave_rresp,
    output [31:0]   io_slave_rdata,
    output          io_slave_rlast,
    output [3:0]    io_slave_rid
`endif // RUNSOC
);

    // (icache : c) (ifu : f) (arbiter : a) (idu : d) (exu : x) 
    // (wbu : w)    (csr : s) (reg : r)     (lsu : l)

//-----------------------------------------------------------------
// CONTROL SIGNAL
//-----------------------------------------------------------------

    wire ifu_valid,     ifu_ready;
    wire icah_valid,    icah_ready;
    wire idu_valid,     idu_ready;
    wire exe_ready,     exe_valid;
    wire exu_valid,     exu_ready;
    wire lsu_wready,    lsu_wvalid;
    wire lsu_rready,    lsu_rvalid;
    wire reg_valid,     csr_valid;

    wire        jpc_ready; // from exu
    wire        err_find;  // from arbiter
    wire [3:0]  err_type;  // from arbiter

    wire fencei;

    wire flush = err_find | reset | fencei;
    wire cflush = fencei | reset;

//-----------------------------------------------------------------
// DATA SIGNAL
//-----------------------------------------------------------------

    // exu <==> ifu
    wire [31:0]         ef_jpc;

    // idu <==> exu
    wire [31:0]         de_pc;
    wire [31:0]         de_imm;
    wire [`OPT_HIGH:0]  de_opt;
    wire [4:0]          de_ard;
    wire [11:0]         de_awcsr;
    wire [3:0]          de_errtp;
    wire                de_err;

    // idu <==> csr | reg
    wire [4:0]          dr_ars1,
                        dr_ars2;
    wire [11:0]         ds_arcsr;

    // csr | reg <==> exu
    wire [31:0]         re_rs1,
                        re_rs2;
    wire [31:0]         se_csr;

    // idu <==> ifu
    wire                df_jump;
    wire [31:0]         fd_inst;
    wire [31:0]         fd_pc;

    // ifu <==> icache
    wire [31:0]         fc_addr;
    wire [31:0]         cf_inst;

    // icache <==> arbiter
    wire                ca_burst;
    wire [7:0]          ca_rlen;
    wire [31:0]         ca_addr;
    wire [31:0]         ac_data;

    // arbiter <==> lsu
    wire [31:0]         al_waddr;
    wire [31:0]         al_raddr;
    wire [31:0]         al_wdata;
    wire [1:0]          al_wmask;
    wire [31:0]         la_rdata;
    wire [7:0]          al_rlen;
    wire [1:0]          al_rmask;
    wire                al_rsign;
    wire                al_burst;

    // exu <==> arbiter
    wire                ea_men;
    wire [4:0]          ea_ard;
    wire [31:0]         ea_rd;
    wire                ea_gen;
    wire [11:0]         ea_acsr;
    wire [31:0]         ea_csr;
    wire [31:0]         ea_pc;
    wire                ea_sen;
    wire                ea_write;
    wire [31:0]         ea_wdata;
    wire [31:0]         ea_addr;
    wire [1:0]          ea_mask; 
    wire                ea_rsign;
    wire                ea_err;
    wire [3:0]          ea_errtp;
    wire                ea_fencei;

    // arbiter <==> reg | csr
    wire [31:0]         ar_data;
    wire [4:0]          ar_addr;
    wire [31:0]         as_data;
    wire [11:0]         as_addr;

//-----------------------------------------------------------------
// MODULE INSTANCES
//-----------------------------------------------------------------
    
    // IFU
    ysyx_25040111_ifu u_ifu(
        .clock     	(clock       ),
        .reset     	(reset       ),
        .ifu_addr  	(fc_addr     ),
        .ifu_inst  	(cf_inst     ),
        .jump      	(df_jump     ),
        .jump_pc  	(ef_jpc      ),
        .jpc_ready  (jpc_ready   ),
        .ifu_ready 	(ifu_ready   ),
        .ifu_valid 	(ifu_valid   ),
        .idu_inst   (fd_inst     ),
        .idu_pc     (fd_pc       ),
        .idu_valid 	(idu_valid   ), 
        .idu_ready 	(idu_ready   ),
        .err        (err_find    ),
        .errpc      (se_csr      )
    );

    // ICACHE
    ysyx_25040111_cache #(
        .CACHE_Ls 	(1  ),
        .BLOCK_Ls 	(5  ))
    u_icache(
        .clock  	(clock       ),
        .reset  	(cflush      ),
        .addr   	(fc_addr     ),
        .data   	(cf_inst     ),
        .chburst    (ca_burst    ),
        .chaddr     (ca_addr     ),
        .chlen      (ca_rlen     ),
        .chdata  	(ac_data     ),
        .ifu_valid  (ifu_valid   ),
        .ifu_ready  (ifu_ready   ),
        .chvalid 	(icah_valid  ),
        .chready   	(icah_ready  ),
        .err        (err_find    )
    );

    // ARBITER
    ysyx_25040111_arbiter u_arbiter(
        .clock      (clock       ),
        .reset      (reset       ),
        .cah_valid  (icah_valid  ),
        .cah_ready  (icah_ready  ),
        .cah_addr   (ca_addr     ),
        .cah_data   (ac_data     ),
        .cah_burst  (ca_burst    ),
        .cah_rlen   (ca_rlen     ),
        .exu_valid  (exu_valid   ),
        .exu_ready  (exu_ready   ),
        .exu_men    (ea_men      ),
        .exu_ard    (ea_ard      ),
        .exu_rd     (ea_rd       ),
        .exu_gen    (ea_gen      ),
        .exu_acsr   (ea_acsr     ),
        .exu_csr    (ea_csr      ),
        .exu_sen    (ea_sen      ),
        .exu_write  (ea_write    ),
        .exu_wdata  (ea_wdata    ),
        .exu_addr   (ea_addr     ),
        .exu_mask   (ea_mask     ),
        .exu_rsign  (ea_rsign    ),
        .exu_pc     (ea_pc       ),
        .lsu_rvalid (lsu_rvalid  ),
        .lsu_rready (lsu_rready  ),
        .lsu_rdata  (la_rdata    ),
        .lsu_raddr  (al_raddr    ),
        .lsu_rlen   (al_rlen     ),
        .lsu_burst  (al_burst    ),
        .lsu_rsign  (al_rsign    ),
        .lsu_rmask  (al_rmask    ),
        .lsu_wvalid (lsu_wvalid  ),
        .lsu_wready (lsu_wready  ),
        .lsu_wdata  (al_wdata    ),
        .lsu_waddr  (al_waddr    ),
        .lsu_wmask  (al_wmask    ),
        .reg_valid  (reg_valid   ),
        .csr_valid  (csr_valid   ),
        .reg_data   (ar_data     ),
        .csr_data   (as_data     ),
        .reg_addr   (ar_addr     ),
        .csr_addr   (as_addr     ),
        .erri       (ea_err      ),
        .errtpi     (ea_errtp    ),
        .erro       (err_find    ),
        .errtpo     (err_type    ),
        .in_fencei  (ea_fencei   ),
        .ot_fencei  (fencei      )
    );
    

    // IDU
    ysyx_25040111_idu u_idu(
        .clock     	(clock       ),
        .reset     	(flush       ),
        .idu_inst  	(fd_inst     ),
        .idu_ready 	(idu_ready   ),
        .idu_valid 	(idu_valid   ),
        .jump      	(df_jump     ),
        .exe_ready 	(exe_ready   ),
        .exe_valid 	(exe_valid   ),
        .rs1       	(dr_ars1     ),
        .rs2       	(dr_ars2     ),
        .rd        	(de_ard      ),
        .imm       	(de_imm      ),
        .opt       	(de_opt      ),
        .csrw      	(de_awcsr    ),
        .csrr      	(ds_arcsr    ),
        .idu_pc     (fd_pc       ),
        .exe_pc     (de_pc       ),
        .err        (de_err      ),
        .err_type   (de_errtp    )
    );
    
    // LSU
    ysyx_25040111_lsu u_lsu(
        .clock      (clock       ),
        .reset      (flush       ),
        .lsu_rvalid (lsu_rvalid  ),
        .lsu_rready (lsu_rready  ),
        .lsu_rdata  (la_rdata    ),
        .lsu_raddr  (al_raddr    ),
        .lsu_rlen   (al_rlen     ),
        .lsu_burst  (al_burst    ),
        .lsu_rsign  (al_rsign    ),
        .lsu_rmask  (al_rmask    ),
        .lsu_wvalid (lsu_wvalid  ),
        .lsu_wready (lsu_wready  ),
        .lsu_wdata  (al_wdata    ),
        .lsu_waddr  (al_waddr    ),
        .lsu_wmask  (al_wmask    )
`ifdef STA_SOC
        ,.io_master_awready (io_master_awready  ),
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
        .io_master_rid     	(io_master_rid      )
`endif
    );
    
    // EXU
    ysyx_25040111_exu u_exu(
        .clock     	(clock      ),
        .reset     	(flush      ),
        .exe_valid 	(exe_valid  ),
        .exe_ready 	(exe_ready  ),
        .opt       	(de_opt     ),
        .ard_in    	(de_ard     ),
        .ar1_in     (dr_ars1    ),
        .ar2_in     (dr_ars2    ),
        .acsrd_in  	(de_awcsr   ),
        .pc        	(de_pc      ),
        .imm       	(de_imm     ),
        .csri      	(se_csr     ),
        .rs1       	(re_rs1     ),
        .rs2       	(re_rs2     ),
        .abt_valid 	(exu_valid  ),
        .abt_ready 	(exu_ready  ),
        .abt_men   	(ea_men     ),
        .abt_ard   	(ea_ard     ),
        .abt_rd    	(ea_rd      ),
        .abt_gen   	(ea_gen     ),
        .abt_acsr  	(ea_acsr    ),
        .abt_csr   	(ea_csr     ),
        .abt_sen   	(ea_sen     ),
        .abt_write 	(ea_write   ),
        .abt_wdata 	(ea_wdata   ),
        .abt_addr  	(ea_addr    ),
        .abt_mask  	(ea_mask    ),
        .abt_rsign 	(ea_rsign   ),
        .jump_pc   	(ef_jpc     ),
        .jpc_ready 	(jpc_ready  ),
        .abt_finish (reg_valid  ),
        .abt_frd    (ar_addr    ),
        .abt_pc     (ea_pc      ),
        .erri       (de_err     ),
        .errtpi     (de_errtp   ),
        .erro       (ea_err     ),
        .errtpo     (ea_errtp   ),
        .fencei     (ea_fencei  )
    );
    
    // CSR
    wire        csr_ren   = (de_opt[11] & de_opt[15]) | err_find;
    wire [11:0] csr_raddr = err_find ? `MTVEC : ds_arcsr;
    ysyx_25040111_csr u_csr(
        .clock 	    (clock      ),
        .reset 	    (reset      ),
        .wen   	    (csr_valid  ),
        .ren   	    (csr_ren    ),
        .waddr 	    (as_addr    ),
        .wdata 	    (as_data    ),
        .raddr 	    (csr_raddr  ),
        .err        (err_find   ),
        .errtp 	    (err_type   ),
        .rdata 	    (se_csr     )
    );
    
    // REG    
    ysyx_25040111_reg u_reg(
        .clock   	(clock       ),
        .wen       	(reg_valid   ),
        .ren       	(de_opt[2:1] ),
        .wdata   	(ar_data     ),
        .waddr   	(ar_addr[3:0]),
        .ars1     	(dr_ars1[3:0]),
        .ars2     	(dr_ars2[3:0]),
        .rs1       	(re_rs1      ),
        .rs2       	(re_rs2      )
    );
    
endmodule
