module top(
    input clk,
    input rstn,
    input [31:0] instr,
    //output reg[31:0] pc,
    output [31:0] dnpc,
    output [31:0] pc,
    output ebreak
);


wire [6:0] opcode;
wire [2:0] funct3;
wire [6:0] funct7;
wire [4:0] rd;
wire [4:0] rs1;
wire [4:0] rs2;
wire [1:0] csr_rst;
wire [1:0] csr_addr;
wire [31:0] imm;
wire [31:0] rs1_data;
wire [31:0] rs2_data;
wire [31:0] alu_out;
wire [31:0] wdata_in;
wire [31:0] rdata;
reg  [31:0] rdata_in;
reg  [31:0] csr_data;
wire  [31:0] csr_in;
wire [31:0] wdata;
wire [31:0] addr;
wire [3:0] wlen;
wire [31:0] inst_addr_o;
wire        pcsrc;
//wire [31:0] dnpc;
//wire ebreak;
wire branch;
wire mem_to_reg;
wire mem_read;
wire mem_write;
wire reg_write;
wire lw;
wire lh;
wire lb;
wire lbu;
wire lhu;
wire sw;
wire sb;
wire sh;
wire csw;
wire csc;
wire css;
wire ecall;
wire mret;
wire [1:0] alu_op;
wire [3:0] aluop;
wire     u_alu_type;
wire     mul_high;
wire     alu_src1;
wire     alu_src2;
wire     zero;
wire jal;
wire jalr;
wire     C_type;
wire     U_type_1;
wire     J_type_1;
assign pc = inst_addr_o;
wire clk_neg;
reg clk_reg;
PC my_pc(
    .clk            (clk        ),
    .rstn           (rstn       ),
    .pcsrc          (pcsrc      ),
    .imm            (imm        ),
    .rs1_data       (rs1_data   ),
    .alu_out        (alu_out    ),
    .zero           (zero       ),
    .jal            (jal        ),
    .jalr           (jalr       ),
    .ecall          (ecall      ),
    .mret           (mret       ),
    .csr_data       (csr_data   ),
    .dnpc           (dnpc       ),
    .inst_addr_o    (inst_addr_o)
);


idu my_idu(
    .instr          (instr      ),
    .opcode         (opcode     ),
    .funct3         (funct3     ),
    .funct7         (funct7     ),
    .rd             (rd         ),
    .rs1            (rs1        ),
    .rs2            (rs2        ),
    .csr_rst        (csr_rst    ),
    .imm            (imm        )
);

control my_crtl(
    .instr          (instr      ),
    .opcode         (opcode     ),
    .funct7         (funct7     ),
    .funct3         (funct3     ),
    .zero           (zero       ),
    .alu_op         (alu_op     ),
    .u_alu_type     (u_alu_type ), 
    .mul_high       (mul_high   ), 
    .alu_src1       (alu_src1   ), 
    .alu_src2       (alu_src2   ), 
    .branch         (branch     ), 
    //.jump           (jump       ), 
    .mem_to_reg     (mem_to_reg ), 
    .mem_read       (mem_read   ), 
    .mem_write      (mem_write  ), 
    .reg_write      (reg_write  ), 
    .jal            (jal        ),
    .jalr           (jalr       ),
    .lw             (lw         ), 
    .lh             (lh         ), 
    .lb             (lb         ),   
    .lbu            (lbu        ), 
    .lhu            (lhu        ), 
    .sw             (sw         ), 
    .sb             (sb         ), 
    .sh             (sh         ),
    .csw            (csw        ),
    .csc            (csc        ),
    .css            (css        ),
    .ebreak         (ebreak     ),
    .ecall          (ecall      ),
    .mret           (mret       ),
    .U_type_1       (U_type_1   ),
    .J_type_1       (J_type_1   ),
    .pcsrc          (pcsrc      ),
    .C_type         (C_type     )
);

assign wdata_in = (C_type) ? csr_data : (mem_to_reg)? rdata : alu_out;
wire ren;
wire wen;

assign wen = mem_write;
assign ren = mem_read;
RegisterFile #(.ADDR_WIDTH(5), .DATA_WIDTH(32)) rf1(
        .clk(clk),
        .wdata(wdata_in),
        .waddr(rd),
        .wen(reg_write),
        .rdata1(rs1_data),
        .raddr1(rs1),
        .rdata2(rs2_data),
        .raddr2(rs2)
    );

assign csr_in = ( {32{csw}} & (rs1_data)) |
                ( {32{csc}} & (rs1_data &csr_data)) |
                ( {32{css}} & (csr_data | rs1_data)) ;

assign csr_addr = (ecall) ? 'd3 : (mret) ? 'd0 :csr_rst;
csr_reg #(.ADDR_WIDTH(2), .DATA_WIDTH(32)) csr1(
        .clk(clk),
        .wdata(csr_in),
        .ecall(ecall),
        .pc(inst_addr_o),
        .waddr(csr_rst),
        .wen(C_type&(~mret)&(~ecall)),
        .rdata1(csr_data),
        .raddr1(csr_addr)
    );

alu_ctrl my_alu_crtl(
    .funct3         (funct3),
    .funct7         (funct7[5:0]),
    .alu_op         (alu_op),
    .aluOp          (aluop)
);

alu my_alu(
    .rs1_data       (rs1_data   ),
    .rs2_data       (rs2_data   ),
    .imm_data       (imm        ),
    .pc_data        (dnpc       ),
    .alu_src1       (alu_src1   ),
    .alu_src2       (alu_src2   ),
    .branch         (branch     ),   
    .J_type_1       (J_type_1   ),
    .u_alu_type     (u_alu_type ),
    .mul_high       (mul_high   ),
    .U_type_1       (U_type_1   ),
    .alu_crtl       (aluop      ),
    .alu_out        (alu_out    ),
    .zero           (zero       )
);

mmu my_mmu(
    .lw             (lw          ),
    .lh             (lh          ),           
    .lb             (lb          ),   
    .lbu            (lbu         ),
    .lhu            (lhu         ),
    .sw             (sw          ),
    .sb             (sb          ),
    .sh             (sh          ),
    .alu_result     (alu_out     ),
    .rs2_data       (rs2_data    ),
    .rdata          (rdata       ),
    .wlen           (wlen        ),
    .rdata_in       (rdata_in    ), 
    .wdata          (wdata       ),
    .addr           (addr        )
);
import "DPI-C" function void vpmem_read(input int raddr,input byte ren,output int rdata);
import "DPI-C" function void vpmem_write(input int waddr, input byte wmask,input int wdata,input byte wen);

always@(posedge clk)
begin 
   if(!rstn)begin
    clk_reg <= 1'b0;
    end
    else begin
    clk_reg <= clk;
    end
end
assign clk_neg = ~clk & clk_reg;
/*
always @(*) begin
   $display("Value of signal rdata_in is %08x", rdata_in);
   $display("Value of signal rdata is %08x", rdata);
   $display("Value of signal wdata_in is %08x", wdata_in);
end
*/
always @(*) begin
    vpmem_read(addr,{7'b0, ren},rdata_in);
end

always @(posedge clk_neg) begin

    vpmem_write(addr, {4'b0, wlen},wdata,{7'b0, wen});
    
end

endmodule


 




