module TopModule(
 input logic clk,
 input logic a,
 input logic b,
 output logic q,
 output logic state
 );

 reg state_reg;
 assign state = state_reg;

 always_ff @(posedge clk) begin
 if (~a & b) begin
 state_reg <= 1'b1;
 end else if (a & ~b) begin
 state_reg <= 1'b0;
 end
 end

 assign q = state_reg ^ a ^ b;

endmodule