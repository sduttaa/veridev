module TopModule_tb();
    logic clk, reset, data, done_counting, ack;
    logic shift_ena, counting, done;
    int mismatch_count = 0;
    int cycle_count = 0;
    
    // Instantiate the module
    TopModule dut (
        .clk(clk), .reset(reset), .data(data),
        .done_counting(done_counting), .ack(ack),
        .shift_ena(shift_ena), .counting(counting), .done(done)
    );

    // Clock generation
    always #5 clk = ~clk;

    initial begin
        clk = 0;
        reset = 1;
        data = 0;
        done_counting = 0;
        ack = 0;

        // Reset
        #10;  // Wait for reset to take effect
        reset = 0;

        // Test case 1: Detect pattern 1101, shift 4 bits, count, done, ack
        data = 1; #10; //1
        data = 1; #10; //1
        data = 0; #10; //0
        data = 1; #10; //1
        
        // Shift enable for 4 cycles
        data = 0; #10; //0
        if (shift_ena !== 1'b1) begin $display("Mismatch at %0t: shift_ena expected 1, actual %b", $time, shift_ena); mismatch_count++; end
        data = 1; #10; //1
        if (shift_ena !== 1'b1) begin $display("Mismatch at %0t: shift_ena expected 1, actual %b", $time, shift_ena); mismatch_count++; end
        data = 0; #10; //0
        if (shift_ena !== 1'b1) begin $display("Mismatch at %0t: shift_ena expected 1, actual %b", $time, shift_ena); mismatch_count++; end
        data = 1; #10; //1
        if (shift_ena !== 1'b1) begin $display("Mismatch at %0t: shift_ena expected 1, actual %b", $time, shift_ena); mismatch_count++; end
        
        //Counting
        if (counting !== 1'b1) begin $display("Mismatch at %0t: counting expected 1, actual %b", $time, counting); mismatch_count++; end
        done_counting = 1; #10;

        //Done
        if (done !== 1'b1) begin $display("Mismatch at %0t: done expected 1, actual %b", $time, done); mismatch_count++; end
        ack = 1; #10;

        //Back to initial state
        if (counting !== 1'b0) begin $display("Mismatch at %0t: counting expected 0, actual %b", $time, counting); mismatch_count++; end
        if (done !== 1'b0) begin $display("Mismatch at %0t: done expected 0, actual %b", $time, done); mismatch_count++; end


        // Test case 2: Another sequence to ensure it resets properly
        data = 1; #10; //1
        data = 1; #10; //1
        data = 0; #10; //0
        data = 1; #10; //1
        
        // Shift enable for 4 cycles
        data = 0; #10; //0
        if (shift_ena !== 1'b1) begin $display("Mismatch at %0t: shift_ena expected 1, actual %b", $time, shift_ena); mismatch_count++; end
        data = 1; #10; //1
        if (shift_ena !== 1'b1) begin $display("Mismatch at %0t: shift_ena expected 1, actual %b", $time, shift_ena); mismatch_count++; end
        data = 0; #10; //0
        if (shift_ena !== 1'b1) begin $display("Mismatch at %0t: shift_ena expected 1, actual %b", $time, shift_ena); mismatch_count++; end
        data = 1; #10; //1
        if (shift_ena !== 1'b1) begin $display("Mismatch at %0t: shift_ena expected 1, actual %b", $time, shift_ena); mismatch_count++; end
        
        //Counting
        if (counting !== 1'b1) begin $display("Mismatch at %0t: counting expected 1, actual %b", $time, counting); mismatch_count++; end
        done_counting = 1; #10;

        //Done
        if (done !== 1'b1) begin $display("Mismatch at %0t: done expected 1, actual %b", $time, done); mismatch_count++; end
        ack = 1; #10;

        //Back to initial state
        if (counting !== 1'b0) begin $display("Mismatch at %0t: counting expected 0, actual %b", $time, counting); mismatch_count++; end
        if (done !== 1'b0) begin $display("Mismatch at %0t: done expected 0, actual %b", $time, done); mismatch_count++; end


        if (mismatch_count == 0)
            $display("SIMULATION PASSED");
        else
            $display("SIMULATION FAILED - %0d MISMATCHES DETECTED", mismatch_count);

        $finish;
    end
endmodule