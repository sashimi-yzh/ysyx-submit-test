module RAW(
    input [4:0] rs1,
    input [4:0] rs2,
    input need_rs2,
    input [11:0] csr_addr,

    input [4:0] rd_exu,
    input rd_valid_exu,
    input forward_ready_exu,
    input [11:0] csr_exu,
    input csr_valid_exu,
    input csr_forward_ready_exu,
    
    input [4:0] rd_lsu,
    input rd_valid_lsu,
    input forward_ready_lsu,
    input [11:0] csr_lsu,
    input csr_valid_lsu,
    input csr_forward_ready_lsu,

    input [4:0] rd_wbu,
    input rd_valid_wbu,
    input forward_ready_wbu,
    input [11:0] csr_wbu,
    input csr_valid_wbu,
    input csr_forward_ready_wbu,
    
    output reg stall
);

    /*handle the stall, if can't load use, then stall*/
    always @(*) begin
        stall = 1'b0;
        if(rd_valid_exu && !forward_ready_exu) begin
            if(rd_exu != 5'b0 && (rd_exu == rs1 || (need_rs2 && rd_exu == rs2))) begin
                stall = 1'b1;
            end
        end

        if(csr_valid_exu && !csr_forward_ready_exu) begin
            if(csr_exu == csr_addr) begin
                stall = 1'b1;
            end
        end

        if(rd_valid_lsu && !forward_ready_lsu) begin
            if(rd_lsu != 5'b0 && (rd_lsu == rs1 || (need_rs2 && rd_lsu == rs2))) begin
                stall = 1'b1;
            end
        end

        if(csr_valid_lsu && !csr_forward_ready_lsu) begin
            if(csr_lsu == csr_addr) begin
                stall = 1'b1;
            end
        end

        if(rd_valid_wbu && !forward_ready_wbu) begin
            if(rd_wbu != 5'b0 && (rd_wbu == rs1 || (need_rs2 && rd_wbu == rs2))) begin
                stall = 1'b1;
            end
        end

        if(csr_valid_wbu && !csr_forward_ready_wbu) begin
            if(csr_wbu == csr_addr) begin
                stall = 1'b1;
            end
        end
    end

endmodule
