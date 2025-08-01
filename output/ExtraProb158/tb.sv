module TopModule_tb;
    logic [7:0] a, b, sum, carry, expected_sum, expected_carry;
    int mismatch_count = 0;
    longint mismatch_time = 0;

    TopModule dut (
        .a(a),
        .b(b),
        .sum(sum),
        .carry(carry)
    );

    initial begin
        for (int i = 0; i < 256; i++) begin
            a = $random;
            b = $random;
            #1;

            expected_sum = (a ^ b);
            expected_carry = (a & b);

            if (sum !== expected_sum || carry !== expected_carry) begin
                $display("Mismatch at time %0t:", $time);
                $display("  a      = 0x%02h", a);
                $display("  b      = 0x%02h", b);
                $display("  sum    = 0x%02h (expected 0x%02h)", sum, expected_sum);
                $display("  carry  = 0x%02h (expected 0x%02h)", carry, expected_carry);
                if (mismatch_count == 0) mismatch_time = $time;
                mismatch_count++;
            end
        end

        if (mismatch_count == 0) begin
            $display("SIMULATION PASSED");
        end else begin
            $display("SIMULATION FAILED - %0d MISMATCHES DETECTED, FIRST AT TIME %0d", mismatch_count, mismatch_time);
        end

        $finish;
    end
endmodule
