module ysyx_26040117_BTB(
    clk,rst,flush,
    araddr,hit,target,
    wen,waddr,wtarget
);
    localparam INDEX_WIDTH=1;
    localparam INDEX_LENGTH=1<<INDEX_WIDTH;
    input clk,rst;
    input flush;
    //ICache-BTB
    input [31:0] araddr;
    output hit;
    output [31:0] target;

    input wen;
    input [31:0] waddr,wtarget;

    reg [INDEX_LENGTH-1:0] btb_valid;
    reg [32-3-INDEX_WIDTH:0] btb_tag_array[INDEX_LENGTH-1:0];
    reg [29:0] btb_target_array[INDEX_LENGTH-1:0];

    wire [INDEX_WIDTH-1:0] rindex,windex;
    assign rindex=araddr[2 +: INDEX_WIDTH];
    assign windex=waddr[2 +: INDEX_WIDTH];

    assign hit=btb_valid[rindex]&&(btb_tag_array[rindex]==araddr[31:2+INDEX_WIDTH]);
    assign target={btb_target_array[rindex],2'b00};

    always @(posedge clk) begin
        if(rst||flush)
            btb_valid<=0;
        else if(wen)begin
            btb_valid[windex]<=1'b1;
            btb_tag_array[windex]<=waddr[31:2+INDEX_WIDTH];
            btb_target_array[windex]<=wtarget[31:2];
        end
    end
endmodule
