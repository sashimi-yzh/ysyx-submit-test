`include "defines.v"


module IMem(
        input reset,
        input [`WordBus]pc,
        output reg [`WordBus] data
);


import "DPI-C" function int get_inst(input int pc);

always@(*) begin
    if(reset) begin
        data = 0;
    end
    else begin
        data = get_inst(pc);
    end
end

endmodule


