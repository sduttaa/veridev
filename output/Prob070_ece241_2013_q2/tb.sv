module TopModule_tb();
    logic a, b, c, d, out_sop, out_pos; 
    int mismatch_count = 0;
    int test_count = 0;

    TopModule dut (
        .a(a),
        .b(b),
        .c(c),
        .d(d),
        .out_sop(out_sop),
        .out_pos(out_pos)
    );

    initial begin
        // Test vector: {a, b, c, d, expected_sop, expected_pos}
        logic [1:0] test_vectors[0:15];
        logic expected_sop, expected_pos;
        test_vectors[0]  = 2'b00; // 0
        test_vectors[1]  = 2'b00; // 1
        test_vectors[2]  = 2'b11; // 2
        test_vectors[3]  = 2'bXX; // 3
        test_vectors[4]  = 2'b00; // 4
        test_vectors[5]  = 2'b00; // 5
        test_vectors[6]  = 2'b00; // 6
        test_vectors[7]  = 2'b11; // 7
        test_vectors[8]  = 2'bXX; // 8
        test_vectors[9]  = 2'b00; // 9
        test_vectors[10] = 2'b00; // 10
        test_vectors[11] = 2'bXX; // 11
        test_vectors[12] = 2'bXX; // 12
        test_vectors[13] = 2'b00; // 13
        test_vectors[14] = 2'b00; // 14
        test_vectors[15] = 2'b11; // 15

        $display("Starting simulation");

        for (int i = 0; i < 16; i++) begin
            a = i[3];
            b = i[2];
            c = i[1];
            d = i[0];

            case (i)
                2: begin expected_sop = 1; expected_pos = 1; end
                7: begin expected_sop = 1; expected_pos = 1; end
                15: begin expected_sop = 1; expected_pos = 1; end
                0: begin expected_sop = 0; expected_pos = 0; end
                1: begin expected_sop = 0; expected_pos = 0; end
                4: begin expected_sop = 0; expected_pos = 0; end
                5: begin expected_sop = 0; expected_pos = 0; end
                6: begin expected_sop = 0; expected_pos = 0; end
                9: begin expected_sop = 0; expected_pos = 0; end
                10: begin expected_sop = 0; expected_pos = 0; end
                13: begin expected_sop = 0; expected_pos = 0; end
                14: begin expected_sop = 0; expected_pos = 0; end
                default: begin expected_sop = 'x; expected_pos = 'x; end
            endcase

            #1;

            if ((expected_sop !== 'x') && (out_sop !== expected_sop)) begin
                $display("Mismatch at time %0t: a=%b, b=%b, c=%b, d=%b, expected_sop=%b, actual_sop=%b",
                          $time, a, b, c, d, expected_sop, out_sop);
                mismatch_count = mismatch_count + 1;
            end
            else begin
                $display("Match at time %0t: a=%b, b=%b, c=%b, d=%b, expected_sop=%b, actual_sop=%b",
                          $time, a, b, c, d, expected_sop, out_sop);
            end

            if ((expected_pos !== 'x') && (out_pos !== expected_pos)) begin
                $display("Mismatch at time %0t: a=%b, b=%b, c=%b, d=%b, expected_pos=%b, actual_pos=%b",
                          $time, a, b, c, d, expected_pos, out_pos);
                mismatch_count = mismatch_count + 1;
            end
            else begin
                $display("Match at time %0t: a=%b, b=%b, c=%b, d=%b, expected_pos=%b, actual_pos=%b",
                          $time, a, b, c, d, expected_pos, out_pos);
            end
            test_count = test_count + 1;
        end

        if (mismatch_count == 0)
            $display("SIMULATION PASSED");
        else
            $display("SIMULATION FAILED - %0d MISMATCHES DETECTED", mismatch_count);

        $finish;
    end
endmodule
