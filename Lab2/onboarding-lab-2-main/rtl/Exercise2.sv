/**
  @brief A fibonacci linear feedback shift register module

  @input clk    clock
  @input nReset active-low reset
  @input init   initial value following a reset
  @output out   current output
*/
module Exercise2 (
    input clk,
    input nReset,
    input [15:0] init,
    output logic [15:0] out
);

wire taps;
assign taps=(((out[15]^out[13])^out[12])^out[10]);

always @(posedge clk) 
  if (nReset)
    out <= {out[14:0], taps};
  else
    out <= init;

endmodule
