module ysyx_25050136_WB
    #(
       parameter ADDR_WIDTH = 4
    )
    (
        input                                         clk,
        input                                       reset,
        input                                  in_valid_i,
        input  [ADDR_WIDTH-1:0]                   in_rd_i,
        input                                  in_rd_en_i,
        input  [31:0]                      in_gpr_wdata_i,
        output                                 in_ready_o,
`ifdef YSYXSOC
        input  [31:0]                         in_dbg_pc_i,
        input  [31:0]                       in_dbg_inst_i,
        input                          in_dbg_is_device_i,
        input  [5:0]                      in_dbg_optype_i,
        input  [31:0]                       in_dbg_addr_i,
        input  [31:0]                       in_dbg_data_i,
        input  [2:0]                         in_dbg_len_i,
        input  [1:0]                        in_dbg_type_i,
`endif
        input  [ADDR_WIDTH-1:0]                  raddr1_i,
        input  [ADDR_WIDTH-1:0]                  raddr2_i,
        output [31:0]                            rdata1_o,
        output [31:0]                            rdata2_o
    );
    // ==== 信号定义 ====
    wire in_fire = in_valid_i & in_ready_o;
    wire real_wen;
    // ==== 逻辑实现 ====
    assign in_ready_o = 1;
    assign real_wen = in_fire & in_rd_en_i;
`ifdef YSYXSOC
    reg [31:0] wb_dbg_pc    ;
    reg [31:0] wb_dbg_inst  ;
    reg [63:0] inst_count;
    always @(posedge clk) begin
        if(reset) begin
            wb_dbg_pc <= 0;
            wb_dbg_inst <= 0;
            inst_count <= 0;
        end else begin
            if(in_fire) begin
                if(in_dbg_is_device_i) find_diff_skip();
                wb_dbg_pc <= in_dbg_pc_i;
                wb_dbg_inst <= in_dbg_inst_i;
                inst_count <= inst_count + 64'd1;
                find_diff_mem(in_dbg_addr_i, in_dbg_data_i, {5'd0, in_dbg_len_i}, {6'd0, in_dbg_type_i});
            end
        end
    end
    always @(*) begin
        if((wb_dbg_pc != 0) & (wb_dbg_inst == 32'h00100073)) begin
            find_ebreak();
        end
    end
`ifdef EVENT_COUNTER
    always @(posedge clk) begin
        if(!reset) begin
            if(in_fire) begin
                commit_get();   // 提交指令计数
                case (1'b1)
                    in_dbg_optype_i[0] : begin // 定点运算操作
                        alu_get();
                    end
                    in_dbg_optype_i[1] : begin // 系统控制操作
                        system_get();
                    end
                    in_dbg_optype_i[2] : begin // 存储操作
                        store_get();
                    end
                    in_dbg_optype_i[3] : begin // 加载操作
                        load_get();
                    end
                    in_dbg_optype_i[4] : begin // 条件跳转
                        branch_get();
                    end
                    in_dbg_optype_i[5] : begin // 无条件跳转  
                        jump_get();
                    end 
                    default: ;
                endcase
            end
        end
    end
`endif
`endif

    ysyx_25050136_RegisterFile #(
        .ADDR_WIDTH(ADDR_WIDTH)
    ) u_ysyx_25050136_RegisterFile (
        .clk      	(clk             ),
        .wdata_i  	(in_gpr_wdata_i  ),
        .waddr_i  	(in_rd_i         ),
        .wen_i      (real_wen        ),
        .raddr1_i 	(raddr1_i        ),
        .raddr2_i 	(raddr2_i        ),
        .rdata1_o 	(rdata1_o        ),
        .rdata2_o 	(rdata2_o        )
    );

endmodule //ysyx_25050136_WB
