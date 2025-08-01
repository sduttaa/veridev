module TopModule(
    input logic a,
    input logic b,
    input logic c,
    input logic d,
    output logic out_sop,
    output logic out_pos
);

    // Truth table based on specification (a is MSB, d is LSB):
    // Decimal | a b c d | Output
    // --------|---------|--------
    //    0    | 0 0 0 0 |   0
    //    1    | 0 0 0 1 |   0
    //    2    | 0 0 1 0 |   1
    //    3    | 0 0 1 1 |   X (Don't Care)
    //    4    | 0 1 0 0 |   0
    //    5    | 0 1 0 1 |   0
    //    6    | 0 1 1 0 |   0
    //    7    | 0 1 1 1 |   1
    //    8    | 1 0 0 0 |   X (Don't Care)
    //    9    | 1 0 0 1 |   0
    //   10    | 1 0 1 0 |   0
    //   11    | 1 0 1 1 |   X (Don't Care)
    //   12    | 1 1 0 0 |   X (Don't Care)
    //   13    | 1 1 0 1 |   0
    //   14    | 1 1 1 0 |   0
    //   15    | 1 1 1 1 |   1

    // K-map (ab/cd):
    //       cd
    //     00 01 11 10
    // ab
    // 00 | 0  0  X  1   (m0, m1, m3, m2)
    // 01 | 0  0  1  0   (m4, m5, m7, m6)
    // 11 | X  0  1  0   (m12, m13, m15, m14)
    // 10 | X  0  X  0   (m8, m9, m11, m10)

    // Minimum Sum-of-Products (SOP) derivation for out_sop:
    // '1's at: m2, m7, m15
    // 'X's at: m3, m8, m11, m12
    //
    // Groupings for SOP:
    // 1. Group (m2, m3(X)): (!a & !b & c)  -> Covers m2
    //    (0010, 0011)
    // 2. Group (m3(X), m7, m11(X), m15): (c & d) -> Covers m7, m15
    //    (0011, 0111, 1011, 1111)
    //
    // Minimum SOP expression:
    assign out_sop = (!a & !b & c) | (c & d);

    // Minimum Product-of-Sums (POS) derivation for out_pos:
    // '0's at: m0, m1, m4, m5, m6, m9, m10, m13, m14
    // 'X's at: m3, m8, m11, m12
    //
    // Groupings for '0's and 'X's (each group forms a sum term):
    // 1. Group (m0, m1, m4, m5): (a + c)
    //    (0000, 0001, 0100, 0101)
    // 2. Group (m6, m14): (!b + !c + d)
    //    (0110, 1110)
    // 3. Group (m9, m13): (!a + c + !d)
    //    (1001, 1101)
    // 4. Group (m10, m14): (!a + !c + d)
    //    (1010, 1110)
    //
    // All '0's are covered by these essential prime implicants (sum terms).
    // Minimum POS expression:
    assign out_pos = (a | c) & (!b | !c | d) & (!a | c | !d) & (!a | !c | d);

endmodule