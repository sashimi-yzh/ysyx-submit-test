module alu(
    input [31:0] rs1_data,
    input [31:0] rs2_data,
    input [31:0] imm_data,
    input [31:0] pc_data,
    input alu_src1,
    input alu_src2,
    input branch,
    input u_alu_type,
    input mul_high,
    input U_type_1,
    input J_type_1,
    input [3:0] alu_crtl,
    output reg [31:0] alu_out,
    output reg zero
);
    wire [31:0] a;
    wire [31:0] b;
    assign a = (alu_src1)? rs1_data : (U_type_1) ? 32'h00000000 : pc_data;
    assign b = (alu_src2)? rs2_data : (J_type_1) ? 32'h00000004 : imm_data;
    wire signed [31:0] signed_a = $signed(a);
    wire signed [31:0] signed_b = $signed(b);
    wire unsigned [31:0] unsigned_a = a;
    wire unsigned [31:0] unsigned_b = b;
    wire [31:0] opdata1;
    wire [31:0] opdata2;
    assign opdata1 = (u_alu_type)? unsigned_a : signed_a;
    assign opdata2 = (u_alu_type)? unsigned_b : signed_b;
    /*
    always @(*) begin
    $display("Value of signal opdata1 is %08x", opdata1);
    $display("Value of signal opdata2 is %08x", opdata2&32'h0000001f);
    $display("Value of signal alu_out is %08x", alu_out);
     $display("Value of signal alu_crtl is %04b", alu_crtl);
    end
    */
    always @(*) begin
        case (alu_crtl)
            4'b0000: begin
                    alu_out = opdata1 + opdata2;
                    zero = 1'b0;
                end
            4'b0001: begin
                    alu_out = opdata1 - opdata2;
                    zero = 1'b0;
                end
            4'b0010: begin
                    alu_out = opdata1 << opdata2;
                    zero = 1'b0;
                end
            4'b0011: begin
                if(branch)
                    if(u_alu_type) begin
                        if(rs1_data < rs2_data)begin
                            alu_out = pc_data + imm_data;
                            zero = 1'b1;
                        end
                        else begin
                            alu_out = pc_data + 32'h4;
                            zero = 1'b0;
                        end
                    end
                    else begin
                        if($signed(rs1_data) < $signed(rs2_data))begin
                            alu_out = pc_data + imm_data;
                            zero = 1'b1;
                        end
                        else begin
                            alu_out = pc_data + 32'h4;
                            zero = 1'b0;
                        end
                    end
                else begin
                    if(u_alu_type) begin
                        alu_out = (opdata1 < opdata2) ? 1 : 0;
                        zero = 1'b0;
                    end
                    else begin
                        alu_out = ($signed(opdata1) < $signed(opdata2)) ? 1 : 0;
                        zero = 1'b0;
                    end
                end
            end
            4'b0100: begin
                    alu_out = opdata1 ^ opdata2;
                    zero = 1'b0;
                end 
            4'b0101: begin
                    alu_out = opdata1 >> (opdata2 & 32'h0000001f);
                    zero = 1'b0;
            end
            4'b0110: begin 
                    alu_out = $signed(opdata1) >>> (opdata2 & 32'h0000001f);
                    zero = 1'b0;
            end
            4'b0111: begin 
                    alu_out = opdata1 | opdata2;
                    zero = 1'b0;
            end
            4'b1000: begin
                    alu_out = opdata1 & opdata2;
                    zero = 1'b0;
            end
            4'b1001: begin
                zero = 1'b0;
                alu_out = 32'b0;
            end
            4'b1010: begin
                    alu_out = 32'b0;
                    zero = 1'b0;
                end
            4'b1011: begin
                    alu_out = 32'b0;
                    zero = 1'b0;
                end
            4'b1100:
                if(branch)begin
                    if(u_alu_type) begin
                        if(rs1_data >= rs2_data)begin
                            alu_out = pc_data + imm_data;
                            zero = 1'b1;
                        end
                        else begin
                            alu_out = pc_data + 32'h4;
                            zero = 1'b0;
                        end
                    end
                    else begin
                        if($signed(rs1_data) >= $signed(rs2_data))begin
                            alu_out = pc_data + imm_data;
                            zero = 1'b1;
                        end
                        else begin
                            alu_out = pc_data + 32'h4;
                            zero = 1'b0;
                        end
                    end
                end
                else begin
                    alu_out = (opdata1 >= opdata2) ? 1 : 0;
                    zero = 1'b0;
                end
            4'b1101: 
                if(branch)
                    if(rs1_data != rs2_data)begin
                        alu_out = pc_data + imm_data;
                        zero = 1'b1;
                    end
                    else begin
                        alu_out = pc_data + 32'h4;
                        zero = 1'b0;
                    end
                else begin
                    alu_out = (opdata1 != opdata2) ? 1 : 0;
                    zero = 1'b0;
                end
            4'b1110: 
                if(branch)
                    if(rs1_data == rs2_data)begin
                        alu_out = pc_data + imm_data;
                        zero = 1'b1;
                    end
                    else begin
                        alu_out = pc_data + 32'h4;
                        zero = 1'b0;
                    end
                else begin
                    alu_out = (opdata1 == opdata2) ? 1 : 0;
                    zero = 1'b0;
                end
            4'b1111: begin
                    alu_out = 32'b0;
                    zero = 1'b0;
                end
            default: begin
                    alu_out = 32'b0;
                    zero = 1'b0;
                end
        endcase
        
    end
endmodule
