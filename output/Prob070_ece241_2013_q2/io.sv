module TopModule(
    input logic a,
    input logic b,
    input logic c,
    input logic d,
    output logic out_sop,
    output logic out_pos
);

// Truth table:
// a b c d | out
// 0 0 0 0 | 0
// 0 0 0 1 | 0
// 0 0 1 0 | 1
// 0 0 1 1 | X
// 0 1 0 0 | 0
// 0 1 0 1 | 0
// 0 1 1 0 | 0
// 0 1 1 1 | 1
// 1 0 0 0 | X
// 1 0 0 1 | 0
// 1 0 1 0 | 0
// 1 0 1 1 | X
// 1 1 0 0 | X
// 1 1 0 1 | 0
// 1 1 1 0 | 0
// 1 1 1 1 | 1

// SOP: out_sop = (!a & !b & c & !d) | (!a & b & c & d) | (a & b & c & d)
// POS: out_pos = (!a & b & c & d) | (a & b & c & d) | (!a & !b & c & !d)

assign out_sop = (~a & ~b & c & ~d) | (~a & b & c & d) | (a & b & c & d);

//KMAP simplification
//out_pos = (c) & ((~a & ~b) | (b & d) | (a & d))
//out_pos = c & (~a & ~b + d)
assign out_pos = c & ((~a & ~b) | d);

endmodule
