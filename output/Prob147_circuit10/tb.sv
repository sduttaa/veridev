module TopModule_tb();
    logic clk, a, b, q, state;
    logic expected_q, expected_state;
    int mismatch_count = 0;
    time first_mismatch_time = 0;

    TopModule dut (.clk(clk), .a(a), .b(b), .q(q), .state(state));

    // Clock generation
    initial begin
        clk = 0;
        forever #5 clk = ~clk;
    end

    // Task to check outputs
    task check_outputs_at_negedge(input logic exp_state, input logic exp_q);
        @(negedge clk); // Wait for negedge to check
        expected_state = exp_state;
        expected_q = exp_q;
        
        $display("Time %0d: Inputs (a=%0b, b=%0b) | DUT (state=%0b, q=%0b) | Expected (state=%0b, q=%0b)",
                 $time, a, b, state, q, expected_state, expected_q);
        
        if (state !== expected_state || q !== expected_q) begin
            if (mismatch_count == 0) begin
                first_mismatch_time = $time;
            end
            mismatch_count++;
            $display("MISMATCH DETECTED!");
        end
    endtask

    // Test stimulus and expected values
    initial begin
        // Initialize inputs
        a = 1; b = 0; // Initial 'a' and 'b' at 0ns. 'b' is 'x' in waveform, using 0.

        // Test vectors from waveform
        // The waveform shows inputs (a, b) at time T, and outputs (state, q) also at time T
        // which are results after the posedge clk at T. We apply inputs at negedge clk
        // (or when clk=0), wait for posedge clk for DUT update, then wait for negedge clk to check.

        // Time 0ns: clk=0, a=1, b=x. Outputs are x. (Skip initial x values)
        // Time 5ns: clk=1, a=1, b=x. Outputs are x. (Skip initial x values)

        #10; // Advance to 10ns (clk=0)
        a = 0; b = 0; // Inputs for 15ns posedge
        @(posedge clk); // At 15ns
        check_outputs_at_negedge(0, 0); // Expected at 15ns (checked at 20ns)

        #5; // Advance to 20ns (clk=0)
        a = 0; b = 0; // Inputs for 25ns posedge
        @(posedge clk); // At 25ns
        check_outputs_at_negedge(0, 0); // Expected at 25ns (checked at 30ns)

        #5; // Advance to 30ns (clk=0)
        a = 0; b = 0; // Inputs for 35ns posedge
        @(posedge clk); // At 35ns
        check_outputs_at_negedge(0, 0); // Expected at 35ns (checked at 40ns)

        #5; // Advance to 40ns (clk=0)
        a = 0; b = 1; // Inputs for 45ns posedge
        @(posedge clk); // At 45ns
        check_outputs_at_negedge(0, 1); // Expected at 45ns (checked at 50ns)

        #5; // Advance to 50ns (clk=0)
        a = 1; b = 0; // Inputs for 55ns posedge
        @(posedge clk); // At 55ns
        check_outputs_at_negedge(0, 1); // Expected at 55ns (checked at 60ns)

        #5; // Advance to 60ns (clk=0)
        a = 1; b = 1; // Inputs for 65ns posedge
        @(posedge clk); // At 65ns
        check_outputs_at_negedge(0, 0); // Expected at 65ns (checked at 70ns)

        #5; // Advance to 70ns (clk=0)
        a = 0; b = 0; // Inputs for 75ns posedge
        @(posedge clk); // At 75ns
        check_outputs_at_negedge(1, 1); // Expected at 75ns (checked at 80ns)

        #5; // Advance to 80ns (clk=0)
        a = 1; b = 1; // Inputs for 85ns posedge
        @(posedge clk); // At 85ns
        check_outputs_at_negedge(0, 0); // Expected at 85ns (checked at 90ns)

        #5; // Advance to 90ns (clk=0)
        a = 1; b = 1; // Inputs for 95ns posedge
        @(posedge clk); // At 95ns
        check_outputs_at_negedge(1, 1); // Expected at 95ns (checked at 100ns)

        #5; // Advance to 100ns (clk=0)
        a = 1; b = 1; // Inputs for 105ns posedge
        @(posedge clk); // At 105ns
        check_outputs_at_negedge(1, 1); // Expected at 105ns (checked at 110ns)

        #5; // Advance to 110ns (clk=0)
        a = 1; b = 0; // Inputs for 115ns posedge
        @(posedge clk); // At 115ns
        check_outputs_at_negedge(0, 0); // Expected at 115ns (checked at 120ns)

        #5; // Advance to 120ns (clk=0)
        a = 0; b = 1; // Inputs for 125ns posedge
        @(posedge clk); // At 125ns
        check_outputs_at_negedge(0, 0); // Expected at 125ns (checked at 130ns)

        #5; // Advance to 130ns (clk=0)
        a = 0; b = 0; // Inputs for 135ns posedge
        @(posedge clk); // At 135ns
        check_outputs_at_negedge(1, 1); // Expected at 135ns (checked at 140ns)

        #5; // Advance to 140ns (clk=0)
        a = 0; b = 0; // Inputs for 145ns posedge
        @(posedge clk); // At 145ns
        check_outputs_at_negedge(0, 0); // Expected at 145ns (checked at 150ns)

        #5; // Advance to 150ns (clk=0)
        a = 0; b = 0; // Inputs for 155ns posedge
        @(posedge clk); // At 155ns
        check_outputs_at_negedge(0, 0); // Expected at 155ns (checked at 160ns)

        #5; // Advance to 160ns (clk=0)
        a = 0; b = 0; // Inputs for 165ns posedge
        @(posedge clk); // At 165ns
        check_outputs_at_negedge(0, 0); // Expected at 165ns (checked at 170ns)

        #5; // Advance to 170ns (clk=0)
        a = 0; b = 0; // Inputs for 175ns posedge
        @(posedge clk); // At 175ns
        check_outputs_at_negedge(0, 0); // Expected at 175ns (checked at 180ns)

        #5; // Advance to 180ns (clk=0)
        a = 0; b = 0; // Inputs for 185ns posedge
        @(posedge clk); // At 185ns
        check_outputs_at_negedge(0, 0); // Expected at 185ns (checked at 190ns)

        #5; // Advance to 190ns (clk=0) - End of waveform

        // Final check
        if (mismatch_count == 0) begin
            $display("SIMULATION PASSED");
        end else begin
            $display("SIMULATION FAILED - %0d MISMATCHES DETECTED, FIRST AT TIME %0d", mismatch_count, first_mismatch_time);
        end
        $finish; // End simulation
    end

endmodule