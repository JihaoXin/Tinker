
#include "instruction_fetch.hh"

void InstructionFetch::receive_clock() {
    // Pass data from outport to outLatch
    outLatch.value = reinterpret_cast<unsigned char*>(outport);
}

void InstructionFetch::do_function(uint32_t PC) {
    /* --- Instruction Fetch and Decode --- */
    
    //Seek to the program counter's value
    instructionFile.seekg(PC, std::ios::beg);

    //Read the 32-bits and output it to the latch
    instructionFile.read((char *) outport, 4);
}

void InstructionFetch::connect(int port_id, Latch inLatch) {
    // Connect inLatch to inport
    inport[port_id] = reinterpret_cast<Port>(inLatch.value);
}