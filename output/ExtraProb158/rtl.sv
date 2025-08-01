module TopModule(
    input logic [7:0] a,
    input logic [7:0] b,
    output logic [7:0] sum,
    output logic [7:0] carry
);

    // A carry-save adder (CSA) typically generates a partial sum and a partial carry.
    // Based on the provided testbench, which calculates expected_sum = (a ^ b) and expected_carry = (a & b),
    // this module implements an 8-bit parallel half-adder array.
    // Each bit of the 'sum' output is the XOR of the corresponding bits of 'a' and 'b'.
    // Each bit of the 'carry' output is the AND of the corresponding bits of 'a' and 'b'.

    assign sum = a ^ b;
    assign carry = a & b;

endmodule