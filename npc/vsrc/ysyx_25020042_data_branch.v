
module ysyx_25020042_data_branch(
    input                clock,
    input                reset,
    input [4:0]          i_rs1,
    input [4:0]          i_rs2,
    input [4:0]          i_rd,
    input [2:0]          i_exu_to_lsu_inst,
    input [2:0]          i_idu_to_exu_inst,
    input                idu_exu_handshake,
    input                exu_lsu_handshake,
    input                lsu_wbu_handshake,
    input                load_valid,
    input  [31:0]        i_exu_rd_data,
    input  [31:0]        i_lsu_rd_data,
    input  [31:0]        i_src1,
    input  [31:0]        i_src2,
    output reg           rs1_data_ready,
    output reg           rs2_data_ready,
    output reg [31:0]    rs1_data,
    output reg [31:0]    rs2_data,
    output  [4:0]        o_rs1,
    output  [4:0]        o_rs2,
    output  [31:0]       o_exu_rd_data,
    output  [31:0]       o_lsu_rd_data,
    output  [4:0]        o_lsu_rd
);


reg [31:0] exu_rd_data_buffer;
reg [31:0] lsu_rd_data_buffer;
reg [4:0]  exu_rd_buffer;
reg [4:0]  lsu_rd_buffer;
reg        exu_rd_valid;
reg        lsu_rd_valid;
wire rs1_hit = i_rs1 != 0 && (i_rs1 == exu_rd_buffer || i_rs1 == lsu_rd_buffer);
wire rs2_hit = i_rs2 != 0 && (i_rs2 == exu_rd_buffer || i_rs2 == lsu_rd_buffer);

assign o_exu_rd_data = exu_rd_data_buffer;
assign o_lsu_rd_data = lsu_rd_data_buffer;
assign o_lsu_rd = lsu_rd_buffer;

assign o_rs1 = i_rs1;
assign o_rs2 = i_rs2;

always @(*) begin
    rs1_data_ready = 1;
    rs1_data = i_src1;
    if (rs1_hit) begin
        if (i_rs1 == exu_rd_buffer && exu_rd_valid) begin
            rs1_data = exu_rd_data_buffer;
        end
        else if (i_rs1 == lsu_rd_buffer && lsu_rd_valid) begin
            rs1_data = lsu_rd_data_buffer;
        end
        else begin
            rs1_data = 0;
            rs1_data_ready = 0;
        end
    end
end

always @(*) begin
    rs2_data_ready = 1;
    rs2_data = i_src2;
    if (rs2_hit) begin
        if (i_rs2 == exu_rd_buffer && exu_rd_valid) begin
            rs2_data = exu_rd_data_buffer;
        end
        else if (i_rs2 == lsu_rd_buffer && lsu_rd_valid) begin
            rs2_data = lsu_rd_data_buffer;
        end
        else begin
            rs2_data = 0;
            rs2_data_ready = 0;
        end
    end
end

always @(posedge clock) begin
    if (reset) begin
        // exu_rd_data_buffer <= 0;
        exu_rd_buffer <= 0;
        exu_rd_valid <= 0;
    end
    else begin

        if (idu_exu_handshake) begin
            exu_rd_buffer <= i_rd;
            exu_rd_data_buffer <= i_exu_rd_data;
            if (i_idu_to_exu_inst == 3'b011 || i_idu_to_exu_inst == 3'b010)
                exu_rd_valid <= 0;
            else 
                exu_rd_valid <= 1;
        end
        else if (exu_lsu_handshake) begin
            exu_rd_buffer <= 0;
        end
    end
end

always @(posedge clock) begin
    if (reset) begin
        // lsu_rd_data_buffer <= 0;
        lsu_rd_buffer <= 0;
        lsu_rd_valid <= 0;
    end
    else begin
        case (1'b1)
            exu_lsu_handshake: begin
                lsu_rd_buffer <= exu_rd_buffer;
                lsu_rd_data_buffer <= exu_rd_data_buffer;
            if (i_exu_to_lsu_inst != 3'b011 && i_exu_to_lsu_inst != 3'b010) begin
                lsu_rd_valid <= 1;
            end
            else 
                lsu_rd_valid <= 0;
            end
            load_valid: begin
                lsu_rd_data_buffer <= i_lsu_rd_data;
                lsu_rd_valid <= 1;

            end
            lsu_wbu_handshake: begin
                lsu_rd_buffer <= 0;
            end
        endcase

    end
end

endmodule
