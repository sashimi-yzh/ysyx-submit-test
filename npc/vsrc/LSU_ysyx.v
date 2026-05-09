`include "npc_config.vh"

module ysyx_25040102_LSU_ysyx(

    input               clk,
    input               reset,

    // lsu ctrl
    // input   [31:0]      lsu_addr, // 内存操作地址
    input   [31:0]      lsu_data, // 写内存数据
    input   [1:0]       lsu_mode, // 00不访存，01 load，11 store，10 mdata
    input   [2:0]       lsu_op,   // memop,指示字节

    // pc_reg
    input   [31:0]      Next_pc,
    input   [31:0]      pc,
    output  [31:0]      pc_out,

    input   [3:0]       mcause,
    input               mcause_wr,
    output  [3:0]       mcause_out,
    output              mcause_wr_out,

    // reg ctrl
    input   [3:0]       Rw,
    input   [31:0]      result,
    input               regwr,
    
    // pc_reg
    output  [31:0]      Next_pc_out,
    
    // reg ctrl
    output  [3:0]       Rw_out,
    output  [31:0]      result_out,
    output              regwr_out,

    output  [1:0]       lsu_mode_out,

    input               lsu_valid,
    output              lsu_ready,

    // input               wbu_ready,
    // output              wbu_valid, // 向wbu模块发

    input               master_awready,
    output              master_awvalid, 
    output  [31:0]      master_awaddr,  
    output  [3:0]       master_awid,    
    output  [7:0]       master_awlen,   
    output  [2:0]       master_awsize,  
    output  [1:0]       master_awburst, 
    input               master_wready,  
    output              master_wvalid,  
    output  [31:0]      master_wdata,   
    output  [3:0]       master_wstrb,   
    output              master_wlast,   
    output              master_bready,  
    input               master_bvalid,  
    input   [1:0]       master_bresp,   
    input   [3:0]       master_bid,     

    input               master_arready, 
    output              master_arvalid,
    output  [31:0]      master_araddr,  
    output  [3:0]       master_arid,    
    output  [7:0]       master_arlen,   
    output  [2:0]       master_arsize,  
    output  [1:0]       master_arburst, 
    output              master_rready,  
    input               master_rvalid,  
    input   [1:0]       master_rresp,   
    input   [31:0]      master_rdata,   
    input               master_rlast,   
    input   [3:0]       master_rid     

);

    reg     [2:0]       current_state;
    reg     [2:0]       next_state;

    // localparam IDLE             = 0;
    localparam WAIT_LSUVALID    = 0;
    localparam WAIT_ARREADY     = 1;
    localparam WAIT_RVALID      = 2;
    localparam WAIT_AWREADY     = 3;
    localparam WAIT_WREADY      = 4;
    localparam WAIT_BVALID      = 5;
    localparam WAIT_WBUREADY    = 6;

    reg     [31:0]      rdata_r;

    // wire    [31:0]  rdata_r     = master_rdata;

    reg     [1:0]       lsu_mode_r;
    reg     [2:0]       memop_r;
    wire    [31:0]      Addr_r;
    reg     [31:0]      DataIn_r;

    reg     [31:0]      Next_pc_r;
    
    // reg ctrl
    reg     [3:0]       Rw_r;
    reg     [31:0]      result_r; // alu result
    reg                 regwr_r; 
    reg     [31:0]      master_wdata_r;
    reg     [1:0]       rresp_r;
    reg     [1:0]       bresp_r;

    always @(posedge clk) begin
        if(reset == 1'b1) begin
            current_state       <= WAIT_LSUVALID;
        end
        else begin
            current_state       <= next_state;
        end
    end

    always @(*) begin

        case(current_state)
            
            WAIT_LSUVALID: begin
                if(lsu_valid == 1'b1) begin
                    if(lsu_mode == 2'b11) begin // write
                        next_state = WAIT_AWREADY;
                    end
                    else if(lsu_mode == 2'b01) begin // read
                        next_state = WAIT_ARREADY;
                    end
                    else begin
                        next_state = WAIT_WBUREADY;
                    end
                end
                else begin
                    next_state = WAIT_LSUVALID;
                end
            end

            WAIT_ARREADY: begin
                if(master_arready == 1'b1) begin
                    next_state = WAIT_RVALID;
                end
                else begin
                    next_state = WAIT_ARREADY;
                end
            end

            WAIT_RVALID: begin
                if(master_rvalid == 1'b1) begin
                    next_state = WAIT_WBUREADY;
                end
                else begin
                    next_state = WAIT_RVALID;
                end
            end

            WAIT_AWREADY: begin
                if(master_awready == 1'b1) begin
                    next_state = WAIT_WREADY;
                end
                else begin
                    next_state = WAIT_AWREADY;
                end
            end

            WAIT_WREADY: begin
                if(master_wready == 1'b1) begin
                    next_state = WAIT_BVALID;
                end
                else begin
                    next_state = WAIT_WREADY;
                end
            end

            WAIT_BVALID: begin
                if(master_bvalid == 1'b1) begin
                    next_state = WAIT_WBUREADY;               
                end
                else begin
                    next_state = WAIT_BVALID;
                end
            end

            WAIT_WBUREADY: begin // write reg
                // if(wbu_ready == 1'b1) begin
                    next_state = WAIT_LSUVALID;
                // end
                // else begin
                    // next_state = WAIT_WBUREADY;
                // end
            end

            default: begin
                next_state = WAIT_LSUVALID;
            end

        endcase
    end

    reg     [3:0]   mcause_r;
    reg     [3:0]   mcause_ls;
    reg             mcause_wr_r;

    assign  mcause_wr_out   = rresp_r != 2'b00 || bresp_r != 2'b00 || mcause_wr_r == 1'b1;
    assign  mcause_out  = mcause_ls;

    always @(*) begin
        if(mcause_wr_r == 1'b1) begin
            mcause_ls   = mcause_r;
        end
        else begin
            if(rresp_r != 2'b00) begin
                mcause_ls = 4'h4;
            end
            else if(bresp_r != 2'b00) begin
                mcause_ls = 4'h7;
            end
            else begin
                mcause_ls = 4'h0;
            end
        end
    end

    reg     [3:0]               m_wstrb_r;
    assign  master_wstrb        = m_wstrb_r;
    assign  master_arburst      = 2'b01;

    reg     [31:0]              r_data;
    reg     [31:0]              pc_r;


    assign  Next_pc_out     = Next_pc_r;
    assign  pc_out          = pc_r;

    // read data
    always @(*) begin

        case(memop_r[1:0])
            2'b00: begin // lb
                case(Addr_r[1:0])
                    2'b00: r_data = {{24{rdata_r[7] & !memop_r[2]}}, rdata_r[7:0]};
                    2'b01: r_data = {{24{rdata_r[15] & !memop_r[2]}}, rdata_r[15:8]};
                    2'b10: r_data = {{24{rdata_r[23] & !memop_r[2]}}, rdata_r[23:16]};
                    2'b11: r_data = {{24{rdata_r[31] & !memop_r[2]}}, rdata_r[31:24]};
                endcase
            end
            
            2'b01: begin // lh
                case(Addr_r[1:0])
                    2'b00: r_data = {{16{rdata_r[15] & !memop_r[2]}}, rdata_r[15:0]}; // 0
                    2'b10: r_data = {{16{rdata_r[31] & !memop_r[2]}}, rdata_r[31:16]}; // 2
                    default: r_data = 32'h0; // 不会出现
                endcase
            end

            default: begin
                r_data = rdata_r;
            end
        endcase
    end

    assign  master_arsize   = {1'b0, memop_r[1:0]};

    // write
    always @(*) begin

        case(memop_r[1:0])
            2'b00: begin // sb
                case(Addr_r[1:0])
                    2'b00: m_wstrb_r = 4'b0001;
                    2'b01: m_wstrb_r = 4'b0010;
                    2'b10: m_wstrb_r = 4'b0100;
                    2'b11: m_wstrb_r = 4'b1000;
                endcase
            end

            2'b01: begin // sh
                case(Addr_r[1:0])
                    2'b00: m_wstrb_r = 4'b0011;
                    2'b10: m_wstrb_r = 4'b1100;
                    default: m_wstrb_r = 4'b0000;
                endcase
            end
            
            default: begin
                m_wstrb_r = 4'b1111;
            end
        endcase
    end

    always @(*) begin
        case(Addr_r[1:0])
            2'b00: master_wdata_r = DataIn_r;
            2'b01: master_wdata_r = {DataIn_r[23:0], 8'h00};
            2'b10: master_wdata_r = {DataIn_r[15:0], 16'h00};
            2'b11: master_wdata_r = {DataIn_r[7:0], 24'h00};
        endcase
    end

    // AXI_lite
    assign  lsu_ready           = current_state == WAIT_LSUVALID;
    // 传araddr  
    assign  master_arvalid      = current_state == WAIT_ARREADY;
    assign  master_araddr       = Addr_r;
    assign  master_arlen        = 8'h00;
    assign  master_arid         = (current_state == WAIT_ARREADY) ? 4'h1 : 0;
 
    assign  master_rready       = current_state == WAIT_RVALID;

    // 传awaddr 
    assign  master_awvalid      = current_state == WAIT_AWREADY;
    assign  master_awaddr       = Addr_r;
    assign  master_awid         = 4'h1;
    assign  master_awburst      = 2'b01;

    // 传wdata
    assign  master_wvalid       = current_state == WAIT_WREADY;
    assign  master_wdata        = master_wdata_r;
    assign  master_wlast        = current_state == WAIT_WREADY;
    assign  master_awlen        = 8'h00;
    assign  master_awsize       = 3'b010;
    //
    assign  master_bready       = current_state == WAIT_BVALID;

    assign  Rw_out              = (current_state == WAIT_LSUVALID) ? 4'h0 : Rw_r;
    assign  result_out          = (lsu_mode_r == 2'b01) ? r_data : result_r; // read
    assign  regwr_out           = (current_state == WAIT_WBUREADY) ? regwr_r : 0;
    assign  lsu_mode_out        = (current_state == WAIT_LSUVALID) ? 2'b00 : lsu_mode_r;

    assign  Addr_r              = result_r;

    always @(posedge clk) begin // 从EXU接收mem操作数据
        if(lsu_valid == 1'b1 && lsu_ready == 1'b1) begin
            lsu_mode_r      <= lsu_mode;
            memop_r         <= lsu_op;
            DataIn_r        <= lsu_data;
            Next_pc_r       <= Next_pc;
            Rw_r            <= Rw;
            result_r        <= result;
            regwr_r         <= regwr;
            pc_r            <= pc;
            mcause_r        <= mcause;
            mcause_wr_r     <= mcause_wr;
        end
    end

    always @(posedge clk) begin // 从SRAM收数据
        if(reset == 1'b1) begin
            rdata_r         <= 32'hffffffff;
        end
        else begin
            if(master_rready == 1'b1 && master_rvalid == 1'b1) begin
                rdata_r         <= master_rdata;
            end
        end
    end

    always @(posedge clk) begin
        if(reset == 1'b1 || current_state == WAIT_LSUVALID) begin
            rresp_r         <= 2'b00;
        end
        else begin
            if(master_rready == 1'b1 && master_rvalid == 1'b1) begin
                rresp_r     <= master_rresp;
            end
        end
    end

    always @(posedge clk) begin
         if(reset == 1'b1 || current_state == WAIT_LSUVALID) begin
            bresp_r         <= 2'b00;
        end
        else begin
            if(master_bready == 1'b1 && master_bvalid == 1'b1) begin
                bresp_r     <= master_bresp;
            end
        end
    end

`ifdef ysyx_25040102_DIFFTEST // skip ref
    always @(posedge clk) begin // addr
        if(master_awready == 1'b1 && master_awvalid == 1'b1) begin
            if(in_mem(master_awaddr)) begin
                difftest_skip_ref();
                // $display("skip, %h", pc_pc);
            end
        end
        else if(master_arready == 1'b1 && master_arvalid == 1'b1) begin
            if(in_mem(master_araddr)) begin
                difftest_skip_ref();
                // $display("skip, %h", pc_pc);
            end
        end
    end
`endif

`ifdef ysyx_25040102_SIM
    always @(posedge clk) begin
        if(current_state == WAIT_LSUVALID && (lsu_mode == 2'b11 || lsu_mode == 2'b01)) begin
            time_add(2);
        end
    end

    always @(posedge clk) begin
        if(current_state != WAIT_LSUVALID && current_state != WAIT_WBUREADY) begin
            cycle_add(2);
        end
    end

`endif

`ifdef ysyx_25040102_SIM
    always @(posedge clk) begin
        if(mcause_wr == 1'b1 && mcause == 4'h3) begin
            call_ebreak();
        end
    end
`endif

`ifdef __ICARUS__

    always @(posedge clk) begin
        if(mcause_wr == 1'b1 && mcause == 4'h3) begin
            $finish(1);
        end
    end
    
`endif

endmodule
