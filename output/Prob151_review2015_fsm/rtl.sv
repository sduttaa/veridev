module TopModule(
    input  logic clk,
    input  logic reset,
    input  logic data,
    input  logic done_counting,
    input  logic ack,
    output logic shift_ena,
    output logic counting,
    output logic done
);

    // Define states for the Finite State Machine (FSM)
    typedef enum logic [2:0] {
        SEARCH_PATTERN, // Initial state, looking for '1101'
        S1,             // Received '1'
        S11,            // Received '11'
        S110,           // Received '110'
        SHIFTING,       // Shifting in 4 bits, shift_ena asserted
        WAIT_COUNTING,  // Waiting for external counters to finish, counting asserted
        WAIT_ACK        // Waiting for user acknowledgment, done asserted
    } fsm_state_t;

    // State registers
    fsm_state_t current_state, next_state;

    // Counter for the 4 clock cycles in SHIFTING state
    // Needs to count from 0 to 3 (4 cycles)
    logic [1:0] shift_cycle_counter;

    // State and counter sequential logic
    always_ff @(posedge clk) begin
        if (reset) begin
            current_state <= SEARCH_PATTERN;
            shift_cycle_counter <= 2'b00; // Reset counter
        end else begin
            current_state <= next_state;
            // Logic for shift_cycle_counter
            if (next_state == SHIFTING && current_state != SHIFTING) begin
                // Reset counter when entering SHIFTING state
                shift_cycle_counter <= 2'b00;
            end else if (current_state == SHIFTING) begin
                // Increment counter while in SHIFTING state
                shift_cycle_counter <= shift_cycle_counter + 2'b01;
            end
        end
    end

    // Next state combinational logic
    always_comb begin
        next_state = current_state; // Default to self-loop

        case (current_state)
            SEARCH_PATTERN:
                if (data == 1'b1) begin
                    next_state = S1;
                end else begin
                    next_state = SEARCH_PATTERN;
                end
            S1:
                if (data == 1'b1) begin
                    next_state = S11;
                end else begin
                    next_state = SEARCH_PATTERN; // Reset if pattern breaks (e.g., '10')
                end
            S11:
                if (data == 1'b0) begin
                    next_state = S110;
                end else begin
                    next_state = S11; // Stay in S11 for consecutive '1's (e.g., '111')
                end
            S110:
                if (data == 1'b1) begin
                    next_state = SHIFTING; // Pattern '1101' detected!
                end else begin
                    next_state = SEARCH_PATTERN; // Reset if pattern breaks (e.g., '1100')
                end
            SHIFTING:
                // After 4 cycles (counter reaches 3), move to WAIT_COUNTING
                if (shift_cycle_counter == 2'b11) begin // Counter values: 0, 1, 2, 3 (4 cycles)
                    next_state = WAIT_COUNTING;
                end else begin
                    next_state = SHIFTING;
                end
            WAIT_COUNTING:
                if (done_counting == 1'b1) begin
                    next_state = WAIT_ACK;
                end else begin
                    next_state = WAIT_COUNTING;
                end
            WAIT_ACK:
                if (ack == 1'b1) begin
                    next_state = SEARCH_PATTERN; // Cycle complete, go back to searching
                end else begin
                    next_state = WAIT_ACK;
                end
            default: // Should not happen, but good for completeness
                next_state = SEARCH_PATTERN;
        endcase
    end

    // Output combinational logic
    // Assign outputs based on the current FSM state
    assign shift_ena = (current_state == SHIFTING);
    assign counting  = (current_state == WAIT_COUNTING);
    assign done      = (current_state == WAIT_ACK);

endmodule
