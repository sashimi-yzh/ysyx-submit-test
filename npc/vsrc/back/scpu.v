module scpu(
    input wire clk,          
    input wire rst,          
    output wire [6:0] seg0,  
    output wire [6:0] seg1,
    output reg [15:0] led  
);

    reg [3:0] pc_reg;
    wire [3:0] pc_next;
    assign pc_next = (opcode == 2'b11 && branch_taken) ? branch_addr : (pc_reg + 1'b1);

    reg [7:0] rom [0:15];  
    initial begin
        rom[0] = 8'h8A; 
        rom[1] = 8'h90; 
        rom[2] = 8'hA0; 
        rom[3] = 8'hB1; 
        rom[4] = 8'h17; 
        rom[5] = 8'h29; 
        rom[6] = 8'h42; // out r2
        rom[7] = 8'hD1; // bner0 4, r1
        rom[8] = 8'hE3; // bner0 8, r3
    end
    
    wire [7:0] ir; //IR指令寄存器
    assign ir = rom[pc_reg];

    // 译码
    wire [1:0] opcode;
    wire [1:0] rd;
    wire [1:0] rs1;
    wire [1:0] rs2;
    wire [3:0] imm;
    wire [3:0] branch_addr;
    
    assign opcode = ir[7:6];
    assign rd = ir[5:4];
    assign rs1 = ir[3:2];
    assign rs2 = ir[1:0];
    assign imm = ir[3:0];
    assign branch_addr = ir[5:2];

    // GPR
    reg [7:0] gpr [0:3];
    
    wire [7:0] rdata1;
    wire [7:0] rdata2;
    assign rdata1 = gpr[rs1];
    assign rdata2 = gpr[rs2];
    
    // 显存
    reg [7:0] display_reg;

    wire [7:0] alu_result;
    wire [7:0] li_data;
    wire branch_taken;
    
    assign alu_result = rdata1 + rdata2;
    assign li_data = {4'b0000, imm};
    assign branch_taken = (gpr[0] != rdata2);

    hex u_hex0 (
        .hex(display_reg[3:0]),
        .seg(seg0)
    );
    hex u_hex1 (
        .hex(display_reg[7:4]),
        .seg(seg1)
    );

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            pc_reg <= 4'd0;
            gpr = '{0, 0, 0, 0};
            display_reg <= 8'd0;
        end else begin
            pc_reg <= pc_next;
            case (opcode)
                2'b00: gpr[rd] <= alu_result;      // add
                2'b01: display_reg <= gpr[rs2];     // out rs (rs在rs2位置)
                2'b10: gpr[rd] <= li_data;         // li
                2'b11: ; //bner0 (无写回)
            endcase
        end
    end

endmodule