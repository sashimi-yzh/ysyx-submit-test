module NPCCORE_TEST (
    input                                     clk,
    input                                   reset,
    // 指令相关
    input                         inst_req_ready_i,
    output  [31:0]                inst_req_addr_o ,
    output                        inst_req_valid_o,
    input                         inst_ret_valid_i,
    input   [31:0]                inst_ret_addr_i ,
    input   [31:0]                inst_ret_rdata_i,
    output                        inst_ret_ready_o,
    output                            inst_flush_o,
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

    assign mem_req_addr_o = 0;
    assign mem_req_valid_o = 0;
    assign mem_req_ren_o = 0;
    assign mem_req_wen_o = 0;
    assign mem_req_mask_o = 0;
    assign mem_req_size_o = 0;
    assign mem_req_use_o = 0;
    assign mem_req_wdata_o = 0;

    wire branch_valid;
    wire id_ex_valid;
    wire id_ex_ready;
    wire ex_mem_valid;
    wire ex_mem_ready;
    wire mem_wb_valid;
    wire mem_wb_ready;
    wire [31:0] id_ex_pc;
    wire [31:0] id_ex_inst;
    wire [31:0] ex_mem_pc;
    wire [31:0] ex_mem_inst;
    wire [31:0] mem_wb_pc;
    wire [31:0] mem_wb_inst;
    wire [31:0] branch_npc;
    IF u_IF(
        .clk         	(clk               ),
        .reset       	(reset             ),
        .flush          (branch_valid      ),
        .branch_npc     (branch_npc        ),
        .out_ready_i 	(inst_req_ready_i  ),
        .out_pc_o    	(inst_req_addr_o   ),
        .out_valid_o 	(inst_req_valid_o  )
    );

    ID u_ID(
        .clk         	(clk               ),
        .reset       	(reset             ),
        .flush       	(branch_valid      ),
        .in_valid_i  	(inst_ret_valid_i  ),
        .in_pc_i     	(inst_ret_addr_i   ),
        .in_inst_i   	(inst_ret_rdata_i  ),
        .in_ready_o  	(inst_ret_ready_o  ),
        .out_ready_i 	(id_ex_ready       ),
        .out_pc_o    	(id_ex_pc          ),
        .out_inst_o  	(id_ex_inst        ),
        .out_valid_o 	(id_ex_valid       )
    );

    EX u_EX(
        .clk          	(clk               ),
        .reset        	(reset             ),
        .in_valid_i   	(id_ex_valid       ),
        .in_pc_i      	(id_ex_pc          ),
        .in_inst_i    	(id_ex_inst        ),
        .in_ready_o   	(id_ex_ready       ),
        .out_ready_i    (ex_mem_ready      ),
        .out_pc_o       (ex_mem_pc         ),
        .out_inst_o     (ex_mem_inst       ),
        .out_valid_o    (ex_mem_valid      ),
        .branch_valid 	(branch_valid      ),
        .branch_npc   	(branch_npc        )
    );

    
    MEM u_MEM(
        .clk         	(clk               ),
        .reset       	(reset             ),
        .in_valid_i  	(ex_mem_valid      ),
        .in_pc_i     	(ex_mem_pc         ),
        .in_inst_i   	(ex_mem_inst       ),
        .in_ready_o  	(ex_mem_ready      ),
        .out_ready_i 	(mem_wb_ready      ),
        .out_pc_o    	(mem_wb_pc         ),
        .out_inst_o  	(mem_wb_inst       ),
        .out_valid_o 	(mem_wb_valid      )
    );

    WB u_WB(
        .clk        	(clk               ),
        .reset      	(reset             ),
        .in_valid_i 	(mem_wb_valid      ),
        .in_pc_i    	(mem_wb_pc         ),
        .in_inst_i  	(mem_wb_inst       ),
        .in_ready_o 	(mem_wb_ready      )
    );

    assign inst_flush_o = branch_valid;
endmodule

module IF(
    input clk,
    input reset,
    input flush,
    input [31:0] branch_npc,
    input out_ready_i,
    output [31:0] out_pc_o,    
    output out_valid_o
);
    reg [31:0] pc;
    reg idle;
    wire out_fire = out_ready_i & out_valid_o;
    wire [31:0] next_pc = pc + 32'h4;
    always @(posedge clk) begin
        if(reset) begin
            idle <= 1;
            pc <= 32'h3000_0000;
        end else begin
            idle <= 0;
            if(flush) begin
                pc <= branch_npc;
            end else if(out_fire) begin
                pc <= next_pc;
            end
        end
    end
    assign out_pc_o = pc;
    assign out_valid_o = !(idle || flush);
endmodule //IF

module ID(
    input clk,
    input reset,
    input flush,
    input in_valid_i,
    input [31:0] in_pc_i,
    input [31:0] in_inst_i,
    output in_ready_o,
    input out_ready_i,
    output [31:0] out_pc_o,
    output [31:0] out_inst_o,
    output out_valid_o
);
    reg idle;
    reg [31:0] id_pc;
    reg [31:0] id_inst;
    wire in_fire = in_valid_i & in_ready_o;
    wire out_fire = out_valid_o & out_ready_i;
    wire ready_go = 1;
    always @(posedge clk) begin
        if(reset) begin
            idle <= 1;
            id_pc <= 0;
            id_inst <= 0;
        end else begin
            if(flush) begin
                idle <= 1;
            end else if(in_fire) begin
                idle <= 0;
                id_pc <= in_pc_i;
                id_inst <= in_inst_i;
            end else if(out_fire) begin
                idle <= 1;
            end
        end
    end
    assign in_ready_o = idle || out_fire;
    assign out_pc_o = id_pc;
    assign out_inst_o = id_inst;
    assign out_valid_o = !(idle || flush) && ready_go;
endmodule //ID

module EX(
    input clk,
    input reset,
    input in_valid_i,
    input [31:0] in_pc_i,
    input [31:0] in_inst_i,
    output in_ready_o,
    input out_ready_i,
    output [31:0] out_pc_o,
    output [31:0] out_inst_o,
    output out_valid_o,
    output branch_valid, 
    output [31:0] branch_npc
); 
    reg idle;
    reg [31:0] ex_pc;
    reg [31:0] ex_inst;
    wire in_fire = in_valid_i & in_ready_o;
    wire out_fire = out_valid_o & out_ready_i;
    wire ready_go = 1;
    always @(posedge clk) begin
        if(reset) begin
            idle <= 1;
            ex_pc <= 0;
            ex_inst <= 0;
        end else begin
            if(in_fire) begin
                idle <= 0;
                ex_pc <= in_pc_i;
                ex_inst <= in_inst_i;
            end else if(out_fire) begin
                idle <= 1;
            end
        end
    end

    assign in_ready_o = idle || out_fire;
    assign out_pc_o = ex_pc;
    assign out_inst_o = ex_inst;
    assign out_valid_o = !idle && ready_go;
    assign branch_valid = out_valid_o && (ex_pc == 32'h3000_0020);
    assign branch_npc = 32'ha000_0000;
endmodule //EX

module MEM(
    input clk,
    input reset,
    input in_valid_i,
    input [31:0] in_pc_i,
    input [31:0] in_inst_i,
    output in_ready_o,
    input out_ready_i,
    output [31:0] out_pc_o,
    output [31:0] out_inst_o,
    output out_valid_o
);
    reg idle;
    reg [31:0] mem_pc;
    reg [31:0] mem_inst;
    wire in_fire = in_valid_i & in_ready_o;
    wire out_fire = out_valid_o & out_ready_i;
    wire ready_go = 1;
    always @(posedge clk) begin
        if(reset) begin
            idle <= 1;
            mem_pc <= 0;
            mem_inst <= 0;
        end else begin
            if(in_fire) begin
                idle <= 0;
                mem_pc <= in_pc_i;
                mem_inst <= in_inst_i;
            end else if(out_fire) begin
                idle <= 1;
            end
        end
    end
    assign in_ready_o = idle || out_fire;
    assign out_valid_o = !idle && ready_go;
    assign out_pc_o = mem_pc;
    assign out_inst_o = mem_inst;
endmodule //ID

module WB(
    input clk,
    input reset,
    input in_valid_i,
    input [31:0] in_pc_i,
    input [31:0] in_inst_i,
    output in_ready_o
); 
    reg idle;
    reg [31:0] wb_pc;
    reg [31:0] wb_inst;
    wire in_fire = in_valid_i & in_ready_o;
    always @(posedge clk) begin
        if(reset) begin
            idle <= 1;
            wb_pc <= 0;
            wb_inst <= 0;
        end else begin
            if(in_fire) begin
                wb_pc <= in_pc_i;
                wb_inst <= in_inst_i;
            end
        end
    end

    assign in_ready_o = idle;
endmodule //MEM
