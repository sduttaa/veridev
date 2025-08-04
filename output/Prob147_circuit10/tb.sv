module TopModule_tb();
  logic clk, a, b, q, state;
  logic expected_q, expected_state;
  int mismatch_count = 0;

  TopModule dut (
    .clk(clk),
    .a(a),
    .b(b),
    .q(q),
    .state(state)
  );

  initial begin
    clk = 0;
    forever #5 clk = ~clk;
  end

  initial begin
    $monitor("%0t clk=%b a=%b b=%b state=%b q=%b expected_state=%b expected_q=%b",
              $time, clk, a, b, state, q, expected_state, expected_q);

    // Initialize inputs
    a = 1; b = 1'bx;
    #10;
    a = 0; b = 0;
    #10;
    a = 0; b = 0; expected_state = 0; expected_q = 0;
    #10;
    a = 0; b = 0; expected_state = 0; expected_q = 0;
    #10;
    a = 0; b = 0; expected_state = 0; expected_q = 0;
    #10;
    a = 0; b = 1; expected_state = 0; expected_q = 1;
    #10;
    a = 1; b = 0; expected_state = 0; expected_q = 1;
    #10;
    a = 1; b = 1; expected_state = 0; expected_q = 0;
    #10;
    a = 0; b = 0; expected_state = 1; expected_q = 1;
    #10;
    a = 1; b = 1; expected_state = 0; expected_q = 0;
    #10;
    a = 1; b = 1; expected_state = 1; expected_q = 1;
    #10;
    a = 1; b = 1; expected_state = 1; expected_q = 1;
    #10;
    a = 1; b = 0; expected_state = 1; expected_q = 0;
    #10;
    a = 0; b = 1; expected_state = 1; expected_q = 0;
    #10;
    a = 0; b = 0; expected_state = 1; expected_q = 1;
    #10;
    a = 0; b = 0; expected_state = 0; expected_q = 0;
    #10;
    a = 0; b = 0; expected_state = 0; expected_q = 0;
    #10;
    a = 0; b = 0; expected_state = 0; expected_q = 0;
    #10;
    a = 0; b = 0; expected_state = 0; expected_q = 0;
    #10;
    a = 0; b = 0; expected_state = 0; expected_q = 0;
    #10;
    a = 0; b = 0; expected_state = 0; expected_q = 0;
    #10;
    a = 0; b = 0; expected_state = 0; expected_q = 0;
    #10;

    #10;

    // Check outputs
    #1 $finish;
  end

  always @(negedge clk) begin
    if ($time >= 15) begin
      case ($time)
        15: begin
          if (q !== 0 || state !== 0) begin
            $display("Mismatch at %0t: a=%b, b=%b, expected_q=%b, actual_q=%b, expected_state=%b, actual_state=%b",
                      $time, a, b, 0, q, 0, state);
            mismatch_count++;
          end
        end
        25: begin
          if (q !== 0 || state !== 0) begin
            $display("Mismatch at %0t: a=%b, b=%b, expected_q=%b, actual_q=%b, expected_state=%b, actual_state=%b",
                      $time, a, b, 0, q, 0, state);
            mismatch_count++;
          end
        end
        35: begin
          if (q !== 0 || state !== 0) begin
            $display("Mismatch at %0t: a=%b, b=%b, expected_q=%b, actual_q=%b, expected_state=%b, actual_state=%b",
                      $time, a, b, 0, q, 0, state);
            mismatch_count++;
          end
        end
        45: begin
          if (q !== 1 || state !== 0) begin
            $display("Mismatch at %0t: a=%b, b=%b, expected_q=%b, actual_q=%b, expected_state=%b, actual_state=%b",
                      $time, a, b, 1, q, 0, state);
            mismatch_count++;
          end
        end
        55: begin
          if (q !== 1 || state !== 0) begin
            $display("Mismatch at %0t: a=%b, b=%b, expected_q=%b, actual_q=%b, expected_state=%b, actual_state=%b",
                      $time, a, b, 1, q, 0, state);
            mismatch_count++;
          end
        end
        65: begin
          if (q !== 0 || state !== 0) begin
            $display("Mismatch at %0t: a=%b, b=%b, expected_q=%b, actual_q=%b, expected_state=%b, actual_state=%b",
                      $time, a, b, 0, q, 0, state);
            mismatch_count++;
          end
        end
        75: begin
          if (q !== 1 || state !== 1) begin
            $display("Mismatch at %0t: a=%b, b=%b, expected_q=%b, actual_q=%b, expected_state=%b, actual_state=%b",
                      $time, a, b, 1, q, 1, state);
            mismatch_count++;
          end
        end
        85: begin
          if (q !== 0 || state !== 0) begin
            $display("Mismatch at %0t: a=%b, b=%b, expected_q=%b, actual_q=%b, expected_state=%b, actual_state=%b",
                      $time, a, b, 0, q, 0, state);
            mismatch_count++;
          end
        end
        95: begin
          if (q !== 1 || state !== 1) begin
            $display("Mismatch at %0t: a=%b, b=%b, expected_q=%b, actual_q=%b, expected_state=%b, actual_state=%b",
                      $time, a, b, 1, q, 1, state);
            mismatch_count++;
          end
        end
        105: begin
          if (q !== 1 || state !== 1) begin
            $display("Mismatch at %0t: a=%b, b=%b, expected_q=%b, actual_q=%b, expected_state=%b, actual_state=%b",
                      $time, a, b, 1, q, 1, state);
            mismatch_count++;
          end
        end
        115: begin
          if (q !== 0 || state !== 1) begin
            $display("Mismatch at %0t: a=%b, b=%b, expected_q=%b, actual_q=%b, expected_state=%b, actual_state=%b",
                      $time, a, b, 0, q, 1, state);
            mismatch_count++;
          end
        end
        125: begin
          if (q !== 0 || state !== 1) begin
            $display("Mismatch at %0t: a=%b, b=%b, expected_q=%b, actual_q=%b, expected_state=%b, actual_state=%b",
                      $time, a, b, 0, q, 1, state);
            mismatch_count++;
          end
        end
        135: begin
          if (q !== 1 || state !== 1) begin
            $display("Mismatch at %0t: a=%b, b=%b, expected_q=%b, actual_q=%b, expected_state=%b, actual_state=%b",
                      $time, a, b, 1, q, 1, state);
            mismatch_count++;
          end
        end
        145: begin
          if (q !== 0 || state !== 0) begin
            $display("Mismatch at %0t: a=%b, b=%b, expected_q=%b, actual_q=%b, expected_state=%b, actual_state=%b",
                      $time, a, b, 0, q, 0, state);
            mismatch_count++;
          end
        end
        default: ;
      endcase
    end
  end

  initial begin
    #200;
    if (mismatch_count == 0)
      $display("SIMULATION PASSED");
    else
      $display("SIMULATION FAILED - %0d MISMATCHES DETECTED", mismatch_count);
    $finish;
  end

endmodule