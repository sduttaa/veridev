module TopModule_tb();
    logic a, b, c, d, out_sop, out_pos; // Removed expected signals
    int mismatch_count = 0;
    int first_mismatch_time = -1;

    TopModule dut (
        .a(a),
        .b(b),
        .c(c),
        .d(d),
        .out_sop(out_sop),
        .out_pos(out_pos)
    );

    initial begin
        $timeformat(-9, 1, "ns", 1);
        for (int i = 0; i < 16; i++) begin
            {a, b, c, d} = i;

            #1; // Delay for combinational logic to settle

            logic expected_sop, expected_pos; // Declare expected signals here

            case (i)
                2: begin
                    expected_sop = 1;
                    expected_pos = 1;
                end
                7: begin
                    expected_sop = 1;
                    expected_pos = 1;
                end
                15: begin
                    expected_sop = 1;
                    expected_pos = 1;
                end
                0: begin
                    expected_sop = 0;
                    expected_pos = 0;
                end
                1: begin
                    expected_sop = 0;
                    expected_pos = 0;
                end
                4: begin
                    expected_sop = 0;
                    expected_pos = 0;
                end
                5: begin
                    expected_sop = 0;
                    expected_pos = 0;
                end
                6: begin
                    expected_sop = 0;
                    expected_pos = 0;
                end
                9: begin
                    expected_sop = 0;
                    expected_pos = 0;
                end
                10: begin
                    expected_sop = 0;
                    expected_pos = 0;
                end
                13: begin
                    expected_sop = 0;
                    expected_pos = 0;
                end
                14: begin
                    expected_sop = 0;
                    expected_pos = 0;
                end
                default: begin
                    expected_sop = 'x; // Don't care
                    expected_pos = 'x;
                end
            endcase

            if (expected_sop !== 'x') begin
                if (out_sop !== expected_sop) begin
                    $display("Mismatch at time %0t: a=%b b=%b c=%b d=%b expected_sop=%b actual_sop=%b",
                             $time, a, b, c, d, expected_sop, out_sop);
                    mismatch_count++;
                    if (first_mismatch_time == -1) first_mismatch_time = $time;
                end else begin
                    $display("Match at time %0t: a=%b b=%b c=%b d=%b expected_sop=%b actual_sop=%b",
                             $time, a, b, c, d, expected_sop, out_sop);
                end
            end

            if (expected_pos !== 'x') begin
                if (out_pos !== expected_pos) begin
                    $display("Mismatch at time %0t: a=%b b=%b c=%b d=%b expected_pos=%b actual_pos=%b",
                             $time, a, b, c, d, expected_pos, out_pos);
                    mismatch_count++;
                    if (first_mismatch_time == -1) first_mismatch_time = $time;
                end else begin
                    $display("Match at time %0t: a=%b b=%b c=%b d=%b expected_pos=%b actual_pos=%b",
                             $time, a, b, c, d, expected_pos, out_pos);
                end
            end
        end

        if (mismatch_count == 0)
            $display("SIMULATION PASSED");
        else
            $display("SIMULATION FAILED - %0d MISMATCHES DETECTED, FIRST AT TIME %0t", mismatch_count, first_mismatch_time);

        $finish;
    end
endmodule
