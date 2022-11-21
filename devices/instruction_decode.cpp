
#include "instruction_decode.hh"

void InstructionDecode::receive_clock() {
    // Pass data from outport to outLatch
    opcode_l.value = reinterpret_cast<unsigned char*>(out_opcode);
    register_d_l.value = reinterpret_cast<unsigned char*>(out_register_d);
    register_s_l.value = reinterpret_cast<unsigned char*>(out_register_s);
    register_t_l.value = reinterpret_cast<unsigned char*>(out_register_t);
    literal_l.value = reinterpret_cast<unsigned char*>(out_literal);
}

void InstructionDecode::do_function() {
    /* --- Instruction Decode --- */
      

    //Decode the instruction to the opcode, r_d, r_s, r_t, and literal
    *out_opcode = (*inport[0] >> 27) & 0b11111;
    *out_register_d = (*inport[0] >> 22) & 0b11111;
    *out_register_s = (*inport[0] >> 17) & 0b11111;
    *out_register_t = (*inport[0] >> 12) & 0b11111;
    *out_literal = *inport[0] & 0b111111111111;
      
    /* --- Control Signals --- */
      
    //TODO:

}

void InstructionDecode::connect(int port_id, Latch inLatch) {
    // Connect inLatch to inport
    inport[port_id] = reinterpret_cast<Port>(inLatch.value);
}