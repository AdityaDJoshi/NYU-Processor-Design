module Exercise3 (
    input clk,
    input nReset,
    input [3:0] a,
    input [15:0] b,
    input [15:0] c,
    output [15:0] out
);

wire [7:0] alphaDwire;
wire [7:0] betaDwire;

Mystery1 alpha(a[1:0], b[7:0], c[7:0], alphaDwire);
Mystery1 beta(a[3:2], b[15:8], c[15:8], betaDwire);

Mystery2 gamma(clk, nReset, alphaDwire, betaDwire, out);


endmodule
