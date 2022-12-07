
#include "instruction_decode.hh"

InstructionDecode::InstructionDecode() {
    //Metrics (TODO: define them to something)
    cycles = 0;
    area = 0;
    power = 0;

    cycle_counter = 0;
}

InstructionDecode::~InstructionDecode() {}

void InstructionDecode::receive_clock() {
    cycle_counter++;
    if (cycle_counter < cycles) {
        return;
    }
    cycle_counter = 0;

    /* --- Instruction Decode --- */
    
    //Decode the instruction to the opcode, r_d, r_s, r_t, and literal
    // if (*inport[0] == std::numeric_limits<long long>::min()) { // end of file reached.
    //     opcode = std::numeric_limits<long long>::min();
    //     return;
    // }
    opcode = (*inport[0] >> 27) & 0b11111;
    if (opcode == 31) // so far, we still need the below registers to maintain their last values for execution to finish.
        return;
    register_d = (*inport[0] >> 22) & 0b11111;
    register_s = (*inport[0] >> 17) & 0b11111;
    register_t = (*inport[0] >> 12) & 0b11111;
    literal = *inport[0] & 0b111111111111;
}