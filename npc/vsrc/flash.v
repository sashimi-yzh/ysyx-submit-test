
module read_flash(input en, input [31:0] addr, output reg [31:0] data_out);

import "DPI-C" function void flash_read(input int addr, output int data);

always@(*) begin
    if(en) begin
        flash_read(addr,data_out);
    end
    else begin
        data_out = 32'b0;
    end
end

endmodule

