module ROM_TEST (
    input            clk          ,
    input            reset        ,
    input            flush_i      ,
    input            req_valid_i  ,
    input    [31:0]  req_addr_i   ,
    output           req_ready_o  ,
    input            ret_ready_i  ,
    output   [31:0]  ret_addr_o   ,
    output   [31:0]  ret_rdata_o  ,
    output           ret_valid_o    
);

// output declaration of module ROM_1
wire temp_ready;
wire [31:0] temp_pc;
wire [31:0] temp_inst;
wire temp_valid;

    ROM_1 u_ROM_1(
        .clk         	(clk          ),
        .reset       	(reset        ),
        .flush       	(flush_i      ),
        .in_valid_i  	(req_valid_i  ),
        .in_pc_i     	(req_addr_i   ),
        .in_ready_o  	(req_ready_o  ),
        .out_ready_i 	(temp_ready   ),
        .out_pc_o    	(temp_pc      ),
        .out_inst_o  	(temp_inst    ),
        .out_valid_o 	(temp_valid   )
    );
    ROM_2 u_ROM_2(
        .clk         	(clk          ),
        .reset       	(reset        ),
        .flush       	(flush_i      ),
        .in_valid_i  	(temp_valid   ),
        .in_pc_i     	(temp_pc      ),
        .in_inst_i   	(temp_inst    ),
        .in_ready_o  	(temp_ready   ),
        .out_ready_i 	(ret_ready_i  ),
        .out_pc_o    	(ret_addr_o   ),
        .out_inst_o  	(ret_rdata_o  ),
        .out_valid_o 	(ret_valid_o  )
    );
    
endmodule

module ROM_1(
    input clk,
    input reset,
    input flush,
    input in_valid_i,
    input [31:0] in_pc_i,
    output in_ready_o,
    input out_ready_i,
    output [31:0] out_pc_o,
    output [31:0] out_inst_o,
    output out_valid_o
);
    reg idle;
    reg [31:0] id_pc;
    wire in_fire = in_valid_i & in_ready_o;
    wire out_fire = out_valid_o & out_ready_i;
    wire ready_go = 1;
    reg [31:0] rom_mem [0:15];
    initial begin
        rom_mem[0 ] = 32'h0f000537; // lui   a0,0xf000
        rom_mem[1 ] = 32'h00200593; // li    a1,2
        rom_mem[2 ] = 32'h00b52023; // sw    a1,0(a0)
        rom_mem[3 ] = 32'h00052283; // lw    t0,0(a0)
        rom_mem[4 ] = 32'h00b28333; // add   t1,t0,a1
        rom_mem[5 ] = 32'h00138393; // addi  t2,t2,1
        rom_mem[6 ] = 32'h40730333; // sub   t1,t1,t2
        rom_mem[7 ] = 32'hfe031ee3; // bnez  t1,skip
        rom_mem[8 ] = 32'h00140413; // addi  s0,s0,1
        rom_mem[9 ] = 32'h00108093; // addi  ra,ra,1
        rom_mem[10] = 32'h00100073; // ebreak
        rom_mem[11] = 32'h00000013;
        rom_mem[12] = 32'h00000013;
        rom_mem[13] = 32'h00000013;
        rom_mem[14] = 32'h00000013;
        rom_mem[15] = 32'h00000013;
    end
    always @(posedge clk) begin
        if(reset) begin
            idle <= 1;
            id_pc <= 0;
        end else begin
            if(flush) begin
                idle <= 1;
            end else if(in_fire) begin
                idle <= 0;
                id_pc <= in_pc_i;
            end else if(out_fire) begin
                idle <= 1;
            end
        end
    end
    assign in_ready_o = idle || out_fire;
    assign out_pc_o = id_pc;
    assign out_inst_o = rom_mem[id_pc[5:2]];
    assign out_valid_o = !(idle || flush) && ready_go;
endmodule //ROM1

module ROM_2(
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
endmodule //ROM2
