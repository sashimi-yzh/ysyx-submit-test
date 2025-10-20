module psram(
  input sck,
  input ce_n,
  inout [3:0] dio
);

import "DPI-C" function void psram_read(input int addr, output int data);
import "DPI-C" function void psram_write(input int addr, input int data,input int mask);

parameter RCMD   =  8'hEB;
parameter WCMD   =  8'h38;
parameter QPICMD =  8'h35;

parameter CMD   =  3'h0;
parameter ADDR  =  3'h1;
parameter DATA  =  3'h2;
parameter DELAY =  3'h3;
parameter ERROR =  3'h4;

wire [3:0] dout_en;
wire [3:0] dout;
wire [3:0] din;

assign din = dio;

genvar i;
generate
  for(i=0; i<4; i=i+1)begin
    assign dio[i] = dout_en[i] ? dout[i] : 1'bz;
  end
endgenerate

reg        QPI_MODE = 0;

reg [ 7: 0] cmd;
reg [23: 0] addr;
reg [31: 0] data;
reg [31: 0] rdata;
reg [ 7: 0] counter;
reg [ 2: 0] state;

always @(posedge ce_n) begin
  if(cmd == QPICMD)begin
    QPI_MODE = 1;
  end
end

always @(posedge sck or posedge ce_n) begin
  if(ce_n)begin
    counter <= 'd0;
    state   <= CMD;
  end
  else begin
    case(state)
      CMD:begin
        if(QPI_MODE)begin
          counter <= (counter <  8'd7 ) ? counter + 8'd4 : 8'd0;
          state   <= (counter == 8'd8 ) ? ADDR : state;
        end
        else begin
          counter <= (counter <  8'd7 ) ? counter + 8'd1 : 8'd0;
          state   <= (counter == 8'd7 ) ? ADDR : state;
        end
      end
      ADDR:begin
        counter <= (counter <  8'd5) ? counter + 8'd1 : 8'd0;
        state   <= (counter == 8'd5) ? (cmd == RCMD ? DELAY : (cmd == WCMD ? DATA : ERROR) ):state;
      end
      DATA:begin
        counter <= counter + 8'd1;
        state   <= state;
      end
      DELAY:begin
        counter <= (counter <  8'd6) ? counter + 8'd1 : 8'd0;
        state   <= (counter == 8'd6) ? DATA  : state;
      end
      ERROR: begin 
        $display("Error! Terminating simulation.");
        $finish;
      end
      default: begin state <= CMD; end
    endcase
  end
end

always@(posedge sck or posedge ce_n) begin
  if (ce_n) cmd <= 8'd0;
  else if (state == CMD)begin
    if(QPI_MODE)begin
      cmd <= {cmd[3:0], din[3:0]};
    end else begin
      cmd <= {cmd[6:0], din[0]};
    end
  end 
end

always@(posedge sck or posedge ce_n) begin
  if (ce_n) addr <= 24'd0;
  else if (state == ADDR && counter < 8'd6) addr <= {addr[19:0], din[3:0]};
end

wire [31:0] data_bswap = {rdata[7:0], rdata[15:8], rdata[23:16], rdata[31:24]};
always@(posedge sck or posedge ce_n) begin
  if (ce_n) data <= 32'd0;
  else if (state == DATA && cmd == RCMD) begin
    data <= {{counter == 8'd0 ? data_bswap : data}[27:0], 4'b0000};
  end
  else if (state == DATA && cmd == WCMD) begin
    data <= {data[27:0], din[3:0]};
  end
end
assign dout    = {(state == DATA &&counter == 8'd0) ? data_bswap : data}[31:28];
assign dout_en = (state == DATA || state == DELAY)&& cmd == RCMD ? 4'b1111 : 4'd0;

wire [31:0] wdata = {data[7:0], data[15:8], data[23:16], data[31:24]};

always @(posedge sck)begin
  if((state == DELAY) && (counter == 8'd0) && (cmd == RCMD))begin
    psram_read({8'd0,addr},rdata);
  end
end
always@(posedge ce_n) begin
  if(cmd == WCMD)begin
    psram_write({8'd0,addr},wdata,{24'd0,counter});
  end
end

endmodule
