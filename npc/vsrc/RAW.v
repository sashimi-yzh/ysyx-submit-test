

// ██████╗  ██████╗  ██╗    ██╗
// ██╔══██╗ ██╔══██╗ ██║    ██║
// ██████╔╝ ███████║ ██║ █╗ ██║
// ██╔══██╗ ██╔══██║ ██║███╗██║
// ██║  ██║ ██║  ██║ ╚███╔███╔╝
// ╚═╝  ╚═╝ ╚═╝  ╚═╝  ╚══╝╚══╝
module ysyx_26010011_RAW(
    input [ 3:0] rs1,
    input [ 3:0] rs2,
    input [11:0] csr,
    
    input rs2_valid,

    input exu_rd_valid,
    input lsu_rd_valid,
    input wbu_rd_valid,

    input exu_csr_valid,
    input lsu_csr_valid,
    input wbu_csr_valid,

    input exu_bypass_valid,
    input lsu_bypass_valid,
    input wbu_bypass_valid,

    input [ 3:0] exu_in_bus_rd,
    input [ 3:0] lsu_in_bus_rd,
    input [ 3:0] wbu_in_bus_rd,

    input [11:0] exu_in_bus_csr_rd,
    input [11:0] lsu_in_bus_csr_rd,
    input [11:0] wbu_in_bus_csr_rd,

    output reg is_RAW
);
	always @(*) begin
        is_RAW = 1'b0;
        if(exu_rd_valid && ((rs1 == exu_in_bus_rd) || ((rs2 == exu_in_bus_rd) && rs2_valid)) && !exu_bypass_valid) begin
            is_RAW = 1'b1;
        end
        else if(exu_csr_valid && (csr == exu_in_bus_csr_rd)) begin
            is_RAW = 1'b1;
        end
        else if(lsu_rd_valid && ((rs1 == lsu_in_bus_rd) || ((rs2 == lsu_in_bus_rd) && rs2_valid)) && !lsu_bypass_valid) begin
            is_RAW = 1'b1;
        end
        else if(lsu_csr_valid && (csr == lsu_in_bus_csr_rd)) begin
            is_RAW = 1'b1;
        end
        else if(wbu_rd_valid && ((rs1 == wbu_in_bus_rd) || ((rs2 == wbu_in_bus_rd) && rs2_valid)) && !wbu_bypass_valid) begin
            is_RAW = 1'b1;
        end
        else if(wbu_csr_valid && (csr == wbu_in_bus_csr_rd)) begin
            is_RAW = 1'b1;
        end
    end
endmodule