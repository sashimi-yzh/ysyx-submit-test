

module ysyx_25040129_PIPELINE #(
	parameter DATA_WIDTH = 128
)(
	input clk,
	input rst,
	input pipeline_flush,

	input in_valid,
	output in_ready,
	input [DATA_WIDTH-1:0] in_data,

	output out_valid,
	input out_ready,
	output reg[DATA_WIDTH-1:0] out_data
);

localparam EMPTY = 1'b0;
localparam FULL = 1'b1;
reg state;
assign in_ready = (state == EMPTY)|| (out_ready);
assign out_valid = (state == FULL);
always @(posedge clk) begin
	if(rst || pipeline_flush)begin
		state <= EMPTY;
		out_data <= {DATA_WIDTH{1'b0}};
	end
	else begin
		case (state)
			EMPTY: begin
				if(in_valid) begin
					state <= FULL;
					out_data <= in_data; 
				end
			end
			FULL: begin
				if(out_ready) begin
					if(in_valid)out_data <= in_data; 
					else state <= EMPTY;
				end
			end
			default: state <= EMPTY;
		endcase
	end
end
endmodule

